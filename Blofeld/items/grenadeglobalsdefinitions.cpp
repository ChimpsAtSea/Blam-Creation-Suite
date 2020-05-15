#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(GameGlobalsGrenadeBlock, eUGT_count)
{
	{ _field_short_integer, "maximum count" },
	{ _field_pad, "CXVLKJE", 2 },
	{ _field_short_integer, "initial count (Campaign)" },
	{ _field_short_integer, "initial count (Firefight)" },
	{ _field_short_integer, "initial count (Multiplayer)" },
	{ _field_short_integer, "grenadier extra count (Campaign)" },
	{ _field_short_integer, "grenadier extra count (Firefight)" },
	{ _field_short_integer, "grenadier extra count (Multiplayer)" },
	{ _field_real, "drop percentage (Campaign)" },
	{ _field_real, "drop percentage (Firefight)" },
	{ _field_real, "drop percentage (Multiplayer)" },
	{ _field_real, "resourceful scavenge percentage (Campaign)" },
	{ _field_real, "resourceful scavenge percentage (Firefight)" },
	{ _field_real, "resourceful scavenge percentage (Multiplayer)" },
	{ _field_tag_reference, "throwing effect" },
	{ _field_tag_reference, "equipment" },
	{ _field_tag_reference, "projectile" },
	{ _field_tag_reference, "equipment (PvE)" },
	{ _field_tag_reference, "projectile (PvE)" },
	{ _field_terminator },
};

TAG_GROUP(game_globals_grenade_list, GAME_GLOBALS_GRENADE_LIST_TAG)
{
	{ _field_block, "grenades", &GameGlobalsGrenadeBlock_block },
	{ _field_terminator },
};

} // namespace blofeld

