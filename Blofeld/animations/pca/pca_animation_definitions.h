#pragma once

namespace blofeld
{


extern s_tag_struct PCAImportedFrameDatablock_struct_definition;
extern s_tag_block_definition PCAImportedFrameDatablock;
extern s_tag_struct PCAImportedMeshDataBlock_struct_definition;
extern s_tag_block_definition PCAImportedMeshDataBlock;
extern s_tag_struct PCAImportedAnimationDataBlock_struct_definition;
extern s_tag_block_definition PCAImportedAnimationDataBlock;

constexpr unsigned long PCA_ANIMATION_TAG = 'pcaa';

extern s_tag_block_definition pca_animation_block;
extern s_tag_group pca_animation_group;
} // namespace blofeld

