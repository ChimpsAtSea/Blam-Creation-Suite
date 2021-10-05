#include "mandrillapiprototype-private-pch.h"

bool g_mandrill_running = true;
const char* c_console::g_console_executable_name = "Mandrill API Prorotype";
c_window* window = nullptr;
c_mandrill_user_interface* mandrill_user_interface = nullptr;

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
			console_write_line("failed to load plugin '%S' LoadLibrary failed", filename);
			return true; // continue
		}

		// #TODO: plugin refactor
		//t_create_mandrill_extension* create_mandrill_extension = reinterpret_cast<t_create_mandrill_extension*>(GetProcAddress(extension_module, "create_mandrill_extension"));
		//if (create_mandrill_extension == nullptr)
		//{
		//	console_write_line("failed to load plugin '%S' create_mandrill_extension was not found", filename);
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
		//	console_write_line("failed to load plugin '%S' version missmatch", filename);
		//	if (extension_module)
		//	{
		//		FreeLibrary(extension_module);
		//	}
		//	return true; // continue
		//}

		//const char* extension_name = extension->get_name();
		//console_write_line("successfully loaded plugin '%s'", extension_name);

		//c_mandrill_extension::register_extension(extension);

		return true;
	};
	filesystem_iterate_directory(executable_directory.c_str(), handler);
}

static void init_mandrill(HINSTANCE instance_handle, int show_cmd, const wchar_t* command_line)
{
#ifdef _DEBUG
	const wchar_t* k_window_title = L"Mandrill API Test Debug";
#else
	const wchar_t* k_window_title = L"Mandrill API Test";
#endif

	c_console::init_console();

	load_plugins();

	c_console::show_startup_banner();

}

static void deinit_mandrill()
{
	c_console::deinit_console();
}

#include <discord_rpc.h>

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



	init_mandrill(hInstance, nShowCmd, lpCmdLine);
	//result = run_mandrill_api_test();
	deinit_mandrill();

	return result;
}
