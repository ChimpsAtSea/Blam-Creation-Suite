#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP(sound_environment, SOUND_ENVIRONMENT_TAG)
	{
		{ _field_explanation, "Reverb Settings" },
		{ _field_struct, "reverb settings", &global_sound_reverb_block_struct_definition },
		{ _field_explanation, "Forced Lowpass" },
		{ _field_struct, "lowpass settings", &global_sound_lowpass_block_struct_definition },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_sound_environment_reference, SOUND_ENVIRONMENT_TAG);

} // namespace blofeld

