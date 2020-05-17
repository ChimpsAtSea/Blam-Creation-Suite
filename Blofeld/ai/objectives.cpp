#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(area_reference_block, k_maximum_areas_per_task)
	{
		FIELD( _field_enum, "area type", &zone_set_type_enum ),
		FIELD( _field_byte_flags, "flags", &zone_set_flags ),
		FIELD( _field_pad, "no-character-flags-padding", 1 ),
		FIELD( _field_short_block_index, "zone^" ),
		FIELD( _field_custom_short_block_index, "area^" ),
		FIELD( _field_angle, "yaw" ),
		FIELD( _field_long_integer, "connection flags 0*!" ),
		FIELD( _field_long_integer, "connection flags 1*!" ),
		FIELD( _field_long_integer, "connection flags 2*!" ),
		FIELD( _field_long_integer, "connection flags 3*!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(opposing_objective_block, k_maximum_opposing_objectives)
	{
		FIELD( _field_short_block_index, "objective" ),
		FIELD( _field_pad, "pad0", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(script_fragment_block, 1)
	{
		FIELD( _field_string_id, "script name*" ),
		FIELD( _field_long_string, "script source" ),
		FIELD( _field_enum, "compile state*", &fragment_state_enum ),
		FIELD( _field_pad, "xcvh", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(task_direction_point_block, k_max_points_per_task_direction)
	{
		FIELD( _field_real_point_3d, "point0" ),
		FIELD( _field_custom_long_block_index, "packedKeyOffaceref~!" ),
		FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref~!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(task_direction_block_v2, 1, task_direction_block_v2_struct_struct_definition );

	TAG_BLOCK(tasks_block, k_maximum_tasks_per_objective)
	{
		FIELD( _field_word_flags, "flags", &task_flags_definition ),
		FIELD( _field_word_flags, "inhibit groups", &inhibit_behavior_flags ),
		FIELD( _field_word_flags, "inhibit on difficulty", &global_campaign_difficulty_enum ),
		FIELD( _field_enum, "movement", &task_movement_enum ),
		FIELD( _field_enum, "follow", &task_follow_enum ),
		FIELD( _field_short_block_index, "follow squad" ),
		FIELD( _field_real, "follow radius" ),
		FIELD( _field_real, "follow Z clamp:wus#Don\'t follow at areas outside of this vertical margin" ),
		FIELD( _field_word_flags, "follow players", &task_follow_player_flags ),
		FIELD( _field_pad, "post-follow-players", 2 ),
		FIELD( _field_real, "player front radius" ),
		FIELD( _field_real, "maximum duration:seconds#Exhaust this task after it has been active for this long" ),
		FIELD( _field_real, "exhaustion delay:seconds#When a task exhausts, hold actors in the task for this long before releasing them" ),
		FIELD( _field_string_id, "Entry Script" ),
		FIELD( _field_string_id, "Command Script" ),
		FIELD( _field_string_id, "Exhaustion Script#static script that is run when the task is exhausted" ),
		FIELD( _field_short_integer, "Script index*~" ),
		FIELD( _field_short_integer, "Command script index*~" ),
		FIELD( _field_short_integer, "Exhaustion script index*~" ),
		FIELD( _field_short_block_index, "Squad group filter" ),
		FIELD( _field_enum, "dialogue type#when someone enters this task for the first time, they play this type of dialogue", &task_dialogue_enum ),
		FIELD( _field_word_flags, "runtime flags*!", &task_runtime_flags ),
		FIELD( _field_short_integer, "Kungfu count#The number of guys under this task that should be allowed to fight the player at a time" ),
		FIELD( _field_pad, "post-kungfu-count", 2 ),
		FIELD( _field_explanation, "UI-Controlled" ),
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_short_integer, "priority*" ),
		FIELD( _field_short_block_index, "first_child*" ),
		FIELD( _field_short_block_index, "next_sibling*" ),
		FIELD( _field_short_block_index, "parent*" ),
		FIELD( _field_block, "activation script", &script_fragment_block_block ),
		FIELD( _field_short_block_index, "script index *~" ),
		FIELD( _field_short_integer, "lifetime count#task will never want to suck in more then n guys over lifetime (soft ceiling only applied when limit exceeded" ),
		FIELD( _field_word_flags, "filter flags", &filter_flags ),
		FIELD( _field_enum, "filter", &filter_enum ),
		FIELD( _field_short_bounds, "capacity" ),
		FIELD( _field_short_integer, "max body count#task becomes inactive after the given number of casualties" ),
		FIELD( _field_enum, "attitude", &task_attitude_enum ),
		FIELD( _field_real, "min strength:[0,1]#task becomes inactive after the strength of the participants falls below the given level" ),
		FIELD( _field_block, "areas", &area_reference_block_block ),
		FIELD( _field_block, "direction", &task_direction_block_v2_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(objectives_block, k_maximum_objectives_per_map)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_block, "opposing objectives", &opposing_objective_block_block ),
		FIELD( _field_word_flags, "objective flags", &objective_flags ),
		FIELD( _field_short_block_index, "zone index*!" ),
		FIELD( _field_short_block_index, "first task index*!" ),
		FIELD( _field_short_block_index, "editor folder!" ),
		FIELD( _field_block, "tasks*!", &tasks_block_block ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(task_direction_block_v2_struct)
	{
		FIELD( _field_block, "points", &task_direction_point_block_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(fragment_state_enum, 3)
	{
		OPTION("edited"),
		OPTION("success"),
		OPTION("error"),
	};

	TAG_ENUM(task_flags_definition, 15)
	{
		OPTION("latch ON"),
		OPTION("latch OFF"),
		OPTION("gate"),
		OPTION("single use"),
		OPTION("suppress combat"),
		OPTION("suppress active camo"),
		OPTION("blind"),
		OPTION("deaf"),
		OPTION("braindead"),
		OPTION("magic player sight"),
		OPTION("DISABLE"),
		OPTION("ignore fronts"),
		OPTION("don\'t generate front"),
		OPTION("reverse direction"),
		OPTION("invert filter logic"),
	};

	TAG_ENUM(filter_flags, 1)
	{
		OPTION("exclusive"),
	};

	TAG_ENUM(objective_flags, 3)
	{
		OPTION("use front area selection"),
		OPTION("use players as front"),
		OPTION("inhibit vehicle entry"),
	};

	TAG_ENUM(inhibit_behavior_flags, 7)
	{
		OPTION("Cover"),
		OPTION("Retreat"),
		OPTION("Vehicles"),
		OPTION("Grenades"),
		OPTION("Berserk"),
		OPTION("Equipment"),
		OPTION("Object Interaction"),
	};

	TAG_ENUM(filter_enum, 53)
	{
		OPTION("none"),
		OPTION("fireteam"),
		OPTION("leader"),
		OPTION("no leader"),
		OPTION("arbiter"),
		OPTION("player in my vehicle"),
		OPTION("in combat"),
		OPTION("sighted player"),
		OPTION("sighted enemy"),
		OPTION("target disengaged"),
		OPTION("infantry"),
		OPTION("has an engineer"),
		OPTION("strength > 0.25"),
		OPTION("strength > 0.5"),
		OPTION("strength > 0.75"),
		OPTION("strength < 0.25"),
		OPTION("strength < 0.5"),
		OPTION("strength < 0.75"),
		OPTION("human team"),
		OPTION("covenant team"),
		OPTION("mule team"),
		OPTION("elite"),
		OPTION("jackal"),
		OPTION("grunt"),
		OPTION("hunter"),
		OPTION("marine"),
		OPTION("brute"),
		OPTION("bugger"),
		OPTION("bishop"),
		OPTION("knight"),
		OPTION("pawn"),
		OPTION("rook"),
		OPTION("engineer"),
		OPTION("skirmisher"),
		OPTION("mule"),
		OPTION("spartan"),
		OPTION("sniper"),
		OPTION("rifle"),
		OPTION("vehicle"),
		OPTION("scorpion"),
		OPTION("ghost"),
		OPTION("warthog"),
		OPTION("wraith"),
		OPTION("phantom"),
		OPTION("tuning fork"),
		OPTION("falcon"),
		OPTION("seraph"),
		OPTION("sabre"),
		OPTION("pelican"),
		OPTION("banshee"),
		OPTION("mongoose"),
		OPTION("revenant"),
		OPTION("shade turret"),
	};

	TAG_ENUM(task_follow_enum, 5)
	{
		OPTION("NONE"),
		OPTION("player"),
		OPTION("squad"),
		OPTION("lead player"),
		OPTION("player front"),
	};

	TAG_ENUM(task_follow_player_flags, 4)
	{
		OPTION("player 0"),
		OPTION("player 1"),
		OPTION("player 2"),
		OPTION("player 3"),
	};

	TAG_ENUM(task_movement_enum, 3)
	{
		OPTION("run (alert)"),
		OPTION("walk (idle)"),
		OPTION("crouch (alert)"),
	};

	TAG_ENUM(task_dialogue_enum, 16)
	{
		OPTION("none"),
		OPTION("enemy is advancing"),
		OPTION("enemy is charging"),
		OPTION("enemy is falling back"),
		OPTION("advance"),
		OPTION("charge"),
		OPTION("fall_back"),
		OPTION("move on{moveone}"),
		OPTION("follow_player"),
		OPTION("arriving into combat"),
		OPTION("end combat"),
		OPTION("investigate"),
		OPTION("spread out"),
		OPTION("hold position{hold}"),
		OPTION("find cover"),
		OPTION("covering fire"),
	};

	TAG_ENUM(zone_set_type_enum, 3)
	{
		OPTION("normal{core}"),
		OPTION("search"),
		OPTION("core{leader}"),
	};

	TAG_ENUM(zone_set_flags, 2)
	{
		OPTION("goal"),
		OPTION("direction valid*!"),
	};

	TAG_ENUM(task_runtime_flags, 1)
	{
		OPTION("area connectivity valid"),
	};

	TAG_ENUM(task_attitude_enum, 5)
	{
		OPTION("normal"),
		OPTION("defensive"),
		OPTION("aggressive"),
		OPTION("playfighting"),
		OPTION("patrol"),
	};

} // namespace blofeld

