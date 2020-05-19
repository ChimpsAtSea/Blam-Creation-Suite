#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(spring_acceleration, SPRING_ACCELERATION_TAG, spring_acceleration_block_block );

	TAG_BLOCK(spring_linear_acceleration_block, k_dimensions_in_3d_count)
	{
		{ _field_real, "acceleration range:world units" },
		{ _field_real, "inverse acceleration range:world units*!" },
		{ _field_real, "world acceleration scale#0 defaults to 1, scale the acceleration the object itself applies on this system." },
		{ _field_explanation, "damping" },
		{ _field_struct, "spring damping", &scalar_function_named_struct_struct_definition },
		{ _field_real, "velocity domain" },
		{ _field_struct, "spring acceleration", &scalar_function_named_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(spring_acceleration_block, 1, spring_acceleration_struct_definition_struct_definition );

	TAG_STRUCT(spring_acceleration_struct_definition)
	{
		{ _field_block, "linear acceleartions", &spring_linear_acceleration_block_block },
		{ _field_short_block_index, "x-axis" },
		{ _field_short_block_index, "y-axis" },
		{ _field_short_block_index, "z-axis" },
		{ _field_pad, "pad", 2 },
		{ _field_terminator }
	};

} // namespace blofeld

