#include "assemblyplugintool-private-pch.h"

c_assembly_field_definition::c_assembly_field_definition(
	c_assembly_structure_definition& parent,
	e_assembly_data_type data_type,
	const char* _field_name,
	uint32_t array_size,
	c_assembly_structure_definition* structure_definition,
	c_assembly_bitfield_definition* bitfield_definition,
	c_assembly_enum_definition* enum_definition,
	std::string comment) :
	parent(parent),
	data_type(data_type),
	unformatted_name(_field_name),
	field_name(_field_name),
	nice_name(_field_name),
	array_size(array_size),
	structure_definition(structure_definition),
	bitfield_definition(bitfield_definition),
	enum_definition(enum_definition),
	comment(comment)
{
	field_name = c_assembly_plugin_tool::format_source_friendly_name(unformatted_name);
	field_name = parent.get_unique_field_name(field_name);

	switch (data_type)
	{
	case _data_type_reflexive:
		field_name += "_block";
		break;
	case _data_type_tagref:
		field_name += "_reference";
		break;
	case _data_type_dataref:
		field_name += "_data_reference";
		break;
	}

	if (nice_name == "Unknown")
	{
		int unknown_index = parent.get_next_unknown_type_index();
		nice_name.clear();
		field_name = "__unknown" + std::to_string(unknown_index);
	}

}
