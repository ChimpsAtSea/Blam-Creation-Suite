#include "graphicslib-private-pch.h"

c_imgui_viewport_render_context::c_imgui_viewport_render_context(
	c_render_context& parent_render_context,
	c_viewport& viewport,
	float4 clear_color) :
	parent_render_context(parent_render_context),
	viewport(viewport),
	render_target(nullptr),
	viewport_size_changed_handle()
{
	c_graphics* graphics;
	BCS_FAIL_THROW(get_graphics(graphics));

	BCS_RESULT render_target_result = graphics_color_render_target_create(graphics, 512, 512, _graphics_data_format_rgba8, clear_color, render_target);
	BCS_FAIL_THROW(render_target_result);

	BCS_RESULT add_callback_result = viewport.on_size_changed.add_callback(viewport_size_changed, this, viewport_size_changed_handle);
	BCS_FAIL_THROW(add_callback_result);
}

c_imgui_viewport_render_context::~c_imgui_viewport_render_context()
{
	BCS_RESULT render_target_result = graphics_render_target_destroy(render_target);
	BCS_FAIL_THROW(render_target_result);

	BCS_RESULT remove_callback_result = viewport.on_size_changed.remove_callback(viewport_size_changed_handle);
	BCS_FAIL_THROW(remove_callback_result);
}

void c_imgui_viewport_render_context::render()
{
	ImGuiContext* old_context = ImGui::GetCurrentContext();
	{
		ImGuiContext* new_context;

		c_imgui_context* imgui_context;
		BCS_RESULT get_imgui_context_result = parent_render_context.get_imgui_context(imgui_context);
		ASSERT(BCS_SUCCEEDED(get_imgui_context_result));

		BCS_RESULT get_imgui_context_result2 = imgui_context->get_context(new_context);
		ASSERT(BCS_SUCCEEDED(get_imgui_context_result));

		ImGui::SetCurrentContext(new_context);

		ImVec2 start_pos = ImGui::GetCursorScreenPos();
		ImVec2 content_region = { viewport.width_float, viewport.height_float };
		ImVec2 end_pos = { start_pos.x * content_region.x, start_pos.y * content_region.y };

		render_target->clear_render_target();

		void* display_handle;
		if (BCS_SUCCEEDED(render_target->get_ui_image_display_handle(display_handle)))
		{
			ImGui::Image(display_handle, content_region);
		}

	}
	ImGui::SetCurrentContext(old_context);
}

BCS_RESULT c_imgui_viewport_render_context::get_viewport(c_viewport*& out_viewport)
{
	out_viewport = &viewport;
	return BCS_S_OK;
}

BCS_RESULT c_imgui_viewport_render_context::get_window(c_window*& window)
{
	return parent_render_context.get_window(window);
}

BCS_RESULT c_imgui_viewport_render_context::get_imgui_context(c_imgui_context*& imgui_context)
{
	return parent_render_context.get_imgui_context(imgui_context);
}

BCS_RESULT c_imgui_viewport_render_context::get_graphics(c_graphics*& graphics)
{
	return parent_render_context.get_graphics(graphics);
}

unsigned long c_imgui_viewport_render_context::get_width()
{
	return viewport.width;
}

unsigned long c_imgui_viewport_render_context::get_height()
{
	return viewport.height;
}

float c_imgui_viewport_render_context::get_width_float()
{
	return viewport.width_float;
}

float c_imgui_viewport_render_context::get_height_float()
{
	return viewport.height_float;
}

void __cdecl c_imgui_viewport_render_context::viewport_size_changed(c_imgui_viewport_render_context& _this, unsigned long width, unsigned long height)
{
	BCS_RESULT render_target_resize_result = _this.render_target->resize(width, height);
	DEBUG_ASSERT(BCS_SUCCEEDED(render_target_resize_result));
}

BCS_RESULT render_context_imgui_viewport_create(
	c_render_context& parent_render_context,
	c_viewport& viewport,
	float4 clear_color,
	c_imgui_viewport_render_context*& render_context)
{
	try
	{
		render_context = new c_imgui_viewport_render_context(
			parent_render_context, 
			viewport,
			clear_color);
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

BCS_RESULT render_context_imgui_viewport_destroy(c_imgui_viewport_render_context* render_context)
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