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

using h_string_id = c_fixed_string_2048;

class h_notification_system
{
private:
	h_notification_system() = delete;
	h_notification_system(h_notification_system const&) = delete;

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
	h_type(h_type* parent = nullptr);
	virtual ~h_type();

	void add_notification_listener(s_notification_listener_func callback, void* userdata);
	void remove_notification_listener(s_notification_listener_func callback, void* userdata);
	void notify_data_change(const c_data_change_notification& notification);

#ifndef __INTELLISENSE__
	/*
#TODO: I don't think this should be exposed.
Makes more sense if parent is const for the
lifetime of the type and we use move/assignment
on all types to track changes

This has to be exposed currently because h_typed_array has no way
to specify a default value and this has to be called on all elements
*/
	void _set_parent(h_type* parent);
#endif

protected:
	h_type(h_type const&) = default;

	h_type* parent;
	s_notification_listener* notification_listeners;
};

class h_resource :
	public h_type
{
public:
	h_resource(h_type* parent = nullptr);
	virtual ~h_resource();

	s_tag_resource _original_resource;
};

class h_interop :
	public h_type
{
public:
	h_interop();
	virtual ~h_interop();

};

class h_object :
	public h_type
{
public:
	h_object(h_type* parent = nullptr);
	virtual ~h_object();

	virtual uint32_t get_high_level_type_size() const = 0;
	virtual uint32_t get_low_level_type_size() const = 0;
	virtual void* get_field_data(const blofeld::s_tag_field& field) = 0;
	inline const void* get_field_data(const blofeld::s_tag_field& field) const
	{
		return const_cast<h_object*>(this)->get_field_data(field);
	}
	virtual bool is_field_active(const blofeld::s_tag_field& field) const = 0;
	virtual const blofeld::s_tag_struct_definition& get_blofeld_struct_definition() const = 0;
	virtual const blofeld::s_tag_field* const* get_blofeld_field_list() const = 0;

	template<typename T>
	T* get_field_data(const blofeld::s_tag_field& field)
	{
		return static_cast<T*>(get_field_data(field));
	}

	//protected:
	//	h_object(h_object const&) = default;
};

template<typename field_type, typename parent_type, uint32_t _field_index>
class h_field
{
public:
	explicit h_field();

	field_type& operator=(const field_type& new_value);
	bool operator==(const field_type& new_value) const; // #TODO: is it okay to assume the compiler is optimizing here?

	template<typename t_result>
	operator t_result() const
	{
		return static_cast<t_result>(value);
	}

public:
	field_type value;
};

#define h_field_func_impl(field_type, parent_type, _field_index, _field_name)										\
template<>																											\
h_field<field_type, parent_type, _field_index>::h_field() : value() {}												\
																													\
bool h_field<field_type, parent_type, _field_index>::operator==(field_type const& new_value) const					\
{																													\
	bool is_same = &this->value == &new_value || memcmp(&value, &new_value, sizeof(value)) == 0;					\
	return is_same;																									\
}																													\
																													\
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
			c_data_change_notification _notification;																\
																													\
			_type->notify_data_change(_notification);																\
		}																											\
	}																												\
	else																											\
	{																												\
		value = new_value;																							\
																													\
		c_data_change_notification _notification;																	\
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
protected:
	h_tag(h_group* group, const char* tag_filepath);
	h_tag(h_type* parent);

public:
	virtual ~h_tag();
	virtual const blofeld::s_tag_group& get_blofeld_group_definition() const = 0;

public: // #TODO: protected
	c_fixed_path tag_filepath;
	c_fixed_path tag_filename;
	h_group* group;

	//protected:
	//	h_tag(h_tag const&) = default;
};

class h_group :
	public h_type
{
public:
	h_group(s_engine_platform_build engine_platform_build, const blofeld::s_tag_group& tag_group);

	~h_group();

	h_tag& create_tag_instance(const char* filepath);

	std::vector<h_tag*> tags;
	s_engine_platform_build const engine_platform_build;
	const blofeld::s_tag_group& tag_group;

protected:
	h_group(h_group const&) = default;
};

class h_enumerable :
	public h_type
{
public:
	h_enumerable(h_type* parent = nullptr);

	virtual h_object& operator[](uint32_t index) = 0;
	virtual const h_object& operator[](uint32_t index) const = 0;
	virtual h_object& get(uint32_t index) = 0;
	virtual const h_object& get(uint32_t index) const = 0;
	virtual const h_object* data() = 0;
	virtual uint32_t get_high_level_type_size() const = 0;
	virtual uint32_t get_low_level_type_size() const = 0;
	virtual uint32_t size() const = 0;
	virtual uint32_t data_size() const = 0;

	//protected:
	//	h_enumerable(h_enumerable const&) = default;
};

template<typename h_custom_type, uint32_t _size>
class h_typed_array :
	public std::array<h_custom_type, _size>,
	public h_enumerable
{
public:
	h_typed_array(h_type * parent = nullptr) :
		h_enumerable(parent)
	{
		for (uint32_t index = 0; index < _size; index++)
		{
			// #TODO: is there a better way to do this?
			// _set_parent is kind of nasty to expose
			get(index)._set_parent(this); 
		}
	}

	virtual h_custom_type& operator[](uint32_t index) final
	{
		return std::array<h_custom_type, _size>::operator [](index);
	}

	virtual const h_custom_type& operator[](uint32_t index) const final
	{
		return std::array<h_custom_type, _size>::operator [](index);
	}

	virtual h_custom_type & get(uint32_t index) final
	{
		return std::array<h_custom_type, _size>::operator [](index);
	}

	virtual const h_custom_type& get(uint32_t index) const final
	{
		return std::array<h_custom_type, _size>::operator [](index);
	}

	virtual const h_custom_type * data() final
	{
		return std::array<h_custom_type, _size>::data();
	}

	virtual uint32_t get_high_level_type_size() const final
	{
		return h_custom_type::high_level_type_size;
	}

	virtual uint32_t get_low_level_type_size() const final
	{
		return h_custom_type::low_level_type_size;
	}

	virtual uint32_t size() const final
	{
		return _size;
	}

	virtual uint32_t data_size() const final
	{
		return _size * sizeof(h_custom_type);
	}

//protected:
//	h_typed_array(h_typed_array const&) = default;
};

class h_block :
	public h_enumerable
{
public:
	h_block(h_type* parent = nullptr);

	virtual h_object& emplace_back() = 0;
	virtual h_object& emplace_back(const h_object& value) = 0;
	virtual void reserve(uint32_t count) = 0;
	virtual void resize(uint32_t count) = 0;
	virtual void insert_hole(uint32_t index, uint32_t count) = 0;
	virtual void remove(uint32_t index) = 0;
	virtual void clear() = 0;

	//protected:
	//	h_block(h_block const&) = default;
};

template<typename h_custom_type>
class h_typed_block :
	public std::vector<h_custom_type>,
	public h_block
{
public:
	h_typed_block(h_type* parent = nullptr);

	virtual h_custom_type& operator[](uint32_t index) final;
	virtual const h_custom_type& operator[](uint32_t index) const final;
	virtual h_custom_type& get(uint32_t index) final;
	virtual const h_custom_type& get(uint32_t index) const final;
	virtual const h_custom_type* data() final;
	virtual uint32_t get_high_level_type_size() const final;
	virtual uint32_t get_low_level_type_size() const final;
	virtual uint32_t size() const final;
	virtual uint32_t data_size() const final;
	virtual h_custom_type& emplace_back() final;
	virtual h_custom_type& emplace_back(const h_object& value) final;
	virtual void reserve(uint32_t count) final;
	virtual void resize(uint32_t count) final;
	virtual void insert_hole(uint32_t index, uint32_t count) final;
	virtual void remove(uint32_t index) final;
	virtual void clear() final;

	//protected:
	//	h_typed_block(h_typed_block const&) = default;
};

#define _h_typed_block_ctor_impl(h_custom_type)																											\
template<>																																				\
h_typed_block<h_custom_type>::h_typed_block(h_type* parent) :																							\
	std::vector<h_custom_type>(),																														\
	h_block(parent)																																		\
{ }

#define _h_typed_block_array_operator_impl(h_custom_type)																								\
template<>																																				\
h_custom_type& h_typed_block<h_custom_type>::operator[](uint32_t index)																					\
{																																						\
	return std::vector<h_custom_type>::operator [](index);																								\
}																																						\
template<>																																				\
const h_custom_type& h_typed_block<h_custom_type>::operator[](uint32_t index) const																		\
{																																						\
	return std::vector<h_custom_type>::operator [](index);																								\
}																																						

#define _h_typed_block_get_impl(h_custom_type)																											\
template<>																																				\
h_custom_type& h_typed_block<h_custom_type>::get(uint32_t index)																						\
{																																						\
	return std::vector<h_custom_type>::operator [](index);																								\
}																																						\
template<>																																				\
const h_custom_type& h_typed_block<h_custom_type>::get(uint32_t index) const																			\
{																																						\
	return std::vector<h_custom_type>::operator [](index);																								\
}

#define _h_typed_block_data_impl(h_custom_type)																											\
template<>																																				\
const h_custom_type* h_typed_block<h_custom_type>::data()																								\
{																																						\
	auto values = std::vector<h_custom_type>::data();																									\
	return values;																																		\
}																																						

#define _h_typed_block_type_size_impl(h_custom_type)																									\
template<>																																				\
uint32_t h_typed_block<h_custom_type>::get_high_level_type_size() const																					\
{																																						\
	return h_custom_type::high_level_type_size;																											\
}																																						\
																																						\
template<>																																				\
uint32_t h_typed_block<h_custom_type>::get_low_level_type_size() const																					\
{																																						\
	return h_custom_type::low_level_type_size;																											\
}																																						

#define _h_typed_block_size_impl(h_custom_type)																											\
template<>																																				\
uint32_t h_typed_block<h_custom_type>::size()  const																									\
{																																						\
	return static_cast<uint32_t>(std::vector<h_custom_type>::size());																					\
}																																						

#define _h_typed_block_data_size_impl(h_custom_type)																									\
template<>																																				\
uint32_t h_typed_block<h_custom_type>::data_size() const																								\
{																																						\
	return static_cast<uint32_t>(std::vector<h_custom_type>::size() * sizeof(h_custom_type));															\
}																																						

#define _h_typed_block_emplace_back_impl(h_custom_type)																									\
template<>																																				\
h_custom_type& h_typed_block<h_custom_type>::emplace_back()																								\
{																																						\
	return std::vector<h_custom_type>::emplace_back(this);																								\
}																																						

#define _h_typed_block_emplace_back_alt_impl(h_custom_type)																								\
template<>																																				\
h_custom_type& h_typed_block<h_custom_type>::emplace_back(const h_object& value)																		\
{																																						\
	const h_custom_type* typed_value = dynamic_cast<const h_custom_type*>(&value);																		\
	DEBUG_ASSERT(typed_value != nullptr);																												\
	h_custom_type& created_type = std::vector<h_custom_type>::emplace_back(this);																		\
	created_type = *typed_value;																														\
	return created_type;																																\
}

#define _h_typed_block_reserve_impl(h_custom_type)																										\
template<>																																				\
void h_typed_block<h_custom_type>::reserve(uint32_t count)																								\
{																																						\
	std::vector<h_custom_type>::reserve(count);																											\
}																																						

#define _h_typed_block_resize_impl(h_custom_type)																										\
template<>																																				\
void h_typed_block<h_custom_type>::resize(uint32_t count)																								\
{																																						\
	uint32_t old_count = static_cast<uint32_t>(std::vector<h_custom_type>::size());																		\
	std::vector<h_custom_type>::resize(count);																											\
																																						\
	{																																					\
		/* fixup parents */																																\
		/* #TODO: is there a better way to do this?  */																									\
																																						\
		h_custom_type* raw_types = std::vector<h_custom_type>::data();																					\
		for (uint32_t index = old_count; index < count; index++) 																						\
		{																																				\
			raw_types[index]._set_parent(this);																											\
		}																																				\
	}																																					\
}																																						
																																						
#define _h_typed_block_insert_hole_impl(h_custom_type)																									\
template<>																																				\
void h_typed_block<h_custom_type>::insert_hole(uint32_t index, uint32_t count)																			\
{																																						\
	std::vector<h_custom_type>::insert(std::vector<h_custom_type>::begin() + index, count, h_custom_type(this));										\
}																																						

#define _h_typed_block_remove_impl(h_custom_type)																										\
template<>																																				\
void h_typed_block<h_custom_type>::remove(uint32_t index)																								\
{																																						\
	std::vector<h_custom_type>::erase(std::vector<h_custom_type>::begin() + index);																		\
}																																						

#define _h_typed_block_clear_impl(h_custom_type)																										\
template<>																																				\
void h_typed_block<h_custom_type>::clear()																												\
{																																						\
	std::vector<h_custom_type>::clear();																												\
}
