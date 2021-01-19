#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long CAMO_TAG = 'cmoe';
	extern s_tag_group camo_group; // camo_block


	extern s_tag_block_definition camo_block;

	extern s_tag_struct_definition camo_struct_definition; // tag group
	extern s_tag_struct_definition camo_scalar_function_struct;

	extern c_versioned_string_list camo_flags_strings;
	extern s_string_list_definition camo_flags;

} // namespace macaque

} // namespace blofeld

