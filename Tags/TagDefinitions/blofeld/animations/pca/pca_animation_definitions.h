#pragma once

namespace blofeld
{

	constexpr unsigned long PCA_ANIMATION_TAG = 'pcaa';

	extern s_tag_struct_definition pca_animation_block_struct;
	extern s_tag_block_definition pca_animation_block;
	extern s_tag_group pca_animation_group;

	extern s_tag_struct_definition PCAImportedFrameDatablock_block_struct;
	extern s_tag_block_definition PCAImportedFrameDatablock_block;
	extern s_tag_struct_definition PCAImportedAnimationDataBlock_block_struct;
	extern s_tag_block_definition PCAImportedAnimationDataBlock_block;

	extern s_tag_struct_definition pca_coefficients_resource_definition_struct_struct_definition;

	extern s_tag_struct_definition PCAImportedMeshDataBlock_block_struct;
	extern s_tag_block_definition PCAImportedMeshDataBlock_block;

	extern c_versioned_string_list pca_animation_tag_flags_strings;
	extern s_string_list_definition pca_animation_tag_flags;

	extern s_tag_reference_definition global_pca_animation_tag_reference;

} // namespace blofeld

