#pragma once

namespace blofeld
{

	constexpr unsigned long CUSTOM_APP_GLOBALS_TAG = 'capg';

	extern s_tag_group custom_app_globals_group;

	extern s_tag_struct_definition custom_app_damage_modifier_block_block_struct;
	extern s_tag_block_definition custom_app_damage_modifier_block_block;
	extern s_tag_struct_definition custom_app_block_block_struct;
	extern s_tag_block_definition custom_app_block_block;
	extern s_tag_block_definition custom_app_globals_block_block;

	extern s_tag_struct_definition custom_app_globals_struct_definition_struct_definition; // tag group

	extern c_versioned_string_list custom_app_flags$2_strings;
	extern s_string_list_definition custom_app_flags$2;
	extern c_versioned_string_list custom_app_update_frequencies_strings;
	extern s_string_list_definition custom_app_update_frequencies;

	extern s_tag_reference_definition global_custom_app_globals_reference;

} // namespace blofeld

