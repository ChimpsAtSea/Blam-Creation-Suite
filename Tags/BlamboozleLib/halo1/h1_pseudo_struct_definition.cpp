#include "blamboozlelib-private-pch.h"

c_h1_pseudo_struct_definition::c_h1_pseudo_struct_definition(
	const char* guerilla_data, 
	const s_h1_tag_field* fields, 
	c_h1_tag_block_definition& block_definition, 
	c_h1_pseudo_array_definition* pseudo_array_definition) :
	name(),
	code_name(),
	pseudo_fields(),
	block_definition(block_definition),
	fields_begin(fields),
	fields_end(nullptr),
	pseudo_array_definition(pseudo_array_definition)
{
	if (pseudo_array_definition)
	{
		name = pseudo_array_definition->name;
		code_name = pseudo_array_definition->code_name;
		code_name += "_array_struct_definition";
	}
	else
	{
		name = block_definition.name;
		code_name = block_definition.code_name;
		code_name += "_struct_definition";
	}

	const s_h1_tag_field* field = fields;
	for (; field->field_type != _h1_field_type_terminator; field++)
	{
		c_h1_pseudo_field_definition* pseudo_field = new() c_h1_pseudo_field_definition(guerilla_data, *field);

		switch (field->field_type)
		{
		case _h1_field_type_tag_reference:
			break;
		case _h1_field_type_block:
		{
			c_h1_tag_block_definition* tag_block_definition = h1_get_tag_block_definition(guerilla_data, field->definition_address);
			debug_point;
		}
		break;
		case _h1_field_type_short_block_index:
		case _h1_field_type_long_block_index:
		case _h1_field_type_data:
			break;
		case _h1_field_type_array_start:
		{
			c_h1_pseudo_array_definition* pseudo_array_definition = new() c_h1_pseudo_array_definition(guerilla_data, field, block_definition);
			pseudo_field->pseudo_array_definition = pseudo_array_definition;
			field = pseudo_array_definition->pseudo_struct_definition->fields_end;
		}
		break;
		case _h1_field_type_array_end:
			fields_end = field;
			goto array_end;
		case _h1_field_type_pad:
		case _h1_field_type_skip:
		case _h1_field_type_explanation:
		case _h1_field_type_custom:
			break;
		case _h1_field_type_enum:
		case _h1_field_type_long_flags:
		case _h1_field_type_word_flags:
		case _h1_field_type_byte_flags:
			break;
		case _h1_field_type_short_integer:
		case _h1_field_type_long_integer:
		{
			if (field->definition_address) // potentially points to a block?
			{
				//printf("%s::%s 0x%X\n", block_definition.name, pseudo_field->name, field->definition_address);
			}
		}
		
		break;
		case _h1_field_type_real:
		{
			if (field->definition_address) // potentially points to a description?
			{
				const char* description = h1_va_to_pointer(guerilla_data, field->definition_address);
				//printf("%s::%s '%s'\n", block_definition.name, pseudo_field->name, description);
			}
		}
		break;
		case _h1_field_type_char_integer:
		case _h1_field_type_string:
		case _h1_field_type_angle:
		case _h1_field_type_tag:
		case _h1_field_type_point_2d:
		case _h1_field_type_rectangle_2d:
		case _h1_field_type_rgb_color:
		case _h1_field_type_argb_color:
		case _h1_field_type_real_fraction:
		case _h1_field_type_real_point_2d:
		case _h1_field_type_real_point_3d:
		case _h1_field_type_real_vector_2d:
		case _h1_field_type_real_vector_3d:
		case _h1_field_type_real_quaternion:
		case _h1_field_type_real_euler_angles_2d:
		case _h1_field_type_real_euler_angles_3d:
		case _h1_field_type_real_plane_2d:
		case _h1_field_type_real_plane_3d:
		case _h1_field_type_real_rgb_color:
		case _h1_field_type_real_argb_color:
		case _h1_field_type_real_hsv_color:
		case _h1_field_type_real_ahsv_color:
		case _h1_field_type_short_bounds:
		case _h1_field_type_angle_bounds:
		case _h1_field_type_real_bounds:
		case _h1_field_type_real_fraction_bounds:
			if (field->definition_address)
			{
				debug_point;
			}
			break;
		default:
		case _h1_field_type_terminator:
			throw;
		}

		pseudo_fields.emplace_back(pseudo_field);
	}
	fields_end = field + 1;

array_end:;

	ASSERT(field->field_type == _h1_field_type_terminator || field->field_type == _h1_field_type_array_end);
	{
		c_h1_pseudo_field_definition* pseudo_field = new() c_h1_pseudo_field_definition(guerilla_data, *field);
		pseudo_fields.emplace_back(pseudo_field);
	}

	for (c_h1_pseudo_field_definition* pseudo_field : pseudo_fields)
	{
		switch (pseudo_field->field_type)
		{
			case _h1_pseudo_field_type_string:
			case _h1_pseudo_field_type_char_integer:
			case _h1_pseudo_field_type_short_integer:
			case _h1_pseudo_field_type_long_integer:
			case _h1_pseudo_field_type_angle:
			case _h1_pseudo_field_type_tag:
			case _h1_pseudo_field_type_enum:
			case _h1_pseudo_field_type_long_flags:
			case _h1_pseudo_field_type_word_flags:
			case _h1_pseudo_field_type_byte_flags:
			case _h1_pseudo_field_type_point_2d:
			case _h1_pseudo_field_type_rectangle_2d:
			case _h1_pseudo_field_type_rgb_color:
			case _h1_pseudo_field_type_argb_color:
			case _h1_pseudo_field_type_real:
			case _h1_pseudo_field_type_real_fraction:
			case _h1_pseudo_field_type_real_point_2d:
			case _h1_pseudo_field_type_real_point_3d:
			case _h1_pseudo_field_type_real_vector_2d:
			case _h1_pseudo_field_type_real_vector_3d:
			case _h1_pseudo_field_type_real_quaternion:
			case _h1_pseudo_field_type_real_euler_angles_2d:
			case _h1_pseudo_field_type_real_euler_angles_3d:
			case _h1_pseudo_field_type_real_plane_2d:
			case _h1_pseudo_field_type_real_plane_3d:
			case _h1_pseudo_field_type_real_rgb_color:
			case _h1_pseudo_field_type_real_argb_color:
			case _h1_pseudo_field_type_real_hsv_color:
			case _h1_pseudo_field_type_real_ahsv_color:
			case _h1_pseudo_field_type_short_bounds:
			case _h1_pseudo_field_type_angle_bounds:
			case _h1_pseudo_field_type_real_bounds:
			case _h1_pseudo_field_type_real_fraction_bounds:
			case _h1_pseudo_field_type_tag_reference:
			case _h1_pseudo_field_type_block:
			case _h1_pseudo_field_type_short_block_index:
			case _h1_pseudo_field_type_long_block_index:
			case _h1_pseudo_field_type_data:
			case _h1_pseudo_field_type_array:
			case _h1_pseudo_field_type_pad:
			case _h1_pseudo_field_type_skip:
			case _h1_pseudo_field_type_explanation:
			case _h1_pseudo_field_type_custom:
			case _h1_pseudo_field_type_terminator:
				break;
			default:
				throw;
		}
	}

	ASSERT(pseudo_fields.size() >= 1);
	ASSERT(pseudo_fields.end()[-1]->field_type == _h1_pseudo_field_type_terminator);
}
