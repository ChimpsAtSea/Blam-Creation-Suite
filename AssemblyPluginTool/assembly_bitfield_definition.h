#pragma once

class c_assembly_plugin_tool;
class c_assembly_structure_definition;

struct s_assembly_bit
{
	s_assembly_bit(
		std::string name,
		int index,
		std::string nice_name
	) :
		name(name),
		index(index),
		nice_name(nice_name)
	{


	}
	std::string name;
	int index;
	std::string nice_name;
};

class c_assembly_bitfield_definition
{
public:
	c_assembly_bitfield_definition(c_assembly_structure_definition& parent, c_assembly_plugin_tool& plugin_tool, const char* bitfield_name, pugi::xml_object_range<pugi::xml_node_iterator> nodes);
	c_assembly_structure_definition& parent;
	c_assembly_plugin_tool& plugin_tool;
	std::string unformatted_name;
	std::string name;
	std::string type_name;
	std::string nice_name;
	e_assembly_plugin_tool_error tool_error;

	std::vector<s_assembly_bit> bits;

	std::map<std::string, int> bit_name_tracker;
	std::string get_unique_bit_name(const std::string& name);
};
