#pragma once

namespace blofeld
{
	enum e_field_id
	{
		_field_id_default,
		_field_id_null = -1,

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
		_field_id_manual_bsp_flags = 'mbsp',
		_field_id_scenario_zone_set_index = 'szsi',

		_field_id_block_index_flags = 'bifs',
		_field_id_block_flags_32bit = 'bf32', // BLOCK_FLAGS_I_KNOW_BLOCK_HAS_MORE_THAN_32_ELEMENTS_ID

		_field_id_shader_unknown = 'ick!',

		_field_id_import_model = 'ipmi',


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
		_field_id_npik = 'npik',
		_field_id_ai_point = 'aipt',

		_field_id_function_constant_value = 'fncv',
		_field_id_editablepropertybaseforceflags = 'fnfc',

		_field_id_bspf_unknown_bsp = 'bspf',
		_field_id_usqd_unknown_squad = 'usqd',
		_field_id_gnvb_unknown_graph_node = 'gnvb',
		_field_id_sky_lighting = 'skyl',

		_field_id_malleablepropertybasefloat = 'mpfi',
		_field_id_malleablepropertybaseshort = 'mpsh',
		_field_id_malleablepropertybaseangle = 'mpai',

		_field_id_ascii = 'asci',
		_field_id_lflg = 'lflg',
		_field_id_allg = 'allg',
		_field_id_bspX = 'bsp*',
		_field_id_bspY = 'bsp!',
		_field_id_rede = 'rede',
		_field_id_cflt = 'cflt',
		_field_id_filx = 'filx',
		_field_id_auds = 'auds',
		_field_id_cseb = 'cseb',
		_field_id_creb = 'creb',

		_field_id_prof = 'prof',
		_field_id_mply = 'mply',
		_field_id_pd64 = 'pd64',
		_field_id_pd32 = 'pd32',
		_field_id_align = 'algn',

		// halo 2 structure
		_field_id_sobj = 'sobj',
		_field_id_sper = 'sper',
		_field_id_sct3 = 'sct3',
		_field_id_ssct = 'ssct',
		_field_id_sct2 = 'sct2',
		_field_id_swpt = 'swpt',
		_field_id_sunt = 'sunt',
		_field_id_sust = 'sust',
		_field_id_sdvt = 'sdvt',
		_field_id_slit = 'slit',
		_field_id_seqt = 'seqt',
		_field_id__sc_ = '#sc#',
		_field_id_MAPP = 'MAPP',
		_field_id_BLOK = 'BLOK',
		_field_id_SCFN = 'SCFN',
		_field_id_CLFN = 'CLFN',
		_field_id_particle_property_scalar = 'PRPS',
		_field_id_particle_property_color = 'PRPC',
		_field_id_uncs = 'uncs',
		_field_id_usas = 'usas',
		_field_id_uHnd = 'uHnd',
		_field_id_ubms = 'ubms',
		_field_id_cmtb = 'cmtb',
		_field_id_unknown = '!@#$',
		_field_id_ulYc = 'ulYc',
		_field_id_blod = 'blod',
		_field_id_chgr = 'chgr',
		_field_id_chfl = 'chfl',
		_field_id_chdd = 'chdd',
		_field_id_chsn = 'chsn',
		_field_id_chpy = 'chpy',
		_field_id_nbmi = 'nbmi',
		_field_id_clpr = 'clpr',
		_field_id_cbsp = 'cbsp',
		_field_id_DREZ = 'DREZ',
		_field_id_smht = 'smht',
		_field_id_sdst = 'sdst',
		_field_id_sctt = 'sctt',
		_field_id_slft = 'slft',
		_field_id_prli = 'prli',
		_field_id_scli = 'scli',
		_field_id_amli = 'amli',
		_field_id_lmsh = 'lmsh',
		_field_id_cnvs = 'cnvs',
		_field_id_ires = 'ires',
		_field_id_irem = 'irem',
		_field_id_MTLO = 'MTLO',
		_field_id_nhgs = 'nhgs',
		_field_id_aaim = 'aaim',
		_field_id_apds = 'apds',
		_field_id_qoSS = 'qoSS',
		_field_id_MAgr = 'MAgr',
		_field_id_ANII = 'ANII',
		_field_id_ATSS = 'ATSS',
		_field_id_MAgc = 'MAgc',
		_field_id_MArt = 'MArt',
		_field_id_masd = 'masd',
		_field_id_SFDS = 'SFDS',
		_field_id_RFDS = 'RFDS',
		_field_id_RBDS = 'RBDS',
		_field_id_dsfx = 'dsfx',
		_field_id_SINF = 'SINF',
		_field_id_SECT = 'SECT',
		_field_id_mphp = 'mphp',
		_field_id_msst = 'msst',
		_field_id_PDAT = 'PDAT',
		_field_id_ISQI = 'ISQI',
		_field_id_gapu = 'gapu',
		_field_id_hwis = 'hwis',
		_field_id_hwsd = 'hwsd',
		_field_id_hwef = 'hwef',
		_field_id_nhd2 = 'nhd2',
		_field_id_sebs = 'sebs',
		_field_id_csbs = 'csbs',
		_field_id_sd2s = 'sd2s',
		_field_id_avlb = 'avlb',
		_field_id_shtb = 'shtb',
		_field_id_GPUR = 'GPUR',
		_field_id_GPUS = 'GPUS',
		_field_id_scms = 'scms',
		_field_id_schs = 'schs',
		_field_id_svis = 'svis',
		_field_id_igri = 'igri',
		_field_id_spdf = 'spdf',
		_field_id_rnli = 'rnli',
		_field_id_ntor = 'ntor',
		_field_id_sszd = 'sszd',
		_field_id_spl1 = 'spl1',
		_field_id_ssfx = 'ssfx',
		_field_id_plsn = 'plsn',
		_field_id_slpp = 'slpp',
		_field_id_snsc = 'snsc',
		_field_id_snpr = 'snpr',
		_field_id_srpr = 'srpr',
		_field_id_sngl = 'sngl',
		_field_id_trcv = 'trcv',
		_field_id_HVPH = 'HVPH',
		_field_id_mdps = 'mdps',
		_field_id_easd = 'easd',
		_field_id_wtsf = 'wtsf',
		_field_id_wSiS = 'wSiS',
		_field_id_wItS = 'wItS',
		_field_id_wtas = 'wtas',
		_field_id_wtcs = 'wtcs',
		_field_id_wbde = 'wbde',
		_field_id_WNDM = 'WNDM',

		_field_id_bitmap_show = 'bshw',				// bitmap_show_dialog
		_field_id_whis = 'whis',					// hud_interface_show_dialog
		_field_id_ghis = 'ghis',					// hud_interface_show_dialog
		_field_id_uhis = 'uhis',					// hud_interface_show_dialog
		_field_id_sply = 'sply',					// sound_playback_dialog
		_field_id_function_editor = 'fned',			// c_field_function_dialog
		_field_id_shader_template = 'tmpl',			// c_tag_template_field_dialog
		_field_id_high_level_model_tag = 'hlmt',	// c_model_bulk_import_dialog
		_field_id_edit = 'edit',					// c_editor_tag_command_dialog
		_field_id_unknown_player = 'mkpl',			// c_marker_play_dialog
		_field_id_biqu = 'biqu',					// c_biquad_graph_dialog
		_field_id_sound_player = 'snpl',			// c_sound_permutation_dialog

	};

	BCS_DEBUG_API const char* field_id_to_string(e_field_id field);
}
