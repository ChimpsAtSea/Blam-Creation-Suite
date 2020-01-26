#pragma once

class GameLauncher
{
public:
	static void Init();
	static void Deinit();
	static void OpusTick();
	static void OpusUITick();
	static void GameTick();
	inline static bool IsGameRunning() { return s_gameRunning; }
private:
	static void loadSettings();
	static void update();
	static void renderMainMenu();
	static void renderUI();
	static void updateCamera();
	static void renderCameraDebug();
	static void gameRender();
	static void launchGame(EngineVersion engineVersion);
	static void launchHaloReach();
	static void checkSteamOwnership();
	static void ensureBink2Win64IsLoaded(const char* pLibName, const char* pFallbackDir);
	static void renderPauseMenu();
private:

public:
	using GenericGameEvent = void(*)(EngineVersion engineVersion, BuildVersion buildVersion);
	inline static void RegisterGameStartupCallback(GenericGameEvent eventCallback) { s_gameStartupEvent.push_back(eventCallback); }
	inline static void RegisterGameShutdownCallback(GenericGameEvent eventCallback) { s_gameShutdownEvent.push_back(eventCallback); }
	inline static void UnregisterGameLaunchCallback(GenericGameEvent eventCallback) { VectorEraseByValueHelper(s_gameStartupEvent, eventCallback); }
	inline static void UnregisterGameShutdownCallback(GenericGameEvent eventCallback) { VectorEraseByValueHelper(s_gameShutdownEvent, eventCallback); }
private:
	static std::vector<GenericGameEvent> s_gameStartupEvent;
	static std::vector<GenericGameEvent> s_gameShutdownEvent;
	static bool s_gameRunning;
};

//class LegacyGameLauncher
//{
//public:
//	enum class CurrentState
//	{
//		eInactive,
//		eMainMenu,
//		eWaitingToRun,
//		eRunning,
//		eFinished
//	};
//
//	enum class SelectedGameModeMapInfoIndex
//	{
//		Campaign,
//		Multiplayer,
//		Firefight,
//		Unknown,
//		Count
//	};
//
//	typedef void(GameLaunchCallback)(EngineVersion engineVersion, BuildVersion buildVersion);
//	typedef void(GameShutdownCallback)(EngineVersion engineVersion, BuildVersion buildVersion);
//
//	static void Init(HINSTANCE hInstance, LPSTR lpCmdLine);
//	static void Deinit();
//	static void RegisterTerminationValue(char& rTerminationReference);
//
//	
//	static void Terminate();
//	static void EnsureBink2Win64IsLoaded(const char* pLibName, const char* pFallbackDir = "");
//	static void RegisterGameLaunchCallback(EngineVersion engineVersion, GameLaunchCallback gameLaunchCallback);
//	static void RegisterGameShutdownCallback(EngineVersion engineVersion, GameShutdownCallback gameShutdownCallback);
//	static void LoadSettings();
//	static int Run(HINSTANCE hInstance, LPSTR lpCmdLine, GameRuntime& rGameRuntime);
//	static void SetupGameContext(GameContext& gameContext);
//	static void LaunchGame();
//	static void SetState(CurrentState state);
//	static void Update();
//	static void Render();
//	static void BeginRender();
//	static void EndRender();
//	static void DrawMainMenu();
//	static void DrawPauseMenu();
//
//	static const MapInfo* GetDefaultGameOptionSelection(SelectedGameModeMapInfoIndex gameModeMapInfoIndex);
//	static void SelectGameMode();
//	static bool IsMapInfoCompatibleWithGameMode(GameMode gameMode, const MapInfo& rMapInfo);
//	static const MapInfo* GetFirstSuitableGameModeMapInfo(GameMode gameMode);
//	static void SaveSelectedMap(GameMode gameMode, const MapInfo* pMapInfo);
//	static SelectedGameModeMapInfoIndex GameModeToSelectedGameModeMapInfoIndex(GameMode gameMode);
//	static GameMode SelectedGameModeMapInfoIndexToGameMode(SelectedGameModeMapInfoIndex selectedGameModeMapInfoIndex);
//	static const MapInfo*& GetSelectedMapInfoBySelectedGameModeMapInfoIndex(SelectedGameModeMapInfoIndex selectedGameModeMapInfoIndex);
//	static const MapInfo*& GetSelectedMapInfoByGameMode(GameMode gameMode);
//	static void SelectMap();
//	static void SelectDifficulty();
//	static void SelectGameVariant();
//	static void SelectMapVariant();
//	static void SelectSavedFilm();
//
//
//	static void CheckSteamAPI();
//
//
//	static char* s_pTerminationFlag;
//	BuildVersion GetCurrentbuildVersion();
//	static bool s_gameManuallyKilled;
//	static bool s_hideWindowOnStartup; 
//
//	static CurrentState s_currentState;
//	// #TODO: Implement a map and vector for this!!!
//	static GameLaunchCallback* s_gameLaunchCallback;
//	static GameShutdownCallback* s_gameShutdownCallback;
//	static GameRuntime* s_pCurrentGameRuntime;
//	static IGameEngine* s_pHaloReachEngine;
//	static std::atomic<int> s_uiStackLength;
//
//	static const MapInfo* s_pSelectedMapInfo[underlying_cast(SelectedGameModeMapInfoIndex::Count)];
//	static constexpr const char* s_kpMapInfoSettingsName[underlying_cast(SelectedGameModeMapInfoIndex::Count)] = { "LastCampaignMap", "LastMultiplayerMap", "LastSurvivalMap", "LastUnknownGamemodeMap" };
//};

