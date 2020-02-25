
struct s_game_options;

intptr_t main_game_start_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	if (engineVersion == EngineVersion::Eldorado)
	{
		switch (buildVersion)
		{
		case BuildVersion::Eldorado_1_106708_cert_ms23: return 0x00567E40;
		}
	}
	return ~intptr_t();
}
FunctionHookVarArgsEx<main_game_start_offset, char __cdecl (s_game_options * game_options)> main_game_start = { "main_game_start", [](s_game_options* game_options)
{
	WriteLineVerbose("main_game_start called!");
	return main_game_start(game_options);
} };

intptr_t c_stop_watch__start_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	if (engineVersion == EngineVersion::Eldorado)
	{
		switch (buildVersion)
		{
		case BuildVersion::Eldorado_1_106708_cert_ms23: return 0x005547F0;
		}
	}
	return ~intptr_t();
}
FunctionHookVarArgsEx<c_stop_watch__start_offset, void ()> c_stop_watch__start = { "c_stop_watch__start", []()
{
	RUNONCE(Console::Startup());
	Console::Update();
	return c_stop_watch__start();
} };
