#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		structure_meta_group,
		STRUCTURE_META_TAG,
		nullptr,
		INVALID_TAG,
		structure_meta_block );

	TAG_BLOCK_FROM_STRUCT(
		structure_meta_block,
		"structure_meta_block",
		1,
		structure_meta_struct_definition);

	#define STRUCTURE_META_STRUCT_DEFINITION_ID { 0xAAF021B9, 0xE656432A, 0x971E39DE, 0x0BA1DF54 }
	TAG_STRUCT(
		structure_meta_struct_definition,
		"structure_meta_struct_definition",
		"StructureMetadata",
		STRUCTURE_META_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "Effects markers*", &structureBspFxMarkerBlock_block },
		{ _field_block, "Airprobes*", &scenario_airprobes_block },
		{ _field_block, "Light Cones*", &structureMetadataLightConeMarkerBlock_block },
		{ _field_block, "Object Palette*", &structure_bsp_environment_object_palette_block },
		{ _field_block, "Objects*", &structure_bsp_environment_object_block },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

