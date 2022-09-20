#include "lightmapresearch-private-pch.h"

c_lightmap::c_lightmap()
{

}

c_lightmap::~c_lightmap()
{

}

c_graphics_buffer* index_buffer;
c_graphics_buffer* vertex_position_buffer;
c_graphics_buffer* vertex_uv_buffer;
c_graphics_vertex_layout* vertex_layout;
c_graphics_geometry* geometry;
c_graphics_shader_pipeline* shader_pipeline;
c_graphics_render_instance* render_instance;
c_graphics_render_target* render_targets[5];
c_graphics_render_target*& position_render_target = render_targets[0];
c_graphics_render_target*& normal_render_target = render_targets[1];
c_graphics_render_target*& tangent_render_target = render_targets[2];
c_graphics_render_target*& binormal_render_target = render_targets[3];
c_graphics_render_target*& uv_render_target = render_targets[4];
c_viewport* viewport;
c_graphics_render_pass* render_pass;
t_callback_handle render_pass_callback_handle;

void c_lightmap::init(c_graphics& graphics)
{
	union
	{
		s_graphics_vertex_layout_description vertex_layout_descriptions[2];
		struct
		{
			s_graphics_vertex_layout_description vertex_layout_position;
			s_graphics_vertex_layout_description vertex_layout_uv;
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

	vertex_layout_uv = {};
	vertex_layout_uv.semantic = _graphics_vertex_layout_semantic_texcoord;
	vertex_layout_uv.semantic_index = 0;
	vertex_layout_uv.data_format = _graphics_data_format_r32g32_float;
	vertex_layout_uv.buffer_index = 1;
	vertex_layout_uv.buffer_offset = 0;
	vertex_layout_uv.stepping = _graphics_vertex_layout_stepping_per_vertex;
	vertex_layout_uv.buffer_instance_stepping = 0;
	
	BCS_RESULT vertex_layout_result = graphics_vertex_layout_create(
		&graphics, 
		vertex_layout_descriptions, 
		_countof(vertex_layout_descriptions), 
		vertex_layout);

	unsigned int indices[] = { 0, 1, 2, 0, 2, 3 };
	float3 positions[] = { { 0.0f, 0.0f, 0.0f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 0.0f }, { 0.0f, 1.0f, 0.0f } };
	float2 uvs[] = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f } };

	BCS_RESULT index_buffer_create_result = graphics_buffer_create(
		&graphics,
		_graphics_buffer_type_generic,
		sizeof(unsigned int),
		_countof(indices),
		index_buffer,
		"Debug Triangle Index Buffer");

	BCS_RESULT vertex_position_buffer_create_result = graphics_buffer_create(
		&graphics,
		_graphics_buffer_type_generic,
		sizeof(float3),
		_countof(positions),
		vertex_position_buffer,
		"Debug Triangle Vertex Position Buffer");

	BCS_RESULT vertex_uv_buffer_create_result = graphics_buffer_create(
		&graphics,
		_graphics_buffer_type_generic,
		sizeof(float2),
		_countof(uvs),
		vertex_uv_buffer,
		"Debug Triangle Vertex UV Buffer");

	ASSERT(BCS_SUCCEEDED(index_buffer_create_result));
	ASSERT(BCS_SUCCEEDED(vertex_position_buffer_create_result));
	ASSERT(BCS_SUCCEEDED(vertex_uv_buffer_create_result));

	BCS_RESULT write_index_buffer_result = index_buffer->write_data(indices, sizeof(indices));
	BCS_RESULT write_vertex_position_buffer_result = vertex_position_buffer->write_data(positions, sizeof(positions));
	BCS_RESULT write_vertex_uv_buffer_result = vertex_uv_buffer->write_data(uvs, sizeof(uvs));

	ASSERT(BCS_SUCCEEDED(write_index_buffer_result));
	ASSERT(BCS_SUCCEEDED(write_vertex_position_buffer_result));
	ASSERT(BCS_SUCCEEDED(write_vertex_uv_buffer_result));

	c_graphics_buffer* vertex_buffers[2] =
	{
		vertex_position_buffer,
		vertex_uv_buffer,
	};

	BCS_RESULT graphics_geometry_result = graphics_geometry_create(
		&graphics,
		index_buffer,
		static_cast<unsigned long>(_countof(indices)),
		vertex_buffers,
		_countof(vertex_buffers),
		vertex_layout,
		geometry);

	c_graphics_shader_binary* graphics_shader_binaries[2];
	BCS_RESULT vertex_shader_binary_result = graphics_shader_binary_create(
		&graphics, 
		_bcs_resource_type_generic_lightmap_debug_vertex_shader,
		graphics_shader_binaries[0]);
	BCS_FAIL_THROW(vertex_shader_binary_result);

	BCS_RESULT pixel_shader_binary_result = graphics_shader_binary_create(
		&graphics, 
		_bcs_resource_type_generic_lightmap_debug_pixel_shader, 
		graphics_shader_binaries[1]);
	BCS_FAIL_THROW(pixel_shader_binary_result);

	e_graphics_data_format render_target_formats[] = { _graphics_data_format_r8g8b8a8_unorm };
	e_graphics_data_format depth_target_format = _graphics_data_format_depth_float32;

	BCS_RESULT shader_pipeline_result = graphics_shader_pipeline_create(
		&graphics,
		graphics_shader_binaries,
		_countof(graphics_shader_binaries),
		render_target_formats,
		_countof(render_target_formats),
		&depth_target_format,
		vertex_layout,
		shader_pipeline);
	BCS_FAIL_THROW(shader_pipeline_result);

	BCS_RESULT model_instance_create_result = graphics_render_instance_create(&graphics, render_instance);
	BCS_FAIL_THROW(model_instance_create_result);

	BCS_RESULT vertex_shader_binary_result2 = graphics_shader_binary_destroy(graphics_shader_binaries[0]);
	BCS_FAIL_THROW(vertex_shader_binary_result);

	BCS_RESULT pixel_shader_binary_result2 = graphics_shader_binary_destroy(graphics_shader_binaries[1]);
	BCS_FAIL_THROW(pixel_shader_binary_result);

	debug_point;

	uint32_t viewport_width = 1024;
	uint32_t viewport_height = 1024;

	viewport = new() c_viewport();
	viewport->set_size(viewport_width, viewport_height);

	// position_render_target
	// normal_render_target
	// tangent_render_target
	// binormal_render_target
	// uv_render_target

	BCS_RESULT create_position_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32b32_float, {}, position_render_target, "position_render_target");
	BCS_RESULT create_normal_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32b32_float, {}, normal_render_target, "normal_render_target");
	BCS_RESULT create_tangent_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32b32_float, {}, tangent_render_target, "tangent_render_target");
	BCS_RESULT create_binormal_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32b32_float, {}, binormal_render_target, "binormal_render_target");
	BCS_RESULT create_uv_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32_float, {}, uv_render_target, "uv_render_target");
	
	BCS_FAIL_THROW(create_position_render_target_result);
	BCS_FAIL_THROW(create_normal_render_target_result);
	BCS_FAIL_THROW(create_tangent_render_target_result);
	BCS_FAIL_THROW(create_binormal_render_target_result);
	BCS_FAIL_THROW(create_uv_render_target_result);

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
}

void c_lightmap::deinit(c_graphics& graphics)
{
	BCS_RESULT destroy_render_pass = graphics_render_pass_destroy(render_pass);

	delete viewport;

	BCS_RESULT destroy_position_render_target_result = graphics_render_target_destroy(position_render_target);
	BCS_RESULT destroy_normal_render_target_result = graphics_render_target_destroy(normal_render_target);
	BCS_RESULT destroy_tangent_render_target_result = graphics_render_target_destroy(tangent_render_target);
	BCS_RESULT destroy_binormal_render_target_result = graphics_render_target_destroy(binormal_render_target);
	BCS_RESULT destroy_uv_render_target_result = graphics_render_target_destroy(uv_render_target);

	BCS_RESULT destroy_model_instance_result = graphics_render_instance_destroy(render_instance);
	BCS_RESULT destroy_shader_pipeline_result = graphics_shader_pipeline_destroy(shader_pipeline);
	BCS_RESULT destroy_vertex_uv_buffer_result = graphics_buffer_destroy(vertex_uv_buffer);
	BCS_RESULT destroy_vertex_position_buffer_result = graphics_buffer_destroy(vertex_position_buffer);
	BCS_RESULT destroy_index_buffer_result = graphics_buffer_destroy(index_buffer);
	BCS_RESULT destroy_vertex_layout_result = graphics_vertex_layout_destroy(vertex_layout);
}

void c_lightmap::render_graphics()
{
	render_pass->render();
}

void c_lightmap::render_pass_callback()
{
	shader_pipeline->bind();

	c_graphics_buffer* render_instance_buffer;
	render_instance->get_graphics_buffer(render_instance_buffer);
	render_instance->update_buffers();

	render_instance_buffer->bind(0);

	if (geometry)
	{
		geometry->render_geometry();
	}
}

void c_lightmap::render_user_interface()
{

	if (ImGui::Begin("Texture Test"))
	{
		ImGui::Text("Hello World");
	}
	ImGui::End();
}
