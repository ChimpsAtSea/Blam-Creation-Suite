#include "blamboozlelib-private-pch.h"

std::map<ptr32, c_h2_pseudo_struct_definition*> c_h2_pseudo_struct_definition::pseudo_struct_definitions;

bool reverse_replace(std::string& string, std::string find, std::string replace)
{
	auto search = string.rfind(find);
	if (search != std::string::npos)
	{
		string = string.replace(string.find(find), find.length(), replace);
		return true;
	}
	return false;
}

c_h2_pseudo_struct_definition::c_h2_pseudo_struct_definition(
	const char* guerilla_data,
	const s_h2_tag_struct_definition& struct_definition,
	c_h2_tag_block_definition* tag_block_definition) :
	name(),
	code_name(),
	struct_name(),
	size_string(h2_va_to_pointer(guerilla_data, struct_definition.size_string)),
	size(struct_definition.struct_size),
	struct_definition(&struct_definition),
	is_array(true),
	pseudo_array_definition(nullptr),
	pseudo_fields(),
	fields_begin(nullptr),
	fields_end(nullptr)
{
	if (tag_block_definition) associate_tag_block(*tag_block_definition);

	const char* byteswap_name = h2_va_to_pointer(guerilla_data, struct_definition.byte_swap_definition.name);
	//if (strcmp("collision_bsp_fields_byte_swap_definition", byteswap_name) == 0)
	//{
	//	debug_point;
	//}
	if (byteswap_name)
	{
		name = byteswap_name;
		reverse_replace(name, "_byte_swap_definition", "");
		code_name = h2_convert_to_code_name(name).c_str();
		reverse_replace(name, "_fields", "");
		if (!reverse_replace(code_name, "_fields", "_struct_definition"))
		{
			code_name += "_struct_definition";
		}
	}
	else
	{
		ASSERT(tag_block_definition != nullptr); // otherwise no strings to pull a name from

		name = tag_block_definition->name;
		code_name = tag_block_definition->code_name;
		code_name += "_struct_definition";

		debug_point;
	}
	

	unsigned long existing_count = 0;
	for (auto& keyval : pseudo_struct_definitions) if (name == keyval.second->name) existing_count++;
	if (existing_count > 1)
	{
		code_name += "$";
		char existing_count_buffer[32];
		_itoa(existing_count, existing_count_buffer, 10);
		code_name += existing_count_buffer;
	}

	struct_name = "s_";
	struct_name += h2_convert_to_code_name(name).c_str();

	if (size_string)
	{
		if (const char* sizeofstr = strstr(size_string, "sizeof("))
		{
			const char* begin = sizeofstr + strlen("sizeof(");
			const char* end = strstr(begin, ")");

			struct_name = std::string(begin, end);

			begin = struct_name.data();
			end = struct_name.data() + struct_name.size();

			if (begin = strstr(begin, "struct "))
			{
				begin += strlen("struct ");

				struct_name = std::string(begin, end);
			}
		}
	}

	ASSERT(struct_definition.upgrade_definition.unknown4 >= 0);

	ASSERT(struct_definition.unknownC == 0);
	ASSERT(struct_definition.unknown10 >= 0);
	ASSERT(struct_definition.alignment_bits <= 6);
	ASSERT(struct_definition.unknown1C == 0 || struct_definition.unknown1C == 0xFFFFFFFFu);

	ASSERT(struct_definition.byte_swap_definition.unknown8 != 0);
	ASSERT(struct_definition.byte_swap_definition.signature == 0 || struct_definition.byte_swap_definition.signature == 'bysw');
	ASSERT(struct_definition.byte_swap_definition.unknown10 > 0);
	ASSERT(struct_definition.byte_swap_definition.unknown14 >= 0);
	ASSERT(struct_definition.byte_swap_definition.unknown18 == 0 || h2_va_to_pointer(guerilla_data, struct_definition.byte_swap_definition.unknown18));
	ASSERT(struct_definition.byte_swap_definition.unknown1C >= 0);
	ASSERT(struct_definition.byte_swap_definition.unknown20 >= 0);

	fields_begin = reinterpret_cast<const s_h2_tag_field*>(h2_va_to_pointer(guerilla_data, struct_definition.fields_address));
	process_fields(guerilla_data);
}

c_h2_pseudo_struct_definition::c_h2_pseudo_struct_definition(
	const char* guerilla_data,
	const s_h2_tag_field* fields,
	c_h2_pseudo_array_definition& pseudo_array_definition) :
	name(),
	code_name(),
	block_definitions(),
	struct_definition(nullptr),
	is_array(true),
	pseudo_array_definition(&pseudo_array_definition),
	pseudo_fields(),
	fields_begin(fields),
	fields_end(nullptr)
{
	name = pseudo_array_definition.name;
	code_name = pseudo_array_definition.code_name;
	code_name += "_struct_definition";

	process_fields(guerilla_data);

	static unsigned long array_index = 0;  // #HACK
	pseudo_struct_definitions[array_index] = this;
	array_index++;
}

c_h2_pseudo_struct_definition* c_h2_pseudo_struct_definition::h2_get_pseudo_struct_definition(const char* guerilla_data, ptr32 virtual_address, c_h2_tag_block_definition* tag_block_definition)
{
	std::map<ptr32, c_h2_pseudo_struct_definition*>::iterator tag_block_definition_iterator = pseudo_struct_definitions.find(virtual_address);

	if (tag_block_definition_iterator != pseudo_struct_definitions.end())
	{
		c_h2_pseudo_struct_definition* pseudo_struct_definition = tag_block_definition_iterator->second;
		if (tag_block_definition)
		{
			pseudo_struct_definition->associate_tag_block(*tag_block_definition);
		}
		return pseudo_struct_definition;
	}

	const s_h2_tag_struct_definition* _tag_struct_definition = reinterpret_cast<const s_h2_tag_struct_definition*>(h2_va_to_pointer(guerilla_data, virtual_address));

	c_h2_pseudo_struct_definition* pseudo_struct_definition = reinterpret_cast<c_h2_pseudo_struct_definition*>(new char[sizeof(c_h2_pseudo_struct_definition)]);

	pseudo_struct_definitions[virtual_address] = pseudo_struct_definition;

	pseudo_struct_definition = new(pseudo_struct_definition) c_h2_pseudo_struct_definition(guerilla_data, *_tag_struct_definition, tag_block_definition);

	if (tag_block_definition)
	{
		pseudo_struct_definition->associate_tag_block(*tag_block_definition);
	}

	return pseudo_struct_definition;
}

void c_h2_pseudo_struct_definition::associate_tag_block(c_h2_tag_block_definition& block_definition)
{
	for (auto& _block_definition : block_definitions)
	{
		if (_block_definition == &block_definition)
		{
			return;
		}
	}
	block_definitions.push_back(&block_definition);
}

void c_h2_pseudo_struct_definition::process_fields(const char* guerilla_data)
{
	const s_h2_tag_field* field = fields_begin;
	for (; field->field_type != _h2_field_type_terminator; field++)
	{
		c_h2_pseudo_field_definition* pseudo_field = new() c_h2_pseudo_field_definition(guerilla_data, *field);

		switch (field->field_type)
		{
		case _h2_field_type_tag_reference:
			break;
		case _h2_field_type_block:
		{
			c_h2_tag_block_definition* tag_block_definition = c_h2_tag_block_definition::h2_get_tag_block_definition(guerilla_data, field->definition_address);
			debug_point;
		}
		break;
		case _h2_field_type_custom_char_block_index:
		case _h2_field_type_custom_short_block_index:
		case _h2_field_type_custom_long_block_index:
			break;
		case _h2_field_type_char_block_index:
		case _h2_field_type_short_block_index:
		case _h2_field_type_long_block_index:
			break;
		case _h2_field_type_data:
			break;
		case _h2_field_type_struct:
		{
			const s_h2_tag_field_struct_definition* tag_struct_definition = reinterpret_cast<const s_h2_tag_field_struct_definition*>(h2_va_to_pointer(guerilla_data, field->definition_address));
			ASSERT(tag_struct_definition);

			c_h2_tag_block_definition* block_definition = c_h2_tag_block_definition::h2_get_tag_block_definition(guerilla_data, tag_struct_definition->block_definition_address);
			ASSERT(block_definition);

			c_h2_pseudo_struct_definition* pseudo_struct_definition = block_definition->latest_pseudo_struct_definition;

			debug_point;
		}
		break;
		case _h2_field_type_array_start:
		{
			c_h2_pseudo_array_definition* pseudo_array_definition = new() c_h2_pseudo_array_definition(guerilla_data, field, *this);
			pseudo_field->pseudo_array_definition = pseudo_array_definition;
			field = pseudo_array_definition->array_pseudo_struct_definition->fields_end;
		}
		break;
		case _h2_field_type_array_end:
			fields_end = field;
			goto array_end;
		case _h2_field_type_pad:
		case _h2_field_type_skip:
		case _h2_field_type_explanation:
		case _h2_field_type_custom:
			break;
		case _h2_field_type_char_enum:
		case _h2_field_type_enum:
		case _h2_field_type_long_enum:
		case _h2_field_type_long_flags:
		case _h2_field_type_word_flags:
		case _h2_field_type_byte_flags:
			break;
		case _h2_field_type_long_block_flags:
		case _h2_field_type_word_block_flags:
		case _h2_field_type_byte_block_flags:
			break;
		case _h2_field_type_short_integer:
		case _h2_field_type_long_integer:
		{
			if (field->definition_address) // potentially points to a block?
			{
				//printf("%s::%s 0x%X\n", block_definition.name, pseudo_field->name, field->definition_address);
			}
		}

		break;
		case _h2_field_type_real:
		{
			if (field->definition_address) // potentially points to a description?
			{
				const char* description = h2_va_to_pointer(guerilla_data, field->definition_address);
				//printf("%s::%s '%s'\n", block_definition.name, pseudo_field->name, description);
			}
		}
		break;
		case _h2_field_type_char_integer:
		case _h2_field_type_string:
		case _h2_field_type_angle:
		case _h2_field_type_tag:
		case _h2_field_type_point_2d:
		case _h2_field_type_rectangle_2d:
		case _h2_field_type_rgb_color:
		case _h2_field_type_argb_color:
		case _h2_field_type_real_fraction:
		case _h2_field_type_real_point_2d:
		case _h2_field_type_real_point_3d:
		case _h2_field_type_real_vector_2d:
		case _h2_field_type_real_vector_3d:
		case _h2_field_type_real_quaternion:
		case _h2_field_type_real_euler_angles_2d:
		case _h2_field_type_real_euler_angles_3d:
		case _h2_field_type_real_plane_2d:
		case _h2_field_type_real_plane_3d:
		case _h2_field_type_real_rgb_color:
		case _h2_field_type_real_argb_color:
		case _h2_field_type_real_hsv_color:
		case _h2_field_type_real_ahsv_color:
		case _h2_field_type_short_bounds:
		case _h2_field_type_angle_bounds:
		case _h2_field_type_real_bounds:
		case _h2_field_type_real_fraction_bounds:
			if (field->definition_address)
			{
				debug_point;
			}
			break;
		case _h2_field_type_terminator:
			throw;
		}

		pseudo_fields.emplace_back(pseudo_field);
	}
	fields_end = field + 1;

array_end:;

	ASSERT(field->field_type == _h2_field_type_terminator || field->field_type == _h2_field_type_array_end);
	{
		c_h2_pseudo_field_definition* pseudo_field = new() c_h2_pseudo_field_definition(guerilla_data, *field);
		pseudo_fields.emplace_back(pseudo_field);
	}

	for (c_h2_pseudo_field_definition* pseudo_field : pseudo_fields)
	{
		switch (pseudo_field->field_type)
		{
		case _h2_pseudo_field_type_string:
		case _h2_pseudo_field_type_long_string:
		case _h2_pseudo_field_type_string_id:
		case _h2_pseudo_field_type_old_string_id:
		case _h2_pseudo_field_type_char_integer:
		case _h2_pseudo_field_type_short_integer:
		case _h2_pseudo_field_type_long_integer:
		case _h2_pseudo_field_type_angle:
		case _h2_pseudo_field_type_tag:
		case _h2_pseudo_field_type_char_enum:
		case _h2_pseudo_field_type_enum:
		case _h2_pseudo_field_type_long_enum:
		case _h2_pseudo_field_type_long_flags:
		case _h2_pseudo_field_type_word_flags:
		case _h2_pseudo_field_type_byte_flags:
		case _h2_pseudo_field_type_long_block_flags:
		case _h2_pseudo_field_type_word_block_flags:
		case _h2_pseudo_field_type_byte_block_flags:
		case _h2_pseudo_field_type_point_2d:
		case _h2_pseudo_field_type_rectangle_2d:
		case _h2_pseudo_field_type_rgb_color:
		case _h2_pseudo_field_type_argb_color:
		case _h2_pseudo_field_type_real:
		case _h2_pseudo_field_type_real_fraction:
		case _h2_pseudo_field_type_real_point_2d:
		case _h2_pseudo_field_type_real_point_3d:
		case _h2_pseudo_field_type_real_vector_2d:
		case _h2_pseudo_field_type_real_vector_3d:
		case _h2_pseudo_field_type_real_quaternion:
		case _h2_pseudo_field_type_real_euler_angles_2d:
		case _h2_pseudo_field_type_real_euler_angles_3d:
		case _h2_pseudo_field_type_real_plane_2d:
		case _h2_pseudo_field_type_real_plane_3d:
		case _h2_pseudo_field_type_real_rgb_color:
		case _h2_pseudo_field_type_real_argb_color:
		case _h2_pseudo_field_type_real_hsv_color:
		case _h2_pseudo_field_type_real_ahsv_color:
		case _h2_pseudo_field_type_short_bounds:
		case _h2_pseudo_field_type_angle_bounds:
		case _h2_pseudo_field_type_real_bounds:
		case _h2_pseudo_field_type_real_fraction_bounds:
		case _h2_pseudo_field_type_tag_reference:
		case _h2_pseudo_field_type_block:
		case _h2_pseudo_field_type_char_block_index:
		case _h2_pseudo_field_type_short_block_index:
		case _h2_pseudo_field_type_long_block_index:
		case _h2_pseudo_field_type_custom_char_block_index:
		case _h2_pseudo_field_type_custom_short_block_index:
		case _h2_pseudo_field_type_custom_long_block_index:
		case _h2_pseudo_field_type_data:
		case _h2_pseudo_field_type_array:
		case _h2_pseudo_field_type_pad:
		case _h2_pseudo_field_type_skip:
		case _h2_pseudo_field_type_explanation:
		case _h2_pseudo_field_type_custom:
		case _h2_pseudo_field_type_struct:
		case _h2_pseudo_field_type_useless_pad:
		case _h2_pseudo_field_type_vertex_buffer:
		case _h2_pseudo_field_type_terminator:
			break;
		default:
			throw;
		}
	}

	ASSERT(pseudo_fields.size() >= 1);
	ASSERT(pseudo_fields.end()[-1]->field_type == _h2_pseudo_field_type_terminator);
}
