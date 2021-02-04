#pragma once

enum e_engine_state : int
{
	_engine_state_pause,
	_engine_state_unpause,

	_engine_state_immediate_exit,
	_engine_state_restart_checkpoint,
	_engine_state_restart_level,

	_engine_state_reload_settings,

	// 6 and 7 are connected
	_engine_state_game_load_start, // sets a temp variable to `g_render_thread_mode` and sets `g_render_thread_mode` to `0`, sets `g_game_is_loading` to `true` and runs `UpdateGameStatus(RestartCheckpoint)`
	_engine_state_game_load_end, // sets `g_render_thread_mode` to the temp variable and sets the temp variable to `0`, sets `g_game_is_loading` to `false` and runs `UpdateGameStatus(RestartLevel)`

	// 8 and 9 are connected
	_engine_state_push_ui_page, // allocates `c_controller_input_message` (loadout selection is shown) and sets a temp variable to `true`
	_engine_state_pop_ui_page, // sets the temp variable to `false` and player spawns

	_engine_state_game_variant_save, // creates a new `IGameVariant` and passes it to `IGameEngineHostLegacy::SaveGameVariant`
	_engine_state_map_variant_save, // creates a new `IMapVariant` and passes it to `IGameEngineHostLegacy::SaveMapVariant`

	_engine_state_round_end, // not confirmed
	_engine_state_game_end, // not confirmed

	_engine_state_reload_renderer, // potentially enhanced graphics. causes member 42 to run, also causes memory spike!

	_engine_state_unknown15, // unknown
	_engine_state_unknown16, // unknown this takes some extra argument provided to engine_state_update
};
extern const char* engine_state_to_string(e_engine_state engineState);

#ifdef __INTELLISENSE__

/*
	IGameEngine Revision 2 : Build 1367
*/
class __IGameEngine;
class IGameEngine
{
public: // instance functions
	virtual void Dtor();
	virtual __forceinline __int64 __fastcall InitGraphics(ID3D11Device* device, ID3D11DeviceContext* device_context, IDXGISwapChain* swapchain, IDXGISwapChain* swapchain_fallback);
	virtual HANDLE __fastcall PlayGame(class IGameEngineHost* host, GameOptions* options);
	virtual __int64 __fastcall EngineStateUpdate(e_engine_state status, _QWORD* extraArgument = nullptr);
	virtual void __fastcall PreloadCommonBegin(ID3D11Device* device);
	virtual void __fastcall PreloadLevelBegin(int map_id);
	virtual void __fastcall Member06();
	virtual void __fastcall Member07();
	virtual void __fastcall Member08();
	virtual __int64 __fastcall SendEngineCommand(const char* command);
	virtual __int64 __fastcall Member10();

	// #INTELLISENSE
	IGameEngine(__IGameEngine& game_engine, e_build build);
	
private:
	int m_externalUIActiveCounter;
	float m_old_film_playback_speed;

	SLIST_HEADER ListHeaders[69];
};


#else

enum IGameEngineVirtualFunctionIndex
{
	__game_engine_virtual_function_dtor,
	__game_engine_virtual_function_init_graphics,
	__game_engine_virtual_function_play_game,
	__game_engine_virtual_function_engine_state_update,
	__game_engine_virtual_function_preload_common_begin,
	__game_engine_virtual_function_preload_level_begin,
	__game_engine_virtual_function_member_6,
	__game_engine_virtual_function_member_7,
	__game_engine_virtual_function_member_8,
	__game_engine_virtual_function_send_engine_command,
	__game_engine_virtual_function_member_10,
};

inline uint32_t get_game_engine_virtual_function_index(e_build build, IGameEngineVirtualFunctionIndex game_engine_virtual_function_index)
{
	enum IGameEngineV1VirtualFunctionIndex
	{
		__game_engine_v1_virtual_function_init_graphics,
		__game_engine_v1_virtual_function_play_game,
		__game_engine_v1_virtual_function_engine_state_update,
		__game_engine_v1_virtual_function_dtor,
		__game_engine_v1_virtual_function_preload_common_begin,
		__game_engine_v1_virtual_function_preload_level_begin,
		__game_engine_v1_virtual_function_member_6,
		__game_engine_v1_virtual_function_member_7,
		__game_engine_v1_virtual_function_member_8,
		__game_engine_v1_virtual_function_send_engine_command,
		__game_engine_v1_virtual_function_member_10,
	};

	enum IGameEngineV2VirtualFunctionIndex
	{
		__game_engine_v2_virtual_function_dtor,
		__game_engine_v2_virtual_function_init_graphics,
		__game_engine_v2_virtual_function_play_game,
		__game_engine_v2_virtual_function_engine_state_update,
		__game_engine_v2_virtual_function_preload_common_begin,
		__game_engine_v2_virtual_function_preload_level_begin,
		__game_engine_v2_virtual_function_member_6,
		__game_engine_v2_virtual_function_member_7,
		__game_engine_v2_virtual_function_member_8,
		__game_engine_v2_virtual_function_send_engine_command,
		__game_engine_v2_virtual_function_member_10,
	};

	if (build >= _build_mcc_1_1367_0_0)
	{
		// version 2
		switch (game_engine_virtual_function_index)
		{
		case __game_engine_virtual_function_dtor:					return __game_engine_v2_virtual_function_dtor;
		case __game_engine_virtual_function_init_graphics:			return __game_engine_v2_virtual_function_init_graphics;
		case __game_engine_virtual_function_play_game:				return __game_engine_v2_virtual_function_play_game;
		case __game_engine_virtual_function_engine_state_update:	return __game_engine_v2_virtual_function_engine_state_update;
		case __game_engine_virtual_function_preload_common_begin:	return __game_engine_v2_virtual_function_preload_common_begin;
		case __game_engine_virtual_function_preload_level_begin:	return __game_engine_v2_virtual_function_preload_level_begin;
		case __game_engine_virtual_function_member_6:				return __game_engine_v2_virtual_function_member_6;
		case __game_engine_virtual_function_member_7:				return __game_engine_v2_virtual_function_member_7;
		case __game_engine_virtual_function_member_8:				return __game_engine_v2_virtual_function_member_8;
		case __game_engine_virtual_function_send_engine_command:	return __game_engine_v2_virtual_function_send_engine_command;
		case __game_engine_virtual_function_member_10:				return __game_engine_v2_virtual_function_member_10;
		}
	}
	else
	{
		// version 1
		switch (game_engine_virtual_function_index)
		{
		case __game_engine_virtual_function_dtor:					return __game_engine_v1_virtual_function_dtor;
		case __game_engine_virtual_function_init_graphics:			return __game_engine_v1_virtual_function_init_graphics;
		case __game_engine_virtual_function_play_game:				return __game_engine_v1_virtual_function_play_game;
		case __game_engine_virtual_function_engine_state_update:	return __game_engine_v1_virtual_function_engine_state_update;
		case __game_engine_virtual_function_preload_common_begin:	return __game_engine_v1_virtual_function_preload_common_begin;
		case __game_engine_virtual_function_preload_level_begin:	return __game_engine_v1_virtual_function_preload_level_begin;
		case __game_engine_virtual_function_member_6:				return __game_engine_v1_virtual_function_member_6;
		case __game_engine_virtual_function_member_7:				return __game_engine_v1_virtual_function_member_7;
		case __game_engine_virtual_function_member_8:				return __game_engine_v1_virtual_function_member_8;
		case __game_engine_virtual_function_send_engine_command:	return __game_engine_v1_virtual_function_send_engine_command;
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
	int m_externalUIActiveCounter;
	float m_old_film_playback_speed;
	SLIST_HEADER ListHeaders[69];
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


		uint32_t dtor_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_dtor);
		uint32_t init_graphics_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_init_graphics);
		uint32_t play_game_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_play_game);
		uint32_t engine_state_update_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_engine_state_update);
		uint32_t preload_common_begin_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_preload_common_begin);
		uint32_t preload_level_begin_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_preload_level_begin);
		uint32_t member_6_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_member_6);
		uint32_t member_7_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_member_7);
		uint32_t member_8_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_member_8);
		uint32_t send_engine_command_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_send_engine_command);
		uint32_t member_10_virtual_function_index = get_game_engine_virtual_function_index(build, __game_engine_virtual_function_member_10);

		_Dtor = static_cast<decltype(_Dtor)>(game_engine.__vfptr[dtor_virtual_function_index]);
		_InitGraphics = static_cast<decltype(_InitGraphics)>(game_engine.__vfptr[init_graphics_virtual_function_index]);
		_PlayGame = static_cast<decltype(_PlayGame)>(game_engine.__vfptr[play_game_virtual_function_index]);
		_EngineStateUpdate = static_cast<decltype(_EngineStateUpdate)>(game_engine.__vfptr[engine_state_update_virtual_function_index]);
		_PreloadCommonBegin = static_cast<decltype(_PreloadCommonBegin)>(game_engine.__vfptr[preload_common_begin_virtual_function_index]);
		_PreloadLevelBegin = static_cast<decltype(_PreloadLevelBegin)>(game_engine.__vfptr[preload_level_begin_virtual_function_index]);
		_Member06 = static_cast<decltype(_Member06)>(game_engine.__vfptr[member_6_virtual_function_index]);
		_Member07 = static_cast<decltype(_Member07)>(game_engine.__vfptr[member_7_virtual_function_index]);
		_Member08 = static_cast<decltype(_Member08)>(game_engine.__vfptr[member_8_virtual_function_index]);
		_SendEngineCommand = static_cast<decltype(_SendEngineCommand)>(game_engine.__vfptr[send_engine_command_virtual_function_index]);
		_Member10 = static_cast<decltype(_Member10)>(game_engine.__vfptr[member_10_virtual_function_index]);

		DEBUG_ASSERT(_Dtor != nullptr);
		DEBUG_ASSERT(_InitGraphics != nullptr);
		DEBUG_ASSERT(_PlayGame != nullptr);
		DEBUG_ASSERT(_EngineStateUpdate != nullptr);
		DEBUG_ASSERT(_PreloadCommonBegin != nullptr);
		DEBUG_ASSERT(_PreloadLevelBegin != nullptr);
		DEBUG_ASSERT(_Member06 != nullptr);
		DEBUG_ASSERT(_Member07 != nullptr);
		DEBUG_ASSERT(_Member08 != nullptr);
		DEBUG_ASSERT(_SendEngineCommand != nullptr);
		DEBUG_ASSERT(_Member10 != nullptr);
	}

	~IGameEngine()
	{

	}

	typedef __int64 __fastcall DtorFunc(__IGameEngine*);
	typedef __int64 __fastcall InitGraphicsFunc(__IGameEngine*, ID3D11Device* device, ID3D11DeviceContext* device_context, IDXGISwapChain* swapchain, IDXGISwapChain* swapchain_fallback);
	typedef HANDLE __fastcall InitThreadFunc(__IGameEngine*, class IGameEngineHost* host, GameOptions* options);
	typedef __int64 __fastcall EngineStateUpdateFunc(__IGameEngine*, e_engine_state state, _QWORD* extraArgument);
	typedef void __fastcall PreloadCommonBeginFunc(__IGameEngine*, ID3D11Device* device);
	typedef void __fastcall PreloadLevelBeginFunc(__IGameEngine*, int map_id);
	typedef void __fastcall Member06Func(__IGameEngine*);
	typedef void __fastcall Member07Func(__IGameEngine*);
	typedef void __fastcall Member08Func(__IGameEngine*);
	typedef __int64 __fastcall SendEngineCommandFunc(__IGameEngine*, const char* command);
	typedef __int64 __fastcall Member10Func(__IGameEngine*);

	__IGameEngine& game_engine;
	e_build build;

	DtorFunc* _Dtor;
	InitGraphicsFunc* _InitGraphics;
	InitThreadFunc* _PlayGame;
	EngineStateUpdateFunc* _EngineStateUpdate;
	PreloadCommonBeginFunc* _PreloadCommonBegin;
	PreloadLevelBeginFunc* _PreloadLevelBegin;
	Member06Func* _Member06;
	Member07Func* _Member07;
	Member08Func* _Member08;
	SendEngineCommandFunc* _SendEngineCommand;
	Member10Func* _Member10;

	__int64 __fastcall Dtor() { _Dtor(&game_engine); }
	__int64 __fastcall InitGraphics(ID3D11Device* device, ID3D11DeviceContext* device_context, IDXGISwapChain* swapchain, IDXGISwapChain* swapchain_fallback)
	{
		return _InitGraphics(&game_engine, device, device_context, swapchain, swapchain_fallback);
	}
	HANDLE __fastcall PlayGame(class IGameEngineHost* host, GameOptions* options) { return _PlayGame(&game_engine, host, options); }
	__int64 __fastcall EngineStateUpdate(e_engine_state state, _QWORD* extraArgument = nullptr) { return _EngineStateUpdate(&game_engine, state, extraArgument); }
	void __fastcall PreloadCommonBegin(ID3D11Device* device) { return _PreloadCommonBegin(&game_engine, device); }
	void __fastcall PreloadLevelBegin(int map_id) { return _PreloadLevelBegin(&game_engine, map_id); }
	void __fastcall Member06() { return _Member06(&game_engine); }
	void __fastcall Member07() { return _Member07(&game_engine); }
	void __fastcall Member08() { return _Member08(&game_engine); }
	__int64 __fastcall SendEngineCommand(const char* command) { return _SendEngineCommand(&game_engine, command); }
	__int64 __fastcall Member10() { return _Member10(&game_engine); }
};

#endif












