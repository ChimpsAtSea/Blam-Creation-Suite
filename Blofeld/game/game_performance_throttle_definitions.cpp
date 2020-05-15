#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(game_performance_throttle_entries, 32)
{
	FIELD( _field_struct, "filter" ),
	FIELD( _field_struct, "profile" ),
	FIELD( _field_terminator )
};

TAG_GROUP(game_performance_throttle, GAME_PERFORMANCE_THROTTLE_TAG)
{
	FIELD( _field_block, "entries", &game_performance_throttle_entries_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

