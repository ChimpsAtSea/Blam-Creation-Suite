#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP(wind, WIND_TAG)
	{
		{ _field_legacy, _field_explanation, "WIND DIRECTION", "Speed is in MPH, direction is in degrees:\n   0°  North\n  90°  East\n 180°  South\n 270°  West\n" },
		{ _field_legacy, _field_struct, "direction", &wind_scalar_function_struct_struct_definition },
		{ _field_legacy, _field_struct, "speed", &wind_scalar_function_struct_struct_definition },
		{ _field_legacy, _field_explanation, "DECORATOR WIND MOTION", "These are all a function of the wind speed (between 0 MPH on the left and 200 MPH on the right)\n\nbend: how much the decorators bend - 0.0 is standing straight up, 10.0 is super-flattened\noscillation: how much the decorators \'oscillate\' at a given speed\nfrequency: how fast the oscillation waves each decorator\ngust size: big gusts move large areas of decorators in sync.  small gusts give more variation\n" },
		{ _field_legacy, _field_struct, "bend", &wind_scalar_function_struct_struct_definition },
		{ _field_legacy, _field_struct, "oscillation", &wind_scalar_function_struct_struct_definition },
		{ _field_legacy, _field_struct, "frequency", &wind_scalar_function_struct_struct_definition },
		{ _field_legacy, _field_real, "gust size:world units" },
		{ _field_legacy, _field_tag_reference, "gust noise bitmap", &global_bitmap_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(wind_scalar_function_struct)
	{
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	TAG_REFERENCE(global_wind_reference, WIND_TAG);

} // namespace blofeld

