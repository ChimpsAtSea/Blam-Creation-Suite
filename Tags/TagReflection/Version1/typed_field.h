#pragma once

template<typename t_field_type_>
class h_typed_field :
	public h_field
{
public:
	using t_field_type = t_field_type_;

#ifndef BCS_IS_HIGH_LEVEL_BUILD_PROJECT
	BCS_SHARED explicit h_typed_field() = delete;
	BCS_SHARED explicit h_typed_field(h_typed_field const& field) = delete;
	BCS_SHARED explicit h_typed_field(t_field_type const& _value) = delete;
	BCS_SHARED explicit h_typed_field(t_field_type&& _value) = delete;
	BCS_SHARED virtual ~h_typed_field();
#else

	//BCS_SHARED explicit h_typed_field() : value() {}
	//BCS_SHARED explicit h_typed_field(h_typed_field const& field) : value(field.value) {}
	//BCS_SHARED explicit h_typed_field(t_field_type const& _value) : value(_value) {}
	//BCS_SHARED explicit h_typed_field(t_field_type&& _value) : value(_value) {}
	//BCS_SHARED virtual ~h_typed_field();

	BCS_SHARED explicit h_typed_field() = delete;
	BCS_SHARED explicit h_typed_field(h_prototype& parent);
	BCS_SHARED explicit h_typed_field(h_typed_field const& field) = delete;
	// BCS_SHARED explicit h_typed_field(t_field_type const& _value);
	BCS_SHARED virtual ~h_typed_field();
#endif

#ifndef BCS_IS_HIGH_LEVEL_BUILD_PROJECT

	virtual void const* get_data() const override;
	virtual void* get_data() override;
	virtual operator t_field_type const& () const;
	virtual operator t_field_type& ();
	virtual h_typed_field& operator=(t_field_type const& _value);
	virtual h_typed_field& operator=(t_field_type&& _value);
	virtual bool operator==(t_field_type const& _value);
	virtual bool operator==(t_field_type&& _value);
	virtual bool operator!=(t_field_type const& _value);
	virtual bool operator!=(t_field_type&& _value);
	virtual t_field_type const* operator->() const;
	virtual t_field_type* operator->();

#else

	virtual void const* get_data() const override
	{
		return &value;
	}

	virtual void* get_data() override
	{
		return &value;
	}

	virtual operator t_field_type const& () const
	{
		return value;
	}

	virtual operator t_field_type& ()
	{
		return value;
	}

	h_typed_field<t_field_type>& operator=(t_field_type const& _value)
	{
		value = _value;
		return *this;
	}

	h_typed_field<t_field_type>& operator=(t_field_type&& _value)
	{
		value = _value;
		return *this;
	}

	virtual bool operator==(t_field_type&& _value)
	{
		if constexpr (
			std::is_arithmetic_v<t_field_type> ||
			std::is_same_v<h_string_id_field, t_field_type> ||
			std::is_base_of_v<h_prototype, t_field_type>)
		{
			return value == _value;
		}
		else
		{
			return memcmp(&value, &_value, sizeof(value)) == 0;
		}
	}

	virtual bool operator==(t_field_type const& _value)
	{
		if constexpr (
			std::is_arithmetic_v<t_field_type> ||
			std::is_same_v<h_string_id_field, t_field_type> ||
			std::is_base_of_v<h_prototype, t_field_type>)
		{
			return value == _value;
		}
		else
		{
			return memcmp(&value, &_value, sizeof(value)) == 0;
		}
	}

	virtual bool operator!=(t_field_type&& _value)
	{
		if constexpr (
			std::is_arithmetic_v<t_field_type> ||
			std::is_same_v<h_string_id_field, t_field_type> ||
			std::is_base_of_v<h_prototype, t_field_type>)
		{
			return value != _value;
		}
		else
		{
			return memcmp(&value, &_value, sizeof(value)) != 0;
		}
	}

	virtual bool operator!=(t_field_type const& _value)
	{
		if constexpr (
			std::is_arithmetic_v<t_field_type> ||
			std::is_same_v<h_string_id_field, t_field_type> ||
			std::is_base_of_v<h_prototype, t_field_type>)
		{
			return value != _value;
		}
		else
		{
			return memcmp(&value, &_value, sizeof(value)) != 0;
		}
	}

	virtual t_field_type const* operator->() const
	{
		return &value;
	}

	virtual t_field_type* operator->()
	{
		return &value;
	}

#endif

#ifdef BCS_IS_HIGH_LEVEL_BUILD_PROJECT
public:
#else
protected:
#endif
	t_field_type value;
};

#ifdef BCS_HIGH_LEVEL_USE_TRIVIAL_FIELDS

template<typename t_type, typename t_parent_type, uint32_t _field_index>
using h_prototype_field = h_typed_field<t_type>;

#else

template<typename t_field_type_, typename t_parent_type, uint32_t _field_index>
class h_prototype_field :
	public h_typed_field<t_field_type_>
{
public:
	using t_base = h_typed_field<t_field_type_>;
	using t_field_type = t_field_type_;

	explicit h_prototype_field() = delete;
	explicit h_prototype_field(h_prototype_field const& field) = delete;
	virtual ~h_prototype_field();

	//virtual h_prototype_field& operator=(t_field_type&& _value)
	//{
	//	constexpr uint32_t _field_offset = offsetof(t_parent_type, _field_name);
	//	h_type* _type = reinterpret_cast<h_type*>(reinterpret_cast<uintptr_t>(this) - _field_offset);

	//	if constexpr (std::is_arithmetic<t_field_type>::value)
	//	{
	//		if (value != _value)
	//		{
	//			auto _old_value = value;
	//			t_base:: operator=(_value);

	//			c_data_change_notification _notification;
	//			_type->notify_data_change(_notification);
	//		}
	//	}
	//	else
	//	{
	//		t_base:: operator=(_value);

	//		c_data_change_notification _notification;
	//		_type->notify_data_change(_notification);
	//	}
	//	return *this;
	//}

	//virtual h_prototype_field& operator=(t_field_type const& _value)
	//{
	//	constexpr uint32_t _field_offset = offsetof(t_parent_type, _field_name);
	//	h_type* _type = reinterpret_cast<h_type*>(reinterpret_cast<uintptr_t>(this) - _field_offset);

	//	if constexpr (std::is_arithmetic<t_field_type>::value)
	//	{
	//		if (value != _value)
	//		{
	//			auto _old_value = value;
	//			value = _value;

	//			c_data_change_notification _notification;
	//			_type->notify_data_change(_notification);
	//		}
	//	}
	//	else
	//	{
	//		value = _value;

	//		c_data_change_notification _notification;
	//		_type->notify_data_change(_notification);
	//	}
	//	return *this;
	//}
};

#endif


//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//template<typename t_enum, typename t_parent_type, uint32_t _field_index>
//class h_typed_field_flags :
//	public h_typed_field<c_flags<t_enum, qword>, t_parent_type, _field_index>
//{
//public:
//	using t_field = h_typed_field<c_flags<t_enum, qword>, t_parent_type, _field_index>;
//	using t_flags = c_flags<t_enum, qword>;
//	using t_flags_no_init = c_flags_no_init<t_enum, qword>;
//#ifndef BCS_IS_HIGH_LEVEL_BUILD_PROJECT
//
//	explicit h_typed_field_flags() = delete;
//	explicit h_typed_field_flags(h_typed_field_flags const& field) = delete;
//	explicit h_typed_field_flags(t_enum const& field) = delete;
//	explicit h_typed_field_flags(t_flags const& _value) = delete;
//	explicit h_typed_field_flags(t_flags&& _value) = delete;
//	explicit h_typed_field_flags(t_flags_no_init const& _value) = delete;
//	explicit h_typed_field_flags(t_flags_no_init&& _value) = delete;
//	virtual ~h_typed_field_flags();
//
//#else
//
//	explicit h_typed_field_flags() : t_field() {}
//	explicit h_typed_field_flags(h_typed_field_flags const& field) : t_field(field.value) {}
//	explicit h_typed_field_flags(t_enum const& _value) : t_field(_value) {}
//	explicit h_typed_field_flags(t_flags const& _value) : t_field(_value) {}
//	explicit h_typed_field_flags(t_flags&& _value) : t_field(_value) {}
//	explicit h_typed_field_flags(t_flags_no_init const& _value) : t_field(_value) {}
//	explicit h_typed_field_flags(t_flags_no_init&& _value) : t_field(_value) {}
//	virtual ~h_typed_field_flags() = default;
//
//#endif
//
//	virtual t_flags operator|(t_flags value) const;
//	virtual bool is_clear() const;
//	virtual t_flags_no_init operator~() const;
//	virtual void clear();
//	virtual bool test(t_enum bit) const;
//	virtual void set(t_enum bit, bool value);
//	virtual bool valid() const;
//};
//
//#pragma pack(pop)
//
//#ifdef BCS_IS_HIGH_LEVEL_BUILD_PROJECT
//
//#define h_typed_field_enum_func_impl_rvalue_assignment(t_enum, t_parent_type, _field_index, _field_name)																							\
//h_typed_field_enum<t_enum, t_parent_type, _field_index>& h_typed_field_enum<t_enum, t_parent_type, _field_index>::operator=(t_enum const& _value)														\
//{																																															\
//	h_typed_field::operator=(_value);																																								\
//	return *this;																																											\
//}
//
//#define h_typed_field_enum_func_impl_lvalue_assignment(t_enum, t_parent_type, _field_index, _field_name)																							\
//h_typed_field_enum<t_enum, t_parent_type, _field_index>& h_typed_field_enum<t_enum, t_parent_type, _field_index>::operator=(t_enum const& _value)														\
//{																																															\
//	h_typed_field::operator=(_value);																																								\
//	return *this;																																											\
//}
//
//#define h_typed_field_enum_func_impl_or(t_enum, t_parent_type, _field_index, _field_name) \
//h_typed_field_flags<t_enum, t_parent_type, _field_index>::t_flags h_typed_field_flags<t_enum, t_parent_type, _field_index>::operator|(h_typed_field_flags<t_enum, t_parent_type, _field_index>::t_flags _value) const {return value.operator|(_value);}
//
//#define h_typed_field_enum_func_impl_is_clear(t_enum, t_parent_type, _field_index, _field_name) \
//bool h_typed_field_flags<t_enum, t_parent_type, _field_index>::is_clear() const{return value.is_clear();}
//
//#define h_typed_field_enum_func_impl_xor(t_enum, t_parent_type, _field_index, _field_name) \
//h_typed_field_flags<t_enum, t_parent_type, _field_index>::t_flags_no_init h_typed_field_flags<t_enum, t_parent_type, _field_index>::operator~() const{	return value.operator~();}
//
//#define h_typed_field_enum_func_impl_clear(t_enum, t_parent_type, _field_index, _field_name) \
//void h_typed_field_flags<t_enum, t_parent_type, _field_index>::clear(){	value.clear();}
//
//#define h_typed_field_enum_func_impl_test(t_enum, t_parent_type, _field_index, _field_name) \
//bool h_typed_field_flags<t_enum, t_parent_type, _field_index>::test(t_enum bit) const{	return value.test(bit);}
//
//#define h_typed_field_enum_func_impl_set(t_enum, t_parent_type, _field_index, _field_name) \
//void h_typed_field_flags<t_enum, t_parent_type, _field_index>::set(t_enum bit, bool _value){	value.set(bit, _value);}
//
//#define h_typed_field_enum_func_impl_valid(t_enum, t_parent_type, _field_index, _field_name) \
//bool h_typed_field_flags<t_enum, t_parent_type, _field_index>::valid() const{	return value.valid();}
//
//#endif
