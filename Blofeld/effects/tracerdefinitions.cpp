#include <blofeld-private-pch.h>

namespace blofeld
{

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
	FIELD( _field_struct, "profile lifespan#seconds" ),
	FIELD( _field_struct, "profile self acceleration#world units per second-squared" ),
	FIELD( _field_struct, "length#world units" ),
	FIELD( _field_struct, "offset#world units" ),
	FIELD( _field_struct, "profile size#world units" ),
	FIELD( _field_struct, "profile density#profiles per world unit" ),
	FIELD( _field_struct, "profile offset#world units" ),
	FIELD( _field_struct, "profile rotation#degrees" ),
	FIELD( _field_struct, "profile rotation rate#degrees per second" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Tracer Appearance" ),
	FIELD( _field_word_flags, "appearance flags" ),
	FIELD( _field_short_integer, "sort bias#use values between -10 and 10 to move closer and farther from camera (positive is closer)" ),
	FIELD( _field_custom, "material" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "actual material\?" ),
	FIELD( _field_custom ),
	FIELD( _field_real_vector_2d, "uv tiling:u lengthwise, v crosswise#u is tiles/world unit, v is absolute tiles" ),
	FIELD( _field_real_vector_2d, "uv scrolling:tiles per second" ),
	FIELD( _field_real, "angle fade range:degrees#radial (from tracer axis) degrees beyond beginning angle over which tracer fades" ),
	FIELD( _field_real, "angle fade begin:degrees#radial (from tracer axis) degrees away from face-on where fade begins" ),
	FIELD( _field_struct, "profile color" ),
	FIELD( _field_struct, "profile alpha" ),
	FIELD( _field_struct, "profile alpha2" ),
	FIELD( _field_struct, "profile black point" ),
	FIELD( _field_struct, "profile palette" ),
	FIELD( _field_struct, "profile intensity" ),
	FIELD( _field_custom ),
	FIELD( _field_custom ),
	FIELD( _field_dword_integer, "runtime m_constantPerProfileProperties!" ),
	FIELD( _field_dword_integer, "runtime m_usedStates!" ),
	FIELD( _field_dword_integer, "runtime m_maxProfileCount!" ),
	FIELD( _field_struct, "runtime m_gpuData!" ),
	FIELD( _field_terminator )
};

TAG_GROUP(tracer_system, TRACER_SYSTEM_TAG)
{
	FIELD( _field_long_flags, "tracer system flags" ),
	FIELD( _field_explanation, "far lod" ),
	FIELD( _field_real, "far lod start" ),
	FIELD( _field_real, "far lod end" ),
	FIELD( _field_real, "far lod start value" ),
	FIELD( _field_real, "far lod end value" ),
	FIELD( _field_block, "tracers", &tracerDefinitionBlock_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

