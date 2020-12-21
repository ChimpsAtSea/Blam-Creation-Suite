
#pragma region MCC Parse Hooks
uintptr_t mcc_map_id_parse_from_halo3odst_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1767_0_0, 0x180062770);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1778_0_0, 0x1800625D0);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1792_0_0, 0x180062640);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1829_0_0, 0x1800628E0);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1864_0_0, 0x1800628E0);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1871_0_0, 0x1800628E0);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1955_0_0, 0x18004F580);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_2028_0_0, 0x18004F580);
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
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1864_0_0, 0x180062840);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1871_0_0, 0x180062840);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1955_0_0, 0x18004F4F4);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_2028_0_0, 0x18004F4F4);
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
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1864_0_0, 0x1800145BE + 1);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1871_0_0, 0x1800145BE + 1);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1955_0_0, 0x1800102C7 + 1);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_2028_0_0, 0x1800102C7 + 1);
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
// this patch solves the issue of not being able to load `_scenario_type_mainmenu`
uintptr_t halo3odst_enable_mainmenu_scenario_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1767_0_0, 0x1800A86C2);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1778_0_0, 0x1800A84C2);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1792_0_0, 0x1800A8742);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1829_0_0, 0x1800A9102);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1864_0_0, 0x1800A9102);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1871_0_0, 0x1800A9102);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1955_0_0, 0x180084924);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_2028_0_0, 0x180084924);
	return ~uintptr_t();
}
c_data_patch<halo3odst_enable_mainmenu_scenario_patch_offset> halo3odst_enable_mainmenu_scenario_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	packet = MAKE_DATAPATCHPACKET(data, 6);
	nop_address(data, 6);
} };

// prevents to game from exiting and switching the thread mode to single-threaded for safe engine disposal?
// this patch solves the issue of the mainmenu turning into a slideshow after (overall_timeout=120000)/(individual_state_timeout=60000) milliseconds
uintptr_t halo3odst_external_launch_timeout_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1767_0_0, 0x180032701);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1778_0_0, 0x1800327A1);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1792_0_0, 0x1800327A1);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1829_0_0, 0x180032991);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1864_0_0, 0x180032991);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1871_0_0, 0x180032991);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1955_0_0, 0x18002A877);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_2028_0_0, 0x18002A877);
	return ~uintptr_t();
}
c_data_patch<halo3odst_external_launch_timeout_patch_offset> halo3odst_external_launch_timeout_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
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