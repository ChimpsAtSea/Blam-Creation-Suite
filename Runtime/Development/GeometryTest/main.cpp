#include "geometrytest-private-pch.h"

using namespace blofeld::halo3::pc64;

int main()
{
	const wchar_t* launch_filepath_command_line_argument = nullptr; // #TODO: implement this with the command line API

	BCS_FAIL_RETURN(register_process_module_by_pointer(main));
	BCS_RESULT rs0 = init_command_line();
	BCS_RESULT rs1 = init_console();
	if (BCS_SUCCEEDED(rs1)) rs1 = BCS_SUCCEEDED(command_line_has_argument_internal("commandline")) ? alloc_console("GeometryTest") : BCS_S_OK;

	s_engine_platform_build engine_platform_build = { _engine_type_halo3, _platform_type_pc_64bit, _build_halo3_guerilla };

	const blofeld::s_tag_group* model_tag_group = blofeld::get_tag_group_by_group_tag(engine_platform_build, MODEL_TAG);
	h_group* model_high_level_group = new() h_group(engine_platform_build, *model_tag_group);

	const blofeld::s_tag_group* render_model_tag_group = blofeld::get_tag_group_by_group_tag(engine_platform_build, RENDER_MODEL_TAG);
	h_group* render_model_high_level_group = new() h_group(engine_platform_build, *render_model_tag_group);
	
	h_tag& model_tag = model_high_level_group->create_tag_instance("geometrytest");
	h_tag& render_model_tag = render_model_high_level_group->create_tag_instance("geometrytest");

	h_model_block_struct* model = dynamic_cast<decltype(model)>(&model_tag);
	h_render_model_block_struct* render_model = dynamic_cast<decltype(render_model)>(&render_model_tag);

	model->render_model.set_tag(render_model);

	const char* model_path;
	BCS_RESULT get_command_line_argument_result = command_line_get_argument("modelpath", model_path);
	BCS_FAIL_THROW(get_command_line_argument_result);

	c_geometry_scene* geometry_scene;
	BCS_RESULT load_geometry_scene_from_file_result = load_geometry_scene_from_file(model_path, geometry_scene);
	BCS_FAIL_THROW(load_geometry_scene_from_file_result);

	auto& runtime_region = model->runtime_regions_block.emplace_back();

	render_model->name = "geometry_test";

	unsigned int num_meshes = geometry_scene->get_num_meshes();
	for (unsigned int mesh_index = 0; mesh_index < num_meshes; mesh_index++)
	{
		c_geometry_mesh* geometry_mesh = geometry_scene->get_mesh(mesh_index);

		auto& region = render_model->regions_block.emplace_back();
		region.name = geometry_mesh->get_name();;

		auto& permutation = region.permutations_block.emplace_back();
		permutation.name = "main";
		permutation.mesh_index = mesh_index;
		permutation.mesh_count = 1;
	}

	auto& node = render_model->nodes_block.emplace_back();
	node.name = "geometry_test";


	node.default_translation = { 0.0f, 0.0f, 0.0f };
	node.default_rotation = { 0.0f, 0.0f, 0.0f, 1.0f };

	/* Old Mistakes Die Hard
	 Be aware that the displayed inverse matrix below is incorrect.
	 The inverse scale value should come before the inverse matrix. Currently the first value of the inverse matrix is the inverse scale and the inverse scale is the final value of the inverse position.
	 i.e. The actual field order should have been:
	   *inverse scale
	   *inverse forward
	   *inverse left
	   *inverse up
	   *inverse position*/

	real inverse_scale = 1.0f;
	real_vector3d inverse_forward = { 1.0f, 0.0f, 0.0f };
	real_vector3d inverse_left = { 0.0f, 1.0f, 0.0f };
	real_vector3d inverse_up = { 0.0f, 0.0f, 1.0f };
	real_point3d inverse_position = { 0.0f, 0.0f, 0.0f };

	node.inverse_forward = { inverse_scale, inverse_forward.i, inverse_forward.j };
	node.inverse_left = { inverse_forward.k, inverse_left.i, inverse_left.j };
	node.inverse_up = { inverse_left.k, inverse_up.i, inverse_up.j };
	node.inverse_position = { inverse_up.k, inverse_position.x, inverse_position.y };
	node.inverse_scale = inverse_position.z;

	auto& material = render_model->materials_block.emplace_back();
	material.render_method.set_unqualified_file_path_without_extension(SHADER_TAG, "geometrytest");
	material.imported_material_index = 0;
	
	auto& render_geometry = render_model->render_geometry;

	render_model->render_geometry.runtime_flags.set(_render_geometry_flags_version_2, true);

	unsigned int num_vertex_buffers = 0;

	float3 position_minimum = { INFINITY, INFINITY, INFINITY };
	float3 position_maximum = { -INFINITY, -INFINITY, -INFINITY };
	float2 texcoord_minimum = { INFINITY, INFINITY };
	float2 texcoord_maximum = { -INFINITY, -INFINITY };
	for (unsigned int mesh_index = 0; mesh_index < num_meshes; mesh_index++)
	{
		c_geometry_mesh* geometry_mesh = geometry_scene->get_mesh(mesh_index);

		const float3* positions = geometry_mesh->get_positions();
		const float2* texture_coordinate_set = geometry_mesh->get_texture_coordinate_set(0);
		unsigned int geometry_vertex_count = geometry_mesh->get_vertex_count();

		for (unsigned int vertex_index = 0; vertex_index < geometry_vertex_count; vertex_index++)
		{
			const float3& position = positions[vertex_index];
			const float2& texcoord = texture_coordinate_set[vertex_index];
			position_minimum = { __min(position_minimum.x, position.x), __min(position_minimum.y, position.y), __min(position_minimum.z, position.z) };
			position_maximum = { __max(position_maximum.x, position.x), __max(position_maximum.y, position.y), __max(position_maximum.z, position.z) };
			texcoord_minimum = { __min(texcoord_minimum.x, texcoord.x), __min(texcoord_minimum.y, -texcoord.y) };
			texcoord_maximum = { __max(texcoord_maximum.x, texcoord.x), __max(texcoord_maximum.y, -texcoord.y) };
		}
	}
	float3 position_range = { position_maximum.x - position_minimum.x, position_maximum.y - position_minimum.y, position_maximum.z - position_minimum.z };
	float2 texcoord_range = { texcoord_maximum.x - texcoord_minimum.x, texcoord_maximum.y - texcoord_minimum.y };

	for (unsigned int mesh_index = 0; mesh_index < num_meshes; mesh_index++)
	{
		c_geometry_mesh* geometry_mesh = geometry_scene->get_mesh(mesh_index);
		unsigned int geometry_vertex_count = geometry_mesh->get_vertex_count();
		unsigned int geometry_indice_count = geometry_mesh->get_index_count();
		unsigned int num_indices = 0;

		auto& mesh = render_geometry.meshes_block.emplace_back();

		auto& part = mesh.parts_block.emplace_back();
		part.render_method_index = 0;
		part.transparent_sorting_index = -1;

		part.index_start = num_indices;
		part.index_count = geometry_indice_count;

		part.subpart_start = mesh.subparts_block.size();
		part.subpart_count = 1;
		part.budget_vertex_count = geometry_vertex_count;

		auto& subpart = mesh.subparts_block.emplace_back();
		subpart.index_start = num_indices;
		subpart.index_count = geometry_indice_count;
		subpart.budget_vertex_count = geometry_vertex_count;
		subpart.part_index = 0;

		mesh.vertex_buffer_indices[0].vertex_buffer_index = mesh_index; // #TODO?
		mesh.vertex_buffer_indices[0].vertex_buffer_index = 0;
		mesh.index_buffer_index = -1;
		mesh.index_buffer_tessellation = -1;
		mesh.rigid_node_index = 0;
		//mesh.prt_vertex_type = _mesh_transfer_vertex_type_definition_prt_ambient;
		mesh.prt_vertex_type = _mesh_transfer_vertex_type_definition_no_prt;
		mesh.index_buffer_type = _mesh_index_buffer_type_definition_triangle_list;
		mesh.vertex_type = _mesh_vertex_type_definition_rigid;

		num_indices += geometry_indice_count;

		auto& mesh_temporary = render_geometry.per_mesh_temporary_block.emplace_back();

		const float3* positions = geometry_mesh->get_positions();
		const float3* normals = geometry_mesh->get_normals();
		const float3* tangents = geometry_mesh->get_tangents();
		const float3* bitangents = geometry_mesh->get_bitangents();
		const float2* texture_coordinate_set = geometry_mesh->get_texture_coordinate_set(0);
		const float4* color_set = geometry_mesh->get_color_set(0);

		for (unsigned int vertex_index = 0; vertex_index < geometry_vertex_count; vertex_index++)
		{
			auto& vertex = mesh_temporary.raw_vertices_block.emplace_back();

			float3 position = positions[vertex_index];
			position.x = (position.x - position_minimum.x) / position_range.x;
			position.y = (position.y - position_minimum.y) / position_range.y;
			position.z = (position.z - position_minimum.z) / position_range.z;

			float2 texcoord = texture_coordinate_set[vertex_index];
			texcoord.x = (texcoord.x - texcoord_minimum.x) / texcoord_range.x;
			texcoord.y = ((-texcoord.y) - texcoord_minimum.y) / texcoord_range.y;
				
			vertex.position = { position.x, position.y, position.z };
			vertex.texcoord = { texcoord.x, texcoord.y };
			vertex.normal = { normals[vertex_index].x, normals[vertex_index].y, normals[vertex_index].z };
			vertex.binormal = { bitangents[vertex_index].x, bitangents[vertex_index].y, bitangents[vertex_index].z };
			vertex.tangent = { tangents[vertex_index].x, tangents[vertex_index].y, tangents[vertex_index].z };
			vertex.lightmap_texcoord = { 0.0f, 0.0f };
			vertex.node_indices[0].node_index = 0;
			vertex.node_indices[1].node_index = -1;
			vertex.node_indices[2].node_index = -1;
			vertex.node_indices[3].node_index = -1;
			vertex.node_weights[0].node_weight = 1.0f;
			vertex.node_weights[1].node_weight = 0.0f;
			vertex.node_weights[2].node_weight = 0.0f;
			vertex.node_weights[3].node_weight = 0.0f;
			vertex.vertex_color = { color_set[vertex_index].x, color_set[vertex_index].y, color_set[vertex_index].z };
		}

		unsigned int* indices = geometry_mesh->get_mesh_indices_uint();

		for (unsigned int indice_index = 0; indice_index < geometry_indice_count; indice_index++)
		{
			auto& index = mesh_temporary.raw_indices_block.emplace_back();

			index._word = indices[indice_index];
		}

		mesh_temporary.flags.set(_per_mesh_raw_data_flags_indices_are_triangle_lists, true);

	}

	auto& compression_info = render_geometry.compression_info_block.emplace_back();

	compression_info.compression_flags.clear();

	float position_bounds_x[2] = { position_minimum.x, position_maximum.x };
	float position_bounds_y[2] = { position_minimum.y, position_maximum.y };
	float position_bounds_z[2] = { position_minimum.z, position_maximum.z };
	float texcoord_bounds_x[2] = { texcoord_minimum.x, texcoord_maximum.x };
	float texcoord_bounds_y[2] = { texcoord_minimum.y, texcoord_maximum.y };

	compression_info.position_bounds_0->x = position_bounds_x[0];
	compression_info.position_bounds_0->y = position_bounds_x[1];
	compression_info.position_bounds_0->z = position_bounds_y[0];
	compression_info.position_bounds_1->x = position_bounds_y[1];
	compression_info.position_bounds_1->y = position_bounds_z[0];
	compression_info.position_bounds_1->z = position_bounds_z[1];
	compression_info.texcoord_bounds_0->x = texcoord_bounds_x[0];
	compression_info.texcoord_bounds_0->y = texcoord_bounds_x[1];
	compression_info.texcoord_bounds_1->x = texcoord_bounds_y[0];
	compression_info.texcoord_bounds_1->y = texcoord_bounds_y[1];

	render_model->default_lightprobe_r[0].coefficient = 0.895147f;
	render_model->default_lightprobe_r[1].coefficient = -1.08524f;
	render_model->default_lightprobe_r[2].coefficient = 0.000000f;
	render_model->default_lightprobe_r[3].coefficient = -1.08524f;
	render_model->default_lightprobe_r[4].coefficient = 1.681450f;
	render_model->default_lightprobe_r[5].coefficient = 0.0000000f;
	render_model->default_lightprobe_r[6].coefficient = -0.971081f;
	render_model->default_lightprobe_r[7].coefficient = 0.0000000f;
	render_model->default_lightprobe_r[8].coefficient = 0.0000000f;
	render_model->default_lightprobe_r[9].coefficient = 0.0000000f;
	render_model->default_lightprobe_r[10].coefficient = 0.0000000f;
	render_model->default_lightprobe_r[11].coefficient = 0.0000000f;
	render_model->default_lightprobe_r[12].coefficient = 0.0000000f;
	render_model->default_lightprobe_r[13].coefficient = 0.0000000f;
	render_model->default_lightprobe_r[14].coefficient = 0.0000000f;
	render_model->default_lightprobe_r[15].coefficient = 0.0000000f;

	render_model->default_lightprobe_g[0].coefficient = 0.895147f;
	render_model->default_lightprobe_g[1].coefficient = -1.08524f;
	render_model->default_lightprobe_g[2].coefficient = 0.000000f;
	render_model->default_lightprobe_g[3].coefficient = -1.08524f;
	render_model->default_lightprobe_g[4].coefficient = 1.681450f;
	render_model->default_lightprobe_g[5].coefficient = 0.0000000f;
	render_model->default_lightprobe_g[6].coefficient = -0.971081f;
	render_model->default_lightprobe_g[7].coefficient = 0.0000000f;
	render_model->default_lightprobe_g[8].coefficient = 0.0000000f;
	render_model->default_lightprobe_g[9].coefficient = 0.0000000f;
	render_model->default_lightprobe_g[10].coefficient = 0.0000000f;
	render_model->default_lightprobe_g[11].coefficient = 0.0000000f;
	render_model->default_lightprobe_g[12].coefficient = 0.0000000f;
	render_model->default_lightprobe_g[13].coefficient = 0.0000000f;
	render_model->default_lightprobe_g[14].coefficient = 0.0000000f;
	render_model->default_lightprobe_g[15].coefficient = 0.0000000f;

	render_model->default_lightprobe_b[0].coefficient = 0.895147f;
	render_model->default_lightprobe_b[1].coefficient = -1.08524f;
	render_model->default_lightprobe_b[2].coefficient = 0.000000f;
	render_model->default_lightprobe_b[3].coefficient = -1.08524f;
	render_model->default_lightprobe_b[4].coefficient = 1.681450f;
	render_model->default_lightprobe_b[5].coefficient = 0.0000000f;
	render_model->default_lightprobe_b[6].coefficient = -0.971081f;
	render_model->default_lightprobe_b[7].coefficient = 0.0000000f;
	render_model->default_lightprobe_b[8].coefficient = 0.0000000f;
	render_model->default_lightprobe_b[9].coefficient = 0.0000000f;
	render_model->default_lightprobe_b[10].coefficient = 0.0000000f;
	render_model->default_lightprobe_b[11].coefficient = 0.0000000f;
	render_model->default_lightprobe_b[12].coefficient = 0.0000000f;
	render_model->default_lightprobe_b[13].coefficient = 0.0000000f;
	render_model->default_lightprobe_b[14].coefficient = 0.0000000f;
	render_model->default_lightprobe_b[15].coefficient = 0.0000000f;

	const char* tags_directory;
	BCS_RESULT get_command_line_argument_result2 = command_line_get_argument("tagsdir", tags_directory);
	BCS_FAIL_THROW(get_command_line_argument_result2);

	char model_filepath[260];
	memcpy(model_filepath, tags_directory, strlen(tags_directory) + 1);
	strcat_s(model_filepath, "geometrytest.model");

	char render_model_filepath[260];
	memcpy(render_model_filepath, tags_directory, strlen(tags_directory) + 1);
	strcat_s(render_model_filepath, "geometrytest.render_model");

	c_high_level_tag_file_writer tag_file_writer(engine_platform_build, model_filepath, model_tag);
	c_high_level_tag_file_writer tag_file_writer2(engine_platform_build, render_model_filepath, render_model_tag);

	BCS_RESULT geometry_scene_destroy_result = geometry_scene_destroy(geometry_scene);
	BCS_FAIL_THROW(geometry_scene_destroy_result);

	debug_point;

	if (BCS_SUCCEEDED(rs1)) rs1 = deinit_console();
	if (BCS_SUCCEEDED(rs0)) rs0 = deinit_command_line();

	BCS_FAIL_RETURN(rs1);
	BCS_FAIL_RETURN(rs0);

	return 0;
}
