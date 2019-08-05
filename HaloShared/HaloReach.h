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
typedef __int64(__fastcall* main_game_launch_sequence1_Func)(__int64 a1, __int64 a2);
typedef __int64 (*s_static_string_256_print_func)(char* dst, char* format, ...);
typedef char* (*game_get_haloreach_path_func)();


typedef __int64(__fastcall* load_scenario_into_game_options_func)(s_game_options* a1);
typedef void (*sub_18078C550_func)(__int64 a1, ...);
typedef void (*main_status_func)(__int64 a1, ...);
typedef char(__fastcall* main_game_launch_func)(__int64 a1, __int64 a2);
typedef __int64 (*main_game_launch_sequence2_func)();
typedef __int64 (*main_game_launch_sequence3_func)();
typedef __int64 (*main_game_launch_sequence11_func)();
typedef __int64(__fastcall* main_game_launch_sequence9_func)(__int64 a1);
typedef char* (__fastcall* simulation_watcher_get_status_func)(uint8_t* pSimulationWatcher, char* dst);
typedef __int64(__stdcall* shell_dispose_func)();
typedef void* (__stdcall* main_thread_routine_func)();

// Halo Reach Functions
#define preferences_set_bindings_args \
__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8,	\
__int64 a9, __int64 a10, __int64 a11, __int64 a12, __int64 a13, __int64 a14, __int64 a15, __int64 a16,	\
__int64 a17, __int64 a18, __int64 a19, __int64 a20, __int64 a21, __int64 a22, __int64 a23, __int64 a24,	\
__int64 a25, __int64 a26, __int64 a27, __int64 a28, __int64 a29, __int64 a30, __int64 a31, __int64 a32,	\
__int64 a33, __int64 a34, __int64 a35, __int64 a36, __int64 a37, __int64 a38, __int64 a39, __int64 a40,	\
__int64 a41, __int64 a42, __int64 a43, __int64 a44, __int64 a45, __int64 a46, __int64 a47, __int64 a48,	\
__int64 a49, __int64 a50, __int64 a51, __int64 a52, __int64 a53, __int64 a54, __int64 a55, __int64 a56,	\
__int64 a57, __int64 a58, __int64 a59, __int64 a60, __int64 a61, __int64 a62, __int64 a63
#define preferences_set_bindings_vals \
a1,a2,a3,a4,a5,a6,a7,a8, \
a9,a10,a11,a12,a13,a14,a15,a16, \
a17,a18,a19,a20,a21,a22,a23,a24, \
a25,a26,a27,a28,a29,a30,a31,a32, \
a33,a34,a35,a36,a37,a38,a39,a40, \
a41,a42,a43,a44,a45,a46,a47,a48, \
a49,a50,a51,a52,a53,a54,a55,a56, \
a57,a58,a59,a60,a61,a62,a63
typedef char __fastcall preferences_set_bindings_func(preferences_set_bindings_args);
extern FunctionHook<HaloGameID::HaloReach, 0x180780D90, preferences_set_bindings_func> preferences_set_bindings_type;

// Halo Reach Variables


extern HaloReachReference<GameEngineHostCallback*, 0x1810EC5C0> g_gameEngineHostCallback;
extern HaloReachReference<LONG, 0x18102F2A4> g_render_thread_mode;
extern HaloReachReference<DWORD, 0x1810EC584> dword_1810EC584;
extern HaloReachReference<BYTE, 0x18342E55D> byte_18342E55D;
extern HaloReachReference<BYTE, 0x183984DE4> byte_183984DE4;
extern HaloReachReference<DWORD, 0x1810524AC> dword_1810524AC;
extern HaloReachReference<s_player_profile[4], 0x183D43560> g_player_profiles;
extern HaloReachReference<s_game_options, 0x183B0FB70> g_game_options;
extern HaloReachReference<wchar_t[4][32], 0x183DE6FB0> g_player_names;
extern HaloReachReference<HWND, 0x1810EC5E0> g_hwnd;
extern HaloReachReference<char, 0x180DC64A8> level_name_to_patch;






// config flags
extern bool useCustomGameEngineHostCallback;
extern bool useCustomGameWindow;
extern GameEngineHostCallback gameEngineHostCallback;
extern GameEngineHostCallback_vftbl gameEngineHostCallbackVftbl;
extern GameEvents gameEvents;
extern GameEvents_vftbl gameEventsVftbl;
extern void init_haloreach_hooks();
extern rasterizer_initialize_func rasterizer_initialize;
extern create_device_func create_device;
//extern create_window_func create_window;
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



