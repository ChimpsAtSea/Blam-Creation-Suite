#include "graphicslib-private-pch.h"

c_render_context::c_render_context() :
	on_render_background(),
	on_render_foreground(),
	on_device_lost(),
	on_device_recover()
{

}

c_render_context::~c_render_context()
{

}

BCS_RESULT render_context_window_create(
	c_window& window,
	float4 background_color,
	c_render_context*& render_context,
	c_graphics* existing_graphics_context)
{
	return window_render_context_window_create(
		window,
		background_color,
		*reinterpret_cast<c_window_render_context**>(&render_context),
		existing_graphics_context);
}

BCS_RESULT render_context_imgui_create(
	c_render_context& parent_render_context,
	c_viewport& viewport,
	float4 clear_color,
	c_render_context*& render_context)
{
	return render_context_imgui_viewport_create(
		parent_render_context,
		viewport,
		clear_color,
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
		return render_context_imgui_viewport_destroy(imgui_viewport_render_context);
	}
	return BCS_E_UNSUPPORTED;
}
