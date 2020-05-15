#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(rewardDefinitionBlock, RewardGlobalDefinition::k_maximum_count)
{
	{ _field_string_id, "name^" },
	{ _field_char_enum, "type" },
	{ _field_pad, "PJB1", 3 },
	{ _field_block, "rewards", &rewardBlock_block },
	{ _field_terminator },
};

TAG_GROUP(reward_globals_definition, REWARD_GLOBALS_DEFINITION_TAG)
{
	{ _field_block, "reward definitions{cookie awards}", &rewardDefinitionBlock_block },
	{ _field_terminator },
};

} // namespace blofeld

