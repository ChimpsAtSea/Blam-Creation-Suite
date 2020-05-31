//struct s_game_options;
//
//uintptr_t main_game_start_offset(e_engine_type engine_type, e_build build)
//{
//	OFFSET(Engine::Eldorado, Build::Eldorado_1_106708_cert_ms23, 0x00567E40);
//	return ~uintptr_t();
//}
//FunctionHookVarArgsEx<main_game_start_offset, char __cdecl (s_game_options * game_options)> main_game_start = { "main_game_start", [](s_game_options* game_options)
//{
//	write_line_verbose("main_game_start called!");
//	return main_game_start(game_options);
//}};

uintptr_t c_stop_watch__start_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_eldorado, _build_eldorado_1_106708_cert_ms23, 0x005547F0);
	OFFSET(_engine_type_eldorado, _build_eldorado_1_604673_Live, 0x004CD0F0);
	OFFSET(_engine_type_eldorado, _build_eldorado_1_700255_cert_ms30_oct19, 0x004CF170);
	return ~uintptr_t();
}
FunctionHookEx<c_stop_watch__start_offset, void()> c_stop_watch__start = { "c_stop_watch__start", []()
{
	RUNONCE(c_console::show_startup_banner());
	c_console::Update();
	return c_stop_watch__start();
}};

//uintptr_t language_patch_offset(e_engine_type engine_type, e_build build)
//{
//	OFFSET(_engine_type_eldorado, _build_eldorado_1_106708_cert_ms23, 0x006333FD);
//	return ~uintptr_t();
//}
//c_data_patch<language_patch_offset> language_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
//{
//		// English patch
//		packet = MAKE_DATAPATCHPACKET(data, 1);
//		data[0] = 0i8; // #TODO: Add multi language support
//}};

std::vector<uintptr_t> enable_tag_edits_patch_offsets(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_eldorado, _build_eldorado_1_106708_cert_ms23,       0x00501A5B, 0x00502874, 0x005030AA);
	OFFSET(_engine_type_eldorado, _build_eldorado_1_604673_Live,            0x00482DB4, 0x004830FA, 0x00483AFC);
	OFFSET(_engine_type_eldorado, _build_eldorado_1_700255_cert_ms30_oct19, 0x00483934, 0x00483C9A, 0x004847A9);
	return {};
}

c_multi_data_patch<enable_tag_edits_patch_offsets> enable_tag_edits_patch = { [](e_engine_type engine_type, e_build build, char* data[], DataPatchPackets& packets)
{
	UINT8 jmp[1] = { 0xEB };
	packets.push_back(MAKE_DATAPATCHPACKET(data[0], sizeof(jmp)));
	copy_to_address(data[0], jmp, sizeof(jmp));

	packets.push_back(MAKE_DATAPATCHPACKET(data[1], 2));
	nop_address(data[1], 2);

	packets.push_back(MAKE_DATAPATCHPACKET(data[2], 2));
	nop_address(data[2], 2);
}};

std::vector<uintptr_t> no_account_args_patch_offsets(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_eldorado, _build_eldorado_1_106708_cert_ms23, 0x0083731A, 0x008373AD);
	return {};
}
c_multi_data_patch<no_account_args_patch_offsets> no_account_args_patch = { [](e_engine_type engine_type, e_build build, char* data[], DataPatchPackets& packets)
{
	// No --account args patch
	UINT8 patch0[2] = { 0xEB, 0x0E };
	UINT8 patch1[2] = { 0xEB, 0x03 };

	packets.push_back(MAKE_DATAPATCHPACKET(data[0], sizeof(patch0)));
	copy_to_address(data[0], patch0, sizeof(patch0));

	packets.push_back(MAKE_DATAPATCHPACKET(data[1], sizeof(patch1)));
	copy_to_address(data[1], patch1, sizeof(patch1));
}};

uintptr_t GameShieldInit_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_eldorado, _build_eldorado_1_604673_Live,            0x00752260);
	OFFSET(_engine_type_eldorado, _build_eldorado_1_700255_cert_ms30_oct19, 0x007648E0);
	return ~uintptr_t();
}
FunctionHookEx<GameShieldInit_offset, void()> GameShieldInit = { "GameShieldInit", []()
{
	write_line_verbose("GameShieldInit");
}};

//uintptr_t network_lobby_patch_offset(e_engine_type engine_type, e_build build)
//{
//	OFFSET(_engine_type_eldorado, _build_eldorado_1_106708_cert_ms23, 0x00AC34B0);
//	return ~uintptr_t();
//}
//c_data_patch<network_lobby_patch_offset> network_lobby_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
//{
//	// Fix "Network" setting in lobbies (change broken 0x100B7 menuID to 0x100B6)
//	packet = MAKE_DATAPATCHPACKET(data, 1);
//	data[0] = 0xB6i8;
//}};

//uintptr_t main_menu_ui_elements_patch_offset(e_engine_type engine_type, e_build build)
//{
//	OFFSET(_engine_type_eldorado, _build_eldorado_1_106708_cert_ms23, 0x00AAA870);
//	return ~uintptr_t();
//}
//c_data_patch<main_menu_ui_elements_patch_offset> main_menu_ui_elements_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
//{
//	// Fix UI elements automatically closing on mainmenu-loaded maps (todo: find real reason why they close)
//	packet = MAKE_DATAPATCHPACKET(data, 1);
//	data[0] = 0xC3i8;
//}};

//uintptr_t load_level_patch(e_engine_type engine_type, e_build build)
//{
//	OFFSET(_engine_type_eldorado, _build_eldorado_1_106708_cert_ms23, 0x006D26DF);
//	return ~uintptr_t();
//}
//c_data_patch<load_level_patch_offset> load_level_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
//{
//	// Level load patch
//	packet = MAKE_DATAPATCHPACKET(data, 5);
//	nop_address(data, 5);
//}};

//uintptr_t anti_cheat_patch_offset(e_engine_type engine_type, e_build build)
//{
//	OFFSET(_engine_type_eldorado, _build_eldorado_1_106708_cert_ms23, 0x006006F0);
//	return ~uintptr_t();
//}
//c_data_patch<anti_cheat_patch_offset> anti_cheat_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
//{
//	packet = MAKE_DATAPATCHPACKET(data, 1);
//	data[0] = 0xC3i8;
//}};

uintptr_t Hf2pInit_offset(e_engine_type engine_type, e_build build)
{
	/*
	Notes for MS23
	game_startup_internal > game_startup_client

	For some reason in MS23 we have to butcher the initialization by killing game_startup_internal
	*/
	OFFSET(_engine_type_eldorado, _build_eldorado_1_106708_cert_ms23, 0x00600630); // game_startup_internal
	//OFFSET(Engine::Eldorado, Build::Eldorado_1_106708_cert_ms23, 0x00600990); // game_startup_internal > game_startup_client

	OFFSET(_engine_type_eldorado, _build_eldorado_1_604673_Live, 0x006B0560);

	/*
	Notes for MS30
	sub_6BD670 > sub_6BD0F0 dont run this function
	game_startup_internal > game_startup_client

	For some reason in MS30 we can still run game_startup_client which fixes the main menu
	*/
	OFFSET(_engine_type_eldorado, _build_eldorado_1_700255_cert_ms30_oct19, 0x006BD0F0);
	
	
	return ~uintptr_t();
}
FunctionHookEx<Hf2pInit_offset, void()> Hf2pInit = { "Hf2pInit", []()
{
	write_line_verbose("Hf2pInit_offset");
	if (c_eldorado_game_host::get_build() == _build_eldorado_1_106708_cert_ms23)
	{
		// #TODO: What are these for?
		*(uint32_t*)0x50CCB3C = 0;
		*(uint32_t*)0x244ED28 = 0;
	}
	//InitSoundSystem();
}};

uintptr_t Hf2pShutdown_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_eldorado, _build_eldorado_1_106708_cert_ms23, 0x00600790);
	OFFSET(_engine_type_eldorado, _build_eldorado_1_604673_Live, ~uintptr_t());
	OFFSET(_engine_type_eldorado, _build_eldorado_1_700255_cert_ms30_oct19, ~uintptr_t());
	return ~uintptr_t();
}
FunctionHookEx<Hf2pShutdown_offset, void()> Hf2pShutdown = { "Hf2pShutdown", []()
{
	write_line_verbose("Hf2pShutdown");
	//ShutdownSoundSystem();
}};

//uintptr_t GameClient__Shutdown_offset(e_engine_type engine_type, e_build build)
//{
//	OFFSET(Engine::Eldorado, Build::Eldorado_1_106708_cert_ms23, 0x005056D0);
//	return ~uintptr_t();
//}
//FunctionHookEx<GameClient__Shutdown_offset, void __cdecl()> GameClient__Shutdown = { "GameClient__Shutdown", []()
//{
//	write_line_verbose("GameClient__Shutdown was called");
//	return GameClient__Shutdown();
//}};





uintptr_t contrail_crash_fix_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_eldorado, _build_eldorado_1_106708_cert_ms23, 0x00A57DC0);
	//OFFSET(_engine_type_eldorado, _build_eldorado_1_604673_Live, 0x0068A120);
	//OFFSET(_engine_type_eldorado, _build_eldorado_1_700255_cert_ms30_oct19, 0x00696690);
	return ~uintptr_t();
}
FunctionHookEx<contrail_crash_fix_offset, int(DWORD *, int)> contrail_crash_fix = { "contrail_crash_fix", [](DWORD* _this, int a2)
{
	return contrail_crash_fix(_this, a2);
} };




