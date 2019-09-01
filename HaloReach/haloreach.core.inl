/*
	this function is the games main routine. inside of here sits the
	main_loop function call
*/intptr_t main_thread_routine_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1800129B0;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x18000FF50;
	}
	return ~intptr_t();
}
FunctionHookEx<main_thread_routine_offset, void *__stdcall ()> main_thread_routine = { "main_thread_routine", []()
{
	WriteLineVerbose("Starting game...");
	g_CurrentGameState = CurrentState::eRunning;
	g_isHooked = true;
	auto result = main_thread_routine();
	WriteLineVerbose("Game finished...");
	WriteLineVerbose("Last status: [0x%X] %s", g_lastGameLoadStatus, g_lastGameLoadStatusStr.c_str());
	g_CurrentGameState = CurrentState::eFinished;
	g_isHooked = false;
	return result;
} };

/*
	override for the halo reach default path
*/intptr_t game_get_haloreach_path_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x180012730;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x18000FD20;
	}
	return ~intptr_t();
}
FunctionHookEx<game_get_haloreach_path_offset, const char *()> game_get_haloreach_path = { "game_get_haloreach_path", []()
{
	return g_haloReachPathOverride;
} };

//intptr_t sub_1800122F0_offset(HaloGameID gameID)
//{
//	switch (gameID)
//	{
//	case HaloGameID::HaloReach_2019_Jun_24: return 0x1800122F0;
//	case HaloGameID::HaloReach_2019_Aug_20: return 0x18000FD20;
//	}
//	return ~intptr_t();
//}
//FunctionHookEx<sub_1800122F0_offset, int()> sub_1800122F0 = { "sub_1800122F0", []() // TODO: add proper name
//{
//	auto callback = []() { return sub_1800122F0(); };
//	return IGameEngineHost::GEHCBypass<IGameEngineHost::GEHCBypassType::UseValidPointer>(g_game_engine_host_pointer, callback);
//} };

intptr_t initialize_window_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1806C2890;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x18040C5E0;
	}
	return ~intptr_t();
}
FunctionHookEx<initialize_window_offset, HWND()> initialize_window = []()
{
	return IGameEngineHost::GEHCBypass<IGameEngineHost::GEHCBypassType::UseNullPointer>(g_game_engine_host_pointer, []()
		{
			HMODULE hHaloReachModule = GetModuleHandleA(GetHaloExecutableString(HaloGameID::HaloReach_2019_Jun_24));
			assert(hHaloReachModule);

			g_WndProc = CustomWindow::WndProc;
			g_hInstance = hHaloReachModule;

			memcpy(&ClassName[0], "HaloReach", sizeof("HaloReach"));
			memcpy(&WindowName[0], "HaloReach", sizeof("HaloReach"));

			HWND hWnd = initialize_window();

			if (g_hideWindowOnStartup == false)
			{
				ShowWindow(hWnd, SW_SHOW);
			}

			// #TODO: Use callbacks to create the window upfront!
			CustomWindow::s_hwnd = hWnd;

			SendMessage(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)CustomWindow::GetIcon());
			return hWnd;
		}
	);
};

//FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x18000F8D0, int()> sub_18000F8D0 = []()
//{
//	auto callback = [=]() { return sub_18000F8D0(); };
//	return IGameEngineHost::GEHCBypass<IGameEngineHost::GEHCBypassType::UseValidPointer>(g_game_engine_host_pointer, callback);
//};

intptr_t load_state_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1810EC5A4;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x180D37AB0;
	}
	return ~intptr_t();
}
DataEx<int, load_state_offset> load_state;

intptr_t network_squad_session_get_machine_count_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: FATAL_ERROR("Unknown address"); return 0;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x180485E20;
	}
	return ~intptr_t();
}

extern s_game_launch_data game_launch_data;
FunctionHookEx<network_squad_session_get_machine_count_offset, __int64()> network_squad_session_get_machine_count = []()
{
	return network_squad_session_get_machine_count();
};

intptr_t main_game_launch_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x180013EA0;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x1800113F0;
	}
	return ~intptr_t();
}
FunctionHookEx<main_game_launch_offset, char __fastcall (__int64 a1, __int64 a2)> main_game_launch = { "main_game_launch", [](__int64 a1, __int64 a2)
{
	const char *load_state_names[] =
	{
		"initial",
		"create_local_squad",
		"select_game_mode",
		"saved_film",
		"campaign",
		"previous_game_state",
		"multiplayer",
		"survival",
		"wait_for_party",
		"join_remote_squad",
		"unused",
		"start_game",
		"finished"
	};

	static int previous_load_state = k_load_state_invalid;

	if ((int)load_state != previous_load_state)
	{
		previous_load_state = load_state;
		printf("load_state changed to: %s\n", load_state_names[(int)load_state]);
	}

	auto result = main_game_launch(a1, a2);

	if ((int)load_state == _load_state_wait_for_party)
	{
		static __int64 last_network_squad_session_machine_count = 0;
		__int64 network_squad_session_machine_count = network_squad_session_get_machine_count();
		if (last_network_squad_session_machine_count != network_squad_session_machine_count)
		{
			last_network_squad_session_machine_count = network_squad_session_machine_count;
			WriteLineVerbose("Machine Count Changed: %i", (int)network_squad_session_machine_count);
		}
	}

	if ((int)load_state != previous_load_state)
	{
		previous_load_state = load_state;
		printf("load_state changed to: %s\n", load_state_names[(int)load_state]);
	}

	return result;
} };

/*intptr_t DamagedMediaHaltAndDisplayError_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x18078C550;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x18049FBB0;
	}
	return ~intptr_t();
}
FunctionHookVarArgsEx<DamagedMediaHaltAndDisplayError_offset, void(const char *format, ...)> DamagedMediaHaltAndDisplayError = { "DamagedMediaHaltAndDisplayError", [](const char *format, ...)
{
	va_list args;
	va_start(args, format);

	// #TODO: Assuming this buffer is big enough
	char buffer[8192] = {};
	vsnprintf(buffer, 8192, format, args);
	buffer[sizeof(buffer) - 1] = 0;

	va_end(args);

	MessageBox(CustomWindow::GetWindowHandle(), "dirty_disk_error", buffer, MB_ICONERROR);
} };*/

intptr_t sub_180012200_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x180012200;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x18000F850;
	}
	return ~intptr_t();
}
FunctionHookEx<sub_180012200_offset, __int64(__fastcall)(__int64 a1)> sub_180012200 = { "sub_180012200", [](__int64 a1) // TODO: add proper name
{
	// g_gameEngineHostCallback is normally nulled out by other code.
	// it is perfectly okay to just use a bypass here but I have
	// left it out just in case as it is currently not exploding

	__int64 result; // rax

	result = static_cast<DWORD>(dword_1810EC584);
	if (!dword_1810EC584)
	{
		result = a1;
	}
	dword_1810EC584 = static_cast<DWORD>(result);
	if (g_game_engine_host_pointer)
	{
		WriteLineVerbose("sub_180012200: Aborting!");

		byte_18342E55D = 1;
		__int64 wait_for_render_thread_result = wait_for_render_thread();
		byte_183984DE4 = 1; // this instructs the main_loop to exit
		if (result & 1)
		{
			_InterlockedExchange(dword_1810524AC.ptr(), -1);
			restricted_region_unlock_primary(6);
			result = restricted_region_unlock_primary(3);
		}
		if (wait_for_render_thread_result & 2)
		{
			result = _InterlockedCompareExchange(g_render_thread_mode.volatile_ptr(), 1, 0);
		}
	}

	return result;
} };

intptr_t levels_try_and_get_scenario_path_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1803A6B30;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x1801C3660;
	}
	return ~intptr_t();
}
//typedef char *(__fastcall levels_try_and_get_scenario_path_func)(int campaign_id, unsigned int map_id, char *scenario_path, int size);
//FunctionHookEx<levels_try_and_get_scenario_path_offset, levels_try_and_get_scenario_path_func> levels_try_and_get_scenario_path = { "levels_try_and_get_scenario_path", [](int campaign_id, unsigned int map_id, char* scenario_path, int size)
//{
//	map_id = 0x10231971; // force the default map load code path
//
//	auto result = levels_try_and_get_scenario_path(campaign_id, map_id, scenario_path, size);
//
//	if (strlen(scenario_path) == 0)
//	{
//		WriteLineVerbose("WARNING: The map name is not set!");
//		WriteLineVerbose("SELECTED MAP: <none>");
//		ThrowDebugger();
//	}
//	else if (strstr(scenario_path, "mainmenu") != 0)
//	{
//		WriteLineVerbose("WARNING: The mainmenu is not supported!");
//	}
//	else
//	{
//		WriteLineVerbose("SELECTED MAP: %s", scenario_path);
//	}
//
//	// forceload a different map file
//	sprintf(scenario_path, "maps\\%s.map", g_LaunchMapName);
//
//	WriteLineVerbose("MAP OVERRIDE: %s", scenario_path);
//
//	return result;
//} };
