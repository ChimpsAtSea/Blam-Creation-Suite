#pragma once

template<typename T>
void high_level_tag_ctor(T* tag) {}

template<typename T>
void high_level_tag_dtor(T* tag) {}

class c_high_level_type
{
public:
	c_high_level_type(const blofeld::s_tag_struct_definition& struct_definition, uint32_t type_size);
	virtual ~c_high_level_type();

	virtual void* get_field_pointer(const blofeld::s_tag_field& field) = 0;

	template<typename T>
	T* get_field_pointer(const blofeld::s_tag_field& field)
	{
		return static_cast<T*>(get_field_pointer(field));
	}

	const blofeld::s_tag_struct_definition& struct_definition;
	const uint32_t type_size;
};

class c_high_level_tag :
	public c_high_level_type
{
public:
	c_high_level_tag(const blofeld::s_tag_group& tag_group, const char* tag_name, uint32_t type_size);
	virtual ~c_high_level_tag();

	c_fixed_path tag_name;
	const blofeld::s_tag_group& tag_group;
};
