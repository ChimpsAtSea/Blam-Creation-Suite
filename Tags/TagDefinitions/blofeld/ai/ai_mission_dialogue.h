#pragma once

namespace blofeld
{

	constexpr unsigned long AI_MISSION_DIALOGUE_TAG = 'mdlg';

	extern s_tag_group ai_mission_dialogue_group;

	extern s_tag_struct_definition mission_dialogue_variants_block_block_struct;
	extern s_tag_block_definition mission_dialogue_variants_block_block;
	extern s_tag_struct_definition mission_dialogue_lines_block_block_struct;
	extern s_tag_block_definition mission_dialogue_lines_block_block;
	extern s_tag_block_definition ai_mission_dialogue_block_block;
	extern s_tag_struct_definition ai_scene_trigger_block_block_struct;
	extern s_tag_block_definition ai_scene_trigger_block_block;
	extern s_tag_struct_definition ai_scene_role_variants_block_block_struct;
	extern s_tag_block_definition ai_scene_role_variants_block_block;
	extern s_tag_struct_definition ai_scene_role_block_block_struct;
	extern s_tag_block_definition ai_scene_role_block_block;
	extern s_tag_struct_definition ai_scene_block_block_struct;
	extern s_tag_block_definition ai_scene_block_block;
	extern s_tag_struct_definition ai_scenario_mission_dialogue_block_block_struct;
	extern s_tag_block_definition ai_scenario_mission_dialogue_block_block;

	extern s_tag_struct_definition ai_mission_dialogue_struct_definition_struct_definition; // tag group

	extern const char* role_group_enum_strings[];
	extern s_string_list_definition role_group_enum;
	extern const char* scene_flags_strings[];
	extern s_string_list_definition scene_flags;

} // namespace blofeld

