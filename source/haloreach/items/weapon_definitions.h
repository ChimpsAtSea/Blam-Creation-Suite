#pragma once

#include <cseries/cseries.h>
#include <math/integer_math.h>
#include <math/real_math.h>
#include <haloreach/objects/damage_new.h>
#include <haloreach/items/item_definitions.h>
#include <haloreach/ai/ai.h>

/* ---------- constants */

constexpr tag k_weapon_group_tag = 'weap';

constexpr int k_maximum_number_of_weapon_melee_damage_parameters = 2;
constexpr int k_maximum_number_of_weapon_tracking_types = 16;
constexpr int k_maximum_number_of_weapon_target_tracking_parameters = 1;
constexpr int k_maximum_number_of_weapon_first_person_interfaces = 2;
constexpr int k_maximum_number_of_weapon_predicted_resources = NONE;
constexpr int k_maximum_number_of_weapon_magazine_objects = 8;
constexpr int k_maximum_number_of_weapon_magazines = 2;
constexpr int k_maximum_number_of_weapon_trigger_charging_fire_fractions = 16;
constexpr int k_maximum_number_of_weapon_triggers = 2;
constexpr int k_maximum_number_of_weapon_barrel_first_person_offsets = 3;
constexpr int k_maximum_number_of_weapon_barrel_firing_effects = 5;
constexpr int k_maximum_number_of_weapon_barrels = 2;
constexpr int k_maximum_number_of_weapon_screen_effects = 4;

/* ---------- types */

enum e_weapon_definition_flags
{
	_weapon_vertical_heat_display_bit,
	_weapon_mutually_exclusive_triggers_bit,
	_weapon_attacks_automatically_on_bump_bit,
	_weapon_must_be_readied_bit,
	_weapon_doesn_t_count_towards_maximum_bit,
	_weapon_aim_assists_only_when_zoomed_bit,
	_weapon_prevents_grenade_throwing_bit,
	_weapon_must_be_picked_up_bit,
	_weapon_holds_triggers_when_dropped_bit,
	_weapon_prevents_melee_attack_bit,
	_weapon_detonates_when_dropped_bit,
	_weapon_cannot_fire_at_maximum_age_bit,
	_weapon_secondary_trigger_overrides_grenades_bit,
	_weapon_does_not_depower_active_camo_in_multiplayer_bit,
	_weapon_enables_integrated_night_vision_bit,
	_weapon_ai_uses_weapon_melee_damage_bit,
	_weapon_forces_no_binoculars_bit,
	_weapon_loop_fp_firing_animation_bit,
	_weapon_prevents_sprinting_bit,
	_weapon_cannot_fire_while_boosting_bit,
	_weapon_prevents_driving_bit,
	_weapon_third_person_camera_bit,
	_weapon_can_be_dual_wielded_bit,
	_weapon_can_only_be_dual_wielded_bit,
	_weapon_melee_only_bit,
	_weapon_cannot_fire_if_parent_dead_bit,
	_weapon_weapon_ages_with_each_kill_bit,
	_weapon_weapon_uses_old_dual_fire_error_code_bit,
	_weapon_primary_trigger_melee_attacks_bit,
	_weapon_cannot_be_used_by_player_bit,
	_weapon_strict_deviation_angle_bit,
	_weapon_notifies_target_units_bit,
	k_number_of_weapon_definition_flags
};

enum e_weapon_definition_secondary_flags
{
	_weapon_magnetizes_only_when_zoomed_bit,
	_weapon_force_enable_equipment_tossing_bit,
	_weapon_non_lunge_melee_dash_disabled_bit,
	_weapon_do_not_drop_on_dual_wield_melee_bit,
	_weapon_is_equipment_special_weapon_bit,
	_weapon_uses_ghost_reticle_bit,
	_weapon_never_overheats_bit,
	_weapon_force_tracers_to_come_from_weapon_barrel_bit,
	_weapon_cannot_fire_during_emp_bit,
	_weapon_weapon_can_headshot_bit,
	_weapon_ai_cannot_fire_tracking_projectiles_bit,
	_weapon_force_match_owner_animation_bit,
	_weapon_weapon_unzooms_on_damage_bit,
	_weapon_do_not_drop_on_equipment_activation_bit,
	_weapon_weapon_can_not_be_dropped_bit,
	_weapon_disable_function_overlays_during_reload_bit,
	_weapon_throw_weapon_on_primary_fire_bit,
	_weapon_do_not_drop_must_be_readied_on_primary_trigger_bit,
	_weapon_delete_on_drop_bit,
	_weapon_allow_melee_when_using_device_bit,
	_weapon_do_not_lower_weapon_when_using_device_bit,
	_weapon_cannot_fire_while_zooming_bit,
	_weapon_weapon_ages_when_damage_is_inflicted_bit,
	_weapon_apply_gunner_armor_mod_abilites_bit,
	_weapon_wielders_sprint_is_unaffected_by_soft_ping_bit,
	_weapon_weapon_drops_further_away_bit,
	_weapon_use_automatic_firing_looping_sounds_bit,
	_weapon_do_not_drop_on_assassination_bit,
	_weapon_is_part_of_body_bit,
	_weapon_suppresses_sprint_bit,
	_weapon_hide_pickup_prompt_unless_special_pickup_priority_bit,
	_weapon_weapon_ignores_player_pickup_allowed_trait_bit,
	k_number_of_weapon_definition_secondary_flags
};

enum e_weapon_secondary_trigger_mode
{
	_weapon_secondary_trigger_mode_normal,
	_weapon_secondary_trigger_slaved_to_primary,
	_weapon_secondary_trigger_inhibits_primary,
	_weapon_secondary_trigger_loads_alternate_ammunition,
	_weapon_secondary_trigger_loads_multiple_primary_ammunition,
	k_number_of_weapon_secondary_trigger_modes
};

struct s_melee_damage_parameters
{
	s_real_euler_angles2d damage_pyramid_angles; // defines the frustum from the camera that the melee-attack uses to find targets
	real damage_pyramid_depth; // how far the melee attack searches for a target
	real maximum_lunge_range; // 0 defaults to k_default_player_melee_lunge_distance
	real damage_lunge_explosive_depth; // the distance out from the pyramid center to spawn explosive effects. This value will be clamped to the damage pyramid depth. 0 defaults to the damage pyramid depth
	real runtime_damage_lunge_explosive_fraction;
	s_tag_reference melee_damage;
	s_tag_reference melee_response;
	s_tag_reference lunge_melee_damage; // this is only important for the energy sword
	s_tag_reference lunge_melee_response; // this is only important for the energy sword
	s_tag_reference empty_melee_damage; // this is only important for the energy sword
	s_tag_reference empty_melee_response; // this is only important for the energy sword
	s_tag_reference clang_melee_damage; // this is only important for the energy sword
	s_tag_reference clang_melee_response; // this is only important for the energy sword
	s_tag_reference clang_melee_against_melee_damage; // e.g. used by AR to damage sword guy when clanging sword attack
	s_tag_reference clang_melee_against_melee_response; // e.g. used by AR to damage sword guy when clanging sword attack
	s_tag_reference lunge_melee_explosive_damage;
};
static_assert(sizeof(s_melee_damage_parameters) == 0xC8);

struct s_aim_assist_parameters
{
	real autoaim_angle; // the maximum angle that autoaim works at full strength
	real autoaim_range; // autoaim only has an effect along this distance
	real autoaim_falloff_range; // at what point the autoaim starts falling off. Fully falls off at autoaim range
	real autoaim_near_falloff_range; // at what point the autoaim reaches full power
	real magnetism_angle; // the maximum angle that magnetism works at full strength
	real magnetism_range; // magnetism only has an effect along this distance
	real magnetism_falloff_range; // at what point magnetism starts falling off. Fully falls off at magnetism range
	real magnetism_near_falloff_range; // at what point magnetism reaches full power
	real deviation_angle; // the maximum angle that a projectile is allowed to deviate from the gun barrel due to autoaim OR network lead vector reconstruction
	real unknown1;
	real unknown2;
	real unknown3;
	real unknown4;
	real unknown5;
	real unknown6;
};
static_assert(sizeof(s_aim_assist_parameters) == 0x3C);

struct s_tracking_type
{
	string_id tracking_type;
};
static_assert(sizeof(s_tracking_type) == 0x4);

struct s_target_tracking_parameters
{
	c_typed_tag_block<s_tracking_type> tracking_types; // specify the kinds of targets this tracking system can lock on
	real acquire_time;
	real grace_time;
	real decay_time;
	s_tag_reference tracking_sound;
	s_tag_reference locked_sound;
};
static_assert(sizeof(s_target_tracking_parameters) == 0x38);

enum e_weapon_movement_penalty
{
	_weapon_movement_penalized_always,
	_weapon_movement_penalized_when_zoomed,
	_weapon_movement_penalized_when_zoomed_or_reloading,
	k_number_of_weapon_movement_penalties
};

enum e_weapon_type
{
	_weapon_type_undefined,
	_weapon_type_shotgun,
	_weapon_type_needler,
	_weapon_type_plasma_pistol,
	_weapon_type_plasma_rifle,
	_weapon_type_rocket_launcher,
	_weapon_type_energy_blade,
	_weapon_type_splaser,
	_weapon_type_shield,
	_weapon_type_scarab_gun,
	_weapon_type_wolverine_quad,
	_weapon_type_flak_cannon,
	_weapon_type_plasma_launcher,
	k_number_of_weapon_types
};

struct s_weapon_first_person_interface
{
	s_tag_reference first_person_model;
	s_tag_reference first_person_animation;
};
static_assert(sizeof(s_weapon_first_person_interface) == 0x20);

struct s_weapon_predicted_resources
{
	short type; // <--- TODO: enum
	short resource_index;
	long definition_index;
};
static_assert(sizeof(s_weapon_predicted_resources) == 0x8);

enum e_weapon_magazine_flags
{
	_weapon_magazine_wastes_rounds_when_reloaded_bit,
	_weapon_magazine_every_round_must_be_chambered_bit,
	_weapon_magazine_magazine_cannot_change_state_while_firing_bit, // will prevent reload until fire is complete (sticky det)
	_weapon_magazine_allow_overheated_reload_when_empty_bit,
	_weapon_magazine_bottomless_inventory_bit,
	k_number_of_weapon_magazine_flags
};

enum e_weapon_magazine_ammo_refill_type
{
	_weapon_magazine_ammo_refill_none,
	_weapon_magazine_ammo_refill_unsc,
	_weapon_magazine_ammo_refill_covenant,
	_weapon_magazine_ammo_refill_forerunner,
	k_number_of_weapon_magazine_refill_types
};

struct s_weapon_magazine_object
{
	short rounds;
	short : 16;
	s_tag_reference equipment;
};
static_assert(sizeof(s_weapon_magazine_object) == 0x14);

struct s_weapon_magazine_definition
{
	c_flags<e_weapon_magazine_flags, dword> flags;
	short rounds_recharged; // per second
	short rounds_total_initial;
	short rounds_total_maximum;
	short rounds_loaded_maximum;
	short runtime_rounds_inventory_maximum;
	c_enum<e_weapon_magazine_ammo_refill_type, short> ammo_refill_type;
	real reload_dialogue_time; // the length of time we wait before saying the reload dialogue
	short rounds_reloaded;
	short : 16;
	real chamber_time; // the length of time it takes to chamber the next round
	real unknown1;
	real unknown2;
	real unknown3;
	real unknown4;
	real unknown5;
	real unknown6;
	s_tag_reference reloading_effect;
	s_tag_reference reloading_damage_effect;
	s_tag_reference chambering_effect;
	s_tag_reference chambering_damage_effect;
	c_typed_tag_block<s_weapon_magazine_object> magazines;
};
static_assert(sizeof(s_weapon_magazine_definition) == 0x80);

enum e_weapon_trigger_definition_flags
{
	_weapon_trigger_autofire_single_action_only_bit,
	k_number_of_weapon_trigger_definition_flags
};

enum e_weapon_trigger_input
{
	_weapon_trigger_input_right_trigger,
	_weapon_trigger_input_left_trigger,
	_weapon_trigger_input_melee_attack,
	_weapon_trigger_input_automated_fire,
	_weapon_trigger_input_right_bumper,
	k_number_of_weapon_trigger_inputs
};

enum e_weapon_trigger_behavior
{
	_weapon_trigger_behavior_spew, // fires its primary action barrel whenever the trigger is down
	_weapon_trigger_behavior_latch, // fires its primary action barrel when the trigger is down and then latches
	_weapon_trigger_behavior_latch_autofire, // fires its primary action barrel once if pulsed quickly or if not depressed all the way, otherwise does secondary behavior
	_weapon_trigger_behavior_latch_tether, // tethers projectiles if latched long enough, on release the tethered projectile detonates
	_weapon_trigger_behavior_charge, // charges the trigger
	_weapon_trigger_behavior_latch_zoom, // latched; fires its primary action barrel when unzoomed, secondary when zoomed
	_weapon_trigger_behavior_spew_charge,
	_weapon_trigger_behavior_sword_charge,
	_weapon_trigger_behavior_double_latch_tether, // projectile is tethered by 1st latch, 2nd releases and detonates it
	_weapon_trigger_behavior_charge_with_magazine, // like charge, but pays attention to any magazine and will not charge unless magazine is idle and barrel is actually able to fire
	k_number_of_weapon_trigger_behaviors
};

enum e_weapon_trigger_prediction
{
	_weapon_trigger_prediction_none,
	_weapon_trigger_prediction_spew,
	_weapon_trigger_prediction_charge,
	k_number_of_weapon_trigger_predictions
};

enum e_weapon_trigger_autofire_action
{
	_weapon_trigger_autofire_action_fire,
	_weapon_trigger_autofire_action_charge,
	_weapon_trigger_autofire_action_track,
	_weapon_trigger_autofire_action_fire_other,
	k_number_of_weapon_trigger_autofire_actions
};

struct s_weapon_trigger_autofire_parameters
{
	real autofire_time;
	real autofire_throw;
	c_enum<e_weapon_trigger_autofire_action, short> secondary_action;
	c_enum<e_weapon_trigger_autofire_action, short> primary_action;
};
static_assert(sizeof(s_weapon_trigger_autofire_parameters) == 0xC);

enum e_weapon_trigger_overcharged_action
{
	_weapon_trigger_overcharged_action_none,
	_weapon_trigger_overcharged_action_explode,
	_weapon_trigger_overcharged_action_discharge,
	k_number_of_weapon_trigger_overcharged_actions
};

enum e_weapon_trigger_charge_projectiles
{
	_weapon_trigger_charge_projectiles_default,
	_weapon_trigger_charge_projectiles_one_for_every_charge_level,
	k_number_of_weapon_trigger_charge_projectiles
};

enum e_weapon_trigger_charging_flags
{
	_weapon_trigger_can_fire_from_partial_charge_bit,
	_weapon_trigger_charging_unknown1_bit,
	_weapon_trigger_charging_unknown2_bit,
	_weapon_trigger_charging_unknown3_bit,
	_weapon_trigger_disallow_fire_from_partial_charge_bit,
	k_number_of_weapon_trigger_charging_flags
};

struct s_weapon_trigger_charging_fire_fraction
{
	real charge_fraction; // charging fraction at which the weapon should additionally fire a shot
};
static_assert(sizeof(s_weapon_trigger_charging_fire_fraction) == 0x4);

struct s_weapon_trigger_charging_parameters
{
	real charging_time; // the amount of time it takes for this trigger to become fully charged
	real charged_time; // the amount of time this trigger can be charged before becoming overcharged
	c_enum<e_weapon_trigger_overcharged_action, char> overcharged_action;
	c_enum<e_weapon_trigger_charge_projectiles, char> charge_projectiles;
	c_flags<e_weapon_trigger_charging_flags, word> flags;
	real charged_illumination; // the amount of illumination given off when the weapon is fully charged
	s_tag_reference charging_effect; // the charging effect that is created once when the trigger begins to charge
	s_tag_reference charging_damage_effect; // the charging damage effect that is created once when the trigger begins to charge
	s_tag_reference charging_continuous_damage_response; // plays every tick you're charging or charged, scaled to charging fraction
	real charged_drain_rate; // how much battery to drain per second when charged
	s_tag_reference discharge_effect; // the discharging effect that is created once when the trigger releases its charge
	s_tag_reference discharge_damage_effect; // the discharging damage effect that is created once when the trigger releases its charge
	c_typed_tag_block<s_weapon_trigger_charging_fire_fraction> fire_fractions;
};
static_assert(sizeof(s_weapon_trigger_charging_parameters) == 0x70);

struct s_weapon_barrel_definition;

struct s_weapon_trigger_definition
{
	c_flags<e_weapon_trigger_definition_flags, dword> flags;
	c_enum<e_weapon_trigger_input, short> input;
	c_enum<e_weapon_trigger_behavior, short> behavior;
	c_tag_block_index<s_weapon_barrel_definition, short> primary_barrel;
	c_tag_block_index<s_weapon_barrel_definition, short> secondary_barrel;
	c_enum<e_weapon_trigger_prediction, short> prediction;
	short : 16;
	s_weapon_trigger_autofire_parameters autofire;
	s_weapon_trigger_charging_parameters charging;
};
static_assert(sizeof(s_weapon_trigger_definition) == 0x8C);

enum e_weapon_barrel_definition_flags
{
	_weapon_barrel_random_firing_effects_bit,
	_weapon_barrel_can_fire_with_partial_ammo_bit,
	_weapon_barrel_projectiles_use_weapon_origin_bit,
	_weapon_barrel_ejects_during_chamber_bit,
	_weapon_barrel_projectile_vector_cannot_be_adjusted_bit,
	_weapon_barrel_projectiles_have_identical_error_bit,
	_weapon_barrel_projectiles_fire_parallel_bit,
	_weapon_barrel_cannot_fire_when_others_firing_bit,
	_weapon_barrel_cannot_fire_when_others_recovering_bit,
	_weapon_barrel_do_not_clear_fire_bit_after_recovering_bit,
	_weapon_barrel_stagger_fire_across_multiple_markers_bit,
	_weapon_barrel_can_fire_at_maximum_age_bit,
	_weapon_barrel_use_1_firing_effect_per_burst_bit,
	_weapon_barrel_prevent_marker_deviation_bit,
	_weapon_barrel_error_ignores_zoom_bit,
	_weapon_barrel_projectile_fires_in_marker_direction_bit,
	_weapon_barrel_skip_test_for_object_being_outside_bsp_bit,
	_weapon_barrel_only_reload_if_all_barrels_idle_bit,
	_weapon_barrel_only_switch_weapons_if_barrel_idle_bit,
	_weapon_barrel_use_automatic_fire_looping_sounds_bit,
	k_number_of_weapon_barrel_definition_flags
};

struct s_weapon_barrel_firing_parameters
{
	s_real_bounds rounds_per_second; // the number of firing effects created per second. 0 defaults to 60
	string_id rate_of_fire_acceleration; // function value sets the current rate of fire when the barrel is firing
	real acceleration_time; // the continuous firing time it takes for the weapon to achieve its final rounds per second
	string_id rate_of_fire_deceleration; // function value sets the current rate of fire when the barrel is not firing
	real deceleration_time; // the continuous idle time it takes for the weapon to return from its final rounds per second to its initial
	real barrel_spin_scale; // scale the barrel spin speed by this amount
	real blurred_rate_of_fire; // a percentage between 0 and 1 which controls how soon in its firing animation the weapon blurs
	s_short_bounds shots_per_fire; // allows designer caps to the shots you can fire from one firing action
	real fire_recovery_time; // how long after a set of shots it takes before the barrel can fire again
	real soft_recovery_fraction; // how much of the recovery allows shots to be queued
	real melee_fire_recovery_time; // how long after a set of shots it takes before the weapon can melee
	real melee_soft_recovery_fraction; // how much of the melee recovery allows melee to be queued
};
static_assert(sizeof(s_weapon_barrel_firing_parameters) == 0x34);

enum e_weapon_barrel_prediction_type
{
	_weapon_barrel_prediction_none,
	_weapon_barrel_prediction_continuous,
	_weapon_barrel_prediction_instant,
	_weapon_barrel_prediction_continuous_burst,
	k_number_of_weapon_barrel_prediction_types
};

enum e_weapon_barrel_projectile_distribution_function
{
	_weapon_barrel_projectile_distribution_point,
	_weapon_barrel_projectile_distribution_horizontal_fan,
	k_number_of_weapon_barrel_projectile_distribution_functions
};

struct s_weapon_barrel_projectile_distribution
{
	c_enum<e_weapon_barrel_projectile_distribution_function, short> distribution_function;
	short projectiles_per_shot;
	real distribution_angle; // used by _weapon_barrel_projectile_distribution_horizontal_fan
};
static_assert(sizeof(s_weapon_barrel_projectile_distribution) == 0x8);

struct s_weapon_barrel_projectile_error_parameters
{
	real minimum_error; // projectile direction is randomly selected between this and max_error_angle below
	s_real_bounds error_angle; // current barrel_error is linearly interpolated between these to generate max_error_angle
};
static_assert(sizeof(s_weapon_barrel_projectile_error_parameters) == 0xC);

struct s_weapon_barrel_wield_accuracy_penalties
{
	c_typed_tag_block<s_tag_data> firing_penalty_function; // percentage accuracy lost when the barrel has fired
	c_typed_tag_block<s_tag_data> firing_crouched_penalty_function; // percentage accuracy lost when the barrel has fired from a crouched position
	c_typed_tag_block<s_tag_data> moving_penalty_function; // percentage accuracy lost when moving
	c_typed_tag_block<s_tag_data> turning_penalty_function; // percentage accuracy lost when turning the camera
	real error_angle_max_rotation; // angle which represents the maximum input to the turning penalty function
};
static_assert(sizeof(s_weapon_barrel_wield_accuracy_penalties) == 0x34);

struct s_weapon_barrel_accuracy_penalties
{
	real reload_penalty; // percentage accuracy lost when reloading
	real switch_penalty; // percentage accuracy lost when switching weapons
	real zoom_penalty; // percentage accuracy lost when zooming in/out
	real jump_penalty; // percentage accuracy lost when jumping
	s_weapon_barrel_wield_accuracy_penalties single_wield_penalties;
	s_weapon_barrel_wield_accuracy_penalties dual_wield_penalties;
};
static_assert(sizeof(s_weapon_barrel_accuracy_penalties) == 0x78);

struct s_weapon_barrel_first_person_offset
{
	s_real_point3d first_person_offset; // +x is forward, +z is up, +y is left
};
static_assert(sizeof(s_weapon_barrel_first_person_offset) == 0xC);

struct s_weapon_barrel_firing_effect
{
	s_short_bounds shot_count_range; // the range of the number of times this firing effect will be used, once it has been chosen
	s_tag_reference firing_effect; // this effect is used when the weapon is loaded and fired normally
	s_tag_reference misfire_effect; // this effect is used when the weapon is loaded but fired while overheated
	s_tag_reference empty_effect; // this effect is used when the weapon is not loaded
	s_tag_reference optional_secondary_firing_effect; // this effect is for later shots of a burst if set
	s_tag_reference firing_damage; // this effect is used when the weapon is loaded and fired normally
	s_tag_reference misfire_damage; // this effect is used when the weapon is loaded but fired while overheated
	s_tag_reference empty_damage; // this effect is used when the weapon is not loaded
	s_tag_reference optional_secondary_firing_damage; // this effect is for later shots of a burst if set
	s_tag_reference firing_rider_damage; // this effect is used when the weapon is loaded and fired normally
	s_tag_reference misfire_rider_damage; // this effect is used when the weapon is loaded but fired while overheated
	s_tag_reference empty_rider_damage; // this effect is used when the weapon is not loaded
	s_tag_reference optional_secondary_firing_rider_damage; // this effect is for later shots of a burst if set
};
static_assert(sizeof(s_weapon_barrel_firing_effect) == 0xC4);

struct s_weapon_barrel_definition
{
	c_flags<e_weapon_barrel_definition_flags, dword> flags;

	/* ------ firing */

	s_weapon_barrel_firing_parameters firing;
	c_tag_block_index<s_weapon_magazine_definition, short> magazine; // the magazine from which this trigger draws its ammunition
	short rounds_per_shot; // the number of rounds expended to create a single firing effect
	short minimum_rounds_loaded; // the minimum number of rounds necessary to fire the weapon
	short rounds_between_tracers; // the number of non-tracer rounds fired between tracers
	string_id optional_barrel_marker_name;
	c_enum<e_ai_sound_volume, short> firing_noise; // how loud this weapon appears to the AI when firing

	/* ------ prediction properties:
		what the behavior of this barrel is in a predicted network game
	*/

	c_enum<e_weapon_barrel_prediction_type, short> prediction_type;

	real unknown;

	/* ------ error */

	real acceleration_time;
	real deceleration_time;
	s_real_bounds damage_error_bounds;

	/* ------ error turn rates */

	real min_error_look_pitch_rate; // yaw rate is doubled
	real full_error_look_pitch_rate; // yaw rate is doubled
	real look_pitch_error_power; // use to soften or sharpen the rate ding

	/* ------ projectile */

	s_weapon_barrel_projectile_distribution projectile_distribution;
	s_weapon_barrel_projectile_error_parameters projectile_error;
	s_weapon_barrel_accuracy_penalties accuracy_penalties;
	c_typed_tag_block<s_weapon_barrel_first_person_offset> first_person_offset;
	c_enum<e_damage_reporting_type, char> projectile_damage_reporting_type;
	char : 8;
	short : 16;
	s_tag_reference projectile;
	s_tag_reference optional_secondary_projectile;
	s_tag_reference damage_effect;
	s_tag_reference crate_projectile;
	real crate_projectile_speed;

	/* ------ misc */

	real ejection_port_recovery_time; // the amount of time (in seconds) it takes for the ejection port to transition from 1.0 (open) to 0.0 (closed) after a shot has been fired
	real illumination_recovery_time; // the amount of time (in seconds) it takes the illumination function to transition from 1.0 (bright) to 0.0 (dark) after a shot has been fired
	real heat_generated_per_round; // the amount of heat generated each time the barrel fires. Unlike the name suggests, this amount of heat is NOT applied per projectile created
	string_id heat_generated_per_round_function; // function value sets the amount of heat to add to the weapon each tick the barrel is firing
	real age_generated_per_round; // the amount the weapon ages each time the trigger is fired
	real campaign_age_generated_per_round; // the amount the weapon ages each time the trigger is fired in campaign
	real overload_time; // the next trigger fires this often while holding down this trigger
	real runtime_illumination_recovery_rate;
	real runtime_ejection_port_recovery_rate;
	real rate_of_fire_acceleration_time;
	real rate_of_fire_deceleration_time;
	real bloom_rate_of_decay;
	c_typed_tag_block<s_weapon_barrel_firing_effect> firing_effects; // firing effects determine what happens when this trigger is fired
};
static_assert(sizeof(s_weapon_barrel_definition) == 0x184);

enum e_weapon_screen_effect_flags
{
	_weapon_screen_effect_overrides_unit_and_camera_screen_effects_bit,
	_weapon_screen_effect_unzoomed_bit,
	_weapon_screen_effect_zoom_level1_bit,
	_weapon_screen_effect_zoom_level2_bit,
	k_number_of_weapon_screen_effect_flags
};

struct s_weapon_screen_effect
{
	c_flags<e_weapon_screen_effect_flags, byte> flags;
	char : 8;
	short : 16;
	s_tag_reference screen_effect;
};
static_assert(sizeof(s_weapon_screen_effect) == 0x14);

struct s_weapon_definition : s_item_definition
{
	c_flags<e_weapon_definition_flags, dword> flags;
	c_flags<e_weapon_definition_secondary_flags, dword> secondary_flags;
	string_id unused_label;
	c_enum<e_weapon_secondary_trigger_mode, short> secondary_trigger_mode;
	short maximum_alternate_shots_loaded;
	real turn_on_time; // how long after being readied it takes this weapon to switch its 'turned_on' attachment to 1.0
	real ready_time;
	s_tag_reference ready_effect;
	s_tag_reference ready_damage_effect;

	/* ------ heat */

	real heat_recovery_threshold; // the heat value a weapon must return to before leaving the overheated state, once it has become overheated in the first place
	real overheated_threshold; // the heat value over which a weapon first becomes overheated (should be greater than the heat recovery threshold)
	real heat_detonation_threshold; // the heat value above which the weapon has a chance of exploding each time it is fired
	real heat_detonation_fraction; // the percent chance (between 0.0 and 1.0) the weapon will explode when fired over the heat detonation threshold
	real heat_loss_per_second; // the amount of heat lost each second when the weapon is not being fired
	string_id heat_loss; // function value sets the current heat loss per second
	string_id heat_loss_venting; // function value sets the heat loss per second while weapon is being vented
	real heat_venting_time;
	real heat_venting_exit_heat; // heat at which to begin the venting exit animations so that the weapon is just about fully cooled when the exit animation completes
	real heat_illumination; // the amount of illumination given off when the weapon is overheated
	real heat_warning_threshold; // the amount of heat at which a warning will be displayed on the hud
	real overheated_heat_loss_per_second; // the amount of heat lost each second when the weapon is not being fired
	string_id overheated_heat_loss; // function value sets the heat loss per second when weapon is overheated
	s_tag_reference overheated;
	s_tag_reference overheated_damage_effect;
	s_tag_reference detonation;
	s_tag_reference detonation_damage_effect;

	/* ------ melee */

	c_typed_tag_block<s_melee_damage_parameters> melee_damage_parameters;
	s_tag_reference clang_effect; // effect that is played in the air between two players that clang with this weapon
	c_enum<e_damage_reporting_type, char> melee_damage_reporting_type;
	char : 8;

	/* ------ zoom */

	short magnification_levels; // the number of magnification levels this weapon allows
	s_real_bounds magnification_range;

	/* ------ aim assist */

	s_aim_assist_parameters aim_assist;
	c_typed_tag_block<s_target_tracking_parameters> target_tracking;

	/* ------ ballistics */

	s_real_bounds ballistic_arcing_firing_bounds; // word units; at the min range (or closer), the minimum ballistic arcing is used, at the max (or farther away), the maximum arcing is used
	s_real_bounds ballistic_arcing_fraction_bounds; // controls speed and degree of arc. 0 = low, fast, 1 = high, slow

	/* ------ movement */

	c_enum<e_weapon_movement_penalty, short> movement_penalized;
	short : 16;
	real forward_movement_penalty; // percent slowdown to forward movement for units carrying this weapon
	real sideways_movement_penalty; // percent slowdown to sideways and backward movement for units carrying this weapon

	/* ------ AI targeting parameters */

	real ai_scariness;

	/* ------ miscellaneous */

	real weapon_power_on_time;
	real weapon_power_off_time;
	s_tag_reference weapon_power_on_effect;
	s_tag_reference weapon_power_off_effect;
	real age_heat_recovery_penalty; // how much the weapon's heat recovery is penalized as it ages
	real age_rate_of_fire_penalty; // how much the weapon's rate of fire is penalized as it ages
	real age_misfire_start; // the age threshold when the weapon begins to misfire
	real age_misfire_chance; // at age 1.0, the misfire chance per shot
	s_tag_reference pickup_sound;
	s_tag_reference zoom_in_sound;
	s_tag_reference zoom_out_sound;
	real active_camo_ding; // how much to decrease active camo when a round is fired
	string_id handle_node; // the node that get's attached to the unit's hand

	/* ------ weapon labels */

	string_id weapon_class;
	string_id weapon_name;

	c_enum<e_weapon_type, short> weapon_type;
	short low_ammo_threshold;

	/* ------ interface */

	real unknown1;
	real unknown2;
	real unknown3;
	real unknown4;
	c_typed_tag_block<s_weapon_first_person_interface> first_person;
	s_tag_reference hud_interface;
	s_tag_reference alternate_hud_interface; // the parent of the weapon can indicate that this hud should be used instead of the default

	c_typed_tag_block<s_weapon_predicted_resources> predicted_resources;
	c_typed_tag_block<s_weapon_magazine_definition> magazines;
	c_typed_tag_block<s_weapon_trigger_definition> new_triggers;
	c_typed_tag_block<s_weapon_barrel_definition> barrels;

	real runtime_weapon_power_on_velocity;
	real runtime_weapon_power_off_velocity;

	/* ------ first-person movement control */

	real max_movement_acceleration;
	real max_movement_velocity;
	real max_turning_acceleration;
	real max_turning_velocity;

	s_tag_reference deployed_vehicle;
	s_tag_reference tossed_weapon;
	s_tag_reference age_effect;
	s_tag_reference aged_weapon;
	s_tag_reference aged_material_effects;

	real external_aging_amount;
	real campaign_external_aging_amount;
	real external_heat_amount;

	s_real_vector3d first_person_weapon_offset;
	s_real_vector2d first_person_scope_size;
	s_real_bounds support_third_person_camera_range; // range in degrees. 0 is straight, -90 is down, 90 is up

	real weapon_zoom_time; // in seconds
	real weapon_ready_for_use_time; // in seconds
	
	string_id unit_stow_anchor_name;

	c_typed_tag_block<s_weapon_screen_effect> screen_effects;
};
static_assert(sizeof(s_weapon_definition) == sizeof(s_item_definition) + 0x2CC);

/* ---------- globals */

extern s_tag_block_definition g_weapon_barrel_definition_block;
extern s_tag_group g_weapon_group;
