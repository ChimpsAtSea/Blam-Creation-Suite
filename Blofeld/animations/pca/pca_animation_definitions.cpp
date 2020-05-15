#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(PCAImportedFrameDatablock, 64 * k_meg)
{
	{ _field_data, "Coefficients" },
	{ _field_terminator },
};

TAG_BLOCK(PCAImportedMeshDataBlock, (8*1024-1))
{
	{ _field_long_integer, "render mesh index*" },
	{ _field_long_integer, "vertices per shape*" },
	{ _field_long_integer, "vertex buffer index*" },
	{ _field_real_vector_3d, "position scale*" },
	{ _field_real, "tension scale*" },
	{ _field_real_vector_3d, "position offset*" },
	{ _field_real, "tension offset*" },
	{ _field_real_vector_3d, "normal scale*" },
	{ _field_real, "stretch scale*" },
	{ _field_real_vector_3d, "normal offset*" },
	{ _field_real, "stretch offset*" },
	{ _field_explanation, "Animations" },
	{ _field_block, "animations*", &PCAImportedAnimationDataBlock_block },
	{ _field_explanation, "Vertices" },
	{ _field_block, "raw blendshape verts*", &raw_blendshape_block },
	{ _field_terminator },
};

TAG_BLOCK(PCAImportedAnimationDataBlock, k_max_animations_per_graph)
{
	{ _field_string_id, "Name^*" },
	{ _field_long_integer, "Offset*" },
	{ _field_long_integer, "Count*" },
	{ _field_long_integer, "PCA Shape Offset*!" },
	{ _field_long_integer, "PCA coefficient Count*!" },
	{ _field_explanation, "Resource Data" },
	{ _field_pageable, "CoefficientResource*" },
	{ _field_terminator },
};

TAG_GROUP(pca_animation, PCA_ANIMATION_TAG)
{
	{ _field_explanation, "Links" },
	{ _field_tag_reference, "RenderModel*" },
	{ _field_tag_reference, "AnimationGraph*" },
	{ _field_long_flags, "pcaFlags*" },
	{ _field_long_integer, "PCA Animation Count*!" },
	{ _field_long_integer, "PCA Checksum*!" },
	{ _field_explanation, "Imported Data" },
	{ _field_block, "frame data*", &PCAImportedFrameDatablock_block },
	{ _field_block, "mesh data*", &PCAImportedMeshDataBlock_block },
	{ _field_explanation, "Resource Data" },
	{ _field_pageable, "api resource*" },
	{ _field_terminator },
};

} // namespace blofeld

