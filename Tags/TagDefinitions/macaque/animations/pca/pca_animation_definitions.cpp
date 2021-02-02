#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define PCA_ANIMATION_STRUCT_DEFINITION_ID { 0x7CDBDEA2, 0x89A44131, 0x8B74D5FD, 0xD31DFAA3 }
	TAG_BLOCK(
		pca_animation_block,
		"pca_animation_block",
		1,
		"PcaAnimationTag",
		PCA_ANIMATION_STRUCT_DEFINITION_ID)
	{
		{ _field_explanation, "Links", "links to the tags this data is associated with. These will be set by the importer, you don\'t need to do it manually" },
		{ _field_tag_reference, "RenderModel", &render_model_reference$6 },
		{ _field_tag_reference, "AnimationGraph", &global_animation_graph_reference },
		{ _field_long_flags, "pcaFlags", &pca_animation_tag_flags },
		{ _field_long_integer, "PCA Animation Count" },
		{ _field_long_integer, "PCA Checksum" },
		{ _field_explanation, "Imported Data", "imported data" },
		{ _field_block, "frame data", &PCAImportedFrameDatablock_block },
		{ _field_block, "mesh data", &PCAImportedMeshDataBlock_block },
		{ _field_explanation, "Resource Data", "vertex buffers" },
		{ _field_pageable, "api resource", &render_geometry_api_resource_definition_struct },
		{ _field_terminator }
	};

	TAG_GROUP(
		pca_animation_group,
		PCA_ANIMATION_TAG,
		nullptr,
		INVALID_TAG,
		pca_animation_block );

	#define PCAIMPORTEDFRAMEDATABLOCK_ID { 0xE5333434, 0x06554F48, 0x821AF6F8, 0x556FB3B5 }
	TAG_BLOCK(
		PCAImportedFrameDatablock_block,
		"PCAImportedFrameDatablock",
		64 * k_meg,
		"PCAImportedFrameData",
		PCAIMPORTEDFRAMEDATABLOCK_ID)
	{
		{ _field_data, "Coefficients" },
		{ _field_terminator }
	};

	#define PCAIMPORTEDMESHDATABLOCK_ID { 0x3F7A00D0, 0x1FE3442A, 0xAED7FE34, 0x26590547 }
	TAG_BLOCK(
		PCAImportedMeshDataBlock_block,
		"PCAImportedMeshDataBlock",
		(8*1024-1),
		"PCAImportedMeshData",
		PCAIMPORTEDMESHDATABLOCK_ID)
	{
		{ _field_long_integer, "render mesh index" },
		{ _field_long_integer, "vertices per shape" },
		{ _field_long_integer, "vertex buffer index" },
		{ _field_real_vector_3d, "position scale" },
		{ _field_real, "tension scale" },
		{ _field_real_vector_3d, "position offset" },
		{ _field_real, "tension offset" },
		{ _field_real_vector_3d, "normal scale" },
		{ _field_real, "stretch scale" },
		{ _field_real_vector_3d, "normal offset" },
		{ _field_real, "stretch offset" },
		{ _field_explanation, "Animations", "all imported animations for this mesh" },
		{ _field_block, "animations", &PCAImportedAnimationDataBlock_block },
		{ _field_explanation, "Vertices", "all imported blend shape vertices for this mesh" },
		{ _field_block, "raw blendshape verts", &raw_blendshape_block },
		{ _field_terminator }
	};

	#define PCAIMPORTEDANIMATIONDATABLOCK_ID { 0x959FD2F8, 0xBBC14296, 0xADCD7D1C, 0x128A561C }
	TAG_BLOCK(
		PCAImportedAnimationDataBlock_block,
		"PCAImportedAnimationDataBlock",
		k_max_animations_per_graph,
		"PCAImportedAnimationData",
		PCAIMPORTEDANIMATIONDATABLOCK_ID)
	{
		{ _field_string_id, "Name" },
		{ _field_long_integer, "Offset" },
		{ _field_long_integer, "Count" },
		{ _field_long_integer, "PCA Shape Offset" },
		{ _field_long_integer, "PCA coefficient Count" },
		{ _field_explanation, "Resource Data", "coefficients" },
		{ _field_pageable, "CoefficientResource", &pca_coefficients_resource_definition_struct },
		{ _field_terminator }
	};

	#define PCA_COEFFICIENTS_RESOURCE_DEFINITION_STRUCT_ID { 0x53EAA5E8, 0x27D74A19, 0xB37E2E13, 0xA022F958 }
	TAG_STRUCT(
		pca_coefficients_resource_definition_struct,
		"pca_coefficients_resource_definition_struct",
		"PCAImportedFrameData",
		PCA_COEFFICIENTS_RESOURCE_DEFINITION_STRUCT_ID)
	{
		{ _field_data, "Coefficients" },
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

} // namespace macaque

} // namespace blofeld

