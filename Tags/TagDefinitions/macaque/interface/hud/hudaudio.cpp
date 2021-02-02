#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define HUD_UNIT_SOUND_BLOCK_ID { 0xC7767088, 0x7D904BD8, 0x8174AD02, 0x4421D182 }
	TAG_BLOCK(
		hud_unit_sound_block,
		"hud_unit_sound_block",
		1,
		"HudUnitSoundDefinitions",
		HUD_UNIT_SOUND_BLOCK_ID)
	{
		{ _field_block, "Hud audio cues", &hud_unit_sound_cue_block },
		FIELD_CUSTOM("health thresholds", nullptr, _field_id_function_group_begin),
		{ _field_real, "health minor" },
		{ _field_real, "health major" },
		{ _field_real, "health critical" },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		FIELD_CUSTOM("shield thresholds", nullptr, _field_id_function_group_begin),
		{ _field_real, "shield minor" },
		{ _field_real, "shield major" },
		{ _field_real, "shield critical" },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		{ _field_terminator }
	};

	#define HUD_UNIT_SOUND_CUE_BLOCK_ID { 0xDCDD571F, 0xE87C4C5F, 0xB5FB4306, 0x032243B3 }
	TAG_BLOCK(
		hud_unit_sound_cue_block,
		"hud_unit_sound_cue_block",
		k_maximumHudUnitSoundCues,
		"HudUnitSoundCueDefinition",
		HUD_UNIT_SOUND_CUE_BLOCK_ID)
	{
		{ _field_tag_reference, "sound", &global_sound_and_looping_sound_reference },
		{ _field_long_flags, "latched to", &hud_sound_cue_flags },
		{ _field_real, "scale" },
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

} // namespace macaque

} // namespace blofeld

