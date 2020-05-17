#pragma once

namespace blofeld
{

	extern const char* coop_spawning_flags_strings[];
	extern s_string_list_definition coop_spawning_flags;
	extern const char* safety_check_mode_enum_strings[];
	extern s_string_list_definition safety_check_mode_enum;

	constexpr unsigned long COOP_SPAWNING_GLOBALS_DEFINITION_TAG = 'coop';

	extern s_tag_group coop_spawning_globals_definition_group;

	extern s_tag_block_definition coop_spawning_globals_definition_block_block;

	extern s_tag_struct coop_spawning_globals_definition_struct_definition_struct_definition; // tag group

} // namespace blofeld

