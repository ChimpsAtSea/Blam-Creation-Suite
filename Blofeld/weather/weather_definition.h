#pragma once

namespace blofeld
{

	extern const char* rain_particle_flags_strings[];
	extern s_string_list_definition rain_particle_flags;

	constexpr unsigned long RAIN_DEFINITION_TAG = 'rain';

	extern s_tag_group rain_definition_group;

	extern s_tag_block_definition rain_definition_block_block;

	extern s_tag_struct rain_definition_struct_definition_struct_definition; // tag group

} // namespace blofeld

