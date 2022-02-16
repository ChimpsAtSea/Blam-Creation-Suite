#pragma once

template<typename t_element>
void byteswap_inplace(t_element&);

template<typename t_element>
t_element byteswap(t_element value)
{
	byteswap_inplace(value);
	return value;
}

template<typename t_element, const long k_maximum_count>
void byteswap_inplace(t_element(&arr)[k_maximum_count])
{
	for (t_element& value : arr)
	{
		byteswap_inplace(value);
	}
}

template<typename t_element, const long k_maximum_count>
void byteswap_inplace(s_static_array<t_element, k_maximum_count>& arr)
{
	for (t_element& value : arr)
	{
		byteswap_inplace(value);
	}
}

template <typename t_enum, typename t_storage, const long k_number_of_bits>
void byteswap_inplace(c_flags<t_enum, t_storage, k_number_of_bits>& value)
{
	byteswap_inplace(*reinterpret_cast<t_storage*>(&value));
}

template <typename t_enum, typename t_storage>
void byteswap_inplace(c_enum<t_enum, t_storage>& value)
{
	byteswap_inplace(*reinterpret_cast<t_storage*>(&value));
}

template <typename t_enum, typename t_storage, const long k_number_of_bits>
void byteswap_inplace(c_flags_no_init<t_enum, t_storage, k_number_of_bits>& value)
{
	byteswap_inplace(*reinterpret_cast<t_storage*>(&value));
}

template <typename t_enum, typename t_storage>
void byteswap_inplace(c_enum_no_init<t_enum, t_storage>& value)
{
	byteswap_inplace(*reinterpret_cast<t_storage*>(&value));
}

template <const long k_maximum_length>
void byteswap_inplace(c_static_string<k_maximum_length>& str)
{

}

template<unsigned long k_capacity, typename t_char_type = char>
void byteswap_inplace(c_fixed_string<k_capacity, t_char_type>& str)
{

}

template <typename t_element>
void byteswap_inplace(c_typed_tag_block<t_element>& block)
{
	byteswap<s_tag_block>(block);
}

template<unsigned long ... tag_groups>
void byteswap_inplace(c_typed_tag_reference<tag_groups...>& reference)
{
	byteswap<s_tag_reference>(reference);
}

#define byteswap_func(type) template<> void byteswap_inplace<type>(type& value)
