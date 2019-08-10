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
int g_useController = 0;
bool g_pancamEnabled = false;
bool g_keyboardPrintKeyState = false;
bool g_waitingForInputUpdate = false;

// Halo Reach Variables

HaloReachReference<uint32_t, 0x1810A3098> TlsIndex;
HaloReachReference<GameEngineHostCallback*, 0x1810EC5C0> g_GameEngineHostCallback;
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
HaloReachReference<float, 0x183DF5830> dword_183DF5830;
HaloReachReference<_QWORD, 0x183461018> qword_183461018;
HaloReachReference<s_gamepad_globals, 0x183DF54E0> g_gamepad_globals;
HaloReachReference<s_input_abstraction, 0x183B2E510> g_input_abstraction;

// Halo Reach Functions

typedef __int64 (*wait_for_render_thread_func)();
typedef __int64(__fastcall* physical_memory_stage_push_func)(int a1);
wait_for_render_thread_func wait_for_render_thread = nullptr;
physical_memory_stage_push_func physical_memory_stage_push = nullptr;

HaloReachReference<char[64], 0x1810EC600> ClassName;
HaloReachReference<char[64], 0x1810EC640> WindowName;
HaloReachReference<WNDPROC, 0x1810EC5F0> qword_1810EC5F0;
HaloReachReference<HINSTANCE, 0x1810EC5D0> qword_1810EC5D0;
HaloReachReference<char*, 0x183461000> g_shell_command_line;



HaloReachHook<0x1806C2890, HWND()> initialize_window = []()
{
	char* pBaseAddress = (char*)GetHaloExecutable(HaloGameID::HaloReach);
	GameEngineHostCallback*& pGameEngineHostCallback = *reinterpret_cast<GameEngineHostCallback * *>(pBaseAddress + (0x1810EC5C0 - 0x180000000));
	HWND& g_windowHWND = *reinterpret_cast<HWND*>(pBaseAddress + (0x1810EC5D8 - 0x180000000));

	auto before = pGameEngineHostCallback;
	pGameEngineHostCallback = nullptr;

	HWND hwnd;
	{
		HMODULE hHaloReachModule = GetModuleHandleA(GetHaloExecutableString(HaloGameID::HaloReach));
		assert(hHaloReachModule);

		qword_1810EC5F0 = CustomWindow::WndProc;
		qword_1810EC5D0 = hHaloReachModule;

		memcpy(&ClassName[0], "HaloReach", sizeof("HaloReach"));
		memcpy(&WindowName[0], "HaloReach", sizeof("HaloReach"));

		hwnd = initialize_window();
	}
	ShowWindow(hwnd, SW_SHOW);

	pGameEngineHostCallback = before;
	return hwnd;
};

HaloReachHook<0x180012B60, __int64 __fastcall (__int64 a1, __int64 a2)> main_game_launch_create_local_squad = [](__int64 a1, __int64 a2)
{
	auto callback = [=]() { return main_game_launch_create_local_squad(a1, a2); };
	return GEHCBypass<GEHCBypassType::UseValidPointer>(callback);
};

HaloReachHookVarArgs<0x18004AFC0, char* (char* dst, char* format, ...)> sprintf_256 = [](char* dst, char* format, ...)
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

HaloReachHookVarArgs<0x18078C550, void(const char* format, ...)> DamagedMediaHaltAndDisplayError = [](const char* format, ...)
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

	auto result = GEHCBypass<GEHCBypassType::UseValidPointer>([a1, a2, load_state, load_state_names]()
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
	if (g_GameEngineHostCallback)
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
	// #HACK #TODO: Figure out the best home for this incase this is incorrect
	g_waitingForInputUpdate = true;

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
	auto callback = []() { return sub_1800122F0(); };
	return GEHCBypass<GEHCBypassType::UseValidPointer>(callback);
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

static s_game_globals* game_globals;
static s_player_control_globals* player_control_globals;
static s_director_globals* director_globals;

HaloReachHook<0x180308BD0, __int64 __fastcall (__int64 a1, __int64 a2, int a3)> sub_180308BD0 = [](__int64 a1, __int64 a2, int a3) {
	auto result = sub_180308BD0(a1, a2, a3);

	return result;
};

HaloReachHook<0x180780C20, __int64 __fastcall (s_binding_preferences* a1, int a2)> sub_180780C20 = [](s_binding_preferences* a1, int a2) 
{
	auto callback = [=]() { return sub_180780C20(a1, a2); };
	return GEHCBypass<GEHCBypassType::UseNullPointer>(callback);
};

HaloReachHook<0x180307B10, char(__fastcall)()> input_update = []() {

	s_bindings_table& bindingsTable = g_input_abstraction.ptr()->BindingsTable[0];

	if (g_keyboardPrintKeyState)
	{
		for (int i = 0; i < _countof(bindingsTable.ControllerButtons); i++)
		{
			if (bindingsTable.ControllerButtons[i])
			{
				WriteLineVerbose("binding table %08lx was pressed value %08lx", i, bindingsTable.ControllerButtons[i]);
			}
		}
	}





	//for (int i = 0; i < _countof(g_input_abstraction->struct3); i++)
	//{
	//	s_input_abstraction_struct3& struct3 = g_input_abstraction->struct3[i];

	//	int sum = 0;
	//	for (int j = 0xD8; j < _countof(struct3.data); j++)
	//	{
	//		sum += static_cast<unsigned __int8>(struct3.data[j]);
	//	}
	//	g_input_abstraction->struct3[0].bindingsTableCopy;
	//	assert(sum == 0);
	//}

	auto result = GEHCBypass<GEHCBypassType::UseValidPointer>([]()
		{
			CustomWindow::inputDeltaX = 0;
			CustomWindow::inputDeltaY = 0;

			CustomWindow::Update();

			if (ThreadLocalStorage.IsValid())
			{
				//assert(game_globals = ThreadLocalStorage.Get<s_game_globals *>(_tls_offset_game_globals));

				//WriteLineVerbose("game_globals->game_options.scenario_path: %s", game_globals->game_options.scenario_path)

				assert(player_control_globals = ThreadLocalStorage.Get<s_player_control_globals*>(_tls_offset_player_control_globals));
				assert(director_globals = ThreadLocalStorage.Get<s_director_globals*>(_tls_offset_director_globals));

				float mov = 0.042f;

				//player_control_globals->hLookAngle += float(CustomWindow::inputDeltaX) * 0.001;
				//player_control_globals->vLookAngle += float(CustomWindow::inputDeltaY) * 0.001;

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
		}
	);
	return result;
};

HaloReachHook<0x1803080A0, char(__fastcall)(e_key_code a1)> sub_1803080A0 = [](e_key_code a1)
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

HaloReachHook<0x1803D8480, __int64 __fastcall (s_bindings_table* a1)> bindings_set_default = [](s_bindings_table* a1)
{
	auto result = bindings_set_default(a1);

	// 0 for left trigger
	// 1 for right trigger

	//memset(a1->ControllerButtons, 0, sizeof(a1->ControllerButtons));
	//for (int i = 0; i < _countof(a1->ControllerButtons); i++)
	//{
	//	a1->ControllerButtons[i] = e_controller_button_32::_controller_button_left_trigger;
	//}

	// default expected ordering
	assert(a1->ControllerButtons[_game_action_jump] == _controller_button_a);
	assert(a1->ControllerButtons[_game_action_switch_grenade] == _controller_button_b);
	assert(a1->ControllerButtons[_game_action_switch_weapon] == _controller_button_y);
	assert(a1->ControllerButtons[_game_action_action] == _controller_button_x);
	assert(a1->ControllerButtons[_game_action_melee_attack] == _controller_button_right_bumper);
	assert(a1->ControllerButtons[_game_action_equipment] == _controller_button_left_bumper);
	assert(a1->ControllerButtons[_game_action_throw_grenade] == _controller_button_left_trigger);
	assert(a1->ControllerButtons[_game_action_fire_primary] == _controller_button_right_trigger);
	assert(a1->ControllerButtons[_game_action_crouch] == _controller_button_left_stick);
	assert(a1->ControllerButtons[_game_action_scope_zoom] == _controller_button_right_stick);
	assert(a1->ControllerButtons[_game_action_vehicle_brake] == _controller_button_left_trigger);
	assert(a1->ControllerButtons[_game_action_11] == _controller_button_b);
	assert(a1->ControllerButtons[_game_action_vehicle_brake2] == _controller_button_right_bumper);
	assert(a1->ControllerButtons[_game_action_13] == _controller_button_left_bumper);
	assert(a1->ControllerButtons[_game_action_14] == _controller_button_b);
	assert(a1->ControllerButtons[_game_action_15] == _controller_button_dpad_up);
	assert(a1->ControllerButtons[_game_action_16] == _controller_button_start);
	assert(a1->ControllerButtons[_game_action_show_weapon_details] == _controller_button_select);
	assert(a1->ControllerButtons[_game_action_18] == _controller_button_dpad_left);
	assert(a1->ControllerButtons[_game_action_19] == _controller_button_dpad_right);
	assert(a1->ControllerButtons[_game_action_night_vision] == _controller_button_dpad_left);
	assert(a1->ControllerButtons[_game_action_skip_cutscene] == _controller_button_a);
	assert(a1->ControllerButtons[_game_action_22] == _controller_button_b);
	assert(a1->ControllerButtons[_game_action_23] == _controller_button_dpad_down);
	assert(a1->ControllerButtons[_game_action_24] == _controller_button_dpad_up);
	assert(a1->ControllerButtons[_game_action_25] == _controller_button_dpad_left);
	assert(a1->ControllerButtons[_game_action_26] == _controller_button_dpad_right);
	assert(a1->ControllerButtons[_game_action_unknown_physics_debug1] == _controller_button_right_bumper);
	assert(a1->ControllerButtons[_game_action_unknown_physics_debug2] == _controller_button_left_bumper);
	assert(a1->ControllerButtons[_game_action_29] == _controller_button_dpad_up);
	assert(a1->ControllerButtons[_game_action_skip_cutscene_confirm] == _controller_button_y);
	assert(a1->ControllerButtons[_game_action_31] == _controller_button_dpad_up);
	assert(a1->ControllerButtons[_game_action_32] == _controller_button_dpad_down);
	assert(a1->ControllerButtons[_game_action_33] == _controller_button_select);
	assert(a1->ControllerButtons[_game_action_34] == _controller_button_dpad_left);
	assert(a1->ControllerButtons[_game_action_35] == _controller_button_x);
	assert(a1->ControllerButtons[_game_action_36] == _controller_button_select);
	assert(a1->ControllerButtons[_game_action_37] == _controller_button_dpad_up);
	assert(a1->ControllerButtons[_game_action_reload] == _controller_button_x);
	assert(a1->ControllerButtons[_game_action_39] == _controller_button_b);
	assert(a1->ControllerButtons[_game_action_40] == _controller_button_b);

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
		a1->ControllerButtons[_game_action_jump] = _controller_button_a;
		a1->ControllerButtons[_game_action_melee_attack] = _controller_button_right_bumper;
		a1->ControllerButtons[_game_action_switch_weapon] = _controller_button_y;
		a1->ControllerButtons[_game_action_switch_grenade] = _controller_button_b;
		a1->ControllerButtons[_game_action_equipment] = _controller_button_right_bumper;
		a1->ControllerButtons[_game_action_action] = _controller_button_x;
		a1->ControllerButtons[_game_action_fire_primary] = _controller_button_right_trigger;
		a1->ControllerButtons[_game_action_throw_grenade] = _controller_button_left_trigger;
		a1->ControllerButtons[_game_action_scope_zoom] = _controller_button_right_stick;
		a1->ControllerButtons[_game_action_crouch] = _controller_button_left_stick;
		break;
	case Boxer:
		a1->ControllerButtons[_game_action_jump] = _controller_button_a;
		a1->ControllerButtons[_game_action_melee_attack] = _controller_button_left_trigger;
		a1->ControllerButtons[_game_action_switch_weapon] = _controller_button_y;
		a1->ControllerButtons[_game_action_switch_grenade] = _controller_button_b;
		a1->ControllerButtons[_game_action_equipment] = _controller_button_left_bumper;
		a1->ControllerButtons[_game_action_action] = _controller_button_x;
		a1->ControllerButtons[_game_action_fire_primary] = _controller_button_right_trigger;
		a1->ControllerButtons[_game_action_throw_grenade] = _controller_button_right_bumper;
		a1->ControllerButtons[_game_action_scope_zoom] = _controller_button_right_stick;
		a1->ControllerButtons[_game_action_crouch] = _controller_button_left_stick;
		break;
	case GreenThumb:
		a1->ControllerButtons[_game_action_jump] = _controller_button_a;
		a1->ControllerButtons[_game_action_melee_attack] = _controller_button_right_stick;
		a1->ControllerButtons[_game_action_switch_weapon] = _controller_button_y;
		a1->ControllerButtons[_game_action_switch_grenade] = _controller_button_b;
		a1->ControllerButtons[_game_action_equipment] = _controller_button_left_bumper;
		a1->ControllerButtons[_game_action_action] = _controller_button_x;
		a1->ControllerButtons[_game_action_fire_primary] = _controller_button_right_trigger;
		a1->ControllerButtons[_game_action_throw_grenade] = _controller_button_left_trigger;
		a1->ControllerButtons[_game_action_scope_zoom] = _controller_button_right_bumper;
		a1->ControllerButtons[_game_action_crouch] = _controller_button_left_stick;
		break;
	case BumperJumper:
		a1->ControllerButtons[_game_action_jump] = _controller_button_left_bumper;
		a1->ControllerButtons[_game_action_melee_attack] = _controller_button_right_bumper;
		a1->ControllerButtons[_game_action_switch_weapon] = _controller_button_y;
		a1->ControllerButtons[_game_action_switch_grenade] = _controller_button_a;
		a1->ControllerButtons[_game_action_equipment] = _controller_button_x;
		a1->ControllerButtons[_game_action_action] = _controller_button_b;
		a1->ControllerButtons[_game_action_fire_primary] = _controller_button_right_trigger;
		a1->ControllerButtons[_game_action_throw_grenade] = _controller_button_left_trigger;
		a1->ControllerButtons[_game_action_scope_zoom] = _controller_button_right_stick;
		a1->ControllerButtons[_game_action_crouch] = _controller_button_left_stick;
		break;
	case Recon:
		a1->ControllerButtons[_game_action_jump] = _controller_button_a;
		a1->ControllerButtons[_game_action_melee_attack] = _controller_button_b;
		a1->ControllerButtons[_game_action_switch_weapon] = _controller_button_y;
		a1->ControllerButtons[_game_action_switch_grenade] = _controller_button_x;
		a1->ControllerButtons[_game_action_equipment] = _controller_button_left_bumper;
		a1->ControllerButtons[_game_action_action] = _controller_button_right_bumper;
		a1->ControllerButtons[_game_action_fire_primary] = _controller_button_right_trigger;
		a1->ControllerButtons[_game_action_throw_grenade] = _controller_button_left_trigger;
		a1->ControllerButtons[_game_action_scope_zoom] = _controller_button_right_stick;
		a1->ControllerButtons[_game_action_crouch] = _controller_button_left_stick;
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
		FILE* pGameStateFile = fopen("gamestate.hdr", "w+b");
		HaloReachReference<s_game_state_header*, 0x183841B18> pGameStateHeader;
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



HaloReachHook<0x1806C2C30, char()> initialize_device = []()
{
	qword_183461018 = 0x10;

	auto result = initialize_device();

	return result;
};

HaloReachHook<0x1803D8640, __int64 __fastcall (GameBindings& a1)> sub_1803D8640 = [](GameBindings& a1)
{
	auto result = sub_1803D8640(a1);

	// mouse buttons
	a1.MouseBindings[_game_action_vehicle_brake].primary = e_mouse::_mouse_button3;
	a1.MouseBindings[_game_action_fire_primary].primary = e_mouse::_mouse_button1;
	a1.MouseBindings[_game_action_scope_zoom].primary = e_mouse::_mouse_button3;

	// mouse axis								
	a1.MouseAxisBindings[_game_action_mouse_axis_unknown45].primary = e_mouse_axis::_mouse_axis_unknown2;
	a1.MouseAxisBindings[_game_action_mouse_axis_unknown46].primary = e_mouse_axis::_mouse_axis_unknown3;
	a1.MouseAxisBindings[_game_action_mouse_axis_unknown47].primary = e_mouse_axis::_mouse_axis_unknown1;
	a1.MouseAxisBindings[_game_action_mouse_axis_unknown48].primary = e_mouse_axis::_mouse_axis_unknown0;

	// keyboard
	a1.KeyboardBindings[_game_action_jump].primary = _key_code_space;
	a1.KeyboardBindings[_game_action_switch_grenade].primary = _key_code_g;
	a1.KeyboardBindings[_game_action_switch_weapon].primary = _key_code_c;
	a1.KeyboardBindings[_game_action_action].primary = _key_code_e;
	a1.KeyboardBindings[_game_action_melee_attack].primary = _key_code_q;
	a1.KeyboardBindings[_game_action_equipment].primary = _key_code_left_shift;
	a1.KeyboardBindings[_game_action_throw_grenade].primary = _key_code_f; // throw gnade		
	a1.KeyboardBindings[_game_action_crouch].primary = _key_code_left_control;
	a1.KeyboardBindings[_game_action_vehicle_brake2].primary = _key_code_left_bracket;
	a1.KeyboardBindings[_game_action_13].primary = _key_code_right_bracket;
	a1.KeyboardBindings[_game_action_16].primary = _key_code_escape;
	a1.KeyboardBindings[_game_action_show_weapon_details].primary = _key_code_back;
	a1.KeyboardBindings[_game_action_night_vision].primary = _key_code_m;
	a1.KeyboardBindings[_game_action_skip_cutscene].primary = _key_code_enter;
	a1.KeyboardBindings[_game_action_skip_cutscene_confirm].primary = _key_code_space;
	a1.KeyboardBindings[_game_action_35].primary = _key_code_space; // banshee flip?
	a1.KeyboardBindings[_game_action_36].primary = _key_code_tab;
	a1.KeyboardBindings[_game_action_37].primary = _key_code_z; // banshee bomb?
	a1.KeyboardBindings[_game_action_reload].primary = _key_code_r;
	a1.KeyboardBindings[_game_action_move_forward].primary = _key_code_w;
	a1.KeyboardBindings[_game_action_move_backwards].primary = _key_code_s;
	a1.KeyboardBindings[_game_action_move_left].primary = _key_code_a;
	a1.KeyboardBindings[_game_action_move_right].primary = _key_code_d;

	//a1.KeyboardBindings[_game_action_11].primary = _key_code_1;
	//a1.KeyboardBindings[_game_action_13].primary = _key_code_2;
	//a1.KeyboardBindings[_game_action_14].primary = _key_code_3;
	//a1.KeyboardBindings[_game_action_15].primary = _key_code_4;
	//a1.KeyboardBindings[_game_action_16].primary = _key_code_5;
	//a1.KeyboardBindings[_game_action_18].primary = _key_code_6;
	//a1.KeyboardBindings[_game_action_19].primary = _key_code_7;
	//a1.KeyboardBindings[_game_action_22].primary = _key_code_8;
	//a1.KeyboardBindings[_game_action_23].primary = _key_code_9;
	//a1.KeyboardBindings[_game_action_24].primary = _key_code_0;
	//a1.KeyboardBindings[_game_action_25].primary = _key_code_1;
	//a1.KeyboardBindings[_game_action_26].primary = _key_code_2;
	//a1.KeyboardBindings[_game_action_27].primary = _key_code_3;
	//a1.KeyboardBindings[_game_action_28].primary = _key_code_4;
	//a1.KeyboardBindings[_game_action_29].primary = _key_code_5;
	//a1.KeyboardBindings[_game_action_31].primary = _key_code_6;
	//a1.KeyboardBindings[_game_action_32].primary = _key_code_7;
	//a1.KeyboardBindings[_game_action_33].primary = _key_code_8;
	//a1.KeyboardBindings[_game_action_34].primary = _key_code_9;
	//a1.KeyboardBindings[_game_action_35].primary = _key_code_0;
	//a1.KeyboardBindings[_game_action_36].primary = _key_code_1;
	//a1.KeyboardBindings[_game_action_37].primary = _key_code_2; // switch nade
	//a1.KeyboardBindings[_game_action_39].primary = _key_code_3; // switch nade
	//a1.KeyboardBindings[_game_action_40].primary = _key_code_4;

	return result;
};

void init_haloreach_hooks()
{
	check_library_can_load("bink2w64.dll");

	init_detours();

	initialize_window.SetIsActive(useCustomGameWindow);

	physical_memory_stage_push = get_function_ptr<HaloGameID::HaloReach, 0x1803FB790, physical_memory_stage_push_func>();
	wait_for_render_thread = get_function_ptr<HaloGameID::HaloReach, 0x18031F6A0, wait_for_render_thread_func>();

	g_frameLimit = GetPrivateProfileIntW(L"Game", L"FrameLimit", 60, L".\\Settings.ini");
	g_fieldOfView = GetPrivateProfileIntW(L"Camera", L"FieldOfView", 78, L".\\Settings.ini");
	g_controlsLayout = GetPrivateProfileIntW(L"Player", L"ControlsLayout", 0, L".\\Settings.ini");
	g_pancamEnabled = (bool)GetPrivateProfileIntW(L"Debug", L"PancamEnabled", 0, L".\\Settings.ini");
	g_keyboardPrintKeyState = (bool)GetPrivateProfileIntW(L"Debug", L"PrintKeyState", 0, L".\\Settings.ini");
	g_useController = GetPrivateProfileIntW(L"Player", L"UseController", 0, L".\\Settings.ini");
	//input_update.SetCallback([](void *) { WriteGameState(); }, nullptr);

	DataReferenceBase::ProcessTree(HaloGameID::HaloReach);
	FunctionHookBase::ProcessTree(HaloGameID::HaloReach);

	g_shell_command_line = GetCommandLineA();

	end_detours();
}
