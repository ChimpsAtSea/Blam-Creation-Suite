#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(dialogue_names_enum, 158)
	{
		OPTION("NONE"),
		OPTION("death"),
		OPTION("death_headshot{damage_headshot}"),
		OPTION("death_assassination{damage_assassination}"),
		OPTION("damage"),
		OPTION("anounce"),
		OPTION("sighted_interest"),
		OPTION("sighted_new"),
		OPTION("sighted_new major"),
		OPTION("sighted_first"),
		OPTION("sighted_special"),
		OPTION("heard_new"),
		OPTION("heard_old"),
		OPTION("found_unit"),
		OPTION("found_unit_pursuit"),
		OPTION("throwing_grenade"),
		OPTION("throwing_grenade_all"),
		OPTION("stuck_grenade"),
		OPTION("fighting"),
		OPTION("suppressing_fire"),
		OPTION("grenade_uncover"),
		OPTION("jump"),
		OPTION("reload"),
		OPTION("reload_low_ammo"),
		OPTION("ready_spartan_laser"),
		OPTION("ready_rocket_launcher"),
		OPTION("ready_flak_cannon"),
		OPTION("ready_plasma_launcher"),
		OPTION("surprised"),
		OPTION("lost_contact"),
		OPTION("investigate_failed"),
		OPTION("pursuit_failed"),
		OPTION("investigate_start"),
		OPTION("investigate_interest"),
		OPTION("searching"),
		OPTION("abandoned_search_space"),
		OPTION("abandoned_search_time"),
		OPTION("presearch_failed"),
		OPTION("abandoned_search_restricted"),
		OPTION("pursuit_start"),
		OPTION("postcombat_inspect_body"),
		OPTION("vehicle_slow_down"),
		OPTION("vehicle_get_in"),
		OPTION("idle"),
		OPTION("combat_idle"),
		OPTION("taunt"),
		OPTION("taunt_reply"),
		OPTION("retreat"),
		OPTION("retreat_from_scary_target"),
		OPTION("retreat_from_dead_leader"),
		OPTION("retreat_from_proximity"),
		OPTION("retreat_from_low_shield"),
		OPTION("flee"),
		OPTION("cowering"),
		OPTION("melee_charge"),
		OPTION("melee_attack{melee}"),
		OPTION("vehicle_falling"),
		OPTION("vehicle_woohoo"),
		OPTION("vehicle_scared"),
		OPTION("vehicle_crazy"),
		OPTION("leap"),
		OPTION("postcombat_win"),
		OPTION("postcombat_lose"),
		OPTION("postcombat_neutral"),
		OPTION("shoot_corpse"),
		OPTION("postcombat start"),
		OPTION("inspect_body_start"),
		OPTION("postcombat_status"),
		OPTION("postcombat_last_standing"),
		OPTION("vehicle_entry_start_driver"),
		OPTION("vehicle_enter"),
		OPTION("vehicle_entry_start_gun"),
		OPTION("vehicle_entry_start_passenger"),
		OPTION("vehicle_exit"),
		OPTION("evict_driver"),
		OPTION("evict_gunner"),
		OPTION("evict_passenger"),
		OPTION("new_order_enemy_advancing"),
		OPTION("new_order_enemy_charging"),
		OPTION("new_order_enemy_fallingback"),
		OPTION("new_order_advance"),
		OPTION("new_order_charge"),
		OPTION("new_order_fallback"),
		OPTION("new_order_moveon"),
		OPTION("new_order_fllplr"),
		OPTION("new_order_arrive_combat"),
		OPTION("new_order_end_combat"),
		OPTION("new_order_investigate"),
		OPTION("new_order_spread"),
		OPTION("new_order_hold"),
		OPTION("new_order_find_cover"),
		OPTION("new_order_covering_fire"),
		OPTION("order_ack_positive"),
		OPTION("order_ack_negative"),
		OPTION("order_ack_canceled"),
		OPTION("order_ack_completed"),
		OPTION("order_ack_regroup"),
		OPTION("order_ack_disband"),
		OPTION("order_ack_weapon_change"),
		OPTION("order_ack_attack_vehicle"),
		OPTION("order_ack_attack_infantry"),
		OPTION("order_ack_interact"),
		OPTION("order_ack_pinned_down"),
		OPTION("fireteam_member_join"),
		OPTION("fireteam_member_danger"),
		OPTION("fireteam_member_died"),
		OPTION("emerge"),
		OPTION("curse"),
		OPTION("threaten"),
		OPTION("cover_friend"),
		OPTION("move_cover"),
		OPTION("in_cover"),
		OPTION("pinned_down"),
		OPTION("strike"),
		OPTION("open_fire"),
		OPTION("shoot"),
		OPTION("shoot_multiple"),
		OPTION("shoot_gunner"),
		OPTION("gloat"),
		OPTION("greet"),
		OPTION("player_look"),
		OPTION("player_look_longtime"),
		OPTION("panic_grenade_attached"),
		OPTION("panic_vehicle_destroyed"),
		OPTION("help response"),
		OPTION("remind"),
		OPTION("overheated"),
		OPTION("weapon_trade_better"),
		OPTION("weapon_trade_worse"),
		OPTION("weapon_trade_equal"),
		OPTION("betray"),
		OPTION("forgive"),
		OPTION("warn_target"),
		OPTION("warn_pursuit"),
		OPTION("use_equipment"),
		OPTION("ambush"),
		OPTION("undr_fire"),
		OPTION("undr_fire_trrt"),
		OPTION("flood_boom"),
		OPTION("vehicle_boom"),
		OPTION("berserk"),
		OPTION("stealth"),
		OPTION("infection"),
		OPTION("reanimate"),
		OPTION("scold"),
		OPTION("praise"),
		OPTION("scorn"),
		OPTION("plead"),
		OPTION("thank"),
		OPTION("ok"),
		OPTION("cheer"),
		OPTION("invite_vehicle"),
		OPTION("invite_vehicle_driver"),
		OPTION("invite_vehicle_gunner"),
		OPTION("player_blocking"),
		OPTION("player_multi_kill"),
		OPTION("advance_start"),
		OPTION("hamstring_charge"),
	};

	TAG_ENUM(response_flags, 2)
	{
		OPTION("nonexclusive"),
		OPTION("trigger response"),
	};

	TAG_ENUM(response_type_enum, 7)
	{
		OPTION("friend"),
		OPTION("enemy"),
		OPTION("listener"),
		OPTION("joint"),
		OPTION("peer"),
		OPTION("leader"),
		OPTION("friend_infantry"),
	};

	TAG_ENUM(glance_type_enum, 7)
	{
		OPTION("NONE"),
		OPTION("glance subject short"),
		OPTION("glance subject long"),
		OPTION("glance cause short"),
		OPTION("glance cause long"),
		OPTION("glance friend short"),
		OPTION("glance friend long"),
	};

	TAG_ENUM(priority_enum, 16)
	{
		OPTION("none"),
		OPTION("recall"),
		OPTION("idle"),
		OPTION("comment"),
		OPTION("idle_response"),
		OPTION("postcombat"),
		OPTION("combat"),
		OPTION("status"),
		OPTION("respond"),
		OPTION("warn"),
		OPTION("act"),
		OPTION("react"),
		OPTION("involuntary"),
		OPTION("scream"),
		OPTION("scripted"),
		OPTION("death"),
	};

	TAG_ENUM(vocalization_flags_definition, 5)
	{
		OPTION("immediate"),
		OPTION("interrupt"),
		OPTION("cancel low priority"),
		OPTION("disable dialogue effect"),
		OPTION("predict facial animations"),
	};

	TAG_ENUM(perception_type_enum, 3)
	{
		OPTION("none"),
		OPTION("speaker"),
		OPTION("listener"),
	};

	TAG_ENUM(combat_status_enum, 10)
	{
		OPTION("asleep"),
		OPTION("idle"),
		OPTION("alert"),
		OPTION("active"),
		OPTION("uninspected"),
		OPTION("definite"),
		OPTION("certain"),
		OPTION("visible"),
		OPTION("clear_los"),
		OPTION("dangerous"),
	};

	TAG_ENUM(dialogue_animation_enum, 12)
	{
		OPTION("none"),
		OPTION("shakefist"),
		OPTION("cheer"),
		OPTION("surprise-front"),
		OPTION("surprise-back"),
		OPTION("taunt"),
		OPTION("brace"),
		OPTION("point"),
		OPTION("hold"),
		OPTION("wave"),
		OPTION("advance"),
		OPTION("fallback"),
	};

	TAG_ENUM(dialogue_emotion_enum, 9)
	{
		OPTION("none"),
		OPTION("happy"),
		OPTION("sad"),
		OPTION("angry"),
		OPTION("disgusted"),
		OPTION("scared"),
		OPTION("surprised"),
		OPTION("pain"),
		OPTION("shout"),
	};

	TAG_ENUM(pattern_flags, 13)
	{
		OPTION("subject visible"),
		OPTION("cause visible"),
		OPTION("friends present"),
		OPTION("subject is speaker\'s target"),
		OPTION("cause is speaker\'s target"),
		OPTION("cause is player or speaker is player ally"),
		OPTION("cause is primary player ally"),
		OPTION("cause is infantry"),
		OPTION("subject is infantry"),
		OPTION("speaker is infantry"),
		OPTION("speaker in space"),
		OPTION("speaker has low health"),
		OPTION("cause is targeting player"),
	};

	TAG_ENUM(speaker_type_enum, 13)
	{
		OPTION("subject"),
		OPTION("cause"),
		OPTION("friend"),
		OPTION("target"),
		OPTION("enemy"),
		OPTION("vehicle"),
		OPTION("joint"),
		OPTION("task"),
		OPTION("leader"),
		OPTION("joint_leader"),
		OPTION("clump"),
		OPTION("peer"),
		OPTION("none"),
	};

	TAG_ENUM(speaker_behavior_enum, 12)
	{
		OPTION("any"),
		OPTION("combat"),
		OPTION("engage"),
		OPTION("search"),
		OPTION("cover"),
		OPTION("retreat"),
		OPTION("follow"),
		OPTION("shoot"),
		OPTION("clump_idle"),
		OPTION("clump_combat"),
		OPTION("fought_brutes"),
		OPTION("fought_flood"),
	};

	TAG_ENUM(hostility_enum, 6)
	{
		OPTION("NONE"),
		OPTION("self"),
		OPTION("neutral"),
		OPTION("friend"),
		OPTION("enemy"),
		OPTION("traitor"),
	};

	TAG_ENUM(damage_enum, 14)
	{
		OPTION("NONE"),
		OPTION("falling"),
		OPTION("bullet"),
		OPTION("grenade"),
		OPTION("explosive"),
		OPTION("sniper"),
		OPTION("melee"),
		OPTION("flame"),
		OPTION("mounted weapon"),
		OPTION("vehicle"),
		OPTION("plasma"),
		OPTION("needle"),
		OPTION("shotgun"),
		OPTION("assassination"),
	};

	TAG_ENUM(game_type_enum, 6)
	{
		OPTION("none"),
		OPTION("sandbox"),
		OPTION("megalo"),
		OPTION("campaign"),
		OPTION("survival"),
		OPTION("firefight"),
	};

	TAG_ENUM(danger_enum, 9)
	{
		OPTION("NONE"),
		OPTION("broadly facing"),
		OPTION("shooting near"),
		OPTION("shooting at"),
		OPTION("extremely close"),
		OPTION("shield damage"),
		OPTION("shield extended damage"),
		OPTION("body damage"),
		OPTION("body extended damage"),
	};

	TAG_ENUM(dialogue_object_types_enum, 32)
	{
		OPTION("NONE"),
		OPTION("player"),
		OPTION("actor"),
		OPTION("biped"),
		OPTION("body"),
		OPTION("vehicle"),
		OPTION("projectile"),
		OPTION("actor or player"),
		OPTION("turret"),
		OPTION("unit in vehicle"),
		OPTION("unit in turret"),
		OPTION("unit carrying turret"),
		OPTION("driver"),
		OPTION("gunner"),
		OPTION("passenger"),
		OPTION("postcombat"),
		OPTION("postcombat_won"),
		OPTION("postcombat_lost"),
		OPTION("player masterchief"),
		OPTION("player spartans"),
		OPTION("player dervish"),
		OPTION("heretic"),
		OPTION("majorly scary"),
		OPTION("last man in vehicle"),
		OPTION("male"),
		OPTION("female"),
		OPTION("grenade"),
		OPTION("stealth"),
		OPTION("flood"),
		OPTION("pureform"),
		OPTION("player empty vehicle"),
		OPTION("equipment"),
	};

	TAG_ENUM(spatial_relation_enum, 12)
	{
		OPTION("none"),
		OPTION("very near"),
		OPTION("near"),
		OPTION("medium range"),
		OPTION("far"),
		OPTION("very far"),
		OPTION("in front of"),
		OPTION("behind"),
		OPTION("above"),
		OPTION("below"),
		OPTION("few"),
		OPTION("in range"),
	};

	TAG_ENUM(dialogue_condition_flags, 13)
	{
		OPTION("asleep"),
		OPTION("idle"),
		OPTION("alert"),
		OPTION("active"),
		OPTION("uninspected orphan"),
		OPTION("definite orphan"),
		OPTION("certain orphan"),
		OPTION("visible enemy"),
		OPTION("clear los enemy"),
		OPTION("dangerous enemy"),
		OPTION("no vehicle"),
		OPTION("vehicle driver"),
		OPTION("vehicle passenger"),
	};

	TAG_GROUP_FROM_BLOCK(ai_dialogue_globals, AI_DIALOGUE_GLOBALS_TAG, ai_dialogue_globals_block_block );

	TAG_BLOCK_FROM_STRUCT(ai_dialogue_globals_block, 1, ai_dialogue_globals_struct_definition_struct_definition );

	TAG_BLOCK(default_stimulus_suppressor_block, 4)
	{
		FIELD( _field_string_id, "stimulus^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(vocalization_definitions_block, 500)
	{
		FIELD( _field_string_id, "vocalization^" ),
		FIELD( _field_short_block_index, "parent index*" ),
		FIELD( _field_enum, "priority", &priority_enum ),
		FIELD( _field_long_flags, "flags", &vocalization_flags_definition ),
		FIELD( _field_enum, "glance behavior#how does the speaker of this vocalization direct his gaze\?", &glance_type_enum ),
		FIELD( _field_enum, "glance recipient behavior#how does someone who hears me behave\?", &glance_type_enum ),
		FIELD( _field_enum, "perception type", &perception_type_enum ),
		FIELD( _field_enum, "max combat status", &combat_status_enum ),
		FIELD( _field_enum, "animation impulse", &dialogue_animation_enum ),
		FIELD( _field_short_integer, "proxy dialogue index" ),
		FIELD( _field_real, "sound repetition delay:minutes#Minimum delay time between playing the same permutation" ),
		FIELD( _field_real, "allowable queue delay:seconds#How long to wait to actually start the vocalization" ),
		FIELD( _field_real, "pre voc. delay:seconds#How long to wait to actually start the vocalization" ),
		FIELD( _field_real, "notification delay:seconds#How long into the vocalization the AI should be notified" ),
		FIELD( _field_real, "post voc. delay:seconds#How long speech is suppressed in the speaking unit after vocalizing" ),
		FIELD( _field_real, "repeat delay:seconds#How long before the same vocalization can be repeated" ),
		FIELD( _field_real, "weight:[0-1]#Inherent weight of this vocalization" ),
		FIELD( _field_real, "speaker freeze time#speaker won\'t move for the given amount of time" ),
		FIELD( _field_real, "listener freeze time#listener won\'t move for the given amount of time (from start of vocalization)" ),
		FIELD( _field_enum, "speaker emotion", &dialogue_emotion_enum ),
		FIELD( _field_enum, "listener emotion", &dialogue_emotion_enum ),
		FIELD( _field_real, "player speaker skip fraction" ),
		FIELD( _field_real, "player skip fraction" ),
		FIELD( _field_real, "flood skip fraction" ),
		FIELD( _field_real, "skip fraction" ),
		FIELD( _field_short_integer, "mission min value#The lowest mission id that we play this line in" ),
		FIELD( _field_short_integer, "mission max value#The highest mission id that we play this line in" ),
		FIELD( _field_string_id, "Sample line" ),
		FIELD( _field_block, "reponses", &response_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(response_block, 20)
	{
		FIELD( _field_string_id, "vocalization name" ),
		FIELD( _field_word_flags, "flags", &response_flags ),
		FIELD( _field_short_integer, "vocalization index*" ),
		FIELD( _field_enum, "response type", &response_type_enum ),
		FIELD( _field_short_integer, "dialogue index (import)*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(vocalization_patterns_block, 1000)
	{
		FIELD( _field_enum, "dialogue type", &dialogue_names_enum ),
		FIELD( _field_short_integer, "vocalization index" ),
		FIELD( _field_string_id, "vocalization name" ),
		FIELD( _field_enum, "speaker type", &speaker_type_enum ),
		FIELD( _field_enum, "listener/target#who/what am I speaking to/of\?", &speaker_type_enum ),
		FIELD( _field_enum, "hostility#The relationship between the subject and the cause", &hostility_enum ),
		FIELD( _field_word_flags, "flags", &pattern_flags ),
		FIELD( _field_explanation, "Cause" ),
		FIELD( _field_enum, "cause actor type", &actor_type_enum ),
		FIELD( _field_enum, "cause type", &dialogue_object_types_enum ),
		FIELD( _field_string_id, "cause ai type name" ),
		FIELD( _field_string_id, "cause equipment type name" ),
		FIELD( _field_explanation, "Speaker" ),
		FIELD( _field_enum, "speaker object type", &dialogue_object_types_enum ),
		FIELD( _field_enum, "speaker behavior", &speaker_behavior_enum ),
		FIELD( _field_enum, "danger level#Speaker must have danger level of at least this much", &danger_enum ),
		FIELD( _field_char_enum, "speaker/subject position", &spatial_relation_enum ),
		FIELD( _field_char_enum, "speaker/cause position", &spatial_relation_enum ),
		FIELD( _field_long_flags, "Conditions", &dialogue_condition_flags ),
		FIELD( _field_explanation, "Matching" ),
		FIELD( _field_enum, "spatial relation#with respect to the subject, the cause is ...", &spatial_relation_enum ),
		FIELD( _field_enum, "damage type", &damage_enum ),
		FIELD( _field_enum, "game type", &game_type_enum ),
		FIELD( _field_explanation, "Subject" ),
		FIELD( _field_enum, "subject actor type", &actor_type_enum ),
		FIELD( _field_enum, "subject type", &dialogue_object_types_enum ),
		FIELD( _field_pad, "post-subject-type-pad", 2 ),
		FIELD( _field_string_id, "subject ai type name" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(dialogue_data_block, k_dialogue_type_count)
	{
		FIELD( _field_short_integer, "start index (postprocess)*" ),
		FIELD( _field_short_integer, "length (postprocess)*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(involuntary_data_block, 100)
	{
		FIELD( _field_short_integer, "involuntary vocalization index*" ),
		FIELD( _field_pad, "JXIFX", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(predicted_data_block, 32)
	{
		FIELD( _field_long_integer, "predicted vocalization index*" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(ai_dialogue_globals_struct_definition)
{
		FIELD( _field_explanation, "Global timing" ),
		FIELD( _field_real_bounds, "strike delay bounds:secs" ),
		FIELD( _field_real, "remind delay:secs" ),
		FIELD( _field_real, "cover curse chance" ),
		FIELD( _field_explanation, "Player look settings" ),
		FIELD( _field_real, "player look max distance:wu#defaults to 10 wu" ),
		FIELD( _field_real, "player look:secs#defaults to 3 secs" ),
		FIELD( _field_real, "player look long time:secs#defaults to 15 secs" ),
		FIELD( _field_explanation, "Spartan nearby search distance" ),
		FIELD( _field_real, "spartan nearby search distance:wu#defaults to 7 wu" ),
		FIELD( _field_explanation, "Face friendly player distance" ),
		FIELD( _field_real, "face friendly player distance:wu#0: disable facing behavior" ),
		FIELD( _field_explanation, "Space dialogue effect" ),
		FIELD( _field_string_id, "space dialogue effect#used for dialog lines started by a pattern with \"speaker in space\" set" ),
		FIELD( _field_explanation, "Default stimulus suppressors" ),
		FIELD( _field_block, "default stimulus suppressors", &default_stimulus_suppressor_block_block ),
		FIELD( _field_explanation, "Imported Data. Don\'t touch me." ),
		FIELD( _field_block, "vocalizations", &vocalization_definitions_block_block ),
		FIELD( _field_block, "patterns", &vocalization_patterns_block_block ),
		FIELD( _field_pad, "WWKMVLL", 12 ),
		FIELD( _field_block, "dialogue data", &dialogue_data_block_block ),
		FIELD( _field_block, "involuntary data", &involuntary_data_block_block ),
		FIELD( _field_block, "predicted vocalizations", &predicted_data_block_block ),
		FIELD( _field_terminator )
};

} // namespace blofeld

