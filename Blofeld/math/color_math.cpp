#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(half_rgb_lightprobe_struct)
{
	FIELD( _field_array, "red sh terms" ),
	FIELD( _field_array, "green sh terms" ),
	FIELD( _field_array, "blue sh terms" ),
	FIELD( _field_short_integer, "analytical visibility" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

