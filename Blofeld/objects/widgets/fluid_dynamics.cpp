#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(fluid_dynamics_squirter, MAXIMUM_SQUIRTERS_PER_FLUID_DYNAMICS)
{
	{ _field_point_2d, "grid location" },
	{ _field_skip, "JKISKKJS", 48 },
	{ _field_real, "squirt scale" },
	{ _field_terminator },
};

TAG_BLOCK(fluid_dynamics_inflow, MAXIMUM_INFLOWS_PER_FLUID_DYNAMICS)
{
	{ _field_point_2d, "grid location" },
	{ _field_real, "inflow rate#particles/sec" },
	{ _field_real, "inflow angle#degrees" },
	{ _field_real, "inflow velocity scale" },
	{ _field_terminator },
};

TAG_BLOCK(fluid_dynamics_outflow, MAXIMUM_OUTFLOWS_PER_FLUID_DYNAMICS)
{
	{ _field_point_2d, "grid location" },
	{ _field_terminator },
};

TAG_BLOCK(fluid_dynamics_obstacle, MAXIMUM_OBSTACLES_PER_FLUID_DYNAMICS)
{
	{ _field_point_2d, "2x2 grid location" },
	{ _field_terminator },
};

TAG_GROUP(fluid_dynamics, FLUID_DYNAMICS_TAG)
{
	{ _field_long_flags, "flags" },
	{ _field_string_id, "marker attachment name" },
	{ _field_real, "diffusion rate#0.0000001->0.0000100" },
	{ _field_real, "viscosity#0.0000001->0.0060000" },
	{ _field_pad, "FIRWW", 40 },
	{ _field_short_integer, "number grid cells width#grid cells across" },
	{ _field_short_integer, "update rate#game updates per velocity field update" },
	{ _field_real, "particle gravity multiplier" },
	{ _field_real, "grid cell width#world units" },
	{ _field_real, "grid cell height#world units" },
	{ _field_short_integer, "maximum particles per cell#0 is no max. teleports ># away randomly" },
	{ _field_pad, "SKT", 2 },
	{ _field_pad, "DBNFAM", 76 },
	{ _field_short_integer, "number of tracers" },
	{ _field_pad, "FQ", 2 },
	{ _field_real_bounds, "tracer time multipier range" },
	{ _field_real, "tracer max velocity influence scale#1-32" },
	{ _field_pad, "NYUBJV", 36 },
	{ _field_short_integer, "number of particles#should = number of particles in the effect" },
	{ _field_short_integer, "particle collision rate#game updates per collision update" },
	{ _field_real, "particle collision radius#world units" },
	{ _field_real, "particle movement multiplier#0.001-5.0" },
	{ _field_real, "particle force to center of grid scale#0.001-5.0" },
	{ _field_real, "particle drag coeff#0-1" },
	{ _field_real, "maximum particle velocity(disabled)" },
	{ _field_pad, "DNF", 28 },
	{ _field_block, "particle effects", &particle_system_definition_block },
	{ _field_pad, "ZJSKRR", 20 },
	{ _field_block, "squirters", &fluid_dynamics_squirter_block },
	{ _field_block, "inflow", &fluid_dynamics_inflow_block },
	{ _field_block, "outflow", &fluid_dynamics_outflow_block },
	{ _field_block, "obstacles", &fluid_dynamics_obstacle_block },
	{ _field_explanation, "Cylinder map" },
	{ _field_struct, "cylindrical radius" },
	{ _field_terminator },
};

} // namespace blofeld

