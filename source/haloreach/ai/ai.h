#pragma once

#include <cseries/cseries.h>
#include <math/real_math.h>
#include <tag_files/tag_groups.h>

/* ---------- types */

enum e_ai_sound_volume
{
    _ai_sound_volume_silent,
    _ai_sound_volume_medium,
    _ai_sound_volume_loud,
    _ai_sound_volume_shout,
    _ai_sound_volume_quiet,
    k_number_of_ai_sound_volumes
};

/* ---------- globals */

extern s_enum_definition g_ai_sound_volume_enum;

/* ---------- prototypes/AI.CPP */

void ai_initialize();
void ai_dispose();
void ai_update();

void ai_get_center_of_mass(long object_index, s_real_point3d *center_of_mass);
