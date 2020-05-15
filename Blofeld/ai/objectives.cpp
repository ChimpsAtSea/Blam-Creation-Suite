#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(area_reference, k_maximum_areas_per_task)
{
	{ _field_enum, "area type" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "no-character-flags-padding", 1 },
	{ _field_short_block_index, "zone^" },
	{ _field_custom_short_block_index, "area^" },
	{ _field_angle, "yaw" },
	{ _field_long_integer, "connection flags 0*!" },
	{ _field_long_integer, "connection flags 1*!" },
	{ _field_long_integer, "connection flags 2*!" },
	{ _field_long_integer, "connection flags 3*!" },
	{ _field_terminator },
};

TAG_BLOCK(objectives, k_maximum_objectives_per_map)
{
	{ _field_string_id, "name^" },
	{ _field_block, "opposing objectives", &opposing_objective_block },
	{ _field_word_flags, "objective flags" },
	{ _field_short_block_index, "zone index*!" },
	{ _field_short_block_index, "first task index*!" },
	{ _field_short_block_index, "editor folder!" },
	{ _field_block, "tasks*!", &tasks_block },
	{ _field_terminator },
};

TAG_BLOCK(opposing_objective, k_maximum_opposing_objectives)
{
	{ _field_short_block_index, "objective" },
	{ _field_pad, "pad0", 2 },
	{ _field_terminator },
};

TAG_BLOCK(tasks, k_maximum_tasks_per_objective)
{
	{ _field_word_flags, "flags" },
	{ _field_word_flags, "inhibit groups" },
	{ _field_word_flags, "inhibit on difficulty" },
	{ _field_enum, "movement" },
	{ _field_enum, "follow" },
	{ _field_short_block_index, "follow squad" },
	{ _field_real, "follow radius" },
	{ _field_real, "follow Z clamp:wus#Don\'t follow at areas outside of this vertical margin" },
	{ _field_word_flags, "follow players" },
	{ _field_pad, "post-follow-players", 2 },
	{ _field_real, "player front radius" },
	{ _field_real, "maximum duration:seconds#Exhaust this task after it has been active for this long" },
	{ _field_real, "exhaustion delay:seconds#When a task exhausts, hold actors in the task for this long before releasing them" },
	{ _field_string_id, "Entry Script" },
	{ _field_string_id, "Command Script" },
	{ _field_string_id, "Exhaustion Script#static script that is run when the task is exhausted" },
	{ _field_short_integer, "Script index*~" },
	{ _field_short_integer, "Command script index*~" },
	{ _field_short_integer, "Exhaustion script index*~" },
	{ _field_short_block_index, "Squad group filter" },
	{ _field_enum, "dialogue type#when someone enters this task for the first time, they play this type of dialogue" },
	{ _field_word_flags, "runtime flags*!" },
	{ _field_short_integer, "Kungfu count#The number of guys under this task that should be allowed to fight the player at a time" },
	{ _field_pad, "post-kungfu-count", 2 },
	{ _field_explanation, "UI-Controlled" },
	{ _field_string_id, "name^" },
	{ _field_short_integer, "priority*" },
	{ _field_short_block_index, "first_child*" },
	{ _field_short_block_index, "next_sibling*" },
	{ _field_short_block_index, "parent*" },
	{ _field_block, "activation script", &script_fragment_block },
	{ _field_short_block_index, "script index *~" },
	{ _field_short_integer, "lifetime count#task will never want to suck in more then n guys over lifetime (soft ceiling only applied when limit exceeded" },
	{ _field_word_flags, "filter flags" },
	{ _field_enum, "filter" },
	{ _field_short_bounds, "capacity" },
	{ _field_short_integer, "max body count#task becomes inactive after the given number of casualties" },
	{ _field_enum, "attitude" },
	{ _field_real, "min strength:[0,1]#task becomes inactive after the strength of the participants falls below the given level" },
	{ _field_block, "areas", &area_reference_block },
	{ _field_block, "direction", &task_direction_block },
	{ _field_terminator },
};

TAG_BLOCK(script_fragment, 1)
{
	{ _field_string_id, "script name*" },
	{ _field_long_string, "script source" },
	{ _field_enum, "compile state*" },
	{ _field_pad, "xcvh", 2 },
	{ _field_terminator },
};

TAG_BLOCK(task_direction, 1)
{
	{ _field_block, "points", &task_direction_point_block },
	{ _field_terminator },
};

TAG_BLOCK(task_direction_point, k_max_points_per_task_direction)
{
	{ _field_real_point_3d, "point0" },
	{ _field_custom_long_block_index, "packedKeyOffaceref~!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref~!" },
	{ _field_terminator },
};

} // namespace blofeld

