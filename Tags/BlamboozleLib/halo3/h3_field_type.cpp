#include "blamboozlelib-private-pch.h"

const char* h3_field_type_to_string(e_h3_field_type field_type)
{
	switch (field_type)
	{
		case _h3_field_type_string:													return "string"							;
		case _h3_field_type_long_string:											return "long string"					;
		case _h3_field_type_string_id:												return "string id"						;
		case _h3_field_type_old_string_id:											return "old string id"					;
		case _h3_field_type_char_integer:											return "char integer"					;
		case _h3_field_type_short_integer:											return "short integer"					;
		case _h3_field_type_long_integer:											return "long integer"					;
		case _h3_field_type_int64_integer:											return "int64 integer"					;
		case _h3_field_type_angle:													return "angle"							;
		case _h3_field_type_tag:													return "tag"							;
		case _h3_field_type_char_enum:												return "char enum"						;
		case _h3_field_type_short_enum:												return "short enum"						;
		case _h3_field_type_long_enum:												return "long enum"						;
		case _h3_field_type_long_flags:												return "long flags"						;
		case _h3_field_type_word_flags:												return "word flags"						;
		case _h3_field_type_byte_flags:												return "byte flags"						;
		case _h3_field_type_point_2d:												return "point 2d"						;
		case _h3_field_type_rectangle_2d:											return "rectangle 2d"					;
		case _h3_field_type_rgb_color:												return "rgb color"						;
		case _h3_field_type_argb_color:												return "argb color"						;
		case _h3_field_type_real:													return "real"							;
		case _h3_field_type_real_slider:											return "real slider"					;
		case _h3_field_type_real_fraction:											return "real fraction"					;
		case _h3_field_type_real_point_2d:											return "real point 2d"					;
		case _h3_field_type_real_point_3d:											return "real point 3d"					;
		case _h3_field_type_real_vector_2d:											return "real vector 2d"					;
		case _h3_field_type_real_vector_3d:											return "real vector 3d"					;
		case _h3_field_type_real_quaternion:										return "real quaternion"				;
		case _h3_field_type_real_euler_angles_2d:									return "real euler angles 2d"			;
		case _h3_field_type_real_euler_angles_3d:									return "real euler angles 3d"			;
		case _h3_field_type_real_plane_2d:											return "real plane 2d"					;
		case _h3_field_type_real_plane_3d:											return "real plane 3d"					;
		case _h3_field_type_real_rgb_color:											return "real rgb color"					;
		case _h3_field_type_real_argb_color:										return "real argb color"				;
		case _h3_field_type_real_hsv_color:											return "real hsv color"					;
		case _h3_field_type_real_ahsv_color:										return "real ahsv color"				;
		case _h3_field_type_short_integer_bounds:									return "short integer bounds"			;
		case _h3_field_type_angle_bounds:											return "angle bounds"					;
		case _h3_field_type_real_bounds:											return "real bounds"					;
		case _h3_field_type_fraction_bounds:										return "fraction bounds"				;
		case _h3_field_type_tag_reference:											return "tag reference"					;
		case _h3_field_type_block:													return "block"							;
		case _h3_field_type_long_block_flags:										return "long block flags"				;
		case _h3_field_type_word_block_flags:										return "word block flags"				;
		case _h3_field_type_byte_block_flags:										return "byte block flags"				;
		case _h3_field_type_char_block_index:										return "char block index"				;
		case _h3_field_type_custom_char_block_index:								return "custom char block index"		;
		case _h3_field_type_short_block_index:										return "short block index"				;
		case _h3_field_type_custom_short_block_index:								return "custom short block index"		;
		case _h3_field_type_long_block_index:										return "long block index"				;
		case _h3_field_type_custom_long_block_index:								return "custom long block index"		;
		case _h3_field_type_data:													return "data"							;
		case _h3_field_type_vertex_buffer:											return "vertex buffer"					;
		case _h3_field_type_pad:													return "pad"							;
		case _h3_field_type_useless_pad:											return "useless pad"					;
		case _h3_field_type_skip:													return "skip"							;
		case _h3_field_type_explanation:											return "explanation"					;
		case _h3_field_type_custom:													return "custom"							;
		case _h3_field_type_struct:													return "struct"							;
		case _h3_field_type_array:													return "array"							;
		case _h3_field_type_pageable_resource:										return "pageable resource"				;
		case _h3_field_type_api_interop:											return "api interop"					;
		case _h3_field_type_terminator_X:											return "terminator X"					;
	}
	return nullptr;
}

const char* h3_field_type_to_generic_field_type(e_h3_field_type field_type)
{
	switch (field_type)
	{
	case _h3_field_type_string:														return "_field_string";
	case _h3_field_type_long_string:												return "_field_long_string";
	case _h3_field_type_string_id:													return "_field_string_id";
	case _h3_field_type_old_string_id:												return "_field_old_string_id";
	case _h3_field_type_char_integer:												return "_field_char_integer";
	case _h3_field_type_short_integer:												return "_field_short_integer";
	case _h3_field_type_long_integer:												return "_field_long_integer";
	case _h3_field_type_int64_integer:												return "_field_int64_integer";
	case _h3_field_type_angle:														return "_field_angle";
	case _h3_field_type_tag:														return "_field_tag";
	case _h3_field_type_char_enum:													return "_field_char_enum";
	case _h3_field_type_short_enum:													return "_field_enum";
	case _h3_field_type_long_enum:													return "_field_long_enum";
	case _h3_field_type_long_flags:													return "_field_long_flags";
	case _h3_field_type_word_flags:													return "_field_word_flags";
	case _h3_field_type_byte_flags:													return "_field_byte_flags";
	case _h3_field_type_point_2d:													return "_field_point_2d";
	case _h3_field_type_rectangle_2d:												return "_field_rectangle_2d";
	case _h3_field_type_rgb_color:													return "_field_rgb_color";
	case _h3_field_type_argb_color:													return "_field_argb_color";
	case _h3_field_type_real:														return "_field_real";
	case _h3_field_type_real_slider:												return "_field_real"; // #TODO: investigate this
	case _h3_field_type_real_fraction:												return "_field_real_fraction";
	case _h3_field_type_real_point_2d:												return "_field_real_point_2d";
	case _h3_field_type_real_point_3d:												return "_field_real_point_3d";
	case _h3_field_type_real_vector_2d:												return "_field_real_vector_2d";
	case _h3_field_type_real_vector_3d:												return "_field_real_vector_3d";
	case _h3_field_type_real_quaternion:											return "_field_real_quaternion";
	case _h3_field_type_real_euler_angles_2d:										return "_field_real_euler_angles_2d";
	case _h3_field_type_real_euler_angles_3d:										return "_field_real_euler_angles_3d";
	case _h3_field_type_real_plane_2d:												return "_field_real_plane_2d";
	case _h3_field_type_real_plane_3d:												return "_field_real_plane_3d";
	case _h3_field_type_real_rgb_color:												return "_field_real_rgb_color";
	case _h3_field_type_real_argb_color:											return "_field_real_argb_color";
	case _h3_field_type_real_hsv_color:												return "_field_real_hsv_color";
	case _h3_field_type_real_ahsv_color:											return "_field_real_ahsv_color";
	case _h3_field_type_short_integer_bounds:										return "_field_short_bounds";
	case _h3_field_type_angle_bounds:												return "_field_angle_bounds";
	case _h3_field_type_real_bounds:												return "_field_real_bounds";
	case _h3_field_type_fraction_bounds:											return "_field_real_fraction_bounds";
	case _h3_field_type_tag_reference:												return "_field_tag_reference";
	case _h3_field_type_block:														return "_field_block";
	case _h3_field_type_long_block_flags:											return "_field_long_block_flags";
	case _h3_field_type_word_block_flags:											return "_field_word_block_flags";
	case _h3_field_type_byte_block_flags:											return "_field_byte_block_flags";
	case _h3_field_type_char_block_index:											return "_field_char_block_index";
	case _h3_field_type_custom_char_block_index:									return "_field_custom_char_block_index";
	case _h3_field_type_short_block_index:											return "_field_short_block_index";
	case _h3_field_type_custom_short_block_index:									return "_field_custom_short_block_index";
	case _h3_field_type_long_block_index:											return "_field_long_block_index";
	case _h3_field_type_custom_long_block_index:									return "_field_custom_long_block_index";
	case _h3_field_type_data:														return "_field_data";
	case _h3_field_type_vertex_buffer:												return "_field_vertex_buffer";
	case _h3_field_type_useless_pad:												return "_field_useless_pad";
	case _h3_field_type_pad:														return "_field_pad";
	case _h3_field_type_skip:														return "_field_skip";
	case _h3_field_type_explanation:												return "_field_explanation";
	case _h3_field_type_custom:														return "_field_custom";
	case _h3_field_type_struct:														return "_field_struct";
	case _h3_field_type_array:														return "_field_array";
	case _h3_field_type_pageable_resource:											return "_field_pageable";
	case _h3_field_type_api_interop:												return "_field_api_interop";
	case _h3_field_type_terminator_X:												return "_field_terminator_X";
	}
	FATAL_ERROR("oh shit");
	return nullptr;
}
