#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(playerEnlistmentFlags, 1)
	{
		OPTION("disabled#since we can\'t reorder the list after ship, this allows us to disable/enable this enlistment"),
	};

	TAG_GROUP_FROM_BLOCK(player_enlistment_globals_definition, PLAYER_ENLISTMENT_GLOBALS_DEFINITION_TAG, player_enlistment_globals_definition_block_block );

	TAG_BLOCK_FROM_STRUCT(player_enlistment_globals_definition_block, 1, player_enlistment_globals_definition_struct_definition_struct_definition );

	TAG_BLOCK(playerEnlistmentDefinitionBlock, k_maximumPlayerEnlistments - 1)
	{
		FIELD( _field_string_id, "name#the string id of the name of this enlistment" ),
		FIELD( _field_string_id, "description#the string id of the description of this enlistment" ),
		FIELD( _field_short_integer, "sprite index#the sprite index of the icon for this enlistment" ),
		FIELD( _field_byte_flags, "flags", &playerEnlistmentFlags ),
		FIELD( _field_pad, "PAD0", 1 ),
		FIELD( _field_string_id, "unlocked emblem fg" ),
		FIELD( _field_string_id, "unlocked emblem bg" ),
		FIELD( _field_string_id, "unlocked helmet" ),
		FIELD( _field_string_id, "unlocked chest" ),
		FIELD( _field_string_id, "unlocked left shoulder" ),
		FIELD( _field_string_id, "unlocked right shoulder" ),
		FIELD( _field_string_id, "unlocked arms" ),
		FIELD( _field_string_id, "unlocked legs" ),
		FIELD( _field_string_id, "unlocked visor" ),
		FIELD( _field_block, "grades#the grades that define the leveling track for this enlistment", &player_grade_definition_block_block ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(player_enlistment_globals_definition_struct_definition)
{
		FIELD( _field_explanation, "Enlistments" ),
		FIELD( _field_block, "enlistments", &playerEnlistmentDefinitionBlock_block ),
		FIELD( _field_terminator )
};

} // namespace blofeld

