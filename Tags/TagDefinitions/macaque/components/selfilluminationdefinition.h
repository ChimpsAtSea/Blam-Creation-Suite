#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long SELF_ILLUMINATION_TAG = 'sict';
	extern s_tag_group self_illumination_group; // self_illumination_block


	extern s_tag_block_definition self_illumination_block;
	extern s_tag_block_definition self_illumination_state_block;
	extern s_tag_struct_definition self_illumination_state_block_struct_definition; // self_illumination_state_block

	extern s_tag_struct_definition self_illumination_struct_definition; // tag group

	extern c_versioned_string_list self_illumination_flags_strings;
	extern s_string_list_definition self_illumination_flags;

} // namespace macaque

} // namespace blofeld

