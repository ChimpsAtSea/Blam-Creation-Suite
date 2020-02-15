#include <Shared\shared-public-pch.h>
#include <OpusFramework\opusframework-public-pch.h>


intptr_t sub_141806A64_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	if (engineVersion == EngineVersion::MCC)
	{
		switch (buildVersion)
		{
		case BuildVersion::Build_1_1350_0_0: return 0x141806A64;
		}
	}
	return ~intptr_t();
}
FunctionHookVarArgsEx<sub_141806A64_offset, const wchar_t* __fastcall (__int64 a1, int a2)> sub_141806A64 = { "sub_141806A64", [](__int64 a1, int a2)
{
	const wchar_t* szResult = sub_141806A64(a1, a2);
	WriteLineVerbose("%S", szResult);
	return szResult;
} };



