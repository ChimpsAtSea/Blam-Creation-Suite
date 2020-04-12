#pragma once

class c_reflection_type_container;


class c_reflection_field_container
{
public:
	std::string field_name;
	std::string nice_name;
	std::string description;
	std::string qualified_decl;
	c_reflection_type_container* type_container;
	e_reflection_type_class type_class;
};

