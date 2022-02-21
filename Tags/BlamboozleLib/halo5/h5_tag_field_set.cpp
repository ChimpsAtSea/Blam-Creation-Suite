#include "blamboozlelib-private-pch.h"




c_h5_tag_field_set::c_h5_tag_field_set(const char* halo5_forge_data, const s_h5_tag_field_set_header* set_header)
{
	fields = reinterpret_cast<const s_h5_tag_field_definition*>(h5_aa_to_pointer(halo5_forge_data, set_header->fields_address));
	size_string = h5_aa_to_pointer(halo5_forge_data, set_header->size_string_address);

	const s_h5_tag_field_definition* field_definition = fields;
	unsigned long field_index = 0;
	while (field_definition->field_type != _h5_field_type_terminator)
	{
		c_h5_tag_field* field = nullptr;

		switch (field_definition->field_type)
		{
		case _h5_field_type_tag_reference:					field = new() c_h5_tag_field_template<s_h5_tag_reference_definition>(halo5_forge_data, field_definition); break;
		case _h5_field_type_tag_reference_64:				field = new() c_h5_tag_field_template<s_h5_tag_reference_definition>(halo5_forge_data, field_definition); break;
		case _h5_field_type_data:							field = new() c_h5_tag_field_template<s_h5_tag_data_definition>(halo5_forge_data, field_definition, _h5_tag_field_validation_check_ensure_valid); break;
		case _h5_field_type_data_64:						field = new() c_h5_tag_field_template<s_h5_tag_data_definition>(halo5_forge_data, field_definition, _h5_tag_field_validation_check_ensure_valid); break;
		case _h5_field_type_struct:							field = new() c_h5_tag_field_template<s_h5_tag_struct_definition>(halo5_forge_data, field_definition, _h5_tag_field_validation_check_ensure_valid); break;
		case _h5_field_type_block:							field = new() c_h5_tag_field_template<s_h5_tag_block_definition>(halo5_forge_data, field_definition, _h5_tag_field_validation_check_ensure_valid); break;
		case _h5_field_type_block_64:						field = new() c_h5_tag_field_template<s_h5_tag_block_definition>(halo5_forge_data, field_definition, _h5_tag_field_validation_check_ensure_valid); break;
		case _h5_field_type_char_enum:						field = new() c_h5_tag_field_template<s_h5_tag_enum_definition>(halo5_forge_data, field_definition); break;
		case _h5_field_type_enum:							field = new() c_h5_tag_field_template<s_h5_tag_enum_definition>(halo5_forge_data, field_definition); break;
		case _h5_field_type_long_enum:						field = new() c_h5_tag_field_template<s_h5_tag_enum_definition>(halo5_forge_data, field_definition); break;
		case _h5_field_type_byte_flags:						field = new() c_h5_tag_field_template<s_h5_tag_enum_definition>(halo5_forge_data, field_definition); break;
		case _h5_field_type_word_flags:						field = new() c_h5_tag_field_template<s_h5_tag_enum_definition>(halo5_forge_data, field_definition); break;
		case _h5_field_type_long_flags:						field = new() c_h5_tag_field_template<s_h5_tag_enum_definition>(halo5_forge_data, field_definition); break;
		case _h5_field_type_char_block_index:				field = new() c_h5_tag_field_template<s_h5_tag_block_index_custom_search_definition>(halo5_forge_data, field_definition); break;
		case _h5_field_type_custom_char_block_index:		field = new() c_h5_tag_field_template<s_h5_tag_block_index_custom_search_definition>(halo5_forge_data, field_definition); break;
		case _h5_field_type_short_block_index:				field = new() c_h5_tag_field_template<s_h5_tag_block_index_custom_search_definition>(halo5_forge_data, field_definition); break;
		case _h5_field_type_custom_short_block_index:		field = new() c_h5_tag_field_template<s_h5_tag_block_index_custom_search_definition>(halo5_forge_data, field_definition); break;
		case _h5_field_type_long_block_index:				field = new() c_h5_tag_field_template<s_h5_tag_block_index_custom_search_definition>(halo5_forge_data, field_definition); break;
		case _h5_field_type_custom_long_block_index:		field = new() c_h5_tag_field_template<s_h5_tag_block_index_custom_search_definition>(halo5_forge_data, field_definition); break;
		case _h5_field_type_explanation:					field = new() c_h5_tag_field_template<char>(halo5_forge_data, field_definition, _h5_tag_field_validation_check_ensure_valid); break;
		case _h5_field_type_byte_block_flags:				field = new() c_h5_tag_field_template<void>(halo5_forge_data, field_definition); break;
		case _h5_field_type_word_block_flags:				field = new() c_h5_tag_field_template<void>(halo5_forge_data, field_definition); break;
		case _h5_field_type_long_block_flags:				field = new() c_h5_tag_field_template<void>(halo5_forge_data, field_definition); break;
		case _h5_field_type_pad:							field = new() c_h5_tag_field_pad(halo5_forge_data, field_definition); break;
		case _h5_field_type_skip:							field = new() c_h5_tag_field_skip(halo5_forge_data, field_definition); break;
		case _h5_field_type_char_integer:					field = new() c_h5_tag_field_char_integer(halo5_forge_data, field_definition); break;
		case _h5_field_type_short_integer:					field = new() c_h5_tag_field_short_integer(halo5_forge_data, field_definition); break;
		case _h5_field_type_long_integer:					field = new() c_h5_tag_field_long_integer(halo5_forge_data, field_definition); break;
		case _h5_field_type_int64_integer:					field = new() c_h5_tag_field_int64_integer(halo5_forge_data, field_definition); break;
		case _h5_field_type_byte_integer:					field = new() c_h5_tag_field_byte_integer(halo5_forge_data, field_definition); break;
		case _h5_field_type_word_integer:					field = new() c_h5_tag_field_word_integer(halo5_forge_data, field_definition); break;
		case _h5_field_type_dword_integer:					field = new() c_h5_tag_field_dword_integer(halo5_forge_data, field_definition); break;
		case _h5_field_type_qword_integer:					field = new() c_h5_tag_field_qword_integer(halo5_forge_data, field_definition); break;
		case _h5_field_type_real:							field = new() c_h5_tag_field_real(halo5_forge_data, field_definition); break;
		case _h5_field_type_array:							field = new() c_h5_tag_field_template<void>(halo5_forge_data, field_definition, _h5_tag_field_validation_check_ensure_valid); break;
		case _h5_field_type_string:							field = new() c_h5_tag_field_template<void>(halo5_forge_data, field_definition); break;
		case _h5_field_type_string_id:						field = new() c_h5_tag_field_template<void>(halo5_forge_data, field_definition); break;
		case _h5_field_type_pageable_resource_64:			field = new() c_h5_tag_field_template<void>(halo5_forge_data, field_definition, _h5_tag_field_validation_check_ensure_valid); break;
		case _h5_field_type_custom:							field = new() c_h5_tag_field_template<void>(halo5_forge_data, field_definition); break;
		default:											field = new() c_h5_tag_field_template<void>(halo5_forge_data, field_definition, _h5_tag_field_validation_check_ensure_invalid); break;
		}

		tag_fields.emplace_back(field);
		field_definition++;
		field_index++;
	}

}
