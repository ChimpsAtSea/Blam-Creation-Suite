#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(wind, WIND_TAG)
{
	FIELD( _field_explanation, "WIND DIRECTION" ),
	FIELD( _field_struct, "direction" ),
	FIELD( _field_struct, "speed" ),
	FIELD( _field_explanation, "DECORATOR WIND MOTION" ),
	FIELD( _field_struct, "bend" ),
	FIELD( _field_struct, "oscillation" ),
	FIELD( _field_struct, "frequency" ),
	FIELD( _field_real, "gust size:world units" ),
	FIELD( _field_tag_reference, "gust noise bitmap" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

