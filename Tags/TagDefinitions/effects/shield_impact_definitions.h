#pragma once

namespace blofeld
{

	constexpr unsigned long SHIELD_IMPACT_TAG = 'shit';

	extern s_tag_group shield_impact_group;

	extern s_tag_block_definition shield_impact_block_block;

	extern s_tag_struct_definition shield_impact_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition shield_color_function_struct_struct_definition;
	extern s_tag_struct_definition shield_scalar_function_struct_struct_definition;

	extern const char* shield_flags_strings[];
	extern s_string_list_definition shield_flags;

	extern s_tag_reference_definition global_shield_parameters_reference;

} // namespace blofeld

