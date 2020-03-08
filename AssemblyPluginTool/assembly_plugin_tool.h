#pragma once

class c_assembly_plugin_tool
{
public:
	c_assembly_plugin_tool(const wchar_t* file_name, const wchar_t* file_path, const wchar_t* output_directory);
	~c_assembly_plugin_tool();
	static void replace_instances_in_string(std::string& data, std::string search, std::string replace);
	static std::string format_source_friendly_name(const std::string& name);

private:
	e_assembly_plugin_tool_error parse_plugin_file();

	const wchar_t* file_name;
	const wchar_t* file_path;
	const wchar_t* output_directory;
	c_assembly_structure_definition* tag_definition;

	std::wstring output_file_name;
	std::wstring output_file_path;
	std::string tag_group_name;
	std::string tag_group_short_name;

};

