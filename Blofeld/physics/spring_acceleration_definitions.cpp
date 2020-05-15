#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(spring_linear_acceleration, k_dimensions_in_3d_count)
{
	{ _field_real, "acceleration range:world units" },
	{ _field_real, "inverse acceleration range:world units*!" },
	{ _field_real, "world acceleration scale#0 defaults to 1, scale the acceleration the object itself applies on this system." },
	{ _field_explanation, "damping" },
	{ _field_struct, "spring damping" },
	{ _field_real, "velocity domain" },
	{ _field_struct, "spring acceleration" },
	{ _field_terminator },
};

TAG_GROUP(spring_acceleration, SPRING_ACCELERATION_TAG)
{
	{ _field_block, "linear acceleartions", &spring_linear_acceleration_block },
	{ _field_short_block_index, "x-axis" },
	{ _field_short_block_index, "y-axis" },
	{ _field_short_block_index, "z-axis" },
	{ _field_pad, "pad", 2 },
	{ _field_terminator },
};

} // namespace blofeld

