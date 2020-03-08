#pragma once

class c_assembly_plugin_tool
{
public:
	c_assembly_plugin_tool(const wchar_t* file_name, const wchar_t* file_path, const wchar_t* output_file_path);

private:
	e_assembly_plugin_tool_error parse_plugin_file();

	const wchar_t* file_name;
	const wchar_t* file_path;
	const wchar_t* output_file_path;
};

