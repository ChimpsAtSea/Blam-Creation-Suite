#include "opusframework-private-pch.h"

enum class NextLaunchMode
{
	None,
	Generic,
	Theater
};
NextLaunchMode s_nextLaunchMode = NextLaunchMode::None;

std::vector<GameLauncher::GenericGameEvent> GameLauncher::s_gameStartupEvent;
std::vector<GameLauncher::GenericGameEvent> GameLauncher::s_gameShutdownEvent;
bool GameLauncher::s_gameRunning = false;
IDataAccess* GameLauncher::s_pCurrentDataAccess = nullptr;
GameRuntime gameRuntime = GameRuntime("haloreach", "HaloReach\\haloreach.dll");

//#TODO: Create an interface for getting the camera co-ordinates
// -------------------------

intptr_t player_mapping_get_local_player_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1270_0_0: return 0x18006FDF0;
	}
	return ~intptr_t();
}
FunctionHookEx<player_mapping_get_local_player_offset, int __stdcall ()> player_mapping_get_local_player;

intptr_t observer_try_and_get_camera_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1270_0_0: return 0x1800E2FA0;
	}
	return ~intptr_t();
}
FunctionHookEx<observer_try_and_get_camera_offset, s_observer_camera * __fastcall (signed int a1)> observer_try_and_get_camera;

// -------------------------


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
	s_pCurrentDataAccess = gameRuntime.GetDataAccess();

	checkSteamOwnership();
	ensureBink2Win64IsLoaded("bink2w64.dll", "..\\MCC\\Binaries\\Win64");
	GameLauncher::loadSettings();

	GameOptionSelection::Init();
	Window::RegisterWndProcCallback(WndProc);
	DebugUI::RegisterCallback(DebugUI::CallbackMode::AlwaysRun, renderMainMenu);
	DebugUI::RegisterCallback(DebugUI::CallbackMode::Toggleable, renderUI);
}

void GameLauncher::Deinit()
{
	DebugUI::UnregisterCallback(DebugUI::CallbackMode::AlwaysRun, renderMainMenu);
	DebugUI::UnregisterCallback(DebugUI::CallbackMode::Toggleable, renderUI);
	Window::UnregisterWndProcCallback(WndProc);
	GameOptionSelection::Deinit();
}

void GameLauncher::loadSettings()
{
	float horizontalSensitivity = Settings::ReadFloatValue(SettingsSection::Controls, "HorizontalSensitivity", 1.0f);
	float verticalSensitivity = Settings::ReadFloatValue(SettingsSection::Controls, "VerticalSensitivity", 1.0f);
	MouseInput::SetSensitivity(horizontalSensitivity, verticalSensitivity);
}

void GameLauncher::OpusTick()
{
	update();

	DebugUI::StartFrame(); // OpusUITick is registered to the DebugUI
	//OpusUITick();
	if (DebugUI::IsRendering() && s_gameRunning) // render a debug layer for the game to render text to
	{
		constexpr ImGuiWindowFlags kDebugWindowFlags =
			ImGuiWindowFlags_NoMove |
			ImGuiWindowFlags_NoBackground |
			ImGuiWindowFlags_NoSavedSettings |
			ImGuiWindowFlags_NoMouseInputs |
			ImGuiWindowFlags_NoNav |
			ImGuiWindowFlags_NoDecoration |
			ImGuiWindowFlags_NoInputs;
		ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
		ImGui::SetNextWindowSize(ImVec2(static_cast<float>(Window::GetWindowWidth()), static_cast<float>(Window::GetWindowHeight())), ImGuiCond_Always);
		if (ImGui::Begin("##debug", NULL, kDebugWindowFlags)) // render inside of the dummy imgui window for on screen text display
		{
			gameRender();
		}
		ImGui::End();
	}
	DebugUI::EndFrame();
}

void GameLauncher::update()
{
	if (s_gameRunning)
	{
		// need some place to update the launcher, might as well do it here for now
		Window::UpdateNoCallbacks();
	}
	else
	{
		if (s_nextLaunchMode != NextLaunchMode::None)
		{
			s_nextLaunchMode = NextLaunchMode::None;
			launchGame(EngineVersion::HaloReach);
		}
	}
}

void GameLauncher::gameRender()
{
	updateCamera();
	MantleGUI::GameRender();
	PrimitiveRenderManager::Render();
}

void GameLauncher::renderUI()
{
	MantleGUI::Render();
	renderCameraDebug();
}

void GameLauncher::updateCamera()
{
	int playerIndex = player_mapping_get_local_player();
	s_observer_camera* observer_camera = observer_try_and_get_camera(playerIndex);
	if (observer_camera)
	{
		float aspectRatio = 16.0f / 9.0f; // #TODO: Correct aspect ratio
		float fieldOfViewHorizontal = observer_camera->field_of_view;
		PrimitiveRenderManager::UpdatePerspective(fieldOfViewHorizontal, aspectRatio);
		PrimitiveRenderManager::UpdateView(
			observer_camera->forward.I,
			observer_camera->forward.J,
			observer_camera->forward.K,
			observer_camera->up.I,
			observer_camera->up.J,
			observer_camera->up.K,
			observer_camera->position.I,
			observer_camera->position.J,
			observer_camera->position.K
		);
	}
}

void GameLauncher::renderCameraDebug()
{
	static bool kEnableCameraDebugTest = CommandLine::HasCommandLineArg("-cameradebug");
	if(kEnableCameraDebugTest)
	{
		ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
		ImGui::SetNextWindowSize(ImVec2(1876, 1024), ImGuiCond_FirstUseEver);

		// Main body of the Demo window starts here.
		static bool isReachCameraDebugWindowOpen = true;
		if (ImGui::Begin("Camera Debug Output", &isReachCameraDebugWindowOpen, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse))
		{
			if (s_gameRunning)
			{
				int playerIndex = player_mapping_get_local_player();
				s_observer_camera* observer_camera = observer_try_and_get_camera(playerIndex);

				if (observer_camera)
				{
					ImGui::Text("position:       %f, %f, %f", observer_camera->position.I, observer_camera->position.J, observer_camera->position.K);
					ImGui::Text("position_shift: %f, %f, %f", observer_camera->position_shift.I, observer_camera->position_shift.J, observer_camera->position_shift.K);
					ImGui::Text("look:           %f", observer_camera->look);
					ImGui::Text("look_shift:     %f", observer_camera->look_shift);
					ImGui::Text("depth:          %f", observer_camera->depth);
					ImGui::Text("unknown0:       %f", observer_camera->unknown0);
					ImGui::Text("forward:        %f, %f, %f", observer_camera->forward.I, observer_camera->forward.J, observer_camera->forward.K);
					ImGui::Text("up:             %f, %f, %f", observer_camera->up.I, observer_camera->up.J, observer_camera->up.K);
					ImGui::Text("field_of_view:  %f", observer_camera->field_of_view);
					ImGui::Text("unknown1:       %f", observer_camera->unknown1);
					ImGui::Text("unknown2:       %f", observer_camera->unknown2);
				}
				else ImGui::Text("No camera present.");
			}
			else ImGui::Text("Game not running.");
			
		}
		ImGui::End();

	}
}

void GameLauncher::launchGame(EngineVersion engineVersion)
{
	s_gameRunning = true;
	// #TODO: We currently can't resize the game without crashing
	// we should do this at the beginning of the frame. 

	Render::SetResizeEnabled(false);
	switch (engineVersion)
	{
	case EngineVersion::HaloReach:
		launchHaloReach();
		break;
	}
	Render::SetResizeEnabled(true);

	s_gameRunning = false;
}

void GameLauncher::launchHaloReach()
{

	IGameEngine* pHaloReachEngine = nullptr;
	__int64 createGameEngineResult = gameRuntime.CreateGameEngine(&pHaloReachEngine);
	assert(pHaloReachEngine);

	EngineVersion engineVersion = EngineVersion::HaloReach;
	BuildVersion buildVersion = gameRuntime.GetBuildVersion();

	// #TODO: Game specific version of this!!!

	for (GenericGameEvent gameEvent : s_gameStartupEvent)
	{
		gameEvent(engineVersion, buildVersion);
	}

	GameContext gameContext = {};
	{
		const MapInfo* pSelectedMapInfo = GameOptionSelection::GetSelectedMapInfo();
		GameMode gameMode = GameOptionSelection::GetSelectedGameMode();

		const char* pMapFileName = pSelectedMapInfo->GetMapFileName();
		WriteLineVerbose("Loading map '%s.map'", pMapFileName);
		{
			wchar_t pMapFilePathBuffer[MAX_PATH + 1] = {};
			_snwprintf(pMapFilePathBuffer, MAX_PATH, L"%S%S.map", "haloreach/maps/", pMapFileName);
			MantleGUI::OpenMapFile(pMapFilePathBuffer);
		}

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

				GameOptionSelection::LoadGameVariant(s_pCurrentDataAccess, GameOptionSelection::s_pLaunchGameVariant.c_str(), *reinterpret_cast<s_game_variant*>(gameContext.GameVariantBuffer), true);
				GameOptionSelection::LoadMapVariant(s_pCurrentDataAccess, GameOptionSelection::s_pLaunchMapVariant.c_str(), *reinterpret_cast<s_map_variant*>(gameContext.MapVariantBuffer), true);
				//GameOptionSelection::LoadPreviousGamestate("gamestate", gameContext);
				//GameOptionSelection::LoadSavedFilmMetadata(GameOptionSelection::s_pLaunchSavedFilm.c_str(), gameContext);

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


	for (GenericGameEvent gameEvent : s_gameShutdownEvent)
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

void GameLauncher::renderMainMenu()
{
	if (s_gameRunning) return;

	float width = static_cast<float>(GetSystemMetrics(SM_CXSCREEN));
	float height = static_cast<float>(GetSystemMetrics(SM_CYSCREEN));

	ImVec2 globalWindowSize = ImVec2(static_cast<float>(Window::GetWindowWidth()), static_cast<float>(Window::GetWindowHeight()));
	ImVec2 windowSize = ImVec2(globalWindowSize.x * 0.75f, globalWindowSize.y * 0.75f);
	ImVec2 windowOffset = ImVec2((globalWindowSize.x - windowSize.x) / 2.0f, (globalWindowSize.y - windowSize.y) / 2.0f);
	ImGui::SetNextWindowSize(windowSize, ImGuiCond_Always);
	ImGui::SetNextWindowPos(windowOffset, ImGuiCond_Always);

	static bool isWindowOpen = true;
	int windowFlags = 0;
	//windowFlags |= ImGuiWindowFlags_MenuBar;
	windowFlags |= ImGuiWindowFlags_NoCollapse;
	windowFlags |= ImGuiWindowFlags_NoTitleBar;
	windowFlags |= ImGuiWindowFlags_NoMove;
	windowFlags |= ImGuiWindowFlags_NoResize;
	windowFlags |= ImGuiWindowFlags_NoSavedSettings;
	//windowFlags |= ImGuiWindowFlags_AlwaysAutoResize;

	if (ImGui::Begin("MAIN MENU", &isWindowOpen, windowFlags))
	{
		GameOptionSelection::Render();
		{
			ImGui::Dummy(ImVec2(0.0f, 30.0f));
			static bool hasAutostarted = false;
			if (ImGui::Button("START GAME") || (CommandLine::HasCommandLineArg("-autostart") && !hasAutostarted) || GetKeyState(VK_RETURN) & 0x80)
			{
				GameOptionSelection::s_pLaunchSavedFilm = "";
				hasAutostarted = true;
				s_nextLaunchMode = NextLaunchMode::Generic;
			}

			if (ImGui::Button("PLAY FILM") || GetKeyState('P') & 0x80)
			{
				s_nextLaunchMode = NextLaunchMode::Theater;
			}

			ImGui::Dummy(ImVec2(0.0f, 20.0f));
			if (ImGui::Button("QUIT TO DESKTOP"))
			{
				exit(0);
			}
		}
	}
	ImGui::End();
}

void GameLauncher::renderPauseMenu()
{
	MouseInput::SetMode(MouseMode::UI);

	float width = static_cast<float>(GetSystemMetrics(SM_CXSCREEN));
	float height = static_cast<float>(GetSystemMetrics(SM_CYSCREEN));

	ImVec2 globalWindowSize = ImVec2(static_cast<float>(Window::GetWindowWidth()), static_cast<float>(Window::GetWindowHeight()));
	ImVec2 windowSize = ImVec2(globalWindowSize.x * 0.75f, globalWindowSize.y * 0.75f);
	ImVec2 windowOffset = ImVec2((globalWindowSize.x - windowSize.x) / 2.0f, (globalWindowSize.y - windowSize.y) / 2.0f);
	ImGui::SetNextWindowSize(windowSize, ImGuiCond_Always);
	ImGui::SetNextWindowPos(windowOffset, ImGuiCond_Always);

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


