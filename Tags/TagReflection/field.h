#pragma once

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
h_field<field_type, parent_type, _field_index>::h_field() : value() {}												

#define h_field_func_impl2(field_type, parent_type, _field_index, _field_name)										\
bool h_field<field_type, parent_type, _field_index>::operator==(field_type const& new_value) const					\
{																													\
	bool is_same = &this->value == &new_value || memcmp(&value, &new_value, sizeof(value)) == 0;					\
	return is_same;																									\
}																													

#define h_field_func_impl3(field_type, parent_type, _field_index, _field_name)										\
field_type& h_field<field_type, parent_type, _field_index>::operator=(field_type const& new_value)					\
{																													\
	uint32_t _field_offset = offsetof(parent_type, _field_name);												\
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
