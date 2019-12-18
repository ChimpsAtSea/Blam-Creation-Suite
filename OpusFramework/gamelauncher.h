#pragma once

class GameLauncher
{
public:
	enum class CurrentState
	{
		eInactive,
		eMainMenu,
		eWaitingToRun,
		eRunning,
		eFinished
	};

	typedef void(GameLaunchCallback)(EngineVersion engineVersion, BuildVersion buildVersion);
	typedef void(GameShutdownCallback)(EngineVersion engineVersion, BuildVersion buildVersion);

	static void Init(HINSTANCE hInstance, LPSTR lpCmdLine);
	static void Deinit();
	static void RegisterTerminationValue(char& rTerminationReference);

	static bool HasCommandLineArg(const char* pArgument);
	static void Terminate();
	static void RegisterGameLaunchCallback(EngineVersion engineVersion, GameLaunchCallback gameLaunchCallback);
	static void RegisterGameShutdownCallback(EngineVersion engineVersion, GameShutdownCallback gameShutdownCallback);
	static void LoadSettings();
	static int Run(HINSTANCE hInstance, LPSTR lpCmdLine, GameInterface& rGameInterface);
	static void SetupGameContext(GameContext& gameContext);
	static void LaunchGame();
	static void SetState(CurrentState state);
	static void Update();
	static void Render();
	static void BeginRender();
	static void EndRender();
	static void DrawMainMenu();
	static void DrawPauseMenu();

	static void SelectGameMode();
	static void SelectMap();
	static void SelectDifficulty();
	static void SelectGameVariant();
	static void SelectMapVariant();
	static void SelectSavedFilm();

	


	static void InitSockets();
	static void DeinitSockets();

	static void LoadMapVariant(IDataAccess* pDataAccess, const char* pVariantName, s_map_variant& out_variant, bool print = false);
	static void LoadGameVariant(IDataAccess* pDataAccess, const char* pVariantName, s_game_variant& out_variant, bool print = false);
	static void LoadPreviousGamestate(const char* pFilename, GameContext& gameContext);
	static void LoadSavedFilmMetadata(const char* pSavedFilmName, GameContext &gameContext);
	static char* s_pTerminationFlag;
	BuildVersion GetCurrentbuildVersion();
	static bool s_gameManuallyKilled;
	static bool s_hideWindowOnStartup; 


	static CurrentState s_currentState;
	// #TODO: Implement a map and vector for this!!!
	static GameLaunchCallback* s_gameLaunchCallback;
	static GameShutdownCallback* s_gameShutdownCallback;
	static GameInterface* s_pCurrentGameInterface;
	static IGameEngine* s_pHaloReachEngine;
	static std::atomic<int> s_uiStackLength;
	
};

