#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(rewardDefinitionBlock, RewardGlobalDefinition::k_maximum_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_char_enum, "type" ),
	FIELD( _field_pad, "PJB1", 3 ),
	FIELD( _field_block, "rewards", &rewardBlock_block ),
	FIELD( _field_terminator )
};

TAG_GROUP(reward_globals_definition, REWARD_GLOBALS_DEFINITION_TAG)
{
	FIELD( _field_block, "reward definitions{cookie awards}", &rewardDefinitionBlock_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

