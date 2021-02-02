#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define STRUCTURE_DESIGN_STRUCT_DEFINITION_ID { 0xA073D9E0, 0x3D9447CB, 0x1BE0B4FF, 0x3ABDC3B1 }
	TAG_BLOCK(
		structure_design_block,
		"structure_design_block",
		1,
		"s_structure_design",
		STRUCTURE_DESIGN_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "build identifier", &structure_manifest_build_identifier_struct },
		{ _field_struct, "parent build identifier", &structure_manifest_build_identifier_struct },
		{ _field_struct, "physics", &global_structure_physics_design_struct },
		{ _field_struct, "planar fog set", &planar_fog_set_definition_struct },
		FIELD_CUSTOM("rain", nullptr, _field_id_function_group_begin),
		{ _field_struct, "render geometry", &global_render_geometry_struct },
		{ _field_block, "instanced geometries definitions", &structure_bsp_instanced_geometry_definition_block },
		{ _field_block, "instanced geometry instances", &structure_bsp_instanced_geometry_instances_block },
		{ _field_block, "materials", &global_geometry_material_block },
		{ _field_block, "rain_blocker mopp code block", &mopp_code_definition_block },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		{ _field_terminator }
	};

	TAG_GROUP(
		structure_design_group,
		STRUCTURE_DESIGN_TAG,
		nullptr,
		INVALID_TAG,
		structure_design_block );

} // namespace macaque

} // namespace blofeld

