#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(looping_sound_track, MAXIMUM_TRACKS_PER_LOOPING_SOUND)
{
	FIELD( _field_string_id, "name^!" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_enum, "output effect" ),
	FIELD( _field_real, "gain:dB" ),
	FIELD( _field_tag_reference, "in" ),
	FIELD( _field_tag_reference, "loop" ),
	FIELD( _field_tag_reference, "out" ),
	FIELD( _field_tag_reference, "alt loop" ),
	FIELD( _field_tag_reference, "alt out" ),
	FIELD( _field_tag_reference, "alt trans in" ),
	FIELD( _field_tag_reference, "alt trans out" ),
	FIELD( _field_real, "fade in duration:seconds" ),
	FIELD( _field_long_enum, "fade in mode" ),
	FIELD( _field_real, "fade out duration:seconds" ),
	FIELD( _field_long_enum, "fade out mode" ),
	FIELD( _field_real, "alt crossfade duration:seconds" ),
	FIELD( _field_long_enum, "alt crossfade mode" ),
	FIELD( _field_real, "alt fade out duration:seconds" ),
	FIELD( _field_long_enum, "alt fade out mode" ),
	FIELD( _field_explanation, "Layer Settings" ),
	FIELD( _field_enum, "layer" ),
	FIELD( _field_word_flags, "layer flags" ),
	FIELD( _field_real, "layer fade in duration:seconds" ),
	FIELD( _field_long_enum, "layer fade in mode" ),
	FIELD( _field_real, "layer fade out duration:seconds" ),
	FIELD( _field_long_enum, "layer fade out mode" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

