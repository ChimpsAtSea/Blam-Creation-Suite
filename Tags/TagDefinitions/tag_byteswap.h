#pragma once

template<typename t_element>
void byteswap(t_element&);

template<typename t_element, const long k_maximum_count>
void byteswap(t_element(&arr)[k_maximum_count])
{
	for (t_element& value : arr)
	{
		byteswap(value);
	}
}

template<typename t_element, const long k_maximum_count>
void byteswap(s_static_array<t_element, k_maximum_count>& arr)
{
	for (t_element& value : arr)
	{
		byteswap(value);
	}
}

template <typename t_enum, typename t_storage, const long k_number_of_bits>
void byteswap(c_flags<t_enum, t_storage, k_number_of_bits>& value)
{
	byteswap(*reinterpret_cast<t_storage*>(&value));
}

template <typename t_enum, typename t_storage>
void byteswap(c_enum<t_enum, t_storage>& value)
{
	byteswap(*reinterpret_cast<t_storage*>(&value));
}

template <typename t_enum, typename t_storage, const long k_number_of_bits>
void byteswap(c_flags_no_init<t_enum, t_storage, k_number_of_bits>& value)
{
	byteswap(*reinterpret_cast<t_storage*>(&value));
}

template <typename t_enum, typename t_storage>
void byteswap(c_enum_no_init<t_enum, t_storage>& value)
{
	byteswap(*reinterpret_cast<t_storage*>(&value));
}

template <const long k_maximum_length>
void byteswap(c_static_string<k_maximum_length>& str)
{

}

template<uint32_t k_capacity, typename t_char_type = char>
void byteswap(c_fixed_string<k_capacity, t_char_type>& str)
{

}

template <typename t_element>
void byteswap(c_typed_tag_block<t_element>& block)
{
	byteswap<s_tag_block>(block);
}

template<unsigned long ... tag_groups>
void byteswap(c_typed_tag_reference<tag_groups...>& reference)
{
	byteswap<s_tag_reference>(reference);
}

#define byteswap_func(type) template<> void byteswap<type>(type& value)
