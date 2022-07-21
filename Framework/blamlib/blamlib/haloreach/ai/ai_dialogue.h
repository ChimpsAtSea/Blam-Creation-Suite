#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/datatypes/enum.h>
#include <blamlib/datatypes/flags.h>
#include <blamlib/math/real_math.h>
#include <blamlib/tag_files/string_ids.h>
#include <blamlib/tag_files/tag_groups.h>

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

enum e_vocalization_emotion
{
	_vocalization_emotion_none,
	_vocalization_emotion_happy,
	_vocalization_emotion_sad,
	_vocalization_emotion_angry,
	_vocalization_emotion_disgusted,
	_vocalization_emotion_scared,
	_vocalization_emotion_surprised,
	_vocalization_emotion_pain,
	_vocalization_emotion_shout,
	k_number_of_vocalization_emotions
};

enum e_vocalization_response_flags
{
	_vocalization_response_nonexclusive_bit,
	_vocalization_response_trigger_response_bit,
	k_number_of_vocalization_response_flags
};

enum e_vocalization_response_type
{
	_vocalization_response_type_friend,
	_vocalization_response_type_enemy,
	_vocalization_response_type_listener,
	_vocalization_response_type_joint,
	_vocalization_response_type_peer,
	_vocalization_response_type_leader,
	_vocalization_response_type_friend_infantry,
	k_number_of_vocalization_response_types
};

struct s_vocalization_definition;

struct s_vocalization_response
{
	string_id vocalization_name;
	c_flags<e_vocalization_response_flags, word, k_number_of_vocalization_response_flags> flags;
	c_tag_block_index<s_vocalization_definition, short> vocalization_index;
	c_enum<e_vocalization_response_type, short> response_type;
	short dialogue_index;
};
static_assert(sizeof(s_vocalization_response) == 0xC);

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
	c_enum<e_vocalization_animation_impulse, short> animation_impulse;
	short proxy_dialogue_index;
	real sound_repetition_delay; // minutes; minimum delay time between playing the same permutation
	real allowable_queue_delay; // seconds; how int to wait to actually start the vocalization
	real pre_voc_delay; // seconds; how int to wait to actually start the vocalization
	real notification_delay; // seconds; how int into the vocalization the AI should be notified
	real post_voc_delay; // seconds; how int speech is suppressed in the speaking unit after vocalizing
	real repeat_delay; // seconds; how int before the same vocalization can be repeated
	real weight; // [0-1] inherent weight of this vocalization
	real speaker_freeze_time; // speaker won't move for the given amount of time
	real listener_freeze_time; // listener won't move for the given amount of time (from start of vocalization)
	c_enum<e_vocalization_emotion, short> speaker_emotion;
	c_enum<e_vocalization_emotion, short> listener_emotion;
	real player_speaker_skip_fraction;
	real player_skip_fraction;
	real flood_skip_fraction;
	real skip_fraction;
	short mission_min_value; // the lowest mission id that we play this line in
	short mission_max_value; // the highest mission id that we play this line in
	string_id sample_line;
	c_typed_tag_block<s_vocalization_response> responses;
};
static_assert(sizeof(s_vocalization_definition) == 0x64);

enum e_vocalization_target
{
	_vocalization_target_subject,
	_vocalization_target_cause,
	_vocalization_target_friend,
	_vocalization_target_target,
	_vocalization_target_enemy,
	_vocalization_target_vehicle,
	_vocalization_target_joint,
	_vocalization_target_task,
	_vocalization_target_leader,
	_vocalization_target_joint2,
	_vocalization_target_clump,
	_vocalization_target_peer,
	_vocalization_target_none,
	k_number_of_vocalization_targets
};

enum e_vocalization_hostility
{
	_vocalization_hostility_none,
	_vocalization_hostility_self,
	_vocalization_hostility_neutral,
	_vocalization_hostility_friend,
	_vocalization_hostility_enemy,
	_vocalization_hostility_traitor,
	k_vocalization_hostility_count
};

enum e_vocalization_pattern_flags
{
	_vocalization_pattern_subject_visible_bit,
	_vocalization_pattern_cause_visible_bit,
	_vocalization_pattern_friends_present_bit,
	_vocalization_pattern_subject_is_speaker_s_target_bit,
	_vocalization_pattern_cause_is_speaker_s_target_bit,
	_vocalization_pattern_cause_is_player_or_speaker_is_player_ally_bit,
	_vocalization_pattern_cause_is_primary_player_ally_bit,
	_vocalization_pattern_cause_is_infantry_bit,
	_vocalization_pattern_subject_is_infantry_bit,
	_vocalization_pattern_speaker_is_infantry_bit,
	_vocalization_pattern_unknown10_bit,
	_vocalization_pattern_speaker_has_low_health_bit,
	_vocalization_pattern_cause_is_targeting_player_bit,
	_vocalization_pattern_unknown13_bit,
	_vocalization_pattern_unknown14_bit,
	_vocalization_pattern_unknown15_bit,
	k_number_of_vocalization_pattern_flags
};

struct s_vocalization_pattern
{
	short dialog_type;
	short vocalizations_index;
	string_id vocalization_name;
	c_enum<e_vocalization_target, short> speaker_type;
	c_enum<e_vocalization_target, short> listener_type;
	c_enum<e_vocalization_hostility, short> hostility;
	c_flags<e_vocalization_pattern_flags, word, k_number_of_vocalization_pattern_flags> flags;
	short cause_actor_type; // TODO
	short cause_type; // TODO
	string_id cause_ai_type_name;
	string_id cause_equipment_type_name;
	short speaker_object_type; // TODO
	short speaker_behavior; // TODO
	short danger_level; // TODO
	char speaker_subject_position; // TODO
	char speaker_cause_position; // TODO
	dword conditions;
	short spacial_relation; // TODO
	short damage_type; // TODO
	short game_type; // TODO
	short subject_actor_type; // TODO
	short subject_type; // TODO
	short unknown; // TODO
	string_id subject_ai_type_name;
};
static_assert(sizeof(s_vocalization_pattern) == 0x38);

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

	real_bounds strike_delay_bounds;
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
