#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(game_globals_ordnance_list, GAME_GLOBALS_ORDNANCE_LIST_TAG, game_globals_ordnance_list_block_block );

	V5_TAG_GROUP_FROM_BLOCK(scenario_ordnance_list, SCENARIO_ORDNANCE_LIST_TAG, scenario_ordnance_list_block_block );

	V5_TAG_BLOCK(GameGlobalsOrdnanceBlock, k_maximumNumberOfMultiplayerOrdnanceSelections)
	{
		{ _field_legacy, _field_string_id, "ordnance name^" },
		{ _field_legacy, _field_string, "ordnance internal name!" },
		{ _field_legacy, _field_long_integer, "activation point cost" },
		{ _field_legacy, _field_string_id, "drop pod variant name#is pod with this power weapon, else if blank is remote strike (remote strike equipment)" },
		{ _field_legacy, _field_tag_reference, "remote strike equipment", &global_equipment_reference },
		{ _field_legacy, _field_byte_integer, "sequence index" },
		{ _field_legacy, _field_byte_integer, "equipment count" },
		{ _field_legacy, _field_byte_flags, "premium flag", &GuiOrdnancePrimiumFlag },
		{ _field_legacy, _field_pad, "PAD", 1 },
		{ _field_legacy, _field_real_point_3d, "navpoint marker offset*!" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(OrdnanceRemappingBlock, 128)
	{
		{ _field_legacy, _field_string_id, "from^#This must match one of the global ordnance objects." },
		{ _field_legacy, _field_string_id, "to^#This must match one of the global ordnance objects." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(OrdnanceRemappingVariantBlock, 64)
	{
		{ _field_legacy, _field_string_id, "name" },
		{ _field_legacy, _field_string, "internal name!" },
		{ _field_legacy, _field_block, "remappings", &OrdnanceRemappingBlock_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(game_globals_ordnance_list_block, 1, game_globals_ordnance_list_struct_definition_struct_definition );

	V5_TAG_BLOCK(RandomOrdnanceItemBlock, k_maximum_random_ordnance_items)
	{
		{ _field_legacy, _field_string_id, "ordnance_name^#This must match one of the global ordnance objects." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(PlayerOrdnanceItemBlock, 8)
	{
		{ _field_legacy, _field_string, "ordnance name^#This must match one of the global ordnance objects." },
		{ _field_legacy, _field_real, "ordnance frequency#chance that an ordnance from this group will be chosen" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(PlayerOrdnanceGroupBlock, 3)
	{
		{ _field_legacy, _field_block, "Player ordnance drops", &PlayerOrdnanceItemBlock_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(scenario_ordnance_list_block, 1, scenario_ordnance_list_struct_definition_struct_definition );

	V5_TAG_STRUCT(game_globals_ordnance_list_struct_definition)
	{
		{ _field_legacy, _field_real, "ordnance map width:world units" },
		{ _field_legacy, _field_real, "random ordnance fanfare duration:seconds" },
		{ _field_legacy, _field_tag_reference, "drop pod cleanup effect", &global_effect_reference },
		{ _field_legacy, _field_block, "ordnances", &GameGlobalsOrdnanceBlock_block },
		{ _field_legacy, _field_block, "ordnance remapping tables", &OrdnanceRemappingVariantBlock_block },
		{ _field_legacy, _field_real, "equipment invulnerable seconds" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(scenario_ordnance_list_struct_definition)
	{
		{ _field_legacy, _field_block, "Random ordnance drop list", &RandomOrdnanceItemBlock_block },
		{ _field_legacy, _field_block, "Player ordnance drop groups", &PlayerOrdnanceGroupBlock_block },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(GuiOrdnancePrimiumFlag)
	{
		"premium ordnance"
	};
	STRING_LIST(GuiOrdnancePrimiumFlag, GuiOrdnancePrimiumFlag_strings, _countof(GuiOrdnancePrimiumFlag_strings));

} // namespace blofeld

