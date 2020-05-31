#pragma once

namespace blofeld
{
	enum e_field : unsigned long
	{
		_field_string,
		_field_long_string,
		_field_string_id,
		_field_old_string_id,
		_field_char_integer,
		_field_short_integer,
		_field_long_integer,
		_field_int64_integer,
		_field_angle,
		_field_tag,
		_field_char_enum,
		_field_enum,
		_field_long_enum,
		_field_long_flags,
		_field_word_flags,
		_field_byte_flags,
		_field_point_2d,
		_field_rectangle_2d,
		_field_rgb_color,
		_field_argb_color,
		_field_real,
		_field_real_fraction,
		_field_real_point_2d,
		_field_real_point_3d,
		_field_real_vector_2d,
		_field_real_vector_3d,
		_field_real_quaternion,
		_field_real_euler_angles_2d,
		_field_real_euler_angles_3d,
		_field_real_plane_2d,
		_field_real_plane_3d,
		_field_real_rgb_color,
		_field_real_argb_color,
		_field_real_hsv_color,
		_field_real_ahsv_color,
		_field_short_bounds,
		_field_angle_bounds,
		_field_real_bounds,
		_field_real_fraction_bounds,
		_field_tag_reference,
		_field_block,
		_field_long_block_flags,
		_field_word_block_flags,
		_field_byte_block_flags,
		_field_char_block_index,
		_field_custom_char_block_index,
		_field_short_block_index,
		_field_custom_short_block_index,
		_field_long_block_index,
		_field_custom_long_block_index,
		_field_data,
		_field_vertex_buffer,
		_field_pad,
		_field_useless_pad,
		_field_skip,
		_field_non_cache_runtime_value,
		_field_explanation,
		_field_custom,
		_field_struct,
		_field_array,
		_field_pageable,
		_field_api_interop,
		_field_terminator,
		_field_byte_integer,
		_field_word_integer,
		_field_dword_integer,
		_field_qword_integer,
	};

	inline uint32_t get_blofeld_field_size(blofeld::e_field field)
	{
		switch (field)
		{
		case blofeld::_field_string:							return sizeof(::c_static_string<32>);
		case blofeld::_field_long_string:						return sizeof(::c_static_string<256>);
		case blofeld::_field_string_id:							return sizeof(string_id);
		case blofeld::_field_old_string_id:						return sizeof(::c_old_string_id);
		case blofeld::_field_char_integer:						return sizeof(char);
		case blofeld::_field_short_integer:						return sizeof(short);
		case blofeld::_field_long_integer:						return sizeof(long);
		case blofeld::_field_int64_integer:						return sizeof(long long);
		case blofeld::_field_angle:								return sizeof(angle);
		case blofeld::_field_tag:								return sizeof(tag);
		case blofeld::_field_char_enum:							return sizeof(char);
		case blofeld::_field_enum:								return sizeof(short);
		case blofeld::_field_long_enum:							return sizeof(long);
		case blofeld::_field_long_flags:						return sizeof(long);
		case blofeld::_field_word_flags:						return sizeof(word);
		case blofeld::_field_byte_flags:						return sizeof(byte);
		case blofeld::_field_point_2d:							return sizeof(::s_point2d);
		case blofeld::_field_rectangle_2d:						return sizeof(::s_rectangle2d);
		case blofeld::_field_rgb_color:							return sizeof(::pixel32);
		case blofeld::_field_argb_color:						return sizeof(::pixel32);
		case blofeld::_field_real:								return sizeof(::real);
		case blofeld::_field_real_fraction:						return sizeof(::real_fraction);
		case blofeld::_field_real_point_2d:						return sizeof(::real_point2d);
		case blofeld::_field_real_point_3d:						return sizeof(::real_point3d);
		case blofeld::_field_real_vector_2d:					return sizeof(::real_vector2d);
		case blofeld::_field_real_vector_3d:					return sizeof(::real_vector3d);
		case blofeld::_field_real_quaternion:					return sizeof(::real_quaternion);
		case blofeld::_field_real_euler_angles_2d:				return sizeof(::real_euler_angles2d);
		case blofeld::_field_real_euler_angles_3d:				return sizeof(::real_euler_angles3d);
		case blofeld::_field_real_plane_2d:						return sizeof(::real_plane2d);
		case blofeld::_field_real_plane_3d:						return sizeof(::real_plane3d);
		case blofeld::_field_real_rgb_color:					return sizeof(::rgb_color);
		case blofeld::_field_real_argb_color:					return sizeof(::argb_color);
		case blofeld::_field_real_hsv_color:					return sizeof(::real_hsv_color);
		case blofeld::_field_real_ahsv_color:					return sizeof(::real_ahsv_color);
		case blofeld::_field_short_bounds:						return sizeof(::short_bounds);
		case blofeld::_field_angle_bounds:						return sizeof(::angle_bounds);
		case blofeld::_field_real_bounds:						return sizeof(::real_bounds);
		case blofeld::_field_real_fraction_bounds:				return sizeof(::real_bounds);
		case blofeld::_field_tag_reference:						return sizeof(::s_tag_reference);
		case blofeld::_field_block:								return sizeof(::s_tag_block);
		case blofeld::_field_long_block_flags:					return sizeof(long);
		case blofeld::_field_word_block_flags:					return sizeof(word);
		case blofeld::_field_byte_block_flags:					return sizeof(byte);
		case blofeld::_field_char_block_index:					return sizeof(char);
		case blofeld::_field_custom_char_block_index:			return sizeof(char);
		case blofeld::_field_short_block_index:					return sizeof(short);
		case blofeld::_field_custom_short_block_index:			return sizeof(short);
		case blofeld::_field_long_block_index:					return sizeof(long);
		case blofeld::_field_custom_long_block_index:			return sizeof(long);
		case blofeld::_field_data:								return sizeof(::s_tag_data);
		case blofeld::_field_vertex_buffer:						return sizeof(::s_tag_d3d_vertex_buffer);
		case blofeld::_field_pad:								return 0;	// dynamic
		case blofeld::_field_useless_pad:						return 0;	// dynamic
		case blofeld::_field_skip:								return 0;	// dynamic
		case blofeld::_field_non_cache_runtime_value:			return sizeof(long);
		case blofeld::_field_explanation:						return 0;	// empty
		case blofeld::_field_custom:							return 0;	// empty
		case blofeld::_field_struct:							return 0;	// dynamic
		case blofeld::_field_array:								return 0;	// dynamic
		case blofeld::_field_pageable:							return sizeof(::s_tag_resource);
		case blofeld::_field_api_interop:						return sizeof(::s_tag_interop);
		case blofeld::_field_terminator:						return 0;	// empty
		case blofeld::_field_byte_integer:						return sizeof(byte);
		case blofeld::_field_word_integer:						return sizeof(word);
		case blofeld::_field_dword_integer:						return sizeof(dword);
		case blofeld::_field_qword_integer:						return sizeof(qword);
		default: FATAL_ERROR(L"unknown field type");
		}
	}

	inline const char* field_to_string(e_field field)
	{
		switch (field)
		{
		case _field_string:									return "_field_string";
		case _field_long_string:							return "_field_long_string";
		case _field_string_id:								return "_field_string_id";
		case _field_old_string_id:							return "_field_old_string_id";
		case _field_char_integer:							return "_field_char_integer";
		case _field_short_integer:							return "_field_short_integer";
		case _field_long_integer:							return "_field_long_integer";
		case _field_int64_integer:							return "_field_int64_integer";
		case _field_angle:									return "_field_angle";
		case _field_tag:									return "_field_tag";
		case _field_char_enum:								return "_field_char_enum";
		case _field_enum:									return "_field_enum";
		case _field_long_enum:								return "_field_long_enum";
		case _field_long_flags:								return "_field_long_flags";
		case _field_word_flags:								return "_field_word_flags";
		case _field_byte_flags:								return "_field_byte_flags";
		case _field_point_2d:								return "_field_point_2d";
		case _field_rectangle_2d:							return "_field_rectangle_2d";
		case _field_rgb_color:								return "_field_rgb_color";
		case _field_argb_color:								return "_field_argb_color";
		case _field_real:									return "_field_real";
		case _field_real_fraction:							return "_field_real_fraction";
		case _field_real_point_2d:							return "_field_real_point_2d";
		case _field_real_point_3d:							return "_field_real_point_3d";
		case _field_real_vector_2d:							return "_field_real_vector_2d";
		case _field_real_vector_3d:							return "_field_real_vector_3d";
		case _field_real_quaternion:						return "_field_real_quaternion";
		case _field_real_euler_angles_2d:					return "_field_real_euler_angles_2d";
		case _field_real_euler_angles_3d:					return "_field_real_euler_angles_3d";
		case _field_real_plane_2d:							return "_field_real_plane_2d";
		case _field_real_plane_3d:							return "_field_real_plane_3d";
		case _field_real_rgb_color:							return "_field_real_rgb_color";
		case _field_real_argb_color:						return "_field_real_argb_color";
		case _field_real_hsv_color:							return "_field_real_hsv_color";
		case _field_real_ahsv_color:						return "_field_real_ahsv_color";
		case _field_short_bounds:							return "_field_short_bounds";
		case _field_angle_bounds:							return "_field_angle_bounds";
		case _field_real_bounds:							return "_field_real_bounds";
		case _field_real_fraction_bounds:					return "_field_real_fraction_bounds";
		case _field_tag_reference:							return "_field_tag_reference";
		case _field_block:									return "_field_block";
		case _field_long_block_flags:						return "_field_long_block_flags";
		case _field_word_block_flags:						return "_field_word_block_flags";
		case _field_byte_block_flags:						return "_field_byte_block_flags";
		case _field_char_block_index:						return "_field_char_block_index";
		case _field_custom_char_block_index:				return "_field_custom_char_block_index";
		case _field_short_block_index:						return "_field_short_block_index";
		case _field_custom_short_block_index:				return "_field_custom_short_block_index";
		case _field_long_block_index:						return "_field_long_block_index";
		case _field_custom_long_block_index:				return "_field_custom_long_block_index";
		case _field_data:									return "_field_data";
		case _field_vertex_buffer:							return "_field_vertex_buffer";
		case _field_pad:									return "_field_pad";
		case _field_useless_pad:							return "_field_useless_pad";
		case _field_skip:									return "_field_skip";
		case _field_non_cache_runtime_value:				return "_field_non_cache_runtime_value";
		case _field_explanation:							return "_field_explanation";
		case _field_custom:									return "_field_custom";
		case _field_struct:									return "_field_struct";
		case _field_array:									return "_field_array";
		case _field_pageable:								return "_field_pageable";
		case _field_api_interop:							return "_field_api_interop";
		case _field_terminator:								return "_field_terminator";
		case _field_byte_integer:							return "_field_byte_integer";
		case _field_word_integer:							return "_field_word_integer";
		case _field_dword_integer:							return "_field_dword_integer";
		case _field_qword_integer:							return "_field_qword_integer";
		}
		return nullptr;
	}
}
