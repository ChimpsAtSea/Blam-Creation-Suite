#pragma once

namespace blofeld
{

	extern const char* dialogue_names_enum_strings[];
	extern s_string_list_definition dialogue_names_enum;
	extern const char* response_flags_strings[];
	extern s_string_list_definition response_flags;
	extern const char* response_type_enum_strings[];
	extern s_string_list_definition response_type_enum;
	extern const char* glance_type_enum_strings[];
	extern s_string_list_definition glance_type_enum;
	extern const char* priority_enum_strings[];
	extern s_string_list_definition priority_enum;
	extern const char* vocalization_flags_definition_strings[];
	extern s_string_list_definition vocalization_flags_definition;
	extern const char* perception_type_enum_strings[];
	extern s_string_list_definition perception_type_enum;
	extern const char* combat_status_enum_strings[];
	extern s_string_list_definition combat_status_enum;
	extern const char* dialogue_animation_enum_strings[];
	extern s_string_list_definition dialogue_animation_enum;
	extern const char* dialogue_emotion_enum_strings[];
	extern s_string_list_definition dialogue_emotion_enum;
	extern const char* pattern_flags_strings[];
	extern s_string_list_definition pattern_flags;
	extern const char* speaker_type_enum_strings[];
	extern s_string_list_definition speaker_type_enum;
	extern const char* speaker_behavior_enum_strings[];
	extern s_string_list_definition speaker_behavior_enum;
	extern const char* hostility_enum_strings[];
	extern s_string_list_definition hostility_enum;
	extern const char* damage_enum_strings[];
	extern s_string_list_definition damage_enum;
	extern const char* game_type_enum_strings[];
	extern s_string_list_definition game_type_enum;
	extern const char* danger_enum_strings[];
	extern s_string_list_definition danger_enum;
	extern const char* dialogue_object_types_enum_strings[];
	extern s_string_list_definition dialogue_object_types_enum;
	extern const char* spatial_relation_enum_strings[];
	extern s_string_list_definition spatial_relation_enum;
	extern const char* dialogue_condition_flags_strings[];
	extern s_string_list_definition dialogue_condition_flags;

	constexpr unsigned long AI_DIALOGUE_GLOBALS_TAG = 'adlg';

	extern s_tag_group ai_dialogue_globals_group;

	extern s_tag_block_definition ai_dialogue_globals_block_block;
	extern s_tag_struct default_stimulus_suppressor_block_block_struct;
	extern s_tag_block_definition default_stimulus_suppressor_block_block;
	extern s_tag_struct vocalization_definitions_block_block_struct;
	extern s_tag_block_definition vocalization_definitions_block_block;
	extern s_tag_struct response_block_block_struct;
	extern s_tag_block_definition response_block_block;
	extern s_tag_struct vocalization_patterns_block_block_struct;
	extern s_tag_block_definition vocalization_patterns_block_block;
	extern s_tag_struct dialogue_data_block_block_struct;
	extern s_tag_block_definition dialogue_data_block_block;
	extern s_tag_struct involuntary_data_block_block_struct;
	extern s_tag_block_definition involuntary_data_block_block;
	extern s_tag_struct predicted_data_block_block_struct;
	extern s_tag_block_definition predicted_data_block_block;

	extern s_tag_struct ai_dialogue_globals_struct_definition_struct_definition; // tag group

} // namespace blofeld

