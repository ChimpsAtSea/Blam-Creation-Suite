#include "haloreach-private-pch.h"

// Custom Engine Stuff
GameEvents gameEvents;
GameEvents_vftbl gameEventsVftbl;
s_thread_local_storage ThreadLocalStorage;

// Custom Stuff

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
bool g_hideWindowOnStartup = false;
HaloGameID g_currentGameID = HaloGameID::NotSet;

char g_LaunchMapName[256] = "ff45_corvette";
e_map_id g_LaunchMapId = _map_id_ff45_corvette;
int g_LaunchGameMode = _game_mode_survival;
e_campaign_difficulty_level g_LaunchCampaignDifficultyLevel = _campaign_difficulty_level_normal;
const char* g_LaunchHopperGameVariant = "ff_gruntpocalypse_054";

// Assembly hacks

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

void patch_out_gameenginehostcallback_mov(HaloGameID id, intptr_t offset)
{
	char* pBeginning = (char*)GetHaloExecutable(id);

	char* pMovAttack = pBeginning + (offset - 0x180000000);
	// 48 8B 0D A3 9B C8 00
	// mov    rcx,QWORD PTR [rip+0xc89ba3]
	// change to
	// 48 31 c9
	// xor rcx, rcx
	// nop 
	// nop 
	// nop 
	// nop

	assert(pMovAttack[0] == 0x48i8);
	assert(pMovAttack[1] == 0x8Bi8);
	assert(pMovAttack[2] == 0x0Di8);

	char bytes[] =
	{
		0x48i8, 0x31i8, 0xc9i8,	// xor rcx, rcx
		0x90i8,					// nop
		0x90i8,					// nop
		0x90i8,					// nop
		0x90i8,					// nop
	};

	memcpy_virtual(pMovAttack, bytes, 7);
}

// Halo Reach Variables

Pointer<HaloGameID::HaloReach_2019_Aug_20, IDirectInputDevice8*, 0x1839EC128> qword_1839EC128;

intptr_t get_game_engine_host_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1810EC5C0;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x180D37AA8;
	}
	return ~intptr_t();
}
DataEx<IGameEngineHost*, get_game_engine_host_offset> g_game_engine_host_pointer;

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

intptr_t get_render_thread_mode_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x18102F2A4;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x180C79B28;
	}
	return ~intptr_t();
}
DataEx<LONG, get_render_thread_mode_offset> g_render_thread_mode;

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
DataEx<WNDPROC, g_WndProc_offset> g_WndProc;

intptr_t g_hInstance_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1810EC5D0;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x180D37B00;
	}
	return ~intptr_t();
}
DataEx<HINSTANCE, g_hInstance_offset> g_hInstance;

intptr_t ClassName_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1810EC600;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x180D37B30;
	}
	return ~intptr_t();
}
DataEx<char[64], ClassName_offset> ClassName;
intptr_t WindowName_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1810EC640;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x180D37B70;
	}
	return ~intptr_t();
}
DataEx<char[64], WindowName_offset> WindowName;

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

// rendering functionality
#include "haloreach.render.inl"

//// log and text manipulation functionality
//#include "haloreach.log.inl"
//
//// game functionality
//#include "haloreach.game.inl"

// --- WORK IN PROGRESS BELOW ---


Pointer<HaloGameID::HaloReach_2019_Aug_20, _QWORD, 0x18306F898> qword_18306F898;

//FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x18008FC30, __int64()> network_update = []()
//{
//	return IGameEngineHost::GEHCBypass<IGameEngineHost::GEHCBypassType::UseValidPointer>(g_game_engine_host_pointer, network_update);
//};

FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x18090A0E0, __int64 __fastcall (PCSTR, unsigned __int16, char, SOCKET*)> sub_18090A0E0 = [](PCSTR pNodeName, unsigned __int16 a2, char a3, SOCKET* a4)
{
	return sub_18090A0E0(pNodeName, a2, a3, a4);
};

//FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x180100C90, void()> sub_180100C90 = []()
//{
//	auto callback = []() {
//		sub_180100C90();
//	};
//	return IGameEngineHost::GEHCBypass<IGameEngineHost::GEHCBypassType::UseNullPointer>(g_game_engine_host_pointer, callback);
//};
//
//FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x1800ADE20, void()> sub_1800ADE20 = []()
//{
//	auto callback = []() {
//		sub_1800ADE20();
//	};
//	return IGameEngineHost::GEHCBypass<IGameEngineHost::GEHCBypassType::UseNullPointer>(g_game_engine_host_pointer, callback);
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

void check_library_can_load(const char* pLibName, const char* pFallbackDir = "")
{
	HMODULE hModule = GetModuleHandleA(pLibName);
	if (!hModule)
	{
		hModule = LoadLibraryA(pLibName);

		// use fallback if 
		if (!hModule && pFallbackDir[0])
		{
			char fallbackPath[MAX_PATH] = {};
			sprintf(fallbackPath, "%s\\%s", pFallbackDir, pLibName);
			hModule = GetModuleHandleA(fallbackPath);
			if (!hModule)
			{
				hModule = LoadLibraryA(fallbackPath);
			}
		}
	}
	if (!hModule)
	{
		MessageBox(CustomWindow::GetWindowHandle(), pLibName, "failed to load library", MB_ICONERROR);
	}
	assert(hModule);
}


void set_player_name(int index)
{
	static wchar_t name[16] = L"";
	if (GetPrivateProfileStringW(L"Player", L"Name", L"Player", name, 16, L".\\Settings.ini") != 2)
	{
		if (wcsncmp(g_player_names[index], name, 16) == 0)
		{
			WriteLineVerbose("player[%d].Name already set", index);
			return;
		}
		wcsncpy_s(g_player_names[index], 32, name, 16);
		WriteLineVerbose("player[%d].Name: set %ls", index, name);
	}
}
void set_service_tag(int index)
{
	static wchar_t tag[5] = L"";
	if (GetPrivateProfileStringW(L"Player", L"ServiceTag", L"UNSC", tag, 5, L".\\Settings.ini") != 2)
	{
		if (wcsncmp(g_controller_interfaces[index].Profile.ServiceTag, tag, 5) == 0)
		{
			WriteLineVerbose("player[%d].Tag already set", index);
			return;
		}
		wcsncpy(g_controller_interfaces[index].Profile.ServiceTag, tag, 5);
		WriteLineVerbose("player[%d].Tag: set %ls", index, tag);
	}
}

void set_player_name_and_tag()
{
	int index = 0; // GetPrivateProfileIntW(L"Player", L"Index", 0, L".\\Settings.ini");

	if (g_player_names.ptr())
		set_player_name(index);

	if (g_controller_interfaces.ptr())
		set_service_tag(index);
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

	strcpy_s(g_LaunchMapName, sizeof(g_LaunchMapName), g_Config.ReadString("Launch", "Map", "ff45_corvette"));
	g_LaunchMapId = string_to_map_id(g_LaunchMapName);
	g_LaunchGameMode = string_to_game_mode(g_Config.ReadString("Launch", "GameMode", "survival"));
	g_LaunchCampaignDifficultyLevel = string_to_campaign_difficulty_level(g_Config.ReadString("Launch", "CampaignDifficultyLevel", "easy"));
	g_LaunchHopperGameVariant = g_Config.ReadString("Launch", "HopperGameVariant", "ff_gruntpocalypse_054");
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

void log_socket_info(struct sockaddr* from)
{
	if (!from)
	{
		return;
	}

	switch (from->sa_family)
	{
	case AF_INET:
	{
		sockaddr_in& sockaddr = *(sockaddr_in*)from;
		char* pIPv4 = inet_ntoa(sockaddr.sin_addr);
		WriteLineVerbose("IPv4 %s:%i", pIPv4, sockaddr.sin_port);
	}
	break;
	case AF_INET6:
	{
		sockaddr_in6& sockaddr6 = *(sockaddr_in6*)from;
		char IPv6[INET6_ADDRSTRLEN] = {};
		inet_ntop(AF_INET6, &sockaddr6.sin6_addr, IPv6, INET6_ADDRSTRLEN);
		WriteLineVerbose("IPv6 [%s]:%i", IPv6, sockaddr6.sin6_port);
	}
	break;
	}
}

typedef int(__stdcall recvfrom_Func)(
	_In_ SOCKET s,
	_Out_writes_bytes_to_(len, return) __out_data_source(NETWORK) char FAR* buf,
	_In_ int len,
	_In_ int flags,
	_Out_writes_bytes_to_opt_(*fromlen, *fromlen) struct sockaddr FAR* from,
	_Inout_opt_ int FAR* fromlen
	);
static recvfrom_Func* recvfromPointer;
int __stdcall recvfromHook(
	_In_ SOCKET s,
	_Out_writes_bytes_to_(len, return) __out_data_source(NETWORK) char FAR* buf,
	_In_ int len,
	_In_ int flags,
	_Out_writes_bytes_to_opt_(*fromlen, *fromlen) struct sockaddr FAR* from,
	_Inout_opt_ int FAR* fromlen
)
{
	sockaddr* pSocketAddressBuffer = (sockaddr*)alloca(32 * 1024);
	int length = 32 * 1024;
	memset(pSocketAddressBuffer, 0, length);
	getsockname(s, pSocketAddressBuffer, &length);
	log_socket_info(pSocketAddressBuffer);

	auto result = recvfromPointer(s, buf, len, flags, from, fromlen);

	if (result == -1)
	{
		wchar_t* errorMessage = NULL;
		FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, WSAGetLastError(),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPWSTR)& errorMessage, 0, NULL);

		LocalFree(errorMessage);

		return result;
	}

	log_socket_info(from);

	return result;
}

void init_haloreach_hooks()
{
	check_library_can_load("bink2w64.dll", "..\\MCC\\Binaries\\Win64");

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
	g_currentGameID = gameID;

	DataReferenceBase::ProcessTree(gameID);
	FunctionHookBase::ProcessTree(gameID);

	// #TODO: Remove this
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24:
		g_shell_command_line = GetCommandLineA();
		break;
	}

	//patch_out_gameenginehostcallback_mov(HaloGameID::HaloReach_2019_Aug_20, 0x1800AE684);
	//patch_out_gameenginehostcallback_mov(HaloGameID::HaloReach_2019_Aug_20, 0x180100D54);
	//patch_out_gameenginehostcallback_mov(HaloGameID::HaloReach_2019_Aug_20, 0x1800ADEFE);
	
		
	//create_dll_hook("WS2_32.dll", "recvfrom", recvfromHook, recvfromPointer);

	end_detours();
}


const char* game_mode_to_string(int game_mode)
{
	switch (game_mode)
	{
	case _game_mode_none:
		return "none";
	case _game_mode_campaign:
		return "campaign";
	case _game_mode_multiplayer:
		return "multiplayer";
	case _game_mode_survival:
		return "survival";
	}
	return "<unknown>";
}
e_game_mode string_to_game_mode(const char* string)
{
	int result = _game_mode_survival;
	for (int i = _game_mode_none; i < k_number_of_game_modes; i++)
	{
		if (strcmp(string, game_mode_to_string(i)) == 0)
			result = i;
	}
	return (e_game_mode)result;
}
const char* campaign_difficulty_level_to_string(int campaign_difficulty_level)
{
	switch (campaign_difficulty_level)
	{
	case _campaign_difficulty_level_easy:
		return "easy";
	case _campaign_difficulty_level_normal:
		return "normal";
	case _campaign_difficulty_level_heroic:
		return "heroic";
	case _campaign_difficulty_level_legendary:
		return "legendary";
	}
	return "<unknown>";
}
e_campaign_difficulty_level string_to_campaign_difficulty_level(const char* string)
{
	int result = _campaign_difficulty_level_normal;
	for (int i = _campaign_difficulty_level_easy; i < k_number_of_campaign_difficulty_levels; i++)
	{
		if (strcmp(string, campaign_difficulty_level_to_string(i)) == 0)
			result = i;
	}
	return (e_campaign_difficulty_level)result;
}
const char* map_id_to_string(int map_id)
{
	switch (map_id)
	{
	case _map_id_m05:
		return "m05";
	case _map_id_m10:
		return "m10";
	case _map_id_m20:
		return "m20";
	case _map_id_m30:
		return "m30";
	case _map_id_m35:
		return "m35";
	case _map_id_m45:
		return "m45";
	case _map_id_m50:
		return "m50";
	case _map_id_m52:
		return "m52";
	case _map_id_m60:
		return "m60";
	case _map_id_m70:
		return "m70";
	case _map_id_m70_a:
		return "m70_a";
	case _map_id_m70_bonus:
		return "m70_bonus";
	case _map_id_50_panopticon:
		return "50_panopticon";
	case _map_id_70_boneyard:
		return "70_boneyard";
	case _map_id_45_launch_station:
		return "45_launch_station";
	case _map_id_30_settlement:
		return "30_settlement";
	case _map_id_52_ivory_tower:
		return "52_ivory_tower";
	case _map_id_35_island:
		return "35_island";
	case _map_id_20_sword_slayer:
		return "20_sword_slayer";
	case _map_id_45_aftship:
		return "45_aftship";
	case _map_id_dlc_slayer:
		return "dlc_slayer";
	case _map_id_dlc_invasion:
		return "dlc_invasion";
	case _map_id_dlc_medium:
		return "dlc_medium";
	case _map_id_condemned:
		return "condemned";
	case _map_id_trainingpreserve:
		return "trainingpreserve";
	case _map_id_cex_beaver_creek:
		return "cex_beaver_creek";
	case _map_id_cex_damnation:
		return "cex_damnation";
	case _map_id_cex_timberland:
		return "cex_timberland";
	case _map_id_cex_prisoner:
		return "cex_prisoner";
	case _map_id_cex_hangemhigh:
		return "cex_hangemhigh";
	case _map_id_cex_headlong:
		return "cex_headlong";
	case _map_id_forge_halo:
		return "forge_halo";
	case _map_id_ff50_park:
		return "ff50_park";
	case _map_id_ff45_corvette:
		return "ff45_corvette";
	case _map_id_ff20_courtyard:
		return "ff20_courtyard";
	case _map_id_ff60_icecave:
		return "ff60_icecave";
	case _map_id_ff70_holdout:
		return "ff70_holdout";
	case _map_id_ff60_ruins:
		return "ff60_ruins";
	case _map_id_ff10_prototype:
		return "ff10_prototype";
	case _map_id_ff30_waterfront:
		return "ff30_waterfront";
	case _map_id_ff_unearthed:
		return "ff_unearthed";
	case _map_id_cex_ff_halo:
		return "cex_ff_halo";
	}
	return "<unknown>";
}
e_map_id string_to_map_id(const char* string)
{
	int result = _map_id_ff45_corvette;
	for (int i = _map_id_m05; i < k_number_of_map_ids; i++)
	{
		if (strcmp(string, map_id_to_string(i)) == 0)
			result = i;
	}
	return (e_map_id)result;
}