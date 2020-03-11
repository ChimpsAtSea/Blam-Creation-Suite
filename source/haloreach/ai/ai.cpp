#include <haloreach/ai/ai.h>
#include <tag_files/tag_groups.h>

/* ---------- definitions */

TAG_ENUM(
    g_ai_sound_volume_enum,
    k_number_of_ai_sound_volumes)
{
    { "silent", _ai_sound_volume_silent },
    { "medium", _ai_sound_volume_medium },
    { "loud", _ai_sound_volume_loud },
    { "shout", _ai_sound_volume_shout },
    { "quiet", _ai_sound_volume_quiet },
};
