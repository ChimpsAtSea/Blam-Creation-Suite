#pragma once

namespace blofeld
{

	constexpr unsigned long MATERIAL_EFFECTS_TAG = 'foot';

	extern s_tag_struct_definition material_effects_block_struct;
	extern s_tag_block_definition material_effects_block;
	extern s_tag_group material_effects_group;

	extern s_tag_struct_definition old_material_effect_material_block_block_struct;
	extern s_tag_block_definition old_material_effect_material_block_block;
	extern s_tag_struct_definition material_effect_material_block_block_struct;
	extern s_tag_block_definition material_effect_material_block_block;
	extern s_tag_struct_definition material_effect_block_v2_block_struct;
	extern s_tag_block_definition material_effect_block_v2_block;


	extern const char* sweeneter_mode_enum_strings[];
	extern s_string_list_definition sweeneter_mode_enum;

	extern s_tag_reference_definition global_material_effects_reference;

} // namespace blofeld

