#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(coop_spawning_globals_definition_struct_definition)
{
	FIELD( _field_short_integer, "player cooldown timer seconds" ),
	FIELD( _field_short_integer, "backfield cooldown timer seconds" ),
	FIELD( _field_short_integer, "unsafe spawn timer" ),
	FIELD( _field_short_integer, "teammate damage timer" ),
	FIELD( _field_short_integer, "dead body switch time" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_short_integer, "loadout menu spawn suppression time#maximal time that the loadout menu can prevent respawn while up" ),
	FIELD( _field_short_integer, "loadout menu cooldown time#cooldown time after loadout menu is dismissed before player spawns in" ),
	FIELD( _field_short_integer, "loadout menu initial choice time#time before players initially spawn in for choosing starting loadout" ),
	FIELD( _field_short_integer, "maximum spawn suppression time#maximal time that a player can continue to delay his spawn by switching targets" ),
	FIELD( _field_real, "nearby enemy cylinder height" ),
	FIELD( _field_real, "nearby enemy cylinder radius" ),
	FIELD( _field_custom, "Safety Statuses" ),
	FIELD( _field_long_enum, "ready#safe and ready to spawn - this value currently ignored" ),
	FIELD( _field_long_enum, "waiting#safe but waiting to spawn - this value currently ignored" ),
	FIELD( _field_long_enum, "enemy territory#spawn target is inside enemy territory volumes" ),
	FIELD( _field_long_enum, "teammate damaged#spawn target has recently taken damage" ),
	FIELD( _field_long_enum, "enemy nearby#There is an enemy within the cylinder around the spawn target" ),
	FIELD( _field_long_enum, "projectiles#There are dangerous projectiles in the area" ),
	FIELD( _field_custom ),
	FIELD( _field_real, "failover to influence spawning time#number of seconds before influence spawning will be used (<= 0 is disabled)" ),
	FIELD( _field_terminator )
};

TAG_GROUP(coop_spawning_globals_definition_block, COOP_SPAWNING_GLOBALS_DEFINITION_TAG)
{
	FIELD( _field_short_integer, "player cooldown timer seconds" ),
	FIELD( _field_short_integer, "backfield cooldown timer seconds" ),
	FIELD( _field_short_integer, "unsafe spawn timer" ),
	FIELD( _field_short_integer, "teammate damage timer" ),
	FIELD( _field_short_integer, "dead body switch time" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_short_integer, "loadout menu spawn suppression time#maximal time that the loadout menu can prevent respawn while up" ),
	FIELD( _field_short_integer, "loadout menu cooldown time#cooldown time after loadout menu is dismissed before player spawns in" ),
	FIELD( _field_short_integer, "loadout menu initial choice time#time before players initially spawn in for choosing starting loadout" ),
	FIELD( _field_short_integer, "maximum spawn suppression time#maximal time that a player can continue to delay his spawn by switching targets" ),
	FIELD( _field_real, "nearby enemy cylinder height" ),
	FIELD( _field_real, "nearby enemy cylinder radius" ),
	FIELD( _field_custom, "Safety Statuses" ),
	FIELD( _field_long_enum, "ready#safe and ready to spawn - this value currently ignored" ),
	FIELD( _field_long_enum, "waiting#safe but waiting to spawn - this value currently ignored" ),
	FIELD( _field_long_enum, "enemy territory#spawn target is inside enemy territory volumes" ),
	FIELD( _field_long_enum, "teammate damaged#spawn target has recently taken damage" ),
	FIELD( _field_long_enum, "enemy nearby#There is an enemy within the cylinder around the spawn target" ),
	FIELD( _field_long_enum, "projectiles#There are dangerous projectiles in the area" ),
	FIELD( _field_custom ),
	FIELD( _field_real, "failover to influence spawning time#number of seconds before influence spawning will be used (<= 0 is disabled)" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

