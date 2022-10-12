#include "lightmapresearch-private-pch.h"

#define position_render_target render_targets[0]
#define color_render_target render_targets[1]
#define normal_render_target render_targets[2]
#define tangent_render_target render_targets[3]
#define bitangent_render_target render_targets[4]
#define uv_render_target render_targets[5]

c_lightmap::c_lightmap(c_graphics& _graphics, uint32_t resolution) :
	graphics(_graphics),
	lightmap_render_meshes(),
	vertex_layout(),
	uv_space_shader_pipeline(),
	compute_test_shader_pipeline(),
	render_instance(),
	render_targets(),
	viewport(),
	render_pass(),
	render_pass_callback_handle(),
	viewport_width(resolution),
	viewport_height(resolution),
	graphics_register_layout(),
	compute_register_layout()
{

}

c_lightmap::~c_lightmap()
{

}





class c_lightmap_render_mesh
{
public:
	c_graphics_buffer* index_buffer;
	c_graphics_buffer* vertex_position_buffer;
	c_graphics_buffer* vertex_colors_buffer;
	c_graphics_buffer* vertex_normals_buffer;
	c_graphics_buffer* vertex_tangents_buffer;
	c_graphics_buffer* vertex_bitangents_buffer;
	c_graphics_buffer* vertex_texcoord_buffer;
	c_graphics_buffer* vertex_lightmap_texcoord_buffer;
	c_graphics_geometry* geometry;

	c_lightmap_render_mesh(c_graphics& graphics, c_graphics_vertex_layout* vertex_layout, c_geometry_mesh* mesh)
	{
		BCS_RESULT index_buffer_create_result = graphics_buffer_create(
			&graphics,
			_graphics_buffer_type_generic,
			sizeof(unsigned int),
			mesh->get_index_count(),
			index_buffer,
			"Debug Triangle Index Buffer");
		BCS_FAIL_THROW(index_buffer_create_result);

		BCS_RESULT vertex_position_buffer_create_result = graphics_buffer_create(
			&graphics,
			_graphics_buffer_type_generic,
			sizeof(float3),
			mesh->get_vertex_count(),
			vertex_position_buffer,
			"Debug Triangle Vertex Position Buffer");
		BCS_FAIL_THROW(vertex_position_buffer_create_result);

		BCS_RESULT vertex_colors_buffer_create_result = graphics_buffer_create(
			&graphics,
			_graphics_buffer_type_generic,
			sizeof(float4),
			mesh->get_vertex_count(),
			vertex_colors_buffer,
			"Debug Triangle Vertex Color Buffer");
		BCS_FAIL_THROW(vertex_colors_buffer_create_result);

		BCS_RESULT vertex_normals_buffer_create_result = graphics_buffer_create(
			&graphics,
			_graphics_buffer_type_generic,
			sizeof(float3),
			mesh->get_vertex_count(),
			vertex_normals_buffer,
			"Debug Triangle Vertex Normal Buffer");
		BCS_FAIL_THROW(vertex_normals_buffer_create_result);

		BCS_RESULT vertex_tangents_buffer_create_result = graphics_buffer_create(
			&graphics,
			_graphics_buffer_type_generic,
			sizeof(float3),
			mesh->get_vertex_count(),
			vertex_tangents_buffer,
			"Debug Triangle Vertex Tangent Buffer");
		BCS_FAIL_THROW(vertex_tangents_buffer_create_result);

		BCS_RESULT vertex_bitangents_buffer_create_result = graphics_buffer_create(
			&graphics,
			_graphics_buffer_type_generic,
			sizeof(float3),
			mesh->get_vertex_count(),
			vertex_bitangents_buffer,
			"Debug Triangle Vertex Bitangent Buffer");
		BCS_FAIL_THROW(vertex_bitangents_buffer_create_result);

		BCS_RESULT vertex_texcoord_buffer_create_result = graphics_buffer_create(
			&graphics,
			_graphics_buffer_type_generic,
			sizeof(float2),
			mesh->get_vertex_count(),
			vertex_texcoord_buffer,
			"Debug Triangle Vertex Texcoord Buffer");
		BCS_FAIL_THROW(vertex_texcoord_buffer_create_result);

		BCS_RESULT vertex_lightmap_texcoord_buffer_create_result = graphics_buffer_create(
			&graphics,
			_graphics_buffer_type_generic,
			sizeof(float2),
			mesh->get_vertex_count(),
			vertex_lightmap_texcoord_buffer,
			"Debug Triangle Vertex Lightmap Texcoord Buffer");
		BCS_FAIL_THROW(vertex_lightmap_texcoord_buffer_create_result);

		BCS_RESULT write_index_buffer_result = index_buffer->write_data(mesh->get_mesh_indices_uint(), sizeof(unsigned int), mesh->get_index_count());
		BCS_RESULT write_vertex_position_buffer_result = vertex_position_buffer->write_data(mesh->get_positions(), sizeof(float3), mesh->get_vertex_count());
		BCS_RESULT write_vertex_colors_buffer_result = vertex_colors_buffer->write_data(mesh->get_color_set(0), sizeof(float4), mesh->get_vertex_count());
		BCS_RESULT write_vertex_normals_buffer_result = vertex_normals_buffer->write_data(mesh->get_normals(), sizeof(float3), mesh->get_vertex_count());
		BCS_RESULT write_vertex_tangents_buffer_result = vertex_tangents_buffer->write_data(mesh->get_tangents(), sizeof(float3), mesh->get_vertex_count());
		BCS_RESULT write_vertex_bitangents_buffer_result = vertex_bitangents_buffer->write_data(mesh->get_bitangents(), sizeof(float3), mesh->get_vertex_count());
		BCS_RESULT write_vertex_texcoord_buffer_result = vertex_texcoord_buffer->write_data(mesh->get_texture_coordinate_set(0), sizeof(float2), mesh->get_vertex_count());
		BCS_RESULT write_vertex_lightmap_texcoord_buffer_result = vertex_lightmap_texcoord_buffer->write_data(mesh->get_texture_coordinate_set(1), sizeof(float2), mesh->get_vertex_count());

		BCS_FAIL_THROW(write_index_buffer_result);
		BCS_FAIL_THROW(write_vertex_position_buffer_result);
		BCS_FAIL_THROW(write_vertex_colors_buffer_result);
		BCS_FAIL_THROW(write_vertex_normals_buffer_result);
		BCS_FAIL_THROW(write_vertex_tangents_buffer_result);
		BCS_FAIL_THROW(write_vertex_bitangents_buffer_result);
		BCS_FAIL_THROW(write_vertex_texcoord_buffer_result);
		BCS_FAIL_THROW(write_vertex_lightmap_texcoord_buffer_result);

		c_graphics_buffer* vertex_buffers[] =
		{
			vertex_position_buffer,
			vertex_colors_buffer,
			vertex_normals_buffer,
			vertex_tangents_buffer,
			vertex_bitangents_buffer,
			vertex_texcoord_buffer,
			vertex_lightmap_texcoord_buffer,
		};

		BCS_RESULT graphics_geometry_result = graphics_geometry_create(
			&graphics,
			index_buffer,
			mesh->get_index_count(),
			vertex_buffers,
			_countof(vertex_buffers),
			vertex_layout,
			geometry);
	}

	~c_lightmap_render_mesh()
	{
		BCS_RESULT destroy_index_buffer_result = graphics_buffer_destroy(index_buffer);
		BCS_RESULT destroy_vertex_position_buffer_result = graphics_buffer_destroy(vertex_position_buffer);
		BCS_RESULT destroy_vertex_colors_buffer_result = graphics_buffer_destroy(vertex_colors_buffer);
		BCS_RESULT destroy_vertex_normals_buffer_result = graphics_buffer_destroy(vertex_normals_buffer);
		BCS_RESULT destroy_vertex_tangents_buffer_result = graphics_buffer_destroy(vertex_tangents_buffer);
		BCS_RESULT destroy_vertex_bitangents_buffer_result = graphics_buffer_destroy(vertex_bitangents_buffer);
		BCS_RESULT destroy_vertex_texcoord_buffer_result = graphics_buffer_destroy(vertex_texcoord_buffer);
		BCS_RESULT destroy_vertex_lightmap_texcoord_buffer_result = graphics_buffer_destroy(vertex_lightmap_texcoord_buffer);

		BCS_FAIL_THROW(destroy_index_buffer_result);
		BCS_FAIL_THROW(destroy_vertex_position_buffer_result);
		BCS_FAIL_THROW(destroy_vertex_colors_buffer_result);
		BCS_FAIL_THROW(destroy_vertex_normals_buffer_result);
		BCS_FAIL_THROW(destroy_vertex_tangents_buffer_result);
		BCS_FAIL_THROW(destroy_vertex_bitangents_buffer_result);
		BCS_FAIL_THROW(destroy_vertex_texcoord_buffer_result);;
		BCS_FAIL_THROW(destroy_vertex_lightmap_texcoord_buffer_result);
	}
};

void c_lightmap::init()
{
	const char* model_path;
	BCS_RESULT get_command_line_argument_result = command_line_get_argument("modelpath", model_path);
	BCS_FAIL_THROW(get_command_line_argument_result);

	c_geometry_scene* geometry_scene;
	BCS_RESULT load_geometry_scene_from_file_result = load_geometry_scene_from_file(model_path, geometry_scene);
	BCS_FAIL_THROW(load_geometry_scene_from_file_result);

	h_uv_atlas_packer uv_atlas_packer;
	BCS_RESULT create_uv_atlas_packer_result = create_uv_atlas_packer(uv_atlas_packer, __max(viewport_width, viewport_height));
	BCS_FAIL_THROW(create_uv_atlas_packer_result);

	unsigned int num_meshes = geometry_scene->get_num_meshes();
	for (unsigned int mesh_index = 0; mesh_index < num_meshes; mesh_index++)
	{
		c_geometry_mesh* mesh = geometry_scene->get_mesh(mesh_index);

		BCS_RESULT uv_atlas_packer_add_mesh_result = uv_atlas_packer_add_mesh(uv_atlas_packer, mesh);
		BCS_FAIL_THROW(uv_atlas_packer_add_mesh_result);
	}

	BCS_RESULT uv_atlas_packer_bake_result = uv_atlas_packer_bake(uv_atlas_packer);
	BCS_FAIL_THROW(uv_atlas_packer_bake_result);

	BCS_RESULT destroy_uv_atlas_packer_result = destroy_uv_atlas_packer(uv_atlas_packer);
	BCS_FAIL_THROW(destroy_uv_atlas_packer_result);



	union
	{
		s_graphics_vertex_layout_description vertex_layout_descriptions[7];
		struct
		{
			s_graphics_vertex_layout_description vertex_layout_position;
			s_graphics_vertex_layout_description vertex_layout_color;
			s_graphics_vertex_layout_description vertex_layout_normal;
			s_graphics_vertex_layout_description vertex_layout_tangent;
			s_graphics_vertex_layout_description vertex_layout_bitangent;
			s_graphics_vertex_layout_description vertex_layout_uv0;
			s_graphics_vertex_layout_description vertex_layout_uv1;
		};
	};

	vertex_layout_position = {};
	vertex_layout_position.semantic = _graphics_vertex_layout_semantic_position;
	vertex_layout_position.semantic_index = 0;
	vertex_layout_position.data_format = _graphics_data_format_r32g32b32_float;
	vertex_layout_position.buffer_index = 0;
	vertex_layout_position.buffer_offset = 0;
	vertex_layout_position.stepping = _graphics_vertex_layout_stepping_per_vertex;
	vertex_layout_position.buffer_instance_stepping = 0;

	vertex_layout_color = {};
	vertex_layout_color.semantic = _graphics_vertex_layout_semantic_color;
	vertex_layout_color.semantic_index = 0;
	vertex_layout_color.data_format = _graphics_data_format_r32g32b32a32_float;
	vertex_layout_color.buffer_index = 1;
	vertex_layout_color.buffer_offset = 0;
	vertex_layout_color.stepping = _graphics_vertex_layout_stepping_per_vertex;
	vertex_layout_color.buffer_instance_stepping = 0;

	vertex_layout_normal = {};
	vertex_layout_normal.semantic = _graphics_vertex_layout_semantic_normal;
	vertex_layout_normal.semantic_index = 0;
	vertex_layout_normal.data_format = _graphics_data_format_r32g32b32_float;
	vertex_layout_normal.buffer_index = 2;
	vertex_layout_normal.buffer_offset = 0;
	vertex_layout_normal.stepping = _graphics_vertex_layout_stepping_per_vertex;
	vertex_layout_normal.buffer_instance_stepping = 0;

	vertex_layout_tangent = {};
	vertex_layout_tangent.semantic = _graphics_vertex_layout_semantic_tangent;
	vertex_layout_tangent.semantic_index = 0;
	vertex_layout_tangent.data_format = _graphics_data_format_r32g32b32_float;
	vertex_layout_tangent.buffer_index = 3;
	vertex_layout_tangent.buffer_offset = 0;
	vertex_layout_tangent.stepping = _graphics_vertex_layout_stepping_per_vertex;
	vertex_layout_tangent.buffer_instance_stepping = 0;

	vertex_layout_bitangent = {};
	vertex_layout_bitangent.semantic = _graphics_vertex_layout_semantic_binormal;
	vertex_layout_bitangent.semantic_index = 0;
	vertex_layout_bitangent.data_format = _graphics_data_format_r32g32b32_float;
	vertex_layout_bitangent.buffer_index = 4;
	vertex_layout_bitangent.buffer_offset = 0;
	vertex_layout_bitangent.stepping = _graphics_vertex_layout_stepping_per_vertex;
	vertex_layout_bitangent.buffer_instance_stepping = 0;

	vertex_layout_uv0 = {};
	vertex_layout_uv0.semantic = _graphics_vertex_layout_semantic_texcoord;
	vertex_layout_uv0.semantic_index = 0;
	vertex_layout_uv0.data_format = _graphics_data_format_r32g32_float;
	vertex_layout_uv0.buffer_index = 5;
	vertex_layout_uv0.buffer_offset = 0;
	vertex_layout_uv0.stepping = _graphics_vertex_layout_stepping_per_vertex;
	vertex_layout_uv0.buffer_instance_stepping = 0;

	vertex_layout_uv1 = {};
	vertex_layout_uv1.semantic = _graphics_vertex_layout_semantic_texcoord;
	vertex_layout_uv1.semantic_index = 1;
	vertex_layout_uv1.data_format = _graphics_data_format_r32g32_float;
	vertex_layout_uv1.buffer_index = 6;
	vertex_layout_uv1.buffer_offset = 0;
	vertex_layout_uv1.stepping = _graphics_vertex_layout_stepping_per_vertex;
	vertex_layout_uv1.buffer_instance_stepping = 0;

	BCS_RESULT vertex_layout_result = graphics_vertex_layout_create(
		&graphics,
		vertex_layout_descriptions,
		_countof(vertex_layout_descriptions),
		vertex_layout);



	for (unsigned int mesh_index = 0; mesh_index < num_meshes; mesh_index++)
	{
		c_geometry_mesh* mesh = geometry_scene->get_mesh(mesh_index);
		c_lightmap_render_mesh* lightmap_render_mesh = new() c_lightmap_render_mesh(graphics, vertex_layout, mesh);
		lightmap_render_meshes.push_back(lightmap_render_mesh);
	}

	float4 render_target_clear_color = { 0.0f, 0.0f, 0.0f, 1.0f };

	BCS_RESULT create_position_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32b32_float, render_target_clear_color, position_render_target, "position_render_target");
	BCS_RESULT create_color_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32b32a32_float, render_target_clear_color, color_render_target, "color_render_target");
	BCS_RESULT create_normal_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32b32_float, render_target_clear_color, normal_render_target, "normal_render_target");
	BCS_RESULT create_tangent_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32b32_float, render_target_clear_color, tangent_render_target, "tangent_render_target");
	BCS_RESULT create_bitangent_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32b32_float, render_target_clear_color, bitangent_render_target, "bitangent_render_target");
	BCS_RESULT create_uv_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32_float, render_target_clear_color, uv_render_target, "uv_render_target");

	BCS_FAIL_THROW(create_position_render_target_result);
	BCS_FAIL_THROW(create_color_render_target_result);
	BCS_FAIL_THROW(create_normal_render_target_result);
	BCS_FAIL_THROW(create_tangent_render_target_result);
	BCS_FAIL_THROW(create_bitangent_render_target_result);
	BCS_FAIL_THROW(create_uv_render_target_result);

	e_graphics_data_format render_target_formats[] =
	{
		position_render_target->get_graphics_data_format(),
		color_render_target->get_graphics_data_format(),
		normal_render_target->get_graphics_data_format(),
		tangent_render_target->get_graphics_data_format(),
		bitangent_render_target->get_graphics_data_format(),
		uv_render_target->get_graphics_data_format(),
	};
	e_graphics_data_format depth_target_format = _graphics_data_format_unspecified;

	c_graphics_shader_binary* _lightmap_debug_vertex_shader;
	BCS_RESULT vertex_shader_binary_result = graphics_shader_binary_create(
		&graphics,
		_bcs_resource_type_generic_lightmap_debug_vertex_shader,
		_lightmap_debug_vertex_shader);
	BCS_FAIL_THROW(vertex_shader_binary_result);

	c_graphics_shader_binary* lightmap_debug_pixel_shader;
	BCS_RESULT pixel_shader_binary_result = graphics_shader_binary_create(
		&graphics,
		_bcs_resource_type_generic_lightmap_debug_pixel_shader,
		lightmap_debug_pixel_shader);
	BCS_FAIL_THROW(pixel_shader_binary_result);

	s_graphics_register_layout_description graphics_register_layouts[1];
	graphics_register_layouts[0].semantic = _graphics_register_layout_unordered_access;
	graphics_register_layouts[0].register_index = 0;
	graphics_register_layouts[0].register_count = 1;
	graphics_register_layouts[0].register_space = 0;
	graphics_register_layouts[0].num_32_bit_values = 0;
	graphics_register_layouts[0].use_table = true;
	graphics_register_layouts[0].sampler_layout_description = nullptr;

	BCS_RESULT graphics_register_layout_result = graphics_register_layout_create(
		&graphics,
		_graphics_register_layout_type_graphics,
		graphics_register_layouts,
		_countof(graphics_register_layouts),
		graphics_register_layout, 
		"graphics_register_layout");
	BCS_FAIL_THROW(graphics_register_layout_result);

	c_graphics_shader_binary* graphics_shader_binaries[2] = { _lightmap_debug_vertex_shader, lightmap_debug_pixel_shader };
	BCS_RESULT uv_space_shader_pipeline_result = graphics_shader_pipeline_graphics_create(
		&graphics,
		graphics_register_layout,
		graphics_shader_binaries,
		_countof(graphics_shader_binaries),
		render_target_formats,
		_countof(render_target_formats),
		&depth_target_format,
		vertex_layout,
		uv_space_shader_pipeline);
	BCS_FAIL_THROW(uv_space_shader_pipeline_result);


	c_graphics_shader_binary* lightmap_compute_test_shader_binary;
	BCS_RESULT lightmap_compute_test_shader_binary_result = graphics_shader_binary_create(
		&graphics,
		_bcs_resource_type_generic_lightmap_compute_test_shader,
		lightmap_compute_test_shader_binary);
	BCS_FAIL_THROW(lightmap_compute_test_shader_binary_result);

	s_graphics_register_layout_description compute_register_layouts[1];
	compute_register_layouts[0].semantic = _graphics_register_layout_unordered_access;
	compute_register_layouts[0].register_index = 0;
	compute_register_layouts[0].register_count = 1;
	compute_register_layouts[0].register_space = 0;
	compute_register_layouts[0].num_32_bit_values = 0;
	compute_register_layouts[0].use_table = true;
	compute_register_layouts[0].sampler_layout_description = nullptr;

	BCS_RESULT compute_register_layout_result = graphics_register_layout_create(
		&graphics,
		_graphics_register_layout_type_compute,
		compute_register_layouts,
		_countof(compute_register_layouts),
		compute_register_layout, 
		"compute_register_layout");
	BCS_FAIL_THROW(compute_register_layout_result);

	BCS_RESULT compute_test_shader_pipeline_result = graphics_shader_pipeline_compute_create(
		&graphics,
		compute_register_layout,
		lightmap_compute_test_shader_binary,
		compute_test_shader_pipeline);
	BCS_FAIL_THROW(compute_test_shader_pipeline_result);

	BCS_RESULT graphics_buffer_create_result = graphics_buffer_create(&graphics, _graphics_buffer_type_unordered_access_view, 512 * sizeof(float4), compute_test_buffer, "compute_test_buffer");
	BCS_FAIL_THROW(graphics_buffer_create_result);

	BCS_RESULT model_instance_create_result = graphics_render_instance_create(&graphics, render_instance);
	BCS_FAIL_THROW(model_instance_create_result);

	BCS_RESULT vertex_shader_binary_result2 = graphics_shader_binary_destroy(graphics_shader_binaries[0]);
	BCS_FAIL_THROW(vertex_shader_binary_result);

	BCS_RESULT pixel_shader_binary_result2 = graphics_shader_binary_destroy(graphics_shader_binaries[1]);
	BCS_FAIL_THROW(pixel_shader_binary_result);

	debug_point;

	viewport = new() c_viewport();
	viewport->set_size(viewport_width, viewport_height);

	// position_render_target
	// normal_render_target
	// tangent_render_target
	// bitangent_render_target
	// uv_render_target



	BCS_RESULT create_render_pass_result = graphics_render_pass_create(
		&graphics,
		viewport,
		render_targets,
		nullptr,
		_countof(render_targets),
		0,
		_countof(render_targets),
		1,
		render_pass,
		"render_pass");
	BCS_FAIL_THROW(create_render_pass_result);

	render_pass->render_callback.add_callback(member_to_static_function(&c_lightmap::render_pass_callback), this, render_pass_callback_handle);

	BCS_RESULT geometry_scene_destroy_result = geometry_scene_destroy(geometry_scene);
	BCS_FAIL_THROW(geometry_scene_destroy_result);
}

void c_lightmap::deinit()
{
	BCS_RESULT destroy_render_pass = graphics_render_pass_destroy(render_pass);

	delete viewport;

	BCS_RESULT destroy_position_render_target_result = graphics_render_target_destroy(position_render_target);
	BCS_RESULT destroy_color_render_target_result = graphics_render_target_destroy(color_render_target);
	BCS_RESULT destroy_normal_render_target_result = graphics_render_target_destroy(normal_render_target);
	BCS_RESULT destroy_tangent_render_target_result = graphics_render_target_destroy(tangent_render_target);
	BCS_RESULT destroy_bitangent_render_target_result = graphics_render_target_destroy(bitangent_render_target);
	BCS_RESULT destroy_uv_render_target_result = graphics_render_target_destroy(uv_render_target);

	BCS_RESULT destroy_model_instance_result = graphics_render_instance_destroy(render_instance);
	BCS_RESULT destroy_shader_pipeline_result = graphics_shader_pipeline_destroy(uv_space_shader_pipeline);
	for (c_lightmap_render_mesh* lightmap_render_mesh : lightmap_render_meshes)
	{
		delete lightmap_render_mesh;
	}
	BCS_RESULT destroy_vertex_layout_result = graphics_vertex_layout_destroy(vertex_layout);
}

void c_lightmap::render_graphics()
{
	render_pass->render();
}

void c_lightmap::render_pass_callback()
{
	graphics_register_layout->bind();
	uv_space_shader_pipeline->bind();


	c_graphics_buffer* render_instance_buffer;
	render_instance->get_graphics_buffer(render_instance_buffer);
	render_instance->update_buffers();

	BCS_RESULT bind_buffer_result = graphics_register_layout->bind_buffer(0, 0, *render_instance_buffer);
	ASSERT(BCS_SUCCEEDED(bind_buffer_result));

	for (c_lightmap_render_mesh* lightmap_render_mesh : lightmap_render_meshes)
	{
		lightmap_render_mesh->geometry->render_geometry();
	}

	compute_register_layout->bind();
	compute_test_shader_pipeline->bind();
	compute_register_layout->bind_buffer(0, 0, *compute_test_buffer);
	compute_test_shader_pipeline->dispatch(viewport_width, viewport_height);

	debug_point;
}

void c_lightmap::render_texture_preview()
{
	static unsigned int visible_index = UINT_MAX;

	static constexpr const char* render_target_names[] =
	{
		"position",
		"color",
		"normal",
		"tangent",
		"bitangent",
		"uv",
	};
	static constexpr ImVec4 tint_colors[] =
	{
		{ 1.0f / 255.0f, 1.0f / 255.0f, 1.0f / 255.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
	};
	if (ImGui::Button("All"))
	{
		visible_index = UINT_MAX;
	}
	for (unsigned int render_target_index = 0; render_target_index < _countof(render_targets); render_target_index++)
	{
		ImGui::SameLine();
		const char* render_target_name = render_target_names[render_target_index];
		if (ImGui::Button(render_target_name))
		{
			visible_index = render_target_index;
		}
	}

	const char* render_target_name = "all";
	if (visible_index != UINT_MAX)
	{
		render_target_name = render_target_names[visible_index];
	}
	ImGui::SameLine();
	ImGui::TextUnformatted(render_target_name);

	for (unsigned int render_target_index = 0; render_target_index < _countof(render_targets); render_target_index++)
	{
		if (visible_index == UINT_MAX || visible_index == render_target_index)
		{

			c_graphics_render_target* render_target = render_targets[render_target_index];

			void* display_handle;
			if (BCS_SUCCEEDED(render_target->get_ui_image_display_handle(display_handle)))
			{
				ImVec2 start_pos = ImGui::GetCursorScreenPos();
				ImVec2 content_region = { viewport->width_float, viewport->height_float };
				if (visible_index == UINT_MAX)
				{
					content_region.x = 256;
					content_region.y = 256;
				}
				ImVec2 end_pos = { start_pos.x * content_region.x, start_pos.y * content_region.y };

				ImGui::Image(display_handle, content_region, ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f), tint_colors[render_target_index]);

				if (visible_index == UINT_MAX && !((render_target_index + 1) % 3 == 0))
				{
					ImGui::SameLine();
				}
			}
		}
	}
}

void c_lightmap::render_user_interface()
{
	ImGui::SetNextWindowPos({}, ImGuiCond_Always);
	ImGui::SetNextWindowSize({}, ImGuiCond_Always);
	if (ImGui::Begin("##scrolldraggingoverlay", 0, ImGuiWindowFlags_HorizontalScrollbar))
	{
		render_texture_preview();
	}
	ImGui::End();
}
