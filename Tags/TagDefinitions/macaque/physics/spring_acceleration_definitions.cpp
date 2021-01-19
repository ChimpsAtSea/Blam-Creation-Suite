#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		spring_acceleration_group,
		SPRING_ACCELERATION_TAG,
		nullptr,
		INVALID_TAG,
		spring_acceleration_block );

	TAG_BLOCK_FROM_STRUCT(
		spring_acceleration_block,
		"spring_acceleration_block",
		1,
		spring_acceleration_struct_definition);

	#define SPRING_LINEAR_ACCELERATION_BLOCK_ID { 0x1C23AAAC, 0x13234449, 0xAEAB1083, 0xD9170D8A }
	TAG_BLOCK(
		spring_linear_acceleration_block,
		"spring_linear_acceleration_block",
		k_dimensions_in_3d_count,
		"s_spring_acceleration_linear_definition",
		SPRING_LINEAR_ACCELERATION_BLOCK_ID)
	{
		{ _field_real, "acceleration range:world units" },
		{ _field_real, "inverse acceleration range:world units*!" },
		{ _field_real, "world acceleration scale#0 defaults to 1, scale the acceleration the object itself applies on this system." },
		{ _field_explanation, "damping", "feed velocity into this function and damp by the value that comes out" },
		{ _field_struct, "spring damping", &scalar_function_named_struct },
		{ _field_real, "velocity domain" },
		{ _field_struct, "spring acceleration", &scalar_function_named_struct },
		{ _field_terminator }
	};

	#define SPRING_ACCELERATION_STRUCT_DEFINITION_ID { 0x1073ABE0, 0xAD9447BB, 0x8910B4FF, 0x30CD63B1 }
	TAG_STRUCT(
		spring_acceleration_struct_definition,
		"spring_acceleration_struct_definition",
		"s_spring_acceleration_definition",
		SPRING_ACCELERATION_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "linear acceleartions", &spring_linear_acceleration_block },
		{ _field_short_block_index, "x-axis" },
		{ _field_short_block_index, "y-axis" },
		{ _field_short_block_index, "z-axis" },
		{ _field_pad, "pad", 2 },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

