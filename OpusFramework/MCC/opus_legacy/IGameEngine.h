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





static constexpr size_t k_game_variant_buffer_size = 0x1CC00;
static constexpr size_t k_map_variant_buffer_size = 0xE800;

struct s_peer_context
{
	long long secure_address;
};

struct s_player_context_v1
{
	long long xbox_user_id;
	long team;
	long player_assigned_team;
	long long secure_address;
};

struct s_player_context_v2 :
	public s_player_context_v1
{
	long __unknown18;
	long __unknown1C;
};

template<typename s_player_context>
class c_game_context
{
public:
	long game_mode;

	char game_variant_buffer[k_game_variant_buffer_size];
	char map_variant_buffer[k_map_variant_buffer_size];

	long map_id;

	long campaign_difficulty_level;
	unsigned short campaign_insertion_point;
private:
	char __padding0[10];
public:
	unsigned long long active_game_skull_flags;
private:
	char __padding1[8];
public:
	void* game_state_header_ptr;
	size_t game_state_header_size;

	const char* saved_film_path_ptr;

	s_peer_context party;
	s_peer_context local;

	bool is_host;
	bool is_legacy_mode;
	bool is_legacy_sounds;
private:
	char __padding2[5];
public:
	s_peer_context peers[17];
	size_t peer_count;

	s_player_context players[16];
	size_t player_count;

	s_peer_context host;

private:
	char __padding3[8];
public:
	const wchar_t* custom_engine_name;
private:
	char __padding4[176];
};

using c_game_context_v1 = c_game_context<s_player_context_v1>;
static constexpr size_t k_game_context_v1_size = sizeof(c_game_context_v1);
static_assert(k_game_context_v1_size == 0x2B738, "c_game_context_v1 invalid size");
using c_game_context_v2 = c_game_context<s_player_context_v2>;
static constexpr size_t k_game_context_v2_size = sizeof(c_game_context_v2);
static_assert(k_game_context_v2_size == 0x2B7B8, "c_game_context_v2 invalid size");

struct c_game_context_v3
{
public:
	bool is_legacy_mode;
	bool is_legacy_sounds;
private:
	char __padding0;
public:
	bool is_host;
private:
	char __padding1[8];
public:
	long game_mode;
	long map_id;

	long campaign_difficulty_level;
	unsigned short campaign_insertion_point;
private:
	char __padding2[6];
public:
	unsigned long long active_game_skull_flags;

	s_peer_context party;
	s_peer_context local;

	s_peer_context peers[17];
	size_t peer_count;

	s_player_context_v2 players[16];
	size_t player_count;
	s_peer_context host;

	char game_variant_buffer[k_game_variant_buffer_size];
	char map_variant_buffer[k_map_variant_buffer_size];

	size_t game_state_header_size;
	void* game_state_header_ptr;
	const char* saved_film_path_ptr;
	const wchar_t* custom_engine_name;
};

static constexpr size_t k_game_context_v3_size = sizeof(c_game_context_v3);
static_assert(k_game_context_v3_size == 0x2B6F8, "c_game_context_v3 invalid size");

class GameContext
{
private:
	union
	{
		c_game_context_v1 game_context_v1;
		c_game_context_v2 game_context_v2;
		c_game_context_v3 game_context_v3;
	};
public:
	e_game_context_version const game_context_version;

	bool& is_legacy_mode;
	bool& is_legacy_sounds;
	bool& is_host;
	long& game_mode;
	long& map_id;
	long& campaign_difficulty_level;
	unsigned short& campaign_insertion_point;
	unsigned long long& active_game_skull_flags;
	s_peer_context& party;
	s_peer_context& local;
	s_peer_context (&peers)[17];
	size_t& peer_count;
	//s_player_context_v1 players[16];
	//s_player_context_v2 players[16];
	size_t& player_count;
	s_peer_context& host;
	char(&game_variant_buffer)[k_game_variant_buffer_size];
	char(&map_variant_buffer)[k_map_variant_buffer_size];
	size_t& game_state_header_size;
	void*& game_state_header_ptr;
	const char*& saved_film_path_ptr;
	const wchar_t*& custom_engine_name;

private:

#define reference_getter(field_name) \
	decltype(&field_name) get_##field_name() \
	{ \
		switch (game_context_version) \
		{ \
		case _game_context_version_1: return &game_context_v1.field_name; \
		case _game_context_version_2: return &game_context_v2.field_name; \
		case _game_context_version_3: return &game_context_v3.field_name; \
		} \
		return nullptr; \
	}

	reference_getter(is_legacy_mode);
	reference_getter(is_legacy_sounds);
	reference_getter(is_host);
	reference_getter(game_mode);
	reference_getter(map_id);
	reference_getter(campaign_difficulty_level);
	reference_getter(campaign_insertion_point);
	reference_getter(active_game_skull_flags);
	reference_getter(party);
	reference_getter(local);
	reference_getter(peers);
	reference_getter(peer_count);
	//reference_getter(players);
	reference_getter(player_count);
	reference_getter(host);
	reference_getter(game_variant_buffer);
	reference_getter(map_variant_buffer);
	reference_getter(game_state_header_size);
	reference_getter(game_state_header_ptr);
	reference_getter(saved_film_path_ptr);
	reference_getter(custom_engine_name);

#undef reference_getter

	class c_virtual_game_context_players_interface
	{
	public:
		c_virtual_game_context_players_interface(GameContext& parent) :
			parent(parent)
		{ }

		GameContext& parent;

		s_player_context_v1& operator[](size_t player_index) const
		{
			switch (parent.game_context_version)
			{
			case _game_context_version_1: return parent.game_context_v1.players[player_index];
			case _game_context_version_2: return parent.game_context_v2.players[player_index];
			case _game_context_version_3: return parent.game_context_v3.players[player_index];
			}
			throw;
		}
	};
	c_virtual_game_context_players_interface players;

public:

	GameContext(e_game_context_version game_context_version) :
		game_context_v1(),
		//game_context_v2(),
		//game_context_v3(),
		game_context_version(game_context_version),
		is_legacy_mode(*get_is_legacy_mode()),
		is_legacy_sounds(*get_is_legacy_sounds()),
		is_host(*get_is_host()),
		game_mode(*get_game_mode()),
		map_id(*get_map_id()),
		campaign_difficulty_level(*get_campaign_difficulty_level()),
		campaign_insertion_point(*get_campaign_insertion_point()),
		active_game_skull_flags(*get_active_game_skull_flags()),
		party(*get_party()),
		local(*get_local()),
		peers(*get_peers()),
		peer_count(*get_peer_count()),
		players(*this),
		player_count(*get_player_count()),
		host(*get_host()),
		game_variant_buffer(*get_game_variant_buffer()),
		map_variant_buffer(*get_map_variant_buffer()),
		game_state_header_size(*get_game_state_header_size()),
		game_state_header_ptr(*get_game_state_header_ptr()),
		saved_film_path_ptr(*get_saved_film_path_ptr()),
		custom_engine_name(*get_custom_engine_name())
	{
		memset(&game_context_v1, 0, sizeof(game_context_v1));
		memset(&game_context_v2, 0, sizeof(game_context_v2));
		memset(&game_context_v3, 0, sizeof(game_context_v3));
	}
};

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
static_assert_64(IGameEngineBaseSize == 0x8, "IGameEngineBase is incorrect size");

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
static_assert_64(IGameEngineSize == 0x460, "IGameEngineHaloReach is incorrect size");
static constexpr size_t unknown8Offset = offsetof(IGameEngineHaloReach, IGameEngineHaloReach::unknown8);
static_assert_64(unknown8Offset == 0x8, "unknown8 is incorrect offset");
static constexpr size_t header430Offset = offsetof(IGameEngineHaloReach, IGameEngineHaloReach::header430);
static_assert_64(header430Offset == 0x430, "header430 is incorrect offset");
static constexpr size_t header440Offset = offsetof(IGameEngineHaloReach, IGameEngineHaloReach::header440);
static_assert_64(header440Offset == 0x440, "header440 is incorrect offset");
