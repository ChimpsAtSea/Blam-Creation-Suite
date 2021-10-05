#pragma once

namespace blofeld
{
	constexpr unsigned long CHUD_WIDGET_ANIMATION_DATA_TAG = 'wadt';
	constexpr unsigned long CHUD_WIDGET_PLACEMENT_DATA_TAG = 'wpdt';
	constexpr unsigned long CHUD_WIDGET_RENDER_DATA_TAG = 'wrdt';
	constexpr unsigned long CHUD_WIDGET_STATE_DATA_TAG = 'wsdt';
	constexpr unsigned long CHUD_WIDGET_DATASOURCE_TAG = 'wdst';

	extern s_tag_block_definition wsdt_data_block;
	extern s_tag_struct_definition wsdt_data_block_struct_definition;

	// animation data
	extern s_tag_group chud_widget_animation_data_group;
	extern s_tag_struct_definition wadt_struct_definition_struct_definition;
	extern s_tag_block_definition wadt_block;
	extern s_tag_struct_definition wadt_block_struct_definition;
	extern s_tag_block_definition wadt_data_block;
	extern s_tag_struct_definition wadt_data_block_struct_definition;
	extern s_tag_reference_definition chud_widget_animation_data_reference;
	extern s_tag_reference_definition wadt_animation_reference;

	// placement data
	extern s_tag_group chud_widget_placement_data_group;
	extern s_tag_struct_definition wpdt_struct_definition_struct_definition;
	extern s_tag_block_definition wpdt_block;
	extern s_tag_struct_definition wpdt_block_struct_definition;
	extern s_tag_block_definition wpdt_data_block;
	extern s_tag_struct_definition wpdt_data_block_struct_definition;
	extern s_tag_reference_definition chud_widget_placement_data_reference;

	// render data
	extern s_tag_group chud_widget_render_data_group;
	extern s_tag_struct_definition wrdt_struct_definition_struct_definition;
	extern s_tag_block_definition wrdt_block;
	extern s_tag_struct_definition wrdt_block_struct_definition;
	extern s_tag_block_definition wrdt_data_block;
	extern s_tag_struct_definition wrdt_data_block_struct_definition;
	extern s_tag_reference_definition chud_widget_render_data_reference;

	// state data
	extern s_tag_group chud_widget_state_data_group;
	extern s_tag_struct_definition wsdt_struct_definition_struct_definition;
	extern s_tag_block_definition wsdt_block;
	extern s_tag_struct_definition wsdt_block_struct_definition;
	extern s_tag_block_definition wsdt_state_data_block;
	extern s_tag_struct_definition wsdt_state_data_block_struct_definition;
	extern s_tag_block_definition wsdt_states_block;
	extern s_tag_struct_definition wsdt_states_block_struct_definition;
	extern s_tag_block_definition wsdt_triggers_block;
	extern s_tag_struct_definition wsdt_triggers_block_struct_definition;
	extern s_tag_reference_definition chud_widget_state_data_reference;

	// strings

	extern s_string_list_definition wadt_flags_definition;
	extern s_string_list_definition wadt_function_enum_definition;

	extern s_string_list_definition wpdt_unknown_flags_definition;
	extern s_string_list_definition wpdt_anchor_enum_definition;

	extern s_string_list_definition wrdt_shader_index_enum_definition;
	extern s_string_list_definition wrdt_output_color_enum_definition;
	extern s_string_list_definition wrdt_output_scalar_enum_definition;
}

