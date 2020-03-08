#pragma once

class c_assembly_plugin_tool;
class c_assembly_structure_definition;

struct s_assembly_enum
{
	s_assembly_enum(
		std::string name,
		int value,
		std::string nice_name
	) :
		name(name),
		value(value),
		nice_name(nice_name)
	{


	}
	std::string name;
	int value;
	std::string nice_name;
};

class c_assembly_enum_definition
{
public:
	c_assembly_enum_definition(c_assembly_structure_definition& parent, c_assembly_plugin_tool& plugin_tool, const char* unformatted_name, pugi::xml_object_range<pugi::xml_node_iterator> nodes);
	c_assembly_structure_definition& parent;
	c_assembly_plugin_tool& plugin_tool;
	std::string unformatted_name;
	std::string name;
	std::string type_name;
	std::string nice_name;
	e_assembly_plugin_tool_error tool_error;

	std::vector<s_assembly_enum> enums;

	std::map<std::string, int> enum_name_tracker;
	std::string get_unique_enum_name(const std::string& name);
};

