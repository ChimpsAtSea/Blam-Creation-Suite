
#pragma region MCC Parse Hooks
uintptr_t game_context_map_id_parse_to_halo3_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1802913C0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18028B920);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18028B9C0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18028B9C0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, ~uintptr_t()); // doesn't exist in this build
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, ~uintptr_t()); // doesn't exist in this build
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, ~uintptr_t()); // doesn't exist in this build
	return ~uintptr_t();
}
c_function_hook_ex<game_context_map_id_parse_to_halo3_offset, long __fastcall(c_game_context_v3* game_context)> game_context_map_id_parse_to_halo3 = { "game_context_map_id_parse_to_halo3", [](c_game_context_v3* game_context)
{
	long result = game_context_map_id_parse_to_halo3(game_context);
	return result == -1l ? game_context->map_id : result;
} };

uintptr_t mcc_map_id_parse_from_halo3_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180290FC0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18028B520);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18028B5C0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18028B5C0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x18011D980);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x18011D980);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 0x18011DE50);
	return ~uintptr_t();
}
c_function_hook_ex<mcc_map_id_parse_from_halo3_offset, long __fastcall(long map_id)> mcc_map_id_parse_from_halo3 = { "mcc_map_id_parse_from_halo3", [](long map_id)
{
	long result = mcc_map_id_parse_from_halo3(map_id);
	return result == -1l ? map_id : result;
} };

bool launched_as_mainmenu = false;
uintptr_t mcc_map_id_parse_to_halo3_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1802915C0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18028BB20);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18028BBC0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18028BBC0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x18011D780);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x18011D780);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 0x18011DC50);
	return ~uintptr_t();
}
c_function_hook_ex<mcc_map_id_parse_to_halo3_offset, long __fastcall(long map_id)> mcc_map_id_parse_to_halo3 = { "mcc_map_id_parse_to_halo3", [](long map_id)
{
	launched_as_mainmenu = map_id == _map_id_mainmenu;
	long result = mcc_map_id_parse_to_halo3(map_id);
	return result == -1l ? map_id : result;
} };

uintptr_t mcc_game_mode_parse_to_halo3_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180290BE1 + 1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18028B141 + 1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18028B1E1 + 1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18028B1E1 + 1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x18000F1E8 + 1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x18000F1E8 + 1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 0x18000F5E8 + 1);
	return ~uintptr_t();
}
c_data_patch<mcc_game_mode_parse_to_halo3_patch_offset> mcc_game_mode_parse_to_halo3_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	packet = MAKE_DATAPATCHPACKET(data, 4);
	int game_mode = 2;
	copy_to_address(data, &game_mode, 4);
} };
#pragma endregion

#pragma region Main Menu Patches
size_t halo3_enable_mainmenu_scenario_patch_size(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 2);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 2);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 2);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 2);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 2);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 6);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 6);
	return ~size_t();
}
// prevents to game from exiting and switching the thread mode to single-threaded for safe engine disposal?
// this patch solves to issue of not baing able to load `_scenario_type_mainmenu`
uintptr_t halo3_enable_mainmenu_scenario_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1802E5FDE);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x1802E06AE);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x1802E07C6);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x1802E07C6);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x1801752B5);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x180175345);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 0x180175815);
	return ~uintptr_t();
}
c_data_patch<halo3_enable_mainmenu_scenario_patch_offset> halo3_enable_mainmenu_scenario_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	size_t patch_size = halo3_enable_mainmenu_scenario_patch_size(engine_type, build);
	if (patch_size != ~size_t())
	{
		packet = MAKE_DATAPATCHPACKET(data, patch_size);
		nop_address(data, patch_size);
	}
} };

// prevents to game from exiting and switching the thread mode to single-threaded for safe engine disposal?
// this patch solves to issue of the mainmenu turning into a slideshow after (overall_timeout=120000)/(individual_state_timeout=60000) milliseconds
uintptr_t halo3_external_launch_timeout_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180012F60);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18000D2B5);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18000D2F5);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18000D2F5);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x1800ED051);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x1800ED051);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 0x1800ED451);
	return ~uintptr_t();
}

std::vector<uint8_t> halo3_external_launch_timeout_patch_bytes(e_engine_type engine_type, e_build build)
{
	// change instruction from `jump not zero` to `jump` and nop the last byte
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0xE9, 0x31, 0x01, 0x00, 0x00, 0x90);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0xE9, 0xB3, 0x00, 0x00, 0x00, 0x90);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0xE9, 0xB3, 0x00, 0x00, 0x00, 0x90);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0xE9, 0xB3, 0x00, 0x00, 0x00, 0x90);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0xE9, 0xDA, 0x00, 0x00, 0x00, 0x90);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0xE9, 0xDA, 0x00, 0x00, 0x00, 0x90);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 0xE9, 0xDA, 0x00, 0x00, 0x00, 0x90);
	return { };
}
c_data_patch<halo3_external_launch_timeout_patch_offset> halo3_external_launch_timeout_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	std::vector<uint8_t> jmp = halo3_external_launch_timeout_patch_bytes(engine_type, build);
	if (!jmp.empty())
	{
		packet = MAKE_DATAPATCHPACKET(jmp.data(), jmp.size());
		copy_to_address(data, jmp.data(), jmp.size());
	}
} };

// prevents a crash with the matchmaking lobby
uintptr_t ui_game_mode_request_change_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1801A3C60);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18019DEC0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x1804B7070);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x1804B7070);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x18001C3D0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x18001C3D0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 0x18001C7D0);
	return ~uintptr_t();
}
c_function_hook_ex<ui_game_mode_request_change_offset, char __fastcall(int)> ui_game_mode_request_change = { "ui_game_mode_request_change", [](int ui_game_mode)
{
	if (launched_as_mainmenu || ui_game_mode == 1)
	{
		launched_as_mainmenu = false;
		ui_game_mode = 0;
	}

	char result = ui_game_mode_request_change(ui_game_mode);

	return result;
} };
#pragma endregion