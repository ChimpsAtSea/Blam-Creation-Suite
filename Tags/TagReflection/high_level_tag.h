#pragma once

template<typename T>
void high_level_tag_ctor(T* tag) {}

template<typename T>
void high_level_tag_dtor(T* tag) {}

class h_type
{
public:
	h_type(const blofeld::s_tag_struct_definition& tag_struct_definition, uint32_t type_size);
	virtual ~h_type();

	virtual void* get_field_pointer(const blofeld::s_tag_field& field) = 0;

	template<typename T>
	T* get_field_pointer(const blofeld::s_tag_field& field)
	{
		return static_cast<T*>(get_field_pointer(field));
	}

	const blofeld::s_tag_struct_definition& tag_struct_definition;
	const uint32_t type_size;
};

class h_group;

class h_tag :
	public h_type
{
public:
	h_tag(const blofeld::s_tag_group& tag_group, h_group* group, const char* tag_name, uint32_t type_size);
	virtual ~h_tag();

	c_fixed_path tag_name;
	const blofeld::s_tag_group& tag_group;
	h_group* const group;
};

class h_group
{
public:
	h_group(e_engine_type engine_type, e_platform_type platform_type, e_build build, const blofeld::s_tag_group& tag_group);
	~h_group();

	h_tag& create_tag_instance(const char* filepath);

	std::vector<h_tag*> tags;
	e_engine_type const engine_type;
	e_platform_type const platform_type;
	e_build const build;
	const blofeld::s_tag_group& tag_group;
};
