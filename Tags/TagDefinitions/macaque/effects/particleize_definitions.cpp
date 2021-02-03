#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		particleman_group,
		PARTICLEMAN_TAG,
		nullptr,
		INVALID_TAG,
		particleman_block );

	TAG_BLOCK_FROM_STRUCT(
		particleman_block,
		"particleman_block",
		1,
		particleman_struct_definition);

	#define PARTICLEMAN_STRUCT_DEFINITION_ID { 0x9690B47C, 0x91684047, 0x9760BBA7, 0x242F7513 }
	TAG_STRUCT(
		particleman_struct_definition,
		"particleman_struct_definition",
		"s_particleize_parameters",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PARTICLEMAN_STRUCT_DEFINITION_ID)
	{
		{ _field_explanation, "Particleize Settings", "Defines a particular particleize effect\n\nDensity modifies how many particles are made\nSize indicates how large the effect can be in world units\nShape indicates the shape of the effect\nCurve defines how the shape evolves over time\n" },
		{ _field_enum, "Shape", &particleize_shape_enum },
		{ _field_word_flags, "Flags", &particleize_flags },
		{ _field_real, "Duration", "sec" },
		{ _field_real, "Density" },
		{ _field_real, "Size", "world units" },
		{ _field_struct, "Curve", &particleize_scalar_function_struct },
		{ _field_terminator }
	};

	#define PARTICLEIZE_SCALAR_FUNCTION_STRUCT_ID { 0xC1CB3A69, 0x25F9489C, 0xB45FE276, 0x00343B2B }
	TAG_STRUCT(
		particleize_scalar_function_struct,
		"particleize_scalar_function_struct",
		"particleize_function",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PARTICLEIZE_SCALAR_FUNCTION_STRUCT_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_terminator }
	};

	STRINGS(particleize_shape_enum)
	{
		"cloud"
	};
	STRING_LIST(particleize_shape_enum, particleize_shape_enum_strings, _countof(particleize_shape_enum_strings));

	STRINGS(particleize_flags)
	{
		"hide object when effect completes",
		"move particles towards current set target location",
		"override any currently running particleization"
	};
	STRING_LIST(particleize_flags, particleize_flags_strings, _countof(particleize_flags_strings));

	TAG_REFERENCE(global_particleize_parameters_reference, PARTICLEMAN_TAG);

} // namespace macaque

} // namespace blofeld

