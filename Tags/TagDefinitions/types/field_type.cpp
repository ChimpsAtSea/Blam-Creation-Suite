#include "tagdefinitions-private-pch.h"

#include "field_type.inl"

using namespace blofeld;

uint32_t blofeld::get_blofeld_field_size(e_platform_type platform_type, e_field field)
{
	switch (field)
	{
	case _field_string:							return sizeof(::c_static_string<32>);
	case _field_long_string:					return sizeof(::c_static_string<256>);
	case _field_string_id:						return sizeof(string_id);
	case _field_old_string_id:					return sizeof(::c_old_string_id);
	case _field_char_integer:					return sizeof(char);
	case _field_short_integer:					return sizeof(short);
	case _field_long_integer:					return sizeof(long);
	case _field_int64_integer:					return sizeof(int64_t);
	case _field_angle:							return sizeof(angle);
	case _field_tag:							return sizeof(tag);
	case _field_char_enum:						return sizeof(char);
	case _field_short_enum:							return sizeof(short);
	case _field_long_enum:						return sizeof(long);
	case _field_long_flags:						return sizeof(long);
	case _field_word_flags:						return sizeof(word);
	case _field_byte_flags:						return sizeof(byte);
	case _field_point_2d:						return sizeof(::s_point2d);
	case _field_rectangle_2d:					return sizeof(::s_rectangle2d);
	case _field_rgb_color:						return sizeof(::pixel32);
	case _field_argb_color:						return sizeof(::pixel32);
	case _field_real:							return sizeof(::real);
	case _field_real_fraction:					return sizeof(::real_fraction);
	case _field_real_point_2d:					return sizeof(::real_point2d);
	case _field_real_point_3d:					return sizeof(::real_point3d);
	case _field_real_vector_2d:					return sizeof(::real_vector2d);
	case _field_real_vector_3d:					return sizeof(::real_vector3d);
	case _field_real_quaternion:				return sizeof(::real_quaternion);
	case _field_real_euler_angles_2d:			return sizeof(::real_euler_angles2d);
	case _field_real_euler_angles_3d:			return sizeof(::real_euler_angles3d);
	case _field_real_plane_2d:					return sizeof(::real_plane2d);
	case _field_real_plane_3d:					return sizeof(::real_plane3d);
	case _field_real_rgb_color:					return sizeof(::rgb_color);
	case _field_real_argb_color:				return sizeof(::argb_color);
	case _field_real_hsv_color:					return sizeof(::real_hsv_color);
	case _field_real_ahsv_color:				return sizeof(::real_ahsv_color);
	case _field_short_integer_bounds:					return sizeof(::short_bounds);
	case _field_angle_bounds:					return sizeof(::angle_bounds);
	case _field_real_bounds:					return sizeof(::real_bounds);
	case _field_real_fraction_bounds:			return sizeof(::real_fraction_bounds);
	case _field_tag_reference:					return sizeof(::s_tag_reference);
	case _field_block:							return sizeof(::s_tag_block);
	case _field_long_block_flags:				return sizeof(long);
	case _field_word_block_flags:				return sizeof(word);
	case _field_byte_block_flags:				return sizeof(byte);
	case _field_char_block_index:				return sizeof(char);
	case _field_char_block_index_custom_search:		return sizeof(char);
	case _field_short_block_index:				return sizeof(short);
	case _field_short_block_index_custom_search:		return sizeof(short);
	case _field_long_block_index:				return sizeof(long);
	case _field_long_block_index_custom_search:		return sizeof(long);
	case _field_data:							return sizeof(::s_tag_data);
	case _field_vertex_buffer:					return sizeof(::s_tag_d3d_vertex_buffer);
	case _field_pad:							return 0;	// dynamic
	case _field_useless_pad:					return 0;	// dynamic
	case _field_skip:							return 0;	// dynamic
	case _field_non_cache_runtime_value:		return 0;	// empty
	case _field_explanation:					return 0;	// empty
	case _field_custom:							return 0;	// empty
	case _field_struct:							return 0;	// dynamic
	case _field_array:							return 0;	// dynamic
	case _field_pageable_resource:						return sizeof(::s_tag_resource);
	case _field_api_interop:					return sizeof(::s_tag_interop);
	case _field_terminator:						return 0;	// empty
	case _field_byte_integer:					return sizeof(byte);
	case _field_word_integer:					return sizeof(word);
	case _field_dword_integer:					return sizeof(dword);
	case _field_qword_integer:					return sizeof(qword);
	case _field_embedded_tag:					return sizeof(::s_tag_reference);
	case _field_data_path:						return sizeof(::c_static_string<256>);
	case _field_pointer:
	{
		uint32_t pointer_size;
		ASSERT(BCS_SUCCEEDED(get_platform_pointer_size(platform_type, &pointer_size)));
		return pointer_size;
	};
	case _field_half:							return sizeof(uint16_t);
	default: FATAL_ERROR("unknown field type");
	}
	return 0;
}

#include <TagFieldTypeLookupTable\blofeld_field_type_accelerator.h>
#include <TagFieldTypeLookupTable\blofeld_field_type_accelerator.inl>

c_blofeld_field_type_accelerator blofeld_field_type_accelerator;

BCS_RESULT blofeld::tag_field_type_to_field(const char* tag_field_type, e_field& field)
{
	return blofeld_field_type_accelerator.get_value(tag_field_type, field);
}

BCS_RESULT blofeld::byteswap_field_data_inplace(e_field field, void* data, s_engine_platform_build engine_platform_build)
{
#define FIELD_BYTESWAP(_field, _field_typename) if(_field == field) { byteswap_inplace(*static_cast<_field_typename*>(data)); return BCS_S_OK; }
#define FIELD_BYTESWAP_NO_CHANGE(_field) if(_field == field) { return BCS_S_NO_CHANGES_MADE; }

	FIELD_BYTESWAP_NO_CHANGE(_field_string);
	FIELD_BYTESWAP_NO_CHANGE(_field_long_string);
	FIELD_BYTESWAP(_field_string_id, string_id);
	FIELD_BYTESWAP(_field_old_string_id, ::c_old_string_id);
	FIELD_BYTESWAP(_field_char_integer, char);
	FIELD_BYTESWAP(_field_short_integer, short);
	FIELD_BYTESWAP(_field_long_integer, long);
	FIELD_BYTESWAP(_field_int64_integer, int64_t);
	FIELD_BYTESWAP(_field_angle, angle);
	FIELD_BYTESWAP(_field_tag, tag);
	FIELD_BYTESWAP(_field_char_enum, char);
	FIELD_BYTESWAP(_field_short_enum, short);
	FIELD_BYTESWAP(_field_long_enum, long);
	FIELD_BYTESWAP(_field_long_flags, long);
	FIELD_BYTESWAP(_field_word_flags, word);
	FIELD_BYTESWAP(_field_byte_flags, byte);
	FIELD_BYTESWAP(_field_point_2d, ::s_point2d);
	FIELD_BYTESWAP(_field_rectangle_2d, ::s_rectangle2d);
	FIELD_BYTESWAP(_field_rgb_color, ::pixel32);
	FIELD_BYTESWAP(_field_argb_color, ::pixel32);
	FIELD_BYTESWAP(_field_real, ::real);
	FIELD_BYTESWAP(_field_real_fraction, ::real_fraction);
	FIELD_BYTESWAP(_field_real_point_2d, ::real_point2d);
	FIELD_BYTESWAP(_field_real_point_3d, ::real_point3d);
	FIELD_BYTESWAP(_field_real_vector_2d, ::real_vector2d);
	FIELD_BYTESWAP(_field_real_vector_3d, ::real_vector3d);
	FIELD_BYTESWAP(_field_real_quaternion, ::real_quaternion);
	FIELD_BYTESWAP(_field_real_euler_angles_2d, ::real_euler_angles2d);
	FIELD_BYTESWAP(_field_real_euler_angles_3d, ::real_euler_angles3d);
	FIELD_BYTESWAP(_field_real_plane_2d, ::real_plane2d);
	FIELD_BYTESWAP(_field_real_plane_3d, ::real_plane3d);
	FIELD_BYTESWAP(_field_real_rgb_color, ::rgb_color);
	FIELD_BYTESWAP(_field_real_argb_color, ::argb_color);
	FIELD_BYTESWAP(_field_real_hsv_color, ::real_hsv_color);
	FIELD_BYTESWAP(_field_real_ahsv_color, ::real_ahsv_color);
	FIELD_BYTESWAP(_field_short_integer_bounds, ::short_bounds);
	FIELD_BYTESWAP(_field_angle_bounds, ::angle_bounds);
	FIELD_BYTESWAP(_field_real_bounds, ::real_bounds);
	FIELD_BYTESWAP(_field_real_fraction_bounds, ::real_fraction_bounds);
	FIELD_BYTESWAP(_field_tag_reference, ::s_tag_reference);
	FIELD_BYTESWAP(_field_block, ::s_tag_block);
	FIELD_BYTESWAP(_field_long_block_flags, long);
	FIELD_BYTESWAP(_field_word_block_flags, word);
	FIELD_BYTESWAP(_field_byte_block_flags, byte);
	FIELD_BYTESWAP(_field_char_block_index, char);
	FIELD_BYTESWAP(_field_char_block_index_custom_search, char);
	FIELD_BYTESWAP(_field_short_block_index, short);
	FIELD_BYTESWAP(_field_short_block_index_custom_search, short);
	FIELD_BYTESWAP(_field_long_block_index, long);
	FIELD_BYTESWAP(_field_long_block_index_custom_search, long);
	FIELD_BYTESWAP(_field_data, ::s_tag_data);
	FIELD_BYTESWAP(_field_vertex_buffer, ::s_tag_d3d_vertex_buffer);
	FIELD_BYTESWAP_NO_CHANGE(_field_pad);
	FIELD_BYTESWAP_NO_CHANGE(_field_useless_pad);
	FIELD_BYTESWAP_NO_CHANGE(_field_skip);
	FIELD_BYTESWAP_NO_CHANGE(_field_non_cache_runtime_value);
	FIELD_BYTESWAP_NO_CHANGE(_field_explanation);
	FIELD_BYTESWAP_NO_CHANGE(_field_custom);
	FIELD_BYTESWAP_NO_CHANGE(_field_struct);
	FIELD_BYTESWAP_NO_CHANGE(_field_array);
	FIELD_BYTESWAP(_field_pageable_resource, ::s_tag_resource);
	FIELD_BYTESWAP(_field_api_interop, ::s_tag_interop);
	FIELD_BYTESWAP_NO_CHANGE(_field_terminator);
	FIELD_BYTESWAP(_field_byte_integer, byte);
	FIELD_BYTESWAP(_field_word_integer, word);
	FIELD_BYTESWAP(_field_dword_integer, dword);
	FIELD_BYTESWAP(_field_qword_integer, qword);
	FIELD_BYTESWAP(_field_embedded_tag, ::s_tag_reference);
	FIELD_BYTESWAP_NO_CHANGE(_field_data_path);

	if (field == _field_pointer)
	{
		uint32_t pointer_size;
		ASSERT(BCS_SUCCEEDED(get_platform_pointer_size(engine_platform_build.platform_type, &pointer_size)));
		if (pointer_size == 4)
		{
			byteswap_inplace(*static_cast<uint32_t*>(data));
		}
		else if (pointer_size == 8)
		{
			byteswap_inplace(*static_cast<uint64_t*>(data));
		}
		else return BCS_S_NO_CHANGES_MADE;
	};
	FIELD_BYTESWAP(_field_half, word);

#undef FIELD_BYTESWAP
#undef FIELD_BYTESWAP_NO_CHANGE
	return BCS_E_FAIL;
}

BCS_RESULT blofeld::get_blofeld_tag_file_field_size(e_field field, s_engine_platform_build engine_platform_build, uint32_t& field_size)
{
#define FIELD_TO_TAG_FILE_FIELD_SIZE(_field, size) if(_field == field) { field_size = (size); return BCS_S_OK; }

	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_string, sizeof(::c_static_string<32>));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_long_string, sizeof(::c_static_string<256>));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_string_id, sizeof(string_id));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_old_string_id, sizeof(::c_old_string_id));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_char_integer, sizeof(char));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_short_integer, sizeof(short));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_long_integer, sizeof(long));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_int64_integer, sizeof(int64_t));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_angle, sizeof(angle));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_tag, sizeof(tag));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_char_enum, sizeof(char));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_short_enum, sizeof(short));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_long_enum, sizeof(long));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_long_flags, sizeof(long));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_word_flags, sizeof(word));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_byte_flags, sizeof(byte));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_point_2d, sizeof(::s_point2d));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_rectangle_2d, sizeof(::s_rectangle2d));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_rgb_color, sizeof(::pixel32));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_argb_color, sizeof(::pixel32));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_real, sizeof(::real));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_real_fraction, sizeof(::real_fraction));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_real_point_2d, sizeof(::real_point2d));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_real_point_3d, sizeof(::real_point3d));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_real_vector_2d, sizeof(::real_vector2d));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_real_vector_3d, sizeof(::real_vector3d));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_real_quaternion, sizeof(::real_quaternion));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_real_euler_angles_2d, sizeof(::real_euler_angles2d));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_real_euler_angles_3d, sizeof(::real_euler_angles3d));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_real_plane_2d, sizeof(::real_plane2d));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_real_plane_3d, sizeof(::real_plane3d));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_real_rgb_color, sizeof(::rgb_color));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_real_argb_color, sizeof(::argb_color));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_real_hsv_color, sizeof(::real_hsv_color));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_real_ahsv_color, sizeof(::real_ahsv_color));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_short_integer_bounds, sizeof(::short_bounds));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_angle_bounds, sizeof(::angle_bounds));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_real_bounds, sizeof(::real_bounds));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_real_fraction_bounds, sizeof(::real_fraction_bounds));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_tag_reference, sizeof(::s_tag_reference));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_block, sizeof(::s_tag_block));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_long_block_flags, sizeof(long));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_word_block_flags, sizeof(word));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_byte_block_flags, sizeof(byte));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_char_block_index, sizeof(char));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_char_block_index_custom_search, sizeof(char));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_short_block_index, sizeof(short));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_short_block_index_custom_search, sizeof(short));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_long_block_index, sizeof(long));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_long_block_index_custom_search, sizeof(long));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_data, sizeof(::s_tag_data));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_vertex_buffer, sizeof(::s_tag_d3d_vertex_buffer));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_pad, 0);
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_useless_pad, 0);
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_skip, 0);
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_non_cache_runtime_value, 0);
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_explanation, 0);
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_custom, 0);
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_struct, 0);
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_array, 0);
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_pageable_resource, sizeof(::s_tag_resource));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_api_interop, sizeof(::s_tag_interop));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_terminator, 0);
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_byte_integer, sizeof(byte));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_word_integer, sizeof(word));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_dword_integer, sizeof(dword));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_qword_integer, sizeof(qword));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_embedded_tag, sizeof(::s_tag_reference));
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_data_path, sizeof(::c_static_string<256>));
	if (field == _field_pointer)
	{
		ASSERT(BCS_SUCCEEDED(get_platform_pointer_size(engine_platform_build.platform_type, &field_size)));
		return BCS_S_OK;
	};
	FIELD_TO_TAG_FILE_FIELD_SIZE(_field_half, sizeof(word));

#undef FIELD_TO_TAG_FILE_FIELD_SIZE
	return BCS_E_FAIL;
}





