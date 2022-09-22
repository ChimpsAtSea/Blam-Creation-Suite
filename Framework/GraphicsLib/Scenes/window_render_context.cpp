#include "graphicslib-private-pch.h"

c_window_render_context::c_window_render_context(
	c_window& window,
	float4 background_color) :
	window(window),
	graphics(),
	imgui_context(),
	depth_render_target(),
	swap_chain(),
	render_pass(),
	graphics_create_result(),
	window_resize_handle(),
	graphics_render_handle(),
	render_pass_render_handle(),
	render_imgui_handle(),
	graphics_present_handle(),
	swap_chain_resize_finish_handle(),
	background_color(background_color)
{
	BCS_RESULT init_render_context_result = init_render_context();
	BCS_FAIL_THROW(init_render_context_result);
}

c_window_render_context::~c_window_render_context()
{
	BCS_RESULT window_on_size_changed = window.on_size_changed.remove_callback(window_resize_handle);
	BCS_FAIL_THROW(window_on_size_changed);

	BCS_RESULT deinit_render_context_result = deinit_render_context();
	BCS_FAIL_THROW(window_on_size_changed);
}

BCS_RESULT c_window_render_context::init_render_context()
{
	bool use_debug_layer = BCS_SUCCEEDED(command_line_has_argument_internal("graphicsdebug"));
	bool use_cpu_rendering = BCS_SUCCEEDED(command_line_has_argument_internal("forcecpurendering"));
	e_graphics_architecture graphics_architecture = _graphics_architecture_d3d12;
	if (use_cpu_rendering)
	{
		graphics_architecture = _graphics_architecture_d3d12_cpu;
	}
	BCS_FAIL_RETURN(graphics_create(graphics_architecture, use_debug_layer, graphics));
	BCS_FAIL_RETURN(graphics_imgui_context_create(&window, graphics, imgui_context));
	BCS_FAIL_RETURN(graphics_depth_stencil_render_target_create(
		graphics,
		window.width,
		window.height,
		_graphics_data_format_depth_float32,
		0.0f,
		0,
		depth_render_target));
	BCS_FAIL_RETURN(graphics_swap_chain_create(graphics, &window, swap_chain_frames, swap_chain));

	for (uint32_t swap_chain_index = 0; swap_chain_index < swap_chain_frames; swap_chain_index++)
	{
		BCS_FAIL_RETURN(graphics_swapchain_color_render_target_create(
			graphics,
			swap_chain,
			swap_chain_index,
			background_color,
			swap_chain_render_targets[swap_chain_index]));
	}

	BCS_FAIL_RETURN(graphics_render_pass_create(
		graphics,
		&window,
		swap_chain_render_targets,
		&depth_render_target,
		swap_chain_frames,
		1,
		1,
		swap_chain_frames,
		render_pass));

	BCS_FAIL_RETURN(window.on_size_changed.add_callback(window_resize, this, window_resize_handle));
	BCS_FAIL_RETURN(graphics->present_callback.add_callback(graphics_present, this, graphics_present_handle));
	BCS_FAIL_RETURN(graphics->render_callback.add_callback(graphics_render, this, graphics_render_handle));
	BCS_FAIL_RETURN(render_pass->render_callback.add_callback(render_pass_render, this, render_pass_render_handle));
	BCS_FAIL_RETURN(imgui_context->render_callback.add_callback(render_imgui, this, render_imgui_handle));
	BCS_FAIL_RETURN(swap_chain->on_resize_finish.add_callback(swap_chain_resize_finish, this, swap_chain_resize_finish_handle));

	return BCS_S_OK;
}

BCS_RESULT c_window_render_context::deinit_render_context()
{
	BCS_RESULT graphics_present_callback = graphics->present_callback.remove_callback(graphics_present_handle);
	BCS_RESULT graphics_render_callback = graphics->render_callback.remove_callback(graphics_render_handle);
	BCS_RESULT render_pass_render_callback = render_pass->render_callback.remove_callback(render_pass_render_handle);
	BCS_RESULT imgui_context_render_callback = imgui_context->render_callback.remove_callback(render_imgui_handle);
	BCS_RESULT swap_chain_on_resize_finish = swap_chain->on_resize_finish.remove_callback(swap_chain_resize_finish_handle);

	BCS_FAIL_RETURN(graphics_present_callback);
	BCS_FAIL_RETURN(graphics_render_callback);
	BCS_FAIL_RETURN(render_pass_render_callback);
	BCS_FAIL_RETURN(imgui_context_render_callback);
	BCS_FAIL_RETURN(swap_chain_on_resize_finish);

	BCS_RESULT render_pass_destroy_result = graphics_render_pass_destroy(render_pass);
	for (uint32_t swap_chain_index = 0; swap_chain_index < swap_chain_frames; swap_chain_index++)
	{
		BCS_RESULT swap_chain_render_target_destroy_result = graphics_render_target_destroy(swap_chain_render_targets[swap_chain_index]);
		ASSERT(BCS_SUCCEEDED(swap_chain_render_target_destroy_result));
	}
	BCS_RESULT swap_chain_destroy_result = graphics_swap_chain_destroy(swap_chain);
	BCS_RESULT depth_render_target_destroy_result = graphics_render_target_destroy(depth_render_target);
	BCS_RESULT imgui_context_destroy_result = graphics_imgui_context_destroy(imgui_context);
	BCS_RESULT graphics_destroy_result = graphics_destroy(graphics);

	BCS_FAIL_RETURN(render_pass_destroy_result);
	BCS_FAIL_RETURN(swap_chain_destroy_result);
	BCS_FAIL_RETURN(depth_render_target_destroy_result);
	BCS_FAIL_RETURN(imgui_context_destroy_result);
	BCS_FAIL_RETURN(graphics_destroy_result);

	return BCS_S_OK;
}

BCS_RESULT c_window_render_context::render()
{
	BCS_RESULT rs = BCS_S_OK;

	while (window.update())
	{
		if (BCS_FAILED(rs = graphics->render_frame()))
		{
			if (rs == BCS_E_GRAPHICS_DEVICE_LOST && window.allow_adapter_recovery())
			{
				on_device_lost();
				// attempt to recover to a usable GPU device
				BCS_RESULT rs1 = deinit_render_context();
				BCS_RESULT rs2 = init_render_context();
				on_device_recover();
			}
			else
			{
				return rs;
			}
		}
		Sleep(1);
	}

	return rs;
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

uint32_t c_window_render_context::get_width()
{
	return window.width;
}

uint32_t c_window_render_context::get_height()
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

void c_window_render_context::window_resize(c_window_render_context& _this, uint32_t width, uint32_t height)
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

BCS_RESULT c_window_render_context::graphics_present(c_window_render_context& _this)
{
	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = _this.swap_chain->present()))
	{
		return rs;
	}

	return rs;
}

void c_window_render_context::swap_chain_resize_finish(c_window_render_context& _this, uint32_t width, unsigned height)
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
		render_context = new() c_window_render_context(
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