#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define SOUND_RADIO_SETTINGS_STRUCT_DEFINITION_ID { 0x6177BF04, 0xF09F4A0C, 0xB670E9D3, 0x530193CE }
	TAG_BLOCK(
		sound_radio_settings_block,
		"sound_radio_settings_block",
		1,
		"s_sound_radio_settings",
		SOUND_RADIO_SETTINGS_STRUCT_DEFINITION_ID)
	{
		{ _field_explanation, "mix settings", "" },
		{ _field_long_enum, "mix", &radio_mix_setting_definition },
		{ _field_explanation, "distortion settings", "" },
		{ _field_struct, "distortion settings", &global_sound_look_up_table_distortion_block },
		{ _field_explanation, "equalizer settings", "" },
		{ _field_struct, "equalizer settings", &global_sound_equalizer_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		sound_radio_settings_group,
		SOUND_RADIO_SETTINGS_TAG,
		nullptr,
		INVALID_TAG,
		sound_radio_settings_block );

	#define SOUND_EQUALIZER_BAND_SETTINGS_BLOCK_STRUCT_ID { 0xF89C600C, 0x62DA422A, 0xAF5B1D5D, 0x0D1DD0DB }
	TAG_BLOCK(
		sound_equalizer_band_settings_block,
		"sound_equalizer_band_settings_block",
		k_maximum_sound_equalizer_bands,
		"s_sound_equalizer_band_settings",
		SOUND_EQUALIZER_BAND_SETTINGS_BLOCK_STRUCT_ID)
	{
		{ _field_long_enum, "type^", &equalizer_band_type_definition },
		FIELD_CUSTOM("frequency:Hz", _custom_field_slider_editor),
		{ _field_real, "frequency:Hz", nullptr, 'sled' },
		FIELD_CUSTOM("gain:dB", _custom_field_slider_editor),
		{ _field_real, "gain:dB", nullptr, 'sled' },
		FIELD_CUSTOM("q", _custom_field_slider_editor),
		{ _field_real, "q", nullptr, 'sled' },
		{ _field_terminator }
	};

	#define GLOBAL_SOUND_LOWPASS_BLOCK_ID { 0xF38F05D9, 0xF9BB4F33, 0x95EAD7FE, 0x61588F25 }
	TAG_STRUCT(
		global_sound_lowpass_block,
		"global_sound_lowpass_block",
		"s_sound_lowpass_settings",
		GLOBAL_SOUND_LOWPASS_BLOCK_ID)
	{
		FIELD_CUSTOM("cutoff frequency:Hz", _custom_field_slider_editor),
		{ _field_real, "cutoff frequency:Hz", nullptr, 'sled' },
		FIELD_CUSTOM("output gain:dB", _custom_field_slider_editor),
		{ _field_real, "output gain:dB", nullptr, 'sled' },
		{ _field_terminator }
	};

	#define GLOBAL_SOUND_REVERB_BLOCK_ID { 0xE4B31E1D, 0xC5A74C51, 0xAE02D86C, 0x2B3F8B06 }
	TAG_STRUCT(
		global_sound_reverb_block,
		"global_sound_reverb_block",
		"s_sound_reverb_settings",
		GLOBAL_SOUND_REVERB_BLOCK_ID)
	{
		FIELD_CUSTOM("room intensity:dB#intensity of the room effect", _custom_field_slider_editor),
		{ _field_real, "room intensity:dB#intensity of the room effect", nullptr, 'sled' },
		FIELD_CUSTOM("room intensity hf:dB#intensity of the room effect above the reference high frequency", _custom_field_slider_editor),
		{ _field_real, "room intensity hf:dB#intensity of the room effect above the reference high frequency", nullptr, 'sled' },
		FIELD_CUSTOM("room rolloff (0 to 10)#how quickly the room effect rolls off, from 0.0 to 10.0", _custom_field_slider_editor),
		{ _field_real, "room rolloff (0 to 10)#how quickly the room effect rolls off, from 0.0 to 10.0", nullptr, 'sled' },
		FIELD_CUSTOM("decay time (.1 to 20):seconds", _custom_field_slider_editor),
		{ _field_real, "decay time (.1 to 20):seconds", nullptr, 'sled' },
		FIELD_CUSTOM("decay hf ratio (.1 to 2)", _custom_field_slider_editor),
		{ _field_real, "decay hf ratio (.1 to 2)", nullptr, 'sled' },
		FIELD_CUSTOM("reflections intensity:dB[-100,10]", _custom_field_slider_editor),
		{ _field_real, "reflections intensity:dB[-100,10]", nullptr, 'sled' },
		FIELD_CUSTOM("reflections delay (0 to .3):seconds", _custom_field_slider_editor),
		{ _field_real, "reflections delay (0 to .3):seconds", nullptr, 'sled' },
		FIELD_CUSTOM("reverb intensity:dB[-100,20]", _custom_field_slider_editor),
		{ _field_real, "reverb intensity:dB[-100,20]", nullptr, 'sled' },
		FIELD_CUSTOM("reverb delay (0 to .1):seconds", _custom_field_slider_editor),
		{ _field_real, "reverb delay (0 to .1):seconds", nullptr, 'sled' },
		FIELD_CUSTOM("diffusion", _custom_field_slider_editor),
		{ _field_real, "diffusion", nullptr, 'sled' },
		FIELD_CUSTOM("density", _custom_field_slider_editor),
		{ _field_real, "density", nullptr, 'sled' },
		FIELD_CUSTOM("hf reference(20 to 20,000):Hz#for hf values, what frequency defines hf, from 20 to 20,000", _custom_field_slider_editor),
		{ _field_real, "hf reference(20 to 20,000):Hz#for hf values, what frequency defines hf, from 20 to 20,000", nullptr, 'sled' },
		{ _field_explanation, "WWise Environment", "Use these values for WWise reverb. Above stuff will be removed eventually." },
		{ _field_string_id, "Environment name#Name of the environment from WWise. This will be a DSP effect with Environmental Effect checked." },
		FIELD_CUSTOM("Dry mix value#0 to 1 with 0 being none, and 1 being full.", _custom_field_slider_editor),
		{ _field_real, "Dry mix value#0 to 1 with 0 being none, and 1 being full.", nullptr, 'sled' },
		FIELD_CUSTOM("Wet mix value#0 to 1 with 0 being none, and 1 being full.", _custom_field_slider_editor),
		{ _field_real, "Wet mix value#0 to 1 with 0 being none, and 1 being full.", nullptr, 'sled' },
		FIELD_CUSTOM("Player wet mix value#0 to 1 with 0 being none, and 1 being full.", _custom_field_slider_editor),
		{ _field_real, "Player wet mix value#0 to 1 with 0 being none, and 1 being full.", nullptr, 'sled' },
		{ _field_terminator }
	};

	#define GLOBAL_SOUND_LOOK_UP_TABLE_DISTORTION_BLOCK_ID { 0x898FB725, 0x714849A9, 0x8A88EB99, 0x09FC092C }
	TAG_STRUCT(
		global_sound_look_up_table_distortion_block,
		"global_sound_look_up_table_distortion_block",
		"s_sound_look_up_table_distortion_settings",
		GLOBAL_SOUND_LOOK_UP_TABLE_DISTORTION_BLOCK_ID)
	{
		FIELD_CUSTOM("table size", _custom_field_slider_editor),
		{ _field_long_integer, "table size", nullptr, 'sled' },
		FIELD_CUSTOM("noise amount", _custom_field_slider_editor),
		{ _field_real, "noise amount", nullptr, 'sled' },
		{ _field_long_flags, "flags", &look_up_table_flags_definition },
		{ _field_terminator }
	};

	#define GLOBAL_SOUND_EQUALIZER_BLOCK_ID { 0x9EE2BF8D, 0x8CB54AD8, 0xA7D0F3DA, 0x3FDE09A9 }
	TAG_STRUCT(
		global_sound_equalizer_block,
		"global_sound_equalizer_block",
		"s_sound_equalizer_settings",
		GLOBAL_SOUND_EQUALIZER_BLOCK_ID)
	{
		FIELD_CUSTOM("input gain:dB", _custom_field_slider_editor),
		{ _field_real, "input gain:dB", nullptr, 'sled' },
		FIELD_CUSTOM("output gain:dB", _custom_field_slider_editor),
		{ _field_real, "output gain:dB", nullptr, 'sled' },
		{ _field_block, "band settings", &sound_equalizer_band_settings_block },
		{ _field_terminator }
	};

	STRINGS(look_up_table_flags_definition)
	{
		"interpolate"
	};
	STRING_LIST(look_up_table_flags_definition, look_up_table_flags_definition_strings, _countof(look_up_table_flags_definition_strings));

	STRINGS(equalizer_band_type_definition)
	{
		"band pass",
		"low shelf",
		"high shelf",
		"low pass",
		"high pass"
	};
	STRING_LIST(equalizer_band_type_definition, equalizer_band_type_definition_strings, _countof(equalizer_band_type_definition_strings));

	STRINGS(radio_mix_setting_definition)
	{
		"full#full unspatialized radio effect",
		"3d#mixes in the unspatialized radio effect with distance",
		"none#essentially turns off the radio effect!"
	};
	STRING_LIST(radio_mix_setting_definition, radio_mix_setting_definition_strings, _countof(radio_mix_setting_definition_strings));

	TAG_REFERENCE(global_sound_radio_settings_reference, SOUND_RADIO_SETTINGS_TAG);

} // namespace macaque

} // namespace blofeld

