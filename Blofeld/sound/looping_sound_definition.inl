#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(looping_sound_flags, 14)
	{
		OPTION("deafening to AIs#when used as a background stereo track, causes nearby AIs to be unable to hear"),
		OPTION("not a loop#this is a collection of permutations strung together that should play once then stop."),
		OPTION("stops music#all other music loops will stop when this one starts."),
		OPTION("always spatialize#always play as 3d sound, even in first person"),
		OPTION("synchronize with owner{synchronize playback}#synchronizes playback with other looping sounds attached to the owner of this sound"),
		OPTION("synchronize tracks"),
		OPTION("fake spatialization with distance"),
		OPTION("combine all 3d playback"),
		OPTION("persistent flyby#like a laser blast"),
		OPTION("don\'t apply random spatialization to details"),
		OPTION("allow marker stitching#you need to reimport the sound_looping for this to take effect"),
		OPTION("don\'t delay retries!#don\'t delay retrying the looping sound, in case the bank is loaded now"),
		OPTION("Use vehicle parent for playerness#Look to the parent of the vehicle. Only works on vehicles. Duh"),
		OPTION("Implicit speed RPTC#looping_sound_speed"),
	};

	TAG_GROUP_FROM_BLOCK(sound_looping, SOUND_LOOPING_TAG, sound_looping_block_block );

	TAG_BLOCK_FROM_STRUCT(sound_looping_block, 1, sound_looping_struct_definition_struct_definition );

TAG_STRUCT(sound_looping_struct_definition)
{
		FIELD( _field_long_flags, "flags", &looping_sound_flags ),
		FIELD( _field_real_bounds, "marty\'s music time:seconds" ),
		FIELD( _field_real_bounds, "runtime distance bounds!" ),
		FIELD( _field_real, "maximum flyby range distance" ),
		FIELD( _field_enum, "runtime sound class!", &sound_class_enum ),
		FIELD( _field_pad, "asdf", 2 ),
		FIELD( _field_string_id, "master marker track*#This track\'s markers, flags, gain and fade settings are copied to the other tracks. Its gain and fadeout settings are also copied to the details. If you want to change the master track use the sound-looping tool command" ),
		FIELD( _field_real, "maximum radius" ),
		FIELD( _field_block, "tracks#tracks play in parallel and loop continuously for the duration of the looping sound.", &looping_sound_track_block_block ),
		FIELD( _field_block, "detail sounds#detail sounds play at random throughout the duration of the looping sound.", &looping_sound_detail_block_block ),
		FIELD( _field_terminator )
};

} // namespace blofeld

