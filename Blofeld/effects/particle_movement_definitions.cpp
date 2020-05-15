#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(particle_controller, c_particle_movement_definition::k_type_count + 2)
{
	{ _field_enum, "type" },
	{ _field_byte_flags, "flags!" },
	{ _field_pad, "KNTXOMS", 1 },
	{ _field_block, "parameters", &particle_controller_parameters_block },
	{ _field_long_integer, "runtime m_constant_parameters!" },
	{ _field_long_integer, "runtime m_used_particle_states!" },
	{ _field_terminator },
};

TAG_BLOCK(particle_controller_parameters, c_particle_movement_definition::k_flocking_parameter_count)
{
	{ _field_long_integer, "parameter id" },
	{ _field_struct, "property" },
	{ _field_terminator },
};

TAG_GROUP(particle_physics, PARTICLE_PHYSICS_TAG)
{
	{ _field_tag_reference, "template" },
	{ _field_word_flags, "flags" },
	{ _field_char_integer, "collision controller index!" },
	{ _field_char_integer, "turbulence controller index!" },
	{ _field_char_integer, "global force controller index!" },
	{ _field_pad, "pphys", 3 },
	{ _field_block, "movements", &particle_controller_block },
	{ _field_tag_reference, "turbulence texture" },
	{ _field_terminator },
};

} // namespace blofeld

