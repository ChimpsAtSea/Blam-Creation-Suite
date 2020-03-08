#include "assemblyplugintool-private-pch.h"

c_assembly_bitfield_definition::c_assembly_bitfield_definition(c_assembly_plugin_tool& plugin_tool, const char* name, pugi::xml_object_range<pugi::xml_node_iterator> nodes) :
	plugin_tool(plugin_tool),
	bitfield_name(name),
	tool_error(_apt_error_ok)
{
	int current_index = 0;
	for (xml_node node : nodes)
	{
		if (nodecmp(node, "bit"))
		{
			xml_attribute index_attribute = node.attribute("index");
			current_index = index_attribute.as_int(current_index + 1);

			xml_attribute name_attribute = node.attribute("name");
			std::string default_name = std::string("Bit ") + std::to_string(current_index);
			const char* bit_name = name_attribute.as_string(default_name.c_str());

			bits.emplace_back(bit_name, current_index);
		}
	}
}
