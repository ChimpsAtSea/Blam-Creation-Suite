#pragma once

class c_reflection_type_container
{
public:
	c_reflection_type_container() = delete;
	c_reflection_type_container(const c_reflection_type_container&) = delete;
	c_reflection_type_container& operator=(const c_reflection_type_container&) = delete;

	c_reflection_type_container(
		e_reflection_type_class type_class,
		std::string type_name,
		std::string qualified_name,
		std::string nice_name,
		std::string description,
		bool exclude_from_generated_code = false) :
		type_class(type_class),
		type_name(type_name),
		qualified_name(qualified_name),
		nice_name(nice_name),
		description(description),
		exclude_from_generated_code(exclude_from_generated_code)
	{

	}

	e_reflection_type_class type_class;
	std::string type_name;
	std::string qualified_name;
	std::string nice_name;
	std::string description;
	bool exclude_from_generated_code;

	std::vector<c_reflection_field_container*> field_containers;
	std::vector<c_reflection_enum_name_container*> enum_name_containers;
};

