#include "mcc-private-pch.h"


uintptr_t mcc_player_configuration_get_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x1418BFDE8);
	return ~uintptr_t();
}
c_function_hook_ex<mcc_player_configuration_get_offset, c_player_configuration* __fastcall (void* _this, __int64 value)> mcc_player_configuration_get = { "mcc_player_configuration_get", [](void* _this, __int64 value)
{
	c_player_configuration* result = mcc_player_configuration_get(_this, value);
	return result;
} };



uintptr_t InitThread_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x180076240);
	//OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x180012920);
	return ~uintptr_t();
}
c_function_hook_ex<InitThread_offset, HANDLE __fastcall (void*, class IGameEngineHost* game_engineHost, c_game_context_v3 * pGameContext)> InitThread = { "InitThread", [](void* a1, class IGameEngineHost* game_engineHost, c_game_context_v3* pGameContext)
{
	HANDLE result = InitThread(a1, game_engineHost, pGameContext);
	return result;
} };

//.text:0000000180076BA0; void __fastcall sub_180076BA0(struct IGameEngine* thisptr, struct ID3D11Device* pDevice)
uintptr_t sub_180076BA0_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x180076BA0);
	return ~uintptr_t();
}
c_function_hook_ex<sub_180076BA0_offset, void __fastcall (IGameEngine* thisptr, struct ID3D11Device* pDevice)> sub_180076BA0 = { "sub_180076BA0", [](IGameEngine* thisptr, struct ID3D11Device* pDevice)
{
	sub_180076BA0(thisptr, pDevice);
} };

//.text:0000000180076D60; void __fastcall sub_180076D60(struct IGameEngine* a1, int map_id)
uintptr_t sub_180076D60_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x180076D60);
	return ~uintptr_t();
}
c_function_hook_ex<sub_180076D60_offset, void __fastcall (IGameEngine* a1, int map_id)> sub_180076D60 = { "sub_180076D60", [](IGameEngine* a1, int map_id)
{
	sub_180076D60(a1, map_id);
} };


uintptr_t sub_141806A64_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1350_0_0, 0x141806A64);
	return ~uintptr_t();
}
c_function_hook_ex<sub_141806A64_offset, const wchar_t* __fastcall (__int64 a1, int a2)> sub_141806A64 = { "sub_141806A64", [](__int64 a1, int a2)
{
	const wchar_t* szResult = sub_141806A64(a1, a2);
	c_console::write_line_verbose("%S", szResult);
	return szResult;
} };


uintptr_t CreateGameEngine_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1350_0_0, 0x18008D2C0);
	return ~uintptr_t();
}
c_function_hook_ex<CreateGameEngine_offset, __int64 __fastcall (QWORD * a1)> CreateGameEngine = { "CreateGameEngine", [](QWORD* a1)
{
	return CreateGameEngine(a1);
} };
//
//uintptr_t InitThread_offset(e_engine_type engine_type, e_build build)
//{
//	OFFSET(_engine_type_halo1, _build_mcc_1_1350_0_0, 0x18008C550);
//	return ~uintptr_t();
//}
//c_function_hook_ex<InitThread_offset, HANDLE __fastcall (IGameEngine*, IGameEngineHost*, GameContext*)> InitThread = { "InitThread", [](IGameEngine* game_engine, IGameEngineHost* game_engineHost, GameContext* pGameContext)
//{
//	return InitThread(game_engine, game_engineHost, pGameContext);
//} };
//
//









