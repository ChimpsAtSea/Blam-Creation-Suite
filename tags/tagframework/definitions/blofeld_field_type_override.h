#pragma once

#define __FIELD_MACRO_HELPER(type, name, description, flags, data, id)\
{														\
	type,												\
	(const char*)(name),								\
	(const char*)(description),							\
	nullptr,											\
	nullptr,											\
	nullptr,											\
	0,													\
	(data),												\
	id													\
}

#define FIELD_FLAG_NONE f_tag_field_flags()
#define FIELD_FLAG_UNKNOWN0 f_tag_field_flags(_tag_field_flag_unknown0)
#define FIELD_FLAG_READ_ONLY f_tag_field_flags(_tag_field_flag_read_only)
#define FIELD_FLAG_INDEX f_tag_field_flags(_tag_field_flag_index)
#define FIELD_FLAG_UNKNOWN3 f_tag_field_flags(_tag_field_flag_unknown3)
#define FIELD_FLAG_UNKNOWN4 f_tag_field_flags(_tag_field_flag_unknown4)
#define FIELD_FLAG_POINTER f_tag_field_flags(_tag_field_flag_pointer)

#define TAG_REFERENCE_FLAG_NONE f_tag_reference_flags()
#define TAG_REFERENCE_FLAG_NOT_A_DEPENDENCY f_tag_reference_flags(_tag_reference_flag_not_a_dependency)
#define TAG_REFERENCE_FLAG_DONT_RESOLVE_IN_EDITOR f_tag_reference_flags(_tag_reference_flag_dont_resolve_in_editor)
#define TAG_REFERENCE_FLAG_RESOLVED_MANUALLY f_tag_reference_flags(_tag_reference_flag_resolved_manually)
#define TAG_REFERENCE_FLAG_RESOLVED_BY_GAME f_tag_reference_flags(_tag_reference_flag_resolved_by_game)
#define TAG_REFERENCE_FLAG_NOT_A_RESOURCE_DEPENDENCY f_tag_reference_flags(_tag_reference_flag_not_a_resource_dependency)
#define TAG_REFERENCE_FLAG_DEPENDENCY_FOR_CACHE_FILE_SHARING f_tag_reference_flags(_tag_reference_flag_dependency_for_cache_file_sharing)
#define TAG_REFERENCE_FLAG_REFERENCE_IGNORED_BY_BUNDLE_BUILDER f_tag_reference_flags(_tag_reference_flag_reference_ignored_by_bundle_builder)

#define TAG_GROUP_FLAG_NONE f_tag_group_flags()
#define TAG_GROUP_FLAG_IS_GAME_CRITICAL f_tag_group_flags(_tag_group_flag_is_game_critical)
#define TAG_GROUP_FLAG_CAN_BE_RELOADED f_tag_group_flags(_tag_group_flag_can_be_reloaded)
#define TAG_GROUP_FLAG_FORCES_MAP_RELOAD f_tag_group_flags(_tag_group_flag_forces_map_reload)
#define TAG_GROUP_FLAG_FORCES_LIGHTING_RESET f_tag_group_flags(_tag_group_flag_forces_lighting_reset)
#define TAG_GROUP_FLAG_DOES_NOT_EXIST_IN_CACHE_BUILD f_tag_group_flags(_tag_group_flag_does_not_exist_in_cache_build)
#define TAG_GROUP_FLAG_CAN_SAVE_WHEN_NOT_LOADED_FOR_EDITING f_tag_group_flags(_tag_group_flag_can_save_when_not_loaded_for_editing)
#define TAG_GROUP_FLAG_DO_NOT_ATTEMPT_TO_PREDICT_ON_CACHE_MISS f_tag_group_flags(_tag_group_flag_do_not_attempt_to_predict_on_cache_miss)
#define TAG_GROUP_FLAG_DO_NOT_ATTEMPT_TO_PREDICT_THROUGH_DEPENDENCIES f_tag_group_flags(_tag_group_flag_do_not_attempt_to_predict_through_dependencies)
#define TAG_GROUP_FLAG_DO_NOT_ATTEMPT_TO_PREDICT_CHILDREN f_tag_group_flags(_tag_group_flag_do_not_attempt_to_predict_children)
#define TAG_GROUP_FLAG_DO_NOT_XSYNC_TO_TARGET_PLATFORM f_tag_group_flags(_tag_group_flag_do_not_xsync_to_target_platform)
#define TAG_GROUP_FLAG_RESTRICTED_ON_XSYNC f_tag_group_flags(_tag_group_flag_restricted_on_xsync)
#define TAG_GROUP_FLAG_CREATE_AS_GLOBAL_CACHE_FILE_TAG f_tag_group_flags(_tag_group_flag_create_as_global_cache_file_tag)
#define TAG_GROUP_FLAG_DO_NOT_ADD_CHILDREN_TO_GLOBAL_ZONE f_tag_group_flags(_tag_group_flag_do_not_add_children_to_global_zone)
#define TAG_GROUP_FLAG_INVALIDATES_STRUCTURE_MATERIALS f_tag_group_flags(_tag_group_flag_invalidates_structure_materials)
#define TAG_GROUP_FLAG_CHILDREN_RESOLVED_MANUALLY f_tag_group_flags(_tag_group_flag_children_resolved_manually)
#define TAG_GROUP_FLAG_FORCES_SCRIPT_RECOMPILE f_tag_group_flags(_tag_group_flag_forces_script_recompile)
#define TAG_GROUP_FLAG_FORCES_ACTIVE_ZONE_SET_RELOAD f_tag_group_flags(_tag_group_flag_forces_active_zone_set_reload)
#define TAG_GROUP_FLAG_RESTRICTED_FORCES_ACTIVE_ZONE_SET_RELOAD f_tag_group_flags(_tag_group_flag_restricted_forces_active_zone_set_reload)
#define TAG_GROUP_FLAG_CANNOT_BE_CREATED f_tag_group_flags(_tag_group_flag_cannot_be_created)
#define TAG_GROUP_FLAG_SHOULD_NOT_BE_USED_AS_A_RESOLVING_REFERENCE f_tag_group_flags(_tag_group_flag_should_not_be_used_as_a_resolving_reference)
#define TAG_GROUP_FLAG_DO_NOT_MAKE_SCRIPT_DEPENDENCY f_tag_group_flags(_tag_group_flag_do_not_make_script_dependency)
#define TAG_GROUP_FLAG_DO_NOT_WRITE_OUT_UNTIL_CACHE_FILE_LINK_TIME f_tag_group_flags(_tag_group_flag_do_not_write_out_until_cache_file_link_time)
#define TAG_GROUP_FLAG_NOT_LANGUAGE_NEUTRAL f_tag_group_flags(_tag_group_flag_not_language_neutral)
#define TAG_GROUP_FLAG_INVALIDATES_STRUCTURE_BSP_GEOMETRY f_tag_group_flags(_tag_group_flag_invalidates_structure_bsp_geometry)
#define TAG_GROUP_FLAG_DISCARD_FOR_DEDICATED_SERVER f_tag_group_flags(_tag_group_flag_discard_for_dedicated_server)

#define FIELD_CUSTOM(name, tag_field_custom_type)                       __FIELD_MACRO_HELPER(_field_custom,      name, nullptr,        FIELD_FLAG_NONE, nullptr,                                              tag_field_custom_type)
#define FIELD_EXPLANATION(name, explanation)                            __FIELD_MACRO_HELPER(_field_explanation, name, nullptr,        FIELD_FLAG_NONE, static_cast<const void*>(explanation),                _field_id_default)
#define FIELD_PAD(name, size)                                           __FIELD_MACRO_HELPER(_field_pad,         name, nullptr,        FIELD_FLAG_NONE, reinterpret_cast<void*>(static_cast<intptr_t>(size)), _field_id_default)
#define FIELD_USELESS_PAD(name, size)                                   __FIELD_MACRO_HELPER(_field_useless_pad, name, nullptr,        FIELD_FLAG_NONE, reinterpret_cast<void*>(static_cast<intptr_t>(size)), _field_id_default)
#define FIELD_SKIP(name, size)                                          __FIELD_MACRO_HELPER(_field_skip,        name, nullptr,        FIELD_FLAG_NONE, reinterpret_cast<void*>(static_cast<intptr_t>(size)), _field_id_default)
#define FIELD_PAD_EX(name, description, flags, size, tag_field_type)    __FIELD_MACRO_HELPER(_field_pad,         name, description,    flags,           reinterpret_cast<void*>(static_cast<intptr_t>(size)), tag_field_type)
#define FIELD_SKIP_EX(name, description, flags, size)                   __FIELD_MACRO_HELPER(_field_skip,        name, description,    flags,           reinterpret_cast<void*>(static_cast<intptr_t>(size)), _field_id_default)
#define FIELD_EXPLANATION_EX(name, description, flags, explanation)     __FIELD_MACRO_HELPER(_field_explanation, name, description,    flags,           static_cast<const void*>(explanation),                _field_id_default)

#define FIELD_GROUP_BEGIN(name) FIELD_CUSTOM(name, _tag_field_custom_type_field_group_begin)
#define FIELD_GROUP_END() FIELD_CUSTOM("value", _tag_field_custom_type_field_group_end)
#define FIELD_GROUP_END2(name) FIELD_CUSTOM(name, _tag_field_custom_type_field_group_end)
#define FIELD_HIDE_BEGIN() FIELD_CUSTOM("value", _tag_field_custom_type_hide_group_begin)
#define FIELD_HIDE_END() FIELD_CUSTOM("value", _tag_field_custom_type_hide_group_end)
#define FIELD_DONT_CHECKSUM_BEGIN() FIELD_CUSTOM("value", _field_id_dont_checksum_begin)
#define FIELD_DONT_CHECKSUM_END() FIELD_CUSTOM("value", _field_id_dont_checksum_end)
#define FIELD_IFP_BEGIN() FIELD_CUSTOM("value", _tag_field_custom_type_individual_field_preview_group_begin)
#define FIELD_IFP_END() FIELD_CUSTOM("value", _tag_field_custom_type_individual_field_preview_group_end)

#define MAKE_ALT_NAMES(...) ([]() { static const char* old_names[] = { "" __VA_ARGS__ , nullptr }; return old_names; })()

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
#define _legacy_field_short_enum blofeld::_field_short_enum, __FILE__, __LINE__
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
#define _legacy_field_short_integer_bounds blofeld::_field_short_integer_bounds, __FILE__, __LINE__
#define _legacy_field_angle_bounds blofeld::_field_angle_bounds, __FILE__, __LINE__
#define _legacy_field_real_bounds blofeld::_field_real_bounds, __FILE__, __LINE__
#define _legacy_field_real_fraction_bounds blofeld::_field_real_fraction_bounds, __FILE__, __LINE__
#define _legacy_field_tag_reference blofeld::_field_tag_reference, __FILE__, __LINE__
#define _legacy_field_block blofeld::_field_block, __FILE__, __LINE__
#define _legacy_field_long_block_flags blofeld::_field_long_block_flags, __FILE__, __LINE__
#define _legacy_field_word_block_flags blofeld::_field_word_block_flags, __FILE__, __LINE__
#define _legacy_field_byte_block_flags blofeld::_field_byte_block_flags, __FILE__, __LINE__
#define _legacy_field_char_block_index blofeld::_field_char_block_index, __FILE__, __LINE__
#define _legacy_field_char_block_index_custom_search blofeld::_field_char_block_index_custom_search, __FILE__, __LINE__
#define _legacy_field_short_block_index blofeld::_field_short_block_index, __FILE__, __LINE__
#define _legacy_field_short_block_index_custom_search blofeld::_field_short_block_index_custom_search, __FILE__, __LINE__
#define _legacy_field_long_block_index blofeld::_field_long_block_index, __FILE__, __LINE__
#define _legacy_field_long_block_index_custom_search blofeld::_field_long_block_index_custom_search, __FILE__, __LINE__
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
#define _legacy_field_pageable_resource blofeld::_field_pageable_resource, __FILE__, __LINE__
#define _legacy_field_api_interop blofeld::_field_api_interop, __FILE__, __LINE__
#define _legacy_field_terminator blofeld::_field_terminator, __FILE__, __LINE__
#define _legacy_field_byte_integer blofeld::_field_byte_integer, __FILE__, __LINE__
#define _legacy_field_word_integer blofeld::_field_word_integer, __FILE__, __LINE__
#define _legacy_field_dword_integer blofeld::_field_dword_integer, __FILE__, __LINE__
#define _legacy_field_qword_integer blofeld::_field_qword_integer, __FILE__, __LINE__

#define _legacy_field_pointer blofeld::_field_pointer, __FILE__, __LINE__
#define _legacy_field_half blofeld::_field_half, __FILE__, __LINE__
#define _legacy_version_mode_equal blofeld::_version_mode_equal, __FILE__, __LINE__
#define _legacy_version_mode_not_equal blofeld::_version_mode_not_equal, __FILE__, __LINE__
#define _legacy_version_mode_less blofeld::_version_mode_less, __FILE__, __LINE__
#define _legacy_version_mode_greater blofeld::_version_mode_greater, __FILE__, __LINE__
#define _legacy_version_mode_less_or_equal blofeld::_version_mode_less_or_equal, __FILE__, __LINE__
#define _legacy_version_mode_greater_or_equal blofeld::_version_mode_greater_or_equal, __FILE__, __LINE__
#define _legacy_version_mode_custom blofeld::_version_mode_custom, __FILE__, __LINE__
#define _legacy_version_mode_platform_include blofeld::_version_mode_platform_include, __FILE__, __LINE__
#define _legacy_version_mode_platform_exclude blofeld::_version_mode_platform_exclude, __FILE__, __LINE__

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
#define _field_short_enum blofeld::_field_short_enum, __FILE__, __LINE__
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
#define _field_short_integer_bounds blofeld::_field_short_integer_bounds, __FILE__, __LINE__
#define _field_angle_bounds blofeld::_field_angle_bounds, __FILE__, __LINE__
#define _field_real_bounds blofeld::_field_real_bounds, __FILE__, __LINE__
#define _field_real_fraction_bounds blofeld::_field_real_fraction_bounds, __FILE__, __LINE__
#define _field_tag_reference blofeld::_field_tag_reference, __FILE__, __LINE__
#define _field_block blofeld::_field_block, __FILE__, __LINE__
#define _field_long_block_flags blofeld::_field_long_block_flags, __FILE__, __LINE__
#define _field_word_block_flags blofeld::_field_word_block_flags, __FILE__, __LINE__
#define _field_byte_block_flags blofeld::_field_byte_block_flags, __FILE__, __LINE__
#define _field_char_block_index blofeld::_field_char_block_index, __FILE__, __LINE__
#define _field_char_block_index_custom_search blofeld::_field_char_block_index_custom_search, __FILE__, __LINE__
#define _field_short_block_index blofeld::_field_short_block_index, __FILE__, __LINE__
#define _field_short_block_index_custom_search blofeld::_field_short_block_index_custom_search, __FILE__, __LINE__
#define _field_long_block_index blofeld::_field_long_block_index, __FILE__, __LINE__
#define _field_long_block_index_custom_search blofeld::_field_long_block_index_custom_search, __FILE__, __LINE__
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
#define _field_pageable_resource blofeld::_field_pageable_resource, __FILE__, __LINE__
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

#define _version_mode_equal blofeld::_version_mode_equal, __FILE__, __LINE__
#define _version_mode_not_equal blofeld::_version_mode_not_equal, __FILE__, __LINE__
#define _version_mode_less blofeld::_version_mode_less, __FILE__, __LINE__
#define _version_mode_greater blofeld::_version_mode_greater, __FILE__, __LINE__
#define _version_mode_less_or_equal blofeld::_version_mode_less_or_equal, __FILE__, __LINE__
#define _version_mode_greater_or_equal blofeld::_version_mode_greater_or_equal, __FILE__, __LINE__
#define _version_mode_custom blofeld::_version_mode_custom, __FILE__, __LINE__
#define _version_mode_platform_include blofeld::_version_mode_platform_include, __FILE__, __LINE__
#define _version_mode_platform_exclude blofeld::_version_mode_platform_exclude, __FILE__, __LINE__

#define _version_mode_tag_group_equal blofeld::_version_mode_tag_group_equal, __FILE__, __LINE__
#define _version_mode_tag_group_not_equal blofeld::_version_mode_tag_group_not_equal, __FILE__, __LINE__

#define  _struct_version_mode_equal blofeld::_struct_version_mode_equal, __FILE__, __LINE__
#define  _struct_version_mode_greater_or_equal blofeld::_struct_version_mode_greater_or_equal, __FILE__, __LINE__

#define int32 int
#define uint32 unsigned int

#endif
