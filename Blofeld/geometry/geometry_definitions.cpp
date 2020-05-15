#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(raw_blendshape, MAXIMUM_VERTICES_PER_GEOMETRY_SECTION)
{
	FIELD( _field_real_vector_3d, "position*" ),
	FIELD( _field_real_vector_3d, "normal*" ),
	FIELD( _field_real_argb_color, "tension and ambient occlusion*" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

