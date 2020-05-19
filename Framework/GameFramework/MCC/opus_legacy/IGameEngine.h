#pragma once

enum class eEngineState : int
{
	Pause,
	Unpause,

	ImmediateExit,
	RestartCheckpoint,
	RestartLevel,

	ReloadSettings,

	// 6 and 7 are connected
	GameLoadStart, // sets a temp variable to `g_render_thread_mode` and sets `g_render_thread_mode` to `0`, sets `g_game_is_loading` to `true` and runs `UpdateGameStatus(RestartCheckpoint)`
	GameLoadEnd, // sets `g_render_thread_mode` to the temp variable and sets the temp variable to `0`, sets `g_game_is_loading` to `false` and runs `UpdateGameStatus(RestartLevel)`

	// 8 and 9 are connected
	PushUIPage, // allocates `c_controller_input_message` (loadout selection is shown) and sets a temp variable to `true`
	PopUIPage, // sets the temp variable to `false` and player spawns

	SaveGameVariant, // creates a new `IGameVariant` and passes it to `IGameEngineHostLegacy::SaveGameVariant`
	SaveMapVariant, // creates a new `IMapVariant` and passes it to `IGameEngineHostLegacy::SaveMapVariant`

	EndRound, // not confirmed
	EndGame, // not confirmed

	ReloadRenderer, // potentially enhanced graphics. causes member 42 to run, also causes memory spike!

	Unknown15, // unknown
	Unknown16, // unknown this takes some extra argument provided to UpdateEngineState
};
extern const char* engine_state_to_string(eEngineState engineState);

#ifdef __INTELLISENSE__

/*
	IGameEngine Revision 2 : Build 1367
*/
class __IGameEngine;
class IGameEngine
{
public: // instance functions
	virtual void Free();
	virtual __forceinline __int64 __fastcall InitGraphics(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, IDXGISwapChain* pSwapchain, IDXGISwapChain* pFallbackSwapchain);
	virtual HANDLE __fastcall InitThread(class IGameEngineHost* pGameEngineHost, GameContext* pGameContext);
	virtual __int64 __fastcall UpdateEngineState(eEngineState status, _QWORD* extraArgument = nullptr);
	virtual void __fastcall Member04(ID3D11Device* pDevice);
	virtual void __fastcall Member05(int map_id);
	virtual void __fastcall Member06();
	virtual void __fastcall Member07();
	virtual void __fastcall Member08();
	virtual __int64 __fastcall Member09(const char* a1); // Member09 looks same as UpdateEngineState but takes a string argument that is copied with strdup
	virtual __int64 __fastcall Member10();

	// #INTELLISENSE
	IGameEngine(__IGameEngine& game_engine, e_build build);

	DWORD unknown8;
	float GameSpeed;
	char unknown10[1056];
	SLIST_HEADER header430;
	SLIST_HEADER header440;
	char unknown450[16];
};


#else

enum IGameEngineVirtualFunctionIndex
{
	__game_engine_virtual_function_free,
	__game_engine_virtual_function_init_graphics,
	__game_engine_virtual_function_init_thread,
	__game_engine_virtual_function_update_engine_state,
	__game_engine_virtual_function_member_4,
	__game_engine_virtual_function_member_5,
	__game_engine_virtual_function_member_6,
	__game_engine_virtual_function_member_7,
	__game_engine_virtual_function_member_8,
	__game_engine_virtual_function_member_9,
	__game_engine_virtual_function_member_10,
};

inline uint32_t get_game_engine_virtual_function_index(e_build build, IGameEngineVirtualFunctionIndex game_engine_virtual_function_index)
{
	enum IGameEngineV1VirtualFunctionIndex
	{
		__game_engine_v1_virtual_function_init_graphics,
		__game_engine_v1_virtual_function_init_thread,
		__game_engine_v1_virtual_function_update_engine_state,
		__game_engine_v1_virtual_function_free,
		__game_engine_v1_virtual_function_member_4,
		__game_engine_v1_virtual_function_member_5,
		__game_engine_v1_virtual_function_member_6,
		__game_engine_v1_virtual_function_member_7,
		__game_engine_v1_virtual_function_member_8,
		__game_engine_v1_virtual_function_member_9,
		__game_engine_v1_virtual_function_member_10,
	};

	enum IGameEngineV2VirtualFunctionIndex
	{
		__game_engine_v2_virtual_function_free,
		__game_engine_v2_virtual_function_init_graphics,
		__game_engine_v2_virtual_function_init_thread,
		__game_engine_v2_virtual_function_update_engine_state,
		__game_engine_v2_virtual_function_member_4,
		__game_engine_v2_virtual_function_member_5,
		__game_engine_v2_virtual_function_member_6,
		__game_engine_v2_virtual_function_member_7,
		__game_engine_v2_virtual_function_member_8,
		__game_engine_v2_virtual_function_member_9,
		__game_engine_v2_virtual_function_member_10,
	};

	if (build >= _build_mcc_1_1367_0_0)
	{
		// version 2
		switch (game_engine_virtual_function_index)
		{
		case __game_engine_virtual_function_free:					return __game_engine_v2_virtual_function_free;
		case __game_engine_virtual_function_init_graphics:			return __game_engine_v2_virtual_function_init_graphics;
		case __game_engine_virtual_function_init_thread:			return __game_engine_v2_virtual_function_init_thread;
		case __game_engine_virtual_function_update_engine_state:	return __game_engine_v2_virtual_function_update_engine_state;
		case __game_engine_virtual_function_member_4:				return __game_engine_v2_virtual_function_member_4;
		case __game_engine_virtual_function_member_5:				return __game_engine_v2_virtual_function_member_5;
		case __game_engine_virtual_function_member_6:				return __game_engine_v2_virtual_function_member_6;
		case __game_engine_virtual_function_member_7:				return __game_engine_v2_virtual_function_member_7;
		case __game_engine_virtual_function_member_8:				return __game_engine_v2_virtual_function_member_8;
		case __game_engine_virtual_function_member_9:				return __game_engine_v2_virtual_function_member_9;
		case __game_engine_virtual_function_member_10:				return __game_engine_v2_virtual_function_member_10;
		}
	}
	else
	{
		// version 1
		switch (game_engine_virtual_function_index)
		{
		case __game_engine_virtual_function_free:					return __game_engine_v1_virtual_function_free;
		case __game_engine_virtual_function_init_graphics:			return __game_engine_v1_virtual_function_init_graphics;
		case __game_engine_virtual_function_init_thread:			return __game_engine_v1_virtual_function_init_thread;
		case __game_engine_virtual_function_update_engine_state:	return __game_engine_v1_virtual_function_update_engine_state;
		case __game_engine_virtual_function_member_4:				return __game_engine_v1_virtual_function_member_4;
		case __game_engine_virtual_function_member_5:				return __game_engine_v1_virtual_function_member_5;
		case __game_engine_virtual_function_member_6:				return __game_engine_v1_virtual_function_member_6;
		case __game_engine_virtual_function_member_7:				return __game_engine_v1_virtual_function_member_7;
		case __game_engine_virtual_function_member_8:				return __game_engine_v1_virtual_function_member_8;
		case __game_engine_virtual_function_member_9:				return __game_engine_v1_virtual_function_member_9;
		case __game_engine_virtual_function_member_10:				return __game_engine_v1_virtual_function_member_10;
		}
	}
	throw;
}

class IGameEngine;

class __IGameEngine // raw data
{
	friend class IGameEngine;
private:
	void* (&__vfptr)[32];
	DWORD unknown8;
	float GameSpeed;
	char unknown10[1056];
	SLIST_HEADER header430;
	SLIST_HEADER header440;
	char unknown450[16];
};
static_assert_64(sizeof(__IGameEngine) == 0x460, "__IGameEngine is incorrect size");

class IGameEngine
{
public:
	IGameEngine(__IGameEngine& game_engine, e_build build) :
		game_engine(game_engine),
		build(build)
	{
		REFERENCE_ASSERT(game_engine);


		uint32_t free_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_free);
		uint32_t init_graphics_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_init_graphics);
		uint32_t init_thread_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_init_thread);
		uint32_t update_engine_state_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_update_engine_state);
		uint32_t member_4_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_member_4);
		uint32_t member_5_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_member_5);
		uint32_t member_6_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_member_6);
		uint32_t member_7_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_member_7);
		uint32_t member_8_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_member_8);
		uint32_t member_9_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_member_9);
		uint32_t member_10_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_member_10);

		_Free = static_cast<decltype(_Free)>(game_engine.__vfptr[free_virtual_function_index]);
		_InitGraphics = static_cast<decltype(_InitGraphics)>(game_engine.__vfptr[init_graphics_virtual_function_index]);
		_InitThread = static_cast<decltype(_InitThread)>(game_engine.__vfptr[init_thread_virtual_function_index]);
		_UpdateEngineState = static_cast<decltype(_UpdateEngineState)>(game_engine.__vfptr[update_engine_state_virtual_function_index]);
		_Member04 = static_cast<decltype(_Member04)>(game_engine.__vfptr[member_4_virtual_function_index]);
		_Member05 = static_cast<decltype(_Member05)>(game_engine.__vfptr[member_5_virtual_function_index]);
		_Member06 = static_cast<decltype(_Member06)>(game_engine.__vfptr[member_6_virtual_function_index]);
		_Member07 = static_cast<decltype(_Member07)>(game_engine.__vfptr[member_7_virtual_function_index]);
		_Member08 = static_cast<decltype(_Member08)>(game_engine.__vfptr[member_8_virtual_function_index]);
		_Member09 = static_cast<decltype(_Member09)>(game_engine.__vfptr[member_9_virtual_function_index]);
		_Member10 = static_cast<decltype(_Member10)>(game_engine.__vfptr[member_10_virtual_function_index]);

		DEBUG_ASSERT(_Free != nullptr);
		DEBUG_ASSERT(_InitGraphics != nullptr);
		DEBUG_ASSERT(_InitThread != nullptr);
		DEBUG_ASSERT(_UpdateEngineState != nullptr);
		DEBUG_ASSERT(_Member04 != nullptr);
		DEBUG_ASSERT(_Member05 != nullptr);
		DEBUG_ASSERT(_Member06 != nullptr);
		DEBUG_ASSERT(_Member07 != nullptr);
		DEBUG_ASSERT(_Member08 != nullptr);
		DEBUG_ASSERT(_Member09 != nullptr);
		DEBUG_ASSERT(_Member10 != nullptr);
	}

	~IGameEngine()
	{

	}

	typedef __int64 __fastcall FreeFunc(__IGameEngine*);
	typedef __int64 __fastcall InitGraphicsFunc(
		__IGameEngine*,
		ID3D11Device* pDevice,
		ID3D11DeviceContext* pDeviceContext,
		IDXGISwapChain* pSwapchain,
		IDXGISwapChain* pFallbackSwapchain);
	typedef HANDLE __fastcall InitThreadFunc(__IGameEngine*, class IGameEngineHost* pGameEngineHost, GameContext* pGameContext);
	typedef __int64 __fastcall UpdateEngineStateFunc(__IGameEngine*, eEngineState status, _QWORD* extraArgument);
	typedef void __fastcall Member04Func(__IGameEngine*, ID3D11Device* pDevice);
	typedef void __fastcall Member05Func(__IGameEngine*, int map_id);
	typedef void __fastcall Member06Func(__IGameEngine*);
	typedef void __fastcall Member07Func(__IGameEngine*);
	typedef void __fastcall Member08Func(__IGameEngine*);
	typedef __int64 __fastcall Member09Func(__IGameEngine*, const char* a1);
	typedef __int64 __fastcall Member10Func(__IGameEngine*);

	__IGameEngine& game_engine;
	e_build build;

	FreeFunc* _Free;
	InitGraphicsFunc* _InitGraphics;
	InitThreadFunc* _InitThread;
	UpdateEngineStateFunc* _UpdateEngineState;
	Member04Func* _Member04;
	Member05Func* _Member05;
	Member06Func* _Member06;
	Member07Func* _Member07;
	Member08Func* _Member08;
	Member09Func* _Member09;
	Member10Func* _Member10;

	__int64 __fastcall Free() { _Free(&game_engine); }
	__int64 __fastcall InitGraphics(
		ID3D11Device* pDevice,
		ID3D11DeviceContext* pDeviceContext,
		IDXGISwapChain* pSwapchain,
		IDXGISwapChain* pFallbackSwapchain)
	{
		return _InitGraphics(&game_engine, pDevice, pDeviceContext, pSwapchain, pFallbackSwapchain);
	}
	HANDLE __fastcall InitThread(class IGameEngineHost* pGameEngineHost, GameContext* pGameContext) { return _InitThread(&game_engine, pGameEngineHost, pGameContext); }
	__int64 __fastcall UpdateEngineState(eEngineState status, _QWORD* extraArgument = nullptr) { return _UpdateEngineState(&game_engine, status, extraArgument); }
	void __fastcall Member04(ID3D11Device* pDevice) { return _Member04(&game_engine, pDevice); }
	void __fastcall Member05(int map_id) { return _Member05(&game_engine, map_id); }
	void __fastcall Member06() { return _Member06(&game_engine); }
	void __fastcall Member07() { return _Member07(&game_engine); }
	void __fastcall Member08() { return _Member08(&game_engine); }
	__int64 __fastcall Member09(const char* a1) { return _Member09(&game_engine, a1); }
	__int64 __fastcall Member10() { return _Member10(&game_engine); }
};

#endif












