#pragma once

class c_graphics;
class c_graphics_shader_binary;
class c_graphics_vertex_layout;
class c_graphics_register_layout;

class c_graphics_shader_pipeline
{
protected:
	c_graphics_shader_pipeline();
public:
	virtual ~c_graphics_shader_pipeline();

	virtual void bind() = 0;
};

BCS_DEBUG_API BCS_RESULT graphics_shader_pipeline_compute_create(
	c_graphics* graphics,
	c_graphics_register_layout* register_layout,
	c_graphics_shader_binary* shader_binary,
	c_graphics_shader_pipeline*& shader_pipeline,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_shader_pipeline_graphics_create(
	c_graphics* graphics,
	c_graphics_register_layout* register_layout,
	c_graphics_shader_binary** shader_binaries,
	uint32_t num_shader_binaries,
	e_graphics_data_format* render_target_data_formats,
	uint32_t num_render_targets,
	e_graphics_data_format* depth_data_format,
	c_graphics_vertex_layout* vertex_layout,
	c_graphics_shader_pipeline*& shader_pipeline,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_shader_pipeline_destroy(c_graphics_shader_pipeline* shader_pipeline);
