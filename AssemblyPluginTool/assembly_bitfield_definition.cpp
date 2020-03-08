#include "assemblyplugintool-private-pch.h"

c_assembly_bitfield_definition::c_assembly_bitfield_definition(c_assembly_structure_definition& parent, c_assembly_plugin_tool& plugin_tool, const char* bitfield_name, pugi::xml_object_range<pugi::xml_node_iterator> nodes) :
	parent(parent),
	plugin_tool(plugin_tool),
	unformatted_name(bitfield_name),
	name(bitfield_name),
	type_name(bitfield_name),
	nice_name(bitfield_name),
	tool_error(_apt_error_ok)
{
	name = c_assembly_plugin_tool::format_source_friendly_name(unformatted_name);
	name = parent.get_unique_type_name(name);
	type_name = std::string("b_") + name;

	int current_index = 0;
	for (xml_node node : nodes)
	{
		if (nodecmp(node, "bit"))
		{
			xml_attribute index_attribute = node.attribute("index");
			current_index = index_attribute.as_int(current_index + 1);

			xml_attribute name_attribute = node.attribute("name");
			std::string default_name = std::string("Bit ") + std::to_string(current_index);

			std::string bit_nice_name = name_attribute.as_string(default_name.c_str());
			std::string bit_name = std::string("_") + name + "_" + c_assembly_plugin_tool::format_source_friendly_name(bit_nice_name);
			bit_name = get_unique_bit_name(bit_name);

			bits.emplace_back(bit_name, current_index, bit_nice_name);
		}
	}
}

std::string c_assembly_bitfield_definition::get_unique_bit_name(const std::string& name)
{
	std::string result = name;

	int index = bit_name_tracker[name]++;
	if (index > 0)
	{
		result += std::to_string(index);
	}

	return result;
}
