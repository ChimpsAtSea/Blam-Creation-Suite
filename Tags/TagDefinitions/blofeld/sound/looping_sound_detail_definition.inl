#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(looping_sound_detail_block, MAXIMUM_DETAIL_SOUNDS_PER_LOOPING_SOUND)
	{
		{ _field_legacy, _field_string_id, "name^" },
		{ _field_legacy, _field_tag_reference, "sound", &global_force_sound_only_reference },
		{ _field_legacy, _field_explanation, "frequency of play", "" },
		{ _field_legacy, _field_long_enum, "period type", &looping_sound_detail_period_type_enum },
		{ _field_legacy, _field_real_bounds, "random period bounds:seconds#the time between successive playings of this sound will be randomly selected from this range." },
		{ _field_legacy, _field_real, "detail gain:dB" },
		{ _field_legacy, _field_real, "fade out duration:seconds" },
		{ _field_legacy, _field_long_enum, "fade out mode", &looping_sound_fade_modes },
		{ _field_legacy, _field_long_flags, "flags", &looping_sound_detail_flags },
		{ _field_legacy, _field_explanation, "random spatialization", "if the flag above is not set, this detail will be randomly spatialized according to the following constraints. if both lower and upper bounds are zero for any of the following fields, the sound\'s position will be randomly selected from all possible directions or distances." },
		{ _field_legacy, _field_angle_bounds, "yaw bounds:degrees#the sound\'s position along the horizon will be randomly selected from this range." },
		{ _field_legacy, _field_angle_bounds, "pitch bounds:degrees#the sound\'s position above (positive values) or below (negative values) the horizon will be randomly selected from this range." },
		{ _field_legacy, _field_real_bounds, "distance bounds:world units#the sound\'s distance (from its spatialized looping sound or from the listener if the looping sound is stereo) will be randomly selected from this range." },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(looping_sound_detail_flags)
	{
		"don\'t play with alternate",
		"don\'t play without alternate",
		"start immediately with loop",
		"inherit scale from loop",
		"don\'t fade with loop"
	};
	STRING_LIST(looping_sound_detail_flags, looping_sound_detail_flags_strings, _countof(looping_sound_detail_flags_strings));

	STRINGS(looping_sound_detail_period_type_enum)
	{
		"ignores playback time",
		"relative to end of playback"
	};
	STRING_LIST(looping_sound_detail_period_type_enum, looping_sound_detail_period_type_enum_strings, _countof(looping_sound_detail_period_type_enum_strings));

} // namespace blofeld

