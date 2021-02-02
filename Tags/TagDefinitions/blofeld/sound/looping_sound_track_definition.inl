#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(looping_sound_track_block, MAXIMUM_TRACKS_PER_LOOPING_SOUND)
	{
		{ _field_legacy, _field_string_id, "name^!" },
		{ _field_legacy, _field_word_flags, "flags", &looping_sound_track_flags },
		{ _field_legacy, _field_enum, "output effect", &sound_effects_enum },
		{ _field_legacy, _field_real, "gain:dB" },
		{ _field_legacy, _field_tag_reference, "in", &global_force_sound_only_reference },
		{ _field_legacy, _field_tag_reference, "loop", &global_force_sound_only_reference },
		{ _field_legacy, _field_tag_reference, "out", &global_force_sound_only_reference },
		{ _field_legacy, _field_tag_reference, "alt loop", &global_force_sound_only_reference },
		{ _field_legacy, _field_tag_reference, "alt out", &global_force_sound_only_reference },
		{ _field_legacy, _field_tag_reference, "alt trans in", &global_force_sound_only_reference },
		{ _field_legacy, _field_tag_reference, "alt trans out", &global_force_sound_only_reference },
		{ _field_legacy, _field_real, "fade in duration:seconds" },
		{ _field_legacy, _field_long_enum, "fade in mode", &looping_sound_fade_modes },
		{ _field_legacy, _field_real, "fade out duration:seconds" },
		{ _field_legacy, _field_long_enum, "fade out mode", &looping_sound_fade_modes },
		{ _field_legacy, _field_real, "alt crossfade duration:seconds" },
		{ _field_legacy, _field_long_enum, "alt crossfade mode", &looping_sound_fade_modes },
		{ _field_legacy, _field_real, "alt fade out duration:seconds" },
		{ _field_legacy, _field_long_enum, "alt fade out mode", &looping_sound_fade_modes },
		{ _field_legacy, _field_explanation, "Layer Settings", "" },
		{ _field_legacy, _field_enum, "layer", &looping_sound_layers },
		{ _field_legacy, _field_word_flags, "layer flags", &looping_sound_track_layer_flags },
		{ _field_legacy, _field_real, "layer fade in duration:seconds" },
		{ _field_legacy, _field_long_enum, "layer fade in mode", &looping_sound_fade_modes },
		{ _field_legacy, _field_real, "layer fade out duration:seconds" },
		{ _field_legacy, _field_long_enum, "layer fade out mode", &looping_sound_fade_modes },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(looping_sound_fade_modes)
	{
		"default",
		"linear",
		"equal power",
		"inverse power",
		"s curve"
	};
	STRING_LIST(looping_sound_fade_modes, looping_sound_fade_modes_strings, _countof(looping_sound_fade_modes_strings));

	STRINGS(looping_sound_layers)
	{
		"none",
		"1",
		"2",
		"3",
		"4"
	};
	STRING_LIST(looping_sound_layers, looping_sound_layers_strings, _countof(looping_sound_layers_strings));

	STRINGS(looping_sound_track_flags)
	{
		"fade in at start#the loop sound should fade in while the start sound is playing.",
		"fade out at stop#the loop sound should fade out while the stop sound is playing.",
		"fade out at alt stop#the alt loop sound should fade out while the alt stop sound is playing.",
		"crossfade alt loop#crossfade when switching between alt loop and loop.",
		"make fades wait for markers",
		"master surround sound track"
	};
	STRING_LIST(looping_sound_track_flags, looping_sound_track_flags_strings, _countof(looping_sound_track_flags_strings));

	STRINGS(looping_sound_track_layer_flags)
	{
		"make layer wait for markers"
	};
	STRING_LIST(looping_sound_track_layer_flags, looping_sound_track_layer_flags_strings, _countof(looping_sound_track_layer_flags_strings));

} // namespace blofeld

