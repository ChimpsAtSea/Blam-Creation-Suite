#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(zone, k_max_zones_per_map)
{
	{ _field_custom },
	{ _field_custom },
	{ _field_custom },
	{ _field_string, "name^" },
	{ _field_word_flags, "flags" },
	{ _field_short_block_index, "editor folder index!" },
	{ _field_block, "firing positions", &firing_positions_block },
	{ _field_block, "areas", &areas_block },
	{ _field_struct, "Nav Mesh Attachments*" },
	{ _field_struct, "disallowed attachment bsps" },
	{ _field_terminator },
};

TAG_BLOCK(areas, k_max_areas_per_zone)
{
	{ _field_custom },
	{ _field_custom },
	{ _field_custom },
	{ _field_custom },
	{ _field_long_integer, "hkaiVolume vtable*~!" },
	{ _field_short_integer, "size*~!" },
	{ _field_short_integer, "count*~!" },
	{ _field_string, "name^`" },
	{ _field_long_flags, "area flags" },
	{ _field_real_point_3d, "runtime relative mean point!" },
	{ _field_custom_long_block_index, "packedKeyOffaceref~!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref~!" },
	{ _field_real, "runtime standard deviation!" },
	{ _field_short_integer, "runtime starting index!" },
	{ _field_short_integer, "runtime count!" },
	{ _field_struct, "Nav Mesh Attachments*" },
	{ _field_array, "cluster occupancy!" },
	{ _field_block, "flight_hints", &flight_reference_block },
	{ _field_block, "points^", &area_sector_point_block },
	{ _field_explanation, "Generation Properties" },
	{ _field_enum, "preset" },
	{ _field_short_integer, "runtimeCarverInversion*~!" },
	{ _field_long_flags, "flags" },
	{ _field_real, "extrusion" },
	{ _field_real, "sink" },
	{ _field_angle, "firing point orientation" },
	{ _field_angle, "grid orientation" },
	{ _field_real, "nav volume cell size" },
	{ _field_real, "spacing*" },
	{ _field_real, "airborne spacing*" },
	{ _field_real, "min cover length*" },
	{ _field_real, "cover spacing*" },
	{ _field_real, "cover offset distance*" },
	{ _field_real, "too close distance*" },
	{ _field_terminator },
};

TAG_BLOCK(flight_reference, k_max_flight_references_per_area)
{
	{ _field_short_integer, "flight hint index" },
	{ _field_short_integer, "point index" },
	{ _field_short_integer, "structure index" },
	{ _field_pad, "post-structure-index-pad", 2 },
	{ _field_terminator },
};

TAG_BLOCK(area_sector_point, k_maximum_points_per_sector)
{
	{ _field_real_point_3d, "point" },
	{ _field_custom_long_block_index, "packedKeyOffaceref~!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref~!" },
	{ _field_real_euler_angles_2d, "normal" },
	{ _field_terminator },
};

} // namespace blofeld

