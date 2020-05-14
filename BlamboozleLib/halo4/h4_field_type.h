#pragma once

enum e_h4_field_type : uint32_t
{
	_h4_field_type_string,
	_h4_field_type_long_string,
	_h4_field_type_string_id,
	_h4_field_type_old_string_id,
	_h4_field_type_char_integer,
	_h4_field_type_short_integer,
	_h4_field_type_long_integer,
	_h4_field_type_int64_integer,
	_h4_field_type_angle,
	_h4_field_type_tag,
	_h4_field_type_char_enum,
	_h4_field_type_enum,
	_h4_field_type_long_enum,
	_h4_field_type_long_flags,
	_h4_field_type_word_flags,
	_h4_field_type_byte_flags,
	_h4_field_type_point_2d,
	_h4_field_type_rectangle_2d,
	_h4_field_type_rgb_color,
	_h4_field_type_argb_color,
	_h4_field_type_real,
	_h4_field_type_real_fraction,
	_h4_field_type_real_point_2d,
	_h4_field_type_real_point_3d,
	_h4_field_type_real_vector_2d,
	_h4_field_type_real_vector_3d,
	_h4_field_type_real_quaternion,
	_h4_field_type_real_euler_angles_2d,
	_h4_field_type_real_euler_angles_3d,
	_h4_field_type_real_plane_2d,
	_h4_field_type_real_plane_3d,
	_h4_field_type_real_rgb_color,
	_h4_field_type_real_argb_color,
	_h4_field_type_real_hsv_color,
	_h4_field_type_real_ahsv_color,
	_h4_field_type_short_bounds,
	_h4_field_type_angle_bounds,
	_h4_field_type_real_bounds,
	_h4_field_type_real_fraction_bounds,
	_h4_field_type_tag_reference,
	_h4_field_type_block,
	_h4_field_type_long_block_flags,
	_h4_field_type_word_block_flags,
	_h4_field_type_byte_block_flags,
	_h4_field_type_char_block_index,
	_h4_field_type_custom_char_block_index,
	_h4_field_type_short_block_index,
	_h4_field_type_custom_short_block_index,
	_h4_field_type_long_block_index,
	_h4_field_type_custom_long_block_index,
	_h4_field_type_data,
	_h4_field_type_vertex_buffer,
	_h4_field_type_pad,
	_h4_field_type_useless_pad,
	_h4_field_type_skip,
	_h4_field_type_non_cache_runtime_value,
	_h4_field_type_explanation,
	_h4_field_type_custom,
	_h4_field_type_struct,
	_h4_field_type_array,
	_h4_field_type_pageable,
	_h4_field_type_api_interop,
	_h4_field_type_terminator,
	_h4_field_type_byte_integer,
	_h4_field_type_word_integer,
	_h4_field_type_dword_integer,
	_h4_field_type_qword_integer,


	_h4_field_type_max,
};

inline const char* h4_field_type_to_generic_field_type(e_h4_field_type field_type)
{
	switch (field_type)
	{
	case _h4_field_type_string:										return "_field_string";
	case _h4_field_type_long_string:								return "_field_long_string";
	case _h4_field_type_string_id:									return "_field_string_id";
	case _h4_field_type_old_string_id:								return "_field_old_string_id";
	case _h4_field_type_char_integer:								return "_field_char_integer";
	case _h4_field_type_short_integer:								return "_field_short_integer";
	case _h4_field_type_long_integer:								return "_field_long_integer";
	case _h4_field_type_int64_integer:								return "_field_int64_integer";
	case _h4_field_type_angle:										return "_field_angle";
	case _h4_field_type_tag:										return "_field_tag";
	case _h4_field_type_char_enum:									return "_field_char_enum";
	case _h4_field_type_enum:										return "_field_enum";
	case _h4_field_type_long_enum:									return "_field_long_enum";
	case _h4_field_type_long_flags:									return "_field_long_flags";
	case _h4_field_type_word_flags:									return "_field_word_flags";
	case _h4_field_type_byte_flags:									return "_field_byte_flags";
	case _h4_field_type_point_2d:									return "_field_point_2d";
	case _h4_field_type_rectangle_2d:								return "_field_rectangle_2d";
	case _h4_field_type_rgb_color:									return "_field_rgb_color";
	case _h4_field_type_argb_color:									return "_field_argb_color";
	case _h4_field_type_real:										return "_field_real";
	case _h4_field_type_real_fraction:								return "_field_real_fraction";
	case _h4_field_type_real_point_2d:								return "_field_real_point_2d";
	case _h4_field_type_real_point_3d:								return "_field_real_point_3d";
	case _h4_field_type_real_vector_2d:								return "_field_real_vector_2d";
	case _h4_field_type_real_vector_3d:								return "_field_real_vector_3d";
	case _h4_field_type_real_quaternion:							return "_field_real_quaternion";
	case _h4_field_type_real_euler_angles_2d:						return "_field_real_euler_angles_2d";
	case _h4_field_type_real_euler_angles_3d:						return "_field_real_euler_angles_3d";
	case _h4_field_type_real_plane_2d:								return "_field_real_plane_2d";
	case _h4_field_type_real_plane_3d:								return "_field_real_plane_3d";
	case _h4_field_type_real_rgb_color:								return "_field_real_rgb_color";
	case _h4_field_type_real_argb_color:							return "_field_real_argb_color";
	case _h4_field_type_real_hsv_color:								return "_field_real_hsv_color";
	case _h4_field_type_real_ahsv_color:							return "_field_real_ahsv_color";
	case _h4_field_type_short_bounds:								return "_field_short_bounds";
	case _h4_field_type_angle_bounds:								return "_field_angle_bounds";
	case _h4_field_type_real_bounds:								return "_field_real_bounds";
	case _h4_field_type_real_fraction_bounds:						return "_field_real_fraction_bounds";
	case _h4_field_type_tag_reference:								return "_field_tag_reference";
	case _h4_field_type_block:										return "_field_block";
	case _h4_field_type_long_block_flags:							return "_field_long_block_flags";
	case _h4_field_type_word_block_flags:							return "_field_word_block_flags";
	case _h4_field_type_byte_block_flags:							return "_field_byte_block_flags";
	case _h4_field_type_char_block_index:							return "_field_char_block_index";
	case _h4_field_type_short_block_index:							return "_field_short_block_index";
	case _h4_field_type_long_block_index:							return "_field_long_block_index";
	case _h4_field_type_custom_char_block_index:					return "_field_custom_char_block_index";
	case _h4_field_type_custom_short_block_index:					return "_field_custom_short_block_index";
	case _h4_field_type_custom_long_block_index:					return "_field_custom_long_block_index";
	case _h4_field_type_data:										return "_field_data";
	case _h4_field_type_vertex_buffer:								return "_field_vertex_buffer";
	case _h4_field_type_pad:										return "_field_pad";
	case _h4_field_type_useless_pad:								return "_field_useless_pad";
	case _h4_field_type_skip:										return "_field_skip";
	case _h4_field_type_non_cache_runtime_value:					return "_field_non_cache_runtime_value";
	case _h4_field_type_explanation:								return "_field_explanation";
	case _h4_field_type_custom:										return "_field_custom";
	case _h4_field_type_struct:										return "_field_struct";
	case _h4_field_type_array:										return "_field_array";
	case _h4_field_type_pageable:									return "_field_pageable";
	case _h4_field_type_api_interop:								return "_field_api_interop";
	case _h4_field_type_terminator:									return "_field_terminator";
	case _h4_field_type_byte_integer:								return "_field_byte_integer";
	case _h4_field_type_word_integer:								return "_field_word_integer";
	case _h4_field_type_dword_integer:								return "_field_dword_integer";
	case _h4_field_type_qword_integer:								return "_field_qword_integer";
	}
	throw;
}
