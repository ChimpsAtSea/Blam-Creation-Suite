#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_team_role, k_multiplayer_team_game_team_count)
{
	{ _field_long_flags, "flags!" },
	{ _field_enum, "team^!" },
	{ _field_pad, "QVO", 2 },
	{ _field_block, "player roles", &player_role_block },
	{ _field_terminator },
};

TAG_BLOCK(player_role, k_maximum_number_of_game_engine_roles)
{
	{ _field_string_id, "role name^" },
	{ _field_long_flags, "flags!" },
	{ _field_tag_reference, "primary weapon" },
	{ _field_short_integer, "primary weapon rounds loaded" },
	{ _field_short_integer, "primary weapon rounds total" },
	{ _field_tag_reference, "secondary weapon" },
	{ _field_short_integer, "secondary weapon rounds loaded" },
	{ _field_short_integer, "secondary weapon rounds total" },
	{ _field_short_integer, "frag grenade count" },
	{ _field_short_integer, "plasma grenade count" },
	{ _field_short_integer, "UNUSED!" },
	{ _field_short_integer, "spawn location index!" },
	{ _field_tag_reference, "starting equipment!" },
	{ _field_string, "display name" },
	{ _field_long_flags, "installed apps" },
	{ _field_long_integer, "killstreak bonus time:secs" },
	{ _field_real, "movement speed multiplier" },
	{ _field_tag_reference, "killstreak bonus equipment" },
	{ _field_tag_reference, "killstreak bonus activation sound" },
	{ _field_terminator },
};

} // namespace blofeld

