#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP(pca_animation, PCA_ANIMATION_TAG)
	{
		{ _field_explanation, "Links", "links to the tags this data is associated with. These will be set by the importer, you don\'t need to do it manually" },
		{ _field_tag_reference, "RenderModel*", &render_model_reference$6 },
		{ _field_tag_reference, "AnimationGraph*", &global_animation_graph_reference },
		{ _field_long_flags, "pcaFlags*", &pca_animation_tag_flags },
		{ _field_long_integer, "PCA Animation Count*!" },
		{ _field_long_integer, "PCA Checksum*!" },
		{ _field_explanation, "Imported Data", "imported data" },
		{ _field_block, "frame data*", &PCAImportedFrameDatablock_block },
		{ _field_block, "mesh data*", &PCAImportedMeshDataBlock_block },
		{ _field_explanation, "Resource Data", "vertex buffers" },
		{ _field_pageable, "api resource*", &render_geometry_api_resource_definition_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(PCAImportedFrameDatablock, 64 * k_meg)
	{
		{ _field_data, "Coefficients" },
		{ _field_terminator }
	};

	TAG_BLOCK(PCAImportedAnimationDataBlock, k_max_animations_per_graph)
	{
		{ _field_string_id, "Name^*" },
		{ _field_long_integer, "Offset*" },
		{ _field_long_integer, "Count*" },
		{ _field_long_integer, "PCA Shape Offset*!" },
		{ _field_long_integer, "PCA coefficient Count*!" },
		{ _field_explanation, "Resource Data", "coefficients" },
		{ _field_pageable, "CoefficientResource*", &pca_coefficients_resource_definition_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(pca_coefficients_resource_definition_struct)
	{
		{ _field_data, "Coefficients" },
		{ _field_terminator }
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
		{ _field_explanation, "Animations", "all imported animations for this mesh" },
		{ _field_block, "animations*", &PCAImportedAnimationDataBlock_block },
		{ _field_explanation, "Vertices", "all imported blend shape vertices for this mesh" },
		{ _field_block, "raw blendshape verts*", &raw_blendshape_block_block },
		{ _field_terminator }
	};

	STRINGS(pca_animation_tag_flags)
	{
		"lookup table ready",
		"resources generated",
		"resources committed"
	};
	STRING_LIST(pca_animation_tag_flags, pca_animation_tag_flags_strings, _countof(pca_animation_tag_flags_strings));

	TAG_REFERENCE(global_pca_animation_tag_reference, PCA_ANIMATION_TAG);

} // namespace blofeld

