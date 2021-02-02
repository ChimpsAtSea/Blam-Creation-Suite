#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define LOOPING_SOUND_DETAIL_BLOCK_ID { 0xA617A95E, 0x4F7447C1, 0xB14046E5, 0xAE77AE0F }
	TAG_BLOCK(
		looping_sound_detail_block,
		"looping_sound_detail_block",
		MAXIMUM_DETAIL_SOUNDS_PER_LOOPING_SOUND,
		"looping_sound_detail_block",
		LOOPING_SOUND_DETAIL_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_tag_reference, "sound", &global_force_sound_only_reference },
		{ _field_explanation, "frequency of play", "" },
		{ _field_long_enum, "period type", &looping_sound_detail_period_type_enum },
		{ _field_real_bounds, "random period bounds", "the time between successive playings of this sound will be randomly selected from this range.", "seconds" },
		{ _field_real, "detail gain", "dB", _field_id_decibels },
		{ _field_real, "fade out duration", "seconds" },
		{ _field_long_enum, "fade out mode", &looping_sound_fade_modes },
		{ _field_long_flags, "flags", &looping_sound_detail_flags },
		{ _field_explanation, "random spatialization", "if the flag above is not set, this detail will be randomly spatialized according to the following constraints. if both lower and upper bounds are zero for any of the following fields, the sound\'s position will be randomly selected from all possible directions or distances." },
		{ _field_angle_bounds, "yaw bounds", "the sound\'s position along the horizon will be randomly selected from this range.", "degrees" },
		{ _field_angle_bounds, "pitch bounds", "the sound\'s position above (positive values) or below (negative values) the horizon will be randomly selected from this range.", "degrees" },
		{ _field_real_bounds, "distance bounds", "the sound\'s distance (from its spatialized looping sound or from the listener if the looping sound is stereo) will be randomly selected from this range.", "world units" },
		{ _field_terminator }
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

} // namespace macaque

} // namespace blofeld

