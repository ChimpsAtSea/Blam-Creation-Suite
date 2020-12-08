#pragma once

template<typename T>
void high_level_tag_ctor(T* tag) {}

template<typename T>
void high_level_tag_dtor(T* tag) {}

class h_object
{
public:
	virtual ~h_object();

	virtual uint32_t get_type_size() const = 0;
	virtual const blofeld::s_tag_struct_definition& get_blofeld_struct_definition() const = 0;
	virtual void* get_field_pointer(const blofeld::s_tag_field& field) = 0;
	virtual bool is_field_active(const blofeld::s_tag_field& field) = 0;

	template<typename T>
	T* get_field_pointer(const blofeld::s_tag_field& field)
	{
		return static_cast<T*>(get_field_pointer(field));
	}
};

class h_group;

class h_tag :
	public h_object
{
public:
	h_tag(h_group* group, const char* tag_filepath);
	virtual ~h_tag();

	virtual const blofeld::s_tag_group& get_blofeld_group_definition() const = 0;

	c_fixed_path tag_filepath;
	c_fixed_path tag_filename;
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

struct h_block
{
public:
	virtual h_object& emplace_back() = 0;
	virtual h_object* data() = 0;
	virtual h_object& get(uint32_t index) = 0;
	virtual uint32_t type_size() = 0;
	virtual uint32_t size() = 0;
	virtual void reserve(uint32_t count) = 0;
	virtual void resize(uint32_t count) = 0;
};

template<typename h_custom_type>
struct h_typed_block :
	public std::vector<h_custom_type>,
	public h_block
{
public:
	virtual h_custom_type& emplace_back() final
	{
		auto& value = std::vector<h_custom_type>::emplace_back();
		return value;
	}

	virtual h_custom_type& get(uint32_t index) final
	{
		return std::vector<h_custom_type>::operator [](index);
	}

	virtual h_custom_type* data() final
	{
		auto values = std::vector<h_custom_type>::data();
		return values;
	}

	virtual uint32_t type_size() final
	{
		return h_custom_type::type_size;
	}

	virtual uint32_t size() final
	{
		return static_cast<uint32_t>(std::vector<h_custom_type>::size());
	}

	virtual void reserve(uint32_t count) final
	{
		std::vector<h_custom_type>::reserve(count);
	}

	virtual void resize(uint32_t count) final
	{
		std::vector<h_custom_type>::resize(count);
	}
};
