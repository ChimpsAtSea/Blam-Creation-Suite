#pragma once

#include <cseries/cseries.h>
#include <datatypes/flags.h>
#include <tag_files/string_ids.h>
#include <tag_files/tag_groups.h>
#include <haloreach/game/game.h>

/* ---------- constants */

constexpr tag k_game_achievements_group_tag = 'achi';

/* ---------- types */

struct s_single_achievement_restricted_level
{
	string_id level_name;
};
static_assert(sizeof(s_single_achievement_restricted_level) == 0x4);

struct s_single_achievement_definition
{
	using t_difficulty_flags = c_flags<e_campaign_difficulty_level, byte, k_number_of_campaign_difficulty_levels>;

	string_id name;
	signed char type;
	t_difficulty_flags difficulty;
	short : 16;
	c_typed_tag_block<s_single_achievement_restricted_level> restricted_levels;
};
static_assert(sizeof(s_single_achievement_definition) == 0x14);

struct s_game_achievements
{
	c_typed_tag_block<s_single_achievement_definition> achievements;
};
static_assert(sizeof(s_game_achievements) == 0xC);
