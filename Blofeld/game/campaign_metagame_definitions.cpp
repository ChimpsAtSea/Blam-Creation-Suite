#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(campaign_metagame_bucket_type_enum, 44)
	{
		OPTION("brute"),
		OPTION("grunt"),
		OPTION("jackel"),
		OPTION("skirmisher"),
		OPTION("marine"),
		OPTION("spartan"),
		OPTION("bugger"),
		OPTION("hunter"),
		OPTION("flood_infection"),
		OPTION("flood_carrier"),
		OPTION("flood_combat"),
		OPTION("flood_pure"),
		OPTION("sentinel"),
		OPTION("elite"),
		OPTION("engineer"),
		OPTION("mule"),
		OPTION("turret"),
		OPTION("mongoose"),
		OPTION("warthog"),
		OPTION("scorpion"),
		OPTION("hornet"),
		OPTION("pelican"),
		OPTION("revenant"),
		OPTION("seraph"),
		OPTION("shade"),
		OPTION("watchtower"),
		OPTION("ghost"),
		OPTION("chopper"),
		OPTION("mauler"),
		OPTION("wraith"),
		OPTION("banshee"),
		OPTION("phantom"),
		OPTION("scarab"),
		OPTION("guntower"),
		OPTION("tuning_fork"),
		OPTION("broadsword"),
		OPTION("mammoth"),
		OPTION("lich"),
		OPTION("mantis"),
		OPTION("wasp"),
		OPTION("phaeton"),
		OPTION("bishop"),
		OPTION("knight"),
		OPTION("pawn"),
	};

	TAG_ENUM(campaign_metagame_bucket_class_enum, 8)
	{
		OPTION("infantry"),
		OPTION("leader"),
		OPTION("hero"),
		OPTION("specialist"),
		OPTION("light vehicle"),
		OPTION("heavy vehicle"),
		OPTION("giant vehicle"),
		OPTION("standard vehicle"),
	};

	TAG_ENUM(campaign_metagame_bucket_type_with_none_enum, 45)
	{
		OPTION("any"),
		OPTION("brute"),
		OPTION("grunt"),
		OPTION("jackel"),
		OPTION("skirmisher"),
		OPTION("marine"),
		OPTION("spartan"),
		OPTION("bugger"),
		OPTION("hunter"),
		OPTION("flood_infection"),
		OPTION("flood_carrier"),
		OPTION("flood_combat"),
		OPTION("flood_pure"),
		OPTION("sentinel"),
		OPTION("elite"),
		OPTION("engineer"),
		OPTION("mule"),
		OPTION("turret"),
		OPTION("mongoose"),
		OPTION("warthog"),
		OPTION("scorpion"),
		OPTION("hornet"),
		OPTION("pelican"),
		OPTION("revenant"),
		OPTION("seraph"),
		OPTION("shade"),
		OPTION("watchtower"),
		OPTION("ghost"),
		OPTION("chopper"),
		OPTION("mauler"),
		OPTION("wraith"),
		OPTION("banshee"),
		OPTION("phantom"),
		OPTION("scarab"),
		OPTION("guntower"),
		OPTION("tuning_fork"),
		OPTION("broadsword"),
		OPTION("mammoth"),
		OPTION("lich"),
		OPTION("mantis"),
		OPTION("wasp"),
		OPTION("phaeton"),
		OPTION("bishop"),
		OPTION("knight"),
		OPTION("pawn"),
	};

	TAG_ENUM(campaign_metagame_bucket_class_with_none_enum, 9)
	{
		OPTION("any"),
		OPTION("infantry"),
		OPTION("leader"),
		OPTION("hero"),
		OPTION("specialist"),
		OPTION("light vehicle"),
		OPTION("heavy vehicle"),
		OPTION("giant vehicle"),
		OPTION("standard vehicle"),
	};

	TAG_ENUM(campaign_metagame_bucket_flags, 1)
	{
		OPTION("only counts with riders"),
	};

	TAG_BLOCK(campaign_metagame_bucket_block, 1)
	{
		FIELD( _field_byte_flags, "flags", &campaign_metagame_bucket_flags ),
		FIELD( _field_char_enum, "type", &campaign_metagame_bucket_type_enum ),
		FIELD( _field_char_enum, "class", &campaign_metagame_bucket_class_enum ),
		FIELD( _field_pad, "pad0", 1 ),
		FIELD( _field_short_integer, "point count" ),
		FIELD( _field_pad, "pad1", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(campaign_metagame_globals_block, 1)
	{
		FIELD( _field_block, "styles", &campaign_metagame_style_type_block_block ),
		FIELD( _field_block, "difficulty", &campaign_metagame_difficulty_scale_block_block ),
		FIELD( _field_block, "skulls{Primary Skulls}", &campaign_metagame_skull_block_block ),
		FIELD( _field_long_integer, "friendly_death_point_count" ),
		FIELD( _field_long_integer, "player_death_point_count" ),
		FIELD( _field_long_integer, "player_betrayal_point_count" ),
		FIELD( _field_real, "transient score time{multi kill window}:s#how long does transient score stay onscreen" ),
		FIELD( _field_real, "EMP kill window#time after taking a guys shields down with emp damage you have to get the emp kill bonus (seconds)" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(campaign_metagame_style_type_block, 100)
	{
		FIELD( _field_string_id, "incident name^" ),
		FIELD( _field_real, "style multiplier" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(campaign_metagame_difficulty_scale_block, k_campaign_difficulty_levels_count)
	{
		FIELD( _field_real, "difficulty multiplier" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(campaign_metagame_skull_block, k_game_skull_count)
	{
		FIELD( _field_real, "difficulty multiplier" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(campaign_metagame_scenario_block, 1)
	{
		FIELD( _field_real, "par score" ),
		FIELD( _field_block, "time bonuses", &campaign_metagame_scenario_bonuses_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(campaign_metagame_scenario_bonuses_block, k_maximum_campaign_metagame_scenario_completion_bonus_count)
	{
		FIELD( _field_real, "time#if you finish in under this time you get the following bonus" ),
		FIELD( _field_real, "score multiplier" ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

