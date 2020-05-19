#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(player_role_block, k_maximum_number_of_game_engine_roles)
	{
		{ _field_string_id, "role name^" },
		{ _field_long_flags, "flags!", &player_role_flags },
		{ _field_tag_reference, "primary weapon", &weapon_reference$4 },
		{ _field_short_integer, "primary weapon rounds loaded" },
		{ _field_short_integer, "primary weapon rounds total" },
		{ _field_tag_reference, "secondary weapon", &weapon_reference$4 },
		{ _field_short_integer, "secondary weapon rounds loaded" },
		{ _field_short_integer, "secondary weapon rounds total" },
		{ _field_short_integer, "frag grenade count" },
		{ _field_short_integer, "plasma grenade count" },
		{ _field_short_integer, "UNUSED!" },
		{ _field_short_integer, "spawn location index!" },
		{ _field_tag_reference, "starting equipment!", &global_equipment_reference },
		{ _field_string, "display name" },
		{ _field_long_flags, "installed apps", &custom_app_flags },
		{ _field_long_integer, "killstreak bonus time:secs" },
		{ _field_real, "movement speed multiplier" },
		{ _field_tag_reference, "killstreak bonus equipment", &global_equipment_reference },
		{ _field_tag_reference, "killstreak bonus activation sound", &global_sound_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(global_team_role_block, k_multiplayer_team_game_team_count)
	{
		{ _field_long_flags, "flags!", &team_role_flags },
		{ _field_enum, "team^!", &global_multiplayer_team_designator_enum_definition },
		{ _field_pad, "QVO", 2 },
		{ _field_block, "player roles", &player_role_block_block },
		{ _field_terminator }
	};

	STRINGS(player_role_flags)
	{
		"UNUSED"
	};
	STRING_LIST(player_role_flags, player_role_flags_strings, _countof(player_role_flags_strings));

	STRINGS(custom_app_flags)
	{
		"Weightless",
		"Defiance",
		"Maltreat",
		"Recharge",
		"Impervious",
		"Exploiter",
		"Momentum",
		"Reclaim",
		"Detector",
		"Scrimmage",
		"Sprint",
		"Twofold",
		"Supplement",
		"Manifest"
	};
	STRING_LIST(custom_app_flags, custom_app_flags_strings, _countof(custom_app_flags_strings));

	STRINGS(team_role_flags)
	{
		"UNUSED"
	};
	STRING_LIST(team_role_flags, team_role_flags_strings, _countof(team_role_flags_strings));

} // namespace blofeld

