#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(jetwash_definition_block, k_maximum_jetwash_points_per_object)
	{
		FIELD( _field_custom ),
		FIELD( _field_string_id, "marker name^" ),
		FIELD( _field_real, "radius" ),
		FIELD( _field_long_integer, "maximum traces!:traces per second" ),
		FIELD( _field_real, "maximum emission length:world units" ),
		FIELD( _field_angle_bounds, "trace yaw angle: degrees" ),
		FIELD( _field_angle_bounds, "trace pitch angle: degrees" ),
		FIELD( _field_real, "particle offset:world units" ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

