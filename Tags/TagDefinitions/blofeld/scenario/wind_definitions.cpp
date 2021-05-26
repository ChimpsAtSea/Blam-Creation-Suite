#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	#define WIND_STRUCT_DEFINITION_ID { 0x4F54D275, 0x39034545, 0xA099DD8C, 0xB8647BC2 }
	TAG_BLOCK(
		wind_block,
		"wind_block",
		1,
		"s_wind_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		WIND_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("WIND DIRECTION", nullptr, FIELD_FLAG_NONE, "Speed is in MPH, direction is in degrees:\n   0°  North\n  90°  East\n 180°  South\n 270°  West\n"),
		{ _field_struct, "direction", &wind_scalar_function_struct },
		{ _field_struct, "speed", &wind_scalar_function_struct },
		FIELD_EXPLANATION("DECORATOR WIND MOTION", nullptr, FIELD_FLAG_NONE, "These are all a function of the wind speed (between 0 MPH on the left and 200 MPH on the right)\n\nbend: how much the decorators bend - 0.0 is standing straight up, 10.0 is super-flattened\noscillation: how much the decorators \'oscillate\' at a given speed\nfrequency: how fast the oscillation waves each decorator\ngust size: big gusts move large areas of decorators in sync.  small gusts give more variation\n"),
		{ _field_struct, "bend", &wind_scalar_function_struct },
		{ _field_struct, "oscillation", &wind_scalar_function_struct },
		{ _field_struct, "frequency", &wind_scalar_function_struct },
		{ _field_real, "gust size", nullptr, "world units" },
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
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		WIND_SCALAR_FUNCTION_STRUCT_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_wind_reference, WIND_TAG);



} // namespace blofeld

