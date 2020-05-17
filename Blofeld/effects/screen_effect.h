#pragma once

namespace blofeld
{

	extern const char* area_screen_effect_global_flags_definition_strings[];
	extern s_string_list_definition area_screen_effect_global_flags_definition;
	extern const char* area_screen_effect_global_hidden_flags_definition_strings[];
	extern s_string_list_definition area_screen_effect_global_hidden_flags_definition;
	extern const char* area_screen_effect_flags_definition_strings[];
	extern s_string_list_definition area_screen_effect_flags_definition;
	extern const char* area_screen_effect_hidden_flags_definition_strings[];
	extern s_string_list_definition area_screen_effect_hidden_flags_definition;

	constexpr unsigned long AREA_SCREEN_EFFECT_TAG = 'sefc';

	extern s_tag_group area_screen_effect_group;

	extern s_tag_block_definition area_screen_effect_block_block;
	extern s_tag_struct single_screen_effect_block_struct;
	extern s_tag_block_definition single_screen_effect_block;

	extern s_tag_struct area_screen_effect_struct_definition_struct_definition; // tag group
	extern s_tag_struct screen_effect_scalar_function_struct_struct_definition;
	extern s_tag_struct screen_effect_scalar_object_function_struct_struct_definition;

} // namespace blofeld

