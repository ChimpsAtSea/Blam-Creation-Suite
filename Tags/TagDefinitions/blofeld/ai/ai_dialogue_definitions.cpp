#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		ai_dialogue_globals_group,
		AI_DIALOGUE_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		ai_dialogue_globals_block );

	TAG_BLOCK_FROM_STRUCT(
		ai_dialogue_globals_block,
		"ai_dialogue_globals_block",
		1,
		ai_dialogue_globals_struct_definition);

	#define DEFAULT_STIMULUS_SUPPRESSOR_BLOCK_STRUCT_ID { 0x48735579, 0x26B849B0, 0xB08B966D, 0xB3EE55B0 }
	TAG_BLOCK(
		default_stimulus_suppressor_block,
		"default_stimulus_suppressor_block",
		4,
		"string_id",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DEFAULT_STIMULUS_SUPPRESSOR_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "stimulus", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define VOCALIZATION_DEFINITIONS_BLOCK_ID { 0xEFA010A4, 0x3EA148E6, 0xA44C41E0, 0x7FA151D5 }
	TAG_BLOCK(
		vocalization_definitions_block,
		"vocalization_definitions_block",
		500,
		"vocalization",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		VOCALIZATION_DEFINITIONS_BLOCK_ID)
	{
		{ _field_string_id, "vocalization", FIELD_FLAG_INDEX },
		{ _field_short_block_index, "parent index", FIELD_FLAG_READ_ONLY, &vocalization_definitions_block },
		{ _field_enum, "priority", &priority_enum },
		{ _field_long_flags, "flags", &vocalization_flags_definition },
		{ _field_enum, "glance behavior", "how does the speaker of this vocalization direct his gaze?", &glance_type_enum },
		{ _field_enum, "glance recipient behavior", "how does someone who hears me behave?", &glance_type_enum },
		{ _field_enum, "perception type", &perception_type_enum },
		{ _field_enum, "max combat status", &combat_status_enum },
		{ _field_enum, "animation impulse", &dialogue_animation_enum },
		{ _field_short_integer, "proxy dialogue index" },
		{ _field_real, "sound repetition delay", "Minimum delay time between playing the same permutation", "minutes" },
		{ _field_real, "allowable queue delay", "How long to wait to actually start the vocalization", "seconds" },
		{ _field_real, "pre voc. delay", "How long to wait to actually start the vocalization", "seconds" },
		{ _field_real, "notification delay", "How long into the vocalization the AI should be notified", "seconds" },
		{ _field_real, "post voc. delay", "How long speech is suppressed in the speaking unit after vocalizing", "seconds" },
		{ _field_real, "repeat delay", "How long before the same vocalization can be repeated", "seconds" },
		{ _field_real, "weight", "Inherent weight of this vocalization", nullptr, "[0-1]" },
		{ _field_real, "speaker freeze time", "speaker won't move for the given amount of time" },
		{ _field_real, "listener freeze time", "listener won't move for the given amount of time (from start of vocalization)" },
		{ _field_enum, "speaker emotion", &dialogue_emotion_enum },
		{ _field_enum, "listener emotion", &dialogue_emotion_enum },
		{ _field_real, "player speaker skip fraction" },
		{ _field_real, "player skip fraction" },
		{ _field_real, "flood skip fraction" },
		{ _field_real, "skip fraction" },
		{ _field_short_integer, "mission min value", "The lowest mission id that we play this line in" },
		{ _field_short_integer, "mission max value", "The highest mission id that we play this line in" },
		{ _field_string_id, "Sample line" },
		{ _field_block, "reponses", &response_block },
		{ _field_terminator }
	};

	#define RESPONSE_BLOCK_ID { 0x0D94F560, 0x7A584446, 0x8346DEA4, 0x8A08206A }
	TAG_BLOCK(
		response_block,
		"response_block",
		20,
		"response",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RESPONSE_BLOCK_ID)
	{
		{ _field_string_id, "vocalization name" },
		{ _field_word_flags, "flags", &response_flags },
		{ _field_short_integer, "vocalization index", FIELD_FLAG_READ_ONLY },
		{ _field_enum, "response type", &response_type_enum },
		{ _field_short_integer, "dialogue index (import)", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define VOCALIZATION_PATTERNS_BLOCK_ID { 0xD957FA41, 0xCD6C43A7, 0x9D2BA7B7, 0xC3ECCB8C }
	TAG_BLOCK(
		vocalization_patterns_block,
		"vocalization_patterns_block",
		1000,
		"vocalization_pattern",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		VOCALIZATION_PATTERNS_BLOCK_ID)
	{
		{ _field_enum, "dialogue type", &dialogue_names_enum },
		{ _field_short_integer, "vocalization index" },
		{ _field_string_id, "vocalization name" },
		{ _field_enum, "speaker type", &speaker_type_enum },
		{ _field_enum, "listener/target", "who/what am I speaking to/of?", &speaker_type_enum },
		{ _field_enum, "hostility", "The relationship between the subject and the cause", &hostility_enum },
		{ _field_word_flags, "flags", &pattern_flags },
		FIELD_EXPLANATION_EX("Cause", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_enum, "cause actor type", &actor_type_enum },
		{ _field_enum, "cause type", &dialogue_object_types_enum },
		{ _field_string_id, "cause ai type name" },
		{ _field_string_id, "cause equipment type name" },
		FIELD_EXPLANATION_EX("Speaker", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_enum, "speaker object type", &dialogue_object_types_enum },
		{ _field_enum, "speaker behavior", &speaker_behavior_enum },
		{ _field_enum, "danger level", "Speaker must have danger level of at least this much", &danger_enum },
		{ _field_char_enum, "speaker/subject position", &spatial_relation_enum },
		{ _field_char_enum, "speaker/cause position", &spatial_relation_enum },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown" }, // likely a block index. #todo that seems sketchy - Squaresome

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_long_flags, "Conditions", &dialogue_condition_flags },
		
		FIELD_EXPLANATION_EX("Matching", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_enum, "spatial relation", "with respect to the subject, the cause is ...", &spatial_relation_enum },
		{ _field_enum, "damage type", &damage_enum },
		{ _field_enum, "game type", &game_type_enum },
		FIELD_EXPLANATION_EX("Subject", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_enum, "subject actor type", &actor_type_enum },
		{ _field_enum, "subject type", &dialogue_object_types_enum },
		FIELD_PAD_EX("post-subject-type-pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_string_id, "subject ai type name" },
		{ _field_terminator }
	};

	#define DIALOGUE_DATA_BLOCK_ID { 0xFCF21C42, 0x169B4D90, 0x98F06443, 0xC4EAC71E }
	TAG_BLOCK(
		dialogue_data_block,
		"dialogue_data_block",
		k_dialogue_type_count,
		"dialogue_data",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DIALOGUE_DATA_BLOCK_ID)
	{
		{ _field_short_integer, "start index (postprocess)", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "length (postprocess)", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define INVOLUNTARY_DATA_BLOCK_ID { 0x208CDC38, 0x08024456, 0x86F2C9BA, 0xA73BF240 }
	TAG_BLOCK(
		involuntary_data_block,
		"involuntary_data_block",
		100,
		"involuntary_data",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		INVOLUNTARY_DATA_BLOCK_ID)
	{
		{ _field_short_integer, "involuntary vocalization index", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("JXIFX", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define PREDICTED_DATA_BLOCK_ID { 0x6BB73155, 0x9E884B00, 0xA986C881, 0xDA52AEA3 }
	TAG_BLOCK(
		predicted_data_block,
		"predicted_data_block",
		32,
		"long",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PREDICTED_DATA_BLOCK_ID)
	{
		{ _field_long_integer, "predicted vocalization index", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define AI_DIALOGUE_GLOBALS_STRUCT_DEFINITION_ID { 0x28A04827, 0x55DC4CE6, 0x95458C49, 0x9C6549DC }
	TAG_STRUCT(
		ai_dialogue_globals_struct_definition,
		"ai_dialogue_globals_struct_definition",
		"ai_dialogue_definitions",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AI_DIALOGUE_GLOBALS_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION_EX("Global timing", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real_bounds, "strike delay bounds", nullptr, "secs" },
		{ _field_real, "remind delay", nullptr, "secs" },
		{ _field_real, "cover curse chance" },
		FIELD_EXPLANATION_EX("Player look settings", nullptr, FIELD_FLAG_NONE, "used to play look and look_longtime dialogue in campain and firefight"),
		{ _field_real, "player look max distance", "defaults to 10 wu", "wu" },
		{ _field_real, "player look", "defaults to 3 secs", "secs" },
		{ _field_real, "player look long time", "defaults to 15 secs", "secs" },
		FIELD_EXPLANATION_EX("Spartan nearby search distance", nullptr, FIELD_FLAG_NONE, "this is used when checking if the player is with other spartan ais."),
		{ _field_real, "spartan nearby search distance", "defaults to 7 wu", "wu" },
		FIELD_EXPLANATION_EX("Face friendly player distance", nullptr, FIELD_FLAG_NONE, "when talking to friendly players within this distance, if not in combat, we will turn to face them."),
		{ _field_real, "face friendly player distance", "0: disable facing behavior", "wu" },
		FIELD_EXPLANATION_EX("Space dialogue effect", nullptr, FIELD_FLAG_NONE, "at some point this will be moved into the patterns block..."),
		{ _field_string_id, "space dialogue effect", "used for dialog lines started by a pattern with \"speaker in space\" set" },
		FIELD_EXPLANATION_EX("Default stimulus suppressors", nullptr, FIELD_FLAG_NONE, "when these stimuli are active on an actor, default stimulus permutations will be suppressed."),
		{ _field_block, "default stimulus suppressors", &default_stimulus_suppressor_block },
		FIELD_EXPLANATION_EX("Imported Data. Don't touch me.", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_block, "vocalizations", &vocalization_definitions_block },
		{ _field_block, "patterns", &vocalization_patterns_block },
		FIELD_PAD_EX("WWKMVLL", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_block, "dialogue data", &dialogue_data_block },
		{ _field_block, "involuntary data", &involuntary_data_block },
		{ _field_block, "predicted vocalizations", &predicted_data_block },
		{ _field_terminator }
	};

	STRINGS(dialogue_names_enum)
	{
		"NONE",
		"death",
		"death_headshot{damage_headshot}",
		"death_assassination{damage_assassination}",
		"damage",
		"anounce",
		"sighted_interest",
		"sighted_new",
		"sighted_new major",
		"sighted_first",
		"sighted_special",
		"heard_new",
		"heard_old",
		"found_unit",
		"found_unit_pursuit",
		"throwing_grenade",
		"throwing_grenade_all",
		"stuck_grenade",
		"fighting",
		"suppressing_fire",
		"grenade_uncover",
		"jump",
		"reload",
		"reload_low_ammo",
		"ready_spartan_laser",
		"ready_rocket_launcher",
		"ready_flak_cannon",
		"ready_plasma_launcher",
		"surprised",
		"lost_contact",
		"investigate_failed",
		"pursuit_failed",
		"investigate_start",
		"investigate_interest",
		"searching",
		"abandoned_search_space",
		"abandoned_search_time",
		"presearch_failed",
		"abandoned_search_restricted",
		"pursuit_start",
		"postcombat_inspect_body",
		"vehicle_slow_down",
		"vehicle_get_in",
		"idle",
		"combat_idle",
		"taunt",
		"taunt_reply",
		"retreat",
		"retreat_from_scary_target",
		"retreat_from_dead_leader",
		"retreat_from_proximity",
		"retreat_from_low_shield",
		"flee",
		"cowering",
		"melee_charge",
		"melee_attack{melee}",
		"vehicle_falling",
		"vehicle_woohoo",
		"vehicle_scared",
		"vehicle_crazy",
		"leap",
		"postcombat_win",
		"postcombat_lose",
		"postcombat_neutral",
		"shoot_corpse",
		"postcombat start",
		"inspect_body_start",
		"postcombat_status",
		"postcombat_last_standing",
		"vehicle_entry_start_driver",
		"vehicle_enter",
		"vehicle_entry_start_gun",
		"vehicle_entry_start_passenger",
		"vehicle_exit",
		"evict_driver",
		"evict_gunner",
		"evict_passenger",
		"new_order_enemy_advancing",
		"new_order_enemy_charging",
		"new_order_enemy_fallingback",
		"new_order_advance",
		"new_order_charge",
		"new_order_fallback",
		"new_order_moveon",
		"new_order_fllplr",
		"new_order_arrive_combat",
		"new_order_end_combat",
		"new_order_investigate",
		"new_order_spread",
		"new_order_hold",
		"new_order_find_cover",
		"new_order_covering_fire",
		"order_ack_positive",
		"order_ack_negative",
		"order_ack_canceled",
		"order_ack_completed",
		"order_ack_regroup",
		"order_ack_disband",
		"order_ack_weapon_change",
		"order_ack_attack_vehicle",
		"order_ack_attack_infantry",
		"order_ack_interact",
		"order_ack_pinned_down",
		"fireteam_member_join",
		"fireteam_member_danger",
		"fireteam_member_died",
		"emerge",
		"curse",
		"threaten",
		"cover_friend",
		"move_cover",
		"in_cover",
		"pinned_down",
		"strike",
		"open_fire",
		"shoot",
		"shoot_multiple",
		"shoot_gunner",
		"gloat",
		"greet",
		"player_look",
		"player_look_longtime",
		"panic_grenade_attached",
		"panic_vehicle_destroyed",
		"help response",
		"remind",
		"overheated",
		"weapon_trade_better",
		"weapon_trade_worse",
		"weapon_trade_equal",
		"betray",
		"forgive",
		"warn_target",
		"warn_pursuit",
		"use_equipment",
		"ambush",
		"undr_fire",
		"undr_fire_trrt",
		"flood_boom",
		"vehicle_boom",
		"berserk",
		"stealth",
		"infection",
		"reanimate",
		"scold",
		"praise",
		"scorn",
		"plead",
		"thank",
		"ok",
		"cheer",
		"invite_vehicle",
		"invite_vehicle_driver",
		"invite_vehicle_gunner",
		"player_blocking",
		"player_multi_kill",
		"advance_start",
		"hamstring_charge"
	};
	STRING_LIST(dialogue_names_enum, dialogue_names_enum_strings, _countof(dialogue_names_enum_strings));

	STRINGS(response_flags)
	{
		"nonexclusive",
		"trigger response"
	};
	STRING_LIST(response_flags, response_flags_strings, _countof(response_flags_strings));

	STRINGS(response_type_enum)
	{
		"friend",
		"enemy",
		"listener",
		"joint",
		"peer",
		"leader",
		"friend_infantry"
	};
	STRING_LIST(response_type_enum, response_type_enum_strings, _countof(response_type_enum_strings));

	STRINGS(glance_type_enum)
	{
		"NONE",
		"glance subject short",
		"glance subject long",
		"glance cause short",
		"glance cause long",
		"glance friend short",
		"glance friend long"
	};
	STRING_LIST(glance_type_enum, glance_type_enum_strings, _countof(glance_type_enum_strings));

	STRINGS(priority_enum)
	{
		"none",
		"recall",
		"idle",
		"comment",
		"idle_response",
		"postcombat",
		"combat",
		"status",
		"respond",
		"warn",
		"act",
		"react",
		"involuntary",
		"scream",
		"scripted",
		"death"
	};
	STRING_LIST(priority_enum, priority_enum_strings, _countof(priority_enum_strings));

	STRINGS(vocalization_flags_definition)
	{
		"immediate",
		"interrupt",
		"cancel low priority",
		"disable dialogue effect",
		"predict facial animations"
	};
	STRING_LIST(vocalization_flags_definition, vocalization_flags_definition_strings, _countof(vocalization_flags_definition_strings));

	STRINGS(perception_type_enum)
	{
		"none",
		"speaker",
		"listener"
	};
	STRING_LIST(perception_type_enum, perception_type_enum_strings, _countof(perception_type_enum_strings));

	STRINGS(combat_status_enum)
	{
		"asleep",
		"idle",
		"alert",
		"active",
		"uninspected",
		"definite",
		"certain",
		"visible",
		"clear_los",
		"dangerous"
	};
	STRING_LIST(combat_status_enum, combat_status_enum_strings, _countof(combat_status_enum_strings));

	STRINGS(dialogue_animation_enum)
	{
		"none",
		"shakefist",
		"cheer",
		"surprise-front",
		"surprise-back",
		"taunt",
		"brace",
		"point",
		"hold",
		"wave",
		"advance",
		"fallback"
	};
	STRING_LIST(dialogue_animation_enum, dialogue_animation_enum_strings, _countof(dialogue_animation_enum_strings));

	STRINGS(dialogue_emotion_enum)
	{
		"none",
		"happy",
		"sad",
		"angry",
		"disgusted",
		"scared",
		"surprised",
		"pain",
		"shout"
	};
	STRING_LIST(dialogue_emotion_enum, dialogue_emotion_enum_strings, _countof(dialogue_emotion_enum_strings));

	STRINGS(pattern_flags)
	{
		"subject visible",
		"cause visible",
		"friends present",
		"subject is speaker\'s target",
		"cause is speaker\'s target",
		"cause is player or speaker is player ally",
		"cause is primary player ally",
		"cause is infantry",
		"subject is infantry",
		"speaker is infantry",
		"speaker in space",
		"speaker has low health",
		"cause is targeting player"
	};
	STRING_LIST(pattern_flags, pattern_flags_strings, _countof(pattern_flags_strings));

	STRINGS(speaker_type_enum)
	{
		"subject",
		"cause",
		"friend",
		"target",
		"enemy",
		"vehicle",
		"joint",
		"task",
		"leader",
		"joint_leader",
		"clump",
		"peer",
		"none"
	};
	STRING_LIST(speaker_type_enum, speaker_type_enum_strings, _countof(speaker_type_enum_strings));

	STRINGS(speaker_behavior_enum)
	{
		"any",
		"combat",
		"engage",
		"search",
		"cover",
		"retreat",
		"follow",
		"shoot",
		"clump_idle",
		"clump_combat",
		"fought_brutes",
		"fought_flood"
	};
	STRING_LIST(speaker_behavior_enum, speaker_behavior_enum_strings, _countof(speaker_behavior_enum_strings));

	STRINGS(hostility_enum)
	{
		"NONE",
		"self",
		"neutral",
		"friend",
		"enemy",
		"traitor"
	};
	STRING_LIST(hostility_enum, hostility_enum_strings, _countof(hostility_enum_strings));

	STRINGS(damage_enum)
	{
		"NONE",
		"falling",
		"bullet",
		"grenade",
		"explosive",
		"sniper",
		"melee",
		"flame",
		"mounted weapon",
		"vehicle",
		"plasma",
		"needle",
		"shotgun",
		"assassination"
	};
	STRING_LIST(damage_enum, damage_enum_strings, _countof(damage_enum_strings));

	STRINGS(game_type_enum)
	{
		"none",
		"sandbox",
		"megalo",
		"campaign",
		"survival",
		"firefight"
	};
	STRING_LIST(game_type_enum, game_type_enum_strings, _countof(game_type_enum_strings));

	STRINGS(danger_enum)
	{
		"NONE",
		"broadly facing",
		"shooting near",
		"shooting at",
		"extremely close",
		"shield damage",
		"shield extended damage",
		"body damage",
		"body extended damage"
	};
	STRING_LIST(danger_enum, danger_enum_strings, _countof(danger_enum_strings));

	STRINGS(dialogue_object_types_enum)
	{
		"NONE",
		"player",
		"actor",
		"biped",
		"body",
		"vehicle",
		"projectile",
		"actor or player",
		"turret",
		"unit in vehicle",
		"unit in turret",
		"unit carrying turret",
		"driver",
		"gunner",
		"passenger",
		"postcombat",
		"postcombat_won",
		"postcombat_lost",
		"player masterchief",
		"player spartans",
		"player dervish",
		"heretic",
		"majorly scary",
		"last man in vehicle",
		"male",
		"female",
		"grenade",
		"stealth",
		"flood",
		"pureform",
		"player empty vehicle",
		"equipment"
	};
	STRING_LIST(dialogue_object_types_enum, dialogue_object_types_enum_strings, _countof(dialogue_object_types_enum_strings));

	STRINGS(spatial_relation_enum)
	{
		"none",
		"very near",
		"near",
		"medium range",
		"far",
		"very far",
		"in front of",
		"behind",
		"above",
		"below",
		"few",
		"in range"
	};
	STRING_LIST(spatial_relation_enum, spatial_relation_enum_strings, _countof(spatial_relation_enum_strings));

	STRINGS(dialogue_condition_flags)
	{
		"asleep",
		"idle",
		"alert",
		"active",
		"uninspected orphan",
		"definite orphan",
		"certain orphan",
		"visible enemy",
		"clear los enemy",
		"dangerous enemy",
		"no vehicle",
		"vehicle driver",
		"vehicle passenger"
	};
	STRING_LIST(dialogue_condition_flags, dialogue_condition_flags_strings, _countof(dialogue_condition_flags_strings));

	TAG_REFERENCE(global_dialogue_reference, AI_DIALOGUE_GLOBALS_TAG);



} // namespace blofeld

