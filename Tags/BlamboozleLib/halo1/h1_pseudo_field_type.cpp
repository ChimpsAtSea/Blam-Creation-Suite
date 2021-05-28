#include "blamboozlelib-private-pch.h"

e_h1_pseudo_field_type h1_field_type_to_h1_pseudo_field_type(e_h1_field_type field_type)
{
	switch (field_type)
	{
	case _h1_field_type_string:									return _h1_pseudo_field_type_string;
	case _h1_field_type_char_integer:							return _h1_pseudo_field_type_char_integer;
	case _h1_field_type_short_integer:							return _h1_pseudo_field_type_short_integer;
	case _h1_field_type_long_integer:							return _h1_pseudo_field_type_long_integer;
	case _h1_field_type_angle:									return _h1_pseudo_field_type_angle;
	case _h1_field_type_tag:									return _h1_pseudo_field_type_tag;
	case _h1_field_type_enum:									return _h1_pseudo_field_type_enum;
	case _h1_field_type_long_flags:								return _h1_pseudo_field_type_long_flags;
	case _h1_field_type_word_flags:								return _h1_pseudo_field_type_word_flags;
	case _h1_field_type_byte_flags:								return _h1_pseudo_field_type_byte_flags;
	case _h1_field_type_point_2d:								return _h1_pseudo_field_type_point_2d;
	case _h1_field_type_rectangle_2d:							return _h1_pseudo_field_type_rectangle_2d;
	case _h1_field_type_rgb_color:								return _h1_pseudo_field_type_rgb_color;
	case _h1_field_type_argb_color:								return _h1_pseudo_field_type_argb_color;
	case _h1_field_type_real:									return _h1_pseudo_field_type_real;
	case _h1_field_type_real_fraction:							return _h1_pseudo_field_type_real_fraction;
	case _h1_field_type_real_point_2d:							return _h1_pseudo_field_type_real_point_2d;
	case _h1_field_type_real_point_3d:							return _h1_pseudo_field_type_real_point_3d;
	case _h1_field_type_real_vector_2d:							return _h1_pseudo_field_type_real_vector_2d;
	case _h1_field_type_real_vector_3d:							return _h1_pseudo_field_type_real_vector_3d;
	case _h1_field_type_real_quaternion:						return _h1_pseudo_field_type_real_quaternion;
	case _h1_field_type_real_euler_angles_2d:					return _h1_pseudo_field_type_real_euler_angles_2d;
	case _h1_field_type_real_euler_angles_3d:					return _h1_pseudo_field_type_real_euler_angles_3d;
	case _h1_field_type_real_plane_2d:							return _h1_pseudo_field_type_real_plane_2d;
	case _h1_field_type_real_plane_3d:							return _h1_pseudo_field_type_real_plane_3d;
	case _h1_field_type_real_rgb_color:							return _h1_pseudo_field_type_real_rgb_color;
	case _h1_field_type_real_argb_color:						return _h1_pseudo_field_type_real_argb_color;
	case _h1_field_type_real_hsv_color:							return _h1_pseudo_field_type_real_hsv_color;
	case _h1_field_type_real_ahsv_color:						return _h1_pseudo_field_type_real_ahsv_color;
	case _h1_field_type_short_bounds:							return _h1_pseudo_field_type_short_bounds;
	case _h1_field_type_angle_bounds:							return _h1_pseudo_field_type_angle_bounds;
	case _h1_field_type_real_bounds:							return _h1_pseudo_field_type_real_bounds;
	case _h1_field_type_real_fraction_bounds:					return _h1_pseudo_field_type_real_fraction_bounds;
	case _h1_field_type_tag_reference:							return _h1_pseudo_field_type_tag_reference;
	case _h1_field_type_block:									return _h1_pseudo_field_type_block;
	case _h1_field_type_short_block_index:						return _h1_pseudo_field_type_short_block_index;
	case _h1_field_type_long_block_index:						return _h1_pseudo_field_type_long_block_index;
	case _h1_field_type_data:									return _h1_pseudo_field_type_data;
	case _h1_field_type_array_start:							return _h1_pseudo_field_type_array;
	case _h1_field_type_array_end:								return _h1_pseudo_field_type_array;
	case _h1_field_type_pad:									return _h1_pseudo_field_type_pad;
	case _h1_field_type_skip:									return _h1_pseudo_field_type_skip;
	case _h1_field_type_explanation:							return _h1_pseudo_field_type_explanation;
	case _h1_field_type_custom:									return _h1_pseudo_field_type_custom;
	case _h1_field_type_terminator:								return _h1_pseudo_field_type_terminator;
	}
	throw;
}