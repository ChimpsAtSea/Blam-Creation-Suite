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

	typedef void(GameLaunchCallback)(HaloGameID gameID);
	typedef void(GameShutdownCallback)(HaloGameID gameID);

	static void Init(HINSTANCE hInstance, LPSTR lpCmdLine);
	static void Deinit();
	static void RegisterTerminationValue(char& rTerminationReference);

	static bool HasCommandLineArg(const char* pArgument);
	static void Terminate();
	static void RegisterGameLaunchCallback(HaloGameID gameID, GameLaunchCallback gameLaunchCallback);
	static void RegisterGameShutdownCallback(HaloGameID gameID, GameShutdownCallback gameShutdownCallback);
	static void LoadSettings();
	static int Run(HINSTANCE hInstance, LPSTR lpCmdLine, GameInterface& rGameInterface);
	static void SetupGameContext(GameContext& gameContext);
	static void LaunchGame();
	static void SetState(CurrentState state);
	static void Update();
	static void Render();
	static void BeginRender();
	static void EndRender();
	static void DrawMenu();

	static void SelectGameMode();
	static void SelectMap();
	static void SelectDifficulty();
	static void SelectGameVariant();
	static void SelectMapVariant();

	


	static void InitSockets();
	static void DeinitSockets();

	static void LoadHopperMapVariant(IDataAccess* pDataAccess, const char* pHopperGameVariantName, s_map_variant& out_map_variant);
	static void LoadHopperGameVariant(IDataAccess* pDataAccess, const char* pHopperGameVariantName, s_game_variant& out_game_variant);
	static void LoadPreviousGamestate(const char* pFilename, GameContext& gameContext);
	static char* s_pTerminationFlag;
	HaloGameID GetCurrentGameID();
	static bool s_gameManuallyKilled;
	static bool s_hideWindowOnStartup; 


	static CurrentState s_currentState;
	// #TODO: Implement a map and vector for this!!!
	static GameLaunchCallback* s_gameLaunchCallback;
	static GameShutdownCallback* s_gameShutdownCallback;
	static GameInterface* s_pCurrentGameInterface;
	static IGameEngine* s_pHaloReachEngine;
	
};

