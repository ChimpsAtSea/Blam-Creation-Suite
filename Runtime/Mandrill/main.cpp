#include "mandrill-private-pch.h"

#ifdef _DEBUG
static constexpr const char window_title[] = "Mandrill Debug";
#else
static constexpr const char window_title[] = "Mandrill";
#endif
static c_window* application_window;
static c_graphics* application_graphics;
static c_imgui_context* application_imgui_context;

constexpr unsigned long swap_chain_frames = 4;

static c_graphics_render_target* depth_render_target;
static c_graphics_swap_chain* swap_chain;
static c_graphics_render_target* swap_chain_render_targets[swap_chain_frames];
static c_graphics_render_pass* render_pass;

static c_mandrill_user_interface* mandrill_user_interface;

#include "imgui_user_config.h"

#include <imgui\backends\imgui_impl_win32.h>
#include <imgui\backends\imgui_impl_dx12.h>

t_callback_handle window_resize_handle;
void window_resize(unsigned long width, unsigned long height)
{
	depth_render_target->resize(width, height);
	console_write_line("window resize event %u %u", width, height);
	debug_point;
}

t_callback_handle graphics_render_handle;
void graphics_render()
{
	render_pass->render(swap_chain);
}

t_callback_handle render_pass_render_handle;
void render_pass_render()
{
	application_imgui_context->render();
}

t_callback_handle render_imgui_handle;
void render_imgui()
{
	mandrill_user_interface->render();
}

t_callback_handle graphics_present_handle;
void graphics_present()
{
	swap_chain->present();
}

t_callback_handle swap_chain_resize_finish_handle;
void swap_chain_resize_finish(unsigned long width, unsigned height)
{
	render_pass->resize(width, height);
}

int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	const wchar_t* launch_filepath_command_line_argument = nullptr; // #TODO: implement this with the command line API

	BCS_RESULT rs = BCS_S_OK;
	if (BCS_SUCCEEDED(rs)) rs = register_process_module_by_pointer(wWinMain);
	if (BCS_SUCCEEDED(rs)) rs = init_console();
	if (BCS_SUCCEEDED(rs)) rs = init_command_line(lpCmdLine);
	if (BCS_SUCCEEDED(rs)) rs = window_create(window_title, "mandrill", ULONG_MAX, ULONG_MAX, application_window);
	if (BCS_SUCCEEDED(rs)) rs = graphics_create(_graphics_architecture_d3d12, true, application_graphics);
	if (BCS_SUCCEEDED(rs)) rs = graphics_imgui_context_create(application_window, application_graphics, application_imgui_context);

	rs = graphics_depth_stencil_render_target_create(
		application_graphics,
		application_window->width,
		application_window->height,
		_graphics_data_format_depth_float32,
		0.0f,
		0,
		depth_render_target);
	ASSERT(BCS_SUCCEEDED(rs));

	rs = graphics_swap_chain_create(application_graphics, application_window, swap_chain_frames, swap_chain);
	ASSERT(BCS_SUCCEEDED(rs));

	float4 clear_color = { 0.16f, 0.10f, 0.16f, 1.0f };
	for (unsigned long swap_chain_index = 0; swap_chain_index < swap_chain_frames; swap_chain_index++)
	{
		rs = graphics_swapchain_color_render_target_create(
			application_graphics,
			swap_chain,
			swap_chain_index,
			clear_color,
			swap_chain_render_targets[swap_chain_index]);
		ASSERT(BCS_SUCCEEDED(rs));
	}

	rs = graphics_render_pass_create(
		application_graphics,
		swap_chain_render_targets,
		&depth_render_target,
		swap_chain_frames,
		1,
		1,
		swap_chain_frames,
		render_pass);
	ASSERT(BCS_SUCCEEDED(rs));

	rs = application_window->on_size_changed.add_callback(window_resize, window_resize_handle);
	ASSERT(BCS_SUCCEEDED(rs));
	rs = application_graphics->present_callback.add_callback(graphics_present, graphics_present_handle);
	ASSERT(BCS_SUCCEEDED(rs));
	rs = application_graphics->render_callback.add_callback(graphics_render, graphics_render_handle);
	ASSERT(BCS_SUCCEEDED(rs));
	rs = render_pass->render_callback.add_callback(render_pass_render, render_pass_render_handle);
	ASSERT(BCS_SUCCEEDED(rs));
	rs = application_imgui_context->render_callback.add_callback(render_imgui, render_imgui_handle);
	ASSERT(BCS_SUCCEEDED(rs));
	rs = swap_chain->on_resize_finish.add_callback(swap_chain_resize_finish, swap_chain_resize_finish_handle);
	ASSERT(BCS_SUCCEEDED(rs));

	

	mandrill_user_interface = new c_mandrill_user_interface(*application_window, false, launch_filepath_command_line_argument);

	if (BCS_SUCCEEDED(rs))
	{
		while (application_window->update())
		{
			application_graphics->render_frame();

			Sleep(1);
		}
	}

	rs = application_window->on_size_changed.remove_callback(window_resize_handle);
	ASSERT(BCS_SUCCEEDED(rs));
	rs = application_graphics->present_callback.remove_callback(graphics_present_handle);
	ASSERT(BCS_SUCCEEDED(rs));
	rs = application_graphics->render_callback.remove_callback(graphics_render_handle);
	ASSERT(BCS_SUCCEEDED(rs));
	rs = render_pass->render_callback.remove_callback(render_pass_render_handle);
	ASSERT(BCS_SUCCEEDED(rs));
	rs = application_imgui_context->render_callback.remove_callback(render_imgui_handle);
	ASSERT(BCS_SUCCEEDED(rs));

	rs = graphics_imgui_context_destroy(application_imgui_context);
	rs = graphics_destroy(application_graphics);
	rs = window_destroy(application_window);
	rs = deinit_command_line();
	rs = deinit_console();
	return rs;
}
