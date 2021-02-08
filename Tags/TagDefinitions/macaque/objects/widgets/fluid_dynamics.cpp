#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		fluid_dynamics_group,
		FLUID_DYNAMICS_TAG,
		nullptr,
		INVALID_TAG,
		fluid_dynamics_block );

	TAG_BLOCK_FROM_STRUCT(
		fluid_dynamics_block,
		"fluid_dynamics_block",
		1,
		fluid_dynamics_struct_definition);

	#define FLUID_DYNAMICS_SQUIRTER_BLOCK_ID { 0x7414343E, 0x3222489C, 0xB4903432, 0x7654EB15 }
	TAG_BLOCK(
		fluid_dynamics_squirter_block,
		"fluid_dynamics_squirter_block",
		MAXIMUM_SQUIRTERS_PER_FLUID_DYNAMICS,
		"fluid_dynamics_squirter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FLUID_DYNAMICS_SQUIRTER_BLOCK_ID)
	{
		{ _field_point_2d, "grid location" },
		FIELD_SKIP("JKISKKJS", nullptr, FIELD_FLAG_NONE, 48),
		{ _field_real, "squirt scale" },
		{ _field_terminator }
	};

	#define FLUID_DYNAMICS_INFLOW_BLOCK_ID { 0x74143430, 0x32224891, 0xB4903432, 0x7654EB13 }
	TAG_BLOCK(
		fluid_dynamics_inflow_block,
		"fluid_dynamics_inflow_block",
		MAXIMUM_INFLOWS_PER_FLUID_DYNAMICS,
		"fluid_dynamics_inflow",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FLUID_DYNAMICS_INFLOW_BLOCK_ID)
	{
		{ _field_point_2d, "grid location" },
		{ _field_real, "inflow rate", "particles/sec" },
		{ _field_real, "inflow angle", "degrees" },
		{ _field_real, "inflow velocity scale" },
		{ _field_terminator }
	};

	#define FLUID_DYNAMICS_OUTFLOW_BLOCK_ID { 0x7414343A, 0x3222489B, 0xB490343C, 0x7654EB1D }
	TAG_BLOCK(
		fluid_dynamics_outflow_block,
		"fluid_dynamics_outflow_block",
		MAXIMUM_OUTFLOWS_PER_FLUID_DYNAMICS,
		"fluid_dynamics_outflow",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FLUID_DYNAMICS_OUTFLOW_BLOCK_ID)
	{
		{ _field_point_2d, "grid location" },
		{ _field_terminator }
	};

	#define FLUID_DYNAMICS_OBSTACLE_BLOCK_ID { 0x7414341E, 0x3222482C, 0xB4903442, 0x7654EB55 }
	TAG_BLOCK(
		fluid_dynamics_obstacle_block,
		"fluid_dynamics_obstacle_block",
		MAXIMUM_OBSTACLES_PER_FLUID_DYNAMICS,
		"fluid_dynamics_obstacle",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FLUID_DYNAMICS_OBSTACLE_BLOCK_ID)
	{
		{ _field_point_2d, "2x2 grid location" },
		{ _field_terminator }
	};

	#define FLUID_DYNAMICS_STRUCT_DEFINITION_ID { 0x3414341E, 0x3222482C, 0x14903442, 0x0654EB55 }
	TAG_STRUCT(
		fluid_dynamics_struct_definition,
		"fluid_dynamics_struct_definition",
		"fluid_dynamics_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		FLUID_DYNAMICS_STRUCT_DEFINITION_ID)
	{
		{ _field_long_flags, "flags", &fluid_dynamics_flags },
		{ _field_string_id, "marker attachment name" },
		{ _field_real, "diffusion rate", "0.0000001->0.0000100" },
		{ _field_real, "viscosity", "0.0000001->0.0060000" },
		FIELD_PAD("FIRWW", nullptr, FIELD_FLAG_NONE, 40),
		{ _field_short_integer, "number grid cells width", "grid cells across" },
		{ _field_short_integer, "update rate", "game updates per velocity field update" },
		{ _field_real, "particle gravity multiplier" },
		{ _field_real, "grid cell width", "world units" },
		{ _field_real, "grid cell height", "world units" },
		{ _field_short_integer, "maximum particles per cell", "0 is no max. teleports ># away randomly" },
		FIELD_PAD("SKT", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD("DBNFAM", nullptr, FIELD_FLAG_NONE, 76),
		{ _field_short_integer, "number of tracers" },
		FIELD_PAD("FQ", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_bounds, "tracer time multipier range" },
		{ _field_real, "tracer max velocity influence scale", "1-32" },
		FIELD_PAD("NYUBJV", nullptr, FIELD_FLAG_NONE, 36),
		{ _field_short_integer, "number of particles", "should = number of particles in the effect" },
		{ _field_short_integer, "particle collision rate", "game updates per collision update" },
		{ _field_real, "particle collision radius", "world units" },
		{ _field_real, "particle movement multiplier", "0.001-5.0" },
		{ _field_real, "particle force to center of grid scale", "0.001-5.0" },
		{ _field_real, "particle drag coeff", "0-1" },
		{ _field_real, "maximum particle velocity(disabled)" },
		FIELD_PAD("DNF", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_block, "particle effects", &particle_system_definition_block_new_block },
		FIELD_PAD("ZJSKRR", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_block, "squirters", &fluid_dynamics_squirter_block },
		{ _field_block, "inflow", &fluid_dynamics_inflow_block },
		{ _field_block, "outflow", &fluid_dynamics_outflow_block },
		{ _field_block, "obstacles", &fluid_dynamics_obstacle_block },
		FIELD_EXPLANATION("Cylinder map", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "cylindrical radius", &g_single_scalar_function_evaluation_struct },
		{ _field_terminator }
	};

	#define G_SINGLE_SCALAR_FUNCTION_EVALUATION_STRUCT_ID { 0xE5DD9E47, 0x3ECF4316, 0xA03E0324, 0x62F7B19C }
	TAG_STRUCT(
		g_single_scalar_function_evaluation_struct,
		"g_single_scalar_function_evaluation_struct",
		"s_single_scalar_function_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		G_SINGLE_SCALAR_FUNCTION_EVALUATION_STRUCT_ID)
	{
		{ _field_real, "input" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "scalar", &mapping_function },
		FIELD_PAD("LOHRT", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_terminator }
	};

	STRINGS(fluid_dynamics_flags)
	{
		"use tracers",
		"use density diffuse",
		"wrap particles width",
		"wrap particles height",
		"flat horizontal",
		"flat vertical(default)",
		"cylindrical horizontal",
		"cylindrical vertical",
		"approximate volume",
		"random particle placement",
		"tracer jump around"
	};
	STRING_LIST(fluid_dynamics_flags, fluid_dynamics_flags_strings, _countof(fluid_dynamics_flags_strings));

} // namespace macaque

} // namespace blofeld

