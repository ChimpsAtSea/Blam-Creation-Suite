
uintptr_t groundhog_hs_print_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_groundhog, _build_mcc_1_1955_0_0, 0x180275404);
	OFFSET(_engine_type_groundhog, _build_mcc_1_2028_0_0, 0x180275464);
	OFFSET(_engine_type_groundhog, _build_mcc_1_2094_0_0, 0x180275464);
	return ~uintptr_t();
}
c_function_hook_ex<groundhog_hs_print_offset, void __fastcall (const char*)> groundhog_hs_print = { "groundhog_hs_print", [](const char* str)
{
	printf("%s\n", str);
} };