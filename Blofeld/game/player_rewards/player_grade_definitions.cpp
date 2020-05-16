#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(player_grade_globals_definition, PLAYER_GRADE_GLOBALS_DEFINITION_TAG, player_grade_globals_definition_block_block );

TAG_BLOCK_FROM_STRUCT(player_grade_globals_definition_block, 1, player_grade_globals_definition_struct_definition_struct_definition );

TAG_BLOCK(player_grade_definition_block, k_maxPlayerGradeCount)
{
	FIELD( _field_long_integer, "xp threshold #total earned XP needed to reach this rank" ),
	FIELD( _field_string_id, "name" ),
	FIELD( _field_short_integer, "sprite index" ),
	FIELD( _field_pad, "pad0", 2 ),
	FIELD( _field_real, "time played multiplier#This is an additional multiplier to rewards given for time played for players at this grade" ),
	FIELD( _field_block, "level up rewards#These rewards will be given to the player when they reach this grade", &rewardBlock_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(player_grade_globals_definition_struct_definition)
{
	FIELD( _field_block, "player grades", &player_grade_definition_block_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

