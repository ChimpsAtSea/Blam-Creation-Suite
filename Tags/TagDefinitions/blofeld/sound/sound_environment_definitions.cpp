#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define SOUND_ENVIRONMENT_STRUCT_DEFINITION_ID { 0x9AB4B8F2, 0x64524BEC, 0x9D4F14BA, 0x2A6D23A4 }
	TAG_BLOCK(
		sound_environment_block,
		"sound_environment_block",
		1,
		"sound_environment",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_ENVIRONMENT_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION_EX("Reverb Settings", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "reverb settings", &global_sound_reverb_block },
		FIELD_EXPLANATION_EX("Forced Lowpass", nullptr, FIELD_FLAG_NONE, "This will override obstruction and occlusion if you set the cutoff frequency to a non-zero value. Use the individual classes\' \"forced lowpass wet mix\" value to alter the mix."),
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



} // namespace blofeld

