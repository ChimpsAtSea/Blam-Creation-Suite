#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(coop_spawning_globals_definition, COOP_SPAWNING_GLOBALS_DEFINITION_TAG)
{
	{ _field_short_integer, "player cooldown timer seconds" },
	{ _field_short_integer, "backfield cooldown timer seconds" },
	{ _field_short_integer, "unsafe spawn timer" },
	{ _field_short_integer, "teammate damage timer" },
	{ _field_short_integer, "dead body switch time" },
	{ _field_word_flags, "flags" },
	{ _field_short_integer, "loadout menu spawn suppression time#maximal time that the loadout menu can prevent respawn while up" },
	{ _field_short_integer, "loadout menu cooldown time#cooldown time after loadout menu is dismissed before player spawns in" },
	{ _field_short_integer, "loadout menu initial choice time#time before players initially spawn in for choosing starting loadout" },
	{ _field_short_integer, "maximum spawn suppression time#maximal time that a player can continue to delay his spawn by switching targets" },
	{ _field_real, "nearby enemy cylinder height" },
	{ _field_real, "nearby enemy cylinder radius" },
	{ _field_custom, "Safety Statuses" },
	{ _field_long_enum, "ready#safe and ready to spawn - this value currently ignored" },
	{ _field_long_enum, "waiting#safe but waiting to spawn - this value currently ignored" },
	{ _field_long_enum, "enemy territory#spawn target is inside enemy territory volumes" },
	{ _field_long_enum, "teammate damaged#spawn target has recently taken damage" },
	{ _field_long_enum, "enemy nearby#There is an enemy within the cylinder around the spawn target" },
	{ _field_long_enum, "projectiles#There are dangerous projectiles in the area" },
	{ _field_custom },
	{ _field_real, "failover to influence spawning time#number of seconds before influence spawning will be used (<= 0 is disabled)" },
	{ _field_terminator },
};

} // namespace blofeld

