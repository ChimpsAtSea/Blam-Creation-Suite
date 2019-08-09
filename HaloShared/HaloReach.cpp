#include "haloshared-private-pch.h"

// Custom Stuff

bool useCustomGameEngineHostCallback = false;
bool useCustomGameWindow = false;
GameEngineHostCallback gameEngineHostCallback;
GameEngineHostCallback_vftbl gameEngineHostCallbackVftbl;
GameEvents gameEvents;
GameEvents_vftbl gameEventsVftbl;
s_thread_local_storage ThreadLocalStorage;

e_peer_property last_game_load_status;
std::string last_game_load_status_str;
const char* halo_reach_path = "";
CurrentState g_CurrentGameState = CurrentState::eInactive;
bool g_gameManuallyKilled = false;
bool isHooked = false;
WORD g_frameLimit = 60;
int g_fieldOfView = 78;
int g_controlsLayout = 0;
bool g_pancamEnabled = false;

// Halo Reach Variables

HaloReachReference<GameEngineHostCallback*, 0x1810EC5C0> g_gameEngineHostCallback;
HaloReachReference<LONG, 0x18102F2A4> g_render_thread_mode;
HaloReachReference<DWORD, 0x1810EC584> dword_1810EC584;
HaloReachReference<BYTE, 0x18342E55D> byte_18342E55D;
HaloReachReference<BYTE, 0x183984DE4> byte_183984DE4;
HaloReachReference<DWORD, 0x1810524AC> dword_1810524AC;
HaloReachReference<c_controller_interface[4], 0x183D43560> g_controller_interfaces;
HaloReachReference<s_game_options, 0x183B0FB70> g_game_options;
HaloReachReference<wchar_t[4][32], 0x183DE6FB0> g_player_names;
HaloReachReference<HWND, 0x1810EC5E0> g_hwnd;
HaloReachReference<char, 0x180DC64A8> level_name_to_patch;
HaloReachReference<uint32_t, 0x1810A3098> TlsIndex;

// Halo Reach Functions

typedef __int64 (*wait_for_render_thread_func)();
typedef __int64(__fastcall* physical_memory_stage_push_func)(int a1);
wait_for_render_thread_func wait_for_render_thread = nullptr;
physical_memory_stage_push_func physical_memory_stage_push = nullptr;

static HaloReachHook<0x1806C2890, HWND()> create_window = []()
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

HaloReachHook<0x180012B60, __int64 __fastcall (__int64 a1, __int64 a2)> main_game_launch_create_local_squad = [](__int64 a1, __int64 a2)
{
	auto result = GameEngineHostCallback_Bypass([a1, a2]() {
		return main_game_launch_create_local_squad(a1, a2);
		});

	return result;
};

HaloReachHook<0x18004AFC0, char* (char* dst, char* format, ...)> sprintf_256 = [](char* dst, char* format, ...)
{
	va_list args;
	va_start(args, format);

	//vprintf(format, args); printf("\n");
	vsnprintf(dst, 256, format, args);

	va_end(args);

	return dst;
};

HaloReachHook<0x180012730, const char* ()> game_get_haloreach_path = []()
{
	return halo_reach_path;
};

HaloReachHook<0x18034A630, __int64 __fastcall (s_game_options* game_options)> game_options_new = [](s_game_options* game_options)
{
	auto result = game_options_new(game_options);

	game_options->frame_limit = g_frameLimit;

	return result;
};

HaloReachHook<0x1803C9220, __int64 __fastcall (s_game_options* a1)> load_scenario_into_game_options = [](s_game_options* a1)
{
	auto result = load_scenario_into_game_options(a1);

	// TODO

	return result;
};

HaloReachHook<0x18078C550, void(const char* format, ...)> DamagedMediaHaltAndDisplayError = [](const char* format, ...)
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

HaloReachHook<0x180013EA0, char __fastcall (__int64 a1, __int64 a2)> main_game_launch = [](__int64 a1, __int64 a2)
{
	char* const pBaseAddress = reinterpret_cast<char*>(GetHaloExecutable(HaloGameID::HaloReach));
	const int& load_state = *reinterpret_cast<int*>(pBaseAddress + (0x1810EC5A4 - 0x180000000));

	const char* load_state_names[] =
	{
		"initial",
		"create_local_squad",
		"select_game_mode",
		"saved_film",
		"campaign",
		"previous_game_state",
		"multiplayer",
		"survival",
		"wait_for_party",
		"join_remote_squad",
		"unused",
		"start_game",
		"terminate"
	};

	auto result = GameEngineHostCallback_Bypass([a1, a2, load_state, load_state_names]()
		{

			static int previous_load_state = k_load_state_invalid;

			if (load_state != previous_load_state)
			{
				previous_load_state = load_state;
				printf("load_state changed to: %s\n", load_state_names[load_state]);
			}

			auto result = main_game_launch(a1, a2);

			if (load_state != previous_load_state)
			{
				previous_load_state = load_state;
				printf("load_state changed to: %s\n", load_state_names[load_state]);
			}

			return result;
		}
	);
	return result;
};

HaloReachHook<0x180108FB0, char* __fastcall (uint8_t* pSimulationWatcher, char* dst)> simulation_watcher_get_status = [](uint8_t* pSimulationWatcher, char* dst)
{
	auto result = simulation_watcher_get_status(pSimulationWatcher, dst);
	printf("%s\n%s\n", dst, result);
	return result;
};

HaloReachHook<0x1800129B0, void* __stdcall ()> main_thread_routine = []()
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

HaloReachHook<0x180013EA0, const char* __fastcall (e_peer_property game_load_status)> peer_property_get_string = [](e_peer_property game_load_status)
{
	auto pGameLoadStatusStr = peer_property_get_string(game_load_status);

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

HaloReachHook<0x180013090, __int64 __fastcall (__int64 a1)> sub_180013090 = [](__int64 a1)
{
	auto result = sub_180013090(a1);
	auto game_options = (s_game_options*)(a1 + 2280);
	return result;
};

HaloReachHook<0x18034A7E0, bool __fastcall (s_game_options* a1)> game_options_verify = [](s_game_options* a1)
{
	auto result = game_options_verify(a1);
	WriteLineVerbose("s_game_options::scenario_path: %s", a1->scenario_path);
	return result;
};

HaloReachHook<0x180012200, __int64(__fastcall)(__int64 a1)> sub_180012200 = [](__int64 a1)
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
HaloReachHook<0x1803A6B30, levels_try_and_get_scenario_path_func> levels_try_and_get_scenario_path = [](int campaign_id, unsigned int map_id, char* scenario_path, int size)
{
	map_id = 0x10231971; // force the default map load code path

	auto result = levels_try_and_get_scenario_path(campaign_id, map_id, scenario_path, size);

	if (strlen(scenario_path) == 0)
	{
		WriteLineVerbose("WARNING: The map name is not set!");
		WriteLineVerbose("SELECTED MAP: <none>");
		ThrowDebugger();
	}
	else if (strstr(scenario_path, "mainmenu") != 0)
	{
		WriteLineVerbose("WARNING: The mainmenu is not supported!");
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

HaloReachHook<0x1800122F0, int()> sub_1800122F0 = []()
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

bool SetPlayerName()
{
	wchar_t name[16] = {};
	GetPrivateProfileStringW(L"Player", L"Name", L"Player", name, 16, L".\\Settings.ini");
	int index = 0; // GetPrivateProfileIntW(L"Player", L"Index", 0, L".\\Settings.ini");

	if (wcsncmp(g_player_names[index], name, 16) == 0)
	{
		WriteLineVerbose("player[%d].Name already set", index);
		return false;
	}

	wcsncpy_s(g_player_names[index], 32, name, 16);

	WriteLineVerbose("player[%d].Name: set %ls", index, name);
	return true;
}

static s_game_globals *game_globals;
static s_player_control_globals *player_control_globals;
static s_director_globals *director_globals;

HaloReachHook<0x180307B10, char(__fastcall)()> input_update = []() {

	CustomWindow::Update();

	if (ThreadLocalStorage.IsValid())
	{
		//assert(game_globals = ThreadLocalStorage.Get<s_game_globals *>(_tls_offset_game_globals));

		//WriteLineVerbose("game_globals->game_options.scenario_path: %s", game_globals->game_options.scenario_path)

		assert(player_control_globals = ThreadLocalStorage.Get<s_player_control_globals *>(_tls_offset_player_control_globals));
		assert(director_globals = ThreadLocalStorage.Get<s_director_globals *>(_tls_offset_director_globals));

		float mov = 0.042f;

		// up
		if (GetAsyncKeyState('U') & 0x8000)
			player_control_globals->vLookAngle += mov;
		// down
		if (GetAsyncKeyState('J') & 0x8000)
			player_control_globals->vLookAngle -= mov;
		// left
		if (GetAsyncKeyState('H') & 0x8000)
			player_control_globals->hLookAngle += mov;
		// right
		if (GetAsyncKeyState('K') & 0x8000)
			player_control_globals->hLookAngle -= mov;
	}

	return input_update();
};

HaloReachHook<0x1803080A0, char(__fastcall)(KeyCode a1)> sub_1803080A0 = [](KeyCode a1)
{
	auto result = sub_1803080A0(a1);
	return result;
};

HaloReachHook<0x180780D90, preferences_set_bindings_func> preferences_set_bindings_type = [](preferences_set_bindings_args)
{
	auto result = preferences_set_bindings_type(preferences_set_bindings_vals);
	return result;
};

HaloReachHook<0x180306D50, _BYTE* ()> preferences_initialize = []()
{
	auto result = preferences_initialize();
	WriteLineVerbose("preferences_initialize: %p", result);
	return result;
};

HaloReachHook<0x1803E3510, __int64(__fastcall)(uint8_t*, int, float, char)> camera_new = [](uint8_t* director, int camera_type, float camera_speed, char force_update)
{
	//if (camera_type == 4) // on death set the camera_mode to flying
	//	camera_type = 2;

	auto result = camera_new(director, camera_type, camera_speed, force_update);
	return result;
};

HaloReachHook<0x1804DA240, float(__stdcall)()> observer_get_suggested_field_of_view = []()
{
	auto result = observer_get_suggested_field_of_view();

	return g_fieldOfView * 0.017453292f;

	return result;
};

enum ControllerButton32 : uint32_t
{
	eControllerButtonLeftTrigger,
	eControllerButtonRightTrigger,
	eControllerButtonDpadUp,
	eControllerButtonDpadDown,
	eControllerButtonDpadLeft,
	eControllerButtonDpadRight,
	eControllerButtonStart,
	eControllerButtonSelect,
	eControllerButtonLeftStick,
	eControllerButtonRightStick,
	eControllerButtonA,
	eControllerButtonB,
	eControllerButtonX,
	eControllerButtonY,
	eControllerButtonLeftBumper,
	eControllerButtonRightBumper,

	eControllerButton_Count,
	eControllerButton_None = 0xFF, // An invalid controller button (for use in unset bindings)
};

#pragma pack(push, 1)
struct s_bindings_table
{
	float ControllerSensitivityX;
	float ControllerSensitivityY;
	float unknown8;
	float unknownC;
	float unknown10;
	BYTE unknown14;
	BYTE __padding15[3];
	ControllerButton32 ControllerButtons[41];
	WORD unknownBC;
	BYTE unknownBE;
	BYTE unknownBF;
	WORD unknownC0;
	BYTE unknownC2;
	BYTE unknownC3;
	WORD unknownC4;
	BYTE __paddingC6[2];
	float unknownC8;
	float unknownCC;
	float unknownD0;
	float unknownD4;
};
#pragma pack(pop)
static_assert(sizeof(s_bindings_table) == 0xD8, "");

static int test_button = 0;

HaloReachHook<0x1803D8480, __int64 __fastcall (s_bindings_table* a1)> bindings_set_default = [](s_bindings_table* a1)
{
	auto result = bindings_set_default(a1);

	// 0 for left trigger
	// 1 for right trigger

	//memset(a1->ControllerButtons, 0, sizeof(a1->ControllerButtons));
	//for (int i = 0; i < _countof(a1->ControllerButtons); i++)
	//{
	//	a1->ControllerButtons[i] = ControllerButton32::eControllerButtonLeftTrigger;
	//}

	enum Action
	{
		Jump,
		SwitchNade,
		SwitchWeapon,
		Action,
		Melee,
		Equipment,
		ThrowGrenade,
		Fire,
		Crouch,
		Zoom,
		VehicleBrake,
		Unknown,
		BrakeVehicle2,
		Unknown1,
		Unknown2,
		Unknown3,
		Unknown4,
		ShowWeaponDetails,
		Unknown5,
		Unknown6,
		Visor,
		SkipCutscene,
		Unknown8,
		Unknown9,
		Unknown10,
		Unknown11,
		Unknown12,
		UnknownPhysicsDebug1, // makes vehicles move a bit when pressed right next to it
		UnknownPhysicsDebug2, // makes vehicles move a bit when pressed right next to it
		Unknown15,
		SkipCutsceneConfirm,
		Unknown17,
		Unknown18,
		Unknown19,
		Unknown20,
		Unknown21,
		Unknown22,
		Unknown23,
		Unknown24,
		Unknown25,
		Unknown26,
	};

	// default expected ordering
	assert(a1->ControllerButtons[Jump] == eControllerButtonA);
	assert(a1->ControllerButtons[SwitchNade] == eControllerButtonB);
	assert(a1->ControllerButtons[SwitchWeapon] == eControllerButtonY);
	assert(a1->ControllerButtons[Action] == eControllerButtonX);
	assert(a1->ControllerButtons[Melee] == eControllerButtonRightBumper);
	assert(a1->ControllerButtons[Equipment] == eControllerButtonLeftBumper);
	assert(a1->ControllerButtons[ThrowGrenade] == eControllerButtonLeftTrigger);
	assert(a1->ControllerButtons[Fire] == eControllerButtonRightTrigger);
	assert(a1->ControllerButtons[Crouch] == eControllerButtonLeftStick);
	assert(a1->ControllerButtons[Zoom] == eControllerButtonRightStick);
	assert(a1->ControllerButtons[VehicleBrake] == eControllerButtonLeftTrigger);
	assert(a1->ControllerButtons[Unknown] == eControllerButtonB);
	assert(a1->ControllerButtons[BrakeVehicle2] == eControllerButtonRightBumper);
	assert(a1->ControllerButtons[Unknown1] == eControllerButtonLeftBumper);
	assert(a1->ControllerButtons[Unknown2] == eControllerButtonB);
	assert(a1->ControllerButtons[Unknown3] == eControllerButtonDpadUp);
	assert(a1->ControllerButtons[Unknown4] == eControllerButtonStart);
	assert(a1->ControllerButtons[ShowWeaponDetails] == eControllerButtonSelect);
	assert(a1->ControllerButtons[Unknown5] == eControllerButtonDpadLeft);
	assert(a1->ControllerButtons[Unknown6] == eControllerButtonDpadRight);
	assert(a1->ControllerButtons[Visor] == eControllerButtonDpadLeft);
	assert(a1->ControllerButtons[SkipCutscene] == eControllerButtonA);
	assert(a1->ControllerButtons[Unknown8] == eControllerButtonB);
	assert(a1->ControllerButtons[Unknown9] == eControllerButtonDpadDown);
	assert(a1->ControllerButtons[Unknown10] == eControllerButtonDpadUp);
	assert(a1->ControllerButtons[Unknown11] == eControllerButtonDpadLeft);
	assert(a1->ControllerButtons[Unknown12] == eControllerButtonDpadRight);
	assert(a1->ControllerButtons[UnknownPhysicsDebug1] == eControllerButtonRightBumper);
	assert(a1->ControllerButtons[UnknownPhysicsDebug2] == eControllerButtonLeftBumper);
	assert(a1->ControllerButtons[Unknown15] == eControllerButtonDpadUp);
	assert(a1->ControllerButtons[SkipCutsceneConfirm] == eControllerButtonY);
	assert(a1->ControllerButtons[Unknown17] == eControllerButtonDpadUp);
	assert(a1->ControllerButtons[Unknown18] == eControllerButtonDpadDown);
	assert(a1->ControllerButtons[Unknown19] == eControllerButtonSelect);
	assert(a1->ControllerButtons[Unknown20] == eControllerButtonDpadLeft);
	assert(a1->ControllerButtons[Unknown21] == eControllerButtonX);
	assert(a1->ControllerButtons[Unknown22] == eControllerButtonSelect);
	assert(a1->ControllerButtons[Unknown23] == eControllerButtonDpadUp);
	assert(a1->ControllerButtons[Unknown24] == eControllerButtonX);
	assert(a1->ControllerButtons[Unknown25] == eControllerButtonB);
	assert(a1->ControllerButtons[Unknown26] == eControllerButtonB);

	enum ControlsLayout
	{
		Default,
		SouthPaw,
		Boxer,
		GreenThumb,
		BumperJumper,
		Recon
	};

	switch (g_controlsLayout)
	{
	case SouthPaw:
		a1->ControllerButtons[Jump] = eControllerButtonA;
		a1->ControllerButtons[Melee] = eControllerButtonLeftBumper;
		a1->ControllerButtons[SwitchWeapon] = eControllerButtonY;
		a1->ControllerButtons[SwitchNade] = eControllerButtonB;
		a1->ControllerButtons[Equipment] = eControllerButtonRightBumper;
		a1->ControllerButtons[Action] = eControllerButtonX;
		a1->ControllerButtons[Fire] = eControllerButtonRightTrigger;
		a1->ControllerButtons[ThrowGrenade] = eControllerButtonLeftTrigger;
		a1->ControllerButtons[Zoom] = eControllerButtonRightStick;
		a1->ControllerButtons[Crouch] = eControllerButtonLeftStick;
		break;
	case Boxer:
		a1->ControllerButtons[Jump] = eControllerButtonA;
		a1->ControllerButtons[Melee] = eControllerButtonLeftTrigger;
		a1->ControllerButtons[SwitchWeapon] = eControllerButtonY;
		a1->ControllerButtons[SwitchNade] = eControllerButtonB;
		a1->ControllerButtons[Equipment] = eControllerButtonLeftBumper;
		a1->ControllerButtons[Action] = eControllerButtonX;
		a1->ControllerButtons[Fire] = eControllerButtonRightTrigger;
		a1->ControllerButtons[ThrowGrenade] = eControllerButtonRightBumper;
		a1->ControllerButtons[Zoom] = eControllerButtonRightStick;
		a1->ControllerButtons[Crouch] = eControllerButtonLeftStick;
		break;
	case GreenThumb:
		a1->ControllerButtons[Jump] = eControllerButtonA;
		a1->ControllerButtons[Melee] = eControllerButtonRightStick;
		a1->ControllerButtons[SwitchWeapon] = eControllerButtonY;
		a1->ControllerButtons[SwitchNade] = eControllerButtonB;
		a1->ControllerButtons[Equipment] = eControllerButtonLeftBumper;
		a1->ControllerButtons[Action] = eControllerButtonX;
		a1->ControllerButtons[Fire] = eControllerButtonRightTrigger;
		a1->ControllerButtons[ThrowGrenade] = eControllerButtonLeftTrigger;
		a1->ControllerButtons[Zoom] = eControllerButtonRightBumper;
		a1->ControllerButtons[Crouch] = eControllerButtonLeftStick;
		break;
	case BumperJumper:
		a1->ControllerButtons[Jump] = eControllerButtonLeftBumper;
		a1->ControllerButtons[Melee] = eControllerButtonRightBumper;
		a1->ControllerButtons[SwitchWeapon] = eControllerButtonY;
		a1->ControllerButtons[SwitchNade] = eControllerButtonA;
		a1->ControllerButtons[Equipment] = eControllerButtonX;
		a1->ControllerButtons[Action] = eControllerButtonB;
		a1->ControllerButtons[Fire] = eControllerButtonRightTrigger;
		a1->ControllerButtons[ThrowGrenade] = eControllerButtonLeftTrigger;
		a1->ControllerButtons[Zoom] = eControllerButtonRightStick;
		a1->ControllerButtons[Crouch] = eControllerButtonLeftStick;
		break;
	case Recon:
		a1->ControllerButtons[Jump] = eControllerButtonA;
		a1->ControllerButtons[Melee] = eControllerButtonB;
		a1->ControllerButtons[SwitchWeapon] = eControllerButtonY;
		a1->ControllerButtons[SwitchNade] = eControllerButtonX;
		a1->ControllerButtons[Equipment] = eControllerButtonLeftBumper;
		a1->ControllerButtons[Action] = eControllerButtonRightBumper;
		a1->ControllerButtons[Fire] = eControllerButtonRightTrigger;
		a1->ControllerButtons[ThrowGrenade] = eControllerButtonLeftTrigger;
		a1->ControllerButtons[Zoom] = eControllerButtonRightStick;
		a1->ControllerButtons[Crouch] = eControllerButtonLeftStick;
		break;
	default:
		break;
	}

	return result;
};

void WriteGameState()
{
	if (GetAsyncKeyState(VK_F8)) 
	{
		FILE *pGameStateFile = fopen("gamestate.hdr", "w+b");
		auto pGameStateHeader = *(s_game_state_header **)0x183841B18;
		fwrite(pGameStateHeader, 1, sizeof(s_game_state_header), pGameStateFile);
		fclose(pGameStateFile);
	}
}

HaloReachHook<0x180450C20, char(__stdcall)()> pan_cam_enabled = []()
{
	auto result = pan_cam_enabled();

	result = g_pancamEnabled;

	return result;
};

void init_haloreach_hooks()
{
	check_library_can_load("bink2w64.dll");

	init_detours();

	create_window.SetIsActive(useCustomGameWindow);

	physical_memory_stage_push = get_function_ptr<HaloGameID::HaloReach, 0x1803FB790, physical_memory_stage_push_func>();
	wait_for_render_thread = get_function_ptr<HaloGameID::HaloReach, 0x18031F6A0, wait_for_render_thread_func>();

	g_frameLimit = GetPrivateProfileIntW(L"Game", L"FrameLimit", 60, L".\\Settings.ini");
	g_fieldOfView = GetPrivateProfileIntW(L"Camera", L"FieldOfView", 78, L".\\Settings.ini");
	g_controlsLayout = GetPrivateProfileIntW(L"Player", L"ControlsLayout", 0, L".\\Settings.ini");
	g_pancamEnabled = (bool)GetPrivateProfileIntW(L"Debug", L"PancamEnabled", 0, L".\\Settings.ini");

	//input_update.SetCallback([](void *) { WriteGameState(); }, nullptr);

	CustomWindow::SetupHooks();
	DataReferenceBase::ProcessTree(HaloGameID::HaloReach);
	FunctionHookBase::ProcessTree(HaloGameID::HaloReach);

	end_detours();
}
