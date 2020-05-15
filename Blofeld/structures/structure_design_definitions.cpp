#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(structure_design, STRUCTURE_DESIGN_TAG)
{
	{ _field_struct, "build identifier*" },
	{ _field_struct, "parent build identifier*" },
	{ _field_struct, "physics" },
	{ _field_struct, "planar fog set" },
	{ _field_custom, "rain" },
	{ _field_struct, "render geometry*" },
	{ _field_block, "instanced geometries definitions*", &structure_bsp_instanced_geometry_definition_block },
	{ _field_block, "instanced geometry instances*", &structure_bsp_instanced_geometry_instances_block },
	{ _field_block, "materials*", &global_geometry_material_block },
	{ _field_block, "rain_blocker mopp code block!*", &mopp_code_definition_block },
	{ _field_custom },
	{ _field_terminator },
};

} // namespace blofeld

