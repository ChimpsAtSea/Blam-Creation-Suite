#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(sound_looping, SOUND_LOOPING_TAG)
{
	{ _field_long_flags, "flags" },
	{ _field_real_bounds, "marty\'s music time:seconds" },
	{ _field_real_bounds, "runtime distance bounds!" },
	{ _field_real, "maximum flyby range distance" },
	{ _field_enum, "runtime sound class!" },
	{ _field_pad, "asdf", 2 },
	{ _field_string_id, "master marker track*#This track\'s markers, flags, gain and fade settings are copied to the other tracks. Its gain and fadeout settings are also copied to the details. If you want to change the master track use the sound-looping tool command" },
	{ _field_real, "maximum radius" },
	{ _field_block, "tracks#tracks play in parallel and loop continuously for the duration of the looping sound.", &looping_sound_track_block },
	{ _field_block, "detail sounds#detail sounds play at random throughout the duration of the looping sound.", &looping_sound_detail_block },
	{ _field_terminator },
};

} // namespace blofeld

