#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(hud_unit_sound_cue_block, k_maximumHudUnitSoundCues)
	{
		FIELD( _field_tag_reference, "sound^" ),
		FIELD( _field_long_flags, "latched to", &hud_sound_cue_flags ),
		FIELD( _field_real, "scale" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(hud_unit_sound_block, 1)
	{
		FIELD( _field_block, "Hud audio cues", &hud_unit_sound_cue_block_block ),
		FIELD( _field_custom, "health thresholds" ),
		FIELD( _field_real, "health minor" ),
		FIELD( _field_real, "health major" ),
		FIELD( _field_real, "health critical" ),
		FIELD( _field_custom ),
		FIELD( _field_custom, "shield thresholds" ),
		FIELD( _field_real, "shield minor" ),
		FIELD( _field_real, "shield major" ),
		FIELD( _field_real, "shield critical" ),
		FIELD( _field_custom ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(hud_sound_cue_flags, 16)
	{
		OPTION("health recharging"),
		OPTION("health minor damaged"),
		OPTION("health major damaged"),
		OPTION("health critical damaged"),
		OPTION("health minor"),
		OPTION("health major"),
		OPTION("health critical"),
		OPTION("shield recharging"),
		OPTION("shield minor damaged"),
		OPTION("shield major damaged"),
		OPTION("shield critical damaged"),
		OPTION("shield minor"),
		OPTION("shield major"),
		OPTION("shield critical"),
		OPTION("player tracked"),
		OPTION("player locked"),
	};

} // namespace blofeld

