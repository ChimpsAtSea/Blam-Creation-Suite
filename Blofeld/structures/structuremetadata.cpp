#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(structure_meta, STRUCTURE_META_TAG)
{
	{ _field_block, "Effects markers*", &structureBspFxMarkerBlock_block },
	{ _field_block, "Airprobes*", &scenario_airprobes_block },
	{ _field_block, "Light Cones*", &structureMetadataLightConeMarkerBlock_block },
	{ _field_block, "Object Palette*", &structure_bsp_environment_object_palette_block },
	{ _field_block, "Objects*", &structure_bsp_environment_object_block },
	{ _field_terminator },
};

} // namespace blofeld

