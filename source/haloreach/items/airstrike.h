#pragma once

#include <cseries/cseries.h>
#include <math/real_math.h>
#include <tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_airstrike_group_tag = 'airs';

/* ---------- types */

struct s_airstrike_battery
{
	real launch_radius; // each shot will be fired with a random offset in this radius in the x/y plane above the target location
	real launch_z_height; // strike will be launched at this plane height above the target location
	real launch_warmup; // seconds to wait before launching the strike
	real launch_arrival; // seconds to wait until the launch site marker is removed
	real launch_cooldown; // seconds to wait before the next launch will be ready
	real launch_duration; // how long a launch should take to fire all rounds
	long shots_per_launch; // number of rounds to fire per launch
	long default_shot_count; // default number of rounds in the battery
	s_tag_reference fire_effect; // the effect that will be created when the strike fires
	c_typed_tag_block<s_real_point2d> fire_offsets; // offsets on the x/y plane from the sky the strike fires from
	s_tag_reference affected_weapon; // the weapon affected by the strike
};
static_assert(sizeof(s_airstrike_battery) == 0x4C);

struct s_airstrike_definition
{
	c_typed_tag_block<s_airstrike_battery> batteries;
};
static_assert(sizeof(s_airstrike_definition) == 0xC);
