#pragma once

namespace blofeld
{



	constexpr unsigned long DEVICE_CONTROL_TAG = 'ctrl';
	extern s_tag_group device_control_group; // device_control_block

	constexpr unsigned long DEVICE_TAG = 'devi';
	extern s_tag_group device_group; // device_block

	constexpr unsigned long DEVICE_DISPENSER_TAG = 'dspn';
	extern s_tag_group device_dispenser_group; // device_dispenser_block

	constexpr unsigned long DEVICE_MACHINE_TAG = 'mach';
	extern s_tag_group device_machine_group; // device_machine_block

	constexpr unsigned long DEVICE_TERMINAL_TAG = 'term';
	extern s_tag_group device_terminal_group; // device_terminal_block


	extern s_tag_block_definition device_control_block;
	extern s_tag_block_definition device_block;
	extern s_tag_block_definition device_dispenser_block;
	extern s_tag_block_definition device_machine_block;
	extern s_tag_block_definition device_terminal_block;
	extern s_tag_block_definition terminal_page_block_definition_block;
	extern s_tag_struct_definition terminal_page_block_definition_block_struct_definition; // terminal_page_block_definition_block

	extern s_tag_struct_definition device_control_struct_definition; // tag group
	extern s_tag_struct_definition device_struct_definition; // tag group
	extern s_tag_struct_definition device_dispenser_struct_definition; // tag group
	extern s_tag_struct_definition device_machine_struct_definition; // tag group
	extern s_tag_struct_definition device_terminal_struct_definition; // tag group

	extern s_string_list_definition device_definition_flags;
	extern s_string_list_definition device_lightmap_flags;
	extern s_string_list_definition machine_types;
	extern s_string_list_definition machine_flags;
	extern s_string_list_definition machine_collision_responses;
	extern s_string_list_definition machine_pathfinding_policy_enum;
	extern s_string_list_definition control_types;
	extern s_string_list_definition control_triggers;
	extern s_string_list_definition teamUseRestrictionEnum;
	extern s_string_list_definition DispenserDefinitionFlags;
	extern s_string_list_definition DispenserDefinitionTrigger;



} // namespace blofeld

