#pragma once

#include <haloreach/ai/ai.h>
#include <cseries/cseries.h>
#include <haloreach/game/campaign_metagame.h>
#include <haloreach/game/game_allegiance.h>
#include <math/real_math.h>
#include <haloreach/objects/object_definitions.h>

/* ---------- constants */

enum
{
    k_unit_group_tag = 'unit',
    k_maximum_number_of_unit_screen_effect_references = 4,
    k_maximum_number_of_unit_camera_track_references = 4,
    k_maximum_number_of_unit_camera_acceleration_displacements = 1,
    k_maximum_number_of_unit_camera_gamepad_stick_functions = 1,
    k_maximum_number_of_unit_camera_gamepad_stick_overrides = 1,
    k_maximum_number_of_unit_postures = NONE,
    k_maximum_number_of_unit_hud_references = NONE,
    k_maximum_number_of_unit_dialogue_variants = 16,
    k_maximum_number_of_unit_powered_seats = 2,
    k_maximum_number_of_unit_weapons = 4,
    k_maximum_number_of_unit_target_tracking_types = 16,
    k_maximum_number_of_unit_target_trackings = 1,
    k_maximum_number_of_unit_seats = 64,
    k_maximum_number_of_unit_boarding_seats = k_maximum_number_of_unit_seats,
};

/* ---------- types */

struct s_unit_screen_effect_reference
{
    s_tag_reference type;
};
static_assert(sizeof(s_unit_screen_effect_reference) == 0x10);

struct s_unit_camera_track_reference
{
    s_tag_reference track;
    s_tag_reference screen_effect;
};
static_assert(sizeof(s_unit_camera_track_reference) == 0x20);

struct s_unit_camera_obstruction
{
    real cylinder_fraction;
    real obstruction_test_angle;
    real obstruction_max_inward_accel;
    real obstruction_max_outward_accel;
    real obstruction_max_velocity;
    real obstruction_return_delay;
};
static_assert(sizeof(s_unit_camera_obstruction) == 0x18);

enum e_unit_camera_acceleration_input_variable
{
	_unit_camera_acceleration_input_variable_linear_velocity,
	_unit_camera_acceleration_input_variable_linear_acceleration,
	_unit_camera_acceleration_input_variable_yaw,
	_unit_camera_acceleration_input_variable_pitch,
	_unit_camera_acceleration_input_variable_roll,
	k_number_of_unit_camera_acceleration_input_variables
};

struct s_unit_camera_acceleration_function
{
    c_enum<e_unit_camera_acceleration_input_variable, char> input_variable;
    char : 8;
    short : 16;
    s_tag_function function;
    real maximum_value;
    real camera_scale_axial;
    real camera_scale_perpendicular;
};
static_assert(sizeof(s_unit_camera_acceleration_function) == 0x24);

struct s_unit_camera_acceleration_displacement
{
    real maximum_camera_velocity;
    s_unit_camera_acceleration_function forward_back;
    s_unit_camera_acceleration_function left_right;
    s_unit_camera_acceleration_function up_down;
};
static_assert(sizeof(s_unit_camera_acceleration_displacement) == 0x70);

struct s_unit_camera_gamepad_stick_function
{
    s_tag_function function;
};
static_assert(sizeof(s_unit_camera_gamepad_stick_function) == 0x14);

enum e_unit_camera_gamepad_input_shape
{
	_unit_camera_gamepad_input_shape_none,
	_unit_camera_gamepad_input_shape_unit_circle,
	_unit_camera_gamepad_input_shape_unit_square,
	k_number_of_unit_camera_gamepad_input_shapes
};

struct s_unit_camera_gamepad_stick_info
{
    c_enum<e_unit_camera_gamepad_input_shape, char> input_shape;
    char : 8;
    short : 16;
    real peg_threshold;
    s_real_point2d pegged_time;
    s_real_point2d pegged_scale;
    real peg_max_angular_velocity;
    c_typed_tag_block<s_unit_camera_gamepad_stick_function> input_mapping_function;
};
static_assert(sizeof(s_unit_camera_gamepad_stick_info) == 0x28);

enum e_unit_camera_flags
{
	_unit_camera_pitch_bounds_absolute_space_bit,
	_unit_camera_only_collides_with_environment_bit,
	_unit_camera_hides_player_unit_from_camera_bit,
	_unit_camera_use_aiming_vector_instead_of_marker_forward_bit,
	k_number_of_unit_camera_flags
};

struct s_unit_camera
{
    c_flags<e_unit_camera_flags, word> flags;
    short : 16;
    string_id camera_marker_name;
    real pitch_auto_level;
    s_real_bounds pitch_range;
    c_typed_tag_block<s_unit_camera_track_reference> camera_tracks;
    real pitch_minimum_spring;
    real pitch_maximum_spring;
    real spring_velocity;
    real look_acceleration;
    real look_deceleration;
    real look_acceleration_smoothing_fraction;
    real override_fov;
    s_unit_camera_obstruction camera_obstruction;
    c_typed_tag_block<s_unit_camera_acceleration_displacement> camera_acceleration;
    c_typed_tag_block<s_unit_camera_gamepad_stick_info> move_stick_overrides;
    c_typed_tag_block<s_unit_camera_gamepad_stick_info> look_stick_overrides;
};
static_assert(sizeof(s_unit_camera) == 0x78);

struct s_unit_posture
{
    string_id name;
    s_real_point3d pill_offset;
};
static_assert(sizeof(s_unit_posture) == 0x10);

struct s_unit_hud_interface_reference
{
    s_tag_reference type;
};
static_assert(sizeof(s_unit_hud_interface_reference) == 0x10);

struct s_unit_dialogue_variant
{
    short variant_number;
    short : 16;
    s_tag_reference dialogue;
};
static_assert(sizeof(s_unit_dialogue_variant) == 0x14);

struct s_unit_powered_seat
{
    real driver_powerup_time;
    real driver_powerdown_time;
};
static_assert(sizeof(s_unit_powered_seat) == 0x8);

struct s_unit_weapon_reference
{
    s_tag_reference weapon;
    string_id parent_marker;
};
static_assert(sizeof(s_unit_weapon_reference) == 0x14);

struct s_unit_target_tracking_type
{
    string_id tracking_type;
};
static_assert(sizeof(s_unit_target_tracking_type) == 0x4);

struct s_unit_target_tracking
{
    c_typed_tag_block<s_unit_target_tracking_type> tracking_types;
    real acquire_time;
    real grace_time;
    real decay_time;
    s_tag_reference tracking_sound;
    s_tag_reference locked_sound;
};
static_assert(sizeof(s_unit_target_tracking) == 0x38);

struct s_unit_seat;

struct s_unit_boarding_seat
{
    c_tag_block_index<s_unit_seat, short> seat;
    short : 16;
};
static_assert(sizeof(s_unit_boarding_seat) == 0x4);

enum e_unit_seat_flags
{
	_unit_seat_invisible_bit,
	_unit_seat_locked_bit,
	_unit_seat_driver_bit,
	_unit_seat_gunner_bit,
	_unit_seat_third_person_camera_bit,
	_unit_seat_allows_weapons_bit,
	_unit_seat_third_person_on_enter_bit,
	_unit_seat_first_person_camera_slaved_to_gun_bit,
	_unit_seat_allow_vehicle_communication_animations_bit,
	_unit_seat_not_valid_without_driver_bit,
	_unit_seat_boarding_seat_bit,
	_unit_seat_ai_firing_disabled_by_max_acceleration_bit,
	_unit_seat_boarding_enters_seat_bit,
	_unit_seat_boarding_need_any_passenger_bit,
	_unit_seat_invalid_for_player_bit,
	_unit_seat_invalid_for_non_player_bit,
	_unit_seat_invalid_for_hero_bit,
	_unit_seat_gunner_player_only_bit,
	_unit_seat_invisible_under_major_damage_bit,
	_unit_seat_melee_instant_killable_bit,
	_unit_seat_leader_preference_bit,
	_unit_seat_allows_exit_and_detach_bit,
	_unit_seat_blocks_headshots_bit,
	_unit_seat_exits_to_ground_bit,
	_unit_seat_forward_from_attachment_bit,
	_unit_seat_disallow_ai_shooting_bit,
	_unit_seat_prevents_weapon_stowing_bit,
	_unit_seat_takes_top_level_aoe_damage_bit,
	_unit_seat_disallow_exit_bit,
	_unit_seat_local_aiming_bit,
	_unit_seat_pelvis_relative_attachment_bit,
	_unit_seat_apply_velocity_on_death_exit_bit,
	k_number_of_unit_seat_flags
};

enum e_unit_ai_seat_type
{
	_unit_ai_seat_type_none,
	_unit_ai_seat_type_passenger,
	_unit_ai_seat_type_gunner,
	_unit_ai_seat_type_small_cargo,
	_unit_ai_seat_type_large_cargo,
	_unit_ai_seat_type_driver,
	k_number_of_unit_ai_seat_types
};

struct s_unit_seat
{
    c_flags<e_unit_seat_flags, long> flags;
    string_id label;
    string_id marker_name;
    string_id entry_marker_name;
    string_id boarding_grenade_marker;
    string_id boarding_grenade_string;
    string_id boarding_melee_string;
    string_id in_seat_string;
    real ping_scale;
    real turnover_time;
    s_tag_reference seat_acceleration;
    real ai_scariness;
    c_enum<e_unit_ai_seat_type, short> ai_seat_type;
    c_tag_block_index<s_unit_seat, short> boarding_seat;
    c_typed_tag_block<s_unit_boarding_seat> additional_boarding_seats;
    real listener_interpolation_factor;
    s_real_bounds yaw_rate_bounds;
    s_real_bounds pitch_rate_bounds;
    real pitch_interpolation_time;
    real min_speed_reference;
    real max_speed_reference;
    real speed_exponent;
    s_unit_camera unit_camera;
    c_typed_tag_block<s_unit_hud_interface_reference> hud_interface_references;
    string_id enter_seat_string;
    s_real_bounds yaw_range;
    s_tag_reference built_in_gunner;
    real entry_radius;
    real entry_marker_cone_angle;
    real entry_marker_facing_angle;
    real maximum_relative_velocity;
    real open_time;
    real close_time;
    string_id open_function_name;
    string_id opening_function_name;
    string_id closing_function_name;
    string_id invisible_seat_region;
    long runtime_invisible_seat_region_index;
};
static_assert(sizeof(s_unit_seat) == 0x13C);

enum e_unit_boost_flags
{
	_unit_boost_pegs_throttle_bit,
	k_number_of_unit_boost_flags
};

struct s_unit_boost
{
    s_tag_reference collision_damage;
    c_flags<e_unit_boost_flags, long> flags;
    real boost_peak_power;
    real boost_rise_time;
    real boost_fall_time;
    real boost_power_per_second;
    real boost_low_warning_threshold;
    real recharge_rate;
    s_tag_data trigger_to_boost;
};
static_assert(sizeof(s_unit_boost) == 0x40);

struct s_unit_lipsync
{
    real attack_weight;
    real decay_weight;
};
static_assert(sizeof(s_unit_lipsync) == 0x8);

enum e_unit_trick_activation_type
{
	_unit_trick_activation_brake_left,
	_unit_trick_activation_brake_right,
	_unit_trick_activation_brake_up,
	_unit_trick_activation_brake_down,
	_unit_trick_activation_throw_movement_left,
	_unit_trick_activation_throw_movement_right,
	_unit_trick_activation_throw_movement_up,
	_unit_trick_activation_throw_movement_down,
	_unit_trick_activation_throw_look_left,
	_unit_trick_activation_throw_look_right,
	_unit_trick_activation_throw_look_up,
	_unit_trick_activation_throw_look_down,
	_unit_trick_activation_peg_flick_jump_left,
	_unit_trick_activation_peg_flick_jump_right,
	_unit_trick_activation_peg_flick_jump_up,
	_unit_trick_activation_peg_flick_jump_down,
	_unit_trick_activation_double_jump_left,
	_unit_trick_activation_double_jump_right,
	_unit_trick_activation_double_jump_up,
	_unit_trick_activation_double_jump_down,
	k_number_of_unit_trick_activation_types
};

enum e_unit_trick_velocity_preservation_mode
{
	_unit_trick_velocity_preservation_mode_none,
	_unit_trick_velocity_preservation_mode_trick_relative,
	_unit_trick_velocity_preservation_mode_word_relative,
	k_number_of_unit_trick_velocity_preservation_modes
};

enum e_unit_trick_flags
{
	_unit_trick_use_following_camera_bit,
	_unit_trick_do_not_slam_player_control_bit,
	k_number_of_unit_trick_flags
};

struct s_unit_trick_definition
{
	string_id animation_name;
	c_enum<e_unit_trick_activation_type, char> activation_type;
	c_enum<e_unit_trick_velocity_preservation_mode, char> velocity_preservation;
	c_flags<e_unit_trick_flags, byte> flags;
	char : 8;
	real camera_interpolation_time;
	real trick_exit_time;
	s_real_bounds trick_exit_camera_interpolation_time;
	real trick_exit_displacement_reference;
	real cooldown_time;
};
static_assert(sizeof(s_unit_trick_definition) == 0x20);

enum e_unit_definition_flags
{
	_unit_definition_circular_aiming_bit,
	_unit_definition_destroyed_after_dying_bit,
	_unit_definition_half_speed_interpolation_bit,
	_unit_definition_fires_from_camera_bit,
	_unit_definition_entrance_inside_bounding_sphere_bit,
	_unit_definition_doesnt_show_readied_weapon_bit,
	_unit_definition_causes_passenger_dialogue_bit,
	_unit_definition_resists_pings_bit,
	_unit_definition_melee_attack_is_fatal_bit,
	_unit_definition_dont_reface_during_pings_bit,
	_unit_definition_has_no_aiming_bit,
	_unit_definition_simple_creature_bit,
	_unit_definition_impact_melee_attaches_to_unit_bit,
	_unit_definition_impact_melee_dies_on_shield_bit,
	_unit_definition_cannot_open_doors_automatically_bit,
	_unit_definition_melee_attackers_cannot_attach_bit,
	_unit_definition_not_instantly_killed_by_melee_bit,
	_unit_definition_shield_sapping_bit,
	_unit_definition_runs_around_flaming_bit,
	_unit_definition_inconsequential_bit,
	_unit_definition_special_cinematic_unit_bit,
	_unit_definition_ignored_by_autoaiming_bit,
	_unit_definition_shields_fry_infection_forms_bit,
	_unit_definition_can_dual_wield_bit,
	_unit_definition_acts_as_gunner_for_parent_bit,
	_unit_definition_controlled_by_parent_gunner_bit,
	_unit_definition_parents_primary_weapon_bit,
	_unit_definition_parents_secondary_weapon_bit,
	_unit_definition_unit_has_boost_bit,
	k_number_of_unit_definition_flags
};

enum e_unit_motion_sensor_blip_size
{
	_unit_motion_sensor_blip_size_medium,
	_unit_motion_sensor_blip_size_small,
	_unit_motion_sensor_blip_size_large,
	k_number_of_unit_motion_sensor_blip_sizes
};

enum e_unit_item_owner_size
{
	_unit_item_owner_size_small,
	_unit_item_owner_size_medium,
	_unit_item_owner_size_large,
	_unit_item_owner_size_huge,
	k_number_of_unit_item_owner_sizes
};

enum e_unit_grenade_type
{
	_unit_grenade_type_human_fragmentation,
	_unit_grenade_type_covenant_plasma,
	k_number_of_unit_grenade_types
};

struct s_unit_definition : s_object_definition
{
    c_flags<e_unit_definition_flags, long> unit_flags;
    c_enum<e_campaign_team, short> default_team;
    c_enum<e_ai_sound_volume, short> constant_sound_volume;
    s_tag_reference hologram_unit;
    c_typed_tag_block<s_campaign_metagame_bucket> campaign_metagame_bucket;
    c_typed_tag_block<s_unit_screen_effect_reference> screen_effects;
    real camera_stiffness;
    s_unit_camera unit_camera;
    s_unit_camera sync_action_camera;
    s_tag_reference assassination_start_damage_response;
    s_tag_reference assassination_object;
    string_id assassination_object_stow_marker;
    string_id assassination_object_out_marker;
    string_id assassination_object_anchor_marker;
    s_tag_reference seat_acceleration;
    real soft_ping_threshold;
    real soft_ping_interrupt_time;
    real hard_ping_threshold;
    real hard_ping_interrupt_time;
    real hard_death_threshold;
    real feign_death_threshold;
    real feign_death_time;
    real distance_of_evade_animation;
    real pain_screen_duration;
    real pain_screen_region_fade_out_duration;
    real pain_screen_region_fade_out_weight_threshold;
    real pain_screen_angle_tolerance;
    real pain_screen_angle_randomness;
    real defensive_screen_duration;
    real defensive_screen_scrub_fallback_fraction;
    real distance_of_dive_animation;
    real terminal_velocity_fall_ratio;
    real stun_movement_penalty;
    real stun_turning_penalty;
    real stun_jumping_penalty;
    real minimum_stun_time;
    real maximum_stun_time;
    real feign_death_chance;
    real feign_repeat_chance;
    s_tag_reference spawned_turret_character;
    short spawned_actor_count_min;
    short spawned_actor_count_max;
    real spawned_velocity;
    string_id aiming_pivot_marker;
    real aiming_velocity_maximum;
    real aiming_acceleration_maximum;
    real casual_aiming_modifier;
    real looking_velocity_maximum;
    real looking_acceleration_maximum;
    real object_velocity_maximum;
    string_id right_hand_node;
    string_id left_hand_node;
    string_id preferred_gun_node;
    string_id preferred_grenade_node;
    string_id other_node;
    s_tag_reference melee_damage;
    s_tag_reference native_melee_override;
    s_tag_reference boarding_melee_damage;
    s_tag_reference boarding_melee_response;
    s_tag_reference eviction_melee_damage;
    s_tag_reference eviction_melee_response;
    s_tag_reference landing_melee_damage;
    s_tag_reference flurry_melee_damage;
    s_tag_reference obstacle_smash_damage;
    s_tag_reference assassination_damage;
    c_enum<e_unit_motion_sensor_blip_size, short> motion_sensor_blip_size;
    c_enum<e_unit_item_owner_size, short> item_owner_size;
    string_id equipment_variant_name;
    string_id grounded_equipment_variant_name;
    c_typed_tag_block<s_unit_posture> postures;
    c_typed_tag_block<s_unit_hud_interface_reference> hud_interfaces;
    c_typed_tag_block<s_unit_dialogue_variant> dialogue_variants;
    real grenade_angle;
    real grenade_angle_max_elevation;
    real grenade_angle_min_elevation;
    real grenade_velocity;
    c_enum<e_unit_grenade_type, short> grenade_type;
    short grenade_count;
    c_typed_tag_block<s_unit_powered_seat> powered_seats;
    c_typed_tag_block<s_unit_weapon_reference> weapons;
    c_typed_tag_block<s_unit_target_tracking> target_tracking;
    c_typed_tag_block<s_unit_seat> seats;
    real opening_time;
    real closing_time;
    real emp_disabled_time;
    s_tag_reference emp_disabled_effect;
    s_unit_boost boost;
    s_unit_lipsync lipsync;
    s_tag_reference exit_and_detach_damage;
    s_tag_reference exit_and_detach_weapon;
};
static_assert(sizeof(s_unit_definition) == sizeof(s_object_definition) + 0x3A0);

/* ---------- globals */

extern s_tag_block_definition g_unit_seat_block;
extern s_tag_block_definition g_unit_trick_block;
extern s_tag_group g_unit_group;
