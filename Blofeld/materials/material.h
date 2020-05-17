#pragma once

namespace blofeld
{

	extern const char* layerBlendModeEnum_strings[];
	extern s_string_list_definition layerBlendModeEnum;
	extern const char* materialPostprocessFlags_strings[];
	extern s_string_list_definition materialPostprocessFlags;
	extern const char* materialFlags_strings[];
	extern s_string_list_definition materialFlags;
	extern const char* materialRenderFlags_strings[];
	extern s_string_list_definition materialRenderFlags;
	extern const char* MaterialTransparentShadowPolicyEnum_strings[];
	extern s_string_list_definition MaterialTransparentShadowPolicyEnum;

	constexpr unsigned long MATERIAL_TAG = 'mat ';

	extern s_tag_struct material_block_struct;
	extern s_tag_block_definition material_block;
	extern s_tag_group material_group;

	extern s_tag_struct material_postprocess_block_block_struct;
	extern s_tag_block_definition material_postprocess_block_block;
	extern s_tag_struct material_postprocess_texture_block_block_struct;
	extern s_tag_block_definition material_postprocess_texture_block_block;
	extern s_tag_struct real_vector4d_block$3_block_struct;
	extern s_tag_block_definition real_vector4d_block$3_block;
	extern s_tag_struct int_block$3_block_struct;
	extern s_tag_block_definition int_block$3_block;
	extern s_tag_struct functionParameterBlock_block_struct;
	extern s_tag_block_definition functionParameterBlock_block;
	extern s_tag_struct externParameterBlock_block_struct;
	extern s_tag_block_definition externParameterBlock_block;

	extern s_tag_struct material_struct_struct_definition;

} // namespace blofeld

