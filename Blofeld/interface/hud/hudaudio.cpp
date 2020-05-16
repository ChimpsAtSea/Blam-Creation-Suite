#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(hud_unit_sound_block, 1)
{
	FIELD( _field_block, "Hud audio cues", &hud_unit_sound_cue_block ),
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

TAG_BLOCK(hud_unit_sound_cue_block, k_maximumHudUnitSoundCues)
{
	FIELD( _field_tag_reference, "sound^" ),
	FIELD( _field_long_flags, "latched to" ),
	FIELD( _field_real, "scale" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

