#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(coop_spawning_globals_definition, COOP_SPAWNING_GLOBALS_DEFINITION_TAG, coop_spawning_globals_definition_block_block );

	TAG_BLOCK_FROM_STRUCT(coop_spawning_globals_definition_block, 1, coop_spawning_globals_definition_struct_definition_struct_definition );

	TAG_STRUCT(coop_spawning_globals_definition_struct_definition)
	{
		FIELD( _field_short_integer, "player cooldown timer seconds" ),
		FIELD( _field_short_integer, "backfield cooldown timer seconds" ),
		FIELD( _field_short_integer, "unsafe spawn timer" ),
		FIELD( _field_short_integer, "teammate damage timer" ),
		FIELD( _field_short_integer, "dead body switch time" ),
		FIELD( _field_word_flags, "flags", &coop_spawning_flags ),
		FIELD( _field_short_integer, "loadout menu spawn suppression time#maximal time that the loadout menu can prevent respawn while up" ),
		FIELD( _field_short_integer, "loadout menu cooldown time#cooldown time after loadout menu is dismissed before player spawns in" ),
		FIELD( _field_short_integer, "loadout menu initial choice time#time before players initially spawn in for choosing starting loadout" ),
		FIELD( _field_short_integer, "maximum spawn suppression time#maximal time that a player can continue to delay his spawn by switching targets" ),
		FIELD( _field_real, "nearby enemy cylinder height" ),
		FIELD( _field_real, "nearby enemy cylinder radius" ),
		FIELD( _field_custom, "Safety Statuses" ),
		FIELD( _field_long_enum, "ready#safe and ready to spawn - this value currently ignored", &safety_check_mode_enum ),
		FIELD( _field_long_enum, "waiting#safe but waiting to spawn - this value currently ignored", &safety_check_mode_enum ),
		FIELD( _field_long_enum, "enemy territory#spawn target is inside enemy territory volumes", &safety_check_mode_enum ),
		FIELD( _field_long_enum, "teammate damaged#spawn target has recently taken damage", &safety_check_mode_enum ),
		FIELD( _field_long_enum, "enemy nearby#There is an enemy within the cylinder around the spawn target", &safety_check_mode_enum ),
		FIELD( _field_long_enum, "projectiles#There are dangerous projectiles in the area", &safety_check_mode_enum ),
		FIELD( _field_custom ),
		FIELD( _field_real, "failover to influence spawning time#number of seconds before influence spawning will be used (<= 0 is disabled)" ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(coop_spawning_flags, 12)
	{
		OPTION("push to spawn enabled#allow loadout menu to delay spawn"),
		OPTION("show marker on respawn player"),
		OPTION("extermination syncs timers"),
		OPTION("extermination syncs location"),
		OPTION("rotation allowed on player"),
		OPTION("rotation allowed on object"),
		OPTION("display loadouts if changed"),
		OPTION("always display loadouts on death"),
		OPTION("disable spartan respawn on player"),
		OPTION("disable spartan respawn on backfield"),
		OPTION("disable elite respawn on player"),
		OPTION("disable elite respawn on backfield"),
	};

	TAG_ENUM(safety_check_mode_enum, 3)
	{
		OPTION("has no effect"),
		OPTION("displays warning"),
		OPTION("prevents spawn"),
	};

} // namespace blofeld

