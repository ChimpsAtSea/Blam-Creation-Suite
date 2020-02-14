#pragma once

#define IGameEngineHostCreateBarrierDefinition(index) virtual void Member##index() final; 

class IGameEngineHost
{
public:

	enum class PathType : int
	{
		DebugLogs,
		Config,
		Temporary,
		Root
	};

	enum NetworkID : unsigned __int64
	{
		Invalid,
		Unknown1,
		Unknown2,
		Unknown3,
		k_NumNetworkID
	};

#pragma pack(push, 1)
	enum class InputSource : int
	{
		Gamepad,
		MouseAndKeyboard
	};

	struct InputBuffer
	{

		InputSource		inputSource;
		char			keyboardState[256];
		float			MouseX;
		float			MouseY;
		_QWORD			unknown10C;
		char			mouseButtonBits;
		char			__padding[3];
		DWORD           wButtons;
		BYTE            bLeftTrigger;
		BYTE            bRightTrigger;
		SHORT           sThumbLX;
		SHORT           sThumbLY;
		SHORT           sThumbRX;
		SHORT           sThumbRY;
		char			__padding2[2];
	};
	CHECK_STRUCTURE_SIZE(InputBuffer, 0x128);
#pragma pack(pop)

	struct GameResultsData
	{
		char unknown0[0x58738];
	};
	CHECK_STRUCTURE_SIZE(GameResultsData, 0x58738);

	struct Function22Structure
	{
		char data[0x110];
	};
	CHECK_STRUCTURE_SIZE(Function22Structure, 0x110);

#pragma pack(push, 1)
	struct Function28Structure
	{
		long width;
		long height;
		long unknown8;
		long unknownC;
		long unknown10_0;
		long unknown10_4;
		long unknown10_8;
		long unknown10_C;
		long unknown20;
		long unknown24;
		char unknown28;
		unsigned short fps_flags;
		char unknown2B;
		char unknown2C[168]; // unknown
		float unknownD4_0;
		float unknownD4_4;
		float unknownD4_8;
		float unknownD4_C;
		float unknownD4_10;
		float unknownD4_14;
		float unknownD4_18;
		float unknownD4_1C;
		float unknownD4_20;
		float unknownD4_24;
		float unknownD4_28;
		float unknownD4_2C;
		float unknownD4_30;
		float unknownD4_34;
		float unknownD4_38;
		float unknownD4_3C;
		float unknownD4_40;
		float unknownD4_44;
		float unknownD4_48;
		float unknownD4_4C;
		float unknownD4_50;
		float unknownD4_54;
		float unknownD4_58;
		float unknownD4_5C;
		float unknownD4_60;
		float unknownD4_64;
		float unknownD4_68;
		float unknownD4_6C;
		float unknownD4_70;
		float unknownD4_74;
		float unknownD4_78;
		float unknownD4_7C;
		float unknownD4_80;
		float unknownD4_84;
		long unknownD4_88;
		long unknownD4_8C;
		long unknownD4_90;
		long unknownD4_94;
		long unknownD4_98;
		long unknownD4_9C;
		long unknownD4_A0;
		long unknownD4_A4;
		long unknownD4_A8;
	};
	CHECK_STRUCTURE_SIZE(Function28Structure, 0x180);
#pragma pack(pop)

	struct PlayerConfiguration
	{
		INT32   option0;
		char    padding4[12];
		char    unknown10;
		char    padding11;
		char    option12;
		char    option13;
		char    option14;
		char    padding15;
		char    auto_center_look_option;
		char    crouch_lock_option;
		char    padding18;
		char    clench_protection_option;
		char    unknown1A[14];
		bool    is_elite;
		char    padding29[7];
		INT32   armor_helmet_option;
		INT32   armor_left_shoulder_option;
		INT32   armor_right_shoulder_option;
		INT32   armor_chest_option;
		INT32   armor_wrist_option;
		INT32   armor_leg_utility_option;
		INT32   armor_knees_option;
		INT32   option4C_customization_related;
		INT32   armor_effect_dupe_option;
		INT32   option54_customization_related;
		INT32   elite_armor_option;
		INT32   armor_effect_option;
		INT32   firefight_voice_option;
		INT32   primary_color_option;
		INT32   secondary_color_option;
		char    padding6C[4];
		wchar_t service_tag[5];
		char    padding7A[2];
		INT32   option7C;
		INT32   option80;
		INT32   option84;
		float   option88;
		float   option8C;
		char    padding90[8];
		INT32   controller_layout_option;
		INT32   option9C;
		INT32   optionA0;
		char    paddingA4[16];
		INT32   look_sensitivity_option;
		INT32   optionB8;
		INT32   optionBC;
		INT32   optionC0;
		char    optionC4;
		char    optionC5;
		char    unknownC6;
		char    paddingC7;
		char    unknownC8[56];
		char    unknown100[256];
		char    unknown200[512];
		char    unknown400[512];
		char    unknown600[128];
	};
	CHECK_STRUCTURE_SIZE(PlayerConfiguration, 0x680);

	struct s_transport_address;

	inline IGameEngineHost(IGameEvents* pGameEvents)
		:m_pGameEvents(pGameEvents)
	{

	}

	/* 0  */ virtual char FrameStart() = 0;
	/* 1  */ virtual void FrameEnd(IDXGISwapChain* pSwapChain, _QWORD) = 0;
	/* 2  */ virtual void Member02(__int64 player_identifier, unsigned int, __int64, float, float, float, float) = 0;
	/* 3  */ virtual void EngineStateUpdate(eEngineState state) = 0;
	/* 4  */ virtual __int64 GameExited(unsigned int, char*, int) = 0;
	/* 5  */ virtual __int64 __fastcall WriteBufferToFile(LPVOID pBuffer, size_t bufferSize) = 0;
	/* 6  */ virtual void Member06(GameResultsData* pGameResultsData) = 0;
	/* 7  */ virtual void Member07(unsigned int) = 0;
	/* 8  */ virtual void Member08(const wchar_t*, const wchar_t*) = 0;
	/* 9  */ virtual void Member09(wchar_t[1024], wchar_t[1024]) = 0;
	/* 10 */ virtual IGameEvents* GetGameEvents() = 0;
	/* 11 */ virtual void UpdateGameVariant(IGameVariant* pGameVariant) = 0;
	/* 12 */ virtual void UpdateMapVariant(IMapVariant* pMapVariant) = 0;
	/* 13 */ virtual void Member13(const wchar_t*, const wchar_t*, const void*, unsigned int) = 0;
	/* 14 */ virtual char Member14(int controllerIndex, BYTE*) = 0;
	/* 15 */ virtual char Member15(int controllerIndex, BYTE*) = 0;
	/* 16 */ virtual char GetNextLevelInfo(MapID* pMapID, int* pCampaignInsertionPoint, FILETIME* pFiletime, _DWORD*) = 0;
	/* 17 */ virtual bool Member17(int) = 0;
	/* 18 */ virtual void Member18(int) = 0;
	/* 19 */ virtual __int64 __fastcall MapLoadPecentStatus(__int64, __int64, float) = 0;
	/* 20 */ virtual void Member20(__int64, __int8) = 0;
	/* 21 */ virtual __int64 __fastcall GetMachineIdentifier(_QWORD) = 0;
	/* 22 */ virtual __int64 Member22(Function22Structure* buffer, __int64) = 0;
	/* 23 */ virtual char Member23(__int64, __int64) = 0;
	/* 24 */ virtual void GetSessionInfo(s_session_info_part* pSessionInfoPart) = 0;
	/* 25 */ virtual void __fastcall MembershipUpdate(s_session_membership* pSessionMembership, uint32_t playercount) = 0;
	/* 26 */ virtual bool __fastcall Member26() = 0;
	/* 27 */ virtual bool __fastcall Member27() = 0;
	/* 28 */ virtual bool __fastcall UpdateGraphics(Function28Structure* pUnknown) = 0;
	/* 29 */ virtual __int64 __fastcall Member29(__int64 value) = 0;
	/* 30 */ virtual __int64 __fastcall UpdatePlayerConfiguration(wchar_t playerNames[4][32], PlayerConfiguration& rPlayerConfiguration) = 0;
	/* 31 */ virtual bool __fastcall __fastcall UpdateInput(_QWORD, InputBuffer* pInputBuffer) = 0;
	/* 32 */ virtual void Member32(_QWORD, float*) = 0;
	/* 33 */ virtual void Member33() = 0;
	/* 34 */ virtual void XInputSetState(DWORD dwUserIndex, XINPUT_VIBRATION* pVibration) = 0;
	/* 35 */ virtual bool __fastcall __fastcall UpdatePlayerNames(__int64*, wchar_t pszPlayerNames[4][32], size_t dataSize) = 0;
	/* 36 */ virtual void __fastcall Member36(const wchar_t*, const wchar_t*) = 0;
	/* 37 */ virtual bool __fastcall Member37(wchar_t*, __int64) = 0;
	/* 38 */ virtual __int64 __fastcall NetworkSendTo(NetworkID networkID, char* pBuffer, uint32_t buffersize, int) = 0;
	/* 39 */ virtual __int64 __fastcall NetworkReceiveFrom(char* pBuffer, uint32_t buffersize, __int64, s_transport_address* pTransportAddress) = 0;
	/* 40 */ virtual char* __fastcall Member40(unsigned int) = 0;
	/* 41 */ virtual int __fastcall Member41(BYTE* pBuffer) = 0;
	/* 42 */ virtual bool __fastcall Member42(signed int, __int64, __int64) = 0;
	/* 43 */ virtual void __fastcall FirefightNew(__int64, float) = 0;
	/* 44 */ virtual BOOL __fastcall Member44(__int64, __int64) = 0;
	/* 45 */ virtual bool __fastcall GetPathByType(PathType pathType, LPSTR pBuffer, size_t bufferLength) = 0;
	/* 46 */ virtual bool __fastcall GetWidePathByType(PathType pathType, LPWSTR pBuffer, size_t bufferLength) = 0;
	/* 47 */ virtual unsigned __int8* __fastcall Member47(_QWORD, unsigned __int8*, _QWORD) = 0;
	/* 48 */ virtual __int64 __fastcall Member48(_QWORD, __int64) = 0;

	/* barrier functions to prevent new versions of games calling our functions */
	IGameEngineHostCreateBarrierDefinition(49);
	IGameEngineHostCreateBarrierDefinition(50);
	IGameEngineHostCreateBarrierDefinition(51);
	IGameEngineHostCreateBarrierDefinition(52);
	IGameEngineHostCreateBarrierDefinition(53);
	IGameEngineHostCreateBarrierDefinition(54);
	IGameEngineHostCreateBarrierDefinition(55);
	IGameEngineHostCreateBarrierDefinition(56);

	// DATA
	IGameEvents* m_pGameEvents = nullptr;
	QWORD data1[5863] = {};
};
CHECK_STRUCTURE_SIZE(IGameEngineHost, 0xB748);

#undef IGameEngineHostCreateBarrierDefinition

