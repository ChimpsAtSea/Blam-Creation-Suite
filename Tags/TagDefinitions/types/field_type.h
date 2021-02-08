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

	enum e_field_id
	{
		_field_id_default,
		
		_field_id_field_group_begin = 'fgrb',
		_field_id_field_group_end = 'fgre',
		_field_id_point = 'poin',
		_field_id_orientation = 'orie',
		_field_id_scale = 'scal',
		_field_id_decibels = '+dB+',
		_field_id_cents = 'cent',
		_field_id_zero_data = 'nuke',
		_field_id_hide = 'ugly',
		_field_id_hidd_begin = 'hide',
		_field_id_hidd_end = 'edih',
		_field_id_filter = 'filt',
		_field_id_type = 'type',
		_field_id_name = 'name',
		_field_id_marker = 'amkr',
		_field_id_slider_editor = 'sled',
		_field_id_halo_script_block = 'hsbl',
		_field_id_unknown_facing = 'cfpf',

		_field_id_unknown_checksum_begin = 'dnc+',
		_field_id_unknown_checksum_end = 'dnc-',

		_field_id_cinematic_playback = 'cnpb',
		_field_id_cinematic_scene_flags = 'csfs',
		_field_id_cinematic_frame_index = 'cifi',
		_field_id_cinematic_version = 'cvmf',
		_field_id_cinematic_dynamic_light = 'cdlt',
		_field_id_camera_matrix_editor = 'cmed',
		_field_id_loop_cinematic_shot = 'lpsh',
		_field_id_loop_cinematic_scene = 'lpsc',

		_field_id_function_input_scalar = 'fnin',
		_field_id_function_input_range = 'fnir',
		_field_id_function_output_modifier = 'fnom',
		_field_id_function_unknown = 'fn**',

		_field_id_pathfinding = 'path',
		_field_id_object_id = 'obj#',
		_field_id_object_variant = 'vari',
		_field_id_environment_unknown = 'envf',
		_field_id_squad_template = 'sqdt',
		_field_id_bitmap_show = 'bshw',
		_field_id_manual_bsp_flags = 'mbsp',
		_field_id_scenario_zone_set_index = 'szsi',

		_field_id_block_index_flags = 'bifs',
		_field_id_block_flags_32bit = 'bf32', // BLOCK_FLAGS_I_KNOW_BLOCK_HAS_MORE_THAN_32_ELEMENTS_ID

		_field_id_shader_template = 'tmpl',
		_field_id_shader_unknown = 'ick!',

		_field_id_import_model = 'ipmi',
		_field_id_high_level_model_tag = 'hlmt',

		_field_id_sound_player = 'snpl',
		_field_id_unknown_player = 'mkpl',

		_field_id_unknown_maeo = 'maeo',
		_field_id_unknown_ohoc = 'ohoc',
		_field_id_unknown_function = 'coff',
		_field_id_unknown_compile = 'ctcd',

		_field_id_decorator_brush_unknown = 'cbif',
		_field_id_text_unknown = 'tcwd',
		_field_id_unknown_ugh = 'ugh@',
		_field_id_unknown_mela = 'mela',
		_field_id_unknown_begin = 'ifp+',
		_field_id_unknown_end = 'ifp-',

		_field_id_authored_light_probe = 'aulp',
		_field_id_particle_estimate_overdraw_unknown = 'eoci',
		_field_id_hologram_light = 'holl',
		_field_id_object_editor = 'obed',

		_field_id_grid = 'grid',
		_field_id_sort = 'sort',
		_field_id_slap = 'slap',
		_field_id_wide = 'wide',
		_field_id_fnop = 'fnop',
		_field_id_dumb = 'dumb',
		_field_id_ugpc = 'ugpc',
		_field_id_enum = 'enum',
		

	};
}
