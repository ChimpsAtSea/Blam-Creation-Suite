#include <math/function_definitions.h>

/* ---------- definitions */

TAG_ENUM(
	g_function_output_modifier_enum,
	k_number_of_function_output_modifiers)
{
	{ "none", _function_output_modifier_none },
	{ "plus", _function_output_modifier_plus },
	{ "times", _function_output_modifier_times },
};

TAG_ENUM(
	g_function_variable_type_enum,
	k_number_of_function_variable_types)
{
	{ "particle_age", _function_variable_particle_age },
	{ "emitter_age", _function_variable_emitter_age },
	{ "particle_random", _function_variable_particle_random },
	{ "emitter_random", _function_variable_emitter_random },
	{ "particle_random1", _function_variable_particle_random1 },
	{ "particle_random2", _function_variable_particle_random2 },
	{ "particle_random3", _function_variable_particle_random3 },
	{ "particle_random4", _function_variable_particle_random4 },
	{ "emitter_random1", _function_variable_emitter_random1 },
	{ "emitter_random2", _function_variable_emitter_random2 },
	{ "emitter_time", _function_variable_emitter_time },
	{ "system_lod", _function_variable_system_lod },
	{ "game_time", _function_variable_game_time },
	{ "effect_a_scale", _function_variable_effect_a_scale },
	{ "effect_b_scale", _function_variable_effect_b_scale },
	{ "physics_rotation", _function_variable_physics_rotation },
	{ "location_random", _function_variable_location_random },
	{ "distance_from_emitter", _function_variable_distance_from_emitter },
	{ "particle_simulation_a", _function_variable_particle_simulation_a },
	{ "particle_simulation_b", _function_variable_particle_simulation_b },
	{ "particle_velocity", _function_variable_particle_velocity },
	{ "invalid", _function_variable_invalid },
};

TAG_ENUM(
	function_runtime_m_flags_enum,
	k_number_of_function_runtime_m_flags)
{
	{ "unknown0", _function_runtime_m_unknown0_bit },
	{ "unknown1", _function_runtime_m_unknown1_bit },
	{ "unknown2", _function_runtime_m_unknown2_bit },
	{ "unknown3", _function_runtime_m_unknown3_bit },
	{ "unknown4", _function_runtime_m_unknown4_bit },
	{ "unknown5", _function_runtime_m_unknown5_bit },
	{ "unknown6", _function_runtime_m_unknown6_bit },
	{ "unknown7", _function_runtime_m_unknown7_bit },
};
