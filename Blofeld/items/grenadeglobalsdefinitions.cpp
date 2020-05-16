#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(game_globals_grenade_list, GAME_GLOBALS_GRENADE_LIST_TAG, game_globals_grenade_list_block_block )

TAG_BLOCK_FROM_STRUCT(game_globals_grenade_list_block, 1, game_globals_grenade_list_struct_definition_struct_definition );

TAG_BLOCK(GameGlobalsGrenadeBlock, eUGT_count)
{
	FIELD( _field_short_integer, "maximum count" ),
	FIELD( _field_pad, "CXVLKJE", 2 ),
	FIELD( _field_short_integer, "initial count (Campaign)" ),
	FIELD( _field_short_integer, "initial count (Firefight)" ),
	FIELD( _field_short_integer, "initial count (Multiplayer)" ),
	FIELD( _field_short_integer, "grenadier extra count (Campaign)" ),
	FIELD( _field_short_integer, "grenadier extra count (Firefight)" ),
	FIELD( _field_short_integer, "grenadier extra count (Multiplayer)" ),
	FIELD( _field_real, "drop percentage (Campaign)" ),
	FIELD( _field_real, "drop percentage (Firefight)" ),
	FIELD( _field_real, "drop percentage (Multiplayer)" ),
	FIELD( _field_real, "resourceful scavenge percentage (Campaign)" ),
	FIELD( _field_real, "resourceful scavenge percentage (Firefight)" ),
	FIELD( _field_real, "resourceful scavenge percentage (Multiplayer)" ),
	FIELD( _field_tag_reference, "throwing effect" ),
	FIELD( _field_tag_reference, "equipment" ),
	FIELD( _field_tag_reference, "projectile" ),
	FIELD( _field_tag_reference, "equipment (PvE)" ),
	FIELD( _field_tag_reference, "projectile (PvE)" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(game_globals_grenade_list_struct_definition)
{
	FIELD( _field_block, "grenades", &GameGlobalsGrenadeBlock_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

