#pragma once

class c_halo_reach_game_option_selection_legacy
{
public:
	static void Init();
	static void deinit();
	static e_mcc_game_mode get_selected_game_mode();
	static const MapInfo* get_selected_map_info();
	static void SelectGameMode();
	static void Render();

	static void load_map_variant(IDataAccess *pDataAccess, const char* engine_name, const char *pVariantName, s_map_variant &out_variant, bool print = false);
	static void load_game_variant(IDataAccess *pDataAccess, const char* engine_name, const char *pVariantName, s_game_variant &out_variant, bool print = false);
	static void load_savegame(const char *pFileName, GameContext &gameContext);
	static void load_savefilm(const char *pSavedFilmName, GameContext &gameContext);

	static std::string s_launch_game_variant;
	static std::string s_launch_map_variant;
	static std::string s_launch_saved_film_filepath;
public:

	enum class SelectedGameModeMapInfoIndex
	{
		Campaign,
		Multiplayer,
		Firefight,
		Unknown,
		Count
	};

	static void loadSettings();
	static const MapInfo* GetDefaultHaloReachGameOptionSelection(SelectedGameModeMapInfoIndex gameModeMapInfoIndex);
	static const MapInfo* GetDefaultMapSelection(SelectedGameModeMapInfoIndex gameModeMapInfoIndex);
	static void SelectMap();
	static void SelectDifficulty();
	static void SelectGameVariant();
	static void SelectMapVariant();
	static void SelectSavedFilm();


	/* LEGACY */ static void GetVariantInfo(char* buffer, std::string* name, std::string* desc);
	/* LEGACY */ static int ReadGameVariant(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath);
	/* LEGACY */ static int ReadSavedFilm(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath);
	/* LEGACY */ static int ReadMapVariant(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath);

	static bool isMapInfoCompatibleWithGameMode(e_mcc_game_mode gameMode, const MapInfo& rMapInfo);
	static const MapInfo*& GetSelectedMapInfoByGameMode(e_mcc_game_mode gameMode);
	static const MapInfo* GetFirstSuitableGameModeMapInfo(e_mcc_game_mode gameMode);
	static void SaveSelectedMap(e_mcc_game_mode gameMode, const MapInfo* pMapInfo);
	static SelectedGameModeMapInfoIndex GameModeToSelectedGameModeMapInfoIndex(e_mcc_game_mode gameMode);
	static e_mcc_game_mode SelectedGameModeMapInfoIndexToGameMode(SelectedGameModeMapInfoIndex selectedGameModeMapInfoIndex);
	static const MapInfo*& GetSelectedMapInfoBySelectedGameModeMapInfoIndex(SelectedGameModeMapInfoIndex selectedGameModeMapInfoIndex);

	static void RenderHoveredTooltip(const char* pText);

	static c_map_info_manager* s_pMapInfoManager;
	static const MapInfo* s_pSelectedMapInfo[underlying_cast(SelectedGameModeMapInfoIndex::Count)];
	static constexpr const char* s_kpMapInfoSettingsName[underlying_cast(SelectedGameModeMapInfoIndex::Count)] = { "LastCampaignMap", "LastMultiplayerMap", "LastSurvivalMap", "LastUnknownGamemodeMap" };

	static GameTypeManager* s_pGameTypeManager;
	static const GameType* s_pSelectedGameType[underlying_cast(SelectedGameModeMapInfoIndex::Count)];
};