#include "blamboozlelib-private-pch.h"

e_h2_pseudo_field_type h2_field_type_to_h2_pseudo_field_type(e_h2_field_type field_type)
{
	switch (field_type)
	{
	case _h2_field_type_string:									return _h2_pseudo_field_type_string;
	case _h2_field_type_long_string:							return _h2_pseudo_field_type_long_string;
	case _h2_field_type_string_id:								return _h2_pseudo_field_type_string_id;
	case _h2_field_type_old_string_id:							return _h2_pseudo_field_type_old_string_id;
	case _h2_field_type_char_integer:							return _h2_pseudo_field_type_char_integer;
	case _h2_field_type_short_integer:							return _h2_pseudo_field_type_short_integer;
	case _h2_field_type_long_integer:							return _h2_pseudo_field_type_long_integer;
	case _h2_field_type_angle:									return _h2_pseudo_field_type_angle;
	case _h2_field_type_tag:									return _h2_pseudo_field_type_tag;
	case _h2_field_type_char_enum:								return _h2_pseudo_field_type_char_enum;
	case _h2_field_type_enum:									return _h2_pseudo_field_type_enum;
	case _h2_field_type_long_enum:								return _h2_pseudo_field_type_long_enum;
	case _h2_field_type_long_flags:								return _h2_pseudo_field_type_long_flags;
	case _h2_field_type_word_flags:								return _h2_pseudo_field_type_word_flags;
	case _h2_field_type_byte_flags:								return _h2_pseudo_field_type_byte_flags;
	case _h2_field_type_point_2d:								return _h2_pseudo_field_type_point_2d;
	case _h2_field_type_rectangle_2d:							return _h2_pseudo_field_type_rectangle_2d;
	case _h2_field_type_rgb_color:								return _h2_pseudo_field_type_rgb_color;
	case _h2_field_type_argb_color:								return _h2_pseudo_field_type_argb_color;
	case _h2_field_type_real:									return _h2_pseudo_field_type_real;
	case _h2_field_type_real_fraction:							return _h2_pseudo_field_type_real_fraction;
	case _h2_field_type_real_point_2d:							return _h2_pseudo_field_type_real_point_2d;
	case _h2_field_type_real_point_3d:							return _h2_pseudo_field_type_real_point_3d;
	case _h2_field_type_real_vector_2d:							return _h2_pseudo_field_type_real_vector_2d;
	case _h2_field_type_real_vector_3d:							return _h2_pseudo_field_type_real_vector_3d;
	case _h2_field_type_real_quaternion:						return _h2_pseudo_field_type_real_quaternion;
	case _h2_field_type_real_euler_angles_2d:					return _h2_pseudo_field_type_real_euler_angles_2d;
	case _h2_field_type_real_euler_angles_3d:					return _h2_pseudo_field_type_real_euler_angles_3d;
	case _h2_field_type_real_plane_2d:							return _h2_pseudo_field_type_real_plane_2d;
	case _h2_field_type_real_plane_3d:							return _h2_pseudo_field_type_real_plane_3d;
	case _h2_field_type_real_rgb_color:							return _h2_pseudo_field_type_real_rgb_color;
	case _h2_field_type_real_argb_color:						return _h2_pseudo_field_type_real_argb_color;
	case _h2_field_type_real_hsv_color:							return _h2_pseudo_field_type_real_hsv_color;
	case _h2_field_type_real_ahsv_color:						return _h2_pseudo_field_type_real_ahsv_color;
	case _h2_field_type_short_bounds:							return _h2_pseudo_field_type_short_bounds;
	case _h2_field_type_angle_bounds:							return _h2_pseudo_field_type_angle_bounds;
	case _h2_field_type_real_bounds:							return _h2_pseudo_field_type_real_bounds;
	case _h2_field_type_real_fraction_bounds:					return _h2_pseudo_field_type_real_fraction_bounds;
	case _h2_field_type_tag_reference:							return _h2_pseudo_field_type_tag_reference;
	case _h2_field_type_block:									return _h2_pseudo_field_type_block;
	case _h2_field_type_long_block_flags:						return _h2_pseudo_field_type_long_block_flags;
	case _h2_field_type_word_block_flags:						return _h2_pseudo_field_type_word_block_flags;
	case _h2_field_type_byte_block_flags:						return _h2_pseudo_field_type_byte_block_flags;
	case _h2_field_type_char_block_index:						return _h2_pseudo_field_type_char_block_index;
	case _h2_field_type_custom_char_block_index:				return _h2_pseudo_field_type_custom_char_block_index;
	case _h2_field_type_custom_short_block_index:				return _h2_pseudo_field_type_custom_short_block_index;
	case _h2_field_type_custom_long_block_index:				return _h2_pseudo_field_type_custom_long_block_index;
	case _h2_field_type_short_block_index:						return _h2_pseudo_field_type_short_block_index;
	case _h2_field_type_long_block_index:						return _h2_pseudo_field_type_long_block_index;
	case _h2_field_type_data:									return _h2_pseudo_field_type_data;
	case _h2_field_type_array_start:							return _h2_pseudo_field_type_array;
	case _h2_field_type_array_end:								return _h2_pseudo_field_type_array;
	case _h2_field_type_pad:									return _h2_pseudo_field_type_pad;
	case _h2_field_type_useless_pad:							return _h2_pseudo_field_type_useless_pad;
	case _h2_field_type_skip:									return _h2_pseudo_field_type_skip;
	case _h2_field_type_explanation:							return _h2_pseudo_field_type_explanation;
	case _h2_field_type_custom:									return _h2_pseudo_field_type_custom;
	case _h2_field_type_vertex_buffer:							return _h2_pseudo_field_type_vertex_buffer;
	case _h2_field_type_struct:									return _h2_pseudo_field_type_struct;
	case _h2_field_type_terminator:								return _h2_pseudo_field_type_terminator;
	}
	throw;
}

const char* h2_pseudo_field_type_to_generic_field_type(e_h2_pseudo_field_type field_type)
{
	switch (field_type)
	{
	case _h2_pseudo_field_type_string:								return "_field_string";
	case _h2_pseudo_field_type_char_integer:						return "_field_char_integer";
	case _h2_pseudo_field_type_short_integer:						return "_field_short_integer";
	case _h2_pseudo_field_type_long_integer:						return "_field_long_integer";
	case _h2_pseudo_field_type_angle:								return "_field_angle";
	case _h2_pseudo_field_type_tag:									return "_field_tag";
	case _h2_pseudo_field_type_enum:								return "_field_enum";
	case _h2_pseudo_field_type_long_flags:							return "_field_long_flags";
	case _h2_pseudo_field_type_word_flags:							return "_field_word_flags";
	case _h2_pseudo_field_type_byte_flags:							return "_field_byte_flags";
	case _h2_pseudo_field_type_point_2d:							return "_field_point_2d";
	case _h2_pseudo_field_type_rectangle_2d:						return "_field_rectangle_2d";
	case _h2_pseudo_field_type_rgb_color:							return "_field_rgb_color";
	case _h2_pseudo_field_type_argb_color:							return "_field_argb_color";
	case _h2_pseudo_field_type_real:								return "_field_real";
	case _h2_pseudo_field_type_real_fraction:						return "_field_real_fraction";
	case _h2_pseudo_field_type_real_point_2d:						return "_field_real_point_2d";
	case _h2_pseudo_field_type_real_point_3d:						return "_field_real_point_3d";
	case _h2_pseudo_field_type_real_vector_2d:						return "_field_real_vector_2d";
	case _h2_pseudo_field_type_real_vector_3d:						return "_field_real_vector_3d";
	case _h2_pseudo_field_type_real_quaternion:						return "_field_real_quaternion";
	case _h2_pseudo_field_type_real_euler_angles_2d:				return "_field_real_euler_angles_2d";
	case _h2_pseudo_field_type_real_euler_angles_3d:				return "_field_real_euler_angles_3d";
	case _h2_pseudo_field_type_real_plane_2d:						return "_field_real_plane_2d";
	case _h2_pseudo_field_type_real_plane_3d:						return "_field_real_plane_3d";
	case _h2_pseudo_field_type_real_rgb_color:						return "_field_real_rgb_color";
	case _h2_pseudo_field_type_real_argb_color:						return "_field_real_argb_color";
	case _h2_pseudo_field_type_real_hsv_color:						return "_field_real_hsv_color";
	case _h2_pseudo_field_type_real_ahsv_color:						return "_field_real_ahsv_color";
	case _h2_pseudo_field_type_short_bounds:						return "_field_short_bounds";
	case _h2_pseudo_field_type_angle_bounds:						return "_field_angle_bounds";
	case _h2_pseudo_field_type_real_bounds:							return "_field_real_bounds";
	case _h2_pseudo_field_type_real_fraction_bounds:				return "_field_real_fraction_bounds";
	case _h2_pseudo_field_type_tag_reference:						return "_field_tag_reference";
	case _h2_pseudo_field_type_block:								return "_field_block";
	case _h2_pseudo_field_type_short_block_index:					return "_field_short_block_index";
	case _h2_pseudo_field_type_long_block_index:					return "_field_long_block_index";
	case _h2_pseudo_field_type_data:								return "_field_data";
	case _h2_pseudo_field_type_array:								return "_field_array";
	case _h2_pseudo_field_type_pad:									return "_field_pad";
	case _h2_pseudo_field_type_skip:								return "_field_skip";
	case _h2_pseudo_field_type_explanation:							return "_field_explanation";
	case _h2_pseudo_field_type_custom:								return "_field_custom";
	case _h2_pseudo_field_type_terminator:							return "_field_terminator";
	case _h2_pseudo_field_type_struct:								return "_field_struct";

	case _h2_pseudo_field_type_long_string:							return "_field_long_string";
	case _h2_pseudo_field_type_string_id:							return "_field_string_id";
	case _h2_pseudo_field_type_old_string_id:						return "_field_old_string_id";
	case _h2_pseudo_field_type_char_enum:							return "_field_char_enum";
	case _h2_pseudo_field_type_long_enum:							return "_field_long_enum";
	case _h2_pseudo_field_type_long_block_flags:					return "_field_long_block_flags";
	case _h2_pseudo_field_type_word_block_flags:					return "_field_word_block_flags";
	case _h2_pseudo_field_type_byte_block_flags:					return "_field_byte_block_flags";
	case _h2_pseudo_field_type_char_block_index:					return "_field_char_block_index";
	case _h2_pseudo_field_type_custom_char_block_index:				return "_field_custom_char_block_index";
	case _h2_pseudo_field_type_custom_short_block_index:			return "_field_custom_short_block_index";
	case _h2_pseudo_field_type_custom_long_block_index:				return "_field_custom_long_block_index";
	case _h2_pseudo_field_type_useless_pad:							return "_field_useless_pad";
	case _h2_pseudo_field_type_vertex_buffer:						return "_field_vertex_buffer";
	}
	throw;
}
