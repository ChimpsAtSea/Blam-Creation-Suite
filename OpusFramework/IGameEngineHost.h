#pragma once

class IGameEngineHost
{
public: /* structures and enums */

	enum NetworkID : unsigned __int64
	{
		Invalid,
		Unknown1,
		Unknown2,
		Unknown3,
		k_NumNetworkID
	};

	enum class InputSource : int
	{
		Gamepad,
		MouseAndKeyboard
	};

#pragma pack(push, 1)
	struct InputBuffer
	{
		InputSource inputSource;
		char keyboardState[256];
		float MouseX;
		float MouseY;
		_QWORD unknown10C;
		char mouseButtonBits;
		char __padding[3];
		DWORD                               wButtons;
		BYTE                                bLeftTrigger;
		BYTE                                bRightTrigger;
		SHORT                               sThumbLX;
		SHORT                               sThumbLY;
		SHORT                               sThumbRX;
		SHORT                               sThumbRY;
		char __padding2[2];
	};
#pragma pack(pop)
	static constexpr size_t InputBufferSize = sizeof(InputBuffer);
	static_assert(InputBufferSize == 0x128, "InputBuffer is incorrect size");

	struct s_game_results
	{
		char unknown0[0x58738];
	};
	static constexpr size_t s_game_results_size = sizeof(s_game_results);
	static_assert(s_game_results_size == 0x58738, "s_game_results is incorrect size");

	struct Member22Struct
	{
		char data[0x110];
	};
	static constexpr size_t Member22StructSize = sizeof(Member22Struct);
	static_assert(Member22StructSize == 0x110, "Member22Struct is incorrect size");

#pragma pack(push, 1)
	struct Member28Struct
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
#pragma pack(pop)
	static constexpr size_t Member28StructSize = sizeof(Member28Struct);
	static_assert(Member28StructSize == 0x180, "Member28Struct is incorrect size");

	struct s_player_configuration
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
		char    option28;
		char    padding29[7];
		INT32   armor_helmet_index;
		INT32   armor_left_shoulder_index;
		INT32   armor_right_shoulder_index;
		INT32   armor_chest_index;
		INT32   armor_wrist_index;
		INT32   armor_leg_utility_index;
		INT32   armor_knee_index;
		INT32   option4C_customization_related;
		INT32   armor_effect_dupe_index;
		INT32   option54_customization_related;
		INT32   elite_armor_index;
		INT32   armor_effect_index;
		INT32   firefight_voice_index;
		INT32   option64_customization_related;
		INT32   option68_customization_related;
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
	static constexpr size_t s_player_configuration_size = sizeof(s_player_configuration);
	static_assert(s_player_configuration_size == 0x680, "s_player_configuration is incorrect size");

	struct s_transport_address;

public: /* instance functions */
	IGameEngineHost();
	~IGameEngineHost();

	/* 0  */ virtual char Member00();
	/* 1  */ virtual void FrameEnd(IDXGISwapChain*, _QWORD);
	/* 2  */ virtual void Member02(__int64, unsigned int, __int64, float, float, float, float);
	/* 3  */ virtual void EngineStateUpdate(eEngineState);
	/* 4  */ virtual __int64 GameExited(unsigned int a1, char* a2, int);
	/* 5  */ virtual __int64 __fastcall WriteBufferToFile(LPVOID, size_t);
	/* 6  */ virtual void Member06(s_game_results* buffer);
	/* 7  */ virtual void Member07(unsigned int);
	/* 8  */ virtual void Member08(const wchar_t*, const wchar_t*);
	/* 9  */ virtual void Member09(wchar_t[1024], wchar_t[1024]);
	/* 10 */ virtual IGameEvents* GetGameEvents();
	/* 11 */ virtual void UpdateGameVariant(IGameVariant*);
	/* 12 */ virtual void UpdateMapVariant(IMapVariant*);
	/* 13 */ virtual void Member13(const wchar_t*, const wchar_t*, const void*, unsigned int);
	/* 14 */ virtual char Member14(int, BYTE*);
	/* 15 */ virtual char Member15(int, BYTE*);
	/* 16 */ virtual char GetNextLevelInfo(e_map_id*, int*, FILETIME*, _DWORD*);
	/* 17 */ virtual bool Member17(int);
	/* 18 */ virtual void Member18(int);
	/* 19 */ virtual __int64 __fastcall MapLoadPecentStatus(__int64, __int64, float);
	/* 20 */ virtual void Member20(__int64, __int8);
	/* 21 */ virtual __int64 __fastcall GetMachineIdentifier(_QWORD);
	/* 22 */ virtual __int64 Member22(Member22Struct* buffer, __int64);
	/* 23 */ virtual char Member23(__int64, __int64);
	/* 24 */ virtual void GetSessionInfo(s_session_info_part* buffer);
	/* 25 */ virtual void __fastcall MembershipUpdate(s_session_membership* buffer, uint32_t playercount);
	/* 26 */ virtual bool __fastcall Member26();
	/* 27 */ virtual bool __fastcall Member27();
	/* 28 */ virtual bool __fastcall UpdateGraphics(Member28Struct* buffer);
	/* 29 */ virtual __int64 __fastcall UpdatePlayerConfiguration(wchar_t playerNames[4][32], s_player_configuration& rMember29);
	/* 30 */ virtual bool __fastcall __fastcall UpdateInput(_QWORD, InputBuffer* pInputBuffer);
	/* 31 */ virtual void Member31(_QWORD, float *);
	/* 32 */ virtual void Member32();
	/* 33 */ virtual void XInputSetState(DWORD dwUserIndex, XINPUT_VIBRATION *pVibration);
	/* 34 */ virtual bool __fastcall __fastcall UpdatePlayerNames(__int64 *, wchar_t playerNames[4][32], size_t dataSize);
	/* 35 */ virtual void __fastcall Member35(const wchar_t *, const wchar_t *);
	/* 36 */ virtual bool __fastcall Member36(wchar_t *, __int64);
	/* 37 */ virtual __int64 __fastcall NetworkSendTo(NetworkID networkID, char *buffer, uint32_t buffersize, int a5);
	/* 38 */ virtual __int64 __fastcall NetworkReceiveFrom(char *buffer, uint32_t buffersize, __int64 a4, s_transport_address *transport_address);
	/* 39 */ virtual char *__fastcall Member39(unsigned int);
	/* 40 */ virtual int __fastcall Member40(BYTE *buffer);
	/* 41 */ virtual bool __fastcall Member41(signed int, __int64, __int64);
	/* 42 */ virtual void __fastcall FirefightNew(__int64, float);
	/* 43 */ virtual BOOL __fastcall Member43(__int64, __int64);
	/* 44 */ virtual bool __fastcall GetPathByType(int type, LPSTR buf, size_t len);
	/* 45 */ virtual bool __fastcall GetWidePathByType(int type, LPWSTR wbuf, size_t len);
	/* 46 */ virtual unsigned __int8* __fastcall Member46(_QWORD, unsigned __int8*, _QWORD);
	/* 47 */ virtual __int64 __fastcall Member47(_QWORD, __int64);

	// DATA
	IGameEvents* pGameEvents = nullptr;
	QWORD data1[5863] = {};
};
//static constexpr size_t IGameEngineHostSize = sizeof(IGameEngineHost);
//static_assert(IGameEngineHostSize == 0xB748, "IGameEngineHost is incorrect");
