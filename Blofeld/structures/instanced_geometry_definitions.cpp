#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_render_model_instance_placement_block, k_maximum_instance_placements_per_render_model)
{
	FIELD( _field_string_id, "name^*" ),
	FIELD( _field_long_block_index, "node_index*" ),
	FIELD( _field_real, "scale*" ),
	FIELD( _field_real_vector_3d, "forward*" ),
	FIELD( _field_real_vector_3d, "left*" ),
	FIELD( _field_real_vector_3d, "up*" ),
	FIELD( _field_real_point_3d, "position*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(structure_bsp_instanced_geometry_instances_block, k_maximum_instance_geometry_instances_per_structure_bsp)
{
	FIELD( _field_real, "scale" ),
	FIELD( _field_real_vector_3d, "forward" ),
	FIELD( _field_real_vector_3d, "left" ),
	FIELD( _field_real_vector_3d, "up" ),
	FIELD( _field_real_point_3d, "position" ),
	FIELD( _field_short_block_index, "instance definition*" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_long_flags, "Light Channels:" ),
	FIELD( _field_short_integer, "mesh_index" ),
	FIELD( _field_short_integer, "compression_index" ),
	FIELD( _field_long_integer, "seam bit vector 0" ),
	FIELD( _field_long_integer, "seam bit vector 1" ),
	FIELD( _field_long_integer, "seam bit vector 2" ),
	FIELD( _field_long_integer, "seam bit vector 3" ),
	FIELD( _field_real, "bounds x0!" ),
	FIELD( _field_real, "bounds x1!" ),
	FIELD( _field_real, "bounds y0!" ),
	FIELD( _field_real, "bounds y1!" ),
	FIELD( _field_real, "bounds z0!" ),
	FIELD( _field_real, "bounds z1!" ),
	FIELD( _field_real_point_3d, "world bounding sphere center!" ),
	FIELD( _field_real, "world bounding sphere radius!" ),
	FIELD( _field_real, "imposter transition complete distance!" ),
	FIELD( _field_real, "imposter brightness!" ),
	FIELD( _field_long_integer, "checksum*" ),
	FIELD( _field_char_enum, "pathfinding policy*" ),
	FIELD( _field_char_enum, "lightmapping policy*" ),
	FIELD( _field_char_enum, "imposter policy*" ),
	FIELD( _field_pad, "SDFSDFE", 1 ),
	FIELD( _field_char_enum, "streaming priority*" ),
	FIELD( _field_pad, "strpad", 1 ),
	FIELD( _field_short_integer, "cubemap 0 bitmap index" ),
	FIELD( _field_real, "lightmap resolution scale" ),
	FIELD( _field_short_integer, "group_index!" ),
	FIELD( _field_short_integer, "group_list_index!" ),
	FIELD( _field_string_id, "name*^" ),
	FIELD( _field_long_string, "source file name*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(structure_bsp_instanced_geometry_instances_names_block, k_maximum_instance_geometry_instances_per_structure_bsp)
{
	FIELD( _field_string_id, "name*^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(structure_bsp_instanced_geometry_definition_block, k_maximum_instance_geometry_definitions_per_structure_bsp)
{
	FIELD( _field_long_integer, "checksum*" ),
	FIELD( _field_long_flags, "flags*" ),
	FIELD( _field_short_integer, "mesh index" ),
	FIELD( _field_short_integer, "compression index" ),
	FIELD( _field_real, "global lightmap resolution scale" ),
	FIELD( _field_short_integer, "external_index" ),
	FIELD( _field_pad, "useme", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK_FROM_STRUCT(structureIOHavokDataBlock, 1, structureIOHavokDataBlock_struct_struct_definition );

TAG_BLOCK_FROM_STRUCT(SerializedHavokGeometryDataBlock, 5, SerializedHavokGeometryDataBlock_struct_struct_definition );

TAG_STRUCT(structureIOHavokDataBlock_struct)
{
	FIELD( _field_long_integer, "version*" ),
	FIELD( _field_long_integer, "RuntimeDeserializedBody Pointer*!" ),
	FIELD( _field_long_integer, "RuntimeDeserializedData Pointer*!" ),
	FIELD( _field_long_integer, "Prefab Index*!" ),
	FIELD( _field_data, "Serialized Havok Data*" ),
	FIELD( _field_block, "Serialized Per Collision Type Havok Geometry", &SerializedHavokGeometryDataBlock_block ),
	FIELD( _field_real_point_3d, "Shapes bounds min!*" ),
	FIELD( _field_real_point_3d, "Shapes bounds max!*" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(SerializedHavokGeometryDataBlock_struct)
{
	FIELD( _field_data, "Serialized Havok Data*" ),
	FIELD( _field_data, "Serialized Static Havok Data*" ),
	FIELD( _field_long_integer, "collision type" ),
	FIELD( _field_long_integer, "RuntimeDeserializedBody Pointer*!" ),
	FIELD( _field_long_integer, "RuntimeDeserializedData Pointer*!" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

