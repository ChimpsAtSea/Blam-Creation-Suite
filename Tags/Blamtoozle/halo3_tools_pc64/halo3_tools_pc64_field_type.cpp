#include "blamtoozle-private-pch.h"

blofeld::e_field halo3_tools_pc64_field_type_to_generic_field_type(e_halo3_tools_pc64_field_type field_type)
{
	switch (field_type)
	{
	case _halo3_tools_pc64_field_type_string:													return blofeld::_field_string;
	case _halo3_tools_pc64_field_type_long_string:												return blofeld::_field_long_string;
	case _halo3_tools_pc64_field_type_string_id:												return blofeld::_field_string_id;
	case _halo3_tools_pc64_field_type_old_string_id:											return blofeld::_field_old_string_id;
	case _halo3_tools_pc64_field_type_char_integer:												return blofeld::_field_char_integer;
	case _halo3_tools_pc64_field_type_short_integer:											return blofeld::_field_short_integer;
	case _halo3_tools_pc64_field_type_long_integer:												return blofeld::_field_long_integer;
	case _halo3_tools_pc64_field_type_int64_integer:											return blofeld::_field_int64_integer;
	case _halo3_tools_pc64_field_type_angle:													return blofeld::_field_angle;
	case _halo3_tools_pc64_field_type_tag:														return blofeld::_field_tag;
	case _halo3_tools_pc64_field_type_char_enum:												return blofeld::_field_char_enum;
	case _halo3_tools_pc64_field_type_short_enum:												return blofeld::_field_short_enum;
	case _halo3_tools_pc64_field_type_long_enum:												return blofeld::_field_long_enum;
	case _halo3_tools_pc64_field_type_long_flags:												return blofeld::_field_long_flags;
	case _halo3_tools_pc64_field_type_word_flags:												return blofeld::_field_word_flags;
	case _halo3_tools_pc64_field_type_byte_flags:												return blofeld::_field_byte_flags;
	case _halo3_tools_pc64_field_type_point_2d:													return blofeld::_field_point_2d;
	case _halo3_tools_pc64_field_type_rectangle_2d:												return blofeld::_field_rectangle_2d;
	case _halo3_tools_pc64_field_type_rgb_color:												return blofeld::_field_rgb_color;
	case _halo3_tools_pc64_field_type_argb_color:												return blofeld::_field_argb_color;
	case _halo3_tools_pc64_field_type_real:														return blofeld::_field_real;
	case _halo3_tools_pc64_field_type_real_slider:												return blofeld::_field_real;
	case _halo3_tools_pc64_field_type_real_fraction:											return blofeld::_field_real_fraction;
	case _halo3_tools_pc64_field_type_real_point_2d:											return blofeld::_field_real_point_2d;
	case _halo3_tools_pc64_field_type_real_point_3d:											return blofeld::_field_real_point_3d;
	case _halo3_tools_pc64_field_type_real_vector_2d:											return blofeld::_field_real_vector_2d;
	case _halo3_tools_pc64_field_type_real_vector_3d:											return blofeld::_field_real_vector_3d;
	case _halo3_tools_pc64_field_type_real_quaternion:											return blofeld::_field_real_quaternion;
	case _halo3_tools_pc64_field_type_real_euler_angles_2d:										return blofeld::_field_real_euler_angles_2d;
	case _halo3_tools_pc64_field_type_real_euler_angles_3d:										return blofeld::_field_real_euler_angles_3d;
	case _halo3_tools_pc64_field_type_real_plane_2d:											return blofeld::_field_real_plane_2d;
	case _halo3_tools_pc64_field_type_real_plane_3d:											return blofeld::_field_real_plane_3d;
	case _halo3_tools_pc64_field_type_real_rgb_color:											return blofeld::_field_real_rgb_color;
	case _halo3_tools_pc64_field_type_real_argb_color:											return blofeld::_field_real_argb_color;
	case _halo3_tools_pc64_field_type_real_hsv_color:											return blofeld::_field_real_hsv_color;
	case _halo3_tools_pc64_field_type_real_ahsv_color:											return blofeld::_field_real_ahsv_color;
	case _halo3_tools_pc64_field_type_short_integer_bounds:										return blofeld::_field_short_integer_bounds;
	case _halo3_tools_pc64_field_type_angle_bounds:												return blofeld::_field_angle_bounds;
	case _halo3_tools_pc64_field_type_real_bounds:												return blofeld::_field_real_bounds;
	case _halo3_tools_pc64_field_type_fraction_bounds:											return blofeld::_field_fraction_bounds;
	case _halo3_tools_pc64_field_type_tag_reference:											return blofeld::_field_tag_reference;
	case _halo3_tools_pc64_field_type_block:													return blofeld::_field_block;
	case _halo3_tools_pc64_field_type_long_block_flags:											return blofeld::_field_long_block_flags;
	case _halo3_tools_pc64_field_type_word_block_flags:											return blofeld::_field_word_block_flags;
	case _halo3_tools_pc64_field_type_byte_block_flags:											return blofeld::_field_byte_block_flags;
	case _halo3_tools_pc64_field_type_char_block_index:											return blofeld::_field_char_block_index;
	case _halo3_tools_pc64_field_type_custom_char_block_index:									return blofeld::_field_custom_char_block_index;
	case _halo3_tools_pc64_field_type_short_block_index:										return blofeld::_field_short_block_index;
	case _halo3_tools_pc64_field_type_custom_short_block_index:									return blofeld::_field_custom_short_block_index;
	case _halo3_tools_pc64_field_type_long_block_index:											return blofeld::_field_long_block_index;
	case _halo3_tools_pc64_field_type_custom_long_block_index:									return blofeld::_field_custom_long_block_index;
	case _halo3_tools_pc64_field_type_data:														return blofeld::_field_data;
	case _halo3_tools_pc64_field_type_vertex_buffer:											return blofeld::_field_vertex_buffer;
	case _halo3_tools_pc64_field_type_useless_pad:												return blofeld::_field_useless_pad;
	case _halo3_tools_pc64_field_type_pad:														return blofeld::_field_pad;
	case _halo3_tools_pc64_field_type_skip:														return blofeld::_field_skip;
	case _halo3_tools_pc64_field_type_explanation:												return blofeld::_field_explanation;
	case _halo3_tools_pc64_field_type_custom:													return blofeld::_field_custom;
	case _halo3_tools_pc64_field_type_struct:													return blofeld::_field_struct;
	case _halo3_tools_pc64_field_type_array:													return blofeld::_field_array;
	case _halo3_tools_pc64_field_type_pageable_resource:										return blofeld::_field_pageable_resource;
	case _halo3_tools_pc64_field_type_api_interop:												return blofeld::_field_api_interop;
	case _halo3_tools_pc64_field_type_terminator:												return blofeld::_field_terminator;
	}
	FATAL_ERROR("unreachable");
}
