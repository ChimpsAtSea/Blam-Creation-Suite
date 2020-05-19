#pragma once

namespace blofeld
{

	constexpr unsigned long SOUND_RADIO_SETTINGS_TAG = 'srad';

	extern s_tag_struct_definition sound_radio_settings_block_struct;
	extern s_tag_block_definition sound_radio_settings_block;
	extern s_tag_group sound_radio_settings_group;

	extern s_tag_struct_definition sound_equalizer_band_settings_block_block_struct;
	extern s_tag_block_definition sound_equalizer_band_settings_block_block;

	extern s_tag_struct_definition global_sound_lowpass_block_struct_definition;
	extern s_tag_struct_definition global_sound_reverb_block_struct_definition;
	extern s_tag_struct_definition global_sound_look_up_table_distortion_block_struct_definition;
	extern s_tag_struct_definition global_sound_equalizer_block_struct_definition;

	extern const char* look_up_table_flags_definition_strings[];
	extern s_string_list_definition look_up_table_flags_definition;
	extern const char* equalizer_band_type_definition_strings[];
	extern s_string_list_definition equalizer_band_type_definition;
	extern const char* radio_mix_setting_definition_strings[];
	extern s_string_list_definition radio_mix_setting_definition;

	extern s_tag_reference_definition global_sound_radio_settings_reference;

} // namespace blofeld

