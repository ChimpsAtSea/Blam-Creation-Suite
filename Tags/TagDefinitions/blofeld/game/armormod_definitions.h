#pragma once

namespace blofeld
{



	constexpr unsigned long ARMORMOD_GLOBALS_TAG = 'armg';
	extern s_tag_group armormod_globals_group; // armormod_globals_block


	extern s_tag_block_definition armormod_globals_block;
	extern s_tag_block_definition aural_enhancement_audio_settings_block;
	extern s_tag_struct_definition aural_enhancement_audio_settings_block_struct_definition; // aural_enhancement_audio_settings_block

	extern s_tag_struct_definition armormod_globals_struct_definition; // tag group

	extern c_versioned_string_list stealthFlagsDefs_strings;
	extern s_string_list_definition stealthFlagsDefs;



} // namespace blofeld

