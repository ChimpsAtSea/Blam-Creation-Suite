
#pragma region MCC Parse Hooks
uintptr_t game_context_map_id_parse_to_halo3_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1802913C0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18028B920);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18028B9C0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18028B9C0);
	return ~uintptr_t();
}
FunctionHookEx<game_context_map_id_parse_to_halo3_offset, long __fastcall(c_game_context_v3* game_context)> game_context_map_id_parse_to_halo3 = { "game_context_map_id_parse_to_halo3", [](c_game_context_v3* game_context)
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
	return ~uintptr_t();
}
FunctionHookEx<mcc_map_id_parse_from_halo3_offset, long __fastcall(long map_id)> mcc_map_id_parse_from_halo3 = { "mcc_map_id_parse_from_halo3", [](long map_id)
{
	long result = mcc_map_id_parse_from_halo3(map_id);
	return result == -1l ? map_id : result;
} };

uintptr_t mcc_map_id_parse_to_halo3_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1802915C0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18028BB20);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18028BBC0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18028BBC0);
	return ~uintptr_t();
}
FunctionHookEx<mcc_map_id_parse_to_halo3_offset, long __fastcall(long map_id)> mcc_map_id_parse_to_halo3 = { "mcc_map_id_parse_to_halo3", [](long map_id)
{
	long result = mcc_map_id_parse_to_halo3(map_id);
	return result == -1l ? map_id : result;
} };

uintptr_t mcc_game_mode_parse_to_halo3_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180290BD0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18028B130);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18028B1D0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18028B1D0);
	return ~uintptr_t();
}
FunctionHookEx<mcc_game_mode_parse_to_halo3_offset, long __fastcall(c_game_context_v3* game_context)> mcc_game_mode_parse_to_halo3 = { "mcc_game_mode_parse_to_halo3", [](c_game_context_v3* game_context)
{
	long result = mcc_game_mode_parse_to_halo3(game_context);
	return result == 3l ? 2l : result;
} };
#pragma endregion

#pragma region Main Menu Patches
// prevents to game from exiting and switching the thread mode to single-threaded for safe engine disposal?
// this patch solves to issue of not baing able to load `_scenario_type_mainmenu`
uintptr_t enable_mainmenu_scenario_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1802E5FDE);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x1802E06AE);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x1802E07C6);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x1802E07C6);
	return ~uintptr_t();
}
c_data_patch<enable_mainmenu_scenario_patch_offset> enable_mainmenu_scenario_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	packet = MAKE_DATAPATCHPACKET(data, 2);
	nop_address(data, 2);
} };

// prevents to game from exiting and switching the thread mode to single-threaded for safe engine disposal?
// this patch solves to issue of the mainmenu turning into a slideshow after (overall_timeout=120000)/(individual_state_timeout=60000) milliseconds
uintptr_t external_launch_timeout_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180012F60);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18000D2B5);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18000D2F5);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18000D2F5);
	return ~uintptr_t();
}

std::vector<uint8_t> external_launch_timeout_patch_bytes(e_engine_type engine_type, e_build build)
{
	// change instruction from `jump not zero` to `jump` and nop the last byte
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0xE9, 0x31, 0x01, 0x00, 0x00, 0x90);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0xE9, 0xB3, 0x00, 0x00, 0x00, 0x90);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0xE9, 0xB3, 0x00, 0x00, 0x00, 0x90);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0xE9, 0xB3, 0x00, 0x00, 0x00, 0x90);
	return { };
}
c_data_patch<external_launch_timeout_patch_offset> external_launch_timeout_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	std::vector<uint8_t> jmp = external_launch_timeout_patch_bytes(engine_type, build);
	if (!jmp.empty())
	{
		packet = MAKE_DATAPATCHPACKET(jmp.data(), jmp.size());
		copy_to_address(data, jmp.data(), jmp.size());
	}
} };
#pragma endregion