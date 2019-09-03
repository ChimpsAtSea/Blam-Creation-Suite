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

void init_halo_reach(HaloGameID gameID)
{
	g_currentGameID = gameID;

	init_detours();

	ReadConfig();

	DataReferenceBase::InitTree(gameID);
	FunctionHookBase::InitTree(gameID);
	
	CustomWindow::SetWindowTitle("Halo Reach");
	GameLauncher::RegisterTerminationValue(*reinterpret_cast<char*>(byte_183984DE4.ptr()));

	if (gameID == HaloGameID::HaloReach_2019_Jun_24)
	{
		g_shell_command_line = GetCommandLineA();
	}

	//patch_out_gameenginehostcallback_mov(HaloGameID::HaloReach_2019_Aug_20, 0x1800AE684);
	//patch_out_gameenginehostcallback_mov(HaloGameID::HaloReach_2019_Aug_20, 0x180100D54);
	//patch_out_gameenginehostcallback_mov(HaloGameID::HaloReach_2019_Aug_20, 0x1800ADEFE);
	//nop_address(HaloGameID::HaloReach_2019_Aug_20, 0x1800ADB4F, 6);
	int32_t host_wait_for_party_timeout = 45000000;
	copy_to_address(HaloGameID::HaloReach_2019_Aug_20, 0x180011090, &host_wait_for_party_timeout, sizeof(host_wait_for_party_timeout));
	copy_to_address(HaloGameID::HaloReach_2019_Aug_20, 0x180011431, &host_wait_for_party_timeout, sizeof(host_wait_for_party_timeout));
	copy_to_address(HaloGameID::HaloReach_2019_Aug_20, 0x180011458, &host_wait_for_party_timeout, sizeof(host_wait_for_party_timeout));

	end_detours();
}

void deinit_halo_reach(HaloGameID gameID)
{
	init_detours();

	FunctionHookBase::DeinitTree(gameID);
	DataReferenceBase::DeinitTree(gameID);
	
	end_detours();
}