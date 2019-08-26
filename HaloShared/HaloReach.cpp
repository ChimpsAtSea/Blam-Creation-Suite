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

Pointer<HaloGameID::HaloReach_2019_Aug_20, IDirectInputDevice8*, 0x1839EC128> qword_1839EC128;

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


HaloReach_2019_Jun_24_Data<void*, 0x1810EC5B0> g_pIDXGISwapChain;

HaloReach_2019_Jun_24_Data<IID, 0x180E0B2A8> stru_180E0B2A8;
HaloReach_2019_Jun_24_Pointer<IDXGIFactory1*, 0x18112D368> ppFactory;
HaloReach_2019_Jun_24_Pointer<ID3D11Device*, 0x18112D588> g_pDevice;

Data<HaloGameID::HaloReach_2019_Aug_20, ID3D11Device*, 0x180D37AA0> qword_180D37AA0;

intptr_t g_pSwapChain_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x18112D378;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x184465D68;
	}
	return ~intptr_t();
}
PointerEx<IDXGISwapChain*, g_pSwapChain_offset> g_pSwapChain;

intptr_t initialize_device_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1806C2C30;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x18040C8C0;
	}
	return ~intptr_t();
}

// allow the game to read the command line to use -width and -height
HaloReachHookEx<initialize_device_offset, char()> initialize_device = { "initialize_device", []()
{
	D3D_FEATURE_LEVEL pFeatureLevels[] =
	{
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
  IDXGISwapChain* pSwapChain = g_pSwapChain;

  DebugUI::Setup(pSwapChain, pDevice, pImmediateContext);

  return result;
} };

#pragma endregion

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



	init_detours();

	//initialize_window.SetIsActive(g_useCustomGameWindow);

	ReadConfig();

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

	end_detours();
}
