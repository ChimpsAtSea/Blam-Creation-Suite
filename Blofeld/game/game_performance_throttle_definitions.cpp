#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(game_performance_throttle_struct_definition)
{
	FIELD( _field_block, "entries", &game_performance_throttle_entries_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(game_performance_throttle_filter_struct)
{
	FIELD( _field_long_integer, "minimum player count" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(game_performance_throttle_profile_struct)
{
	FIELD( _field_long_integer, "maximum havok proxy count" ),
	FIELD( _field_long_integer, "maximum ragdoll count" ),
	FIELD( _field_long_integer, "maximum impact count" ),
	FIELD( _field_long_integer, "vehicle suspension update frequency" ),
	FIELD( _field_long_integer, "Actor LOD, AI actors to update fully each frame" ),
	FIELD( _field_long_integer, "Actor LOD, Number of frames to tick LODed AI" ),
	FIELD( _field_long_integer, "Actor LOD, Number of concurrent LOD actors to tick" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_performance_throttle_entries_block, 32)
{
	FIELD( _field_struct, "filter", &game_performance_throttle_filter_struct_struct_definition ),
	FIELD( _field_struct, "profile", &game_performance_throttle_profile_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_GROUP(game_performance_throttle_block, GAME_PERFORMANCE_THROTTLE_TAG)
{
	FIELD( _field_block, "entries", &game_performance_throttle_entries_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

