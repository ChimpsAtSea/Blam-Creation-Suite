#include "haloreach-private-pch.h"

// Custom Engine Stuff
s_thread_local_storage ThreadLocalStorage;

// Custom Stuff


s_game_bindings g_GameBindings;
bool g_customBinds = false;
e_peer_property g_lastGameLoadStatus;
const char* g_lastGameLoadStatusStr;
const char* g_haloReachPathOverride = "";
bool g_gameManuallyKilled = false;
bool g_isHooked = false;
WORD g_frameLimit = 60;
int g_fieldOfView = 78;
int g_controlsLayout = 0;
int g_useController = 0;
bool g_pancamEnabled = false;
bool g_keyboardPrintKeyState = false;
HaloGameID g_currentGameID = HaloGameID::NotSet;



// Assembly hacks



void patch_out_gameenginehostcallback_mov_rcx(HaloGameID id, intptr_t offset)
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

void patch_out_gameenginehostcallback_mov_rsi(HaloGameID id, intptr_t offset)
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

	char bytes[] =
	{
		0x48i8, 0x31i8, 0xf6i8,	// xor rsi, rsi
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

intptr_t sub_1800AE4E0_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Aug_20: return 0x1800AE4E0;
	}
	return ~intptr_t();
}
FunctionHookEx<sub_1800AE4E0_offset, int __fastcall (__int64 a1, char* a2)> sub_1800AE4E0 = { "sub_1800AE4E0", [](__int64 a1, char* a2)
{
	auto v2 = a2;
	auto& v18 = *(_QWORD*)(v2 + 24);
	SWORD& v18sword = SWORD1(v18);
	v18sword = 4;
	auto result = sub_1800AE4E0(a1, a2);
	return result;
} };




// #TODO: Move inside of gamehostcallback
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
	ReadInputBindings();
}


void log_socket_info(const struct sockaddr* from, int bytes, const char* pPrefix, uint32_t packetID)
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
		u_short port = htons(sockaddr.sin_port);
		WriteVerbose("%s IPv4 %s:%i", pPrefix, pIPv4, port);
		if (bytes > 0)
		{
			if (bytes < 10)
			{
				WriteVerbose(" [0%i bytes]", bytes);
			}
			else
			{
				WriteVerbose(" [%i bytes]", bytes);
			}
		}
		if (packetID <= UINT16_MAX)
		{
			WriteVerbose(" id:%04x", packetID);
			WriteVerbose(" id:%u", packetID);
			WriteVerbose(" id_nbo:%04x", uint32_t(ntohs(packetID)));
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
		log_socket_info(name, 0, "bind", -1);
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

	uint32_t id = -1;
	if (result > 2)
	{
		id = *(unsigned __int16*)(buf);
	}
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

	log_socket_info(from, result, "recv", id);

	return result;
}

typedef
int
(WSAAPI sendtoFunc)(
	_In_ SOCKET s,
	_In_reads_bytes_(len) const char FAR* buf,
	_In_ int len,
	_In_ int flags,
	_In_reads_bytes_(tolen) const struct sockaddr FAR* to,
	_In_ int tolen
	);
sendtoFunc* sendtoPointer = nullptr;

int
sendtoHook(
	_In_ SOCKET s,
	_In_reads_bytes_(len) const char FAR* buf,
	_In_ int len,
	_In_ int flags,
	_In_reads_bytes_(tolen) const struct sockaddr FAR* to,
	_In_ int tolen
)
{
	uint32_t id = -1;
	if (len > 2)
	{
		id = *(unsigned __int16*)(buf);
	}

	auto result = sendtoPointer(s, buf, len, flags, to, tolen);
	log_socket_info(to, result, "send", id);
	return result;
}

Pointer<HaloGameID::HaloReach_2019_Aug_20, void*, 0x1830DC4E0> g_pNetworkSquadSession;
Data<HaloGameID::HaloReach_2019_Aug_20, c_network_session[4], 0x18324F378> g_networkSessions;

const char* network_session_state_to_string(e_network_session_state network_session_state)
{
	switch (network_session_state)
	{
	case _network_session_state_uninitialized:			return "_network_session_state_uninitialized";
	case _network_session_state_none:					return "_network_session_state_none";
	case _network_session_state_peer_creating:			return "_network_session_state_peer_creating";
	case _network_session_state_peer_joining:			return "_network_session_state_peer_joining";
	case _network_session_state_peer_join_abort:		return "_network_session_state_peer_join_abort";
	case _network_session_state_peer_peer_established:	return "_network_session_state_peer_peer_established";
	case _network_session_state_peer_leaving:			return "_network_session_state_peer_leaving";
	case _network_session_state_host_established:		return "_network_session_state_host_established";
	case _network_session_state_host_disband:			return "_network_session_state_host_disband";
	case _network_session_state_host_handoff:			return "_network_session_state_host_handoff";
	case _network_session_state_host_reestablish:		return "_network_session_state_host_reestablish";
	case _network_session_state_election:				return "_network_session_state_election";
	case _network_session_state_host_disconnected:		return "_network_session_state_host_disconnected";
	default:
		return "<unknown>";
		break;
	}
}

intptr_t sub_18006DAE0_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Aug_20: return 0x18006DAE0;
	}
	return ~intptr_t();
}
FunctionHookEx<sub_18006DAE0_offset, int __fastcall (c_network_session* a1, BOOL a2)> sub_18006DAE0 = { "sub_18006DAE0", [](c_network_session* a1, BOOL a2)
{
	auto result = sub_18006DAE0(a1, a2);
	return result;
} };


const char* ppNetworkSessionNames[] = { "Squad Session", "Posse Session", "Group Session", "Target Session" };

intptr_t c_network_session_abort_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Aug_20: return 0x18006CB40;
	}
	return ~intptr_t();
}
FunctionHookEx<c_network_session_abort_offset, __int64 __fastcall (c_network_session* a1)> c_network_session_abort = { "sub_18006CB40", [](c_network_session* _this)
{
	WriteLineVerbose("c_network_session_abort [%s]", ppNetworkSessionNames[_this->m_session_index]);
	auto result = c_network_session_abort(_this);
	return result;
} };

intptr_t c_network_session_handle_peer_joining_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Aug_20: return 0x18006DC10;
	}
	return ~intptr_t();
}
FunctionHookEx<c_network_session_handle_peer_joining_offset, void __fastcall (c_network_session* _this)> c_network_session_handle_peer_joining = { "c_network_session::handle_peer_joining", [](c_network_session* _this)
{
	//WriteLineVerbose("c_network_session_handle_peer_joining_offset [%s]", ppNetworkSessionNames[_this->m_session_index]);
	//_this->m_session_membership.m_baseline_update_number = 14;
	c_network_session_handle_peer_joining(_this);
} };

void halo_reach_debug_callback()
{
	ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(550, 680), ImGuiCond_FirstUseEver);

	// Main body of the Demo window starts here.
	static bool isReachDebugWindowOpen = true;
	if (!ImGui::Begin("Halo Reach Debug", &isReachDebugWindowOpen, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	ImGui::Columns(3, "g_networkSessions", false);
	ImGui::Separator();
	ImGui::Selectable("Session Name");
	ImGui::NextColumn();
	ImGui::Selectable("Address");
	ImGui::NextColumn();
	ImGui::Selectable("State");
	ImGui::NextColumn();
	for (int i = 0; i < 4; i++)
	{
		auto& rNetworkSession = g_networkSessions[i];
		auto pNetworkSessionName = ppNetworkSessionNames[i];
		const char* local_state_str = network_session_state_to_string(rNetworkSession.m_local_state);

		ImGui::Text(pNetworkSessionName);
		ImGui::NextColumn();
		ImGui::Text("0x%p", &rNetworkSession);
		ImGui::NextColumn();
		ImGui::Text(local_state_str);
		ImGui::NextColumn();
	}

	ImGui::PushID("g_networkSessions"); //Just to be sure !
	for (int i = 0; i < 4; i++)
	{
		auto& rNetworkSession = g_networkSessions[i];
		auto pNetworkSessionName = ppNetworkSessionNames[i];

		ImGui::PushID(i);
		if (ImGui::CollapsingHeader(pNetworkSessionName))
		{
			ImGui::Text("m_message_gateway: %p", rNetworkSession.m_message_gateway);
			ImGui::Text("m_observer: %p", rNetworkSession.m_observer);
			ImGui::Text("m_session_manager: %p", rNetworkSession.m_session_manager);
			ImGui::Text("ppSession: %p", rNetworkSession.ppSession);
			ImGui::Text("m_session_index: %i", rNetworkSession.m_session_index);
			ImGui::Text("m_session_type: %i", rNetworkSession.m_session_type);
			ImGui::Text("m_session_class: %i", rNetworkSession.m_session_class);
			ImGui::Text("unknown2C: %i", rNetworkSession.unknown2C);
			ImGui::Text("m_local_state: %i", rNetworkSession.m_local_state);
			ImGui::Text("m_managed_session_index: %i", rNetworkSession.m_managed_session_index);
			ImGui::Text("pSession: %p", rNetworkSession.pSession);
			
			if (ImGui::CollapsingHeader("m_session_parameters"))
			{
				auto& rSessionParameters = rNetworkSession.m_session_parameters;

				ImGui::Text("session: %p", rSessionParameters.session);
				ImGui::Text("observer: %p", rSessionParameters.observer);
				ImGui::Text("flags: 0x%08x", rSessionParameters.flags);
				ImGui::Text("initial_parameters_update_mask: 0x%08x", rSessionParameters.initial_parameters_update_mask);
			}
			if (ImGui::CollapsingHeader("m_session_membership"))
			{
				auto& rSessionMembership = rNetworkSession.m_session_membership;

				ImGui::Text("m_session: %p", rSessionMembership.m_session);
				ImGui::Text("m_baseline_update_number: %i", rSessionMembership.m_baseline_update_number); 
				ImGui::Text("m_leader_peer_index: %i", rSessionMembership.m_leader_peer_index);
				ImGui::Text("m_host_peer_index: %i", rSessionMembership.m_host_peer_index); 
				ImGui::Text("unknown14: %i", rSessionMembership.unknown14); 
				ImGui::Text("m_private_slot_count: %i", rSessionMembership.m_private_slot_count); 
				ImGui::Text("m_public_slot_count: %i", rSessionMembership.m_public_slot_count); 
				ImGui::Text("m_friends_only: %lli", rSessionMembership.m_friends_only); 
				ImGui::Text("m_peer_count: %i", rSessionMembership.m_peer_count);
				ImGui::Text("m_valid_peer_mask: %i", rSessionMembership.m_valid_peer_mask);
				ImGui::Text("m_player_count: %i", rSessionMembership.m_player_count); 
				ImGui::Text("m_valid_player_mask: %i", rSessionMembership.m_valid_player_mask);
				ImGui::Text("m_player_sequence_number: %i", rSessionMembership.m_player_sequence_number);
				ImGui::Text("unknown291C: %i", rSessionMembership.unknown291C); 
				ImGui::Text("m_incremental_updates: %i", rSessionMembership.m_incremental_updates);
				ImGui::Text("unknown5240: %i", rSessionMembership.unknown5240); 
				ImGui::Text("m_local_peer_index: %i", rSessionMembership.m_local_peer_index);

				if (ImGui::CollapsingHeader("m_peers"))
				{
					auto& rPeers = rSessionMembership.m_peers;
					for (int i = 0; i < __min(rSessionMembership.m_peer_count, _countof(rPeers)); i++)
					{
						ImGui::Text("machine_identifier: %llu", rPeers[i].machine_identifier);
						ImGui::Text("unknown8: %u", rPeers[i].unknown8);
					}
				}
				if (ImGui::CollapsingHeader("m_players"))
				{
					auto& rPlayers = rSessionMembership.m_players;
					for (int i = 0; i < __min(rSessionMembership.m_player_count, _countof(rPlayers)); i++)
					{
						ImGui::Text("desired_configuration_version: %i", rPlayers[i].desired_configuration_version);
						ImGui::Text("player_identifier: %llu", rPlayers[i].player_identifier);
						ImGui::Text("peer_index: %i", rPlayers[i].peer_index);
					}
				}
			}
		}
		ImGui::PopID();
	}
	ImGui::PopID();

	ImGui::End();
}

void init_halo_reach(HaloGameID gameID)
{
	g_currentGameID = gameID;
	CustomWindow::SetWindowTitle("Halo Reach");
	GameLauncher::RegisterTerminationValue(*reinterpret_cast<char*>(byte_183984DE4.ptr()));
	ReadConfig();
	DebugUI::RegisterCallback(halo_reach_debug_callback);

	init_detours();

	if (gameID == HaloGameID::HaloReach_2019_Jun_24)
	{
		g_shell_command_line = GetCommandLineA();
	}

	bool isNetworkingPatchActive = true;
	if (isNetworkingPatchActive)
	{
		patch_out_gameenginehostcallback_mov_rcx(HaloGameID::HaloReach_2019_Aug_20, 0x1800AE684);
		patch_out_gameenginehostcallback_mov_rcx(HaloGameID::HaloReach_2019_Aug_20, 0x180100D54);
		patch_out_gameenginehostcallback_mov_rcx(HaloGameID::HaloReach_2019_Aug_20, 0x1800ADEFE);
		//patch_out_gameenginehostcallback_mov_rsi(HaloGameID::HaloReach_2019_Aug_20, 0x18002350D); // patch for sub_1800234F0 to bypass member25
		nop_address(HaloGameID::HaloReach_2019_Aug_20, 0x1800ADB4F, 6);
		int32_t host_wait_for_party_timeout = 45000000;
		copy_to_address(HaloGameID::HaloReach_2019_Aug_20, 0x180011090, &host_wait_for_party_timeout, sizeof(host_wait_for_party_timeout));
		copy_to_address(HaloGameID::HaloReach_2019_Aug_20, 0x180011431, &host_wait_for_party_timeout, sizeof(host_wait_for_party_timeout));
		copy_to_address(HaloGameID::HaloReach_2019_Aug_20, 0x180011458, &host_wait_for_party_timeout, sizeof(host_wait_for_party_timeout));

		create_dll_hook("WS2_32.dll", "recvfrom", recvfromHook, recvfromPointer);
		create_dll_hook("WS2_32.dll", "bind", bindHook, bindPointer);
		create_dll_hook("WS2_32.dll", "sendto", sendtoHook, sendtoPointer);
	}
	sub_1800AE4E0.SetIsActive(isNetworkingPatchActive);

	DataReferenceBase::InitTree(gameID);
	FunctionHookBase::InitTree(gameID);
	end_detours();
}

void deinit_halo_reach(HaloGameID gameID)
{
	init_detours();

	FunctionHookBase::DeinitTree(gameID);
	DataReferenceBase::DeinitTree(gameID);

	end_detours();
}