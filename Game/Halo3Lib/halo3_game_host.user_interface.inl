
#pragma region Screen Patches
// skip the `shell_get_external_host()` check that prevents the game from using the built-in start menu
uintptr_t start_menu_screen_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1804C176B);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x1804BFD89);
	return ~uintptr_t();
}
c_data_patch<start_menu_screen_patch_offset> start_menu_screen_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	// nop `test    rax, rax`
	packet = MAKE_DATAPATCHPACKET(data, 3);
	nop_address(data, 3);
} };

// this patch shouldn't be needed
uintptr_t settings_menu_patch2_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1804C183A);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x1804BFE53);
	return ~uintptr_t();
}
c_data_patch<settings_menu_patch2_offset> settings_menu_patch2 = {
	[](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
	{
		packet = MAKE_DATAPATCHPACKET(data, 6);
		nop_address(data, 6);
	}
};
#pragma endregion