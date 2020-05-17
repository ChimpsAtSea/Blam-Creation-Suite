#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(looping_sound_detail_flags, 5)
	{
		OPTION("don\'t play with alternate"),
		OPTION("don\'t play without alternate"),
		OPTION("start immediately with loop"),
		OPTION("inherit scale from loop"),
		OPTION("don\'t fade with loop"),
	};

	TAG_ENUM(looping_sound_detail_period_type_enum, 2)
	{
		OPTION("ignores playback time"),
		OPTION("relative to end of playback"),
	};

	TAG_BLOCK(looping_sound_detail_block, MAXIMUM_DETAIL_SOUNDS_PER_LOOPING_SOUND)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_tag_reference, "sound" ),
		FIELD( _field_explanation, "frequency of play" ),
		FIELD( _field_long_enum, "period type", &looping_sound_detail_period_type_enum ),
		FIELD( _field_real_bounds, "random period bounds:seconds#the time between successive playings of this sound will be randomly selected from this range." ),
		FIELD( _field_real, "detail gain:dB" ),
		FIELD( _field_real, "fade out duration:seconds" ),
		FIELD( _field_long_enum, "fade out mode", &looping_sound_fade_modes ),
		FIELD( _field_long_flags, "flags", &looping_sound_detail_flags ),
		FIELD( _field_explanation, "random spatialization" ),
		FIELD( _field_angle_bounds, "yaw bounds:degrees#the sound\'s position along the horizon will be randomly selected from this range." ),
		FIELD( _field_angle_bounds, "pitch bounds:degrees#the sound\'s position above (positive values) or below (negative values) the horizon will be randomly selected from this range." ),
		FIELD( _field_real_bounds, "distance bounds:world units#the sound\'s distance (from its spatialized looping sound or from the listener if the looping sound is stereo) will be randomly selected from this range." ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

