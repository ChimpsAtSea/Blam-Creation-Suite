#include "orus-private-pch.h"
#include <stdio.h>

#define this _this

HMODULE HaloReach; //haloreach.dll

typedef signed __int64(__fastcall CreateGameEngineFunc)(IGameEngine** ppGameEngine);
CreateGameEngineFunc* CreateGameEngine = nullptr;

IGameEngine* pHaloReachEngine = nullptr;
__int64 buffer[1024 * 1024 * 32] = {};
__int64 buffer2[1024 * 1024 * 64] = {};


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

void init_haloreach()
{
	gameEvents.vftbl = &gameEventsVftbl;

	gameEventsVftbl.Member00 = nullsub;
	gameEventsVftbl.AshesToAshes = nullsub;
	gameEventsVftbl.Assist = nullsub;
	gameEventsVftbl.AudioLogClaimed = nullsub;
	gameEventsVftbl.Base = nullsub;
	gameEventsVftbl.Betrayal = nullsub;

	typedef __int64(__fastcall BIFactControllerSettingsFunc)(GameEvents *, unsigned __int64 *, GUID *, _QWORD, __int64, _DWORD, int, int);
	gameEventsVftbl.BIFactControllerSettings = (BIFactControllerSettingsFunc *)nullsub;

	gameEventsVftbl.BIFactDeepLinkRecieve = nullsub;

	typedef void(__fastcall BIFactDeepLinkSendFunc)(GameEvents *, _QWORD *, GUID *, _QWORD *, __int64 *);
	gameEventsVftbl.BIFactDeepLinkSend = (BIFactDeepLinkSendFunc *)nullsub;

	gameEventsVftbl.BIFactDualWield = nullsub;
	gameEventsVftbl.BIFactGameSession = nullsub;
	gameEventsVftbl.BIFactLoadout = nullsub;
	gameEventsVftbl.BIFactMatchmaking = nullsub;
	gameEventsVftbl.BIFactMatchmakingDetails = nullsub;
	gameEventsVftbl.BIFactMedia = nullsub;
	gameEventsVftbl.BirdOfPrey = nullsub;
	gameEventsVftbl.BitsAndPiecesDestroyed = nullsub;
	gameEventsVftbl.BroadcastingAssist = nullsub;
	gameEventsVftbl.BroadcastingDeath = nullsub;
	gameEventsVftbl.BroadcastingHeartbeat = nullsub;
	gameEventsVftbl.BroadcastingKill = nullsub;
	gameEventsVftbl.BroadcastingMatchEnd = nullsub;
	gameEventsVftbl.MultiplayerRoundEnd = nullsub;
	gameEventsVftbl.MultiplayerRoundStart = nullsub;
	gameEventsVftbl.BroadcastingMatchStart = nullsub;
	gameEventsVftbl.BroadcastingMedal = nullsub;
	gameEventsVftbl.BroadcastingPlayerJoined = nullsub;
	gameEventsVftbl.BroadcastingPlayerLeft = nullsub;
	gameEventsVftbl.BroadcastingPlayerSpawn = nullsub;
	gameEventsVftbl.BroadcastingPlayerSwitchedTeams = nullsub;
	gameEventsVftbl.BroadcastingScore = nullsub;

	typedef void(__fastcall BroadcastingStartFunc)(GameEvents *, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _QWORD);
	gameEventsVftbl.BroadcastingStart = (BroadcastingStartFunc *)nullsub;

	gameEventsVftbl.ChallengeCompleted = nullsub;
	gameEventsVftbl.ClassicModeSwitched = nullsub;
	gameEventsVftbl.CleverGirl = nullsub;
	gameEventsVftbl.ClueClaimed = nullsub;
	gameEventsVftbl.CompletionCount = nullsub;
	gameEventsVftbl.Customization = nullsub;
	gameEventsVftbl.DashboardContext = nullsub;
	gameEventsVftbl.Death = nullsub;
	gameEventsVftbl.DollFound = nullsub;
	gameEventsVftbl.EliteWin = nullsub;
	gameEventsVftbl.EnemyDefeated = nullsub;
	gameEventsVftbl.FriendsBestedOnHeroLeaderboard = nullsub;
	gameEventsVftbl.GameProgress = nullsub;
	gameEventsVftbl.GameVarSaved = nullsub;
	gameEventsVftbl.HelloNurse = nullsub;
	gameEventsVftbl.InGamePresence = nullsub;
	gameEventsVftbl.ISeeYou = nullsub;
	gameEventsVftbl.Joinability = nullsub;
	gameEventsVftbl.Lobby = nullsub;
	gameEventsVftbl.MainMenuPresence = nullsub;
	gameEventsVftbl.MapVarSaved = nullsub;
	gameEventsVftbl.MatchmakingHopper = nullsub;
	gameEventsVftbl.MediaUsage = nullsub;
	gameEventsVftbl.MeldOfferPresented = nullsub;
	gameEventsVftbl.MeldOfferResponded = nullsub;
	gameEventsVftbl.MeldPageAction = nullsub;
	gameEventsVftbl.MeldPageView = nullsub;
	gameEventsVftbl.MissionCompleted = nullsub;
	gameEventsVftbl.MortardomWraithsKilled = nullsub;
	gameEventsVftbl.MultiplayerGameEngine = nullsub;
	gameEventsVftbl.MultiplayerRoundEnd_0 = nullsub;
	gameEventsVftbl.MultiplayerRoundStart_0 = nullsub;
	gameEventsVftbl.NappersCaught = nullsub;
	gameEventsVftbl.NewsStoryRead = nullsub;
	gameEventsVftbl.ObjectiveEnd = nullsub;
	gameEventsVftbl.ObjectiveStart = nullsub;
	gameEventsVftbl.PageAction = nullsub;
	gameEventsVftbl.PageView = nullsub;
	gameEventsVftbl.PhantomHunter = nullsub;
	gameEventsVftbl.PigsCanFly = nullsub;
	gameEventsVftbl.PlayerCheckedInToday = nullsub;
	gameEventsVftbl.PlayerDefeated = nullsub;
	gameEventsVftbl.PlayerGameResults = nullsub;
	gameEventsVftbl.PlayerGameResultsDamageStat = nullsub;
	gameEventsVftbl.PlayerGameResultsGriefingStats = nullsub;
	gameEventsVftbl.PlayerGameResultsInterestStats = nullsub;
	gameEventsVftbl.PlayerGameResultsMedal = nullsub;
	gameEventsVftbl.PlayerSessionEnd = nullsub;
	gameEventsVftbl.PlayerSessionPause = nullsub;
	gameEventsVftbl.PlayerSessionResume = nullsub;
	gameEventsVftbl.PlayerSessionStart = nullsub;
	gameEventsVftbl.PlayerSpawned = nullsub;
	gameEventsVftbl.PlaylistCompleted = nullsub;
	gameEventsVftbl.PlaylistProgress = nullsub;
	gameEventsVftbl.RankedStatsDNFInfo = nullsub;
	gameEventsVftbl.RankedStatsOverride = nullsub;
	gameEventsVftbl.RankedStatsPenalty = nullsub;
	gameEventsVftbl.RankedStatsUpdate = nullsub;
	gameEventsVftbl.RankedUpSpartanIv = nullsub;
	gameEventsVftbl.RealtimeFlagCaptured = nullsub;
	gameEventsVftbl.RealtimeMedal = nullsub;
	gameEventsVftbl.RealtimePilotedVehicle = nullsub;
	gameEventsVftbl.RivalID = nullsub;
	gameEventsVftbl.SectionEnd = nullsub;
	gameEventsVftbl.SectionStart = nullsub;
	gameEventsVftbl.SectionStats = nullsub;
	gameEventsVftbl.SessionSizeUpdate = nullsub;
	gameEventsVftbl.SizeIsEverything = nullsub;
	gameEventsVftbl.SkeetShooter = nullsub;
	gameEventsVftbl.SkullClaimed = nullsub;
	gameEventsVftbl.SpartanOpsMissionCompleted = nullsub;
	gameEventsVftbl.TerminalFound = nullsub;
	gameEventsVftbl.TicketsEarned = nullsub;
	gameEventsVftbl.TitleCompleted = nullsub;
	gameEventsVftbl.TitleLaunched = nullsub;
	gameEventsVftbl.ValhallaSign = nullsub;
	gameEventsVftbl.ViewOffer = nullsub;
	gameEventsVftbl.VIPStatusEarned = nullsub;
	gameEventsVftbl.WhatAboutTanksDestroyed = nullsub;
	gameEventsVftbl.WonWarGame = nullsub;
	gameEventsVftbl.ZanzibarSign = nullsub;
	gameEventsVftbl.EnemyDefeated_0 = nullsub;
	gameEventsVftbl.Member114 = nullsub;
	gameEventsVftbl.Member115 = nullsub;
	gameEventsVftbl.Member116 = nullsub;
	gameEventsVftbl.Member117 = nullsub;
	gameEventsVftbl.Member118 = nullsub;
	gameEventsVftbl.Member119 = nullsub;

	typedef __int64(__fastcall Member120Func)(GameEvents *, _QWORD);
	gameEventsVftbl.Member120 = (Member120Func *)nullsub;

	gameEventsVftbl.Member121 = nullsub;
	gameEventsVftbl.GetGuid = GetGuid;
	gameEventsVftbl.Member123 = nullsub;
	gameEventsVftbl.Member124 = nullsub;
	gameEventsVftbl.Member125 = nullsub;

	HaloReach = LoadLibraryA("haloreach.dll");

	printf("0x%p", HaloReach);
	printf("0x180000000");
	assert(HaloReach);


	CreateGameEngine = (CreateGameEngineFunc*)GetProcAddress(HaloReach, "CreateGameEngine");

	__int64 result = CreateGameEngine(&pHaloReachEngine);

	if (pHaloReachEngine)
	{
		pHaloReachEngine->vftbl->init_graphics(pHaloReachEngine, 0, 0, 0, 0);
		pHaloReachEngine->vftbl->init_thread(pHaloReachEngine, &gameEvents, reinterpret_cast<long long>(buffer2));

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