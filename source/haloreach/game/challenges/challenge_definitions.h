#pragma once

#include <cseries/cseries.h>
#include <datatypes/enum.h>
#include <datatypes/flags.h>
#include <math/color_math.h>
#include <math/real_math.h>
#include <tag_files/string_ids.h>
#include <tag_files/tag_groups.h>
#include <haloreach/game/game.h>

/* ---------- constants */

constexpr tag k_challenge_globals_group_tag = 'chdg';

/* ---------- types */

enum e_challenge_category
{
	_challenge_category_bounties,
	_challenge_category_weekly,
	_challenge_category_campaign,
	_challenge_category_firefight,
	_challenge_category_multiplayer,
	k_number_of_challenge_categories
};

enum e_challenge_requirement
{
	_challenge_requirement_win_mp_game_bit,
	_challenge_requirement_complete_campaign_mission_bit,
	_challenge_requirement_play_mp_game_bit,
	_challenge_requirement_have_open_nat_bit,
	_challenge_requirement_complete_x_daily_challenges_bit,
	_challenge_requirement_complete_weekly_challenge_bit,
	_challenge_requirement_complete_all_daily_challenges_bit,
	_challenge_requirement_share_a_local_clipped_film_bit,
	_challenge_requirement_link_gamertag_to_bungie_net_bit,
	_challenge_requirement_customize_armor_bit,
	_challenge_requirement_scoring_enabled_bit,
	k_number_of_challenge_requirements
};

enum e_challenge_map_type_flags
{
	_challenge_map_type_campaign_bit,
	_challenge_map_type_firefight_or_multiplayer_bit,
	k_number_of_challenge_map_type_flags
};

enum e_challenge_player_count_flags
{
	_challenge_player_count_solo_bit,
	_challenge_player_count_cooperative_bit,
	k_number_of_challenge_player_count_flags
};

struct s_challenge_definition
{
	string_id name;
	string_id description;
	long unknown08;
	string_id secondary_description;
	string_id complete_message;
	long number_required;
	long credits_earned;
	long progress_amount;
	string_id in_progress_name;
	long unknown24;
	bool must_be_completed_in_one_match;
	char unknown29;
	short unknown2A;
	short unknown2C;
	c_flags<e_challenge_requirement, word> requirements;
	c_flags<e_game_mode, byte> game_modes;
	c_flags<e_challenge_map_type_flags, byte> map_types;
	c_flags<e_campaign_difficulty_level, byte> difficulty_levels;
	union
	{
		c_flags<e_challenge_player_count_flags, byte> player_counts;
		c_flags<e_campaign_difficulty_level, byte> secondary_difficulty_levels;
	};
	string_id map_name;
	long map_id;
	c_flags<e_game_skulls, dword> required_skulls;
	string_id reward_text;
	long deaths_allowed;
	long time_limitation;
	long number_of_firefight_waves;
};
static_assert(sizeof(s_challenge_definition) == 0x50);

struct s_challenge_category_definition
{
	string_id name;
	c_enum<e_challenge_category, char> category;
	char : 8;
	short : 16;
	c_typed_tag_block<s_challenge_definition> challenges;
};
static_assert(sizeof(s_challenge_category_definition) == 0x14);

struct s_challenge_globals_definition
{
	c_typed_tag_block<s_challenge_category_definition> categories;
};
static_assert(sizeof(s_challenge_globals_definition) == 0xC);
