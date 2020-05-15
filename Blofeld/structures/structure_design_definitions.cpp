#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(structure_design, STRUCTURE_DESIGN_TAG)
{
	FIELD( _field_struct, "build identifier*" ),
	FIELD( _field_struct, "parent build identifier*" ),
	FIELD( _field_struct, "physics" ),
	FIELD( _field_struct, "planar fog set" ),
	FIELD( _field_custom, "rain" ),
	FIELD( _field_struct, "render geometry*" ),
	FIELD( _field_block, "instanced geometries definitions*", &structure_bsp_instanced_geometry_definition_block ),
	FIELD( _field_block, "instanced geometry instances*", &structure_bsp_instanced_geometry_instances_block ),
	FIELD( _field_block, "materials*", &global_geometry_material_block ),
	FIELD( _field_block, "rain_blocker mopp code block!*", &mopp_code_definition_block ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

} // namespace blofeld

