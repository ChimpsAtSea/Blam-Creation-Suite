#include "assemblyplugintool-private-pch.h"

c_assembly_enum_definition::c_assembly_enum_definition(c_assembly_plugin_tool& plugin_tool, const char* name, pugi::xml_object_range<pugi::xml_node_iterator> nodes) :
	plugin_tool(plugin_tool),
	enum_name(name),
	tool_error(_apt_error_ok)
{
	int current_index = 0;
	for (xml_node node : nodes)
	{
		if (nodecmp(node, "option"))
		{
			xml_attribute value_attribute = node.attribute("index");
			current_index = value_attribute.as_int(current_index + 1);

			xml_attribute name_attribute = node.attribute("name");
			if (name_attribute.empty())
				return_error(_apt_error_failed_to_find_name_attribute);

			const char* enum_name = name_attribute.as_string();

			enums.emplace_back(enum_name, current_index);
		}
	}
}
