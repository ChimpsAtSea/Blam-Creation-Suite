#pragma once

namespace blofeld
{



	constexpr unsigned long MATERIAL_TAG = 'mat ';
	extern s_tag_group material_group; // material_block
	extern s_tag_block_definition material_block;
	extern s_tag_struct_definition material_block_struct_definition; // material_block


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

	extern s_string_list_definition layerBlendModeEnum;
	extern s_string_list_definition materialPostprocessFlags;
	extern s_string_list_definition materialFlags;
	extern s_string_list_definition materialRenderFlags;
	extern s_string_list_definition MaterialTransparentShadowPolicyEnum;



} // namespace blofeld

