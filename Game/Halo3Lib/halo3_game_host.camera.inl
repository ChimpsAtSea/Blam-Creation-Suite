
uintptr_t halo3_player_mapping_get_local_player_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1802ACF20);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x1802A74E0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x1802A74E0);
	//OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, ~uintptr_t()); // this build inlined `player_mapping_get_local_player`
	return ~uintptr_t();
}
FunctionHookEx<halo3_player_mapping_get_local_player_offset, int __stdcall ()> halo3_player_mapping_get_local_player;

uintptr_t halo3_observer_try_and_get_camera_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x18034C840);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x180347260);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x180347260);
	//OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x1801EFAA0); // since `player_mapping_get_local_player` was inlined we won't reference 'observer_try_and_get_camera'
	return ~uintptr_t();
}
FunctionHookEx<halo3_observer_try_and_get_camera_offset, s_observer_camera* __fastcall (signed int a1)> halo3_observer_try_and_get_camera;

std::vector<uintptr_t> halo3_enable_debug_hud_coordinates_offsets(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1802EEDC3, 0x1802EEDF2);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x1802E9563, 0x1802E9592);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x1802E9563, 0x1802E9592);
	//OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, ~uintptr_t()); #TODO: get this offsets, since `player_mapping_get_local_player` was inlined the asm instructions a skewed
	return {};
}
// Enable debug hud coordinates, props to Exhibit
c_multi_data_patch<halo3_enable_debug_hud_coordinates_offsets> halo3_enable_debug_hud_coordinates = {
	[](e_engine_type engine_type, e_build build, char* data[], DataPatchPackets& packets)
	{
		packets.push_back(MAKE_DATAPATCHPACKET(data[0], 2));
		nop_address(data[0], 2);

		packets.push_back(MAKE_DATAPATCHPACKET(data[1], 6));
		nop_address(data[1], 6);

		debug_point;
	}
};