#pragma once

#include <cseries/cseries.h>
#include <math/real_math.h>
#include <tag_files/tag_groups.h>
#include <haloreach/items/item_definitions.h>
#include <haloreach/units/unit_definitions.h>
#include <haloreach/ai/ai_traits.h>
#include <haloreach/game/game_engine_player_traits.h>
#include <haloreach/game/game_powerups.h>
#include <haloreach/objects/damage_new.h>

/* ---------- constants */

enum
{
	k_equipment_group_tag = 'eqip'
};

/* ---------- types */

enum e_equipment_flags
{
	_equipment_flags_unknown0_bit,
	_equipment_flags_unknown1_bit,
	_equipment_flags_unknown2_bit,
	_equipment_flags_unknown3_bit,
	_equipment_3rd_person_camera_while_active_bit,
	_equipment_3rd_person_camera_during_activation_animation_bit,
	_equipment_hide_reticule_while_active_bit,
	_equipment_cannot_be_active_while_airborne_bit,
	_equipment_cannot_activate_while_airborne_bit,
	_equipment_cannot_activate_while_standing_on_biped_bit,
	_equipment_cannot_be_active_in_vehicle_bit,
	_equipment_suppresses_weapons_while_active_bit,
	_equipment_suppresses_melee_while_active_bit,
	_equipment_suppresses_grenades_while_active_bit,
	_equipment_suppresses_device_interaction_while_active_bit,
	_equipment_suppresses_sprint_while_active_bit,
	_equipment_suppresses_entering_vehicle_bit,
	_equipment_duck_sound_while_active_bit,
	_equipment_blocks_tracking_while_active_bit,
	_equipment_readies_weapon_on_deactivation_bit,
	_equipment_drops_support_weapons_on_activation_bit,
	_equipment_hides_weapon_on_activation_bit,
	_equipment_cannot_activate_in_vehicle_bit,
	_equipment_flags_unknown23_bit,
	_equipment_flags_unknown24_bit,
	_equipment_flags_unknown25_bit,
	_equipment_flags_unknown26_bit,
	_equipment_flags_unknown27_bit,
	_equipment_flags_unknown28_bit,
	_equipment_flags_unknown29_bit,
	_equipment_flags_unknown30_bit,
	_equipment_flags_unknown31_bit,
	k_number_of_equipment_flags
};

enum e_equipment_pickup_behavior
{
	_equipment_pickup_behavior_none = NONE,
	_equipment_pickup_behavior_automatic_if_empty, // picks it up automatically, if you have no equipment in your inventory, otherwise, press RB to swap
	_equipment_pickup_behavior_always_automatic, // always picks it up, whether or not you have another piece of equipment
	_equipment_pickup_behavior_manual, // press RB to pickup or swap this equipment
	_equipment_pickup_behavior_activate_on_ground, // Never pickup, press RB to activate it in-place
	k_number_of_equipment_pickup_behaviors
};

enum e_equipment_activation_source
{
	_equipment_activation_source_toggle, // toggles state when X is pressed
	_equipment_activation_source_hold, // activates when X is pressed and deactivates when X is released
	_equipment_activation_source_double_tap, // activates when X is pressed twice in quick succession
	_equipment_activation_source_shield_fail, // activates when player shield fails
	_equipment_activation_source_death, // activates when player dies
	k_number_of_equipment_activation_sources
};

struct s_equipment_ability_type_multiplayer_powerup
{
	c_enum<e_multiplayer_powerup_flavor, long> flavor;
};
static_assert(sizeof(s_equipment_ability_type_multiplayer_powerup) == 0x4);

enum e_equipment_spawner_type
{
	_equipment_spawner_type_along_aiming_vector,
	_equipment_spawner_type_camera_pos_z_plane,
	_equipment_spawner_type_foot_pos_z_plane,
	k_number_of_equipment_spawner_types
};

struct s_equipment_ability_type_spawner
{
	s_tag_reference spawned_object;
	s_tag_reference spawned_effect;
	real spawn_radius; // distance from players eyeball on the z-plane that this effect spawns
	real spawn_z_offset; // z-offset of effect spawn
	real spawn_area_radius; // need a sphere of radius r's free space in order to spawn, otherwise we pick a new spawn location
	real spawn_velocity;
	c_enum<e_equipment_spawner_type, short> type;
	short : 16;
};
static_assert(sizeof(s_equipment_ability_type_spawner) == 0x34);

struct s_equipment_ability_type_proximity_mine
{
	s_tag_reference explosion_effect;
	s_tag_reference explosion_damage_effect;
	real arm_time; // time before it becomes a proximity mine
	real self_destruct_time; // seconds after it is created that it must self destruct. 0 means never destroy
	real trigger_time; // seconds object moving at trigger velocity takes to trigger explosion. This will smooth out sensitivity to velocity noise
	real trigger_velocity; // world units per second at which we trigger explosion
};
static_assert(sizeof(s_equipment_ability_type_proximity_mine) == 0x30);

struct s_equipment_ability_type_motion_tracker_noise
{
	real arm_time; // time before it starts making noise
	real noise_radius; // radius in WU that the noise extends to
	long noise_count; // number of noise points that are generated
	real flash_radius; // radius in WU that the damage flash noise extends to
};
static_assert(sizeof(s_equipment_ability_type_motion_tracker_noise) == 0x10);

struct s_equipment_ability_type_unknown
{
	// TODO
};

struct s_equipment_effect_with_threshold
{
	real threshold_energy_burned; // how much energy you have to burn to play this effect
	real energy_adjustment; // how much energy to add when playing this effect
	s_tag_reference effect;
};
static_assert(sizeof(s_equipment_effect_with_threshold) == 0x18);

struct s_equipment_ability_type_invincibility
{
	string_id invincibility_material;
	short invincibility_material_type;
	short : 16;
	real shield_recharge_rate; // while active, shields recharge at this fraction per second
	real shield_max_recharge_level; // highest level shield can recharge to (can be up to 4)
	s_tag_reference override_collision_damage;
	s_tag_reference ai_melee_reflect_damage;
	s_tag_reference player_melee_reflect_damage;
	string_id loop_invincibility_shield_name; // active while the equipment is in use (used for shield rendering effects)
	string_id post_invincibility_shield_name; // active once the equipment is no longer in use
	s_tag_function post_invincibility_time_to_shield_level_function;
	real maximum_vertical_velocity; // we use this to specify the domain of the active vertical velocity funtion
	s_tag_function active_vertical_velocity_damping;
	c_typed_tag_block<s_equipment_effect_with_threshold> threshold_effects;
};
static_assert(sizeof(s_equipment_ability_type_invincibility) == 0x80);

enum e_equipment_tree_of_life_flags
{
	_equipment_tree_of_life_unstuns_shields_bit,
	_equipment_tree_of_life_unstuns_body_bit,
	k_number_of_equipment_tree_of_life_flags
};

struct s_equipment_ability_type_tree_of_life
{
	c_flags<e_equipment_tree_of_life_flags, dword> flags;
	string_id origin_marker;
	real radius;
};
static_assert(sizeof(s_equipment_ability_type_tree_of_life) == 0xC);

struct s_equipment_ability_type_shapeshifter
{
	string_id region_name;
	string_id inactive_permutation_name;
	string_id active_permutation_name;
};
static_assert(sizeof(s_equipment_ability_type_shapeshifter) == 0xC);

struct s_equipment_ability_type_player_trait_field
{
	real radius; // unused
	c_typed_tag_block<s_game_engine_player_traits> active_player_traits;
	c_typed_tag_block<s_game_engine_player_traits> inactive_player_traits;
};
static_assert(sizeof(s_equipment_ability_type_player_trait_field) == 0x1C);

struct s_equipment_ability_type_ai_trait_field
{
	c_typed_tag_block<s_ai_equipment_traits> active_ai_equipment_traits;
	c_typed_tag_block<s_ai_equipment_traits> inactive_ai_equipment_traits;
};
static_assert(sizeof(s_equipment_ability_type_ai_trait_field) == 0x18);

enum e_equipment_repulsor_field_flags
{
	_equipment_repulsor_field_affects_projectiles_bit,
	_equipment_repulsor_field_affects_vehicles_bit,
	_equipment_repulsor_field_affects_bipeds_bit,
	k_number_of_equipment_repulsor_field_flags
};

struct s_equipment_ability_type_repulsor_field
{
	c_flags<e_equipment_repulsor_field_flags, dword> flags;
	real radius;
	real power;
};
static_assert(sizeof(s_equipment_ability_type_repulsor_field) == 0xC);

enum e_equipment_stasis_field_flags
{
	_equipment_stasis_field_affects_projectiles_bit,
	_equipment_stasis_field_affects_vehicles_bit,
	_equipment_stasis_field_affects_bipeds_bit,
	k_number_of_equipment_stasis_field_flags
};

struct s_equipment_ability_type_stasis_field
{
	c_flags<e_equipment_stasis_field_flags, dword> flags;
	real radius;
	
	/* ------ time dilation:
		the effective rate at which time passes for objects in the field
		values below 0.45 screw up jumping
	*/

	real time_dilation_player_characters;
	real time_dilation_projectiles;
	real time_dilation_vehicles;
	real time_dilation_other;

	real max_biped_turning_rate;

	real gravity_multiplier; // negative values will invert gravity
};
static_assert(sizeof(s_equipment_ability_type_stasis_field) == 0x20);

enum e_equipment_daddy_flags
{
	_equipment_daddy_inactive_unstowed_bit,
	_equipment_daddy_inactive_stowed_bit,
	_equipment_daddy_active_unstowed_bit,
	_equipment_daddy_active_stowed_bit,
	_equipment_daddy_warming_up_unstowed_bit,
	_equipment_daddy_warming_up_stowed_bit,
	_equipment_daddy_cooling_down_unstowed_bit,
	_equipment_daddy_cooling_down_stowed_bit,
	_equipment_daddy_shield_vitality_tied_to_energy_bit, // as energy goes down, the shield vitality will as well
	_equipment_daddy_attach_to_marker_bit, // child object directly attached to parent
	_equipment_daddy_drain_energy_when_child_destroyed_bit, // destruction of child object drains equipment of all energy
	k_number_of_equipment_daddy_flags
};

struct s_equipment_ability_type_daddy
{
	s_tag_reference child_object;
	c_enum<e_equipment_daddy_flags, word> flags;
	short : 16;
	real shield_damage_to_energy_scale; // scale factor for energy gain from shield damage to child. Damage is normalized, so if this value is -1.0 then the equipment will lose all its energy when its child's shield is depleted
	real starting_warm_up_object_scale; // if &gt;0 (and warm up time is &gt;0), object size will scale up from this up to 1.0 over course of warm up time and down over cooldown time
	real target_object_scale;  // if nonzero, object size will scale to this ratio after warmup time. default = 1.0

	// TODO
};

struct s_equipment_ability_type_super_jump
{
	// TODO
};

struct s_equipment_ability_type_ammo_pack
{
	// TODO
};

struct s_equipment_ability_type_power_first
{
	// TODO
};

struct s_equipment_ability_type_health_pack
{
	// TODO
};

struct s_equipment_ability_type_jet_pack
{
	// TODO
};

struct s_equipment_ability_type_hologram
{
	// TODO
};

struct s_equipment_ability_type_special_weapon
{
	// TODO
};

struct s_equipment_ability_type_special_move
{
	// TODO
};

struct s_equipment_ability_type_engineer_shields
{
	// TODO
};

struct s_equipment_ability_type_sprint
{
	// TODO
};

struct s_equipment_definition : s_item_definition
{
	/* ------ timers */

	real duration; // use negative numbers for infinite duration
	real warmup_time; // time before the equipment truly becomes active
	real cooldown_time; // for equipment that suppresses combat actions, these actions remain suppressed for this long after the equipment deactivates Note that if this equipment also readies weapons when deactivated, the weapon will not be usable until both this timer expires and the ready animation has finished, whichever is longer
	real phantom_volume_activation_time; // time in seconds for the phantom volumes on this object to start accelerating things in them

	/* ------ energy */

	real minimum_activation_energy; // energy must be at least this high to activate Like activation cost, but doesn't actually change energy levels
	real low_energy_warning_threshold; // used by UI
	real activation_energy_cost;
	real deactivation_energy_cost;
	real active_energy_rate;
	real recharge_rate;
	s_tag_function movement_speed_to_energy_rate;
	real movement_speed_domain;

	c_flags<e_equipment_flags, dword> flags;
	c_enum<e_equipment_pickup_behavior, short> pickup_behavior;
	c_enum<e_equipment_activation_source, char> activation_mode;
	char object_noise_adjustment; // for AI perception. while active, adjusts noises made by the owner unit by this many 'notches'. note that this is additive, so a positive number is louder and a negative number is quieter
	string_id unit_stow_marker; // the marker on the unit to attach this equipment to when it is stowed. The equipment should have a marker named "equipment_stow_anchor"
	s_real_argb_color forced_primary_change_color; // sets the primary change color on the unit to this if the flag above is checked
	s_real_argb_color forced_secondary_change_color; // sets the secondary change color on the unit to this if the flag above is checked

	/* ------ ai */

	real danger_radius; // how large a danger zone we should create around this equipment (0 means no danger zone)
	real min_deployment_distance; // how far does my target have to be for me to throw this at them
	real awareness_time; // how long before nearby enemies become aware of the player
	string_id ai_dialogue_equipment_type; // the equipment ability type name used by the ai dialog system used to filter equipment activation dialogue events

	c_typed_tag_block<s_unit_camera> override_camera;

	/* ------ abilities */

	c_typed_tag_block<s_equipment_ability_type_multiplayer_powerup> multiplayer_powerup;
	c_typed_tag_block<s_equipment_ability_type_spawner> spawner;
	c_typed_tag_block<s_equipment_ability_type_proximity_mine> proximity_mine;
	c_typed_tag_block<s_equipment_ability_type_motion_tracker_noise> motion_tracker_noise;
	c_typed_tag_block<s_equipment_ability_type_unknown> unknown_ability; // TODO
	c_typed_tag_block<s_equipment_ability_type_invincibility> invincibility_mode;
	c_typed_tag_block<s_equipment_ability_type_tree_of_life> tree_of_life;
	c_typed_tag_block<s_equipment_ability_type_shapeshifter> shapeshifter;
	c_typed_tag_block<s_equipment_ability_type_player_trait_field> player_trait_field;
	c_typed_tag_block<s_equipment_ability_type_ai_trait_field> ai_trait_field;
	c_typed_tag_block<s_equipment_ability_type_repulsor_field> repulsor_field;
	c_typed_tag_block<s_equipment_ability_type_stasis_field> stasis_field;
	c_typed_tag_block<s_equipment_ability_type_daddy> daddy;
	c_typed_tag_block<s_equipment_ability_type_super_jump> super_jump;
	c_typed_tag_block<s_equipment_ability_type_ammo_pack> ammo_pack;
	c_typed_tag_block<s_equipment_ability_type_power_first> power_fist;
	c_typed_tag_block<s_equipment_ability_type_health_pack> health_pack;
	c_typed_tag_block<s_equipment_ability_type_jet_pack> jet_pack;
	c_typed_tag_block<s_equipment_ability_type_hologram> hologram;
	c_typed_tag_block<s_equipment_ability_type_special_weapon> special_weapon;
	c_typed_tag_block<s_equipment_ability_type_special_move> special_move;
	c_typed_tag_block<s_equipment_ability_type_engineer_shields> engineer_shields;
	c_typed_tag_block<s_equipment_ability_type_sprint> sprint;

	c_enum<e_damage_reporting_type, char> damage_reporting_type;
	char : 8;
	char : 8;
	char : 8;

	s_tag_reference hud_interface;
	s_tag_reference pickup_sound;
	s_tag_reference empty_sound;
	
	s_tag_reference activation_effect;
	s_tag_reference active_effect;
	s_tag_reference looping_effect;
	s_tag_reference deactivate_effect;

	string_id activation_animation;
	string_id active_animation;
	string_id deactivate_animation;
	string_id active_animation_stance;
};
static_assert(sizeof(s_equipment_definition) == sizeof(s_item_definition) + 0x220);
