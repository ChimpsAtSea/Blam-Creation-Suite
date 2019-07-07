#include "orus-private-pch.h"
#include <stdio.h>
#include "detour_helpers.h"
#include <thread>

#define this _this

HMODULE HaloReach; //haloreach.dll

typedef signed __int64(__fastcall CreateGameEngineFunc)(IGameEngine** ppGameEngine);
CreateGameEngineFunc* CreateGameEngine = nullptr;

IGameEngine* pHaloReachEngine = nullptr;
__int64 buffer[1024 * 1024 * 32] = {};
__int64 buffer2[1024 * 1024 * 64] = {};


GameEngineHostCallback gameEngineHostCallback;
GameEngineHostCallback_vftbl gameEngineHostCallbackVftbl;
GameEvents gameEvents;
GameEvents_vftbl gameEventsVftbl;

void nullsub()
{

}

GUID* __fastcall GetGuid(GameEvents* this, GUID* rGuid)
{
	GUID* result; // rax

	result = rGuid;
	*rGuid = this->guid;
	return result;
}

#define NULLSUB_LAMBDA_CUSTOM(message) []() { printf(message"\n"); }

#define WriteLineVerbose(str, ...) printf(str, ##__VA_ARGS__); printf("\n");
#define WriteVerbose(str, ...) printf(str, ##__VA_ARGS__);

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
	gameEngineHostCallbackVftbl.Member10 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[10]");
	gameEngineHostCallbackVftbl.Member11 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[11]");
	gameEngineHostCallbackVftbl.Member12 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[12]");
	gameEngineHostCallbackVftbl.Member13 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[13]");
	gameEngineHostCallbackVftbl.Member14 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[14]");
	gameEngineHostCallbackVftbl.Member15 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[15]");
	gameEngineHostCallbackVftbl.Member16 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[16]");
	gameEngineHostCallbackVftbl.Member17 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[17]");
	gameEngineHostCallbackVftbl.Member18 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[18]");
	gameEngineHostCallbackVftbl.Member19 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[19]");
	gameEngineHostCallbackVftbl.Member20 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[20]");
	gameEngineHostCallbackVftbl.Member21 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[21]");
	gameEngineHostCallbackVftbl.Member22 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[22]");
	gameEngineHostCallbackVftbl.Member23 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[23]");
	gameEngineHostCallbackVftbl.Member24 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[24]");
	gameEngineHostCallbackVftbl.Member25 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[25]");
	gameEngineHostCallbackVftbl.Member26 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[26]");
	gameEngineHostCallbackVftbl.Member27 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[27]");
	gameEngineHostCallbackVftbl.Member28 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[28]");
	gameEngineHostCallbackVftbl.Member29 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[29]");
	gameEngineHostCallbackVftbl.Member30 = NULLSUB_LAMBDA_CUSTOM("GameEngineHostCallback::vftable[30]");
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

	gameEventsVftbl.Member00 = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable[0]");
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



typedef void(*rasterizer_initialize_func)();
rasterizer_initialize_func rasterizer_initialize = nullptr;
void rasterizer_initialize_hook()
{
	printf("Calling rasterizer_initialize\n");
	rasterizer_initialize();
}
void create_rasterizer_initialize_hook()
{
	// Find the function address
	const char* const pBaseAddress = reinterpret_cast<char*>(HaloReach);
	const char* const pFunctionAddress = pBaseAddress + (0x1806C18A0 - 0x180000000);

	rasterizer_initialize = (rasterizer_initialize_func)(pFunctionAddress);

	PVOID* ppPointer = reinterpret_cast<void**>(&rasterizer_initialize);
	PVOID pDetour = reinterpret_cast<void*>(::rasterizer_initialize_hook);
	LONG detourAttachResult = DetourAttach(ppPointer, pDetour);

	if (detourAttachResult)
	{
		const char* detourAttachResultStr = GetDetourResultStr(detourAttachResult);
		WriteLineVerbose("Failed to hook rasterizer_initialize. Reason: %s", detourAttachResultStr);
	}
	else
	{
		WriteLineVerbose("Successfully hooked rasterizer_initialize");
	}
}

typedef char(*create_device_func)();
create_device_func create_device = nullptr;
char create_device_hook()
{
	printf("Calling create_device\n");
	return create_device();
}
void create_create_device_hook()
{
	// Find the function address
	const char* const pBaseAddress = reinterpret_cast<char*>(HaloReach);
	const char* const pFunctionAddress = pBaseAddress + (0x1806C2C30 - 0x180000000);

	create_device = (create_device_func)(pFunctionAddress);

	PVOID* ppPointer = reinterpret_cast<void**>(&create_device);
	PVOID pDetour = reinterpret_cast<void*>(::create_device_hook);
	LONG detourAttachResult = DetourAttach(ppPointer, pDetour);

	if (detourAttachResult)
	{
		const char* detourAttachResultStr = GetDetourResultStr(detourAttachResult);
		WriteLineVerbose("Failed to hook create_device. Reason: %s", detourAttachResultStr);
	}
	else
	{
		WriteLineVerbose("Successfully hooked create_device");
	}
}

typedef HWND(*create_window_func)();
create_window_func create_window = nullptr;
HWND create_window_hook()
{
	char* const pBaseAddress = reinterpret_cast<char*>(HaloReach);
	GameEngineHostCallback*& pGameEngineHostCallback = *reinterpret_cast<GameEngineHostCallback * *>(pBaseAddress + (0x1810EC5C0 - 0x180000000));
	HWND& g_windowHWND = *reinterpret_cast<HWND*>(pBaseAddress + (0x1810EC5D8 - 0x180000000));

	auto before = pGameEngineHostCallback;
	pGameEngineHostCallback = nullptr;

	printf("Calling create_window\n");
	HWND hwnd = create_window();

	pGameEngineHostCallback = before;

	ShowWindow(hwnd, SW_SHOW);
	return hwnd;
}

void create_create_window_hook()
{
	// Find the function address
	const char* const pBaseAddress = reinterpret_cast<char*>(HaloReach);
	const char* const pFunctionAddress = pBaseAddress + (0x1806C2890 - 0x180000000);

	create_window = (create_window_func)(pFunctionAddress);

	PVOID* ppPointer = reinterpret_cast<void**>(&create_window);
	PVOID pDetour = reinterpret_cast<void*>(::create_window_hook);
	LONG detourAttachResult = DetourAttach(ppPointer, pDetour);

	if (detourAttachResult)
	{
		const char* detourAttachResultStr = GetDetourResultStr(detourAttachResult);
		WriteLineVerbose("Failed to hook create_window. Reason: %s", detourAttachResultStr);
	}
	else
	{
		WriteLineVerbose("Successfully hooked create_window");
	}
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

typedef ATOM(WINAPI* RegisterClassExA_Func)(_In_ CONST WNDCLASSEXA*);
RegisterClassExA_Func RegisterClassExA_Original = nullptr;
ATOM WINAPI RegisterClassExA_Hook(_In_ WNDCLASSEXA* arg)
{
	assert(arg->cbSize == sizeof(WNDCLASSEXA));

	arg->cbSize = sizeof(WNDCLASSEXA);
	arg->style = CS_HREDRAW | CS_VREDRAW;
	arg->lpfnWndProc = WndProc;
	arg->cbClsExtra = 0;
	arg->cbWndExtra = 0;
	arg->hInstance = HaloReach;

	memcpy((char*)arg->lpszClassName, "HaloReach", sizeof("HaloReach"));

	//arg->lpszClassName = "HaloReach";

	return RegisterClassExA_Original(arg);
}

void create_RegisterClassExA_hook()
{
	// Find the function address
	HMODULE user32 = GetModuleHandleA("USER32.dll");
	assert(user32);
	FARPROC RegisterClassExAProc = GetProcAddress(user32, "RegisterClassExA");
	assert(RegisterClassExAProc);

	RegisterClassExA_Original = (RegisterClassExA_Func)(RegisterClassExAProc);

	PVOID* ppPointer = reinterpret_cast<void**>(&RegisterClassExA_Original);
	PVOID pDetour = reinterpret_cast<void*>(::RegisterClassExA_Hook);
	LONG detourAttachResult = DetourAttach(ppPointer, pDetour);

	if (detourAttachResult)
	{
		const char* detourAttachResultStr = GetDetourResultStr(detourAttachResult);
		WriteLineVerbose("Failed to hook RegisterClassExA. Reason: %s", detourAttachResultStr);
	}
	else
	{
		WriteLineVerbose("Successfully hooked RegisterClassExA");
	}
}

std::thread windowThread;
HWND hWnd;
void process_window_events()
{
	BOOL bRet;
	MSG msg;

	while (GetMessage(&msg, hWnd, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

typedef HWND(WINAPI* CreateWindowExA_Func)(
	_In_ DWORD dwExStyle,
	_In_opt_ LPCSTR lpClassName,
	_In_opt_ LPCSTR lpWindowName,
	_In_ DWORD dwStyle,
	_In_ int X,
	_In_ int Y,
	_In_ int nWidth,
	_In_ int nHeight,
	_In_opt_ HWND hWndParent,
	_In_opt_ HMENU hMenu,
	_In_opt_ HINSTANCE hInstance,
	_In_opt_ LPVOID lpParam);
CreateWindowExA_Func CreateWindowExA_Original = nullptr;
HWND WINAPI CreateWindowExA_Hook(
	_In_ DWORD dwExStyle,
	_In_opt_ LPCSTR lpClassName,
	_In_opt_ LPCSTR lpWindowName,
	_In_ DWORD dwStyle,
	_In_ int X,
	_In_ int Y,
	_In_ int nWidth,
	_In_ int nHeight,
	_In_opt_ HWND hWndParent,
	_In_opt_ HMENU hMenu,
	_In_opt_ HINSTANCE hInstance,
	_In_opt_ LPVOID lpParam)
{
	HWND result = CreateWindowExA_Original(
		dwExStyle,
		lpClassName,
		"Halo Reach",
		dwStyle,
		X,
		Y,
		nWidth,
		nHeight,
		hWndParent,
		hMenu,
		hInstance,
		lpParam);

	hWnd = result;
	windowThread = std::thread(process_window_events);
	windowThread.detach();

	return result;
}

void create_CreateWindowExA_hook()
{
	// Find the function address
	HMODULE user32 = GetModuleHandleA("USER32.dll");
	assert(user32);
	FARPROC CreateWindowExAProc = GetProcAddress(user32, "CreateWindowExA");
	assert(CreateWindowExAProc);

	CreateWindowExA_Original = (CreateWindowExA_Func)(CreateWindowExAProc);

	PVOID* ppPointer = reinterpret_cast<void**>(&CreateWindowExA_Original);
	PVOID pDetour = reinterpret_cast<void*>(::CreateWindowExA_Hook);
	LONG detourAttachResult = DetourAttach(ppPointer, pDetour);

	if (detourAttachResult)
	{
		const char* detourAttachResultStr = GetDetourResultStr(detourAttachResult);
		WriteLineVerbose("Failed to hook CreateWindowExA. Reason: %s", detourAttachResultStr);
	}
	else
	{
		WriteLineVerbose("Successfully hooked CreateWindowExA");
	}
}

typedef __int64 (__fastcall *sub_180012B60_Func)(__int64 a1, __int64 a2);
sub_180012B60_Func sub_180012B60 = nullptr;
__int64 __fastcall sub_180012B60_Hook(__int64 a1, __int64 a2)
{
	char* const pBaseAddress = reinterpret_cast<char*>(HaloReach);
	GameEngineHostCallback*& pGameEngineHostCallback = *reinterpret_cast<GameEngineHostCallback * *>(pBaseAddress + (0x1810EC5C0 - 0x180000000));

	pGameEngineHostCallback = &gameEngineHostCallback;

	auto result = sub_180012B60(a1, a2);

	pGameEngineHostCallback = nullptr;

	return result;
}

void create_sub_180012B60_hook()
{
	// Find the function address
	const char* const pBaseAddress = reinterpret_cast<char*>(HaloReach);
	const char* const pFunctionAddress = pBaseAddress + (0x180012B60 - 0x180000000);

	sub_180012B60 = (sub_180012B60_Func)(pFunctionAddress);

	PVOID* ppPointer = reinterpret_cast<void**>(&sub_180012B60);
	PVOID pDetour = reinterpret_cast<void*>(::sub_180012B60_Hook);
	LONG detourAttachResult = DetourAttach(ppPointer, pDetour);

	if (detourAttachResult)
	{
		const char* detourAttachResultStr = GetDetourResultStr(detourAttachResult);
		WriteLineVerbose("Failed to hook sub_180012B60. Reason: %s", detourAttachResultStr);
	}
	else
	{
		WriteLineVerbose("Successfully hooked sub_180012B60");
	}
}




void init_haloreach()
{
	HaloReach = LoadLibraryA("haloreach.dll");

	printf("0x%p\n", HaloReach);
	printf("0x180000000\n");
	assert(HaloReach);

	setup_game_events();
	setup_game_engine_host_callback();

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	create_RegisterClassExA_hook();
	create_CreateWindowExA_hook();
	create_rasterizer_initialize_hook();
	create_create_device_hook();
	create_create_window_hook();
	create_sub_180012B60_hook();



	DetourTransactionCommit();

	

	

	//=========================================================
	//                  rest of function
	//=========================================================



	CreateGameEngine = (CreateGameEngineFunc*)GetProcAddress(HaloReach, "CreateGameEngine");

	__int64 result = CreateGameEngine(&pHaloReachEngine);

	if (pHaloReachEngine)
	{
		pHaloReachEngine->vftbl->init_graphics(pHaloReachEngine, 0, 0, 0, 0);
		pHaloReachEngine->vftbl->init_thread(pHaloReachEngine, nullptr, reinterpret_cast<long long>(buffer2));

	}

}

void deinit_haloreach()
{

	FreeLibrary(HaloReach);
}

int main()
{
	init_haloreach();

	while (true)
	{
		Sleep(1);
	}

	//_aligned_free(pHaloReachEngine);

	//deinit_haloreach();
}