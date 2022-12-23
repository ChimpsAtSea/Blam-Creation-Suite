#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/math/real_math.h>
#include <blamlib/tag_files/tag_groups.h>

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
