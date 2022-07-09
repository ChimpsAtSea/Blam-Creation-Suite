#include "blamtoozle-private-pch.h"

using namespace blofeld;

const char* blamtoozle_field_type_to_string(blofeld::e_field field_type)
{
	switch (field_type)
	{
		case _field_string:													return "string"							;
		case _field_long_string:											return "long string"					;
		case _field_string_id:												return "string id"						;
		case _field_old_string_id:											return "old string id"					;
		case _field_char_integer:											return "char integer"					;
		case _field_short_integer:											return "short integer"					;
		case _field_long_integer:											return "long integer"					;
		case _field_int64_integer:											return "int64 integer"					;
		case _field_angle:													return "angle"							;
		case _field_tag:													return "tag"							;
		case _field_char_enum:												return "char enum"						;
		case _field_short_enum:												return "short enum"						;
		case _field_long_enum:												return "long enum"						;
		case _field_long_flags:												return "long flags"						;
		case _field_word_flags:												return "word flags"						;
		case _field_byte_flags:												return "byte flags"						;
		case _field_point_2d:												return "point 2d"						;
		case _field_rectangle_2d:											return "rectangle 2d"					;
		case _field_rgb_color:												return "rgb color"						;
		case _field_argb_color:												return "argb color"						;
		case _field_real:													return "real"							;
		case _field_real_fraction:											return "real fraction"					;
		case _field_real_point_2d:											return "real point 2d"					;
		case _field_real_point_3d:											return "real point 3d"					;
		case _field_real_vector_2d:											return "real vector 2d"					;
		case _field_real_vector_3d:											return "real vector 3d"					;
		case _field_real_quaternion:										return "real quaternion"				;
		case _field_real_euler_angles_2d:									return "real euler angles 2d"			;
		case _field_real_euler_angles_3d:									return "real euler angles 3d"			;
		case _field_real_plane_2d:											return "real plane 2d"					;
		case _field_real_plane_3d:											return "real plane 3d"					;
		case _field_real_rgb_color:											return "real rgb color"					;
		case _field_real_argb_color:										return "real argb color"				;
		case _field_real_hsv_color:											return "real hsv color"					;
		case _field_real_ahsv_color:										return "real ahsv color"				;
		case _field_short_integer_bounds:									return "short integer bounds"			;
		case _field_angle_bounds:											return "angle bounds"					;
		case _field_real_bounds:											return "real bounds"					;
		case _field_real_fraction_bounds:										return "fraction bounds"				;
		case _field_tag_reference:											return "tag reference"					;
		case _field_block:													return "block"							;
		case _field_long_block_flags:										return "long block flags"				;
		case _field_word_block_flags:										return "word block flags"				;
		case _field_byte_block_flags:										return "byte block flags"				;
		case _field_char_block_index:										return "char block index"				;
		case _field_char_block_index_custom_search:								return "custom char block index"		;
		case _field_short_block_index:										return "short block index"				;
		case _field_short_block_index_custom_search:								return "custom short block index"		;
		case _field_long_block_index:										return "long block index"				;
		case _field_long_block_index_custom_search:								return "custom long block index"		;
		case _field_data:													return "data"							;
		case _field_vertex_buffer:											return "vertex buffer"					;
		case _field_pad:													return "pad"							;
		case _field_useless_pad:											return "useless pad"					;
		case _field_skip:													return "skip"							;
		case _field_explanation:											return "explanation"					;
		case _field_custom:													return "custom"							;
		case _field_struct:													return "struct"							;
		case _field_array:													return "array"							;
		case _field_pageable_resource:										return "pageable resource"				;
		case _field_api_interop:											return "api interop"					;
		case _field_terminator:												return "terminator X"					;
	}
	debug_break; // shouldn't hit this
	return nullptr;
}

const char* blamtoozle_field_type_to_generic_field_type(blofeld::e_field field_type)
{
	switch (field_type)
	{
	case _field_string:														return "_field_string";
	case _field_long_string:												return "_field_long_string";
	case _field_string_id:													return "_field_string_id";
	case _field_old_string_id:												return "_field_old_string_id";
	case _field_char_integer:												return "_field_char_integer";
	case _field_short_integer:												return "_field_short_integer";
	case _field_long_integer:												return "_field_long_integer";
	case _field_int64_integer:												return "_field_int64_integer";
	case _field_angle:														return "_field_angle";
	case _field_tag:														return "_field_tag";
	case _field_char_enum:													return "_field_char_enum";
	case _field_short_enum:													return "_field_short_enum";
	case _field_long_enum:													return "_field_long_enum";
	case _field_long_flags:													return "_field_long_flags";
	case _field_word_flags:													return "_field_word_flags";
	case _field_byte_flags:													return "_field_byte_flags";
	case _field_point_2d:													return "_field_point_2d";
	case _field_rectangle_2d:												return "_field_rectangle_2d";
	case _field_rgb_color:													return "_field_rgb_color";
	case _field_argb_color:													return "_field_argb_color";
	case _field_real:														return "_field_real";
	case _field_real_fraction:												return "_field_real_fraction";
	case _field_real_point_2d:												return "_field_real_point_2d";
	case _field_real_point_3d:												return "_field_real_point_3d";
	case _field_real_vector_2d:												return "_field_real_vector_2d";
	case _field_real_vector_3d:												return "_field_real_vector_3d";
	case _field_real_quaternion:											return "_field_real_quaternion";
	case _field_real_euler_angles_2d:										return "_field_real_euler_angles_2d";
	case _field_real_euler_angles_3d:										return "_field_real_euler_angles_3d";
	case _field_real_plane_2d:												return "_field_real_plane_2d";
	case _field_real_plane_3d:												return "_field_real_plane_3d";
	case _field_real_rgb_color:												return "_field_real_rgb_color";
	case _field_real_argb_color:											return "_field_real_argb_color";
	case _field_real_hsv_color:												return "_field_real_hsv_color";
	case _field_real_ahsv_color:											return "_field_real_ahsv_color";
	case _field_short_integer_bounds:										return "_field_short_integer_bounds";
	case _field_angle_bounds:												return "_field_angle_bounds";
	case _field_real_bounds:												return "_field_real_bounds";
	case _field_real_fraction_bounds:											return "_field_real_fraction_bounds";
	case _field_tag_reference:												return "_field_tag_reference";
	case _field_block:														return "_field_block";
	case _field_long_block_flags:											return "_field_long_block_flags";
	case _field_word_block_flags:											return "_field_word_block_flags";
	case _field_byte_block_flags:											return "_field_byte_block_flags";
	case _field_char_block_index:											return "_field_char_block_index";
	case _field_char_block_index_custom_search:									return "_field_char_block_index_custom_search";
	case _field_short_block_index:											return "_field_short_block_index";
	case _field_short_block_index_custom_search:									return "_field_short_block_index_custom_search";
	case _field_long_block_index:											return "_field_long_block_index";
	case _field_long_block_index_custom_search:									return "_field_long_block_index_custom_search";
	case _field_data:														return "_field_data";
	case _field_vertex_buffer:												return "_field_vertex_buffer";
	case _field_useless_pad:												return "_field_useless_pad";
	case _field_pad:														return "_field_pad";
	case _field_skip:														return "_field_skip";
	case _field_explanation:												return "_field_explanation";
	case _field_custom:														return "_field_custom";
	case _field_struct:														return "_field_struct";
	case _field_array:														return "_field_array";
	case _field_pageable_resource:											return "_field_pageable_resource";
	case _field_api_interop:												return "_field_api_interop";
	case _field_terminator:													return "_field_terminator";
	}
	debug_break; // shouldn't hit this
	return nullptr;
}
