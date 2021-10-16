#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		player_enlistment_globals_definition_group,
		PLAYER_ENLISTMENT_GLOBALS_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		player_enlistment_globals_definition_block );

	TAG_BLOCK_FROM_STRUCT(
		player_enlistment_globals_definition_block,
		"player_enlistment_globals_definition_block",
		1,
		player_enlistment_globals_definition_struct_definition);

	#define PLAYERENLISTMENTDEFINITIONBLOCK_ID { 0x4E1F9AFD, 0x505D40F2, 0xA048FABB, 0xC8D79F05 }
	TAG_BLOCK(
		playerEnlistmentDefinitionBlock_block,
		"playerEnlistmentDefinitionBlock",
		k_maximumPlayerEnlistments - 1,
		"PlayerEnlistmentDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PLAYERENLISTMENTDEFINITIONBLOCK_ID)
	{
		{ _field_string_id, "name", "the string id of the name of this enlistment" },
		{ _field_string_id, "description", "the string id of the description of this enlistment" },
		{ _field_short_integer, "sprite index", "the sprite index of the icon for this enlistment" },
		{ _field_byte_flags, "flags", &playerEnlistmentFlags },
		FIELD_PAD_EX("PAD0", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_string_id, "unlocked emblem fg" },
		{ _field_string_id, "unlocked emblem bg" },
		{ _field_string_id, "unlocked helmet" },
		{ _field_string_id, "unlocked chest" },
		{ _field_string_id, "unlocked left shoulder" },
		{ _field_string_id, "unlocked right shoulder" },
		{ _field_string_id, "unlocked arms" },
		{ _field_string_id, "unlocked legs" },
		{ _field_string_id, "unlocked visor" },
		{ _field_block, "grades", "the grades that define the leveling track for this enlistment", &player_grade_definition_block },
		{ _field_terminator }
	};

	#define PLAYER_ENLISTMENT_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID { 0x4F115FB8, 0x7BE8489F, 0xBFFFE0D8, 0x36B4D323 }
	TAG_STRUCT_V6(
		player_enlistment_globals_definition_struct_definition,
		"player_enlistment_globals_definition_struct_definition",
		"PlayerEnlistmentGlobalsDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PLAYER_ENLISTMENT_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION_EX("Enlistments", nullptr, FIELD_FLAG_NONE, "!!! DO NOT, UNDER ANY CIRCUMSTANCES, REORDER THIS BLOCK AFTER SHIP !!!"),
		{ _field_block, "enlistments", &playerEnlistmentDefinitionBlock_block },
		{ _field_terminator }
	};

	STRINGS(playerEnlistmentFlags)
	{
		"disabled#since we can\'t reorder the list after ship, this allows us to disable/enable this enlistment"
	};
	STRING_LIST(playerEnlistmentFlags, playerEnlistmentFlags_strings, _countof(playerEnlistmentFlags_strings));



} // namespace blofeld

