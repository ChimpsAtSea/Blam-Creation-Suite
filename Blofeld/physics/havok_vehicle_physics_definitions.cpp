#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(havok_vehicle_physics_struct)
{
	FIELD( _field_long_flags, "flags*" ),
	FIELD( _field_custom ),
	FIELD( _field_real, "ground friction#this sucks.  for friction based vehicles only" ),
	FIELD( _field_real, "ground depth#this sucks.  for friction based vehicles only" ),
	FIELD( _field_real, "ground damp factor#this sucks.  for friction based vehicles only" ),
	FIELD( _field_real, "ground moving friction#this sucks.  for friction based vehicles only" ),
	FIELD( _field_real, "ground maximum slope 0#degrees 0-90" ),
	FIELD( _field_real, "ground maximum slope 1#degrees 0-90.  and greater than slope 0" ),
	FIELD( _field_real, "maximum normal force contribution#0 defaults to 3, this prevents the physics from becoming unstable when hucked against a surface" ),
	FIELD( _field_real, "anti_gravity_bank_lift#lift per WU." ),
	FIELD( _field_real, "steering_bank_reaction_scale#how quickly we bank when we steer " ),
	FIELD( _field_real, "gravity scale#value of 0 defaults to 1.  .5 is half gravity" ),
	FIELD( _field_custom ),
	FIELD( _field_enum, "maximum update period ticks#ticks. 0 is default of 2" ),
	FIELD( _field_enum, "maximum remote update period ticks#ticks. when controlled by an ai or remote player. 0 defaults to 4" ),
	FIELD( _field_long_integer, "iteration count# 0 defaults to 1.  Number of iterations per frame of physics" ),
	FIELD( _field_long_integer, "suspension count*!" ),
	FIELD( _field_block, "anti gravity points", &anti_gravity_point_definition_block ),
	FIELD( _field_block, "friction points", &friction_point_definition_block ),
	FIELD( _field_struct, "boat physics", &boat_physics_definition_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(anti_gravity_point_definition_block, k_maximum_anti_gravity_points_per_vehicle_physics_definition)
{
	FIELD( _field_custom ),
	FIELD( _field_string_id, "marker name^" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_long_enum, "damping" ),
	FIELD( _field_custom ),
	FIELD( _field_real, "antigrav strength" ),
	FIELD( _field_real, "antigrav height" ),
	FIELD( _field_real, "antigrav compression damping{antigrav damp factor}" ),
	FIELD( _field_real, "antigrav extension damping" ),
	FIELD( _field_real, "antigrav normal k1" ),
	FIELD( _field_real, "antigrav normal k0" ),
	FIELD( _field_real, "radius" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "collision global material name" ),
	FIELD( _field_short_integer, "runtime global material index!" ),
	FIELD( _field_short_integer, "WU!" ),
	FIELD( _field_string_id, "damage source region name" ),
	FIELD( _field_real, "default state error" ),
	FIELD( _field_real, "minor damage error" ),
	FIELD( _field_real, "medium damage error" ),
	FIELD( _field_real, "major damage error" ),
	FIELD( _field_real, "destroyed state error" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(friction_point_definition_block, k_maximum_friction_points_per_vehicle_physics_definition)
{
	FIELD( _field_custom ),
	FIELD( _field_string_id, "marker name^" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_custom ),
	FIELD( _field_real, "fraction of total mass#(0.0-1.0) fraction of total vehicle mass" ),
	FIELD( _field_real, "radius" ),
	FIELD( _field_real, "damaged radius#radius when the tire is blown off." ),
	FIELD( _field_real, "ground friction scale# scale the non sliding friction on this friction point" ),
	FIELD( _field_real, "AI ground friction scale override# use this value when an AI is driving" ),
	FIELD( _field_real, "moving friction velocity diff" ),
	FIELD( _field_real, "moving friction scale# scale the sliding friction on this friction point, active when velocity is greater than moving friction velocity diff" ),
	FIELD( _field_real, "AI moving friction scale override# use this value when an AI is driving" ),
	FIELD( _field_real, "e-brake moving friction" ),
	FIELD( _field_real, "e-brake friction" ),
	FIELD( _field_real, "e-brake moving friction vel diff" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "collision global material name" ),
	FIELD( _field_short_integer, "runtime global material index!" ),
	FIELD( _field_explanation, "friction point destruction data" ),
	FIELD( _field_enum, "model state destroyed#only need point can destroy flag set" ),
	FIELD( _field_string_id, "region name#only need point can destroy flag set" ),
	FIELD( _field_long_integer, "runtime region index!" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

