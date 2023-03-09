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

	enum e_field : unsigned char
	{
		_field_string [[maybe_unused]],
		_field_long_string [[maybe_unused]],
		_field_string_id [[maybe_unused]],
		_field_old_string_id [[maybe_unused]],
		_field_char_integer [[maybe_unused]],
		_field_short_integer [[maybe_unused]],
		_field_long_integer [[maybe_unused]],
		_field_int64_integer [[maybe_unused]],
		_field_angle [[maybe_unused]],
		_field_tag [[maybe_unused]],
		_field_char_enum [[maybe_unused]],
		_field_short_enum [[maybe_unused]],
		_field_long_enum [[maybe_unused]],
		_field_long_flags [[maybe_unused]],
		_field_word_flags [[maybe_unused]],
		_field_byte_flags [[maybe_unused]],
		_field_point_2d [[maybe_unused]],
		_field_rectangle_2d [[maybe_unused]],
		_field_rgb_color [[maybe_unused]],
		_field_argb_color [[maybe_unused]],
		_field_real [[maybe_unused]],
		_field_real_slider [[maybe_unused]],
		_field_real_fraction [[maybe_unused]],
		_field_real_point_2d [[maybe_unused]],
		_field_real_point_3d [[maybe_unused]],
		_field_real_vector_2d [[maybe_unused]],
		_field_real_vector_3d [[maybe_unused]],
		_field_real_quaternion [[maybe_unused]],
		_field_real_euler_angles_2d [[maybe_unused]],
		_field_real_euler_angles_3d [[maybe_unused]],
		_field_real_plane_2d [[maybe_unused]],
		_field_real_plane_3d [[maybe_unused]],
		_field_real_rgb_color [[maybe_unused]],
		_field_real_argb_color [[maybe_unused]],
		_field_real_hsv_color [[maybe_unused]],
		_field_real_ahsv_color [[maybe_unused]],
		_field_short_integer_bounds [[maybe_unused]],
		_field_angle_bounds [[maybe_unused]],
		_field_real_bounds [[maybe_unused]],
		_field_real_fraction_bounds [[maybe_unused]],
		_field_tag_reference [[maybe_unused]],
		_field_block [[maybe_unused]],
		_field_long_block_flags [[maybe_unused]],
		_field_word_block_flags [[maybe_unused]],
		_field_byte_block_flags [[maybe_unused]],
		_field_char_block_index [[maybe_unused]],
		_field_char_block_index_custom_search [[maybe_unused]],
		_field_short_block_index [[maybe_unused]],
		_field_short_block_index_custom_search [[maybe_unused]],
		_field_long_block_index [[maybe_unused]],
		_field_long_block_index_custom_search [[maybe_unused]],
		_field_data [[maybe_unused]],
		_field_vertex_buffer [[maybe_unused]],
		_field_pad [[maybe_unused]],
		_field_useless_pad [[maybe_unused]],
		_field_skip [[maybe_unused]],
		_field_non_cache_runtime_value [[maybe_unused]],
		_field_explanation [[maybe_unused]],
		_field_custom [[maybe_unused]],
		_field_struct [[maybe_unused]],
		_field_array [[maybe_unused]],
		_field_pageable_resource [[maybe_unused]],
		_field_api_interop [[maybe_unused]],
		_field_terminator [[maybe_unused]],
		_field_byte_integer [[maybe_unused]],
		_field_word_integer [[maybe_unused]],
		_field_dword_integer [[maybe_unused]],
		_field_qword_integer [[maybe_unused]],

		// halo5/infinite
		_field_data_path [[maybe_unused]],
		_field_embedded_tag [[maybe_unused]],

		// custom types
		_field_pointer [[maybe_unused]],
		_field_half [[maybe_unused]],

		k_number_of_blofeld_field_types [[maybe_unused]],
		_field_version [[maybe_unused]]
	};
	

	BCS_SHARED uint32_t get_blofeld_field_size(e_platform_type platform_type, e_field field);
	BCS_SHARED BCS_RESULT get_blofeld_tag_file_field_size(e_field field, s_engine_platform_build engine_platform_build, uint32_t& field_size);
	BCS_SHARED BCS_RESULT field_to_tagfile_field_type(e_field field, const char*& tag_field_type);
	BCS_SHARED BCS_RESULT field_to_string(e_field field, const char*& field_string);
	BCS_SHARED BCS_RESULT tag_field_type_to_field(const char* tag_field_type, e_field& field);
	BCS_SHARED BCS_RESULT byteswap_field_data_inplace(e_field field, void* data, s_engine_platform_build engine_platform_build);

}
