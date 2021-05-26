#pragma once

namespace blofeld
{



	constexpr unsigned long REWARD_GLOBALS_DEFINITION_TAG = 'cook';
	extern s_tag_group reward_globals_definition_group; // reward_globals_definition_block


	extern s_tag_block_definition reward_globals_definition_block;
	extern s_tag_block_definition rewardDefinitionBlock_block;
	extern s_tag_struct_definition rewardDefinitionBlock_block_struct_definition; // rewardDefinitionBlock_block

	extern s_tag_struct_definition reward_globals_definition_struct_definition; // tag group

	extern c_versioned_string_list rewardTypeEnum_strings;
	extern s_string_list_definition rewardTypeEnum;



} // namespace blofeld

