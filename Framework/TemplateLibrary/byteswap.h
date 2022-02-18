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
