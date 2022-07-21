#pragma once

constexpr size_t k_game_variant_buffer_size = 0x1CC00;
constexpr size_t k_map_variant_buffer_size = 0xE800;

struct s_peer_context
{
	int64_t secure_address;
};

struct s_player_context_v1
{
	int64_t xbox_user_id;
	int32_t team;
	int32_t player_assigned_team;
	int64_t secure_address;
};

struct s_player_context_v2 :
	public s_player_context_v1
{
	int32_t __unknown18;
	int32_t __unknown1C;
};

template<typename s_player_context>
class c_game_options
{
public:
	int32_t game_mode;

	char game_variant_buffer[k_game_variant_buffer_size];
	char map_variant_buffer[k_map_variant_buffer_size];

	int32_t map_id;

	int32_t campaign_difficulty_level;
	unsigned short campaign_insertion_point;
	short infinity_mission_id;
private:
	char __padding0[8];
public:
	uint64_t launcher_skull_mask;
private:
	char __padding1[8];
public:
	char* game_state_header;
	uint64_t game_state_header_size;

	const char* saved_film_path;

	s_peer_context party;
	s_peer_context local;

	bool is_host;
	bool visual_remaster;
	bool music_remaster;
	bool sfx_remaster;
private:
	char __padding2[4];
public:
	s_peer_context peers[17];
	uint64_t peer_count;

	s_player_context players[16];
	uint64_t player_count;

	s_peer_context host;

private:
	char __padding3[8];
public:
	wchar_t* custom_engine_name;
private:
	char __padding4[176];
};
using s_game_options_v0 = c_game_options<s_player_context_v1>;
using s_game_options_v1 = c_game_options<s_player_context_v2>;
constexpr size_t k_game_options_v0_size = sizeof(s_game_options_v0);
constexpr size_t k_game_options_v1_size = sizeof(s_game_options_v1);
static_assert_64(k_game_options_v0_size == 0x2B738, "s_game_options_v0 invalid size");
static_assert_64(k_game_options_v1_size == 0x2B7B8, "s_game_options_v1 invalid size");

struct s_game_options_v2
{
public:
	bool visual_remaster;
	bool music_remaster;
	bool sfx_remaster;
	bool is_host;
private:
	char __padding1[8];
public:
	int32_t game_mode;
	int32_t map_id;

	int32_t campaign_difficulty_level;
private:
	char __padding2[4];
public:
	unsigned short campaign_insertion_point;
	short infinity_mission_id;
	uint64_t launcher_skull_mask;

	s_peer_context party;
	s_peer_context local;

	s_peer_context peers[17];
	uint64_t peer_count;

	s_player_context_v2 players[16];
	uint64_t player_count;
	s_peer_context host;

	char game_variant_buffer[k_game_variant_buffer_size];
	char map_variant_buffer[k_map_variant_buffer_size];

	uint64_t game_state_header_size;
	char* game_state_header;
	const char* saved_film_path;
	wchar_t* custom_engine_name;
};
constexpr size_t k_game_options_v2_size = sizeof(s_game_options_v2);
static_assert_64(k_game_options_v2_size == 0x2B6F8, "s_game_options_v2 invalid size");

struct s_game_options_v3
{
public:
	bool visual_remaster : 1;
	bool music_remaster : 1;
	bool sfx_remaster : 1;
	bool is_host : 1;

	// SUCK IT!
	unsigned char launch_flags : 4;
private:
	char __padding0[3];
	char __padding1[6];
public:
	unsigned __int8 tick_length;
private:
	__int8 : 8;
public:
	int32_t game_mode;
	int32_t map_id;

	int32_t campaign_difficulty_level;
private:
	char __padding2[4];
public:
	unsigned short campaign_insertion_point;
	short infinity_mission_id;
	uint64_t launcher_skull_mask;

	s_peer_context party;
	s_peer_context local;

	s_peer_context peers[17];
	uint64_t peer_count;

	s_player_context_v2 players[16];
	uint64_t player_count;
	s_peer_context host;

	char game_variant_buffer[k_game_variant_buffer_size];
	char map_variant_buffer[k_map_variant_buffer_size];

	uint64_t game_state_header_size;
	char* game_state_header;
	const char* saved_film_path;
	wchar_t* custom_engine_name;
};
constexpr size_t k_game_options_v3_size = sizeof(s_game_options_v3);
static_assert_64(k_game_options_v3_size == 0x2B6F8, "s_game_options_v3 invalid size");

class GameOptions
{
private:
	union
	{
		s_game_options_v0 game_options_v0;
		s_game_options_v1 game_options_v1;
		s_game_options_v2 game_options_v2;
		s_game_options_v3 game_options_v3;
	};
public:
	e_game_options_version const game_options_version;

	//bool& visual_remaster;
	//bool& music_remaster;
	//bool& sfx_remaster;
	//bool& is_host;
	unsigned __int8& tick_length;
	int32_t& game_mode;
	int32_t& map_id;
	int32_t& campaign_difficulty_level;
	unsigned short& campaign_insertion_point;
	short &infinity_mission_id;
	uint64_t& launcher_skull_mask;
	s_peer_context& party;
	s_peer_context& local;
	s_peer_context(&peers)[17];
	uint64_t& peer_count;
	//s_player_context_v1 players[16];
	//s_player_context_v2 players[16];
	uint64_t& player_count;
	s_peer_context& host;
	char(&game_variant_buffer)[k_game_variant_buffer_size];
	char(&map_variant_buffer)[k_map_variant_buffer_size];
	uint64_t& game_state_header_size;
	char*& game_state_header;
	const char*& saved_film_path;
	wchar_t*& custom_engine_name;

private:

#define game_options_reference_getter_v0(field_name) \
	decltype(&field_name) get_##field_name() \
	{ \
		switch (game_options_version) \
		{ \
		case _game_options_version_0: return &game_options_v0.field_name; \
		case _game_options_version_1: return &game_options_v1.field_name; \
		case _game_options_version_2: return &game_options_v2.field_name; \
		case _game_options_version_3: return &game_options_v3.field_name; \
		} \
		return nullptr; \
	}
#define game_options_reference_getter_v3(field_name) \
	decltype(&field_name) get_##field_name() \
	{ \
		switch (game_options_version) \
		{ \
		case _game_options_version_3: return &game_options_v3.field_name; \
		} \
		return nullptr; \
	}

	//game_options_reference_getter_v0(visual_remaster);
	//game_options_reference_getter_v0(music_remaster);
	//game_options_reference_getter_v0(sfx_remaster);
	//game_options_reference_getter_v0(is_host);
	game_options_reference_getter_v3(tick_length);
	game_options_reference_getter_v0(game_mode);
	game_options_reference_getter_v0(map_id);
	game_options_reference_getter_v0(campaign_difficulty_level);
	game_options_reference_getter_v0(campaign_insertion_point);
	game_options_reference_getter_v0(infinity_mission_id);
	game_options_reference_getter_v0(launcher_skull_mask);
	game_options_reference_getter_v0(party);
	game_options_reference_getter_v0(local);
	game_options_reference_getter_v0(peers);
	game_options_reference_getter_v0(peer_count);
	//game_options_reference_getter_v0(players);
	game_options_reference_getter_v0(player_count);
	game_options_reference_getter_v0(host);
	game_options_reference_getter_v0(game_variant_buffer);
	game_options_reference_getter_v0(map_variant_buffer);
	game_options_reference_getter_v0(game_state_header_size);
	game_options_reference_getter_v0(game_state_header);
	game_options_reference_getter_v0(saved_film_path);
	game_options_reference_getter_v0(custom_engine_name);

#undef game_options_reference_getter_v0
#undef game_options_reference_getter_v3

	class c_virtual_game_options_players_interface
	{
	public:
		c_virtual_game_options_players_interface(GameOptions& parent) :
			parent(parent)
		{ }

		GameOptions& parent;

		s_player_context_v1& operator[](size_t player_index) const
		{
			switch (parent.game_options_version)
			{
			case _game_options_version_0: return parent.game_options_v0.players[player_index];
			case _game_options_version_1: return parent.game_options_v1.players[player_index];
			case _game_options_version_2: return parent.game_options_v2.players[player_index];
			case _game_options_version_3: return parent.game_options_v3.players[player_index];
			}
			throw;
		}
	};

	class c_virtual_game_options_is_host_interface
	{
	public:
		c_virtual_game_options_is_host_interface(GameOptions& parent) :
			parent(parent)
		{ }

		GameOptions& parent;

		void operator=(bool is_host) const
		{
			switch (parent.game_options_version)
			{
			case _game_options_version_0: parent.game_options_v0.is_host = is_host; return;
			case _game_options_version_1: parent.game_options_v1.is_host = is_host; return;
			case _game_options_version_2: parent.game_options_v2.is_host = is_host; return;
			case _game_options_version_3: parent.game_options_v3.is_host = is_host; return;
			}
			throw;
		}

		// #TODO: figure out how to have `if (is_host)` as with `operator==` we can only to `if (is_host == true/false)`
		bool operator==(bool is_host) const
		{
			switch (parent.game_options_version)
			{
			case _game_options_version_0: return parent.game_options_v0.is_host == is_host;
			case _game_options_version_1: return parent.game_options_v1.is_host == is_host;
			case _game_options_version_2: return parent.game_options_v2.is_host == is_host;
			case _game_options_version_3: return parent.game_options_v3.is_host == is_host;
			}
			throw;
		}
	};

	class c_virtual_game_options_visual_remaster_interface
	{
	public:
		c_virtual_game_options_visual_remaster_interface(GameOptions& parent) :
			parent(parent)
		{ }

		GameOptions& parent;

		void operator=(bool visual_remaster) const
		{
			switch (parent.game_options_version)
			{
			case _game_options_version_0: parent.game_options_v0.visual_remaster = visual_remaster; return;
			case _game_options_version_1: parent.game_options_v1.visual_remaster = visual_remaster; return;
			case _game_options_version_2: parent.game_options_v2.visual_remaster = visual_remaster; return;
			case _game_options_version_3: parent.game_options_v3.visual_remaster = visual_remaster; return;
			}
			throw;
		}

		// #TODO: figure out how to have `if (visual_remaster)` as with `operator==` we can only to `if (visual_remaster == true/false)`
		bool operator==(bool visual_remaster) const
		{
			switch (parent.game_options_version)
			{
			case _game_options_version_0: return parent.game_options_v0.visual_remaster == visual_remaster;
			case _game_options_version_1: return parent.game_options_v1.visual_remaster == visual_remaster;
			case _game_options_version_2: return parent.game_options_v2.visual_remaster == visual_remaster;
			case _game_options_version_3: return parent.game_options_v3.visual_remaster == visual_remaster;
			}
			throw;
		}
	};

	class c_virtual_game_options_music_remaster_interface
	{
	public:
		c_virtual_game_options_music_remaster_interface(GameOptions& parent) :
			parent(parent)
		{ }

		GameOptions& parent;

		void operator=(bool music_remaster) const
		{
			switch (parent.game_options_version)
			{
			case _game_options_version_0: parent.game_options_v0.music_remaster = music_remaster; return;
			case _game_options_version_1: parent.game_options_v1.music_remaster = music_remaster; return;
			case _game_options_version_2: parent.game_options_v2.music_remaster = music_remaster; return;
			case _game_options_version_3: parent.game_options_v3.music_remaster = music_remaster; return;
			}
			throw;
		}

		// #TODO: figure out how to have `if (music_remaster)` as with `operator==` we can only to `if (music_remaster == true/false)`
		bool operator==(bool music_remaster) const
		{
			switch (parent.game_options_version)
			{
			case _game_options_version_0: return parent.game_options_v0.music_remaster == music_remaster;
			case _game_options_version_1: return parent.game_options_v1.music_remaster == music_remaster;
			case _game_options_version_2: return parent.game_options_v2.music_remaster == music_remaster;
			case _game_options_version_3: return parent.game_options_v3.music_remaster == music_remaster;
			}
			throw;
		}
	};

	class c_virtual_game_options_sfx_remaster_interface
	{
	public:
		c_virtual_game_options_sfx_remaster_interface(GameOptions& parent) :
			parent(parent)
		{ }

		GameOptions& parent;

		void operator=(bool sfx_remaster) const
		{
			switch (parent.game_options_version)
			{
			case _game_options_version_0: parent.game_options_v0.sfx_remaster = sfx_remaster; return;
			case _game_options_version_1: parent.game_options_v1.sfx_remaster = sfx_remaster; return;
			case _game_options_version_2: parent.game_options_v2.sfx_remaster = sfx_remaster; return;
			case _game_options_version_3: parent.game_options_v3.sfx_remaster = sfx_remaster; return;
			}
			throw;
		}

		// #TODO: figure out how to have `if (sfx_remaster)` as with `operator==` we can only to `if (sfx_remaster == true/false)`
		bool operator==(bool sfx_remaster) const
		{
			switch (parent.game_options_version)
			{
			case _game_options_version_0: return parent.game_options_v0.sfx_remaster == sfx_remaster;
			case _game_options_version_1: return parent.game_options_v1.sfx_remaster == sfx_remaster;
			case _game_options_version_2: return parent.game_options_v2.sfx_remaster == sfx_remaster;
			case _game_options_version_3: return parent.game_options_v3.sfx_remaster == sfx_remaster;
			}
			throw;
		}
	};

public:
	c_virtual_game_options_players_interface players;
	c_virtual_game_options_is_host_interface is_host;
	c_virtual_game_options_visual_remaster_interface visual_remaster;
	c_virtual_game_options_music_remaster_interface music_remaster;
	c_virtual_game_options_sfx_remaster_interface sfx_remaster;

	GameOptions(e_game_options_version game_options_version) :
		game_options_v0(),
		//game_options_v1(),
		//game_options_v2(),
		//game_options_v3(),
		game_options_version(game_options_version),
		visual_remaster(*this),
		music_remaster(*this),
		sfx_remaster(*this),
		is_host(*this),
		tick_length(*get_tick_length()),
		game_mode(*get_game_mode()),
		map_id(*get_map_id()),
		campaign_difficulty_level(*get_campaign_difficulty_level()),
		campaign_insertion_point(*get_campaign_insertion_point()),
		infinity_mission_id(*get_infinity_mission_id()),
		launcher_skull_mask(*get_launcher_skull_mask()),
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
		game_state_header(*get_game_state_header()),
		saved_film_path(*get_saved_film_path()),
		custom_engine_name(*get_custom_engine_name())
	{
		memset(&game_options_v0, 0, sizeof(game_options_v0));
		memset(&game_options_v1, 0, sizeof(game_options_v1));
		memset(&game_options_v2, 0, sizeof(game_options_v2));
		memset(&game_options_v3, 0, sizeof(game_options_v3));
	}
};
