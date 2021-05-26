#pragma once

namespace blofeld
{



	constexpr unsigned long BIG_BATTLE_CREATURE_TAG = 'bbcr';
	extern s_tag_group big_battle_creature_group; // big_battle_creature_block
	extern s_tag_block_definition big_battle_creature_block;
	extern s_tag_struct_definition big_battle_creature_block_struct_definition; // big_battle_creature_block

	constexpr unsigned long CREATURE_TAG = 'crea';
	extern s_tag_group creature_group; // creature_block


	extern s_tag_block_definition creature_block;
	extern s_tag_block_definition creature_scalar_timing_block;
	extern s_tag_struct_definition creature_scalar_timing_block_struct_definition; // creature_scalar_timing_block

	extern s_tag_struct_definition creature_struct_definition; // tag group

	extern c_versioned_string_list creature_big_battle_definition_flags_strings;
	extern s_string_list_definition creature_big_battle_definition_flags;
	extern c_versioned_string_list creature_definition_flags_strings;
	extern s_string_list_definition creature_definition_flags;
	extern c_versioned_string_list unit_default_teams_strings;
	extern s_string_list_definition unit_default_teams;



} // namespace blofeld

