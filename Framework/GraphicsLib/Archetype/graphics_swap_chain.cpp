#include "graphicslib-private-pch.h"

c_graphics_swap_chain::c_graphics_swap_chain()
{

}

c_graphics_swap_chain::~c_graphics_swap_chain()
{

}

BCS_DEBUG_API BCS_RESULT graphics_swap_chain_create(
	c_graphics* graphics,
	c_window* window,
	uint32_t num_back_buffers,
	c_graphics_swap_chain*& swap_chain,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		c_window_windows* window_windows = dynamic_cast<c_window_windows*>(window);
		if (window_windows == nullptr)
		{
			return BCS_E_INVALID_ARGUMENT;
		}
		return graphics_d3d12_swap_chain_create(
			graphics_d3d12,
			window_windows,
			num_back_buffers,
			*reinterpret_cast<c_graphics_swap_chain_d3d12**>(&swap_chain),
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_DEBUG_API BCS_RESULT graphics_swap_chain_create(
	c_graphics* graphics,
	c_imgui_viewport_render_context* imgui_viewport_render_context,
	uint32_t num_back_buffers,
	c_graphics_swap_chain*& swap_chain,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_swap_chain_create(
			graphics_d3d12,
			imgui_viewport_render_context,
			num_back_buffers,
			*reinterpret_cast<c_graphics_swap_chain_d3d12**>(&swap_chain),
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_DEBUG_API BCS_RESULT graphics_swap_chain_destroy(c_graphics_swap_chain* swap_chain)
{
	if (c_graphics_swap_chain_d3d12* swap_chain_d3d12 = dynamic_cast<c_graphics_swap_chain_d3d12*>(swap_chain))
	{
		return graphics_d3d12_swap_chain_destroy(swap_chain_d3d12);
	}
	return BCS_E_UNSUPPORTED;
}
