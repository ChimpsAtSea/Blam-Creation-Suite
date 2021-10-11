#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		game_globals_grenade_list_group,
		GAME_GLOBALS_GRENADE_LIST_TAG,
		nullptr,
		INVALID_TAG,
		game_globals_grenade_list_block );

	TAG_BLOCK_FROM_STRUCT(
		game_globals_grenade_list_block,
		"game_globals_grenade_list_block",
		1,
		game_globals_grenade_list_struct_definition);

	#define GAMEGLOBALSGRENADEBLOCK_ID { 0xFB5FD410, 0x43B74B07, 0x94CDA4F5, 0x19F43A56 }
	TAG_BLOCK(
		GameGlobalsGrenadeBlock_block,
		"GameGlobalsGrenadeBlock",
		eUGT_count,
		"GameGlobalsGrenade",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAMEGLOBALSGRENADEBLOCK_ID)
	{
		{ _field_short_integer, "maximum count" },
		FIELD_PAD_EX("CXVLKJE", nullptr, FIELD_FLAG_NONE, 2),
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
		{ _field_tag_reference, "throwing effect", &Tag::Reference<struct effect_definition>::s_defaultDefinition },
		{ _field_tag_reference, "equipment", &Tag::Reference<struct equipment_definition>::s_defaultDefinition },
		{ _field_tag_reference, "projectile", &Tag::Reference<struct projectile_definition>::s_defaultDefinition },
		{ _field_tag_reference, "equipment (PvE)", &Tag::Reference<struct equipment_definition>::s_defaultDefinition },
		{ _field_tag_reference, "projectile (PvE)", &Tag::Reference<struct projectile_definition>::s_defaultDefinition },
		{ _field_terminator }
	};

	#define GAME_GLOBALS_GRENADE_LIST_STRUCT_DEFINITION_ID { 0x6AFD3548, 0xBE4A445D, 0xAA007E0A, 0x90F4AA84 }
	TAG_STRUCT(
		game_globals_grenade_list_struct_definition,
		"game_globals_grenade_list_struct_definition",
		"GameGlobalsGrenadeList",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_GLOBALS_GRENADE_LIST_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "grenades", &GameGlobalsGrenadeBlock_block },
		{ _field_terminator }
	};

	STRINGS(global_grenade_type_enum)
	{
		"human fragmentation",
		"covenant plasma",
		"pulse grenade",
		"grenade type 3",
		"grenade type 4",
		"grenade type 5",
		"grenade type 6",
		"grenade type 7"
	};
	STRING_LIST(global_grenade_type_enum, global_grenade_type_enum_strings, _countof(global_grenade_type_enum_strings));



} // namespace blofeld

