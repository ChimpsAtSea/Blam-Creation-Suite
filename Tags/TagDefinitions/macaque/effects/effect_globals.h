#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long EFFECT_GLOBALS_TAG = 'effg';
	extern s_tag_group effect_globals_group; // effect_globals_block


	extern s_tag_block_definition effect_globals_block;
	extern s_tag_block_definition effect_component_holdbacks_block;
	extern s_tag_struct_definition effect_component_holdbacks_block_struct_definition; // effect_component_holdbacks_block
	extern s_tag_block_definition effect_component_holdback_block;
	extern s_tag_struct_definition effect_component_holdback_block_struct_definition; // effect_component_holdback_block
	extern s_tag_block_definition effect_global_spawn_effects_block;
	extern s_tag_struct_definition effect_global_spawn_effects_block_struct_definition; // effect_global_spawn_effects_block

	extern s_tag_struct_definition effect_globals_struct_definition; // tag group

	extern c_versioned_string_list global_effect_priority_enum_strings;
	extern s_string_list_definition global_effect_priority_enum;
	extern c_versioned_string_list effect_holdback_type_enum_strings;
	extern s_string_list_definition effect_holdback_type_enum;

	extern s_tag_reference_definition global_effect_globals_reference;

} // namespace macaque

} // namespace blofeld

