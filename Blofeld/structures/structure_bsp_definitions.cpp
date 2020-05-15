#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(structure_edge_to_seam_edge_mapping, ((true) ? 2621440 : UNSIGNED_SHORT_MAX))
{
	{ _field_short_integer, "seam_index*!" },
	{ _field_short_integer, "seam_edge_index*!" },
	{ _field_terminator },
};

TAG_BLOCK(structure_collision_materials, MAXIMUM_COLLISION_MATERIALS_PER_STRUCTURE)
{
	{ _field_tag_reference, "render method{old shader}*^" },
	{ _field_string_id, "override material name" },
	{ _field_short_integer, "runtime global material index!" },
	{ _field_short_block_index, "conveyor surface index*" },
	{ _field_short_block_index, "seam mapping index*" },
	{ _field_word_flags, "flags*" },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_leaf, ((true) ? 16*((1<<(k_bsp3d_node_child_index_bits-1))) : ((1<<(k_bsp3d_node_child_index_bits-1)))))
{
	{ _field_byte_integer, "cluster*" },
	{ _field_terminator },
};

TAG_BLOCK(structure_super_node_aabbs, (k_bsp3d_maximum_super_node_count)*k_super_node_child_indices_count)
{
	{ _field_real, "x0" },
	{ _field_real, "x1" },
	{ _field_real, "y0" },
	{ _field_real, "y1" },
	{ _field_real, "z0" },
	{ _field_real, "z1" },
	{ _field_terminator },
};

TAG_BLOCK(super_node_mappings, (k_bsp3d_maximum_super_node_count))
{
	{ _field_short_integer, "parent_super_node_index!*" },
	{ _field_char_integer, "parent_internal_node_index!*" },
	{ _field_byte_flags, "flags!*" },
	{ _field_long_integer, "has_traversal_geometry_mask!*" },
	{ _field_short_block_index, "first_traversal_geometry_index!*" },
	{ _field_short_block_index, "first_aabb_index!*" },
	{ _field_long_integer, "aabb_mask!*" },
	{ _field_short_block_index, "non_terminal_traversal_geometry_index!*" },
	{ _field_pad, "pad", 2 },
	{ _field_terminator },
};

TAG_BLOCK(super_node_recursable_masks, (k_bsp3d_maximum_super_node_count))
{
	{ _field_short_integer, "mask!*" },
	{ _field_terminator },
};

TAG_BLOCK(structure_super_node_traversal_geometry, k_short_max)
{
	{ _field_block, "portal_indices!*", &structure_super_node_traversal_geometry_indices_block },
	{ _field_block, "seam_indices!*", &structure_super_node_traversal_geometry_indices_block },
	{ _field_terminator },
};

TAG_BLOCK(structure_super_node_traversal_geometry_indices, ((MAXIMUM_CLUSTER_PORTALS_PER_STRUCTURE)>(k_structure_seam_maximum_seam_count)?(MAXIMUM_CLUSTER_PORTALS_PER_STRUCTURE):(k_structure_seam_maximum_seam_count)))
{
	{ _field_short_integer, "index!*" },
	{ _field_terminator },
};

TAG_BLOCK(structure_surface, ((true) ? SHORT_MAX<<3 : SHORT_MAX))
{
	{ _field_long_integer, "first_structure_surface_to_triangle_mapping_index*" },
	{ _field_long_integer, "structure_surface_to_triangle_mapping_count*" },
	{ _field_terminator },
};

TAG_BLOCK(structure_surface_to_triangle_mapping, (8*((true) ? SHORT_MAX<<3 : SHORT_MAX)))
{
	{ _field_dword_integer, "manual byteswarp1*" },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_cluster_portal, MAXIMUM_CLUSTER_PORTALS_PER_STRUCTURE)
{
	{ _field_struct, "oriented bounds" },
	{ _field_short_integer, "back cluster*" },
	{ _field_short_integer, "front cluster*" },
	{ _field_long_integer, "plane index*" },
	{ _field_real_point_3d, "centroid*" },
	{ _field_real, "bounding radius*" },
	{ _field_long_flags, "flags*" },
	{ _field_block, "vertices*", &structure_bsp_cluster_portal_vertex_block },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_cluster_portal_vertex, MAXIMUM_VERTICES_PER_CLUSTER_PORTAL)
{
	{ _field_real_point_3d, "point*" },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_detail_object_data, 1)
{
	{ _field_block, "cells", &global_detail_object_cells_block },
	{ _field_block, "instances", &global_detail_object_block },
	{ _field_block, "counts", &global_detail_object_counts_block },
	{ _field_block, "z reference vectors", &global_z_reference_vector_block },
	{ _field_pad, "KXILLD", 1 },
	{ _field_pad, "EDFPN", 3 },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_cluster, MAXIMUM_CLUSTERS_PER_STRUCTURE)
{
	{ _field_explanation, "CLUSTER INFO" },
	{ _field_real_bounds, "bounds x*" },
	{ _field_real_bounds, "bounds y*" },
	{ _field_real_bounds, "bounds z*" },
	{ _field_pad, "DING", 1 },
	{ _field_char_integer, "atmosphere index*" },
	{ _field_char_integer, "camera fx index*" },
	{ _field_char_integer, "weather index*" },
	{ _field_short_block_index, "acoustics*" },
	{ _field_short_integer, "acoustics sound cluster index" },
	{ _field_short_integer, "runtime first decal index!" },
	{ _field_short_integer, "runtime decal cound!" },
	{ _field_word_flags, "flags" },
	{ _field_pad, "ERERRFQ", 2 },
	{ _field_block, "predicted resources*", &g_null_block },
	{ _field_block, "portals*", &structure_bsp_cluster_portal_index_block },
	{ _field_short_integer, "mesh index*" },
	{ _field_short_integer, "instance imposter cluster mopp index" },
	{ _field_block, "seam indices*!", &seam_indices_block },
	{ _field_block, "decorator groups*", &decorator_runtime_cluster_block },
	{ _field_block, "cheap light marker refs*", &cheap_light_marker_ref_block },
	{ _field_block, "pvs bound object identifiers*!", &pvs_bound_object_identifiers_block },
	{ _field_block, "pvs bound object references*!", &pvs_bound_object_references_block },
	{ _field_block, "cluster cubemaps", &structure_cluster_cubemap_block },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_cluster_portal_index, MAXIMUM_CLUSTER_PORTALS_PER_CLUSTER)
{
	{ _field_short_integer, "portal index*" },
	{ _field_terminator },
};

TAG_BLOCK(seam_indices, k_structure_seam_maximum_seam_count)
{
	{ _field_char_integer, "seam index*" },
	{ _field_terminator },
};

TAG_BLOCK(cheap_light_marker_ref, MAXIMUM_MARKERS_PER_STRUCTURE)
{
	{ _field_short_block_index, "cheap light reference reference" },
	{ _field_pad, "WHATIZZIT", 2 },
	{ _field_terminator },
};

TAG_BLOCK(pvs_bound_object_identifiers, k_maximum_scenario_object_datum_count)
{
	{ _field_struct, "object ID*!" },
	{ _field_terminator },
};

TAG_BLOCK(pvs_bound_object_references, k_maximum_scenario_object_datum_count)
{
	{ _field_struct, "scenario object reference*!" },
	{ _field_terminator },
};

TAG_BLOCK(structure_material_lighting_info, SHORT_MAX)
{
	{ _field_real, "emissive power" },
	{ _field_real_rgb_color, "emissive color" },
	{ _field_real, "emissive quality" },
	{ _field_real, "emissive focus" },
	{ _field_long_flags, "flags" },
	{ _field_real, "attenuation falloff" },
	{ _field_real, "attenuation cutoff" },
	{ _field_real, "bounce ratio" },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_sky_owner_cluster, MAXIMUM_SKIES_PER_SCENARIO)
{
	{ _field_short_integer, "cluster owner*" },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_conveyor_surface, MAXIMUM_COLLISION_MATERIALS_PER_STRUCTURE)
{
	{ _field_real_vector_3d, "u" },
	{ _field_real_vector_3d, "v" },
	{ _field_terminator },
};

TAG_BLOCK(structure_cookie_cutter_definition, k_kilo)
{
	{ _field_custom, "Cookie Cutter" },
	{ _field_struct, "collision model" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_marker, MAXIMUM_MARKERS_PER_STRUCTURE)
{
	{ _field_char_enum, "marker type*" },
	{ _field_pad, "pad", 3 },
	{ _field_string, "marker parameter*" },
	{ _field_real_quaternion, "rotation" },
	{ _field_real_point_3d, "position*" },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_marker_light_palette, MAXIMUM_MARKERS_PER_STRUCTURE)
{
	{ _field_tag_reference, "light tag" },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_marker_light_index, MAXIMUM_MARKERS_PER_STRUCTURE)
{
	{ _field_short_integer, "palette index" },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_runtime_decal, MAXIMUM_DECALS_PER_STRUCTURE)
{
	{ _field_short_integer, "decal palette index!" },
	{ _field_pad, "post-decal-palette-index-pad", 2 },
	{ _field_struct, "manual bsp flags" },
	{ _field_real_quaternion, "rotation*" },
	{ _field_real_point_3d, "position*" },
	{ _field_real, "scale_x(scale}*" },
	{ _field_real, "scale_y*" },
	{ _field_real, "cull angle" },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_environment_object_palette, MAXIMUM_ENVIRONMENT_OBJECT_PALETTE_ENTRIES_PER_STRUCTURE)
{
	{ _field_tag_reference, "definition^" },
	{ _field_tag_reference, "model" },
	{ _field_long_integer, "GVEYN!" },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_environment_object, MAXIMUM_ENVIRONMENT_OBJECTS_PER_STRUCTURE)
{
	{ _field_string, "name^" },
	{ _field_real_quaternion, "rotation" },
	{ _field_real_point_3d, "translation" },
	{ _field_real, "scale" },
	{ _field_short_block_index, "palette_index" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "QHUGQ", 1 },
	{ _field_long_integer, "unique id*" },
	{ _field_tag, "exported object type" },
	{ _field_string_id, "scenario object name" },
	{ _field_string_id, "variant name" },
	{ _field_terminator },
};

TAG_BLOCK(structure_instance_cluster_definition, k_maximum_cluster_to_instance_group_block_size)
{
	{ _field_long_flags, "flags" },
	{ _field_block, "instance group indices", &index_list_block },
	{ _field_terminator },
};

TAG_BLOCK(index_list, 4 * k_kilo)
{
	{ _field_word_integer, "index" },
	{ _field_terminator },
};

TAG_BLOCK(structure_instance_group_definition, 4 * k_kilo)
{
	{ _field_real_point_3d, "center" },
	{ _field_real, "radius" },
	{ _field_short_integer, "cluster count" },
	{ _field_word_flags, "flags" },
	{ _field_real, "maximum imposter distance*" },
	{ _field_real, "minimum centrifugal distance from group center*" },
	{ _field_real, "minimum imposter distance squared*" },
	{ _field_block, "instance indices", &index_list_block },
	{ _field_terminator },
};

TAG_BLOCK(structure_instance_imposter_info, k_maximum_instance_geometry_instances_per_structure_bsp)
{
	{ _field_string_id, "name" },
	{ _field_char_integer, "imposter policy" },
	{ _field_pad, "parasdd", 3 },
	{ _field_real, "transition distance" },
	{ _field_terminator },
};

TAG_BLOCK(runtime_decorator_set, MAXIMUM_DECORATOR_SETS_PER_SCENARIO)
{
	{ _field_tag_reference, "decorator set reference*" },
	{ _field_terminator },
};

TAG_BLOCK(bsp_preplaced_decal_set_reference, MAXIMUM_DECALS_PER_STRUCTURE)
{
	{ _field_long_integer, "decal definition index!" },
	{ _field_char_integer, "location bsp 0!" },
	{ _field_byte_integer, "location cluster 0!" },
	{ _field_char_integer, "location bsp 1!" },
	{ _field_byte_integer, "location cluster 1!" },
	{ _field_char_integer, "location bsp 2!" },
	{ _field_byte_integer, "location cluster 2!" },
	{ _field_char_integer, "location bsp 3!" },
	{ _field_byte_integer, "location cluster 3!" },
	{ _field_real_point_3d, "center*" },
	{ _field_short_integer, "first decal ref index!" },
	{ _field_short_integer, "decal ref count!" },
	{ _field_terminator },
};

TAG_BLOCK(bsp_preplaced_decal_reference, MAXIMUM_DECALS_PER_STRUCTURE)
{
	{ _field_short_integer, "index start" },
	{ _field_short_integer, "index count" },
	{ _field_short_integer, "vertex start" },
	{ _field_short_integer, "vertex count" },
	{ _field_short_integer, "definition block index" },
	{ _field_pad, "paddddg", 2 },
	{ _field_real_point_2d, "spirit corner" },
	{ _field_real_vector_2d, "spirit size" },
	{ _field_terminator },
};

TAG_BLOCK(transparent_planes, 32*k_kilo)
{
	{ _field_short_integer, "section index" },
	{ _field_short_integer, "part index" },
	{ _field_real_plane_3d, "plane" },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_debug_info, 1)
{
	{ _field_pad, "BRQYEF", 64 },
	{ _field_block, "clusters*", &structure_bsp_cluster_debug_info_block },
	{ _field_block, "fog planes*", &structure_bsp_fog_plane_debug_info_block },
	{ _field_block, "fog zones*", &structure_bsp_fog_zone_debug_info_block },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_cluster_debug_info, MAXIMUM_CLUSTERS_PER_STRUCTURE)
{
	{ _field_word_flags, "errors*" },
	{ _field_word_flags, "warnings*" },
	{ _field_pad, "KHWRB", 28 },
	{ _field_block, "lines*", &structure_bsp_debug_info_render_line_block },
	{ _field_block, "fog plane indices*", &structure_bsp_debug_info_indices_block },
	{ _field_block, "visible fog plane indices*", &structure_bsp_debug_info_indices_block },
	{ _field_block, "vis-fog omission cluster indices*", &structure_bsp_debug_info_indices_block },
	{ _field_block, "containing fog zone indices*", &structure_bsp_debug_info_indices_block },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_debug_info_render_line, SHORT_MAX)
{
	{ _field_enum, "type*" },
	{ _field_short_integer, "code*" },
	{ _field_short_integer, "pad thai*" },
	{ _field_pad, "BNQS", 2 },
	{ _field_real_point_3d, "point 0*" },
	{ _field_real_point_3d, "point 1*" },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_debug_info_indices, SHORT_MAX)
{
	{ _field_long_integer, "index*" },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_fog_plane_debug_info, MAXIMUM_FOG_PLANES_PER_STRUCTURE)
{
	{ _field_long_integer, "fog zone index*" },
	{ _field_pad, "WZGH", 24 },
	{ _field_long_integer, "connected plane designator*" },
	{ _field_block, "lines*", &structure_bsp_debug_info_render_line_block },
	{ _field_block, "intersected cluster indices*", &structure_bsp_debug_info_indices_block },
	{ _field_block, "inf. extent cluster indices*", &structure_bsp_debug_info_indices_block },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_fog_zone_debug_info, MAXIMUM_FOG_ZONES_PER_STRUCTURE)
{
	{ _field_long_integer, "media index:scenario fog plane*" },
	{ _field_long_integer, "base fog plane index*" },
	{ _field_pad, "RB", 24 },
	{ _field_block, "lines*", &structure_bsp_debug_info_render_line_block },
	{ _field_block, "immersed cluster indices*", &structure_bsp_debug_info_indices_block },
	{ _field_block, "bounding fog plane indices*", &structure_bsp_debug_info_indices_block },
	{ _field_block, "collision fog plane indices*", &structure_bsp_debug_info_indices_block },
	{ _field_terminator },
};

TAG_BLOCK(widget_reference, MAXIMUM_MARKERS_PER_STRUCTURE)
{
	{ _field_short_integer, "marker index*" },
	{ _field_pad, "gnlao", 2 },
	{ _field_tag_reference, "widget ref*" },
	{ _field_terminator },
};

TAG_BLOCK(cheap_light_reference, MAXIMUM_MARKERS_PER_STRUCTURE)
{
	{ _field_short_integer, "marker index*" },
	{ _field_pad, "ldajk", 2 },
	{ _field_tag_reference, "cheap light*" },
	{ _field_terminator },
};

TAG_BLOCK(structure_external_instanced_geometry_references, k_external_instanced_geometry_max)
{
	{ _field_tag_reference, "prefab reference" },
	{ _field_string_id, "name*^" },
	{ _field_real, "scale" },
	{ _field_real_vector_3d, "forward" },
	{ _field_real_vector_3d, "left" },
	{ _field_real_vector_3d, "up" },
	{ _field_real_point_3d, "position" },
	{ _field_short_integer, "mesh count!" },
	{ _field_short_integer, "mesh block index!" },
	{ _field_short_integer, "light count!" },
	{ _field_short_integer, "light instance block index!" },
	{ _field_short_integer, "dynamic object count!" },
	{ _field_short_integer, "dynamic object block index!" },
	{ _field_word_flags, "override flags" },
	{ _field_pad, "SDFSDEE", 2 },
	{ _field_char_enum, "override pathfinding policy" },
	{ _field_char_enum, "override lightmapping policy" },
	{ _field_char_enum, "override imposter policy" },
	{ _field_char_enum, "override streaming priority*" },
	{ _field_real, "override lightmap resolution scale" },
	{ _field_real, "override imposter transition distance" },
	{ _field_real, "override imposter brightness" },
	{ _field_real, "override light channel flags" },
	{ _field_word_flags, "instance flags Mask" },
	{ _field_word_flags, "instance policy mask" },
	{ _field_terminator },
};

TAG_BLOCK(structure_bsp_obb_volume, 4096)
{
	{ _field_real_point_3d, "origin" },
	{ _field_real_vector_3d, "axis 1" },
	{ _field_real_vector_3d, "axis 2" },
	{ _field_real_vector_3d, "axis 3" },
	{ _field_dword_integer, "type" },
	{ _field_terminator },
};

TAG_BLOCK(AnimGraphDependencyBlock, 256)
{
	{ _field_tag_reference, "graph" },
	{ _field_terminator },
};

TAG_BLOCK(structureBspFxMarkerBlock, MAXIMUM_MARKERS_PER_STRUCTURE)
{
	{ _field_string, "marker name^" },
	{ _field_real_quaternion, "rotation*" },
	{ _field_real_point_3d, "position*" },
	{ _field_tag_reference, "optional attached effect" },
	{ _field_terminator },
};

TAG_BLOCK(structureMetadataLightConeMarkerBlock, MAXIMUM_MARKERS_PER_STRUCTURE)
{
	{ _field_string, "marker name^" },
	{ _field_real_quaternion, "rotation" },
	{ _field_real_point_3d, "position" },
	{ _field_real, "length" },
	{ _field_real, "width" },
	{ _field_real, "intensity" },
	{ _field_real_argb_color, "light color" },
	{ _field_tag_reference, "light cone tag" },
	{ _field_tag_reference, "intensity curve" },
	{ _field_terminator },
};

TAG_GROUP(prefab, PREFAB_TAG)
{
	{ _field_tag_reference, "bsp reference" },
	{ _field_terminator },
};

TAG_GROUP(scenario_structure_bsp, SCENARIO_STRUCTURE_BSP_TAG)
{
	{ _field_struct, "build identifier*" },
	{ _field_struct, "parent build identifier*" },
	{ _field_long_integer, "import info checksum*" },
	{ _field_tag_reference, "structure lighting_info^" },
	{ _field_long_integer, "import version*!" },
	{ _field_tag_reference, "structure meta data*" },
	{ _field_word_flags, "flags*!" },
	{ _field_word_flags, "content policy flags*!" },
	{ _field_word_flags, "failed content policy flags*!" },
	{ _field_pad, "faild policy pad*!", 2 },
	{ _field_block, "seam identifiers*!", &structure_seam_mapping_block },
	{ _field_block, "edge to seam edge*!", &structure_edge_to_seam_edge_mapping_block },
	{ _field_block, "collision materials*", &structure_collision_materials_block },
	{ _field_block, "leaves*!", &structure_bsp_leaf_block },
	{ _field_block, "super aabbs*!", &structure_super_node_aabbs_block },
	{ _field_block, "super node parent mappings*!", &super_node_mappings_block },
	{ _field_block, "super node recursable_masks*!", &super_node_recursable_masks_block },
	{ _field_block, "structure_super_node_traversal_geometry_block*!", &structure_super_node_traversal_geometry_block },
	{ _field_struct, "instance kd hierarchy!" },
	{ _field_real_bounds, "world bounds x*" },
	{ _field_real_bounds, "world bounds y*" },
	{ _field_real_bounds, "world bounds z*" },
	{ _field_block, "large structure surfaces*", &structure_surface_block },
	{ _field_block, "structure surface to triangle mapping*", &structure_surface_to_triangle_mapping_block },
	{ _field_block, "cluster portals*", &structure_bsp_cluster_portal_block },
	{ _field_block, "detail objects*", &structure_bsp_detail_object_data_block },
	{ _field_block, "clusters*", &structure_bsp_cluster_block },
	{ _field_block, "materials*", &global_geometry_material_block },
	{ _field_block, "emissive materials*", &structure_material_lighting_info_block },
	{ _field_block, "sky owner cluster*", &structure_bsp_sky_owner_cluster_block },
	{ _field_block, "conveyor surfaces*", &structure_bsp_conveyor_surface_block },
	{ _field_block, "breakable surface sets*", &breakable_surface_set_block },
	{ _field_block, "pathfinding data", &pathfinding_data_block },
	{ _field_block, "cookie cutters", &structure_cookie_cutter_definition_block },
	{ _field_block, "acoustics palette", &scenario_acoustics_palette_block },
	{ _field_data, "sound PAS data*" },
	{ _field_block, "markers*", &structure_bsp_marker_block },
	{ _field_block, "marker light palette*", &structure_bsp_marker_light_palette_block },
	{ _field_block, "marker light palette index*", &structure_bsp_marker_light_index_block },
	{ _field_block, "runtime decals*", &structure_bsp_runtime_decal_block },
	{ _field_block, "(DEPRECATED) environment object palette*", &structure_bsp_environment_object_palette_block },
	{ _field_block, "(DEPRECATED) environment objects*", &structure_bsp_environment_object_block },
	{ _field_pad, "IMISWXUG", 4 },
	{ _field_block, "leaf map leaves*", &global_map_leaf_block },
	{ _field_block, "leaf map connections*", &global_leaf_connection_block },
	{ _field_block, "errors*", &global_error_report_categories_block },
	{ _field_block, "cluster to instance group mopps", &mopp_code_definition_block },
	{ _field_block, "instance group to instance mopps", &mopp_code_definition_block },
	{ _field_block, "cluster to instance group spheres", &structure_instance_cluster_definition_block },
	{ _field_block, "instance group to instance spheres", &structure_instance_group_definition_block },
	{ _field_block, "instanced geometry instances*", &structure_bsp_instanced_geometry_instances_block },
	{ _field_block, "instanced geometry instance names*", &structure_bsp_instanced_geometry_instances_names_block },
	{ _field_tag_reference, "instance imposters" },
	{ _field_block, "instance imposter infos", &structure_instance_imposter_info_block },
	{ _field_long_integer, "Instance Geometry Tag Instance Count!" },
	{ _field_custom, "decorator info" },
	{ _field_block, "decorator sets*", &runtime_decorator_set_block },
	{ _field_struct, "decorator instance buffer!*" },
	{ _field_custom },
	{ _field_custom, "decals info" },
	{ _field_block, "preplaced decal sets*", &bsp_preplaced_decal_set_reference_block },
	{ _field_block, "preplaced decals*", &bsp_preplaced_decal_reference_block },
	{ _field_struct, "preplaced decal geometry!*" },
	{ _field_custom },
	{ _field_block, "acoustics sound clusters!", &structure_bsp_sound_cluster_block },
	{ _field_block, "transparent planes*", &transparent_planes_block },
	{ _field_block, "debug info*", &structure_bsp_debug_info_block },
	{ _field_struct, "structure_physics*" },
	{ _field_struct, "render geometry*" },
	{ _field_block, "widget references", &widget_reference_block },
	{ _field_block, "cheap light references", &cheap_light_reference_block },
	{ _field_struct, "resource interface" },
	{ _field_custom, "Any Platform Temporary Storage" },
	{ _field_block, "Any Platform Temp Havok Data*!", &structureIOHavokDataBlock_block },
	{ _field_custom },
	{ _field_block, "external references", &structure_external_instanced_geometry_references_block },
	{ _field_tag_reference, "dependencies" },
	{ _field_long_integer, "base material count*!" },
	{ _field_block, "obb volume list", &structure_bsp_obb_volume_block },
	{ _field_block, "scripted dependencies", &hs_references_block },
	{ _field_block, "pupAnimations*!", &AnimGraphDependencyBlock_block },
	{ _field_terminator },
};

} // namespace blofeld

