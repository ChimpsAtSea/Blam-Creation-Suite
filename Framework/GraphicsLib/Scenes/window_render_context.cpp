#include "graphicslib-private-pch.h"

c_window_render_context::c_window_render_context(
	c_window& window,
	float4 background_color) :
	window(window),
	graphics(),
	imgui_context(),
	depth_render_target(),
	swap_chain(),
	swap_chain_render_targets(),
	render_pass()
{
	BCS_FAIL_THROW(graphics_create(_graphics_architecture_d3d12, true, graphics));
	BCS_FAIL_THROW(graphics_imgui_context_create(&window, graphics, imgui_context));
	BCS_FAIL_THROW(graphics_depth_stencil_render_target_create(
		graphics,
		window.width,
		window.height,
		_graphics_data_format_depth_float32,
		0.0f,
		0,
		depth_render_target));
	BCS_FAIL_THROW(graphics_swap_chain_create(graphics, &window, swap_chain_frames, swap_chain));

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
		&window,
		swap_chain_render_targets,
		&depth_render_target,
		swap_chain_frames,
		1,
		1,
		swap_chain_frames,
		render_pass));

	BCS_FAIL_THROW(window.on_size_changed.add_callback(window_resize, this, window_resize_handle));
	BCS_FAIL_THROW(graphics->present_callback.add_callback(graphics_present, this, graphics_present_handle));
	BCS_FAIL_THROW(graphics->render_callback.add_callback(graphics_render, this, graphics_render_handle));
	BCS_FAIL_THROW(render_pass->render_callback.add_callback(render_pass_render, this, render_pass_render_handle));
	BCS_FAIL_THROW(imgui_context->render_callback.add_callback(render_imgui, this, render_imgui_handle));
	BCS_FAIL_THROW(swap_chain->on_resize_finish.add_callback(swap_chain_resize_finish, this, swap_chain_resize_finish_handle));
}

c_window_render_context::~c_window_render_context()
{
	BCS_RESULT window_on_size_changed = window.on_size_changed.remove_callback(window_resize_handle);
	BCS_RESULT graphics_present_callback = graphics->present_callback.remove_callback(graphics_present_handle);
	BCS_RESULT graphics_render_callback = graphics->render_callback.remove_callback(graphics_render_handle);
	BCS_RESULT render_pass_render_callback = render_pass->render_callback.remove_callback(render_pass_render_handle);
	BCS_RESULT imgui_context_render_callback = imgui_context->render_callback.remove_callback(render_imgui_handle);
	BCS_RESULT swap_chain_on_resize_finish = swap_chain->on_resize_finish.remove_callback(swap_chain_resize_finish_handle);

	BCS_FAIL_THROW(window_on_size_changed);
	BCS_FAIL_THROW(graphics_present_callback);
	BCS_FAIL_THROW(graphics_render_callback);
	BCS_FAIL_THROW(render_pass_render_callback);
	BCS_FAIL_THROW(imgui_context_render_callback);
	BCS_FAIL_THROW(swap_chain_on_resize_finish);

	BCS_RESULT render_pass_destroy_result = graphics_render_pass_destroy(render_pass);
	for (unsigned long swap_chain_index = 0; swap_chain_index < swap_chain_frames; swap_chain_index++)
	{
		BCS_RESULT swap_chain_render_target_destroy_result = graphics_render_target_destroy(swap_chain_render_targets[swap_chain_index]);
		ASSERT(BCS_SUCCEEDED(swap_chain_render_target_destroy_result));
	}
	BCS_RESULT swap_chain_destroy_result = graphics_swap_chain_destroy(swap_chain);
	BCS_RESULT depth_render_target_destroy_result = graphics_render_target_destroy(depth_render_target);
	BCS_RESULT imgui_context_destroy_result = graphics_imgui_context_destroy(imgui_context);
	BCS_RESULT graphics_destroy_result = graphics_destroy(graphics);

	BCS_FAIL_THROW(render_pass_destroy_result);
	BCS_FAIL_THROW(swap_chain_destroy_result);
	BCS_FAIL_THROW(depth_render_target_destroy_result);
	BCS_FAIL_THROW(imgui_context_destroy_result);
	BCS_FAIL_THROW(graphics_destroy_result);
}

void c_window_render_context::render()
{
	while (window.update())
	{
		graphics->render_frame();
		Sleep(1);
	}
}

BCS_RESULT c_window_render_context::get_viewport(c_viewport*& out_viewport)
{
	out_viewport = &window;
	return BCS_S_OK;
}

BCS_RESULT c_window_render_context::get_window(c_window*& out_window)
{
	out_window = &window;
	return BCS_S_OK;
}

BCS_RESULT c_window_render_context::get_imgui_context(c_imgui_context*& out_imgui_context)
{
	out_imgui_context = imgui_context;
	return BCS_S_OK;
}

BCS_RESULT c_window_render_context::get_graphics(c_graphics*& out_graphics)
{
	out_graphics = graphics;
	return BCS_S_OK;
}

unsigned long c_window_render_context::get_width()
{
	return window.width;
}

unsigned long c_window_render_context::get_height()
{
	return window.height;
}

float c_window_render_context::get_width_float()
{
	return window.width_float;
}

float c_window_render_context::get_height_float()
{
	return window.height_float;
}

void c_window_render_context::window_resize(c_window_render_context& _this, unsigned long width, unsigned long height)
{
	_this.depth_render_target->resize(width, height);
	console_write_line("window resize event %u %u", width, height);
	debug_point;
}

void c_window_render_context::graphics_render(c_window_render_context& _this)
{
	_this.render_pass->render(_this.swap_chain);
}

void c_window_render_context::render_pass_render(c_window_render_context& _this)
{
	_this.on_render_background();
	_this.imgui_context->render();
}

void c_window_render_context::render_imgui(c_window_render_context& _this)
{
	_this.on_render_foreground();
}

void c_window_render_context::graphics_present(c_window_render_context& _this)
{
	_this.swap_chain->present();
}

void c_window_render_context::swap_chain_resize_finish(c_window_render_context& _this, unsigned long width, unsigned height)
{
	_this.render_pass->resize(width, height);
}

BCS_RESULT window_render_context_window_create(
	c_window& window,
	float4 background_color,
	c_window_render_context*& render_context)
{
	try
	{
		render_context = new c_window_render_context(
			window, 
			background_color);
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

BCS_RESULT window_render_context_destroy(c_window_render_context* render_context)
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