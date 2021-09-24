#pragma once

namespace blofeld
{



	constexpr unsigned long SOUND_CLASSES_TAG = 'sncl';
	extern s_tag_group sound_classes_group; // sound_classes_block
	extern s_tag_block_definition sound_classes_block;
	extern s_tag_struct_definition sound_classes_block_struct_definition; // sound_classes_block


	extern s_tag_block_definition sound_class_block;
	extern s_tag_struct_definition sound_class_block_struct_definition; // sound_class_block


	extern s_string_list_definition sound_class_internal_flags_definition;
	extern s_string_list_definition sound_class_external_flags_definition;
	extern s_string_list_definition sound_class_cache_miss_mode_definition;
	extern s_string_list_definition sound_class_stereo_playback_definition;
	extern s_string_list_definition sound_class_acoustics_string_definition;
	extern s_string_list_definition sound_class_suppress_spatialization_string_defintion;



} // namespace blofeld

