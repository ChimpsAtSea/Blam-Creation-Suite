#pragma once

//template<typename T>
//void high_level_tag_ctor(T* tag) {}
//
//template<typename T>
//void high_level_tag_dtor(T* tag) {}

#define high_level_tag_ctor(...)
#define high_level_tag_dtor(...)

class h_type;
class h_object;

class h_notification_system
{
private:
	static constexpr int32_t stack_size = 1024;
	static void* stack[stack_size];
	static int32_t index;

public:
	static void push_value(void* userdata);
	static void pop_value();
	static void* get_value();
};

class c_data_change_notification
{
public:
	c_data_change_notification();
	c_data_change_notification(void* userdata);

	h_type* type;
	const blofeld::s_tag_field* field;
	void* userdata;
};

using s_notification_listener_func = void (*)(void* userdata, const c_data_change_notification& notification);

struct s_notification_listener
{
	s_notification_listener_func callback;
	void* userdata;
	s_notification_listener* next;
};

class h_type
{
public:
	h_type();
	virtual ~h_type();

	void set_parent(h_type* parent);
	void add_notification_listener(s_notification_listener_func callback, void* userdata);
	void remove_notification_listener(s_notification_listener_func callback, void* userdata);
	void notify_data_change(const c_data_change_notification& notification);

protected:
	h_type* parent;
	s_notification_listener* notification_listeners;
};

class h_object :
	public h_type
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

template<typename type, typename parent_type, uint32_t field_index>
class h_field
{
public:
	explicit h_field() : value() {};

	type& operator=(const type& new_value);

protected:
	type value;
};

#define h_field_func_impl(field_type, parent_type, _field_index, _field_name)										\
field_type& h_field<field_type, parent_type, _field_index>::operator=(field_type const& new_value)					\
{																													\
	uint32_t _field_offset = offsetof(parent_type, _field_name);													\
	h_type* _type = reinterpret_cast<h_type*>(reinterpret_cast<uintptr_t>(this) - _field_offset);					\
																													\
	if constexpr (/*std::is_pointer<field_type>::value ||*/ std::is_arithmetic<field_type>::value)					\
	{																												\
		if (value != new_value)																						\
		{																											\
			auto _old_value = value;																				\
			value = new_value;																						\
																													\
			c_data_change_notification _notification;															\
																													\
			_type->notify_data_change(_notification);																\
		}																											\
	}																												\
	else																											\
	{																												\
		value = new_value;																							\
																													\
		c_data_change_notification _notification;																\
																													\
		_type->notify_data_change(_notification);																	\
	}																												\
	return value;																									\
}	

class h_data :
	public std::vector<char>,
	public h_type
{
public:
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
	h_group* group;
};

class h_group :
	public h_type
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

class h_enumerable :
	public h_type
{
public:
	virtual h_object& operator[](uint32_t index) = 0;
	virtual h_object& get(uint32_t index) = 0;
	virtual h_object* data() = 0;
	virtual uint32_t type_size() = 0;
	virtual uint32_t size() = 0;
	virtual uint32_t data_size() = 0;
};

template<typename h_custom_type, uint32_t _size>
struct h_typed_array :
	public std::array<h_custom_type, _size>,
	public h_enumerable
{
public:
	virtual h_custom_type & operator[](uint32_t index) final
	{
		return std::array<h_custom_type, _size>::operator [](index);
	}

	virtual h_custom_type & get(uint32_t index) final
	{
		return std::array<h_custom_type, _size>::operator [](index);
	}

	virtual h_custom_type * data() final
	{
		return std::array<h_custom_type, _size>::data();
	}

	virtual uint32_t type_size() final
	{
		return h_custom_type::type_size;
	}

	virtual uint32_t size() final
	{
		return _size;
	}

	virtual uint32_t data_size() final
	{
		return _size * sizeof(h_custom_type);
	}
};

class h_block :
	public h_enumerable
{
public:
	virtual h_object& emplace_back() = 0;
	virtual h_object& emplace_back(const h_object& value) = 0;
	virtual void reserve(uint32_t count) = 0;
	virtual void resize(uint32_t count) = 0;
	virtual void insert_hole(uint32_t index, uint32_t count) = 0;
	virtual void remove(uint32_t index) = 0;
	virtual void clear() = 0;
};

template<typename h_custom_type>
struct h_typed_block :
	public std::vector<h_custom_type>,
	public h_block
{
public:
	virtual h_custom_type& operator[](uint32_t index) final;
	virtual h_custom_type& get(uint32_t index) final;
	virtual h_custom_type* data() final;
	virtual uint32_t type_size() final;
	virtual uint32_t size() final;
	virtual uint32_t data_size() final;
	virtual h_custom_type& emplace_back() final;
	virtual h_custom_type& emplace_back(const h_object& value) final;
	virtual void reserve(uint32_t count) final;
	virtual void resize(uint32_t count) final;
	virtual void insert_hole(uint32_t index, uint32_t count) final;
	virtual void remove(uint32_t index) final;
	virtual void clear() final;
};
																																							
#ifdef _DEBUG																																				
#define k_typed_block_func_impl_debug 1																														
#else																																						
#define k_typed_block_func_impl_debug 0																														
#endif																																						
#define h_typed_block_func_impl(h_custom_type)																												\
template<>																																					\
h_custom_type& h_typed_block<h_custom_type>::operator[](uint32_t index)																						\
{																																							\
	return std::vector<h_custom_type>::operator [](index);																									\
}																																							\
																																							\
template<>																																					\
h_custom_type& h_typed_block<h_custom_type>::get(uint32_t index)																							\
{																																							\
	return std::vector<h_custom_type>::operator [](index);																									\
}																																							\
																																							\
template<>																																					\
h_custom_type* h_typed_block<h_custom_type>::data()																											\
{																																							\
	auto values = std::vector<h_custom_type>::data();																										\
	return values;																																			\
}																																							\
																																							\
template<>																																					\
uint32_t h_typed_block<h_custom_type>::type_size()																											\
{																																							\
	return h_custom_type::type_size;																														\
}																																							\
																																							\
template<>																																					\
uint32_t h_typed_block<h_custom_type>::size()																												\
{																																							\
	return static_cast<uint32_t>(std::vector<h_custom_type>::size());																						\
}																																							\
																																							\
template<>																																					\
uint32_t h_typed_block<h_custom_type>::data_size()																											\
{																																							\
	return static_cast<uint32_t>(std::vector<h_custom_type>::size() * sizeof(h_custom_type));																\
}																																							\
																																							\
template<>																																					\
h_custom_type& h_typed_block<h_custom_type>::emplace_back()																									\
{																																							\
	return std::vector<h_custom_type>::emplace_back();																										\
}																																							\
																																							\
template<>																																					\
h_custom_type& h_typed_block<h_custom_type>::emplace_back(const h_object& value)																			\
{																																							\
	if constexpr (k_typed_block_func_impl_debug)																											\
	{																																						\
		const h_custom_type* typed_value = dynamic_cast<const h_custom_type*>(&value);																		\
		DEBUG_ASSERT(typed_value != nullptr);																												\
		return std::vector<h_custom_type>::emplace_back(*typed_value);																						\
	}																																						\
	else																																					\
	{																																						\
		const h_custom_type* typed_value = static_cast<const h_custom_type*>(&value);																		\
		return std::vector<h_custom_type>::emplace_back(*typed_value);																						\
	}																																						\
}																																							\
																																							\
template<>																																					\
void h_typed_block<h_custom_type>::reserve(uint32_t count)																									\
{																																							\
	std::vector<h_custom_type>::reserve(count);																												\
}																																							\
																																							\
template<>																																					\
void h_typed_block<h_custom_type>::resize(uint32_t count)																									\
{																																							\
	std::vector<h_custom_type>::resize(count);																												\
}																																							\
																																							\
template<>																																					\
void h_typed_block<h_custom_type>::insert_hole(uint32_t index, uint32_t count)																				\
{																																							\
	std::vector<h_custom_type>::insert(std::vector<h_custom_type>::begin() + index, count, h_custom_type());												\
}																																							\
																																							\
template<>																																					\
void h_typed_block<h_custom_type>::remove(uint32_t index)																									\
{																																							\
	std::vector<h_custom_type>::erase(std::vector<h_custom_type>::begin() + index);																			\
}																																							\
																																							\
template<>																																					\
void h_typed_block<h_custom_type>::clear()																													\
{																																							\
	std::vector<h_custom_type>::clear();																													\
}																																								


