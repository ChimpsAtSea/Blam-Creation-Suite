
#pragma region Screen Patches
// skip the `shell_get_external_host()` check that prevents the game from using the built-in start menu
uintptr_t groundhog_start_menu_screen_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_groundhog, _build_mcc_1_1871_0_0, 0x1804CB1FA);
	return ~uintptr_t();
}
c_data_patch<groundhog_start_menu_screen_patch_offset> groundhog_start_menu_screen_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	UINT8 jmp[1] = { 0xEB };
	packet = MAKE_DATAPATCHPACKET(data, sizeof(jmp));
	copy_to_address(data, jmp, sizeof(jmp));
} };
#pragma endregion
