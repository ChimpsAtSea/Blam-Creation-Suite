#pragma once

#define __FIELD_MACRO_HELPER(type, name, description, flags, data)\
{														\
	type,												\
	(const char*)(name),								\
	(const char*)(description),							\
	nullptr,											\
	nullptr,											\
	nullptr,											\
	0,													\
	(data),												\
	_field_id_default									\
}

// #TODO
#define FIELD_FLAG_NONE 0u
#define FIELD_FLAG_UNKNOWN0 0u
#define FIELD_FLAG_READ_ONLY 0u
#define FIELD_FLAG_INDEX 0u
#define FIELD_FLAG_UNKNOWN3 0u
#define FIELD_FLAG_POINTER 0u

#define FIELD_CUSTOM(name, description, flags, type) __FIELD_MACRO_HELPER(_field_custom, name, description, flags, reinterpret_cast<void*>(static_cast<intptr_t>(type)))
#define FIELD_PAD(name, description, flags, size) __FIELD_MACRO_HELPER(_field_pad, name, description, flags, reinterpret_cast<void*>(static_cast<intptr_t>(size)))
#define FIELD_SKIP(name, description, flags, size) __FIELD_MACRO_HELPER(_field_skip, name, description, flags, reinterpret_cast<void*>(static_cast<intptr_t>(size)))
#define FIELD_EXPLANATION(name, description, flags, explanation) __FIELD_MACRO_HELPER(_field_explanation, name, description, flags, static_cast<const void*>(explanation))
#define MAKE_OLD_NAMES(...) ([]() { static const char* old_names[] = { __VA_ARGS__ }; return old_names; })()

#ifndef __INTELLISENSE__

#define _legacy_field_string blofeld::_field_string, __FILE__, __LINE__
#define _legacy_field_long_string blofeld::_field_long_string, __FILE__, __LINE__
#define _legacy_field_string_id blofeld::_field_string_id, __FILE__, __LINE__
#define _legacy_field_old_string_id blofeld::_field_old_string_id, __FILE__, __LINE__
#define _legacy_field_char_integer blofeld::_field_char_integer, __FILE__, __LINE__
#define _legacy_field_short_integer blofeld::_field_short_integer, __FILE__, __LINE__
#define _legacy_field_long_integer blofeld::_field_long_integer, __FILE__, __LINE__
#define _legacy_field_int64_integer blofeld::_field_int64_integer, __FILE__, __LINE__
#define _legacy_field_angle blofeld::_field_angle, __FILE__, __LINE__
#define _legacy_field_tag blofeld::_field_tag, __FILE__, __LINE__
#define _legacy_field_char_enum blofeld::_field_char_enum, __FILE__, __LINE__
#define _legacy_field_enum blofeld::_field_enum, __FILE__, __LINE__
#define _legacy_field_long_enum blofeld::_field_long_enum, __FILE__, __LINE__
#define _legacy_field_long_flags blofeld::_field_long_flags, __FILE__, __LINE__
#define _legacy_field_word_flags blofeld::_field_word_flags, __FILE__, __LINE__
#define _legacy_field_byte_flags blofeld::_field_byte_flags, __FILE__, __LINE__
#define _legacy_field_point_2d blofeld::_field_point_2d, __FILE__, __LINE__
#define _legacy_field_rectangle_2d blofeld::_field_rectangle_2d, __FILE__, __LINE__
#define _legacy_field_rgb_color blofeld::_field_rgb_color, __FILE__, __LINE__
#define _legacy_field_argb_color blofeld::_field_argb_color, __FILE__, __LINE__
#define _legacy_field_real blofeld::_field_real, __FILE__, __LINE__
#define _legacy_field_real_fraction blofeld::_field_real_fraction, __FILE__, __LINE__
#define _legacy_field_real_point_2d blofeld::_field_real_point_2d, __FILE__, __LINE__
#define _legacy_field_real_point_3d blofeld::_field_real_point_3d, __FILE__, __LINE__
#define _legacy_field_real_vector_2d blofeld::_field_real_vector_2d, __FILE__, __LINE__
#define _legacy_field_real_vector_3d blofeld::_field_real_vector_3d, __FILE__, __LINE__
#define _legacy_field_real_quaternion blofeld::_field_real_quaternion, __FILE__, __LINE__
#define _legacy_field_real_euler_angles_2d blofeld::_field_real_euler_angles_2d, __FILE__, __LINE__
#define _legacy_field_real_euler_angles_3d blofeld::_field_real_euler_angles_3d, __FILE__, __LINE__
#define _legacy_field_real_plane_2d blofeld::_field_real_plane_2d, __FILE__, __LINE__
#define _legacy_field_real_plane_3d blofeld::_field_real_plane_3d, __FILE__, __LINE__
#define _legacy_field_real_rgb_color blofeld::_field_real_rgb_color, __FILE__, __LINE__
#define _legacy_field_real_argb_color blofeld::_field_real_argb_color, __FILE__, __LINE__
#define _legacy_field_real_hsv_color blofeld::_field_real_hsv_color, __FILE__, __LINE__
#define _legacy_field_real_ahsv_color blofeld::_field_real_ahsv_color, __FILE__, __LINE__
#define _legacy_field_short_bounds blofeld::_field_short_bounds, __FILE__, __LINE__
#define _legacy_field_angle_bounds blofeld::_field_angle_bounds, __FILE__, __LINE__
#define _legacy_field_real_bounds blofeld::_field_real_bounds, __FILE__, __LINE__
#define _legacy_field_real_fraction_bounds blofeld::_field_real_fraction_bounds, __FILE__, __LINE__
#define _legacy_field_tag_reference blofeld::_field_tag_reference, __FILE__, __LINE__
#define _legacy_field_block blofeld::_field_block, __FILE__, __LINE__
#define _legacy_field_long_block_flags blofeld::_field_long_block_flags, __FILE__, __LINE__
#define _legacy_field_word_block_flags blofeld::_field_word_block_flags, __FILE__, __LINE__
#define _legacy_field_byte_block_flags blofeld::_field_byte_block_flags, __FILE__, __LINE__
#define _legacy_field_char_block_index blofeld::_field_char_block_index, __FILE__, __LINE__
#define _legacy_field_custom_char_block_index blofeld::_field_custom_char_block_index, __FILE__, __LINE__
#define _legacy_field_short_block_index blofeld::_field_short_block_index, __FILE__, __LINE__
#define _legacy_field_custom_short_block_index blofeld::_field_custom_short_block_index, __FILE__, __LINE__
#define _legacy_field_long_block_index blofeld::_field_long_block_index, __FILE__, __LINE__
#define _legacy_field_custom_long_block_index blofeld::_field_custom_long_block_index, __FILE__, __LINE__
#define _legacy_field_data blofeld::_field_data, __FILE__, __LINE__
#define _legacy_field_vertex_buffer blofeld::_field_vertex_buffer, __FILE__, __LINE__
#define _legacy_field_pad blofeld::_field_pad, __FILE__, __LINE__
#define _legacy_field_useless_pad blofeld::_field_useless_pad, __FILE__, __LINE__
#define _legacy_field_skip blofeld::_field_skip, __FILE__, __LINE__
#define _legacy_field_non_cache_runtime_value blofeld::_field_non_cache_runtime_value, __FILE__, __LINE__
#define _legacy_field_explanation blofeld::_field_explanation, __FILE__, __LINE__
#define _legacy_field_custom blofeld::_field_custom, __FILE__, __LINE__
#define _legacy_field_struct blofeld::_field_struct, __FILE__, __LINE__
#define _legacy_field_array blofeld::_field_array, __FILE__, __LINE__
#define _legacy_field_pageable blofeld::_field_pageable, __FILE__, __LINE__
#define _legacy_field_api_interop blofeld::_field_api_interop, __FILE__, __LINE__
#define _legacy_field_terminator blofeld::_field_terminator, __FILE__, __LINE__
#define _legacy_field_byte_integer blofeld::_field_byte_integer, __FILE__, __LINE__
#define _legacy_field_word_integer blofeld::_field_word_integer, __FILE__, __LINE__
#define _legacy_field_dword_integer blofeld::_field_dword_integer, __FILE__, __LINE__
#define _legacy_field_qword_integer blofeld::_field_qword_integer, __FILE__, __LINE__

#define _legacy_field_pointer blofeld::_field_pointer, __FILE__, __LINE__
#define _legacy_field_half blofeld::_field_half, __FILE__, __LINE__
#define _legacy_field_version_equal blofeld::_field_version_equal, __FILE__, __LINE__
#define _legacy_field_version_not_equal blofeld::_field_version_not_equal, __FILE__, __LINE__
#define _legacy_field_version_less blofeld::_field_version_less, __FILE__, __LINE__
#define _legacy_field_version_greater blofeld::_field_version_greater, __FILE__, __LINE__
#define _legacy_field_version_less_or_equal blofeld::_field_version_less_or_equal, __FILE__, __LINE__
#define _legacy_field_version_greater_or_equal blofeld::_field_version_greater_or_equal, __FILE__, __LINE__
#define _legacy_field_version_custom blofeld::_field_version_custom, __FILE__, __LINE__
#define _legacy_field_version_platform_include blofeld::_field_version_platform_include, __FILE__, __LINE__
#define _legacy_field_version_platform_exclude blofeld::_field_version_platform_exclude, __FILE__, __LINE__

#define _field_string blofeld::_field_string, __FILE__, __LINE__
#define _field_long_string blofeld::_field_long_string, __FILE__, __LINE__
#define _field_string_id blofeld::_field_string_id, __FILE__, __LINE__
#define _field_old_string_id blofeld::_field_old_string_id, __FILE__, __LINE__
#define _field_char_integer blofeld::_field_char_integer, __FILE__, __LINE__
#define _field_short_integer blofeld::_field_short_integer, __FILE__, __LINE__
#define _field_long_integer blofeld::_field_long_integer, __FILE__, __LINE__
#define _field_int64_integer blofeld::_field_int64_integer, __FILE__, __LINE__
#define _field_angle blofeld::_field_angle, __FILE__, __LINE__
#define _field_tag blofeld::_field_tag, __FILE__, __LINE__
#define _field_char_enum blofeld::_field_char_enum, __FILE__, __LINE__
#define _field_enum blofeld::_field_enum, __FILE__, __LINE__
#define _field_long_enum blofeld::_field_long_enum, __FILE__, __LINE__
#define _field_long_flags blofeld::_field_long_flags, __FILE__, __LINE__
#define _field_word_flags blofeld::_field_word_flags, __FILE__, __LINE__
#define _field_byte_flags blofeld::_field_byte_flags, __FILE__, __LINE__
#define _field_point_2d blofeld::_field_point_2d, __FILE__, __LINE__
#define _field_rectangle_2d blofeld::_field_rectangle_2d, __FILE__, __LINE__
#define _field_rgb_color blofeld::_field_rgb_color, __FILE__, __LINE__
#define _field_argb_color blofeld::_field_argb_color, __FILE__, __LINE__
#define _field_real blofeld::_field_real, __FILE__, __LINE__
#define _field_real_fraction blofeld::_field_real_fraction, __FILE__, __LINE__
#define _field_real_point_2d blofeld::_field_real_point_2d, __FILE__, __LINE__
#define _field_real_point_3d blofeld::_field_real_point_3d, __FILE__, __LINE__
#define _field_real_vector_2d blofeld::_field_real_vector_2d, __FILE__, __LINE__
#define _field_real_vector_3d blofeld::_field_real_vector_3d, __FILE__, __LINE__
#define _field_real_quaternion blofeld::_field_real_quaternion, __FILE__, __LINE__
#define _field_real_euler_angles_2d blofeld::_field_real_euler_angles_2d, __FILE__, __LINE__
#define _field_real_euler_angles_3d blofeld::_field_real_euler_angles_3d, __FILE__, __LINE__
#define _field_real_plane_2d blofeld::_field_real_plane_2d, __FILE__, __LINE__
#define _field_real_plane_3d blofeld::_field_real_plane_3d, __FILE__, __LINE__
#define _field_real_rgb_color blofeld::_field_real_rgb_color, __FILE__, __LINE__
#define _field_real_argb_color blofeld::_field_real_argb_color, __FILE__, __LINE__
#define _field_real_hsv_color blofeld::_field_real_hsv_color, __FILE__, __LINE__
#define _field_real_ahsv_color blofeld::_field_real_ahsv_color, __FILE__, __LINE__
#define _field_short_bounds blofeld::_field_short_bounds, __FILE__, __LINE__
#define _field_angle_bounds blofeld::_field_angle_bounds, __FILE__, __LINE__
#define _field_real_bounds blofeld::_field_real_bounds, __FILE__, __LINE__
#define _field_real_fraction_bounds blofeld::_field_real_fraction_bounds, __FILE__, __LINE__
#define _field_tag_reference blofeld::_field_tag_reference, __FILE__, __LINE__
#define _field_block blofeld::_field_block, __FILE__, __LINE__
#define _field_long_block_flags blofeld::_field_long_block_flags, __FILE__, __LINE__
#define _field_word_block_flags blofeld::_field_word_block_flags, __FILE__, __LINE__
#define _field_byte_block_flags blofeld::_field_byte_block_flags, __FILE__, __LINE__
#define _field_char_block_index blofeld::_field_char_block_index, __FILE__, __LINE__
#define _field_custom_char_block_index blofeld::_field_custom_char_block_index, __FILE__, __LINE__
#define _field_short_block_index blofeld::_field_short_block_index, __FILE__, __LINE__
#define _field_custom_short_block_index blofeld::_field_custom_short_block_index, __FILE__, __LINE__
#define _field_long_block_index blofeld::_field_long_block_index, __FILE__, __LINE__
#define _field_custom_long_block_index blofeld::_field_custom_long_block_index, __FILE__, __LINE__
#define _field_data blofeld::_field_data, __FILE__, __LINE__
#define _field_vertex_buffer blofeld::_field_vertex_buffer, __FILE__, __LINE__
#define _field_pad blofeld::_field_pad, __FILE__, __LINE__
#define _field_useless_pad blofeld::_field_useless_pad, __FILE__, __LINE__
#define _field_skip blofeld::_field_skip, __FILE__, __LINE__
#define _field_non_cache_runtime_value blofeld::_field_non_cache_runtime_value, __FILE__, __LINE__
#define _field_explanation blofeld::_field_explanation, __FILE__, __LINE__
#define _field_custom blofeld::_field_custom, __FILE__, __LINE__
#define _field_struct blofeld::_field_struct, __FILE__, __LINE__
#define _field_array blofeld::_field_array, __FILE__, __LINE__
#define _field_pageable blofeld::_field_pageable, __FILE__, __LINE__
#define _field_api_interop blofeld::_field_api_interop, __FILE__, __LINE__
#define _field_terminator blofeld::_field_terminator, __FILE__, __LINE__
#define _field_byte_integer blofeld::_field_byte_integer, __FILE__, __LINE__
#define _field_word_integer blofeld::_field_word_integer, __FILE__, __LINE__
#define _field_dword_integer blofeld::_field_dword_integer, __FILE__, __LINE__
#define _field_qword_integer blofeld::_field_qword_integer, __FILE__, __LINE__

#define _field_data_path blofeld::_field_data_path, __FILE__, __LINE__
#define _field_embedded_tag blofeld::_field_embedded_tag, __FILE__, __LINE__

#define _field_pointer blofeld::_field_pointer, __FILE__, __LINE__
#define _field_half blofeld::_field_half, __FILE__, __LINE__
#define _field_version_equal blofeld::_field_version_equal, __FILE__, __LINE__
#define _field_version_not_equal blofeld::_field_version_not_equal, __FILE__, __LINE__
#define _field_version_less blofeld::_field_version_less, __FILE__, __LINE__
#define _field_version_greater blofeld::_field_version_greater, __FILE__, __LINE__
#define _field_version_less_or_equal blofeld::_field_version_less_or_equal, __FILE__, __LINE__
#define _field_version_greater_or_equal blofeld::_field_version_greater_or_equal, __FILE__, __LINE__
#define _field_version_custom blofeld::_field_version_custom, __FILE__, __LINE__
#define _field_version_platform_include blofeld::_field_version_platform_include, __FILE__, __LINE__
#define _field_version_platform_exclude blofeld::_field_version_platform_exclude, __FILE__, __LINE__

#endif
