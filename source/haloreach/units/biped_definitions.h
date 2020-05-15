#pragma once

#include <cseries/cseries.h>
#include <math/real_math.h>
#include <tag_files/tag_groups.h>
#include <haloreach/units/unit_definitions.h>
#include <haloreach/physics/character_physics_definitions.h>

/* ---------- constants */

constexpr tag k_biped_group_tag = 'bipd';

/* ---------- types */

enum e_biped_definition_flags
{
	_biped_definition_turns_without_animating_bit,
	_biped_definition_has_physical_rigid_bodies_when_alive_bit,
	_biped_definition_immune_to_falling_damage_bit,
	_biped_definition_has_animated_jetpack_bit,
	_biped_definition_unused4_bit,
	_biped_definition_unused5_bit,
	_biped_definition_random_speed_increase_bit,
	_biped_definition_unused7_bit,
	_biped_definition_spawn_death_children_on_destroy_bit,
	_biped_definition_stunned_by_emp_damage_bit,
	_biped_definition_dead_physics_when_stunned_bit,
	_biped_definition_always_ragdoll_when_dead_bit,
	_biped_definition_snaps_turns_bit,
	_biped_definition_sync_action_always_projects_on_ground_bit,
	k_number_of_biped_definition_flags
};

struct s_biped_camera_height
{
	string_id weapon_class;
	real standing_height;
	real crouching_height;
};
static_assert(sizeof(s_biped_camera_height) == 0xC);

struct s_biped_movement_gate
{
	real period;
	real z_offset;
	real constant_z_offset;
	real y_offset;
	real speed_threshold;
	s_tag_function default_function;
};
static_assert(sizeof(s_biped_movement_gate) == 0x28);

struct s_contact_point
{
	string_id marker_name;
};
static_assert(sizeof(s_contact_point) == 0x4);

enum e_biped_leap_flags
{
	_biped_leap_force_early_roll_bit,
	k_number_of_biped_leap_flags
};

struct s_biped_leaping_data
{
	c_flags<e_biped_leap_flags, dword> leap_flags;
	real dampening_scale;
	real roll_delay;
	real cannonball_off_axis_scale;
	real cannonball_off_track_scale;
	real_bounds cannonball_roll_bounds;
	real_bounds anticipation_ratio_bounds;
	real_bounds reaction_force_bounds;
	real lobbing_desire;
};
static_assert(sizeof(s_biped_leaping_data) == 0x30);

enum e_biped_ground_fitting_flags
{
	_biped_ground_fitting_foot_fixup_enabled_bit,
	_biped_ground_fitting_root_offset_enabled_bit,
	_biped_ground_fitting_free_foot_enabled_bit,
	_biped_ground_fitting_z_leg_enabled_bit,
	_biped_ground_fitting_foot_pull_pinned_bit,
	_biped_ground_fitting_footlock_adjusts_root_bit,
	_biped_ground_fitting_raycast_vehicles_bit,
	_biped_ground_fitting_foot_fixup_on_composites_bit,
	_biped_ground_fitting_allow_feet_below_grade_bit,
	_biped_ground_fitting_use_biped_up_direction_bit,
	_biped_ground_fitting_snap_marker_above_contact_bit,
	_biped_ground_fitting_allow_ball_roll_on_foot_when_idle_bit,
	k_number_of_biped_ground_fitting_flags
};

struct s_biped_ground_fitting_data
{
	c_flags<e_biped_ground_fitting_flags, dword> ground_fitting_flags;
	real ground_normal_dampening;
	real root_offset_max_scale_idle;
	real root_offset_max_scale_moving;
	real root_offset_dampening;
	real following_cam_scale;
	real root_leaning_scale;
	real stance_width_scale;
	real foot_roll_max;
	real foot_pitch_max;
	real foot_normal_dampening;
	real foot_fitting_test_distance;
	real foot_displacement_upward_dampening;
	real foot_displacement_downward_dampening;
	real foot_pull_threshold_distance_idle;
	real foot_pull_threshold_distance_moving;
	real foot_turn_minimum_radius;
	real foot_turn_maximum_radius;
	real foot_turn_threshold_radius;
	real foot_turn_rate_dampening;
	real foot_turn_weight_dampening;
	real foot_turn_blend_on_time;
	real foot_turn_blend_off_time;
	real push_over_mag;
	real push_back_mag;
	real ledge_ik_success_range;
	real ledge_warning_time;
	real footlock_scale;
	real footlock_min_throttle;
	real footlock_max_throttle;
};
static_assert(sizeof(s_biped_ground_fitting_data) == 0x78);

struct s_biped_definition : s_unit_definition
{
	real moving_turning_speed;
	c_flags<e_biped_definition_flags, dword> flags;
	real stationary_turning_speed;
	s_tag_reference death_program_selector;
	string_id ragdoll_region_name;
	string_id assassination_chud_text;
	
	/* ------ jumping */

	real jump_velocity;
	c_typed_tag_block<s_unit_trick_definition> tricks;
	s_tag_block unknown_biped_block1;
	real maximum_soft_landing_time;
	real maximum_hard_landing_time;
	real minimum_soft_landing_velocity;
	real minimum_hard_landing_velocity;
	real maximum_hard_landing_velocity;
	real stun_duration;

	/* ------ camera, collision, and autoaim */

	real standing_camera_height;
	real running_camera_height;
	real crouching_camera_height;
	real crouch_walking_camera_height;
	real crouch_transition_time;
	s_tag_function camera_height_velocity_function;
	c_typed_tag_block<s_biped_camera_height> camera_heights;
	real camera_interpolation_start;
	real camera_interpolation_end;
	real_vector3d camera_offset;
	real root_offset_camera_scale;
	real root_offset_camera_dampening;
	real autoaim_width;
	short physics_control_node;
	short : 16;
	real runtime_cosine_stationary_turning_threshold;
	real runtime_crouch_transition_velocity;
	real runtime_camera_height_velocity;
	short pelvis_node;
	short head_node;
	s_tag_block unknown_biped_block2;
	s_tag_reference area_damage_effect;
	s_tag_reference health_station_recharge_effect;
	c_typed_tag_block<s_biped_movement_gate> movement_gates;
	c_typed_tag_block<s_biped_movement_gate> movement_gates_crouching;
	real unknown1;
	real unknown2;
	real unknown3;
	real unknown4;
	real unknown5;
	real unknown6;

	/* ------ physics */

	s_character_physics_definition physics;
	c_typed_tag_block<s_contact_point> contact_points;

	s_tag_reference reanimation_character;
	s_tag_reference transformation_muffin;
	s_tag_reference death_spawn_character;
	short death_spawn_count;
	short : 16;

	s_biped_leaping_data leaping_data;
	s_biped_ground_fitting_data ground_fitting_data;
};
static_assert(sizeof(s_biped_definition) == sizeof(s_unit_definition) + 0x2BC);
