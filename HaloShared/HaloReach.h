#pragma once

enum KeyCode : uint16_t
{
	eKeyCodeEscape,
	eKeyCodeF1,
	eKeyCodeF2,
	eKeyCodeF3,
	eKeyCodeF4,
	eKeyCodeF5,
	eKeyCodeF6,
	eKeyCodeF7,
	eKeyCodeF8,
	eKeyCodeF9,
	eKeyCodeF10,
	eKeyCodeF11,
	eKeyCodeF12,
	eKeyCodePrintScreen,
	eKeyCodeF14,
	eKeyCodeF15,
	eKeyCodeTilde, // VK_OEM_3
	eKeyCode1,
	eKeyCode2,
	eKeyCode3,
	eKeyCode4,
	eKeyCode5,
	eKeyCode6,
	eKeyCode7,
	eKeyCode8,
	eKeyCode9,
	eKeyCode0,
	eKeyCodeMinus,
	eKeyCodePlus,
	eKeyCodeBack,
	eKeyCodeTab,
	eKeyCodeQ,
	eKeyCodeW,
	eKeyCodeE,
	eKeyCodeR,
	eKeyCodeT,
	eKeyCodeY,
	eKeyCodeU,
	eKeyCodeI,
	eKeyCodeO,
	eKeyCodeP,
	eKeyCodeLBracket, // VK_OEM_4
	eKeyCodeRBracket, // VK_OEM_6
	eKeyCodePipe, // VK_OEM_5
	eKeyCodeCapital,
	eKeyCodeA,
	eKeyCodeS,
	eKeyCodeD,
	eKeyCodeF,
	eKeyCodeG,
	eKeyCodeH,
	eKeyCodeJ,
	eKeyCodeK,
	eKeyCodeL,
	eKeyCodeColon, // VK_OEM_1
	eKeyCodeQuote, // VK_OEM_7
	eKeyCodeEnter,
	eKeyCodeLShift,
	eKeyCodeZ,
	eKeyCodeX,
	eKeyCodeC,
	eKeyCodeV,
	eKeyCodeB,
	eKeyCodeN,
	eKeyCodeM,
	eKeyCodeComma,
	eKeyCodePeriod,
	eKeyCodeQuestion, // VK_OEM_2
	eKeyCodeRShift,
	eKeyCodeLControl,
	eKeyCodeUnused46, // Left Windows key, but will always fail
	eKeyCodeLAlt,
	eKeyCodeSpace,
	eKeyCodeRAlt,
	eKeyCodeUnused4A, // Right Windows key, but will always fail
	eKeyCodeApps,
	eKeyCodeRcontrol,
	eKeyCodeUp,
	eKeyCodeDown,
	eKeyCodeLeft,
	eKeyCodeRight,
	eKeyCodeInsert,
	eKeyCodeHome,
	eKeyCodePageUp,
	eKeyCodeDelete,
	eKeyCodeEnd,
	eKeyCodePageDown,
	eKeyCodeNumLock,
	eKeyCodeDivide,
	eKeyCodeMultiply,
	eKeyCodeNumpad0,
	eKeyCodeNumpad1,
	eKeyCodeNumpad2,
	eKeyCodeNumpad3,
	eKeyCodeNumpad4,
	eKeyCodeNumpad5,
	eKeyCodeNumpad6,
	eKeyCodeNumpad7,
	eKeyCodeNumpad8,
	eKeyCodeNumpad9,
	eKeyCodeSubtract,
	eKeyCodeAdd,
	eKeyCodeNumpadEnter,
	eKeyCodeDecimal,
	eKeyCodeUnused68,
	eKeyCodeShift,
	eKeyCodeCtrl,
	eKeyCodeUnused6B, // Windows key, but will always fail
	eKeyCodeAlt,

	eKeyCode_Count,
	eKeyCode_None = 0xFF, // An invalid key code (for use in unset bindings)
};

enum e_peer_property
{
	_peer_property_none,
	_peer_property_network_configuration_unavailable,
	_peer_property_file_manifest_unavailable,
	_peer_property_banhammer_unavailable,
	_peer_property_player_stats_unavailable,
	_peer_property_lsp_stats_unavailable,
	_peer_property_master_hopper_file_unavailable,
	_peer_property_hopper_specific_file_unavailable,
	_peer_property_network_configuration_pending,
	_peer_property_file_manifest_pending,
	_peer_property_dlc_map_manifest_pending,
	_peer_property_dlc_enumeration_pending,
	_peer_property_banhammer_pending,
	_peer_property_player_stats_pending,
	_peer_property_lsp_stats_pending,
	_peer_property_master_hopper_file_pending,
	_peer_property_hopper_specific_file_pending,
	_peer_property_no_map_selected,
	_peer_property_no_game_selected,
	_peer_property_map_load_failure,
	_peer_property_map_load_precaching,
	_peer_property_invalid_film_selected,
	_peer_property_no_film_selected,
	_peer_property_too_many_teams,
	_peer_property_all_observers,
	_peer_property_too_many_for_local_coop,
	_peer_property_too_many_for_net_coop,
	_peer_property_incompatible_for_net_coop,
	_peer_property_account_not_online_enabled,
	_peer_property_all_profiles_must_by_live_gold,
	_peer_property_must_be_connect_to_live,
	_peer_property_must_be_in_a_live_lobby,
	_peer_property_invalid_hopper,
	_peer_property_squad_too_large,
	_peer_property_squad_too_small,
	_peer_property_too_many_local_players,
	_peer_property_too_few_local_players,
	_peer_property_non_local_players_exist,
	_peer_property_games_played_too_low,
	_peer_property_games_played_too_high,
	_peer_property_grade_too_low,
	_peer_property_grade_too_high,
	_peer_property_access_bit_not_set,
	_peer_property_unpaid_in_paid_hopper,
	_peer_property_paid_in_unpaid_hopper,
	_peer_property_guest_not_allowed,
	_peer_property_player_missing_files,
	_peer_property_player_missing_required_maps,
	_peer_property_player_banned_from_matchmaking,
	_peer_property_matchmaking_ban_quitting,
	_peer_property_not_yet_start_time,
	_peer_property_end_time_has_passed,
	_peer_property_arena_hopper_no_longer_available,
	_peer_property_hd_required_for_playlist,
	_peer_property_custom_games_are_disabled,
	_peer_property_multiplayer_split_screen,
	_peer_property_no_live_in_live_lobby,
	_peer_property_must_have_live_for_alpha,
	_peer_property_only_one_player_in_theater_alpha,
	_peer_property_theater_too_many_players,
	_peer_property_theater_must_have_hard_drive,
	_peer_property_theater_leader_must_be_host,
	_peer_property_theater_all_not_compatible,
	_peer_property_too_many_players_in_forge,
	_peer_property_user_content_not_permitted,
	_peer_property_coop_player_missing_hdd,
	_peer_property_coop_player_hdd_mismatch,
	_peer_property_coop_player_language_mismatch,
	_peer_property_invalid_film_language,
	_peer_property_controller_not_attached,
	_peer_property_survival_too_many_players,
	_peer_property_queued_join_expected,
	_peer_property_map_and_game_incompatible,

	k_number_of_peer_properties
};

enum e_scenario_type : int
{
	_scenario_type_none,
	_scenario_type_campaign,
	_scenario_type_multiplayer,
	_scenario_type_mainmenu,
	_scenario_type_shared,
	_scenario_type_shared_campaign,
	_scenario_type_unused5,
	_scenario_type_unused6,

	k_number_of_scenario_types,
};

struct s_game_options
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
	BYTE game_variant[0xFC04];
	DWORD map_id;
	BYTE unknownFC30[4];
	char scenario_path[260];
	BYTE unknownFE94[129];
	BYTE game_is_playtest;
	BYTE unknownFF16[18];
	DWORD campaign_difficulty;
	BYTE unknownFF2C[299];
	BYTE map_variant[0xD9AC];
	BYTE unknown1DA03[4345];
};
static_assert(sizeof(s_game_options) == 0x1E9A0, "");
typedef __int64(__fastcall* game_options_new_func)(s_game_options* game_options);

enum class CurrentState
{
	eInactive,
	eRunning,
	eFinished
};
extern CurrentState g_CurrentGameState;
extern bool g_gameManuallyKilled;
extern bool isHooked;
extern WORD g_frameLimit;
extern HICON g_icon;

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
typedef __int64(__fastcall* main_game_launch_sequence1_Func)(__int64 a1, __int64 a2);
typedef __int64 (*s_static_string_256_print_func)(char* dst, char* format, ...);
typedef char* (*game_get_haloreach_path_func)();


typedef __int64(__fastcall* load_scenario_into_game_options_func)(s_game_options* a1);
typedef void (*sub_18078C550_func)(__int64 a1, ...);
typedef void (*main_status_func)(__int64 a1, ...);
typedef char(__fastcall* main_game_launch_func)(__int64 a1, __int64 a2);
typedef __int64(__fastcall* cache_files_get_file_status_func)(const char* a1);
typedef __int64 (*main_game_launch_sequence2_func)();
typedef __int64 (*main_game_launch_sequence3_func)();
typedef __int64 (*main_game_launch_sequence11_func)();
typedef __int64(__fastcall* main_game_launch_sequence9_func)(__int64 a1);
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
//extern create_window_func create_window;
extern RegisterClassExA_Func RegisterClassExA_Original;
extern main_game_launch_sequence1_Func main_game_launch_sequence1;
extern s_static_string_256_print_func s_static_string_256_print;
extern game_get_haloreach_path_func game_get_haloreach_path;
extern game_options_new_func game_options_new;
extern load_scenario_into_game_options_func load_scenario_into_game_options;
extern sub_18078C550_func sub_18078C550;
extern main_status_func main_status;
extern main_game_launch_func main_game_launch;
extern cache_files_get_file_status_func cache_files_get_file_status;
extern main_game_launch_sequence2_func main_game_launch_sequence2;
extern main_game_launch_sequence3_func main_game_launch_sequence3;
extern main_game_launch_sequence11_func main_game_launch_sequence11;
extern main_game_launch_sequence9_func main_game_launch_sequence9;
extern simulation_watcher_get_status_func simulation_watcher_get_status;
extern shell_dispose_func shell_dispose;
extern main_thread_routine_func main_thread_routine;
extern const char* halo_reach_path;

template<typename T>
decltype(auto) GameEngineHostCallback_Bypass(T functionPtr, bool forceDisable = false)
{
	char* pBaseAddress = reinterpret_cast<char*>(GetHaloExecutable(HaloGameID::HaloReach));
	assert(pBaseAddress);
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



