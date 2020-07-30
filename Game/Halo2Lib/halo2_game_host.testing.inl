
// load crash fix
uintptr_t sub_180041770_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo2, _build_mcc_1_1477_0_0, 0x180041770);
	OFFSET(_engine_type_halo2, _build_mcc_1_1499_0_0, 0x180041770);
	OFFSET(_engine_type_halo2, _build_mcc_1_1520_0_0, 0x180041770);
	OFFSET(_engine_type_halo2, _build_mcc_1_1570_0_0, 0x180041770);
	OFFSET(_engine_type_halo2, _build_mcc_1_1619_0_0, 0x180041770);
	OFFSET(_engine_type_halo2, _build_mcc_1_1698_0_0, 0x18003AFC0);
	OFFSET(_engine_type_halo2, _build_mcc_1_1716_0_0, 0x18003AFC0);
	return ~uintptr_t();
}
FunctionHookEx<sub_180041770_offset, char()> sub_180041770 = { "sub_180041770", []()
{
	return char(0);
} };



struct s_halo2_map_info
{
	uint32_t internal_id;
	e_map_id mcc_id;
	const char* scenario_name;
	const wchar_t* scenario_name_wide;
};
uintptr_t halo2_map_info_table_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo2, _build_mcc_1_1477_0_0, 0x180EECE30);
	OFFSET(_engine_type_halo2, _build_mcc_1_1499_0_0, 0x180EECE30);
	OFFSET(_engine_type_halo2, _build_mcc_1_1520_0_0, 0x180EEEE30);
	OFFSET(_engine_type_halo2, _build_mcc_1_1570_0_0, 0x180EEEE30);
	OFFSET(_engine_type_halo2, _build_mcc_1_1619_0_0, 0x180EEEE30);
	OFFSET(_engine_type_halo2, _build_mcc_1_1698_0_0, 0x180A47940);
	OFFSET(_engine_type_halo2, _build_mcc_1_1716_0_0, 0x180A47940);
	return ~uintptr_t();
}
s_halo2_map_info(&halo2_map_info_table)[40] = reference_symbol<s_halo2_map_info[40]>("halo2_map_info_table", halo2_map_info_table_offset);

uintptr_t halo2_map_info_table_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo2, _build_mcc_1_1477_0_0, 0x180EECE30);
	OFFSET(_engine_type_halo2, _build_mcc_1_1499_0_0, 0x180EECE30);
	OFFSET(_engine_type_halo2, _build_mcc_1_1520_0_0, 0x180EEEE30);
	OFFSET(_engine_type_halo2, _build_mcc_1_1570_0_0, 0x180EEEE30);
	OFFSET(_engine_type_halo2, _build_mcc_1_1619_0_0, 0x180EEEE30);
	OFFSET(_engine_type_halo2, _build_mcc_1_1698_0_0, 0x180A47940);
	OFFSET(_engine_type_halo2, _build_mcc_1_1716_0_0, 0x180A47940);
	return ~uintptr_t();
}
c_data_patch<halo2_map_info_table_patch_offset> halo2_map_info_table_patch =
{
	[](e_engine_type engine_type, e_build build, char*, DataPatchPacket& packet)
	{
		packet = MAKE_DATAPATCHPACKET(&halo2_map_info_table, sizeof(halo2_map_info_table));

		DWORD old_protect;
		VirtualProtect(&halo2_map_info_table, sizeof(halo2_map_info_table), PAGE_EXECUTE_READWRITE, &old_protect);

		halo2_map_info_table[0].internal_id = underlying_cast(e_map_id::_map_id_mainmenu);
		halo2_map_info_table[0].mcc_id = e_map_id::_map_id_mainmenu;

		halo2_map_info_table[0].scenario_name = "scenarios\\ui\\mainmenu\\mainmenu";
		halo2_map_info_table[0].scenario_name_wide = L"scenarios\\ui\\mainmenu\\mainmenu";

		VirtualProtect(&halo2_map_info_table, sizeof(halo2_map_info_table), old_protect, &old_protect);
	}
};

//// disable pak crash 1
//uintptr_t sub_1804B4FC0_offset(e_engine_type engine_type, e_build build)
//{
//	OFFSET(_engine_type_halo2, _build_mcc_1_1477_0_0, 0x1804B4FC0);
//	return ~uintptr_t();
//}
//FunctionHookVarArgsEx<sub_1804B4FC0_offset, char()> sub_1804B4FC0 = { "sub_1804B4FC0", []()
//{
//	return char(0);
//} };



