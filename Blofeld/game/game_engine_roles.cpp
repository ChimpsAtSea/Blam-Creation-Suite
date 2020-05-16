#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_team_role_block, k_multiplayer_team_game_team_count)
{
	FIELD( _field_long_flags, "flags!" ),
	FIELD( _field_enum, "team^!" ),
	FIELD( _field_pad, "QVO", 2 ),
	FIELD( _field_block, "player roles", &player_role_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(player_role_block, k_maximum_number_of_game_engine_roles)
{
	FIELD( _field_string_id, "role name^" ),
	FIELD( _field_long_flags, "flags!" ),
	FIELD( _field_tag_reference, "primary weapon" ),
	FIELD( _field_short_integer, "primary weapon rounds loaded" ),
	FIELD( _field_short_integer, "primary weapon rounds total" ),
	FIELD( _field_tag_reference, "secondary weapon" ),
	FIELD( _field_short_integer, "secondary weapon rounds loaded" ),
	FIELD( _field_short_integer, "secondary weapon rounds total" ),
	FIELD( _field_short_integer, "frag grenade count" ),
	FIELD( _field_short_integer, "plasma grenade count" ),
	FIELD( _field_short_integer, "UNUSED!" ),
	FIELD( _field_short_integer, "spawn location index!" ),
	FIELD( _field_tag_reference, "starting equipment!" ),
	FIELD( _field_string, "display name" ),
	FIELD( _field_long_flags, "installed apps" ),
	FIELD( _field_long_integer, "killstreak bonus time:secs" ),
	FIELD( _field_real, "movement speed multiplier" ),
	FIELD( _field_tag_reference, "killstreak bonus equipment" ),
	FIELD( _field_tag_reference, "killstreak bonus activation sound" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

