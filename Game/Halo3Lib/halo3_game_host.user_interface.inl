
#pragma region Screen Patches
// skip the `shell_get_external_host()` check that prevents the game from using the built-in start menu
uintptr_t halo3_start_menu_screen_patch_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1804C176B);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x1804BFD89);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x1804BFEA9);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x1804BFEA9);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x18037FD1B);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x18037FE4B);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 0x1803805F6);
	OFFSET(_engine_type_halo3, _build_mcc_1_1829_0_0, 0x180386756);
	OFFSET(_engine_type_halo3, _build_mcc_1_1864_0_0, 0x180386756);
	OFFSET(_engine_type_halo3, _build_mcc_1_1871_0_0, 0x180386756);
	OFFSET(_engine_type_halo3, _build_mcc_1_1955_0_0, 0x1802B2456);
	OFFSET(_engine_type_halo3, _build_mcc_1_2028_0_0, 0x1802B5026);
	OFFSET(_engine_type_halo3, _build_mcc_1_2094_0_0, 0x1802BD92E);
	return ~uintptr_t();
}
c_data_patch<halo3_start_menu_screen_patch_offset> halo3_start_menu_screen_patch = { [](s_engine_platform_build engine_platform_build, char* data, DataPatchPacket& packet)
{
	// nop `test    rax, rax` or `test    r9, r9`
	packet = MAKE_DATAPATCHPACKET(data, 5);
	nop_address(data, 3);

	uint8_t jump[1] { 0x85ui8 };

	if (engine_platform_build.build == _build_mcc_1_1767_0_0)
	{
		copy_to_address(&data[3], &jump, sizeof(jump));
	}
	else if (engine_platform_build.build >= _build_mcc_1_1955_0_0)
	{
		copy_to_address(&data[4], &jump, sizeof(jump));
	}
} };

// this patch shouldn't be needed
uintptr_t halo3_settings_menu_patch2_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1804C183A);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x1804BFE53);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x1804BFF73);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x1804BFF73);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x18037FE41);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x18037FF71);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 0x180380581);
	OFFSET(_engine_type_halo3, _build_mcc_1_1829_0_0, 0x1803866E1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1864_0_0, 0x1803866E1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1871_0_0, 0x1803866E1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1955_0_0, 0x1802B259B);
	OFFSET(_engine_type_halo3, _build_mcc_1_2028_0_0, 0x1802B516B);
	OFFSET(_engine_type_halo3, _build_mcc_1_2094_0_0, 0x1802BDA73);
	return ~uintptr_t();
}
c_data_patch<halo3_settings_menu_patch2_offset> halo3_settings_menu_patch2 = {
	[](s_engine_platform_build engine_platform_build, char* data, DataPatchPacket& packet)
	{
		packet = MAKE_DATAPATCHPACKET(data, 6);
		nop_address(data, 6);
	}
};
#pragma endregion

#pragma region miscellaneous ui changes
bool g_halo3_disable_c_ui_view_render = false;
uintptr_t halo3_c_ui_view_render_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180483500);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x1804822E0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x1804823D0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x1804823D0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x180339290);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x180339380);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 0x18033B350);
	OFFSET(_engine_type_halo3, _build_mcc_1_1829_0_0, 0x18033E520);
	OFFSET(_engine_type_halo3, _build_mcc_1_1864_0_0, 0x18033E520);
	OFFSET(_engine_type_halo3, _build_mcc_1_1871_0_0, 0x18033E520);
	OFFSET(_engine_type_halo3, _build_mcc_1_1955_0_0, 0x18027C880);
	OFFSET(_engine_type_halo3, _build_mcc_1_2028_0_0, 0x18027F394);
	OFFSET(_engine_type_halo3, _build_mcc_1_2094_0_0, 0x180285650);
	return ~uintptr_t();
}
c_function_hook_ex<halo3_c_ui_view_render_offset, void __fastcall(__int64)> halo3_c_ui_view_render = { "halo3_c_ui_view_render", [](__int64 this_ptr)
{
	if (g_halo3_disable_c_ui_view_render)
	{
		return;
	}

	halo3_c_ui_view_render(this_ptr);
} };

uintptr_t halo3_version_number_callback_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1805430F0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x1805419B0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x180541C10);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x180541C10);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x180414140);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x180414270);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 0x180414880);
	OFFSET(_engine_type_halo3, _build_mcc_1_1829_0_0, 0x18041A9F0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1864_0_0, 0x18041A9F0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1871_0_0, 0x18041A9F0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1955_0_0, 0x180320E6C);
	OFFSET(_engine_type_halo3, _build_mcc_1_2028_0_0, 0x180323BDC);
	OFFSET(_engine_type_halo3, _build_mcc_1_2094_0_0, 0x18032D49C);
	return ~uintptr_t();
}
c_function_hook_ex<halo3_version_number_callback_offset, bool __fastcall(__int64, wchar_t*, int)> halo3_version_number_callback = { "halo3_version_number_callback", [](__int64 unused, wchar_t* dst, int len)
{
	e_build build = c_halo3_game_host::get_game_runtime({}).get_build();
	
	const char* build_str;
	ASSERT(BCS_SUCCEEDED(get_build_string(build, &build_str)));
	
	swprintf_s(dst, len, L"%S", build_str);

	return true;
} };
#pragma endregion
