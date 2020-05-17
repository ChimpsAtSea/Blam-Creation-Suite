#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(behavior_set1, 32)
	{
		OPTION("------GENERAL------"),
		OPTION("root"),
		OPTION("null"),
		OPTION("null_discrete"),
		OPTION("interruptable_control"),
		OPTION("obey"),
		OPTION("guard"),
		OPTION("ready"),
		OPTION("smash_obstacle"),
		OPTION("destroy_obstacle"),
		OPTION("perch"),
		OPTION("blind_panic"),
		OPTION("combat"),
		OPTION("interact object behavior"),
		OPTION("interact object impulse"),
		OPTION("squad_patrol_behavior"),
		OPTION("movement_plan_cover_impulse"),
		OPTION("------BROKEN------"),
		OPTION("broken behavior"),
		OPTION("huddle impulse"),
		OPTION("huddle behavior"),
		OPTION("kamikaze behavior"),
		OPTION("broken kamikaze impulse"),
		OPTION("broken berserk impulse"),
		OPTION("broken flee impulse"),
		OPTION("broken scatter impulse"),
		OPTION("------ENGAGE------"),
		OPTION("equipment"),
		OPTION("equipment active camo"),
		OPTION("engage"),
		OPTION("fight"),
		OPTION("fight_circle"),
	};

	TAG_ENUM(behavior_set2, 32)
	{
		OPTION("hamstring_charge"),
		OPTION("gravity_jump"),
		OPTION("fight_positioning"),
		OPTION("melee_charge"),
		OPTION("unreachable leap charge"),
		OPTION("melee_leaping_charge"),
		OPTION("melee sync attack"),
		OPTION("grenade_impulse"),
		OPTION("object throw impulse"),
		OPTION("anti_vehicle_grenade"),
		OPTION("stalk"),
		OPTION("berserk_wander_impulse"),
		OPTION("stalker_camo_control"),
		OPTION("leader_abandoned_berserk"),
		OPTION("unassailable grenade impulse"),
		OPTION("suppressing_fire_vehicle"),
		OPTION("demand_charge_impulse"),
		OPTION("------BERSERK------"),
		OPTION("shield_depleted_berserk"),
		OPTION("last_man_berserk"),
		OPTION("stuck_with_grenade_berserk"),
		OPTION("surprise_berserk"),
		OPTION("proximity_berserk"),
		OPTION("stuck_with_grenade_balling"),
		OPTION("------PRESEARCH------"),
		OPTION("presearch"),
		OPTION("uncover"),
		OPTION("destroy_cover"),
		OPTION("suppressing fire"),
		OPTION("grenade_uncover"),
		OPTION("leap_on_cover"),
		OPTION("------LEADER------"),
	};

	TAG_ENUM(behavior_set3, 32)
	{
		OPTION("engage_sync"),
		OPTION("------SEARCH------"),
		OPTION("search"),
		OPTION("find_pursuit"),
		OPTION("investigate"),
		OPTION("------SELF-DEFENSE------"),
		OPTION("self_preservation"),
		OPTION("cover"),
		OPTION("avoid"),
		OPTION("evasion_impulse"),
		OPTION("dive_impulse"),
		OPTION("juke_impulse"),
		OPTION("danger cover impulse"),
		OPTION("danger crouch impulse"),
		OPTION("proximity_melee"),
		OPTION("proximity_self_preservation"),
		OPTION("unreachable_enemy_cover"),
		OPTION("unassailable_enemy_cover"),
		OPTION("scary_target_cover"),
		OPTION("group_emerge"),
		OPTION("kungfu_cover"),
		OPTION("------RETREAT------"),
		OPTION("retreat"),
		OPTION("retreat_grenade"),
		OPTION("flee"),
		OPTION("flee_target"),
		OPTION("cower"),
		OPTION("low_shield_retreat"),
		OPTION("scary_target_retreat"),
		OPTION("leader_dead_retreat"),
		OPTION("peer_dead_retreat"),
		OPTION("danger_retreat"),
	};

	TAG_ENUM(behavior_set4, 32)
	{
		OPTION("proximity_retreat"),
		OPTION("charge when cornered"),
		OPTION("surprise_retreat"),
		OPTION("overheated_weapon_retreat"),
		OPTION("------AMBUSH------"),
		OPTION("ambush"),
		OPTION("coordinated_ambush"),
		OPTION("proximity_ambush"),
		OPTION("vulnerable_enemy_ambush"),
		OPTION("nowhere_to_run_ambush"),
		OPTION("------VEHICLE------"),
		OPTION("enter_vehicle"),
		OPTION("enter_friendly_vehicle"),
		OPTION("switch_to_friendly_vehicle"),
		OPTION("vehicle_enter_impulse"),
		OPTION("vehicle_entry_engage_impulse"),
		OPTION("vehicle_board"),
		OPTION("vehicle_fight"),
		OPTION("vehicle_fight@boost"),
		OPTION("vehicle_charge"),
		OPTION("vehicle_ram_behavior"),
		OPTION("vehicle_cover"),
		OPTION("damage_vehicle_cover"),
		OPTION("exposed_rear_cover_impulse"),
		OPTION("player_endagered_cover_impulse"),
		OPTION("vehicle_avoid"),
		OPTION("vehicle_pickup"),
		OPTION("vehicle_exit_impulse"),
		OPTION("danger_vehicle_exit_impulse"),
		OPTION("vehicle_flip_impulse"),
		OPTION("vehicle_flip"),
		OPTION("vehicle_turtle"),
	};

	TAG_ENUM(behavior_set5, 32)
	{
		OPTION("vehicle_engage_patrol_impulse"),
		OPTION("vehicle_engage_wander_impulse"),
		OPTION("vehicle keep station"),
		OPTION("------POSTCOMBAT------"),
		OPTION("postcombat"),
		OPTION("post_postcombat"),
		OPTION("check_friend"),
		OPTION("shoot_corpse"),
		OPTION("postcombat_approach"),
		OPTION("------ALERT------"),
		OPTION("alert"),
		OPTION("------IDLE------"),
		OPTION("idle"),
		OPTION("wander behavior"),
		OPTION("flight_wander"),
		OPTION("patrol"),
		OPTION("fall_sleep"),
		OPTION("------BUGGERS------"),
		OPTION("bugger_ground_uncover"),
		OPTION("------ENGINEER------"),
		OPTION("engineer_control"),
		OPTION("engineer_control@slave"),
		OPTION("engineer_control@free"),
		OPTION("engineer_control@equipment"),
		OPTION("engineer_explode"),
		OPTION("engineer_broken_detonation"),
		OPTION("boost_allies"),
		OPTION("------SCARAB------"),
		OPTION("scarab_root"),
		OPTION("scarab_cure_isolation"),
		OPTION("scarab_combat"),
		OPTION("scarab_fight"),
	};

	TAG_ENUM(behavior_set6, 32)
	{
		OPTION("scarab_target_lock"),
		OPTION("scarab_search"),
		OPTION("scarab_search_pause"),
		OPTION("------FLYING------"),
		OPTION("flying_root"),
		OPTION("flying_idle"),
		OPTION("flying_combat"),
		OPTION("flying_approach"),
		OPTION("flying_cover"),
		OPTION("flying_evade"),
		OPTION("flying_retreat"),
		OPTION("flying_tail"),
		OPTION("flying_strafe"),
		OPTION("flying_dodge_impulse"),
		OPTION("------LOD------"),
		OPTION("lod_root"),
		OPTION("lod_idle"),
		OPTION("lod_combat"),
		OPTION("------ATOMS------"),
		OPTION("go_to"),
		OPTION("------ACTIVITIES------"),
		OPTION("activity"),
		OPTION("posture"),
		OPTION("activity_default"),
		OPTION("------SPECIAL------"),
		OPTION("formation"),
		OPTION("grunt scared by elite"),
		OPTION("cure_isolation"),
		OPTION("deploy_turret"),
		OPTION("control"),
		OPTION("arrange sync action"),
		OPTION("------MOSH------"),
	};

	TAG_ENUM(behavior_set7, 20)
	{
		OPTION("ctf"),
		OPTION("koth"),
		OPTION("assault"),
		OPTION("balling_attack"),
		OPTION("balling_leap_attack"),
		OPTION("protect allies"),
		OPTION("activate item"),
		OPTION("collect projectiles"),
		OPTION("resurrect ally"),
		OPTION("give birth"),
		OPTION("advance"),
		OPTION("teleport advance"),
		OPTION("leap advance"),
		OPTION("follow impulse (pack)"),
		OPTION("follow (pack)"),
		OPTION("stalk (pack)"),
		OPTION("fight (pack)"),
		OPTION("command charge impulse"),
		OPTION("puppet"),
		OPTION("shard spawn"),
	};

	TAG_ENUM_EMPTY(behavior_set8, 0);

	TAG_ENUM(style_control_flags, 1)
	{
		OPTION("New behaviors default to ON"),
	};

	TAG_ENUM(combat_status_enum$2, 3)
	{
		OPTION("Latch at Idle"),
		OPTION("Latch at Alert"),
		OPTION("Latch at Combat"),
	};

	TAG_GROUP_FROM_BLOCK(style, STYLE_TAG, style_block_block );

	TAG_BLOCK_FROM_STRUCT(style_block, 1, style_struct_definition_struct_definition );

	TAG_BLOCK(style_palette_block, 50)
	{
		FIELD( _field_tag_reference, "reference^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(behavior_names_block, k_maximum_behavior_count)
	{
		FIELD( _field_string, "behavior name*^" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(style_struct_definition)
{
		FIELD( _field_string, "name^" ),
		FIELD( _field_explanation, "Combat status decay options" ),
		FIELD( _field_enum, "Combat status decay options", &combat_status_enum ),
		FIELD( _field_pad, "hghq", 2 ),
		FIELD( _field_explanation, "Style Behavior Control" ),
		FIELD( _field_long_flags, "Style control", &style_control_flags ),
		FIELD( _field_long_flags, "Behaviors1", &behavior_set1 ),
		FIELD( _field_long_flags, "Behaviors2", &behavior_set2 ),
		FIELD( _field_long_flags, "Behaviors3", &behavior_set3 ),
		FIELD( _field_long_flags, "Behaviors4", &behavior_set4 ),
		FIELD( _field_long_flags, "Behaviors5", &behavior_set5 ),
		FIELD( _field_long_flags, "Behaviors6", &behavior_set6 ),
		FIELD( _field_long_flags, "Behaviors7", &behavior_set7 ),
		FIELD( _field_long_flags, "Behaviors8", &behavior_set8 ),
		FIELD( _field_block, "Special movement", &special_movement_block_block ),
		FIELD( _field_block, "Behavior list", &behavior_names_block_block ),
		FIELD( _field_terminator )
};

} // namespace blofeld

