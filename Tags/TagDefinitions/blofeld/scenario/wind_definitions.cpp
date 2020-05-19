#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP(wind, WIND_TAG)
	{
		{ _field_explanation, "WIND DIRECTION" },
		{ _field_struct, "direction", &wind_scalar_function_struct_struct_definition },
		{ _field_struct, "speed", &wind_scalar_function_struct_struct_definition },
		{ _field_explanation, "DECORATOR WIND MOTION" },
		{ _field_struct, "bend", &wind_scalar_function_struct_struct_definition },
		{ _field_struct, "oscillation", &wind_scalar_function_struct_struct_definition },
		{ _field_struct, "frequency", &wind_scalar_function_struct_struct_definition },
		{ _field_real, "gust size:world units" },
		{ _field_tag_reference, "gust noise bitmap", &global_bitmap_reference },
		{ _field_terminator }
	};

	TAG_STRUCT(wind_scalar_function_struct)
	{
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_wind_reference, WIND_TAG);

} // namespace blofeld

