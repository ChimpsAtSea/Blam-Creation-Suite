#include "haloshared-private-pch.h"

// Custom Stuff
bool useCustomGameEngineHostCallback = false;
bool useCustomGameWindow = false;
GameEngineHostCallback gameEngineHostCallback;
GameEngineHostCallback_vftbl gameEngineHostCallbackVftbl;
GameEvents gameEvents;
GameEvents_vftbl gameEventsVftbl;

e_peer_property last_game_load_status;
std::string last_game_load_status_str;
const char* halo_reach_path = "";
CurrentState g_CurrentGameState = CurrentState::eInactive;
bool g_gameManuallyKilled = false;
bool isHooked = false;
WORD g_frameLimit = 60;

// Halo Reach Variables

HaloReachReference<GameEngineHostCallback*, 0x1810EC5C0> g_gameEngineHostCallback;
HaloReachReference<LONG, 0x18102F2A4> g_render_thread_mode;
HaloReachReference<DWORD, 0x1810EC584> dword_1810EC584;
HaloReachReference<BYTE, 0x18342E55D> byte_18342E55D;
HaloReachReference<BYTE, 0x183984DE4> byte_183984DE4;
HaloReachReference<DWORD, 0x1810524AC> dword_1810524AC;
HaloReachReference<s_player_profile[4], 0x183D43560> g_player_profiles;
HaloReachReference<s_game_options, 0x183B0FB70> g_game_options;
HaloReachReference<wchar_t[4][32], 0x183DE6FB0> g_player_names;
HaloReachReference<HWND, 0x1810EC5E0> g_hwnd;
HaloReachReference<char, 0x180DC64A8> level_name_to_patch;

// Halo Reach Functions

typedef __int64 (*wait_for_render_thread_func)();
typedef __int64(__fastcall* physical_memory_stage_push_func)(int a1);
wait_for_render_thread_func wait_for_render_thread = nullptr;
physical_memory_stage_push_func physical_memory_stage_push = nullptr;

static FunctionHook<HaloGameID::HaloReach, 0x1806C2890, HWND()> create_window = []()
{
	char* pBaseAddress = (char*)GetHaloExecutable(HaloGameID::HaloReach);
	GameEngineHostCallback*& pGameEngineHostCallback = *reinterpret_cast<GameEngineHostCallback * *>(pBaseAddress + (0x1810EC5C0 - 0x180000000));
	HWND& g_windowHWND = *reinterpret_cast<HWND*>(pBaseAddress + (0x1810EC5D8 - 0x180000000));

	auto before = pGameEngineHostCallback;
	pGameEngineHostCallback = nullptr;

	printf("Calling create_window\n");
	HWND hwnd = create_window();

	pGameEngineHostCallback = before;

	ShowWindow(hwnd, SW_SHOW);
	return hwnd;
};

FunctionHook<HaloGameID::HaloReach, 0x180012B60, __int64 __fastcall (__int64 a1, __int64 a2)> main_game_launch_sequence1 = [](__int64 a1, __int64 a2)
{
	auto result = GameEngineHostCallback_Bypass([a1, a2]() {
		return main_game_launch_sequence1(a1, a2);
		});

	return result;
};

FunctionHook<HaloGameID::HaloReach, 0x18004AFC0, char* (char* dst, char* format, ...)> s_static_string_256_print = [](char* dst, char* format, ...)
{
	va_list args;
	va_start(args, format);

	//vprintf(format, args); printf("\n");
	vsnprintf(dst, 256i64, format, args);

	va_end(args);

	return dst;
};

FunctionHook<HaloGameID::HaloReach, 0x180012730, const char* ()> game_get_haloreach_path = []()
{
	return halo_reach_path;
};

FunctionHook<HaloGameID::HaloReach, 0x18034A630, __int64 __fastcall (s_game_options* game_options)> game_options_new = [](s_game_options* game_options)
{
	auto result = game_options_new(game_options);

	game_options->frame_limit = g_frameLimit;

	return result;
};

FunctionHook<HaloGameID::HaloReach, 0x1803C9220, __int64 __fastcall (s_game_options* a1)> load_scenario_into_game_options = [](s_game_options* a1)
{
	auto result = load_scenario_into_game_options(a1);

	// TODO

	return result;
};

FunctionHook<HaloGameID::HaloReach, 0x18078C550, void(const char* format, ...)> sub_18078C550 = [](const char* format, ...)
{
	va_list args;
	va_start(args, format);

	// #TODO: Assuming this buffer is big enough
	char buffer[8192] = {}; 
	vsnprintf(buffer, 8192, format, args);
	buffer[sizeof(buffer) - 1] = 0;

	va_end(args);

	MessageBox(CustomWindow::GetWindowHandle(), "dirty_disk_error", buffer, MB_ICONERROR);
};

void main_status_hook(__int64 a1, ...)
{
	va_list args;
	va_start(args, a1);

	auto count1 = va_arg(args, __int64);
	assert(count1 == 0);

	const char* str0 = va_arg(args, const char*);

	auto count2 = va_arg(args, __int64);

	printf("status[%lli]: %s", count1, str0);

	for (int i = 0; i < count2; i++)
	{
		const char* str1 = va_arg(args, const char*);
		printf(" %s", str1);
	}
	printf("\n");

	va_end(args);
}

FunctionHook<HaloGameID::HaloReach, 0x180013EA0, char __fastcall (__int64 a1, __int64 a2)> main_game_launch = [](__int64 a1, __int64 a2)
{
	char* const pBaseAddress = reinterpret_cast<char*>(GetHaloExecutable(HaloGameID::HaloReach));
	const DWORD& dword_1810EC5A4 = *reinterpret_cast<DWORD*>(pBaseAddress + (0x1810EC5A4 - 0x180000000));

	auto result = GameEngineHostCallback_Bypass([a1, a2, &dword_1810EC5A4]() {

		static DWORD previous_dword_1810EC5A4 = -1;

		if (dword_1810EC5A4 != previous_dword_1810EC5A4)
		{
			previous_dword_1810EC5A4 = dword_1810EC5A4;
			printf("dword_1810EC5A4 changed to: %d\n", dword_1810EC5A4);
		}

		auto result = main_game_launch(a1, a2);

		if (dword_1810EC5A4 != previous_dword_1810EC5A4)
		{
			previous_dword_1810EC5A4 = dword_1810EC5A4;
			printf("dword_1810EC5A4 changed to: %d\n", dword_1810EC5A4);
		}

		return result;
		});
	return result;
};

FunctionHook<HaloGameID::HaloReach, 0x180108FB0, char* __fastcall (uint8_t* pSimulationWatcher, char* dst)> simulation_watcher_get_status = [](uint8_t* pSimulationWatcher, char* dst)
{
	auto result = simulation_watcher_get_status(pSimulationWatcher, dst);
	printf("%s\n%s\n", dst, result);
	return result;
};

FunctionHook<HaloGameID::HaloReach, 0x1800129B0, void* __stdcall ()> main_thread_routine = []()
{
	WriteLineVerbose("Starting game...");
	g_CurrentGameState = CurrentState::eRunning;
	isHooked = true;
	auto result = main_thread_routine();
	WriteLineVerbose("Game finished...");
	WriteLineVerbose("Last status: [0x%X] %s", last_game_load_status, last_game_load_status_str.c_str());
	g_CurrentGameState = CurrentState::eFinished;
	isHooked = false;
	return result;
};

FunctionHook<HaloGameID::HaloReach, 0x180013EA0, const char* __fastcall (e_peer_property game_load_status)> sub_180071100 = [](e_peer_property game_load_status)
{
	auto pGameLoadStatusStr = sub_180071100(game_load_status);

	// this is to prevent spam
	last_game_load_status = game_load_status;
	bool isSame = last_game_load_status_str == pGameLoadStatusStr;
	last_game_load_status_str = pGameLoadStatusStr;
	bool allowRepeat = false;

	switch (game_load_status)
	{
	case _peer_property_map_load_precaching:
		allowRepeat = false;
		break;
	case _peer_property_none:
	case _peer_property_network_configuration_unavailable:
	case _peer_property_file_manifest_unavailable:
	case _peer_property_banhammer_unavailable:
	case _peer_property_player_stats_unavailable:
	case _peer_property_lsp_stats_unavailable:
	case _peer_property_master_hopper_file_unavailable:
	case _peer_property_hopper_specific_file_unavailable:
	case _peer_property_network_configuration_pending:
	case _peer_property_file_manifest_pending:
	case _peer_property_dlc_map_manifest_pending:
	case _peer_property_dlc_enumeration_pending:
	case _peer_property_banhammer_pending:
	case _peer_property_player_stats_pending:
	case _peer_property_lsp_stats_pending:
	case _peer_property_master_hopper_file_pending:
	case _peer_property_hopper_specific_file_pending:
	case _peer_property_no_map_selected:
	case _peer_property_no_game_selected:
	case _peer_property_map_load_failure:
	case _peer_property_invalid_film_selected:
	case _peer_property_no_film_selected:
	case _peer_property_too_many_teams:
	case _peer_property_all_observers:
	case _peer_property_too_many_for_local_coop:
	case _peer_property_too_many_for_net_coop:
	case _peer_property_incompatible_for_net_coop:
	case _peer_property_account_not_online_enabled:
	case _peer_property_all_profiles_must_by_live_gold:
	case _peer_property_must_be_connect_to_live:
	case _peer_property_must_be_in_a_live_lobby:
	case _peer_property_invalid_hopper:
	case _peer_property_squad_too_large:
	case _peer_property_squad_too_small:
	case _peer_property_too_many_local_players:
	case _peer_property_too_few_local_players:
	case _peer_property_non_local_players_exist:
	case _peer_property_games_played_too_low:
	case _peer_property_games_played_too_high:
	case _peer_property_grade_too_low:
	case _peer_property_grade_too_high:
	case _peer_property_access_bit_not_set:
	case _peer_property_unpaid_in_paid_hopper:
	case _peer_property_paid_in_unpaid_hopper:
	case _peer_property_guest_not_allowed:
	case _peer_property_player_missing_files:
	case _peer_property_player_missing_required_maps:
	case _peer_property_player_banned_from_matchmaking:
	case _peer_property_matchmaking_ban_quitting:
	case _peer_property_not_yet_start_time:
	case _peer_property_end_time_has_passed:
	case _peer_property_arena_hopper_no_longer_available:
	case _peer_property_hd_required_for_playlist:
	case _peer_property_custom_games_are_disabled:
	case _peer_property_multiplayer_split_screen:
	case _peer_property_no_live_in_live_lobby:
	case _peer_property_must_have_live_for_alpha:
	case _peer_property_only_one_player_in_theater_alpha:
	case _peer_property_theater_too_many_players:
	case _peer_property_theater_must_have_hard_drive:
	case _peer_property_theater_leader_must_be_host:
	case _peer_property_theater_all_not_compatible:
	case _peer_property_too_many_players_in_forge:
	case _peer_property_user_content_not_permitted:
	case _peer_property_coop_player_missing_hdd:
	case _peer_property_coop_player_hdd_mismatch:
	case _peer_property_coop_player_language_mismatch:
	case _peer_property_invalid_film_language:
	case _peer_property_controller_not_attached:
	case _peer_property_survival_too_many_players:
	case _peer_property_queued_join_expected:
	case _peer_property_map_and_game_incompatible:
	default:
		allowRepeat = true;
	}

	if (isSame && allowRepeat)
	{
		printf("status [0x%X] %s\n", game_load_status, pGameLoadStatusStr);
	}

	return pGameLoadStatusStr;
};

FunctionHook<HaloGameID::HaloReach, 0x180013090, __int64 __fastcall (__int64 a1)> sub_180013090 = [](__int64 a1)
{
	auto result = sub_180013090(a1);
	auto game_options = (s_game_options*)(a1 + 2280);
	return result;
};

FunctionHook<HaloGameID::HaloReach, 0x18034A7E0, bool __fastcall (s_game_options* a1)> game_options_verify = [](s_game_options* a1)
{
	auto result = game_options_verify(a1);
	WriteLineVerbose("s_game_options::scenario_path: %s", a1->scenario_path);
	return result;
};

FunctionHook<HaloGameID::HaloReach, 0x180012200, __int64(__fastcall)(__int64 a1)> sub_180012200 = [](__int64 a1)
{
	// g_gameEngineHostCallback is normally nulled out by other code.
	// it is perfectly okay to just use a bypass here but I have
	// left it out just in case as it is currently not exploding

	__int64 result; // rax

	result = static_cast<DWORD>(dword_1810EC584);
	if (!dword_1810EC584)
	{
		result = a1;
	}
	dword_1810EC584 = static_cast<DWORD>(result);
	if (g_gameEngineHostCallback)
	{
		WriteLineVerbose("sub_180012200: Aborting!");

		byte_18342E55D = 1;
		__int64 wait_for_render_thread_result = wait_for_render_thread();
		byte_183984DE4 = 1; // this instructs the main_loop to exit
		if (result & 1)
		{
			_InterlockedExchange(dword_1810524AC.ptr(), -1);
			physical_memory_stage_push(6);
			result = physical_memory_stage_push(3);
		}
		if (wait_for_render_thread_result & 2)
		{
			result = _InterlockedCompareExchange(g_render_thread_mode.volatile_ptr(), 1, 0);
		}
	}

	return result;
};

typedef char* (__fastcall levels_try_and_get_scenario_path_func)(int campaign_id, unsigned int map_id, char* scenario_path, int size);
FunctionHook<HaloGameID::HaloReach, 0x1803A6B30, levels_try_and_get_scenario_path_func> levels_try_and_get_scenario_path = [](int campaign_id, unsigned int map_id, char* scenario_path, int size)
{
	map_id = 0x10231971; // force the default map load code path

	auto result = levels_try_and_get_scenario_path(campaign_id, map_id, scenario_path, size);

	if (strlen(scenario_path) == 0)
	{
		WriteLineVerbose("WARNING: The map name is not set!");
		WriteLineVerbose("SELECTED MAP: <none>");
		ThrowDebugger();
	}
	else
	{
		WriteLineVerbose("SELECTED MAP: %s", scenario_path);
	}

	// forceload a different map file
	char customMapName[] = "levels\\solo\\m35\\m35";
	memcpy(scenario_path, customMapName, sizeof(customMapName));

	WriteLineVerbose("MAP OVERRIDE: %s", scenario_path);

	return result;
};

FunctionHook<HaloGameID::HaloReach, 0x1800122F0, int()> sub_1800122F0 = []()
{
	auto result = GameEngineHostCallback_Bypass([]() {

		return sub_1800122F0();

		});
	return result;
};

void memcpy_virtual(
	const void* dst,
	const void* src,
	size_t size
)
{
	if (dst && src && size)
	{
		DWORD oldProtect;
		VirtualProtect(const_cast<void*>(dst), size, PAGE_EXECUTE_READWRITE, &oldProtect);
		memcpy(const_cast<void*>(dst), src, size);
		VirtualProtect(const_cast<void*>(dst), size, oldProtect, &oldProtect);
	}
	else
	{
		WriteLineVerbose("dst must not be null");
		assert(dst);
	}
}

void check_library_can_load(const char* pLibName)
{
	HMODULE hModule = GetModuleHandleA(pLibName);
	if (!hModule)
	{
		hModule = LoadLibraryA(pLibName);
	}
	if (!hModule)
	{
		MessageBox(CustomWindow::GetWindowHandle(), pLibName, "failed to load library", MB_ICONERROR);
	}
	assert(hModule);
}

bool SetPlayerName(int index, const wchar_t name[16])
{
	// #TODO: Lets look into a version of this that doesn't run every frame
	// WriteLineVerbose("Set player[%d].Name: %ls to ", index, name);

	if (wcsncmp(g_player_names[index], name, 16) == 0)
	{
		return false;
	}

	wcsncpy_s(g_player_names[index], 32, name, 16);

	return true;
}

FunctionHook<HaloGameID::HaloReach, 0x180307B10, char(__fastcall)()> input_update = []() {

	CustomWindow::Update();

	//test print on tick update
	//printf("player[%d].Name: %S\n", 0, g_player_profiles[0].Name);
	//printf("g_game_options->frame_limit: %d\n", g_game_options.ptr()->frame_limit);

	SetPlayerName(0, L"Squaresome"); // TODO: get this from a config file

	return input_update();

};

FunctionHook<HaloGameID::HaloReach, 0x1803080A0, char(__fastcall)(KeyCode a1)> sub_1803080A0 = [](KeyCode a1)
{
	auto result = sub_1803080A0(a1);
	return result;
};

void init_haloreach_hooks()
{
	check_library_can_load("bink2w64.dll");

	init_detours();

	create_window.SetIsActive(useCustomGameWindow);

	physical_memory_stage_push = get_function_ptr<HaloGameID::HaloReach, 0x1803FB790, physical_memory_stage_push_func>();
	wait_for_render_thread = get_function_ptr<HaloGameID::HaloReach, 0x18031F6A0, wait_for_render_thread_func>();

	g_frameLimit = 98; // update this here

	CustomWindow::SetupHooks();
	DataReferenceBase::ProcessTree(HaloGameID::HaloReach);
	FunctionHookBase::ProcessTree(HaloGameID::HaloReach);

	end_detours();
}