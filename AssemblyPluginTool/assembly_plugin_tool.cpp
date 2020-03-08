#include "assemblyplugintool-private-pch.h"

c_assembly_plugin_tool::c_assembly_plugin_tool(const wchar_t* file_name, const wchar_t* file_path, const wchar_t* output_file_path) :
	file_name(file_name),
	file_path(file_path),
	output_file_path(output_file_path)
{
	e_assembly_plugin_tool_error result = parse_plugin_file();
	if (result != _apt_error_ok)
	{
		throw;
	}
}

e_assembly_plugin_tool_error c_assembly_plugin_tool::parse_plugin_file()
{
	log("Parsing %S\n", file_name);

	xml_document doc;
	xml_parse_result result = doc.load_file(file_path);
	if (result == -1) return _apt_error_failed_to_load_file;

	xml_node plugin_node = doc.first_child();
	if (!nodecmp(plugin_node, "plugin")) return _apt_error_failed_to_find_plugin_node;

	c_assembly_structure_definition tag_definition(*this, "TAG DEFINITION", plugin_node.children());

	tag_definition.print_debug();

	return tag_definition.tool_error;
}
