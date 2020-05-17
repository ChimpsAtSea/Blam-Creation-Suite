#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP(sound_environment, SOUND_ENVIRONMENT_TAG)
	{
		FIELD( _field_explanation, "Reverb Settings" ),
		FIELD( _field_struct, "reverb settings", &global_sound_reverb_block_struct_definition ),
		FIELD( _field_explanation, "Forced Lowpass" ),
		FIELD( _field_struct, "lowpass settings", &global_sound_lowpass_block_struct_definition ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

