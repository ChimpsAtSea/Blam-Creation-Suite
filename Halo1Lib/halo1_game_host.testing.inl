#include "halo1lib-private-pch.h"

// TODO: get the offset for build 1367
uintptr_t sub_18019BC50_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1350_0_0, 0x18019BC50);
	OFFSET(_engine_type_halo1, _build_mcc_1_1377_0_0, 0x1800EB5E0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1384_0_0, 0x1800EB5E0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1387_0_0, 0x1800EB5E0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x1800EB5E0);
	return ~uintptr_t();
}
FunctionHookVarArgsEx<sub_18019BC50_offset, __int64 __fastcall (__int64*, const char*, va_list)> sub_18019BC50 = { "sub_18019BC50", [](__int64* a1, const char* pFormat, va_list args)
{
	if (pFormat)
	{
		vprintf(pFormat, args);
		printf("\n");
	}
	return sub_18019BC50(a1, pFormat, args);
} };

// TODO: get the offset for build 1367
uintptr_t security_check_cookie_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1350_0_0, 0x180E5A650);
	OFFSET(_engine_type_halo1, _build_mcc_1_1377_0_0, 0x180BBA020);
	OFFSET(_engine_type_halo1, _build_mcc_1_1384_0_0, 0x180BBA050);
	OFFSET(_engine_type_halo1, _build_mcc_1_1387_0_0, 0x180BBA050);
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x180BBA050);
	return ~uintptr_t();
}



// TODO: get the offset for build 1367
uintptr_t sub_18005B520_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1350_0_0, 0x180069E60);
	OFFSET(_engine_type_halo1, _build_mcc_1_1377_0_0, 0x18005B520);
	OFFSET(_engine_type_halo1, _build_mcc_1_1384_0_0, 0x18005B520);
	OFFSET(_engine_type_halo1, _build_mcc_1_1387_0_0, 0x18005B520);
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18005B520);
	return ~uintptr_t();
}
FunctionHookVarArgsEx<sub_18005B520_offset, char __fastcall(unsigned int a1)> sub_18005B520 = { "sub_18005B520", [](unsigned int a1)
{
	return (char)0;
	//return sub_18005B520(a1);
} };







//void __fastcall /*__declspec(naked) */security_check_cookie_hook()
//{
//	//write_line_verbose("security_check_cookie");
//}
//FunctionHookVarArgsEx<security_check_cookie_offset, void()> security_check_cookie = { "security_check_cookie", security_check_cookie_hook };

//uintptr_t security_check_cookie_call_offset(e_engine_type engine_type, e_build build)
//{
//	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18005C699);
//	return ~uintptr_t();
//}
//DataPatch<security_check_cookie_call_offset> security_check_cookie_patch = { [](e_engine_type engine_type, e_build build, char* patch, DataPatchPacket& packet)
//{
//	// Enable tag edits
//	packet = MAKE_DATAPATCHPACKET(patch, 5);
//
//	DWORD oldProtect;
//	BOOL virtualProtectResult = VirtualProtect(patch, 5, PAGE_READWRITE, &oldProtect);
//	ASSERT(virtualProtectResult != 0);
//
//	patch[0] = 0x90i8; // nop
//	patch[1] = 0x90i8; // nop
//	patch[2] = 0x90i8; // nop
//	patch[3] = 0x90i8; // nop
//	patch[4] = 0x90i8; // nop
//
//	BOOL virtualProtectResult2 = VirtualProtect(patch, 5, oldProtect, &oldProtect);
//	ASSERT(virtualProtectResult2 != 0);
//} };




//intptr_t sub_18019BB80_offset(EngineVersion engine, BuildVersion build)
//{
//	if (engine_type == EngineVersion::Halo1)
//	{
//		switch (build)
//		{
//		case BuildVersion::Build_1_1350_0_0: return 0x18019BB80;
//		}
//	}
//	return ~uintptr_t();
//}
//_QWORD* sub_18019BB80_hook(_QWORD* a1, const char* pFormat, ...)
//{
//	if (pFormat)
//	{
//		va_list args;
//		va_start(args, pFormat);
//		vprintf(pFormat, args);
//		va_end(args);
//		printf("\n");
//	}
//	return (_QWORD*)nullptr;
//}
//FunctionHookVarArgsEx<sub_18019BB80_offset, _QWORD * (_QWORD * a1, const char* pFormat, ...)> sub_18019BB80 = { "sub_18019BB80", sub_18019BB80_hook };

//intptr_t sub_1801FE1B0_offset(EngineVersion engine, BuildVersion build)
//{
//	if (engine_type == EngineVersion::Halo1)
//	{
//		switch (build)
//		{
//		case BuildVersion::Build_1_1350_0_0: return 0x1801FE1B0;
//		}
//	}
//	return ~uintptr_t();
//}
//FunctionHookEx<sub_1801FE1B0_offset, __int64 __fastcall (int a1, int a2)> sub_1801FE1B0 = { "sub_1801FE1B0", [](int a1, int a2)
//{
//	a1 = 3072;
//	a2 = 1728;
//	__int64 result = sub_1801FE1B0(a1, a2);
//	return result;
//} };

void terminal_output_print_hook(void *, const char *format, ...)
{
	va_list argptr;
	va_start(argptr, format);
	write_line_verbose(format, argptr);
}

// TODO: get the offset for builds 1350, 1367, 1377, 1384, 1387
uintptr_t terminal_output_print_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18078ADF0);
	return ~uintptr_t();
}
FunctionHookVarArgsEx<terminal_output_print_offset, void(void *, const char*, ...)> terminal_output_print 
	= { "terminal_output_print", terminal_output_print_hook };

// TODO: get the offset for builds 1350, 1367, 1377, 1384, 1387
uintptr_t terminal_output_print_needs_developer_mode_greater_than_or_equal_4_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18078AD10);
	return ~uintptr_t();
}
FunctionHookVarArgsEx<terminal_output_print_needs_developer_mode_greater_than_or_equal_4_offset, void(void *, const char *, ...)> terminal_output_print_needs_developer_mode_greater_than_or_equal_4 
	= { "terminal_output_print_needs_developer_mode_greater_than_or_equal_4", terminal_output_print_hook };