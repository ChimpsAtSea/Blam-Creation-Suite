#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP(sound_radio_settings, SOUND_RADIO_SETTINGS_TAG)
	{
		{ _field_explanation, "mix settings", "" },
		{ _field_long_enum, "mix", &radio_mix_setting_definition },
		{ _field_explanation, "distortion settings", "" },
		{ _field_struct, "distortion settings", &global_sound_look_up_table_distortion_block_struct_definition },
		{ _field_explanation, "equalizer settings", "" },
		{ _field_struct, "equalizer settings", &global_sound_equalizer_block_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(sound_equalizer_band_settings_block, k_maximum_sound_equalizer_bands)
	{
		{ _field_long_enum, "type^", &equalizer_band_type_definition },
		{ _field_custom, "frequency:Hz" },
		{ _field_real, "frequency:Hz" },
		{ _field_custom, "gain:dB" },
		{ _field_real, "gain:dB" },
		{ _field_custom, "q" },
		{ _field_real, "q" },
		{ _field_terminator }
	};

	TAG_STRUCT(global_sound_lowpass_block)
	{
		{ _field_custom, "cutoff frequency:Hz" },
		{ _field_real, "cutoff frequency:Hz" },
		{ _field_custom, "output gain:dB" },
		{ _field_real, "output gain:dB" },
		{ _field_terminator }
	};

	TAG_STRUCT(global_sound_reverb_block)
	{
		{ _field_custom, "room intensity:dB#intensity of the room effect" },
		{ _field_real, "room intensity:dB#intensity of the room effect" },
		{ _field_custom, "room intensity hf:dB#intensity of the room effect above the reference high frequency" },
		{ _field_real, "room intensity hf:dB#intensity of the room effect above the reference high frequency" },
		{ _field_custom, "room rolloff (0 to 10)#how quickly the room effect rolls off, from 0.0 to 10.0" },
		{ _field_real, "room rolloff (0 to 10)#how quickly the room effect rolls off, from 0.0 to 10.0" },
		{ _field_custom, "decay time (.1 to 20):seconds" },
		{ _field_real, "decay time (.1 to 20):seconds" },
		{ _field_custom, "decay hf ratio (.1 to 2)" },
		{ _field_real, "decay hf ratio (.1 to 2)" },
		{ _field_custom, "reflections intensity:dB[-100,10]" },
		{ _field_real, "reflections intensity:dB[-100,10]" },
		{ _field_custom, "reflections delay (0 to .3):seconds" },
		{ _field_real, "reflections delay (0 to .3):seconds" },
		{ _field_custom, "reverb intensity:dB[-100,20]" },
		{ _field_real, "reverb intensity:dB[-100,20]" },
		{ _field_custom, "reverb delay (0 to .1):seconds" },
		{ _field_real, "reverb delay (0 to .1):seconds" },
		{ _field_custom, "diffusion" },
		{ _field_real, "diffusion" },
		{ _field_custom, "density" },
		{ _field_real, "density" },
		{ _field_custom, "hf reference(20 to 20,000):Hz#for hf values, what frequency defines hf, from 20 to 20,000" },
		{ _field_real, "hf reference(20 to 20,000):Hz#for hf values, what frequency defines hf, from 20 to 20,000" },
		{ _field_explanation, "WWise Environment", "Use these values for WWise reverb. Above stuff will be removed eventually." },
		{ _field_string_id, "Environment name#Name of the environment from WWise. This will be a DSP effect with Environmental Effect checked." },
		{ _field_custom, "Dry mix value#0 to 1 with 0 being none, and 1 being full." },
		{ _field_real, "Dry mix value#0 to 1 with 0 being none, and 1 being full." },
		{ _field_custom, "Wet mix value#0 to 1 with 0 being none, and 1 being full." },
		{ _field_real, "Wet mix value#0 to 1 with 0 being none, and 1 being full." },
		{ _field_custom, "Player wet mix value#0 to 1 with 0 being none, and 1 being full." },
		{ _field_real, "Player wet mix value#0 to 1 with 0 being none, and 1 being full." },
		{ _field_terminator }
	};

	TAG_STRUCT(global_sound_look_up_table_distortion_block)
	{
		{ _field_custom, "table size" },
		{ _field_long_integer, "table size" },
		{ _field_custom, "noise amount" },
		{ _field_real, "noise amount" },
		{ _field_long_flags, "flags", &look_up_table_flags_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(global_sound_equalizer_block)
	{
		{ _field_custom, "input gain:dB" },
		{ _field_real, "input gain:dB" },
		{ _field_custom, "output gain:dB" },
		{ _field_real, "output gain:dB" },
		{ _field_block, "band settings", &sound_equalizer_band_settings_block_block },
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

} // namespace blofeld

