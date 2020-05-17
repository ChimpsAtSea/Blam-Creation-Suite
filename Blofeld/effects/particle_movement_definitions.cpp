#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(particle_physics, PARTICLE_PHYSICS_TAG, particle_physics_block_block );

	TAG_BLOCK(particle_controller_parameters, c_particle_movement_definition::k_flocking_parameter_count)
	{
		FIELD( _field_long_integer, "parameter id" ),
		FIELD( _field_struct, "property", &particle_property_scalar_struct_new_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(particle_controller, c_particle_movement_definition::k_type_count + 2)
	{
		FIELD( _field_enum, "type", &particle_movement_type ),
		FIELD( _field_byte_flags, "flags!", &particle_controller_flags ),
		FIELD( _field_pad, "KNTXOMS", 1 ),
		FIELD( _field_block, "parameters", &particle_controller_parameters_block ),
		FIELD( _field_long_integer, "runtime m_constant_parameters!" ),
		FIELD( _field_long_integer, "runtime m_used_particle_states!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(particle_physics_block, 1, particle_physics_struct_definition_struct_definition );

	TAG_STRUCT(particle_physics_struct)
	{
		FIELD( _field_tag_reference, "template" ),
		FIELD( _field_word_flags, "flags", &particle_movement_flags ),
		FIELD( _field_char_integer, "collision controller index!" ),
		FIELD( _field_char_integer, "turbulence controller index!" ),
		FIELD( _field_char_integer, "global force controller index!" ),
		FIELD( _field_pad, "pphys", 3 ),
		FIELD( _field_block, "movements", &particle_controller_block ),
		FIELD( _field_tag_reference, "turbulence texture" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(particle_physics_struct_definition)
	{
		FIELD( _field_tag_reference, "template" ),
		FIELD( _field_word_flags, "flags", &particle_movement_flags ),
		FIELD( _field_char_integer, "collision controller index!" ),
		FIELD( _field_char_integer, "turbulence controller index!" ),
		FIELD( _field_char_integer, "global force controller index!" ),
		FIELD( _field_pad, "pphys", 3 ),
		FIELD( _field_block, "movements", &particle_controller_block ),
		FIELD( _field_tag_reference, "turbulence texture" ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(particle_movement_flags, 12)
	{
		OPTION("physics"),
		OPTION("collide with structure"),
		OPTION("collide with water"),
		OPTION("collide with scenery"),
		OPTION("collide with vehicles"),
		OPTION("collide with bipeds"),
		OPTION("always collide every frame"),
		OPTION("swarm"),
		OPTION("wind"),
		OPTION("turbulence"),
		OPTION("global force"),
		OPTION("disable swarm collision"),
	};

	TAG_ENUM(particle_movement_type, 6)
	{
		OPTION("physics"),
		OPTION("collider"),
		OPTION("swarm"),
		OPTION("wind"),
		OPTION("turbulence"),
		OPTION("global force"),
	};

	TAG_ENUM(particle_controller_flags, 1)
	{
		OPTION("properties fully indexed"),
	};

} // namespace blofeld

