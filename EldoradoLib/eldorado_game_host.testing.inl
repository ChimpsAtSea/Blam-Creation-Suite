//struct s_game_options;
//
//uintptr_t main_game_start_offset(Engine engine, e_build build)
//{
//	OFFSET(Engine::Eldorado, Build::Eldorado_1_106708_cert_ms23, 0x00567E40);
//	return ~uintptr_t();
//}
//FunctionHookVarArgsEx<main_game_start_offset, char __cdecl (s_game_options * game_options)> main_game_start = { "main_game_start", [](s_game_options* game_options)
//{
//	write_line_verbose("main_game_start called!");
//	return main_game_start(game_options);
//} };

uintptr_t c_stop_watch__start_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_eldorado, e_build::_build_eldorado_1_106708_cert_ms23, 0x005547F0);
	OFFSET(_engine_type_eldorado, e_build::_build_eldorado_1_700255_cert_ms30_oct19, 0x004CF170);
	return ~uintptr_t();
}
FunctionHookVarArgsEx<c_stop_watch__start_offset, void()> c_stop_watch__start = { "c_stop_watch__start", []()
{
	RUNONCE(c_console::Startup());
	c_console::Update();
	return c_stop_watch__start();
} };

//uintptr_t language_patch_offset(Engine engine, e_build build)
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

uintptr_t enable_tag_edits_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_eldorado, e_build::_build_eldorado_1_106708_cert_ms23, 0);
	OFFSET(_engine_type_eldorado, e_build::_build_eldorado_1_700255_cert_ms30_oct19, 0);
	return ~uintptr_t();
}
DataPatch<enable_tag_edits_patch_offset> enable_tag_edits = { [](e_engine_type engine_type, e_build build, char*, DataPatchPackets& packets)
{
	// Enable tag edits

	char* patch1 = nullptr;
	char* patch2 = nullptr;
	char* patch3 = nullptr;
	switch (build)
	{
	case e_build::_build_eldorado_1_106708_cert_ms23:
		patch1 = GetEngineVirtualAddress(engine_type, 0x00501A5B);
		patch2 = GetEngineVirtualAddress(engine_type, 0x00502874);
		patch3 = GetEngineVirtualAddress(engine_type, 0x005030AA);
		break;
	case e_build::_build_eldorado_1_700255_cert_ms30_oct19:
		patch1 = GetEngineVirtualAddress(engine_type, 0x00483934);
		patch2 = GetEngineVirtualAddress(engine_type, 0x00483C9A);
		patch3 = GetEngineVirtualAddress(engine_type, 0x004847A9);
		break;
	default:
		return; // skip unknown build
	}

	packets.push_back(MAKE_DATAPATCHPACKET(patch1, 1));
	patch1[0] = 0xEBi8;

	packets.push_back(MAKE_DATAPATCHPACKET(patch2, 2));
	patch2[0] = 0x90i8; // nop
	patch2[1] = 0x90i8; // nop

	packets.push_back(MAKE_DATAPATCHPACKET(patch3, 2));
	patch3[0] = 0x90i8; // nop
	patch3[1] = 0x90i8; // nop
	
} };

uintptr_t no_account_args_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_eldorado, e_build::_build_eldorado_1_106708_cert_ms23, 0);
	return ~uintptr_t();
}
DataPatch<no_account_args_patch_offset> no_account_args_patch = { [](e_engine_type engine_type, e_build build, char*, DataPatchPackets& packets)
{
	// No --account args patch

	if (build == e_build::_build_eldorado_1_106708_cert_ms23)
	{
		char* patch1 = GetEngineVirtualAddress(engine_type, 0x0083731A);
		char* patch2 = GetEngineVirtualAddress(engine_type, 0x008373AD);

		packets.push_back(MAKE_DATAPATCHPACKET(patch1, 1));
		packets.push_back(MAKE_DATAPATCHPACKET(patch2, 2));

		patch1[0] = 0xEBi8;
		patch1[1] = 0x0Ei8;
		patch2[0] = 0xEBi8;
		patch2[1] = 0x03i8;
	}
	
} };

uintptr_t GameShieldInit_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_eldorado, e_build::_build_eldorado_1_700255_cert_ms30_oct19, 0x007648E0);
	return ~uintptr_t();
}
FunctionHookVarArgsEx<GameShieldInit_offset, void()> GameShieldInit = { "GameShieldInit", []()
{
	write_line_verbose("GameShieldInit");
} };

//uintptr_t network_lobby_patch_offset(Engine engine, e_build build)
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
//uintptr_t main_menu_ui_elements_patch_offset(Engine engine, e_build build)
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
//uintptr_t load_level_patch_offset(Engine engine, e_build build)
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
//uintptr_t anti_cheat_patch_offset(Engine engine, e_build build)
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

uintptr_t Hf2pInit_offset(e_engine_type engine_type, e_build build)
{
	/*
	Notes for MS23
	game_startup_internal > game_startup_client

	For some reason in MS23 we have to butcher the initialization by killing game_startup_internal
	*/
	OFFSET(_engine_type_eldorado, e_build::_build_eldorado_1_106708_cert_ms23, 0x00600630); // game_startup_internal
	//OFFSET(Engine::Eldorado, Build::Eldorado_1_106708_cert_ms23, 0x00600990); // game_startup_internal > game_startup_client

	/*
	Notes for MS30
	sub_6BD670 > sub_6BD0F0 dont run this function
	game_startup_internal > game_startup_client

	For some reason in MS30 we can still run game_startup_client which fixes the main menu
	*/
	OFFSET(_engine_type_eldorado, e_build::_build_eldorado_1_700255_cert_ms30_oct19, 0x6BD0F0);
	
	
	return ~uintptr_t();
}
FunctionHookVarArgsEx<Hf2pInit_offset, void()> Hf2pInit = { "Hf2pInit", []()
{
	write_line_verbose("Hf2pInit_offset");
	if (c_eldorado_game_host::get_build() == e_build::_build_eldorado_1_106708_cert_ms23)
	{
		// #TODO: What are these for?
		*(uint32_t*)0x50CCB3C = 0;
		*(uint32_t*)0x244ED28 = 0;
	}
	//InitSoundSystem();
} };

uintptr_t Hf2pShutdown_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_eldorado, e_build::_build_eldorado_1_106708_cert_ms23, 0x00600790);
	OFFSET(_engine_type_eldorado, e_build::_build_eldorado_1_700255_cert_ms30_oct19, ~uintptr_t());
	return ~uintptr_t();
}
FunctionHookVarArgsEx<Hf2pShutdown_offset, void()> Hf2pShutdown = { "Hf2pShutdown", []()
{
	write_line_verbose("Hf2pShutdown");
	//ShutdownSoundSystem();
} };
//
//uintptr_t GameClient__Shutdown_offset(Engine engine, e_build build)
//{
//	OFFSET(Engine::Eldorado, Build::Eldorado_1_106708_cert_ms23, 0x005056D0);
//	return ~uintptr_t();
//}
//FunctionHookVarArgsEx<GameClient__Shutdown_offset, void __cdecl()> GameClient__Shutdown = { "GameClient__Shutdown", []()
//{
//	write_line_verbose("GameClient__Shutdown was called");
//	return GameClient__Shutdown();
//} };




