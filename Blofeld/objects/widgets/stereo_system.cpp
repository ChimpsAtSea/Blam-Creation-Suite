#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(stereo_system, STEREO_SYSTEM_TAG, stereo_system_block_block );

	TAG_BLOCK_FROM_STRUCT(stereo_system_block, 1, stereo_system_struct_definition_struct_definition );

TAG_STRUCT(stereo_system_struct_definition)
{
		FIELD( _field_long_integer, "unused" ),
		FIELD( _field_terminator )
};

} // namespace blofeld

