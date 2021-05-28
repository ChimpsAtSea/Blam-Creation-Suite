#pragma once

enum e_h1_pseudo_field_type : short
{
	_h1_pseudo_field_type_string,
	_h1_pseudo_field_type_char_integer,
	_h1_pseudo_field_type_short_integer,
	_h1_pseudo_field_type_long_integer,
	_h1_pseudo_field_type_angle,
	_h1_pseudo_field_type_tag,
	_h1_pseudo_field_type_enum,
	_h1_pseudo_field_type_long_flags,
	_h1_pseudo_field_type_word_flags,
	_h1_pseudo_field_type_byte_flags,
	_h1_pseudo_field_type_point_2d,
	_h1_pseudo_field_type_rectangle_2d,
	_h1_pseudo_field_type_rgb_color,
	_h1_pseudo_field_type_argb_color,
	_h1_pseudo_field_type_real,
	_h1_pseudo_field_type_real_fraction,
	_h1_pseudo_field_type_real_point_2d,
	_h1_pseudo_field_type_real_point_3d,
	_h1_pseudo_field_type_real_vector_2d,
	_h1_pseudo_field_type_real_vector_3d,
	_h1_pseudo_field_type_real_quaternion,
	_h1_pseudo_field_type_real_euler_angles_2d,
	_h1_pseudo_field_type_real_euler_angles_3d,
	_h1_pseudo_field_type_real_plane_2d,
	_h1_pseudo_field_type_real_plane_3d,
	_h1_pseudo_field_type_real_rgb_color,
	_h1_pseudo_field_type_real_argb_color,
	_h1_pseudo_field_type_real_hsv_color,
	_h1_pseudo_field_type_real_ahsv_color,
	_h1_pseudo_field_type_short_bounds,
	_h1_pseudo_field_type_angle_bounds,
	_h1_pseudo_field_type_real_bounds,
	_h1_pseudo_field_type_real_fraction_bounds,
	_h1_pseudo_field_type_tag_reference,
	_h1_pseudo_field_type_block,
	_h1_pseudo_field_type_short_block_index,
	_h1_pseudo_field_type_long_block_index,
	_h1_pseudo_field_type_data,
	_h1_pseudo_field_type_array,
	_h1_pseudo_field_type_pad,
	_h1_pseudo_field_type_skip,
	_h1_pseudo_field_type_explanation,
	_h1_pseudo_field_type_custom,
	_h1_pseudo_field_type_terminator,
	_h1_pseudo_field_type_struct
};

extern e_h1_pseudo_field_type h1_field_type_to_h1_pseudo_field_type(e_h1_field_type field_type);


inline const char* h1_pseudo_field_type_to_generic_field_type(e_h1_pseudo_field_type field_type)
{
	switch (field_type)
	{
	case _h1_pseudo_field_type_string:								return "_field_string";
	case _h1_pseudo_field_type_char_integer:						return "_field_char_integer";
	case _h1_pseudo_field_type_short_integer:						return "_field_short_integer";
	case _h1_pseudo_field_type_long_integer:						return "_field_long_integer";
	case _h1_pseudo_field_type_angle:								return "_field_angle";
	case _h1_pseudo_field_type_tag:									return "_field_tag";
	case _h1_pseudo_field_type_enum:								return "_field_enum";
	case _h1_pseudo_field_type_long_flags:							return "_field_long_flags";
	case _h1_pseudo_field_type_word_flags:							return "_field_word_flags";
	case _h1_pseudo_field_type_byte_flags:							return "_field_byte_flags";
	case _h1_pseudo_field_type_point_2d:							return "_field_point_2d";
	case _h1_pseudo_field_type_rectangle_2d:						return "_field_rectangle_2d";
	case _h1_pseudo_field_type_rgb_color:							return "_field_rgb_color";
	case _h1_pseudo_field_type_argb_color:							return "_field_argb_color";
	case _h1_pseudo_field_type_real:								return "_field_real";
	case _h1_pseudo_field_type_real_fraction:						return "_field_real_fraction";
	case _h1_pseudo_field_type_real_point_2d:						return "_field_real_point_2d";
	case _h1_pseudo_field_type_real_point_3d:						return "_field_real_point_3d";
	case _h1_pseudo_field_type_real_vector_2d:						return "_field_real_vector_2d";
	case _h1_pseudo_field_type_real_vector_3d:						return "_field_real_vector_3d";
	case _h1_pseudo_field_type_real_quaternion:						return "_field_real_quaternion";
	case _h1_pseudo_field_type_real_euler_angles_2d:				return "_field_real_euler_angles_2d";
	case _h1_pseudo_field_type_real_euler_angles_3d:				return "_field_real_euler_angles_3d";
	case _h1_pseudo_field_type_real_plane_2d:						return "_field_real_plane_2d";
	case _h1_pseudo_field_type_real_plane_3d:						return "_field_real_plane_3d";
	case _h1_pseudo_field_type_real_rgb_color:						return "_field_real_rgb_color";
	case _h1_pseudo_field_type_real_argb_color:						return "_field_real_argb_color";
	case _h1_pseudo_field_type_real_hsv_color:						return "_field_real_hsv_color";
	case _h1_pseudo_field_type_real_ahsv_color:						return "_field_real_ahsv_color";
	case _h1_pseudo_field_type_short_bounds:						return "_field_short_bounds";
	case _h1_pseudo_field_type_angle_bounds:						return "_field_angle_bounds";
	case _h1_pseudo_field_type_real_bounds:							return "_field_real_bounds";
	case _h1_pseudo_field_type_real_fraction_bounds:				return "_field_real_fraction_bounds";
	case _h1_pseudo_field_type_tag_reference:						return "_field_tag_reference";
	case _h1_pseudo_field_type_block:								return "_field_block";
	case _h1_pseudo_field_type_short_block_index:					return "_field_short_block_index";
	case _h1_pseudo_field_type_long_block_index:					return "_field_long_block_index";
	case _h1_pseudo_field_type_data:								return "_field_data";
	case _h1_pseudo_field_type_array:								return "_field_array";
	case _h1_pseudo_field_type_pad:									return "_field_pad";
	case _h1_pseudo_field_type_skip:								return "_field_skip";
	case _h1_pseudo_field_type_explanation:							return "_field_explanation";
	case _h1_pseudo_field_type_custom:								return "_field_custom";
	case _h1_pseudo_field_type_terminator:							return "_field_terminator";
	case _h1_pseudo_field_type_struct:								return "_field_struct";
	}
	throw;
}

