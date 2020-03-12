#pragma once

#include <cseries/cseries.h>
#include <datatypes/enum.h>
#include <datatypes/flags.h>
#include <math/real_math.h>
#include <tag_files/string_ids.h>
#include <tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_ai_dialogue_globals_group_tag = 'adlg';

/* ---------- types */

enum e_vocalization_priority
{
	_vocalization_priority_none,
	_vocalization_priority_autonomic,
	_vocalization_priority_recall,
	_vocalization_priority_idle,
	_vocalization_priority_comment,
	_vocalization_priority_idle_response,
	_vocalization_priority_postcombat,
	_vocalization_priority_combat,
	_vocalization_priority_status,
	_vocalization_priority_respond,
	_vocalization_priority_warn,
	_vocalization_priority_act,
	_vocalization_priority_react,
	_vocalization_priority_involuntary,
	_vocalization_priority_scream,
	_vocalization_priority_scripted,
	_vocalization_priority_death,
	k_number_of_vocalization_priorities
};

enum e_vocalization_flags
{
	_vocalization_immediate_bit,
	_vocalization_interrupt_bit,
	_vocalization_cancel_low_priority_bit,
	_vocalization_disable_dialogue_effect_bit,
	_vocalization_predict_facial_animations_bit,
	_vocalization_no_distance_check_exceptions_bit,
	k_number_of_vocalization_flags
};

enum e_vocalization_glance_behavior
{
	_vocalization_glance_behavior_none,
	_vocalization_glance_behavior_glance_subject_short,
	_vocalization_glance_behavior_glance_subject_long,
	_vocalization_glance_behavior_glance_cause_short,
	_vocalization_glance_behavior_glance_cause_long,
	_vocalization_glance_behavior_glance_friend_short,
	_vocalization_glance_behavior_glance_friend_long,
	k_number_of_vocalization_glance_behaviors
};

enum e_vocalization_perception_type
{
	_vocalization_perception_type_none,
	_vocalization_perception_type_speaker,
	_vocalization_perception_type_listener,
	k_number_of_vocalization_perception_types
};

enum e_vocalization_max_combat_status
{
	_vocalization_max_combat_status_asleep,
	_vocalization_max_combat_status_idle,
	_vocalization_max_combat_status_alert,
	_vocalization_max_combat_status_active,
	_vocalization_max_combat_status_uninspected,
	_vocalization_max_combat_status_definite,
	_vocalization_max_combat_status_certain,
	_vocalization_max_combat_status_visible,
	_vocalization_max_combat_status_clear_los,
	_vocalization_max_combat_status_dangerous,
	k_vocalization_max_combat_status_count
};

enum e_vocalization_animation_impulse
{
	_vocalization_animation_impulse_none,
	_vocalization_animation_impulse_shakefist,
	_vocalization_animation_impulse_cheer,
	_vocalization_animation_impulse_surprise_front,
	_vocalization_animation_impulse_surprise_back,
	_vocalization_animation_impulse_taunt,
	_vocalization_animation_impulse_brace,
	_vocalization_animation_impulse_point,
	_vocalization_animation_impulse_hold,
	_vocalization_animation_impulse_wave,
	_vocalization_animation_impulse_advance,
	_vocalization_animation_impulse_fallback,
	k_vocalization_animation_impulse_count
};

struct s_vocalization_definition
{
	string_id vocalization;
	c_tag_block_index<s_vocalization_definition, short> parent;
	c_enum<e_vocalization_priority, short> priority;
	c_flags<e_vocalization_flags, dword, k_number_of_vocalization_flags> flags;
	c_enum<e_vocalization_glance_behavior, short> glance_behavior;
	c_enum<e_vocalization_glance_behavior, short> glance_recipient_behavior;
	c_enum<e_vocalization_perception_type, short> perception_type;
	c_enum<e_vocalization_max_combat_status, short> max_combat_status;
	// TODO: finish
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
static_assert(sizeof(s_ai_dialogue_globals) == 0x7C);

/* ---------- globals */

extern s_tag_group g_ai_dialogue_globals_group;
