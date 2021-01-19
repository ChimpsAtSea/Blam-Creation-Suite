#pragma once

namespace blofeld
{
	struct s_tag_field;

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

		_field_type_non_standard_custom_type, // custom fields begin here
		_field_pointer,
		_field_half,
		_field_type_non_standard, // custom fields begin here
		_field_version_equal,
		_field_version_not_equal,
		_field_version_less,
		_field_version_greater,
		_field_version_less_or_equal,
		_field_version_greater_or_equal,
		_field_version_platform_include,
		_field_version_platform_exclude,
		_field_version_custom,
		k_number_of_blofeld_field_types
	};

	uint32_t get_blofeld_field_size(e_platform_type platform_type, e_field field);
	uint32_t get_blofeld_field_size(const s_tag_field& field, e_engine_type engine_type, e_platform_type platform_type, e_build build);
	const char* field_to_string(e_field field);

	enum e_custom_field_type
	{
		_custom_field_function_group_begin = 'fgrb',
		_custom_field_function_group_end = 'fgre',
		_custom_field_point = 'poin',
		_custom_field_orientation = 'orie',
		_custom_field_scale = 'scal',
		_custom_field_decibels = '+dB+',
		_custom_field_cents = 'cent',
		_custom_field_zero_data = 'nuke',
		_custom_field_hide = 'ugly',
		_custom_field_hidd_begin = 'hide',
		_custom_field_hidd_end = 'edih',
		_custom_field_filter = 'filt',
		_custom_field_type = 'type',
		_custom_field_name = 'name',
		_custom_field_marker = 'amkr',
		_custom_field_slider_editor = 'sled',
		_custom_field_halo_script_block = 'hsbl',
		_custom_field_unknown_facing = 'cfpf',

		_custom_field_unknown_checksum_begin = 'dnc+',
		_custom_field_unknown_checksum_end = 'dnc-',

		_custom_field_cinematic_playback = 'cnpb',
		_custom_field_cinematic_scene_flags = 'csfs',
		_custom_field_cinematic_frame_index = 'cifi',
		_custom_field_cinematic_version = 'cvmf',
		_custom_field_cinematic_dynamic_light = 'cdlt',
		_custom_field_camera_matrix_editor = 'cmed',
		_custom_field_loop_cinematic_shot = 'lpsh',
		_custom_field_loop_cinematic_scene = 'lpsc',

		_custom_field_function_input_scalar = 'fnin',
		_custom_field_function_input_range = 'fnir',
		_custom_field_function_output_modifier = 'fnom',
		_custom_field_function_unknown = 'fn**',

		_custom_field_pathfinding = 'path',
		_custom_field_object_id = 'obj#',
		_custom_field_object_variant = 'vari',
		_custom_field_environment_unknown = 'envf',
		_custom_field_squad_template = 'sqdt',
		_custom_field_bitmap_show = 'bshw',
		_custom_field_manual_bsp_flags = 'mbsp',
		_custom_field_scenario_zone_set_index = 'szsi',

		_custom_field_block_index_flags = 'bifs',
		_custom_field_block_flags_32bit = 'bf32',

		_custom_field_shader_template = 'tmpl',
		_custom_field_shader_unknown = 'ick!',

		_custom_field_import_model = 'ipmi',
		_custom_field_high_level_model_tag = 'hlmt',

		_custom_field_sound_player = 'snpl',
		_custom_field_unknown_player = 'mkpl',

		_custom_field_unknown_maeo = 'maeo',
		_custom_field_unknown_ohoc = 'ohoc',
		_custom_field_unknown_function = 'coff',
		_custom_field_unknown_compile = 'ctcd',

		_custom_field_decorator_brush_unknown = 'cbif',
		_custom_field_text_unknown = 'tcwd',
		_custom_field_unknown_ugh = 'ugh@',
		_custom_field_unknown_mela = 'mela',
		_custom_field_unknown_begin = 'ifp+',
		_custom_field_unknown_end = 'ifp-',

		_custom_field_authored_light_probe = 'aulp',
		_custom_field_particle_estimate_overdraw_unknown = 'eoci',
		_custom_field_hologram_light = 'holl',
		_custom_field_object_editor = 'obed',

	};
}
