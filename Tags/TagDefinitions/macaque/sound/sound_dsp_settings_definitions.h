#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long SOUND_RADIO_SETTINGS_TAG = 'srad';
	extern s_tag_group sound_radio_settings_group; // sound_radio_settings_block
	extern s_tag_block_definition sound_radio_settings_block;
	extern s_tag_struct_definition sound_radio_settings; // sound_radio_settings_block


	extern s_tag_block_definition sound_equalizer_band_settings_block;
	extern s_tag_struct_definition sound_equalizer_band_settings_block_struct_definition; // sound_equalizer_band_settings_block

	extern s_tag_struct_definition global_sound_lowpass_block;
	extern s_tag_struct_definition global_sound_reverb_block;
	extern s_tag_struct_definition global_sound_look_up_table_distortion_block;
	extern s_tag_struct_definition global_sound_equalizer_block;

	extern c_versioned_string_list look_up_table_flags_definition_strings;
	extern s_string_list_definition look_up_table_flags_definition;
	extern c_versioned_string_list equalizer_band_type_definition_strings;
	extern s_string_list_definition equalizer_band_type_definition;
	extern c_versioned_string_list radio_mix_setting_definition_strings;
	extern s_string_list_definition radio_mix_setting_definition;

	extern s_tag_reference_definition global_sound_radio_settings_reference;

} // namespace macaque

} // namespace blofeld

