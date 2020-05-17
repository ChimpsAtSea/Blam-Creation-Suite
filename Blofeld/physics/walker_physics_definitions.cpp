#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(walker_physics_leg_group_enum, 2)
	{
		OPTION("primary"),
		OPTION("secondary"),
	};

	TAG_ENUM(walker_physics_leg_side_enum, 2)
	{
		OPTION("left"),
		OPTION("right"),
	};

	TAG_ENUM(walker_physics_leg_flags, 1)
	{
		OPTION("constrained plant"),
	};

	TAG_BLOCK(walker_physics_leg_block, s_walker_physics_definition::k_maximum_leg_count)
	{
		FIELD( _field_explanation, "walker physics" ),
		FIELD( _field_char_enum, "leg group", &walker_physics_leg_group_enum ),
		FIELD( _field_char_enum, "leg side", &walker_physics_leg_side_enum ),
		FIELD( _field_char_integer, "leg side order#for each side order the legs from 0-n where 0 is the most forward leg" ),
		FIELD( _field_char_integer, "valid!" ),
		FIELD( _field_string_id, "hip node a name" ),
		FIELD( _field_string_id, "hip node b name" ),
		FIELD( _field_string_id, "knee node a name" ),
		FIELD( _field_string_id, "knee node b name" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "foot marker name" ),
		FIELD( _field_pad, "RLTGT", 60 ),
		FIELD( _field_long_flags, "flags", &walker_physics_leg_flags ),
		FIELD( _field_real_vector_3d, "runtime initial origin to hip offset!" ),
		FIELD( _field_real_vector_3d, "runtime pivot center to hip offset!" ),
		FIELD( _field_real, "runtime upper leg length!" ),
		FIELD( _field_real, "runtime lower leg length!" ),
		FIELD( _field_short_integer, "runtime hip node a index!" ),
		FIELD( _field_short_integer, "runtime hip node b index!" ),
		FIELD( _field_short_integer, "runtime knee node a index!" ),
		FIELD( _field_short_integer, "runtime knee node b index!" ),
		FIELD( _field_short_integer, "runtime foot marker group index!" ),
		FIELD( _field_short_integer, "runtime foot node index!" ),
		FIELD( _field_short_integer, "runtime hip node index!" ),
		FIELD( _field_short_integer, "runtime knee node index!" ),
		FIELD( _field_real_vector_3d, "plant constraint position!" ),
		FIELD( _field_pad, "GKX", 12 ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(walker_physics_struct)
{
		FIELD( _field_real_vector_3d, "maximum leg motion#in WU, how far can we displace the legs in x,y,z each step" ),
		FIELD( _field_real, "maximum turn#in degrees, how much can this walker turn in one step" ),
		FIELD( _field_block, "legs", &walker_physics_leg_block_block ),
		FIELD( _field_real, "leg apex fraction#0-1 fraction.  where the leg tansitions from lift to drop" ),
		FIELD( _field_real, "lift exponent# x(0-1) power exponent" ),
		FIELD( _field_real, "drop exponent# x(0-1) power exponent" ),
		FIELD( _field_real_vector_3d, "object space pivot position!" ),
		FIELD( _field_terminator )
};

} // namespace blofeld

