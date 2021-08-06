#include "mandrill-private-pch.h"

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
		return argv[0];
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
		blofeld::validate_gen3_definitions();

		return false;
	}

	return true;
}

static void load_plugins()
{

	c_fixed_wide_path executable_directory;
	GetModuleFileNameW(c_runtime_util::get_current_module(), executable_directory.str(), executable_directory.capacity());
	PathRemoveFileSpecW(executable_directory.str());
	executable_directory += L"\\*.mext";

	std::function<bool(const wchar_t* filepath)> handler = [](const wchar_t* filepath)
	{
		const wchar_t* filename = PathFindFileNameW(filepath);
		HMODULE extension_module = LoadLibraryW(filepath);
		if (extension_module == nullptr)
		{
			c_console::write_line_verbose("failed to load plugin '%S' LoadLibrary failed", filename);
			return true; // continue
		}

		// #TODO: plugin refactor
		//t_create_mandrill_extension* create_mandrill_extension = reinterpret_cast<t_create_mandrill_extension*>(GetProcAddress(extension_module, "create_mandrill_extension"));
		//if (create_mandrill_extension == nullptr)
		//{
		//	c_console::write_line_verbose("failed to load plugin '%S' create_mandrill_extension was not found", filename);
		//	if (extension_module)
		//	{
		//		FreeLibrary(extension_module);
		//	}
		//	return true; // continue
		//}

		//c_mandrill_extension* extension = create_mandrill_extension();
		//int version = extension->get_version();
		//if (version != BCS_EXTENSION_VERSION)
		//{
		//	c_console::write_line_verbose("failed to load plugin '%S' version missmatch", filename);
		//	if (extension_module)
		//	{
		//		FreeLibrary(extension_module);
		//	}
		//	return true; // continue
		//}

		//const char* extension_name = extension->get_name();
		//c_console::write_line_verbose("successfully loaded plugin '%s'", extension_name);

		//c_mandrill_extension::register_extension(extension);

		return true;
	};
	filesystem_iterate_directory(executable_directory.c_str(), handler);
}

#include <Platform\platform-public-pch.h>
#include <Versioning\versioning-public-pch.h>
#include <Shared\shared-public-pch.h>
#include <Shared\Blam\blamlib-public-pch.h>
#include <SymbolsLib\symbolslib-public-pch.h>
#include <TagDefinitions\tagdefinitions-public-pch.h>
#include <TagReflection\tagreflection-public-pch.h>
#include <TagValidate\tagvalidate-public-pch.h>

#include <MandrillLib/mandrilllib-public-pch.h>

static int init_mandrill(HINSTANCE instance_handle, int show_cmd, const wchar_t* command_line)
{

	const wchar_t* launch_filepath_command_line_argument = get_launch_filepath_command_line_argument(command_line);
#ifdef _DEBUG
	const wchar_t* k_window_title = L"Mandrill Debug";
#else
	const wchar_t* k_window_title = L"Mandrill";
#endif

	c_console::init_console();

	int keys_result = init_keys();
	if (keys_result) return keys_result;

	window = new c_window(instance_handle, k_window_title, L"mandrill", _window_icon_mandrill, show_cmd);
	c_render::init_render(window, instance_handle, true);

	if(c_command_line::has_command_line_arg("-compilertest"))
	{
		//compilertest(0); // 20_sword_slayer.map
		//compilertest(1); // m70_a.map
		//compilertest(2); // m60.map
	}

	load_plugins();
	mandrill_user_interface = new c_mandrill_user_interface(*window, false, launch_filepath_command_line_argument);

	c_debug_gui::register_callback(_callback_mode_always_run, application_ui_callback);
	window->on_window_procedure.register_callback(c_debug_gui::window_procedure);
	window->on_update.register_callback(application_update_callback);
	window->on_destroy.register_callback(application_close_callback);
	mandrill_user_interface->on_close.register_callback(application_close_callback);

	c_debug_gui::show_ui();
	c_console::show_startup_banner();

	return 0;
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
	if (mandrill_user_interface)
	{
		mandrill_user_interface->on_close.unregister_callback(application_close_callback);
	}
	if (window)
	{
		window->on_destroy.unregister_callback(application_close_callback);
		window->on_update.unregister_callback(application_update_callback);
		window->on_window_procedure.unregister_callback(c_debug_gui::window_procedure);
	}
	c_debug_gui::unregister_callback(_callback_mode_always_run, application_ui_callback);

	deinit_keys();

	if (mandrill_user_interface) delete mandrill_user_interface;
	if (window)
	{
		c_render::deinit_render();
		delete window;
	}
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
	//if (rhesus_crash_reporter(result))
	//{
	//	return result;
	//}

	if (run_tests(lpCmdLine)) // allow program to exit without running
	{
		if (!(result = init_mandrill(hInstance, nShowCmd, lpCmdLine)))
		{
			result = run_mandrill();
		}
		deinit_mandrill();
	}
	return result;
}
