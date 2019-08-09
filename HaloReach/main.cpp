#include "haloreach-private-pch.h"

#define this _this


#define HaloReachDLL "HaloReach.dll"
#define HaloReachBase 0x180000000



void nullsub()
{

}

HMODULE HaloReach; //haloreach.dll

typedef errno_t(__fastcall* SetLibrarySettingsFunc)(wchar_t* Src);
SetLibrarySettingsFunc* SetLibrarySettings = nullptr;
typedef signed __int64(__fastcall CreateGameEngineFunc)(IGameEngine** ppGameEngine);
CreateGameEngineFunc* CreateGameEngine = nullptr;

IGameEngine* pHaloReachEngine = nullptr;


#define NULLSUB_LAMBDA_CUSTOM(message) []() { WriteLineVerbose(message); }



GUID* __fastcall GetGuid(GameEvents* this, GUID* rGuid)
{
	GUID* result; // rax

	result = rGuid;
	*rGuid = this->guid;
	return result;
}


void setup_game_engine_host_callback()
{
	//=========================================================
	//             game engine host callback
	//=========================================================

	gameEngineHostCallback.vftbl = &gameEngineHostCallbackVftbl;

	gameEngineHostCallbackVftbl.Member00 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[00]");
	gameEngineHostCallbackVftbl.Member01 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[01]");
	gameEngineHostCallbackVftbl.Member02 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[02]");
	gameEngineHostCallbackVftbl.Member03 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[03]");
	gameEngineHostCallbackVftbl.Member04 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[04]");

	typedef void(__fastcall WriteGameStateFunc)(GameEngineHostCallback*, LPVOID, size_t);
	gameEngineHostCallbackVftbl.WriteGameState = (WriteGameStateFunc*)nullsub;

	gameEngineHostCallbackVftbl.Member06 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[06]");
	gameEngineHostCallbackVftbl.Member07 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[07]");
	gameEngineHostCallbackVftbl.Member08 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[08]");
	gameEngineHostCallbackVftbl.Member09 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[09]");
	gameEngineHostCallbackVftbl.GetGameEvents = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::GetGameEvents");
	gameEngineHostCallbackVftbl.Member11 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[11]");
	gameEngineHostCallbackVftbl.Member12 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[12]");
	gameEngineHostCallbackVftbl.Member13 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[13]");
	gameEngineHostCallbackVftbl.Member14 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[14]");
	gameEngineHostCallbackVftbl.Member15 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[15]");
	gameEngineHostCallbackVftbl.Member16 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[16]");
	gameEngineHostCallbackVftbl.Member17 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[17]");
	gameEngineHostCallbackVftbl.Member18 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[18]");
	//gameEngineHostCallbackVftbl.Member19 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[19]");
	gameEngineHostCallbackVftbl.Member19 = [](GameEngineHostCallback* a1, __int64 a2) {
		WriteLineVerbose("GameEngineHostCallback::vftable[19] %016llx", a2);
		return __int64(0);
	};
	gameEngineHostCallbackVftbl.Member20 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[20]");
	gameEngineHostCallbackVftbl.Member21 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[21]");
	gameEngineHostCallbackVftbl.Member22 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[22]");
	gameEngineHostCallbackVftbl.Member23 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[23]");
	gameEngineHostCallbackVftbl.Member24 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[24]");
	gameEngineHostCallbackVftbl.Member25 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[25]");
	gameEngineHostCallbackVftbl.Member26 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[26]");
	gameEngineHostCallbackVftbl.Member27 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[27]");
	gameEngineHostCallbackVftbl.Member28 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[28]");
	gameEngineHostCallbackVftbl.Member29 = [](GameEngineHostCallback*, _QWORD, unsigned int ptr[74]) {
		NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[29]")();

		bool key = !!GetAsyncKeyState(VK_F3);

		for (int i = 0; i < 74; i++)
		{
			ptr[i] = i;
		}

		memset(ptr, 0, 296);
		*ptr = 1;

		static int once = 0;
		if (!once)
		{
			once = 1;
			return unsigned __int8(1);
		}
		return unsigned __int8(0);
		
	};
	gameEngineHostCallbackVftbl.SetPlayerName = []() { SetPlayerName(); };
	gameEngineHostCallbackVftbl.Member31 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[31]");
	gameEngineHostCallbackVftbl.Member32 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[32]");
	gameEngineHostCallbackVftbl.Member33 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[33]");
	gameEngineHostCallbackVftbl.Member34 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[34]");
	gameEngineHostCallbackVftbl.Member35 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[35]");
	gameEngineHostCallbackVftbl.Member36 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[36]");
	gameEngineHostCallbackVftbl.Member37 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[37]");
	gameEngineHostCallbackVftbl.Member38 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[38]");
	gameEngineHostCallbackVftbl.Member39 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[39]");
	gameEngineHostCallbackVftbl.Member40 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[40]");
	gameEngineHostCallbackVftbl.Member41 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[41]");
	gameEngineHostCallbackVftbl.Member42 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[42]");

	gameEngineHostCallback.pGameEvents = &gameEvents;
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

	gameEventsVftbl.AchievementEarned = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable[0]");
	gameEventsVftbl.AshesToAshes = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::AshesToAshes");
	gameEventsVftbl.Assist = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::Assist");
	gameEventsVftbl.AudioLogClaimed = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::AudioLogClaimed");
	gameEventsVftbl.Base = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::Base");
	gameEventsVftbl.Betrayal = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::Betrayal");
	gameEventsVftbl.BIFactControllerSettings = [](GameEvents*, unsigned __int64*, GUID*, _QWORD, __int64, _DWORD, int, int) { printf("GameEvents::vftable::BIFactControllerSettings""\n"); return __int64(0); };
	gameEventsVftbl.BIFactDeepLinkRecieve = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BIFactDeepLinkRecieve");
	gameEventsVftbl.BIFactDeepLinkSend = [](GameEvents*, _QWORD*, GUID*, _QWORD*, __int64*) { printf("GameEvents::vftable::BIFactDeepLinkSend""\n"); };
	gameEventsVftbl.BIFactDualWield = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BIFactDualWield");
	gameEventsVftbl.BIFactGameSession = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BIFactGameSession");
	gameEventsVftbl.BIFactLoadout = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BIFactLoadout");
	gameEventsVftbl.BIFactMatchmaking = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BIFactMatchmaking");
	gameEventsVftbl.BIFactMatchmakingDetails = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BIFactMatchmakingDetails");
	gameEventsVftbl.BIFactMedia = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BIFactMedia");
	gameEventsVftbl.BirdOfPrey = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BirdOfPrey");
	gameEventsVftbl.BitsAndPiecesDestroyed = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BitsAndPiecesDestroyed");
	gameEventsVftbl.BroadcastingAssist = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BroadcastingAssist");
	gameEventsVftbl.BroadcastingDeath = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BroadcastingDeath");
	gameEventsVftbl.BroadcastingHeartbeat = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BroadcastingHeartbeat");
	gameEventsVftbl.BroadcastingKill = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BroadcastingKill");
	gameEventsVftbl.BroadcastingMatchEnd = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BroadcastingMatchEnd");
	gameEventsVftbl.MultiplayerRoundEnd = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::MultiplayerRoundEnd");
	gameEventsVftbl.MultiplayerRoundStart = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::MultiplayerRoundStart");
	gameEventsVftbl.BroadcastingMatchStart = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BroadcastingMatchStart");
	gameEventsVftbl.BroadcastingMedal = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BroadcastingMedal");
	gameEventsVftbl.BroadcastingPlayerJoined = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BroadcastingPlayerJoined");
	gameEventsVftbl.BroadcastingPlayerLeft = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BroadcastingPlayerLeft");
	gameEventsVftbl.BroadcastingPlayerSpawn = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BroadcastingPlayerSpawn");
	gameEventsVftbl.BroadcastingPlayerSwitchedTeams = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BroadcastingPlayerSwitchedTeams");
	gameEventsVftbl.BroadcastingScore = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BroadcastingScore");
	gameEventsVftbl.BroadcastingStart = [](GameEvents*, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _QWORD) { printf("GameEvents::vftable::BroadcastingStart""\n"); };
	gameEventsVftbl.ChallengeCompleted = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::ChallengeCompleted");
	gameEventsVftbl.ClassicModeSwitched = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::ClassicModeSwitched");
	gameEventsVftbl.CleverGirl = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::CleverGirl");
	gameEventsVftbl.ClueClaimed = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::ClueClaimed");
	gameEventsVftbl.CompletionCount = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::CompletionCount");
	gameEventsVftbl.Customization = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::Customization");
	gameEventsVftbl.DashboardContext = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::DashboardContext");
	gameEventsVftbl.Death = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::Death");
	gameEventsVftbl.DollFound = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::DollFound");
	gameEventsVftbl.EliteWin = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::EliteWin");
	gameEventsVftbl.EnemyDefeated = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::EnemyDefeated");
	gameEventsVftbl.FriendsBestedOnHeroLeaderboard = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::FriendsBestedOnHeroLeaderboard");
	gameEventsVftbl.GameProgress = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::GameProgress");
	gameEventsVftbl.GameVarSaved = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::GameVarSaved");
	gameEventsVftbl.HelloNurse = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::HelloNurse");
	gameEventsVftbl.InGamePresence = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::InGamePresence");
	gameEventsVftbl.ISeeYou = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::ISeeYou");
	gameEventsVftbl.Joinability = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::Joinability");
	gameEventsVftbl.Lobby = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::Lobby");
	gameEventsVftbl.MainMenuPresence = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::MainMenuPresence");
	gameEventsVftbl.MapVarSaved = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::MapVarSaved");
	gameEventsVftbl.MatchmakingHopper = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::MatchmakingHopper");
	gameEventsVftbl.MediaUsage = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::MediaUsage");
	gameEventsVftbl.MeldOfferPresented = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::MeldOfferPresented");
	gameEventsVftbl.MeldOfferResponded = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::MeldOfferResponded");
	gameEventsVftbl.MeldPageAction = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::MeldPageAction");
	gameEventsVftbl.MeldPageView = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::MeldPageView");
	gameEventsVftbl.MissionCompleted = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::MissionCompleted");
	gameEventsVftbl.MortardomWraithsKilled = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::MortardomWraithsKilled");
	gameEventsVftbl.MultiplayerGameEngine = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::MultiplayerGameEngine");
	gameEventsVftbl.MultiplayerRoundEnd_0 = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::MultiplayerRoundEnd_0");
	gameEventsVftbl.MultiplayerRoundStart_0 = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::MultiplayerRoundStart_0");
	gameEventsVftbl.NappersCaught = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::NappersCaught");
	gameEventsVftbl.NewsStoryRead = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::NewsStoryRead");
	gameEventsVftbl.ObjectiveEnd = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::ObjectiveEnd");
	gameEventsVftbl.ObjectiveStart = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::ObjectiveStart");
	gameEventsVftbl.PageAction = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::PageAction");
	gameEventsVftbl.PageView = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::PageView");
	gameEventsVftbl.PhantomHunter = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::PhantomHunter");
	gameEventsVftbl.PigsCanFly = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::PigsCanFly");
	gameEventsVftbl.PlayerCheckedInToday = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::PlayerCheckedInToday");
	gameEventsVftbl.PlayerDefeated = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::PlayerDefeated");
	gameEventsVftbl.PlayerGameResults = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::PlayerGameResults");
	gameEventsVftbl.PlayerGameResultsDamageStat = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::PlayerGameResultsDamageStat");
	gameEventsVftbl.PlayerGameResultsGriefingStats = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::PlayerGameResultsGriefingStats");
	gameEventsVftbl.PlayerGameResultsInterestStats = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::PlayerGameResultsInterestStats");
	gameEventsVftbl.PlayerGameResultsMedal = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::PlayerGameResultsMedal");
	gameEventsVftbl.PlayerSessionEnd = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::PlayerSessionEnd");
	gameEventsVftbl.PlayerSessionPause = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::PlayerSessionPause");
	gameEventsVftbl.PlayerSessionResume = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::PlayerSessionResume");
	gameEventsVftbl.PlayerSessionStart = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::PlayerSessionStart");
	gameEventsVftbl.PlayerSpawned = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::PlayerSpawned");
	gameEventsVftbl.PlaylistCompleted = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::PlaylistCompleted");
	gameEventsVftbl.PlaylistProgress = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::PlaylistProgress");
	gameEventsVftbl.RankedStatsDNFInfo = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::RankedStatsDNFInfo");
	gameEventsVftbl.RankedStatsOverride = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::RankedStatsOverride");
	gameEventsVftbl.RankedStatsPenalty = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::RankedStatsPenalty");
	gameEventsVftbl.RankedStatsUpdate = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::RankedStatsUpdate");
	gameEventsVftbl.RankedUpSpartanIv = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::RankedUpSpartanIv");
	gameEventsVftbl.RealtimeFlagCaptured = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::RealtimeFlagCaptured");
	gameEventsVftbl.RealtimeMedal = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::RealtimeMedal");
	gameEventsVftbl.RealtimePilotedVehicle = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::RealtimePilotedVehicle");
	gameEventsVftbl.RivalID = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::RivalID");
	gameEventsVftbl.SectionEnd = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::SectionEnd");
	gameEventsVftbl.SectionStart = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::SectionStart");
	gameEventsVftbl.SectionStats = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::SectionStats");
	gameEventsVftbl.SessionSizeUpdate = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::SessionSizeUpdate");
	gameEventsVftbl.SizeIsEverything = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::SizeIsEverything");
	gameEventsVftbl.SkeetShooter = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::SkeetShooter");
	gameEventsVftbl.SkullClaimed = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::SkullClaimed");
	gameEventsVftbl.SpartanOpsMissionCompleted = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::SpartanOpsMissionCompleted");
	gameEventsVftbl.TerminalFound = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::TerminalFound");
	gameEventsVftbl.TicketsEarned = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::TicketsEarned");
	gameEventsVftbl.TitleCompleted = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::TitleCompleted");
	gameEventsVftbl.TitleLaunched = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::TitleLaunched");
	gameEventsVftbl.ValhallaSign = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::ValhallaSign");
	gameEventsVftbl.ViewOffer = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::ViewOffer");
	gameEventsVftbl.VIPStatusEarned = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::VIPStatusEarned");
	gameEventsVftbl.WhatAboutTanksDestroyed = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::WhatAboutTanksDestroyed");
	gameEventsVftbl.WonWarGame = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::WonWarGame");
	gameEventsVftbl.ZanzibarSign = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::ZanzibarSign");
	gameEventsVftbl.EnemyDefeated_0 = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::EnemyDefeated_0");
	gameEventsVftbl.Member114 = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable[114]");
	gameEventsVftbl.Member115 = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable[115]");
	gameEventsVftbl.Member116 = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable[116]");
	gameEventsVftbl.Member117 = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable[117]");
	gameEventsVftbl.Member118 = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable[118]");
	gameEventsVftbl.Member119 = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable[119]");
	gameEventsVftbl.Member120 = [](GameEvents*, _QWORD) { printf("GameEvents::vftable::Member120Func""\n"); return __int64(0); };
	gameEventsVftbl.Member121 = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable[121]");
	gameEventsVftbl.GetGuid = GetGuid;
	gameEventsVftbl.Member123 = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable[123]");
	gameEventsVftbl.Member124 = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable[124]");
	gameEventsVftbl.Member125 = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable[125]");
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
	SetLibrarySettings = (SetLibrarySettingsFunc*)GetProcAddress(HaloReach, "SetLibrarySettings");
}


void initialize_custom_halo_reach_stuff()
{
	load_haloreach_dll();
	setup_game_events();
	setup_game_engine_host_callback();

	useCustomGameEngineHostCallback = true;
	useCustomGameWindow = true;
	init_haloreach_hooks();

	__int64 result = CreateGameEngine(&pHaloReachEngine);
	assert(pHaloReachEngine);

	static s_game_launch_data game_launch_data = s_game_launch_data();

	if (FILE *pGameStateFile = fopen("gamestate.hdr", "r"))
	{
		s_game_state_header game_state_header = {};
		fread(&game_state_header, 1, sizeof(s_game_state_header), pGameStateFile);
		fclose(pGameStateFile);

		game_launch_data.pGameStateHeader = reinterpret_cast<uint8_t *>(&game_state_header);
		game_launch_data.GameStateHeaderSize = sizeof(s_game_state_header);
	}

	pHaloReachEngine->InitGraphics(0, 0, 0, 0);
	pHaloReachEngine->InitThread(nullptr, (__int64)& game_launch_data);
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
	g_icon = LoadIconA(GetModuleHandle(NULL), MAKEINTRESOURCEA(IDI_ICON1));
	SetProcessDPIAware();

#if _DEBUG
	bool isDebug = true;
#else
	bool isDebug = false;
#endif

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
}