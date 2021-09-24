#include "tagdefinitions-private-pch.h"

using namespace blofeld;

unsigned long blofeld::get_blofeld_field_size(e_platform_type platform_type, e_field field)
{
	if (field > _field_type_non_standard)
	{
		return 0;
	}
	switch (field)
	{
	case _field_string:							return sizeof(::c_static_string<32>);
	case _field_long_string:					return sizeof(::c_static_string<256>);
	case _field_string_id:						return sizeof(string_id);
	case _field_old_string_id:					return sizeof(::c_old_string_id);
	case _field_char_integer:					return sizeof(char);
	case _field_short_integer:					return sizeof(short);
	case _field_long_integer:					return sizeof(long);
	case _field_int64_integer:					return sizeof(long long);
	case _field_angle:							return sizeof(angle);
	case _field_tag:							return sizeof(tag);
	case _field_char_enum:						return sizeof(char);
	case _field_enum:							return sizeof(short);
	case _field_long_enum:						return sizeof(long);
	case _field_long_flags:						return sizeof(long);
	case _field_word_flags:						return sizeof(word);
	case _field_byte_flags:						return sizeof(byte);
	case _field_point_2d:						return sizeof(::s_point2d);
	case _field_rectangle_2d:					return sizeof(::s_rectangle2d);
	case _field_rgb_color:						return sizeof(::pixel32);
	case _field_argb_color:						return sizeof(::pixel32);
	case _field_real:							return sizeof(::real);
	case _field_real_fraction:					return sizeof(::real_fraction);
	case _field_real_point_2d:					return sizeof(::real_point2d);
	case _field_real_point_3d:					return sizeof(::real_point3d);
	case _field_real_vector_2d:					return sizeof(::real_vector2d);
	case _field_real_vector_3d:					return sizeof(::real_vector3d);
	case _field_real_quaternion:				return sizeof(::real_quaternion);
	case _field_real_euler_angles_2d:			return sizeof(::real_euler_angles2d);
	case _field_real_euler_angles_3d:			return sizeof(::real_euler_angles3d);
	case _field_real_plane_2d:					return sizeof(::real_plane2d);
	case _field_real_plane_3d:					return sizeof(::real_plane3d);
	case _field_real_rgb_color:					return sizeof(::rgb_color);
	case _field_real_argb_color:				return sizeof(::argb_color);
	case _field_real_hsv_color:					return sizeof(::real_hsv_color);
	case _field_real_ahsv_color:				return sizeof(::real_ahsv_color);
	case _field_short_bounds:					return sizeof(::short_bounds);
	case _field_angle_bounds:					return sizeof(::angle_bounds);
	case _field_real_bounds:					return sizeof(::real_bounds);
	case _field_real_fraction_bounds:			return sizeof(::real_fraction_bounds);
	case _field_tag_reference:					return sizeof(::s_tag_reference);
	case _field_block:							return sizeof(::s_tag_block);
	case _field_long_block_flags:				return sizeof(long);
	case _field_word_block_flags:				return sizeof(word);
	case _field_byte_block_flags:				return sizeof(byte);
	case _field_char_block_index:				return sizeof(char);
	case _field_custom_char_block_index:		return sizeof(char);
	case _field_short_block_index:				return sizeof(short);
	case _field_custom_short_block_index:		return sizeof(short);
	case _field_long_block_index:				return sizeof(long);
	case _field_custom_long_block_index:		return sizeof(long);
	case _field_data:							return sizeof(::s_tag_data);
	case _field_vertex_buffer:					return sizeof(::s_tag_d3d_vertex_buffer);
	case _field_pad:							return 0;	// dynamic
	case _field_useless_pad:					return 0;	// dynamic
	case _field_skip:							return 0;	// dynamic
	case _field_non_cache_runtime_value:		return 0;	// empty
	case _field_explanation:					return 0;	// empty
	case _field_custom:							return 0;	// empty
	case _field_struct:							return 0;	// dynamic
	case _field_array:							return 0;	// dynamic
	case _field_pageable:						return sizeof(::s_tag_resource);
	case _field_api_interop:					return sizeof(::s_tag_interop);
	case _field_terminator:						return 0;	// empty
	case _field_byte_integer:					return sizeof(byte);
	case _field_word_integer:					return sizeof(word);
	case _field_dword_integer:					return sizeof(dword);
	case _field_qword_integer:					return sizeof(qword);
	case _field_embedded_tag:					return sizeof(::s_tag_reference);
	case _field_data_path:						return sizeof(::c_static_string<256>);
	case _field_pointer:
	{
		unsigned long pointer_size;
		ASSERT(BCS_SUCCEEDED(get_platform_pointer_size(platform_type, &pointer_size)));
		return pointer_size;
	};
	case _field_half:							return sizeof(uint16_t);
	default: FATAL_ERROR("unknown field type");
	}
	return 0;
}

unsigned long blofeld::get_blofeld_field_size(const s_tag_field& field, s_engine_platform_build engine_platform_build)
{
	switch (field.field_type)
	{
	case _field_pad:							return field.padding;
	case _field_useless_pad:					return 0;
	case _field_skip:							return field.length;
	case _field_struct:
	{
		unsigned long structure_size = blofeld::calculate_struct_size(engine_platform_build, *field.struct_definition);
		return structure_size;
	}
	case _field_array:
	{
		unsigned long structure_size = blofeld::calculate_struct_size(engine_platform_build, field.array_definition->struct_definition);
		unsigned long array_element_count = field.array_definition->count(engine_platform_build);
		unsigned long array_size = structure_size * array_element_count;
		return array_size;
	}
	default: return get_blofeld_field_size(engine_platform_build.platform_type, field.field_type);
	}
}

const char* blofeld::field_to_string(e_field field)
{
	switch (field)
	{
	case _field_string:									return "string";
	case _field_long_string:							return "long string";
	case _field_string_id:								return "string id";
	case _field_old_string_id:							return "old string id";
	case _field_char_integer:							return "char integer";
	case _field_short_integer:							return "short integer";
	case _field_long_integer:							return "long integer";
	case _field_int64_integer:							return "int64 integer";
	case _field_angle:									return "angle";
	case _field_tag:									return "tag";
	case _field_char_enum:								return "char enum";
	case _field_enum:									return "short enum";
	case _field_long_enum:								return "long enum";
	case _field_long_flags:								return "long flags";
	case _field_word_flags:								return "word flags";
	case _field_byte_flags:								return "byte flags";
	case _field_point_2d:								return "point 2d";
	case _field_rectangle_2d:							return "rectangle 2d";
	case _field_rgb_color:								return "rgb color";
	case _field_argb_color:								return "argb color";
	case _field_real:									return "real";
	case _field_real_fraction:							return "real fraction";
	case _field_real_point_2d:							return "real point 2d";
	case _field_real_point_3d:							return "real point 3d";
	case _field_real_vector_2d:							return "real vector 2d";
	case _field_real_vector_3d:							return "real vector 3d";
	case _field_real_quaternion:						return "real quaternion";
	case _field_real_euler_angles_2d:					return "real euler angles 2d";
	case _field_real_euler_angles_3d:					return "real euler angles 3d";
	case _field_real_plane_2d:							return "real plane 2d";
	case _field_real_plane_3d:							return "real plane 3d";
	case _field_real_rgb_color:							return "real rgb color";
	case _field_real_argb_color:						return "real argb color";
	case _field_real_hsv_color:							return "real hsv color";
	case _field_real_ahsv_color:						return "real ahsv color";
	case _field_short_bounds:							return "short integer bounds";
	case _field_angle_bounds:							return "angle bounds";
	case _field_real_bounds:							return "real bounds";
	case _field_real_fraction_bounds:					return "fraction bounds";
	case _field_tag_reference:							return "tag reference";
	case _field_block:									return "block";
	case _field_long_block_flags:						return "long block flags";
	case _field_word_block_flags:						return "word block flags";
	case _field_byte_block_flags:						return "byte block flags";
	case _field_char_block_index:						return "char block index";
	case _field_custom_char_block_index:				return "custom char block index";
	case _field_short_block_index:						return "short block index";
	case _field_custom_short_block_index:				return "custom short block index";
	case _field_long_block_index:						return "long block index";
	case _field_custom_long_block_index:				return "custom long block index";
	case _field_data:									return "data";
	case _field_vertex_buffer:							return "vertex buffer";
	case _field_pad:									return "pad";
	case _field_useless_pad:							return "useless pad";
	case _field_skip:									return "skip";
	case _field_non_cache_runtime_value:				return "non-cache runtime value";
	case _field_explanation:							return "explanation";
	case _field_custom:									return "custom";
	case _field_struct:									return "struct";
	case _field_array:									return "array";
	case _field_pageable:								return "pageable resource";
	case _field_api_interop:							return "api interop";
	case _field_terminator:								return "terminator X";
	case _field_byte_integer:							return "byte integer";
	case _field_word_integer:							return "word integer";
	case _field_dword_integer:							return "dword integer";
	case _field_qword_integer:							return "qword integer";
	case _field_data_path:								return "data path"; // H5F/INF
	case _field_embedded_tag:							return "embedded tag"; // H5F/INF
	case _field_pointer:								return "pointer"; // #NONSTANDARD
	case _field_half:									return "half"; // #NONSTANDARD
	}
	return nullptr;
}
