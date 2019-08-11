
HaloReachHook<0x180013090, __int64 __fastcall (__int64 a1)> sub_180013090 = [](__int64 a1)
{
	auto result = sub_180013090(a1);
	auto game_options = (s_game_options*)(a1 + 2280);
	return result;
};

HaloReachHook<0x18034A7E0, bool __fastcall (s_game_options* a1)> game_options_verify = [](s_game_options* a1)
{
	auto result = game_options_verify(a1);
	WriteLineVerbose("s_game_options::scenario_path: %s", a1->scenario_path);
	return result;
};

HaloReachHook<0x1803C9220, __int64 __fastcall (s_game_options* a1)> load_scenario_into_game_options = [](s_game_options* a1)
{
	auto result = load_scenario_into_game_options(a1);

	// TODO

	return result;
};

HaloReachHook<0x180108FB0, char* __fastcall (uint8_t* pSimulationWatcher, char* dst)> simulation_watcher_get_status = [](uint8_t* pSimulationWatcher, char* dst)
{
	auto result = simulation_watcher_get_status(pSimulationWatcher, dst);
	printf("%s\n%s\n", dst, result);
	return result;
};

