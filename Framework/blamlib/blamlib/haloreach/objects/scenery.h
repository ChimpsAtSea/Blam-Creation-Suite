#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/tag_files/tag_groups.h>
#include <blamlib/haloreach/game/campaign_metagame.h>
#include <blamlib/haloreach/objects/object_definitions.h>

/* ---------- constants */

constexpr tag k_scenery_group_tag = 'scen';

/* ---------- types */

enum e_scenery_pathfinding_policy
{
    _scenery_pathfinding_policy_cut_out,
    _scenery_pathfinding_policy_static,
    _scenery_pathfinding_policy_dynamic,
    _scenery_pathfinding_policy_none,
    k_number_of_scenery_pathfinding_policies
};

enum e_scenery_flags
{
    _scenery_not_physical_bit,
    _scenery_use_complex_activation_bit,
    k_number_of_scenery_flags
};

enum e_scenery_lightmapping_policy
{
    _scenery_lightmapping_policy_per_vertex,
    _scenery_lightmapping_policy_per_pixel,
    _scenery_lightmapping_policy_dynamic,
    k_number_of_scenery_lightmapping_policies
};

struct s_scenery_definition : s_object_definition
{
    c_enum<e_scenery_pathfinding_policy, short> pathfinding_policy;
    c_flags<e_scenery_flags, word> scenery_flags;
    c_enum<e_scenery_lightmapping_policy, short> lightmapping_policy;
    short : 16;
};
static_assert(sizeof(s_scenery_definition) == sizeof(s_object_definition) + 0x8);

struct s_scenario_scenery
{
    // TODO
};
