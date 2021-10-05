#include "graphicslib-private-pch.h"

c_graphics_render_pass::c_graphics_render_pass()
{

}

c_graphics_render_pass::~c_graphics_render_pass()
{

}

BCS_RESULT graphics_render_pass_create(
	c_graphics* graphics,
	c_graphics_render_target** color_render_targets,
	c_graphics_render_target** depth_render_targets,
	unsigned long num_color_render_targets,
	unsigned long num_depth_render_targets,
	unsigned long num_render_target_per_frame,
	unsigned long num_render_target_frames,
	c_graphics_render_pass*& render_pass,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_render_pass_create(
			graphics_d3d12,
			reinterpret_cast<c_graphics_render_target_d3d12**>(color_render_targets),
			reinterpret_cast<c_graphics_render_target_d3d12**>(depth_render_targets),
			num_color_render_targets,
			num_depth_render_targets,
			num_render_target_per_frame,
			num_render_target_frames,
			*reinterpret_cast<c_graphics_render_pass_d3d12**>(&render_pass), 
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_render_pass_destroy(c_graphics_render_pass* render_pass)
{
	if (c_graphics_render_pass_d3d12* render_pass_d3d12 = dynamic_cast<c_graphics_render_pass_d3d12*>(render_pass))
	{
		return graphics_d3d12_render_pass_destroy(render_pass_d3d12);
	}
	return BCS_E_UNSUPPORTED;
}
