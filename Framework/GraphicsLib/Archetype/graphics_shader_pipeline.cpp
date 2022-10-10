#include "graphicslib-private-pch.h"

c_graphics_shader_pipeline::c_graphics_shader_pipeline()
{

}

c_graphics_shader_pipeline::~c_graphics_shader_pipeline()
{

}

BCS_RESULT graphics_shader_pipeline_compute_create(
	c_graphics* graphics,
	c_graphics_shader_binary* shader_binary,
	c_graphics_shader_pipeline*& shader_pipeline,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_shader_pipeline_compute_create(
			graphics_d3d12,
			reinterpret_cast<c_graphics_shader_binary_d3d12*>(shader_binary),
			*reinterpret_cast<c_graphics_shader_pipeline_compute_d3d12**>(&shader_pipeline),
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_shader_pipeline_graphics_create(
	c_graphics* graphics,
	c_graphics_shader_binary** shader_binaries,
	uint32_t num_shader_binaries,
	e_graphics_data_format* render_target_data_formats,
	uint32_t num_render_targets,
	e_graphics_data_format* depth_data_format,
	c_graphics_vertex_layout* vertex_layout,
	c_graphics_shader_pipeline*& shader_pipeline,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_shader_pipeline_graphics_create(
			graphics_d3d12,
			reinterpret_cast<c_graphics_shader_binary_d3d12**>(shader_binaries),
			num_shader_binaries,
			render_target_data_formats,
			num_render_targets,
			depth_data_format,
			dynamic_cast<c_graphics_vertex_layout_d3d12*>(vertex_layout),
			*reinterpret_cast<c_graphics_shader_pipeline_graphics_d3d12**>(&shader_pipeline),
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_shader_pipeline_destroy(c_graphics_shader_pipeline* shader_pipeline)
{
	if (c_graphics_shader_pipeline_graphics_d3d12* shader_pipeline_d3d12 = dynamic_cast<c_graphics_shader_pipeline_graphics_d3d12*>(shader_pipeline))
	{
		return graphics_d3d12_shader_pipeline_destroy(shader_pipeline_d3d12);
	}
	return BCS_E_UNSUPPORTED;
}
