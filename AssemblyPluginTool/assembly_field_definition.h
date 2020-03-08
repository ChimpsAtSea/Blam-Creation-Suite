#pragma once

class c_assembly_structure_definition;
class c_assembly_bitfield_definition;
class c_assembly_enum_definition;

class c_assembly_field_definition
{
public:
	c_assembly_field_definition(
		c_assembly_structure_definition& parent,
		e_assembly_data_type data_type,
		const char* unformatted_name,
		uint32_t array_size = 0,
		c_assembly_structure_definition* structure_definition = nullptr,
		c_assembly_bitfield_definition* bitfield_definition = nullptr,
		c_assembly_enum_definition* enum_definition = nullptr,
		std::string comment = "");
	c_assembly_structure_definition& parent;
	e_assembly_data_type data_type;
	std::string unformatted_name;
	std::string field_name;
	std::string nice_name;
	std::string comment;
	uint32_t array_size;
	c_assembly_structure_definition* structure_definition;
	c_assembly_bitfield_definition* bitfield_definition;
	c_assembly_enum_definition* enum_definition;
};

