#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(structure_meta, STRUCTURE_META_TAG, structure_meta_block_block );

	TAG_BLOCK_FROM_STRUCT(structure_meta_block, 1, structure_meta_struct_definition_struct_definition );

	TAG_STRUCT(structure_meta_struct_definition)
	{
		{ _field_block, "Effects markers*", &structureBspFxMarkerBlock_block },
		{ _field_block, "Airprobes*", &scenario_airprobes_block_block },
		{ _field_block, "Light Cones*", &structureMetadataLightConeMarkerBlock_block },
		{ _field_block, "Object Palette*", &structure_bsp_environment_object_palette_block_block },
		{ _field_block, "Objects*", &structure_bsp_environment_object_block_block },
		{ _field_terminator }
	};

} // namespace blofeld

