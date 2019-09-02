#pragma once

class IGameEngineHost
{
public:

	static void CreateClientConnection(int port = 0);
	static void CreateServerConnection();

	static bool g_enableGameEngineHostOverride;

	enum InputUpdatePatchState
	{
		WaitingForRun,
		WaitingForPatch,
		Patched
	};
	static InputUpdatePatchState g_inputUpdatePatchState;
	
	static IGameEngineHost g_gameEngineHost;

	struct InputBuffer
	{
		int unknown0;
		char keyboardState[256];
		float MouseX;
		float MouseY;
		char data2[12];
		char data3[16];
	};
	static_assert(sizeof(InputBuffer) == 0x128, "");

	IGameEngineHost();
	~IGameEngineHost();

	// VFTBL
	virtual void Member00();
	virtual void Member01(IDXGISwapChain* pSwapChain, _QWORD);
	virtual void Member02();
	virtual void Member03(__int64);
	virtual void GameRestart();
	virtual void __fastcall WriteGameState(LPVOID, size_t);
	virtual void Member06();
	virtual void Member07();
	virtual void Member08();
	virtual void Member09();
	virtual IGameEvents* GetGameEvents();
	virtual void Member11(); // DataAccessGameVariant
	virtual void Member12(); // DataAccessMapVariant
	virtual void Member13();
	virtual void Member14();
	virtual void GetNextLevelInfo();
	virtual void Member16();
	virtual void Member17();
	virtual void Member18();
	virtual __int64 __fastcall Member19(__int64/*, __int64, __int64*/);
	virtual void Member20();
	virtual __int64 __fastcall Member21(_QWORD);
	virtual void Member22();
	virtual void Member23();
	virtual void Member24();

	struct unknown_network_type
	{
		char data[24];
	};

	struct Member25Struct
	{
		unknown_network_type data[16];
		int unknown;
		int unknown2;
	};

	virtual void Member25(Member25Struct* a1, uint32_t a2);
	virtual void Member26();
	virtual void Member27();
	virtual bool Member28(__int64 a2);
	virtual bool Member29(__int64 a2, __int64 a3);
	virtual unsigned __int8 __fastcall Member30(_QWORD, InputBuffer *pInputBuffer);
	virtual bool __fastcall GetPlayerName(__int64*, wchar_t playerNames[4][32], size_t);
	virtual void Member32();
	virtual void Member33();
	virtual __int64 __fastcall NetworkSendTo(__int64 a2, char* buffer, uint32_t buffersize, int a5);
	virtual __int64 NetworkReceiveFrom(char* buffer, uint32_t buffersize, __int64 a4, int a5);
	virtual void Member36();
	virtual void Member37();
	virtual void Member38();
	virtual void Member39();
	virtual void Member40();
	virtual void Member41();
	virtual unsigned __int8 __fastcall FileAccessed(_QWORD, WCHAR*, __int64);
	virtual unsigned __int8* Member43(__int64, char*);

	// DATA

	IGameEvents* pGameEvents;
	QWORD data1[5863];

	// IGameEngineHost bypass functions

	enum class GEHCBypassType // GameEngineHostCallbackType
	{
		UseValidPointer,
		UseNullPointer
	};

	template<GEHCBypassType type, typename T, typename IGameEngineHostRefType>
	static decltype(auto) GEHCBypass(IGameEngineHostRefType& game_engine_host_pointer, T&& functionPtr, bool forceDisable = false) // GameEngineHostCallback
	{
		using return_type = decltype(functionPtr());

		IGameEngineHost* pGameEngineHostBefore = game_engine_host_pointer;

		if constexpr (type == GEHCBypassType::UseValidPointer)
		{
			if (g_enableGameEngineHostOverride && !forceDisable)
			{
				game_engine_host_pointer = &g_gameEngineHost;
			}
		}
		else
		{
			if (g_enableGameEngineHostOverride && !forceDisable)
			{
				game_engine_host_pointer = nullptr;
			}
		}

		if constexpr (std::is_same<return_type, void>::value)
		{
			functionPtr();

			if (g_enableGameEngineHostOverride && !forceDisable)
			{
				game_engine_host_pointer = pGameEngineHostBefore;
			}
		}
		else
		{
			decltype(functionPtr()) result = functionPtr();

			if (g_enableGameEngineHostOverride && !forceDisable)
			{
				game_engine_host_pointer = pGameEngineHostBefore;
			}

			return result;
		}
	}
};
static constexpr size_t IGameEngineHostSize = sizeof(IGameEngineHost);
static_assert(IGameEngineHostSize == 0xB748, "IGameEngineHost is incorrect");
