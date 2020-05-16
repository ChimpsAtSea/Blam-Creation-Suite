#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(game_completion_rewards_globals, GAME_COMPLETION_REWARDS_GLOBALS_TAG, game_completion_rewards_globals_block_block )

TAG_BLOCK_FROM_STRUCT(game_completion_rewards_globals_block, 1, game_completion_rewards_globals_struct_definition_struct_definition );

TAG_BLOCK(game_completion_rewards_difficulty_block, 1)
{
	FIELD( _field_block, "easy matchmaking#this block is used for easy matchmade games", &game_completion_rewards_definition_block_block ),
	FIELD( _field_block, "normal matchmaking#this block is used for normal matchmade games", &game_completion_rewards_definition_block_block ),
	FIELD( _field_block, "heroic matchmaking#this block is used for heroic matchmade games", &game_completion_rewards_definition_block_block ),
	FIELD( _field_block, "legendary matchmaking#this block is used for legendary matchmade games", &game_completion_rewards_definition_block_block ),
	FIELD( _field_block, "custom#this block is used for custom games", &game_completion_rewards_definition_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_completion_rewards_definition_block, eCT_count)
{
	FIELD( _field_long_integer, "initial amount per minute{initial cookies per minute}#base amount of reward given for each minute of play up until the start of the falloff curve" ),
	FIELD( _field_real, "hopper scaling factor#the player\'s time-based reward value is multiplied by this factor before being awarded; this value can be overridden by the hopper" ),
	FIELD( _field_real, "winner scaling factor#if the player is an unambiguous winner, their time-based reward value is multiplied by (this factor - 1) and the result is awarded as a bonus; this value can be overridden by the hopper" ),
	FIELD( _field_real, "performance scaling factor#if the player is not a winner, but is in the top half of the standings, their time-based reward is multiplied by (this factor - 1) and the result is awarded as a bonus; this value can be overriden by the hopper" ),
	FIELD( _field_real, "score scaling factor#for score-based modes, the player\'s normalized score (0..1) is multiplied by this scaling factor and the result is awarded to the player as a bonus; this value can be overridden by the hopper" ),
	FIELD( _field_block, "apm falloff curve{cpm falloff curve}#amount per minute falloff curve; used to provide diminishing returns for longer play time", &game_completion_rewards_falloff_point_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_completion_rewards_falloff_point_block, s_game_completion_rewards_globals::k_max_falloff_curve_points)
{
	FIELD( _field_short_integer, "start time#minutes into the game after which this new reward rate applies" ),
	FIELD( _field_short_integer, "amount per minute{cookies per minute}#points awarded per minute once the given time is reached" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_completion_rewards_multiplayer_block, 1)
{
	FIELD( _field_block, "matchmaking#this block is used for matchmade games", &game_completion_rewards_definition_block_block ),
	FIELD( _field_block, "custom#this block is used for custom games", &game_completion_rewards_definition_block_block ),
	FIELD( _field_block, "unused0!", &game_completion_rewards_definition_block_block ),
	FIELD( _field_block, "unused1!", &game_completion_rewards_definition_block_block ),
	FIELD( _field_block, "unused2!", &game_completion_rewards_definition_block_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(game_completion_rewards_globals_struct_definition)
{
	FIELD( _field_block, "campaign#rewards given for playing campaign games online", &game_completion_rewards_difficulty_block_block ),
	FIELD( _field_block, "firefight#rewards given for playing firefight games online", &game_completion_rewards_difficulty_block_block ),
	FIELD( _field_block, "multiplayer#rewards given for playing PvP multiplayer games online", &game_completion_rewards_multiplayer_block_block ),
	FIELD( _field_real, "fast track armor modifier#this multiplier is applied to the combined reward of timespent, score and performance, multiplied by the percentage time the player has the armor mod active" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

