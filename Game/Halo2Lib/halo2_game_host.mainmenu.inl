
struct s_halo2_map_info
{
	uint32_t internal_id;
	e_map_id mcc_id;
	const char* scenario_name;
	const wchar_t* scenario_name_wide;
};

uintptr_t halo2_map_info_table_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo2, _build_mcc_1_1477_0_0, 0x180EECE30);
	OFFSET(_engine_type_halo2, _build_mcc_1_1499_0_0, 0x180EECE30);
	OFFSET(_engine_type_halo2, _build_mcc_1_1520_0_0, 0x180EEEE30);
	OFFSET(_engine_type_halo2, _build_mcc_1_1570_0_0, 0x180EEEE30);
	OFFSET(_engine_type_halo2, _build_mcc_1_1619_0_0, 0x180EEEE30);
	OFFSET(_engine_type_halo2, _build_mcc_1_1698_0_0, 0x180A47940);
	OFFSET(_engine_type_halo2, _build_mcc_1_1716_0_0, 0x180A47940);
	OFFSET(_engine_type_halo2, _build_mcc_1_1829_0_0, 0x180A48940);
	OFFSET(_engine_type_halo2, _build_mcc_1_1864_0_0, 0x180A48940);
	OFFSET(_engine_type_halo2, _build_mcc_1_1871_0_0, 0x180A48940);
	OFFSET(_engine_type_halo2, _build_mcc_1_1955_0_0, 0x180A48940);
	OFFSET(_engine_type_halo2, _build_mcc_1_2028_0_0, 0x180A48940);
	OFFSET(_engine_type_halo2, _build_mcc_1_2094_0_0, 0x180A48940);
	return ~uintptr_t();
}
s_halo2_map_info(&halo2_map_info_table)[40] = reference_symbol<s_halo2_map_info[40]>("halo2_map_info_table", halo2_map_info_table_offset);

uintptr_t halo2_map_info_table_patch_offset(s_engine_platform_build engine_platform_build)
{
	return halo2_map_info_table_offset(engine_platform_build);
}
c_data_patch<halo2_map_info_table_patch_offset> halo2_map_info_table_patch =
{
	[](s_engine_platform_build engine_platform_build, char*, DataPatchPacket& packet)
	{
		packet = MAKE_DATAPATCHPACKET(&halo2_map_info_table, sizeof(halo2_map_info_table));

		DWORD old_protect;
		VirtualProtect(&halo2_map_info_table, sizeof(halo2_map_info_table), PAGE_EXECUTE_READWRITE, &old_protect);

		halo2_map_info_table[0].internal_id = underlying_cast(e_map_id::_map_id_mainmenu);
		halo2_map_info_table[0].mcc_id = e_map_id::_map_id_mainmenu;

		halo2_map_info_table[0].scenario_name = "scenarios\\ui\\mainmenu\\mainmenu";
		halo2_map_info_table[0].scenario_name_wide = L"scenarios\\ui\\mainmenu\\mainmenu";

		VirtualProtect(&halo2_map_info_table, sizeof(halo2_map_info_table), old_protect, &old_protect);

		s_halo2_map_info mainmenu_map_info = {
			underlying_cast(e_map_id::_map_id_mainmenu),
			e_map_id::_map_id_mainmenu,
			"scenarios\\ui\\mainmenu\\mainmenu",
			L"scenarios\\ui\\mainmenu\\mainmenu"
		};

		copy_to_address(&halo2_map_info_table, &mainmenu_map_info, sizeof(mainmenu_map_info));
	}
};