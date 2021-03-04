
uintptr_t sub_1806F4000_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x1806F4000);
	OFFSET(_engine_type_halo1, _build_mcc_1_1570_0_0, 0x1806F42B0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1619_0_0, 0x1806F42B0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1698_0_0, 0x1806F4BF0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1716_0_0, 0x1806F4BF0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1829_0_0, 0x180ABE7C0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1864_0_0, 0x180ABE7C0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1871_0_0, 0x180ABE7C0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1955_0_0, 0x180ABEDA0);
	OFFSET(_engine_type_halo1, _build_mcc_1_2028_0_0, 0x180ABEEE0);
	OFFSET(_engine_type_halo1, _build_mcc_1_2094_0_0, 0x180ABEEE0);
	return ~uintptr_t();
}
c_function_hook_ex<sub_1806F4000_offset, void()> sub_1806F4000 = { "sub_1806F4000", []()
{

	sub_1806F4000();
} };

uintptr_t sub_1800935B0_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x1800935B0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1570_0_0, 0x1800935F0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1619_0_0, 0x1800935F0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1698_0_0, 0x180093FB0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1716_0_0, 0x180093FB0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1829_0_0, 0x1800BB260);
	OFFSET(_engine_type_halo1, _build_mcc_1_1864_0_0, 0x1800BB260);
	OFFSET(_engine_type_halo1, _build_mcc_1_1871_0_0, 0x1800BB260);
	OFFSET(_engine_type_halo1, _build_mcc_1_1955_0_0, 0x1800BB620);
	OFFSET(_engine_type_halo1, _build_mcc_1_2028_0_0, 0x1800BB690);
	OFFSET(_engine_type_halo1, _build_mcc_1_2094_0_0, 0x1800BB690);
	return ~uintptr_t();
}
c_function_hook_ex<sub_1800935B0_offset, __int64 __fastcall (__int64 a1)> sub_1800935B0 = { "sub_1800935B0", [](__int64 a1)
{
	uint32_t sub_1806F4000_reference_count = sub_1806F4000.reference_counter;
	__int64 result = (sub_1806F4000_reference_count > 0) ? __int64(0) : sub_1800935B0(a1);

	return result;
} };
