#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(game_globals_ordnance_list_struct_definition)
{
	FIELD( _field_real, "ordnance map width:world units" ),
	FIELD( _field_real, "random ordnance fanfare duration:seconds" ),
	FIELD( _field_tag_reference, "drop pod cleanup effect" ),
	FIELD( _field_block, "ordnances", &GameGlobalsOrdnanceBlock ),
	FIELD( _field_block, "ordnance remapping tables", &OrdnanceRemappingVariantBlock ),
	FIELD( _field_real, "equipment invulnerable seconds" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(scenario_ordnance_list_struct_definition)
{
	FIELD( _field_block, "Random ordnance drop list", &RandomOrdnanceItemBlock ),
	FIELD( _field_block, "Player ordnance drop groups", &PlayerOrdnanceGroupBlock ),
	FIELD( _field_terminator )
};

TAG_BLOCK(GameGlobalsOrdnanceBlock, k_maximumNumberOfMultiplayerOrdnanceSelections)
{
	FIELD( _field_string_id, "ordnance name^" ),
	FIELD( _field_string, "ordnance internal name!" ),
	FIELD( _field_long_integer, "activation point cost" ),
	FIELD( _field_string_id, "drop pod variant name#is pod with this power weapon, else if blank is remote strike (remote strike equipment)" ),
	FIELD( _field_tag_reference, "remote strike equipment" ),
	FIELD( _field_byte_integer, "sequence index" ),
	FIELD( _field_byte_integer, "equipment count" ),
	FIELD( _field_byte_flags, "premium flag" ),
	FIELD( _field_pad, "PAD", 1 ),
	FIELD( _field_real_point_3d, "navpoint marker offset*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(OrdnanceRemappingVariantBlock, 64)
{
	FIELD( _field_string_id, "name" ),
	FIELD( _field_string, "internal name!" ),
	FIELD( _field_block, "remappings", &OrdnanceRemappingBlock ),
	FIELD( _field_terminator )
};

TAG_BLOCK(OrdnanceRemappingBlock, 128)
{
	FIELD( _field_string_id, "from^#This must match one of the global ordnance objects." ),
	FIELD( _field_string_id, "to^#This must match one of the global ordnance objects." ),
	FIELD( _field_terminator )
};

TAG_BLOCK(RandomOrdnanceItemBlock, k_maximum_random_ordnance_items)
{
	FIELD( _field_string_id, "ordnance_name^#This must match one of the global ordnance objects." ),
	FIELD( _field_terminator )
};

TAG_BLOCK(PlayerOrdnanceGroupBlock, 3)
{
	FIELD( _field_block, "Player ordnance drops", &PlayerOrdnanceItemBlock ),
	FIELD( _field_terminator )
};

TAG_BLOCK(PlayerOrdnanceItemBlock, 8)
{
	FIELD( _field_string, "ordnance name^#This must match one of the global ordnance objects." ),
	FIELD( _field_real, "ordnance frequency#chance that an ordnance from this group will be chosen" ),
	FIELD( _field_terminator )
};

TAG_GROUP(game_globals_ordnance_list_block, GAME_GLOBALS_ORDNANCE_LIST_TAG)
{
	FIELD( _field_real, "ordnance map width:world units" ),
	FIELD( _field_real, "random ordnance fanfare duration:seconds" ),
	FIELD( _field_tag_reference, "drop pod cleanup effect" ),
	FIELD( _field_block, "ordnances", &GameGlobalsOrdnanceBlock ),
	FIELD( _field_block, "ordnance remapping tables", &OrdnanceRemappingVariantBlock ),
	FIELD( _field_real, "equipment invulnerable seconds" ),
	FIELD( _field_terminator )
};

TAG_GROUP(scenario_ordnance_list_block, SCENARIO_ORDNANCE_LIST_TAG)
{
	FIELD( _field_block, "Random ordnance drop list", &RandomOrdnanceItemBlock ),
	FIELD( _field_block, "Player ordnance drop groups", &PlayerOrdnanceGroupBlock ),
	FIELD( _field_terminator )
};

} // namespace blofeld

