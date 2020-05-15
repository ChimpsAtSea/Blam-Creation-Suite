#pragma once

namespace blofeld
{

extern s_tag_block structure_edge_to_seam_edge_mapping_block;
extern s_tag_block structure_collision_materials_block;
extern s_tag_block structure_bsp_leaf_block;
extern s_tag_block structure_super_node_aabbs_block;
extern s_tag_block super_node_mappings_block;
extern s_tag_block super_node_recursable_masks_block;
extern s_tag_block structure_super_node_traversal_geometry_block;
extern s_tag_block structure_super_node_traversal_geometry_indices_block;
extern s_tag_block structure_surface_block;
extern s_tag_block structure_surface_to_triangle_mapping_block;
extern s_tag_block structure_bsp_cluster_portal_block;
extern s_tag_block structure_bsp_cluster_portal_vertex_block;
extern s_tag_block structure_bsp_detail_object_data_block;
extern s_tag_block structure_bsp_cluster_block;
extern s_tag_block structure_bsp_cluster_portal_index_block;
extern s_tag_block seam_indices_block;
extern s_tag_block cheap_light_marker_ref_block;
extern s_tag_block pvs_bound_object_identifiers_block;
extern s_tag_block pvs_bound_object_references_block;
extern s_tag_block structure_material_lighting_info_block;
extern s_tag_block structure_bsp_sky_owner_cluster_block;
extern s_tag_block structure_bsp_conveyor_surface_block;
extern s_tag_block structure_cookie_cutter_definition_block;
extern s_tag_block structure_bsp_marker_block;
extern s_tag_block structure_bsp_marker_light_palette_block;
extern s_tag_block structure_bsp_marker_light_index_block;
extern s_tag_block structure_bsp_runtime_decal_block;
extern s_tag_block structure_bsp_environment_object_palette_block;
extern s_tag_block structure_bsp_environment_object_block;
extern s_tag_block structure_instance_cluster_definition_block;
extern s_tag_block index_list_block;
extern s_tag_block structure_instance_group_definition_block;
extern s_tag_block structure_instance_imposter_info_block;
extern s_tag_block runtime_decorator_set_block;
extern s_tag_block bsp_preplaced_decal_set_reference_block;
extern s_tag_block bsp_preplaced_decal_reference_block;
extern s_tag_block transparent_planes_block;
extern s_tag_block structure_bsp_debug_info_block;
extern s_tag_block structure_bsp_cluster_debug_info_block;
extern s_tag_block structure_bsp_debug_info_render_line_block;
extern s_tag_block structure_bsp_debug_info_indices_block;
extern s_tag_block structure_bsp_fog_plane_debug_info_block;
extern s_tag_block structure_bsp_fog_zone_debug_info_block;
extern s_tag_block widget_reference_block;
extern s_tag_block cheap_light_reference_block;
extern s_tag_block structure_external_instanced_geometry_references_block;
extern s_tag_block structure_bsp_obb_volume_block;
extern s_tag_block AnimGraphDependencyBlock_block;
extern s_tag_block structureBspFxMarkerBlock_block;
extern s_tag_block structureMetadataLightConeMarkerBlock_block;

constexpr unsigned long PREFAB_TAG = 'prfb';

extern s_tag_block prefab_block;
extern s_tag_group prefab_group;
constexpr unsigned long SCENARIO_STRUCTURE_BSP_TAG = 'sbsp';

extern s_tag_block scenario_structure_bsp_block;
extern s_tag_group scenario_structure_bsp_group;
} // namespace blofeld

