#include "mcc-private-pch.h"

#define MCCExecutableFileName "MCC-Win64-Shipping_Debug.exe"

const char* c_console::g_console_executable_name = "MCC";

bool s_isHaloReachHooked = false;
bool s_isHalo1Hooked = false;

bool init_thread_is_hooked = false;
void nullsub() {}

extern void init_haloreach(s_engine_platform_build engine_platform_build);
extern void deinit_haloreach(s_engine_platform_build engine_platform_build);

void haloreach_dll_loaded_callback()
{
	c_console::write_line_verbose("Halo Reach was loaded!");
	{
		e_build build = c_game_runtime::get_library_file_version(MCCExecutableFileName);
		c_haloreach_game_host::init_runtime_modifications(build);
	}
}

void halo1_dll_loaded_callback()
{
	c_console::write_line_verbose("Halo 1 was loaded!");
	{
		e_build build = c_game_runtime::get_library_file_version(MCCExecutableFileName);
		c_halo1_game_host::init_runtime_modifications(build);
	}
}

typedef FARPROC(__stdcall GetProcAddressFunc)(HMODULE hModule, LPCSTR lpProcName);
GetProcAddressFunc* GetProcAddressPtr = nullptr;
FARPROC __stdcall GetProcAddressHook(HMODULE hModule, LPCSTR lpProcName)
{
	char pModuleFilename[MAX_PATH] = {};
	GetModuleFileNameA(hModule, pModuleFilename, sizeof(pModuleFilename));

	FARPROC farproc = GetProcAddressPtr(hModule, lpProcName);

	if (!s_isHaloReachHooked)
	{
		bool isHaloReach = strstr(pModuleFilename, "haloreach.dll") != nullptr;
		if (isHaloReach)
		{
			s_isHaloReachHooked = true;

			// reset hook states
			init_thread_is_hooked = false;

			//haloreach_dll_loaded_callback();
		}
	}
	if (!s_isHalo1Hooked)
	{
		bool isHalo1 = strstr(pModuleFilename, "halo1.dll") != nullptr;
		if (isHalo1)
		{
			s_isHalo1Hooked = true;

			// reset hook states
			init_thread_is_hooked = false;

			halo1_dll_loaded_callback();
		}
	}

	return farproc;

}

void init_aotus()
{
	register_platforms();

	SystemPatch::PatchEnumWindows();

	AllocConsole();
	(void)(freopen("CONOUT$", "w", stdout));

	init_detours();
	{
		static void* OutputDebugStringW_Original;
		create_dll_hook("KERNEL32.dll", "OutputDebugStringW", nullsub, OutputDebugStringW_Original);
		static void* OutputDebugStringA_Original;
		create_dll_hook("KERNEL32.dll", "OutputDebugStringA", nullsub, OutputDebugStringA_Original);
		create_dll_hook("KERNEL32.dll", "GetProcAddress", GetProcAddressHook, GetProcAddressPtr);

		e_build build = c_game_runtime::get_library_file_version(MCCExecutableFileName);
		c_function_hook_base::init_function_hook_tree({ _engine_type_mcc, _platform_type_pc_64bit, build });
		c_global_reference::init_global_reference_tree({ _engine_type_mcc, _platform_type_pc_64bit, build });
	}
	end_detours();
}

void deinit_aotus()
{

}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	{
		init_aotus();
	}
	break;
	case DLL_PROCESS_DETACH:
	{
		deinit_aotus();
	}
	break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}

/*int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	Window::SetIcon(LoadIconA(hInstance, ResourcesManager::GetResourceIntResource(ResourceType::Icon)));
	SystemPatch::PatchEnumWindows();

	static bool s_running = true;
	void(*UpdateCallback)() = []()
	{
		c_render::BeginFrame(true, &clearColor.x);
		GameLauncher::AotusTick();
		c_render::EndFrame();
	};
	void(*DestroyCallback)() = []()
	{
		s_running = false;
	};
	
	Window::Init("Aotus", "AotusConsole", "aotus");
	c_render::Init(hInstance);
	MandrillGUI::Init(true);
	GameLauncher::Init();

	Window::RegisterUpdateCallback(UpdateCallback);
	Window::RegisterDestroyCallback(DestroyCallback);
	//MandrillGUI::RegisterOnCloseCallback(DestroyCallback);

	while (s_running) Window::Update();

	Window::UnregisterUpdateCallback(UpdateCallback);
	Window::UnregisterDestroyCallback(DestroyCallback);
	//MandrillGUI::UnregisterOnCloseCallback(DestroyCallback);

	GameLauncher::Deinit();
	MandrillGUI::Deinit();
	c_render::Deinit();
	Window::Deinit();

	return 0;
}*/
