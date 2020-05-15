#pragma once

#include <cseries/cseries.h>
#include <memory/static_arrays.h>
#include <tag_files/tag_groups.h>
#include <haloreach/objects/damage_new.h>
#include <haloreach/objects/object_definitions.h>
#include <haloreach/objects/object_types.h>
#include <haloreach/ai/ai.h>

/* ---------- constants */

constexpr tag k_projectile_group_tag = 'proj';

constexpr int k_maximum_number_of_projectile_material_responses = 200;
constexpr int k_maximum_number_of_projectile_brute_grenades = 1;
constexpr int k_maximum_number_of_projectile_fire_bomb_grenades = 1;
constexpr int k_maximum_number_of_projectile_conical_spreads = 1;

/* ---------- enumerators */

enum e_projectile_flags
{
	_projectile_oriented_along_velocity_bit,
	_projectile_ai_must_use_ballistic_aiming_bit,
	_projectile_detonation_max_time_if_attached_bit,
	_projectile_damage_scales_based_on_distance_bit,
	_projectile_steering_adjusts_orientation_bit,
	_projectile_dont_noise_up_steering_bit,
	_projectile_can_track_behind_itself_bit,
	_projectile_robotron_steering_bit,
	_projectile_affected_by_phantom_volumes_bit,
	_projectile_notifies_target_units_bit,
	_projectile_use_ground_detonation_when_attached_bit,
	_projectile_ai_minor_tracking_threat_bit,
	_projectile_dangerous_when_inactive_bit,
	_projectile_ai_stimulus_when_attached_bit,
	_projectile_over_pene_detonation_bit,
	_projectile_no_impact_effects_on_bounce_bit,
	_projectile_rc1_overpenetration_fixes_bit,
	_projectile_disable_instantaneous_first_tick_bit,
	_projectile_constrain_gravity_to_velocity_bounds_bit,
	_projectile_allow_deceleration_below_final_velocity_bit,
	_projectile_supports_tethering_bit,
	_projectile_damage_not_predictable_by_clients_bit,
	_projectile_collides_with_physics_only_surfaces_bit,
	_projectile_detonates_when_attached_to_objects_bit,
	_projectile_cannot_be_detached_by_equipment_bit,
	_projectile_does_not_collide_with_world_geometry_bit,
	_projectile_is_collectible_bit,
	_projectile_different_bursts_will_not_trigger_super_combine_detonation_bit,
	_projectile_distance_based_damage_scaling_uses_damage_range_low_bounds_bit,
	_projectile_skip_object_first_tick_bit,
	_projectile_use_projectile_camera_in_killcam_bit,
	_projectile_detonates_on_attachment_to_equipped_weapon_bit,
	k_number_of_projectile_flags
};

enum e_projectile_detonation_timer_start
{
	_projectile_detonation_timer_start_immediately,
	_projectile_detonation_timer_start_after_first_bounce,
	_projectile_detonation_timer_start_when_at_rest,
	_projectile_detonation_timer_start_after_first_bounce_off_any_surface,
	k_number_of_projectile_detonation_timer_starts
};

enum e_projectile_material_response_type
{
	_projectile_material_response_type_impact_detonate,
	_projectile_material_response_type_fizzle,
	_projectile_material_response_type_overpenetrate,
	_projectile_material_response_type_attach,
	_projectile_material_response_type_bounce,
	_projectile_material_response_type_bounce_dud,
	_projectile_material_response_type_fizzle_ricochet,
	_projectile_material_response_type_turn_physical,
	_projectile_material_response_type_airstrike,
	k_number_of_projectile_material_response_types
};

enum e_projectile_material_response_flags
{
	_projectile_material_response_only_against_units_bit,
	_projectile_material_response_never_against_units_bit,
	_projectile_material_response_only_against_bipeds_bit,
	_projectile_material_response_only_against_vehicles_bit,
	_projectile_material_response_never_against_wuss_players_bit,
	_projectile_material_response_only_when_tethered_bit,
	_projectile_material_response_only_when_not_tethered_bit,
	_projectile_material_response_only_against_dead_bipeds_bit,
	_projectile_material_response_never_against_dead_bipeds_bit,
	_projectile_material_response_only_ai_projectiles_bit,
	_projectile_material_response_never_ai_projectiles_bit,
	k_number_of_projectile_material_response_flags
};

enum e_projectile_material_response_effect_scale
{
	_projectile_material_response_effect_scale_damage,
	_projectile_material_response_effect_scale_angle,
	k_number_of_projectile_material_response_effect_scales
};

/* ---------- structures */

struct s_projectile_material_response_old
{
	c_enum<e_projectile_material_response_type, short> default_response;
	short : 16;
	string_id material_name;
	short runtime_material_index;
	short : 16;
	c_enum<e_projectile_material_response_type, short> potential_response;
	c_flags<e_projectile_material_response_flags, word> response_flags;
	real chance_fraction;
	real_bounds between;
	real_bounds and_;
	c_enum<e_projectile_material_response_effect_scale, short> scale_effects_by;
	short : 16;
	real angular_noise;
	real velocity_noise;
	real initial_friction;
	real parallel_friction;
	real perpendicular_friction;
};
static_assert(sizeof(s_projectile_material_response_old) == 0x3C);

struct s_projectile_material_response
{
	string_id material_name;
	short runtime_material_index;
	c_flags<e_projectile_material_response_flags, word> response_flags;
	real chance_fraction;
	real_bounds between;
	real_bounds and_;
	c_enum<e_projectile_material_response_type, short> response;
	c_enum<e_projectile_material_response_effect_scale, short> scale_effects_by;
	real angular_noise;
	real velocity_noise;
	real initial_friction;
	real parallel_friction;
	real perpendicular_friction;
};
static_assert(sizeof(s_projectile_material_response) == 0x34);

struct s_projectile_brute_grenade
{
	real minimum_angular_velocity;
	real maximum_angular_velocity;
	real spin_angular_velocity;
	real angular_damping;
	real drag_angle_k;
	real drag_speed_k;
	real drag_exponent;
	real attach_sample_radius;
	real attach_acc_k;
	real attach_acc_s;
	real attach_acc_e;
	real attach_acc_damping;
};
static_assert(sizeof(s_projectile_brute_grenade) == 0x30);

struct s_projectile_fire_bomb_grenade
{
	real projection_offset;
};
static_assert(sizeof(s_projectile_fire_bomb_grenade) == 0x4);

struct s_projectile_conical_spread
{
	short yaw_count;
	short pitch_count;
	real distribution_exponent;
	real spread;
};
static_assert(sizeof(s_projectile_conical_spread) == 0xC);

struct s_projectile_definition : s_object_definition
{
	c_flags<e_projectile_flags, long> projectile_flags;
	c_enum<e_projectile_detonation_timer_start, short> detonation_timer_starts;
	c_enum<e_ai_sound_volume, short> impact_noise;
	real collision_radius;
	real arming_time;
	real danger_radius;
	real danger_stimuli_radius;
	short danger_group_burst_count;
	short danger_group_burst_max_count;
	real_bounds timer;
	real minimum_velocity;
	real maximum_range;
	real bounce_maximum_range;
	real max_latch_time_to_detonate;
	real max_latch_time_to_arm;
	c_enum<e_ai_sound_volume, short> detonation_noise;
	short super_detonation_projectile_count;
	real tether_release_safety_delay;
	s_tag_reference detonation_started;
	s_tag_reference detonation_effect_airborne;
	s_tag_reference detonation_effect_ground;
	s_tag_reference detonation_damage;
	s_tag_reference attached_detonation_damage;
	s_tag_reference super_detonation;
	s_tag_reference super_detonation_damage;
	s_tag_reference detonation_sound;
	c_enum<e_damage_reporting_type, char> damage_reporting_type;
	char : 8;
	c_flags<e_object_type, word> super_detonation_object_types;
	s_tag_reference super_attached_detonation_damage;
	real material_effect_radius;
	s_tag_reference flyby_sound;
	s_tag_reference flyby_response;
	real flyby_effects_range;
	s_tag_reference impact_effect;
	s_tag_reference object_impact_effect;
	s_tag_reference impact_damage;
	real boarding_detonation_time;
	s_tag_reference boarding_detonation_damage;
	s_tag_reference boarding_attached_detonation_damage;
	real air_gravity_scale;
	real_bounds air_damage_range;
	real water_gravity_scale;
	real_bounds water_damage_range;
	real initial_velocity;
	real final_velocity;
	real indirect_fire_velocity;
	real ai_velocity_scale_normal;
	real ai_velocity_scale_heroic;
	real ai_velocity_scale_legendary;
	real ai_guided_angular_velocity_scale_normal;
	real ai_guided_angular_velocity_scale_legendary;
	real guided_angular_velocity_lower;
	real guided_angular_velocity_upper;
	real guided_angular_velocity_at_rest;
	real_bounds acceleration_range;
	real runtime_acceleration_bound_inverse;
	real ai_target_leading_scale;
	real targeted_leading_fraction;
	real guided_error_radius;
	c_typed_tag_block<s_projectile_material_response_old> material_responses_old;
	c_typed_tag_block<s_projectile_material_response> material_responses;
	c_typed_tag_block<s_projectile_brute_grenade> brute_grenade;
	c_typed_tag_block<s_projectile_fire_bomb_grenade> fire_bomb_grenade;
	c_typed_tag_block<s_projectile_conical_spread> conical_spread;
	s_tag_reference grounded_friction_settings;
};
static_assert(sizeof(s_projectile_definition) == sizeof(s_object_definition) + 0x1F8);
