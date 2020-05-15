#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(tracerDefinitionBlock, TracerSystemDefinition::k_maxTracers)
{
	{ _field_custom },
	{ _field_string_id, "tracer name^" },
	{ _field_byte_flags, "flags" },
	{ _field_custom, "Tracer Shape" },
	{ _field_char_enum, "profile shape" },
	{ _field_byte_integer, "number of n-gon sides" },
	{ _field_pad, "tracpad", 1 },
	{ _field_real, "origin fade range{origin fade distance}:world units#distance beyond cutoff over which tracers fade" },
	{ _field_real, "origin fade cutoff:world units#distance from tracer origin where fade begins" },
	{ _field_real, "edge fade range:degrees#degrees beyond cutoff over which tracers fade" },
	{ _field_real, "edge fade cutoff:degrees#degrees away from edge-on where fade is total" },
	{ _field_struct, "profile lifespan#seconds" },
	{ _field_struct, "profile self acceleration#world units per second-squared" },
	{ _field_struct, "length#world units" },
	{ _field_struct, "offset#world units" },
	{ _field_struct, "profile size#world units" },
	{ _field_struct, "profile density#profiles per world unit" },
	{ _field_struct, "profile offset#world units" },
	{ _field_struct, "profile rotation#degrees" },
	{ _field_struct, "profile rotation rate#degrees per second" },
	{ _field_custom },
	{ _field_custom, "Tracer Appearance" },
	{ _field_word_flags, "appearance flags" },
	{ _field_short_integer, "sort bias#use values between -10 and 10 to move closer and farther from camera (positive is closer)" },
	{ _field_custom, "material" },
	{ _field_custom },
	{ _field_struct, "actual material\?" },
	{ _field_custom },
	{ _field_real_vector_2d, "uv tiling:u lengthwise, v crosswise#u is tiles/world unit, v is absolute tiles" },
	{ _field_real_vector_2d, "uv scrolling:tiles per second" },
	{ _field_real, "angle fade range:degrees#radial (from tracer axis) degrees beyond beginning angle over which tracer fades" },
	{ _field_real, "angle fade begin:degrees#radial (from tracer axis) degrees away from face-on where fade begins" },
	{ _field_struct, "profile color" },
	{ _field_struct, "profile alpha" },
	{ _field_struct, "profile alpha2" },
	{ _field_struct, "profile black point" },
	{ _field_struct, "profile palette" },
	{ _field_struct, "profile intensity" },
	{ _field_custom },
	{ _field_custom },
	{ _field_dword_integer, "runtime m_constantPerProfileProperties!" },
	{ _field_dword_integer, "runtime m_usedStates!" },
	{ _field_dword_integer, "runtime m_maxProfileCount!" },
	{ _field_struct, "runtime m_gpuData!" },
	{ _field_terminator },
};

TAG_GROUP(tracer_system, TRACER_SYSTEM_TAG)
{
	{ _field_long_flags, "tracer system flags" },
	{ _field_explanation, "far lod" },
	{ _field_real, "far lod start" },
	{ _field_real, "far lod end" },
	{ _field_real, "far lod start value" },
	{ _field_real, "far lod end value" },
	{ _field_block, "tracers", &tracerDefinitionBlock_block },
	{ _field_terminator },
};

} // namespace blofeld

