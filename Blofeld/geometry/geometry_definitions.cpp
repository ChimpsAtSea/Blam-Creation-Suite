#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(raw_blendshape, MAXIMUM_VERTICES_PER_GEOMETRY_SECTION)
{
	{ _field_real_vector_3d, "position*" },
	{ _field_real_vector_3d, "normal*" },
	{ _field_real_argb_color, "tension and ambient occlusion*" },
	{ _field_terminator },
};

} // namespace blofeld

