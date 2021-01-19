#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define SOUND_ENVIRONMENT_STRUCT_DEFINITION_ID { 0x9AB4B8F2, 0x64524BEC, 0x9D4F14BA, 0x2A6D23A4 }
	TAG_BLOCK(
		sound_environment_block,
		"sound_environment_block",
		1,
		"sound_environment",
		SOUND_ENVIRONMENT_STRUCT_DEFINITION_ID)
	{
		{ _field_explanation, "Reverb Settings", "" },
		{ _field_struct, "reverb settings", &global_sound_reverb_block },
		{ _field_explanation, "Forced Lowpass", "This will override obstruction and occlusion if you set the cutoff frequency to a non-zero value. Use the individual classes\' \"forced lowpass wet mix\" value to alter the mix." },
		{ _field_struct, "lowpass settings", &global_sound_lowpass_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		sound_environment_group,
		SOUND_ENVIRONMENT_TAG,
		nullptr,
		INVALID_TAG,
		sound_environment_block );

	TAG_REFERENCE(global_sound_environment_reference, SOUND_ENVIRONMENT_TAG);

} // namespace macaque

} // namespace blofeld

