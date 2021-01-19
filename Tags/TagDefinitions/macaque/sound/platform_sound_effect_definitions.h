#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long SOUND_EFFECT_COLLECTION_TAG = 'sfx+';
	extern s_tag_group sound_effect_collection_group; // sound_effect_collection_block
	extern s_tag_block_definition sound_effect_collection_block;
	extern s_tag_struct_definition sound_effect_collection; // sound_effect_collection_block


	extern s_tag_block_definition platform_sound_playback_block;
	extern s_tag_struct_definition platform_sound_playback_block_struct_definition; // platform_sound_playback_block
	extern s_tag_block_definition platform_sound_playback_lowpass_block;
	extern s_tag_struct_definition platform_sound_playback_lowpass_block_struct_definition; // platform_sound_playback_lowpass_block
	extern s_tag_block_definition platform_sound_playback_component_block;
	extern s_tag_struct_definition platform_sound_playback_component_block_struct_definition; // platform_sound_playback_component_block

	extern s_tag_struct_definition platform_sound_playback_struct;

	extern c_versioned_string_list platform_sound_playback_component_flags_strings;
	extern s_string_list_definition platform_sound_playback_component_flags;
	extern c_versioned_string_list platform_sound_effect_flags_definition_strings;
	extern s_string_list_definition platform_sound_effect_flags_definition;

} // namespace macaque

} // namespace blofeld

