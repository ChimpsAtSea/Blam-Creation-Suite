//struct s_game_options;
//
//uintptr_t main_game_start_offset(Engine engine, Build build)
//{
//	OFFSET(Engine::Eldorado, Build::Eldorado_1_106708_cert_ms23, 0x00567E40);
//	return ~uintptr_t();
//}
//FunctionHookVarArgsEx<main_game_start_offset, char __cdecl (s_game_options * game_options)> main_game_start = { "main_game_start", [](s_game_options* game_options)
//{
//	WriteLineVerbose("main_game_start called!");
//	return main_game_start(game_options);
//} };
//
//uintptr_t c_stop_watch__start_offset(Engine engine, Build build)
//{
//	OFFSET(Engine::Eldorado, Build::Eldorado_1_106708_cert_ms23, 0x005547F0);
//	return ~uintptr_t();
//}
//FunctionHookVarArgsEx<c_stop_watch__start_offset, void()> c_stop_watch__start = { "c_stop_watch__start", []()
//{
//	RUNONCE(Console::Startup());
//	Console::Update();
//	return c_stop_watch__start();
//} };
//
//uintptr_t language_patch_offset(Engine engine, Build build)
//{
//	OFFSET(Engine::Eldorado, Build::Eldorado_1_106708_cert_ms23, 0x006333FD);
//	return ~uintptr_t();
//}
//DataPatch<language_patch_offset> language_patch = { [](Engine, Build, char* data, DataPatchPacket& packet)
//{
//	// English patch
//
//	char* language_patch_data = data;
//	packet = MAKE_DATAPATCHPACKET(language_patch_data, 1);
//	data[0] = 0; // #TODO: Add multi language support
//} };

uintptr_t enable_tag_edits_patch_offset(Engine engine, Build build)
{
	OFFSET(Engine::Eldorado, Build::Eldorado_1_106708_cert_ms23, 0);
	OFFSET(Engine::Eldorado, Build::Eldorado_1_700255_cert_ms30_oct19, 0);
	return ~uintptr_t();
}
DataPatch<enable_tag_edits_patch_offset> enable_tag_edits = { [](Engine engine, Build build, char*, DataPatchPackets& packets)
{
	// Enable tag edits

	if (build == Build::Eldorado_1_106708_cert_ms23)
	{
		{
			char* patch1 = GetEngineVirtualAddress(engine, 0x00501A5B);
			packets.push_back(MAKE_DATAPATCHPACKET(patch1, 1));
			patch1[0] = 0xEBi8;
		}
		{
			char* patch2 = GetEngineVirtualAddress(engine, 0x00502874);
			packets.push_back(MAKE_DATAPATCHPACKET(patch2, 2));
			patch2[0] = 0x90i8; // nop
			patch2[1] = 0x90i8; // nop
		}
		{
			char* patch3 = GetEngineVirtualAddress(engine, 0x005030AA);
			packets.push_back(MAKE_DATAPATCHPACKET(patch3, 2));
			patch3[0] = 0x90i8; // nop
			patch3[1] = 0x90i8; // nop
		}
	}
	if (build == Build::Eldorado_1_700255_cert_ms30_oct19)
	{
		
	}
	
} };

uintptr_t no_account_args_patch_offset(Engine engine, Build build)
{
	OFFSET(Engine::Eldorado, Build::Eldorado_1_106708_cert_ms23, 0);
	OFFSET(Engine::Eldorado, Build::Eldorado_1_700255_cert_ms30_oct19, 0);
	return ~uintptr_t();
}
DataPatch<no_account_args_patch_offset> no_account_args_patch = { [](Engine engine, Build build, char*, DataPatchPackets& packets)
{
	// No --account args patch

	if (build == Build::Eldorado_1_106708_cert_ms23)
	{
		char* patch1 = GetEngineVirtualAddress(engine, 0x0083731A);
		char* patch2 = GetEngineVirtualAddress(engine, 0x008373AD);

		packets.push_back(MAKE_DATAPATCHPACKET(patch1, 1));
		packets.push_back(MAKE_DATAPATCHPACKET(patch2, 2));

		patch1[0] = 0xEBi8;
		patch1[1] = 0x0Ei8;
		patch2[0] = 0xEBi8;
		patch2[1] = 0x03i8;
	}
	if (build == Build::Eldorado_1_700255_cert_ms30_oct19)
	{

	}
	
} };

//uintptr_t network_lobby_patch_offset(Engine engine, Build build)
//{
//	OFFSET(Engine::Eldorado, Build::Eldorado_1_106708_cert_ms23, 0x00AC34B0);
//	return ~uintptr_t();
//}
//DataPatch<network_lobby_patch_offset> network_lobby_patch = { [](Engine engine, Build, char* data, DataPatchPacket& packet)
//{
//	// Fix "Network" setting in lobbies (change broken 0x100B7 menuID to 0x100B6)
//
//	char* network_lobby_patch_data = data;
//	packet = MAKE_DATAPATCHPACKET(network_lobby_patch_data, 1);
//	*network_lobby_patch_data = 0xB6i8;
//} };
//
//uintptr_t main_menu_ui_elements_patch_offset(Engine engine, Build build)
//{
//	OFFSET(Engine::Eldorado, Build::Eldorado_1_106708_cert_ms23, 0x00AAA870);
//	return ~uintptr_t();
//}
//DataPatch<main_menu_ui_elements_patch_offset> main_menu_ui_elements_patch = { [](Engine engine, Build, char* data, DataPatchPacket& packet)
//{
//	// Fix UI elements automatically closing on mainmenu-loaded maps (todo: find real reason why they close)
//
//	char* network_lobby_patch_data = data;
//	packet = MAKE_DATAPATCHPACKET(network_lobby_patch_data, 1);
//	*network_lobby_patch_data = 0xC3i8;
//} };
//
//uintptr_t load_level_patch_offset(Engine engine, Build build)
//{
//	OFFSET(Engine::Eldorado, Build::Eldorado_1_106708_cert_ms23, 0x006D26DF);
//	return ~uintptr_t();
//}
//DataPatch<load_level_patch_offset> load_level_patch = { [](Engine engine, Build, char* data, DataPatchPacket& packet)
//{
//	// Level load patch
//
//	char* load_level_patch_data = data;
//	packet = MAKE_DATAPATCHPACKET(load_level_patch_data, 5);
//	memset(load_level_patch_data, 0x90, 5); // nop
//} };
//
//uintptr_t anti_cheat_patch_offset(Engine engine, Build build)
//{
//	OFFSET(Engine::Eldorado, Build::Eldorado_1_106708_cert_ms23, 0x006006F0);
//	return ~uintptr_t();
//}
//DataPatch<anti_cheat_patch_offset> anti_cheat_patch = { [](Engine engine, Build, char* data, DataPatchPacket& packet)
//{
//	// Level load patch
//
//	packet = MAKE_DATAPATCHPACKET(data, 1);
//	data[0] = 0xC3;
//} };

uintptr_t Hf2pInit_offset(Engine engine, Build build)
{
	OFFSET(Engine::Eldorado, Build::Eldorado_1_106708_cert_ms23, 0x00600630);
	OFFSET(Engine::Eldorado, Build::Eldorado_1_700255_cert_ms30_oct19, 0);
	return ~uintptr_t();
}
FunctionHookVarArgsEx<Hf2pInit_offset, void()> Hf2pInit = { "Hf2pInit", []()
{
	WriteLineVerbose("Hf2pInit_offset");
		*(uint32_t*)0x50CCB3C = 0;
		*(uint32_t*)0x244ED28 = 0;
	//InitSoundSystem();
} };

uintptr_t Hf2pShutdown_offset(Engine engine, Build build)
{
	OFFSET(Engine::Eldorado, Build::Eldorado_1_106708_cert_ms23, 0x00600790);
	OFFSET(Engine::Eldorado, Build::Eldorado_1_700255_cert_ms30_oct19, 0);
	return ~uintptr_t();
}
FunctionHookVarArgsEx<Hf2pShutdown_offset, void()> Hf2pShutdown = { "Hf2pShutdown", []()
{
	WriteLineVerbose("Hf2pShutdown");
	//ShutdownSoundSystem();
} };
//
//uintptr_t GameClient__Shutdown_offset(Engine engine, Build build)
//{
//	OFFSET(Engine::Eldorado, Build::Eldorado_1_106708_cert_ms23, 0x005056D0);
//	return ~uintptr_t();
//}
//FunctionHookVarArgsEx<GameClient__Shutdown_offset, void __cdecl()> GameClient__Shutdown = { "GameClient__Shutdown", []()
//{
//	WriteLineVerbose("GameClient__Shutdown was called");
//	return GameClient__Shutdown();
//} };




