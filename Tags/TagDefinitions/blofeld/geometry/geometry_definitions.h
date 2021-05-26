#pragma once

namespace blofeld
{
	// #TODO: is this the right place for this?
	extern s_tag_struct_definition constant_buffer_struct; // #CUSTOM
	extern s_tag_block_definition constant_buffer_interops_block; // #CUSTOM
	extern s_tag_struct_definition constant_buffer_interops_block_struct_definition; // #CUSTOM
	extern s_tag_block_definition global_render_geometry_unknown_meshes_block; // #CUSTOM
	extern s_tag_struct_definition global_render_geometry_unknown_meshes_block_struct_definition; // #CUSTOM
	extern s_tag_block_definition global_render_geometry_unknown_meshes2_block; // #CUSTOM
	extern s_tag_struct_definition global_render_geometry_unknown_meshes2_block_struct_definition; // #CUSTOM

	extern s_tag_block_definition global_mesh_block;
	extern s_tag_struct_definition global_mesh_block_struct_definition; // global_mesh_block
	extern s_tag_block_definition part_block;
	extern s_tag_struct_definition part_block_struct_definition; // part_block
	extern s_tag_block_definition sorting_position_block;
	extern s_tag_struct_definition sorting_position_block_struct_definition; // sorting_position_block
	extern s_tag_block_definition subpart_block;
	extern s_tag_struct_definition subpart_block_struct_definition; // subpart_block
	extern s_tag_block_definition global_instance_bucket_block;
	extern s_tag_struct_definition global_instance_bucket_block_struct_definition; // global_instance_bucket_block
	extern s_tag_block_definition instance_index_word_block;
	extern s_tag_struct_definition instance_index_word_block_struct_definition; // instance_index_word_block
	extern s_tag_block_definition indices_word_block;
	extern s_tag_struct_definition indices_word_block_struct_definition; // indices_word_block
	extern s_tag_block_definition vertexKeyBlock_block;
	extern s_tag_struct_definition vertexKeyBlock_block_struct_definition; // vertexKeyBlock_block
	extern s_tag_block_definition PCAMeshIndexBlock_block;
	extern s_tag_struct_definition PCAMeshIndexBlock_block_struct_definition; // PCAMeshIndexBlock_block
	extern s_tag_block_definition compression_info_block;
	extern s_tag_struct_definition compression_info_block_struct_definition; // compression_info_block
	extern s_tag_block_definition user_data_block;
	extern s_tag_struct_definition user_data_block_struct_definition; // user_data_block
	extern s_tag_block_definition per_mesh_raw_data_block;
	extern s_tag_struct_definition per_mesh_raw_data_block_struct_definition; // per_mesh_raw_data_block
	extern s_tag_block_definition raw_vertex_block;
	extern s_tag_struct_definition raw_vertex_block_struct_definition; // raw_vertex_block
	extern s_tag_block_definition indices_dword_block;
	extern s_tag_struct_definition indices_dword_block_struct_definition; // indices_dword_block
	extern s_tag_block_definition raw_water_block;
	extern s_tag_struct_definition raw_water_block_struct_definition; // raw_water_block
	extern s_tag_block_definition raw_water_append_block;
	extern s_tag_struct_definition raw_water_append_block_struct_definition; // raw_water_append_block
	extern s_tag_block_definition raw_imposter_brdf_block;
	extern s_tag_struct_definition raw_imposter_brdf_block_struct_definition; // raw_imposter_brdf_block
	extern s_tag_block_definition raw_instance_imposter_block;
	extern s_tag_struct_definition raw_instance_imposter_block_struct_definition; // raw_instance_imposter_block
	extern s_tag_block_definition raw_blendshape_block;
	extern s_tag_struct_definition raw_blendshape_block_struct_definition; // raw_blendshape_block
	extern s_tag_block_definition per_mesh_node_map_block;
	extern s_tag_struct_definition per_mesh_node_map_block_struct_definition; // per_mesh_node_map_block
	extern s_tag_block_definition node_map_byte_block;
	extern s_tag_struct_definition node_map_byte_block_struct_definition; // node_map_byte_block
	extern s_tag_block_definition per_mesh_subpart_visibility_block;
	extern s_tag_struct_definition per_mesh_subpart_visibility_block_struct_definition; // per_mesh_subpart_visibility_block
	extern s_tag_block_definition per_mesh_prt_data_block;
	extern s_tag_struct_definition per_mesh_prt_data_block_struct_definition; // per_mesh_prt_data_block
	extern s_tag_block_definition per_instance_prt_data_block;
	extern s_tag_struct_definition per_instance_prt_data_block_struct_definition; // per_instance_prt_data_block
	extern s_tag_block_definition per_instance_lightmap_texcoords_block;
	extern s_tag_struct_definition per_instance_lightmap_texcoords_block_struct_definition; // per_instance_lightmap_texcoords_block
	extern s_tag_block_definition raw_texcoord_block;
	extern s_tag_struct_definition raw_texcoord_block_struct_definition; // raw_texcoord_block
	extern s_tag_block_definition water_bounding_box_block;
	extern s_tag_struct_definition water_bounding_box_block_struct_definition; // water_bounding_box_block
	extern s_tag_block_definition vertex_buffers_block;
	extern s_tag_struct_definition vertex_buffers_block_struct_definition; // vertex_buffers_block
	extern s_tag_block_definition index_buffers_block;
	extern s_tag_struct_definition index_buffers_block_struct_definition; // index_buffers_block
	extern s_tag_block_definition render_vertex_buffer_block;
	extern s_tag_struct_definition render_vertex_buffer_block_struct_definition; // render_vertex_buffer_block
	extern s_tag_block_definition render_index_buffer_block;
	extern s_tag_struct_definition render_index_buffer_block_struct_definition; // render_index_buffer_block
	extern s_tag_block_definition render_geometry_pvs_data_block;
	extern s_tag_struct_definition render_geometry_pvs_data_block_struct_definition; // render_geometry_pvs_data_block
	extern s_tag_block_definition render_geometry_pvs_data_visibility_value_block;
	extern s_tag_struct_definition render_geometry_pvs_data_visibility_value_block_struct_definition; // render_geometry_pvs_data_visibility_value_block
	extern s_tag_block_definition render_geometry_pvs_data_visibility_index_block;
	extern s_tag_struct_definition render_geometry_pvs_data_visibility_index_block_struct_definition; // render_geometry_pvs_data_visibility_index_block
	extern s_tag_block_definition shapeNameBlock_block;
	extern s_tag_struct_definition shapeNameBlock_block_struct_definition; // shapeNameBlock_block

	extern s_tag_struct_definition node_indices_array_struct_definition;
	extern s_tag_array_definition node_indices_array;
	extern s_tag_struct_definition node_weights_implicit_array_struct_definition;
	extern s_tag_array_definition node_weights_implicit_array;
	extern s_tag_struct_definition vertex_buffer_indices_word_array_struct_definition;
	extern s_tag_array_definition vertex_buffer_indices_word_array;
	extern s_tag_struct_definition node_weights_complete_array_struct_definition;
	extern s_tag_array_definition node_weights_complete_array;
	extern s_tag_struct_definition global_render_geometry_struct;
	extern s_tag_struct_definition global_render_geometry_user_data_header_struct;
	extern s_tag_struct_definition render_geometry_api_resource_definition_struct;

	extern c_versioned_string_list part_flags_strings;
	extern s_string_list_definition part_flags;
	extern c_versioned_string_list tessellation_mode_definition_strings;
	extern s_string_list_definition tessellation_mode_definition;
	extern c_versioned_string_list specialized_render_definition_strings;
	extern s_string_list_definition specialized_render_definition;
	extern c_versioned_string_list compression_flags_strings;
	extern s_string_list_definition compression_flags;
	extern c_versioned_string_list mesh_flags_strings;
	extern s_string_list_definition mesh_flags;
	extern c_versioned_string_list mesh_vertex_type_definition_strings;
	extern s_string_list_definition mesh_vertex_type_definition;
	extern c_versioned_string_list mesh_transfer_vertex_type_definition_strings;
	extern s_string_list_definition mesh_transfer_vertex_type_definition;
	extern c_versioned_string_list mesh_lighting_policy_type_definition_strings;
	extern s_string_list_definition mesh_lighting_policy_type_definition;
	extern c_versioned_string_list mesh_index_buffer_type_definition_strings;
	extern s_string_list_definition mesh_index_buffer_type_definition;
	extern c_versioned_string_list per_mesh_raw_data_flags_strings;
	extern s_string_list_definition per_mesh_raw_data_flags;
	extern c_versioned_string_list render_geometry_user_data_type_definition_strings;
	extern s_string_list_definition render_geometry_user_data_type_definition;
	extern c_versioned_string_list render_geometry_flags_strings;
	extern s_string_list_definition render_geometry_flags;



} // namespace blofeld

