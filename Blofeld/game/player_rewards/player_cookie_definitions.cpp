#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(reward_globals_definition_struct_definition)
{
	FIELD( _field_block, "reward definitions{cookie awards}", &rewardDefinitionBlock ),
	FIELD( _field_terminator )
};

TAG_BLOCK(rewardDefinitionBlock, RewardGlobalDefinition::k_maximum_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_char_enum, "type" ),
	FIELD( _field_pad, "PJB1", 3 ),
	FIELD( _field_block, "rewards", &rewardBlock ),
	FIELD( _field_terminator )
};

TAG_GROUP(reward_globals_definition_block, REWARD_GLOBALS_DEFINITION_TAG)
{
	FIELD( _field_block, "reward definitions{cookie awards}", &rewardDefinitionBlock ),
	FIELD( _field_terminator )
};

} // namespace blofeld

