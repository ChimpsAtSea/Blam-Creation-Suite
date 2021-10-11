#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define LOOPING_SOUND_TRACK_BLOCK_ID { 0x274E50ED, 0x4CB34CFA, 0x8469F40F, 0xEDAF50AC }
	TAG_BLOCK(
		looping_sound_track_block,
		"looping_sound_track_block",
		MAXIMUM_TRACKS_PER_LOOPING_SOUND,
		"looping_sound_track",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		LOOPING_SOUND_TRACK_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_INDEX },
		{ _field_word_flags, "flags", &looping_sound_track_flags },
		{ _field_enum, "output effect", &sound_effects_enum },
		{ _field_real, "gain", nullptr, "dB", _field_id_decibels },
		{ _field_tag_reference, "in", &global_force_sound_only_reference },
		{ _field_tag_reference, "loop", &global_force_sound_only_reference },
		{ _field_tag_reference, "out", &global_force_sound_only_reference },
		{ _field_tag_reference, "alt loop", &global_force_sound_only_reference },
		{ _field_tag_reference, "alt out", &global_force_sound_only_reference },
		{ _field_tag_reference, "alt trans in", &global_force_sound_only_reference },
		{ _field_tag_reference, "alt trans out", &global_force_sound_only_reference },
		{ _field_real, "fade in duration", nullptr, "seconds" },
		{ _field_long_enum, "fade in mode", &looping_sound_fade_modes },
		{ _field_real, "fade out duration", nullptr, "seconds" },
		{ _field_long_enum, "fade out mode", &looping_sound_fade_modes },
		{ _field_real, "alt crossfade duration", nullptr, "seconds" },
		{ _field_long_enum, "alt crossfade mode", &looping_sound_fade_modes },
		{ _field_real, "alt fade out duration", nullptr, "seconds" },
		{ _field_long_enum, "alt fade out mode", &looping_sound_fade_modes },
		FIELD_EXPLANATION_EX("Layer Settings", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_enum, "layer", &looping_sound_layers },
		{ _field_word_flags, "layer flags", &looping_sound_track_layer_flags },
		{ _field_real, "layer fade in duration", nullptr, "seconds" },
		{ _field_long_enum, "layer fade in mode", &looping_sound_fade_modes },
		{ _field_real, "layer fade out duration", nullptr, "seconds" },
		{ _field_long_enum, "layer fade out mode", &looping_sound_fade_modes },
		{ _field_terminator }
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

