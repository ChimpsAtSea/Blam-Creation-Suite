#include "opusframework-private-pch.h"

std::vector<GameLauncher::GenericGameEvent> GameLauncher::m_gameStartupEvent;
std::vector<GameLauncher::GenericGameEvent> GameLauncher::m_gameShutdownEvent;
GameRuntime gameRuntime = GameRuntime("haloreach", "HaloReach\\haloreach.dll");


bool startGameNextFrame = false;
bool gameRunning = false;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INPUT:
		MouseInput::InputWindowMessage(lParam);
		break;
	case WM_SETCURSOR:
		if (MouseInput::SetCursorWindowMessage(lParam))
		{
			return TRUE;
		}
		break;
	}
	return 0;
}

void GameLauncher::Init()
{
	checkSteamOwnership();
	ensureBink2Win64IsLoaded("bink2w64.dll", "..\\MCC\\Binaries\\Win64");
	GameOptionSelection::Init();

	Window::RegisterWndProcCallback(WndProc);
}

void GameLauncher::Deinit()
{
	Window::UnregisterWndProcCallback(WndProc);
	GameOptionSelection::Deinit();
}

void GameLauncher::OpusTick()
{
	update();
}

void GameLauncher::OpusUITick()
{
	if(gameRunning)
	{
		update();
		gameRender();
	}
	else
	{
		render();
	}
}

void GameLauncher::update()
{
	if (startGameNextFrame)
	{
		startGameNextFrame = false;
		gameRunning = true;
		launchGame(EngineVersion::HaloReach);
		gameRunning = false;
	}

	if (gameRunning)
	{
		Window::UpdateNoCallbacks();
	}
}

void GameLauncher::render()
{
	float width = static_cast<float>(GetSystemMetrics(SM_CXSCREEN));
	float height = static_cast<float>(GetSystemMetrics(SM_CYSCREEN));

	static ImVec2 nextWindowSize = ImVec2(width * 0.98f, height * 0.94f);
	//ImGui::SetNextWindowPosCenter(ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(nextWindowSize, ImGuiCond_FirstUseEver);

	static bool isWindowOpen = true;
	int windowFlags = 0;
	//windowFlags |= ImGuiWindowFlags_MenuBar;
	windowFlags |= ImGuiWindowFlags_NoCollapse;
	windowFlags |= ImGuiWindowFlags_NoTitleBar;
	windowFlags |= ImGuiWindowFlags_NoMove;
	windowFlags |= ImGuiWindowFlags_NoResize;
	windowFlags |= ImGuiWindowFlags_NoSavedSettings;
	//windowFlags |= ImGuiWindowFlags_AlwaysAutoResize;

	if (!ImGui::Begin("MAIN MENU", &isWindowOpen, windowFlags))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	GameOptionSelection::Render();

	static ImVec2 gridButtonSize = ImVec2(nextWindowSize.x / 5, nextWindowSize.y / 16);

	ImGui::SetCursorPos(ImVec2(gridButtonSize.x * 0.35f, gridButtonSize.y * 8));
	static bool hasAutostarted = false;
	if (ImGui::Button("START GAME", gridButtonSize) || (CommandLine::HasCommandLineArg("-autostart") && !hasAutostarted) || GetKeyState(VK_RETURN) & 0x80)
	{
		GameOptionSelection::m_pLaunchSavedFilm = "";
		hasAutostarted = true;
		startGameNextFrame = true;
	}

	ImGui::SetCursorPos(ImVec2(gridButtonSize.x * 0.35f, gridButtonSize.y * 9.1f));
	if (ImGui::Button("PLAY FILM", gridButtonSize) || GetKeyState('P') & 0x80)
	{
		startGameNextFrame = true;
	}

	ImGui::SetCursorPos(ImVec2(gridButtonSize.x * 0.35f, gridButtonSize.y * 14));
	if (ImGui::Button("QUIT TO DESKTOP", gridButtonSize) || GetKeyState(VK_ESCAPE) & 0x80)
	{
		exit(0);
	}


	ImGui::End();
}

void GameLauncher::gameRender()
{

}

void GameLauncher::launchGame(EngineVersion engineVersion)
{
	switch (engineVersion)
	{
	case EngineVersion::HaloReach:
		launchHaloReach();
		break;
	}
}

void GameLauncher::launchHaloReach()
{
	IGameEngine* pHaloReachEngine = nullptr;
	__int64 createGameEngineResult = gameRuntime.CreateGameEngine(&pHaloReachEngine);
	assert(pHaloReachEngine);

	EngineVersion engineVersion = EngineVersion::HaloReach;
	BuildVersion buildVersion = gameRuntime.GetBuildVersion();

	// #TODO: Game specific version of this!!!

	for (GenericGameEvent gameEvent : m_gameStartupEvent)
	{
		gameEvent(engineVersion, buildVersion);
	}

	GameContext gameContext = {};
	{
		const MapInfo* pSelectedMapInfo = GameOptionSelection::GetSelectedMapInfo();
		GameMode gameMode = GameOptionSelection::GetSelectedGameMode();

		gameContext.pGameHandle = GetModuleHandle("HaloReach.dll");
		char byte2B678Data[] = { 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
		memcpy(gameContext.byte2B678, byte2B678Data, sizeof(byte2B678Data)); // what the hell is this?

		{
			uint64_t SquadAddress = 0x2F385E2E95D4F33E;
			uint64_t HostAddress = 0xDEADBEEFDEADBEEF;
			uint64_t ClientAddress = 0xCAFEBABECAFEBABE;

			gameContext.SessionInfo.SquadAddress = SquadAddress; // this is set

			gameContext.GameMode = gameMode;

			gameContext.SessionInfo.PeerIdentifierCount = 1;
			gameContext.SessionInfo.SessionMembership.Count = 1;
			gameContext.SessionInfo.IsHost = true;
			if (gameContext.SessionInfo.IsHost)
			{
				gameContext.MapId = static_cast<MapID>(pSelectedMapInfo->GetMapID());
				gameContext.CampaignDifficultyLevel = e_campaign_difficulty_level::_campaign_difficulty_level_easy;

				GameOptionSelection::LoadGameVariant(GameOptionSelection::GetDataAccess(), GameOptionSelection::m_pLaunchGameVariant.c_str(), *reinterpret_cast<s_game_variant*>(gameContext.GameVariantBuffer), true);
				GameOptionSelection::LoadMapVariant(GameOptionSelection::GetDataAccess(), GameOptionSelection::m_pLaunchMapVariant.c_str(), *reinterpret_cast<s_map_variant*>(gameContext.MapVariantBuffer), true);
				//GameOptionSelection::LoadPreviousGamestate("gamestate", gameContext);
				GameOptionSelection::LoadSavedFilmMetadata(GameOptionSelection::m_pLaunchSavedFilm.c_str(), gameContext);

				gameContext.SessionInfo.LocalMachineID = HostAddress; // this is set
				gameContext.SessionInfo.HostAddress = HostAddress;
			}
			else
			{
				gameContext.SessionInfo.LocalMachineID = ClientAddress; // this is set
				gameContext.SessionInfo.HostAddress = HostAddress;
			}
		}
	}

	pHaloReachEngine->InitGraphics(Render::s_pDevice, Render::s_pDeviceContext, Render::s_pSwapChain, Render::s_pSwapChain);

	IOpusGameEngineHost gameEngineHost = IOpusGameEngineHost(gameRuntime);

	{
		// useful for testing if the gameenginehostcallback vftable is correct or not
		static constexpr bool kBogusGameEngineHostCallbackVFT = false;
		if constexpr (kBogusGameEngineHostCallbackVFT)
		{
			void*& pGameEngineHostVftable = *reinterpret_cast<void**>(&gameEngineHost);
			static char data[sizeof(void*) * 1024] = {};
			memset(data, -1, sizeof(data));
			static constexpr size_t kNumBytesToCopyFromExistingVFT = 0;
			memcpy(data, pGameEngineHostVftable, kNumBytesToCopyFromExistingVFT);
			pGameEngineHostVftable = data;
		}
	}

	HANDLE hMainGameThread = pHaloReachEngine->InitThread(&gameEngineHost, &gameContext);
	Window::SetPostMessageThreadId(hMainGameThread);

	HRESULT waitForSingleObjectResult;
	do
	{
		update();
		waitForSingleObjectResult = WaitForSingleObject(hMainGameThread, 5);
	} while (waitForSingleObjectResult == WAIT_TIMEOUT);


	for (GenericGameEvent gameEvent : m_gameShutdownEvent)
	{
		gameEvent(engineVersion, buildVersion);
	}

	pHaloReachEngine->Destructor();
	//free(pHaloReachEngine);
	//free(pHaloReachDataAccess);

	// reset runtime information after we've destroyed the engine
	//s_pCurrentGameRuntime = nullptr;
}

void GameLauncher::checkSteamOwnership()
{
	{
		FILE* pAppIDFile = fopen("steam_appid.txt", "w");
		assert(pAppIDFile);
		constexpr const char* pAppId = "976730";
		fwrite(pAppId, sizeof(char), strlen(pAppId), pAppIDFile);
		fclose(pAppIDFile);
	}

	bool steamAPIInitResult = SteamAPI_Init();
	if (!steamAPIInitResult)
	{
		MessageBox(NULL, "Fatal Error - Steam failed to initialize", "Fatal Error", MB_OK | MB_ICONWARNING);
		exit(1);
	}
}

void GameLauncher::ensureBink2Win64IsLoaded(const char* pLibName, const char* pFallbackDir)
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
		MessageBox(Window::GetWindowHandle(), pLibName, "failed to load library", MB_ICONERROR);
	}
	assert(hModule);
}

void GameLauncher::renderPauseMenu()
{
	MouseInput::SetMode(MouseMode::UI);

	float width = static_cast<float>(GetSystemMetrics(SM_CXSCREEN));
	float height = static_cast<float>(GetSystemMetrics(SM_CYSCREEN));

	//ImGui::SetNextWindowPosCenter(ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(width / 1.5f, height / 1.5f), ImGuiCond_FirstUseEver);

	static bool isWindowOpen = true;
	int windowFlags = 0;
	windowFlags |= ImGuiWindowFlags_MenuBar;
	windowFlags |= ImGuiWindowFlags_NoCollapse;
	windowFlags |= ImGuiWindowFlags_NoTitleBar;
	windowFlags |= ImGuiWindowFlags_NoMove;
	windowFlags |= ImGuiWindowFlags_NoResize;
	windowFlags |= ImGuiWindowFlags_NoSavedSettings;
	//windowFlags |= ImGuiWindowFlags_AlwaysAutoResize;

	static ImVec2 gridButtonSize = ImVec2((width / 1.5f) / 5, (height / 1.5f) / 16);

	if (!ImGui::Begin("PAUSE MENU", &isWindowOpen, windowFlags))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	static bool isPaused = false;

	while (!isPaused && GetKeyState(VK_ESCAPE) & 0x80)
	{
		Sleep(1);
	}

	//if (s_pHaloReachEngine)
	//{
	//	if (!isPaused)
	//	{
	//		s_pHaloReachEngine->UpdateEngineState(eEngineState::Pause);
	//		isPaused = true;
	//	}

	//	if (ImGui::Button("RETURN TO GAME", gridButtonSize) || GetKeyState(VK_ESCAPE) & 0x80)
	//	{
	//		isPaused = false;
	//	}

	//	if (s_currentGameMode == GameMode::GameMode::Campaign)
	//	{
	//		if (ImGui::Button("REVERT TO LAST SAVE", gridButtonSize))
	//		{
	//			s_pHaloReachEngine->UpdateEngineState(eEngineState::RevertToLastSave);
	//			isPaused = false;
	//		}
	//	}

	//	if (s_currentGameMode == GameMode::GameMode::Multiplayer || s_currentGameMode == GameMode::GameMode::Survival)
	//	{
	//		if (ImGui::Button("END ROUND", gridButtonSize))
	//		{
	//			s_pHaloReachEngine->UpdateEngineState(eEngineState::EndRound);
	//			isPaused = false;
	//		}
	//	}

	//	if (s_currentGameMode == GameMode::GameMode::Campaign || s_currentGameMode == GameMode::GameMode::Survival)
	//	{
	//		if (ImGui::Button("RESTART GAME", gridButtonSize))
	//		{
	//			s_pHaloReachEngine->UpdateEngineState(eEngineState::RestartLevel);
	//			isPaused = false;
	//		}
	//	}

	//	if (ImGui::Button("RETURN TO MAINMENU", gridButtonSize))
	//	{
	//		s_pHaloReachEngine->UpdateEngineState(eEngineState::EndGame);
	//		isPaused = false;
	//	}

	//	if (!isPaused)
	//	{
	//		s_pHaloReachEngine->UpdateEngineState(eEngineState::Unpause);
	//		DebugUI::UnregisterCallback(LegacyGameLauncher::DrawPauseMenu);
	//		MouseInput::SetMode(MouseMode::Exclusive);
	//		DebugUI::Hide();
	//	}
	//}

	//ImVec2 mouseSensitivity = MouseInput::GetSensitivity();
	//static float MouseSensitivityX = mouseSensitivity.x;
	//static float MouseSensitivityY = mouseSensitivity.y;

	//if (ImGui::InputFloat("Mouse Sensitivity X", &MouseSensitivityX, 0.01f, 0.1f, "%.3f"))
	//{
	//	if (MouseSensitivityX > 1.0f) MouseSensitivityX = 1.0f;
	//	if (MouseSensitivityX < 0.0f) MouseSensitivityX = 0.0f;
	//}

	//if (ImGui::InputFloat("Mouse Sensitivity Y", &MouseSensitivityY, 0.01f, 0.1f, "%.3f"))
	//{
	//	if (MouseSensitivityY > 1.0f) MouseSensitivityY = 1.0f;
	//	if (MouseSensitivityY < 0.0f) MouseSensitivityY = 0.0f;
	//}

	//if (MouseSensitivityX != mouseSensitivity.x || MouseSensitivityY != mouseSensitivity.y)
	//{
	//	MouseInput::SetSensitivity(MouseSensitivityX, MouseSensitivityY);
	//}

	ImGui::End();
}

