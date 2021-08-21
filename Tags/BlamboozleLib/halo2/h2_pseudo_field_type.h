#pragma once

enum e_h2_pseudo_field_type : short
{
	_h2_pseudo_field_type_string,
	_h2_pseudo_field_type_long_string,
	_h2_pseudo_field_type_string_id,
	_h2_pseudo_field_type_old_string_id,
	_h2_pseudo_field_type_char_integer,
	_h2_pseudo_field_type_short_integer,
	_h2_pseudo_field_type_long_integer,
	_h2_pseudo_field_type_angle,
	_h2_pseudo_field_type_tag,
	_h2_pseudo_field_type_char_enum,
	_h2_pseudo_field_type_enum,
	_h2_pseudo_field_type_long_enum,
	_h2_pseudo_field_type_long_flags,
	_h2_pseudo_field_type_word_flags,
	_h2_pseudo_field_type_byte_flags,
	_h2_pseudo_field_type_point_2d,
	_h2_pseudo_field_type_rectangle_2d,
	_h2_pseudo_field_type_rgb_color,
	_h2_pseudo_field_type_argb_color,
	_h2_pseudo_field_type_real,
	_h2_pseudo_field_type_real_fraction,
	_h2_pseudo_field_type_real_point_2d,
	_h2_pseudo_field_type_real_point_3d,
	_h2_pseudo_field_type_real_vector_2d,
	_h2_pseudo_field_type_real_vector_3d,
	_h2_pseudo_field_type_real_quaternion,
	_h2_pseudo_field_type_real_euler_angles_2d,
	_h2_pseudo_field_type_real_euler_angles_3d,
	_h2_pseudo_field_type_real_plane_2d,
	_h2_pseudo_field_type_real_plane_3d,
	_h2_pseudo_field_type_real_rgb_color,
	_h2_pseudo_field_type_real_argb_color,
	_h2_pseudo_field_type_real_hsv_color,
	_h2_pseudo_field_type_real_ahsv_color,
	_h2_pseudo_field_type_short_bounds,
	_h2_pseudo_field_type_angle_bounds,
	_h2_pseudo_field_type_real_bounds,
	_h2_pseudo_field_type_real_fraction_bounds,
	_h2_pseudo_field_type_tag_reference,
	_h2_pseudo_field_type_block,
	_h2_pseudo_field_type_long_block_flags,
	_h2_pseudo_field_type_word_block_flags,
	_h2_pseudo_field_type_byte_block_flags,
	_h2_pseudo_field_type_char_block_index,
	_h2_pseudo_field_type_custom_char_block_index,
	_h2_pseudo_field_type_custom_short_block_index,
	_h2_pseudo_field_type_custom_long_block_index,
	_h2_pseudo_field_type_short_block_index,
	_h2_pseudo_field_type_long_block_index,
	_h2_pseudo_field_type_data,
	_h2_pseudo_field_type_array,
	_h2_pseudo_field_type_pad,
	_h2_pseudo_field_type_useless_pad,
	_h2_pseudo_field_type_skip,
	_h2_pseudo_field_type_explanation,
	_h2_pseudo_field_type_custom,
	_h2_pseudo_field_type_vertex_buffer,
	_h2_pseudo_field_type_struct,
	_h2_pseudo_field_type_terminator,
};

extern e_h2_pseudo_field_type h2_field_type_to_h2_pseudo_field_type(e_h2_field_type field_type);
extern const char* h2_pseudo_field_type_to_generic_field_type(e_h2_pseudo_field_type field_type);
