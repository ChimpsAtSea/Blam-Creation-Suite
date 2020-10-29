
#pragma region MCC Parse Hooks
uintptr_t mcc_map_id_parse_from_halo4_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo4, _build_mcc_1_1896_0_0, 0x18007E1A4);
	return ~uintptr_t();
}
c_function_hook_ex<mcc_map_id_parse_from_halo4_offset, long __fastcall(long map_id)> mcc_map_id_parse_from_halo4 = { "mcc_map_id_parse_from_halo4", [](long map_id)
{
	long result = mcc_map_id_parse_from_halo4(map_id);
	return result == -1l ? map_id : result;
} };

uintptr_t mcc_map_id_parse_to_halo4_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo4, _build_mcc_1_1896_0_0, 0x18007DF20);
	return ~uintptr_t();
}
c_function_hook_ex<mcc_map_id_parse_to_halo4_offset, long __fastcall(long map_id)> mcc_map_id_parse_to_halo4 = { "mcc_map_id_parse_to_halo4", [](long map_id)
{
	long result = mcc_map_id_parse_to_halo4(map_id);
	return result == -1l ? map_id : result;
} };

uintptr_t mcc_game_mode_parse_to_halo4_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo4, _build_mcc_1_1896_0_0, 0x18003DBAA + 2);
	return ~uintptr_t();
}
c_data_patch<mcc_game_mode_parse_to_halo4_patch_offset> mcc_game_mode_parse_to_halo4_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	// what the engine does by default
	// mov     ebx, 3
	// lea     eax, [rbx+2] ; 5

	// what we want to do
	// mov     ebx, 3
	// lea     eax, [rbx+1] ; 4

	packet = MAKE_DATAPATCHPACKET(data, 1);
	BYTE shifted_game_mode = 4 - 3;
	copy_to_address(data, &shifted_game_mode, 1);
} };
#pragma endregion

#pragma region Main Menu Patches
size_t halo4_enable_mainmenu_scenario_patch_size(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo4, _build_mcc_1_1896_0_0, 6);
	return ~size_t();
}
// prevents to game from exiting and switching the thread mode to single-threaded for safe engine disposal?
// this patch solves to issue of not baing able to load `_scenario_type_mainmenu`
uintptr_t halo4_enable_mainmenu_scenario_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo4, _build_mcc_1_1896_0_0, 0x180104510);
	return ~uintptr_t();
}
c_data_patch<halo4_enable_mainmenu_scenario_patch_offset> halo4_enable_mainmenu_scenario_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	size_t patch_size = halo4_enable_mainmenu_scenario_patch_size(engine_type, build);
	if (patch_size != ~size_t())
	{
		packet = MAKE_DATAPATCHPACKET(data, patch_size);
		nop_address(data, patch_size);
	}
} };

// prevents to game from exiting and switching the thread mode to single-threaded for safe engine disposal?
// this patch solves to issue of the mainmenu turning into a slideshow after (overall_timeout=120000)/(individual_state_timeout=60000) milliseconds
uintptr_t halo4_external_launch_timeout_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo4, _build_mcc_1_1896_0_0, 0x180066F6B);
	return ~uintptr_t();
}

std::vector<uint8_t> halo4_external_launch_timeout_patch_bytes(e_engine_type engine_type, e_build build)
{
	// change instruction from `jump not zero` to `jump` and nop the last byte
	OFFSET(_engine_type_halo4, _build_mcc_1_1896_0_0, 0xE9, 0xDB, 0x00, 0x00, 0x00, 0x90);
	return { };
}
c_data_patch<halo4_external_launch_timeout_patch_offset> halo4_external_launch_timeout_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	std::vector<uint8_t> jmp = halo4_external_launch_timeout_patch_bytes(engine_type, build);
	if (!jmp.empty())
	{
		packet = MAKE_DATAPATCHPACKET(jmp.data(), jmp.size());
		copy_to_address(data, jmp.data(), jmp.size());
	}
} };
#pragma endregion