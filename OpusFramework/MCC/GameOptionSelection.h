#pragma once

class GameOptionSelection
{
public:
	static void Init();
	static void Deinit();
	static GameMode GetSelectedGameMode();
	static const MapInfo* GetSelectedMapInfo();
	static IDataAccess* GetDataAccess();
	static void SelectGameMode();
	static void Render();

	static void LoadMapVariant(IDataAccess *pDataAccess, const char *pVariantName, s_map_variant &out_variant, bool print = false);
	static void LoadGameVariant(IDataAccess *pDataAccess, const char *pVariantName, s_game_variant &out_variant, bool print = false);
	static void LoadPreviousGamestate(const char *pFileName, GameContext &gameContext);
	static void LoadSavedFilmMetadata(const char *pSavedFilmName, GameContext &gameContext);

	static std::string m_pLaunchGameVariant;
	static std::string m_pLaunchMapVariant;
	static std::string m_pLaunchSavedFilm;
private:

	enum class SelectedGameModeMapInfoIndex
	{
		Campaign,
		Multiplayer,
		Firefight,
		Unknown,
		Count
	};

	static const MapInfo* GetDefaultGameOptionSelection(SelectedGameModeMapInfoIndex gameModeMapInfoIndex);
	static void SelectMap();
	static void SelectDifficulty();
	static void SelectGameVariant();
	static void SelectMapVariant();
	static void SelectSavedFilm();


	/* LEGACY */ static void GetVariantInfo(char* pBuffer, std::string* name, std::string* desc);
	/* LEGACY */ static int ReadGameVariant(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath);
	/* LEGACY */ static int ReadSavedFilm(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath);
	/* LEGACY */ static int ReadMapVariant(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath);

	static bool isMapInfoCompatibleWithGameMode(GameMode gameMode, const MapInfo& rMapInfo);
	static const MapInfo*& GetSelectedMapInfoByGameMode(GameMode gameMode);
	static const MapInfo* GetFirstSuitableGameModeMapInfo(GameMode gameMode);
	static void SaveSelectedMap(GameMode gameMode, const MapInfo* pMapInfo);
	static SelectedGameModeMapInfoIndex GameModeToSelectedGameModeMapInfoIndex(GameMode gameMode);
	static GameMode SelectedGameModeMapInfoIndexToGameMode(SelectedGameModeMapInfoIndex selectedGameModeMapInfoIndex);
	static const MapInfo*& GetSelectedMapInfoBySelectedGameModeMapInfoIndex(SelectedGameModeMapInfoIndex selectedGameModeMapInfoIndex);

	static void RenderHoveredTooltip(const char* pText);

	static MapInfoManager* s_pMapInfoManager;
	static const MapInfo* s_pSelectedMapInfo[underlying_cast(SelectedGameModeMapInfoIndex::Count)];
	static constexpr const char* s_kpMapInfoSettingsName[underlying_cast(SelectedGameModeMapInfoIndex::Count)] = { "LastCampaignMap", "LastMultiplayerMap", "LastSurvivalMap", "LastUnknownGamemodeMap" };
};