#pragma once

namespace blofeld
{

constexpr unsigned long PCA_ANIMATION_TAG = 'pcaa';

extern s_tag_struct pca_animation_block_struct;
extern s_tag_block_definition pca_animation_block;
extern s_tag_group pca_animation_group;

extern s_tag_struct PCAImportedFrameDatablock_block_struct;
extern s_tag_block_definition PCAImportedFrameDatablock_block;
extern s_tag_struct PCAImportedMeshDataBlock_block_struct;
extern s_tag_block_definition PCAImportedMeshDataBlock_block;
extern s_tag_struct PCAImportedAnimationDataBlock_block_struct;
extern s_tag_block_definition PCAImportedAnimationDataBlock_block;


} // namespace blofeld

