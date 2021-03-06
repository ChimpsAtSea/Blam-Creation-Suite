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
	for(t_element& value : arr)
	{
		byteswap(value);
	}
}

template <typename t_enum, typename t_storage>
void byteswap(c_flags_no_init<t_enum, t_storage>& value)
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

#define byteswap_func(type) template<> void byteswap<type>(type& value)
