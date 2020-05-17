#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(looping_sound_track_block, MAXIMUM_TRACKS_PER_LOOPING_SOUND)
	{
		FIELD( _field_string_id, "name^!" ),
		FIELD( _field_word_flags, "flags", &looping_sound_track_flags ),
		FIELD( _field_enum, "output effect", &sound_effects_enum ),
		FIELD( _field_real, "gain:dB" ),
		FIELD( _field_tag_reference, "in" ),
		FIELD( _field_tag_reference, "loop" ),
		FIELD( _field_tag_reference, "out" ),
		FIELD( _field_tag_reference, "alt loop" ),
		FIELD( _field_tag_reference, "alt out" ),
		FIELD( _field_tag_reference, "alt trans in" ),
		FIELD( _field_tag_reference, "alt trans out" ),
		FIELD( _field_real, "fade in duration:seconds" ),
		FIELD( _field_long_enum, "fade in mode", &looping_sound_fade_modes ),
		FIELD( _field_real, "fade out duration:seconds" ),
		FIELD( _field_long_enum, "fade out mode", &looping_sound_fade_modes ),
		FIELD( _field_real, "alt crossfade duration:seconds" ),
		FIELD( _field_long_enum, "alt crossfade mode", &looping_sound_fade_modes ),
		FIELD( _field_real, "alt fade out duration:seconds" ),
		FIELD( _field_long_enum, "alt fade out mode", &looping_sound_fade_modes ),
		FIELD( _field_explanation, "Layer Settings" ),
		FIELD( _field_enum, "layer", &looping_sound_layers ),
		FIELD( _field_word_flags, "layer flags", &looping_sound_track_layer_flags ),
		FIELD( _field_real, "layer fade in duration:seconds" ),
		FIELD( _field_long_enum, "layer fade in mode", &looping_sound_fade_modes ),
		FIELD( _field_real, "layer fade out duration:seconds" ),
		FIELD( _field_long_enum, "layer fade out mode", &looping_sound_fade_modes ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(looping_sound_fade_modes, 5)
	{
		OPTION("default"),
		OPTION("linear"),
		OPTION("equal power"),
		OPTION("inverse power"),
		OPTION("s curve"),
	};

	TAG_ENUM(looping_sound_layers, 5)
	{
		OPTION("none"),
		OPTION("1"),
		OPTION("2"),
		OPTION("3"),
		OPTION("4"),
	};

	TAG_ENUM(looping_sound_track_flags, 6)
	{
		OPTION("fade in at start#the loop sound should fade in while the start sound is playing."),
		OPTION("fade out at stop#the loop sound should fade out while the stop sound is playing."),
		OPTION("fade out at alt stop#the alt loop sound should fade out while the alt stop sound is playing."),
		OPTION("crossfade alt loop#crossfade when switching between alt loop and loop."),
		OPTION("make fades wait for markers"),
		OPTION("master surround sound track"),
	};

	TAG_ENUM(looping_sound_track_layer_flags, 1)
	{
		OPTION("make layer wait for markers"),
	};

} // namespace blofeld

