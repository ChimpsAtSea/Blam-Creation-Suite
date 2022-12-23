#pragma once

namespace blofeld
{
	enum e_tag_field_custom_type
	{
		_tag_field_custom_type_null_type = -1,
		_tag_field_custom_type_unknown_type = 0,

		// tag value custom tool commands

		_tag_field_custom_type_bitmap_group = 'bshw', // bitmap_show_dialog
		_tag_field_custom_type_tool_command = 'ctcd',
		_tag_field_custom_type_tool_command_with_directory = 'tcwd',
		_tag_field_custom_type_import_particle_model_command = 'ipmi',
		_tag_field_custom_type_model_bulk_import_command = 'hlmt', // c_model_bulk_import_dialog
		_tag_field_custom_type_estimate_overdraw_command = 'eoci',

		// tag value custom function editors

		_tag_field_custom_type_function_editor = 'fned', // c_field_function_dialog

		// tag value custom

		_tag_field_custom_type_vertical_layout = 'vert',
		_tag_field_custom_type_horizontal_layout = 'horz',
		_tag_field_custom_type_group_begin = 'gro+',
		_tag_field_custom_type_group_end = 'gro-',
		_tag_field_custom_type_end_layout = 'lynd',
		_tag_field_custom_type_hide_group_begin = 'hide',
		_tag_field_custom_type_hide_group_end = 'edih',
		_tag_field_custom_type_filter_on_next_field = 'filt',
		_tag_field_custom_type_filter_on_next_field_folder = 'filx',
		_tag_field_custom_type_filter_on_next_field_both = 'fil*',
		_tag_field_custom_type_editor_command = 'edit', // c_editor_tag_command_dialog
		_tag_field_custom_type_tag_template_view_command = 'gcmd',
		_tag_field_custom_type_designer_zone_block_index_flags = 'bifs',
		_tag_field_custom_type_custom_button = 'cust',
		_tag_field_custom_type_field_group_begin = 'fgrb',
		_tag_field_custom_type_field_group_end = 'fgre',
		_tag_field_custom_type_sound_playback = 'snpl', // c_sound_permutation_dialog
		_tag_field_custom_type_sound_marker_playback = 'mkpl', // c_marker_play_dialog
		_tag_field_custom_type_tag_group_template = 'tmpl', // c_tag_template_field_dialog
		_tag_field_custom_type_cinematic_dynamic_light = 'cdlt',
		_tag_field_custom_type_cinematic_vmf_light = 'cvmf',
		_tag_field_custom_type_custom_chud_state_editor_block = 'cseb',
		_tag_field_custom_type_custom_chud_render_editor_block = 'creb',
		_tag_field_custom_type_marker_name_attribute = 'amkr',
		_tag_field_custom_type_matched_element_array = 'mela',
		_tag_field_custom_type_individual_field_preview_group_begin = 'ifp+',
		_tag_field_custom_type_individual_field_preview_group_end = 'ifp-',
		_tag_field_custom_type_custom_object_function_field = 'coff',
		_tag_field_custom_type_scenario_and_zone_set = 'szsi',
		_tag_field_custom_type_cinematic_playback = 'cnpb',
		_tag_field_custom_type_cinematic_playback_loop_scene = 'lpsc',
		_tag_field_custom_type_cinematic_playback_loop_shot = 'lpsh',
		_tag_field_custom_type_slider = 'sled',

		// unknown, seen on custom field type

		_tag_field_custom_type_unknown_object_editor = 'obed',
		_tag_field_custom_type_unknown_environment = 'envf',
		_tag_field_custom_type_unknown_pathfinding = 'path',
		_tag_field_custom_type_unknown_facing = 'cfpf',
		_tag_field_custom_type_unknown_lflg = 'lflg',
		_tag_field_custom_type_unknown_allg = 'allg',
		_tag_field_custom_type_unknown_camera_matrix_editor = 'cmed',

		// #todo used in Halo 1 and Halo 2

		_tag_field_custom_type_unknown_whis = 'whis',					// hud_interface_show_dialog
		_tag_field_custom_type_unknown_ghis = 'ghis',					// hud_interface_show_dialog
		_tag_field_custom_type_unknown_uhis = 'uhis',					// hud_interface_show_dialog
		_tag_field_custom_type_unknown_sply = 'sply',					// sound_playback_dialog
		_tag_field_custom_type_unknown_biqu = 'biqu',					// c_biquad_graph_dialog
	};
	BCS_SHARED const char* tag_field_custom_type_to_string(e_tag_field_custom_type tag_field_custom_type);
}
