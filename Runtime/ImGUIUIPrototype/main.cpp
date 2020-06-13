#include <Platform\platform-public-pch.h>
#include <Shared\shared-public-pch.h>

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */

bool g_running = true;
const char* c_console::g_console_executable_name = "ImGUI UI Prototype";

/* ---------- private prototypes */
/* ---------- public code */
/* ---------- private code */

void mandrill_init();
void mandrill_deinit();
void mandrill();

static void application_ui_callback()
{
	mandrill();
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

static void init(const wchar_t* command_line)
{
	//c_console::init_console();
	c_window_win32::init_window(L"ImGUI UI Prototype", L"ImGUI UI Prototype Console", L"imgui-ui-prototype");
	c_render::init_render(NULL, true);

	c_debug_gui::register_callback(_callback_mode_always_run, application_ui_callback);
	c_window_win32::register_window_procedure_callback(c_debug_gui::WndProc);
	c_window_win32::register_update_callback(application_update_callback);
	c_window_win32::register_destroy_callback(application_close_callback);

	c_debug_gui::show_ui();
	//c_console::show_startup_banner();

	mandrill_init();
}

static int run()
{
	while (g_running)
	{
		c_window_win32::update_window();
	}
	return 0;
}

static void deinit()
{
	mandrill_deinit();

	c_window_win32::unregister_destroy_callback(application_close_callback);
	c_window_win32::unregister_update_callback(application_update_callback);
	c_window_win32::unregister_window_procedure_callback(c_debug_gui::WndProc);
	c_debug_gui::unregister_callback(_callback_mode_always_run, application_ui_callback);

	c_render::deinit_render();
	c_window_win32::deinit_window();
	//c_console::deinit_console();
}

int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,				/* [input] handle to current instance */
	_In_opt_ HINSTANCE hPrevInstance,		/* [input] handle to previous instance */
	_In_ LPWSTR lpCmdLine,					/* [input] pointer to command line */
	_In_ int nShowCmd						/* [input] show state of window */
)
{
	int result = 0;
	init(lpCmdLine);
	result = run();
	deinit();
	return result;
}
