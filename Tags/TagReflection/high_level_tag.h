#pragma once

template<typename T>
void high_level_tag_ctor(T* tag) {}

template<typename T>
void high_level_tag_dtor(T* tag) {}

class c_high_level_type
{
public:
	c_high_level_type(blofeld::s_tag_struct_definition& struct_definition);
	const blofeld::s_tag_struct_definition& struct_definition;
};

class c_high_level_tag :
	public c_high_level_type
{
public:
	c_high_level_tag(
		blofeld::s_tag_struct_definition& struct_definition,
		const char* tag_name, 
		c_high_level_type* parent, 
		const blofeld::s_tag_group& tag_group);

	virtual void* get_field_pointer(const blofeld::s_tag_field& field) = 0;

	c_fixed_path tag_name;
	c_high_level_type* parent;
	const blofeld::s_tag_group& tag_group;
};
