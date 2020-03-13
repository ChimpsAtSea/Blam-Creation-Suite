/*
DEATH_PROGRAM_SELECTION_DEFINITIONS.H

	Death Program Selection:
		There are 3 levels of filtering for this.
		Certain combinations of the first two levels are either impossible or redundant.
		This is because they come from different places in the damage code. I will try to make that clearer here:
		
		The first level of filtering is a special damage type (none, headshot, melee, collision).
		Previously, this was the only data that was used to determine if a dead body ragdolled immediately or not.
		These filters should be pretty self-explanatory.

		The second level of filtering is the damage reporting info.
		This includes every weapon as well as general categories like melee and explosions.
		You should probably only use this to filter for specific weapons and ignore those categories because they
		are somewhat redundant with the first level of filtering.
		
		The last level of filtering is a velocity gate.
		If the biped being killed is traveling faster than this value, then the specified death program will be used.
		When there is more than one velocity gate, the largest one will be used.

		The output of the filtering system (which is part of the last level of filtering) is a death program and a scale value.
		The death programs are (animate then ragdoll, headshot ragdoll program, melee ragdoll program, default ragdoll program).
		The scale value only affects the ragdoll programs, not the animation.
		If the scale value is 0, then the object's default acceleration scale will be used.
	
	Headshot ragdoll program:
		Accelerates the body upwards and torques it back in the direction the damage came from.
		Scales the effect based on the dying biped's speed and direction relative to damage

	Melee ragdoll program:
		Accelerates ragdoll nodes in the direction of damage, applying more acceleration to the bodies closer to the point of impact.
		Also torques the body from the point of impact.

	Default ragdoll program:
		Similar to melee program, but torque is different depending on how far from the center of mass the killing blow came from.

	The headshot program is good for, well, headshots; the melee program is good for melees and collisions and possibly shotguns; and the default program is good for mostly everything else.

Inheritance:

Currently there is only one level of inheritance for each of the first two filters.  If the type of death was collision but none of the collision filters match, then it will search through "none" as well.  For the second level, if there is a filter for the weapon type but the velocity gate didn't match, it will search though "the guardians" as well.  The second filtering level looks like it has a lot of opportunity for inheritance relationships, but I didn't want to implement any without getting some input on what those should be.
*/

#pragma once

#include <cseries/cseries.h>
#include <datatypes/enum.h>
#include <datatypes/flags.h>
#include <math/real_math.h>
#include <tag_files/string_ids.h>
#include <tag_files/tag_groups.h>
#include <haloreach/objects/damage_new.h>

/* ---------- constants */

constexpr tag k_biped_death_program_selector_group_tag = 'bdpd';

/* ---------- types */

enum e_death_program_special_type
{
	_death_program_special_type_none,
	_death_program_special_type_headshot,
	_death_program_special_type_melee,
	_death_program_special_type_collision,
	_death_program_special_type_assassination,
	_death_program_special_type_shoulderbash,
	_death_program_special_type_groundpound,
	k_number_of_death_program_special_types
};

enum e_death_program_type
{
	_death_program_type_animate_then_ragdoll,
	_death_program_type_default_ragdoll,
	_death_program_type_headshot_ragdoll,
	_death_program_type_melee_ragdoll,
	_death_program_type_powered_ragdoll,
	_death_program_type_vehicle_ragdoll,
	k_number_of_death_program_types
};

struct s_death_program_velocity_gate
{
	real animated_length;
	c_enum<e_death_program_type, long> program_type;
	real acceleration;
	string_id death_animation_stance;
};
static_assert(sizeof(s_death_program_velocity_gate) == 0x10);

struct s_death_program_damage_reporting
{
	c_enum<e_damage_reporting_type, long> reporting_type;
	c_typed_tag_block<s_death_program_velocity_gate> velocity;
};
static_assert(sizeof(s_death_program_damage_reporting) == 0x10);

struct s_death_program_selector_special
{
	c_enum<e_death_program_special_type, long> special_type;
	c_typed_tag_block<s_death_program_damage_reporting> damage_type;
};
static_assert(sizeof(s_death_program_selector_special) == 0x10);

struct s_biped_death_program_selector
{
	s_tag_reference parent; // 'bdpd'
	c_typed_tag_block<s_death_program_selector_special> special_type;
};
static_assert(sizeof(s_biped_death_program_selector) == 0x1C);
