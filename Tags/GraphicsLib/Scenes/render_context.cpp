#include "graphicslib-private-pch.h"

c_render_context::c_render_context()
{

}

c_render_context::~c_render_context()
{

}

BCS_RESULT render_context_window_create(
	c_window& window,
	float4 background_color,
	c_render_context*& render_context)
{
	return window_render_context_window_create(
		window,
		background_color,
		*reinterpret_cast<c_window_render_context**>(&render_context));
}

BCS_RESULT render_context_imgui_create(
	c_imgui_context& imgui_context,
	c_render_context*& render_context)
{
	return imgui_viewport_render_context_window_create(
		imgui_context,
		*reinterpret_cast<c_imgui_viewport_render_context**>(&render_context));
}

BCS_RESULT render_context_destroy(c_render_context* render_context)
{
	if (c_window_render_context* window_render_context = dynamic_cast<c_window_render_context*>(render_context))
	{
		return window_render_context_destroy(window_render_context);
	}
	if (c_imgui_viewport_render_context* imgui_viewport_render_context = dynamic_cast<c_imgui_viewport_render_context*>(render_context))
	{
		return imgui_viewport_render_context_destroy(imgui_viewport_render_context);
	}
	return BCS_E_UNSUPPORTED;
}
