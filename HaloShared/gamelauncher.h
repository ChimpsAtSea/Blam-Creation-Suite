#pragma once

class GameLauncher
{
public:

	typedef void(GameLaunchCallback)(HaloGameID gameID);
	typedef void(GameShutdownCallback)(HaloGameID gameID);

	static void Init(LPSTR lpCmdLine);
	static void Deinit();
	static void RegisterTerminationValue(char& rTerminationReference);

	static void Terminate();
	static void RegisterGameLaunchCallback(HaloGameID gameID, GameLaunchCallback gameLaunchCallback);
	static void RegisterGameShutdownCallback(HaloGameID gameID, GameShutdownCallback gameShutdownCallback);
	static void LoadSettings();
	static void LaunchGame(const char* pGameLibrary);
	static void Update();
	


	static void InitSockets();
	static void DeinitSockets();

	static HaloGameID GetLibraryHaloGameID(const char* pFilename);
	static uint64_t GetLibraryFileVersion(const char* pFilename);
	static void LoadHopperMapVariant(IDataAccess* pDataAccess, const char* pHopperGameVariantName, s_map_variant& out_map_variant);
	static void LoadHopperGameVariant(IDataAccess* pDataAccess, const char* pHopperGameVariantName, s_game_variant& out_game_variant);
	static void LoadPreviousGamestate(const char* pFilename, s_game_launch_data& game_launch_data);
	static char* s_pTerminationFlag;
	static bool s_gameManuallyKilled;
	static bool s_hideWindowOnStartup; 

	enum class CurrentState
	{
		eInactive,
		eRunning,
		eFinished
	};
	static CurrentState s_currentGameState;
	// #TODO: Implement a map and vector for this!!!
	static GameLaunchCallback* s_gameLaunchCallback;
	static GameShutdownCallback* s_gameShutdownCallback;
	
};

