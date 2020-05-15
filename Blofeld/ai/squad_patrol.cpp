#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(squad_patrol, k_max_squad_patrols_per_map)
{
	{ _field_custom },
	{ _field_string_id, "name^" },
	{ _field_block, "squads", &squad_patrol_member_block },
	{ _field_block, "points", &squad_patrol_point_block },
	{ _field_block, "transitions", &squad_patrol_transition_block },
	{ _field_short_block_index, "editor folder!" },
	{ _field_pad, "pad", 2 },
	{ _field_terminator },
};

TAG_BLOCK(squad_patrol_member, k_max_members_per_squad_patrol)
{
	{ _field_short_block_index, "squad^" },
	{ _field_pad, "post-squad-pad", 2 },
	{ _field_terminator },
};

TAG_BLOCK(squad_patrol_point, k_max_points_per_squad_patrol)
{
	{ _field_short_block_index, "objective^" },
	{ _field_pad, "post-objective-pad", 2 },
	{ _field_custom },
	{ _field_real, "hold time{occupy time}:seconds#How long the AI should pause at this point before searching" },
	{ _field_custom },
	{ _field_real, "search time:seconds#How long the AI should search at this point before returning" },
	{ _field_custom },
	{ _field_real, "pause time:seconds#How long the AI should pause at this point after searching before moving on" },
	{ _field_custom },
	{ _field_real, "cooldown time:seconds#How long after being abandoned should this point be available again" },
	{ _field_terminator },
};

TAG_BLOCK(squad_patrol_transition, k_max_squad_patrol_transitions)
{
	{ _field_short_block_index, "point1" },
	{ _field_short_block_index, "point2" },
	{ _field_block, "waypoints", &squad_patrol_waypoint_block },
	{ _field_terminator },
};

TAG_BLOCK(squad_patrol_waypoint, k_max_squad_patrol_waypoints_per_transition)
{
	{ _field_real_point_3d, "position" },
	{ _field_custom_long_block_index, "packedKeyOffaceref~!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref~!" },
	{ _field_terminator },
};

} // namespace blofeld

