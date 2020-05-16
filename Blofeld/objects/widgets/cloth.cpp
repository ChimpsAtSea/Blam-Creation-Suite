#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(cloth, CLOTH_TAG, cloth_block_block );

TAG_BLOCK_FROM_STRUCT(cloth_block, 1, cloth_struct_definition_struct_definition );

TAG_BLOCK(collision_sphere_block, k_maximum_collision_spheres_per_cloth)
{
	FIELD( _field_string_id, "object marker name" ),
	FIELD( _field_real, "radius" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cloth_vertices_block, k_maximum_vertices_per_cloth)
{
	FIELD( _field_real_point_3d, "initial position*" ),
	FIELD( _field_real_vector_2d, "uv*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cloth_indices_block, k_maximum_indices_per_cloth)
{
	FIELD( _field_short_integer, "index*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cloth_links_block, k_maximum_links_per_cloth)
{
	FIELD( _field_real, "default_distance*" ),
	FIELD( _field_long_integer, "index1*" ),
	FIELD( _field_long_integer, "index2*" ),
	FIELD( _field_pad, "vmx_pad", 4 ),
	FIELD( _field_terminator )
};

TAG_STRUCT(cloth_struct_definition)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_string_id, "marker attachment name" ),
	FIELD( _field_string_id, "secondary axis attachment name" ),
	FIELD( _field_tag_reference, "Shader" ),
	FIELD( _field_explanation, "Default cloth vertices" ),
	FIELD( _field_short_integer, "grid x dimension" ),
	FIELD( _field_short_integer, "grid y dimension" ),
	FIELD( _field_real, "grid spacing x" ),
	FIELD( _field_real, "grid spacing y" ),
	FIELD( _field_block, "collision spheres", &collision_sphere_block_block ),
	FIELD( _field_explanation, "Cloth Properties" ),
	FIELD( _field_struct, "properties", &cloth_properties_struct_definition ),
	FIELD( _field_explanation, "Import or grid data" ),
	FIELD( _field_block, "vertices*", &cloth_vertices_block_block ),
	FIELD( _field_block, "indices*", &cloth_indices_block_block ),
	FIELD( _field_block, "strip indices*", &cloth_indices_block_block ),
	FIELD( _field_block, "links*", &cloth_links_block_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(cloth_properties)
{
	FIELD( _field_enum, "Integration type*" ),
	FIELD( _field_short_integer, "Number iterations#[1-8] sug 1" ),
	FIELD( _field_real, "weight#[-10.0 - 10.0] sug 1.0" ),
	FIELD( _field_real, "drag#[0.0 - 0.5] sug 0.07" ),
	FIELD( _field_real, "wind_scale#[0.0 - 3.0] sug 1.0" ),
	FIELD( _field_real, "wind_flappiness_scale#[0.0 - 1.0] sug 0.75" ),
	FIELD( _field_real, "longest_rod#[1.0 - 10.0] sug 3.5" ),
	FIELD( _field_pad, "WXLH", 24 ),
	FIELD( _field_terminator )
};

} // namespace blofeld

