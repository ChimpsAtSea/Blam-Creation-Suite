#pragma once

namespace blofeld
{

	constexpr unsigned long LEAF_SYSTEM_TAG = 'lswd';

	extern s_tag_group leaf_system_group;

	extern s_tag_struct_definition leaf_type_block_block_struct;
	extern s_tag_block_definition leaf_type_block_block;
	extern s_tag_block_definition leaf_system_block_block;


	extern s_tag_struct_definition leaf_system_struct_definition_struct_definition; // tag group

	extern const char* leaf_flags$2_strings[];
	extern s_string_list_definition leaf_flags$2;

} // namespace blofeld

