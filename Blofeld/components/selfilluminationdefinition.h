#pragma once

namespace blofeld
{

	constexpr unsigned long SELF_ILLUMINATION_TAG = 'sict';

	extern s_tag_group self_illumination_group;

	extern s_tag_struct_definition self_illumination_state_block_struct;
	extern s_tag_block_definition self_illumination_state_block;
	extern s_tag_block_definition self_illumination_block_block;


	extern s_tag_struct_definition self_illumination_struct_definition_struct_definition; // tag group

	extern const char* self_illumination_flags_strings[];
	extern s_string_list_definition self_illumination_flags;

} // namespace blofeld

