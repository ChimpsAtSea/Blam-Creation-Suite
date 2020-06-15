#include <Platform\platform-public-pch.h>
#include <Versioning\versioning-public-pch.h>
#include <Shared\shared-public-pch.h>
#include <TagDefinitions\tagdefinitions-public-pch.h>
#include <MandrillLib\mandrilllib-public-pch.h>
#include <Rhesus\rhesus-public-pch.h>

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */

bool g_mandrill_running = true;
const char* c_console::g_console_executable_name = "Mandrill";
c_window* window = nullptr;
c_mandrill_user_interface* mandrill_user_interface = nullptr;

/* ---------- private prototypes */
/* ---------- public code */
/* ---------- private code */

static const wchar_t* get_launch_filepath_command_line_argument(const wchar_t* command_line)
{
	int argc = 0;
	wchar_t** argv = CommandLineToArgvW(command_line, &argc);

	if (argc > 0)
	{
		const wchar_t* launch_argument_extension = PathFindExtensionW(argv[0]);
		// #TODO: Add support for c_mandrill::is_supported_file_extension();
		if (wcscmp_ic(launch_argument_extension, L".map") == 0)
		{
			return argv[0];
		}
	}

	return nullptr;
}

static void application_ui_callback()
{
	mandrill_user_interface->render();
}

static void application_update_callback()
{
	static float clearColor[] = { 0.25f, 0.25f, 0.25f, 1.0f };
	c_render::begin_frame(true, clearColor);
	c_render::end_frame();
}

static void application_close_callback()
{
	g_mandrill_running = false;
}

static bool run_tests(const wchar_t* command_line)
{
	const wchar_t* launch_filepath_command_line_argument = get_launch_filepath_command_line_argument(command_line);

	if (c_command_line::has_command_line_arg("-generatecachefilememorydebug"))
	{
		//c_cache_file cache_file = c_cache_file(launch_filepath_command_line_argument);
		//cache_file.generate_cache_file_data_access_data();

		return false;
	}

	if (c_command_line::has_command_line_arg("-validatehalo4"))
	{
		blofeld::validate_halo4();

		return false;
	}

	return true;
}

static void init_mandrill(HINSTANCE instance_handle, int show_cmd, const wchar_t* command_line)
{
	const wchar_t* launch_filepath_command_line_argument = get_launch_filepath_command_line_argument(command_line);
#ifdef _DEBUG
	const wchar_t* k_window_title = L"Mandrill Debug";
#else
	const wchar_t* k_window_title = L"Mandrill";
#endif

	c_console::init_console();

	window = new c_window(instance_handle, k_window_title, L"mandrill", _window_icon_mandrill, show_cmd);
	c_render::init_render(window, instance_handle, true);
	mandrill_user_interface = new c_mandrill_user_interface(*window, false, launch_filepath_command_line_argument);

	c_debug_gui::register_callback(_callback_mode_always_run, application_ui_callback);
	window->on_window_procedure.register_callback(c_debug_gui::window_procedure);
	window->on_update.register_callback(application_update_callback);
	window->on_destroy.register_callback(application_close_callback);
	mandrill_user_interface->on_close.register_callback(application_close_callback);

	c_debug_gui::show_ui();
	c_console::show_startup_banner();
}

static int run_mandrill()
{
	while (g_mandrill_running)
	{
		window->update();
	}
	return 0;
}

static void deinit_mandrill()
{
	mandrill_user_interface->on_close.unregister_callback(application_close_callback);
	window->on_destroy.unregister_callback(application_close_callback);
	window->on_update.unregister_callback(application_update_callback);
	window->on_window_procedure.unregister_callback(c_debug_gui::window_procedure);
	c_debug_gui::unregister_callback(_callback_mode_always_run, application_ui_callback);

	delete mandrill_user_interface;
	c_render::deinit_render();
	delete window;
	c_console::deinit_console();
}

int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,				/* [input] handle to current instance */
	_In_opt_ HINSTANCE hPrevInstance,		/* [input] handle to previous instance */
	_In_ LPWSTR lpCmdLine,					/* [input] pointer to command line */
	_In_ int nShowCmd						/* [input] show state of window */
)
{
	int result = 0;
	if (rhesus_crash_reporter(result))
	{
		return result;
	}

	if (run_tests(lpCmdLine)) // allow program to exit without running
	{
		init_mandrill(hInstance, nShowCmd, lpCmdLine);
		result = run_mandrill();
		deinit_mandrill();
	}
	return result;
}
