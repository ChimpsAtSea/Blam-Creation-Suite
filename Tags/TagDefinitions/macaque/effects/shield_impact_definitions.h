#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long SHIELD_IMPACT_TAG = 'shit';
	extern s_tag_group shield_impact_group; // shield_impact_block


	extern s_tag_block_definition shield_impact_block;

	extern s_tag_struct_definition shield_impact_struct_definition; // tag group
	extern s_tag_struct_definition shield_color_function_struct;
	extern s_tag_struct_definition shield_scalar_function_struct;

	extern c_versioned_string_list shield_flags_strings;
	extern s_string_list_definition shield_flags;

	extern s_tag_reference_definition global_shield_parameters_reference;

} // namespace macaque

} // namespace blofeld

