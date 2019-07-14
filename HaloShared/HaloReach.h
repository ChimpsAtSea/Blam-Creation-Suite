#pragma once

#define HaloReachDLL "HaloReach.dll"
#define HaloReachBase 0x180000000
#define HaloReachModule GetModuleHandleA(HaloReachDLL)
#define HaloReachBaseAddressPtr reinterpret_cast<char*>(HaloReachModule)

enum e_scenario_type : __int32
{
	_scenario_type_none = 0x0,
	_scenario_type_campaign = 0x1,
	_scenario_type_multiplayer = 0x2,
	_scenario_type_mainmenu = 0x3,
	_scenario_type_shared = 0x4,
	_scenario_type_shared_campaign = 0x5,
	_scenario_type_unused5 = 0x6,
	_scenario_type_unused6 = 0x7,
	k_number_of_scenario_types = 0x8,
};

struct __declspec(align(4)) s_game_options
{
	e_scenario_type scenario_type;
	BYTE game_simulation[8];
	WORD frame_limit;
	WORD unknownE;
	BYTE game_instance[8];
	DWORD random_seed;
	DWORD language;
	BYTE campaign_id;
	DWORD determinism_version;
	BYTE game_variant[64516];
	DWORD map_id;
	BYTE unknownFC30[4];
	char scenario_path[260];
	BYTE unknownFE94[129];
	BYTE game_is_playtest;
	BYTE unknownFF16[18];
	DWORD campaign_difficulty;
	BYTE unknownFF2C[60368];
};
typedef __int64(__fastcall* game_options_new_func)(s_game_options* a1);

enum class CurrentState
{
	eInactive,
	eRunning,
	eFinished
};
extern CurrentState g_CurrentGameState;
extern bool isHooked;

typedef void(*rasterizer_initialize_func)();
typedef char(*create_device_func)();
typedef HWND(*create_window_func)();
typedef ATOM(WINAPI* RegisterClassExA_Func)(_In_ CONST WNDCLASSEXA*);
typedef HWND(WINAPI* CreateWindowExA_Func)(
	_In_ DWORD dwExStyle,
	_In_opt_ LPCSTR lpClassName,
	_In_opt_ LPCSTR lpWindowName,
	_In_ DWORD dwStyle,
	_In_ int X,
	_In_ int Y,
	_In_ int nWidth,
	_In_ int nHeight,
	_In_opt_ HWND hWndParent,
	_In_opt_ HMENU hMenu,
	_In_opt_ HINSTANCE hInstance,
	_In_opt_ LPVOID lpParam);
typedef __int64(__fastcall* sub_180012B60_Func)(__int64 a1, __int64 a2);
typedef __int64 (*s_static_string_256_print_func)(char* dst, char* format, ...);
typedef char* (*game_get_haloreach_path_func)();


typedef __int64(__fastcall* load_scenario_into_game_options_func)(s_game_options* a1);
typedef void (*sub_18078C550_func)(__int64 a1, ...);
typedef void (*main_status_func)(__int64 a1, ...);
typedef char(__fastcall* sub_180013EA0_func)(__int64 a1, __int64 a2);
typedef __int64(__fastcall* cache_files_get_file_status_func)(const char* a1);
typedef __int64 (*sub_180012C30_func)();
typedef __int64 (*sub_180012D60_func)();
typedef __int64 (*sub_180013CD0_func)();
typedef __int64(__fastcall* sub_180013BF0_func)(__int64 a1);
typedef char* (__fastcall* simulation_watcher_get_status_func)(uint8_t* pSimulationWatcher, char* dst);
typedef __int64(__stdcall* shell_dispose_func)();
typedef void* (__stdcall* main_thread_routine_func)();


// config flags
extern bool useCustomGameEngineHostCallback;
extern bool useCustomGameWindow;
extern GameEngineHostCallback gameEngineHostCallback;
extern GameEngineHostCallback_vftbl gameEngineHostCallbackVftbl;
extern GameEvents gameEvents;
extern GameEvents_vftbl gameEventsVftbl;
extern void init_haloreach_hooks();
extern std::thread windowThread;
extern HWND hWnd;
extern CreateWindowExA_Func CreateWindowExA_Original;
extern rasterizer_initialize_func rasterizer_initialize;
extern create_device_func create_device;
extern create_window_func create_window;
extern RegisterClassExA_Func RegisterClassExA_Original;
extern sub_180012B60_Func sub_180012B60;
extern s_static_string_256_print_func s_static_string_256_print;
extern game_get_haloreach_path_func game_get_haloreach_path;
extern game_options_new_func game_options_new;
extern load_scenario_into_game_options_func load_scenario_into_game_options;
extern sub_18078C550_func sub_18078C550;
extern main_status_func main_status;
extern sub_180013EA0_func sub_180013EA0;
extern cache_files_get_file_status_func cache_files_get_file_status;
extern sub_180012C30_func sub_180012C30;
extern sub_180012D60_func sub_180012D60;
extern sub_180013CD0_func sub_180013CD0;
extern sub_180013BF0_func sub_180013BF0;
extern simulation_watcher_get_status_func simulation_watcher_get_status;
extern shell_dispose_func shell_dispose;
extern main_thread_routine_func main_thread_routine;
extern const char* halo_reach_path;

template<typename T>
decltype(auto) GameEngineHostCallbackNullsubBypass(T functionPtr, bool forceDisable = false)
{
	char* const pBaseAddress = HaloReachBaseAddressPtr;
	GameEngineHostCallback*& pGameEngineHostCallback = *reinterpret_cast<GameEngineHostCallback * *>(pBaseAddress + (0x1810EC5C0 - 0x180000000));

	auto pGameEngineHostCallbackBefore = pGameEngineHostCallback;
	if (useCustomGameEngineHostCallback && !forceDisable)
	{
		pGameEngineHostCallback = &gameEngineHostCallback;
	}

	decltype(functionPtr()) result = functionPtr();

	if (useCustomGameEngineHostCallback && !forceDisable)
	{
		pGameEngineHostCallback = pGameEngineHostCallbackBefore;
	}

	return result;
}



