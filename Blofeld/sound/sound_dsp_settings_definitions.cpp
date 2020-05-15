#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(sound_radio_settings, SOUND_RADIO_SETTINGS_TAG)
{
	{ _field_explanation, "mix settings" },
	{ _field_long_enum, "mix" },
	{ _field_explanation, "distortion settings" },
	{ _field_struct, "distortion settings" },
	{ _field_explanation, "equalizer settings" },
	{ _field_struct, "equalizer settings" },
	{ _field_terminator },
};

} // namespace blofeld

