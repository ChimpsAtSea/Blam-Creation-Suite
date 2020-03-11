#pragma once

#include <cseries/cseries.h>
#include <tag_files/tag_groups.h>
#include <haloreach/devices/devices.h>

/* ---------- constants */

enum
{
	k_machine_group_tag = 'mach'
};

/* ---------- types */

enum e_machine_type
{
	_machine_type_door,
	_machine_type_platform,
	_machine_type_gear,
	k_number_of_machine_types
};

enum e_machine_flags
{
	_machine_pathfinding_obstacle_bit,
	_machine_pathfinding_obstacle_unless_open_bit,
	_machine_elevator_bit,
	_machine_is_portal_blocker_bit,
	_machine_is_not_pathfinding_mobile_bit,
	_machine_uses_default_occlusion_bounds_bit,
	_machine_gears_repeat_motion_instead_of_loop_bit,
	_machine_is_vehicle_bay_bit,
	_machine_always_check_children_collision_bit,
	k_number_of_machine_flags
};

enum e_machine_collision_response
{
	_machine_collision_response_pause_until_crushed,
	_machine_collision_response_reverse_directions,
	_machine_collision_response_discs,
	k_number_of_machine_collision_responses
};

enum e_machine_pathfinding_policy
{
	_machine_pathfinding_policy_discs,
	_machine_pathfinding_policy_sectors,
	_machine_pathfinding_policy_cut_out,
	_machine_pathfinding_policy_none,
	k_number_of_machine_pathfinding_policies
};

struct s_machine_definition : s_device_definition
{
	c_enum<e_machine_type, short> machine_type;
	c_flags<e_machine_flags, word> machine_flags;
	real door_open_time;
	s_real_bounds door_occlusion_bounds;
	c_enum<e_machine_collision_response, short> collision_response;
	short elevator_node;
	c_enum<e_machine_pathfinding_policy, short> pathfinding_policy;
	short : 16;
	string_id shield_name;
	string_id shield_function;
};
static_assert(sizeof(s_machine_definition) == sizeof(s_device_definition) + 0x20);

/* ---------- globals */

extern s_tag_group g_machine_group;
