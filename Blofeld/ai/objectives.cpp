#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(area_reference, k_maximum_areas_per_task)
{
	FIELD( _field_enum, "area type" ),
	FIELD( _field_byte_flags, "flags" ),
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

TAG_BLOCK(objectives, k_maximum_objectives_per_map)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_block, "opposing objectives", &opposing_objective_block ),
	FIELD( _field_word_flags, "objective flags" ),
	FIELD( _field_short_block_index, "zone index*!" ),
	FIELD( _field_short_block_index, "first task index*!" ),
	FIELD( _field_short_block_index, "editor folder!" ),
	FIELD( _field_block, "tasks*!", &tasks_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(opposing_objective, k_maximum_opposing_objectives)
{
	FIELD( _field_short_block_index, "objective" ),
	FIELD( _field_pad, "pad0", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(tasks, k_maximum_tasks_per_objective)
{
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_word_flags, "inhibit groups" ),
	FIELD( _field_word_flags, "inhibit on difficulty" ),
	FIELD( _field_enum, "movement" ),
	FIELD( _field_enum, "follow" ),
	FIELD( _field_short_block_index, "follow squad" ),
	FIELD( _field_real, "follow radius" ),
	FIELD( _field_real, "follow Z clamp:wus#Don\'t follow at areas outside of this vertical margin" ),
	FIELD( _field_word_flags, "follow players" ),
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
	FIELD( _field_enum, "dialogue type#when someone enters this task for the first time, they play this type of dialogue" ),
	FIELD( _field_word_flags, "runtime flags*!" ),
	FIELD( _field_short_integer, "Kungfu count#The number of guys under this task that should be allowed to fight the player at a time" ),
	FIELD( _field_pad, "post-kungfu-count", 2 ),
	FIELD( _field_explanation, "UI-Controlled" ),
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_short_integer, "priority*" ),
	FIELD( _field_short_block_index, "first_child*" ),
	FIELD( _field_short_block_index, "next_sibling*" ),
	FIELD( _field_short_block_index, "parent*" ),
	FIELD( _field_block, "activation script", &script_fragment_block ),
	FIELD( _field_short_block_index, "script index *~" ),
	FIELD( _field_short_integer, "lifetime count#task will never want to suck in more then n guys over lifetime (soft ceiling only applied when limit exceeded" ),
	FIELD( _field_word_flags, "filter flags" ),
	FIELD( _field_enum, "filter" ),
	FIELD( _field_short_bounds, "capacity" ),
	FIELD( _field_short_integer, "max body count#task becomes inactive after the given number of casualties" ),
	FIELD( _field_enum, "attitude" ),
	FIELD( _field_real, "min strength:[0,1]#task becomes inactive after the strength of the participants falls below the given level" ),
	FIELD( _field_block, "areas", &area_reference_block ),
	FIELD( _field_block, "direction", &task_direction_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(script_fragment, 1)
{
	FIELD( _field_string_id, "script name*" ),
	FIELD( _field_long_string, "script source" ),
	FIELD( _field_enum, "compile state*" ),
	FIELD( _field_pad, "xcvh", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(task_direction, 1)
{
	FIELD( _field_block, "points", &task_direction_point_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(task_direction_point, k_max_points_per_task_direction)
{
	FIELD( _field_real_point_3d, "point0" ),
	FIELD( _field_custom_long_block_index, "packedKeyOffaceref~!" ),
	FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref~!" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

