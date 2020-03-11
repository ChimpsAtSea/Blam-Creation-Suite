#pragma once

#include <cseries/cseries.h>
#include <math/real_math.h>
#include <tag_files/string_ids.h>
#include <tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_ai_dialogue_globals_group_tag = 'adlg';

/* ---------- types */

struct s_vocalization_definition
{
	// TODO
};

struct s_vocalization_pattern
{
	// TODO
};

struct s_ai_dialogue_data
{
	short start_index;
	short length;
};
static_assert(sizeof(s_ai_dialogue_data) == 0x4);

struct s_ai_dialogue_involuntary_data
{
	c_tag_block_index<s_vocalization_definition, short> vocalization;
	short : 16;
};
static_assert(sizeof(s_ai_dialogue_involuntary_data) == 0x4);

struct s_ai_dialogue_predicted_vocalization
{
	c_tag_block_index<s_vocalization_definition, long> vocalization;
};
static_assert(sizeof(s_ai_dialogue_predicted_vocalization) == 0x4);

struct s_ai_dialogue_globals
{
	/* ------ global timing */

	s_real_bounds strike_delay_bounds;
	real remind_delay;
	real cover_curse_chance;

	/* ------ player look settings:
		used to play look and look_longtime dialogue in campain and firefight */

	real player_look_max_distance;
	real player_look;
	real player_look_long_time;

	/* ------ spartan nearby search settings:
		this is used when checking if the player is with other spartan ais */

	real spartan_nearby_search_distance;

	/* ------ face friendly player distance:
		when talking to friendly players within this distance, if not in combat, we will turn to face them */

	real face_friendly_player_distance;

	/* ------ space dialogue effect */

	string_id space_dialogue_effect;

	/* ------ default stimulus suppressors:
		when these stimuli are active on an actor, default stimulus permutations will be suppressed */

	c_typed_tag_block<string_id> default_stimulus_suppressors;

	/* ------ import data */

	c_typed_tag_block<s_vocalization_definition> vocalizations;
	c_typed_tag_block<s_vocalization_pattern> patterns;
	s_tag_block unused;
	c_typed_tag_block<s_ai_dialogue_data> dialogue_data;
	c_typed_tag_block<s_ai_dialogue_involuntary_data> involuntary_data;
	c_typed_tag_block<s_ai_dialogue_predicted_vocalization> predicted_vocalizations;
};

/* ---------- globals */

extern s_tag_group g_ai_dialogue_globals_group;
