#pragma once

class c_reflection_type_container
{
public:
	std::string type_name;
	std::string qualified_name;
	std::string nice_name;
	std::string description;
	e_reflection_type_class type_class;

	std::vector<c_reflection_field_container*> field_containers;
};

