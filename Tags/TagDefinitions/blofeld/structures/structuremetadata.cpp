#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
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
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_META_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "Effects markers", FIELD_FLAG_READ_ONLY, &structureBspFxMarkerBlock_block },
		{ _field_block, "Airprobes", FIELD_FLAG_READ_ONLY, &scenario_airprobes_block },
		{ _field_block, "Light Cones", FIELD_FLAG_READ_ONLY, &structureMetadataLightConeMarkerBlock_block },
		{ _field_block, "Object Palette", FIELD_FLAG_READ_ONLY, &structure_bsp_environment_object_palette_block },
		{ _field_block, "Objects", FIELD_FLAG_READ_ONLY, &structure_bsp_environment_object_block },
		{ _field_terminator }
	};



} // namespace blofeld

