#pragma once

namespace blofeld
{



	constexpr unsigned long AI_DIALOGUE_GLOBALS_TAG = 'adlg';
	extern s_tag_group ai_dialogue_globals_group; // ai_dialogue_globals_block


	extern s_tag_block_definition ai_dialogue_globals_block;
	extern s_tag_block_definition default_stimulus_suppressor_block;
	extern s_tag_struct_definition default_stimulus_suppressor_block_struct_definition; // default_stimulus_suppressor_block
	extern s_tag_block_definition vocalization_definitions_block;
	extern s_tag_struct_definition vocalization_definitions_block_struct_definition; // vocalization_definitions_block
	extern s_tag_block_definition response_block;
	extern s_tag_struct_definition response_block_struct_definition; // response_block
	extern s_tag_block_definition vocalization_patterns_block;
	extern s_tag_struct_definition vocalization_patterns_block_struct_definition; // vocalization_patterns_block
	extern s_tag_block_definition dialogue_data_block;
	extern s_tag_struct_definition dialogue_data_block_struct_definition; // dialogue_data_block
	extern s_tag_block_definition involuntary_data_block;
	extern s_tag_struct_definition involuntary_data_block_struct_definition; // involuntary_data_block
	extern s_tag_block_definition predicted_data_block;
	extern s_tag_struct_definition predicted_data_block_struct_definition; // predicted_data_block

	extern s_tag_struct_definition ai_dialogue_globals_struct_definition; // tag group

	extern s_string_list_definition dialogue_names_enum;
	extern s_string_list_definition response_flags;
	extern s_string_list_definition response_type_enum;
	extern s_string_list_definition glance_type_enum;
	extern s_string_list_definition priority_enum;
	extern s_string_list_definition vocalization_flags_definition;
	extern s_string_list_definition perception_type_enum;
	extern s_string_list_definition combat_status_enum;
	extern s_string_list_definition dialogue_animation_enum;
	extern s_string_list_definition dialogue_emotion_enum;
	extern s_string_list_definition pattern_flags;
	extern s_string_list_definition speaker_type_enum;
	extern s_string_list_definition speaker_behavior_enum;
	extern s_string_list_definition hostility_enum;
	extern s_string_list_definition damage_enum;
	extern s_string_list_definition game_type_enum;
	extern s_string_list_definition danger_enum;
	extern s_string_list_definition dialogue_object_types_enum;
	extern s_string_list_definition spatial_relation_enum;
	extern s_string_list_definition dialogue_condition_flags;

	extern s_tag_reference_definition global_dialogue_reference;



} // namespace blofeld

