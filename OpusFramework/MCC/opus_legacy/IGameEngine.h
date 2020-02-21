#pragma once

struct s_member_info
{
	QWORD MachineIdentifier;
	long Team;
	long PlayerAssignedTeam;
	_QWORD SecureAddress;
	_QWORD unknown;
};
static constexpr size_t s_member_info_size = sizeof(s_member_info);
static_assert(s_member_info_size == 0x20, "s_member_info is incorrect size");

struct s_session_membership
{
	s_member_info Members[16];
	int Count;
	int : 32;
};
static constexpr size_t s_session_membership_size = sizeof(s_session_membership);
static_assert(s_session_membership_size == 0x208, "s_session_membership is incorrect size");

struct s_session_info_part
{
	QWORD SquadAddress; // c_managed_session offset 0x3E0
	QWORD SecureAddress; // s_network_session_peer offset 0, type s_transport_secure_address
	s_session_membership SessionMembership;
};
static constexpr size_t s_session_info_part_size = sizeof(s_session_info_part);
static_assert(s_session_info_part_size == 0x218, "s_session_info_part is incorrect size");

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
//static constexpr size_t SessionInfo_HostAddress_Offset = offsetof(s_session_info, s_session_info::HostAddress);
//static_assert(SessionInfo_HostAddress_Offset == 0x230);
static constexpr size_t SessionInfoSize = sizeof(s_session_info);
static_assert(SessionInfoSize == 0x2B8);

#pragma pack(push, 1)
struct GameContext
{
	//char shit[32];
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
	char* pGameStateHeader;
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
static constexpr size_t byte2B678_Offset = offsetof(GameContext, GameContext::byte2B678);
static_assert(byte2B678_Offset + 32 == 177944);

static constexpr size_t SessionInfo_Offset = offsetof(GameContext, GameContext::SessionInfo.HostAddress);
static_assert(SessionInfo_Offset == 0x2B6F0);

enum class eEngineState : int
{
	Pause,
	Unpause,

	ImmediateExit,
	RevertToLastSave,
	RestartLevel,

	ReloadSettings,

	// 6 and 7 are connected
	GameLoadStart, // sets a temp variable to `g_render_thread_mode` and sets `g_render_thread_mode` to `0`, sets `g_game_is_loading` to `true` and runs `UpdateGameStatus(RevertToLastSave)`
	GameLoadEnd, // sets `g_render_thread_mode` to the temp variable and sets the temp variable to `0`, sets `g_game_is_loading` to `false` and runs `UpdateGameStatus(RestartLevel)`

	// 8 and 9 are connected
	PushUIPage, // allocates `c_controller_input_message` (loadout selection is shown) and sets a temp variable to `true`
	PopUIPage, // sets the temp variable to `false` and player spawns

	UpdateGameVariant, // creates a new `IGameVariant` and passes it to `IGameEngineHostLegacy::UpdateGameVariant`
	UpdateMapVariant, // creates a new `IMapVariant` and passes it to `IGameEngineHostLegacy::UpdateMapVariant`

	EndRound, // not confirmed
	EndGame, // not confirmed

	ReloadRenderer, // potentially enhanced graphics. causes member 42 to run, also causes memory spike!

	Unknown15, // unknown
	Unknown16, // unknown this takes some extra argument provided to UpdateEngineState
};
extern const char* engine_state_to_string(eEngineState engineState);


class IGameEngine
{
public: // instance functions

	virtual __forceinline __int64 __fastcall InitGraphics(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, IDXGISwapChain* pSwapchain, IDXGISwapChain* pFallbackSwapchain) = 0;
	virtual HANDLE __fastcall InitThread(class IGameEngineHost* pGameEngineHost, GameContext* pGameContext) = 0;
	virtual __int64 __fastcall UpdateEngineState(eEngineState status, _QWORD* extraArgument = nullptr) = 0;
	virtual __int64 __fastcall Destructor() = 0;
	virtual void __fastcall Member04() = 0;
	virtual void __fastcall Member05() = 0;
	virtual void __fastcall Member06() = 0;
	virtual void __fastcall Member07() = 0;
	virtual void __fastcall Member08() = 0;
	virtual __int64 __fastcall Member09(const char* a1) = 0; // Member09 looks same as UpdateEngineState but takes a string argument that is copied with strdup
	virtual __int64 __fastcall Member10() = 0;
};
static constexpr size_t IGameEngineBaseSize = sizeof(IGameEngine);
static_assert(IGameEngineBaseSize == 0x8, "IGameEngineBase is incorrect size");

class IGameEngineHaloReach : public IGameEngine
{
public:
	DWORD unknown8;
	float GameSpeed;
	char unknown10[1056];
	SLIST_HEADER header430;
	SLIST_HEADER header440;
	char unknown450[16];
};
static constexpr size_t IGameEngineSize = sizeof(IGameEngineHaloReach);
static_assert(IGameEngineSize == 0x460, "IGameEngineHaloReach is incorrect size");
static constexpr size_t unknown8Offset = offsetof(IGameEngineHaloReach, IGameEngineHaloReach::unknown8);
static_assert(unknown8Offset == 0x8, "unknown8 is incorrect offset");
static constexpr size_t header430Offset = offsetof(IGameEngineHaloReach, IGameEngineHaloReach::header430);
static_assert(header430Offset == 0x430, "header430 is incorrect offset");
static constexpr size_t header440Offset = offsetof(IGameEngineHaloReach, IGameEngineHaloReach::header440);
static_assert(header440Offset == 0x440, "header440 is incorrect offset");
