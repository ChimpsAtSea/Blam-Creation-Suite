#include <Shared\shared-public-pch.h>
#include <OpusFramework\opusframework-public-pch.h>


uintptr_t Function29_offset(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_mcc)
	{
		switch (build)
		{
		case _build_mcc_1_1389_0_0: return 0x1418BFDE8;
		}
	}
	return ~uintptr_t();
}
FunctionHookEx<Function29_offset, PlayerConfiguration* __fastcall (void* _this, __int64 value)> GetPlayerConfiguration = { "GetPlayerConfiguration", [](void* _this, __int64 value)
{
	PlayerConfiguration* result = GetPlayerConfiguration(_this, value);





	return result;
} };



uintptr_t InitThread_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x180076240);
	//OFFSET(_engine_type_halo_reach, _build_mcc_1_1389_0_0, 0x180012920);
	return ~uintptr_t();
}
FunctionHookEx<InitThread_offset, HANDLE __fastcall (void*, class IGameEngineHost* pGameEngineHost, c_game_context_v3 * pGameContext)> InitThread = { "InitThread", [](void* a1, class IGameEngineHost* pGameEngineHost, c_game_context_v3* pGameContext)
{
	HANDLE result = InitThread(a1, pGameEngineHost, pGameContext);
	return result;
} };

//.text:0000000180076BA0; void __fastcall sub_180076BA0(struct IGameEngine* thisptr, struct ID3D11Device* pDevice)
uintptr_t sub_180076BA0_offset(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_halo1)
	{
		switch (build)
		{
		case _build_mcc_1_1389_0_0: return 0x180076BA0;
		}
	}
	return ~uintptr_t();
}
FunctionHookEx<sub_180076BA0_offset, void __fastcall (IGameEngine* thisptr, struct ID3D11Device* pDevice)> sub_180076BA0 = { "sub_180076BA0", [](IGameEngine* thisptr, struct ID3D11Device* pDevice)
{
	sub_180076BA0(thisptr, pDevice);
} };

//.text:0000000180076D60; void __fastcall sub_180076D60(struct IGameEngine* a1, int map_id)
uintptr_t sub_180076D60_offset(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_halo1)
	{
		switch (build)
		{
		case _build_mcc_1_1389_0_0: return 0x180076D60;
		}
	}
	return ~uintptr_t();
}
FunctionHookEx<sub_180076D60_offset, void __fastcall (IGameEngine* a1, int map_id)> sub_180076D60 = { "sub_180076D60", [](IGameEngine* a1, int map_id)
{
	sub_180076D60(a1, map_id);
} };


uintptr_t sub_141806A64_offset(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_mcc)
	{
		switch (build)
		{
		case _build_mcc_1_1350_0_0: return 0x141806A64;
		}
	}
	return ~uintptr_t();
}
FunctionHookEx<sub_141806A64_offset, const wchar_t* __fastcall (__int64 a1, int a2)> sub_141806A64 = { "sub_141806A64", [](__int64 a1, int a2)
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
		case _build_mcc_1_1350_0_0: return 0x18008D2C0;
		}
	}
	return ~uintptr_t();
}
FunctionHookEx<CreateGameEngine_offset, __int64 __fastcall (QWORD * a1)> CreateGameEngine = { "CreateGameEngine", [](QWORD* a1)
{
	return CreateGameEngine(a1);
} };
//
//uintptr_t InitThread_offset(e_engine_type engine_type, e_build build)
//{
//	if (engine_type == _engine_type_halo1)
//	{
//		switch (build)
//		{
//		case _build_mcc_1_1350_0_0: return 0x18008C550;
//		}
//	}
//	return ~uintptr_t();
//}
//FunctionHookEx<InitThread_offset, HANDLE __fastcall (IGameEngine*, IGameEngineHost*, GameContext*)> InitThread = { "InitThread", [](IGameEngine* pGameEngine, IGameEngineHost* pGameEngineHost, GameContext* pGameContext)
//{
//	return InitThread(pGameEngine, pGameEngineHost, pGameContext);
//} };
//
//









