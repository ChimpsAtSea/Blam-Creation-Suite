#pragma once

class HaloReachGameOptionSelection
{
public:
	static void Init();
	static void Deinit();
	static e_game_mode GetSelectedGameMode();
	static const MapInfo* GetSelectedMapInfo();
	static void SelectGameMode();
	static void Render();

	static void LoadMapVariant(IDataAccess *pDataAccess, const char *pVariantName, s_map_variant &out_variant, bool print = false);
	static void LoadGameVariant(IDataAccess *pDataAccess, const char *pVariantName, s_game_variant &out_variant, bool print = false);
	static void LoadPreviousGamestate(const char *pFileName, GameContext &gameContext);
	static void LoadSavedFilmMetadata(const char *pSavedFilmName, GameContext &gameContext);

	static std::string s_pLaunchGameVariant;
	static std::string s_pLaunchMapVariant;
	static std::string s_pLaunchSavedFilm;
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


	/* LEGACY */ static void GetVariantInfo(char* pBuffer, std::string* name, std::string* desc);
	/* LEGACY */ static int ReadGameVariant(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath);
	/* LEGACY */ static int ReadSavedFilm(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath);
	/* LEGACY */ static int ReadMapVariant(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath);

	static bool isMapInfoCompatibleWithGameMode(e_game_mode gameMode, const MapInfo& rMapInfo);
	static const MapInfo*& GetSelectedMapInfoByGameMode(e_game_mode gameMode);
	static const MapInfo* GetFirstSuitableGameModeMapInfo(e_game_mode gameMode);
	static void SaveSelectedMap(e_game_mode gameMode, const MapInfo* pMapInfo);
	static SelectedGameModeMapInfoIndex GameModeToSelectedGameModeMapInfoIndex(e_game_mode gameMode);
	static e_game_mode SelectedGameModeMapInfoIndexToGameMode(SelectedGameModeMapInfoIndex selectedGameModeMapInfoIndex);
	static const MapInfo*& GetSelectedMapInfoBySelectedGameModeMapInfoIndex(SelectedGameModeMapInfoIndex selectedGameModeMapInfoIndex);

	static void RenderHoveredTooltip(const char* pText);

	static MapInfoManager* s_pMapInfoManager;
	static const MapInfo* s_pSelectedMapInfo[underlying_cast(SelectedGameModeMapInfoIndex::Count)];
	static constexpr const char* s_kpMapInfoSettingsName[underlying_cast(SelectedGameModeMapInfoIndex::Count)] = { "LastCampaignMap", "LastMultiplayerMap", "LastSurvivalMap", "LastUnknownGamemodeMap" };

	static GameTypeManager* s_pGameTypeManager;
	static const GameType* s_pSelectedGameType[underlying_cast(SelectedGameModeMapInfoIndex::Count)];
};