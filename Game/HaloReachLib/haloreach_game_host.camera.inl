
uintptr_t haloreach_player_mapping_get_local_player_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_824_0_0, 0x1805C10B0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_887_0_0, 0x180366030);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1035_0_0, 0x180190190);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1186_0_0, 0x180072F20);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1211_0_0, 0x180073460);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1246_0_0, 0x18006FDF0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1270_0_0, 0x18006FDF0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1305_0_0, 0x18006FE30);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1350_0_0, 0x1800711A0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x180071180);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1377_0_0, 0x180071180);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1384_0_0, 0x180071180);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1387_0_0, 0x180071180);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x180071180);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1520_0_0, 0x1800712E0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1570_0_0, 0x1800712E0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1619_0_0, 0x1800712E0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1698_0_0, 0x180071C90);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1716_0_0, 0x180071C90);
	// not available for builds 1767-1871
	OFFSET(_engine_type_haloreach, _build_mcc_1_1930_0_0, 0x180059A74);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x180059A24);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2028_0_0, 0x180059A24);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2094_0_0, 0x180059A24);
	return ~uintptr_t();
}
c_function_hook_ex<haloreach_player_mapping_get_local_player_offset, int __stdcall ()> haloreach_player_mapping_get_local_player;

uintptr_t haloreach_observer_try_and_get_camera_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_824_0_0, 0x180624D10);
	OFFSET(_engine_type_haloreach, _build_mcc_1_887_0_0, 0x1804DA0C0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1035_0_0, 0x18029B840);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1186_0_0, 0x1800E6110);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1211_0_0, 0x1800E66A0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1246_0_0, 0x1800E2FA0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1270_0_0, 0x1800E2FA0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1305_0_0, 0x1800E3050);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1350_0_0, 0x1800E4580);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x1800E4560);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1377_0_0, 0x1800E4560);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1384_0_0, 0x1800E4560);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1387_0_0, 0x1800E4560);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x1800E4560);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1520_0_0, 0x1800E46C0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1570_0_0, 0x1800E46C0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1619_0_0, 0x1800E46C0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1698_0_0, 0x1800E5FA0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1716_0_0, 0x1800E5FA0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1829_0_0, 0x1800EBB30);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1864_0_0, 0x1800EBB30);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1871_0_0, 0x1800EBB30);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1930_0_0, 0x1800B29E4);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x1800B2994);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2028_0_0, 0x1800B2994);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2094_0_0, 0x1800B2994);
	return ~uintptr_t();
}
c_function_hook_ex<haloreach_observer_try_and_get_camera_offset, s_observer_camera * __fastcall (signed int a1)> haloreach_observer_try_and_get_camera;

std::vector<uintptr_t> haloreach_enable_debug_hud_coordinates_offsets(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1305_0_0, 0x1800DCA8A, 0x1800DCA97);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x1800DDF7A, 0x1800DDF87);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1377_0_0, 0x1800DDF7A, 0x1800DDF87);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1384_0_0, 0x1800DDF7A, 0x1800DDF87);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1387_0_0, 0x1800DDF7A, 0x1800DDF87);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x1800DDF7A, 0x1800DDF87);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1520_0_0, 0x1800DE0DA, 0x1800DE0E7);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1570_0_0, 0x1800DE0DA, 0x1800DE0E7);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1619_0_0, 0x1800DE0DA, 0x1800DE0E7);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1698_0_0, 0x1800DF9EA, 0x1800DF9F7);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1716_0_0, 0x1800DF9EA, 0x1800DF9F7);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1829_0_0, 0x1800E516B, 0x1800E5178);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1864_0_0, 0x1800E516B, 0x1800E5178);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1871_0_0, 0x1800E516B, 0x1800E5178);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1930_0_0, 0x1800AED58, 0x1800AED65);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x1800AED08, 0x1800AED15);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2028_0_0, 0x1800AED08, 0x1800AED15);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2094_0_0, 0x1800AED08, 0x1800AED15);
	return {};
}
// Enable debug hud coordinates
c_multi_data_patch<haloreach_enable_debug_hud_coordinates_offsets> haloreach_enable_debug_hud_coordinates = {
	[](s_engine_platform_build engine_platform_build, char *data[], DataPatchPackets &packets)
	{
		packets.push_back(MAKE_DATAPATCHPACKET(data[0], 6));
		nop_address(data[0], 6);

		packets.push_back(MAKE_DATAPATCHPACKET(data[1], 6));
		nop_address(data[1], 6);
	}
};