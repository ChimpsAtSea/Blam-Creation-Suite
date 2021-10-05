#include "graphicslib-private-pch.h"

c_imgui_viewport_render_context::c_imgui_viewport_render_context(c_imgui_context& imgui_context)
{

}

c_imgui_viewport_render_context::~c_imgui_viewport_render_context()
{

}

void c_imgui_viewport_render_context::render()
{
}

BCS_RESULT c_imgui_viewport_render_context::get_window(c_window*& window)
{
	return BCS_E_NOT_IMPLEMENTED;
}

BCS_RESULT c_imgui_viewport_render_context::get_imgui_context(c_imgui_context*& imgui_context)
{
	return BCS_E_NOT_IMPLEMENTED;
}

BCS_RESULT c_imgui_viewport_render_context::get_graphics(c_graphics*& graphics)
{
	return BCS_E_NOT_IMPLEMENTED;
}

unsigned long c_imgui_viewport_render_context::get_width()
{
	return 0;
}

unsigned long c_imgui_viewport_render_context::get_height()
{
	return 0;
}

float c_imgui_viewport_render_context::get_width_float()
{
	return 0;
}

float c_imgui_viewport_render_context::get_height_float()
{
	return 0;
}

BCS_RESULT imgui_viewport_render_context_window_create(
	c_imgui_context& imgui_context,
	c_imgui_viewport_render_context*& render_context)
{
	try
	{
		render_context = new c_imgui_viewport_render_context(imgui_context);
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FATAL;
	}
	return BCS_S_OK;
}

BCS_RESULT imgui_viewport_render_context_destroy(c_imgui_viewport_render_context* render_context)
{
	try
	{
		delete render_context;
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FATAL;
	}
	return BCS_S_OK;
}