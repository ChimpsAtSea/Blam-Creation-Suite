#include "graphicslib-private-pch.h"

c_graphics_shader_pipeline::c_graphics_shader_pipeline()
{

}

c_graphics_shader_pipeline::~c_graphics_shader_pipeline()
{

}

BCS_RESULT graphics_shader_pipeline_create(
	c_graphics* graphics,
	c_graphics_shader_binary* shader_binaries,
	unsigned long num_shader_binaries,
	c_graphics_shader_pipeline*& shader_pipeline,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_shader_pipeline_create(
			graphics_d3d12,
			reinterpret_cast<c_graphics_shader_binary_d3d12*>(shader_binaries),
			num_shader_binaries, 
			*reinterpret_cast<c_graphics_shader_pipeline_d3d12**>(&shader_pipeline),
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_shader_pipeline_destroy(c_graphics_shader_pipeline* shader_pipeline)
{
	if (c_graphics_shader_pipeline_d3d12* shader_pipeline_d3d12 = dynamic_cast<c_graphics_shader_pipeline_d3d12*>(shader_pipeline))
	{
		return graphics_d3d12_shader_pipeline_destroy(shader_pipeline_d3d12);
	}
	return BCS_E_UNSUPPORTED;
}
