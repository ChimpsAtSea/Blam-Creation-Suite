
uintptr_t convert_mcc_map_id_to_map_name_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1350_0_0, 0x180A47A20);
	OFFSET(_engine_type_halo1, _build_mcc_1_1367_0_0, 0x18073C810);
	OFFSET(_engine_type_halo1, _build_mcc_1_1377_0_0, 0x18073C930);
	OFFSET(_engine_type_halo1, _build_mcc_1_1384_0_0, 0x18073C960);
	OFFSET(_engine_type_halo1, _build_mcc_1_1387_0_0, 0x18073C960);
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18073C960);
	OFFSET(_engine_type_halo1, _build_mcc_1_1520_0_0, 0x18073CC60);
	OFFSET(_engine_type_halo1, _build_mcc_1_1570_0_0, 0x18073CC60);
	OFFSET(_engine_type_halo1, _build_mcc_1_1619_0_0, 0x18073CC60);
	OFFSET(_engine_type_halo1, _build_mcc_1_1698_0_0, 0x180747000);
	OFFSET(_engine_type_halo1, _build_mcc_1_1716_0_0, 0x180747000);
	return ~uintptr_t();
}
c_function_hook_ex<convert_mcc_map_id_to_map_name_offset, const char* __fastcall (e_map_id)> convert_mcc_map_id_to_map_name = { "convert_mcc_map_id_to_map_name", [](e_map_id map_id)
{
	switch (map_id)
	{
	case _map_id_mainmenu:
		return "ui";
	default:
		return convert_mcc_map_id_to_map_name(map_id);
	}
} };

uintptr_t halo1_ui_string_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1829_0_0, 0x1816678E4);
	OFFSET(_engine_type_halo1, _build_mcc_1_1864_0_0, 0x1816678E4);
	OFFSET(_engine_type_halo1, _build_mcc_1_1871_0_0, 0x1816678E4);
	OFFSET(_engine_type_halo1, _build_mcc_1_1955_0_0, 0x1816688E4);
	OFFSET(_engine_type_halo1, _build_mcc_1_2028_0_0, 0x1816688E4);
	return ~uintptr_t();
}
char(&halo1_ui_string)[] = reference_symbol<char[]>("halo1_ui_string", halo1_ui_string_offset);

uintptr_t mcc_map_id_parse_to_halo1_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1829_0_0, 0x180090C59 + 3);
	OFFSET(_engine_type_halo1, _build_mcc_1_1864_0_0, 0x180090C59 + 3);
	OFFSET(_engine_type_halo1, _build_mcc_1_1871_0_0, 0x180090C59 + 3);
	OFFSET(_engine_type_halo1, _build_mcc_1_1955_0_0, 0x180090B79 + 3);
	OFFSET(_engine_type_halo1, _build_mcc_1_2028_0_0, 0x180090BD9 + 3);
	return ~uintptr_t();
}
c_data_patch<mcc_map_id_parse_to_halo1_patch_offset> mcc_map_id_parse_to_halo1_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	packet = MAKE_DATAPATCHPACKET(data, 4);

	ptrdiff_t ui_string_delta = (uintptr_t)&halo1_ui_string - (uintptr_t)(data + 4);

	copy_to_address(data, &ui_string_delta, 4);
} };
