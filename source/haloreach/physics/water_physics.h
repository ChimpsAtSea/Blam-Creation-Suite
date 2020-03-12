#pragma once

#include <cseries/cseries.h>
#include <math/real_math.h>
#include <memory/static_arrays.h>
#include <tag_files/tag_groups.h>

/* ---------- constants */

constexpr int k_maximum_number_of_water_physics_hull_surfaces = 64;
constexpr int k_maximum_number_of_water_physics_material_overrides = 512;

/* ---------- types */

enum e_water_density
{
	_water_density_least,
	_water_density_some,
	_water_density_equal,
	_water_density_more,
	_water_density_more_still,
	_water_density_lots_more,
	k_number_of_water_densities
};

enum e_water_physics_hull_surface_flags
{
	_water_physics_hull_surface_works_on_land_bit,
	_water_physics_hull_surface_effects_only_bit,
	k_number_of_water_physics_hull_surface_flags
};

struct s_water_physics_velocity_mapping
{
	s_tag_function function;
	real max_velocity;
};
static_assert(sizeof(s_water_physics_velocity_mapping) == 0x18);

struct s_water_physics_drag_velocity_mapping
{
	s_water_physics_velocity_mapping pressure;
	s_water_physics_velocity_mapping suction;
	real linear_damping;
	real angular_damping;
};
static_assert(sizeof(s_water_physics_drag_velocity_mapping) == 0x38);

struct s_water_physics_material_override
{
	string_id material;
	s_water_physics_drag_velocity_mapping drag;
};
static_assert(sizeof(s_water_physics_material_override) == 0x3C);

struct s_water_physics_hull_surface_definition
{
	c_enum<e_water_physics_hull_surface_flags, word> flags;
	short : 16;
	string_id marker_name;
	real radius;
	c_typed_tag_block<s_water_physics_material_override> material_overrides;
};
static_assert(sizeof(s_water_physics_hull_surface_definition) == 0x18);

/* ---------- globals */

extern s_enum_definition g_water_density_enum;
extern s_tag_block_definition g_water_physics_hull_surface_definition_block;
