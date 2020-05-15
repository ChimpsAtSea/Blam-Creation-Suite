#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_render_model_instance_placement, k_maximum_instance_placements_per_render_model)
{
	{ _field_string_id, "name^*" },
	{ _field_long_block_index, "node_index*" },
	{ _field_real, "scale*" },
	{ _field_real_vector_3d, "forward*" },
	{ _field_real_vector_3d, "left*" },
	{ _field_real_vector_3d, "up*" },
	{ _field_real_point_3d, "position*" },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_instanced_geometry_instances, k_maximum_instance_geometry_instances_per_structure_bsp)
{
	{ _field_real, "scale" },
	{ _field_real_vector_3d, "forward" },
	{ _field_real_vector_3d, "left" },
	{ _field_real_vector_3d, "up" },
	{ _field_real_point_3d, "position" },
	{ _field_short_block_index, "instance definition*" },
	{ _field_word_flags, "flags" },
	{ _field_long_flags, "Light Channels:" },
	{ _field_short_integer, "mesh_index" },
	{ _field_short_integer, "compression_index" },
	{ _field_long_integer, "seam bit vector 0" },
	{ _field_long_integer, "seam bit vector 1" },
	{ _field_long_integer, "seam bit vector 2" },
	{ _field_long_integer, "seam bit vector 3" },
	{ _field_real, "bounds x0!" },
	{ _field_real, "bounds x1!" },
	{ _field_real, "bounds y0!" },
	{ _field_real, "bounds y1!" },
	{ _field_real, "bounds z0!" },
	{ _field_real, "bounds z1!" },
	{ _field_real_point_3d, "world bounding sphere center!" },
	{ _field_real, "world bounding sphere radius!" },
	{ _field_real, "imposter transition complete distance!" },
	{ _field_real, "imposter brightness!" },
	{ _field_long_integer, "checksum*" },
	{ _field_char_enum, "pathfinding policy*" },
	{ _field_char_enum, "lightmapping policy*" },
	{ _field_char_enum, "imposter policy*" },
	{ _field_pad, "SDFSDFE", 1 },
	{ _field_char_enum, "streaming priority*" },
	{ _field_pad, "strpad", 1 },
	{ _field_short_integer, "cubemap 0 bitmap index" },
	{ _field_real, "lightmap resolution scale" },
	{ _field_short_integer, "group_index!" },
	{ _field_short_integer, "group_list_index!" },
	{ _field_string_id, "name*^" },
	{ _field_long_string, "source file name*" },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_instanced_geometry_instances_names, k_maximum_instance_geometry_instances_per_structure_bsp)
{
	{ _field_string_id, "name*^" },
	{ _field_terminator },
};

TAG_BLOCK(structureIOHavokDataBlock, 1)
{
	{ _field_long_integer, "version*" },
	{ _field_long_integer, "RuntimeDeserializedBody Pointer*!" },
	{ _field_long_integer, "RuntimeDeserializedData Pointer*!" },
	{ _field_long_integer, "Prefab Index*!" },
	{ _field_data, "Serialized Havok Data*" },
	{ _field_block, "Serialized Per Collision Type Havok Geometry", &SerializedHavokGeometryDataBlock_block },
	{ _field_real_point_3d, "Shapes bounds min!*" },
	{ _field_real_point_3d, "Shapes bounds max!*" },
	{ _field_terminator },
};

TAG_BLOCK(SerializedHavokGeometryDataBlock, 5)
{
	{ _field_data, "Serialized Havok Data*" },
	{ _field_data, "Serialized Static Havok Data*" },
	{ _field_long_integer, "collision type" },
	{ _field_long_integer, "RuntimeDeserializedBody Pointer*!" },
	{ _field_long_integer, "RuntimeDeserializedData Pointer*!" },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_instanced_geometry_definition, k_maximum_instance_geometry_definitions_per_structure_bsp)
{
	{ _field_long_integer, "checksum*" },
	{ _field_long_flags, "flags*" },
	{ _field_short_integer, "mesh index" },
	{ _field_short_integer, "compression index" },
	{ _field_real, "global lightmap resolution scale" },
	{ _field_short_integer, "external_index" },
	{ _field_pad, "useme", 2 },
	{ _field_terminator },
};

} // namespace blofeld

