#pragma once

#pragma warning( push )
#pragma warning( disable : 4312 ) // warning C4312: 'type cast': conversion from 'A' to 'void *' of greater size


namespace blofeld
{
	struct s_tag_group;

	s_tag_group* get_tag_group_by_group_tag(uint32_t group_tag);

	constexpr unsigned long INVALID_TAG = 0xFFFFFFFF;

	struct s_tag_block;

	enum e_field
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

	struct s_tag_field
	{
		e_field const field_type;
		const char* const name;
		union
		{
			void* const value1;
			s_tag_block* tag_block;
		};
		void* const value2;
		//enum e_build const min_version;
		//enum e_build const max_version;

		template<typename A, typename B>
		s_tag_field(
			e_field field_type,
			const char* const name,
			A&& value1,
			B&& value2/*,
			e_build min_version = 0,
			e_build max_version = 0*/) :
			field_type(field_type),
			name(name),
			value1((void*)(value1)),
			value2((void*)(value1))/*,
			min_version(min_version),
			max_version(max_version)*/
		{

		}

		template<typename A>
		s_tag_field(
			e_field field_type,
			const char* const name,
			A&& value1/*,
			e_build min_version = (e_build)0,
			e_build max_version = (e_build)0*/) :
			field_type(field_type),
			name(name),
			value1((void*)(value1)),
			value2(nullptr)/*,
			min_version(min_version),
			max_version(max_version)*/
		{

		}

		s_tag_field(
			e_field field_type,
			const char* const name/*,
			e_build min_version = (e_build)0,
			e_build max_version = (e_build)0*/) :
			field_type(field_type),
			name(name),
			value1(nullptr),
			value2(nullptr)/*,
			min_version(min_version),
			max_version(max_version)*/
		{

		}

		s_tag_field(
			e_field field_type/*,
			e_build min_version = (e_build)0,
			e_build max_version = (e_build)0*/) :
			field_type(field_type),
			name(nullptr),
			value1(nullptr),
			value2(nullptr)/*,
			min_version(min_version),
			max_version(max_version)*/
		{

		}
	};

	struct s_tag_field_set
	{
		const char* const name;
		const char* const display_name;
		GUID const guid;
		s_tag_field* const tag_fields;
	};

	struct s_tag_block
	{
		const char* name;
		const char* display_name;
		unsigned long max_count;
		const char* max_count_string;
		s_tag_field_set* field_set;

	};

	struct s_tag_group
	{
		const char* const name;
		unsigned long const group_tag;
		unsigned long const parent_group_tag;
		s_tag_block* const block;
		s_tag_group* parent_tag_group;
	};

	struct  s_tag_reference
	{
		unsigned long const flags;
		unsigned long const group_tag;
		const unsigned long* const group_tags;
	};

#pragma warning( pop )


}