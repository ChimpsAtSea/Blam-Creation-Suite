#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define SQUAD_PATROL_BLOCK_ID { 0xBA52B4CA, 0xAF324B33, 0x9B6A0F6F, 0xAD1274B9 }
	TAG_BLOCK(
		squad_patrol_block,
		"squad_patrol_block",
		k_max_squad_patrols_per_map,
		"s_squad_patrol_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SQUAD_PATROL_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_block, "squads", &squad_patrol_member_block },
		{ _field_block, "points", &squad_patrol_point_block },
		{ _field_block, "transitions", &squad_patrol_transition_block },
		{ _field_short_block_index, "editor folder", FIELD_FLAG_UNKNOWN0, &g_scenario_editor_folder_block, _field_id_hide },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define SQUAD_PATROL_MEMBER_BLOCK_ID { 0x8092823C, 0x0CE64669, 0xA842F833, 0xC9ACEABD }
	TAG_BLOCK(
		squad_patrol_member_block,
		"squad_patrol_member_block",
		k_max_members_per_squad_patrol,
		"s_squad_patrol_member_definition",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SQUAD_PATROL_MEMBER_BLOCK_ID)
	{
		{ _field_short_block_index, "squad", FIELD_FLAG_INDEX, &squads_block },
		FIELD_PAD("post-squad-pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define SQUAD_PATROL_POINT_BLOCK_ID { 0x19925340, 0x2CD7411C, 0x84AED8BA, 0x22F75B6D }
	TAG_BLOCK(
		squad_patrol_point_block,
		"squad_patrol_point_block",
		k_max_points_per_squad_patrol,
		"s_squad_patrol_point_definition",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SQUAD_PATROL_POINT_BLOCK_ID)
	{
		{ _field_short_block_index, "objective", FIELD_FLAG_INDEX, &objectives_block },
		FIELD_PAD("post-objective-pad", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_real, "hold time", "How long the AI should pause at this point before searching", "seconds", MAKE_OLD_NAMES("occupy time") },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_real, "search time", "How long the AI should search at this point before returning", "seconds" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_real, "pause time", "How long the AI should pause at this point after searching before moving on", "seconds" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_real, "cooldown time", "How long after being abandoned should this point be available again", "seconds" },
		{ _field_terminator }
	};

	#define SQUAD_PATROL_TRANSITION_BLOCK_ID { 0x70647FDE, 0x5A0449E6, 0x8491538C, 0xAFE36794 }
	TAG_BLOCK(
		squad_patrol_transition_block,
		"squad_patrol_transition_block",
		k_max_squad_patrol_transitions,
		"s_squad_patrol_transition_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SQUAD_PATROL_TRANSITION_BLOCK_ID)
	{
		{ _field_short_block_index, "point1", &squad_patrol_point_block },
		{ _field_short_block_index, "point2", &squad_patrol_point_block },
		{ _field_block, "waypoints", &squad_patrol_waypoint_block },
		{ _field_terminator }
	};

	#define SQUAD_PATROL_WAYPOINT_BLOCK_ID { 0xE428A1E3, 0x735A4EF2, 0xB58F05F6, 0x703A8167 }
	TAG_BLOCK(
		squad_patrol_waypoint_block,
		"squad_patrol_waypoint_block",
		k_max_squad_patrol_waypoints_per_transition,
		"s_squad_patrol_waypoint_definition",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE),
		SQUAD_PATROL_WAYPOINT_BLOCK_ID)
	{
		{ _field_real_point_3d, "position" },
		{ _field_custom_long_block_index, "packedKeyOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

