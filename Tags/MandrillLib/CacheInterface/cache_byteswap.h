#pragma once

template<typename t_element>
void byteswap(t_element&);

template<typename t_element, const long k_maximum_count>
void byteswap(s_static_array<t_element, k_maximum_count>& arr)
{
	for(t_element& value : arr)
	{
		byteswap(value);
	}
}

#define byteswap_func(type) template<> void byteswap<type>(type& value)

