#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(PCAImportedFrameDatablock, 64 * k_meg)
{
	FIELD( _field_data, "Coefficients" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(PCAImportedMeshDataBlock, (8*1024-1))
{
	FIELD( _field_long_integer, "render mesh index*" ),
	FIELD( _field_long_integer, "vertices per shape*" ),
	FIELD( _field_long_integer, "vertex buffer index*" ),
	FIELD( _field_real_vector_3d, "position scale*" ),
	FIELD( _field_real, "tension scale*" ),
	FIELD( _field_real_vector_3d, "position offset*" ),
	FIELD( _field_real, "tension offset*" ),
	FIELD( _field_real_vector_3d, "normal scale*" ),
	FIELD( _field_real, "stretch scale*" ),
	FIELD( _field_real_vector_3d, "normal offset*" ),
	FIELD( _field_real, "stretch offset*" ),
	FIELD( _field_explanation, "Animations" ),
	FIELD( _field_block, "animations*", &PCAImportedAnimationDataBlock ),
	FIELD( _field_explanation, "Vertices" ),
	FIELD( _field_block, "raw blendshape verts*", &raw_blendshape_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(PCAImportedAnimationDataBlock, k_max_animations_per_graph)
{
	FIELD( _field_string_id, "Name^*" ),
	FIELD( _field_long_integer, "Offset*" ),
	FIELD( _field_long_integer, "Count*" ),
	FIELD( _field_long_integer, "PCA Shape Offset*!" ),
	FIELD( _field_long_integer, "PCA coefficient Count*!" ),
	FIELD( _field_explanation, "Resource Data" ),
	FIELD( _field_pageable, "CoefficientResource*" ),
	FIELD( _field_terminator )
};

TAG_GROUP(pca_animation_block, PCA_ANIMATION_TAG)
{
	FIELD( _field_explanation, "Links" ),
	FIELD( _field_tag_reference, "RenderModel*" ),
	FIELD( _field_tag_reference, "AnimationGraph*" ),
	FIELD( _field_long_flags, "pcaFlags*" ),
	FIELD( _field_long_integer, "PCA Animation Count*!" ),
	FIELD( _field_long_integer, "PCA Checksum*!" ),
	FIELD( _field_explanation, "Imported Data" ),
	FIELD( _field_block, "frame data*", &PCAImportedFrameDatablock ),
	FIELD( _field_block, "mesh data*", &PCAImportedMeshDataBlock ),
	FIELD( _field_explanation, "Resource Data" ),
	FIELD( _field_pageable, "api resource*" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

