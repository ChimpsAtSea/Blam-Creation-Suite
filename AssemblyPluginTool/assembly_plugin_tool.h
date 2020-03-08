#pragma once
class c_assembly_plugin_tool
{
public:
	c_assembly_plugin_tool(const wchar_t* file_path);

private:
	int parse_plugin_file(const wchar_t* file_path);
	int parse_node(pugi::xml_node& node);
};

