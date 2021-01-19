#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		reward_globals_definition_group,
		REWARD_GLOBALS_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		reward_globals_definition_block );

	TAG_BLOCK_FROM_STRUCT(
		reward_globals_definition_block,
		"reward_globals_definition_block",
		1,
		reward_globals_definition_struct_definition);

	#define REWARDDEFINITIONBLOCK_ID { 0x093E5D8A, 0xA9E7437D, 0x807AAE8F, 0xD94A13A7 }
	TAG_BLOCK(
		rewardDefinitionBlock_block,
		"rewardDefinitionBlock",
		RewardGlobalDefinition::k_maximum_count,
		"RewardGlobalDefinition",
		REWARDDEFINITIONBLOCK_ID)
	{
		{ _field_string_id, "name^" },
		{ _field_char_enum, "type", &rewardTypeEnum },
		{ _field_pad, "PJB1", 3 },
		{ _field_block, "rewards", &rewardBlock_block },
		{ _field_terminator }
	};

	#define REWARD_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID { 0x78615FBC, 0x4B164E69, 0xA8272FE7, 0x4E40CB80 }
	TAG_STRUCT(
		reward_globals_definition_struct_definition,
		"reward_globals_definition_struct_definition",
		"RewardGlobalsDefinition",
		REWARD_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID)
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

} // namespace macaque

} // namespace blofeld

