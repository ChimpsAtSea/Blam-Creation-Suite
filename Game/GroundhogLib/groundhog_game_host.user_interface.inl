
#pragma region Screen Patches
// skip the `shell_get_external_host()` check that prevents the game from using the built-in start menu
uintptr_t groundhog_start_menu_screen_patch_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_groundhog, _build_mcc_1_1871_0_0, 0x1804CB1FA);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1955_0_0, 0x1803A3A6E);
	OFFSET(_engine_type_groundhog, _build_mcc_1_2028_0_0, 0x1803A3ACE);
	OFFSET(_engine_type_groundhog, _build_mcc_1_2094_0_0, 0x1803A3ACE);
	return ~uintptr_t();
}
c_data_patch<groundhog_start_menu_screen_patch_offset> groundhog_start_menu_screen_patch = { [](s_engine_platform_build engine_platform_build, char* data, DataPatchPacket& packet)
{
	UINT8 jmp[1] = { 0xEB };
	packet = MAKE_DATAPATCHPACKET(data, sizeof(jmp));
	copy_to_address(data, jmp, sizeof(jmp));
} };
#pragma endregion
