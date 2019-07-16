#pragma once

#define HaloReachDLL "HaloReach.dll"
#define HaloReachBase 0x180000000
#define HaloReachModule GetModuleHandleA(HaloReachDLL)
#define HaloReachBaseAddressPtr reinterpret_cast<char*>(HaloReachModule)

enum e_peer_property // this name is not confirmed
{
	_none,
	_network_configuration_unavailable,
	_file_manifest_unavailable,
	_banhammer_unavailable,
	_player_stats_unavailable,
	_lsp_stats_unavailable,
	_master_hopper_file_unavailable,
	_hopper_specific_file_unavailable,
	_network_configuration_pending,
	_file_manifest_pending,
	_dlc_map_manifest_pending,
	_dlc_enumeration_pending,
	_banhammer_pending,
	_player_stats_pending,
	_lsp_stats_pending,
	_master_hopper_file_pending,
	_hopper_specific_file_pending,
	_no_map_selected,
	_no_game_selected,
	_map_load_failure,
	_map_load_precaching,
	_invalid_film_selected,
	_no_film_selected,
	_too_many_teams,
	_all_observers,
	_too_many_for_local_coop,
	_too_many_for_net_coop,
	_incompatible_for_net_coop,
	_account_not_online_enabled,
	_all_profiles_must_by_live_gold,
	_must_be_connect_to_live,
	_must_be_in_a_live_lobby,
	_invalid_hopper,
	_squad_too_large,
	_squad_too_small,
	_too_many_local_players,
	_too_few_local_players,
	_non_local_players_exist,
	_games_played_too_low,
	_games_played_too_high,
	_grade_too_low,
	_grade_too_high,
	_access_bit_not_set,
	_unpaid_in_paid_hopper,
	_paid_in_unpaid_hopper,
	_guest_not_allowed,
	_player_missing_files,
	_player_missing_required_maps,
	_player_banned_from_matchmaking,
	_matchmaking_ban_quitting,
	_not_yet_start_time,
	_end_time_has_passed,
	_arena_hopper_no_longer_available,
	_hd_required_for_playlist,
	_custom_games_are_disabled,
	_multiplayer_split_screen,
	_no_live_in_live_lobby,
	_must_have_live_for_alpha,
	_only_one_player_in_theater_alpha,
	_theater_too_many_players,
	_theater_must_have_hard_drive,
	_theater_leader_must_be_host,
	_theater_all_not_compatible,
	_too_many_players_in_forge,
	_user_content_not_permitted,
	_coop_player_missing_hdd,
	_coop_player_hdd_mismatch,
	_coop_player_language_mismatch,
	_invalid_film_language,
	_controller_not_attached,
	_survival_too_many_players,
	_queued_join_expected,
	_mapand_game_incompatible,
	k_number_of_peer_properties
};

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
typedef __int64(__fastcall* game_launch_mode_1_Func)(__int64 a1, __int64 a2);
typedef __int64 (*s_static_string_256_print_func)(char* dst, char* format, ...);
typedef char* (*game_get_haloreach_path_func)();


typedef __int64(__fastcall* load_scenario_into_game_options_func)(s_game_options* a1);
typedef void (*sub_18078C550_func)(__int64 a1, ...);
typedef void (*main_status_func)(__int64 a1, ...);
typedef char(__fastcall* main_game_launch_func)(__int64 a1, __int64 a2);
typedef __int64(__fastcall* cache_files_get_file_status_func)(const char* a1);
typedef __int64 (*game_launch_mode_2_func)();
typedef __int64 (*game_launch_mode_3_func)();
typedef __int64 (*game_launch_mode_11_func)();
typedef __int64(__fastcall* game_launch_mode_9_func)(__int64 a1);
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
extern game_launch_mode_1_Func game_launch_mode_1;
extern s_static_string_256_print_func s_static_string_256_print;
extern game_get_haloreach_path_func game_get_haloreach_path;
extern game_options_new_func game_options_new;
extern load_scenario_into_game_options_func load_scenario_into_game_options;
extern sub_18078C550_func sub_18078C550;
extern main_status_func main_status;
extern main_game_launch_func main_game_launch;
extern cache_files_get_file_status_func cache_files_get_file_status;
extern game_launch_mode_2_func game_launch_mode_2;
extern game_launch_mode_3_func game_launch_mode_3;
extern game_launch_mode_11_func game_launch_mode_11;
extern game_launch_mode_9_func game_launch_mode_9;
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



