#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(GameGlobalsOrdnanceBlock, k_maximumNumberOfMultiplayerOrdnanceSelections)
{
	{ _field_string_id, "ordnance name^" },
	{ _field_string, "ordnance internal name!" },
	{ _field_long_integer, "activation point cost" },
	{ _field_string_id, "drop pod variant name#is pod with this power weapon, else if blank is remote strike (remote strike equipment)" },
	{ _field_tag_reference, "remote strike equipment" },
	{ _field_byte_integer, "sequence index" },
	{ _field_byte_integer, "equipment count" },
	{ _field_byte_flags, "premium flag" },
	{ _field_pad, "PAD", 1 },
	{ _field_real_point_3d, "navpoint marker offset*!" },
	{ _field_terminator },
};

TAG_BLOCK(OrdnanceRemappingVariantBlock, 64)
{
	{ _field_string_id, "name" },
	{ _field_string, "internal name!" },
	{ _field_block, "remappings", &OrdnanceRemappingBlock_block },
	{ _field_terminator },
};

TAG_BLOCK(OrdnanceRemappingBlock, 128)
{
	{ _field_string_id, "from^#This must match one of the global ordnance objects." },
	{ _field_string_id, "to^#This must match one of the global ordnance objects." },
	{ _field_terminator },
};

TAG_BLOCK(RandomOrdnanceItemBlock, k_maximum_random_ordnance_items)
{
	{ _field_string_id, "ordnance_name^#This must match one of the global ordnance objects." },
	{ _field_terminator },
};

TAG_BLOCK(PlayerOrdnanceGroupBlock, 3)
{
	{ _field_block, "Player ordnance drops", &PlayerOrdnanceItemBlock_block },
	{ _field_terminator },
};

TAG_BLOCK(PlayerOrdnanceItemBlock, 8)
{
	{ _field_string, "ordnance name^#This must match one of the global ordnance objects." },
	{ _field_real, "ordnance frequency#chance that an ordnance from this group will be chosen" },
	{ _field_terminator },
};

TAG_GROUP(game_globals_ordnance_list, GAME_GLOBALS_ORDNANCE_LIST_TAG)
{
	{ _field_real, "ordnance map width:world units" },
	{ _field_real, "random ordnance fanfare duration:seconds" },
	{ _field_tag_reference, "drop pod cleanup effect" },
	{ _field_block, "ordnances", &GameGlobalsOrdnanceBlock_block },
	{ _field_block, "ordnance remapping tables", &OrdnanceRemappingVariantBlock_block },
	{ _field_real, "equipment invulnerable seconds" },
	{ _field_terminator },
};

TAG_GROUP(scenario_ordnance_list, SCENARIO_ORDNANCE_LIST_TAG)
{
	{ _field_block, "Random ordnance drop list", &RandomOrdnanceItemBlock_block },
	{ _field_block, "Player ordnance drop groups", &PlayerOrdnanceGroupBlock_block },
	{ _field_terminator },
};

} // namespace blofeld

