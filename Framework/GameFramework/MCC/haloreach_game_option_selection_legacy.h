#pragma once

enum e_selected_game_mode_map_info_index
{
	_selected_game_mode_map_info_index_campaign,
	_selected_game_mode_map_info_index_multiplayer,
	_selected_game_mode_map_info_index_firefight,
	_selected_game_mode_map_info_index_unknown,
	k_number_of_selected_game_mode_map_info_indices
};

class c_haloreach_game_option_selection_legacy
{
public:
	static void Init();
	static void deinit();
	static e_mcc_game_mode get_selected_game_mode();
	static const c_map_info* get_selected_map_info();
	static void select_game_mode();
	static void Render();

	static void load_map_variant(IDataAccess* data_access, const char* engine_name, const char* variant_name, s_map_variant& out_variant, bool print = false);
	static void load_game_variant(IDataAccess* data_access, const char* engine_name, const char* variant_name, s_game_variant& out_variant, bool print = false);
	static void load_savegame(const char* filepath, GameOptions& options);
	static void load_saved_film(const char* saved_film_name, GameOptions& options);

	static std::string s_launch_game_variant;
	static std::string s_launch_map_variant;
	static std::string s_launch_saved_film_filepath;
public:

	static void loadSettings();
	static const c_map_info* GetDefaultHaloReachGameOptionSelection(e_selected_game_mode_map_info_index game_mode_map_info_index);
	static const c_map_info* GetDefaultMapSelection(e_selected_game_mode_map_info_index game_mode_map_info_index);
	static void select_map();
	static void select_difficulty();
	static void select_game_variant();
	static void select_map_variant();
	static void select_saved_film();


	/* LEGACY */ static void GetVariantInfo(char* buffer, std::string* name, std::string* desc);
	/* LEGACY */ static int read_game_variant(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath);
	/* LEGACY */ static int ReadSavedFilm(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath);
	/* LEGACY */ static int ReadMapVariant(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath);

	static bool is_map_info_compatible_with_game_mode(e_mcc_game_mode game_mode, const c_map_info& rMapInfo);
	static const c_map_info*& get_selected_map_info_by_game_mode(e_mcc_game_mode game_mode);
	static const c_map_info* get_first_suitable_game_modeMapInfo(e_mcc_game_mode game_mode);
	static void save_selected_map(e_mcc_game_mode game_mode, const c_map_info* pMapInfo);
	static e_selected_game_mode_map_info_index game_mode_to_selected_game_mode_map_info_index(e_mcc_game_mode game_mode);
	static e_mcc_game_mode selected_game_mode_map_info_index_to_game_mode(e_selected_game_mode_map_info_index selected_game_mode_map_info_index);
	static const c_map_info*& get_selected_map_info_by_selected_game_mode_map_info_index(e_selected_game_mode_map_info_index selected_game_mode_map_info_index);

	static void render_hovered_tooltip(const char* pText);

	static c_map_info_manager* g_map_info_manager;
	static const c_map_info* g_selected_map_info[underlying_cast(k_number_of_selected_game_mode_map_info_indices)];
	static constexpr const char* s_kpMapInfoSettingsName[underlying_cast(k_number_of_selected_game_mode_map_info_indices)] = { "LastCampaignMap", "LastMultiplayerMap", "LastSurvivalMap", "LastUnknowngame_modeMap" };

	//static GameTypeManager* g_game_type_manager;
	//static const GameType* selected_game_type[underlying_cast(k_number_of_selected_game_mode_map_info_indices)];
};