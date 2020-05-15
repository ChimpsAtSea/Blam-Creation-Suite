#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(sound_looping, SOUND_LOOPING_TAG)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real_bounds, "marty\'s music time:seconds" ),
	FIELD( _field_real_bounds, "runtime distance bounds!" ),
	FIELD( _field_real, "maximum flyby range distance" ),
	FIELD( _field_enum, "runtime sound class!" ),
	FIELD( _field_pad, "asdf", 2 ),
	FIELD( _field_string_id, "master marker track*#This track\'s markers, flags, gain and fade settings are copied to the other tracks. Its gain and fadeout settings are also copied to the details. If you want to change the master track use the sound-looping tool command" ),
	FIELD( _field_real, "maximum radius" ),
	FIELD( _field_block, "tracks#tracks play in parallel and loop continuously for the duration of the looping sound.", &looping_sound_track_block ),
	FIELD( _field_block, "detail sounds#detail sounds play at random throughout the duration of the looping sound.", &looping_sound_detail_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

