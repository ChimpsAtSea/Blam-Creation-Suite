#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP(sound_radio_settings, SOUND_RADIO_SETTINGS_TAG)
	{
		FIELD( _field_explanation, "mix settings" ),
		FIELD( _field_long_enum, "mix", &radio_mix_setting_definition ),
		FIELD( _field_explanation, "distortion settings" ),
		FIELD( _field_struct, "distortion settings", &global_sound_look_up_table_distortion_block_struct_definition ),
		FIELD( _field_explanation, "equalizer settings" ),
		FIELD( _field_struct, "equalizer settings", &global_sound_equalizer_block_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(sound_equalizer_band_settings_block, k_maximum_sound_equalizer_bands)
	{
		FIELD( _field_long_enum, "type^", &equalizer_band_type_definition ),
		FIELD( _field_custom, "frequency:Hz" ),
		FIELD( _field_real, "frequency:Hz" ),
		FIELD( _field_custom, "gain:dB" ),
		FIELD( _field_real, "gain:dB" ),
		FIELD( _field_custom, "q" ),
		FIELD( _field_real, "q" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(global_sound_lowpass_block)
	{
		FIELD( _field_custom, "cutoff frequency:Hz" ),
		FIELD( _field_real, "cutoff frequency:Hz" ),
		FIELD( _field_custom, "output gain:dB" ),
		FIELD( _field_real, "output gain:dB" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(global_sound_reverb_block)
	{
		FIELD( _field_custom, "room intensity:dB#intensity of the room effect" ),
		FIELD( _field_real, "room intensity:dB#intensity of the room effect" ),
		FIELD( _field_custom, "room intensity hf:dB#intensity of the room effect above the reference high frequency" ),
		FIELD( _field_real, "room intensity hf:dB#intensity of the room effect above the reference high frequency" ),
		FIELD( _field_custom, "room rolloff (0 to 10)#how quickly the room effect rolls off, from 0.0 to 10.0" ),
		FIELD( _field_real, "room rolloff (0 to 10)#how quickly the room effect rolls off, from 0.0 to 10.0" ),
		FIELD( _field_custom, "decay time (.1 to 20):seconds" ),
		FIELD( _field_real, "decay time (.1 to 20):seconds" ),
		FIELD( _field_custom, "decay hf ratio (.1 to 2)" ),
		FIELD( _field_real, "decay hf ratio (.1 to 2)" ),
		FIELD( _field_custom, "reflections intensity:dB[-100,10]" ),
		FIELD( _field_real, "reflections intensity:dB[-100,10]" ),
		FIELD( _field_custom, "reflections delay (0 to .3):seconds" ),
		FIELD( _field_real, "reflections delay (0 to .3):seconds" ),
		FIELD( _field_custom, "reverb intensity:dB[-100,20]" ),
		FIELD( _field_real, "reverb intensity:dB[-100,20]" ),
		FIELD( _field_custom, "reverb delay (0 to .1):seconds" ),
		FIELD( _field_real, "reverb delay (0 to .1):seconds" ),
		FIELD( _field_custom, "diffusion" ),
		FIELD( _field_real, "diffusion" ),
		FIELD( _field_custom, "density" ),
		FIELD( _field_real, "density" ),
		FIELD( _field_custom, "hf reference(20 to 20,000):Hz#for hf values, what frequency defines hf, from 20 to 20,000" ),
		FIELD( _field_real, "hf reference(20 to 20,000):Hz#for hf values, what frequency defines hf, from 20 to 20,000" ),
		FIELD( _field_explanation, "WWise Environment" ),
		FIELD( _field_string_id, "Environment name#Name of the environment from WWise. This will be a DSP effect with Environmental Effect checked." ),
		FIELD( _field_custom, "Dry mix value#0 to 1 with 0 being none, and 1 being full." ),
		FIELD( _field_real, "Dry mix value#0 to 1 with 0 being none, and 1 being full." ),
		FIELD( _field_custom, "Wet mix value#0 to 1 with 0 being none, and 1 being full." ),
		FIELD( _field_real, "Wet mix value#0 to 1 with 0 being none, and 1 being full." ),
		FIELD( _field_custom, "Player wet mix value#0 to 1 with 0 being none, and 1 being full." ),
		FIELD( _field_real, "Player wet mix value#0 to 1 with 0 being none, and 1 being full." ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(global_sound_look_up_table_distortion_block)
	{
		FIELD( _field_custom, "table size" ),
		FIELD( _field_long_integer, "table size" ),
		FIELD( _field_custom, "noise amount" ),
		FIELD( _field_real, "noise amount" ),
		FIELD( _field_long_flags, "flags", &look_up_table_flags_definition ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(global_sound_equalizer_block)
	{
		FIELD( _field_custom, "input gain:dB" ),
		FIELD( _field_real, "input gain:dB" ),
		FIELD( _field_custom, "output gain:dB" ),
		FIELD( _field_real, "output gain:dB" ),
		FIELD( _field_block, "band settings", &sound_equalizer_band_settings_block_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(look_up_table_flags_definition, 1)
	{
		OPTION("interpolate"),
	};

	TAG_ENUM(equalizer_band_type_definition, 5)
	{
		OPTION("band pass"),
		OPTION("low shelf"),
		OPTION("high shelf"),
		OPTION("low pass"),
		OPTION("high pass"),
	};

	TAG_ENUM(radio_mix_setting_definition, 3)
	{
		OPTION("full#full unspatialized radio effect"),
		OPTION("3d#mixes in the unspatialized radio effect with distance"),
		OPTION("none#essentially turns off the radio effect!"),
	};

} // namespace blofeld

