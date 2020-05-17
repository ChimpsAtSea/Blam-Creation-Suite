#pragma once

namespace blofeld
{

	extern const char* custom_app_flags$2_strings[];
	extern s_string_list_definition custom_app_flags$2;
	extern const char* custom_app_update_frequencies_strings[];
	extern s_string_list_definition custom_app_update_frequencies;

	constexpr unsigned long CUSTOM_APP_GLOBALS_TAG = 'capg';

	extern s_tag_group custom_app_globals_group;

	extern s_tag_block_definition custom_app_globals_block_block;
	extern s_tag_struct custom_app_block_block_struct;
	extern s_tag_block_definition custom_app_block_block;
	extern s_tag_struct custom_app_damage_modifier_block_block_struct;
	extern s_tag_block_definition custom_app_damage_modifier_block_block;

	extern s_tag_struct custom_app_globals_struct_definition_struct_definition; // tag group

} // namespace blofeld

