#pragma once

#include <cseries/cseries.h>
#include <tag_files/string_ids.h>
#include <tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_game_avatar_awards_group_tag = 'avat';

/* ---------- types */

struct s_single_avatar_award_definition
{
	string_id name;
	long award_index;
};
static_assert(sizeof(s_single_avatar_award_definition) == 0x8);

struct s_game_avatar_awards
{
	c_typed_tag_block<s_single_avatar_award_definition> avatar_awards;
};
static_assert(sizeof(s_game_avatar_awards) == 0xC);
