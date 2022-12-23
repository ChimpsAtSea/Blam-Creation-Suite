#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/datatypes/enum.h>
#include <blamlib/datatypes/flags.h>
#include <blamlib/math/real_math.h>
#include <blamlib/tag_files/string_ids.h>
#include <blamlib/tag_files/tag_groups.h>
#include <blamlib/haloreach/game/campaign_metagame.h>
#include <blamlib/haloreach/game/game_allegiance.h>
#include <blamlib/haloreach/physics/character_physics_definitions.h>

/* ---------- constants */

constexpr tag k_big_battle_creature_group_tag = 'bbcr';

/* ---------- types */

enum e_big_battle_creature_flags
{
	_big_battle_creature_unused_bit,
	_big_battle_creature_immune_to_falling_damage_bit,
	_big_battle_creature_rotate_while_airborne_bit,
	_big_battle_creature_zapped_by_shields_bit,
	_big_battle_creature_attach_upon_impact_bit,
	_big_battle_creature_not_on_motion_sensor_bit,
	_big_battle_creature_force_ground_movement_bit,
	k_number_of_big_battle_creature_flags
};

enum e_big_battle_flags
{
	_big_battle_boid_aims_at_big_battle_target_bit, // setting this forces boid to aim at target instead of firing straight ahead
	_big_battle_boids_fly_with_no_pitch_bit, // flying boids will always stay level when changing altitude
	_big_battle_boids_fly_non_directionally_bit, // flying boids will move like helicopters
	k_number_of_big_battle_flags
};

struct s_big_battle_creature_definition
{
	c_flags<e_big_battle_creature_flags, dword, k_number_of_big_battle_creature_flags> flags;
	c_enum<e_campaign_team, short> default_team;

	short : 16;

	real turning_velocity_maximum; // degrees per second (ground creatures only)
	real turning_acceleration_maximum; // degrees per second squared (ground creatures only)
	real casual_turning_modifier; // [0,1] (ground creatures only)
	real autoaim_width; // world units

	s_character_physics_definition physics;

	s_tag_reference impact_damage;
	s_tag_reference impact_shield_damage; // if not specified, uses impact_damage

	c_typed_tag_block<s_campaign_metagame_bucket> campaign_metagame_bucket;

	/* ------ death and destruction */

	real_bounds destroy_after_death_time; // if non-zero, the creature will destroy itself upon death after this much time

	/* ------ big battle:
		the following fields only affect creatures configured as boids for big battle */

	c_flags<e_big_battle_flags, dword, k_number_of_big_battle_flags> big_battle_flags;

	s_tag_reference big_battle_weapon_emitter;
	real_point3d big_battle_weapon_offset;

	s_tag_reference big_battle_weapon_emitter2; // if you leave this empty, only the first emitter will fire
	real_point3d big_battle_weapon_offset2;

	c_typed_tag_block<s_tag_function> big_battle_weapon_fire_timing;

	s_tag_reference big_battle_expensive_weapon_effect; // this fires a full effect from location up, oriented along vehicle's forward and up axes
	real_bounds expensive_weapon_fire_time; // seconds

	s_tag_reference big_battle_death_effect;

	s_tag_reference big_battle_imposter;
};
static_assert(sizeof(s_big_battle_creature_definition) == 0x184);
