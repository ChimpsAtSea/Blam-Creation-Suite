#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long MATERIAL_TAG = 'mat ';
	extern s_tag_group material_group; // material_block
	extern s_tag_block_definition material_block;
	extern s_tag_struct_definition material; // material_block


	extern s_tag_block_definition material_postprocess_block;
	extern s_tag_struct_definition material_postprocess_block_struct_definition; // material_postprocess_block
	extern s_tag_block_definition material_postprocess_texture_block;
	extern s_tag_struct_definition material_postprocess_texture_block_struct_definition; // material_postprocess_texture_block
	extern s_tag_block_definition real_vector4d_block$3_block;
	extern s_tag_struct_definition real_vector4d_block$3_block_struct_definition; // real_vector4d_block$3_block
	extern s_tag_block_definition int_block$3_block;
	extern s_tag_struct_definition int_block$3_block_struct_definition; // int_block$3_block
	extern s_tag_block_definition functionParameterBlock_block;
	extern s_tag_struct_definition functionParameterBlock_block_struct_definition; // functionParameterBlock_block
	extern s_tag_block_definition externParameterBlock_block;
	extern s_tag_struct_definition externParameterBlock_block_struct_definition; // externParameterBlock_block

	extern s_tag_struct_definition runtime_queryable_properties$3_array_struct_definition;
	extern s_tag_array_definition runtime_queryable_properties$3_array;
	extern s_tag_struct_definition material_struct;

	extern c_versioned_string_list layerBlendModeEnum_strings;
	extern s_string_list_definition layerBlendModeEnum;
	extern c_versioned_string_list materialPostprocessFlags_strings;
	extern s_string_list_definition materialPostprocessFlags;
	extern c_versioned_string_list materialFlags_strings;
	extern s_string_list_definition materialFlags;
	extern c_versioned_string_list materialRenderFlags_strings;
	extern s_string_list_definition materialRenderFlags;
	extern c_versioned_string_list MaterialTransparentShadowPolicyEnum_strings;
	extern s_string_list_definition MaterialTransparentShadowPolicyEnum;

} // namespace macaque

} // namespace blofeld

