#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(user_hint, 1)
{
	{ _field_block, "line segment geometry", &user_hint_line_segment_block },
	{ _field_block, "parallelogram geometry", &user_hint_parallelogram_block },
	{ _field_block, "jump hints", &user_hint_jump_block },
	{ _field_block, "climb hints", &user_hint_climb_block },
	{ _field_block, "well hints", &user_hint_well_block },
	{ _field_block, "flight hints", &user_hint_flight_block },
	{ _field_block, "volume avoidance hints", &user_hint_volume_avoidance_block },
	{ _field_block, "spline hints", &user_hint_spline_block },
	{ _field_block, "cookie cutters", &user_hint_cookie_cutter_block },
	{ _field_block, "navmesh areas", &user_hint_navmesh_area_block },
	{ _field_block, "giant hints", &user_hint_giant_block },
	{ _field_block, "flood hints", &user_hint_flood_block },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_line_segment, k_max_hint_geometries)
{
	{ _field_long_flags, "Flags" },
	{ _field_real_point_3d, "Point 0" },
	{ _field_custom_long_block_index, "packedKeyOffaceref0~!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref0~!" },
	{ _field_real_point_3d, "Point 1" },
	{ _field_custom_long_block_index, "packedKeyOffaceref1~!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref1~!" },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_parallelogram, k_max_hint_geometries)
{
	{ _field_long_flags, "Flags" },
	{ _field_real_point_3d, "Point 0" },
	{ _field_custom_long_block_index, "packedKeyOffaceref0!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref0!" },
	{ _field_real_point_3d, "Point 1" },
	{ _field_custom_long_block_index, "packedKeyOffaceref1!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref1!" },
	{ _field_real_point_3d, "Point 2" },
	{ _field_custom_long_block_index, "packedKeyOffaceref2!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref2!" },
	{ _field_real_point_3d, "Point 3" },
	{ _field_custom_long_block_index, "packedKeyOffaceref3!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref3!" },
	{ _field_word_flags, "invalid_points*" },
	{ _field_pad, "KJHIUF", 2 },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_jump, k_max_hint_geometries)
{
	{ _field_enum, "hint type" },
	{ _field_short_block_index, "Squad group filter" },
	{ _field_block, "hint vertices*~", &hint_vertex_block },
	{ _field_long_integer, "hint data 0*" },
	{ _field_short_integer, "hint data 1*" },
	{ _field_byte_integer, "hint data 2*" },
	{ _field_byte_integer, "pad1*" },
	{ _field_word_flags, "Flags" },
	{ _field_short_block_index, "geometry index*" },
	{ _field_enum, "force jump height" },
	{ _field_word_flags, "control flags" },
	{ _field_terminator },
};

TAG_BLOCK(hint_vertex, (1024))
{
	{ _field_real_point_3d, "point*" },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_climb, k_max_climb_hints)
{
	{ _field_enum, "hint type" },
	{ _field_short_block_index, "Squad group filter" },
	{ _field_block, "hint vertices*~", &hint_vertex_block },
	{ _field_long_integer, "hint data 0*" },
	{ _field_short_integer, "hint data 1*" },
	{ _field_byte_integer, "hint data 2*" },
	{ _field_byte_integer, "pad1*" },
	{ _field_word_flags, "Flags" },
	{ _field_short_block_index, "geometry index*" },
	{ _field_enum, "force hoist height" },
	{ _field_pad, "post-forced-hoist-height", 2 },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_well, k_max_hint_geometries)
{
	{ _field_long_flags, "flags" },
	{ _field_block, "points", &user_hint_well_point_block },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_well_point, k_max_hint_geometries)
{
	{ _field_enum, "type" },
	{ _field_pad, "CNXLP", 2 },
	{ _field_real_point_3d, "point" },
	{ _field_custom_long_block_index, "packedKeyOffaceref~!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref~!" },
	{ _field_real_euler_angles_2d, "normal" },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_flight, k_max_flight_hints_per_bsp)
{
	{ _field_block, "points", &user_hint_flight_point_block },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_flight_point, k_max_points_per_flight_hint)
{
	{ _field_real_vector_3d, "point" },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_volume_avoidance, k_max_avoidance_volumes_per_bsp)
{
	{ _field_long_enum, "type" },
	{ _field_real_point_3d, "origin{center}" },
	{ _field_real, "radius" },
	{ _field_real_vector_3d, "facing vector#for pills" },
	{ _field_real, "height#for pills" },
	{ _field_short_block_index, "bsp" },
	{ _field_short_integer, "spline_count*!" },
	{ _field_short_integer, "zone_index*!" },
	{ _field_short_integer, "area_index*!" },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_spline, k_max_spline_hints_per_bsp)
{
	{ _field_string_id, "name" },
	{ _field_real, "radius:wus" },
	{ _field_real, "time between points:sec" },
	{ _field_block, "control points", &user_hint_spline_control_point_block },
	{ _field_short_block_index, "bsp" },
	{ _field_pad, "post-bsp-pad", 2 },
	{ _field_block, "volume intersect points*!", &user_hint_spline_intersect_point_block },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_spline_control_point, k_max_control_points_per_spline_hint)
{
	{ _field_word_flags, "flags" },
	{ _field_pad, "post-flags-pad", 2 },
	{ _field_real_point_3d, "point" },
	{ _field_real_vector_3d, "tangent" },
	{ _field_real, "segment arc length*!" },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_spline_intersect_point, 2)
{
	{ _field_short_block_index, "volume index" },
	{ _field_pad, "post-volume-index-pad", 2 },
	{ _field_real_point_3d, "point" },
	{ _field_real_vector_3d, "tangent" },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_cookie_cutter, k_max_cookie_cutters)
{
	{ _field_long_integer, "hkaiVolume vtable*~!" },
	{ _field_short_integer, "size*~!" },
	{ _field_short_integer, "count*~!" },
	{ _field_block, "points", &user_hint_sector_point_block },
	{ _field_block, "pointsObjectIds", &hint_object_id_block },
	{ _field_real, "z height" },
	{ _field_real, "z sink" },
	{ _field_enum, "type" },
	{ _field_short_integer, "pad*!" },
	{ _field_long_integer, "runtimeObjectTransformOverrideIndex*~!" },
	{ _field_char_integer, "invalid*!" },
	{ _field_char_integer, "pad2*!" },
	{ _field_char_integer, "pad3*!" },
	{ _field_char_integer, "pad4*!" },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_sector_point, k_maximum_points_per_sector)
{
	{ _field_real_point_3d, "point" },
	{ _field_custom_long_block_index, "packedKeyOffaceref~!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref~!" },
	{ _field_real_euler_angles_2d, "normal" },
	{ _field_terminator },
};

TAG_BLOCK(hint_object_id, k_maximum_points_per_sector)
{
	{ _field_struct, "object ID*!" },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_navmesh_area, k_max_navmesh_areas)
{
	{ _field_long_integer, "hkaiVolume vtable*~!" },
	{ _field_short_integer, "size*~!" },
	{ _field_short_integer, "count*~!" },
	{ _field_block, "points", &user_hint_sector_point_block },
	{ _field_real, "z height" },
	{ _field_real, "z sink" },
	{ _field_real, "step height" },
	{ _field_long_enum, "type" },
	{ _field_real, "isValid*~!" },
	{ _field_explanation, "Max CONVEX Border Simplify Area" },
	{ _field_real, "Max CONVEX Border Simplify Area" },
	{ _field_explanation, "Max Border Distance Error" },
	{ _field_real, "Max Border Distance Error" },
	{ _field_explanation, "Max CONCAVE Border Simplify Area" },
	{ _field_real, "Max CONCAVE Border Simplify Area" },
	{ _field_explanation, "Max Walkable Slope" },
	{ _field_real, "Max Walkable Slope" },
	{ _field_explanation, "Cosine angle merge control" },
	{ _field_real, "Cosine angle merge control" },
	{ _field_explanation, "Hole replacement area" },
	{ _field_real, "Hole replacement area" },
	{ _field_explanation, "Partition size" },
	{ _field_long_integer, "Partition size" },
	{ _field_explanation, "Loop shrink factor" },
	{ _field_real, "Loop shrink factor" },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_giant, 1)
{
	{ _field_block, "giant sector hints", &user_hint_giant_sector_block },
	{ _field_block, "giant rail hints", &user_hint_giant_rail_block },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_giant_sector, k_max_hint_geometries)
{
	{ _field_block, "points", &user_hint_sector_point_block },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_giant_rail, k_max_hint_geometries)
{
	{ _field_short_block_index, "geometry index*" },
	{ _field_pad, "JLOU", 2 },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_flood, 1)
{
	{ _field_block, "flood sector hints", &user_hint_flood_sector_block },
	{ _field_terminator },
};

TAG_BLOCK(user_hint_flood_sector, k_max_hint_geometries)
{
	{ _field_block, "points", &user_hint_sector_point_block },
	{ _field_terminator },
};

TAG_BLOCK(special_movement, 1)
{
	{ _field_long_flags, "Special movement 1" },
	{ _field_terminator },
};

} // namespace blofeld

