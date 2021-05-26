#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
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
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		REWARDDEFINITIONBLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_char_enum, "type", &rewardTypeEnum },
		FIELD_PAD("PJB1", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_block, "rewards", &rewardBlock_block },
		{ _field_terminator }
	};

	#define REWARD_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID { 0x78615FBC, 0x4B164E69, 0xA8272FE7, 0x4E40CB80 }
	TAG_STRUCT(
		reward_globals_definition_struct_definition,
		"reward_globals_definition_struct_definition",
		"RewardGlobalsDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		REWARD_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "reward definitions", MAKE_OLD_NAMES("cookie awards"), &rewardDefinitionBlock_block },
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

