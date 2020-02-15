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


intptr_t CreateGameEngine_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	if (engineVersion == EngineVersion::Halo1)
	{
		switch (buildVersion)
		{
		case BuildVersion::Build_1_1350_0_0: return 0x18008D2C0;
		}
	}
	return ~intptr_t();
}
FunctionHookVarArgsEx<CreateGameEngine_offset, __int64 __fastcall (QWORD * a1)> CreateGameEngine = { "CreateGameEngine", [](QWORD* a1)
{
	return CreateGameEngine(a1);
} };

intptr_t InitThread_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	if (engineVersion == EngineVersion::Halo1)
	{
		switch (buildVersion)
		{
		case BuildVersion::Build_1_1350_0_0: return 0x18008C550;
		}
	}
	return ~intptr_t();
}
FunctionHookVarArgsEx<InitThread_offset, HANDLE __fastcall (IGameEngine*, IGameEngineHost*, GameContext*)> InitThread = { "InitThread", [](IGameEngine* pGameEngine, IGameEngineHost* pGameEngineHost, GameContext* pGameContext)
{
	return InitThread(pGameEngine, pGameEngineHost, pGameContext);
} };











