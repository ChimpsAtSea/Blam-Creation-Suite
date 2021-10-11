#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		achievements_group,
		ACHIEVEMENTS_TAG,
		nullptr,
		INVALID_TAG,
		achievements_block );

	TAG_BLOCK_FROM_STRUCT(
		achievements_block,
		"achievements_block",
		1,
		achievements_struct_definition);

	#define SINGLE_ACHIEVEMENT_DEFINITION_BLOCK_ID { 0x7549688B, 0xD7D74EDF, 0x92AC71EF, 0x573D94F5 }
	TAG_BLOCK(
		single_achievement_definition_block,
		"single_achievement_definition_block",
		k_maximum_achievements,
		"s_single_achievement_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SINGLE_ACHIEVEMENT_DEFINITION_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_char_enum, "type", &global_achievement_enum },
		{ _field_byte_flags, "difficulty", &global_campaign_difficulty_flags },
		FIELD_PAD_EX("VJNOSNJER", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "restricted levels", &single_achievement_restricted_level_block },
		{ _field_terminator }
	};

	#define SINGLE_ACHIEVEMENT_RESTRICTED_LEVEL_BLOCK_ID { 0x55CEF750, 0x51414598, 0x966B2F43, 0x4A6C23E5 }
	TAG_BLOCK(
		single_achievement_restricted_level_block,
		"single_achievement_restricted_level_block",
		s_single_achivement_restricted_level_definition::k_maximum_count,
		"s_single_achivement_restricted_level_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SINGLE_ACHIEVEMENT_RESTRICTED_LEVEL_BLOCK_ID)
	{
		{ _field_string_id, "level name", "Compared to map name in scenario", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define ACHIEVEMENTS_STRUCT_DEFINITION_ID { 0x21EA12AC, 0x29164C0A, 0x91892198, 0xD2724D89 }
	TAG_STRUCT(
		achievements_struct_definition,
		"achievements_struct_definition",
		"s_game_achievements_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ACHIEVEMENTS_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "achievement", &single_achievement_definition_block },
		{ _field_terminator }
	};

	STRINGS(global_achievement_enum)
	{
		"m10_complete",
		"m20_complete",
		"m30_complete",
		"m60_complete",
		"m40_complete",
		"m70_complete",
		"m80_complete",
		"m90_complete",
		"camp_normal_complete",
		"camp_heroic_complete",
		"camp_legendary_complete",
		"camp_legendary_solo_complete",
		"camp_heroic_3skulls_complete",
		"camp_coop_mission_complete",
		"camp_coop_complete",
		"terminal_1",
		"terminal_all",
		"m10_special",
		"m20_special",
		"m30_special",
		"m60_special",
		"m40_special",
		"m70_special",
		"m80_special",
		"m90_special",
		"earn_rank_005",
		"earn_rank_020",
		"wargames_win_5",
		"wargames_win_20",
		"spartan_ops_mission_complete",
		"spartan_ops_episode1_complete",
		"spartan_ops_5episodes_complete",
		"spartan_ops_legendary_solo_mission_complete",
		"spops_1_special",
		"spops_2_special",
		"spops_3_special",
		"spops_4_special",
		"spops_5_special",
		"challenge_complete",
		"25_challenges_complete",
		"change_armor",
		"change_emblem",
		"change_tag",
		"change_pose",
		"save_custom_map",
		"save_custom_gametype",
		"save_screenshot",
		"save_filmclip",
		"upload_to_fileshare"
	};
	STRING_LIST(global_achievement_enum, global_achievement_enum_strings, _countof(global_achievement_enum_strings));



} // namespace blofeld

