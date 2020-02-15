#include <Shared\shared-public-pch.h>
#include <OpusFramework\opusframework-public-pch.h>

intptr_t sub_18019BC50_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	if (engineVersion == EngineVersion::Halo1)
	{
		switch (buildVersion)
		{
		case BuildVersion::Build_1_1350_0_0: return 0x18019BC50;
		}
	}
	return ~intptr_t();
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

