#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(player_grade_definition, k_maxPlayerGradeCount)
{
	{ _field_long_integer, "xp threshold #total earned XP needed to reach this rank" },
	{ _field_string_id, "name" },
	{ _field_short_integer, "sprite index" },
	{ _field_pad, "pad0", 2 },
	{ _field_real, "time played multiplier#This is an additional multiplier to rewards given for time played for players at this grade" },
	{ _field_block, "level up rewards#These rewards will be given to the player when they reach this grade", &rewardBlock_block },
	{ _field_terminator },
};

TAG_GROUP(player_grade_globals_definition, PLAYER_GRADE_GLOBALS_DEFINITION_TAG)
{
	{ _field_block, "player grades", &player_grade_definition_block },
	{ _field_terminator },
};

} // namespace blofeld

