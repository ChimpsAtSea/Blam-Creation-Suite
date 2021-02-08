#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long PREFAB_TAG = 'prfb';
	extern s_tag_group prefab_group; // prefab_block

	constexpr unsigned long SCENARIO_STRUCTURE_BSP_TAG = 'sbsp';
	extern s_tag_group scenario_structure_bsp_group; // scenario_structure_bsp_block
	extern s_tag_block_definition scenario_structure_bsp_block;
	extern s_tag_struct_definition scenario_structure_bsp; // scenario_structure_bsp_block


	extern s_tag_block_definition prefab_block;
	extern s_tag_block_definition structure_edge_to_seam_edge_mapping_block;
	extern s_tag_struct_definition structure_edge_to_seam_edge_mapping_block_struct_definition; // structure_edge_to_seam_edge_mapping_block
	extern s_tag_block_definition structure_collision_materials_block;
	extern s_tag_struct_definition structure_collision_materials_block_struct_definition; // structure_collision_materials_block
	extern s_tag_block_definition structure_bsp_conveyor_surface_block;
	extern s_tag_struct_definition structure_bsp_conveyor_surface_block_struct_definition; // structure_bsp_conveyor_surface_block
	extern s_tag_block_definition structure_bsp_leaf_block;
	extern s_tag_struct_definition structure_bsp_leaf_block_struct_definition; // structure_bsp_leaf_block
	extern s_tag_block_definition structure_super_node_aabbs_block;
	extern s_tag_struct_definition structure_super_node_aabbs_block_struct_definition; // structure_super_node_aabbs_block
	extern s_tag_block_definition super_node_mappings_block;
	extern s_tag_struct_definition super_node_mappings_block_struct_definition; // super_node_mappings_block
	extern s_tag_block_definition structure_super_node_traversal_geometry_indices_block;
	extern s_tag_struct_definition structure_super_node_traversal_geometry_indices_block_struct_definition; // structure_super_node_traversal_geometry_indices_block
	extern s_tag_block_definition super_node_recursable_masks_block;
	extern s_tag_struct_definition super_node_recursable_masks_block_struct_definition; // super_node_recursable_masks_block
	extern s_tag_block_definition structure_super_node_traversal_geometry_block;
	extern s_tag_struct_definition structure_super_node_traversal_geometry_block_struct_definition; // structure_super_node_traversal_geometry_block
	extern s_tag_block_definition structure_surface_block;
	extern s_tag_struct_definition structure_surface_block_struct_definition; // structure_surface_block
	extern s_tag_block_definition structure_surface_to_triangle_mapping_block;
	extern s_tag_struct_definition structure_surface_to_triangle_mapping_block_struct_definition; // structure_surface_to_triangle_mapping_block
	extern s_tag_block_definition structure_bsp_cluster_portal_block;
	extern s_tag_struct_definition structure_bsp_cluster_portal_block_struct_definition; // structure_bsp_cluster_portal_block
	extern s_tag_block_definition structure_bsp_cluster_portal_vertex_block;
	extern s_tag_struct_definition structure_bsp_cluster_portal_vertex_block_struct_definition; // structure_bsp_cluster_portal_vertex_block
	extern s_tag_block_definition structure_bsp_detail_object_data_block;
	extern s_tag_struct_definition structure_bsp_detail_object_data_block_struct_definition; // structure_bsp_detail_object_data_block
	extern s_tag_block_definition structure_bsp_cluster_block;
	extern s_tag_struct_definition structure_bsp_cluster_block_struct_definition; // structure_bsp_cluster_block
	extern s_tag_block_definition structure_bsp_cluster_portal_index_block;
	extern s_tag_struct_definition structure_bsp_cluster_portal_index_block_struct_definition; // structure_bsp_cluster_portal_index_block
	extern s_tag_block_definition seam_indices_block_definition_block;
	extern s_tag_struct_definition seam_indices_block_definition_block_struct_definition; // seam_indices_block_definition_block
	extern s_tag_block_definition cheap_light_marker_ref_block;
	extern s_tag_struct_definition cheap_light_marker_ref_block_struct_definition; // cheap_light_marker_ref_block
	extern s_tag_block_definition cheap_light_reference_block;
	extern s_tag_struct_definition cheap_light_reference_block_struct_definition; // cheap_light_reference_block
	extern s_tag_block_definition pvs_bound_object_identifiers_block;
	extern s_tag_struct_definition pvs_bound_object_identifiers_block_struct_definition; // pvs_bound_object_identifiers_block
	extern s_tag_block_definition pvs_bound_object_references_block;
	extern s_tag_struct_definition pvs_bound_object_references_block_struct_definition; // pvs_bound_object_references_block
	extern s_tag_block_definition structure_material_lighting_info_block;
	extern s_tag_struct_definition structure_material_lighting_info_block_struct_definition; // structure_material_lighting_info_block
	extern s_tag_block_definition structure_bsp_sky_owner_cluster_block;
	extern s_tag_struct_definition structure_bsp_sky_owner_cluster_block_struct_definition; // structure_bsp_sky_owner_cluster_block
	extern s_tag_block_definition structure_cookie_cutter_definition_block;
	extern s_tag_struct_definition structure_cookie_cutter_definition_block_struct_definition; // structure_cookie_cutter_definition_block
	extern s_tag_block_definition structure_bsp_marker_block;
	extern s_tag_struct_definition structure_bsp_marker_block_struct_definition; // structure_bsp_marker_block
	extern s_tag_block_definition structure_bsp_marker_light_palette_block;
	extern s_tag_struct_definition structure_bsp_marker_light_palette_block_struct_definition; // structure_bsp_marker_light_palette_block
	extern s_tag_block_definition structure_bsp_marker_light_index_block;
	extern s_tag_struct_definition structure_bsp_marker_light_index_block_struct_definition; // structure_bsp_marker_light_index_block
	extern s_tag_block_definition structure_bsp_runtime_decal_block;
	extern s_tag_struct_definition structure_bsp_runtime_decal_block_struct_definition; // structure_bsp_runtime_decal_block
	extern s_tag_block_definition structure_bsp_environment_object_palette_block;
	extern s_tag_struct_definition structure_bsp_environment_object_palette_block_struct_definition; // structure_bsp_environment_object_palette_block
	extern s_tag_block_definition structure_bsp_environment_object_block;
	extern s_tag_struct_definition structure_bsp_environment_object_block_struct_definition; // structure_bsp_environment_object_block
	extern s_tag_block_definition structure_instance_cluster_definition_block;
	extern s_tag_struct_definition structure_instance_cluster_definition_block_struct_definition; // structure_instance_cluster_definition_block
	extern s_tag_block_definition index_list_block;
	extern s_tag_struct_definition index_list_block_struct_definition; // index_list_block
	extern s_tag_block_definition structure_instance_group_definition_block;
	extern s_tag_struct_definition structure_instance_group_definition_block_struct_definition; // structure_instance_group_definition_block
	extern s_tag_block_definition structure_instance_imposter_info_block;
	extern s_tag_struct_definition structure_instance_imposter_info_block_struct_definition; // structure_instance_imposter_info_block
	extern s_tag_block_definition runtime_decorator_set_block;
	extern s_tag_struct_definition runtime_decorator_set_block_struct_definition; // runtime_decorator_set_block
	extern s_tag_block_definition bsp_preplaced_decal_set_reference_block;
	extern s_tag_struct_definition bsp_preplaced_decal_set_reference_block_struct_definition; // bsp_preplaced_decal_set_reference_block
	extern s_tag_block_definition bsp_preplaced_decal_reference_block;
	extern s_tag_struct_definition bsp_preplaced_decal_reference_block_struct_definition; // bsp_preplaced_decal_reference_block
	extern s_tag_block_definition transparent_planes_block;
	extern s_tag_struct_definition transparent_planes_block_struct_definition; // transparent_planes_block
	extern s_tag_block_definition structure_bsp_debug_info_block;
	extern s_tag_struct_definition structure_bsp_debug_info_block_struct_definition; // structure_bsp_debug_info_block
	extern s_tag_block_definition structure_bsp_cluster_debug_info_block;
	extern s_tag_struct_definition structure_bsp_cluster_debug_info_block_struct_definition; // structure_bsp_cluster_debug_info_block
	extern s_tag_block_definition structure_bsp_debug_info_render_line_block;
	extern s_tag_struct_definition structure_bsp_debug_info_render_line_block_struct_definition; // structure_bsp_debug_info_render_line_block
	extern s_tag_block_definition structure_bsp_debug_info_indices_block;
	extern s_tag_struct_definition structure_bsp_debug_info_indices_block_struct_definition; // structure_bsp_debug_info_indices_block
	extern s_tag_block_definition structure_bsp_fog_plane_debug_info_block;
	extern s_tag_struct_definition structure_bsp_fog_plane_debug_info_block_struct_definition; // structure_bsp_fog_plane_debug_info_block
	extern s_tag_block_definition structure_bsp_fog_zone_debug_info_block;
	extern s_tag_struct_definition structure_bsp_fog_zone_debug_info_block_struct_definition; // structure_bsp_fog_zone_debug_info_block
	extern s_tag_block_definition widget_reference_block;
	extern s_tag_struct_definition widget_reference_block_struct_definition; // widget_reference_block
	extern s_tag_block_definition structure_bsp_raw_resources_block;
	extern s_tag_struct_definition structure_bsp_raw_resources_block_struct_definition; // structure_bsp_raw_resources_block
	extern s_tag_block_definition structure_external_instanced_geometry_references_block;
	extern s_tag_struct_definition structure_external_instanced_geometry_references_block_struct_definition; // structure_external_instanced_geometry_references_block
	extern s_tag_block_definition structure_bsp_obb_volume_block;
	extern s_tag_struct_definition structure_bsp_obb_volume_block_struct_definition; // structure_bsp_obb_volume_block
	extern s_tag_block_definition AnimGraphDependencyBlock_block;
	extern s_tag_struct_definition AnimGraphDependencyBlock_block_struct_definition; // AnimGraphDependencyBlock_block
	extern s_tag_block_definition structureBspFxMarkerBlock_block;
	extern s_tag_struct_definition structureBspFxMarkerBlock_block_struct_definition; // structureBspFxMarkerBlock_block
	extern s_tag_block_definition structureMetadataLightConeMarkerBlock_block;
	extern s_tag_struct_definition structureMetadataLightConeMarkerBlock_block_struct_definition; // structureMetadataLightConeMarkerBlock_block

	extern s_tag_struct_definition prefab_struct_definition; // tag group
	extern s_tag_struct_definition structure_bsp_cluster_portal_oriented_bounds_block;
	extern s_tag_struct_definition structure_bsp_resource_interface;
	extern s_tag_struct_definition structure_bsp_resource_struct;
	extern s_tag_struct_definition structure_bsp_tag_resources_struct;
	extern s_tag_struct_definition structure_bsp_cache_file_tag_resources_struct;

	extern c_versioned_string_list structure_material_lighting_info_flags_strings;
	extern s_string_list_definition structure_material_lighting_info_flags;
	extern c_versioned_string_list structure_bsp_cluster_portal_flags_definition_strings;
	extern s_string_list_definition structure_bsp_cluster_portal_flags_definition;
	extern c_versioned_string_list structure_cluster_flags_strings;
	extern s_string_list_definition structure_cluster_flags;
	extern c_versioned_string_list structure_collision_materialg_flags_strings;
	extern s_string_list_definition structure_collision_materialg_flags;
	extern c_versioned_string_list structure_marker_type_enum_strings;
	extern s_string_list_definition structure_marker_type_enum;
	extern c_versioned_string_list environmentObjectFlagsDefinition_strings;
	extern s_string_list_definition environmentObjectFlagsDefinition;
	extern c_versioned_string_list structure_super_node_mapping_flags_strings;
	extern s_string_list_definition structure_super_node_mapping_flags;
	extern c_versioned_string_list structure_bsp_debug_info_cluster_error_flags_strings;
	extern s_string_list_definition structure_bsp_debug_info_cluster_error_flags;
	extern c_versioned_string_list structure_bsp_debug_info_cluster_warning_flags_strings;
	extern s_string_list_definition structure_bsp_debug_info_cluster_warning_flags;
	extern c_versioned_string_list structure_bsp_debug_info_render_line_type_enum_strings;
	extern s_string_list_definition structure_bsp_debug_info_render_line_type_enum;
	extern c_versioned_string_list structure_bsp_flags_definition_strings;
	extern s_string_list_definition structure_bsp_flags_definition;
	extern c_versioned_string_list structure_bsp_content_policy_flag_strings;
	extern s_string_list_definition structure_bsp_content_policy_flag;
	extern c_versioned_string_list structure_instance_cluster_flags_strings;
	extern s_string_list_definition structure_instance_cluster_flags;
	extern c_versioned_string_list structure_instance_group_flags_strings;
	extern s_string_list_definition structure_instance_group_flags;
	extern c_versioned_string_list prefabOverrideFlags_strings;
	extern s_string_list_definition prefabOverrideFlags;

	extern s_tag_reference_definition structure_lighting_bsp_reference;

} // namespace macaque

} // namespace blofeld
