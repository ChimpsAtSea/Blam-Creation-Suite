#include "haloreach-private-pch.h"

#define this _this

void nullsub()
{
}

HMODULE HaloReach; //haloreach.dll

typedef errno_t(__fastcall* SetLibrarySettingsFunc)(wchar_t* Src);
SetLibrarySettingsFunc* SetLibrarySettings = nullptr;
typedef signed __int64(__fastcall CreateGameEngineFunc)(IGameEngine** ppGameEngine);
CreateGameEngineFunc* CreateGameEngine = nullptr;
typedef __int64(__fastcall CreateDataAccessFunc)(IDataAccess** ppDataAccess);
CreateDataAccessFunc* CreateDataAccess = nullptr;


IGameEngine* pHaloReachEngine = nullptr;
IDataAccess* pHaloReachDataAccess = nullptr;


#define NULLSUB_LAMBDA_LOG(message) []() { WriteLineVerbose(message); }
#define NULLSUB_LAMBDA(message) nullsub

typedef __int64(ZeroSubFunc)();
#define ZEROSUB_LAMBDA(message) (NullSubFunc*)(ZeroSubFunc*)[]() { WriteLineVerbose(message " <zerosub>"); return __int64(0);  }



void load_haloreach_dll()
{
	HaloReach = LoadLibraryA("haloreach.dll");
	if (HaloReach == nullptr)
	{
		WriteLineVerbose("Failed to load haloreach.dll");
	}
	assert(HaloReach);
	WriteLineVerbose("haloreach.dll: 0x%p", HaloReach);

	CreateGameEngine = (CreateGameEngineFunc*)GetProcAddress(HaloReach, "CreateGameEngine");
	CreateDataAccess = (CreateDataAccessFunc*)GetProcAddress(HaloReach, "CreateDataAccess");

	SetLibrarySettings = (SetLibrarySettingsFunc*)GetProcAddress(HaloReach, "SetLibrarySettings");
}

FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x180021810, char __fastcall (char*, int, s_game_variant*)> sub_180021810 = [](char* file_data, int file_length, s_game_variant* game_variant)
{
	return sub_180021810(file_data, file_length, game_variant);
};

size_t get_file_size(FILE* pFile)
{
	assert(pFile);
	fseek(pFile, 0, SEEK_END);
	size_t variantSize = ftell(pFile);
	fseek(pFile, 0L, SEEK_SET);
	return variantSize;
}

void read_file_to_buffer(FILE* pFile, char* pBuffer, size_t length)
{
	assert(pFile);
	fseek(pFile, 0L, SEEK_SET);

	size_t totalBytesRead = 0;
	do
	{
		size_t bytesToRead = length - totalBytesRead;
		fseek(pFile, static_cast<long>(totalBytesRead), SEEK_SET);
		size_t bytesRead = fread(pBuffer + totalBytesRead, 1, bytesToRead, pFile);;
		totalBytesRead += bytesRead;
	} while (totalBytesRead < length);

}

void load_hopper_map_variant(const char* pHopperGameVariantName, s_map_variant& out_map_variant)
{
	char pFilename[MAX_PATH] = {};
	sprintf(pFilename, "hopper_map_variants\\%s", pHopperGameVariantName);
	pFilename[MAX_PATH - 1] = 0;

	FILE* pVariantFile = fopen(pFilename, "rb");
	if (pVariantFile)
	{
		size_t variantSize = get_file_size(pVariantFile);
		char* pVariantBuffer = (char*)alloca(variantSize);
		memset(pVariantBuffer, 0x00, variantSize);
		read_file_to_buffer(pVariantFile, pVariantBuffer, variantSize);
		fclose(pVariantFile);

		__int64 result = pHaloReachDataAccess->CreateMapVariantFromFile(pVariantBuffer, static_cast<int>(variantSize));

		// #TODO: MCC STRUCTURE FOR THIS
		// #TODO: First 8 bytes appear to be a pointer to something in base game
		s_map_variant* variant = (s_map_variant*)(result + 8);

		out_map_variant = *variant;
	}
}

void load_hopper_game_variant(const char* pHopperGameVariantName, s_game_variant& out_game_variant)
{
	char pFilename[MAX_PATH] = {};
	sprintf(pFilename, "hopper_game_variants\\%s.bin", pHopperGameVariantName);
	pFilename[MAX_PATH - 1] = 0;

	FILE* pVariantFile = fopen(pFilename, "rb");
	if (pVariantFile)
	{
		size_t variantSize = get_file_size(pVariantFile);
		char* pVariantBuffer = (char*)alloca(variantSize);
		memset(pVariantBuffer, 0x00, variantSize);
		read_file_to_buffer(pVariantFile, pVariantBuffer, variantSize);
		fclose(pVariantFile);

		__int64 result = pHaloReachDataAccess->CreateGameVariantFromFile(pVariantBuffer, static_cast<int>(variantSize));

		// #TODO: MCC STRUCTURE FOR THIS
		// #TODO: First 8 bytes appear to be a pointer to something in base game
		s_game_variant* variant = (s_game_variant*)(result + 8);

		out_game_variant = *variant;
	}
}

void load_previous_gamestate(const char* pFilename, s_game_launch_data& game_launch_data)
{
	FILE* pGameStateFile = fopen(pFilename, "rb");
	if (pGameStateFile)
	{
		size_t gameStateSize = get_file_size(pGameStateFile);
		char* pGameStateBuffer = (char*)alloca(gameStateSize);
		memset(pGameStateBuffer, 0x00, gameStateSize);
		read_file_to_buffer(pGameStateFile, pGameStateBuffer, gameStateSize);
		fclose(pGameStateFile);

		game_launch_data.pGameStateHeader = reinterpret_cast<uint8_t*>(&pGameStateBuffer);
		game_launch_data.GameStateHeaderSize = gameStateSize;
	}
}

s_game_launch_data game_launch_data = {};

void initialize_custom_halo_reach_stuff()
{
	load_haloreach_dll();

	IGameEngineHost::g_enableGameEngineHostOverride = true;
	g_useCustomGameWindow = true;
	init_haloreach_hooks();

	__int64 createGameEngineResult = CreateGameEngine(&pHaloReachEngine);
	assert(pHaloReachEngine);
	__int64 createDataAccessResult = CreateDataAccess(&pHaloReachDataAccess);
	assert(pHaloReachDataAccess);

	game_launch_data = {};
	game_launch_data.pGameHandle = GetModuleHandle("HaloReach.dll");
	char byte2B678Data[] = { 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	memcpy(game_launch_data.byte2B678, byte2B678Data, sizeof(byte2B678Data)); // what the hell is this?

	{
		uint64_t SquadID = 0x2F385E2E95D4F33E;
		uint64_t HostId = 0x7F7F86B0EE577202;
		uint64_t ClientId = 0x7F7Faf4521cdad53;

		game_launch_data.PartyData.SquadId = SquadID; // this is set
		game_launch_data.PartyData.IsHost = strstr(GetCommandLineA(), "-host"); // if client, is false

		int localhost = inet_addr("127.0.0.1");
		if (game_launch_data.PartyData.IsHost)
		{
			IGameEngineHost::CreateServerConnection();

			SetConsoleTitleA("Halo Reach Console | HOST");
			game_launch_data.PartyData.LocalId = HostId; // this is set
			game_launch_data.PartyData.PeerIds[0] = HostId;
			game_launch_data.PartyData.PeerIds[1] = ClientId;
			game_launch_data.PartyData.PeerCount = 1;

			game_launch_data.PartyData.PlayerIds[0] = { 0x0009000002D75AC8, 0x00000000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
			game_launch_data.PartyData.PlayerIds[1] = { 0x000901FE31A851C0, 0x00000000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };


			game_launch_data.PartyData.PlayerCount = 1;

			game_launch_data.MapId = g_LaunchMapId;
			game_launch_data.GameMode = g_LaunchGameMode;
			game_launch_data.CampaignDifficultyLevel = g_LaunchCampaignDifficultyLevel;

			load_hopper_game_variant(g_LaunchHopperGameVariant, *reinterpret_cast<s_game_variant*>(game_launch_data.GameVariantBuffer));
			//load_hopper_map_variant("the_cage.mvar", game_launch_data.halo_reach_map_variant);
			load_previous_gamestate("gamestate.hdr", game_launch_data);
		}
		else
		{
			IGameEngineHost::CreateClientConnection();

			game_launch_data.PartyData.LocalId = ClientId; // this is set
			game_launch_data.PartyData.HostId = HostId;
		}
	}

	//pHaloReachEngine->InitGraphics(0, 0, 0, 0); // #TODO: Correct MCC graphics initialization
	pHaloReachEngine->InitThread(&IGameEngineHost::g_gameEngineHost, &game_launch_data);
}

void deinit_haloreach()
{
	FreeLibrary(HaloReach);
}

HICON g_icon = NULL;

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	WSADATA wsaData = {};
	// Initialize Winsock
	auto WSAStartupResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (WSAStartupResult != 0) {
		printf("WSAStartup failed with error: %d\n", WSAStartupResult);
		return 1;
	}

	g_icon = LoadIconA(GetModuleHandle(NULL), MAKEINTRESOURCEA(IDI_ICON1));
	SetProcessDPIAware();

	CustomWindow::SetOnDestroyCallback([]()
		{
			byte_183984DE4 = 1;
			g_gameManuallyKilled = true;
		}
	);

#if _DEBUG
	bool isDebug = true;
#else
	bool isDebug = false;
#endif

	if (strstr(lpCmdLine, "-hidesplash") == nullptr)
	{
		SplashScreen::Create();
		g_hideWindowOnStartup = true;
	}

	if (strstr(lpCmdLine, "-showconsole") || isDebug)
	{
		AllocConsole();
		FILE* pStdOut = freopen("CONOUT$", "w", stdout);
		assert(pStdOut);
		SetConsoleTitleA("Halo Reach Console");
	}

	if (strstr(lpCmdLine, "-waitfordebugger"))
	{
		WriteLineVerbose("Waiting for debugger to attach");
		while (!IsDebuggerPresent()) { Sleep(1); }
		WriteLineVerbose("Debugger attached");
	}

	initialize_custom_halo_reach_stuff();

	while (g_CurrentGameState != CurrentState::eFinished)
	{
		Sleep(10);
	}

#if _DEBUG
	while (g_gameManuallyKilled == false)
	{
		if (GetAsyncKeyState(VK_F11))
		{
			g_gameManuallyKilled = true;
		}
	}
#endif

	return 0;
}