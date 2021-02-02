#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define OBJECTIVES_BLOCK_ID { 0x337629EE, 0xC49F426B, 0xB388142C, 0xD2A66AE8 }
	TAG_BLOCK(
		objectives_block,
		"objectives_block",
		k_maximum_objectives_per_map,
		"s_objective",
		OBJECTIVES_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_block, "opposing objectives", &opposing_objective_block },
		{ _field_word_flags, "objective flags", &objective_flags },
		{ _field_short_block_index, "zone index", &zone_block },
		{ _field_short_block_index, "first task index", &tasks_block },
		{ _field_short_block_index, "editor folder", &g_scenario_editor_folder_block },
		{ _field_block, "tasks", &tasks_block },
		{ _field_terminator }
	};

	#define OPPOSING_OBJECTIVE_BLOCK_ID { 0xB1CF4807, 0x862A48E5, 0x987F56BD, 0x4ACD02F3 }
	TAG_BLOCK(
		opposing_objective_block,
		"opposing_objective_block",
		k_maximum_opposing_objectives,
		"s_opposing_objective",
		OPPOSING_OBJECTIVE_BLOCK_ID)
	{
		{ _field_short_block_index, "objective", &objectives_block },
		FIELD_PAD("pad0", nullptr, 2),
		{ _field_terminator }
	};

	#define TASKS_BLOCK_STRUCT_ID { 0x0C243A66, 0xABF24442, 0x826D572E, 0xF1C57BB0 }
	TAG_BLOCK(
		tasks_block,
		"tasks_block",
		k_maximum_tasks_per_objective,
		"s_task",
		TASKS_BLOCK_STRUCT_ID)
	{
		{ _field_word_flags, "flags", &task_flags_definition },
		{ _field_word_flags, "inhibit groups", &inhibit_behavior_flags },
		{ _field_word_flags, "inhibit on difficulty", &global_campaign_difficulty_enum },
		{ _field_enum, "movement", &task_movement_enum },
		{ _field_enum, "follow", &task_follow_enum },
		{ _field_short_block_index, "follow squad", &squads_block },
		{ _field_real, "follow radius" },
		{ _field_real, "follow Z clamp", "Don\'t follow at areas outside of this vertical margin", "wus" },
		{ _field_word_flags, "follow players", &task_follow_player_flags },
		FIELD_PAD("post-follow-players", nullptr, 2),
		{ _field_real, "player front radius" },
		{ _field_real, "maximum duration", "Exhaust this task after it has been active for this long", "seconds" },
		{ _field_real, "exhaustion delay", "When a task exhausts, hold actors in the task for this long before releasing them", "seconds" },
		{ _field_string_id, "Entry Script", _field_id_halo_script_block },
		{ _field_string_id, "Command Script", _field_id_halo_script_block },
		{ _field_string_id, "Exhaustion Script", "static script that is run when the task is exhausted", _field_id_halo_script_block },
		{ _field_short_integer, "Script index" },
		{ _field_short_integer, "Command script index" },
		{ _field_short_integer, "Exhaustion script index" },
		{ _field_short_block_index, "Squad group filter", &squad_groups_block },
		{ _field_enum, "dialogue type", &task_dialogue_enum },
		{ _field_word_flags, "runtime flags", &task_runtime_flags },
		{ _field_short_integer, "Kungfu count", "The number of guys under this task that should be allowed to fight the player at a time" },
		FIELD_PAD("post-kungfu-count", nullptr, 2),
		{ _field_explanation, "UI-Controlled", "You don\'t need to modify these here. They are managed by the objectives ui" },
		{ _field_string_id, "name" },
		{ _field_short_integer, "priority", _field_id_unknown_ohoc },
		{ _field_short_block_index, "first_child", &tasks_block },
		{ _field_short_block_index, "next_sibling", &tasks_block },
		{ _field_short_block_index, "parent", &tasks_block },
		{ _field_block, "activation script", &script_fragment_block },
		{ _field_short_block_index, "script index ", &hs_scripts_block },
		{ _field_short_integer, "lifetime count", "task will never want to suck in more then n guys over lifetime (soft ceiling only applied when limit exceeded" },
		{ _field_word_flags, "filter flags", &filter_flags },
		{ _field_enum, "filter", &filter_enum },
		{ _field_short_bounds, "capacity" },
		{ _field_short_integer, "max body count", "task becomes inactive after the given number of casualties" },
		{ _field_enum, "attitude", &task_attitude_enum },
		{ _field_real, "min strength", "task becomes inactive after the strength of the participants falls below the given level" },
		{ _field_block, "areas", &area_reference_block },
		{ _field_block, "direction", &task_direction_block_v2_block },
		{ _field_terminator }
	};

	#define SCRIPT_FRAGMENT_BLOCK_ID { 0xBE3330E4, 0x1D254941, 0x949273FC, 0x61A61F94 }
	TAG_BLOCK(
		script_fragment_block,
		"script_fragment_block",
		1,
		"s_script_fragment",
		SCRIPT_FRAGMENT_BLOCK_ID)
	{
		{ _field_string_id, "script name" },
		{ _field_long_string, "script source", _field_id_unknown_maeo },
		{ _field_enum, "compile state", &fragment_state_enum },
		FIELD_PAD("xcvh", nullptr, 2),
		{ _field_terminator }
	};

	#define AREA_REFERENCE_BLOCK_STRUCT_ID { 0xF805BB85, 0x40034CC8, 0xA7CED22B, 0xC5D6C669 }
	TAG_BLOCK(
		area_reference_block,
		"area_reference_block",
		k_maximum_areas_per_task,
		"s_area_reference",
		AREA_REFERENCE_BLOCK_STRUCT_ID)
	{
		{ _field_enum, "area type", &zone_set_type_enum },
		{ _field_byte_flags, "flags", &zone_set_flags },
		FIELD_PAD("no-character-flags-padding", nullptr, 1),
		{ _field_short_block_index, "zone", &zone_block },
		{ _field_custom_short_block_index, "area" },
		{ _field_angle, "yaw" },
		{ _field_long_integer, "connection flags 0" },
		{ _field_long_integer, "connection flags 1" },
		{ _field_long_integer, "connection flags 2" },
		{ _field_long_integer, "connection flags 3" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		task_direction_block_v2_block,
		"task_direction_block_v2",
		1,
		task_direction_block_v2_struct);

	#define TASK_DIRECTION_POINT_BLOCK_ID { 0xE85253E6, 0x72574833, 0xAFA188B9, 0xBFF2A0ED }
	TAG_BLOCK(
		task_direction_point_block,
		"task_direction_point_block",
		k_max_points_per_task_direction,
		"s_task_direction_point",
		TASK_DIRECTION_POINT_BLOCK_ID)
	{
		{ _field_real_point_3d, "point0" },
		{ _field_custom_long_block_index, "packedKeyOffaceref" },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref" },
		{ _field_terminator }
	};

	#define TASK_DIRECTION_BLOCK_V2_STRUCT_ID { 0xFD7F6876, 0x58824DDC, 0x9EE64C67, 0xC4D351E4 }
	TAG_STRUCT(
		task_direction_block_v2_struct,
		"task_direction_block_v2_struct",
		"s_task_direction_v2",
		TASK_DIRECTION_BLOCK_V2_STRUCT_ID)
	{
		{ _field_block, "points", &task_direction_point_block },
		{ _field_terminator }
	};

	STRINGS(fragment_state_enum)
	{
		"edited",
		"success",
		"error"
	};
	STRING_LIST(fragment_state_enum, fragment_state_enum_strings, _countof(fragment_state_enum_strings));

	STRINGS(task_flags_definition)
	{
		"latch ON",
		"latch OFF",
		"gate",
		"single use",
		"suppress combat",
		"suppress active camo",
		"blind",
		"deaf",
		"braindead",
		"magic player sight",
		"DISABLE",
		"ignore fronts",
		"don\'t generate front",
		"reverse direction",
		"invert filter logic"
	};
	STRING_LIST(task_flags_definition, task_flags_definition_strings, _countof(task_flags_definition_strings));

	STRINGS(filter_flags)
	{
		"exclusive"
	};
	STRING_LIST(filter_flags, filter_flags_strings, _countof(filter_flags_strings));

	STRINGS(objective_flags)
	{
		"use front area selection",
		"use players as front",
		"inhibit vehicle entry"
	};
	STRING_LIST(objective_flags, objective_flags_strings, _countof(objective_flags_strings));

	STRINGS(inhibit_behavior_flags)
	{
		"Cover",
		"Retreat",
		"Vehicles",
		"Grenades",
		"Berserk",
		"Equipment",
		"Object Interaction"
	};
	STRING_LIST(inhibit_behavior_flags, inhibit_behavior_flags_strings, _countof(inhibit_behavior_flags_strings));

	STRINGS(filter_enum)
	{
		"none",
		"fireteam",
		"leader",
		"no leader",
		"arbiter",
		"player in my vehicle",
		"in combat",
		"sighted player",
		"sighted enemy",
		"target disengaged",
		"infantry",
		"has an engineer",
		"strength > 0.25",
		"strength > 0.5",
		"strength > 0.75",
		"strength < 0.25",
		"strength < 0.5",
		"strength < 0.75",
		"human team",
		"covenant team",
		"mule team",
		"elite",
		"jackal",
		"grunt",
		"hunter",
		"marine",
		"brute",
		"bugger",
		"bishop",
		"knight",
		"pawn",
		"rook",
		"engineer",
		"skirmisher",
		"mule",
		"spartan",
		"sniper",
		"rifle",
		"vehicle",
		"scorpion",
		"ghost",
		"warthog",
		"wraith",
		"phantom",
		"tuning fork",
		"falcon",
		"seraph",
		"sabre",
		"pelican",
		"banshee",
		"mongoose",
		"revenant",
		"shade turret"
	};
	STRING_LIST(filter_enum, filter_enum_strings, _countof(filter_enum_strings));

	STRINGS(task_follow_enum)
	{
		"NONE",
		"player",
		"squad",
		"lead player",
		"player front"
	};
	STRING_LIST(task_follow_enum, task_follow_enum_strings, _countof(task_follow_enum_strings));

	STRINGS(task_follow_player_flags)
	{
		"player 0",
		"player 1",
		"player 2",
		"player 3"
	};
	STRING_LIST(task_follow_player_flags, task_follow_player_flags_strings, _countof(task_follow_player_flags_strings));

	STRINGS(task_movement_enum)
	{
		"run (alert)",
		"walk (idle)",
		"crouch (alert)"
	};
	STRING_LIST(task_movement_enum, task_movement_enum_strings, _countof(task_movement_enum_strings));

	STRINGS(task_dialogue_enum)
	{
		"none",
		"enemy is advancing",
		"enemy is charging",
		"enemy is falling back",
		"advance",
		"charge",
		"fall_back",
		"move on{moveone}",
		"follow_player",
		"arriving into combat",
		"end combat",
		"investigate",
		"spread out",
		"hold position{hold}",
		"find cover",
		"covering fire"
	};
	STRING_LIST(task_dialogue_enum, task_dialogue_enum_strings, _countof(task_dialogue_enum_strings));

	STRINGS(zone_set_type_enum)
	{
		"normal{core}",
		"search",
		"core{leader}"
	};
	STRING_LIST(zone_set_type_enum, zone_set_type_enum_strings, _countof(zone_set_type_enum_strings));

	STRINGS(zone_set_flags)
	{
		"goal",
		"direction valid*!"
	};
	STRING_LIST(zone_set_flags, zone_set_flags_strings, _countof(zone_set_flags_strings));

	STRINGS(task_runtime_flags)
	{
		"area connectivity valid"
	};
	STRING_LIST(task_runtime_flags, task_runtime_flags_strings, _countof(task_runtime_flags_strings));

	STRINGS(task_attitude_enum)
	{
		"normal",
		"defensive",
		"aggressive",
		"playfighting",
		"patrol"
	};
	STRING_LIST(task_attitude_enum, task_attitude_enum_strings, _countof(task_attitude_enum_strings));

} // namespace macaque

} // namespace blofeld

