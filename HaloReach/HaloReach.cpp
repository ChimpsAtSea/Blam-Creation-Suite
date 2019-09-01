#include "haloreach-private-pch.h"

// Custom Engine Stuff
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

void nop_address(HaloGameID id, intptr_t offset, size_t count)
{
	char* pBeginning = (char*)GetHaloExecutable(id);
	char* pNopAttack = pBeginning + (offset - 0x180000000);

	char nop = 0x90i8;
	for (int i = 0; i < count; i++)
	{
		memcpy_virtual(pNopAttack + i, &nop, 1);
	}
}

void copy_to_address(HaloGameID id, intptr_t offset, void* data, size_t length)
{
	char* pBeginning = (char*)GetHaloExecutable(id);
	char* pDataAttack = pBeginning + (offset - 0x180000000);

	memcpy_virtual(pDataAttack, data, length);
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
FunctionHookEx<wait_for_render_thread_offset, __int64()> wait_for_render_thread;

intptr_t restricted_region_unlock_primary_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1803FB790;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x1802041F0;
	}
	return ~intptr_t();
}
FunctionHookEx<restricted_region_unlock_primary_offset, __int64(int a1)> restricted_region_unlock_primary;

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

//FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x1800ADAB0, __int64 __fastcall (int a1, __int16 a2, char a3, __int64* a4)> sub_1800ADAB0 = [](int a1, __int16 a2, char a3, __int64* a4)
//{
//	return IGameEngineHost::GEHCBypass<IGameEngineHost::GEHCBypassType::UseNullPointer>(g_game_engine_host_pointer, [=]()
//		{
//			return sub_1800ADAB0(a1, a2, a3, a4);
//		});
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

struct struct_v4
{
	SOCKET socket;
	_DWORD dword8;
	_DWORD dwordC;
	_DWORD dword10;
	_WORD word14;
	_WORD port;
};
static_assert(sizeof(struct_v4) == 0x18, "");


FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x1800ADAB0, bool __fastcall (int, __int16, char, struct_v4*&)> create_endpoint = [](int a1, __int16 port, char a3, struct_v4*& transport_endpoint_out)
{
	auto result = create_endpoint(a1, port, a3, transport_endpoint_out);
	return result;
};

Pointer<HaloGameID::HaloReach_2019_Aug_20, _QWORD, 0x18393C028> qword_18393C028;


FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x180492500, char __fastcall (__int64 a1, __int64 a2, PeerUUID* squadAddr, PeerUUID* hostAddr, void* a5)> join_party = [](__int64 a1, __int64 a2, PeerUUID* squadAddr, PeerUUID* hostAddr, void* a5)
{
	auto result = join_party(a1, a2, squadAddr, hostAddr, a5);
	return result;
};

FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x180031CE0, char __fastcall (__int64, char, char, char, __int64, PeerUUID*, void*, PeerUUID*)> network_join_to_remote_squad = [](__int64 a1, char a2, char a3, char a4, __int64 a5, PeerUUID* squadAddr, void* a7, PeerUUID* hostAddr)
{
	auto result = network_join_to_remote_squad(a1, a2, a3, a4, a5, squadAddr, a7, hostAddr);
	return result;
};

class c_network_session;
#define join_remote_session_args c_network_session *_this, unsigned __int8 a2, unsigned int a3, unsigned int a4, _QWORD *a5, _OWORD *a6, PeerUUID *a7, __int64 a8, _DWORD *a9, __int128 *a10, __int64 a11, int a12, char a13
FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x180028150, char __fastcall (join_remote_session_args)> join_remote_session = [](join_remote_session_args)
{
	auto result = join_remote_session(_this, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
	return result;
};

#define managed_session_create_host_args c_network_session* _this, unsigned __int8 a2, int a3, unsigned int a4, PeerUUID* squadAddr, _OWORD* a6, PeerUUID* hostAddr, __int64 a8, __int64 a9, __int64 a10, void* a11, int a12
FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x1800288B0, __int64 __fastcall (managed_session_create_host_args)> managed_session_create_host = [](managed_session_create_host_args)
{
	auto result = managed_session_create_host(_this, a2, a3, a4, squadAddr, a6, hostAddr, a8, a9, a10, a11, a12);
	return result;
};

FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x18002AD80, __int64 __fastcall (_DWORD* a1, int a2, _QWORD* a3, int a4, int a5, __int64 a6, __int128* a7)> peer_request_player_add = [](_DWORD* a1, int a2, _QWORD* a3, int a4, int a5, __int64 a6, __int128* a7)
{
	WriteLineVerbose("peer_request_player_add");
	auto result = peer_request_player_add(a1, a2, a3, a4, a5, a6, a7);
	return result;
};


//class c_network_session;
//FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x18005CE70, c_network_session* __fastcall (c_network_session** a1, _QWORD* a2)> squad_in_session = [](c_network_session** a1, _QWORD* a2)
//{
//	auto result = squad_in_session(a1, a2);
//	
//	WriteLineVerbose("squad_in_session: %s", result ? "true" : "false");
//
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

void set_service_tag(int index)
{
	if (g_controller_interfaces.ptr())
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
}

void ReadConfig()
{
	g_frameLimit = Settings::ReadIntegerValue(SettingsSection::Game, "FrameLimit", 60);
	g_fieldOfView = Settings::ReadIntegerValue(SettingsSection::Camera, "FieldOfView", 78);
	g_controlsLayout = Settings::ReadIntegerValue(SettingsSection::Player, "ControlsLayout", 0);
	g_pancamEnabled = Settings::ReadBoolValue(SettingsSection::Debug, "PancamEnabled", false);
	g_keyboardPrintKeyState = Settings::ReadBoolValue(SettingsSection::Debug, "PrintKeyState", 0);
	g_useController = Settings::ReadIntegerValue(SettingsSection::Player, "UseController", 0);

	char pLaunchMapNameBuffer[256] = {};
	Settings::ReadStringValue(SettingsSection::Launch, "Map", pLaunchMapNameBuffer, sizeof(pLaunchMapNameBuffer), "ff45_corvette");
	g_LaunchMapId = string_to_map_id(pLaunchMapNameBuffer);

	ReadInputBindings();

	char pLaunchGameModeBuffer[256] = {};
	Settings::ReadStringValue(SettingsSection::Launch, "GameMode", pLaunchGameModeBuffer, sizeof(pLaunchGameModeBuffer), "survival");
	g_LaunchGameMode = string_to_game_mode(pLaunchGameModeBuffer);

	char pLaunchCampaignDifficultyLevelBuffer[256] = {};
	Settings::ReadStringValue(SettingsSection::Launch, "DifficultyLevel", pLaunchCampaignDifficultyLevelBuffer, sizeof(pLaunchCampaignDifficultyLevelBuffer), "normal");
	g_LaunchCampaignDifficultyLevel = string_to_campaign_difficulty_level(pLaunchCampaignDifficultyLevelBuffer);

	// #TODO: This must persist outside of the read
	static char pLaunchHopperGameVariantBuffer[256] = {};
	Settings::ReadStringValue(SettingsSection::Launch, "HopperGameVariant", pLaunchHopperGameVariantBuffer, sizeof(pLaunchHopperGameVariantBuffer), "ff_gruntpocalypse_054");
	g_LaunchHopperGameVariant = pLaunchHopperGameVariantBuffer;
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

		if (GetFileVersionInfo(pFilename, NULL, verSize, verData) != 0)
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

void log_socket_info(const struct sockaddr* from, int bytes = 0)
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
		WriteVerbose("IPv4 %s:%i", pIPv4, sockaddr.sin_port);
		if (bytes > 0)
		{
			WriteVerbose(" [%i bytes]", bytes);
		}
		WriteLineVerbose("");
	}
	break;
	case AF_INET6:
	{
		sockaddr_in6& sockaddr6 = *(sockaddr_in6*)from;
		char IPv6[INET6_ADDRSTRLEN] = {};
		inet_ntop(AF_INET6, &sockaddr6.sin6_addr, IPv6, INET6_ADDRSTRLEN);
		WriteVerbose("IPv6 [%s]:%i", IPv6, sockaddr6.sin6_port);
		if (bytes > 0)
		{
			WriteVerbose(" [%i bytes]", bytes);
		}
		WriteLineVerbose("");
	}
	break;
	}
}


typedef int (WSAAPI bindFunc)(
	_In_ SOCKET s,
	_In_reads_bytes_(namelen) const struct sockaddr FAR* name,
	_In_ int namelen
	);
static bindFunc* bindPointer;
int WSAAPI bindHook(
	_In_ SOCKET s,
	_In_reads_bytes_(namelen) const struct sockaddr FAR* name,
	_In_ int namelen
)
{
	sockaddr_in& in = *(sockaddr_in*)name;
	__int64 x = __ROR2__(in.sin_port, 8);
	{
		log_socket_info(name);
	}
	return bindPointer(s, name, namelen);
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
	auto result = recvfromPointer(s, buf, len, flags, from, fromlen);

	//if (result > 0)
	//{
	//	{
	//		sockaddr* pSocketAddressBuffer = (sockaddr*)alloca(32 * 1024);
	//		int length = 32 * 1024;
	//		memset(pSocketAddressBuffer, 0, length);
	//		getsockname(s, pSocketAddressBuffer, &length);
	//		log_socket_info(pSocketAddressBuffer);
	//	}

	//	{
	//		sockaddr* pSocketAddressBuffer = (sockaddr*)alloca(32 * 1024);
	//		int length = 32 * 1024;
	//		memset(pSocketAddressBuffer, 0, length);
	//		getpeername(s, pSocketAddressBuffer, &length);
	//		log_socket_info(pSocketAddressBuffer);
	//	}
	//}

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
	//nop_address(HaloGameID::HaloReach_2019_Aug_20, 0x1800ADB4F, 6);
	int32_t host_wait_for_party_timeout = 45000000;
	copy_to_address(HaloGameID::HaloReach_2019_Aug_20, 0x180011090, &host_wait_for_party_timeout, sizeof(host_wait_for_party_timeout));
	copy_to_address(HaloGameID::HaloReach_2019_Aug_20, 0x180011431, &host_wait_for_party_timeout, sizeof(host_wait_for_party_timeout));
	copy_to_address(HaloGameID::HaloReach_2019_Aug_20, 0x180011458, &host_wait_for_party_timeout, sizeof(host_wait_for_party_timeout));
	

	//create_dll_hook("WS2_32.dll", "recvfrom", recvfromHook, recvfromPointer);
	create_dll_hook("WS2_32.dll", "bind", bindHook, bindPointer);

	end_detours();
}
