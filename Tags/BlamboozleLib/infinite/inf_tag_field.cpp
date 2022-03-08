#include "blamboozlelib-private-pch.h"



c_inf_tag_field::c_inf_tag_field(const char* guerilla_data, const s_inf_tag_field& field_definition) :
	name(inf_pa_to_pointer(guerilla_data, field_definition.name_address)),
	definition(inf_pa_to_pointer(guerilla_data, field_definition.definition_address)),
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
	case _inf_field_type_char_block_index:
	case _inf_field_type_short_block_index:
	case _inf_field_type_long_block_index:
	case _inf_field_type_block:
	case _inf_field_type_block_v2:
	case _inf_field_type_block_64:
		block_definition = c_inf_tag_block_definition::inf_get_tag_block_definition(guerilla_data, field_definition.definition_address);
		break;
	case _inf_field_type_struct:
		struct_definition = c_inf_tag_struct_definition::inf_get_tag_struct_definition(guerilla_data, field_definition.definition_address);
		break;
	case _inf_field_type_array:
		array_definition = c_inf_tag_array_definition::inf_get_tag_array_definition(guerilla_data, field_definition.definition_address);
		break;
	case _inf_field_type_tag_reference:
	case _inf_field_type_reference_v2:
	case _inf_field_type_tag_reference_64:
		tag_reference_definition = inf_get_tag_reference_definition(guerilla_data, field_definition.definition_address);
		break;
	case _inf_field_type_pad:
	case _inf_field_type_skip:
		padding = skip_length = field_definition.definition_address.value();
		break;
	case _inf_field_type_char_enum:
	case _inf_field_type_short_enum:
	case _inf_field_type_long_enum:
	case _inf_field_type_long_flags:
	case _inf_field_type_word_flags:
	case _inf_field_type_byte_flags:
		string_list_definition = inf_get_string_list_definition(guerilla_data, field_definition.definition_address);
		break;
	case _inf_field_type_explanation:
		if (field_definition.definition_address)
			explanation = inf_pa_to_pointer(guerilla_data, field_definition.definition_address);
		break;
	case _inf_field_type_data_64:
	case _inf_field_type_data_v2:
		break; // not needed yet
	case _inf_field_type_pageable_resource:
	case _inf_field_type_pageable_resource_64:
		ASSERT(field_definition.definition_address != 0);
		pageable_resource_definition = c_inf_tag_resource_definition::inf_get_tag_resource_definition(guerilla_data, field_definition.definition_address);
		break;
	//case _inf_field_type_data_path:
	//case _inf_field_type_embedded_tag:
	//case _inf_field_type_pageable_resource:
	//case _inf_field_type_pageable_resource_64:
	//	ASSERT(field_definition.definition_address == 0);
	//	break;
	case _inf_field_type_UNUSED:
		throw;
	}
}
