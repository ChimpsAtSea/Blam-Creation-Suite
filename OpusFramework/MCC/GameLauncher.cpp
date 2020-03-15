#include "opusframework-private-pch.h"


NextLaunchMode g_next_launch_mode = NextLaunchMode::None;


std::vector<GameLauncher::GenericGameEvent> GameLauncher::s_gameStartupEvent;
std::vector<GameLauncher::GenericGameEvent> GameLauncher::s_gameShutdownEvent;
bool GameLauncher::s_gameRunning = false;
c_opus_game_engine_host* pCurrentGameHost = nullptr;

e_engine_type k_supported_engines[] =
{
#ifdef _WIN64
	_engine_type_halo1,
	_engine_type_halo_reach,
#else
	_engine_type_eldorado
#endif
};
e_engine_type g_engine_type = k_supported_engines[0];

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

static bool has_auto_started = false;
static bool k_autostart_halo_reach = false;
static bool k_autostart_halo_halo1 = false;
static bool k_autostart_halo_eldorado = false;
static bool k_autostart_halo_online = false;

void GameLauncher::Init()
{
	k_autostart_halo_reach = c_command_line::get_command_line_arg("-autostart") == "haloreach";
	k_autostart_halo_halo1 = c_command_line::get_command_line_arg("-autostart") == "halo1";
	k_autostart_halo_eldorado = c_command_line::get_command_line_arg("-autostart") == "eldorado";
	k_autostart_halo_online = c_command_line::get_command_line_arg("-autostart") == "haloonline";

#ifdef _WIN64
	checkSteamOwnership();
	entireLibraryIsLoaded("steam_api64.dll", "MCC\\Binaries\\Win64");
	entireLibraryIsLoaded("bink2w64.dll", "MCC\\Binaries\\Win64");
	if (PathFileExistsA("halo1\\halo1.dll"))
	{
		// #TODO: New home for this in Halo1Lib
		entireLibraryIsLoaded("halo1\\fmodex64.dll", "..\\halo1");
		entireLibraryIsLoaded("halo1\\fmod_event_net64.dll", "..\\halo1");
	}
#endif

	GameLauncher::loadSettings();
#ifdef _WIN64
	HaloReachGameOptionSelection::Init();
#endif
	c_window::RegisterWndProcCallback(WndProc);
	c_debug_gui::register_callback(_callback_mode_always_run, renderMainMenu);
	c_debug_gui::register_callback(_callback_mode_toggleable, renderUI);

	c_window::register_destroy_callback(WindowDestroyCallback);

	if (!has_auto_started)
	{
		if (!k_autostart_halo_reach) startGame(_engine_type_halo_reach, NextLaunchMode::Generic);
		if (!k_autostart_halo_halo1) startGame(_engine_type_halo1, NextLaunchMode::Generic);
		if (!k_autostart_halo_eldorado || !k_autostart_halo_online) startGame(_engine_type_eldorado, NextLaunchMode::Generic);
	}
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
		if (g_next_launch_mode != NextLaunchMode::None)
		{
			g_next_launch_mode = NextLaunchMode::None;
			launchGame(g_engine_type);
		}
	}
}

void GameLauncher::gameRender()
{
	c_mantle_gui::render_in_game_gui();
	c_primitive_render_manager::Render();
}

void GameLauncher::startGame(e_engine_type engine_type, NextLaunchMode next_launch_mode)
{
	g_engine_type = engine_type;
	g_next_launch_mode = next_launch_mode;

#ifdef _WIN64
	HaloReachGameOptionSelection::s_pLaunchSavedFilm = "";
#endif
	has_auto_started = true;
	g_next_launch_mode = NextLaunchMode::Generic;

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
	case _engine_type_halo_reach:
		launchMCCGame(engine_type);
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
void GameLauncher::launchMCCGame(e_engine_type engine_type)
{
	ASSERT(pCurrentGameHost == nullptr);

	e_build build = _build_not_set;
	switch (engine_type)
	{
	case _engine_type_halo1:
		build = c_halo_reach_game_host::get_game_runtime().get_build();
		pCurrentGameHost = new c_halo1_game_host(engine_type, build);
		break;
	case _engine_type_halo_reach:
		build = c_halo_reach_game_host::get_game_runtime().get_build();
		pCurrentGameHost = new c_halo_reach_game_host(engine_type, build);
		break;
	default:
		write_line_verbose(__FUNCTION__"> unknown engine_type");
		return;
	}
	ASSERT(pCurrentGameHost != nullptr);
	IGameEngine* pGameEngine = pCurrentGameHost->get_game_engine();
	ASSERT(pGameEngine != nullptr);

	// #TODO: Game specific version of this!!!

	for (GenericGameEvent gameEvent : s_gameStartupEvent)
	{
		gameEvent(engine_type, build);
	}

	GameContext* game_context = nullptr;
	c_session_manager::create_game_context(build, &game_context);
	ASSERT(game_context);

	{
		// #TODO: Make a home for this
		if (game_context->is_host)
		{
			if (engine_type == _engine_type_halo1)
			{
				game_context->game_mode = _game_mode_campaign;
				game_context->map_id = (e_map_id)(3);
				game_context->campaign_difficulty_level = _campaign_difficulty_level_easy;
			}
			else if (engine_type == _engine_type_halo_reach)
			{
				const MapInfo* pSelectedMapInfo = HaloReachGameOptionSelection::GetSelectedMapInfo();
				e_game_mode gameMode = HaloReachGameOptionSelection::GetSelectedGameMode();

				game_context->game_mode = gameMode;
				game_context->map_id = static_cast<e_map_id>(pSelectedMapInfo->GetMapID());
				game_context->campaign_difficulty_level = _campaign_difficulty_level_easy;

				HaloReachGameOptionSelection::LoadGameVariant(c_halo_reach_game_host::get_data_access(), HaloReachGameOptionSelection::s_pLaunchGameVariant.c_str(), *reinterpret_cast<s_game_variant*>(game_context->game_variant_buffer), true);
				HaloReachGameOptionSelection::LoadMapVariant(c_halo_reach_game_host::get_data_access(), HaloReachGameOptionSelection::s_pLaunchMapVariant.c_str(), *reinterpret_cast<s_map_variant*>(game_context->map_variant_buffer), true);
				//HaloReachGameOptionSelection::LoadPreviousGamestate("gamestate", gameContext);
				//HaloReachGameOptionSelection::LoadSavedFilmMetadata(HaloReachGameOptionSelection::s_pLaunchSavedFilm.c_str(), gameContext);

				{
					// #TODO: Move this over to a IGameEngineHost callback so when a new map is loaded we load the cache file into mantle
					const char* pMapFileName = pSelectedMapInfo->GetMapFileName();
					write_line_verbose("Loading map '%s.map'", pMapFileName);
					{
						wchar_t pMapFilePathBuffer[MAX_PATH + 1] = {};
						_snwprintf(pMapFilePathBuffer, MAX_PATH, L"%S%S.map", "haloreach/maps/", pMapFileName);
						c_mantle_gui::open_cache_file_from_filepath(pMapFilePathBuffer);
					}
				}
			}
		}
	}

	{
		// useful for testing if the gameenginehostcallback vftable is correct or not
		constexpr bool kBogusGameEngineHostCallbackVFT = false;
		if constexpr (kBogusGameEngineHostCallbackVFT)
		{
			void*& pGameEngineHostVftable = *reinterpret_cast<void**>(pCurrentGameHost);
			static char data[sizeof(void*) * 1024] = {};
			memset(data, -1, sizeof(data));
			constexpr size_t kNumBytesToCopyFromExistingVFT = 0;
			memcpy(data, pGameEngineHostVftable, kNumBytesToCopyFromExistingVFT);
			pGameEngineHostVftable = data;
		}
	}

	IGameEngineHost* game_engine_host = pCurrentGameHost->GetDynamicGameEngineHost();
	static HANDLE hMainGameThread = NULL;

	pGameEngine->Member04(c_render::s_pDevice);
	pGameEngine->Member05(game_context->map_id);
	pGameEngine->InitGraphics(c_render::s_pDevice, c_render::s_pDeviceContext, c_render::s_pSwapChain, c_render::s_pSwapChain);
	hMainGameThread = pGameEngine->InitThread(game_engine_host, game_context);

	c_window::set_post_message_thread_id(hMainGameThread);

	// #TODO: Absolutely terrible thread sync here
	{
		std::thread thread([]()
			{

				if (g_engine_type == _engine_type_halo1)
				{
					// we should fix this by listening to engine messages using the MCC layer to determine
					// when a game has actually exited.
					while (true) {}; // hasty hax because the thread closes too soon!
				}
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

	delete game_context;


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

	ImVec2 globalWindowSize = ImVec2(static_cast<float>(c_window::get_width()), static_cast<float>(c_window::get_height()));
	ImVec2 windowSize = ImVec2(globalWindowSize.x * 0.75f, globalWindowSize.y * 0.75f);
	ImVec2 windowOffset = ImVec2((globalWindowSize.x - windowSize.x) / 2.0f, (globalWindowSize.y - windowSize.y) / 2.0f);
	ImGui::SetNextWindowSize(windowSize, ImGuiCond_Always);
	ImGui::SetNextWindowPos(windowOffset, ImGuiCond_Always);

	constexpr ImGuiWindowFlags window_flags =
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_NoTitleBar |
		ImGuiWindowFlags_NoMove |
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoSavedSettings;
	if (ImGui::Begin("Main Menu", nullptr, window_flags))
	{
		ImGui::Columns(2);
		ImGui::SetColumnOffset(1, c_window::get_width() * 0.5f);

		const char* current_engine_name = engine_type_to_nice_name(g_engine_type);
		if (ImGui::BeginCombo("engine type combo", current_engine_name))
		{
			for (e_engine_type supported_engine_type : k_supported_engines)
			{
				const char* supported_engine_name = engine_type_to_nice_name(supported_engine_type);
				if (ImGui::Selectable(supported_engine_name))
				{
					g_engine_type = supported_engine_type;
				}
			}

			ImGui::EndCombo();
		}

		switch (g_engine_type)
		{
#ifdef _WIN64
		case _engine_type_halo1:
			break;
		case _engine_type_halo_reach:
			HaloReachGameOptionSelection::Render();
			break;
#else
		case _engine_type_eldorado:
			break;
#endif
		}

		ImGui::Dummy(ImVec2(0.0f, 30.0f));

		if (ImGui::Button("START GAME"))
		{
			startGame(g_engine_type, NextLaunchMode::Generic);
		}

		if (g_engine_type == _engine_type_halo_reach)
		{
			if (ImGui::Button("PLAY FILM"))
			{
				startGame(g_engine_type, NextLaunchMode::Theater);
			}
		}

		ImGui::Dummy(ImVec2(0.0f, 20.0f));
		if (ImGui::Button("QUIT TO DESKTOP"))
		{
			exit(0); // #TODO: Exit properly
		}

		ImGui::NextColumn();
		ImGui::Text("My Game Session");
		ImGui::Dummy(ImVec2(0.0f, 10.0f));
		// #TODO: Display session information
		//for (size_t player_index = 0; player_index < game_context->player_count; player_index++)
		//{
		//	ImGui::Text("Player xuid[%llx]", game_context.players[player_index].xbox_user_id);
		//}

		ImGui::Dummy(ImVec2(0.0f, 50.0f));
		ImGui::Text("Friends");
		ImGui::Dummy(ImVec2(0.0f, 10.0f));
		// #TODO: Display friends information

		ImGui::Columns(1);

		ImGui::End();
	}
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

