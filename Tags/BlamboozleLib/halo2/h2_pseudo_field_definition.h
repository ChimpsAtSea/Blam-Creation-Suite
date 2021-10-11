#pragma once

class c_h2_tag_group_definition;
class c_h2_pseudo_array_definition;
class c_h2_tag_reference_definition;
class c_h2_string_list_definition;
class c_h2_pseudo_struct_definition;

enum e_h2_field_id_type
{
	// confirmed from Halo 2 Guerilla
	_h2_field_id_bitmap_show_dialog = 'bshw',
	_h2_field_id_hud_interface_show_weapon_dialog = 'whis',
	_h2_field_id_hud_interface_show_grenade_dialog = 'ghis',
	_h2_field_id_hud_interface_show_unit_dialog = 'uhis',
	_h2_field_id_sound_playback_dialog = 'sply',
	_h2_field_id_c_field_function_dialog = 'fned',
	_h2_field_id_c_tag_template_field_dialog = 'tmpl',
	_h2_field_id_c_model_bulk_import_dialog = 'hlmt',
	_h2_field_id_c_editor_tag_command_dialog = 'edit',
	_h2_field_id_c_marker_play_dialog = 'mkpl',
	_h2_field_id_c_biquad_graph_dialog = 'biqu',
	_h2_field_id_c_sound_permutation_dialog = 'snpl',

	// discovered in Halo 2 Guerilla
	_h2_field_id_c_string_editor_base = 'sted',

	// unconfirmed
	_h2_field_id_scenario_environment_function = 'envf',
	_h2_field_id_squad_template = 'sqdt',
	_h2_field_id_halo_script_block = 'hsbl',

	_h2_field_id_filter = 'filt',
	_h2_field_id_type = 'type',
	_h2_field_id_name = 'name',
	_h2_field_id_object_editor = 'obed',
	_h2_field_id_point = 'poin',
	_h2_field_id_orientation = 'orie',
	_h2_field_id_scale = 'scal',
	_h2_field_id_hide = 'ugly',
	_h2_field_id_enum = 'enum',
	_h2_field_id_manual_bsp_flags = 'mbsp',
	_h2_field_id_object_id = 'obj#',
	_h2_field_id_object_variant = 'vari',
	_h2_field_id_pathfinding = 'path',
	_h2_field_id_lflg = 'lflg',
	_h2_field_id_allg = 'allg',

	_h2_field_id_hide_begin = 'hide',
	_h2_field_id_hide_end = 'edih',

	_h2_field_id_function_input_scalar = 'fnin',
	_h2_field_id_function_input_range = 'fnir',
	_h2_field_id_function_output_modifier_input = 'fnom',
	_h2_field_id_function_unknown = 'fn**',
	_h2_field_id_function_output_modifier = 'fnop',
	_h2_field_id_cfpf = 'cfpf',
	_h2_field_id_cflt = 'cflt',
	_h2_field_id_sort = 'sort',
	_h2_field_id_camera_matrix_editor = 'cmed',
	_h2_field_id_align = 'algn',
	_h2_field_id_unknown_ugh = 'ugh@',
	_h2_field_id_wide = 'wide',
	_h2_field_id_decibels = '+dB+',
	_h2_field_id_filx = 'filx',
	_h2_field_id_cents = 'cent',
	_h2_field_id_auds = 'auds',
	
	
};

struct s_h2_tag_field
{
	e_h2_field_type field_type;
	ptr32 name_address;
	ptr32 definition_address;
	e_h2_field_id_type field_id_type;
};

class c_h2_pseudo_field_definition
{
public:
	const char* name;
	e_h2_pseudo_field_type field_type;
	const s_h2_tag_field* field;

	c_h2_tag_block_definition* block_definition;
	c_h2_tag_reference_definition* tag_reference_definition;
	c_h2_pseudo_struct_definition* struct_definition;
	c_h2_pseudo_array_definition* pseudo_array_definition;
	c_h2_string_list_definition* string_list_definition;
	
	unsigned long long padding;
	unsigned long long skip_length;
	const char* explanation;

	c_h2_pseudo_field_definition(const char* guerilla_data, const s_h2_tag_field& field);
	c_h2_pseudo_field_definition(c_h2_pseudo_struct_definition& pseudo_struct_definition);
};
