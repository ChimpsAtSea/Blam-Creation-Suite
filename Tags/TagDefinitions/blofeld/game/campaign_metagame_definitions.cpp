#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	#define CAMPAIGN_METAGAME_BUCKET_BLOCK_ID { 0x63D7EE66, 0xCFE44D6F, 0xBC5A8E71, 0x7128E562 }
	TAG_BLOCK(
		campaign_metagame_bucket_block,
		"campaign_metagame_bucket_block",
		1,
		"s_campaign_metagame_bucket",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMPAIGN_METAGAME_BUCKET_BLOCK_ID)
	{
		{ _field_byte_flags, "flags", &campaign_metagame_bucket_flags },
		{ _field_char_enum, "type", &campaign_metagame_bucket_type_enum },
		{ _field_char_enum, "class", &campaign_metagame_bucket_class_enum },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_short_integer, "point count" },
		FIELD_PAD("pad1", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define CAMPAIGN_METAGAME_GLOBALS_BLOCK_ID { 0x84D6CB38, 0x9F7147BA, 0x80478800, 0x00026D5C }
	TAG_BLOCK(
		campaign_metagame_globals_block,
		"campaign_metagame_globals_block",
		1,
		"s_campaign_metagame_globals",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CAMPAIGN_METAGAME_GLOBALS_BLOCK_ID)
	{
		{ _field_block, "styles", &campaign_metagame_style_type_block },
		{ _field_block, "difficulty", &campaign_metagame_difficulty_scale_block },
		{ _field_block, "skulls", MAKE_OLD_NAMES("Primary Skulls"), &campaign_metagame_skull_block },
		{ _field_long_integer, "friendly_death_point_count" },
		{ _field_long_integer, "player_death_point_count" },
		{ _field_long_integer, "player_betrayal_point_count" },
		{ _field_real, "transient score time", "how long does transient score stay onscreen", "s", MAKE_OLD_NAMES("multi kill window") },
		{ _field_real, "EMP kill window", "time after taking a guys shields down with emp damage you have to get the emp kill bonus (seconds)" },
		{ _field_terminator }
	};

	#define CAMPAIGN_METAGAME_STYLE_TYPE_BLOCK_ID { 0x5DFA1230, 0x8A3D4653, 0x9E93D875, 0xAFD34842 }
	TAG_BLOCK(
		campaign_metagame_style_type_block,
		"campaign_metagame_style_type_block",
		100,
		"s_campaign_metagame_style_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMPAIGN_METAGAME_STYLE_TYPE_BLOCK_ID)
	{
		{ _field_string_id, "incident name", FIELD_FLAG_INDEX },
		{ _field_real, "style multiplier" },
		{ _field_terminator }
	};

	#define CAMPAIGN_METAGAME_DIFFICULTY_SCALE_BLOCK_ID { 0x4C1DFA8F, 0x201E4EAA, 0xAD8B851B, 0x7D67E295 }
	TAG_BLOCK(
		campaign_metagame_difficulty_scale_block,
		"campaign_metagame_difficulty_scale_block",
		k_campaign_difficulty_levels_count,
		"s_campaign_metagame_difficulty",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMPAIGN_METAGAME_DIFFICULTY_SCALE_BLOCK_ID)
	{
		{ _field_real, "difficulty multiplier" },
		{ _field_terminator }
	};

	#define CAMPAIGN_METAGAME_SKULL_BLOCK_ID { 0x8F1530D9, 0xC5CC4C93, 0xA6739313, 0xD5C8BAAE }
	TAG_BLOCK(
		campaign_metagame_skull_block,
		"campaign_metagame_skull_block",
		k_game_skull_count,
		"s_campaign_metagame_skull_data",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMPAIGN_METAGAME_SKULL_BLOCK_ID)
	{
		{ _field_real, "difficulty multiplier" },
		{ _field_terminator }
	};

	#define CAMPAIGN_METAGAME_SCENARIO_BLOCK_ID { 0x59269CAB, 0x380A4488, 0x9D7D8B32, 0xD61CB01A }
	TAG_BLOCK(
		campaign_metagame_scenario_block,
		"campaign_metagame_scenario_block",
		1,
		"s_campaign_metagame_scenario",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CAMPAIGN_METAGAME_SCENARIO_BLOCK_ID)
	{
		{ _field_real, "par score" },
		{ _field_block, "time bonuses", &campaign_metagame_scenario_bonuses_block },
		{ _field_terminator }
	};

	#define CAMPAIGN_METAGAME_SCENARIO_BONUSES_BLOCK_ID { 0xDD111048, 0xEEC841D1, 0x860C878F, 0xD680F7F4 }
	TAG_BLOCK(
		campaign_metagame_scenario_bonuses_block,
		"campaign_metagame_scenario_bonuses_block",
		k_maximum_campaign_metagame_scenario_completion_bonus_count,
		"s_campaign_metagame_scenario_completion_bonus",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMPAIGN_METAGAME_SCENARIO_BONUSES_BLOCK_ID)
	{
		{ _field_real, "time", "if you finish in under this time you get the following bonus" },
		{ _field_real, "score multiplier" },
		{ _field_terminator }
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

