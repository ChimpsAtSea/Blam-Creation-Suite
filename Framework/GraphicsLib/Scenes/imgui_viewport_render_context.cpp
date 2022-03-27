#include "graphicslib-private-pch.h"

c_imgui_viewport_render_context::c_imgui_viewport_render_context(
	c_render_context& parent_render_context,
	c_viewport& viewport,
	float4 background_color) :
	parent_render_context(parent_render_context),
	viewport(viewport),
	viewport_size_changed_handle(),
	render_pass_render_handle(),
	swap_chain_resize_finish_handle(),
	depth_render_target(),
	swap_chain(),
	swap_chain_render_targets(),
	render_pass()
{
	c_graphics* graphics;
	BCS_FAIL_THROW(get_graphics(graphics));

	BCS_FAIL_THROW(graphics_depth_stencil_render_target_create(
		graphics,
		viewport.width,
		viewport.height,
		_graphics_data_format_depth_float32,
		0.0f,
		0,
		depth_render_target));
	BCS_FAIL_THROW(graphics_swap_chain_create(graphics, this, swap_chain_frames, swap_chain));

	for (unsigned long swap_chain_index = 0; swap_chain_index < swap_chain_frames; swap_chain_index++)
	{
		BCS_FAIL_THROW(graphics_swapchain_color_render_target_create(
			graphics,
			swap_chain,
			swap_chain_index,
			background_color,
			swap_chain_render_targets[swap_chain_index]));
	}

	BCS_FAIL_THROW(graphics_render_pass_create(
		graphics,
		&viewport,
		swap_chain_render_targets,
		&depth_render_target,
		swap_chain_frames,
		1,
		1,
		swap_chain_frames,
		render_pass));

	BCS_FAIL_THROW(viewport.on_size_changed.add_callback(viewport_size_changed, this, viewport_size_changed_handle));
	BCS_FAIL_THROW(render_pass->render_callback.add_callback(render_pass_render, this, render_pass_render_handle));
	BCS_FAIL_THROW(swap_chain->on_resize_finish.add_callback(swap_chain_resize_finish, this, swap_chain_resize_finish_handle));
}

c_imgui_viewport_render_context::~c_imgui_viewport_render_context()
{
	//BCS_RESULT render_target_result = graphics_render_target_destroy(render_target);
	//BCS_FAIL_THROW(render_target_result);

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
	
		// render
		// calls scene callbacks to render
		render_pass->render(swap_chain); 
	
		// present
		// sets up virtual swap chain and calls c_imgui_viewport_render_context::present
		swap_chain->present();

		if (c_window_render_context* window_render_context = dynamic_cast<c_window_render_context*>(&parent_render_context))
		{
			window_render_context->render_pass->bind_render_targets();
		}
	}
	ImGui::SetCurrentContext(old_context);
}

void c_imgui_viewport_render_context::present()
{
	unsigned long backbuffer_index = swap_chain->get_current_back_buffer_index();
	c_graphics_render_target* backbuffer = swap_chain_render_targets[backbuffer_index];

	void* display_handle;
	if (BCS_SUCCEEDED(backbuffer->get_ui_image_display_handle(display_handle)))
	{
		ImVec2 start_pos = ImGui::GetCursorScreenPos();
		ImVec2 content_region = { viewport.width_float, viewport.height_float };
		ImVec2 end_pos = { start_pos.x * content_region.x, start_pos.y * content_region.y };

		ImGui::Image(display_handle, content_region);
	}
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
	console_write_line("c_imgui_viewport_render_context> viewport resize event %u %u", width, height);

	BCS_RESULT depth_render_target_resize_result = _this.depth_render_target->resize(width, height);
	DEBUG_ASSERT(BCS_SUCCEEDED(depth_render_target_resize_result));

	debug_point;
}

void __cdecl c_imgui_viewport_render_context::render_pass_render(c_imgui_viewport_render_context& _this)
{
	_this.on_render_background();
}

void __cdecl c_imgui_viewport_render_context::swap_chain_resize_finish(c_imgui_viewport_render_context& _this, unsigned long width, unsigned long height)
{
	_this.render_pass->resize(width, height);
}

BCS_RESULT render_context_imgui_viewport_create(
	c_render_context& parent_render_context,
	c_viewport& viewport,
	float4 clear_color,
	c_imgui_viewport_render_context*& render_context)
{
	try
	{
		render_context = new() c_imgui_viewport_render_context(
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