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
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_RESOURCES | 
		SET_UNKNOWN14 | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_DESIGN_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "build identifier", FIELD_FLAG_READ_ONLY, &structure_manifest_build_identifier_struct },
		{ _field_struct, "parent build identifier", FIELD_FLAG_READ_ONLY, &structure_manifest_build_identifier_struct },
		{ _field_struct, "physics", &global_structure_physics_design_struct },
		{ _field_struct, "planar fog set", &planar_fog_set_definition_struct },
		FIELD_CUSTOM("rain", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "render geometry", FIELD_FLAG_READ_ONLY, &global_render_geometry_struct },
		{ _field_block, "instanced geometries definitions", FIELD_FLAG_READ_ONLY, &structure_bsp_instanced_geometry_definition_block },
		{ _field_block, "instanced geometry instances", FIELD_FLAG_READ_ONLY, &structure_bsp_instanced_geometry_instances_block },
		{ _field_block, "materials", FIELD_FLAG_READ_ONLY, &global_geometry_material_block },
		{ _field_block, "rain_blocker mopp code block", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &mopp_code_definition_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
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

