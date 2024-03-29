#pragma once

template<typename t_element, const int32_t k_maximum_count>
void byteswap_inplace(s_static_array<t_element, k_maximum_count>& value)
{
	for (t_element& element : value)
	{
		byteswap_inplace(element);
	}
}

template <typename t_enum, typename t_storage, const int32_t k_number_of_bits>
void byteswap_inplace(c_flags<t_enum, t_storage, k_number_of_bits>& value)
{
	byteswap_inplace(*reinterpret_cast<t_storage*>(&value));
}

template <typename t_storage, const int32_t k_number_of_bits>
void byteswap_inplace(c_big_flags_typed<t_storage, k_number_of_bits>& value)
{
	byteswap_inplace(*reinterpret_cast<t_storage(*)[c_big_flags_typed<t_storage, k_number_of_bits>::k_number_of_storage_elements]>(&value));
}

template <typename t_enum, typename t_storage, t_enum minimum_value, t_enum maximum_value>
void byteswap_inplace(c_enum<t_enum, t_storage, minimum_value, maximum_value>& value)
{
	byteswap_inplace(*reinterpret_cast<t_storage*>(&value));
}

template <typename t_enum, typename t_storage, const int32_t k_number_of_bits>
void byteswap_inplace(c_flags_no_init<t_enum, t_storage, k_number_of_bits>& value)
{
	byteswap_inplace(*reinterpret_cast<t_storage*>(&value));
}

template <typename t_enum, typename t_storage>
void byteswap_inplace(c_enum_no_init<t_enum, t_storage>& value)
{
	byteswap_inplace(*reinterpret_cast<t_storage*>(&value));
}

template <const int32_t k_maximum_length>
void byteswap_inplace(c_static_string<k_maximum_length>& value)
{

}

template<uint32_t k_capacity, typename t_char_type = char>
void byteswap_inplace(c_fixed_string<k_capacity, t_char_type>& value)
{

}

template <typename t_element>
void byteswap_inplace(c_typed_tag_block<t_element>& value)
{
	byteswap_inplace<s_tag_block>(value);
}

template<uint32_t ... tag_groups>
void byteswap_inplace(c_typed_tag_reference<tag_groups...>& value)
{
	byteswap_inplace<s_tag_reference>(value);
}

template <typename t_element>
void byteswap_inplace(c_basic_buffer32<t_element>& value)
{
	byteswap_inplace(value.elements);
	byteswap_inplace(value.size);
}

template <typename t_element>
void byteswap_inplace(c_basic_buffer64<t_element>& value)
{
	byteswap_inplace(value.elements);
	byteswap_inplace(value.size);
}

template <typename t_element>
void byteswap_inplace(c_ptr32<t_element>& value)
{
	byteswap_inplace(*reinterpret_cast<dword*>(&value));
}

template <typename t_element>
void byteswap_inplace(c_ptr64<t_element>& value)
{
	byteswap_inplace(*reinterpret_cast<qword*>(&value));
}
