#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(sound_radio_settings, SOUND_RADIO_SETTINGS_TAG)
{
	FIELD( _field_explanation, "mix settings" ),
	FIELD( _field_long_enum, "mix" ),
	FIELD( _field_explanation, "distortion settings" ),
	FIELD( _field_struct, "distortion settings" ),
	FIELD( _field_explanation, "equalizer settings" ),
	FIELD( _field_struct, "equalizer settings" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

