#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(structure_meta_struct_definition)
{
	FIELD( _field_block, "Effects markers*", &structureBspFxMarkerBlock ),
	FIELD( _field_block, "Airprobes*", &scenario_airprobes_block ),
	FIELD( _field_block, "Light Cones*", &structureMetadataLightConeMarkerBlock ),
	FIELD( _field_block, "Object Palette*", &structure_bsp_environment_object_palette_block ),
	FIELD( _field_block, "Objects*", &structure_bsp_environment_object_block ),
	FIELD( _field_terminator )
};

TAG_GROUP(structure_meta_block, STRUCTURE_META_TAG)
{
	FIELD( _field_block, "Effects markers*", &structureBspFxMarkerBlock ),
	FIELD( _field_block, "Airprobes*", &scenario_airprobes_block ),
	FIELD( _field_block, "Light Cones*", &structureMetadataLightConeMarkerBlock ),
	FIELD( _field_block, "Object Palette*", &structure_bsp_environment_object_palette_block ),
	FIELD( _field_block, "Objects*", &structure_bsp_environment_object_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

