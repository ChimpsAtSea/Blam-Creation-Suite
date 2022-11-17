#pragma once


enum e_high_level_type : unsigned char
{
	_high_level_field_metadata_1byte, // char
	_high_level_field_metadata_2byte, // short
	_high_level_field_metadata_4byte, // int, float, short+short
	_high_level_field_metadata_8byte, // int64
	_high_level_field_metadata_12byte, // float3
	_high_level_field_metadata_16byte, // float4
	_high_level_field_metadata_32byte, // string32
	_high_level_field_metadata_256byte, // string256
	_high_level_extended_type_string_id,
	_high_level_extended_type_tag_reference,
	_high_level_extended_type_block,
	_high_level_extended_type_data,
	_high_level_extended_type_struct,
	_high_level_extended_type_array,
	_high_level_extended_type_pageable_resource,
	_high_level_extended_type_api_interop,
	k_number_of_high_level_basic_types = _high_level_extended_type_string_id,
	k_number_of_high_level_types
};
static constexpr unsigned long k_number_of_high_level_type_bits = 5;
static_assert(k_number_of_high_level_types <= (1u << k_number_of_high_level_type_bits));

class h_type
{
	intelliaccess(public, protected) :;

	static constexpr unsigned char k_global_vftable_index = 0;

	e_high_level_type __field_type : k_number_of_high_level_type_bits;

protected:
	h_type(h_type const&) = delete;
	h_type(e_high_level_type _field_type)
	{
		__field_type = _field_type;
	}
};
