#include "opusframework-private-pch.h"

std::string format_string(const char* pFormat, ...)
{
	va_list args;
	va_start(args, pFormat);
	char stringBuffer[64 * 1024] = {};
	vsnprintf(stringBuffer, _countof(stringBuffer) - 1, pFormat, args);
	va_end(args);
	return stringBuffer;
}

MapInfoManager* GameOptionSelection::s_pMapInfoManager = nullptr;
GameMode s_currentGameMode = GameMode::Campaign;
std::string GameOptionSelection::s_pLaunchGameVariant = "";
std::string GameOptionSelection::s_pLaunchMapVariant = "";
std::string GameOptionSelection::s_pLaunchSavedFilm = "";
e_campaign_difficulty_level g_LaunchCampaignDifficultyLevel = _campaign_difficulty_level_normal;
const MapInfo* GameOptionSelection::s_pSelectedMapInfo[underlying_cast(SelectedGameModeMapInfoIndex::Count)] = {};


void GameOptionSelection::Init()
{
	// #TODO: Support more games than just Halo Reach
	s_pMapInfoManager = new MapInfoManager("haloreach/maps/info");

	loadSettings();
}

void GameOptionSelection::Deinit()
{
	delete s_pMapInfoManager;
}

void GameOptionSelection::loadSettings()
{
	for (underlying(SelectedGameModeMapInfoIndex) i = 0; i < underlying_cast(SelectedGameModeMapInfoIndex::Count); i++)
	{
		s_pSelectedMapInfo[i] = GetDefaultMapSelection(static_cast<SelectedGameModeMapInfoIndex>(i));
	}

	char pLaunchGameModeBuffer[256] = {};
	Settings::ReadStringValue(SettingsSection::Launch, "GameMode", pLaunchGameModeBuffer, sizeof(pLaunchGameModeBuffer), "");
	s_currentGameMode = StringToGameMode(pLaunchGameModeBuffer);

	char pLaunchCampaignDifficultyLevelBuffer[256] = {};
	Settings::ReadStringValue(SettingsSection::Launch, "DifficultyLevel", pLaunchCampaignDifficultyLevelBuffer, sizeof(pLaunchCampaignDifficultyLevelBuffer), "normal");
	g_LaunchCampaignDifficultyLevel = string_to_campaign_difficulty_level(pLaunchCampaignDifficultyLevelBuffer);

	LPCSTR pDefaultHopperGameVariant = "";
	switch (s_currentGameMode)
	{
		break;
	case GameMode::Campaign:
		pDefaultHopperGameVariant = "campaign_default_054";
		break;
	case GameMode::Multiplayer:
		pDefaultHopperGameVariant = "slayer_054";
		break;
	case GameMode::Survival:
		pDefaultHopperGameVariant = "ff_firefight_054";
		break;
	}

	// #TODO: This must persist outside of the read
	static char pLaunchGameVariantBuffer[256] = {};
	uint32_t LaunchGameVariantLength = Settings::ReadStringValue(SettingsSection::Launch, "GameVariant", pLaunchGameVariantBuffer, sizeof(pLaunchGameVariantBuffer), pDefaultHopperGameVariant);
	if (LaunchGameVariantLength > 0)
	{
		s_pLaunchGameVariant = pLaunchGameVariantBuffer;
	}
	else
	{
		s_pLaunchGameVariant = "";
	}

	// #TODO: This must persist outside of the read
	static char pLaunchMapVariantBuffer[256] = {};
	uint32_t LaunchMapVariantLength = Settings::ReadStringValue(SettingsSection::Launch, "MapVariant", pLaunchMapVariantBuffer, sizeof(pLaunchMapVariantBuffer), "");
	if (LaunchMapVariantLength > 0)
	{
		s_pLaunchMapVariant = pLaunchMapVariantBuffer;
	}
	else
	{
		s_pLaunchMapVariant = "";
	}
}

GameMode GameOptionSelection::GetSelectedGameMode()
{
	return s_currentGameMode;
}

void GameOptionSelection::SelectGameMode()
{
	if (CommandLine::HasCommandLineArg("-showallmodes"))
	{
		LPCSTR s_pCurrentGameModeStr = GameModeToString(s_currentGameMode);
		if (ImGui::BeginCombo("###MODE", s_pCurrentGameModeStr))
		{
			for (int i = 0; i < GameMode::NumGameModes; i++)
			{
				LPCSTR pGameModeStr = GameModeToString(static_cast<GameMode>(i));
				if (pGameModeStr)
				{
					bool selected = s_pCurrentGameModeStr == pGameModeStr;
					if (ImGui::Selectable(pGameModeStr, &selected))
					{
						s_currentGameMode = static_cast<GameMode>(i);
						Settings::WriteStringValue(SettingsSection::Launch, "GameMode", (char*)GameModeToString(s_currentGameMode));
					}
				}
			}

			ImGui::EndCombo();
		}
	}
	else
	{
		LPCSTR s_pCurrentGameModeStr = GameModeToString(s_currentGameMode);
		if (ImGui::BeginCombo("###MODE", s_pCurrentGameModeStr))
		{
			for (underlying(SelectedGameModeMapInfoIndex) i = 0; i < underlying_cast(SelectedGameModeMapInfoIndex::Count); i++)
			{
				if (static_cast<SelectedGameModeMapInfoIndex>(i) == SelectedGameModeMapInfoIndex::Unknown)
				{
					continue;
				}

				GameMode gameMode = SelectedGameModeMapInfoIndexToGameMode(static_cast<SelectedGameModeMapInfoIndex>(i));
				LPCSTR pGameModeStr = GameModeToString(gameMode);
				if (pGameModeStr)
				{
					bool selected = s_pCurrentGameModeStr == pGameModeStr;
					if (ImGui::Selectable(pGameModeStr, &selected))
					{
						s_currentGameMode = gameMode;
						Settings::WriteStringValue(SettingsSection::Launch, "GameMode", (char*)GameModeToString(s_currentGameMode));
					}
				}
			}

			ImGui::EndCombo();
		}
	}
}

void GameOptionSelection::Render()
{


	SelectSavedFilm();

	ImGui::Separator();

	//if (s_currentGameMode != GameMode::Multiplayer)
	//{
	//	ImGui::PushItemWidth((width / 100) * 25 * 0.938f);
	//}
	//else
	//{
	//	ImGui::PushItemWidth((width / 100) * 25 * 1.415f);
	//}
	SelectGameMode();
	//ImGui::SameLine();
	SelectMap();

	//if (s_currentGameMode != GameMode::Multiplayer)
	//{
	//	ImGui::SameLine();
	//}
	SelectDifficulty();
	//ImGui::PopItemWidth();

	ImGui::Separator();

	SelectGameVariant();
	SelectMapVariant();
}

const MapInfo* GameOptionSelection::GetDefaultMapSelection(SelectedGameModeMapInfoIndex gameModeMapInfoIndex)
{
	int previousMapID = Settings::ReadIntegerValue(SettingsSection::Launch, s_kpMapInfoSettingsName[underlying_cast(gameModeMapInfoIndex)], -1);
	for (const MapInfo& rMapInfo : s_pMapInfoManager->m_mapInfo)
	{
		if (rMapInfo.GetMapID() == previousMapID)
		{
			return &rMapInfo;
		}
	}

	return nullptr;
}

const MapInfo* GameOptionSelection::GetDefaultGameOptionSelection(SelectedGameModeMapInfoIndex gameModeMapInfoIndex)
{
	int previousMapID = Settings::ReadIntegerValue(SettingsSection::Launch, s_kpMapInfoSettingsName[underlying_cast(gameModeMapInfoIndex)], -1);
	for (const MapInfo& rMapInfo : s_pMapInfoManager->m_mapInfo)
	{
		if (rMapInfo.GetMapID() == previousMapID)
		{
			return &rMapInfo;
		}
	}

	return nullptr;
}

GameOptionSelection::SelectedGameModeMapInfoIndex GameOptionSelection::GameModeToSelectedGameModeMapInfoIndex(GameMode gameMode)
{
	switch (gameMode)
	{
	case GameMode::Campaign:
		return SelectedGameModeMapInfoIndex::Campaign;
		break;
	case GameMode::Multiplayer:
		return SelectedGameModeMapInfoIndex::Multiplayer;
		break;
	case GameMode::Survival:
		return SelectedGameModeMapInfoIndex::Firefight;
		break;
	default:
		return SelectedGameModeMapInfoIndex::Unknown;
		break;
	}
}

GameMode GameOptionSelection::SelectedGameModeMapInfoIndexToGameMode(SelectedGameModeMapInfoIndex selectedGameModeMapInfoIndex)
{
	switch (selectedGameModeMapInfoIndex)
	{
	case SelectedGameModeMapInfoIndex::Campaign:
		return GameMode::Campaign;
		break;
	case SelectedGameModeMapInfoIndex::Multiplayer:
		return GameMode::Multiplayer;
		break;
	case SelectedGameModeMapInfoIndex::Firefight:
		return GameMode::Survival;
		break;
	default:
		return GameMode::None;
	}
}

const MapInfo*& GameOptionSelection::GetSelectedMapInfoBySelectedGameModeMapInfoIndex(SelectedGameModeMapInfoIndex selectedGameModeMapInfoIndex)
{
	const MapInfo*& pSelectedMapInfo = s_pSelectedMapInfo[underlying_cast(selectedGameModeMapInfoIndex)];
	return pSelectedMapInfo;
}

const MapInfo*& GameOptionSelection::GetSelectedMapInfoByGameMode(GameMode gameMode)
{
	return GetSelectedMapInfoBySelectedGameModeMapInfoIndex(GameModeToSelectedGameModeMapInfoIndex(s_currentGameMode));
}

const MapInfo* GameOptionSelection::GetSelectedMapInfo()
{
	return GetSelectedMapInfoByGameMode(s_currentGameMode);
}

const MapInfo* GameOptionSelection::GetFirstSuitableGameModeMapInfo(GameMode gameMode)
{
	for (const MapInfo& rMapInfo : s_pMapInfoManager->m_mapInfo)
	{
		if (isMapInfoCompatibleWithGameMode(gameMode, rMapInfo))
		{
			return &rMapInfo;
		}
	}
	return nullptr;
}

void GameOptionSelection::SaveSelectedMap(GameMode gameMode, const MapInfo* pMapInfo)
{
	switch (gameMode)
	{
	case GameMode::Campaign:
		Settings::WriteIntegerValue(SettingsSection::Launch, s_kpMapInfoSettingsName[underlying_cast(SelectedGameModeMapInfoIndex::Campaign)], pMapInfo ? pMapInfo->GetMapID() : -1);
		break;
	case GameMode::Multiplayer:
		Settings::WriteIntegerValue(SettingsSection::Launch, s_kpMapInfoSettingsName[underlying_cast(SelectedGameModeMapInfoIndex::Multiplayer)], pMapInfo ? pMapInfo->GetMapID() : -1);
		break;
	case GameMode::Survival:
		Settings::WriteIntegerValue(SettingsSection::Launch, s_kpMapInfoSettingsName[underlying_cast(SelectedGameModeMapInfoIndex::Firefight)], pMapInfo ? pMapInfo->GetMapID() : -1);
		break;
	default:
		Settings::WriteIntegerValue(SettingsSection::Launch, s_kpMapInfoSettingsName[underlying_cast(SelectedGameModeMapInfoIndex::Unknown)], pMapInfo ? pMapInfo->GetMapID() : -1);
		break;
	}
}

bool GameOptionSelection::isMapInfoCompatibleWithGameMode(GameMode gameMode, const MapInfo& rMapInfo)
{
	switch (gameMode)
	{
	case GameMode::Campaign:
		if (!rMapInfo.IsCampaign()) return false;
		break;
	case GameMode::Multiplayer:
		if (!rMapInfo.IsMultiplayer()) return false;
		break;
	case GameMode::Survival:
		if (!rMapInfo.IsFirefight()) return false;
		break;
	}
	return true;
}

void GameOptionSelection::RenderHoveredTooltip(const char* pText)
{
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::Text(pText);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

void GameOptionSelection::SelectMap()
{
	const MapInfo*& pSelectedMapInfo = GetSelectedMapInfoByGameMode(s_currentGameMode);

	if (!pSelectedMapInfo || pSelectedMapInfo && !isMapInfoCompatibleWithGameMode(s_currentGameMode, *pSelectedMapInfo))
	{
		pSelectedMapInfo = GetFirstSuitableGameModeMapInfo(s_currentGameMode);
		SaveSelectedMap(s_currentGameMode, pSelectedMapInfo);
	}

	const char* pSelectedLevelName = "<no level selected>";
	if (pSelectedMapInfo)
	{
		pSelectedLevelName = pSelectedMapInfo->GetFriendlyName();
	}

	if (ImGui::BeginCombo("###MAP", pSelectedLevelName))
	{
		// #TODO: Make a nice and beautiful interface to this for multi-game
		for (const MapInfo& rMapInfo : s_pMapInfoManager->m_mapInfo)
		{
			if (!isMapInfoCompatibleWithGameMode(s_currentGameMode, rMapInfo))
			{
				continue;
			}

			bool isSelected = pSelectedMapInfo == &rMapInfo;
			const char* pCurrentLevelFriendlyName = rMapInfo.GetFriendlyName();

			if (ImGui::Selectable(pCurrentLevelFriendlyName, &isSelected))
			{
				pSelectedMapInfo = &rMapInfo;
				SaveSelectedMap(s_currentGameMode, pSelectedMapInfo);
			}
			RenderHoveredTooltip(rMapInfo.GetFriendlyDescription());
		}

		ImGui::EndCombo();
	}
}

void GameOptionSelection::SelectDifficulty()
{
	if (s_currentGameMode == GameMode::Campaign || s_currentGameMode == GameMode::Survival)
	{
		LPCSTR pCurrentDifficultyStr = campaign_difficulty_level_to_string(g_LaunchCampaignDifficultyLevel);
		if (ImGui::BeginCombo("###DIFFICULTY", pCurrentDifficultyStr))
		{
			for (e_campaign_difficulty_level difficulty = e_campaign_difficulty_level::_campaign_difficulty_level_easy; difficulty < k_number_of_campaign_difficulty_levels; reinterpret_cast<int&>(difficulty)++)
			{
				LPCSTR pDifficultyStr = campaign_difficulty_level_to_string(difficulty);
				if (pDifficultyStr)
				{
					bool selected = pDifficultyStr == pCurrentDifficultyStr;
					if (ImGui::Selectable(pDifficultyStr, &selected))
					{
						g_LaunchCampaignDifficultyLevel = static_cast<e_campaign_difficulty_level>(difficulty);
						Settings::WriteStringValue(SettingsSection::Launch, "DifficultyLevel", (char*)campaign_difficulty_level_to_string(g_LaunchCampaignDifficultyLevel));
					}
				}
			}

			ImGui::EndCombo();
		}
	}
}

void GameOptionSelection::GetVariantInfo(char* pBuffer, std::string* name, std::string* desc)
{
	for (size_t i = 0; i < 256; i++)
	{
		char* nameCur = &pBuffer[0x80 + i];
		if (nameCur[0] && !nameCur[1])
		{
			*name += nameCur;
		}
		char* descCur = &pBuffer[0x180 + i];
		if (descCur[0] && !descCur[1])
		{
			*desc += descCur;
		}
	}
}

int GameOptionSelection::ReadGameVariant(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath)
{
	static s_game_variant gameVariant;
	IDataAccess* pDataAccess = HaloReachGameHost::GetDataAccess();
	assert(pDataAccess != nullptr);
	LoadGameVariant(pDataAccess, pName, gameVariant);

	int result = gameVariant.game_engine_index;

	GetVariantInfo(gameVariant.game_engine_variant.data, name, desc);

	if (!(*name).c_str()[0])
	{
		*name = pName;
	}

	return result;
}

int GameOptionSelection::ReadMapVariant(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath)
{
	static s_map_variant mapVariant;
	IDataAccess* pDataAccess = HaloReachGameHost::GetDataAccess();
	assert(pDataAccess != nullptr);
	LoadMapVariant(pDataAccess, pName, mapVariant);

	int result = *reinterpret_cast<int*>(&mapVariant.data[0x2C]);
	GetVariantInfo(mapVariant.data, name, desc);

	return result;
}

int GameOptionSelection::ReadSavedFilm(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath)
{
	IDataAccess* pDataAccess = HaloReachGameHost::GetDataAccess();
	if (pDataAccess)
	{
		char* out_data = { 0 };

		c_file_reference filo(pPath);
		if (filo.open_file())
		{
			out_data = pDataAccess->SaveFilmMetadataCreateFromFile(filo.pBuffer, static_cast<int>(filo.bufferSize))->data;

			filo.read_string_long_as_string(name, 256, 0xC0);
			filo.read_string_long_as_string(desc, 256, 0x1C0);

			filo.close_file();
		}
	}

	return -1;
}

void GameOptionSelection::SelectGameVariant()
{
	const char* pEngineName = "haloreach"; // #TODO: Set this up properly
	static std::vector<std::string> pfilePaths = {
		format_string("%s/game_variants", pEngineName/*"haloreach"*/),
		format_string("%s/hopper_game_variants", pEngineName/*"haloreach"*/),
		format_string("%s/AppData/LocalLow/MCC/Temporary/UserContent/%s/GameType/", GetUserprofileVariable(), pEngineName/*"haloreach"*/)
	};
	static c_file_array fileArray = c_file_array(pfilePaths, { ".bin" }, &ReadGameVariant);
	static LPCSTR pLast = s_pLaunchGameVariant.c_str();

	if (s_currentGameMode == GameMode::Campaign)
	{
		return;
	}

	if (ImGui::BeginCombo("###GAME VARIANT", fileArray.GetName(pLast)))
	{
		for (int i = 0; i < fileArray.Count; i++)
		{
			int shouldShow = s_currentGameMode == GameMode::Multiplayer && fileArray.GetType(i) == _game_engine_type_sandbox;
			shouldShow |= s_currentGameMode == GameMode::Multiplayer && fileArray.GetType(i) == _game_engine_type_megalo;
			shouldShow |= s_currentGameMode == GameMode::Campaign && fileArray.GetType(i) == _game_engine_type_campaign;
			shouldShow |= s_currentGameMode == GameMode::Survival && fileArray.GetType(i) == _game_engine_type_survival;

			if (fileArray.GetFileName(i) && shouldShow)
			{
				bool selected = fileArray.GetFileName(i) == fileArray.GetFileName(pLast);

				std::string pSelectedGameVariantName = std::string(fileArray.GetName(i)).append(" (").append(fileArray.GetFileName(i)).append(")###").append(std::to_string(i));
				if (ImGui::Selectable(pSelectedGameVariantName.c_str(), &selected))
				{
					pLast = fileArray.GetFileName(i);
				}

				RenderHoveredTooltip(fileArray.GetDesc(i));
			}
		}

		ImGui::EndCombo();
	}

	s_pLaunchGameVariant = pLast;
}

void GameOptionSelection::SelectMapVariant()
{
	const char* pEngineName = "haloreach"; // #TODO: Set this up properly
	static std::vector<std::string> pfilePaths = {
		format_string("%s/map_variants", pEngineName/*"haloreach"*/),
		format_string("%s/map_game_variants", pEngineName/*"haloreach"*/),
		format_string("%s/AppData/LocalLow/MCC/Temporary/UserContent/%s/Map/", GetUserprofileVariable(), pEngineName/*"haloreach"*/)
	};
	static c_file_array fileArray = c_file_array(pfilePaths, { ".mvar" }, &ReadMapVariant);
	static LPCSTR pLast = s_pLaunchMapVariant.c_str();

	if (s_currentGameMode != GameMode::Multiplayer)
	{
		return;
	}

	const MapInfo* pSelectedMapInfo = GetSelectedMapInfoByGameMode(s_currentGameMode);

	LPCSTR lastMapName = fileArray.GetName(pLast);
	if (!lastMapName || pLast[0] == 0)
	{
		pLast = "";
		lastMapName = "<Default Variant>";
	}
	if (ImGui::BeginCombo("###MAP VARIANT", lastMapName))
	{
		bool defaultSelected = false;
		if (ImGui::Selectable("<Default Variant>", &defaultSelected))
		{
			pLast = "";
		}

		for (int i = 0; i < fileArray.Count; i++)
		{
			int shouldShow = fileArray.GetType(i) == pSelectedMapInfo->GetMapID();

			if (fileArray.GetFileName(i) && shouldShow)
			{
				bool selected = fileArray.GetFileName(i) == fileArray.GetFileName(pLast);

				std::string pSelectedMapVariantName = std::string(fileArray.GetName(i)).append(" (").append(fileArray.GetFileName(i)).append(")###").append(std::to_string(i));
				if (ImGui::Selectable(pSelectedMapVariantName.c_str(), &selected) && !defaultSelected)
				{
					pLast = fileArray.GetFileName(i);
				}

				RenderHoveredTooltip(fileArray.GetDesc(i));
			}
		}

		ImGui::EndCombo();
	}

	s_pLaunchMapVariant = pLast;
}

void GameOptionSelection::SelectSavedFilm()
{
	static std::vector<std::string> pFilePaths = {
		format_string("%s/Temporary/autosave/", "haloreach"),
		format_string("%s/AppData/LocalLow/MCC/Temporary/UserContent/%s/Movie/", GetUserprofileVariable(), "haloreach"),
		format_string("%s/AppData/LocalLow/MCC/Temporary/%s/autosave/", GetUserprofileVariable(), "haloreach")
	};

	static c_file_array fileArray = c_file_array(pFilePaths, { ".film", ".mov" }, &ReadSavedFilm);
	static LPCSTR pLast = "";

	if (s_pLaunchSavedFilm != fileArray.GetFileName(pLast))
	{
		s_pLaunchSavedFilm = fileArray.GetFileName(pLast);
	}
	if (pLast != fileArray.GetFileName(pLast))
	{
		pLast = fileArray.GetFileName(pLast);
	}

	if (ImGui::BeginCombo("###SAVED FILM", fileArray.GetDesc(pLast)))
	{
		for (int i = 0; i < fileArray.Count; i++)
		{
			if (fileArray.GetName(i))
			{
				bool selected = fileArray.GetName(i) == fileArray.GetName(pLast);

				std::string pSelectedSavedFilmName = std::string(fileArray.GetDesc(i)).append(" (").append(fileArray.GetFileName(i)).append(")###").append(std::to_string(i));
				if (ImGui::Selectable(fileArray.GetDesc(i), &selected))
				{
					pLast = fileArray.GetFileName(i);
				}

				RenderHoveredTooltip(fileArray.GetName(i));
			}
		}

		ImGui::EndCombo();
	}

	s_pLaunchSavedFilm = pLast;
}

void GameOptionSelection::LoadMapVariant(IDataAccess* pDataAccess, const char* pVariantName, s_map_variant& rMapVariant, bool print)
{
	memset(&rMapVariant, 0, sizeof(rMapVariant));

	if (pVariantName[0])
	{
		static std::string pFileName = "";
		if (!PathFileExists((pFileName = format_string("%s/hopper_map_variants/%s.mvar", "haloreach", pVariantName)).c_str()))
		{
			if (!PathFileExists((pFileName = format_string("%s/map_variants/%s.mvar", "haloreach", pVariantName)).c_str()))
			{
				if (!PathFileExists((pFileName = format_string("%s/AppData/LocalLow/HaloMCC/Temporary/UserContent/%s/Map/%s.mvar", GetUserprofileVariable(), "haloreach", pVariantName)).c_str()))
				{
					if (!PathFileExists((pFileName = format_string("%s/AppData/LocalLow/MCC/Temporary/UserContent/%s/Map/%s.mvar", GetUserprofileVariable(), "haloreach", pVariantName)).c_str()))
					{
						pFileName = "";
					}
				}
			}
		}

		c_file_reference filo(pFileName.c_str());
		if (filo.open_file())
		{
			if (print)
			{
				WriteLineVerbose("Loading map variant [%s]", pFileName.c_str());
			}

			rMapVariant = pDataAccess->MapVariantCreateFromFile(filo.pBuffer, static_cast<int>(filo.bufferSize))->MapVariant;
			filo.close_file();
			return;
		}
	}

	// fallback to use map ID
	{
		const MapInfo* pSelectedMapInfo = GetSelectedMapInfoByGameMode(s_currentGameMode);

		if (print)
		{
			WriteLineVerbose("Creating map variant for '%s'", pSelectedMapInfo->GetFriendlyName());
		}

		rMapVariant = pDataAccess->MapVariantCreateFromMapID(pSelectedMapInfo->GetMapID())->MapVariant;
	}
}

void GameOptionSelection::LoadGameVariant(IDataAccess* pDataAccess, const char* pVariantName, s_game_variant& rGameVariant, bool print)
{
	memset(&rGameVariant, 0, sizeof(rGameVariant));
	if (pVariantName == nullptr)
	{
		return;
	}

	static std::string pFileName = "";
	if (!PathFileExists((pFileName = format_string("%s/hopper_game_variants/%s.bin", "haloreach", pVariantName)).c_str()))
	{
		if (!PathFileExists((pFileName = format_string("%s/game_variants/%s.bin", "haloreach", pVariantName)).c_str()))
		{
			if (!PathFileExists((pFileName = format_string("%s/AppData/LocalLow/HaloMCC/Temporary/UserContent/%s/GameType/%s.bin", GetUserprofileVariable(), "haloreach", pVariantName)).c_str()))
			{
				if (!PathFileExists((pFileName = format_string("%s/AppData/LocalLow/MCC/Temporary/UserContent/%s/GameType/%s.bin", GetUserprofileVariable(), "haloreach", pVariantName)).c_str()))
				{
					pFileName = "";
				}
			}
		}
	}

	c_file_reference filo(pFileName.c_str());
	if (filo.open_file())
	{
		if (print)
		{
			WriteLineVerbose("Loading game variant [%s]", pFileName.c_str());
		}
		rGameVariant = pDataAccess->GameVariantCreateFromFile(filo.pBuffer, static_cast<int>(filo.bufferSize))->GameVariant;
		filo.close_file();
	}
}

// TODO: Test, and fix if broke
void GameOptionSelection::LoadPreviousGamestate(const char* pGamestateName, GameContext& gameContext)
{
	char pFileName[MAX_PATH + 1];
	sprintf(pFileName, "%s.hdr", pGamestateName);
	pFileName[MAX_PATH] = 0;

	char* pGameStateBuffer = {};
	size_t gameStateSize = {};

	c_file_reference filo(pFileName);
	if (filo.open_file())
	{
		pGameStateBuffer = new char[filo.bufferSize];
		memset(pGameStateBuffer, 0x00, filo.bufferSize);
		pGameStateBuffer = filo.pBuffer;

		gameContext.GameMode = GameMode::Campaign;
		gameContext.GameStateHeaderSize = filo.bufferSize;
		gameContext.pGameStateHeader = pGameStateBuffer;

		filo.close_file();
	}
}

void GameOptionSelection::LoadSavedFilmMetadata(const char* pSavedFilmName, GameContext& gameContext)
{
	if (!pSavedFilmName[0])
		return;

	static std::string pFileName = "";
	if (!PathFileExists((pFileName = format_string("%s/Temporary/autosave/%s.film", "haloreach", pSavedFilmName)).c_str()))
	{
		if (!PathFileExists((pFileName = format_string("%s/Temporary/autosave/%s.mov", "haloreach", pSavedFilmName)).c_str()))
		{
			if (!PathFileExists((pFileName = format_string("%s/AppData/LocalLow/HaloMCC/Temporary/UserContent/%s/Movie/%s.mov", GetUserprofileVariable(), "haloreach", pSavedFilmName)).c_str()))
			{
				if (!PathFileExists((pFileName = format_string("%s/AppData/LocalLow/MCC/Temporary/UserContent/%s/Movie/%s.mov", GetUserprofileVariable(), "haloreach", pSavedFilmName)).c_str()))
				{
					if (!PathFileExists((pFileName = format_string("%s/AppData/LocalLow/MCC/Temporary/%s/autosave/%s.film", GetUserprofileVariable(), "haloreach", pSavedFilmName)).c_str()))
					{
						pFileName = "";
					}
				}
			}
		}
	}

	if (pFileName.c_str())
	{
		WriteLineVerbose("Loading saved film [%s]", pFileName.c_str());
	}

	gameContext.SavedFilmPath = pFileName.c_str();
}

