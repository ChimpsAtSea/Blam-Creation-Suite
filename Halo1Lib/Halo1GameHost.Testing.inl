#include "halo1lib-private-pch.h"

uintptr_t sub_18019BC50_offset(Engine engine, Build build)
{
	if (engine == Engine::Halo1)
	{
		switch (build)
		{
		case Build::MCC_1_1350_0_0: return 0x18019BC50;
		}
	}
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




//intptr_t sub_18019BB80_offset(EngineVersion engine, BuildVersion build)
//{
//	if (engine == EngineVersion::Halo1)
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
//	if (engine == EngineVersion::Halo1)
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

