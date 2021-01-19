#pragma once

namespace blofeld
{

namespace macaque
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

	extern c_versioned_string_list device_definition_flags_strings;
	extern s_string_list_definition device_definition_flags;
	extern c_versioned_string_list device_lightmap_flags_strings;
	extern s_string_list_definition device_lightmap_flags;
	extern c_versioned_string_list machine_types_strings;
	extern s_string_list_definition machine_types;
	extern c_versioned_string_list machine_flags_strings;
	extern s_string_list_definition machine_flags;
	extern c_versioned_string_list machine_collision_responses_strings;
	extern s_string_list_definition machine_collision_responses;
	extern c_versioned_string_list machine_pathfinding_policy_enum_strings;
	extern s_string_list_definition machine_pathfinding_policy_enum;
	extern c_versioned_string_list control_types_strings;
	extern s_string_list_definition control_types;
	extern c_versioned_string_list control_triggers_strings;
	extern s_string_list_definition control_triggers;
	extern c_versioned_string_list teamUseRestrictionEnum_strings;
	extern s_string_list_definition teamUseRestrictionEnum;
	extern c_versioned_string_list DispenserDefinitionFlags_strings;
	extern s_string_list_definition DispenserDefinitionFlags;
	extern c_versioned_string_list DispenserDefinitionTrigger_strings;
	extern s_string_list_definition DispenserDefinitionTrigger;

} // namespace macaque

} // namespace blofeld

