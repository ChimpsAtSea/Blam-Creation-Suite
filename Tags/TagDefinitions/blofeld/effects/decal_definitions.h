#pragma once

namespace blofeld
{

	constexpr unsigned long DECAL_SYSTEM_TAG = 'decs';

	extern s_tag_group decal_system_group;

	extern s_tag_struct_definition decal_definition_block_block_struct;
	extern s_tag_block_definition decal_definition_block_block;
	extern s_tag_block_definition decal_system_block_block;

	extern s_tag_struct_definition decal_system_struct_definition_struct_definition; // tag group

	extern c_versioned_string_list decal_flags_strings;
	extern s_string_list_definition decal_flags;
	extern c_versioned_string_list decal_system_flags_strings;
	extern s_string_list_definition decal_system_flags;

} // namespace blofeld

