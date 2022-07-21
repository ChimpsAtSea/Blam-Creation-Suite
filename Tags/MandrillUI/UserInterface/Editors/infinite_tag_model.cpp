#include "mandrillui-private-pch.h"

c_infinite_tag_model::c_infinite_tag_model(
	c_graphics& graphics, 
	blofeld::infinite::h_render_model_definition& render_model, 
	uint32_t mesh_index) :
	graphics(graphics),
	render_model(render_model),
	mesh(),
	graphics_shader_pipeline(),
	render_instance()
{
	mesh = new() c_infinite_tag_mesh(graphics, render_model, mesh_index);

	c_graphics_shader_binary* graphics_shader_binaries[2];
	BCS_RESULT vertex_shader_binary_result = graphics_shader_binary_create(&graphics, _bcs_resource_type_generic_infinite_vertex_shader, graphics_shader_binaries[0]);
	BCS_FAIL_THROW(vertex_shader_binary_result);

	BCS_RESULT pixel_shader_binary_result = graphics_shader_binary_create(&graphics, _bcs_resource_type_generic_infinite_pixel_shader, graphics_shader_binaries[1]);
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
		mesh->vertex_layout,
		graphics_shader_pipeline);
	BCS_FAIL_THROW(shader_pipeline_result);

	BCS_RESULT model_instance_create_result = graphics_render_instance_create(&graphics, render_instance);
	BCS_FAIL_THROW(model_instance_create_result);

	BCS_RESULT vertex_shader_binary_result2 = graphics_shader_binary_destroy(graphics_shader_binaries[0]);
	BCS_FAIL_THROW(vertex_shader_binary_result);

	BCS_RESULT pixel_shader_binary_result2 = graphics_shader_binary_destroy(graphics_shader_binaries[1]);
	BCS_FAIL_THROW(pixel_shader_binary_result);
}

c_infinite_tag_model::~c_infinite_tag_model()
{
	delete mesh;
}

void c_infinite_tag_model::render()
{
	graphics_shader_pipeline->bind();

	c_graphics_buffer* render_instance_buffer;
	render_instance->get_graphics_buffer(render_instance_buffer);
	render_instance->update_buffers();

	render_instance_buffer->bind(1);

	if (mesh->graphics_geometry)
	{
		mesh->graphics_geometry->render_geometry();
	}
}
