#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(collision_sphere, k_maximum_collision_spheres_per_cloth)
{
	{ _field_string_id, "object marker name" },
	{ _field_real, "radius" },
	{ _field_terminator },
};

TAG_BLOCK(cloth_vertices, k_maximum_vertices_per_cloth)
{
	{ _field_real_point_3d, "initial position*" },
	{ _field_real_vector_2d, "uv*" },
	{ _field_terminator },
};

TAG_BLOCK(cloth_indices, k_maximum_indices_per_cloth)
{
	{ _field_short_integer, "index*" },
	{ _field_terminator },
};

TAG_BLOCK(cloth_links, k_maximum_links_per_cloth)
{
	{ _field_real, "default_distance*" },
	{ _field_long_integer, "index1*" },
	{ _field_long_integer, "index2*" },
	{ _field_pad, "vmx_pad", 4 },
	{ _field_terminator },
};

TAG_GROUP(cloth, CLOTH_TAG)
{
	{ _field_long_flags, "flags" },
	{ _field_string_id, "marker attachment name" },
	{ _field_string_id, "secondary axis attachment name" },
	{ _field_tag_reference, "Shader" },
	{ _field_explanation, "Default cloth vertices" },
	{ _field_short_integer, "grid x dimension" },
	{ _field_short_integer, "grid y dimension" },
	{ _field_real, "grid spacing x" },
	{ _field_real, "grid spacing y" },
	{ _field_block, "collision spheres", &collision_sphere_block },
	{ _field_explanation, "Cloth Properties" },
	{ _field_struct, "properties" },
	{ _field_explanation, "Import or grid data" },
	{ _field_block, "vertices*", &cloth_vertices_block },
	{ _field_block, "indices*", &cloth_indices_block },
	{ _field_block, "strip indices*", &cloth_indices_block },
	{ _field_block, "links*", &cloth_links_block },
	{ _field_terminator },
};

} // namespace blofeld

