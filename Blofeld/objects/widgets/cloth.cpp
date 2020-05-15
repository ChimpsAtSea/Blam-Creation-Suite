#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(collision_sphere, k_maximum_collision_spheres_per_cloth)
{
	FIELD( _field_string_id, "object marker name" ),
	FIELD( _field_real, "radius" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cloth_vertices, k_maximum_vertices_per_cloth)
{
	FIELD( _field_real_point_3d, "initial position*" ),
	FIELD( _field_real_vector_2d, "uv*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cloth_indices, k_maximum_indices_per_cloth)
{
	FIELD( _field_short_integer, "index*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cloth_links, k_maximum_links_per_cloth)
{
	FIELD( _field_real, "default_distance*" ),
	FIELD( _field_long_integer, "index1*" ),
	FIELD( _field_long_integer, "index2*" ),
	FIELD( _field_pad, "vmx_pad", 4 ),
	FIELD( _field_terminator )
};

TAG_GROUP(cloth, CLOTH_TAG)
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
	FIELD( _field_block, "collision spheres", &collision_sphere_block ),
	FIELD( _field_explanation, "Cloth Properties" ),
	FIELD( _field_struct, "properties" ),
	FIELD( _field_explanation, "Import or grid data" ),
	FIELD( _field_block, "vertices*", &cloth_vertices_block ),
	FIELD( _field_block, "indices*", &cloth_indices_block ),
	FIELD( _field_block, "strip indices*", &cloth_indices_block ),
	FIELD( _field_block, "links*", &cloth_links_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

