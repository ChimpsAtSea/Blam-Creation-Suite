#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(tracer_system_struct_definition)
{
	FIELD( _field_long_flags, "tracer system flags" ),
	FIELD( _field_explanation, "far lod" ),
	FIELD( _field_real, "far lod start" ),
	FIELD( _field_real, "far lod end" ),
	FIELD( _field_real, "far lod start value" ),
	FIELD( _field_real, "far lod end value" ),
	FIELD( _field_block, "tracers", &tracerDefinitionBlock ),
	FIELD( _field_terminator )
};

TAG_STRUCT(tracerProperty_real_Struct)
{
	FIELD( _field_char_enum, "Input Variable" ),
	FIELD( _field_char_enum, "Range Variable" ),
	FIELD( _field_char_enum, "Output Modifier" ),
	FIELD( _field_char_enum, "Output Modifier Input" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
	FIELD( _field_real, "runtime m_constant_value!" ),
	FIELD( _field_word_integer, "runtime m_flags!" ),
	FIELD( _field_pad, "DSFDSGLKJ", 2 ),
	FIELD( _field_terminator )
};

TAG_STRUCT(tracerProperty_real_vector3d_Struct)
{
	FIELD( _field_char_enum, "Input Variable" ),
	FIELD( _field_char_enum, "Range Variable" ),
	FIELD( _field_char_enum, "Output Modifier" ),
	FIELD( _field_char_enum, "Output Modifier Input" ),
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
	FIELD( _field_char_enum, "Input Variable" ),
	FIELD( _field_char_enum, "Range Variable" ),
	FIELD( _field_char_enum, "Output Modifier" ),
	FIELD( _field_char_enum, "Output Modifier Input" ),
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
	FIELD( _field_char_enum, "Input Variable" ),
	FIELD( _field_char_enum, "Range Variable" ),
	FIELD( _field_char_enum, "Output Modifier" ),
	FIELD( _field_char_enum, "Output Modifier Input" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
	FIELD( _field_real, "runtime m_constant_value!" ),
	FIELD( _field_word_integer, "runtime m_flags!" ),
	FIELD( _field_pad, "DSFDSGLKJ", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(tracerDefinitionBlock, TracerSystemDefinition::k_maxTracers)
{
	FIELD( _field_custom ),
	FIELD( _field_string_id, "tracer name^" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_custom, "Tracer Shape" ),
	FIELD( _field_char_enum, "profile shape" ),
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
	FIELD( _field_word_flags, "appearance flags" ),
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

TAG_GROUP(tracer_system_block, TRACER_SYSTEM_TAG)
{
	FIELD( _field_long_flags, "tracer system flags" ),
	FIELD( _field_explanation, "far lod" ),
	FIELD( _field_real, "far lod start" ),
	FIELD( _field_real, "far lod end" ),
	FIELD( _field_real, "far lod start value" ),
	FIELD( _field_real, "far lod end value" ),
	FIELD( _field_block, "tracers", &tracerDefinitionBlock ),
	FIELD( _field_terminator )
};

} // namespace blofeld

