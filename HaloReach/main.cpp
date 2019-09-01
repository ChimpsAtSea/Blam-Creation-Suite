#include "haloreach-private-pch.h"

#define this _this

void nullsub()
{
}

HMODULE HaloReach; //haloreach.dll

typedef errno_t(__fastcall* SetLibrarySettingsFunc)(wchar_t* Src);
SetLibrarySettingsFunc* SetLibrarySettings = nullptr;
typedef signed __int64(__fastcall CreateGameEngineFunc)(IGameEngine** ppGameEngine);
CreateGameEngineFunc* CreateGameEngine = nullptr;
typedef __int64(__fastcall CreateDataAccessFunc)(IDataAccess** ppDataAccess);
CreateDataAccessFunc* CreateDataAccess = nullptr;


IGameEngine* pHaloReachEngine = nullptr;
IDataAccess* pHaloReachDataAccess = nullptr;


#define NULLSUB_LAMBDA_LOG(message) []() { WriteLineVerbose(message); }
#define NULLSUB_LAMBDA(message) nullsub

typedef __int64(ZeroSubFunc)();
#define ZEROSUB_LAMBDA(message) (NullSubFunc*)(ZeroSubFunc*)[]() { WriteLineVerbose(message " <zerosub>"); return __int64(0);  }

GUID* __fastcall GetGuid(GameEvents* this, GUID* rGuid)
{
	GUID* result; // rax

	result = rGuid;
	*rGuid = this->guid;
	return result;
}


void setup_game_engine_host_callback()
{
	IGameEngineHost::g_gameEngineHost.pGameEvents = &gameEvents;
}

void setup_game_events()
{
	//=========================================================
	//                    game events
	//=========================================================

	gameEvents.vftbl = &gameEventsVftbl;


	typedef void(__fastcall BIFactDeepLinkSendFunc)(GameEvents*, _QWORD*, GUID*, _QWORD*, __int64*);
	typedef void(__fastcall BroadcastingStartFunc)(GameEvents*, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _QWORD);
	typedef __int64(__fastcall BIFactControllerSettingsFunc)(GameEvents*, unsigned __int64*, GUID*, _QWORD, __int64, _DWORD, int, int);
	typedef __int64(__fastcall Member120Func)(GameEvents*, _QWORD);

	gameEventsVftbl.AchievementEarned = NULLSUB_LAMBDA_LOG("GameEvents::vftable[0]");
	gameEventsVftbl.AshesToAshes = NULLSUB_LAMBDA_LOG("GameEvents::vftable::AshesToAshes");
	gameEventsVftbl.Assist = NULLSUB_LAMBDA_LOG("GameEvents::vftable::Assist");
	gameEventsVftbl.AudioLogClaimed = NULLSUB_LAMBDA_LOG("GameEvents::vftable::AudioLogClaimed");
	gameEventsVftbl.Base = NULLSUB_LAMBDA_LOG("GameEvents::vftable::Base");
	gameEventsVftbl.Betrayal = NULLSUB_LAMBDA_LOG("GameEvents::vftable::Betrayal");
	gameEventsVftbl.BIFactControllerSettings = [](GameEvents*, unsigned __int64*, GUID*, _QWORD, __int64, _DWORD, int, int) { printf("GameEvents::vftable::BIFactControllerSettings""\n"); return __int64(0); };
	gameEventsVftbl.BIFactDeepLink = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BIFactDeepLink");
	gameEventsVftbl.BIFactDeepLinkRecieve = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BIFactDeepLinkRecieve");
	gameEventsVftbl.BIFactDeepLinkSend = [](GameEvents*, _QWORD*, GUID*, _QWORD*, __int64*) { printf("GameEvents::vftable::BIFactDeepLinkSend""\n"); };
	gameEventsVftbl.BIFactDualWield = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BIFactDualWield");
	gameEventsVftbl.BIFactGameSession = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BIFactGameSession");
	gameEventsVftbl.BIFactLoadout = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BIFactLoadout");
	gameEventsVftbl.BIFactMatchmaking = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BIFactMatchmaking");
	gameEventsVftbl.BIFactMatchmakingDetails = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BIFactMatchmakingDetails");
	gameEventsVftbl.BIFactMedia = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BIFactMedia");
	gameEventsVftbl.BirdOfPrey = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BirdOfPrey");
	gameEventsVftbl.BitsAndPiecesDestroyed = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BitsAndPiecesDestroyed");
	gameEventsVftbl.BroadcastingAssist = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BroadcastingAssist");
	gameEventsVftbl.BroadcastingDeath = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BroadcastingDeath");
	gameEventsVftbl.BroadcastingHeartbeat = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BroadcastingHeartbeat");
	gameEventsVftbl.BroadcastingKill = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BroadcastingKill");
	gameEventsVftbl.BroadcastingMatchEnd = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BroadcastingMatchEnd");
	gameEventsVftbl.MultiplayerRoundEnd = NULLSUB_LAMBDA_LOG("GameEvents::vftable::MultiplayerRoundEnd");
	gameEventsVftbl.MultiplayerRoundStart = NULLSUB_LAMBDA_LOG("GameEvents::vftable::MultiplayerRoundStart");
	gameEventsVftbl.BroadcastingMatchStart = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BroadcastingMatchStart");
	gameEventsVftbl.BroadcastingMedal = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BroadcastingMedal");
	gameEventsVftbl.BroadcastingPlayerJoined = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BroadcastingPlayerJoined");
	gameEventsVftbl.BroadcastingPlayerLeft = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BroadcastingPlayerLeft");
	gameEventsVftbl.BroadcastingPlayerSpawn = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BroadcastingPlayerSpawn");
	gameEventsVftbl.BroadcastingPlayerSwitchedTeams = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BroadcastingPlayerSwitchedTeams");
	gameEventsVftbl.BroadcastingScore = NULLSUB_LAMBDA_LOG("GameEvents::vftable::BroadcastingScore");
	gameEventsVftbl.BroadcastingStart = [](GameEvents*, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _QWORD) { printf("GameEvents::vftable::BroadcastingStart""\n"); };
	gameEventsVftbl.CampaignDifficulty = NULLSUB_LAMBDA_LOG("GameEvents::vftable::CampaignDifficulty");
	gameEventsVftbl.ChallengeCompleted = NULLSUB_LAMBDA_LOG("GameEvents::vftable::ChallengeCompleted");
	gameEventsVftbl.ClassicModeSwitched = NULLSUB_LAMBDA_LOG("GameEvents::vftable::ClassicModeSwitched");
	gameEventsVftbl.CleverGirl = NULLSUB_LAMBDA_LOG("GameEvents::vftable::CleverGirl");
	gameEventsVftbl.ClueClaimed = NULLSUB_LAMBDA_LOG("GameEvents::vftable::ClueClaimed");
	gameEventsVftbl.CoopMissionCompleted = NULLSUB_LAMBDA_LOG("GameEvents::vftable::CoopMissionCompleted");
	gameEventsVftbl.CoopSpartanOpsMissionCompleted = NULLSUB_LAMBDA_LOG("GameEvents::vftable::CoopSpartanOpsMissionCompleted");
	gameEventsVftbl.CompletionCount = NULLSUB_LAMBDA_LOG("GameEvents::vftable::CompletionCount");
	gameEventsVftbl.Customization = NULLSUB_LAMBDA_LOG("GameEvents::vftable::Customization");
	gameEventsVftbl.DashboardContext = NULLSUB_LAMBDA_LOG("GameEvents::vftable::DashboardContext");
	gameEventsVftbl.Death = NULLSUB_LAMBDA_LOG("GameEvents::vftable::Death");
	gameEventsVftbl.DollFound = NULLSUB_LAMBDA_LOG("GameEvents::vftable::DollFound");
	gameEventsVftbl.EliteWin = NULLSUB_LAMBDA_LOG("GameEvents::vftable::EliteWin");
	gameEventsVftbl.Emblem = NULLSUB_LAMBDA_LOG("GameEvents::vftable::Emblem");
	gameEventsVftbl.EnemyDefeated = NULLSUB_LAMBDA_LOG("GameEvents::vftable::EnemyDefeated");
	gameEventsVftbl.FriendsBestedOnHeroLeaderboard = NULLSUB_LAMBDA_LOG("GameEvents::vftable::FriendsBestedOnHeroLeaderboard");
	gameEventsVftbl.GameProgress = NULLSUB_LAMBDA_LOG("GameEvents::vftable::GameProgress");
	gameEventsVftbl.GameVarSaved = NULLSUB_LAMBDA_LOG("GameEvents::vftable::GameVarSaved");
	gameEventsVftbl.GrenadeStick = NULLSUB_LAMBDA_LOG("GameEvents::vftable::GrenadeStick");
	gameEventsVftbl.HelloNurse = NULLSUB_LAMBDA_LOG("GameEvents::vftable::HelloNurse");
	gameEventsVftbl.InGamePresence = NULLSUB_LAMBDA_LOG("GameEvents::vftable::InGamePresence");
	gameEventsVftbl.ISeeYou = NULLSUB_LAMBDA_LOG("GameEvents::vftable::ISeeYou");
	gameEventsVftbl.Joinability = NULLSUB_LAMBDA_LOG("GameEvents::vftable::Joinability");
	gameEventsVftbl.Lobby = NULLSUB_LAMBDA_LOG("GameEvents::vftable::Lobby");
	gameEventsVftbl.MainMenuPresence = NULLSUB_LAMBDA_LOG("GameEvents::vftable::MainMenuPresence");
	gameEventsVftbl.MapVarSaved = NULLSUB_LAMBDA_LOG("GameEvents::vftable::MapVarSaved");
	gameEventsVftbl.MatchmakingHopper = NULLSUB_LAMBDA_LOG("GameEvents::vftable::MatchmakingHopper");
	gameEventsVftbl.MediaUsage = NULLSUB_LAMBDA_LOG("GameEvents::vftable::MediaUsage");
	gameEventsVftbl.MeldOfferPresented = NULLSUB_LAMBDA_LOG("GameEvents::vftable::MeldOfferPresented");
	gameEventsVftbl.MeldOfferResponded = NULLSUB_LAMBDA_LOG("GameEvents::vftable::MeldOfferResponded");
	gameEventsVftbl.MeldPageAction = NULLSUB_LAMBDA_LOG("GameEvents::vftable::MeldPageAction");
	gameEventsVftbl.MeldPageView = NULLSUB_LAMBDA_LOG("GameEvents::vftable::MeldPageView");
	gameEventsVftbl.MissionCompleted = NULLSUB_LAMBDA_LOG("GameEvents::vftable::MissionCompleted");
	gameEventsVftbl.MortardomWraithsKilled = NULLSUB_LAMBDA_LOG("GameEvents::vftable::MortardomWraithsKilled");
	gameEventsVftbl.MultiplayerGameEngine = NULLSUB_LAMBDA_LOG("GameEvents::vftable::MultiplayerGameEngine");
	gameEventsVftbl.MultiplayerMap = NULLSUB_LAMBDA_LOG("GameEvents::vftable::MultiplayerMap");
	gameEventsVftbl.MultiplayerRoundEnd = NULLSUB_LAMBDA_LOG("GameEvents::vftable::MultiplayerRoundEnd");
	gameEventsVftbl.MultiplayerRoundStart = NULLSUB_LAMBDA_LOG("GameEvents::vftable::MultiplayerRoundStart");
	gameEventsVftbl.NappersCaught = NULLSUB_LAMBDA_LOG("GameEvents::vftable::NappersCaught");
	gameEventsVftbl.NewsStoryRead = NULLSUB_LAMBDA_LOG("GameEvents::vftable::NewsStoryRead");
	gameEventsVftbl.ObjectiveEnd = NULLSUB_LAMBDA_LOG("GameEvents::vftable::ObjectiveEnd");
	gameEventsVftbl.ObjectiveStart = NULLSUB_LAMBDA_LOG("GameEvents::vftable::ObjectiveStart");
	gameEventsVftbl.PageAction = NULLSUB_LAMBDA_LOG("GameEvents::vftable::PageAction");
	gameEventsVftbl.PageView = NULLSUB_LAMBDA_LOG("GameEvents::vftable::PageView");
	gameEventsVftbl.PhantomHunter = NULLSUB_LAMBDA_LOG("GameEvents::vftable::PhantomHunter");
	gameEventsVftbl.PigsCanFly = NULLSUB_LAMBDA_LOG("GameEvents::vftable::PigsCanFly");
	gameEventsVftbl.PlayerCheckedInToday = NULLSUB_LAMBDA_LOG("GameEvents::vftable::PlayerCheckedInToday");
	gameEventsVftbl.PlayerDefeated = NULLSUB_LAMBDA_LOG("GameEvents::vftable::PlayerDefeated");
	gameEventsVftbl.PlayerGameResults = NULLSUB_LAMBDA_LOG("GameEvents::vftable::PlayerGameResults");
	gameEventsVftbl.PlayerGameResultsDamageStat = NULLSUB_LAMBDA_LOG("GameEvents::vftable::PlayerGameResultsDamageStat");
	gameEventsVftbl.PlayerGameResultsGriefingStat = NULLSUB_LAMBDA_LOG("GameEvents::vftable::PlayerGameResultsGriefingStat");
	gameEventsVftbl.PlayerGameResultsGriefingStats = NULLSUB_LAMBDA_LOG("GameEvents::vftable::PlayerGameResultsGriefingStats");
	gameEventsVftbl.PlayerGameResultsInterestStats = NULLSUB_LAMBDA_LOG("GameEvents::vftable::PlayerGameResultsInterestStats");
	gameEventsVftbl.PlayerGameResultsMedal = NULLSUB_LAMBDA_LOG("GameEvents::vftable::PlayerGameResultsMedal");
	gameEventsVftbl.PlayerSessionEnd = NULLSUB_LAMBDA_LOG("GameEvents::vftable::PlayerSessionEnd");
	gameEventsVftbl.PlayerSessionPause = NULLSUB_LAMBDA_LOG("GameEvents::vftable::PlayerSessionPause");
	gameEventsVftbl.PlayerSessionResume = NULLSUB_LAMBDA_LOG("GameEvents::vftable::PlayerSessionResume");
	gameEventsVftbl.PlayerSessionStart = NULLSUB_LAMBDA_LOG("GameEvents::vftable::PlayerSessionStart");
	gameEventsVftbl.PlayerSpawned = NULLSUB_LAMBDA_LOG("GameEvents::vftable::PlayerSpawned");
	gameEventsVftbl.PlaylistCompleted = NULLSUB_LAMBDA_LOG("GameEvents::vftable::PlaylistCompleted");
	gameEventsVftbl.PlaylistProgress = NULLSUB_LAMBDA_LOG("GameEvents::vftable::PlaylistProgress");
	gameEventsVftbl.RankedStatsDNFInfo = NULLSUB_LAMBDA_LOG("GameEvents::vftable::RankedStatsDNFInfo");
	gameEventsVftbl.RankedStatsOverride = NULLSUB_LAMBDA_LOG("GameEvents::vftable::RankedStatsOverride");
	gameEventsVftbl.RankedStatsPenalty = NULLSUB_LAMBDA_LOG("GameEvents::vftable::RankedStatsPenalty");
	gameEventsVftbl.RankedStatsUpdate = NULLSUB_LAMBDA_LOG("GameEvents::vftable::RankedStatsUpdate");
	gameEventsVftbl.RankedUpSpartanIv = NULLSUB_LAMBDA_LOG("GameEvents::vftable::RankedUpSpartanIv");
	gameEventsVftbl.RealtimeFlagCaptured = NULLSUB_LAMBDA_LOG("GameEvents::vftable::RealtimeFlagCaptured");
	gameEventsVftbl.RealtimeMedal = NULLSUB_LAMBDA_LOG("GameEvents::vftable::RealtimeMedal");
	gameEventsVftbl.RealtimePilotedVehicle = NULLSUB_LAMBDA_LOG("GameEvents::vftable::RealtimePilotedVehicle");
	gameEventsVftbl.RivalID = NULLSUB_LAMBDA_LOG("GameEvents::vftable::RivalID");
	gameEventsVftbl.SectionEnd = NULLSUB_LAMBDA_LOG("GameEvents::vftable::SectionEnd");
	gameEventsVftbl.SectionStart = NULLSUB_LAMBDA_LOG("GameEvents::vftable::SectionStart");
	gameEventsVftbl.SectionStats = NULLSUB_LAMBDA_LOG("GameEvents::vftable::SectionStats");
	gameEventsVftbl.SessionSizeUpdate = NULLSUB_LAMBDA_LOG("GameEvents::vftable::SessionSizeUpdate");
	gameEventsVftbl.SizeIsEverything = NULLSUB_LAMBDA_LOG("GameEvents::vftable::SizeIsEverything");
	gameEventsVftbl.SkeetShooter = NULLSUB_LAMBDA_LOG("GameEvents::vftable::SkeetShooter");
	gameEventsVftbl.SkullClaimed = NULLSUB_LAMBDA_LOG("GameEvents::vftable::SkullClaimed");
	gameEventsVftbl.SoloMissionCompleted = NULLSUB_LAMBDA_LOG("GameEvents::vftable::SoloMissionCompleted");
	gameEventsVftbl.SoloSpartanOpsMissionCompleted = NULLSUB_LAMBDA_LOG("GameEvents::vftable::SoloSpartanOpsMissionCompleted");
	gameEventsVftbl.SpartanOpsMissionCompleted = NULLSUB_LAMBDA_LOG("GameEvents::vftable::SpartanOpsMissionCompleted");
	gameEventsVftbl.Supercombine = NULLSUB_LAMBDA_LOG("GameEvents::vftable::Supercombine");
	gameEventsVftbl.SurvivalSpace = NULLSUB_LAMBDA_LOG("GameEvents::vftable::SurvivalSpace");
	gameEventsVftbl.TerminalFound = NULLSUB_LAMBDA_LOG("GameEvents::vftable::TerminalFound");
	gameEventsVftbl.TerminalId = NULLSUB_LAMBDA_LOG("GameEvents::vftable::TerminalId");
	gameEventsVftbl.TicketsEarned = NULLSUB_LAMBDA_LOG("GameEvents::vftable::TicketsEarned");
	gameEventsVftbl.TitleCompleted = NULLSUB_LAMBDA_LOG("GameEvents::vftable::TitleCompleted");
	gameEventsVftbl.TitleLaunched = NULLSUB_LAMBDA_LOG("GameEvents::vftable::TitleLaunched");
	gameEventsVftbl.ValhallaSign = NULLSUB_LAMBDA_LOG("GameEvents::vftable::ValhallaSign");
	gameEventsVftbl.ViewOffer = NULLSUB_LAMBDA_LOG("GameEvents::vftable::ViewOffer");
	gameEventsVftbl.VIPStatusEarned = NULLSUB_LAMBDA_LOG("GameEvents::vftable::VIPStatusEarned");
	gameEventsVftbl.WhatAboutTanksDestroyed = NULLSUB_LAMBDA_LOG("GameEvents::vftable::WhatAboutTanksDestroyed");
	gameEventsVftbl.WonWarGame = NULLSUB_LAMBDA_LOG("GameEvents::vftable::WonWarGame");
	gameEventsVftbl.ZanzibarSign = NULLSUB_LAMBDA_LOG("GameEvents::vftable::ZanzibarSign");
	gameEventsVftbl.EnemyDefeated_0 = NULLSUB_LAMBDA_LOG("GameEvents::vftable::EnemyDefeated_0");
	gameEventsVftbl.Member127 = NULLSUB_LAMBDA_LOG("GameEvents::vftable[127]");
	gameEventsVftbl.Member128 = NULLSUB_LAMBDA_LOG("GameEvents::vftable[128]");
	gameEventsVftbl.Member129 = NULLSUB_LAMBDA_LOG("GameEvents::vftable[129]");
	gameEventsVftbl.Member130 = NULLSUB_LAMBDA_LOG("GameEvents::vftable[130]");
	gameEventsVftbl.Member131 = NULLSUB_LAMBDA_LOG("GameEvents::vftable[131]");
	gameEventsVftbl.Member132 = NULLSUB_LAMBDA_LOG("GameEvents::vftable[132]");
	gameEventsVftbl.Member133 = [](GameEvents*, _QWORD) { WriteLineVerbose("GameEvents::vftable[133]"); return __int64(0); };
	gameEventsVftbl.Member134 = NULLSUB_LAMBDA_LOG("GameEvents::vftable[134]");
	gameEventsVftbl.GetGuid = GetGuid;
	gameEventsVftbl.Member136 = NULLSUB_LAMBDA_LOG("GameEvents::vftable[136]");
	gameEventsVftbl.Member137 = NULLSUB_LAMBDA_LOG("GameEvents::vftable[137]");
	gameEventsVftbl.Member138 = NULLSUB_LAMBDA_LOG("GameEvents::vftable[138]");
}

void load_haloreach_dll()
{
	HaloReach = LoadLibraryA("haloreach.dll");
	if (HaloReach == nullptr)
	{
		WriteLineVerbose("Failed to load haloreach.dll");
	}
	assert(HaloReach);
	WriteLineVerbose("haloreach.dll: 0x%p", HaloReach);

	CreateGameEngine = (CreateGameEngineFunc*)GetProcAddress(HaloReach, "CreateGameEngine");
	CreateDataAccess = (CreateDataAccessFunc*)GetProcAddress(HaloReach, "CreateDataAccess");

	SetLibrarySettings = (SetLibrarySettingsFunc*)GetProcAddress(HaloReach, "SetLibrarySettings");
}

FunctionHook<HaloGameID::HaloReach_2019_Aug_20, 0x180021810, char __fastcall (char*, int, s_game_variant*)> sub_180021810 = [](char* file_data, int file_length, s_game_variant* game_variant)
{
	return sub_180021810(file_data, file_length, game_variant);
};

size_t get_file_size(FILE* pFile)
{
	assert(pFile);
	fseek(pFile, 0, SEEK_END);
	size_t variantSize = ftell(pFile);
	fseek(pFile, 0L, SEEK_SET);
	return variantSize;
}

void read_file_to_buffer(FILE* pFile, char* pBuffer, size_t length)
{
	assert(pFile);
	fseek(pFile, 0L, SEEK_SET);

	size_t totalBytesRead = 0;
	do
	{
		size_t bytesToRead = length - totalBytesRead;
		fseek(pFile, static_cast<long>(totalBytesRead), SEEK_SET);
		size_t bytesRead = fread(pBuffer + totalBytesRead, 1, bytesToRead, pFile);;
		totalBytesRead += bytesRead;
	} while (totalBytesRead < length);

}

void load_hopper_map_variant(const char* pHopperGameVariantName, s_map_variant& out_map_variant)
{
	char pFilename[MAX_PATH] = {};
	sprintf(pFilename, "hopper_map_variants\\%s", pHopperGameVariantName);
	pFilename[MAX_PATH - 1] = 0;

	FILE* pVariantFile = fopen(pFilename, "rb");
	if (pVariantFile)
	{
		size_t variantSize = get_file_size(pVariantFile);
		char* pVariantBuffer = (char*)alloca(variantSize);
		memset(pVariantBuffer, 0x00, variantSize);
		read_file_to_buffer(pVariantFile, pVariantBuffer, variantSize);
		fclose(pVariantFile);

		__int64 result = pHaloReachDataAccess->CreateMapVariantFromFile(pVariantBuffer, static_cast<int>(variantSize));

		// #TODO: MCC STRUCTURE FOR THIS
		// #TODO: First 8 bytes appear to be a pointer to something in base game
		s_map_variant* variant = (s_map_variant*)(result + 8);

		out_map_variant = *variant;
	}
}

void load_hopper_game_variant(const char* pHopperGameVariantName, s_game_variant& out_game_variant)
{
	char pFilename[MAX_PATH] = {};
	sprintf(pFilename, "hopper_game_variants\\%s.bin", pHopperGameVariantName);
	pFilename[MAX_PATH - 1] = 0;

	FILE* pVariantFile = fopen(pFilename, "rb");
	if (pVariantFile)
	{
		size_t variantSize = get_file_size(pVariantFile);
		char* pVariantBuffer = (char*)alloca(variantSize);
		memset(pVariantBuffer, 0x00, variantSize);
		read_file_to_buffer(pVariantFile, pVariantBuffer, variantSize);
		fclose(pVariantFile);

		__int64 result = pHaloReachDataAccess->CreateGameVariantFromFile(pVariantBuffer, static_cast<int>(variantSize));

		// #TODO: MCC STRUCTURE FOR THIS
		// #TODO: First 8 bytes appear to be a pointer to something in base game
		s_game_variant* variant = (s_game_variant*)(result + 8);

		out_game_variant = *variant;
	}
}

/*
void load_previous_gamestate(const char* pFilename, s_game_launch_data& game_launch_data)
{
	if (FILE * pGameStateFile = fopen(pFilename, "r"))
	{
		static s_game_state_header game_state_header = {};
		fread(&game_state_header, 1, sizeof(s_game_state_header), pGameStateFile);
		fclose(pGameStateFile);

		game_launch_data.pGameStateHeader = reinterpret_cast<uint8_t*>(&game_state_header);
		game_launch_data.GameStateHeaderSize = sizeof(s_game_state_header);
	}
}
*/

void load_previous_gamestate(const char* pFilename, s_game_launch_data& game_launch_data)
{
	FILE* pGameStateFile = fopen(pFilename, "rb");
	if (pGameStateFile)
	{
		size_t gameStateSize = get_file_size(pGameStateFile);
		char* pGameStateBuffer = (char*)alloca(gameStateSize);
		memset(pGameStateBuffer, 0x00, gameStateSize);
		read_file_to_buffer(pGameStateFile, pGameStateBuffer, gameStateSize);
		fclose(pGameStateFile);

		game_launch_data.pGameStateHeader = reinterpret_cast<uint8_t*>(&pGameStateBuffer);
		game_launch_data.GameStateHeaderSize = gameStateSize;
	}
}

s_game_launch_data game_launch_data = s_game_launch_data();

void initialize_custom_halo_reach_stuff()
{
	load_haloreach_dll();
	setup_game_events();
	setup_game_engine_host_callback();

	IGameEngineHost::g_enableGameEngineHostOverride = true;
	g_useCustomGameWindow = true;
	init_haloreach_hooks();

	__int64 createGameEngineResult = CreateGameEngine(&pHaloReachEngine);
	assert(pHaloReachEngine);
	__int64 createDataAccessResult = CreateDataAccess(&pHaloReachDataAccess);
	assert(pHaloReachDataAccess);

	game_launch_data = s_game_launch_data();


	memset(&game_launch_data.PartyData, 0, sizeof(game_launch_data.PartyData));

	uint64_t SquadID = 0x2F385E2E95D4F33E;
	uint64_t HostId = 0x7F7F86B0EE577202;
	uint64_t ClientId = 0x7F7Faf4521cdad53;

	game_launch_data.PartyData.SquadId = SquadID; // this is set

	game_launch_data.PartyData.IsHost = strstr(GetCommandLineA(), "-host"); // if client, is false

	int localhost = inet_addr("127.0.0.1");
	if (game_launch_data.PartyData.IsHost)
	{
		IGameEngineHost::CreateServerConnection();

		SetConsoleTitleA("Halo Reach Console | HOST");
		game_launch_data.PartyData.LocalId = HostId; // this is set
		game_launch_data.PartyData.PeerIds[0] = HostId;
		game_launch_data.PartyData.PeerIds[1] = ClientId;
		game_launch_data.PartyData.PeerCount = 2;

		game_launch_data.PartyData.PlayerIds[0] = { 0x0009000002D75AC8, 0x00000000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
		game_launch_data.PartyData.PlayerIds[1] = { 0x000901FE31A851C0, 0x00000000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };


		game_launch_data.PartyData.PlayerCount = 2;

		game_launch_data.MapId = g_LaunchMapId;
		game_launch_data.GameMode = g_LaunchGameMode;
		game_launch_data.CampaignDifficultyLevel = g_LaunchCampaignDifficultyLevel;

		load_hopper_game_variant(g_LaunchHopperGameVariant, game_launch_data.halo_reach_game_variant);
		//load_hopper_map_variant("the_cage.mvar", game_launch_data.halo_reach_map_variant);
		load_previous_gamestate("gamestate.hdr", game_launch_data);
	}
	else
	{
		IGameEngineHost::CreateClientConnection();

		game_launch_data.PartyData.LocalId = ClientId; // this is set
		game_launch_data.PartyData.HostId = HostId;
	}



	//pHaloReachEngine->InitGraphics(0, 0, 0, 0); // #TODO: Correct MCC graphics initialization
	pHaloReachEngine->InitThread(&IGameEngineHost::g_gameEngineHost, &game_launch_data);
}

void deinit_haloreach()
{
	FreeLibrary(HaloReach);
}

HICON g_icon = NULL;

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	WSADATA wsaData = {};
	// Initialize Winsock
	auto WSAStartupResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (WSAStartupResult != 0) {
		printf("WSAStartup failed with error: %d\n", WSAStartupResult);
		return 1;
	}

	g_icon = LoadIconA(GetModuleHandle(NULL), MAKEINTRESOURCEA(IDI_ICON1));
	SetProcessDPIAware();

	CustomWindow::SetOnDestroyCallback([]()
		{
			byte_183984DE4 = 1;
			g_gameManuallyKilled = true;
		}
	);

#if _DEBUG
	bool isDebug = true;
#else
	bool isDebug = false;
#endif

	if (strstr(lpCmdLine, "-hidesplash") == nullptr)
	{
		SplashScreen::Create();
		g_hideWindowOnStartup = true;
	}

	if (strstr(lpCmdLine, "-showconsole") || isDebug)
	{
		AllocConsole();
		FILE* pStdOut = freopen("CONOUT$", "w", stdout);
		assert(pStdOut);
		SetConsoleTitleA("Halo Reach Console");
	}

	if (strstr(lpCmdLine, "-waitfordebugger"))
	{
		WriteLineVerbose("Waiting for debugger to attach");
		while (!IsDebuggerPresent()) { Sleep(1); }
		WriteLineVerbose("Debugger attached");
	}

	initialize_custom_halo_reach_stuff();

	while (g_CurrentGameState != CurrentState::eFinished)
	{
		Sleep(10);
	}

#if _DEBUG
	while (g_gameManuallyKilled == false)
	{
		if (GetAsyncKeyState(VK_F11))
		{
			g_gameManuallyKilled = true;
		}
	}
#endif

	return 0;
}