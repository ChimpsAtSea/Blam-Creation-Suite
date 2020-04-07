#include "assemblyplugintool-private-pch.h"

c_assembly_enum_definition::c_assembly_enum_definition(c_assembly_structure_definition& parent, c_assembly_plugin_tool& plugin_tool, const char* enum_name, pugi::xml_object_range<pugi::xml_node_iterator> nodes) :
	parent(parent),
	plugin_tool(plugin_tool),
	unformatted_name(enum_name),
	name(enum_name),
	type_name(enum_name),
	nice_name(enum_name),
	tool_error(_apt_error_ok)
{
	name = c_assembly_plugin_tool::format_source_friendly_name(unformatted_name);
	name = parent.get_unique_type_name(name);
	type_name = std::string("e_") + name;

	int current_index = 0;
	for (xml_node node : nodes)
	{
		if (nodecmp(node, "option"))
		{
			xml_attribute value_attribute = node.attribute("index");
			uint64_t enum_value = value_attribute.as_ullong(current_index);

			xml_attribute name_attribute = node.attribute("name");
			if (name_attribute.empty())
				return_error(_apt_error_failed_to_find_name_attribute);

			std::string enum_nice_name = name_attribute.as_string();
			std::string enum_name = std::string("_") + name + "_" + c_assembly_plugin_tool::format_source_friendly_name(enum_nice_name);
			enum_name = get_unique_enum_name(enum_name);

			enums.emplace_back(enum_name, enum_value, enum_nice_name);

			current_index++;
		}
	}
}

std::string c_assembly_enum_definition::get_unique_enum_name(const std::string& name)
{
	std::string result = name;

	int index = enum_name_tracker[name]++;
	if (index > 0)
	{
		result += std::to_string(index);
	}

	return result;
}
