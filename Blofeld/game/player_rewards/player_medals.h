#pragma once

namespace blofeld
{

	extern const char* medal_class_enum_strings[];
	extern s_string_list_definition medal_class_enum;

	constexpr unsigned long GAME_MEDAL_GLOBALS_TAG = 'gmeg';

	extern s_tag_group game_medal_globals_group;

	extern s_tag_block_definition game_medal_globals_block_block;
	extern s_tag_struct gameMedalTiers_block_struct;
	extern s_tag_block_definition gameMedalTiers_block;
	extern s_tag_struct game_medal_block_block_struct;
	extern s_tag_block_definition game_medal_block_block;

	extern s_tag_struct game_medal_globals_struct_definition_struct_definition; // tag group

} // namespace blofeld

