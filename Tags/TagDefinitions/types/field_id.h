#pragma once

namespace blofeld
{
	enum e_field_id
	{
		_field_id_default,
		
		_field_id_point = 'poin',
		_field_id_orientation = 'orie',
		_field_id_scale = 'scal',
		_field_id_decibels = '+dB+',
		_field_id_cents = 'cent',
		_field_id_zero_data = 'nuke',
		_field_id_hide = 'ugly',
		_field_id_filter = 'filt',
		_field_id_type = 'type',
		_field_id_name = 'name',
		_field_id_marker = 'amkr',
		_field_id_slider_editor = 'sled',
		_field_id_halo_script_block = 'hsbl',
		_field_id_unknown_facing = 'cfpf',


		_field_id_field_group_begin = 'fgrb',
		_field_id_field_group_end = 'fgre',
		_field_id_hide_begin = 'hide',
		_field_id_hide_end = 'edih',
		_field_id_dont_checksum_begin = 'dnc+',
		_field_id_dont_checksum_end = 'dnc-',
		_field_id_ifp_begin = 'ifp+',
		_field_id_ifp_end = 'ifp-',

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
		_field_id_function_output_modifier_input = 'fnom',
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

		_field_id_authored_light_probe = 'aulp',
		_field_id_particle_estimate_overdraw_unknown = 'eoci',
		_field_id_hologram_light = 'holl',
		_field_id_object_editor = 'obed',

		_field_id_grid = 'grid',
		_field_id_sort = 'sort',
		_field_id_slap = 'slap',
		_field_id_wide = 'wide',
		_field_id_function_output_modifier = 'fnop',
		_field_id_dumb = 'dumb',
		_field_id_ugpc = 'ugpc',
		_field_id_enum = 'enum',

		_field_id_archive_pointer = 'arpt',
		_field_id_sted = 'sted',
		_field_id_parent = 'parr',
		_field_id_edit = 'edit',
		_field_id_npik = 'npik',
		_field_id_ai_point = 'aipt',

		_field_id_function_editor = 'fned',
		_field_id_function_constant_value = 'fncv',
		_field_id_editablepropertybaseforceflags = 'fnfc',

		_field_id_bspf_unknown_bsp = 'bspf',
		_field_id_usqd_unknown_squad = 'usqd',
		_field_id_gnvb_unknown_graph_node = 'gnvb',
		_field_id_sky_lighting = 'skyl',

		_field_id_malleablepropertybasefloat = 'mpfi',
		_field_id_malleablepropertybaseshort = 'mpsh',
		_field_id_malleablepropertybaseangle = 'mpai',
		
	};

	BCS_DEBUG_API const char* field_id_to_string(e_field_id field);
}
