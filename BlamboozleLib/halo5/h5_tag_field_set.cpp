#include "blamboozlelib-private-pch.h"

c_h5_tag_field_set::c_h5_tag_field_set(const char* halo5_forge_data, const s_h5_tag_field_set_header* set_header)
{
	fields = reinterpret_cast<const s_h5_tag_field_definition*>(h5_aa_to_pointer(halo5_forge_data, set_header->fields_address));
	size_string = h5_aa_to_pointer(halo5_forge_data, set_header->size_string_address);

	const s_h5_tag_field_definition* field_definition = fields;
	uint32_t field_index = 0;
	while (field_definition->field_type != _h5_field_type_terminator)
	{
		c_h5_tag_field* field = nullptr;

		switch (field_definition->field_type)
		{
		case _h5_field_type_tag_reference:
		case _h5_field_type_data:
		case _h5_field_type_block:
			FATAL_ERROR(L"Legacy types not supported?");
			break;
		case _h5_field_type_tag_reference_64:
		{
			c_h5_tag_field_tag_reference_64* struct_field = new c_h5_tag_field_tag_reference_64(halo5_forge_data, field_definition);
			field = struct_field;
			break;
		}
		case _h5_field_type_struct:
		{
			ASSERT(field_definition->definition_address);
			c_h5_tag_field_struct* struct_field = new c_h5_tag_field_struct(halo5_forge_data, field_definition);
			field = struct_field;
			break;
		}
		case _h5_field_type_data_64:
		{
			c_h5_tag_field_data_64* data_field = new c_h5_tag_field_data_64(halo5_forge_data, field_definition);
			field = data_field;
			break;
		}
		case _h5_field_type_byte_flags:
		case _h5_field_type_long_flags:
		case _h5_field_type_word_flags:
		case _h5_field_type_char_enum:
		case _h5_field_type_enum:
		case _h5_field_type_long_enum:
		{
			c_h5_tag_field_enum* enum_field = new c_h5_tag_field_enum(halo5_forge_data, field_definition);
			field = enum_field;
			break;
		}
		case _h5_field_type_char_block_index:
		case _h5_field_type_custom_char_block_index:
		case _h5_field_type_short_block_index:
		case _h5_field_type_custom_short_block_index:
		case _h5_field_type_long_block_index:
		case _h5_field_type_custom_long_block_index:
		{
			c_h5_tag_field_block_index_custom_search_definition* block_index_custom_search_field = new c_h5_tag_field_block_index_custom_search_definition(halo5_forge_data, field_definition);
			field = block_index_custom_search_field;
			break;
		}
		case _h5_field_type_explanation:
		{
			c_h5_tag_field_explaination_definition* explaination_field = new c_h5_tag_field_explaination_definition(halo5_forge_data, field_definition);
			field = explaination_field;
			break;
		}
		case _h5_field_type_byte_block_flags:
		case _h5_field_type_word_block_flags:
		case _h5_field_type_long_block_flags:
		{
			ASSERT(field_definition->definition_address != 0); // want to know about anything juicy that is here!
			field = new c_h5_tag_field(halo5_forge_data, field_definition);
			break;
		}
		case _h5_field_type_char_integer:
		case _h5_field_type_short_integer:
		case _h5_field_type_long_integer:
		case _h5_field_type_int64_integer:
		case _h5_field_type_byte_integer:
		case _h5_field_type_word_integer:
		case _h5_field_type_dword_integer:
		case _h5_field_type_qword_integer:
		{
			field_definition->definition_address; // sometimes not null
			field = new c_h5_tag_field(halo5_forge_data, field_definition);
			break;
		}
		case _h5_field_type_real:
		{
			field_definition->definition_address; // sometimes
			struct data
			{
				float min;
				float max;
				float step;
			};
			data* d = (data*)field_definition->definition_address;
			field = new c_h5_tag_field(halo5_forge_data, field_definition);
			break;
		}
		case _h5_field_type_block_64:
		{
			field = new c_h5_tag_field_block_64(halo5_forge_data, field_definition);

			break;
		}
		case _h5_field_type_array:
		{
			field = new c_h5_tag_field(halo5_forge_data, field_definition);

			//const s_h5_tag_block_definition_header* tag_block_definition_header = reinterpret_cast<const s_h5_tag_block_definition_header*>(h5_aa_to_pointer(halo5_forge_data, field_definition->definition_address));
			//c_h5_tag_block_definition* tag_block_definition = c_blamboozle_h5_forge::get_tag_block_definition(field_definition->definition_address, halo5_forge_data, tag_block_definition_header);
			//field->tag_block_definition = tag_block_definition;

			break;
		}
		case _h5_field_type_pad:
			field = new c_h5_tag_field_pad(halo5_forge_data, field_definition);
			break;
		case _h5_field_type_skip:
			field = new c_h5_tag_field_skip(halo5_forge_data, field_definition);
			break;
		case _h5_field_type_string_id:
			field = new c_h5_tag_field_string_id(halo5_forge_data, field_definition);
			break;
		case _h5_field_type_string:
			field = new c_h5_tag_field_string(halo5_forge_data, field_definition);
			break;
		case _h5_field_type_pageable_resource_64:
			ASSERT(field_definition->definition_address != 0);
			field = new c_h5_tag_field(halo5_forge_data, field_definition);
			break;
		case _h5_field_type_custom:
			field_definition->definition_address; // sometimes
			field = new c_h5_tag_field(halo5_forge_data, field_definition);
			break;

		default:
		{
			ASSERT(field_definition->definition_address == 0); // want to know about anything juicy that is here!
			field = new c_h5_tag_field(halo5_forge_data, field_definition);
			break;
		}
		}

		


		tag_fields.emplace_back(field);
		field_definition++;
		field_index++;
	}

}
