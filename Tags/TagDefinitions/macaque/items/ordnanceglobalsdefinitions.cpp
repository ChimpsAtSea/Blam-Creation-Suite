#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		game_globals_ordnance_list_group,
		GAME_GLOBALS_ORDNANCE_LIST_TAG,
		nullptr,
		INVALID_TAG,
		game_globals_ordnance_list_block );

	TAG_GROUP(
		scenario_ordnance_list_group,
		SCENARIO_ORDNANCE_LIST_TAG,
		nullptr,
		INVALID_TAG,
		scenario_ordnance_list_block );

	TAG_BLOCK_FROM_STRUCT(
		game_globals_ordnance_list_block,
		"game_globals_ordnance_list_block",
		1,
		game_globals_ordnance_list_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		scenario_ordnance_list_block,
		"scenario_ordnance_list_block",
		1,
		scenario_ordnance_list_struct_definition);

	#define GAMEGLOBALSORDNANCEBLOCK_ID { 0xB1148A66, 0xD4744CB4, 0xAD66B2F7, 0x996F17D5 }
	TAG_BLOCK(
		GameGlobalsOrdnanceBlock_block,
		"GameGlobalsOrdnanceBlock",
		k_maximumNumberOfMultiplayerOrdnanceSelections,
		"OrdnanceLoadoutData",
		GAMEGLOBALSORDNANCEBLOCK_ID)
	{
		{ _field_string_id, "ordnance name" },
		{ _field_string, "ordnance internal name" },
		{ _field_long_integer, "activation point cost" },
		{ _field_string_id, "drop pod variant name", "is pod with this power weapon, else if blank is remote strike (remote strike equipment)" },
		{ _field_tag_reference, "remote strike equipment", &global_equipment_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "equipment count" },
		{ _field_byte_flags, "premium flag", &GuiOrdnancePrimiumFlag },
		FIELD_PAD("PAD", nullptr, 1),
		{ _field_real_point_3d, "navpoint marker offset" },
		{ _field_terminator }
	};

	#define ORDNANCEREMAPPINGVARIANTBLOCK_ID { 0x9AEAD981, 0xF9F147D4, 0x9D76F0E6, 0x1EA7C0E6 }
	TAG_BLOCK(
		OrdnanceRemappingVariantBlock_block,
		"OrdnanceRemappingVariantBlock",
		64,
		"OrdnanceRemappingVariant",
		ORDNANCEREMAPPINGVARIANTBLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_string, "internal name" },
		{ _field_block, "remappings", &OrdnanceRemappingBlock_block },
		{ _field_terminator }
	};

	#define ORDNANCEREMAPPINGBLOCK_ID { 0xF68C5861, 0xC7BA4AB4, 0xAC1388FD, 0x730ACEA8 }
	TAG_BLOCK(
		OrdnanceRemappingBlock_block,
		"OrdnanceRemappingBlock",
		128,
		"OrdnanceRemapping",
		ORDNANCEREMAPPINGBLOCK_ID)
	{
		{ _field_string_id, "from", "This must match one of the global ordnance objects." },
		{ _field_string_id, "to", "This must match one of the global ordnance objects." },
		{ _field_terminator }
	};

	#define RANDOMORDNANCEITEMBLOCK_ID { 0x055D5EEA, 0x705E45C9, 0xA93EEA28, 0x51622165 }
	TAG_BLOCK(
		RandomOrdnanceItemBlock_block,
		"RandomOrdnanceItemBlock",
		k_maximum_random_ordnance_items,
		"randomOrdnanceItem",
		RANDOMORDNANCEITEMBLOCK_ID)
	{
		{ _field_string_id, "ordnance_name", "This must match one of the global ordnance objects." },
		{ _field_terminator }
	};

	#define PLAYERORDNANCEGROUPBLOCK_ID { 0x5C352C76, 0xBB3449B2, 0xB202321F, 0xE2FC9E1C }
	TAG_BLOCK(
		PlayerOrdnanceGroupBlock_block,
		"PlayerOrdnanceGroupBlock",
		3,
		"playerOrdnanceGroup",
		PLAYERORDNANCEGROUPBLOCK_ID)
	{
		{ _field_block, "Player ordnance drops", &PlayerOrdnanceItemBlock_block },
		{ _field_terminator }
	};

	#define PLAYERORDNANCEITEMBLOCK_ID { 0x5FFE0CCB, 0x27E84523, 0xADA8BA59, 0x747B2D50 }
	TAG_BLOCK(
		PlayerOrdnanceItemBlock_block,
		"PlayerOrdnanceItemBlock",
		8,
		"playerOrdnanceItem",
		PLAYERORDNANCEITEMBLOCK_ID)
	{
		{ _field_string, "ordnance name", "This must match one of the global ordnance objects." },
		{ _field_real, "ordnance frequency", "chance that an ordnance from this group will be chosen" },
		{ _field_terminator }
	};

	#define GAME_GLOBALS_ORDNANCE_LIST_STRUCT_DEFINITION_ID { 0x7D88DCED, 0x1F3E433E, 0xB9099675, 0x33B8D47B }
	TAG_STRUCT(
		game_globals_ordnance_list_struct_definition,
		"game_globals_ordnance_list_struct_definition",
		"GameGlobalsOrdnance",
		GAME_GLOBALS_ORDNANCE_LIST_STRUCT_DEFINITION_ID)
	{
		{ _field_real, "ordnance map width", "world units" },
		{ _field_real, "random ordnance fanfare duration", "seconds" },
		{ _field_tag_reference, "drop pod cleanup effect", &global_effect_reference },
		{ _field_block, "ordnances", &GameGlobalsOrdnanceBlock_block },
		{ _field_block, "ordnance remapping tables", &OrdnanceRemappingVariantBlock_block },
		{ _field_real, "equipment invulnerable seconds" },
		{ _field_terminator }
	};

	#define SCENARIO_ORDNANCE_LIST_STRUCT_DEFINITION_ID { 0x23500DD2, 0x50D74522, 0xBBC8C5FD, 0x21E2B58C }
	TAG_STRUCT(
		scenario_ordnance_list_struct_definition,
		"scenario_ordnance_list_struct_definition",
		"ScenarioOrdnance",
		SCENARIO_ORDNANCE_LIST_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "Random ordnance drop list", &RandomOrdnanceItemBlock_block },
		{ _field_block, "Player ordnance drop groups", &PlayerOrdnanceGroupBlock_block },
		{ _field_terminator }
	};

	STRINGS(GuiOrdnancePrimiumFlag)
	{
		"premium ordnance"
	};
	STRING_LIST(GuiOrdnancePrimiumFlag, GuiOrdnancePrimiumFlag_strings, _countof(GuiOrdnancePrimiumFlag_strings));

} // namespace macaque

} // namespace blofeld

