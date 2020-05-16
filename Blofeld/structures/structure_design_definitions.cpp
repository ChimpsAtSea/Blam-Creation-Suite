#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(structure_design_block, STRUCTURE_DESIGN_TAG)
{
	FIELD( _field_struct, "build identifier*", &structure_manifest_build_identifier_struct_struct_definition ),
	FIELD( _field_struct, "parent build identifier*", &structure_manifest_build_identifier_struct_struct_definition ),
	FIELD( _field_struct, "physics", &global_structure_physics_design_struct_struct_definition ),
	FIELD( _field_struct, "planar fog set", &planar_fog_set_definition_struct_struct_definition ),
	FIELD( _field_custom, "rain" ),
	FIELD( _field_struct, "render geometry*", &global_render_geometry_struct_struct_definition ),
	FIELD( _field_block, "instanced geometries definitions*", &structure_bsp_instanced_geometry_definition_block ),
	FIELD( _field_block, "instanced geometry instances*", &structure_bsp_instanced_geometry_instances_block ),
	FIELD( _field_block, "materials*", &global_geometry_material_block ),
	FIELD( _field_block, "rain_blocker mopp code block!*", &mopp_code_definition_block ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

} // namespace blofeld

