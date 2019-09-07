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

class IGameEngine
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

	DWORD unknown0;
	float unknown1;
	char unknown2[454];
};

