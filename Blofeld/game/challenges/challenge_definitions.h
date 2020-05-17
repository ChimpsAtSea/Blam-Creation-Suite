#pragma once

namespace blofeld
{

	constexpr unsigned long CHALLENGE_GLOBALS_DEFINITION_TAG = 'chdg';

	extern s_tag_group challenge_globals_definition_group;

	extern s_tag_struct_definition challenge_block_block_struct;
	extern s_tag_block_definition challenge_block_block;
	extern s_tag_struct_definition challenge_category_block_block_struct;
	extern s_tag_block_definition challenge_category_block_block;
	extern s_tag_block_definition challenge_globals_definition_block_block;


	extern s_tag_struct_definition challenge_globals_definition_struct_definition_struct_definition; // tag group

	extern const char* challenge_definition_flags_strings[];
	extern s_string_list_definition challenge_definition_flags;
	extern const char* challengeIconDefinition_strings[];
	extern s_string_list_definition challengeIconDefinition;
	extern const char* challenge_progress_flags_strings[];
	extern s_string_list_definition challenge_progress_flags;
	extern const char* challenge_category_enum_definition_strings[];
	extern s_string_list_definition challenge_category_enum_definition;
	extern const char* skull_flags_definition_strings[];
	extern s_string_list_definition skull_flags_definition;

} // namespace blofeld

