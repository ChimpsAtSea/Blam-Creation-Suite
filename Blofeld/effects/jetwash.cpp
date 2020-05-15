#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(jetwash_definition, k_maximum_jetwash_points_per_object)
{
	{ _field_custom },
	{ _field_string_id, "marker name^" },
	{ _field_real, "radius" },
	{ _field_long_integer, "maximum traces!:traces per second" },
	{ _field_real, "maximum emission length:world units" },
	{ _field_angle_bounds, "trace yaw angle: degrees" },
	{ _field_angle_bounds, "trace pitch angle: degrees" },
	{ _field_real, "particle offset:world units" },
	{ _field_terminator },
};

} // namespace blofeld

