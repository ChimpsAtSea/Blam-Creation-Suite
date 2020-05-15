#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(game_performance_throttle_entries, 32)
{
	{ _field_struct, "filter" },
	{ _field_struct, "profile" },
	{ _field_terminator },
};

TAG_GROUP(game_performance_throttle, GAME_PERFORMANCE_THROTTLE_TAG)
{
	{ _field_block, "entries", &game_performance_throttle_entries_block },
	{ _field_terminator },
};

} // namespace blofeld

