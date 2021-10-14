#include "blamboozlelib-private-pch.h"

c_h4_tag_struct::c_h4_tag_struct(const char* h4_data, const s_h4_tag_struct_definition* struct_header, unsigned long offset) :
	pretty_name(h4_va_to_pointer(h4_data, struct_header->pretty_name)),
	name(h4_va_to_pointer(h4_data, struct_header->name)),
	filepath(h4_va_to_pointer(h4_data, struct_header->filepath)),
	line_number(struct_header->line_number),
	fields(h4_va_to_pointer<s_h4_tag_field_definition>(h4_data, struct_header->fields_address)),
	struct_header(struct_header),
	size(struct_header->size),
	size_string(h4_va_to_pointer(h4_data, struct_header->size_string_address)),
	alignment_bits(struct_header->alignment_bits),
	legacy_struct_tag{ struct_header->legacy_struct_tag[0] , struct_header->legacy_struct_tag[1] },
	tag_fields(),
	offset(offset),
	runtime_flags(struct_header->runtime_flags),
	memory_attributes{ struct_header->memory_attributes.memory_type, struct_header->memory_attributes.usage_flags },
	persistent_identifier
	{ 
		struct_header->persistent_identifier.data[0], 
		struct_header->persistent_identifier.data[1], 
		struct_header->persistent_identifier.data[2], 
		struct_header->persistent_identifier.data[3] 
	}
{
	ASSERT(fields != nullptr);

	if (alignment_bits != 0)
	{
		debug_point;
	}

	int highest_runtime_flag = 31 - static_cast<int>(__lzcnt(runtime_flags));
	ASSERT(highest_runtime_flag == -1 || highest_runtime_flag < k_num_h4_runtime_flags);

	ASSERT(memory_attributes.memory_type < k_num_tag_memory_type);
	
	int highest_memory_usage_flag = 31 - static_cast<int>(__lzcnt(memory_attributes.usage_flags));
	ASSERT(highest_memory_usage_flag == -1 || highest_memory_usage_flag < k_num_h4_tag_memory_usage_bits);
	
	const s_h4_tag_field_definition* field_definition = fields;
	unsigned long field_index = 0;
	e_h4_field_type field_type = field_definition->field_type;
	while (field_type != _h4_field_type_terminator)
	{
		c_h4_tag_field* field = nullptr;

		switch (field_type)
		{
		case _h4_field_type_tag_reference:					field = new c_h4_tag_field_tag_reference(h4_data, field_definition); break;
		case _h4_field_type_data:							field = new c_h4_tag_field_data(h4_data, field_definition); break;
		case _h4_field_type_struct:							field = new c_h4_tag_field_struct(h4_data, field_definition); break;
		case _h4_field_type_block:							field = new c_h4_tag_field_block(h4_data, field_definition); break;
		case _h4_field_type_char_enum:						field = new c_h4_tag_field_enum(h4_data, field_definition); break;
		case _h4_field_type_enum:							field = new c_h4_tag_field_enum(h4_data, field_definition); break;
		case _h4_field_type_long_enum:						field = new c_h4_tag_field_enum(h4_data, field_definition); break;
		case _h4_field_type_byte_flags:						field = new c_h4_tag_field_enum(h4_data, field_definition); break;
		case _h4_field_type_word_flags:						field = new c_h4_tag_field_enum(h4_data, field_definition); break;
		case _h4_field_type_long_flags:						field = new c_h4_tag_field_enum(h4_data, field_definition); break;
		case _h4_field_type_char_block_index:				field = new c_h4_tag_field_block(h4_data, field_definition); break;
		case _h4_field_type_short_block_index:				field = new c_h4_tag_field_block(h4_data, field_definition); break;
		case _h4_field_type_long_block_index:				field = new c_h4_tag_field_block(h4_data, field_definition); break;
		case _h4_field_type_custom_char_block_index:		field = new c_h4_tag_field_custom_block_index(h4_data, field_definition); break;
		case _h4_field_type_custom_short_block_index:		field = new c_h4_tag_field_custom_block_index(h4_data, field_definition); break;
		case _h4_field_type_custom_long_block_index:		field = new c_h4_tag_field_custom_block_index(h4_data, field_definition); break;
		case _h4_field_type_explanation:					field = new c_h4_tag_field_explanation(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid); break;
		case _h4_field_type_byte_block_flags:				field = new c_h4_tag_field_block(h4_data, field_definition); break;
		case _h4_field_type_word_block_flags:				field = new c_h4_tag_field_block(h4_data, field_definition); break;
		case _h4_field_type_long_block_flags:				field = new c_h4_tag_field_block(h4_data, field_definition); break;
		case _h4_field_type_pad:							field = new c_h4_tag_field_pad(h4_data, field_definition); break;
		case _h4_field_type_skip:							field = new c_h4_tag_field_skip(h4_data, field_definition); break;
		case _h4_field_type_char_integer:					field = new c_h4_tag_field_char_integer(h4_data, field_definition); break;
		case _h4_field_type_short_integer:					field = new c_h4_tag_field_short_integer(h4_data, field_definition); break;
		case _h4_field_type_long_integer:					field = new c_h4_tag_field_long_integer(h4_data, field_definition); break;
		case _h4_field_type_int64_integer:					field = new c_h4_tag_field_int64_integer(h4_data, field_definition); break;
		case _h4_field_type_byte_integer:					field = new c_h4_tag_field_byte_integer(h4_data, field_definition); break;
		case _h4_field_type_word_integer:					field = new c_h4_tag_field_word_integer(h4_data, field_definition); break;
		case _h4_field_type_dword_integer:					field = new c_h4_tag_field_dword_integer(h4_data, field_definition); break;
		case _h4_field_type_qword_integer:					field = new c_h4_tag_field_qword_integer(h4_data, field_definition); break;
		case _h4_field_type_real:							field = new c_h4_tag_field_real(h4_data, field_definition); break;
		case _h4_field_type_array:							field = new c_h4_tag_field_array(h4_data, field_definition); break;
		case _h4_field_type_string:							field = new c_h4_tag_field_string(h4_data, field_definition); break;
		case _h4_field_type_string_id:						field = new c_h4_tag_field_string_id(h4_data, field_definition); break;
		case _h4_field_type_pageable:						field = new c_h4_tag_resource_definition(h4_data, field_definition); break;
		case _h4_field_type_api_interop:					field = new c_h4_tag_api_interop_definition(h4_data, field_definition); break;
		case _h4_field_type_custom:							field = new c_h4_tag_field_custom(h4_data, field_definition); break;
		default:											field = new t_h4_tag_field<void>(h4_data, field_definition, _h4_tag_field_validation_check_ensure_invalid); break;
		}

		tag_fields.emplace_back(field);
		field_definition++;
		field_index++;
		field_type = field_definition->field_type;
	}
}
