#pragma once

#include <cseries/cseries.h>
#include <math/real_math.h>
#include <tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_spring_acceleration_group_tag = 'sadt';

constexpr int k_maximum_number_of_spring_linear_accelerations = 3; // x, y, z

/* ---------- types */

struct s_spring_linear_acceleration
{
	real acceleration_range;
	real inverse_acceleration_range;
	real world_acceleration_scale; // 0 defaults to 1, scale the acceleration the object itself applies on this system

	/* ------ damping:
		feed velocity into this function and damp by the value that comes out
	*/

	s_tag_function spring_damping;
	real velocity_domain;
	s_tag_function spring_acceleration;
};

struct s_spring_acceleration_definition
{
	c_typed_tag_block<s_spring_linear_acceleration> linear_accelerations;
	c_tag_block_index<s_spring_linear_acceleration, short> x_axis;
	c_tag_block_index<s_spring_linear_acceleration, short> y_axis;
	c_tag_block_index<s_spring_linear_acceleration, short> z_axis;
	short : 16;
};
static_assert(sizeof(s_spring_acceleration_definition) == 0x14);

/* ---------- globals */

extern s_tag_group g_spring_acceleration_group;
