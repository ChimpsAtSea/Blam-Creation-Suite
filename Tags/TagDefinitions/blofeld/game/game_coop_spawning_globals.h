#pragma once

namespace blofeld
{



	constexpr unsigned long COOP_SPAWNING_GLOBALS_DEFINITION_TAG = 'coop';
	extern s_tag_group coop_spawning_globals_definition_group; // coop_spawning_globals_definition_block


	extern s_tag_block_definition coop_spawning_globals_definition_block;

	extern s_tag_struct_definition coop_spawning_globals_definition_struct_definition; // tag group

	extern c_versioned_string_list coop_spawning_flags_strings;
	extern s_string_list_definition coop_spawning_flags;
	extern c_versioned_string_list safety_check_mode_enum_strings;
	extern s_string_list_definition safety_check_mode_enum;

	extern s_tag_reference_definition global_coop_spawning_globals_reference;



} // namespace blofeld

