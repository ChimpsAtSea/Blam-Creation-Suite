#include "graphicslib-private-pch.h"

c_graphics_render_target::c_graphics_render_target()
{

}

c_graphics_render_target::~c_graphics_render_target()
{

}

BCS_RESULT graphics_swapchain_color_render_target_create(
	c_graphics* graphics,
	c_graphics_swap_chain* swap_chain,
	uint32_t swap_chain_buffer_index,
	float4 clear_color,
	c_graphics_render_target*& render_target,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		c_graphics_swap_chain_d3d12* swap_chain_d3d12 = dynamic_cast<c_graphics_swap_chain_d3d12*>(swap_chain);
		if (swap_chain_d3d12 == nullptr)
		{
			return BCS_E_INVALID_ARGUMENT;
		}
		return graphics_d3d12_swapchain_color_render_target_create(
			graphics_d3d12,
			swap_chain_d3d12,
			swap_chain_buffer_index,
			clear_color,
			*reinterpret_cast<c_graphics_render_target_d3d12**>(&render_target),
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_color_render_target_create(
	c_graphics* graphics,
	uint32_t width,
	uint32_t height,
	e_graphics_data_format format,
	float4 clear_color,
	c_graphics_render_target*& render_target,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_color_render_target_create(
			graphics_d3d12, 
			width, 
			height, 
			format, 
			clear_color,
			*reinterpret_cast<c_graphics_render_target_d3d12**>(&render_target), 
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_depth_stencil_render_target_create(
	c_graphics* graphics,
	uint32_t width,
	uint32_t height,
	e_graphics_data_format format,
	float clear_depth,
	unsigned char stencil_value,
	c_graphics_render_target*& render_target,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_depth_stencil_render_target_create(
			graphics_d3d12, 
			width, 
			height,
			format,
			clear_depth,
			stencil_value,
			*reinterpret_cast<c_graphics_render_target_d3d12**>(&render_target), 
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_render_target_destroy(c_graphics_render_target* render_target)
{
	if (c_graphics_render_target_d3d12* render_target_d3d12 = dynamic_cast<c_graphics_render_target_d3d12*>(render_target))
	{
		return graphics_d3d12_render_target_destroy(render_target_d3d12);
	}
	return BCS_E_UNSUPPORTED;
}
