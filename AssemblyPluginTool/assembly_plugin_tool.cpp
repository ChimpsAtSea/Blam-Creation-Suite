#include "assemblyplugintool-private-pch.h"

using namespace pugi;

enum e_assembly_plugin_tool_error
{
	_apt_error_ok,
	_apt_error_failed_to_load_file,
	_apt_error_failed_to_find_plugin_node,

};

c_assembly_plugin_tool::c_assembly_plugin_tool(const wchar_t* file_path)
{
	int result = parse_plugin_file(file_path);
	if (result != _apt_error_ok)
	{
		throw;
	}
}

int c_assembly_plugin_tool::parse_plugin_file(const wchar_t* file_path)
{
	xml_document doc;
	xml_parse_result result = doc.load_file(file_path);
	if (result == -1) return _apt_error_failed_to_load_file;

	xml_node plugin_node = doc.first_child();
	if (_stricmp(plugin_node.name(), "plugin") != 0) return _apt_error_failed_to_find_plugin_node;

	for (xml_node node : plugin_node.children())
	{
		int result = parse_node(node);
		if (result != _apt_error_ok) return result;
	}

	return _apt_error_ok;
}

int c_assembly_plugin_tool::parse_node(pugi::xml_node& node)
{
	printf("%s\n", node.name());



	return _apt_error_ok;
}
