
uintptr_t halo4_hs_function_table_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo4, _build_mcc_1_1896_0_0, 0x180D97F20);
	OFFSET(_engine_type_halo4, _build_mcc_1_1930_0_0, 0x180D98F10);
	OFFSET(_engine_type_halo4, _build_mcc_1_1955_0_0, 0x180D98F20);
	OFFSET(_engine_type_halo4, _build_mcc_1_2028_0_0, 0x180D98F00);
	OFFSET(_engine_type_halo4, _build_mcc_1_2094_0_0, 0x180D98F00);
	return ~uintptr_t();
}
void** (&halo4_hs_function_table)[] = reference_symbol<void** []>("halo4_hs_function_table", halo4_hs_function_table_offset);

uintptr_t halo4_hs_compiler_global_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo4, _build_mcc_1_1896_0_0, 0x180D97CD0);
	OFFSET(_engine_type_halo4, _build_mcc_1_1930_0_0, 0x180D98CC0);
	OFFSET(_engine_type_halo4, _build_mcc_1_1955_0_0, 0x180D98CD0);
	OFFSET(_engine_type_halo4, _build_mcc_1_2028_0_0, 0x180D98CB0);
	OFFSET(_engine_type_halo4, _build_mcc_1_2094_0_0, 0x180D98CB0);
	return ~uintptr_t();
}
void*& halo4_hs_compiler_global = reference_symbol<void*>("halo4_hs_compiler_global", halo4_hs_compiler_global_offset);

uintptr_t halo4_hs_compiler_register_hs_functions_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo4, _build_mcc_1_1896_0_0, 0x18012F554);
	OFFSET(_engine_type_halo4, _build_mcc_1_1930_0_0, 0x180130B14);
	OFFSET(_engine_type_halo4, _build_mcc_1_1955_0_0, 0x180130B64);
	OFFSET(_engine_type_halo4, _build_mcc_1_2028_0_0, 0x180130BC4);
	OFFSET(_engine_type_halo4, _build_mcc_1_2094_0_0, 0x180130BC4);
	return ~uintptr_t();
}
c_function_hook_ex<halo4_hs_compiler_register_hs_functions_offset, __int64 __fastcall(__int64 a1)> halo4_hs_compiler_register_hs_functions = { "halo4_hs_compiler_register_hs_functions", [](__int64 a1)
{
	ASSERT(is_valid(halo4_hs_compiler_register_hs_functions));

	__int64 result = halo4_hs_compiler_register_hs_functions(a1);

	if (is_valid(halo4_hs_function_table) && is_valid(halo4_hs_compiler_global))
	{
		return result;
		for (int i = 0; i < 3072; i++)
		{
			if (halo4_hs_function_table[i] != nullptr)
			{
				printf("_hs_function_table[0x%02X] = 0x%llX, 0x%llX\n", i, (uint64_t)halo4_hs_function_table[i], *(uint64_t*)*halo4_hs_function_table[i]);
			}
			else
			{
				printf("_hs_function_table[0x%02X] = 0x%llX\n", i, (uint64_t)halo4_hs_function_table[i]);
			}
		}
	}

	return result;
} };

uintptr_t halo4_hs_print_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo4, _build_mcc_1_1896_0_0, 0x1802741DC);
	OFFSET(_engine_type_halo4, _build_mcc_1_1930_0_0, 0x180275F7C);
	OFFSET(_engine_type_halo4, _build_mcc_1_1955_0_0, 0x180275FCC);
	OFFSET(_engine_type_halo4, _build_mcc_1_2028_0_0, 0x18027612C);
	OFFSET(_engine_type_halo4, _build_mcc_1_2094_0_0, 0x18027612C);
	return ~uintptr_t();
}
c_function_hook_ex<halo4_hs_print_offset, void __fastcall (const char*)> halo4_hs_print = { "halo4_hs_print", [](const char* str)
{
	printf("%s\n", str);
} };