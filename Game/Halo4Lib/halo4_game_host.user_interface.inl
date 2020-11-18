
#pragma region Screen Patches
// skip the `shell_get_external_host()` check that prevents the game from using the built-in start menu
uintptr_t halo4_start_menu_screen_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo4, _build_mcc_1_1896_0_0, 0x1803A11ED);
	OFFSET(_engine_type_halo4, _build_mcc_1_1930_0_0, 0x1803A299D);
	OFFSET(_engine_type_halo4, _build_mcc_1_1955_0_0, 0x1803A29FD);
	return ~uintptr_t();
}
c_data_patch<halo4_start_menu_screen_patch_offset> halo4_start_menu_screen_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	UINT8 jmp[1] = { 0xEB };
	packet = MAKE_DATAPATCHPACKET(data, sizeof(jmp));
	copy_to_address(data, jmp, sizeof(jmp));
} };
#pragma endregion
