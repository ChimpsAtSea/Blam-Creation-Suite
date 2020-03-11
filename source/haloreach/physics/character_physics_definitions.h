#pragma once

#include <cseries/cseries.h>
#include <math/real_math.h>
#include <memory/static_arrays.h>
#include <tag_files/string_ids.h>
#include <tag_files/tag_groups.h>

/* ---------- types */

enum e_character_physics_flags
{
	_character_physics_centered_at_origin_bit,
	_character_physics_shape_spherical_bit,
	_character_physics_use_player_physics_bit,
	_character_physics_climb_any_surface_bit,
	_character_physics_flying_bit,
	_character_physics_not_physical_bit,
	_character_physics_dead_character_collision_group_bit,
	_character_physics_suppress_ground_planes_on_bipeds_bit,
	_character_physics_physical_ragdoll_bit,
	_character_physics_do_not_resize_dead_spheres_bit,
	k_number_of_character_physics_flags
};

struct s_character_ground_physics_definition
{
	real maximum_slope_angle;
	real downhill_falloff_angle;
	real downhill_cutoff_angle;
	real uphill_falloff_angle;
	real uphill_cutoff_angle;
	real downhill_velocity_scale;
	real uphill_velocity_scale;
	real runtime_minimum_normal_k;
	real runtime_downhill_k0;
	real runtime_downhill_k1;
	real runtime_uphill_k0;
	real runtime_uphill_k1;
	real climb_inflection_angle;
	real scale_airborne_reaction_time;
	real scale_ground_adhesion_velocity;
	real gravity_scale;
	real airborne_acceleration_scale;
};
static_assert(sizeof(s_character_ground_physics_definition) == 0x44);

enum e_character_flying_physics_flags
{
	_character_flying_physics_use_world_up_bit,
	k_number_of_character_flying_physics_flags
};

struct s_character_flying_physics_definition
{
	real bank_angle;
	real bank_apply_time;
	real bank_decay_time;
	real pitch_ratio;
	real maximum_velocity;
	real maximum_sidestep_velocity;
	real acceleration;
	real deceleration;
	real angular_velocity_maximum;
	real angular_acceleration_maximum;
	real crouch_velocity_modifier;
	c_flags<e_character_flying_physics_flags, dword> flags;
};
static_assert(sizeof(s_character_flying_physics_definition) == 0x30);

struct s_character_physics_definition
{
	c_flags<e_character_physics_flags, dword> flags;
	real height_standing;
	real height_crouching;
	real radius;
	real mass;
	string_id living_material_name;
	string_id dead_material_name;
	short runtime_global_material_type; // <--- TODO: block index
	short runtime_dead_global_material_type; // <--- TODO: block index
	s_tag_block dead_sphere_shapes;
	s_tag_block pill_shapes;
	s_tag_block sphere_shapes;
	s_character_ground_physics_definition ground_physics;
	s_character_flying_physics_definition flying_physics;
};
static_assert(sizeof(s_character_physics_definition) == 0xB8);

/* ---------- globals */

extern s_struct_definition g_character_physics_definition_struct;
