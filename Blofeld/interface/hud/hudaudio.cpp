#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(hud_unit_sound, 1)
{
	{ _field_block, "Hud audio cues", &hud_unit_sound_cue_block },
	{ _field_custom, "health thresholds" },
	{ _field_real, "health minor" },
	{ _field_real, "health major" },
	{ _field_real, "health critical" },
	{ _field_custom },
	{ _field_custom, "shield thresholds" },
	{ _field_real, "shield minor" },
	{ _field_real, "shield major" },
	{ _field_real, "shield critical" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_BLOCK(hud_unit_sound_cue, k_maximumHudUnitSoundCues)
{
	{ _field_tag_reference, "sound^" },
	{ _field_long_flags, "latched to" },
	{ _field_real, "scale" },
	{ _field_terminator },
};

} // namespace blofeld

