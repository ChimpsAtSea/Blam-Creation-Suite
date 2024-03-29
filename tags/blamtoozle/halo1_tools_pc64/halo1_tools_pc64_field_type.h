#pragma once

enum e_halo1_tools_pc64_field : unsigned int
{
	_halo1_tools_pc64_field_string,
	_halo1_tools_pc64_field_long_string,
	_halo1_tools_pc64_field_char_integer,
	_halo1_tools_pc64_field_short_integer,
	_halo1_tools_pc64_field_long_integer,
	_halo1_tools_pc64_field_angle,
	_halo1_tools_pc64_field_tag,
	_halo1_tools_pc64_field_short_enum,
	_halo1_tools_pc64_field_long_flags,
	_halo1_tools_pc64_field_word_flags,
	_halo1_tools_pc64_field_byte_flags,
	_halo1_tools_pc64_field_point_2d,
	_halo1_tools_pc64_field_rectangle_2d,
	_halo1_tools_pc64_field_rgb_color,
	_halo1_tools_pc64_field_argb_color,
	_halo1_tools_pc64_field_real,
	_halo1_tools_pc64_field_real_fraction,
	_halo1_tools_pc64_field_real_point_2d,
	_halo1_tools_pc64_field_real_point_3d,
	_halo1_tools_pc64_field_real_vector_2d,
	_halo1_tools_pc64_field_real_vector_3d,
	_halo1_tools_pc64_field_real_quaternion,
	_halo1_tools_pc64_field_real_euler_angles_2d,
	_halo1_tools_pc64_field_real_euler_angles_3d,
	_halo1_tools_pc64_field_real_plane_2d,
	_halo1_tools_pc64_field_real_plane_3d,
	_halo1_tools_pc64_field_real_rgb_color,
	_halo1_tools_pc64_field_real_argb_color,
	_halo1_tools_pc64_field_real_hsv_color,
	_halo1_tools_pc64_field_real_ahsv_color,
	_halo1_tools_pc64_field_short_integer_bounds,
	_halo1_tools_pc64_field_angle_bounds,
	_halo1_tools_pc64_field_real_bounds,
	_halo1_tools_pc64_field_real_fraction_bounds,
	_halo1_tools_pc64_field_tag_reference,
	_halo1_tools_pc64_field_block,
	_halo1_tools_pc64_field_short_block_index,
	_halo1_tools_pc64_field_long_block_index,
	_halo1_tools_pc64_field_data,
	_halo1_tools_pc64_field_array_start,
	_halo1_tools_pc64_field_array_end,
	_halo1_tools_pc64_field_pad,
	_halo1_tools_pc64_field_skip,
	_halo1_tools_pc64_field_explanation,
	_halo1_tools_pc64_field_custom,
	_halo1_tools_pc64_field_terminator,
	k_num_halo1_tools_pc64_fields [[maybe_unused]]
};

extern blofeld::e_field halo1_tools_pc64_field_type_to_generic_field_type(e_halo1_tools_pc64_field field_type);
