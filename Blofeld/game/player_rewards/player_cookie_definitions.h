#pragma once

namespace blofeld
{

	extern const char* rewardTypeEnum_strings[];
	extern s_string_list_definition rewardTypeEnum;

	constexpr unsigned long REWARD_GLOBALS_DEFINITION_TAG = 'cook';

	extern s_tag_group reward_globals_definition_group;

	extern s_tag_block_definition reward_globals_definition_block_block;
	extern s_tag_struct rewardDefinitionBlock_block_struct;
	extern s_tag_block_definition rewardDefinitionBlock_block;

	extern s_tag_struct reward_globals_definition_struct_definition_struct_definition; // tag group

} // namespace blofeld

