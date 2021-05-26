#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	#define GAME_AUDIBILITY_BLOCK_ID { 0x73FDA6A6, 0x4E2A483E, 0xA308C3B1, 0xAD242965 }
	TAG_BLOCK(
		game_audibility_block,
		"game_audibility_block",
		k_maximum_scenario_zone_set_count,
		"s_game_audibility",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_AUDIBILITY_BLOCK_ID)
	{
		{ _field_long_integer, "door portal count" },
		{ _field_long_integer, "room count" },
		{ _field_real_bounds, "room distance bounds" },
		{ _field_block, "encoded door pas", &door_encoded_pas_block },
		{ _field_block, "room door portal encoded pas", &room_door_portal_encoded_pas_block },
		{ _field_block, "ai deafening pas", &ai_deafening_encoded_pas_block },
		{ _field_block, "room distances", &encoded_room_distances_block },
		{ _field_block, "game portal to door occluder mapping", &game_portal_to_door_occluder_block },
		{ _field_block, "bsp cluster to room bounds", &bsp_cluster_to_room_bounds_block },
		{ _field_block, "bsp cluster to room indices", &bsp_cluster_to_room_indices_block },
		{ _field_terminator }
	};

	#define DOOR_ENCODED_PAS_BLOCK_ID { 0x1FE14003, 0x355B4244, 0x9C611D68, 0x025CD191 }
	TAG_BLOCK(
		door_encoded_pas_block,
		"door_encoded_pas_block",
		k_maximum_audibility_door_count*2*((((k_maximum_rooms_per_game)+(k_int32_bits-1))>>k_int32_bits_bits)),
		"dword",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DOOR_ENCODED_PAS_BLOCK_ID)
	{
		{ _field_long_integer, "encoded data" },
		{ _field_terminator }
	};

	#define ROOM_DOOR_PORTAL_ENCODED_PAS_BLOCK_ID { 0x79C40107, 0xC34F4FFE, 0xA9B0E0BA, 0x40627A21 }
	TAG_BLOCK(
		room_door_portal_encoded_pas_block,
		"room_door_portal_encoded_pas_block",
		k_maximum_rooms_per_game*((((k_maximum_audibility_door_count)+(k_int32_bits-1))>>k_int32_bits_bits)),
		"dword",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ROOM_DOOR_PORTAL_ENCODED_PAS_BLOCK_ID)
	{
		{ _field_long_integer, "encoded data" },
		{ _field_terminator }
	};

	#define AI_DEAFENING_ENCODED_PAS_BLOCK_ID { 0x8229AF1A, 0x07484AF9, 0xB927F592, 0xE928E357 }
	TAG_BLOCK(
		ai_deafening_encoded_pas_block,
		"ai_deafening_encoded_pas_block",
		(((((k_maximum_rooms_per_game*(k_maximum_rooms_per_game-1))/2)+(k_int32_bits-1))>>k_int32_bits_bits)),
		"dword",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		AI_DEAFENING_ENCODED_PAS_BLOCK_ID)
	{
		{ _field_long_integer, "encoded data" },
		{ _field_terminator }
	};

	#define ENCODED_ROOM_DISTANCES_BLOCK_ID { 0x079EE95D, 0x71A0441D, 0x9947D8E4, 0x6865EE9B }
	TAG_BLOCK(
		encoded_room_distances_block,
		"encoded_room_distances_block",
		(k_maximum_rooms_per_game*(k_maximum_rooms_per_game-1))/2,
		"byte",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ENCODED_ROOM_DISTANCES_BLOCK_ID)
	{
		{ _field_char_integer, "encoded data" },
		{ _field_terminator }
	};

	#define GAME_PORTAL_TO_DOOR_OCCLUDER_BLOCK_ID { 0xD969E829, 0x574E4545, 0x9AEAA8B4, 0x755A88B9 }
	TAG_BLOCK(
		game_portal_to_door_occluder_block,
		"game_portal_to_door_occluder_block",
		MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO,
		"s_game_audibility_bsp_game_portal_mapping",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_PORTAL_TO_DOOR_OCCLUDER_BLOCK_ID)
	{
		{ _field_long_integer, "first door occluder index" },
		{ _field_long_integer, "door occluder count" },
		{ _field_terminator }
	};

	#define BSP_CLUSTER_TO_ROOM_BOUNDS_ID { 0xABDDE059, 0xBF8E4C35, 0xB3B79A93, 0x7AB91ED6 }
	TAG_BLOCK(
		bsp_cluster_to_room_bounds_block,
		"bsp_cluster_to_room_bounds",
		MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO,
		"s_game_audibility_bsp_mapping",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BSP_CLUSTER_TO_ROOM_BOUNDS_ID)
	{
		{ _field_long_integer, "first room index" },
		{ _field_long_integer, "room index count" },
		{ _field_terminator }
	};

	#define BSP_CLUSTER_TO_ROOM_INDICES_ID { 0x06A9CB1C, 0xDEEA451B, 0x89E0296C, 0x362F4EB6 }
	TAG_BLOCK(
		bsp_cluster_to_room_indices_block,
		"bsp_cluster_to_room_indices",
		k_maximum_audibility_room_count,
		"short",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BSP_CLUSTER_TO_ROOM_INDICES_ID)
	{
		{ _field_short_integer, "room index" },
		{ _field_terminator }
	};



} // namespace blofeld

