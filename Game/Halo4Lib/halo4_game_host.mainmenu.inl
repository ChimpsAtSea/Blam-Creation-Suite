
#pragma region MCC Parse Hooks
uintptr_t mcc_map_id_parse_from_halo4_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo4, _build_mcc_1_1896_0_0, 0x18007E1A4);
	OFFSET(_engine_type_halo4, _build_mcc_1_1930_0_0, 0x18007E1C4);
	OFFSET(_engine_type_halo4, _build_mcc_1_1955_0_0, 0x18007E1C4);
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
	OFFSET(_engine_type_halo4, _build_mcc_1_1930_0_0, 0x18007DF40);
	OFFSET(_engine_type_halo4, _build_mcc_1_1955_0_0, 0x18007DF40);
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
	OFFSET(_engine_type_halo4, _build_mcc_1_1930_0_0, 0x18003DBB6 + 2);
	OFFSET(_engine_type_halo4, _build_mcc_1_1955_0_0, 0x18003DBB6 + 2);
	return ~uintptr_t();
}
c_data_patch<mcc_game_mode_parse_to_halo4_patch_offset> mcc_game_mode_parse_to_halo4_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	// default
	// mov     ebx, 3
	// lea     eax, [rbx+2] ; 5

	// patch
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
	OFFSET(_engine_type_halo4, _build_mcc_1_1930_0_0, 6);
	OFFSET(_engine_type_halo4, _build_mcc_1_1955_0_0, 6);
	return ~size_t();
}
// prevents to game from exiting and switching the thread mode to single-threaded for safe engine disposal?
// this patch solves the issue of not being able to load `_scenario_type_mainmenu`
// if no mainmenu map exists the game will crash with the error `we would have shown the damaged media ui here, but then we wouldn't know about the failure!`
uintptr_t halo4_enable_mainmenu_scenario_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo4, _build_mcc_1_1896_0_0, 0x180104510);
	OFFSET(_engine_type_halo4, _build_mcc_1_1930_0_0, 0x180105888);
	OFFSET(_engine_type_halo4, _build_mcc_1_1955_0_0, 0x1801058D8);
	return ~uintptr_t();
}
c_data_patch<halo4_enable_mainmenu_scenario_patch_offset> halo4_enable_mainmenu_scenario_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	size_t patch_size = halo4_enable_mainmenu_scenario_patch_size(engine_type, build);
	packet = MAKE_DATAPATCHPACKET(data, patch_size);
	// commented out until we actually have a mainmenu to use
	//nop_address(data, patch_size);
} };

// prevents to game from exiting and switching the thread mode to single-threaded for safe engine disposal?
// this patch solves the issue of the mainmenu turning into a slideshow after (overall_timeout=120000)/(individual_state_timeout=60000) milliseconds
uintptr_t halo4_external_launch_timeout_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo4, _build_mcc_1_1896_0_0, 0x180066F6B);
	OFFSET(_engine_type_halo4, _build_mcc_1_1930_0_0, 0x180066F8B);
	OFFSET(_engine_type_halo4, _build_mcc_1_1955_0_0, 0x180066F8B);
	return ~uintptr_t();
}
c_data_patch<halo4_external_launch_timeout_patch_offset> halo4_external_launch_timeout_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	uint8_t jump[6] { 0x90ui8, 0x90ui8, 0x90ui8, 0x90ui8, 0x90ui8, 0x90ui8 };
	packet = MAKE_DATAPATCHPACKET(data, sizeof(jump));

	// 0F 85 cw/cd 	JNE rel16/32 	Jump near if not equal (ZF=0)
	// 0F 85 cw/cd 	JNZ rel16/32 	Jump near if not zero (ZF=0)
	if (data[0] == 0x0Fi8 && data[1] == 0x85i8) // check the type of jump is JNE/JNZ
	{
		// set the type of jump to JMP
		jump[0] = 0xE9ui8;
		// set the relative offset
		*(uint32_t*)&jump[1] = (*(uint32_t*)&data[2]) + 1;

		copy_to_address(data, jump, sizeof(jump));
	}
} };
#pragma endregion