#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long CINEMATIC_TAG = 'cine';
	extern s_tag_group cinematic_group; // cinematic_block
	extern s_tag_block_definition cinematic_block;
	extern s_tag_struct_definition cinematic; // cinematic_block

	constexpr unsigned long CINEMATIC_SCENE_TAG = 'cisc';
	extern s_tag_group cinematic_scene_group; // cinematic_scene_block

	constexpr unsigned long CINEMATIC_SCENE_DATA_TAG = 'cisd';
	extern s_tag_group cinematic_scene_data_group; // cinematic_scene_data_block

	constexpr unsigned long CINEMATIC_TRANSITION_TAG = 'citr';
	extern s_tag_group cinematic_transition_group; // cinematic_transition_block
	extern s_tag_block_definition cinematic_transition_block;
	extern s_tag_struct_definition cinematic_transition; // cinematic_transition_block


	extern s_tag_block_definition cinematic_scene_block;
	extern s_tag_block_definition cinematic_scene_data_block;
	extern s_tag_block_definition cinematic_scene_reference_block;
	extern s_tag_struct_definition cinematic_scene_reference_block_struct_definition; // cinematic_scene_reference_block
	extern s_tag_block_definition cinematic_shot_playback_data_block;
	extern s_tag_struct_definition cinematic_shot_playback_data_block_struct_definition; // cinematic_shot_playback_data_block
	extern s_tag_block_definition cinematic_scene_object_block;
	extern s_tag_struct_definition cinematic_scene_object_block_struct_definition; // cinematic_scene_object_block
	extern s_tag_block_definition scene_object_attachment_block;
	extern s_tag_struct_definition scene_object_attachment_block_struct_definition; // scene_object_attachment_block
	extern s_tag_block_definition cinematic_shot_block;
	extern s_tag_struct_definition cinematic_shot_block_struct_definition; // cinematic_shot_block
	extern s_tag_block_definition cinematic_shot_lighting_block;
	extern s_tag_struct_definition cinematic_shot_lighting_block_struct_definition; // cinematic_shot_lighting_block
	extern s_tag_block_definition cinematic_shot_clip_block;
	extern s_tag_struct_definition cinematic_shot_clip_block_struct_definition; // cinematic_shot_clip_block
	extern s_tag_block_definition cinematic_shot_clip_subject_block;
	extern s_tag_struct_definition cinematic_shot_clip_subject_block_struct_definition; // cinematic_shot_clip_subject_block
	extern s_tag_block_definition cinematic_shot_music_block;
	extern s_tag_struct_definition cinematic_shot_music_block_struct_definition; // cinematic_shot_music_block
	extern s_tag_block_definition cinematic_shot_object_function_block;
	extern s_tag_struct_definition cinematic_shot_object_function_block_struct_definition; // cinematic_shot_object_function_block
	extern s_tag_block_definition cinematic_shot_object_function_keyframe_block;
	extern s_tag_struct_definition cinematic_shot_object_function_keyframe_block_struct_definition; // cinematic_shot_object_function_keyframe_block
	extern s_tag_block_definition cinematic_shot_screen_effect_block;
	extern s_tag_struct_definition cinematic_shot_screen_effect_block_struct_definition; // cinematic_shot_screen_effect_block
	extern s_tag_block_definition cinematic_shot_user_input_constraints_block;
	extern s_tag_struct_definition cinematic_shot_user_input_constraints_block_struct_definition; // cinematic_shot_user_input_constraints_block
	extern s_tag_block_definition cinematicShotTextureMovieBlock_block;
	extern s_tag_struct_definition cinematicShotTextureMovieBlock_block_struct_definition; // cinematicShotTextureMovieBlock_block
	extern s_tag_block_definition cinematicStructureLightingBlock_block;
	extern s_tag_struct_definition cinematicStructureLightingBlock_block_struct_definition; // cinematicStructureLightingBlock_block
	extern s_tag_block_definition cinematicSceneDataObjectBlock_block;
	extern s_tag_block_definition cinematicDataShotBlock_block;
	extern s_tag_struct_definition cinematicDataShotBlock_block_struct_definition; // cinematicDataShotBlock_block
	extern s_tag_block_definition cinematic_shot_dialogue_block;
	extern s_tag_struct_definition cinematic_shot_dialogue_block_struct_definition; // cinematic_shot_dialogue_block
	extern s_tag_block_definition cinematic_shot_effect_block;
	extern s_tag_struct_definition cinematic_shot_effect_block_struct_definition; // cinematic_shot_effect_block
	extern s_tag_block_definition cinematic_shot_custom_script_block;
	extern s_tag_struct_definition cinematic_shot_custom_script_block_struct_definition; // cinematic_shot_custom_script_block
	extern s_tag_block_definition cinematic_shot_frame_block;
	extern s_tag_struct_definition cinematic_shot_frame_block_struct_definition; // cinematic_shot_frame_block
	extern s_tag_block_definition cinematic_shot_frame_dynamic_block;
	extern s_tag_struct_definition cinematic_shot_frame_dynamic_block_struct_definition; // cinematic_shot_frame_dynamic_block
	extern s_tag_block_definition cinematic_shot_frame_constant_block;
	extern s_tag_struct_definition cinematic_shot_frame_constant_block_struct_definition; // cinematic_shot_frame_constant_block
	extern s_tag_block_definition cinematic_shot_extra_camera_block;
	extern s_tag_struct_definition cinematic_shot_extra_camera_block_struct_definition; // cinematic_shot_extra_camera_block
	extern s_tag_block_definition cinematic_extra_camera_shot_block;
	extern s_tag_struct_definition cinematic_extra_camera_shot_block_struct_definition; // cinematic_extra_camera_shot_block
	extern s_tag_block_definition cinematic_extra_camera_frame_block;
	extern s_tag_struct_definition cinematic_extra_camera_frame_block_struct_definition; // cinematic_extra_camera_frame_block
	extern s_tag_block_definition cinematic_transition_global_gain_block;
	extern s_tag_struct_definition cinematic_transition_global_gain_block_struct_definition; // cinematic_transition_global_gain_block
	extern s_tag_block_definition cinematic_transition_sound_class_gain_block;
	extern s_tag_struct_definition cinematic_transition_sound_class_gain_block_struct_definition; // cinematic_transition_sound_class_gain_block
	extern s_tag_block_definition cinematic_transition_sound_reference_block;
	extern s_tag_struct_definition cinematic_transition_sound_reference_block_struct_definition; // cinematic_transition_sound_reference_block
	extern s_tag_block_definition cinematic_transition_looping_sound_reference_block;
	extern s_tag_struct_definition cinematic_transition_looping_sound_reference_block_struct_definition; // cinematic_transition_looping_sound_reference_block
	extern s_tag_block_definition cinematic_transition_looping_sound_state_block;
	extern s_tag_struct_definition cinematic_transition_looping_sound_state_block_struct_definition; // cinematic_transition_looping_sound_state_block
	extern s_tag_block_definition cinematics_globals_block;
	extern s_tag_struct_definition cinematics_globals_block_struct_definition; // cinematics_globals_block
	extern s_tag_block_definition cinematic_characters_block;
	extern s_tag_struct_definition cinematic_characters_block_struct_definition; // cinematic_characters_block
	extern s_tag_block_definition scenario_cinematics_block;
	extern s_tag_struct_definition scenario_cinematics_block_struct_definition; // scenario_cinematics_block
	extern s_tag_block_definition scenario_cutscene_title_block;

	extern s_tag_struct_definition g_cinematicShotFlagArray_array_struct_definition;
	extern s_tag_array_definition g_cinematicShotFlagArray_array;
	extern s_tag_struct_definition cinematic_scene_struct_definition; // tag group
	extern s_tag_struct_definition cinematic_scene_data_struct_definition; // tag group
	extern s_tag_struct_definition cinematic_playback_data_block;
	extern s_tag_struct_definition scenario_and_zone_set_struct;
	extern s_tag_struct_definition cinematic_custom_script_block;
	extern s_tag_struct_definition cinematicSceneDataObjectBlock_struct;
	extern s_tag_struct_definition camera_frame_struct;
	extern s_tag_struct_definition camera_frame_dynamic_struct;
	extern s_tag_struct_definition camera_frame_constant_struct;
	extern s_tag_struct_definition cinematic_transition_element_block;
	extern s_tag_struct_definition cinematic_transition_global_fade_block;
	extern s_tag_struct_definition scenario_cutscene_title_struct;

	extern c_versioned_string_list scenario_cutscene_camera_flags_strings;
	extern s_string_list_definition scenario_cutscene_camera_flags;
	extern c_versioned_string_list scenario_cutscene_camera_types_strings;
	extern s_string_list_definition scenario_cutscene_camera_types;
	extern c_versioned_string_list text_justification_enum_definition_strings;
	extern s_string_list_definition text_justification_enum_definition;
	extern c_versioned_string_list text_vertical_justification_enum_definition_strings;
	extern s_string_list_definition text_vertical_justification_enum_definition;
	extern c_versioned_string_list cinematic_channel_type_enum_strings;
	extern s_string_list_definition cinematic_channel_type_enum;
	extern c_versioned_string_list shot_flags_definition_strings;
	extern s_string_list_definition shot_flags_definition;
	extern c_versioned_string_list cinematic_shot_lighting_flags_definition_strings;
	extern s_string_list_definition cinematic_shot_lighting_flags_definition;
	extern c_versioned_string_list scene_object_flags_strings;
	extern s_string_list_definition scene_object_flags;
	extern c_versioned_string_list cinematic_coop_type_flags_strings;
	extern s_string_list_definition cinematic_coop_type_flags;
	extern c_versioned_string_list scene_object_attachment_flags_strings;
	extern s_string_list_definition scene_object_attachment_flags;
	extern c_versioned_string_list music_flags_enum_strings;
	extern s_string_list_definition music_flags_enum;
	extern c_versioned_string_list textureMovieFlags_strings;
	extern s_string_list_definition textureMovieFlags;
	extern c_versioned_string_list cinematic_shot_effect_flags_strings;
	extern s_string_list_definition cinematic_shot_effect_flags;
	extern c_versioned_string_list sceneShotEffectState_strings;
	extern s_string_list_definition sceneShotEffectState;
	extern c_versioned_string_list cinematicShotScreenEffectFlags_strings;
	extern s_string_list_definition cinematicShotScreenEffectFlags;
	extern c_versioned_string_list cinematic_shot_object_function_flags_strings;
	extern s_string_list_definition cinematic_shot_object_function_flags;
	extern c_versioned_string_list cinematic_extra_camera_frame_flags_strings;
	extern s_string_list_definition cinematic_extra_camera_frame_flags;
	extern c_versioned_string_list cinematic_shot_custom_script_flags_strings;
	extern s_string_list_definition cinematic_shot_custom_script_flags;
	extern c_versioned_string_list sceneShotSettingsFlags_strings;
	extern s_string_list_definition sceneShotSettingsFlags;
	extern c_versioned_string_list scene_reset_object_lighting_enum_strings;
	extern s_string_list_definition scene_reset_object_lighting_enum;
	extern c_versioned_string_list cinematic_transition_looping_sound_alternate_flags_strings;
	extern s_string_list_definition cinematic_transition_looping_sound_alternate_flags;
	extern c_versioned_string_list cinematic_transition_looping_sound_layer_flags_strings;
	extern s_string_list_definition cinematic_transition_looping_sound_layer_flags;
	extern c_versioned_string_list cinematic_flags_strings;
	extern s_string_list_definition cinematic_flags;
	extern c_versioned_string_list scenario_cinematics_flags_strings;
	extern s_string_list_definition scenario_cinematics_flags;

} // namespace macaque

} // namespace blofeld

