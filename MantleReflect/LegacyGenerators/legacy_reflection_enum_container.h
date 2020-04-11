#pragma once

class c_reflection_type_container;

class c_reflection_enum_value_container
{
public:
	c_reflection_enum_value_container();

	std::string value_name;
	uint64_t value;
};
