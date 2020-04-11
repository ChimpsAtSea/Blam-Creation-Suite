#pragma once

class c_reflection_type_container;

class c_reflection_field_container
{
public:
	c_reflection_field_container();

	std::string field_name;
	std::string field_nice_name;
	e_legacy_reflection_type_category legacy_reflection_type_category;
	e_legacy_primitive_type primitive_type;
	c_reflection_type_container* field_type;
	uint64_t array_size;
	uint64_t static_string_size;
	uint64_t offset;
	uint64_t data_size;
	bool is_hidden_by_default;
};


