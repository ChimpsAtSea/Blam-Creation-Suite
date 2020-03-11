#pragma once

#include <cseries/cseries.h>
#include <math/real_math.h>
#include <memory/static_arrays.h>
#include <tag_files/tag_groups.h>

/* ---------- types */

enum e_function_output_modifier
{
	_function_output_modifier_none,
	_function_output_modifier_plus,
	_function_output_modifier_times,

	k_number_of_function_output_modifiers
};
extern s_enum_definition g_function_output_modifier_enum;

enum e_function_variable_type
{
	_function_variable_particle_age,
	_function_variable_emitter_age,
	_function_variable_particle_random,
	_function_variable_emitter_random,
	_function_variable_particle_random1,
	_function_variable_particle_random2,
	_function_variable_particle_random3,
	_function_variable_particle_random4,
	_function_variable_emitter_random1,
	_function_variable_emitter_random2,
	_function_variable_emitter_time,
	_function_variable_system_lod,
	_function_variable_game_time,
	_function_variable_effect_a_scale,
	_function_variable_effect_b_scale,
	_function_variable_physics_rotation,
	_function_variable_location_random,
	_function_variable_distance_from_emitter,
	_function_variable_particle_simulation_a,
	_function_variable_particle_simulation_b,
	_function_variable_particle_velocity,
	_function_variable_invalid,

	k_number_of_function_variable_types
};
extern s_enum_definition g_function_variable_type_enum;

enum e_function_runtime_m_flags
{
	_function_runtime_m_unknown0_bit,
	_function_runtime_m_unknown1_bit,
	_function_runtime_m_unknown2_bit,
	_function_runtime_m_unknown3_bit,
	_function_runtime_m_unknown4_bit,
	_function_runtime_m_unknown5_bit,
	_function_runtime_m_unknown6_bit,
	_function_runtime_m_unknown7_bit,

	k_number_of_function_runtime_m_flags
};

/* ---------- classes */

class c_function_definition
{
private:
	c_enum<e_function_variable_type, char> m_input_variable;
	c_enum<e_function_variable_type, char> m_range_variable;
	c_enum<e_function_output_modifier, char> m_output_modifier;
	c_enum<e_function_variable_type, char> m_output_modifier_input;
	s_tag_function m_function;
	real m_constant_value;
	c_flags<e_function_runtime_m_flags, byte> m_flags;
	char : 8;
	short : 16;

public:
	double map_to_output_range_legacy(
		float value);

	/* TODO:
	evaluate_color
	evaluate_scalar
	get_function_type
	map_to_color_range_legacy
	map_to_color_range_legacy
	evaluate_legacy
	is_valid
	get_exponent
	set_exponent
	evaluate_color
	get_ranged
	try_and_get_ranged
	is_really_constant
	get_clamp_range_min
	get_clamp_range_max
	get_color_graph_type
	try_and_get_color_graph_type
	get_size_of_compact_function
	get_clamped
	get_exclusion_active
	get_exclusion_max
	get_exclusion_min
	unexclude_value
	unexclude_value
	*/
};
static_assert(sizeof(c_function_definition) == 0x20);
