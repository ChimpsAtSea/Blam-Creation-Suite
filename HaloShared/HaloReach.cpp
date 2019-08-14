#include "haloshared-private-pch.h"

// Custom Engine Stuff
GameEngineHostCallback gameEngineHostCallback;
GameEngineHostCallback_vftbl gameEngineHostCallbackVftbl;
GameEvents gameEvents;
GameEvents_vftbl gameEventsVftbl;
s_thread_local_storage ThreadLocalStorage;

// Custom Stuff

bool g_useCustomGameEngineHostCallback = false;
bool g_useCustomGameWindow = false;
s_game_bindings g_GameBindings;
bool g_customBinds = false;
e_peer_property g_lastGameLoadStatus;
std::string g_lastGameLoadStatusStr;
const char* g_haloReachPathOverride = "";
CurrentState g_CurrentGameState = CurrentState::eInactive;
bool g_gameManuallyKilled = false;
bool g_isHooked = false;
WORD g_frameLimit = 60;
int g_fieldOfView = 78;
int g_controlsLayout = 0;
int g_useController = 0;
bool g_pancamEnabled = false;
bool g_keyboardPrintKeyState = false;
bool g_waitingForInputUpdate = false;
bool g_hideWindowOnStartup = false;

// Halo Reach Variables

ReachData<uint32_t, 0x1810A3098> TlsIndex;
ReachData<GameEngineHostCallback*, 0x1810EC5C0> g_GameEngineHostCallback;
ReachData<LONG, 0x18102F2A4> g_render_thread_mode;
ReachData<DWORD, 0x1810EC584> dword_1810EC584;
ReachData<BYTE, 0x18342E55D> byte_18342E55D;
ReachData<BYTE, 0x183984DE4> byte_183984DE4;
ReachData<DWORD, 0x1810524AC> dword_1810524AC;
ReachData<c_controller_interface[4], 0x183D43560> g_controller_interfaces;
ReachData<s_game_options, 0x183B0FB70> g_game_options;
ReachData<wchar_t[4][32], 0x183DE6FB0> g_player_names;
ReachData<HWND, 0x1810EC5E0> g_hwnd;
ReachData<char, 0x180DC64A8> level_name_to_patch;
ReachData<float, 0x183DF5830> dword_183DF5830;
ReachData<_QWORD, 0x183461018> qword_183461018;
ReachData<s_gamepad_globals, 0x183DF54E0> g_gamepad_globals;
ReachData<s_input_abstraction, 0x183B2E510> g_input_abstraction;
ReachData<char[64], 0x1810EC600> ClassName;
ReachData<char[64], 0x1810EC640> WindowName;
ReachData<WNDPROC, 0x1810EC5F0> qword_1810EC5F0;
ReachData<HINSTANCE, 0x1810EC5D0> qword_1810EC5D0;
ReachData<char*, 0x183461000> g_shell_command_line;
ReachData<HWND, 0x1810EC5D8> g_windowHWND;

// Halo Reach Functions

typedef __int64 (*wait_for_render_thread_func)();
typedef __int64(__fastcall* physical_memory_stage_push_func)(int a1);
wait_for_render_thread_func wait_for_render_thread = nullptr;
physical_memory_stage_push_func physical_memory_stage_push = nullptr;

// core functionality required for the game to run
#include "haloreach.core.inl"

// input functionality
#include "haloreach.input.inl"

// rendering functionality
#include "haloreach.render.inl"

// log and text manipulation functionality
#include "haloreach.log.inl"

// game functionality
#include "haloreach.game.inl"

// --- WORK IN PROGRESS BELOW ---

#pragma region RenderingWIP

#include <dxgi.h>
#include <d3d11_4.h>

ReachData<void*, 0x1810EC5B0> g_pIDXGISwapChain;
ReachPointer<IDXGISwapChain*, 0x18112D378> g_pSwapChain;
ReachData<IID, 0x180E0B2A8> stru_180E0B2A8;
ReachPointer<IDXGIFactory1*, 0x18112D368> ppFactory;
ReachPointer<ID3D11Device*, 0x18112D588> g_pDevice;


#include <functional>

 



// allow the game to read the command line to use -width and -height
HaloReachHook<0x1806C2C30, char()> initialize_device = []()
{

	qword_183461018 = 0x10;

	auto result = initialize_device();

	bool isCurrent = ppFactory->IsCurrent();
	assert(isCurrent);
	ID3D11DeviceContext* pD3DContext = nullptr;
	g_pDevice->GetImmediateContext(&pD3DContext);

	return result;
};

#pragma endregion














//HaloReachHook<0x180013EA0, const char* __fastcall (e_peer_property game_load_status)> peer_property_get_string = [](e_peer_property game_load_status)
//{
//	auto pGameLoadStatusStr = peer_property_get_string(game_load_status);
//
//	// this is to prevent spam
//	last_game_load_status = game_load_status;
//	bool isSame = last_game_load_status_str == pGameLoadStatusStr;
//	last_game_load_status_str = pGameLoadStatusStr;
//	bool allowRepeat = false;
//
//	switch (game_load_status)
//	{
//	case _peer_property_map_load_precaching:
//		allowRepeat = false;
//		break;
//	case _peer_property_none:
//	case _peer_property_network_configuration_unavailable:
//	case _peer_property_file_manifest_unavailable:
//	case _peer_property_banhammer_unavailable:
//	case _peer_property_player_stats_unavailable:
//	case _peer_property_lsp_stats_unavailable:
//	case _peer_property_master_hopper_file_unavailable:
//	case _peer_property_hopper_specific_file_unavailable:
//	case _peer_property_network_configuration_pending:
//	case _peer_property_file_manifest_pending:
//	case _peer_property_dlc_map_manifest_pending:
//	case _peer_property_dlc_enumeration_pending:
//	case _peer_property_banhammer_pending:
//	case _peer_property_player_stats_pending:
//	case _peer_property_lsp_stats_pending:
//	case _peer_property_master_hopper_file_pending:
//	case _peer_property_hopper_specific_file_pending:
//	case _peer_property_no_map_selected:
//	case _peer_property_no_game_selected:
//	case _peer_property_map_load_failure:
//	case _peer_property_invalid_film_selected:
//	case _peer_property_no_film_selected:
//	case _peer_property_too_many_teams:
//	case _peer_property_all_observers:
//	case _peer_property_too_many_for_local_coop:
//	case _peer_property_too_many_for_net_coop:
//	case _peer_property_incompatible_for_net_coop:
//	case _peer_property_account_not_online_enabled:
//	case _peer_property_all_profiles_must_by_live_gold:
//	case _peer_property_must_be_connect_to_live:
//	case _peer_property_must_be_in_a_live_lobby:
//	case _peer_property_invalid_hopper:
//	case _peer_property_squad_too_large:
//	case _peer_property_squad_too_small:
//	case _peer_property_too_many_local_players:
//	case _peer_property_too_few_local_players:
//	case _peer_property_non_local_players_exist:
//	case _peer_property_games_played_too_low:
//	case _peer_property_games_played_too_high:
//	case _peer_property_grade_too_low:
//	case _peer_property_grade_too_high:
//	case _peer_property_access_bit_not_set:
//	case _peer_property_unpaid_in_paid_hopper:
//	case _peer_property_paid_in_unpaid_hopper:
//	case _peer_property_guest_not_allowed:
//	case _peer_property_player_missing_files:
//	case _peer_property_player_missing_required_maps:
//	case _peer_property_player_banned_from_matchmaking:
//	case _peer_property_matchmaking_ban_quitting:
//	case _peer_property_not_yet_start_time:
//	case _peer_property_end_time_has_passed:
//	case _peer_property_arena_hopper_no_longer_available:
//	case _peer_property_hd_required_for_playlist:
//	case _peer_property_custom_games_are_disabled:
//	case _peer_property_multiplayer_split_screen:
//	case _peer_property_no_live_in_live_lobby:
//	case _peer_property_must_have_live_for_alpha:
//	case _peer_property_only_one_player_in_theater_alpha:
//	case _peer_property_theater_too_many_players:
//	case _peer_property_theater_must_have_hard_drive:
//	case _peer_property_theater_leader_must_be_host:
//	case _peer_property_theater_all_not_compatible:
//	case _peer_property_too_many_players_in_forge:
//	case _peer_property_user_content_not_permitted:
//	case _peer_property_coop_player_missing_hdd:
//	case _peer_property_coop_player_hdd_mismatch:
//	case _peer_property_coop_player_language_mismatch:
//	case _peer_property_invalid_film_language:
//	case _peer_property_controller_not_attached:
//	case _peer_property_survival_too_many_players:
//	case _peer_property_queued_join_expected:
//	case _peer_property_map_and_game_incompatible:
//	default:
//		allowRepeat = true;
//	}
//
//	if (isSame && allowRepeat)
//	{
//		printf("status [0x%X] %s\n", game_load_status, pGameLoadStatusStr);
//	}
//
//	return pGameLoadStatusStr;
//};

//static s_game_globals* game_globals;
//static s_player_control_globals* player_control_globals;
//static s_director_globals* director_globals;
//
//HaloReachHook<0x180308BD0, __int64 __fastcall (__int64 a1, __int64 a2, int a3)> sub_180308BD0 = [](__int64 a1, __int64 a2, int a3) {
//	auto result = sub_180308BD0(a1, a2, a3);
//
//	return result;
//};

//HaloReachHook<0x1803080A0, char(__fastcall)(e_key_code a1)> sub_1803080A0 = [](e_key_code a1)
//{
//	auto result = sub_1803080A0(a1);
//	return result;
//};

//

//
//HaloReachHook<0x180780D90, preferences_set_bindings_func> preferences_set_bindings_type = [](preferences_set_bindings_args)
//{
//	auto result = preferences_set_bindings_type(preferences_set_bindings_vals);
//	return result;
//};
//
//HaloReachHook<0x180306D50, _BYTE* ()> preferences_initialize = []()
//{
//	auto result = preferences_initialize();
//	WriteLineVerbose("preferences_initialize: %p", result);
//	return result;
//};

void WriteGameState()
{
	if (GetAsyncKeyState(VK_F8))
	{
		FILE* pGameStateFile = fopen("gamestate.hdr", "w+b");
		ReachData<s_game_state_header*, 0x183841B18> pGameStateHeader;
		fwrite(pGameStateHeader, 1, sizeof(s_game_state_header), pGameStateFile);
		fclose(pGameStateFile);
	}
}

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

// TODO: find a better home / move into own file
#pragma region Config

struct Config
{
	char Path[MAX_PATH] = ".\\Settings.ini";

	bool ReadBool(LPCSTR Section, LPCSTR Name, int Default = false)
	{
		return !!GetPrivateProfileIntA(Section, Name, Default, Path);
	}
	int ReadInt(LPCSTR Section, LPCSTR Name, int Default = -1)
	{
		return GetPrivateProfileIntA(Section, Name, Default, Path);
	}
	LPSTR ReadString(LPCSTR Section, LPCSTR Name, LPCSTR Default)
	{
		static char result[MAX_PATH] = "";
		GetPrivateProfileStringA(Section, Name, Default, result, MAX_PATH, Path);
		return result;
	}

	template<int Count, typename T>
	T IndexOf(const char* Array[], const char* Input)
	{
		for (int i = 0; i < Count; i++)
		{
			if (strcmp(Array[i], Input) == 0)
				return (T)i;
		}

		return (T)0xFF;
	}
} g_Config;

#pragma endregion

// TODO: find a better home / move into own file
#pragma region Binds

struct Binds
{
	struct Bind
	{
		e_game_action GameAction;
		e_key_code KeyCode;

		Bind(e_game_action game_action, e_key_code key_code)
		{
			KeyCode = key_code;
			GameAction = game_action;
		}
		Bind(e_key_code key_code, e_game_action game_action)
		{
			KeyCode = key_code;
			GameAction = game_action;
		}
		e_key_code ReadFromConfig()
		{
			LPSTR configResult = g_Config.ReadString("Controls", game_action_strings[GameAction], key_code_strings[KeyCode]);
			return g_Config.IndexOf<k_number_of_key_codes, e_key_code>(key_code_strings, configResult);
		}
	};

	std::vector<Bind> Array;
	int Count = 0;

	void Add(e_game_action game_action, e_key_code key_code)
	{
		Array.push_back(Bind(game_action, key_code));
		Count++;
	}

	void ReadBindsFromConfig(s_game_bindings& gameBindings)
	{
		memset(&gameBindings, 0xFF, sizeof(gameBindings));

		for (int i = 0; i < Count; i++)
		{
			gameBindings.KeyboardBindings[Array.at(i).GameAction].primary = Array.at(i).ReadFromConfig();
		}
	}
} g_Binds;

void ReadBinds()
{
	g_Binds.Add(_game_action_jump, _key_code_space);
	g_Binds.Add(_game_action_switch_grenade, _key_code_g);
	g_Binds.Add(_game_action_switch_weapon, _key_code_c);
	g_Binds.Add(_game_action_action, _key_code_e);
	g_Binds.Add(_game_action_melee_attack, _key_code_q);
	g_Binds.Add(_game_action_equipment, _key_code_left_shift);
	g_Binds.Add(_game_action_throw_grenade, _key_code_f);
	g_Binds.Add(_game_action_crouch, _key_code_left_control);
	g_Binds.Add(_game_action_vehicle_brake2, _key_code_left_bracket);
	g_Binds.Add(_game_action_show_weapon_details, _key_code_back);
	g_Binds.Add(_game_action_night_vision, _key_code_4);
	g_Binds.Add(_game_action_skip_cutscene, _key_code_enter);
	g_Binds.Add(_game_action_skip_cutscene_confirm, _key_code_space);
	g_Binds.Add(_game_action_reload, _key_code_r);
	g_Binds.Add(_game_action_move_forward, _key_code_w);
	g_Binds.Add(_game_action_move_backwards, _key_code_s);
	g_Binds.Add(_game_action_move_left, _key_code_a);
	g_Binds.Add(_game_action_move_right, _key_code_d);

	if (g_customBinds = g_Config.ReadBool("Controls", "CustomBinds", true))
		g_Binds.ReadBindsFromConfig(g_GameBindings);
}

#pragma endregion

void ReadConfig()
{
	g_frameLimit = g_Config.ReadInt("Game", "FrameLimit", 60);
	g_fieldOfView = g_Config.ReadInt("Camera", "FieldOfView", 78);
	g_controlsLayout = g_Config.ReadInt("Player", "ControlsLayout", 0);
	g_pancamEnabled = g_Config.ReadBool("Debug", "PancamEnabled", false);
	g_keyboardPrintKeyState = g_Config.ReadBool("Debug", "PrintKeyState", 0);
	g_useController = g_Config.ReadInt("Player", "UseController", 0);
	//input_update.SetCallback([](void *) { WriteGameState(); }, nullptr);

	ReadBinds();
}

void init_haloreach_hooks()
{
	check_library_can_load("bink2w64.dll");

	init_detours();

	initialize_window.SetIsActive(g_useCustomGameWindow);

	physical_memory_stage_push = get_function_ptr<HaloGameID::HaloReach, 0x1803FB790, physical_memory_stage_push_func>();
	wait_for_render_thread = get_function_ptr<HaloGameID::HaloReach, 0x18031F6A0, wait_for_render_thread_func>();

	ReadConfig();

	DataReferenceBase::ProcessTree(HaloGameID::HaloReach);
	FunctionHookBase::ProcessTree(HaloGameID::HaloReach);

	g_shell_command_line = GetCommandLineA();

	end_detours();
}
