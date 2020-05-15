#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(playerEnlistmentDefinitionBlock, k_maximumPlayerEnlistments - 1)
{
	{ _field_string_id, "name#the string id of the name of this enlistment" },
	{ _field_string_id, "description#the string id of the description of this enlistment" },
	{ _field_short_integer, "sprite index#the sprite index of the icon for this enlistment" },
	{ _field_byte_flags, "flags" },
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
	{ _field_block, "grades#the grades that define the leveling track for this enlistment", &player_grade_definition_block },
	{ _field_terminator },
};

TAG_GROUP(player_enlistment_globals_definition, PLAYER_ENLISTMENT_GLOBALS_DEFINITION_TAG)
{
	{ _field_explanation, "Enlistments" },
	{ _field_block, "enlistments", &playerEnlistmentDefinitionBlock_block },
	{ _field_terminator },
};

} // namespace blofeld

