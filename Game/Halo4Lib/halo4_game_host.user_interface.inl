
#pragma region Screen Patches
// skip the `shell_get_external_host()` check that prevents the game from using the built-in start menu
uintptr_t halo4_start_menu_screen_patch_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo4, _build_mcc_1_1896_0_0, 0x1803A11ED);
	OFFSET(_engine_type_halo4, _build_mcc_1_1930_0_0, 0x1803A299D);
	OFFSET(_engine_type_halo4, _build_mcc_1_1955_0_0, 0x1803A29FD);
	OFFSET(_engine_type_halo4, _build_mcc_1_2028_0_0, 0x1803A2B5D);
	OFFSET(_engine_type_halo4, _build_mcc_1_2094_0_0, 0x1803A2B5D);
	return ~uintptr_t();
}
c_data_patch<halo4_start_menu_screen_patch_offset> halo4_start_menu_screen_patch = { [](s_engine_platform_build engine_platform_build, char* data, DataPatchPacket& packet)
{
	UINT8 jmp[1] = { 0xEB };
	packet = MAKE_DATAPATCHPACKET(data, sizeof(jmp));
	copy_to_address(data, jmp, sizeof(jmp));
} };
#pragma endregion
