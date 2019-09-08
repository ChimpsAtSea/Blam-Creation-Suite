#pragma once

enum e_map_id : int;
enum e_campaign_difficulty_level : int;

struct s_member_info
{
	QWORD MachineIdentifier;
	long Team;
	long PlayerAssignedTeam;
	_QWORD SecureAddress;
};

struct s_session_membership
{
	s_member_info Members[16];
	int Count;
	int : 32;
};
static constexpr size_t s_session_membership_size = sizeof(s_session_membership);
static_assert(s_session_membership_size == 0x188, "s_session_membership is incorrect size");

struct s_session_info_part
{
	QWORD SquadAddress; // c_managed_session offset 0x3E0
	QWORD SecureAddress; // s_network_session_peer offset 0, type s_transport_secure_address
	s_session_membership SessionMembership;
};
static constexpr size_t s_session_info_part_size = sizeof(s_session_info_part);
static_assert(s_session_info_part_size == 0x198, "s_session_info_part is incorrect size");

struct s_session_info
{
	QWORD SquadAddress;
	QWORD LocalMachineID;
	bool IsHost; // if client, is false
	__declspec(align(8)) struct
	{
		QWORD PeerIdentifiers[17];
		uint32_t PeerIdentifierCount; // if client, is 0
	};
	s_session_membership SessionMembership;
	QWORD HostAddress; // if client, is LocalId
};
static constexpr size_t SessionInfo_HostAddress_Offset = offsetof(s_session_info, s_session_info::HostAddress);
static_assert(SessionInfo_HostAddress_Offset == 0x230);
static constexpr size_t SessionInfoSize = sizeof(s_session_info);
static_assert(SessionInfoSize == 0x238);



#pragma pack(push, 1)
struct GameContext
{
	int32_t GameMode;
	uint8_t GameVariantBuffer[115 * 1024] = {};
	uint8_t MapVariantBuffer[58 * 1024] = {};
	// [180330500, mcc_id_to_reach_map_id,   https://pastebin.com/r3ihQagj]
	// [180330BD0, mcc_id_to_reach_map_name, https://pastebin.com/Qx72e0G6]
	e_map_id MapId;
	e_campaign_difficulty_level CampaignDifficultyLevel;
	int16_t CampaignInsertionPoint;
	uint16_t __padding1 : 16;
	uint64_t __padding2 : 64;
	int8_t GameSkullFlags[16];
	uint8_t* pGameStateHeader;
	size_t GameStateHeaderSize;
	const char* SavedFilmPath;
	s_session_info SessionInfo;
	uint8_t byte2B678[8];
	const wchar_t* GamePath = nullptr;
	wchar_t Locale[88] = L"en-US";
	uint32_t dword2B738 = 1;
	uint32_t dword2B73C = 1;
	HMODULE pGameHandle = 0;
	uint32_t EngineIndex0 = 6;
	uint32_t EngineIndex1 = 6;
	uint8_t unknownStruct2B750[48] = {}; // changes
	uint64_t qword2B780 = 0;
	uint64_t qword2B788 = 0;
	struct RallyPointLoader* pRallyPointLoader = nullptr; // changes // WARNING: this is needed for MCC to run don't overwrite
	uint32_t dword2B798 = 11;
	uint32_t dword2B79C = 0;
	uint64_t qword2B7A0 = 0; // changes
	uint64_t qword2B7A8 = 0;
	uint8_t byte2B7B0 = 0;
	uint8_t byte2B7B1 = 0;
	uint16_t word2B7B2 = 0;
	uint16_t word2B7B4 = 0;
	uint16_t word2B7B6 = 0;
	uint64_t qword2B7B8 = 0; // changes
	uint32_t dword2B7C0 = 0;
	uint32_t dword2B7C4 = 0;
};
#pragma pack(pop)
static constexpr size_t GameContext_size = sizeof(GameContext);
static_assert(GameContext_size == 0x2B7C8, "");
static_assert(offsetof(GameContext, GameContext::pGameHandle) == 0x2B740, "");

//// for some reason MSVC doesn't respect the correct size of alignment of this structure
//// this is supposed to be a SLIST_HEADER
//struct SLIST_HEADER_Explicit 
//{
//public:
//	SLIST_HEADER& Get() { return *reinterpret_cast<SLIST_HEADER*>(data); }
//private:
//	uint64_t data[2];
//};
//static_assert(sizeof(SLIST_HEADER_Explicit) == sizeof(SLIST_HEADER), "SLIST_HEADER_Explicit should match size of SLIST_HEADER");

class IGameEngine2
{
public:
	virtual __int64 __fastcall InitGraphics(ID3D11Device*, ID3D11DeviceContext*, IDXGISwapChain*, IDXGISwapChain*) = 0;
	virtual HANDLE __fastcall InitThread(class IGameEngineHost*, GameContext*) = 0;
	virtual __int64 __fastcall Member02(int, _QWORD*) = 0;
	virtual __int64 __fastcall Destructor() = 0;
	virtual void __fastcall Member04() = 0;
	virtual void __fastcall Member05() = 0;
	virtual void __fastcall Member06() = 0;
	virtual void __fastcall Member07() = 0;
	virtual void __fastcall Member08() = 0;
	virtual __int64 __fastcall Member09(const char*) = 0;
	virtual __int64 __fastcall Member10() = 0;

	DWORD unknown8;
	float unknownC;
	char unknown10[1056];
	SLIST_HEADER header430;
	SLIST_HEADER header440;
};

class IGameEngine
{
public:
	__forceinline __int64 __fastcall InitGraphics(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, IDXGISwapChain* pSwapchain, IDXGISwapChain* pFallbackSwapchain) 
	{ 
		return impl.__vftable->InitGraphics(this, pDevice, pDeviceContext, pSwapchain, pFallbackSwapchain);
	}
	HANDLE __fastcall InitThread(class IGameEngineHost* pGameEngineHost, s_game_launch_data* pGameLaunchData)
	{
		return impl.__vftable->InitThread(this, pGameEngineHost, pGameLaunchData);
	}
	__int64 __fastcall Member02(int a1, _QWORD* a2)
	{
		return impl.__vftable->Member02(this, a1, a2);
	}
	__int64 __fastcall Destructor()
	{
		return impl.__vftable->Destructor(this);
	}
	void __fastcall Member04()
	{
		return impl.__vftable->Member04(this);
	}
	void __fastcall Member05()
	{
		return impl.__vftable->Member05(this);
	}
	void __fastcall Member06()
	{
		return impl.__vftable->Member06(this);
	}
	void __fastcall Member07()
	{
		return impl.__vftable->Member07(this);
	}
	void __fastcall Member08()
	{
		return impl.__vftable->Member08(this);
	}
	__int64 __fastcall Member09(const char* a1)
	{
		return impl.__vftable->Member09(this, a1);
	}
	__int64 __fastcall Member10()
	{
		return impl.__vftable->Member10(this);
	}

private:
	//pHaloReachEngine->Member02(0, 0); // pause
	//pHaloReachEngine->Member02(1, 0); // unpause
	//pHaloReachEngine->Member02(2, 0); // exit (immediate)
	//pHaloReachEngine->Member02(3, 0); // restart
	//pHaloReachEngine->Member02(4, 0); // restart
	//pHaloReachEngine->Member02(5, 0); // reload controls
	//pHaloReachEngine->Member02(6, 0); // crash...
	//pHaloReachEngine->Member02(7, 0); // unknown
	//pHaloReachEngine->Member02(8, 0); // unknown
	//pHaloReachEngine->Member02(9, 0); // unknown
	//pHaloReachEngine->Member02(10, 0); // unknown
	//pHaloReachEngine->Member02(11, 0); // unknown
	//pHaloReachEngine->Member02(12, 0); // restart round?
	//pHaloReachEngine->Member02(13, 0); // unknown
	//pHaloReachEngine->Member02(14, 0); // unknown, potentially audio related. causes member 40 to run a lot of times. also causes massive memory spike!
	//pHaloReachEngine->Member02(15, 0);
	//pHaloReachEngine->Member02(16, (uint64*)200); // unknown this takes some argument
	// Member09 looks same as Member02 but takes a string argument that is copied with strdup

	struct /*VFT*/ IGameEngine_vtbl
	{
		__int64(__fastcall* InitGraphics)(IGameEngine*, struct ID3D11Device*, struct ID3D11DeviceContext*, struct IDXGISwapChain*, struct IDXGISwapChain*);
		HANDLE(__fastcall* InitThread)(IGameEngine*, IGameEngineHost*, s_game_launch_data*);
		__int64(__fastcall* Member02)(IGameEngine*, int, _QWORD*);
		__int64(__fastcall* Destructor)(IGameEngine*);
		void(__fastcall* Member04)(IGameEngine*);
		void(__fastcall* Member05)(IGameEngine*);
		void(__fastcall* Member06)(IGameEngine*);
		void(__fastcall* Member07)(IGameEngine*);
		void(__fastcall* Member08)(IGameEngine*);
		__int64(__fastcall* Member09)(IGameEngine*, const char*);
		__int64(__fastcall* Member10)(IGameEngine*);
	};

	struct IGameEngineData
	{
		IGameEngine_vtbl* __vftable /*VFT*/;
		DWORD unknown8;
		float unknownC;
		char unknown10[1056];
		SLIST_HEADER header430;
		SLIST_HEADER header440;
		char unknown450[16];
	};
	static constexpr size_t unknown8Offset = offsetof(IGameEngineData, IGameEngineData::unknown8);
	static_assert(unknown8Offset == 0x8, "unknown8 is incorrect offset");
	static constexpr size_t header430Offset = offsetof(IGameEngineData, IGameEngineData::header430);
	static_assert(header430Offset == 0x430, "header430 is incorrect offset");
	static constexpr size_t header440Offset = offsetof(IGameEngineData, IGameEngineData::header440);
	static_assert(header440Offset == 0x440, "header440 is incorrect offset");
	static constexpr size_t IGameEngineDataSize = sizeof(IGameEngineData);
	static_assert(IGameEngineDataSize == 0x460, "IGameEngineData is incorrect size");

	IGameEngineData impl;
};

static constexpr size_t IGameEngineSize = sizeof(IGameEngine);
static_assert(IGameEngineSize == 0x460, "IGameEngine is incorrect size");
