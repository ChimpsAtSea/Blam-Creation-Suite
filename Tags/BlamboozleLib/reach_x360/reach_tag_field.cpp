#include "blamboozlelib-private-pch.h"



c_reach_x360_tag_field::c_reach_x360_tag_field(const char* guerilla_data, const s_reach_x360_tag_field& field_definition) :
	name(reach_x360_pa_to_pointer(guerilla_data, field_definition.name_address)),
	definition(reach_x360_pa_to_pointer(guerilla_data, field_definition.definition_address)),
	field_type(field_definition.field_type),
	name_address(field_definition.name_address),
	definition_address(field_definition.definition_address),
	block_definition(nullptr),
	tag_reference_definition(nullptr),
	struct_definition(nullptr),
	array_definition(nullptr),
	string_list_definition(nullptr),
	data_definition(nullptr),
	padding(0),
	skip_length(0),
	explanation(0),
	field_id(static_cast<blofeld::e_field_id>(static_cast<unsigned long>(field_definition.meta))),
	field_id_string(field_id_to_string(field_id)),
	_field_id_byteswap(_byteswap_ulong(field_definition.meta))
{
	ASSERT(field_id_string);

	switch (field_type)
	{
	case _reach_x360_field_type_char_block_index:
	case _reach_x360_field_type_short_block_index:
	case _reach_x360_field_type_long_block_index:
	case _reach_x360_field_type_long_block_flags:
	case _reach_x360_field_type_word_block_flags:
	case _reach_x360_field_type_byte_block_flags:
	case _reach_x360_field_type_block:
		block_definition = c_reach_x360_tag_block_definition::reach_x360_get_tag_block_definition(guerilla_data, field_definition.definition_address);
		break;
	case _reach_x360_field_type_struct:
		struct_definition = c_reach_x360_tag_struct_definition::reach_x360_get_tag_struct_definition(guerilla_data, field_definition.definition_address);
		break;
	case _reach_x360_field_type_array:
		array_definition = c_reach_x360_tag_array_definition::reach_x360_get_tag_array_definition(guerilla_data, field_definition.definition_address);
		break;
	case _reach_x360_field_type_tag_reference:
		tag_reference_definition = reach_x360_get_tag_reference_definition(guerilla_data, field_definition.definition_address);
		break;
	case _reach_x360_field_type_useless_pad:
	case _reach_x360_field_type_pad:
	case _reach_x360_field_type_skip:
		padding = skip_length = field_definition.definition_address.value();
		break;
	case _reach_x360_field_type_char_enum:
	case _reach_x360_field_type_short_enum:
	case _reach_x360_field_type_long_enum:
	case _reach_x360_field_type_long_flags:
	case _reach_x360_field_type_word_flags:
	case _reach_x360_field_type_byte_flags:
		string_list_definition = reach_x360_get_string_list_definition(guerilla_data, field_definition.definition_address);
		break;
	case _reach_x360_field_type_explanation:
		if (field_definition.definition_address)
			explanation = reach_x360_pa_to_pointer(guerilla_data, field_definition.definition_address);
		break;
	case _reach_x360_field_type_pageable_resource:
		ASSERT(field_definition.definition_address != 0);
		pageable_resource_definition = c_reach_x360_tag_pageable_resource_definition::reach_x360_get_tag_pageable_resource_definition(guerilla_data, field_definition.definition_address);
		break;
	case _reach_x360_field_type_custom_char_block_index:
	case _reach_x360_field_type_custom_short_block_index:
	case _reach_x360_field_type_custom_long_block_index:
		break;
	case _reach_x360_field_type_custom:
		break;
	case _reach_x360_field_type_api_interop:
		ASSERT(field_definition.definition_address != 0);
		api_interop_definition = c_reach_x360_tag_api_interop_definition::reach_x360_get_tag_api_interop_definition(guerilla_data, field_definition.definition_address);
		break;
	case _reach_x360_field_type_data:
		ASSERT(field_definition.definition_address != 0);
		data_definition = c_reach_x360_tag_data_definition::reach_x360_get_tag_data_definition(guerilla_data, field_definition.definition_address);
		break;
	case _reach_x360_field_type_char_integer:
	case _reach_x360_field_type_short_integer:
	case _reach_x360_field_type_long_integer:
	case _reach_x360_field_type_real:
	case _reach_x360_field_type_string_id:
	case _reach_x360_field_type_int64_integer:
		break;
	default:
		ASSERT(field_definition.definition_address == 0);
	}
}

c_reach_x360_tag_field_combined_fixup::c_reach_x360_tag_field_combined_fixup(c_reach_x360_tag_group_definition& group_definition, unsigned long count) :
	group_definition(group_definition),
	count(count)
{
}
