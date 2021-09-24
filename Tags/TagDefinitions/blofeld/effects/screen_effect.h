#pragma once

namespace blofeld
{



	constexpr unsigned long AREA_SCREEN_EFFECT_TAG = 'sefc';
	extern s_tag_group area_screen_effect_group; // area_screen_effect_block


	extern s_tag_block_definition area_screen_effect_block;
	extern s_tag_block_definition single_screen_effect_block;
	extern s_tag_struct_definition single_screen_effect_block_struct_definition; // single_screen_effect_block

	extern s_tag_struct_definition area_screen_effect_struct_definition; // tag group
	extern s_tag_struct_definition screen_effect_scalar_function_struct;
	extern s_tag_struct_definition screen_effect_scalar_object_function_struct;

	extern s_string_list_definition area_screen_effect_global_flags_definition;
	extern s_string_list_definition area_screen_effect_global_hidden_flags_definition;
	extern s_string_list_definition area_screen_effect_flags_definition;
	extern s_string_list_definition area_screen_effect_hidden_flags_definition;

	extern s_tag_reference_definition global_area_screen_effect_reference;
	extern s_tag_reference_definition global_screen_shader_reference;



} // namespace blofeld

