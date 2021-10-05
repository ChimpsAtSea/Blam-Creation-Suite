#pragma once

namespace blofeld
{



	constexpr unsigned long HAVOK_COLLISION_FILTER_TAG = 'hcfd';
	extern s_tag_group havok_collision_filter_group; // havok_collision_filter_block


	extern s_tag_block_definition havok_collision_filter_block;
	extern s_tag_block_definition havok_collision_filter_group_block;
	extern s_tag_struct_definition havok_collision_filter_group_block_struct_definition; // havok_collision_filter_group_block

	extern s_tag_struct_definition havok_collision_filter_struct_definition; // tag group
	extern s_tag_struct_definition havok_group_filter_filter_struct;

	extern s_string_list_definition collision_filter_enum;



} // namespace blofeld

