#pragma once

class c_graphics_d3d12;
class c_graphics_shader_binary_d3d12;

class c_graphics_shader_pipeline_d3d12 :
	public c_graphics_shader_pipeline
{
public:
	c_graphics_shader_pipeline_d3d12(
		c_graphics_d3d12& graphics,
		c_graphics_shader_binary_d3d12* shader_binaries,
		unsigned long num_shader_binaries,
		const char* debug_name);
	virtual ~c_graphics_shader_pipeline_d3d12();

	c_graphics& graphics;
};

BCS_RESULT graphics_d3d12_shader_pipeline_create(
	c_graphics_d3d12* graphics,
	c_graphics_shader_binary_d3d12* shader_binaries,
	unsigned long num_shader_binaries,
	c_graphics_shader_pipeline_d3d12*& shader_pipeline,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_shader_pipeline_destroy(c_graphics_shader_pipeline_d3d12* shader_pipeline);
