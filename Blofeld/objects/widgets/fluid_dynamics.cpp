#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(fluid_dynamics, FLUID_DYNAMICS_TAG, fluid_dynamics_block_block );

TAG_BLOCK_FROM_STRUCT(fluid_dynamics_block, 1, fluid_dynamics_struct_definition_struct_definition );

TAG_BLOCK(fluid_dynamics_squirter_block, MAXIMUM_SQUIRTERS_PER_FLUID_DYNAMICS)
{
	FIELD( _field_point_2d, "grid location" ),
	FIELD( _field_skip, "JKISKKJS", 48 ),
	FIELD( _field_real, "squirt scale" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(fluid_dynamics_inflow_block, MAXIMUM_INFLOWS_PER_FLUID_DYNAMICS)
{
	FIELD( _field_point_2d, "grid location" ),
	FIELD( _field_real, "inflow rate#particles/sec" ),
	FIELD( _field_real, "inflow angle#degrees" ),
	FIELD( _field_real, "inflow velocity scale" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(fluid_dynamics_outflow_block, MAXIMUM_OUTFLOWS_PER_FLUID_DYNAMICS)
{
	FIELD( _field_point_2d, "grid location" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(fluid_dynamics_obstacle_block, MAXIMUM_OBSTACLES_PER_FLUID_DYNAMICS)
{
	FIELD( _field_point_2d, "2x2 grid location" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(fluid_dynamics_struct_definition)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_string_id, "marker attachment name" ),
	FIELD( _field_real, "diffusion rate#0.0000001->0.0000100" ),
	FIELD( _field_real, "viscosity#0.0000001->0.0060000" ),
	FIELD( _field_pad, "FIRWW", 40 ),
	FIELD( _field_short_integer, "number grid cells width#grid cells across" ),
	FIELD( _field_short_integer, "update rate#game updates per velocity field update" ),
	FIELD( _field_real, "particle gravity multiplier" ),
	FIELD( _field_real, "grid cell width#world units" ),
	FIELD( _field_real, "grid cell height#world units" ),
	FIELD( _field_short_integer, "maximum particles per cell#0 is no max. teleports ># away randomly" ),
	FIELD( _field_pad, "SKT", 2 ),
	FIELD( _field_pad, "DBNFAM", 76 ),
	FIELD( _field_short_integer, "number of tracers" ),
	FIELD( _field_pad, "FQ", 2 ),
	FIELD( _field_real_bounds, "tracer time multipier range" ),
	FIELD( _field_real, "tracer max velocity influence scale#1-32" ),
	FIELD( _field_pad, "NYUBJV", 36 ),
	FIELD( _field_short_integer, "number of particles#should = number of particles in the effect" ),
	FIELD( _field_short_integer, "particle collision rate#game updates per collision update" ),
	FIELD( _field_real, "particle collision radius#world units" ),
	FIELD( _field_real, "particle movement multiplier#0.001-5.0" ),
	FIELD( _field_real, "particle force to center of grid scale#0.001-5.0" ),
	FIELD( _field_real, "particle drag coeff#0-1" ),
	FIELD( _field_real, "maximum particle velocity(disabled)" ),
	FIELD( _field_pad, "DNF", 28 ),
	FIELD( _field_block, "particle effects", &particle_system_definition_block_new_block ),
	FIELD( _field_pad, "ZJSKRR", 20 ),
	FIELD( _field_block, "squirters", &fluid_dynamics_squirter_block_block ),
	FIELD( _field_block, "inflow", &fluid_dynamics_inflow_block_block ),
	FIELD( _field_block, "outflow", &fluid_dynamics_outflow_block_block ),
	FIELD( _field_block, "obstacles", &fluid_dynamics_obstacle_block_block ),
	FIELD( _field_explanation, "Cylinder map" ),
	FIELD( _field_struct, "cylindrical radius", &g_single_scalar_function_evaluation_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(g_single_scalar_function_evaluation_struct)
{
	FIELD( _field_real, "input" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "scalar", &mapping_function_struct_definition ),
	FIELD( _field_pad, "LOHRT", 16 ),
	FIELD( _field_terminator )
};

} // namespace blofeld

