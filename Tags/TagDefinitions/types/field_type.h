#pragma once

namespace blofeld
{
	struct s_tag_field;

	enum e_field_flags
	{

	};

	enum e_field_legacy : unsigned long
	{
		_field_legacy
	};

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

		// halo5/infinite
		_field_data_path,
		_field_embedded_tag,

		// custom types
		_field_pointer,
		_field_half,

		k_number_of_blofeld_field_types,
		_field_version
	};
	

	BCS_DEBUG_API unsigned long get_blofeld_field_size(e_platform_type platform_type, e_field field);
	BCS_DEBUG_API unsigned long get_blofeld_field_size(const s_tag_field& field, s_engine_platform_build engine_platform_build);
	BCS_DEBUG_API BCS_RESULT field_to_tag_field_type(e_field field, const char*& tag_field_type);
	BCS_DEBUG_API BCS_RESULT tag_field_type_to_field(const char* tag_field_type, e_field& field);
	BCS_DEBUG_API BCS_RESULT byteswap_field_data_inplace(e_field field, void* data, s_engine_platform_build engine_platform_build);
}
