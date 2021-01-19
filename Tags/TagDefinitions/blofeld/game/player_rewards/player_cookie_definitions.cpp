#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(reward_globals_definition, REWARD_GLOBALS_DEFINITION_TAG, reward_globals_definition_block_block );

	V5_TAG_BLOCK(rewardDefinitionBlock, RewardGlobalDefinition::k_maximum_count)
	{
		{ _field_string_id, "name^" },
		{ _field_char_enum, "type", &rewardTypeEnum },
		{ _field_pad, "PJB1", 3 },
		{ _field_block, "rewards", &rewardBlock_block },
		{ _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(reward_globals_definition_block, 1, reward_globals_definition_struct_definition_struct_definition );

	V5_TAG_STRUCT(reward_globals_definition_struct_definition)
	{
		{ _field_block, "reward definitions{cookie awards}", &rewardDefinitionBlock_block },
		{ _field_terminator }
	};

	STRINGS(rewardTypeEnum)
	{
		"invasion",
		"bounties",
		"slot machine",
		"heat",
		"mission scripting",
		"commendation",
		"daily challenge",
		"achievement",
		"console scripting",
		"game complete",
		"time spent",
		"score",
		"winning",
		"hopper",
		"slot machinelsp_jackpot",
		"double_xp",
		"fast_track_armor"
	};
	STRING_LIST(rewardTypeEnum, rewardTypeEnum_strings, _countof(rewardTypeEnum_strings));

} // namespace blofeld

