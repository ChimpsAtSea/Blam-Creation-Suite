#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{
	TAG_GROUP(structure_design, STRUCTURE_DESIGN_TAG)
	{
		{ _field_struct, "build identifier*", &structure_manifest_build_identifier_struct_struct_definition },
		{ _field_struct, "parent build identifier*", &structure_manifest_build_identifier_struct_struct_definition },
		{ _field_struct, "physics", &global_structure_physics_design_struct_struct_definition },
		{ _field_struct, "planar fog set", &planar_fog_set_definition_struct_struct_definition },
		{ _field_custom, "rain" },
		{ _field_struct, "render geometry*", &global_render_geometry_struct_struct_definition },
		{ _field_block, "instanced geometries definitions*", &structure_bsp_instanced_geometry_definition_block_block },
		{ _field_block, "instanced geometry instances*", &structure_bsp_instanced_geometry_instances_block_block },
		{ _field_block, "materials*", &global_geometry_material_block_block },
		{ _field_block, "rain_blocker mopp code block!*", &mopp_code_definition_block_block },
		{ _field_custom },
		{ _field_terminator }
	};

} // namespace blofeld

