#pragma once

class c_reflection_type_container;

class c_reflection_field_container
{
public:
	c_reflection_field_container();

	std::string field_name;
	std::string field_nice_name;
	ReflectionTypeCategory reflection_type_category;
	PrimitiveType primitive_type;
	c_reflection_type_container* field_type;
	uint64_t array_size;
	uint64_t offset;
	uint64_t data_size;
	bool is_hidden_by_default;
};


