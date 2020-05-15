#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(campaign_metagame_bucket, 1)
{
	{ _field_byte_flags, "flags" },
	{ _field_char_enum, "type" },
	{ _field_char_enum, "class" },
	{ _field_pad, "pad0", 1 },
	{ _field_short_integer, "point count" },
	{ _field_pad, "pad1", 2 },
	{ _field_terminator },
};

TAG_BLOCK(campaign_metagame_globals, 1)
{
	{ _field_block, "styles", &campaign_metagame_style_type_block },
	{ _field_block, "difficulty", &campaign_metagame_difficulty_scale_block },
	{ _field_block, "skulls{Primary Skulls}", &campaign_metagame_skull_block },
	{ _field_long_integer, "friendly_death_point_count" },
	{ _field_long_integer, "player_death_point_count" },
	{ _field_long_integer, "player_betrayal_point_count" },
	{ _field_real, "transient score time{multi kill window}:s#how long does transient score stay onscreen" },
	{ _field_real, "EMP kill window#time after taking a guys shields down with emp damage you have to get the emp kill bonus (seconds)" },
	{ _field_terminator },
};

TAG_BLOCK(campaign_metagame_style_type, 100)
{
	{ _field_string_id, "incident name^" },
	{ _field_real, "style multiplier" },
	{ _field_terminator },
};

TAG_BLOCK(campaign_metagame_difficulty_scale, k_campaign_difficulty_levels_count)
{
	{ _field_real, "difficulty multiplier" },
	{ _field_terminator },
};

TAG_BLOCK(campaign_metagame_skull, k_game_skull_count)
{
	{ _field_real, "difficulty multiplier" },
	{ _field_terminator },
};

TAG_BLOCK(campaign_metagame_scenario, 1)
{
	{ _field_real, "par score" },
	{ _field_block, "time bonuses", &campaign_metagame_scenario_bonuses_block },
	{ _field_terminator },
};

TAG_BLOCK(campaign_metagame_scenario_bonuses, k_maximum_campaign_metagame_scenario_completion_bonus_count)
{
	{ _field_real, "time#if you finish in under this time you get the following bonus" },
	{ _field_real, "score multiplier" },
	{ _field_terminator },
};

} // namespace blofeld

