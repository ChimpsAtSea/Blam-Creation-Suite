#pragma once

enum e_map_id : int;
enum e_campaign_difficulty_level : int;

typedef uint64_t PeerUUID;
#pragma pack(push, 1)
struct PlayerUUID
{
	QWORD qword0;
	DWORD dword8;
	uint8_t unknownC[12];
};
#pragma pack(pop)
static_assert(sizeof(PlayerUUID) == 24, "");

struct s_party_data
{
	PeerUUID SquadId;
	PeerUUID LocalId;
	bool IsHost; // if client, is false
	__declspec(align(8)) struct
	{
		PeerUUID PeerIds[17];
		uint32_t PeerCount; // if client, is 0
	};
	__declspec(align(8)) struct
	{
		PlayerUUID PlayerIds[16];
		int64_t PlayerCount; // if client, is 0
	};
	PeerUUID HostId; // if client, is LocalId
};
static constexpr size_t PartyData_HostId_Offset = offsetof(s_party_data, s_party_data::HostId);
static_assert(PartyData_HostId_Offset == 0x230);
static constexpr size_t PartyDataSize = sizeof(s_party_data);
static_assert(PartyDataSize == 0x238);



#pragma pack(push, 1)
struct s_game_launch_data
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
	s_party_data PartyData;
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
static constexpr size_t s_game_launch_data_size = sizeof(s_game_launch_data);
static_assert(s_game_launch_data_size == 0x2B7C8, "");
static_assert(offsetof(s_game_launch_data, s_game_launch_data::pGameHandle) == 0x2B740, "");

class IGameEngine
{
public:
	virtual __int64 __fastcall InitGraphics(ID3D11Device*, ID3D11DeviceContext*, IDXGISwapChain*, IDXGISwapChain*) = 0;
	virtual HANDLE __fastcall InitThread(class IGameEngineHost*, s_game_launch_data*) = 0;
	virtual __int64 __fastcall Member02(int, _QWORD*) = 0;
	virtual __int64 __fastcall Destructor() = 0;
	virtual void __fastcall Member04() = 0;
	virtual void __fastcall Member05() = 0;
	virtual void __fastcall Member06() = 0;
	virtual void __fastcall Member07() = 0;
	virtual void __fastcall Member08() = 0;
	virtual __int64 __fastcall Member09(const char*) = 0;
	virtual __int64 __fastcall Member10() = 0;

	DWORD unknown0;
	float unknown1;
	char unknown2[454];
};

