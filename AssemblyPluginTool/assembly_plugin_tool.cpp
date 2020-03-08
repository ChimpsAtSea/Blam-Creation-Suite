#include "assemblyplugintool-private-pch.h"

#pragma warning( disable : 4244 )

#include <MantleLib/CacheInterface/tag_group_names.inl>

const char* tag_group_to_structure_name(const std::wstring& tag_group_str)
{
	char buffer[sizeof(int) + 1]{' ', ' ', ' ', ' '};
	snprintf(buffer, _countof(buffer), "%S", tag_group_str.c_str());
	size_t bufferlen = strlen(buffer);
	if (bufferlen < sizeof(int))
	{
		buffer[bufferlen] = ' ';
	}
	int tag_group = _byteswap_ulong(*reinterpret_cast<int*>(buffer)); // >> (8 * (sizeof(int) - strlen(buffer)));
	
	for (std::pair<int, const char*>& tag_group_id_and_name_pair : tag_group_names)
	{
		if (tag_group_id_and_name_pair.first == tag_group)
		{
			return tag_group_id_and_name_pair.second;
		}
	}
	printf("Warning: Failed to find structure name for '%S'\n", tag_group_str.c_str());
	return "";
}

c_assembly_plugin_tool::c_assembly_plugin_tool(const wchar_t* file_name, const wchar_t* file_path, const wchar_t* output_directory) :
	file_name(file_name),
	file_path(file_path),
	output_directory(output_directory),
	tag_definition(nullptr)
{
	output_file_name = std::wstring(file_name);
	output_file_name = output_file_name.substr(0, output_file_name.rfind(L"."));

	tag_group_short_name = std::string(output_file_name.begin(), output_file_name.end());

	tag_group_name = tag_group_to_structure_name(output_file_name);
	if (!tag_group_name.empty())
	{
		output_file_name = std::wstring(tag_group_name.begin(), tag_group_name.end());
	}
	else
	{
		tag_group_name = std::string(output_file_name.begin(), output_file_name.end());
	}
	output_file_name += L".h";
	output_file_path = std::wstring(output_directory) + output_file_name; // #TODO: convert the file name to the structure name

	e_assembly_plugin_tool_error result = parse_plugin_file();
	if (result != _apt_error_ok)
	{
		throw;
	}

	char* existing_file_contents = nullptr;
	{
		FILE* output_file = _wfopen(output_file_path.c_str(), L"rb");
		if (output_file)
		{
			fseek(output_file, 0, SEEK_END);
			size_t file_size = static_cast<size_t>(_ftelli64(output_file));
			fseek(output_file, 0, SEEK_SET);
			existing_file_contents = new char[file_size + 1] {};
			size_t bytes_read = 0;
			while (bytes_read < file_size)
				bytes_read += fread(existing_file_contents + bytes_read, 1, file_size - bytes_read, output_file);
			
			fclose(output_file);
		}
	}

	std::stringstream output_stream;
	tag_definition->write_begin(output_stream);
	std::string output_contents = output_stream.str();

	if (!existing_file_contents || (output_contents != existing_file_contents))
	{
		printf("Updating '%S'\n", output_file_name.c_str());
		FILE* output_file = _wfopen(output_file_path.c_str(), L"wb");
		fwrite(output_contents.c_str(), 1, output_contents.length(), output_file);
		assert(output_file != nullptr);
		fclose(output_file);
	}

	if (existing_file_contents)
	{
		delete[] existing_file_contents;
	}
}

c_assembly_plugin_tool::~c_assembly_plugin_tool()
{
	delete tag_definition;
}

e_assembly_plugin_tool_error c_assembly_plugin_tool::parse_plugin_file()
{
	log("Parsing %S\n", file_name);

	xml_document doc;
	xml_parse_result result = doc.load_file(file_path);
	if (result == -1) return _apt_error_failed_to_load_file;

	xml_node plugin_node = doc.first_child();
	if (!nodecmp(plugin_node, "plugin")) return _apt_error_failed_to_find_plugin_node;

	tag_definition = new c_assembly_structure_definition(nullptr, *this, tag_group_name.c_str(), plugin_node.children(), tag_group_short_name.c_str());
	tag_definition->print_debug();
	return tag_definition->tool_error;
}

void c_assembly_plugin_tool::replace_instances_in_string(std::string& data, std::string search, std::string replace)
{
	size_t current_position = data.find(search);
	while (current_position != std::string::npos)
	{
		data.replace(current_position, search.size(), replace);
		current_position = data.find(search, current_position + replace.size());
	}
}

std::string c_assembly_plugin_tool::format_source_friendly_name(const std::string& name)
{
	std::string result = name;

	std::transform(result.begin(), result.end(), result.begin(), [](char c)
		{ 
			if (c == ' ') return '_';
			return (char)std::tolower(c);
		});

	replace_instances_in_string(result, "?", "");
	replace_instances_in_string(result, "]", "");
	replace_instances_in_string(result, "[", "");
	replace_instances_in_string(result, "!", "");
	replace_instances_in_string(result, "@", "");
	replace_instances_in_string(result, "#", "");
	replace_instances_in_string(result, "$", "");
	replace_instances_in_string(result, "%", "");
	replace_instances_in_string(result, "^", "");
	replace_instances_in_string(result, "&", "");
	replace_instances_in_string(result, "*", "");
	replace_instances_in_string(result, "(", "");
	replace_instances_in_string(result, ")", "");
	replace_instances_in_string(result, "/", "_");
	replace_instances_in_string(result, "\\", "_");
	replace_instances_in_string(result, "-", "_");
	replace_instances_in_string(result, "'", "");
	replace_instances_in_string(result, ",", "");
	replace_instances_in_string(result, "+", "");
	replace_instances_in_string(result, ":", "");
	replace_instances_in_string(result, ".", "");

	if (
		result.size() > 0 && (
			result[0] == '0' ||
			result[0] == '1' ||
			result[0] == '2' ||
			result[0] == '3' ||
			result[0] == '4' ||
			result[0] == '5' ||
			result[0] == '6' ||
			result[0] == '7' ||
			result[0] == '8' ||
			result[0] == '9'
			))
	{
		result = std::string("_") + result;
	}

	if (result == "class") result = "$class";
	if (result == "operator") result = "$operator";
	
	return result;
}
