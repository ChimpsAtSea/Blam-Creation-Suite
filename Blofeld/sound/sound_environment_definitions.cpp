#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(sound_environment, SOUND_ENVIRONMENT_TAG)
{
	FIELD( _field_explanation, "Reverb Settings" ),
	FIELD( _field_struct, "reverb settings" ),
	FIELD( _field_explanation, "Forced Lowpass" ),
	FIELD( _field_struct, "lowpass settings" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

