#pragma once

namespace blofeld
{

	extern const char* pathfinding_policy_enum$2_strings[];
	extern s_string_list_definition pathfinding_policy_enum$2;
	extern const char* lightmapping_policy_enum_strings[];
	extern s_string_list_definition lightmapping_policy_enum;
	extern const char* scenery_flags_strings[];
	extern s_string_list_definition scenery_flags;

	constexpr unsigned long SCENERY_TAG = 'scen';

	extern s_tag_group scenery_group;

	extern s_tag_block_definition scenery_block_block;

	extern s_tag_struct scenery_group_struct_definition; // tag group

} // namespace blofeld

