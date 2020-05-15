#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(looping_sound_track, MAXIMUM_TRACKS_PER_LOOPING_SOUND)
{
	{ _field_string_id, "name^!" },
	{ _field_word_flags, "flags" },
	{ _field_enum, "output effect" },
	{ _field_real, "gain:dB" },
	{ _field_tag_reference, "in" },
	{ _field_tag_reference, "loop" },
	{ _field_tag_reference, "out" },
	{ _field_tag_reference, "alt loop" },
	{ _field_tag_reference, "alt out" },
	{ _field_tag_reference, "alt trans in" },
	{ _field_tag_reference, "alt trans out" },
	{ _field_real, "fade in duration:seconds" },
	{ _field_long_enum, "fade in mode" },
	{ _field_real, "fade out duration:seconds" },
	{ _field_long_enum, "fade out mode" },
	{ _field_real, "alt crossfade duration:seconds" },
	{ _field_long_enum, "alt crossfade mode" },
	{ _field_real, "alt fade out duration:seconds" },
	{ _field_long_enum, "alt fade out mode" },
	{ _field_explanation, "Layer Settings" },
	{ _field_enum, "layer" },
	{ _field_word_flags, "layer flags" },
	{ _field_real, "layer fade in duration:seconds" },
	{ _field_long_enum, "layer fade in mode" },
	{ _field_real, "layer fade out duration:seconds" },
	{ _field_long_enum, "layer fade out mode" },
	{ _field_terminator },
};

} // namespace blofeld

