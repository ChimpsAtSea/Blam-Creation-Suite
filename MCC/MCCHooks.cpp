#include <Shared\shared-public-pch.h>
#include <OpusFramework\opusframework-public-pch.h>


uintptr_t sub_141806A64_offset(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_mcc)
	{
		switch (build)
		{
		case e_build::_build_mcc_1_1350_0_0: return 0x141806A64;
		}
	}
	return ~uintptr_t();
}
FunctionHookVarArgsEx<sub_141806A64_offset, const wchar_t* __fastcall (__int64 a1, int a2)> sub_141806A64 = { "sub_141806A64", [](__int64 a1, int a2)
{
	const wchar_t* szResult = sub_141806A64(a1, a2);
	write_line_verbose("%S", szResult);
	return szResult;
} };


uintptr_t CreateGameEngine_offset(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_halo1)
	{
		switch (build)
		{
		case e_build::_build_mcc_1_1350_0_0: return 0x18008D2C0;
		}
	}
	return ~uintptr_t();
}
FunctionHookVarArgsEx<CreateGameEngine_offset, __int64 __fastcall (QWORD * a1)> CreateGameEngine = { "CreateGameEngine", [](QWORD* a1)
{
	return CreateGameEngine(a1);
} };

uintptr_t InitThread_offset(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_halo1)
	{
		switch (build)
		{
		case e_build::_build_mcc_1_1350_0_0: return 0x18008C550;
		}
	}
	return ~uintptr_t();
}
FunctionHookVarArgsEx<InitThread_offset, HANDLE __fastcall (IGameEngine*, IGameEngineHost*, GameContext*)> InitThread = { "InitThread", [](IGameEngine* pGameEngine, IGameEngineHost* pGameEngineHost, GameContext* pGameContext)
{
	return InitThread(pGameEngine, pGameEngineHost, pGameContext);
} };











