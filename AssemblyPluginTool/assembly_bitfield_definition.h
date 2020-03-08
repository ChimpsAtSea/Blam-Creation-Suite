#pragma once

class c_assembly_plugin_tool;

using c_assembly_bit = std::pair<std::string, int>;

class c_assembly_bitfield_definition
{
public:
	c_assembly_bitfield_definition(c_assembly_plugin_tool& plugin_tool, const char* name, pugi::xml_object_range<pugi::xml_node_iterator> nodes);
	c_assembly_plugin_tool& plugin_tool;
	std::string bitfield_name;
	e_assembly_plugin_tool_error tool_error;

	std::vector<c_assembly_bit> bits;
};
