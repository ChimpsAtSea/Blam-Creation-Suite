#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define WIND_STRUCT_DEFINITION_ID { 0x4F54D275, 0x39034545, 0xA099DD8C, 0xB8647BC2 }
	TAG_BLOCK(
		wind_block,
		"wind_block",
		1,
		"s_wind_definition",
		WIND_STRUCT_DEFINITION_ID)
	{
		{ _field_explanation, "WIND DIRECTION", "Speed is in MPH, direction is in degrees:\n   0°  North\n  90°  East\n 180°  South\n 270°  West\n" },
		{ _field_struct, "direction", &wind_scalar_function_struct },
		{ _field_struct, "speed", &wind_scalar_function_struct },
		{ _field_explanation, "DECORATOR WIND MOTION", "These are all a function of the wind speed (between 0 MPH on the left and 200 MPH on the right)\n\nbend: how much the decorators bend - 0.0 is standing straight up, 10.0 is super-flattened\noscillation: how much the decorators \'oscillate\' at a given speed\nfrequency: how fast the oscillation waves each decorator\ngust size: big gusts move large areas of decorators in sync.  small gusts give more variation\n" },
		{ _field_struct, "bend", &wind_scalar_function_struct },
		{ _field_struct, "oscillation", &wind_scalar_function_struct },
		{ _field_struct, "frequency", &wind_scalar_function_struct },
		{ _field_real, "gust size:world units" },
		{ _field_tag_reference, "gust noise bitmap", &global_bitmap_reference },
		{ _field_terminator }
	};

	TAG_GROUP(
		wind_group,
		WIND_TAG,
		nullptr,
		INVALID_TAG,
		wind_block );

	#define WIND_SCALAR_FUNCTION_STRUCT_ID { 0xC19F77F7, 0xBDE74B5E, 0xA4BA598F, 0x198FA328 }
	TAG_STRUCT(
		wind_scalar_function_struct,
		"wind_scalar_function_struct",
		"s_wind_function",
		WIND_SCALAR_FUNCTION_STRUCT_ID)
	{
		FIELD_CUSTOM(nullptr, 0),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_wind_reference, WIND_TAG);

} // namespace macaque

} // namespace blofeld

