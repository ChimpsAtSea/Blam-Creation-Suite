#pragma once

class IGameEngineHost
{
public:

	static IGameEngineHost g_gameEngineHost;

	struct InputBuffer
	{
		int unknown0;
		char data0[256];
		char data1[20];
		char data2[16];
	};
	static_assert(sizeof(InputBuffer) == 0x128, "");

	IGameEngineHost();
	~IGameEngineHost();

	// VFTBL
	virtual void Member00();
	virtual void Member01();
	virtual void Member02();
	virtual void Member03();
	virtual void Member04();
	virtual void __fastcall WriteGameState(LPVOID, size_t);
	virtual void Member06();
	virtual void Member07();
	virtual void Member08();
	virtual void Member09();
	virtual void GetGameEvents();
	virtual void Member11(); // DataAccessGameVariant
	virtual void Member12(); // DataAccessMapVariant
	virtual void Member13();
	virtual void Member14();
	virtual void GetNextMapId();
	virtual void Member16();
	virtual void Member17();
	virtual void Member18();
	virtual __int64 __fastcall Member19(__int64/*, __int64, __int64*/);
	virtual void Member20();
	virtual void Member21();
	virtual void Member22();
	virtual void Member23();
	virtual void Member24();
	virtual void Member25();
	virtual void Member26();
	virtual void Member27();
	virtual void Member28();
	virtual void Member29();
	virtual unsigned __int8 __fastcall Member30(_QWORD, InputBuffer* pInputBuffer);
	virtual void SetPlayerName();
	virtual void Member32();
	virtual void Member33();
	virtual void Member34();
	virtual void Member35();
	virtual void Member36();
	virtual void Member37();
	virtual void Member38();
	virtual void Member39();
	virtual void Member40();
	virtual void Member41();
	virtual void Member42();
	virtual void Member43();

	// DATA

	GameEvents* pGameEvents;
	QWORD data1[5863];

	// IGameEngineHost bypass functions 

	enum class GEHCBypassType // GameEngineHostCallbackType
	{
		UseValidPointer,
		UseNullPointer
	};

	template<GEHCBypassType type, typename T>
	static decltype(auto) GEHCBypass(T functionPtr, bool forceDisable = false) // GameEngineHostCallback
	{
		using return_type = decltype(functionPtr());

		IGameEngineHost* pGameEngineHostBefore = g_game_engine_host_pointer;

		if constexpr (type == GEHCBypassType::UseValidPointer)
		{
			if (g_enableGameEngineHostOverride && !forceDisable)
			{
				g_game_engine_host_pointer = &gameEngineHost;
			}
		}
		else
		{
			if (g_enableGameEngineHostOverride && !forceDisable)
			{
				g_game_engine_host_pointer = nullptr;
			}
		}

		if constexpr (std::is_same<return_type, void>::value)
		{
			functionPtr();

			if (g_enableGameEngineHostOverride && !forceDisable)
			{
				g_game_engine_host_pointer = pGameEngineHostBefore;
			}
		}
		else
		{
			decltype(functionPtr()) result = functionPtr();

			if (g_enableGameEngineHostOverride && !forceDisable)
			{
				g_game_engine_host_pointer = pGameEngineHostBefore;
			}

			return result;
		}
	}
};
static constexpr size_t IGameEngineHostSize = sizeof(IGameEngineHost);
static_assert(IGameEngineHostSize == 0xB748, "IGameEngineHost is incorrect");
