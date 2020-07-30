
uintptr_t halo3_spawn_ai_with_scripts_and_effects_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x18063445E);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18064014E);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18064014E);
	return {};
}
// Allows spawning AI via scripts or effects, props to Exhibit
c_data_patch<halo3_spawn_ai_with_scripts_and_effects_offset> halo3_spawn_ai_with_scripts_and_effects = {
	[](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
	{
		packet = MAKE_DATAPATCHPACKET(data, 2);
		nop_address(data, 2);
	}
};