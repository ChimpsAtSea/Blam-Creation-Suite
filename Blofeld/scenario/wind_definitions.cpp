#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP(wind, WIND_TAG)
	{
		FIELD( _field_explanation, "WIND DIRECTION" ),
		FIELD( _field_struct, "direction", &wind_scalar_function_struct_struct_definition ),
		FIELD( _field_struct, "speed", &wind_scalar_function_struct_struct_definition ),
		FIELD( _field_explanation, "DECORATOR WIND MOTION" ),
		FIELD( _field_struct, "bend", &wind_scalar_function_struct_struct_definition ),
		FIELD( _field_struct, "oscillation", &wind_scalar_function_struct_struct_definition ),
		FIELD( _field_struct, "frequency", &wind_scalar_function_struct_struct_definition ),
		FIELD( _field_real, "gust size:world units" ),
		FIELD( _field_tag_reference, "gust noise bitmap" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(wind_scalar_function_struct)
{
		FIELD( _field_custom ),
		FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
		FIELD( _field_terminator )
};

} // namespace blofeld

