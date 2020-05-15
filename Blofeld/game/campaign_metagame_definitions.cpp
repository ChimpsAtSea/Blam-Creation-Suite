#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(campaign_metagame_bucket, 1)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_char_enum, "type" ),
	FIELD( _field_char_enum, "class" ),
	FIELD( _field_pad, "pad0", 1 ),
	FIELD( _field_short_integer, "point count" ),
	FIELD( _field_pad, "pad1", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(campaign_metagame_globals, 1)
{
	FIELD( _field_block, "styles", &campaign_metagame_style_type_block ),
	FIELD( _field_block, "difficulty", &campaign_metagame_difficulty_scale_block ),
	FIELD( _field_block, "skulls{Primary Skulls}", &campaign_metagame_skull_block ),
	FIELD( _field_long_integer, "friendly_death_point_count" ),
	FIELD( _field_long_integer, "player_death_point_count" ),
	FIELD( _field_long_integer, "player_betrayal_point_count" ),
	FIELD( _field_real, "transient score time{multi kill window}:s#how long does transient score stay onscreen" ),
	FIELD( _field_real, "EMP kill window#time after taking a guys shields down with emp damage you have to get the emp kill bonus (seconds)" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(campaign_metagame_style_type, 100)
{
	FIELD( _field_string_id, "incident name^" ),
	FIELD( _field_real, "style multiplier" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(campaign_metagame_difficulty_scale, k_campaign_difficulty_levels_count)
{
	FIELD( _field_real, "difficulty multiplier" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(campaign_metagame_skull, k_game_skull_count)
{
	FIELD( _field_real, "difficulty multiplier" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(campaign_metagame_scenario, 1)
{
	FIELD( _field_real, "par score" ),
	FIELD( _field_block, "time bonuses", &campaign_metagame_scenario_bonuses_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(campaign_metagame_scenario_bonuses, k_maximum_campaign_metagame_scenario_completion_bonus_count)
{
	FIELD( _field_real, "time#if you finish in under this time you get the following bonus" ),
	FIELD( _field_real, "score multiplier" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

