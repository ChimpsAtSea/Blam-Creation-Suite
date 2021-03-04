
#pragma region MCC Parse Hooks
uintptr_t mcc_map_id_parse_to_reach_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x18004CD50);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1930_0_0, 0x18003E3E0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x18003E390);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2028_0_0, 0x18003E390);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2094_0_0, 0x18003E390);
	return ~uintptr_t();
}
c_function_hook_ex<mcc_map_id_parse_to_reach_offset, long __fastcall (long map_id)> mcc_map_id_parse_to_reach = { "mcc_map_id_parse_to_reach", [](long map_id)
{
	long result = mcc_map_id_parse_to_reach(map_id);
	return result == -1l ? map_id : result;
} };

uintptr_t mcc_map_id_parse_from_reach_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x18004CF80);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1930_0_0, 0x18003E6A0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x18003E650);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2028_0_0, 0x18003E650);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2094_0_0, 0x18003E650);
	return ~uintptr_t();
}
c_function_hook_ex<mcc_map_id_parse_from_reach_offset, long __fastcall (long map_id)> mcc_map_id_parse_from_reach = { "mcc_map_id_parse_from_reach", [](long map_id)
{
	long result = mcc_map_id_parse_from_reach(map_id);
	return result == -1l ? map_id : result;
} };
#pragma endregion