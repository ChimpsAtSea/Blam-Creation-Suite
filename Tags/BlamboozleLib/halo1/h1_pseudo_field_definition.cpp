#include "blamboozlelib-private-pch.h"

c_h1_pseudo_field_definition::c_h1_pseudo_field_definition(const char* guerilla_data, const s_h1_tag_field& field) :
	name(va_to_pointer(guerilla_data, field.name_address)),
	field_type(h1_field_type_to_h1_pseudo_field_type(field.field_type)),
	field(&field),
	block_definition(nullptr),
	tag_reference_definition(nullptr),
	struct_definition(nullptr),
	pseudo_array_definition(nullptr),
	string_list_definition(nullptr),
	padding(),
	skip_length(),
	explanation()
{
	if (field.definition_address)
	{
		if (field.field_type == _h1_field_type_real)
		{
			ASSERT(strstr(name, "#") == nullptr);
			ASSERT(strstr(name, "(") == nullptr);
			const char* bad_description = va_to_pointer(guerilla_data, field.definition_address);
			size_t new_name_buffer_size = strlen(name) + strlen(bad_description) + 2;
			char* new_name_buffer = new char[new_name_buffer_size];
			snprintf(new_name_buffer, new_name_buffer_size, "%s#%s", name, bad_description);
			new_name_buffer[new_name_buffer_size - 1] = 0;

			name = new_name_buffer;
		}
		if (field.field_type == _h1_field_type_short_integer)
		{
			field_type = _h1_pseudo_field_type_short_block_index;
		}
		if (field.field_type == _h1_field_type_long_integer)
		{
			field_type = _h1_pseudo_field_type_long_block_index;
		}
	}
	if (field.field_type == _h1_field_type_array_end)
	{
		field_type = _h1_pseudo_field_type_terminator;
	}

	switch (field_type)
	{
	case _h1_pseudo_field_type_short_block_index:
	case _h1_pseudo_field_type_long_block_index:
	case _h1_pseudo_field_type_block:
		block_definition = get_tag_block_definition(guerilla_data, field.definition_address);
		break;
	case _h1_pseudo_field_type_tag_reference:
		tag_reference_definition = get_tag_reference_definition(guerilla_data, field.definition_address);
		break;
	case _h1_pseudo_field_type_pad:
	case _h1_pseudo_field_type_skip:
		padding = skip_length = field.definition_address;
		break;
	case _h1_pseudo_field_type_enum:
	case _h1_pseudo_field_type_long_flags:
	case _h1_pseudo_field_type_word_flags:
	case _h1_pseudo_field_type_byte_flags:
		string_list_definition = get_string_list_definition(guerilla_data, field.definition_address);
		break;
	case _h1_pseudo_field_type_explanation:
		if (field.definition_address)
			explanation = va_to_pointer(guerilla_data, field.definition_address);
		break;
	}
}

c_h1_pseudo_field_definition::c_h1_pseudo_field_definition(c_h1_tag_group_definition& tag_group_definition) :
	name(),
	field_type(_h1_pseudo_field_type_struct),
	field(nullptr),
	block_definition(nullptr),
	tag_reference_definition(nullptr),
	struct_definition(tag_group_definition.tag_block_definition->pseudo_struct_definition),
	pseudo_array_definition(nullptr),
	string_list_definition(nullptr),
	padding(),
	skip_length(),
	explanation()
{
	name = tag_group_definition.name;
}
