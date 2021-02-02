#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(campaign_metagame_bucket_block, 1)
	{
		{ _field_legacy, _field_byte_flags, "flags", &campaign_metagame_bucket_flags },
		{ _field_legacy, _field_char_enum, "type", &campaign_metagame_bucket_type_enum },
		{ _field_legacy, _field_char_enum, "class", &campaign_metagame_bucket_class_enum },
		{ _field_legacy, _field_pad, "pad0", 1 },
		{ _field_legacy, _field_short_integer, "point count" },
		{ _field_legacy, _field_pad, "pad1", 2 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(campaign_metagame_style_type_block, 100)
	{
		{ _field_legacy, _field_string_id, "incident name^" },
		{ _field_legacy, _field_real, "style multiplier" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(campaign_metagame_difficulty_scale_block, k_campaign_difficulty_levels_count)
	{
		{ _field_legacy, _field_real, "difficulty multiplier" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(campaign_metagame_skull_block, k_game_skull_count)
	{
		{ _field_legacy, _field_real, "difficulty multiplier" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(campaign_metagame_globals_block, 1)
	{
		{ _field_legacy, _field_block, "styles", &campaign_metagame_style_type_block_block },
		{ _field_legacy, _field_block, "difficulty", &campaign_metagame_difficulty_scale_block_block },
		{ _field_legacy, _field_block, "skulls{Primary Skulls}", &campaign_metagame_skull_block_block },
		{ _field_legacy, _field_long_integer, "friendly_death_point_count" },
		{ _field_legacy, _field_long_integer, "player_death_point_count" },
		{ _field_legacy, _field_long_integer, "player_betrayal_point_count" },
		{ _field_legacy, _field_real, "transient score time{multi kill window}:s#how long does transient score stay onscreen" },
		{ _field_legacy, _field_real, "EMP kill window#time after taking a guys shields down with emp damage you have to get the emp kill bonus (seconds)" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(campaign_metagame_scenario_bonuses_block, k_maximum_campaign_metagame_scenario_completion_bonus_count)
	{
		{ _field_legacy, _field_real, "time#if you finish in under this time you get the following bonus" },
		{ _field_legacy, _field_real, "score multiplier" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(campaign_metagame_scenario_block, 1)
	{
		{ _field_legacy, _field_real, "par score" },
		{ _field_legacy, _field_block, "time bonuses", &campaign_metagame_scenario_bonuses_block_block },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(campaign_metagame_bucket_type_enum)
	{
		"brute",
		"grunt",
		"jackel",
		"skirmisher",
		"marine",
		"spartan",
		"bugger",
		"hunter",
		"flood_infection",
		"flood_carrier",
		"flood_combat",
		"flood_pure",
		"sentinel",
		"elite",
		"engineer",
		"mule",
		"turret",
		"mongoose",
		"warthog",
		"scorpion",
		"hornet",
		"pelican",
		"revenant",
		"seraph",
		"shade",
		"watchtower",
		"ghost",
		"chopper",
		"mauler",
		"wraith",
		"banshee",
		"phantom",
		"scarab",
		"guntower",
		"tuning_fork",
		"broadsword",
		"mammoth",
		"lich",
		"mantis",
		"wasp",
		"phaeton",
		"bishop",
		"knight",
		"pawn"
	};
	STRING_LIST(campaign_metagame_bucket_type_enum, campaign_metagame_bucket_type_enum_strings, _countof(campaign_metagame_bucket_type_enum_strings));

	STRINGS(campaign_metagame_bucket_class_enum)
	{
		"infantry",
		"leader",
		"hero",
		"specialist",
		"light vehicle",
		"heavy vehicle",
		"giant vehicle",
		"standard vehicle"
	};
	STRING_LIST(campaign_metagame_bucket_class_enum, campaign_metagame_bucket_class_enum_strings, _countof(campaign_metagame_bucket_class_enum_strings));

	STRINGS(campaign_metagame_bucket_type_with_none_enum)
	{
		"any",
		"brute",
		"grunt",
		"jackel",
		"skirmisher",
		"marine",
		"spartan",
		"bugger",
		"hunter",
		"flood_infection",
		"flood_carrier",
		"flood_combat",
		"flood_pure",
		"sentinel",
		"elite",
		"engineer",
		"mule",
		"turret",
		"mongoose",
		"warthog",
		"scorpion",
		"hornet",
		"pelican",
		"revenant",
		"seraph",
		"shade",
		"watchtower",
		"ghost",
		"chopper",
		"mauler",
		"wraith",
		"banshee",
		"phantom",
		"scarab",
		"guntower",
		"tuning_fork",
		"broadsword",
		"mammoth",
		"lich",
		"mantis",
		"wasp",
		"phaeton",
		"bishop",
		"knight",
		"pawn"
	};
	STRING_LIST(campaign_metagame_bucket_type_with_none_enum, campaign_metagame_bucket_type_with_none_enum_strings, _countof(campaign_metagame_bucket_type_with_none_enum_strings));

	STRINGS(campaign_metagame_bucket_class_with_none_enum)
	{
		"any",
		"infantry",
		"leader",
		"hero",
		"specialist",
		"light vehicle",
		"heavy vehicle",
		"giant vehicle",
		"standard vehicle"
	};
	STRING_LIST(campaign_metagame_bucket_class_with_none_enum, campaign_metagame_bucket_class_with_none_enum_strings, _countof(campaign_metagame_bucket_class_with_none_enum_strings));

	STRINGS(campaign_metagame_bucket_flags)
	{
		"only counts with riders"
	};
	STRING_LIST(campaign_metagame_bucket_flags, campaign_metagame_bucket_flags_strings, _countof(campaign_metagame_bucket_flags_strings));

} // namespace blofeld

