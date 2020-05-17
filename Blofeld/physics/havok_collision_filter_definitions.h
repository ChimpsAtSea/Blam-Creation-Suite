#pragma once

namespace blofeld
{

	extern const char* collision_filter_enum_strings[];
	extern s_string_list_definition collision_filter_enum;

	constexpr unsigned long HAVOK_COLLISION_FILTER_TAG = 'hcfd';

	extern s_tag_group havok_collision_filter_group;

	extern s_tag_block_definition havok_collision_filter_block_block;
	extern s_tag_struct havok_collision_filter_group_block_block_struct;
	extern s_tag_block_definition havok_collision_filter_group_block_block;

	extern s_tag_struct havok_collision_filter_struct_definition_struct_definition; // tag group
	extern s_tag_struct havok_group_filter_filter_struct_struct_definition;

} // namespace blofeld

