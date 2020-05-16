#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(squad_patrol_block, k_max_squad_patrols_per_map)
{
	FIELD( _field_custom ),
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_block, "squads", &squad_patrol_member_block_block ),
	FIELD( _field_block, "points", &squad_patrol_point_block_block ),
	FIELD( _field_block, "transitions", &squad_patrol_transition_block_block ),
	FIELD( _field_short_block_index, "editor folder!" ),
	FIELD( _field_pad, "pad", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(squad_patrol_member_block, k_max_members_per_squad_patrol)
{
	FIELD( _field_short_block_index, "squad^" ),
	FIELD( _field_pad, "post-squad-pad", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(squad_patrol_point_block, k_max_points_per_squad_patrol)
{
	FIELD( _field_short_block_index, "objective^" ),
	FIELD( _field_pad, "post-objective-pad", 2 ),
	FIELD( _field_custom ),
	FIELD( _field_real, "hold time{occupy time}:seconds#How long the AI should pause at this point before searching" ),
	FIELD( _field_custom ),
	FIELD( _field_real, "search time:seconds#How long the AI should search at this point before returning" ),
	FIELD( _field_custom ),
	FIELD( _field_real, "pause time:seconds#How long the AI should pause at this point after searching before moving on" ),
	FIELD( _field_custom ),
	FIELD( _field_real, "cooldown time:seconds#How long after being abandoned should this point be available again" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(squad_patrol_transition_block, k_max_squad_patrol_transitions)
{
	FIELD( _field_short_block_index, "point1" ),
	FIELD( _field_short_block_index, "point2" ),
	FIELD( _field_block, "waypoints", &squad_patrol_waypoint_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(squad_patrol_waypoint_block, k_max_squad_patrol_waypoints_per_transition)
{
	FIELD( _field_real_point_3d, "position" ),
	FIELD( _field_custom_long_block_index, "packedKeyOffaceref~!" ),
	FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref~!" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

