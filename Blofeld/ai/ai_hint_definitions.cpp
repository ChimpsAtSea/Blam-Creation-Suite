#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(user_hint_block, 1)
{
	FIELD( _field_block, "line segment geometry", &user_hint_line_segment_block_block ),
	FIELD( _field_block, "parallelogram geometry", &user_hint_parallelogram_block_block ),
	FIELD( _field_block, "jump hints", &user_hint_jump_block_block ),
	FIELD( _field_block, "climb hints", &user_hint_climb_block_block ),
	FIELD( _field_block, "well hints", &user_hint_well_block_block ),
	FIELD( _field_block, "flight hints", &user_hint_flight_block_block ),
	FIELD( _field_block, "volume avoidance hints", &user_hint_volume_avoidance_block ),
	FIELD( _field_block, "spline hints", &user_hint_spline_block_block ),
	FIELD( _field_block, "cookie cutters", &user_hint_cookie_cutter_block_block ),
	FIELD( _field_block, "navmesh areas", &user_hint_navmesh_area_block_block ),
	FIELD( _field_block, "giant hints", &user_hint_giant_block_block ),
	FIELD( _field_block, "flood hints", &user_hint_flood_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(user_hint_line_segment_block, k_max_hint_geometries)
{
	FIELD( _field_long_flags, "Flags" ),
	FIELD( _field_real_point_3d, "Point 0" ),
	FIELD( _field_custom_long_block_index, "packedKeyOffaceref0~!" ),
	FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref0~!" ),
	FIELD( _field_real_point_3d, "Point 1" ),
	FIELD( _field_custom_long_block_index, "packedKeyOffaceref1~!" ),
	FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref1~!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(user_hint_parallelogram_block, k_max_hint_geometries)
{
	FIELD( _field_long_flags, "Flags" ),
	FIELD( _field_real_point_3d, "Point 0" ),
	FIELD( _field_custom_long_block_index, "packedKeyOffaceref0!" ),
	FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref0!" ),
	FIELD( _field_real_point_3d, "Point 1" ),
	FIELD( _field_custom_long_block_index, "packedKeyOffaceref1!" ),
	FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref1!" ),
	FIELD( _field_real_point_3d, "Point 2" ),
	FIELD( _field_custom_long_block_index, "packedKeyOffaceref2!" ),
	FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref2!" ),
	FIELD( _field_real_point_3d, "Point 3" ),
	FIELD( _field_custom_long_block_index, "packedKeyOffaceref3!" ),
	FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref3!" ),
	FIELD( _field_word_flags, "invalid_points*" ),
	FIELD( _field_pad, "KJHIUF", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(user_hint_jump_block, k_max_hint_geometries)
{
	FIELD( _field_enum, "hint type" ),
	FIELD( _field_short_block_index, "Squad group filter" ),
	FIELD( _field_block, "hint vertices*~", &hint_vertex_block_block ),
	FIELD( _field_long_integer, "hint data 0*" ),
	FIELD( _field_short_integer, "hint data 1*" ),
	FIELD( _field_byte_integer, "hint data 2*" ),
	FIELD( _field_byte_integer, "pad1*" ),
	FIELD( _field_word_flags, "Flags" ),
	FIELD( _field_short_block_index, "geometry index*" ),
	FIELD( _field_enum, "force jump height" ),
	FIELD( _field_word_flags, "control flags" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(hint_vertex_block, (1024))
{
	FIELD( _field_real_point_3d, "point*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(user_hint_climb_block, k_max_climb_hints)
{
	FIELD( _field_enum, "hint type" ),
	FIELD( _field_short_block_index, "Squad group filter" ),
	FIELD( _field_block, "hint vertices*~", &hint_vertex_block_block ),
	FIELD( _field_long_integer, "hint data 0*" ),
	FIELD( _field_short_integer, "hint data 1*" ),
	FIELD( _field_byte_integer, "hint data 2*" ),
	FIELD( _field_byte_integer, "pad1*" ),
	FIELD( _field_word_flags, "Flags" ),
	FIELD( _field_short_block_index, "geometry index*" ),
	FIELD( _field_enum, "force hoist height" ),
	FIELD( _field_pad, "post-forced-hoist-height", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(user_hint_well_block, k_max_hint_geometries)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_block, "points", &user_hint_well_point_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(user_hint_well_point_block, k_max_hint_geometries)
{
	FIELD( _field_enum, "type" ),
	FIELD( _field_pad, "CNXLP", 2 ),
	FIELD( _field_real_point_3d, "point" ),
	FIELD( _field_custom_long_block_index, "packedKeyOffaceref~!" ),
	FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref~!" ),
	FIELD( _field_real_euler_angles_2d, "normal" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(user_hint_flight_block, k_max_flight_hints_per_bsp)
{
	FIELD( _field_block, "points", &user_hint_flight_point_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(user_hint_flight_point_block, k_max_points_per_flight_hint)
{
	FIELD( _field_real_vector_3d, "point" ),
	FIELD( _field_terminator )
};

TAG_BLOCK_FROM_STRUCT(user_hint_volume_avoidance, k_max_avoidance_volumes_per_bsp, user_hint_volume_avoidance_struct_struct_definition );

TAG_BLOCK(user_hint_spline_block, k_max_spline_hints_per_bsp)
{
	FIELD( _field_string_id, "name" ),
	FIELD( _field_real, "radius:wus" ),
	FIELD( _field_real, "time between points:sec" ),
	FIELD( _field_block, "control points", &user_hint_spline_control_point_block_block ),
	FIELD( _field_short_block_index, "bsp" ),
	FIELD( _field_pad, "post-bsp-pad", 2 ),
	FIELD( _field_block, "volume intersect points*!", &user_hint_spline_intersect_point_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(user_hint_spline_control_point_block, k_max_control_points_per_spline_hint)
{
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "post-flags-pad", 2 ),
	FIELD( _field_real_point_3d, "point" ),
	FIELD( _field_real_vector_3d, "tangent" ),
	FIELD( _field_real, "segment arc length*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(user_hint_spline_intersect_point_block, 2)
{
	FIELD( _field_short_block_index, "volume index" ),
	FIELD( _field_pad, "post-volume-index-pad", 2 ),
	FIELD( _field_real_point_3d, "point" ),
	FIELD( _field_real_vector_3d, "tangent" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(user_hint_cookie_cutter_block, k_max_cookie_cutters)
{
	FIELD( _field_long_integer, "hkaiVolume vtable*~!" ),
	FIELD( _field_short_integer, "size*~!" ),
	FIELD( _field_short_integer, "count*~!" ),
	FIELD( _field_block, "points", &user_hint_sector_point_block_block ),
	FIELD( _field_block, "pointsObjectIds", &hint_object_id_block_block ),
	FIELD( _field_real, "z height" ),
	FIELD( _field_real, "z sink" ),
	FIELD( _field_enum, "type" ),
	FIELD( _field_short_integer, "pad*!" ),
	FIELD( _field_long_integer, "runtimeObjectTransformOverrideIndex*~!" ),
	FIELD( _field_char_integer, "invalid*!" ),
	FIELD( _field_char_integer, "pad2*!" ),
	FIELD( _field_char_integer, "pad3*!" ),
	FIELD( _field_char_integer, "pad4*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(user_hint_sector_point_block, k_maximum_points_per_sector)
{
	FIELD( _field_real_point_3d, "point" ),
	FIELD( _field_custom_long_block_index, "packedKeyOffaceref~!" ),
	FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref~!" ),
	FIELD( _field_real_euler_angles_2d, "normal" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(hint_object_id_block, k_maximum_points_per_sector)
{
	FIELD( _field_struct, "object ID*!", &scenario_object_id_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(user_hint_navmesh_area_block, k_max_navmesh_areas)
{
	FIELD( _field_long_integer, "hkaiVolume vtable*~!" ),
	FIELD( _field_short_integer, "size*~!" ),
	FIELD( _field_short_integer, "count*~!" ),
	FIELD( _field_block, "points", &user_hint_sector_point_block_block ),
	FIELD( _field_real, "z height" ),
	FIELD( _field_real, "z sink" ),
	FIELD( _field_real, "step height" ),
	FIELD( _field_long_enum, "type" ),
	FIELD( _field_real, "isValid*~!" ),
	FIELD( _field_explanation, "Max CONVEX Border Simplify Area" ),
	FIELD( _field_real, "Max CONVEX Border Simplify Area" ),
	FIELD( _field_explanation, "Max Border Distance Error" ),
	FIELD( _field_real, "Max Border Distance Error" ),
	FIELD( _field_explanation, "Max CONCAVE Border Simplify Area" ),
	FIELD( _field_real, "Max CONCAVE Border Simplify Area" ),
	FIELD( _field_explanation, "Max Walkable Slope" ),
	FIELD( _field_real, "Max Walkable Slope" ),
	FIELD( _field_explanation, "Cosine angle merge control" ),
	FIELD( _field_real, "Cosine angle merge control" ),
	FIELD( _field_explanation, "Hole replacement area" ),
	FIELD( _field_real, "Hole replacement area" ),
	FIELD( _field_explanation, "Partition size" ),
	FIELD( _field_long_integer, "Partition size" ),
	FIELD( _field_explanation, "Loop shrink factor" ),
	FIELD( _field_real, "Loop shrink factor" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(user_hint_giant_block, 1)
{
	FIELD( _field_block, "giant sector hints", &user_hint_giant_sector_block_block ),
	FIELD( _field_block, "giant rail hints", &user_hint_giant_rail_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(user_hint_giant_sector_block, k_max_hint_geometries)
{
	FIELD( _field_block, "points", &user_hint_sector_point_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(user_hint_giant_rail_block, k_max_hint_geometries)
{
	FIELD( _field_short_block_index, "geometry index*" ),
	FIELD( _field_pad, "JLOU", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(user_hint_flood_block, 1)
{
	FIELD( _field_block, "flood sector hints", &user_hint_flood_sector_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(user_hint_flood_sector_block, k_max_hint_geometries)
{
	FIELD( _field_block, "points", &user_hint_sector_point_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(special_movement_block, 1)
{
	FIELD( _field_long_flags, "Special movement 1" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(user_hint_volume_avoidance_struct)
{
	FIELD( _field_long_enum, "type" ),
	FIELD( _field_real_point_3d, "origin{center}" ),
	FIELD( _field_real, "radius" ),
	FIELD( _field_real_vector_3d, "facing vector#for pills" ),
	FIELD( _field_real, "height#for pills" ),
	FIELD( _field_short_block_index, "bsp" ),
	FIELD( _field_short_integer, "spline_count*!" ),
	FIELD( _field_short_integer, "zone_index*!" ),
	FIELD( _field_short_integer, "area_index*!" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

