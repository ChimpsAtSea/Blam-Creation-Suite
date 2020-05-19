#include <Shared\shared-public-pch.h>
#include <TagDefinitions/tagdefinitions-public-pch.h>
#include <MantleLib\mantlelib-public-pch.h>
#include <HaloReachLib\haloreachlib-private-pch.h>
#include <Halo1Lib\halo1lib-private-pch.h>

#define MCCExecutableFileName "MCC-Win64-Shipping_Debug.exe"

const char* c_console::g_console_executable_name = "MCC";

bool s_isHaloReachHooked = false;
bool s_isHalo1Hooked = false;

bool initThreadIsHooked = false;
void nullsub() {}

extern void init_halo_reach(e_engine_type engine_type, e_build build);
extern void deinit_halo_reach(e_engine_type engine_type, e_build build);

void haloreach_dll_loaded_callback()
{
	write_line_verbose("Halo Reach was loaded!");
	{
		e_build build = c_game_runtime::get_library_file_version(MCCExecutableFileName);
		c_halo_reach_game_host::init_runtime_modifications(build);
	}
}

void halo1_dll_loaded_callback()
{
	write_line_verbose("Halo 1 was loaded!");
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
			initThreadIsHooked = false;

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
			initThreadIsHooked = false;

			halo1_dll_loaded_callback();
		}
	}

	return farproc;

}

void init_opus()
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
		c_function_hook_base::init_function_hook_tree(_engine_type_mcc, build);
		c_global_reference::init_global_reference_tree(_engine_type_mcc, build);
	}
	end_detours();
}

void deinit_opus()
{

}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	{
		init_opus();
	}
	break;
	case DLL_PROCESS_DETACH:
	{
		deinit_opus();
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
		GameLauncher::OpusTick();
		c_render::EndFrame();
	};
	void(*DestroyCallback)() = []()
	{
		s_running = false;
	};
	
	Window::Init("Opus", "OpusConsole", "opus");
	c_render::Init(hInstance);
	MantleGUI::Init(true);
	GameLauncher::Init();

	Window::RegisterUpdateCallback(UpdateCallback);
	Window::RegisterDestroyCallback(DestroyCallback);
	//MantleGUI::RegisterOnCloseCallback(DestroyCallback);

	while (s_running) Window::Update();

	Window::UnregisterUpdateCallback(UpdateCallback);
	Window::UnregisterDestroyCallback(DestroyCallback);
	//MantleGUI::UnregisterOnCloseCallback(DestroyCallback);

	GameLauncher::Deinit();
	MantleGUI::Deinit();
	c_render::Deinit();
	Window::Deinit();

	return 0;
}*/
