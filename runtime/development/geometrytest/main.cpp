#include "geometrytest-private-pch.h"

using namespace blofeld::halo3::pc64;

extern "C" int bcs_main()
{
	BCS_RESULT rs1 = BCS_SUCCEEDED(command_line_has_argument_internal("commandline")) ? alloc_console("GeometryTest") : BCS_S_OK;

	BCS_RESULT tag_definition_registry_init_result = blofeld::tag_definition_registry_init();
	ASSERT(BCS_SUCCEEDED(tag_definition_registry_init_result));

	BCS_RESULT tag_definitions_register_result = blofeld::tag_definitions_register();
	ASSERT(BCS_SUCCEEDED(tag_definitions_register_result));

	BCS_RESULT high_level_registry_init_result = high_level_registry_init();
	ASSERT(BCS_SUCCEEDED(high_level_registry_init_result));

	BCS_RESULT high_level_register_result = high_level_register();
	ASSERT(BCS_SUCCEEDED(high_level_register_result));



	s_engine_platform_build engine_platform_build = { _engine_type_halo3, _platform_type_pc_64bit, _build_halo3_guerilla };

	blofeld::s_tag_group const* model_tag_group;
	ASSERT(BCS_SUCCEEDED(blofeld::tag_definition_registry_get_tag_group_by_engine_platform_build(engine_platform_build, blofeld::taggroups::MODEL_TAG(engine_platform_build.engine_type), model_tag_group)));

	blofeld::s_tag_group const* render_model_tag_group;
	ASSERT(BCS_SUCCEEDED(blofeld::tag_definition_registry_get_tag_group_by_engine_platform_build(engine_platform_build, blofeld::taggroups::RENDER_MODEL_TAG, render_model_tag_group)));

	h_tag_group* model_high_level_group = new() h_tag_group(engine_platform_build, *model_tag_group);
	h_tag_group* render_model_high_level_group = new() h_tag_group(engine_platform_build, *render_model_tag_group);

	h_tag_instance* model_tag;
	BCS_RESULT create_model_tag_result = BCS_S_OK;
	if (BCS_FAILED(create_model_tag_result = model_high_level_group->create_tag_instance("geometrytest", model_tag)))
	{
		return create_model_tag_result;
	}

	h_tag_instance* render_model_tag;
	BCS_RESULT create_render_model_tag_result = BCS_S_OK;
	if (BCS_FAILED(create_render_model_tag_result = render_model_high_level_group->create_tag_instance("geometrytest", render_model_tag)))
	{
		return create_render_model_tag_result;
	}

	h_model_block_struct* model = high_level_cast<decltype(model)>(&model_tag->prototype);
	h_render_model_block_struct* render_model = high_level_cast<decltype(render_model)>(&render_model_tag->prototype);

	model->render_model.set_tag(render_model_tag);

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
	material.render_method.set_unqualified_file_path_without_extension(blofeld::taggroups::SHADER_TAG(engine_platform_build.engine_type), "geometrytest");
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

		unsigned int geometry_vertex_count = geometry_mesh->get_vertex_count();

		// #TODO: Is there a more efficient way to expose this interface rather than always allocating memory and copying the data???

		float3* positions = new float3[geometry_vertex_count];
		float2* texture_coordinates = new float2[geometry_vertex_count];

		BCS_RESULT read_positions = geometry_mesh->get_property(
			_geometry_mesh_property_positions,
			0,
			0,
			geometry_vertex_count,
			_graphics_data_format_r32g32b32_float,
			positions);
		ASSERT(BCS_SUCCEEDED(read_positions));

		BCS_RESULT read_texture_coordinates = geometry_mesh->get_property(
			_geometry_mesh_property_texture_coordinates,
			0,
			0,
			geometry_vertex_count,
			_graphics_data_format_r32g32_float,
			positions);
		ASSERT(BCS_SUCCEEDED(read_texture_coordinates));

		for (unsigned int vertex_index = 0; vertex_index < geometry_vertex_count; vertex_index++)
		{
			const float3& position = positions[vertex_index];
			const float2& texcoord = texture_coordinates[vertex_index];
			position_minimum = { __min(position_minimum.x, position.x), __min(position_minimum.y, position.y), __min(position_minimum.z, position.z) };
			position_maximum = { __max(position_maximum.x, position.x), __max(position_maximum.y, position.y), __max(position_maximum.z, position.z) };
			texcoord_minimum = { __min(texcoord_minimum.x, texcoord.x), __min(texcoord_minimum.y, -texcoord.y) };
			texcoord_maximum = { __max(texcoord_maximum.x, texcoord.x), __max(texcoord_maximum.y, -texcoord.y) };
		}

		delete[] positions;
		delete[] texture_coordinates;
	}
	float3 position_range = { position_maximum.x - position_minimum.x, position_maximum.y - position_minimum.y, position_maximum.z - position_minimum.z };
	float2 texcoord_range = { texcoord_maximum.x - texcoord_minimum.x, texcoord_maximum.y - texcoord_minimum.y };

	e_mesh_transfer_vertex_type_definition vertex_type_definition = _mesh_transfer_vertex_type_definition_prt_quadratic;

	int order = 0;
#define vertex_type_definition_order(_mesh_transfer_vertex_type_definition, _order) if(vertex_type_definition == _mesh_transfer_vertex_type_definition) order = _order;
	vertex_type_definition_order(_mesh_transfer_vertex_type_definition_no_prt, 0);
	vertex_type_definition_order(_mesh_transfer_vertex_type_definition_prt_ambient, 0);
	vertex_type_definition_order(_mesh_transfer_vertex_type_definition_prt_linear, 1);
	vertex_type_definition_order(_mesh_transfer_vertex_type_definition_prt_quadratic, 2);
#undef vertex_type_definition_order



	c_radiance_transfer_engine* radiance_transfer_engine;
	BCS_RESULT radiance_transfer_create_result = radiance_transfer_create(_radiance_transfer_engine_gpu, order, 20, false, false, radiance_transfer_engine);
	ASSERT(BCS_SUCCEEDED(radiance_transfer_create_result));

	for (unsigned int mesh_index = 0; mesh_index < num_meshes; mesh_index++)
	{
		c_geometry_mesh* geometry_mesh = geometry_scene->get_mesh(mesh_index);

		BCS_RESULT radiance_transfer_add_mesh_result = radiance_transfer_add_mesh(radiance_transfer_engine, geometry_mesh);
		ASSERT(BCS_SUCCEEDED(radiance_transfer_add_mesh_result));
	}

	BCS_RESULT radiance_transfer_bake_result = radiance_transfer_bake(radiance_transfer_engine);
	ASSERT(BCS_SUCCEEDED(radiance_transfer_bake_result));

	for (unsigned int mesh_index = 0; mesh_index < num_meshes; mesh_index++)
	{
		c_geometry_mesh* geometry_mesh = geometry_scene->get_mesh(mesh_index);
		unsigned int geometry_vertex_count = geometry_mesh->get_vertex_count();
		unsigned int geometry_index_count = geometry_mesh->get_index_count();
		unsigned int num_indices = 0;

		auto& mesh = render_geometry.meshes_block.emplace_back();

		auto& part = mesh.parts_block.emplace_back();
		part.render_method_index = 0;
		part.transparent_sorting_index = -1;

		part.index_start = num_indices;
		part.index_count = geometry_index_count;

		part.subpart_start = mesh.subparts_block.size();
		part.subpart_count = 1;
		part.budget_vertex_count = geometry_vertex_count;

		auto& subpart = mesh.subparts_block.emplace_back();
		subpart.index_start = num_indices;
		subpart.index_count = geometry_index_count;
		subpart.budget_vertex_count = geometry_vertex_count;
		subpart.part_index = 0;

		mesh.vertex_buffer_indices[0].vertex_buffer_index = mesh_index; // #TODO?
		mesh.vertex_buffer_indices[0].vertex_buffer_index = 0;
		mesh.index_buffer_index = -1;
		mesh.index_buffer_tessellation = -1;
		mesh.rigid_node_index = 0;
		mesh.prt_vertex_type = vertex_type_definition;
		mesh.index_buffer_type = _mesh_index_buffer_type_definition_triangle_list;
		mesh.vertex_type = _mesh_vertex_type_definition_rigid;

		num_indices += geometry_index_count;

		auto& mesh_temporary = render_geometry.per_mesh_temporary_block.emplace_back();

		// #TODO: Is there a more efficient way to expose this interface rather than always allocating memory and copying the data???

		uint16_t* indices = new uint16_t[geometry_index_count];
		float3* positions = new float3[geometry_vertex_count];
		float3* normals = new float3[geometry_vertex_count];
		float3* tangents = new float3[geometry_vertex_count];
		float3* bitangents = new float3[geometry_vertex_count];
		float2* texture_coordinates = new float2[geometry_vertex_count];
		float4* colors = new float4[geometry_vertex_count];

		BCS_RESULT read_indices = geometry_mesh->get_property(_geometry_mesh_property_indices, 0, 0, geometry_index_count, _graphics_data_format_r16_uint, indices);
		BCS_RESULT read_positions = geometry_mesh->get_property(_geometry_mesh_property_positions, 0, 0, geometry_vertex_count, _graphics_data_format_r32g32b32_float, positions);
		BCS_RESULT read_normals = geometry_mesh->get_property(_geometry_mesh_property_normals, 0, 0, geometry_vertex_count, _graphics_data_format_r32g32b32_float, normals);
		BCS_RESULT read_tangents = geometry_mesh->get_property(_geometry_mesh_property_tangents, 0, 0, geometry_vertex_count, _graphics_data_format_r32g32b32_float, tangents);
		BCS_RESULT read_bitangents = geometry_mesh->get_property(_geometry_mesh_property_bitangents, 0, 0, geometry_vertex_count, _graphics_data_format_r32g32b32_float, bitangents);
		BCS_RESULT read_texture_coordinates = geometry_mesh->get_property(_geometry_mesh_property_texture_coordinates, 0, 0, geometry_vertex_count, _graphics_data_format_r32g32_float, texture_coordinates);
		BCS_RESULT read_colors = geometry_mesh->get_property(_geometry_mesh_property_colors, 0, 0, geometry_vertex_count, _graphics_data_format_r32g32b32a32_float, colors);

		ASSERT(BCS_SUCCEEDED(read_indices));
		ASSERT(BCS_SUCCEEDED(read_positions));
		ASSERT(BCS_SUCCEEDED(read_normals));
		ASSERT(BCS_SUCCEEDED(read_tangents));
		ASSERT(BCS_SUCCEEDED(read_bitangents));
		ASSERT(BCS_SUCCEEDED(read_texture_coordinates));
		ASSERT(BCS_SUCCEEDED(read_colors));

		for (unsigned int vertex_index = 0; vertex_index < geometry_vertex_count; vertex_index++)
		{
			auto& vertex = mesh_temporary.raw_vertices_block.emplace_back();

			float3 position = positions[vertex_index];
			position.x = (position.x - position_minimum.x) / position_range.x;
			position.y = (position.y - position_minimum.y) / position_range.y;
			position.z = (position.z - position_minimum.z) / position_range.z;

			float2 texcoord = texture_coordinates[vertex_index];
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
			vertex.vertex_color = { colors[vertex_index].x, colors[vertex_index].y, colors[vertex_index].z };
		}

		for (unsigned int indice_index = 0; indice_index < geometry_index_count; indice_index++)
		{
			auto& index = mesh_temporary.raw_indices_block.emplace_back();

			index._word = indices[indice_index];
		}

		mesh_temporary.flags.set(_per_mesh_raw_data_flags_indices_are_triangle_lists, true);

		if (mesh.prt_vertex_type > _mesh_transfer_vertex_type_definition_no_prt)
		{
			struct s_render_geometry_user_data_prt_info
			{
				unsigned int unknown0;
				unsigned int unknown4;
				unsigned int num_coefficients;
				unsigned int unknownC;
				unsigned int unknown10;
			};
			s_render_geometry_user_data_prt_info prt_info = {};

			prt_info.unknown0 = 3;
			prt_info.unknown4 = 0;
			int order = 0;
			switch (mesh.prt_vertex_type)
			{
			case _mesh_transfer_vertex_type_definition_no_prt:
				prt_info.num_coefficients = 0;
				order = 0;
				break;
			case _mesh_transfer_vertex_type_definition_prt_ambient:
				prt_info.num_coefficients = 1;
				order = 0;
				break;
			case _mesh_transfer_vertex_type_definition_prt_linear:
				prt_info.num_coefficients = 4;
				order = 1;
				break;
			case _mesh_transfer_vertex_type_definition_prt_quadratic:
				prt_info.num_coefficients = 9;
				order = 2;
				break;
			}
			prt_info.unknownC = 0;
			prt_info.unknown10 = 0;

			auto& prt_user_data = render_geometry.user_data_block.emplace_back();
			prt_user_data.user_data.append_elements(reinterpret_cast<char*>(&prt_info), sizeof(prt_info));
			prt_user_data.user_data_header.data_type = _render_geometry_user_data_type_definition_prt_info;
			prt_user_data.user_data_header.data_count = 1;
			prt_user_data.user_data_header.data_size = sizeof(prt_info);

			float const* const* surface_coefficient_planes;
			float const* const* subsurface_coefficient_planes;
			unsigned int num_coefficient_planes;
			BCS_RESULT radiance_transfer_read_result = radiance_transfer_read(radiance_transfer_engine, geometry_mesh, surface_coefficient_planes, subsurface_coefficient_planes, num_coefficient_planes);
			ASSERT(BCS_SUCCEEDED(radiance_transfer_read_result));
			ASSERT(num_coefficient_planes == prt_info.num_coefficients);

			auto& prt_data_block = render_geometry.per_mesh_prt_data_block.emplace_back();

			for (unsigned int vertex_index = 0; vertex_index < geometry_vertex_count; vertex_index++)
			{
				// red
				for (unsigned int coefficient_index = 0; coefficient_index < prt_info.num_coefficients; coefficient_index++)
				{
					float coefficient = surface_coefficient_planes[coefficient_index][vertex_index];
					const char* pca_data_start = reinterpret_cast<const char*>(&coefficient);
					const char* pca_data_end = reinterpret_cast<const char*>(&coefficient + 1);
					prt_data_block.mesh_pca_data.append_elements(pca_data_start, pca_data_end);
				}
				// green
				for (unsigned int coefficient_index = 0; coefficient_index < prt_info.num_coefficients; coefficient_index++)
				{
					float coefficient = surface_coefficient_planes[coefficient_index][vertex_index];
					const char* pca_data_start = reinterpret_cast<const char*>(&coefficient);
					const char* pca_data_end = reinterpret_cast<const char*>(&coefficient + 1);
					prt_data_block.mesh_pca_data.append_elements(pca_data_start, pca_data_end);
				}
				// blue
				for (unsigned int coefficient_index = 0; coefficient_index < prt_info.num_coefficients; coefficient_index++)
				{
					float coefficient = surface_coefficient_planes[coefficient_index][vertex_index];
					const char* pca_data_start = reinterpret_cast<const char*>(&coefficient);
					const char* pca_data_end = reinterpret_cast<const char*>(&coefficient + 1);
					prt_data_block.mesh_pca_data.append_elements(pca_data_start, pca_data_end);
				}
			}
			ASSERT(prt_data_block.mesh_pca_data.size() == (sizeof(float3) * prt_info.num_coefficients * geometry_vertex_count));
		}

		delete[] indices;
		delete[] positions;
		delete[] normals;
		delete[] tangents;
		delete[] bitangents;
		delete[] texture_coordinates;
		delete[] colors;
	}

	BCS_RESULT radiance_transfer_destroy_result = radiance_transfer_destroy(radiance_transfer_engine);
	ASSERT(BCS_SUCCEEDED(radiance_transfer_destroy_result));

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
	if (BCS_SUCCEEDED(get_command_line_argument_result2))
	{
		char model_filepath[260];
		memcpy(model_filepath, tags_directory, strlen(tags_directory) + 1);
		strcat_s(model_filepath, "geometrytest.model");

		char render_model_filepath[260];
		memcpy(render_model_filepath, tags_directory, strlen(tags_directory) + 1);
		strcat_s(render_model_filepath, "geometrytest.render_model");

		c_high_level_tag_file_writer tag_file_writer(engine_platform_build, model_filepath, *model_tag);
		c_high_level_tag_file_writer tag_file_writer2(engine_platform_build, render_model_filepath, *render_model_tag);
	}

	BCS_RESULT geometry_scene_destroy_result = geometry_scene_destroy(geometry_scene);
	BCS_FAIL_THROW(geometry_scene_destroy_result);

	debug_point;

	BCS_FAIL_RETURN(rs1);

	return 0;
}
