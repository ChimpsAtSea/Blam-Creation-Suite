#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(stereo_system, STEREO_SYSTEM_TAG, stereo_system_block_block );

	V5_TAG_BLOCK_FROM_STRUCT(stereo_system_block, 1, stereo_system_struct_definition_struct_definition );

	V5_TAG_STRUCT(stereo_system_struct_definition)
	{
		{ _field_legacy, _field_long_integer, "unused" },
		{ _field_legacy, _field_terminator }
	};

} // namespace blofeld

