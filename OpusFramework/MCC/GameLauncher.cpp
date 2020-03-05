#include "opusframework-private-pch.h"

enum class NextLaunchMode
{
	None,
	Generic,
	Theater
};
NextLaunchMode s_nextLaunchMode = NextLaunchMode::None;
e_engine_type s_nextLaunchEngine;

std::vector<GameLauncher::GenericGameEvent> GameLauncher::s_gameStartupEvent;
std::vector<GameLauncher::GenericGameEvent> GameLauncher::s_gameShutdownEvent;
bool GameLauncher::s_gameRunning = false;
c_opus_game_engine_host* pCurrentGameHost = nullptr;

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
#ifdef _WIN64
	checkSteamOwnership();
	entireLibraryIsLoaded("bink2w64.dll", "..\\MCC\\Binaries\\Win64");
	// #TODO: New home for this in Halo1Lib
	entireLibraryIsLoaded("halo1\\fmodex64.dll", "..\\halo1");
	entireLibraryIsLoaded("halo1\\fmod_event_net64.dll", "..\\halo1");
#endif

	GameLauncher::loadSettings();
#ifdef _WIN64
	HaloReachGameOptionSelection::Init();
#endif
	c_window::RegisterWndProcCallback(WndProc);
	c_debug_gui::register_callback(_callback_mode_always_run, renderMainMenu);
	c_debug_gui::register_callback(_callback_mode_toggleable, renderUI);

	c_window::register_destroy_callback(WindowDestroyCallback);

}

void GameLauncher::Deinit()
{
	c_window::unregister_destroy_callback(WindowDestroyCallback);
	c_debug_gui::UnregisterCallback(_callback_mode_always_run, renderMainMenu);
	c_debug_gui::UnregisterCallback(_callback_mode_toggleable, renderUI);
	c_window::UnregisterWndProcCallback(WndProc);
#ifdef _WIN64
	HaloReachGameOptionSelection::Deinit();
#endif
}

void GameLauncher::WindowDestroyCallback()
{
	// terrible hack but lets tell the game to quit and then wait for no game to be running
	if (s_gameRunning)
	{
		IGameEngine* pGameEngine = pCurrentGameHost->get_game_engine();
		pGameEngine->UpdateEngineState(eEngineState::ImmediateExit);
		write_line_verbose("Waiting for game to exit...");
		while (s_gameRunning) { Sleep(1); }
	}
}

void GameLauncher::loadSettings()
{
	float horizontalSensitivity = Settings::ReadFloatValue(SettingsSection::Controls, "HorizontalSensitivity", 1.0f);
	float verticalSensitivity = Settings::ReadFloatValue(SettingsSection::Controls, "VerticalSensitivity", 1.0f);
	MouseInput::SetSensitivity(horizontalSensitivity, verticalSensitivity);
}

void GameLauncher::OpusTick()
{
	if (!s_gameRunning)
	{
		update();
	}

	c_debug_gui::StartFrame(); // OpusUITick is registered to the DebugUI
	//OpusUITick();
	if (c_debug_gui::IsRendering() && s_gameRunning) // render a debug layer for the game to render text to
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
		ImGui::SetNextWindowSize(ImVec2(static_cast<float>(c_window::get_width()), static_cast<float>(c_window::get_height())), ImGuiCond_Always);
		if (ImGui::Begin("##debug", NULL, kDebugWindowFlags)) // render inside of the dummy imgui window for on screen text display
		{
			gameRender();
		}
		ImGui::End();
	}
	c_debug_gui::EndFrame();
}

void GameLauncher::update()
{
	if (s_gameRunning)
	{
		// need some place to update the launcher, might as well do it here for now
		c_window::UpdateNoCallbacks();
	}
	else
	{
		if (s_nextLaunchMode != NextLaunchMode::None)
		{
			s_nextLaunchMode = NextLaunchMode::None;
			launchGame(s_nextLaunchEngine);
		}
	}
}

void GameLauncher::gameRender()
{
	c_mantle_gui::render_in_game_gui();
	c_primitive_render_manager::Render();
}

void GameLauncher::renderUI()
{
	c_mantle_gui::render_gui();
	if (s_gameRunning)
	{
		pCurrentGameHost->render_ui();
	}
}

void GameLauncher::launchGame(e_engine_type engine_type)
{
	s_gameRunning = true;
	// #TODO: We currently can't resize the game without crashing
	// we should do this at the beginning of the frame. 

	c_render::SetResizeEnabled(false);
	switch (engine_type)
	{
#ifdef _WIN64
	case _engine_type_halo1:
		launchHalo1();
		break;
	case _engine_type_halo_reach:
		launchHaloReach();
		break;
#else
	case _engine_type_eldorado:
		launchEldorado();
		break;
#endif
	}
	c_render::SetResizeEnabled(true);

	s_gameRunning = false;
}
#ifdef _WIN64
void GameLauncher::launchHalo1()
{
	ASSERT(pCurrentGameHost == nullptr);

	e_engine_type engine_type = _engine_type_halo1;
	e_build build = c_halo1_game_host::get_game_runtime().get_build();

	pCurrentGameHost = new c_halo1_game_host(engine_type, build);
	ASSERT(pCurrentGameHost != nullptr);
	IGameEngine* pGameEngine = pCurrentGameHost->get_game_engine();
	ASSERT(pGameEngine != nullptr);


	// #TODO: Game specific version of this!!!

	for (GenericGameEvent gameEvent : s_gameStartupEvent)
	{
		gameEvent(engine_type, build);
	}

	GameContext gameContext = {};
	{
		//const MapInfo* pSelectedMapInfo = HaloReachGameOptionSelection::GetSelectedMapInfo();
		e_game_mode gameMode = HaloReachGameOptionSelection::GetSelectedGameMode();

		//const char* pMapFileName = pSelectedMapInfo->GetMapFileName();
		//write_line_verbose("Loading map '%s.map'", pMapFileName);
		//{
		//	wchar_t pMapFilePathBuffer[MAX_PATH + 1] = {};
		//	_snwprintf(pMapFilePathBuffer, MAX_PATH, L"%S%S.map", "halo1/maps/", pMapFileName);
		//	MantleGUI::OpenMapFile(pMapFilePathBuffer);
		//}

		gameContext.pGameHandle = GetModuleHandle("Halo1.dll");
		char byte2B678Data[] = { 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
		memcpy(gameContext.byte2B678, byte2B678Data, sizeof(byte2B678Data)); // what the hell is this?

		{
			uint64_t SquadAddress = 0x2F385E2E95D4F33E;
			uint64_t HostAddress = 0xDEADBEEFDEADBEEF;
			uint64_t ClientAddress = 0xCAFEBABECAFEBABE;

			gameContext.SessionInfo.SquadAddress = SquadAddress; // this is set

			gameContext.GameMode = _game_mode_campaign;

			gameContext.SessionInfo.PeerIdentifierCount = 1;
			gameContext.SessionInfo.SessionMembership.Count = 1;
			gameContext.SessionInfo.IsHost = true;
			if (gameContext.SessionInfo.IsHost)
			{
				//gameContext.MapId = static_cast<MapID>(pSelectedMapInfo->GetMapID());
				gameContext.MapId = (e_map_id)(3);
				gameContext.CampaignDifficultyLevel = e_campaign_difficulty_level::_campaign_difficulty_level_easy;

				//HaloReachGameOptionSelection::LoadGameVariant(HaloReachGameHost::GetDataAccess(), HaloReachGameOptionSelection::s_pLaunchGameVariant.c_str(), *reinterpret_cast<s_game_variant*>(gameContext.GameVariantBuffer), true);
				//HaloReachGameOptionSelection::LoadMapVariant(HaloReachGameHost::GetDataAccess(), HaloReachGameOptionSelection::s_pLaunchMapVariant.c_str(), *reinterpret_cast<s_map_variant*>(gameContext.MapVariantBuffer), true);
				//HaloReachGameOptionSelection::LoadPreviousGamestate("gamestate", gameContext);
				//HaloReachGameOptionSelection::LoadSavedFilmMetadata(HaloReachGameOptionSelection::s_pLaunchSavedFilm.c_str(), gameContext);

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

	pGameEngine->InitGraphics(c_render::s_pDevice, c_render::s_pDeviceContext, c_render::s_pSwapChain, c_render::s_pSwapChain);

	{
		// useful for testing if the gameenginehostcallback vftable is correct or not
		static constexpr bool kBogusGameEngineHostCallbackVFT = false;
		if constexpr (kBogusGameEngineHostCallbackVFT)
		{
			void*& pGameEngineHostVftable = *reinterpret_cast<void**>(pCurrentGameHost);
			static char data[sizeof(void*) * 1024] = {};
			memset(data, -1, sizeof(data));
			static constexpr size_t kNumBytesToCopyFromExistingVFT = 0;
			memcpy(data, pGameEngineHostVftable, kNumBytesToCopyFromExistingVFT);
			pGameEngineHostVftable = data;
		}
	}

	IGameEngineHost* game_engine_host = pCurrentGameHost->GetDynamicGameEngineHost();
	static HANDLE hMainGameThread = pGameEngine->InitThread(game_engine_host, &gameContext);
	c_window::SetPostMessageThreadId(hMainGameThread);

	// #TODO: Absolutely terrible thread sync here
	{
		std::thread thread([]() {

			WaitForSingleObject(hMainGameThread, INFINITE);
			s_gameRunning = false;
			});
		while (s_gameRunning)
		{
			update();
			SwitchToThread(); // don't smash the CPU
		}
		thread.join();
	}


	//HRESULT waitForSingleObjectResult;
	//do
	//{
	//	update();
	//	waitForSingleObjectResult = WaitForSingleObject(hMainGameThread, 5);
	//} while (waitForSingleObjectResult == WAIT_TIMEOUT);
	//WaitForSingleObject(hMainGameThread, INFINITE);

	write_line_verbose("Game has exited.");

	for (GenericGameEvent gameEvent : s_gameShutdownEvent)
	{
		gameEvent(engine_type, build);
	}

	delete pCurrentGameHost;
	pCurrentGameHost = nullptr;

	// reset runtime information after we've destroyed the engine
	//s_pCurrentGameRuntime = nullptr;
}

void GameLauncher::launchHaloReach()
{
	ASSERT(pCurrentGameHost == nullptr);

	e_engine_type engine_type = _engine_type_halo_reach;
	e_build build = c_halo_reach_game_host::get_game_runtime().get_build();

	pCurrentGameHost = new c_halo_reach_game_host(engine_type, build);
	ASSERT(pCurrentGameHost != nullptr);
	IGameEngine* pGameEngine = pCurrentGameHost->get_game_engine();
	ASSERT(pGameEngine != nullptr);


	// #TODO: Game specific version of this!!!

	for (GenericGameEvent gameEvent : s_gameStartupEvent)
	{
		gameEvent(engine_type, build);
	}

	GameContext gameContext = {};
	{
		const MapInfo* pSelectedMapInfo = HaloReachGameOptionSelection::GetSelectedMapInfo();
		e_game_mode gameMode = HaloReachGameOptionSelection::GetSelectedGameMode();

		const char* pMapFileName = pSelectedMapInfo->GetMapFileName();
		write_line_verbose("Loading map '%s.map'", pMapFileName);
		{
			wchar_t pMapFilePathBuffer[MAX_PATH + 1] = {};
			_snwprintf(pMapFilePathBuffer, MAX_PATH, L"%S%S.map", "haloreach/maps/", pMapFileName);
			c_mantle_gui::open_cache_file_from_filepath(pMapFilePathBuffer);
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
				gameContext.MapId = static_cast<e_map_id>(pSelectedMapInfo->GetMapID());
				gameContext.CampaignDifficultyLevel = e_campaign_difficulty_level::_campaign_difficulty_level_easy;

				HaloReachGameOptionSelection::LoadGameVariant(c_halo_reach_game_host::get_data_access(), HaloReachGameOptionSelection::s_pLaunchGameVariant.c_str(), *reinterpret_cast<s_game_variant*>(gameContext.GameVariantBuffer), true);
				HaloReachGameOptionSelection::LoadMapVariant(c_halo_reach_game_host::get_data_access(), HaloReachGameOptionSelection::s_pLaunchMapVariant.c_str(), *reinterpret_cast<s_map_variant*>(gameContext.MapVariantBuffer), true);
				//HaloReachGameOptionSelection::LoadPreviousGamestate("gamestate", gameContext);
				//HaloReachGameOptionSelection::LoadSavedFilmMetadata(HaloReachGameOptionSelection::s_pLaunchSavedFilm.c_str(), gameContext);

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

	pGameEngine->InitGraphics(c_render::s_pDevice, c_render::s_pDeviceContext, c_render::s_pSwapChain, c_render::s_pSwapChain);

	{
		// useful for testing if the gameenginehostcallback vftable is correct or not
		static constexpr bool kBogusGameEngineHostCallbackVFT = false;
		if constexpr (kBogusGameEngineHostCallbackVFT)
		{
			void*& pGameEngineHostVftable = *reinterpret_cast<void**>(pCurrentGameHost);
			static char data[sizeof(void*) * 1024] = {};
			memset(data, -1, sizeof(data));
			static constexpr size_t kNumBytesToCopyFromExistingVFT = 0;
			memcpy(data, pGameEngineHostVftable, kNumBytesToCopyFromExistingVFT);
			pGameEngineHostVftable = data;
		}
	}
	
	IGameEngineHost* game_engine_host = pCurrentGameHost->GetDynamicGameEngineHost();
	static HANDLE hMainGameThread = pGameEngine->InitThread(game_engine_host, &gameContext);
	c_window::SetPostMessageThreadId(hMainGameThread);

	// #TODO: Absolutely terrible thread sync here
	{
		std::thread thread([]() {

			WaitForSingleObject(hMainGameThread, INFINITE);
			s_gameRunning = false;
			});
		while (s_gameRunning)
		{
			update();
			SwitchToThread(); // don't smash the CPU
		}
		thread.join();
	}


	//HRESULT waitForSingleObjectResult;
	//do
	//{
	//	update();
	//	waitForSingleObjectResult = WaitForSingleObject(hMainGameThread, 5);
	//} while (waitForSingleObjectResult == WAIT_TIMEOUT);
	//WaitForSingleObject(hMainGameThread, INFINITE);

	write_line_verbose("Game has exited.");

	for (GenericGameEvent gameEvent : s_gameShutdownEvent)
	{
		gameEvent(engine_type, build);
	}

	delete pCurrentGameHost;
	pCurrentGameHost = nullptr;

	// reset runtime information after we've destroyed the engine
	//s_pCurrentGameRuntime = nullptr;
}
#else
void GameLauncher::launchEldorado()
{

}
#endif
void GameLauncher::checkSteamOwnership()
{
#ifdef _WIN64
	{
		FILE* pAppIDFile = fopen("steam_appid.txt", "w");
		ASSERT(pAppIDFile != nullptr);
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
#endif
}

void GameLauncher::entireLibraryIsLoaded(const char* pLibName, const char* pFallbackDir)
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
		MessageBox(c_window::GetWindowHandle(), pLibName, "failed to load library", MB_ICONERROR);
	}
	ASSERT(hModule != NULL);
}

void GameLauncher::renderMainMenu()
{
	if (s_gameRunning) return;

	MouseInput::SetMode(MouseMode::UI);

	float width = static_cast<float>(GetSystemMetrics(SM_CXSCREEN));
	float height = static_cast<float>(GetSystemMetrics(SM_CYSCREEN));

	ImVec2 globalWindowSize = ImVec2(static_cast<float>(c_window::get_width()), static_cast<float>(c_window::get_height()));
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
		static bool hasAutostarted = false;
#ifdef _WIN64
		HaloReachGameOptionSelection::Render();
		{
			ImGui::Dummy(ImVec2(0.0f, 30.0f));

			if (ImGui::Button("START GAME (Reach)") || (c_command_line::has_command_line_arg("-autostart") && !hasAutostarted))
			{
				HaloReachGameOptionSelection::s_pLaunchSavedFilm = "";
				hasAutostarted = true;
				s_nextLaunchMode = NextLaunchMode::Generic;
				s_nextLaunchEngine = _engine_type_halo_reach;
			}

			if (ImGui::Button("PLAY FILM (Reach)") || GetKeyState('P') & 0x80)
			{
				s_nextLaunchMode = NextLaunchMode::Theater;
				s_nextLaunchEngine = _engine_type_halo_reach;
			}

			if (ImGui::Button("START GAME (Halo 1)") || (c_command_line::has_command_line_arg("-autostarthalo1") && !hasAutostarted))
			{
				HaloReachGameOptionSelection::s_pLaunchSavedFilm = "";
				hasAutostarted = true;
				s_nextLaunchMode = NextLaunchMode::Generic;
				s_nextLaunchEngine = _engine_type_halo1;
			}
		}
#else
		{
			if (ImGui::Button("START GAME (Eldorado)") || (c_command_line::has_command_line_arg("-autostart") && !hasAutostarted))
			{
				hasAutostarted = true;
				s_nextLaunchMode = NextLaunchMode::Generic;
				s_nextLaunchEngine = _engine_type_eldorado;
	}
		}
#endif
		ImGui::Dummy(ImVec2(0.0f, 20.0f));
		if (ImGui::Button("QUIT TO DESKTOP"))
		{
			exit(0);
		}
	}
	ImGui::End();
}

void GameLauncher::renderPauseMenu()
{
	MouseInput::SetMode(MouseMode::UI);

	float width = static_cast<float>(GetSystemMetrics(SM_CXSCREEN));
	float height = static_cast<float>(GetSystemMetrics(SM_CYSCREEN));

	ImVec2 globalWindowSize = ImVec2(static_cast<float>(c_window::get_width()), static_cast<float>(c_window::get_height()));
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


