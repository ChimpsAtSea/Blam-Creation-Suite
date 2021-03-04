
// load crash fix
uintptr_t sub_180041770_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo2, _build_mcc_1_1477_0_0, 0x180041770);
	OFFSET(_engine_type_halo2, _build_mcc_1_1499_0_0, 0x180041770);
	OFFSET(_engine_type_halo2, _build_mcc_1_1520_0_0, 0x180041770);
	OFFSET(_engine_type_halo2, _build_mcc_1_1570_0_0, 0x180041770);
	OFFSET(_engine_type_halo2, _build_mcc_1_1619_0_0, 0x180041770);
	OFFSET(_engine_type_halo2, _build_mcc_1_1698_0_0, 0x18003AFC0);
	OFFSET(_engine_type_halo2, _build_mcc_1_1716_0_0, 0x18003AFC0);
	OFFSET(_engine_type_halo2, _build_mcc_1_1829_0_0, 0x18003B2F0);
	OFFSET(_engine_type_halo2, _build_mcc_1_1864_0_0, 0x18003B2F0);
	OFFSET(_engine_type_halo2, _build_mcc_1_1871_0_0, 0x18003B2F0);
	OFFSET(_engine_type_halo2, _build_mcc_1_1955_0_0, 0x18003B340);
	OFFSET(_engine_type_halo2, _build_mcc_1_2028_0_0, 0x18003B340);
	OFFSET(_engine_type_halo2, _build_mcc_1_2094_0_0, 0x18003B340);
	return ~uintptr_t();
}
c_function_hook_ex<sub_180041770_offset, char()> sub_180041770 = { "sub_180041770", []()
{
	return char(0);
} };