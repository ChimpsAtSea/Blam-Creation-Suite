#pragma once

class c_graphics;
class c_graphics_shader_binary;

class c_graphics_shader_pipeline
{
protected:
	c_graphics_shader_pipeline();
public:
	virtual ~c_graphics_shader_pipeline();
};

BCS_DEBUG_API BCS_RESULT graphics_shader_pipeline_create(
	c_graphics* graphics,
	c_graphics_shader_binary* shader_binaries,
	unsigned long num_shader_binaries,
	c_graphics_shader_pipeline*& shader_pipeline,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_shader_pipeline_destroy(c_graphics_shader_pipeline* shader_pipeline);
