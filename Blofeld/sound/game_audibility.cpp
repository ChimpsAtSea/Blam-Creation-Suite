#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(game_audibility, k_maximum_scenario_zone_set_count)
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
	{ _field_terminator },
};

TAG_BLOCK(door_encoded_pas, k_maximum_audibility_door_count*2*((((k_maximum_rooms_per_game)+(k_int32_bits-1))>>k_int32_bits_bits)))
{
	{ _field_long_integer, "encoded data" },
	{ _field_terminator },
};

TAG_BLOCK(room_door_portal_encoded_pas, k_maximum_rooms_per_game*((((k_maximum_audibility_door_count)+(k_int32_bits-1))>>k_int32_bits_bits)))
{
	{ _field_long_integer, "encoded data" },
	{ _field_terminator },
};

TAG_BLOCK(ai_deafening_encoded_pas, (((((k_maximum_rooms_per_game*(k_maximum_rooms_per_game-1))/2)+(k_int32_bits-1))>>k_int32_bits_bits)))
{
	{ _field_long_integer, "encoded data" },
	{ _field_terminator },
};

TAG_BLOCK(encoded_room_distances, (k_maximum_rooms_per_game*(k_maximum_rooms_per_game-1))/2)
{
	{ _field_char_integer, "encoded data" },
	{ _field_terminator },
};

TAG_BLOCK(game_portal_to_door_occluder, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
{
	{ _field_long_integer, "first door occluder index" },
	{ _field_long_integer, "door occluder count" },
	{ _field_terminator },
};

TAG_BLOCK(bsp_cluster_to_room_bounds, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
{
	{ _field_long_integer, "first room index" },
	{ _field_long_integer, "room index count" },
	{ _field_terminator },
};

TAG_BLOCK(bsp_cluster_to_room_indices, k_maximum_audibility_room_count)
{
	{ _field_short_integer, "room index" },
	{ _field_terminator },
};

} // namespace blofeld

