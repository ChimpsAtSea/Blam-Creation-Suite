#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(tracer_system, TRACER_SYSTEM_TAG, tracer_system_block_block );

	TAG_BLOCK(tracerDefinitionBlock, TracerSystemDefinition::k_maxTracers)
	{
		{ _field_custom },
		{ _field_string_id, "tracer name^" },
		{ _field_byte_flags, "flags", &tracerFlags },
		{ _field_custom, "Tracer Shape" },
		{ _field_char_enum, "profile shape", &tracerProfileShapeEnum },
		{ _field_byte_integer, "number of n-gon sides" },
		{ _field_pad, "tracpad", 1 },
		{ _field_real, "origin fade range{origin fade distance}:world units#distance beyond cutoff over which tracers fade" },
		{ _field_real, "origin fade cutoff:world units#distance from tracer origin where fade begins" },
		{ _field_real, "edge fade range:degrees#degrees beyond cutoff over which tracers fade" },
		{ _field_real, "edge fade cutoff:degrees#degrees away from edge-on where fade is total" },
		{ _field_struct, "profile lifespan#seconds", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "profile self acceleration#world units per second-squared", &tracerProperty_real_vector3d_Struct_struct_definition },
		{ _field_struct, "length#world units", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "offset#world units", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "profile size#world units", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "profile density#profiles per world unit", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "profile offset#world units", &tracerProperty_real_point2d_Struct_struct_definition },
		{ _field_struct, "profile rotation#degrees", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "profile rotation rate#degrees per second", &tracerProperty_real_Struct_struct_definition },
		{ _field_custom },
		{ _field_custom, "Tracer Appearance" },
		{ _field_word_flags, "appearance flags", &tracerAppearanceFlags },
		{ _field_short_integer, "sort bias#use values between -10 and 10 to move closer and farther from camera (positive is closer)" },
		{ _field_custom, "material" },
		{ _field_custom },
		{ _field_struct, "actual material\?", &material_block_struct },
		{ _field_custom },
		{ _field_real_vector_2d, "uv tiling:u lengthwise, v crosswise#u is tiles/world unit, v is absolute tiles" },
		{ _field_real_vector_2d, "uv scrolling:tiles per second" },
		{ _field_real, "angle fade range:degrees#radial (from tracer axis) degrees beyond beginning angle over which tracer fades" },
		{ _field_real, "angle fade begin:degrees#radial (from tracer axis) degrees away from face-on where fade begins" },
		{ _field_struct, "profile color", &tracerProperty_real_rgb_color_Struct_struct_definition },
		{ _field_struct, "profile alpha", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "profile alpha2", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "profile black point", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "profile palette", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "profile intensity", &tracerProperty_real_Struct_struct_definition },
		{ _field_custom },
		{ _field_custom },
		{ _field_dword_integer, "runtime m_constantPerProfileProperties!" },
		{ _field_dword_integer, "runtime m_usedStates!" },
		{ _field_dword_integer, "runtime m_maxProfileCount!" },
		{ _field_struct, "runtime m_gpuData!", &gpu_property_function_color_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(tracer_system_block, 1, tracer_system_struct_definition_struct_definition );

	TAG_STRUCT(tracer_system_struct_definition)
	{
		{ _field_long_flags, "tracer system flags", &tracerSystemFlags },
		{ _field_explanation, "far lod", "These don\'t actually do anything unless you use \"tracer lod\" in one of your curves." },
		{ _field_real, "far lod start" },
		{ _field_real, "far lod end" },
		{ _field_real, "far lod start value" },
		{ _field_real, "far lod end value" },
		{ _field_block, "tracers", &tracerDefinitionBlock_block },
		{ _field_terminator }
	};

	TAG_STRUCT(tracerProperty_real_Struct)
	{
		{ _field_char_enum, "Input Variable", &tracerStateInputEnum },
		{ _field_char_enum, "Range Variable", &tracerStateInputEnum },
		{ _field_char_enum, "Output Modifier", &tracerStateOutputModEnum },
		{ _field_char_enum, "Output Modifier Input", &tracerStateInputEnum },
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_real, "runtime m_constant_value!" },
		{ _field_word_integer, "runtime m_flags!" },
		{ _field_pad, "DSFDSGLKJ", 2 },
		{ _field_terminator }
	};

	TAG_STRUCT(tracerProperty_real_vector3d_Struct)
	{
		{ _field_char_enum, "Input Variable", &tracerStateInputEnum },
		{ _field_char_enum, "Range Variable", &tracerStateInputEnum },
		{ _field_char_enum, "Output Modifier", &tracerStateOutputModEnum },
		{ _field_char_enum, "Output Modifier Input", &tracerStateInputEnum },
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_real, "runtime m_constant_value!" },
		{ _field_word_integer, "runtime m_flags!" },
		{ _field_pad, "DSFDSGLKJ", 2 },
		{ _field_real_vector_3d, "Starting interpolant" },
		{ _field_real_vector_3d, "Ending interpolant" },
		{ _field_terminator }
	};

	TAG_STRUCT(tracerProperty_real_point2d_Struct)
	{
		{ _field_char_enum, "Input Variable", &tracerStateInputEnum },
		{ _field_char_enum, "Range Variable", &tracerStateInputEnum },
		{ _field_char_enum, "Output Modifier", &tracerStateOutputModEnum },
		{ _field_char_enum, "Output Modifier Input", &tracerStateInputEnum },
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_real, "runtime m_constant_value!" },
		{ _field_word_integer, "runtime m_flags!" },
		{ _field_pad, "DSFDSGLKJ", 2 },
		{ _field_real_vector_2d, "Starting interpolant" },
		{ _field_real_vector_2d, "Ending interpolant" },
		{ _field_terminator }
	};

	TAG_STRUCT(tracerProperty_real_rgb_color_Struct)
	{
		{ _field_char_enum, "Input Variable", &tracerStateInputEnum },
		{ _field_char_enum, "Range Variable", &tracerStateInputEnum },
		{ _field_char_enum, "Output Modifier", &tracerStateOutputModEnum },
		{ _field_char_enum, "Output Modifier Input", &tracerStateInputEnum },
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_real, "runtime m_constant_value!" },
		{ _field_word_integer, "runtime m_flags!" },
		{ _field_pad, "DSFDSGLKJ", 2 },
		{ _field_terminator }
	};

	STRINGS(tracerStateInputEnum)
	{
		"profile age",
		"profile position",
		"unused",
		"profile random",
		"profile correlation 1",
		"profile correlation 2",
		"profile correlation 3",
		"profile correlation 4",
		"game time",
		"tracer random",
		"tracer correlation 1",
		"tracer correlation 2",
		"tracer speed",
		"tracer length",
		"system age",
		"system lod",
		"effect a scale",
		"effect b scale",
		"invalid state --- please set again"
	};
	STRING_LIST(tracerStateInputEnum, tracerStateInputEnum_strings, _countof(tracerStateInputEnum_strings));

	STRINGS(tracerStateOutputModEnum)
	{
		" ",
		"Plus",
		"Times"
	};
	STRING_LIST(tracerStateOutputModEnum, tracerStateOutputModEnum_strings, _countof(tracerStateOutputModEnum_strings));

	STRINGS(tracerProfileShapeEnum)
	{
		"aligned ribbon",
		"cross",
		"n-gon",
		"horizontal",
		"vertical"
	};
	STRING_LIST(tracerProfileShapeEnum, tracerProfileShapeEnum_strings, _countof(tracerProfileShapeEnum_strings));

	STRINGS(tracerFlags)
	{
		"disabled for debugging"
	};
	STRING_LIST(tracerFlags, tracerFlags_strings, _countof(tracerFlags_strings));

	STRINGS(tracerAppearanceFlags)
	{
		"tint from lightmap",				// _tint_from_lightmap_bit
		"double-sided",						// _double_sided_bit
		"profile opacity from scale a",		// _profile_opacity_from_scale_a_bit
		"random u offset",					// _random_u_offset_bit
		"random v offset",					// _random_v_offset_bit

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		"can render low res",

		{ _field_version_equal, _engine_type_halo4 },
		"unknown 64",
		"unknown 128",

	};
	STRING_LIST(tracerAppearanceFlags, tracerAppearanceFlags_strings, _countof(tracerAppearanceFlags_strings));

	STRINGS(tracerSystemFlags)
	{
		"point-to-point#skips the update step, and ignores lifespan, for point-to-point effects",
		"draw in first person pass (dangerous)#use this only if the entire tracer is in \"first person space\"; can lead to depth artifacts if misused",
		"disable when zoomed"
	};
	STRING_LIST(tracerSystemFlags, tracerSystemFlags_strings, _countof(tracerSystemFlags_strings));

} // namespace blofeld

