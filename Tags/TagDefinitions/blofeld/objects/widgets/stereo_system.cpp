#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(stereo_system, STEREO_SYSTEM_TAG, stereo_system_block_block );

	TAG_BLOCK_FROM_STRUCT(stereo_system_block, 1, stereo_system_struct_definition_struct_definition );

	TAG_STRUCT(stereo_system_struct_definition)
	{
		{ _field_long_integer, "unused" },
		{ _field_terminator }
	};

} // namespace blofeld

