#include "haloshared-private-pch.h"

#define MAKE_FILE_VERSION(a, b, c, d) ((uint64_t(a) << 48) | (uint64_t(b) << 32) | (uint64_t(c) << 16) | (uint64_t(d) << 0))

bool GameLauncher::s_gameManuallyKilled = false;
bool GameLauncher::s_hideWindowOnStartup = false;
GameLauncher::CurrentState GameLauncher::s_currentState = GameLauncher::CurrentState::eInactive;
GameLauncher::GameLaunchCallback* GameLauncher::s_gameLaunchCallback = nullptr;
GameLauncher::GameShutdownCallback* GameLauncher::s_gameShutdownCallback;
GameInterface* GameLauncher::s_pGameInterface = nullptr;
HaloGameID GameLauncher::s_gameID = HaloGameID::NotSet;
IGameEngine* GameLauncher::s_pHaloReachEngine = nullptr;
IDataAccess* GameLauncher::s_pHaloReachDataAccess = nullptr;

char* GameLauncher::s_pTerminationFlag = nullptr;

e_map_id g_LaunchMapId = _map_id_ff45_corvette;
e_game_mode g_LaunchGameMode = _game_mode_survival;
e_campaign_difficulty_level g_LaunchCampaignDifficultyLevel = _campaign_difficulty_level_normal;
const char* g_LaunchHopperGameVariant = nullptr;
const char* g_LaunchHopperMapVariant = nullptr;

void GameLauncher::LaunchGame(const char* pGameLibrary)
{
	// make sure the runtime information is in a valid state before trying to run another game
	assert(s_pHaloReachEngine == nullptr);
	assert(s_pHaloReachDataAccess == nullptr);
	assert(s_pGameInterface == nullptr);
	assert(s_gameID == HaloGameID::NotSet);

	GameInterface gameInterface = GameInterface(pGameLibrary);
	s_pGameInterface = &gameInterface;
	s_gameID = GetLibraryHaloGameID(pGameLibrary);
	assert(s_pGameInterface != nullptr);
	assert(s_gameID != HaloGameID::NotSet);

	// #TODO: Game specific version of this!!!
	if (s_gameLaunchCallback != nullptr)
	{
		s_gameLaunchCallback(s_gameID);
	}

	__int64 createGameEngineResult = gameInterface.CreateGameEngine(&s_pHaloReachEngine);
	__int64 createDataAccessResult = gameInterface.CreateDataAccess(&s_pHaloReachDataAccess);
	assert(s_pHaloReachEngine);
	assert(s_pHaloReachDataAccess);

	GameContext gameContext = {};
	SetupGameContext(gameContext);

	s_pHaloReachEngine->InitGraphics(GameRender::s_pDevice, GameRender::s_pDeviceContext, GameRender::s_pSwapChain, GameRender::s_pSwapChain);

	IGameEngineHost* pGameEngineHost = &IGameEngineHost::g_gameEngineHost;

	// useful for testing if the gameenginehostcallback vftable is correct or not
	static constexpr bool kBogusGameEngineHostCallbackVFT = false;
	if constexpr(kBogusGameEngineHostCallbackVFT)
	{
		void*& pGameEngineHostVftable = *reinterpret_cast<void**>(pGameEngineHost);
		static char data[sizeof(void*) * 1024] = {};
		memset(data, -1, sizeof(data));
		static constexpr size_t kNumBytesToCopyFromExistingVFT = 0;
		memcpy(data, pGameEngineHostVftable, kNumBytesToCopyFromExistingVFT);
		pGameEngineHostVftable = data;
	}

	HANDLE hMainGameThread = s_pHaloReachEngine->InitThread(pGameEngineHost, &gameContext);

	CustomWindow::SetPostMessageThreadId(hMainGameThread);

	while (true)
	{
		switch (s_currentState)
		{
		case GameLauncher::CurrentState::eWaitingToRun:
		case GameLauncher::CurrentState::eRunning:
		case GameLauncher::CurrentState::eInactive:
			Update();
			continue;
		}
		break;
	}

	WaitForSingleObject(hMainGameThread, INFINITE);

	if (s_gameShutdownCallback)
	{
		s_gameShutdownCallback(s_gameID);
	}

	s_pHaloReachEngine->Destructor();
	//free(pHaloReachEngine);
	s_pHaloReachDataAccess->__vftable->Free(s_pHaloReachDataAccess);
	//free(pHaloReachDataAccess);

	// reset runtime information after we've destroyed the engine
	s_pGameInterface = nullptr;
	s_gameID = HaloGameID::NotSet;
	s_pHaloReachEngine = nullptr;
	s_pHaloReachDataAccess = nullptr;
}

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

#ifdef _DEBUG
	bool isDebug = true;
#else
	bool isDebug = false;
#endif

	if (GameLauncher::HasCommandLineArg("-hidesplash"))
	{
		SplashScreen::Create();
		s_hideWindowOnStartup = true;
	}

	if ((GameLauncher::HasCommandLineArg("-showconsole") || isDebug) && !GameLauncher::HasCommandLineArg("-hideconsole"))
	{
		AllocConsole();
		FILE* pStdOut = freopen("CONOUT$", "w", stdout);
		assert(pStdOut);
		SetConsoleTitleA("Opus");
	}

	if (GameLauncher::HasCommandLineArg("-waitfordebugger"))
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
	LoadSettings(); // #TODO: Replace with UI
	CustomWindow::Init();
	GameRender::Init(hInstance);
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

bool GameLauncher::HasCommandLineArg(const char* pArgument)
{
	return strstr(GetCommandLineA(), pArgument) != 0;
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

void CreateSwapchainAndBackbuffer(IDXGISwapChain*& pSwapchain, ID3D11RenderTargetView*& pBackBuffer)
{
	if (!pSwapchain)
	{
		GameRender::CreateSwapchain(pSwapchain);
	}

	// get the address of the back buffer
	ID3D11Texture2D* pBackBufferTexture;
	pSwapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)& pBackBufferTexture);

	// use the back buffer address to create the render target
	GameRender::s_pDevice->CreateRenderTargetView(pBackBufferTexture, NULL, &pBackBuffer);
	pBackBufferTexture->Release();

	// set the render target as the back buffer
	GameRender::s_pDeviceContext->OMSetRenderTargets(1, &pBackBuffer, NULL);
}




ID3D11RenderTargetView* s_pMenuBackBuffer;    // global declaration

int GameLauncher::Run(HINSTANCE hInstance, LPSTR lpCmdLine)
{
	SetState(CurrentState::eMainMenu);

	GameLauncher::Init(hInstance, lpCmdLine);
	//GameLauncher::LaunchGame("haloreach.dll");

	CreateSwapchainAndBackbuffer(GameRender::s_pSwapChain, s_pMenuBackBuffer);

	while (true)
	{
		SplashScreen::Destroy();
		Update();
		Render();
	}
	GameLauncher::Deinit();
	return 0;
}

void GameLauncher::SetupGameContext(GameContext& rGameContext)
{
	rGameContext.pGameHandle = GetModuleHandle("HaloReach.dll");
	char byte2B678Data[] = { 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	memcpy(rGameContext.byte2B678, byte2B678Data, sizeof(byte2B678Data)); // what the hell is this?

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

		rGameContext.SessionInfo.SquadAddress = SquadAddress; // this is set
		rGameContext.SessionInfo.IsHost = !strstr(GetCommandLineA(), "-client"); // if client, is false

		rGameContext.GameMode = g_LaunchGameMode;



		int playerCount = GameLauncher::HasCommandLineArg("-multiplayer") ? 2 : 1;
		playerCount = 1;
		rGameContext.SessionInfo.PeerIdentifierCount = playerCount;
		rGameContext.SessionInfo.SessionMembership.Count = playerCount;

		rGameContext.SessionInfo.PeerIdentifiers[0] = 0;
		rGameContext.SessionInfo.PeerIdentifiers[1] = 1;
		{
			rGameContext.SessionInfo.SessionMembership.Members[0].MachineIdentifier = 0;
			rGameContext.SessionInfo.SessionMembership.Members[0].Team = 0;
			rGameContext.SessionInfo.SessionMembership.Members[0].PlayerAssignedTeam = 0;
			rGameContext.SessionInfo.SessionMembership.Members[0].SecureAddress = HostAddress;
		}
		if (rGameContext.SessionInfo.SessionMembership.Count > 1)
		{
			rGameContext.SessionInfo.SessionMembership.Members[1].MachineIdentifier = 0;
			rGameContext.SessionInfo.SessionMembership.Members[1].Team = 0;
			rGameContext.SessionInfo.SessionMembership.Members[1].PlayerAssignedTeam = 0;
			rGameContext.SessionInfo.SessionMembership.Members[1].SecureAddress = ClientAddress;
		}
		if (rGameContext.SessionInfo.SessionMembership.Count > 2)
		{
			FATAL_ERROR("Too many people need to add more data");
		}

		if (rGameContext.SessionInfo.IsHost)
		{
			IGameEngineHost::CreateServerConnection();

			SetConsoleTitleA("Opus | HOST");

			rGameContext.MapId = g_LaunchMapId;
			rGameContext.CampaignDifficultyLevel = g_LaunchCampaignDifficultyLevel;

			LoadHopperGameVariant(s_pHaloReachDataAccess, g_LaunchHopperGameVariant, *reinterpret_cast<s_game_variant*>(rGameContext.GameVariantBuffer));
			LoadHopperMapVariant(s_pHaloReachDataAccess, g_LaunchHopperMapVariant, *reinterpret_cast<s_map_variant*>(rGameContext.MapVariantBuffer));
			LoadPreviousGamestate("gamestate.hdr", rGameContext);
			*reinterpret_cast<int*>(rGameContext.GameVariantBuffer) = 3;

			rGameContext.SessionInfo.LocalMachineID = HostAddress; // this is set
			rGameContext.SessionInfo.HostAddress = HostAddress;
		}
		else
		{
			IGameEngineHost::CreateClientConnection();

			rGameContext.SessionInfo.LocalMachineID = ClientAddress; // this is set
			rGameContext.SessionInfo.HostAddress = HostAddress;
		}
		IGameEngineHost::g_isHost = rGameContext.SessionInfo.IsHost;
	}
}

void GameLauncher::SetState(CurrentState state)
{
	if (s_currentState == state)
	{
		return;
	}

	s_currentState = state;

	switch (state)
	{
	case CurrentState::eInactive:
		break;
	case CurrentState::eMainMenu:
		DebugUI::RegisterCallback(DrawMenu);
		break;
	case CurrentState::eWaitingToRun:
		break;
	case CurrentState::eRunning:
		DebugUI::UnregisterCallback(DrawMenu);
		DebugUI::Hide();
		LaunchGame("haloreach.dll");
		break;
	case CurrentState::eFinished:
		break;
	}
}

void GameLauncher::Update()
{
	MouseInput::Acquire(); // have to try to acquire mouse here as this thread updates the window messages
	CustomWindow::Update();

	switch (GameLauncher::s_currentState)
	{
	case CurrentState::eRunning:
		
		break;
	case CurrentState::eWaitingToRun:
		SetState(CurrentState::eRunning);
		break;
	case CurrentState::eInactive:
	case CurrentState::eFinished:
		SetState(CurrentState::eMainMenu);
		break;
	case CurrentState::eMainMenu:
		MouseInput::SetAcquireMode(MouseAcquireMode::UI);
		DebugUI::Show();
		MouseInput::Read();
		break;
	}

	Sleep(1); // prevent 100% CPU
}

void GameLauncher::Render()
{
	BeginRender();
	DebugUI::RenderFrame();
	EndRender();
}

void GameLauncher::BeginRender()
{
	// clear the back buffer to a deep blue
	float clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };
	GameRender::s_pDeviceContext->ClearRenderTargetView(s_pMenuBackBuffer, clearColor);
}

void GameLauncher::EndRender()
{
	GameRender::s_pSwapChain->Present(0, 0);
}

void GameLauncher::SelectGameMode()
{
	static const char* s_pGameModesStr[k_number_of_game_modes] = {
		nullptr,
		"campaign",
		nullptr,
		"multiplayer",
		nullptr,
		"survival" };
	std::string s_pCurrentGameModeStr = game_mode_to_string(g_LaunchGameMode);
	if (ImGui::BeginCombo("GameMode", s_pCurrentGameModeStr.c_str()))
	{
		for (int i = 0; i < _countof(s_pGameModesStr); i++)
		{
			const char* pGameModeStr = s_pGameModesStr[i];
			if (pGameModeStr)
			{
				bool selected = s_pCurrentGameModeStr == pGameModeStr;
				if (ImGui::Selectable(pGameModeStr, &selected))
				{
					g_LaunchGameMode = static_cast<e_game_mode>(i);
				}
			}
		}

		ImGui::EndCombo();
	}
}

void GameLauncher::SelectMap()
{
	const char* pCurrentMapStr = map_id_to_string(g_LaunchMapId);
	if (ImGui::BeginCombo("Map", pCurrentMapStr))
	{
		for (e_map_id mapId = e_map_id::_map_id_m05; mapId < k_number_of_map_ids; reinterpret_cast<int&>(mapId)++)
		{
			const char* pMapStr = map_id_to_string(mapId);
			if (pMapStr)
			{
				bool selected = pMapStr == pCurrentMapStr;
				if (ImGui::Selectable(pMapStr, &selected))
				{
					g_LaunchMapId = static_cast<e_map_id>(mapId);
				}
			}
		}

		ImGui::EndCombo();
	}
}

void GameLauncher::SelectDifficulty()
{
	const char* pCurrentDifficultyStr = campaign_difficulty_level_to_string(g_LaunchCampaignDifficultyLevel);
	if (ImGui::BeginCombo("Difficulty", pCurrentDifficultyStr))
	{
		for (e_campaign_difficulty_level difficulty = e_campaign_difficulty_level::_campaign_difficulty_level_easy; difficulty < k_number_of_campaign_difficulty_levels; reinterpret_cast<int&>(difficulty)++)
		{
			const char* pDifficultyStr = campaign_difficulty_level_to_string(difficulty);
			if (pDifficultyStr)
			{
				bool selected = pDifficultyStr == pCurrentDifficultyStr;
				if (ImGui::Selectable(pDifficultyStr, &selected))
				{
					g_LaunchCampaignDifficultyLevel = static_cast<e_campaign_difficulty_level>(difficulty);
				}
			}
		}

		ImGui::EndCombo();
	}
}

void GameLauncher::DrawMenu()
{
	ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(1876, 1000), ImGuiCond_FirstUseEver);

	// Main body of the Demo window starts here.
	static bool isReachDebugWindowOpen = true;
	int windowFlags = 0;
	windowFlags |= ImGuiWindowFlags_MenuBar;
	windowFlags |= ImGuiWindowFlags_NoCollapse;
	windowFlags |= ImGuiWindowFlags_NoTitleBar;
	windowFlags |= ImGuiWindowFlags_NoMove;
	windowFlags |= ImGuiWindowFlags_NoResize;
	windowFlags |= ImGuiWindowFlags_NoSavedSettings;
	//windowFlags |= ImGuiWindowFlags_AlwaysAutoResize;
	
	if (!ImGui::Begin("Main Menu", &isReachDebugWindowOpen, windowFlags))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	SelectGameMode();
	SelectMap();
	SelectDifficulty();

	static bool hasAutostarted = false;
	if (ImGui::Button("Start game") || (GameLauncher::HasCommandLineArg("-autostart") && !hasAutostarted))
	{
		hasAutostarted = true;
		SetState(CurrentState::eWaitingToRun);
	}
	

	
	ImGui::End();
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
	case MAKE_FILE_VERSION(1, 1186, 0, 0): return HaloGameID::HaloReach_2019_Oct_30;
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

		s_map_variant* pMapVariant = (s_map_variant*)(result + 8);

		out_map_variant = *pMapVariant;
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
		memset(pVariantBuffer, 0xFF, variantSize);
		read_file_to_buffer(pVariantFile, pVariantBuffer, variantSize);
		fclose(pVariantFile);
		__int64 result = pDataAccess->CreateGameVariantFromFile(pVariantBuffer, static_cast<int>(variantSize));

		s_game_variant* pGameVariant = (s_game_variant*)(result + 8);

		out_game_variant = *pGameVariant;
	}
}

void GameLauncher::LoadPreviousGamestate(const char* pFilename, GameContext& gameContext)
{
	FILE* pGameStateFile = fopen(pFilename, "rb");
	if (pGameStateFile)
	{
		size_t gameStateSize = get_file_size(pGameStateFile);
		char* pGameStateBuffer = (char*)alloca(gameStateSize);
		memset(pGameStateBuffer, 0x00, gameStateSize);
		read_file_to_buffer(pGameStateFile, pGameStateBuffer, gameStateSize);
		fclose(pGameStateFile);

		gameContext.pGameStateHeader = reinterpret_cast<uint8_t*>(&pGameStateBuffer);
		gameContext.GameStateHeaderSize = gameStateSize;
	}
}
