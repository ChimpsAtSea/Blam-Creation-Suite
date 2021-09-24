#pragma once

namespace blofeld
{



	constexpr unsigned long PERFORMANCE_THROTTLES_TAG = 'perf';
	extern s_tag_group performance_throttles_group; // performance_throttles_block


	extern s_tag_block_definition performance_throttles_block;
	extern s_tag_block_definition performane_throttle_block;
	extern s_tag_struct_definition performane_throttle_block_struct_definition; // performane_throttle_block

	extern s_tag_struct_definition performance_throttles_struct_definition; // tag group

	extern s_string_list_definition performance_throttle_flags;

	extern s_tag_reference_definition global_performance_throttles_reference;



} // namespace blofeld

