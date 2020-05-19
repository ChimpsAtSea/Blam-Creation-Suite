#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(hud_unit_sound_cue_block, k_maximumHudUnitSoundCues)
	{
		{ _field_tag_reference, "sound^", &global_sound_and_looping_sound_reference },
		{ _field_long_flags, "latched to", &hud_sound_cue_flags },
		{ _field_real, "scale" },
		{ _field_terminator }
	};

	TAG_BLOCK(hud_unit_sound_block, 1)
	{
		{ _field_block, "Hud audio cues", &hud_unit_sound_cue_block_block },
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
		{ _field_terminator }
	};

	STRINGS(hud_sound_cue_flags)
	{
		"health recharging",
		"health minor damaged",
		"health major damaged",
		"health critical damaged",
		"health minor",
		"health major",
		"health critical",
		"shield recharging",
		"shield minor damaged",
		"shield major damaged",
		"shield critical damaged",
		"shield minor",
		"shield major",
		"shield critical",
		"player tracked",
		"player locked"
	};
	STRING_LIST(hud_sound_cue_flags, hud_sound_cue_flags_strings, _countof(hud_sound_cue_flags_strings));

} // namespace blofeld

