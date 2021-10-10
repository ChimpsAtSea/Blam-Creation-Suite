#include "graphicslib-private-pch.h"

c_graphics_render_instance::c_graphics_render_instance()
{

}

c_graphics_render_instance::~c_graphics_render_instance()
{

}

BCS_RESULT graphics_render_instance_create(
	c_graphics* graphics,
	c_graphics_render_instance*& render_instance,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_render_instance_create(
			graphics_d3d12,
			*reinterpret_cast<c_graphics_render_instance_d3d12**>(&render_instance), 
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_render_instance_destroy(c_graphics_render_instance* render_instance)
{
	if (c_graphics_render_instance_d3d12* render_instance_d3d12 = dynamic_cast<c_graphics_render_instance_d3d12*>(render_instance))
	{
		return graphics_d3d12_render_instance_destroy(render_instance_d3d12);
	}
	return BCS_E_UNSUPPORTED;
}
