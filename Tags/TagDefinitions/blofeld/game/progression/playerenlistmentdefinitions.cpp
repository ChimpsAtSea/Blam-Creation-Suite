#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(player_enlistment_globals_definition, PLAYER_ENLISTMENT_GLOBALS_DEFINITION_TAG, player_enlistment_globals_definition_block_block );

	TAG_BLOCK(playerEnlistmentDefinitionBlock, k_maximumPlayerEnlistments - 1)
	{
		{ _field_string_id, "name#the string id of the name of this enlistment" },
		{ _field_string_id, "description#the string id of the description of this enlistment" },
		{ _field_short_integer, "sprite index#the sprite index of the icon for this enlistment" },
		{ _field_byte_flags, "flags", &playerEnlistmentFlags },
		{ _field_pad, "PAD0", 1 },
		{ _field_string_id, "unlocked emblem fg" },
		{ _field_string_id, "unlocked emblem bg" },
		{ _field_string_id, "unlocked helmet" },
		{ _field_string_id, "unlocked chest" },
		{ _field_string_id, "unlocked left shoulder" },
		{ _field_string_id, "unlocked right shoulder" },
		{ _field_string_id, "unlocked arms" },
		{ _field_string_id, "unlocked legs" },
		{ _field_string_id, "unlocked visor" },
		{ _field_block, "grades#the grades that define the leveling track for this enlistment", &player_grade_definition_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(player_enlistment_globals_definition_block, 1, player_enlistment_globals_definition_struct_definition_struct_definition );

	TAG_STRUCT(player_enlistment_globals_definition_struct_definition)
	{
		{ _field_explanation, "Enlistments", "!!! DO NOT, UNDER ANY CIRCUMSTANCES, REORDER THIS BLOCK AFTER SHIP !!!" },
		{ _field_block, "enlistments", &playerEnlistmentDefinitionBlock_block },
		{ _field_terminator }
	};

	STRINGS(playerEnlistmentFlags)
	{
		"disabled#since we can\'t reorder the list after ship, this allows us to disable/enable this enlistment"
	};
	STRING_LIST(playerEnlistmentFlags, playerEnlistmentFlags_strings, _countof(playerEnlistmentFlags_strings));

} // namespace blofeld

