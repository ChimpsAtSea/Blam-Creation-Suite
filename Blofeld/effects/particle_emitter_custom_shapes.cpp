#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(particle_emitter_custom_point, s_particle_emitter_custom_points::k_maximum_points)
{
	{ _field_short_integer, "position_x" },
	{ _field_short_integer, "position_y" },
	{ _field_short_integer, "position_z" },
	{ _field_char_integer, "normal_x" },
	{ _field_char_integer, "normal_y" },
	{ _field_char_integer, "normal_z" },
	{ _field_byte_integer, "correlation" },
	{ _field_terminator },
};

TAG_GROUP(particle_emitter_custom_points, PARTICLE_EMITTER_CUSTOM_POINTS_TAG)
{
	{ _field_custom, "import" },
	{ _field_explanation, "PARTICLE POINTS" },
	{ _field_tag_reference, "source reference!" },
	{ _field_real_vector_3d, "compression scale" },
	{ _field_real_vector_3d, "compression offset" },
	{ _field_block, "points", &particle_emitter_custom_point_block },
	{ _field_terminator },
};

} // namespace blofeld

