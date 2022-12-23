#include "blamtoozle-private-pch.h"

blofeld::e_field halo2_tools_pc64_field_type_to_generic_field_type(e_halo2_tools_pc64_field field_type)
{
	switch (field_type)
	{
		case _halo2_tools_pc64_field_string:											return blofeld::_field_string;
		case _halo2_tools_pc64_field_long_string: 										return blofeld::_field_long_string;
		case _halo2_tools_pc64_field_string_id: 										return blofeld::_field_string_id;
		case _halo2_tools_pc64_field_old_string_id: 									return blofeld::_field_old_string_id;
		case _halo2_tools_pc64_field_char_integer: 									return blofeld::_field_char_integer;
		case _halo2_tools_pc64_field_short_integer: 									return blofeld::_field_short_integer;
		case _halo2_tools_pc64_field_long_integer: 									return blofeld::_field_long_integer;
		case _halo2_tools_pc64_field_angle: 											return blofeld::_field_angle;
		case _halo2_tools_pc64_field_tag: 												return blofeld::_field_tag;
		case _halo2_tools_pc64_field_char_enum: 										return blofeld::_field_char_enum;
		case _halo2_tools_pc64_field_short_enum: 										return blofeld::_field_short_enum;
		case _halo2_tools_pc64_field_long_enum: 										return blofeld::_field_long_enum;
		case _halo2_tools_pc64_field_long_flags: 										return blofeld::_field_long_flags;
		case _halo2_tools_pc64_field_word_flags: 										return blofeld::_field_word_flags;
		case _halo2_tools_pc64_field_byte_flags: 										return blofeld::_field_byte_flags;
		case _halo2_tools_pc64_field_point_2d: 										return blofeld::_field_point_2d;
		case _halo2_tools_pc64_field_rectangle_2d: 									return blofeld::_field_rectangle_2d;
		case _halo2_tools_pc64_field_rgb_color: 										return blofeld::_field_rgb_color;
		case _halo2_tools_pc64_field_argb_color: 										return blofeld::_field_argb_color;
		case _halo2_tools_pc64_field_real: 											return blofeld::_field_real;
		case _halo2_tools_pc64_field_real_fraction: 									return blofeld::_field_real_fraction;
		case _halo2_tools_pc64_field_real_point_2d: 									return blofeld::_field_real_point_2d;
		case _halo2_tools_pc64_field_real_point_3d: 									return blofeld::_field_real_point_3d;
		case _halo2_tools_pc64_field_real_vector_2d: 									return blofeld::_field_real_vector_2d;
		case _halo2_tools_pc64_field_real_vector_3d: 									return blofeld::_field_real_vector_3d;
		case _halo2_tools_pc64_field_real_quaternion: 									return blofeld::_field_real_quaternion;
		case _halo2_tools_pc64_field_real_euler_angles_2d: 							return blofeld::_field_real_euler_angles_2d;
		case _halo2_tools_pc64_field_real_euler_angles_3d: 							return blofeld::_field_real_euler_angles_3d;
		case _halo2_tools_pc64_field_real_plane_2d: 									return blofeld::_field_real_plane_2d;
		case _halo2_tools_pc64_field_real_plane_3d: 									return blofeld::_field_real_plane_3d;
		case _halo2_tools_pc64_field_real_rgb_color: 									return blofeld::_field_real_rgb_color;
		case _halo2_tools_pc64_field_real_argb_color: 									return blofeld::_field_real_argb_color;
		case _halo2_tools_pc64_field_real_hsv_color: 									return blofeld::_field_real_hsv_color;
		case _halo2_tools_pc64_field_real_ahsv_color: 									return blofeld::_field_real_ahsv_color;
		case _halo2_tools_pc64_field_short_integer_bounds: 							return blofeld::_field_short_integer_bounds;
		case _halo2_tools_pc64_field_angle_bounds: 									return blofeld::_field_angle_bounds;
		case _halo2_tools_pc64_field_real_bounds: 										return blofeld::_field_real_bounds;
		case _halo2_tools_pc64_field_real_fraction_bounds: 							return blofeld::_field_real_fraction_bounds;
		case _halo2_tools_pc64_field_tag_reference: 									return blofeld::_field_tag_reference;
		case _halo2_tools_pc64_field_block: 											return blofeld::_field_block;
		case _halo2_tools_pc64_field_long_block_flags: 								return blofeld::_field_long_block_flags;
		case _halo2_tools_pc64_field_word_block_flags: 								return blofeld::_field_word_block_flags;
		case _halo2_tools_pc64_field_byte_block_flags: 								return blofeld::_field_byte_block_flags;
		case _halo2_tools_pc64_field_char_block_index: 								return blofeld::_field_char_block_index;
		case _halo2_tools_pc64_field_char_block_index_custom_search: 							return blofeld::_field_char_block_index_custom_search;
		case _halo2_tools_pc64_field_short_block_index: 								return blofeld::_field_short_block_index;
		case _halo2_tools_pc64_field_short_block_index_custom_search: 						return blofeld::_field_short_block_index_custom_search;
		case _halo2_tools_pc64_field_long_block_index: 								return blofeld::_field_long_block_index;
		case _halo2_tools_pc64_field_long_block_index_custom_search: 							return blofeld::_field_long_block_index_custom_search;
		case _halo2_tools_pc64_field_data: 											return blofeld::_field_data;
		case _halo2_tools_pc64_field_vertex_buffer: 									return blofeld::_field_vertex_buffer;
		case _halo2_tools_pc64_field_array_start: 										return blofeld::_field_array;
		case _halo2_tools_pc64_field_array_end: 										return blofeld::_field_terminator;
		case _halo2_tools_pc64_field_pad: 												return blofeld::_field_pad;
		case _halo2_tools_pc64_field_useless_pad: 										return blofeld::_field_useless_pad;
		case _halo2_tools_pc64_field_skip: 											return blofeld::_field_skip;
		case _halo2_tools_pc64_field_explanation: 										return blofeld::_field_explanation;
		case _halo2_tools_pc64_field_custom: 											return blofeld::_field_custom;
		case _halo2_tools_pc64_field_struct: 											return blofeld::_field_struct;
		case _halo2_tools_pc64_field_pointer: 											return blofeld::_field_pointer;
		case _halo2_tools_pc64_field_terminator: 										return blofeld::_field_terminator;
	}
	FATAL_ERROR("unreachable");
}
