#include "blamboozlelib-private-pch.h"



c_h3_tag_field::c_h3_tag_field(const char* guerilla_data, const s_h3_tag_field& field_definition) :
	name(h3_pa_to_pointer(guerilla_data, field_definition.name_address)),
	definition(h3_pa_to_pointer(guerilla_data, field_definition.definition_address)),
	field_type(field_definition.field_type),
	name_address(field_definition.name_address),
	definition_address(field_definition.definition_address),
	block_definition(nullptr),
	tag_reference_definition(nullptr),
	struct_definition(nullptr),
	array_definition(nullptr),
	string_list_definition(nullptr),
	padding(0),
	skip_length(0),
	explanation(0),
	field_id(static_cast<blofeld::e_field_id>(field_definition.meta)),
	field_id_string(field_id_to_string(field_id)),
	_field_id_byteswap(_byteswap_ulong(field_definition.meta))
{
	ASSERT(field_id_string);

	switch (field_type)
	{
	case _h3_field_type_char_block_index:
	case _h3_field_type_short_block_index:
	case _h3_field_type_long_block_index:
	case _h3_field_type_long_block_flags:
	case _h3_field_type_word_block_flags:
	case _h3_field_type_byte_block_flags:
	case _h3_field_type_block:
		block_definition = c_h3_tag_block_definition::h3_get_tag_block_definition(guerilla_data, field_definition.definition_address);
		break;
	case _h3_field_type_struct:
		struct_definition = c_h3_tag_struct_definition::h3_get_tag_struct_definition(guerilla_data, field_definition.definition_address);
		break;
	case _h3_field_type_array:
		array_definition = c_h3_tag_array_definition::h3_get_tag_array_definition(guerilla_data, field_definition.definition_address);
		break;
	case _h3_field_type_tag_reference:
		tag_reference_definition = h3_get_tag_reference_definition(guerilla_data, field_definition.definition_address);
		break;
	case _h3_field_type_useless_pad:
	case _h3_field_type_pad:
	case _h3_field_type_skip:
		padding = skip_length = field_definition.definition_address.value();
		break;
	case _h3_field_type_char_enum:
	case _h3_field_type_short_enum:
	case _h3_field_type_long_enum:
	case _h3_field_type_long_flags:
	case _h3_field_type_word_flags:
	case _h3_field_type_byte_flags:
		string_list_definition = h3_get_string_list_definition(guerilla_data, field_definition.definition_address);
		break;
	case _h3_field_type_explanation:
		if (field_definition.definition_address)
			explanation = h3_pa_to_pointer(guerilla_data, field_definition.definition_address);
		break;
	case _h3_field_type_pageable_resource:
		ASSERT(field_definition.definition_address != 0);
		pageable_resource_definition = c_h3_tag_pageable_resource_definition::h3_get_tag_pageable_resource_definition(guerilla_data, field_definition.definition_address);
		break;
	case _h3_field_type_custom_char_block_index:
	case _h3_field_type_custom_short_block_index:
	case _h3_field_type_custom_long_block_index:
		break;
	case _h3_field_type_custom:
	case _h3_field_type_api_interop:
		break;
	case _h3_field_type_data:
	case _h3_field_type_short_integer:
	case _h3_field_type_real:
	case _h3_field_type_string_id:
	case _h3_field_type_int64_integer:
		break;
	default:
		ASSERT(field_definition.definition_address == 0);
	}
}
