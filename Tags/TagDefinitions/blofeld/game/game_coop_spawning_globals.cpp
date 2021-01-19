#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(coop_spawning_globals_definition, COOP_SPAWNING_GLOBALS_DEFINITION_TAG, coop_spawning_globals_definition_block_block );

	V5_TAG_BLOCK_FROM_STRUCT(coop_spawning_globals_definition_block, 1, coop_spawning_globals_definition_struct_definition_struct_definition );

	V5_TAG_STRUCT(coop_spawning_globals_definition_struct_definition)
	{
		{ _field_short_integer, "player cooldown timer seconds" },
		{ _field_short_integer, "backfield cooldown timer seconds" },
		{ _field_short_integer, "unsafe spawn timer" },
		{ _field_short_integer, "teammate damage timer" },
		{ _field_short_integer, "dead body switch time" },
		{ _field_word_flags, "flags", &coop_spawning_flags },
		{ _field_short_integer, "loadout menu spawn suppression time#maximal time that the loadout menu can prevent respawn while up" },
		{ _field_short_integer, "loadout menu cooldown time#cooldown time after loadout menu is dismissed before player spawns in" },
		{ _field_short_integer, "loadout menu initial choice time#time before players initially spawn in for choosing starting loadout" },
		{ _field_short_integer, "maximum spawn suppression time#maximal time that a player can continue to delay his spawn by switching targets" },
		{ _field_real, "nearby enemy cylinder height" },
		{ _field_real, "nearby enemy cylinder radius" },
		{ _field_custom, "Safety Statuses" },
		{ _field_long_enum, "ready#safe and ready to spawn - this value currently ignored", &safety_check_mode_enum },
		{ _field_long_enum, "waiting#safe but waiting to spawn - this value currently ignored", &safety_check_mode_enum },
		{ _field_long_enum, "enemy territory#spawn target is inside enemy territory volumes", &safety_check_mode_enum },
		{ _field_long_enum, "teammate damaged#spawn target has recently taken damage", &safety_check_mode_enum },
		{ _field_long_enum, "enemy nearby#There is an enemy within the cylinder around the spawn target", &safety_check_mode_enum },
		{ _field_long_enum, "projectiles#There are dangerous projectiles in the area", &safety_check_mode_enum },
		{ _field_custom },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_real, "failover to influence spawning time#number of seconds before influence spawning will be used (<= 0 is disabled)" },

		{ _field_terminator }
	};

	STRINGS(coop_spawning_flags)
	{
		"push to spawn enabled#allow loadout menu to delay spawn",
		"show marker on respawn player",
		"extermination syncs timers",
		"extermination syncs location",
		"rotation allowed on player",
		"rotation allowed on object",
		"display loadouts if changed",
		"always display loadouts on death",
		"disable spartan respawn on player",
		"disable spartan respawn on backfield",
		"disable elite respawn on player",
		"disable elite respawn on backfield"
	};
	STRING_LIST(coop_spawning_flags, coop_spawning_flags_strings, _countof(coop_spawning_flags_strings));

	STRINGS(safety_check_mode_enum)
	{
		"has no effect",
		"displays warning",
		"prevents spawn"
	};
	STRING_LIST(safety_check_mode_enum, safety_check_mode_enum_strings, _countof(safety_check_mode_enum_strings));

	TAG_REFERENCE(global_coop_spawning_globals_reference, COOP_SPAWNING_GLOBALS_DEFINITION_TAG);

} // namespace blofeld

