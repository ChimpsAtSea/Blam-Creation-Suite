#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(particleman, PARTICLEMAN_TAG, particleman_block_block );

	TAG_BLOCK_FROM_STRUCT(particleman_block, 1, particleman_struct_definition_struct_definition );

	TAG_STRUCT(particleman_struct_definition)
	{
		{ _field_explanation, "Particleize Settings", "Defines a particular particleize effect\n\nDensity modifies how many particles are made\nSize indicates how large the effect can be in world units\nShape indicates the shape of the effect\nCurve defines how the shape evolves over time\n" },
		{ _field_enum, "Shape", &particleize_shape_enum },
		{ _field_word_flags, "Flags", &particleize_flags },
		{ _field_real, "Duration:sec" },
		{ _field_real, "Density" },
		{ _field_real, "Size:world units" },
		{ _field_struct, "Curve", &particleize_scalar_function_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(particleize_scalar_function_struct)
	{
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
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

} // namespace blofeld

