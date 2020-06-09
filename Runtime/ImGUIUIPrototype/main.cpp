#include <Platform\platform-public-pch.h>
#include <Versioning\versioning-public-pch.h>
#include <Shared\shared-public-pch.h>
#include <TagDefinitions\tagdefinitions-public-pch.h>
#include <MantleLib\mantlelib-public-pch.h>

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

static void application_ui_callback()
{
	ImGui::Text("hello world");
}

static void application_update_callback()
{
	static float clearColor[] = { 0.25f, 0.25f, 0.25f, 1.0f };
	c_render::begin_frame(true, clearColor);
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
