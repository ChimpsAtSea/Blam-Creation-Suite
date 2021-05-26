#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		stereo_system_group,
		STEREO_SYSTEM_TAG,
		nullptr,
		INVALID_TAG,
		stereo_system_block );

	TAG_BLOCK_FROM_STRUCT(
		stereo_system_block,
		"stereo_system_block",
		1,
		stereo_system_struct_definition);

	#define STEREO_SYSTEM_STRUCT_DEFINITION_ID { 0x4B58B990, 0x4F154F6F, 0xA32235AE, 0xCFE62423 }
	TAG_STRUCT(
		stereo_system_struct_definition,
		"stereo_system_struct_definition",
		"stereo_system_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STEREO_SYSTEM_STRUCT_DEFINITION_ID)
	{
		{ _field_long_integer, "unused" },
		{ _field_terminator }
	};



} // namespace blofeld

