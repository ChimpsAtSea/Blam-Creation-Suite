
#pragma region network tests

uintptr_t transport_endpoint_bind_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x18022C0D0);
	return ~uintptr_t();
}
FunctionHookEx<transport_endpoint_bind_offset, bool __fastcall(__int64 a1, __int64 a2)> transport_endpoint_bind = { "transport_endpoint_bind", [](__int64 a1, __int64 a2)
{
	bool result = transport_endpoint_bind(a1, a2);
	return result;
} };

uintptr_t transport_endpoint_bind_shell_host_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x18022C11E);
	return ~uintptr_t();
}
c_data_patch<transport_endpoint_bind_shell_host_patch_offset> transport_endpoint_bind_shell_host_patch = {
	[](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
	{
		packet = MAKE_DATAPATCHPACKET(data, 2);
		nop_address(data, 2);
	}
};

uintptr_t sendto_with_error_code_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x18022C820);
	return ~uintptr_t();
}
FunctionHookEx<sendto_with_error_code_offset, int __fastcall(SOCKET* a1, const char* a2, __int16 a3, __int64 a4)> sendto_with_error_code = { "sendto_with_error_code", [](SOCKET* a1, const char* a2, __int16 a3, __int64 a4)
{
	*(_WORD*)(a4 + 18) = 4;
	int result = sendto_with_error_code(a1, a2, a3, a4);
	return result;
} };

#pragma endregion
