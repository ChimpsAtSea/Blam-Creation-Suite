#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define GLOBAL_TEAM_ROLE_BLOCK_ID { 0x971A7EDE, 0x2F8D426C, 0x9FE80DD7, 0x1DD603FB }
	TAG_BLOCK(
		global_team_role_block,
		"global_team_role_block",
		k_multiplayer_team_game_team_count,
		"s_team_role",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_TEAM_ROLE_BLOCK_ID)
	{
		{ _field_long_flags, "flags", FIELD_FLAG_UNKNOWN0, &team_role_flags },
		{ _field_enum, "team", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_INDEX, &global_multiplayer_team_designator_enum_definition },
		FIELD_PAD_EX("QVO", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "player roles", &player_role_block },
		{ _field_terminator }
	};

	#define PLAYER_ROLE_BLOCK_ID { 0x78742FC8, 0x50AC4EBE, 0xB0892D25, 0x6C8578CB }
	TAG_BLOCK(
		player_role_block,
		"player_role_block",
		k_maximum_number_of_game_engine_roles,
		"s_player_role",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PLAYER_ROLE_BLOCK_ID)
	{
		{ _field_string_id, "role name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", FIELD_FLAG_UNKNOWN0, &player_role_flags },
		{ _field_tag_reference, "primary weapon", &weapon_reference$4 },
		{ _field_short_integer, "primary weapon rounds loaded" },
		{ _field_short_integer, "primary weapon rounds total" },
		{ _field_tag_reference, "secondary weapon", &weapon_reference$4 },
		{ _field_short_integer, "secondary weapon rounds loaded" },
		{ _field_short_integer, "secondary weapon rounds total" },
		{ _field_short_integer, "frag grenade count" },
		{ _field_short_integer, "plasma grenade count" },
		{ _field_short_integer, "UNUSED", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "spawn location index", FIELD_FLAG_UNKNOWN0 },
		{ _field_tag_reference, "starting equipment", FIELD_FLAG_UNKNOWN0, &global_equipment_reference },
		{ _field_string, "display name" },
		{ _field_long_flags, "installed apps", &custom_app_flags },
		{ _field_long_integer, "killstreak bonus time", nullptr, "secs" },
		{ _field_real, "movement speed multiplier" },
		{ _field_tag_reference, "killstreak bonus equipment", &global_equipment_reference },
		{ _field_tag_reference, "killstreak bonus activation sound", &global_sound_reference },
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

