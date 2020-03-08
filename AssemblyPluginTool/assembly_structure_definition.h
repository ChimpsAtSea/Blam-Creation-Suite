#pragma once

class c_assembly_plugin_tool;
class c_assembly_field_definition;

class c_assembly_structure_definition
{
public:
	c_assembly_structure_definition(c_assembly_plugin_tool& plugin_tool, const char* name, pugi::xml_object_range<pugi::xml_node_iterator> nodes);
	c_assembly_plugin_tool& plugin_tool;
	std::string structure_name;
	e_assembly_plugin_tool_error tool_error;

	std::vector<c_assembly_field_definition> fields;

	void print_debug(int level = 0);
};

