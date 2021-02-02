#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP(sound_environment, SOUND_ENVIRONMENT_TAG)
	{
		{ _field_legacy, _field_explanation, "Reverb Settings", "" },
		{ _field_legacy, _field_struct, "reverb settings", &global_sound_reverb_block_struct_definition },
		{ _field_legacy, _field_explanation, "Forced Lowpass", "This will override obstruction and occlusion if you set the cutoff frequency to a non-zero value. Use the individual classes\' \"forced lowpass wet mix\" value to alter the mix." },
		{ _field_legacy, _field_struct, "lowpass settings", &global_sound_lowpass_block_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	TAG_REFERENCE(global_sound_environment_reference, SOUND_ENVIRONMENT_TAG);

} // namespace blofeld

