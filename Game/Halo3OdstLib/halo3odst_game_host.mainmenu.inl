
#pragma region MCC Parse Hooks
uintptr_t game_context_map_id_parse_to_halo3odst_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1767_0_0, ~uintptr_t());
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1778_0_0, ~uintptr_t());
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1792_0_0, ~uintptr_t());
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1829_0_0, ~uintptr_t());
	return ~uintptr_t();
}
c_function_hook_ex<game_context_map_id_parse_to_halo3odst_offset, long __fastcall(c_game_context_v3* game_context)> game_context_map_id_parse_to_halo3odst = { "game_context_map_id_parse_to_halo3odst", [](c_game_context_v3* game_context)
{
	long result = game_context_map_id_parse_to_halo3odst(game_context);
	return result == -1l ? game_context->map_id : result;
} };

uintptr_t mcc_map_id_parse_from_halo3odst_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1767_0_0, 0x180062770);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1778_0_0, 0x1800625D0);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1792_0_0, 0x180062640);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1829_0_0, 0x1800628E0);
	return ~uintptr_t();
}
c_function_hook_ex<mcc_map_id_parse_from_halo3odst_offset, long __fastcall(long map_id)> mcc_map_id_parse_from_halo3odst = { "mcc_map_id_parse_from_halo3odst", [](long map_id)
{
	long result = mcc_map_id_parse_from_halo3odst(map_id);
	return result == -1l ? map_id : result;
} };

uintptr_t mcc_map_id_parse_to_halo3odst_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1767_0_0, 0x1800626D0);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1778_0_0, 0x180062530);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1792_0_0, 0x1800625A0);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1829_0_0, 0x180062840);
	return ~uintptr_t();
}
c_function_hook_ex<mcc_map_id_parse_to_halo3odst_offset, long __fastcall(long map_id)> mcc_map_id_parse_to_halo3odst = { "mcc_map_id_parse_to_halo3odst", [](long map_id)
{
	long result = mcc_map_id_parse_to_halo3odst(map_id);
	return result == -1l ? map_id : result;
} };

uintptr_t mcc_game_mode_parse_to_halo3odst_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1767_0_0, 0x18001456D + 1);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1778_0_0, 0x18001456D + 1);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1792_0_0, 0x18001456D + 1);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1829_0_0, 0x1800145BE + 1);
	return ~uintptr_t();
}
c_data_patch<mcc_game_mode_parse_to_halo3odst_patch_offset> mcc_game_mode_parse_to_halo3odst_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	packet = MAKE_DATAPATCHPACKET(data, 4);
	int game_mode = 2;
	copy_to_address(data, &game_mode, 4);
} };
#pragma endregion

#pragma region Main Menu Patches
// prevents to game from exiting and switching the thread mode to single-threaded for safe engine disposal?
// this patch solves to issue of not baing able to load `_scenario_type_mainmenu`
uintptr_t halo3odst_enable_mainmenu_scenario_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1767_0_0, 0x1800A86C2);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1778_0_0, 0x1800A84C2);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1792_0_0, 0x1800A8742);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1829_0_0, 0x1800A9102);
	return ~uintptr_t();
}
c_data_patch<halo3odst_enable_mainmenu_scenario_patch_offset> halo3odst_enable_mainmenu_scenario_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	packet = MAKE_DATAPATCHPACKET(data, 6);
	nop_address(data, 6);
} };

// prevents to game from exiting and switching the thread mode to single-threaded for safe engine disposal?
// this patch solves to issue of the mainmenu turning into a slideshow after (overall_timeout=120000)/(individual_state_timeout=60000) milliseconds
uintptr_t halo3odst_external_launch_timeout_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1767_0_0, 0x180032701);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1778_0_0, 0x1800327A1);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1792_0_0, 0x1800327A1);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1829_0_0, 0x180032991);
	return ~uintptr_t();
}

std::vector<uint8_t> halo3odst_external_launch_timeout_patch_bytes(e_engine_type engine_type, e_build build)
{
	// change instruction from `jump not zero` to `jump` and nop the last byte
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1767_0_0, 0xE9, 0xDA, 0x00, 0x00, 0x00, 0x90);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1778_0_0, 0xE9, 0xDA, 0x00, 0x00, 0x00, 0x90);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1792_0_0, 0xE9, 0xDA, 0x00, 0x00, 0x00, 0x90);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1829_0_0, 0xE9, 0xDB, 0x00, 0x00, 0x00, 0x90);
	return { };
}
c_data_patch<halo3odst_external_launch_timeout_patch_offset> halo3odst_external_launch_timeout_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	std::vector<uint8_t> jmp = halo3odst_external_launch_timeout_patch_bytes(engine_type, build);
	if (!jmp.empty())
	{
		packet = MAKE_DATAPATCHPACKET(jmp.data(), jmp.size());
		copy_to_address(data, jmp.data(), jmp.size());
	}
} };
#pragma endregion