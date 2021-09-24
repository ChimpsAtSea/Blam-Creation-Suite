#include <Platform\platform-public-pch.h>
#include <Shared\shared-public-pch.h>

bool g_running = true;
const char* c_console::g_console_executable_name = "ImGUI UI Prototype";
c_window* window = nullptr;

void mandrill_init();
void mandrill_deinit();
void mandrill(c_window& window);

static void application_ui_callback()
{
	mandrill(*window);
}

static void application_update_callback()
{
	constexpr float clear_shade = 33.0f / 255.0f;
	static float clear_color[] = { clear_shade, clear_shade, clear_shade, 1.0f };
	c_render::begin_frame(true, clear_color);
	c_render::end_frame();
}

static void application_close_callback()
{
	g_running = false;
}

static void init(HINSTANCE instance_handle, int show_cmd, const wchar_t* command_line)
{
#ifdef _DEBUG
	const wchar_t* k_window_title = L"ImGUI UI Prototype Debug";
#else
	const wchar_t* k_window_title = L"ImGUI UI Prototype";
#endif

	window = new c_window(instance_handle, k_window_title, L"imgui-ui-prototype", _window_icon_default, show_cmd);
	c_render::init_render(window, c_runtime_util::get_current_module(), true);

	c_debug_gui::register_callback(_callback_mode_always_run, application_ui_callback);
	window->on_window_procedure.register_callback(c_debug_gui::window_procedure);
	window->on_update.register_callback(application_update_callback);
	window->on_destroy.register_callback(application_close_callback);

	c_debug_gui::show_ui();

	mandrill_init();
}

static int run()
{
	while (g_running)
	{
		window->update();
	}
	return 0;
}

static void deinit()
{
	mandrill_deinit();

	window->on_destroy.unregister_callback(application_close_callback);
	window->on_update.unregister_callback(application_update_callback);
	window->on_window_procedure.unregister_callback(c_debug_gui::window_procedure);
	c_debug_gui::unregister_callback(_callback_mode_always_run, application_ui_callback);

	c_render::deinit_render();
	delete window;
}

int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,				/* [input] handle to current instance */
	_In_opt_ HINSTANCE hPrevInstance,		/* [input] handle to previous instance */
	_In_ LPWSTR lpCmdLine,					/* [input] pointer to command line */
	_In_ int nShowCmd						/* [input] show state of window */
)
{
	int result = 0;
	init(hInstance, nShowCmd, lpCmdLine);
	result = run();
	deinit();
	return result;
}
