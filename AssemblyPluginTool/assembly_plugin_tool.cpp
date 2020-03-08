#include "assemblyplugintool-private-pch.h"

#include <MantleLib/CacheInterface/tag_group_names.inl>

std::wstring tag_group_to_structure_name(const std::wstring& tag_group_str)
{
	char buffer[sizeof(int) + 1]{};
	snprintf(buffer, _countof(buffer), "%S", tag_group_str.c_str());
	int tag_group = _byteswap_ulong(*reinterpret_cast<int*>(buffer));
	
	for (std::pair<int, const char*>& tag_group_id_and_name_pair : tag_group_names)
	{
		if (tag_group_id_and_name_pair.first == tag_group)
		{
			std::string result = tag_group_id_and_name_pair.second;
			return std::wstring(result.begin(), result.end());
		}
	}
	printf("Warning: Failed to find structure name for '%S'\n", tag_group_str.c_str());
	return tag_group_str;
}

c_assembly_plugin_tool::c_assembly_plugin_tool(const wchar_t* file_name, const wchar_t* file_path, const wchar_t* output_directory) :
	file_name(file_name),
	file_path(file_path),
	output_directory(output_directory),
	tag_definition(nullptr)
{
	e_assembly_plugin_tool_error result = parse_plugin_file();
	if (result != _apt_error_ok)
	{
		throw;
	}

	std::wstring output_file_name = std::wstring(file_name);
	output_file_name = output_file_name.substr(0, output_file_name.rfind(L"."));
	output_file_name = tag_group_to_structure_name(output_file_name);
	output_file_name += L".cpp";
	std::wstring output_file_path = std::wstring(output_directory) + output_file_name; // #TODO: convert the file name to the structure name

	char* existing_file_contents = nullptr;
	{
		FILE* output_file = _wfopen(output_file_path.c_str(), L"rb");
		if (output_file)
		{
			fseek(output_file, 0, SEEK_SET);
			size_t file_size = static_cast<size_t>(_ftelli64(output_file));
			fseek(output_file, 0, SEEK_END);
			existing_file_contents = new char[file_size + 1] {};
			size_t bytes_read = 0;
			while (bytes_read < file_size)
				bytes_read += fread(existing_file_contents, 1, file_size - bytes_read, output_file);
			
			fclose(output_file);
		}
	}

	std::stringstream output_stream;
	tag_definition->write(output_stream);
	std::string output_contents = output_stream.str();

	if (!existing_file_contents || (output_contents != existing_file_contents))
	{
		FILE* output_file = _wfopen(output_file_path.c_str(), L"wb");
		fwrite(output_contents.c_str(), 1, output_contents.length(), output_file);
		assert(output_file != nullptr);
		fclose(output_file);
	}

	if (existing_file_contents)
	{
		delete existing_file_contents;
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

	tag_definition = new c_assembly_structure_definition(*this, "TAG DEFINITION", plugin_node.children());
	tag_definition->print_debug();
	return tag_definition->tool_error;
}
