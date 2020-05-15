#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(looping_sound_detail, MAXIMUM_DETAIL_SOUNDS_PER_LOOPING_SOUND)
{
	{ _field_string_id, "name^" },
	{ _field_tag_reference, "sound" },
	{ _field_explanation, "frequency of play" },
	{ _field_long_enum, "period type" },
	{ _field_real_bounds, "random period bounds:seconds#the time between successive playings of this sound will be randomly selected from this range." },
	{ _field_real, "detail gain:dB" },
	{ _field_real, "fade out duration:seconds" },
	{ _field_long_enum, "fade out mode" },
	{ _field_long_flags, "flags" },
	{ _field_explanation, "random spatialization" },
	{ _field_angle_bounds, "yaw bounds:degrees#the sound\'s position along the horizon will be randomly selected from this range." },
	{ _field_angle_bounds, "pitch bounds:degrees#the sound\'s position above (positive values) or below (negative values) the horizon will be randomly selected from this range." },
	{ _field_real_bounds, "distance bounds:world units#the sound\'s distance (from its spatialized looping sound or from the listener if the looping sound is stereo) will be randomly selected from this range." },
	{ _field_terminator },
};

} // namespace blofeld

