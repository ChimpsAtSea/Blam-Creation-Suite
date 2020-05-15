#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(light_cone, LIGHT_CONE_TAG)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "gosh", 3 ),
	FIELD( _field_custom, "material" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "actual material\?" ),
	FIELD( _field_custom ),
	FIELD( _field_real, "angle fade range:degrees" ),
	FIELD( _field_real, "angle fade cutoff:degrees" ),
	FIELD( _field_real, "far fade range:wus" ),
	FIELD( _field_real, "far fade cutoff:wus" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

