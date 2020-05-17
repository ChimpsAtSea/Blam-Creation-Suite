#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(global_achievement_enum, 49)
	{
		OPTION("m10_complete"),
		OPTION("m20_complete"),
		OPTION("m30_complete"),
		OPTION("m60_complete"),
		OPTION("m40_complete"),
		OPTION("m70_complete"),
		OPTION("m80_complete"),
		OPTION("m90_complete"),
		OPTION("camp_normal_complete"),
		OPTION("camp_heroic_complete"),
		OPTION("camp_legendary_complete"),
		OPTION("camp_legendary_solo_complete"),
		OPTION("camp_heroic_3skulls_complete"),
		OPTION("camp_coop_mission_complete"),
		OPTION("camp_coop_complete"),
		OPTION("terminal_1"),
		OPTION("terminal_all"),
		OPTION("m10_special"),
		OPTION("m20_special"),
		OPTION("m30_special"),
		OPTION("m60_special"),
		OPTION("m40_special"),
		OPTION("m70_special"),
		OPTION("m80_special"),
		OPTION("m90_special"),
		OPTION("earn_rank_005"),
		OPTION("earn_rank_020"),
		OPTION("wargames_win_5"),
		OPTION("wargames_win_20"),
		OPTION("spartan_ops_mission_complete"),
		OPTION("spartan_ops_episode1_complete"),
		OPTION("spartan_ops_5episodes_complete"),
		OPTION("spartan_ops_legendary_solo_mission_complete"),
		OPTION("spops_1_special"),
		OPTION("spops_2_special"),
		OPTION("spops_3_special"),
		OPTION("spops_4_special"),
		OPTION("spops_5_special"),
		OPTION("challenge_complete"),
		OPTION("25_challenges_complete"),
		OPTION("change_armor"),
		OPTION("change_emblem"),
		OPTION("change_tag"),
		OPTION("change_pose"),
		OPTION("save_custom_map"),
		OPTION("save_custom_gametype"),
		OPTION("save_screenshot"),
		OPTION("save_filmclip"),
		OPTION("upload_to_fileshare"),
	};

	TAG_GROUP_FROM_BLOCK(achievements, ACHIEVEMENTS_TAG, achievements_block_block );

	TAG_BLOCK_FROM_STRUCT(achievements_block, 1, achievements_struct_definition_struct_definition );

	TAG_BLOCK(single_achievement_definition_block, k_maximum_achievements)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_char_enum, "type", &global_achievement_enum ),
		FIELD( _field_byte_flags, "difficulty", &global_campaign_difficulty_flags ),
		FIELD( _field_pad, "VJNOSNJER", 2 ),
		FIELD( _field_block, "restricted levels", &single_achievement_restricted_level_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(single_achievement_restricted_level_block, s_single_achivement_restricted_level_definition::k_maximum_count)
	{
		FIELD( _field_string_id, "level name^#Compared to map name in scenario" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(achievements_struct_definition)
{
		FIELD( _field_block, "achievement", &single_achievement_definition_block_block ),
		FIELD( _field_terminator )
};

} // namespace blofeld

