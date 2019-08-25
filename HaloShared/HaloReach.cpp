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

intptr_t GetGameEngineHostCallbackOffset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1810EC5C0;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x180D37AA8;
	}
	return ~intptr_t();
}
HaloReachDataEx<GameEngineHostCallback*, GetGameEngineHostCallbackOffset> g_GameEngineHostCallback;

intptr_t TlsIndex_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1810A3098;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x180CF6998;
	}
	return ~intptr_t();
}
DataEx<uint32_t, TlsIndex_offset> TlsIndex;

intptr_t g_render_thread_mode_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x18102F2A4;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x180C79B28;
	}
	return ~intptr_t();
}
DataEx<LONG, g_render_thread_mode_offset> g_render_thread_mode;

intptr_t dword_1810EC584_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1810EC584;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x180D37A78;
	}
	return ~intptr_t();
}
DataEx<DWORD, dword_1810EC584_offset> dword_1810EC584;

intptr_t byte_18342E55D_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x18342E55D;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x18340E4CB;
	}
	return ~intptr_t();
}
DataEx<BYTE, byte_18342E55D_offset> byte_18342E55D;

intptr_t byte_183984DE4_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x183984DE4;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x18358EF04;
	}
	return ~intptr_t();
}
DataEx<BYTE, byte_183984DE4_offset> byte_183984DE4;

intptr_t dword_1810524AC_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1810524AC;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x180CA20A8;
	}
	return ~intptr_t();
}
DataEx<DWORD, dword_1810524AC_offset> dword_1810524AC;

intptr_t g_controller_interfaces_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x183D43560;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x183945FC0;
	}
	return ~intptr_t();
}
DataEx<c_controller_interface[4], g_controller_interfaces_offset> g_controller_interfaces;

intptr_t g_game_options_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x183B0FB70;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x183719E50;
	}
	return ~intptr_t();
}
DataEx<s_game_options, g_game_options_offset> g_game_options;

intptr_t g_player_names_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x183DE6FB0;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x1839EB850;
	}
	return ~intptr_t();
}
DataEx<wchar_t[4][32], g_player_names_offset> g_player_names;

intptr_t g_hwnd_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1810EC5E0;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x180D37B10;
	}
	return ~intptr_t();
}
DataEx<HWND, g_hwnd_offset> g_hwnd;

intptr_t level_name_to_patch_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x180DC64A8;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x180A48E60;
	}
	return ~intptr_t();
}
DataEx<char, level_name_to_patch_offset> level_name_to_patch;

// HaloReach_2019_Jun_24_Data<float, 0x183DF5830> dword_183DF5830; g_gamepad_globals->unknown350
HaloReach_2019_Jun_24_Data<_QWORD, 0x183461018> qword_183461018; // no equivalent

intptr_t g_gamepad_globals_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x183DF54E0;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x1839EBDE0;
	}
	return ~intptr_t();
}
DataEx<s_gamepad_globals, g_gamepad_globals_offset> g_gamepad_globals;

intptr_t g_input_abstraction_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x183B2E510;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x1837387F0;
	}
	return ~intptr_t();
}
DataEx<s_input_abstraction, g_input_abstraction_offset> g_input_abstraction;

intptr_t g_WndProc_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1810EC5F0;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x180D37B20;
	}
	return ~intptr_t();
}
HaloReachDataEx<WNDPROC, g_WndProc_offset> g_WndProc;

intptr_t g_hInstance_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1810EC5D0;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x180D37B00;
	}
	return ~intptr_t();
}
HaloReachDataEx<HINSTANCE, g_hInstance_offset> g_hInstance;

intptr_t ClassName_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1810EC600;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x180D37B30;
	}
	return ~intptr_t();
}
HaloReachDataEx<char[64], ClassName_offset> ClassName;
intptr_t WindowName_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1810EC640;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x180D37B70;
	}
	return ~intptr_t();
}
HaloReachDataEx<char[64], WindowName_offset> WindowName;

HaloReach_2019_Jun_24_Data<char*, 0x183461000> g_shell_command_line; // no equivalent

intptr_t g_createdWindow_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1810EC5D8;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x180D37B08;
	}
	return ~intptr_t();
}
DataEx<HWND, g_createdWindow_offset> g_createdWindow;

// Halo Reach Functions

intptr_t wait_for_render_thread_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x18031F6A0;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x18015D360;
	}
	return ~intptr_t();
}
HaloReachHookEx<wait_for_render_thread_offset, __int64()> wait_for_render_thread;

intptr_t restricted_region_unlock_primary_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1803FB790;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x1802041F0;
	}
	return ~intptr_t();
}
HaloReachHookEx<restricted_region_unlock_primary_offset, __int64(int a1)> restricted_region_unlock_primary;

// core functionality required for the game to run
#include "haloreach.core.inl"

// input functionality
#include "haloreach.input.inl"

//// rendering functionality
//#include "haloreach.render.inl"
//
//// log and text manipulation functionality
//#include "haloreach.log.inl"
//
//// game functionality
//#include "haloreach.game.inl"

// --- WORK IN PROGRESS BELOW ---

#pragma region RenderingWIP

#include <dxgi.h>
#include <d3d11_4.h>

HaloReach_2019_Jun_24_Data<void*, 0x1810EC5B0> g_pIDXGISwapChain;
HaloReach_2019_Jun_24_Pointer<IDXGISwapChain*, 0x18112D378> g_pSwapChain;
HaloReach_2019_Jun_24_Data<IID, 0x180E0B2A8> stru_180E0B2A8;
HaloReach_2019_Jun_24_Pointer<IDXGIFactory1*, 0x18112D368> ppFactory;
HaloReach_2019_Jun_24_Pointer<ID3D11Device*, 0x18112D588> g_pDevice;

extern intptr_t initialize_device_offset(HaloGameID gameID);
extern HaloReachHookEx<initialize_device_offset, char()> initialize_device;

Data<HaloGameID::HaloReach_2019_Aug_20, ID3D11Device*, 0x180D37AA0> qword_180D37AA0;

// allow the game to read the command line to use -width and -height
HaloReachHookEx<initialize_device_offset, char()> initialize_device = { "initialize_device", []()
{
	D3D_FEATURE_LEVEL pFeatureLevels[] = {
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_0,
	};

  ID3D11Device* pDevice = nullptr;
  ID3D11DeviceContext* pImmediateContext = nullptr;
  D3D_FEATURE_LEVEL FeatureLevel = {};
  auto D3D11CreateDeviceResult = D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, pFeatureLevels, _countof(pFeatureLevels), D3D11_SDK_VERSION, &pDevice, &FeatureLevel, &pImmediateContext);
  assert(D3D11CreateDeviceResult == S_OK);

  qword_180D37AA0 = pDevice;

  auto result = initialize_device();

  //bool isCurrent = ppFactory->IsCurrent();
  //assert(isCurrent);
  //ID3D11DeviceContext* pD3DContext = nullptr;
  //g_pDevice->GetImmediateContext(&pD3DContext);

  return result;
} };

intptr_t initialize_device_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1806C2C30;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x18040C8C0;
	}
	return ~intptr_t();
}

#pragma endregion

FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x18000F8D0, int()> sub_18000F8D0 = []()
{
	auto callback = [=]() { return sub_18000F8D0(); };
	return GEHCBypass<GEHCBypassType::UseValidPointer>(callback);
};

extern s_game_launch_data* p_game_launch_data;


//Data<HaloGameID::HaloReach_2019_Aug_20, __int64, 0x18445DB98> qword_18445DB98;
//FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x18030EC20, char()> survival_engine_member8 = []()
//{
//	auto result = survival_engine_member8();
//	return result;
//};

FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x180161FF0, void __fastcall(__int64 a1, unsigned int a2)> c_game_engine_variant_ctor = [](__int64 a1, unsigned int a2)
{
	return c_game_engine_variant_ctor(a1, a2);
};

//FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x180010770, __int64()> main_game_launch_campaign = []()
//{
//	return main_game_launch_campaign();
//};
//
//FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x180010EA0, __int64()> main_game_launch_survival = []()
//{
//	return main_game_launch_survival();
//};

//sub_180488C90


//// don't run stuff that crashes fix but we should remove this
//FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x180310430, __int64()> sub_180310430 = []()
//{
//	return __int64(0);
//};



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
//HaloReachHook<0x180780D90, profile_configuration_update_func> profile_configuration_update_type = [](profile_configuration_update_args)
//{
//	auto result = profile_configuration_update_type(profile_configuration_update_vals);
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
		HaloReach_2019_Jun_24_Data<s_game_state_header*, 0x183841B18> pGameStateHeader;
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

bool SetPlayerNameAndServiceTag()
{
	wchar_t name[16] = {};
	wchar_t tag[5] = {};

	GetPrivateProfileStringW(L"Player", L"Name", L"Player", name, 16, L".\\Settings.ini");
	GetPrivateProfileStringW(L"Player", L"ServiceTag", L"UNSC", tag, 5, L".\\Settings.ini");

	int index = 0; // GetPrivateProfileIntW(L"Player", L"Index", 0, L".\\Settings.ini");

	if (wcsncmp(g_player_names[index], name, 16) == 0)
	{
		WriteLineVerbose("player[%d].Name already set", index);
		return false;
	}
	if (wcsncmp(g_controller_interfaces[index].Profile.ServiceTag, tag, 5) == 0)
	{
		WriteLineVerbose("player[%d].Tag already set", index);
		return false;
	}

	wcsncpy_s(g_player_names[index], 32, name, 16);
	wcsncpy(g_controller_interfaces[index].Profile.ServiceTag, tag, 5);

	WriteLineVerbose("player[%d].Name: set %ls", index, name);
	WriteLineVerbose("player[%d].Tag: set %ls", index, tag);
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
	g_Binds.Add(_game_action_context_primary, _key_code_e);
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

uint64_t GetVersionID(const char* pFilename)
{
	uint64_t result = 0;
	DWORD  verHandle = 0;
	UINT   size = 0;
	LPBYTE lpBuffer = NULL;
	DWORD  verSize = GetFileVersionInfoSize(pFilename, &verHandle);

	if (verSize != NULL)
	{
		char* verData = static_cast<char*>(alloca(verSize));

		if (GetFileVersionInfo(pFilename, verHandle, verSize, verData))
		{
			if (VerQueryValue(verData, "\\", (VOID FAR * FAR*) & lpBuffer, &size))
			{
				if (size)
				{
					VS_FIXEDFILEINFO* verInfo = (VS_FIXEDFILEINFO*)lpBuffer;
					if (verInfo->dwSignature == 0xfeef04bd)
					{
						result |= uint64_t(verInfo->dwFileVersionMS);
						result <<= 32;
						result |= uint64_t(verInfo->dwFileVersionLS);

					}
				}
			}
		}
	}
	return result;
}

#define MAKE_FILE_VERSION(a, b, c, d) ((uint64_t(a) << 48) | (uint64_t(b) << 32) | (uint64_t(c) << 16) | (uint64_t(d) << 0))

void init_haloreach_hooks()
{
	check_library_can_load("bink2w64.dll");

	HaloGameID gameID = HaloGameID::NotSet;

	uint64_t haloReachVersion = GetVersionID("HaloReach.dll");
	switch (haloReachVersion)
	{
	case MAKE_FILE_VERSION(1, 1035, 0, 0):
		gameID = HaloGameID::HaloReach_2019_Aug_20;
		break;
	case MAKE_FILE_VERSION(1, 887, 0, 0):
		gameID = HaloGameID::HaloReach_2019_Jun_24;
		break;
	}

	init_detours();

	//initialize_window.SetIsActive(g_useCustomGameWindow);

	ReadConfig();

	DataReferenceBase::ProcessTree(gameID);
	FunctionHookBase::ProcessTree(gameID);

	end_detours();

	// #TODO: Remove this
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24:
		g_shell_command_line = GetCommandLineA();
		break;
	}

}
