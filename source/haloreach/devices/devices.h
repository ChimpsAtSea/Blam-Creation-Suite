#pragma once

#include <cseries/cseries.h>
#include <math/real_math.h>
#include <memory/static_arrays.h>
#include <haloreach/objects/object_definitions.h>
#include <tag_files/tag_groups.h>

/* ---------- constants */

enum
{
    k_device_group_tag = 'devi'
};

/* ---------- types */

enum e_device_flags
{
    _device_position_loops_bit,
    _device_use_multiplayer_boundary_bit,
    _device_allow_interpolation_bit,
    _device_allow_attached_players_bit,
    _device_control_uses_parent_interact_scripts_bit,
    _device_requires_line_of_sight_for_interaction_bit,
    _device_only_active_when_parent_is_hostile_bit,
    _device_is_targetable_bit,
    _device_ignore_important_work_just_for_vs_bit,
    _device_huge_device_bit,
    k_number_of_device_flags
};

enum e_device_lightmap_flags
{
    _device_dont_use_in_lightmap_bit,
    _device_dont_use_in_lightprobe_bit,
    k_number_of_device_lightmap_flags
};

struct s_device_definition : s_object_definition
{
    c_flags<e_device_flags, long> device_flags;
    real power_transition_time;
    real power_acceleration_time;
    real position_transition_time;
    real position_acceleration_time;
    real depowered_position_transition_time;
    real depowered_position_acceleration_time;
    c_flags<e_device_lightmap_flags, word> lightmap_flags;
    short : 16;
    s_tag_reference open;
    s_tag_reference close;
    s_tag_reference opened;
    s_tag_reference closed;
    s_tag_reference depowered;
    s_tag_reference repowered;
    real delay_time;
    s_tag_reference delay_effect;
    real automatic_activation_radius;
};
static_assert(sizeof(s_device_definition) == sizeof(s_object_definition) + 0x98);

/* ---------- globals */

extern s_tag_reference_definition g_device_effect_sound_reference;
extern s_tag_group g_device_group;
