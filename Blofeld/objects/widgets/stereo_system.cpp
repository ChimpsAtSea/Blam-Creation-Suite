#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(stereo_system_struct_definition)
{
	FIELD( _field_long_integer, "unused" ),
	FIELD( _field_terminator )
};

TAG_GROUP(stereo_system_block, STEREO_SYSTEM_TAG)
{
	FIELD( _field_long_integer, "unused" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

