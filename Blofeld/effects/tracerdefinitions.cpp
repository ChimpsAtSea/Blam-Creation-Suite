#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(tracer_system, TRACER_SYSTEM_TAG, tracer_system_block_block );

	TAG_BLOCK(tracerDefinitionBlock, TracerSystemDefinition::k_maxTracers)
	{
		FIELD( _field_custom ),
		FIELD( _field_string_id, "tracer name^" ),
		FIELD( _field_byte_flags, "flags", &tracerFlags ),
		FIELD( _field_custom, "Tracer Shape" ),
		FIELD( _field_char_enum, "profile shape", &tracerProfileShapeEnum ),
		FIELD( _field_byte_integer, "number of n-gon sides" ),
		FIELD( _field_pad, "tracpad", 1 ),
		FIELD( _field_real, "origin fade range{origin fade distance}:world units#distance beyond cutoff over which tracers fade" ),
		FIELD( _field_real, "origin fade cutoff:world units#distance from tracer origin where fade begins" ),
		FIELD( _field_real, "edge fade range:degrees#degrees beyond cutoff over which tracers fade" ),
		FIELD( _field_real, "edge fade cutoff:degrees#degrees away from edge-on where fade is total" ),
		FIELD( _field_struct, "profile lifespan#seconds", &tracerProperty_real_Struct_struct_definition ),
		FIELD( _field_struct, "profile self acceleration#world units per second-squared", &tracerProperty_real_vector3d_Struct_struct_definition ),
		FIELD( _field_struct, "length#world units", &tracerProperty_real_Struct_struct_definition ),
		FIELD( _field_struct, "offset#world units", &tracerProperty_real_Struct_struct_definition ),
		FIELD( _field_struct, "profile size#world units", &tracerProperty_real_Struct_struct_definition ),
		FIELD( _field_struct, "profile density#profiles per world unit", &tracerProperty_real_Struct_struct_definition ),
		FIELD( _field_struct, "profile offset#world units", &tracerProperty_real_point2d_Struct_struct_definition ),
		FIELD( _field_struct, "profile rotation#degrees", &tracerProperty_real_Struct_struct_definition ),
		FIELD( _field_struct, "profile rotation rate#degrees per second", &tracerProperty_real_Struct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_custom, "Tracer Appearance" ),
		FIELD( _field_word_flags, "appearance flags", &tracerAppearanceFlags ),
		FIELD( _field_short_integer, "sort bias#use values between -10 and 10 to move closer and farther from camera (positive is closer)" ),
		FIELD( _field_custom, "material" ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "actual material\?", &material_struct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_real_vector_2d, "uv tiling:u lengthwise, v crosswise#u is tiles/world unit, v is absolute tiles" ),
		FIELD( _field_real_vector_2d, "uv scrolling:tiles per second" ),
		FIELD( _field_real, "angle fade range:degrees#radial (from tracer axis) degrees beyond beginning angle over which tracer fades" ),
		FIELD( _field_real, "angle fade begin:degrees#radial (from tracer axis) degrees away from face-on where fade begins" ),
		FIELD( _field_struct, "profile color", &tracerProperty_real_rgb_color_Struct_struct_definition ),
		FIELD( _field_struct, "profile alpha", &tracerProperty_real_Struct_struct_definition ),
		FIELD( _field_struct, "profile alpha2", &tracerProperty_real_Struct_struct_definition ),
		FIELD( _field_struct, "profile black point", &tracerProperty_real_Struct_struct_definition ),
		FIELD( _field_struct, "profile palette", &tracerProperty_real_Struct_struct_definition ),
		FIELD( _field_struct, "profile intensity", &tracerProperty_real_Struct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_custom ),
		FIELD( _field_dword_integer, "runtime m_constantPerProfileProperties!" ),
		FIELD( _field_dword_integer, "runtime m_usedStates!" ),
		FIELD( _field_dword_integer, "runtime m_maxProfileCount!" ),
		FIELD( _field_struct, "runtime m_gpuData!", &gpu_property_function_color_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(tracer_system_block, 1, tracer_system_struct_definition_struct_definition );

	TAG_STRUCT(tracer_system_struct_definition)
	{
		FIELD( _field_long_flags, "tracer system flags", &tracerSystemFlags ),
		FIELD( _field_explanation, "far lod" ),
		FIELD( _field_real, "far lod start" ),
		FIELD( _field_real, "far lod end" ),
		FIELD( _field_real, "far lod start value" ),
		FIELD( _field_real, "far lod end value" ),
		FIELD( _field_block, "tracers", &tracerDefinitionBlock_block ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(tracerProperty_real_Struct)
	{
		FIELD( _field_char_enum, "Input Variable", &tracerStateInputEnum ),
		FIELD( _field_char_enum, "Range Variable", &tracerStateInputEnum ),
		FIELD( _field_char_enum, "Output Modifier", &tracerStateOutputModEnum ),
		FIELD( _field_char_enum, "Output Modifier Input", &tracerStateInputEnum ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
		FIELD( _field_real, "runtime m_constant_value!" ),
		FIELD( _field_word_integer, "runtime m_flags!" ),
		FIELD( _field_pad, "DSFDSGLKJ", 2 ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(tracerProperty_real_vector3d_Struct)
	{
		FIELD( _field_char_enum, "Input Variable", &tracerStateInputEnum ),
		FIELD( _field_char_enum, "Range Variable", &tracerStateInputEnum ),
		FIELD( _field_char_enum, "Output Modifier", &tracerStateOutputModEnum ),
		FIELD( _field_char_enum, "Output Modifier Input", &tracerStateInputEnum ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
		FIELD( _field_real, "runtime m_constant_value!" ),
		FIELD( _field_word_integer, "runtime m_flags!" ),
		FIELD( _field_pad, "DSFDSGLKJ", 2 ),
		FIELD( _field_real_vector_3d, "Starting interpolant" ),
		FIELD( _field_real_vector_3d, "Ending interpolant" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(tracerProperty_real_point2d_Struct)
	{
		FIELD( _field_char_enum, "Input Variable", &tracerStateInputEnum ),
		FIELD( _field_char_enum, "Range Variable", &tracerStateInputEnum ),
		FIELD( _field_char_enum, "Output Modifier", &tracerStateOutputModEnum ),
		FIELD( _field_char_enum, "Output Modifier Input", &tracerStateInputEnum ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
		FIELD( _field_real, "runtime m_constant_value!" ),
		FIELD( _field_word_integer, "runtime m_flags!" ),
		FIELD( _field_pad, "DSFDSGLKJ", 2 ),
		FIELD( _field_real_vector_2d, "Starting interpolant" ),
		FIELD( _field_real_vector_2d, "Ending interpolant" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(tracerProperty_real_rgb_color_Struct)
	{
		FIELD( _field_char_enum, "Input Variable", &tracerStateInputEnum ),
		FIELD( _field_char_enum, "Range Variable", &tracerStateInputEnum ),
		FIELD( _field_char_enum, "Output Modifier", &tracerStateOutputModEnum ),
		FIELD( _field_char_enum, "Output Modifier Input", &tracerStateInputEnum ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
		FIELD( _field_real, "runtime m_constant_value!" ),
		FIELD( _field_word_integer, "runtime m_flags!" ),
		FIELD( _field_pad, "DSFDSGLKJ", 2 ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(tracerStateInputEnum, 19)
	{
		OPTION("profile age"),
		OPTION("profile position"),
		OPTION("unused"),
		OPTION("profile random"),
		OPTION("profile correlation 1"),
		OPTION("profile correlation 2"),
		OPTION("profile correlation 3"),
		OPTION("profile correlation 4"),
		OPTION("game time"),
		OPTION("tracer random"),
		OPTION("tracer correlation 1"),
		OPTION("tracer correlation 2"),
		OPTION("tracer speed"),
		OPTION("tracer length"),
		OPTION("system age"),
		OPTION("system lod"),
		OPTION("effect a scale"),
		OPTION("effect b scale"),
		OPTION("invalid state --- please set again"),
	};

	TAG_ENUM(tracerStateOutputModEnum, 3)
	{
		OPTION(" "),
		OPTION("Plus"),
		OPTION("Times"),
	};

	TAG_ENUM(tracerProfileShapeEnum, 5)
	{
		OPTION("aligned ribbon"),
		OPTION("cross"),
		OPTION("n-gon"),
		OPTION("horizontal"),
		OPTION("vertical"),
	};

	TAG_ENUM(tracerFlags, 1)
	{
		OPTION("disabled for debugging"),
	};

	TAG_ENUM(tracerAppearanceFlags, 6)
	{
		OPTION("tint from lightmap"),
		OPTION("double-sided"),
		OPTION("profile opacity from scale a"),
		OPTION("random u offset"),
		OPTION("random v offset"),
		OPTION("can render low res"),
	};

	TAG_ENUM(tracerSystemFlags, 3)
	{
		OPTION("point-to-point#skips the update step, and ignores lifespan, for point-to-point effects"),
		OPTION("draw in first person pass (dangerous)#use this only if the entire tracer is in \"first person space\"; can lead to depth artifacts if misused"),
		OPTION("disable when zoomed"),
	};

} // namespace blofeld

