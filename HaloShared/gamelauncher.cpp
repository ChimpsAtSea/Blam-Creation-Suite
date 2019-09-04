#include "haloshared-private-pch.h"

#define MAKE_FILE_VERSION(a, b, c, d) ((uint64_t(a) << 48) | (uint64_t(b) << 32) | (uint64_t(c) << 16) | (uint64_t(d) << 0))

bool GameLauncher::s_gameManuallyKilled = false;
bool GameLauncher::s_hideWindowOnStartup = false;
GameLauncher::CurrentState GameLauncher::s_currentGameState = GameLauncher::CurrentState::eInactive;
GameLauncher::GameLaunchCallback* GameLauncher::s_gameLaunchCallback = nullptr;
GameLauncher::GameShutdownCallback* GameLauncher::s_gameShutdownCallback;

char* GameLauncher::s_pTerminationFlag = nullptr;

e_map_id g_LaunchMapId = _map_id_ff45_corvette;
e_game_mode g_LaunchGameMode = _game_mode_survival;
e_campaign_difficulty_level g_LaunchCampaignDifficultyLevel = _campaign_difficulty_level_normal;
const char* g_LaunchHopperGameVariant = nullptr;
const char* g_LaunchHopperMapVariant = nullptr;

typedef BOOL(EnumWindowsFunc)(WNDENUMPROC lpEnumFunc, LPARAM lParam);
EnumWindowsFunc* EnumWindowsPointer = nullptr;
BOOL EnumWindowsHook(
	WNDENUMPROC lpEnumFunc,
	LPARAM      lParam
)
{
	static thread_local WNDENUMPROC s_lpEnumFunc = nullptr;
	static thread_local bool s_processedCustomWindow = false;

	assert(s_lpEnumFunc == nullptr);
	assert(EnumWindowsPointer != nullptr);

	s_lpEnumFunc = lpEnumFunc;

	auto callback = [](HWND hWnd, LPARAM lParam) {

		bool isExcluded = false;
		isExcluded |= hWnd == GetConsoleWindow();
		isExcluded |= hWnd == SplashScreen::GetWindowHandle();

		if (hWnd == CustomWindow::GetWindowHandle())
		{
			s_processedCustomWindow = true;
		}

		if (isExcluded)
		{
			return TRUE;
		}

		return s_lpEnumFunc(hWnd, lParam);
	};

	auto result = EnumWindowsPointer(callback, lParam);
	s_lpEnumFunc = nullptr;
	return result;
}

void GameLauncher::Init(HINSTANCE hInstance, LPSTR lpCmdLine)
{

#if _DEBUG
	bool isDebug = true;
#else
	bool isDebug = false;
#endif

	if (strstr(lpCmdLine, "-hidesplash") == nullptr)
	{
		SplashScreen::Create();
		s_hideWindowOnStartup = true;
	}

	if ((strstr(lpCmdLine, "-showconsole") || isDebug) && !strstr(lpCmdLine, "-hideconsole"))
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

	static bool patchedEnumWindows = false;
	if (!patchedEnumWindows)
	{
		init_detours();
		create_dll_hook("USER32.dll", "EnumWindows", EnumWindowsHook, EnumWindowsPointer);
		patchedEnumWindows = true;
		end_detours();
	}

	IGameEngineHost::g_enableGameEngineHostOverride = true;
	CustomWindow::Init();
	GameRender::Init(); 
	MouseInput::Init(hInstance);
	InitSockets();

	CustomWindow::SetOnDestroyCallback(GameLauncher::Terminate);
}

void GameLauncher::Deinit()
{
	DeinitSockets();
	MouseInput::Deinit();
	GameRender::Deinit();
	CustomWindow::Deinit();

	// when debugging make sure to manually quit the game
	// this keeps the console window open
#if _DEBUG
	while (s_gameManuallyKilled == false)
	{
		if (GetAsyncKeyState(VK_F11))
		{
			s_gameManuallyKilled = true;
		}
	}
#endif
}

void GameLauncher::RegisterTerminationValue(char& rTerminationReference)
{
	s_pTerminationFlag = &rTerminationReference;
}

void GameLauncher::Terminate()
{
	if (s_pTerminationFlag != nullptr)
	{
		*s_pTerminationFlag = true;
		s_gameManuallyKilled = true;
	}
}

void GameLauncher::RegisterGameLaunchCallback(HaloGameID gameID, GameLaunchCallback gameLaunchCallback)
{
	// #TODO: Multiple game versions!!!
	s_gameLaunchCallback = gameLaunchCallback;
}

void GameLauncher::RegisterGameShutdownCallback(HaloGameID gameID, GameShutdownCallback gameShutdownCallback)
{
	s_gameShutdownCallback = gameShutdownCallback;
}

void GameLauncher::LoadSettings()
{
	char pLaunchMapNameBuffer[256] = {};
	Settings::ReadStringValue(SettingsSection::Launch, "Map", pLaunchMapNameBuffer, sizeof(pLaunchMapNameBuffer), "ff45_corvette");
	g_LaunchMapId = string_to_map_id(pLaunchMapNameBuffer);

	char pLaunchGameModeBuffer[256] = {};
	Settings::ReadStringValue(SettingsSection::Launch, "GameMode", pLaunchGameModeBuffer, sizeof(pLaunchGameModeBuffer), "");
	g_LaunchGameMode = string_to_game_mode(pLaunchGameModeBuffer);

	char pLaunchCampaignDifficultyLevelBuffer[256] = {};
	Settings::ReadStringValue(SettingsSection::Launch, "DifficultyLevel", pLaunchCampaignDifficultyLevelBuffer, sizeof(pLaunchCampaignDifficultyLevelBuffer), "normal");
	g_LaunchCampaignDifficultyLevel = string_to_campaign_difficulty_level(pLaunchCampaignDifficultyLevelBuffer);

	const char* pDefaultHopperGameVariant = "";
	switch (g_LaunchGameMode)
	{
		break;
	case _game_mode_campaign:
		pDefaultHopperGameVariant = "campaign_default_054";
		break;
	case _game_mode_multiplayer:
		pDefaultHopperGameVariant = "slayer_054";
		break;
	case _game_mode_survival:
		pDefaultHopperGameVariant = "ff_firefight_054";
		break;
	}

	// #TODO: This must persist outside of the read
	static char pLaunchHopperGameVariantBuffer[256] = {};
	uint32_t LaunchHopperGameVariantLength = Settings::ReadStringValue(SettingsSection::Launch, "HopperGameVariant", pLaunchHopperGameVariantBuffer, sizeof(pLaunchHopperGameVariantBuffer), pDefaultHopperGameVariant);
	if (LaunchHopperGameVariantLength > 0)
	{
		g_LaunchHopperGameVariant = pLaunchHopperGameVariantBuffer;
	}
	else
	{
		g_LaunchHopperGameVariant = nullptr;
	}

	// #TODO: This must persist outside of the read
	static char pLaunchHopperMapVariantBuffer[256] = {};
	uint32_t LaunchHopperMapVariantLength = Settings::ReadStringValue(SettingsSection::Launch, "HopperMapVariant", pLaunchHopperMapVariantBuffer, sizeof(pLaunchHopperMapVariantBuffer), "");
	if (LaunchHopperMapVariantLength > 0)
	{
		g_LaunchHopperMapVariant = pLaunchHopperMapVariantBuffer;
	}
	else
	{
		g_LaunchHopperMapVariant = nullptr;
	}
}

void GameLauncher::LaunchGame(const char* pGameLibrary)
{
	LoadSettings(); // #TODO: Replace with UI

	s_currentGameState = CurrentState::eInactive;

	GameInterface gameInterface = GameInterface(pGameLibrary);
	HaloGameID gameID = GetLibraryHaloGameID(pGameLibrary);

	// #TODO: Game specific version of this!!!
	if (s_gameLaunchCallback != nullptr)
	{
		s_gameLaunchCallback(gameID);
	}

	IGameEngine* pHaloReachEngine = nullptr;
	IDataAccess* pHaloReachDataAccess = nullptr;

	__int64 createGameEngineResult = gameInterface.CreateGameEngine(&pHaloReachEngine);
	__int64 createDataAccessResult = gameInterface.CreateDataAccess(&pHaloReachDataAccess);

	assert(pHaloReachEngine);
	assert(pHaloReachDataAccess);

	s_game_launch_data game_launch_data = {};
	game_launch_data.pGameHandle = GetModuleHandle("HaloReach.dll");
	char byte2B678Data[] = { 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	memcpy(game_launch_data.byte2B678, byte2B678Data, sizeof(byte2B678Data)); // what the hell is this?

	{
		uint64_t SquadAddress = 0x2F385E2E95D4F33E;
		uint64_t HostAddress = 0xDEADBEEFDEADBEEF;
		uint64_t ClientAddress = 0xCAFEBABECAFEBABE;

		{
			int ipv4_address = 0;
			inet_pton(AF_INET, "10.255.0.2", &ipv4_address);
			ipv4_address = htonl(ipv4_address);
			ClientAddress = ipv4_address;
		}
		{
			int ipv4_address = 0;
			inet_pton(AF_INET, "10.255.0.1", &ipv4_address);
			ipv4_address = htonl(ipv4_address);
			HostAddress = ipv4_address;
		}

		game_launch_data.SessionInfo.SquadAddress = SquadAddress; // this is set
		game_launch_data.SessionInfo.IsHost = !strstr(GetCommandLineA(), "-client"); // if client, is false
		if (game_launch_data.SessionInfo.IsHost)
		{
			Sleep(1000);
		}

		game_launch_data.GameMode = g_LaunchGameMode;



		int playerCount = strstr(GetCommandLineA(), "-multiplayer") ? 2 : 1;
		game_launch_data.SessionInfo.PeerIdentifierCount = playerCount;
		game_launch_data.SessionInfo.SessionMembership.Count = playerCount;
		game_launch_data.SessionInfo.LocalAddress = 0; // this is set



		game_launch_data.SessionInfo.PeerIdentifiers[0] = 0;
		game_launch_data.SessionInfo.PeerIdentifiers[1] = 0;

		{
			game_launch_data.SessionInfo.SessionMembership.Members[0].MachineIdentifier = 0;
			game_launch_data.SessionInfo.SessionMembership.Members[0].Team = 0;
			game_launch_data.SessionInfo.SessionMembership.Members[0].PlayerAssignedTeam = 0;
			game_launch_data.SessionInfo.SessionMembership.Members[0].SecureAddress = (void*)HostAddress;
		}
		if (game_launch_data.SessionInfo.SessionMembership.Count > 1)
		{
			game_launch_data.SessionInfo.SessionMembership.Members[1].MachineIdentifier = 0;
			game_launch_data.SessionInfo.SessionMembership.Members[1].Team = 0;
			game_launch_data.SessionInfo.SessionMembership.Members[1].PlayerAssignedTeam = 0;
			game_launch_data.SessionInfo.SessionMembership.Members[1].SecureAddress = (void*)ClientAddress;
		}
		if (game_launch_data.SessionInfo.SessionMembership.Count > 2)
		{
			FATAL_ERROR("Too many people need to add more data");
		}



		if (game_launch_data.SessionInfo.IsHost)
		{
			IGameEngineHost::CreateServerConnection();

			SetConsoleTitleA("Halo Reach Console | HOST");

			game_launch_data.MapId = g_LaunchMapId;
			game_launch_data.CampaignDifficultyLevel = g_LaunchCampaignDifficultyLevel;

			LoadHopperGameVariant(pHaloReachDataAccess, g_LaunchHopperGameVariant, *reinterpret_cast<s_game_variant*>(game_launch_data.GameVariantBuffer));
			LoadHopperMapVariant(pHaloReachDataAccess, g_LaunchHopperMapVariant, *reinterpret_cast<s_map_variant*>(game_launch_data.MapVariantBuffer));
			LoadPreviousGamestate("gamestate.hdr", game_launch_data);

			

		}
		else
		{
			IGameEngineHost::CreateClientConnection();

			game_launch_data.SessionInfo.LocalAddress = ClientAddress; // this is set
			game_launch_data.SessionInfo.HostAddress = HostAddress;
		}
	}

	pHaloReachEngine->InitGraphics(GameRender::s_pDevice, GameRender::s_pDeviceContext, GameRender::s_pSwapChain, GameRender::s_pSwapChain);
	HANDLE hMainGameThread = pHaloReachEngine->InitThread(&IGameEngineHost::g_gameEngineHost, &game_launch_data);

	CustomWindow::SetPostMessageThreadId(hMainGameThread);

	while (s_currentGameState != CurrentState::eFinished)
	{
		Update();
	}

	WaitForSingleObject(hMainGameThread, INFINITE);

	if (s_gameShutdownCallback)
	{
		s_gameShutdownCallback(gameID);
	}

	pHaloReachEngine->Destructor();
	//free(pHaloReachEngine);
	pHaloReachDataAccess->__vftable->Free(pHaloReachDataAccess);
	//free(pHaloReachDataAccess);
}

void GameLauncher::Update()
{
	
	MouseInput::Acquire(); // have to try to acquire mouse here as this thread updates the window messages
	CustomWindow::Update();

	// keep updating state while the game is not running
	if (s_currentGameState == CurrentState::eFinished)
	{
		MouseInput::Read();
	}

	Sleep(1); // prevent 100% CPU
}

void GameLauncher::InitSockets()
{
	WSADATA wsaData = {};
	// Initialize Winsock
	auto WSAStartupResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (WSAStartupResult != 0)
	{
		FATAL_ERROR("WSAStartup failed with error: %d\n", WSAStartupResult);
	}
}

void GameLauncher::DeinitSockets()
{

}

HaloGameID GameLauncher::GetLibraryHaloGameID(const char* pFilename)
{
	uint64_t libraryFileVersion = GetLibraryFileVersion("HaloReach.dll");
	switch (libraryFileVersion)
	{
	case MAKE_FILE_VERSION(1, 1035, 0, 0): return HaloGameID::HaloReach_2019_Aug_20;
	case MAKE_FILE_VERSION(1, 887, 0, 0): return HaloGameID::HaloReach_2019_Jun_24;
	default:
		return HaloGameID::NotSet;
	}
}

uint64_t GameLauncher::GetLibraryFileVersion(const char* pFilename)
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

static size_t get_file_size(FILE* pFile)
{
	assert(pFile);
	fseek(pFile, 0, SEEK_END);
	size_t variantSize = ftell(pFile);
	fseek(pFile, 0L, SEEK_SET);
	return variantSize;
}

static void read_file_to_buffer(FILE* pFile, char* pBuffer, size_t length)
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

void GameLauncher::LoadHopperMapVariant(IDataAccess* pDataAccess, const char* pHopperMapVariantName, s_map_variant& out_map_variant)
{
	char pFilename[MAX_PATH] = {};
	sprintf(pFilename, "hopper_map_variants\\%s.mvar", pHopperMapVariantName);
	pFilename[MAX_PATH - 1] = 0;

	FILE* pVariantFile = fopen(pFilename, "rb");
	if (pVariantFile)
	{
		WriteLineVerbose("Loading map variant [%s]", pFilename);
		size_t variantSize = get_file_size(pVariantFile);
		char* pVariantBuffer = (char*)alloca(variantSize);
		memset(pVariantBuffer, 0x00, variantSize);
		read_file_to_buffer(pVariantFile, pVariantBuffer, variantSize);
		fclose(pVariantFile);

		__int64 result = pDataAccess->CreateMapVariantFromFile(pVariantBuffer, static_cast<int>(variantSize));

		s_map_variant* pGameVariant = (s_map_variant*)(result + 8);

		out_map_variant = *pGameVariant;
	}
}

void GameLauncher::LoadHopperGameVariant(IDataAccess* pDataAccess, const char* pHopperGameVariantName, s_game_variant& out_game_variant)
{
	char pFilename[MAX_PATH] = {};
	sprintf(pFilename, "hopper_game_variants\\%s.bin", pHopperGameVariantName);
	pFilename[MAX_PATH - 1] = 0;

	FILE* pVariantFile = fopen(pFilename, "rb");
	if (pVariantFile)
	{
		WriteLineVerbose("Loading game variant [%s]", pFilename);
		size_t variantSize = get_file_size(pVariantFile);
		char* pVariantBuffer = (char*)alloca(variantSize);
		memset(pVariantBuffer, 0x00, variantSize);
		read_file_to_buffer(pVariantFile, pVariantBuffer, variantSize);
		fclose(pVariantFile);

		__int64 result = pDataAccess->CreateGameVariantFromFile(pVariantBuffer, static_cast<int>(variantSize));

		s_game_variant* pGameVariant = (s_game_variant*)(result + 8);

		out_game_variant = *pGameVariant;
	}
}

void GameLauncher::LoadPreviousGamestate(const char* pFilename, s_game_launch_data& game_launch_data)
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
