#include "graphicslib-private-pch.h"

c_imgui_context::c_imgui_context()
{

}

c_imgui_context::~c_imgui_context()
{

}

BCS_RESULT graphics_imgui_context_create(
	c_window* window,
	c_graphics* graphics,
	c_imgui_context*& imgui_context)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		c_window_windows* window_windows = dynamic_cast<c_window_windows*>(window);
		if (window_windows == nullptr)
		{
			return BCS_E_INVALID_ARGUMENT;
		}
		return graphics_d3d12_imgui_context_create(
			window_windows,
			graphics_d3d12,
			*reinterpret_cast<c_imgui_context_d3d12**>(&imgui_context));
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_imgui_context_destroy(c_imgui_context* imgui_context)
{
	if (c_imgui_context_d3d12* imgui_context_d3d12 = dynamic_cast<c_imgui_context_d3d12*>(imgui_context))
	{
		return graphics_d3d12_imgui_context_destroy(imgui_context_d3d12);
	}
	return BCS_E_UNSUPPORTED;
}
