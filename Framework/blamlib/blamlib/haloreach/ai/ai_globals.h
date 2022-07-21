#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/math/integer_math.h>
#include <blamlib/math/real_math.h>
#include <blamlib/tag_files/tag_groups.h>
#include <blamlib/tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_ai_globals_group_tag = 'aigl';

/* ---------- types */

struct s_ai_globals_gravemind_definition
{
	real min_retreat_time;
	real ideal_retreat_time;
	real max_retreat_time;
};
static_assert(sizeof(s_ai_globals_gravemind_definition) == 0xC);

struct s_ai_globals_formation_definition
{
	s_tag_reference formation;
};
static_assert(sizeof(s_ai_globals_formation_definition) == 0x10);

struct s_ai_globals_squad_template_definition
{
	s_tag_reference squad_template;
};
static_assert(sizeof(s_ai_globals_squad_template_definition) == 0x10);

struct s_ai_globals_squad_template_sub_folder
{
	string_id sub_folder_name;
	c_typed_tag_block<s_ai_globals_squad_template_definition> templates;
};
static_assert(sizeof(s_ai_globals_squad_template_sub_folder) == 0x10);

struct s_ai_globals_squad_template_folder
{
	string_id folder_name;
	c_typed_tag_block<s_ai_globals_squad_template_sub_folder> sub_folders;
	c_typed_tag_block<s_ai_globals_squad_template_definition> templates;
};
static_assert(sizeof(s_ai_globals_squad_template_folder) == 0x1C);

struct s_ai_globals_performance_template_definition
{
	s_tag_reference performance_template;
};
static_assert(sizeof(s_ai_globals_performance_template_definition) == 0x10);

struct s_ai_globals_performance_template_sub_folder
{
	string_id sub_folder_name;
	c_typed_tag_block<s_ai_globals_performance_template_definition> templates;
};
static_assert(sizeof(s_ai_globals_performance_template_sub_folder) == 0x10);

struct s_ai_globals_performance_template_folder
{
	string_id folder_name;
	c_typed_tag_block<s_ai_globals_performance_template_sub_folder> sub_folders;
	c_typed_tag_block<s_ai_globals_performance_template_definition> templates;
};
static_assert(sizeof(s_ai_globals_performance_template_folder) == 0x1C);

struct s_ai_globals_custom_stimuli_definition
{
	string_id name;
};
static_assert(sizeof(s_ai_globals_custom_stimuli_definition) == 0x4);

struct s_ai_globals_unknown11C_unknown04_definition
{
	real unknown;
};
static_assert(sizeof(s_ai_globals_unknown11C_unknown04_definition) == 0x4);

struct s_ai_globals_unknown11C_unknown10_definition
{
	string_id unknown;
};
static_assert(sizeof(s_ai_globals_unknown11C_unknown10_definition) == 0x4);

struct s_ai_globals_unknown11C_unknown1C_definition
{
	int unknown00;
	int unknown04;
	int unknown08;
	int unknown0C;
	int unknown10;
	int unknown14;
	int unknown18;
	int unknown1C;
	int unknown20;
	int unknown24;
	int unknown28;
};
static_assert(sizeof(s_ai_globals_unknown11C_unknown1C_definition) == 0x2C);

struct s_ai_globals_unknown11C_definition
{
	string_id unknown00;
	c_typed_tag_block<s_ai_globals_unknown11C_unknown04_definition> unknown04;
	c_typed_tag_block<s_ai_globals_unknown11C_unknown10_definition> unknown10;
	c_typed_tag_block<s_ai_globals_unknown11C_unknown1C_definition> unknown1C;
};
static_assert(sizeof(s_ai_globals_unknown11C_definition) == 0x28);

struct s_ai_globals_trait_vision_definition // Traits that affect the AI's vision
{
	real vision_distance_scale; // Scale the distance at which an AI can see their target.
	real vision_angle_scale; // Scale the angles of the AI's vision cone.
};
static_assert(sizeof(s_ai_globals_trait_vision_definition) == 0x8);

struct s_ai_globals_trait_sound_definition // Traits that affect the AI's sound awareness
{
	real hearing_distance_scale; // Scale the character's hearing distance.
};
static_assert(sizeof(s_ai_globals_trait_sound_definition) == 0x4);

struct s_ai_globals_trait_luck_definition // Traits that affect the AI's luck
{
	real evasion_chance_scale; // Scale the chance of evading fire.
	real grenade_dive_chance_scale; // Scale the chance of diving from grenades.
	real broken_kamikaze_chance_scale; // Scale the chance of going kamikaze when broken.
	real leader_dead_retreat_chance_scale; // Scale the chance of retreating when your leader dies.
	real dive_retreat_chance_scale; // Scale the chance of retreating after a dive.
	real shield_depleted_berserk_chance_scale; // Scale the chance of berserking when your shield is depleted.
	real leader_abandoned_berserk_chance_scale; // Scale the chance of a leader berserking when all his followers die.
	real melee_attack_delay_timer_scale; // Scale the time between melee attacks.
	real melee_chance_scale; // Scale the chance of meleeing.
	real melee_leap_delay_timer_scale; // Scale the delay for performing melee leaps.
	real throw_grenade_delay_scale; // Scale the time between grenade throws.
};
static_assert(sizeof(s_ai_globals_trait_luck_definition) == 0x2C);

struct s_ai_globals_trait_grenade_definition // Traits that affect the AI's grenade use
{
	real velocity_scale; // Scale the velocity at which AI throws grenades
	real throw_grenade_delay_scale; // Scale the time between grenade throws
	real dont_drop_grenades_chance_scale;
	real grenade_uncover_chance_scale;
	real retreat_throw_grenade_chance_scale;
	real anti_vehicle_grenade_chance_scale;
	real throw_grenade_chance_scale;
};
static_assert(sizeof(s_ai_globals_trait_grenade_definition) == 0x1C);

struct s_ai_globals_data
{
	real ai_infantry_on_ai_weapon_damage_scale; // [0,1] Global scale on weapon damage made by AI on other AI
	real ai_vehicle_on_ai_weapon_damage_scale; // [0,1] Global scale on weapon damage made by AI in a vehicle on other AI
	real ai_player_vehicle_on_ai_weapon_damage_scale; // [0,1] Global scale on weapon damage made by AI in a vehicle with the player on other AI

	real danger_broadly_facing;
	real danger_shooting_near;
	real danger_shooting_at;
	real danger_extremely_close;
	real danger_shield_damage;
	real danger_extended_shield_damage;
	real danger_body_damage;
	real danger_extended_body_damage;

	s_tag_reference global_dialogue;
	string_id default_mission_dialogue_sound_effect;

	real jump_down;
	real jump_step;
	real jump_crouch;
	real jump_stand;
	real jump_storey;
	real jump_tower;
	int : 32;

	real maximum_jump_down_height_down;
	real maximum_jump_down_height_step;
	real maximum_jump_down_height_crouch;
	real maximum_jump_down_height_stand;
	real maximum_jump_down_height_storey;
	real maximum_jump_down_height_tower;
	int : 32;

	real hoist_step_min;
	real hoist_step_max;
	real hoist_crouch_min;
	real hoist_crouch_max;
	real hoist_stand_min;
	real hoist_stand_max;
	real vault_step_min;
	real vault_step_max;
	real vault_crouch_min;
	real vault_crouch_max;

	/* ------ PATHFINDING SEARCH RANGES:
		The maximum ranges to which firing point evaluations will do pathfinding searches.
		INCREASING THESE VALUES WILL ALMOST CERTAINLY HAVE A NEGATIVE IMPACT ON PERFORMANCE. */

	real search_range_infantry;
	real search_range_flying;
	real search_range_vehicle;
	real search_range_giant;

	c_typed_tag_block<s_ai_globals_gravemind_definition> gravemind_properties;

	real scary_target_threshold; // A target of this scariness is offically considered scary (by combat dialogue, etc.)
	real scary_weapon_threshold; // A weapon of this scariness is offically considered scary (by combat dialogue, etc.)
	real player_scariness; // when an actor's target is a player, he is this much more scared
	real berserking_actor_scariness; // when an actor's target is a berserking actor, he is this much more scared
	real kamikazeing_actor_scariness; // when an actor's target is a kamikazeing actor, he is this much more scared
	real invincible_scariness; // when an actor's target is invincible, he is this much more scared

	/* ------ RESURRECTION:
		A few properties to help define when it is safe for a mission critical character to ressurect. */

	real min_death_time; // I will be dead for at least this long
	real projectile_distance; // If there is a projectile within this distance of me, I'll stay dead
	real idle_clump_distance; // If there is any enemy clump within this distance of me, I'll stay dead
	real dangerous_clump_distance; // If there is any enemy clump with a status higher than idle within this distance of me, I'll stay dead

	/* ------ TELEPORTATION:
		A few properties to help define when it is safe for a mission critical character to teleport. */

	real cover_search_duration;
	real task_direction_search_duration;

	c_typed_tag_block<s_ai_globals_formation_definition> spawn_formations;
	c_typed_tag_block<s_ai_globals_squad_template_folder> squad_template_folders;
	c_typed_tag_block<s_ai_globals_performance_template_folder> performance_template_folders;
	c_typed_tag_block<s_ai_globals_custom_stimuli_definition> custom_stimuli;
	c_typed_tag_block<s_ai_globals_unknown11C_definition> unknown11C;

	/* ------ CLUMP THROTTLING:
		Some values to help you control how much guys will throttle when they want to stick with the rest of their squad. */

	real stop_distance;
	real resume_distance;
	real minimum_distance;
	real maximum_distance;
	real minimum_scale;

	/* ------ SQUAD PATROLLING:
		Parameters related to squad patrolling. */

	real passthrough_chance;
	real search_phase_skip_chance;
	real patrol_transition_timeout;
	real patrol_maneuver_timeout;
	real patrol_search_firing_point_time_min;
	real patrol_search_firing_point_time_max;
	real patrol_isolation_distance;
	real patrol_isolation_time;

	/* ------ KUNGFU CONTROL:
		These parameters control how the kung-fu circle works (i.e. when tasks have kungfu-count associated with them) */

	real kungfu_deactivation_delay;

	/* ------ Presearch Child Counts (0 Means No Limit) */

	short suppressing_fire_count;
	short uncover_count;
	short leap_on_cover_count;
	short destroy_cover_count;
	short guard_count;
	short investigate_count;

	c_typed_tag_block<s_ai_globals_trait_vision_definition> vision_traits;
	c_typed_tag_block<s_ai_globals_trait_sound_definition> sound_traits;
	c_typed_tag_block<s_ai_globals_trait_luck_definition> luck_traits;
	c_typed_tag_block<s_ai_globals_trait_grenade_definition> grenade_traits;

	real max_decay_time;
	real decay_time_ping;
	real search_pattern_radius;
	short search_pattern_shell_count;
	short_bounds search_pattern_cells_per_shell_range;
	short : 16;
};
static_assert(sizeof(s_ai_globals_data) == 0x1B0);

struct s_ai_globals_definition
{
	c_typed_tag_block<s_ai_globals_data> data;
	int : 32;
};
static_assert(sizeof(s_ai_globals_definition) == 0x10);
