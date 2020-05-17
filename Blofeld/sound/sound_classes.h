#pragma once

namespace blofeld
{

	extern const char* sound_class_internal_flags_definition_strings[];
	extern s_string_list_definition sound_class_internal_flags_definition;
	extern const char* sound_class_external_flags_definition_strings[];
	extern s_string_list_definition sound_class_external_flags_definition;
	extern const char* sound_class_cache_miss_mode_definition_strings[];
	extern s_string_list_definition sound_class_cache_miss_mode_definition;
	extern const char* sound_class_stereo_playback_definition_strings[];
	extern s_string_list_definition sound_class_stereo_playback_definition;
	extern const char* sound_class_acoustics_string_definition_strings[];
	extern s_string_list_definition sound_class_acoustics_string_definition;
	extern const char* sound_class_suppress_spatialization_string_defintion_strings[];
	extern s_string_list_definition sound_class_suppress_spatialization_string_defintion;

	constexpr unsigned long SOUND_CLASSES_TAG = 'sncl';

	extern s_tag_struct sound_classes_block_struct;
	extern s_tag_block_definition sound_classes_block;
	extern s_tag_group sound_classes_group;

	extern s_tag_struct sound_class_block_block_struct;
	extern s_tag_block_definition sound_class_block_block;


} // namespace blofeld

