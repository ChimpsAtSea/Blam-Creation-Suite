#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long GAME_PERFORMANCE_THROTTLE_TAG = 'gptd';
	extern s_tag_group game_performance_throttle_group; // game_performance_throttle_block


	extern s_tag_block_definition game_performance_throttle_block;
	extern s_tag_block_definition game_performance_throttle_entries_block;
	extern s_tag_struct_definition game_performance_throttle_entries_block_struct_definition; // game_performance_throttle_entries_block

	extern s_tag_struct_definition game_performance_throttle_struct_definition; // tag group
	extern s_tag_struct_definition game_performance_throttle_filter_struct;
	extern s_tag_struct_definition game_performance_throttle_profile_struct;

} // namespace macaque

} // namespace blofeld

