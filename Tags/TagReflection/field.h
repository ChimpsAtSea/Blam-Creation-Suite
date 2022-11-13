#pragma once

#pragma pack(push, 1)
template<typename _field_type, typename t_parent_type, uint32_t _field_index>
class h_field :
	public h_type
{
public:
	using t_field_type = _field_type;
#ifndef BCS_IS_HIGH_LEVEL_BUILD_PROJECT

	explicit h_field() = delete;
	explicit h_field(h_field const& field) = delete;
	explicit h_field(t_field_type const& _value) = delete;
	explicit h_field(t_field_type&& _value) = delete;
	virtual ~h_field();

#else

	explicit h_field() : value() {}
	explicit h_field(h_field const& field) : value(field.value) {}
	explicit h_field(t_field_type const& _value) : value(_value) {}
	explicit h_field(t_field_type&& _value) : value(_value) {}
	virtual ~h_field() = default;

#endif

	virtual operator t_field_type const& () const;
	virtual operator t_field_type& ();
	virtual h_field& operator=(t_field_type const& _value);
	virtual h_field& operator=(t_field_type&& _value);
	virtual bool operator==(t_field_type const& _value);
	virtual bool operator==(t_field_type&& _value);
	virtual bool operator!=(t_field_type const& _value);
	virtual bool operator!=(t_field_type&& _value);
	virtual t_field_type const* operator->() const;
	virtual t_field_type* operator->();

	template<typename t_parent_type, uint32_t _field_index>
	bool operator==(h_field<t_field_type, t_parent_type, _field_index>& field)
	{
		return operator==(field.operator t_field_type &());
	}

#ifdef BCS_IS_HIGH_LEVEL_BUILD_PROJECT
public:
#else
protected:
#endif
	t_field_type value;
};

template<typename t_enum, typename t_parent_type, uint32_t _field_index>
class h_field_flags :
	public h_field<c_flags<t_enum, qword>, t_parent_type, _field_index>
{
public:
	using t_field = h_field<c_flags<t_enum, qword>, t_parent_type, _field_index>;
	using t_flags = c_flags<t_enum, qword>;
	using t_flags_no_init = c_flags_no_init<t_enum, qword>;
#ifndef BCS_IS_HIGH_LEVEL_BUILD_PROJECT

	explicit h_field_flags() = delete;
	explicit h_field_flags(h_field_flags const& field) = delete;
	explicit h_field_flags(t_enum const& field) = delete;
	explicit h_field_flags(t_flags const& _value) = delete;
	explicit h_field_flags(t_flags&& _value) = delete;
	explicit h_field_flags(t_flags_no_init const& _value) = delete;
	explicit h_field_flags(t_flags_no_init&& _value) = delete;
	virtual ~h_field_flags();

#else

	explicit h_field_flags() : t_field() {}
	explicit h_field_flags(h_field_flags const& field) : t_field(field.value) {}
	explicit h_field_flags(t_enum const& _value) : t_field(_value) {}
	explicit h_field_flags(t_flags const& _value) : t_field(_value) {}
	explicit h_field_flags(t_flags&& _value) : t_field(_value) {}
	explicit h_field_flags(t_flags_no_init const& _value) : t_field(_value) {}
	explicit h_field_flags(t_flags_no_init&& _value) : t_field(_value) {}
	virtual ~h_field_flags() = default;

#endif

	virtual t_flags operator|(t_flags value) const;
	virtual bool is_clear() const;
	virtual t_flags_no_init operator~() const;
	virtual void clear();
	virtual bool test(t_enum bit) const;
	virtual void set(t_enum bit, bool value);
	virtual bool valid() const;
};

#pragma pack(pop)

#ifdef BCS_IS_HIGH_LEVEL_BUILD_PROJECT

#define h_field_func_impl_cast_const(t_field_type, t_parent_type, _field_index, _field_name)												\
h_field<t_field_type, t_parent_type, _field_index>::operator t_field_type const& () const													\
{																																			\
	return value;																															\
}

#define h_field_func_impl_cast(t_field_type, t_parent_type, _field_index, _field_name)														\
h_field<t_field_type, t_parent_type, _field_index>::operator t_field_type& ()																\
{																																			\
	return value;																															\
}

#define h_field_func_impl_rvalue_assignment(t_field_type, t_parent_type, _field_index, _field_name)												\
h_field<t_field_type, t_parent_type, _field_index>& h_field<t_field_type, t_parent_type, _field_index>::operator=(t_field_type&& _value)	\
{																																				\
	constexpr uint32_t _field_offset = offsetof(t_parent_type, _field_name);																	\
	h_type* _type = reinterpret_cast<h_type*>(reinterpret_cast<uintptr_t>(this) - _field_offset);												\
																																				\
	if constexpr (std::is_arithmetic<t_field_type>::value)																						\
	{																																			\
		if (value != _value)																													\
		{																																		\
			auto _old_value = value;																											\
			value = _value;																														\
																																				\
			c_data_change_notification _notification;																							\
			_type->notify_data_change(_notification);																							\
		}																																		\
	}																																			\
	else																																		\
	{																																			\
		value = _value;																															\
																																				\
		c_data_change_notification _notification;																								\
		_type->notify_data_change(_notification);																								\
	}																																			\
	return *this;																																\
}

#define h_field_func_impl_lvalue_assignment(t_field_type, t_parent_type, _field_index, _field_name)												\
h_field<t_field_type, t_parent_type, _field_index>& h_field<t_field_type, t_parent_type, _field_index>::operator=(t_field_type const& _value)	\
{																																				\
	constexpr uint32_t _field_offset = offsetof(t_parent_type, _field_name);																	\
	h_type* _type = reinterpret_cast<h_type*>(reinterpret_cast<uintptr_t>(this) - _field_offset);												\
																																				\
	if constexpr (std::is_arithmetic<t_field_type>::value)																						\
	{																																			\
		if (value != _value)																													\
		{																																		\
			auto _old_value = value;																											\
			value = _value;																														\
																																				\
			c_data_change_notification _notification;																							\
			_type->notify_data_change(_notification);																							\
		}																																		\
	}																																			\
	else																																		\
	{																																			\
		value = _value;																															\
																																				\
		c_data_change_notification _notification;																								\
		_type->notify_data_change(_notification);																								\
	}																																			\
	return *this;																																\
}

#define h_field_func_impl_rvalue_equality(t_field_type, t_parent_type, _field_index, _field_name)											\
bool h_field<t_field_type, t_parent_type, _field_index>::operator==(t_field_type&& _value)											\
{																																			\
	if constexpr (																															\
		std::is_arithmetic_v<t_field_type> ||																								\
		std::is_same_v<h_string_id, t_field_type> ||																						\
		std::is_base_of_v<h_prototype, t_field_type>)																						\
	{																																		\
		return value == _value;																												\
	}																																		\
	else																																	\
	{																																		\
		return memcmp(&value, &_value, sizeof(value)) == 0;																					\
	}																																		\
}

#define h_field_func_impl_lvalue_equality(t_field_type, t_parent_type, _field_index, _field_name)											\
bool h_field<t_field_type, t_parent_type, _field_index>::operator==(t_field_type const& _value)												\
{																																			\
	if constexpr (																															\
		std::is_arithmetic_v<t_field_type> ||																								\
		std::is_same_v<h_string_id, t_field_type> ||																						\
		std::is_base_of_v<h_prototype, t_field_type>)																						\
	{																																		\
		return value == _value;																												\
	}																																		\
	else																																	\
	{																																		\
		return memcmp(&value, &_value, sizeof(value)) == 0;																					\
	}																																		\
}

#define h_field_func_impl_rvalue_inequality(t_field_type, t_parent_type, _field_index, _field_name)											\
bool h_field<t_field_type, t_parent_type, _field_index>::operator!=(t_field_type&& _value)											\
{																																			\
	if constexpr (																															\
		std::is_arithmetic_v<t_field_type> ||																								\
		std::is_same_v<h_string_id, t_field_type> ||																						\
		std::is_base_of_v<h_prototype, t_field_type>)																						\
	{																																		\
		return value != _value;																												\
	}																																		\
	else																																	\
	{																																		\
		return memcmp(&value, &_value, sizeof(value)) != 0;																					\
	}																																		\
}

#define h_field_func_impl_lvalue_inequality(t_field_type, t_parent_type, _field_index, _field_name)											\
bool h_field<t_field_type, t_parent_type, _field_index>::operator!=(t_field_type const& _value)												\
{																																			\
	if constexpr (																															\
		std::is_arithmetic_v<t_field_type> ||																								\
		std::is_same_v<h_string_id, t_field_type> ||																						\
		std::is_base_of_v<h_prototype, t_field_type>)																						\
	{																																		\
		return value != _value;																												\
	}																																		\
	else																																	\
	{																																		\
		return memcmp(&value, &_value, sizeof(value)) != 0;																					\
	}																																		\
}

#define h_field_func_impl_pointer_const(t_field_type, t_parent_type, _field_index, _field_name)												\
t_field_type const* h_field<t_field_type, t_parent_type, _field_index>::operator->() const													\
{																																			\
	return &value;																															\
}

#define h_field_func_impl_pointer(t_field_type, t_parent_type, _field_index, _field_name)													\
t_field_type* h_field<t_field_type, t_parent_type, _field_index>::operator->()																\
{																																			\
	return &value;																															\
}

#define h_field_enum_func_impl_rvalue_assignment(t_enum, t_parent_type, _field_index, _field_name)																							\
h_field_enum<t_enum, t_parent_type, _field_index>& h_field_enum<t_enum, t_parent_type, _field_index>::operator=(t_enum const& _value)														\
{																																															\
	h_field::operator=(_value);																																								\
	return *this;																																											\
}

#define h_field_enum_func_impl_lvalue_assignment(t_enum, t_parent_type, _field_index, _field_name)																							\
h_field_enum<t_enum, t_parent_type, _field_index>& h_field_enum<t_enum, t_parent_type, _field_index>::operator=(t_enum const& _value)														\
{																																															\
	h_field::operator=(_value);																																								\
	return *this;																																											\
}

#define h_field_enum_func_impl_or(t_enum, t_parent_type, _field_index, _field_name) \
h_field_flags<t_enum, t_parent_type, _field_index>::t_flags h_field_flags<t_enum, t_parent_type, _field_index>::operator|(h_field_flags<t_enum, t_parent_type, _field_index>::t_flags _value) const {return value.operator|(_value);}

#define h_field_enum_func_impl_is_clear(t_enum, t_parent_type, _field_index, _field_name) \
bool h_field_flags<t_enum, t_parent_type, _field_index>::is_clear() const{return value.is_clear();}

#define h_field_enum_func_impl_xor(t_enum, t_parent_type, _field_index, _field_name) \
h_field_flags<t_enum, t_parent_type, _field_index>::t_flags_no_init h_field_flags<t_enum, t_parent_type, _field_index>::operator~() const{	return value.operator~();}

#define h_field_enum_func_impl_clear(t_enum, t_parent_type, _field_index, _field_name) \
void h_field_flags<t_enum, t_parent_type, _field_index>::clear(){	value.clear();}

#define h_field_enum_func_impl_test(t_enum, t_parent_type, _field_index, _field_name) \
bool h_field_flags<t_enum, t_parent_type, _field_index>::test(t_enum bit) const{	return value.test(bit);}

#define h_field_enum_func_impl_set(t_enum, t_parent_type, _field_index, _field_name) \
void h_field_flags<t_enum, t_parent_type, _field_index>::set(t_enum bit, bool _value){	value.set(bit, _value);}

#define h_field_enum_func_impl_valid(t_enum, t_parent_type, _field_index, _field_name) \
bool h_field_flags<t_enum, t_parent_type, _field_index>::valid() const{	return value.valid();}

#endif
