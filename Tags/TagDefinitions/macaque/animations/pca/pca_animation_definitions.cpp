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
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_RESOURCES | SET_UNKNOWN14 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PCA_ANIMATION_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("Links", nullptr, "links to the tags this data is associated with. These will be set by the importer, you don\'t need to do it manually"),
		{ _field_tag_reference, "RenderModel", FIELD_FLAG_READ_ONLY, &render_model_reference$6 },
		{ _field_tag_reference, "AnimationGraph", FIELD_FLAG_READ_ONLY, &global_animation_graph_reference },
		{ _field_long_flags, "pcaFlags", FIELD_FLAG_READ_ONLY, &pca_animation_tag_flags },
		{ _field_long_integer, "PCA Animation Count", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "PCA Checksum", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_EXPLANATION("Imported Data", nullptr, "imported data"),
		{ _field_block, "frame data", FIELD_FLAG_READ_ONLY, &PCAImportedFrameDatablock_block },
		{ _field_block, "mesh data", FIELD_FLAG_READ_ONLY, &PCAImportedMeshDataBlock_block },
		FIELD_EXPLANATION("Resource Data", nullptr, "vertex buffers"),
		{ _field_pageable, "api resource", FIELD_FLAG_READ_ONLY, &render_geometry_api_resource_definition_struct },
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
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_UNKNOWN8 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
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
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_RESOURCES | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PCAIMPORTEDMESHDATABLOCK_ID)
	{
		{ _field_long_integer, "render mesh index", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "vertices per shape", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "vertex buffer index", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "position scale", FIELD_FLAG_READ_ONLY },
		{ _field_real, "tension scale", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "position offset", FIELD_FLAG_READ_ONLY },
		{ _field_real, "tension offset", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "normal scale", FIELD_FLAG_READ_ONLY },
		{ _field_real, "stretch scale", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "normal offset", FIELD_FLAG_READ_ONLY },
		{ _field_real, "stretch offset", FIELD_FLAG_READ_ONLY },
		FIELD_EXPLANATION("Animations", nullptr, "all imported animations for this mesh"),
		{ _field_block, "animations", FIELD_FLAG_READ_ONLY, &PCAImportedAnimationDataBlock_block },
		FIELD_EXPLANATION("Vertices", nullptr, "all imported blend shape vertices for this mesh"),
		{ _field_block, "raw blendshape verts", FIELD_FLAG_READ_ONLY, &raw_blendshape_block },
		{ _field_terminator }
	};

	#define PCAIMPORTEDANIMATIONDATABLOCK_ID { 0x959FD2F8, 0xBBC14296, 0xADCD7D1C, 0x128A561C }
	TAG_BLOCK(
		PCAImportedAnimationDataBlock_block,
		"PCAImportedAnimationDataBlock",
		k_max_animations_per_graph,
		"PCAImportedAnimationData",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_RESOURCES | SET_UNKNOWN14 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PCAIMPORTEDANIMATIONDATABLOCK_ID)
	{
		{ _field_string_id, "Name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_long_integer, "Offset", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "Count", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "PCA Shape Offset", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "PCA coefficient Count", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_EXPLANATION("Resource Data", nullptr, "coefficients"),
		{ _field_pageable, "CoefficientResource", FIELD_FLAG_READ_ONLY, &pca_coefficients_resource_definition_struct },
		{ _field_terminator }
	};

	#define PCA_COEFFICIENTS_RESOURCE_DEFINITION_STRUCT_ID { 0x53EAA5E8, 0x27D74A19, 0xB37E2E13, 0xA022F958 }
	TAG_STRUCT(
		pca_coefficients_resource_definition_struct,
		"pca_coefficients_resource_definition_struct",
		"PCAImportedFrameData",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_UNKNOWN8 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
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

