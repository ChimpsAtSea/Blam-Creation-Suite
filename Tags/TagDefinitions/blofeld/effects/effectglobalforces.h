#pragma once

namespace blofeld
{

	constexpr unsigned long EFFECT_GLOBAL_FORCE_TAG = 'egfd';

	extern s_tag_group effect_global_force_group;

	extern s_tag_block_definition effect_global_force_block_block;

	extern s_tag_struct_definition effect_global_force_struct_definition_struct_definition; // tag group

	extern c_versioned_string_list globalForceFlags_strings;
	extern s_string_list_definition globalForceFlags;

} // namespace blofeld

