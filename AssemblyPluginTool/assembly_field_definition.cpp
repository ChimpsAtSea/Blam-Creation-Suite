#include "assemblyplugintool-private-pch.h"

c_assembly_field_definition::c_assembly_field_definition(
	e_assembly_data_type data_type,
	const char* field_name,
	uint32_t array_size,
	c_assembly_structure_definition* structure_definition,
	c_assembly_bitfield_definition* bitfield_definition,
	c_assembly_enum_definition* enum_definition) :
	data_type(data_type),
	field_name(field_name),
	array_size(array_size),
	structure_definition(structure_definition),
	bitfield_definition(bitfield_definition),
	enum_definition(enum_definition)
{

}
