#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/math/real_math.h>
#include <blamlib/tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_collision_damage_group_tag = 'cddf';

/* ---------- types */

struct s_collision_damage_definition
{
    /* ------ Applying Collision Damage:
        for things that want to cause more or less collision damage */

    real apply_collision_damage_scale;
    real friendly_apply_collision_damage_scale;

    /* ------ Game Collision Damage Parameters:
        0 - means take default value from globals.globals */

    real minimum_velocity_for_game_damage;
    s_tag_function game_collision_damage_function;
    real_bounds game_acceleration;

    /* ------ Applying Absolute Collision Damage:
        for things that want to cause more or less collision damage */

    real apply_absolute_collision_damage_scale;
    real friendly_apply_absolute_collision_damage_scale;

    /* ------ Absolute Collision Damage Parameters:
        0 - means take default value from globals.globals */

    real minimum_velocity_for_absolute_damage;
    s_tag_function absolute_collision_damage_function;
    real_bounds absolute_acceleration;
};
static_assert(sizeof(s_collision_damage_definition) == 0x50);
