#include "haloreach-private-pch.h"

#define this _this

HMODULE HaloReach; //haloreach.dll

typedef signed __int64(__fastcall CreateGameEngineFunc)(IGameEngine **ppGameEngine);
CreateGameEngineFunc *CreateGameEngine = nullptr;

IGameEngine *pHaloReachEngine = nullptr;
__int64 buffer[1024 * 1024 * 32] = {};
__int64 buffer2[1024 * 1024 * 64] = {};


#define NULLSUB_LAMBDA_CUSTOM(message) []() { printf(message"\n"); }

#define WriteLineVerbose(str, ...) printf(str, ##__VA_ARGS__); printf("\n");
#define WriteVerbose(str, ...) printf(str, ##__VA_ARGS__);

GameEngineHostCallback gameEngineHostCallback;
GameEngineHostCallback_vftbl gameEngineHostCallbackVftbl;
GameEvents gameEvents;
GameEvents_vftbl gameEventsVftbl;

GUID *__fastcall GetGuid(GameEvents *this, GUID *rGuid)
{
	GUID *result; // rax

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

	typedef void(__fastcall WriteGameStateFunc)(GameEngineHostCallback *, LPVOID, size_t);
	gameEngineHostCallbackVftbl.WriteGameState = (WriteGameStateFunc *)nullsub;

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


	typedef void(__fastcall BIFactDeepLinkSendFunc)(GameEvents *, _QWORD *, GUID *, _QWORD *, __int64 *);
	typedef void(__fastcall BroadcastingStartFunc)(GameEvents *, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _QWORD);
	typedef __int64(__fastcall BIFactControllerSettingsFunc)(GameEvents *, unsigned __int64 *, GUID *, _QWORD, __int64, _DWORD, int, int);
	typedef __int64(__fastcall Member120Func)(GameEvents *, _QWORD);

	gameEventsVftbl.Member00 = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable[0]");
	gameEventsVftbl.AshesToAshes = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::AshesToAshes");
	gameEventsVftbl.Assist = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::Assist");
	gameEventsVftbl.AudioLogClaimed = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::AudioLogClaimed");
	gameEventsVftbl.Base = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::Base");
	gameEventsVftbl.Betrayal = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::Betrayal");
	gameEventsVftbl.BIFactControllerSettings = [](GameEvents *, unsigned __int64 *, GUID *, _QWORD, __int64, _DWORD, int, int) { printf("GameEvents::vftable::BIFactControllerSettings""\n"); return __int64(0); };
	gameEventsVftbl.BIFactDeepLinkRecieve = NULLSUB_LAMBDA_CUSTOM("GameEvents::vftable::BIFactDeepLinkRecieve");
	gameEventsVftbl.BIFactDeepLinkSend = [](GameEvents *, _QWORD *, GUID *, _QWORD *, __int64 *) { printf("GameEvents::vftable::BIFactDeepLinkSend""\n"); };
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
	gameEventsVftbl.BroadcastingStart = [](GameEvents *, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _QWORD) { printf("GameEvents::vftable::BroadcastingStart""\n"); };
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
	gameEventsVftbl.Member120 = [](GameEvents *, _QWORD) { printf("GameEvents::vftable::Member120Func""\n"); return __int64(0); };
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

typedef char(*create_device_func)();
create_device_func create_device = nullptr;
char create_device_hook()
{
	printf("Calling create_device\n");
	return create_device();
}

typedef HWND(*create_window_func)();
create_window_func create_window = nullptr;
HWND create_window_hook()
{
	char *const pBaseAddress = reinterpret_cast<char *>(HaloReach);
	GameEngineHostCallback *&pGameEngineHostCallback = *reinterpret_cast<GameEngineHostCallback * *>(pBaseAddress + (0x1810EC5C0 - 0x180000000));
	HWND &g_windowHWND = *reinterpret_cast<HWND *>(pBaseAddress + (0x1810EC5D8 - 0x180000000));

	auto before = pGameEngineHostCallback;
	pGameEngineHostCallback = nullptr;

	printf("Calling create_window\n");
	HWND hwnd = create_window();

	pGameEngineHostCallback = before;

	ShowWindow(hwnd, SW_SHOW);
	return hwnd;
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

typedef ATOM(WINAPI *RegisterClassExA_Func)(_In_ CONST WNDCLASSEXA *);
RegisterClassExA_Func RegisterClassExA_Original = nullptr;
ATOM WINAPI RegisterClassExA_Hook(_In_ WNDCLASSEXA *arg)
{
	assert(arg->cbSize == sizeof(WNDCLASSEXA));

	arg->cbSize = sizeof(WNDCLASSEXA);
	arg->style = CS_HREDRAW | CS_VREDRAW;
	arg->lpfnWndProc = WndProc;
	arg->cbClsExtra = 0;
	arg->cbWndExtra = 0;
	arg->hInstance = HaloReach;

	memcpy((char *)arg->lpszClassName, "HaloReach", sizeof("HaloReach"));

	//arg->lpszClassName = "HaloReach";

	return RegisterClassExA_Original(arg);
}

std::thread windowThread;
HWND hWnd;
void process_window_events()
{
	MSG msg;

	while (GetMessage(&msg, hWnd, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

typedef HWND(WINAPI *CreateWindowExA_Func)(
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

typedef __int64(__fastcall *sub_180012B60_Func)(__int64 a1, __int64 a2);
sub_180012B60_Func sub_180012B60 = nullptr;
__int64 __fastcall sub_180012B60_Hook(__int64 a1, __int64 a2)
{
	char *const pBaseAddress = reinterpret_cast<char *>(HaloReach);
	GameEngineHostCallback *&pGameEngineHostCallback = *reinterpret_cast<GameEngineHostCallback * *>(pBaseAddress + (0x1810EC5C0 - 0x180000000));

	pGameEngineHostCallback = &gameEngineHostCallback;

	auto result = sub_180012B60(a1, a2);

	pGameEngineHostCallback = nullptr;

	return result;
}

typedef __int64 (*s_static_string_256_print_func)(char *dst, char *format, ...);
s_static_string_256_print_func s_static_string_256_print = nullptr;
char *s_static_string_256_print_hook(char *dst, char *format, ...)
{
	va_list args;
	va_start(args, format);

	//vprintf(format, args); printf("\n");
	vsnprintf(dst, 256i64, format, args);

	va_end(args);

	return dst;
}

typedef char *(*game_get_haloreach_path_func)();
game_get_haloreach_path_func game_get_haloreach_path = nullptr;
const char *game_get_haloreach_path_hook()
{
	return "";
}

enum e_scenario_type : __int32
{
	_scenario_type_none = 0x0,
	_scenario_type_campaign = 0x1,
	_scenario_type_multiplayer = 0x2,
	_scenario_type_mainmenu = 0x3,
	_scenario_type_shared = 0x4,
	_scenario_type_shared_campaign = 0x5,
	_scenario_type_unused5 = 0x6,
	_scenario_type_unused6 = 0x7,
	k_number_of_scenario_types = 0x8,
};


struct __declspec(align(4)) s_game_options
{
	e_scenario_type scenario_type;
	BYTE game_simulation[8];
	WORD frame_limit;
	WORD unknownE;
	BYTE game_instance[8];
	DWORD random_seed;
	DWORD language;
	BYTE campaign_id;
	DWORD determinism_version;
	BYTE game_variant[64516];
	DWORD map_id;
	BYTE unknownFC30[4];
	char scenario_path[260];
	BYTE unknownFE94[129];
	BYTE game_is_playtest;
	BYTE unknownFF16[18];
	DWORD campaign_difficulty;
	BYTE unknownFF2C[60368];
};


typedef __int64(__fastcall *game_options_new_func)(s_game_options *a1);
game_options_new_func game_options_new = nullptr;

typedef __int64(__fastcall *load_scenario_into_game_options_func)(s_game_options *a1);
load_scenario_into_game_options_func load_scenario_into_game_options = nullptr;
__int64 __fastcall load_scenario_into_game_options_hook(s_game_options *a1)
{
	auto result = load_scenario_into_game_options(a1);

	// TODO

	return result;
}

typedef void (*sub_18078C550_func)(__int64 a1, ...);
sub_18078C550_func sub_18078C550 = nullptr;
void sub_18078C550_hook(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	char buffer[8192] = {};
	vsnprintf(buffer, 8192, format, args);
	buffer[sizeof(buffer) - 1] = 0;

	va_end(args);

	MessageBox(hWnd, "dirty_disk_error", buffer, MB_ICONERROR);

	//return sub_18078C550(a1, );
}

typedef void (*main_status_func)(__int64 a1, ...);
main_status_func main_status = nullptr;
void main_status_hook(__int64 a1, ...)
{
	va_list args;
	va_start(args, a1);

	auto count1 = va_arg(args, __int64);
	assert(count1 == 0);

	const char *str0 = va_arg(args, const char *);

	auto count2 = va_arg(args, __int64);

	printf("status[%lli]: %s", count1, str0);

	for (int i = 0; i < count2; i++)
	{
		const char *str1 = va_arg(args, const char *);
		printf(" %s", str1);
	}
	printf("\n");

	va_end(args);
}

typedef char(__fastcall *sub_180013EA0_func)(__int64 a1, __int64 a2);
sub_180013EA0_func sub_180013EA0 = nullptr;
char __fastcall sub_180013EA0_hook(__int64 a1, __int64 a2)
{
	char *const pBaseAddress = reinterpret_cast<char *>(HaloReach);
	DWORD &dword_1810EC5A4 = *reinterpret_cast<DWORD *>(pBaseAddress + (0x1810EC5A4 - 0x180000000));
	//GameEngineHostCallback*& pGameEngineHostCallback = *reinterpret_cast<GameEngineHostCallback * *>(pBaseAddress + (0x1810EC5C0 - 0x180000000));

	//pGameEngineHostCallback = &gameEngineHostCallback;
	static DWORD previous_dword_1810EC5A4 = -1;

	if (dword_1810EC5A4 != previous_dword_1810EC5A4)
	{
		previous_dword_1810EC5A4 = dword_1810EC5A4;
		printf("dword_1810EC5A4 changed to: %d\n", dword_1810EC5A4);
	}

	auto result = sub_180013EA0(a1, a2);

	if (dword_1810EC5A4 != previous_dword_1810EC5A4)
	{
		previous_dword_1810EC5A4 = dword_1810EC5A4;
		printf("dword_1810EC5A4 changed to: %d\n", dword_1810EC5A4);
	}

	//pGameEngineHostCallback = nullptr;
	return result;
}

typedef __int64(__fastcall *cache_files_get_file_status_func)(const char *a1);
cache_files_get_file_status_func cache_files_get_file_status = nullptr;
void get_cache_files_get_file_status()
{
	// Find the function address
	const char *const pBaseAddress = reinterpret_cast<char *>(HaloReach);
	const char *const pFunctionAddress = pBaseAddress + (0x180352340 - 0x180000000);

	cache_files_get_file_status = (cache_files_get_file_status_func)(pFunctionAddress);
}

typedef __int64 (*sub_180012C30_func)();
sub_180012C30_func sub_180012C30 = nullptr;
__int64 sub_180012C30_hook()
{
#pragma warning( push )
#pragma warning( disable : 4244)


	char *const pBaseAddress = reinterpret_cast<char *>(HaloReach);

	DWORD &dword_180FAEE10 = *reinterpret_cast<DWORD *>(pBaseAddress + (0x180FAEE10 - 0x180000000));
	DWORD &dword_18342E560 = *reinterpret_cast<DWORD *>(pBaseAddress + (0x18342E560 - 0x180000000));
	QWORD &qword_183459988 = *reinterpret_cast<QWORD *>(pBaseAddress + (0x183459988 - 0x180000000));
	const char *&qword_183459998 = *reinterpret_cast<const char **>(pBaseAddress + (0x183459998 - 0x180000000));
	DWORD &global_state_dword_1810EC5A4 = *reinterpret_cast<DWORD *>(pBaseAddress + (0x1810EC5A4 - 0x180000000));

	int v0; // ebx
	__int64 result; // rax

	v0 = cache_files_get_file_status("levels\\shared\\shared\\shared");
	result = cache_files_get_file_status("levels\\shared\\shared\\campaign");
	if ((v0 - 3) <= 1 && ((result - 3) <= 1 || !result))
	{
		// dword_18342E560 = 1; // hack, goes through 2, 4, 9, 12
		if (dword_18342E560)
		{
			if (dword_18342E560 == 1)
			{
				result = 1i64;
			}
			else if (dword_18342E560 == 3)
			{
				result = 3i64;
			}
			else if (dword_18342E560 != 4 && dword_18342E560 == 5)
			{
				result = 2i64;
			}
			else
			{
				result = 4i64;
			}
		}
		else
		{
			result = 0i64;
		}
		//qword_183459998 = "maps\\m35.map";
		if (qword_183459998)
		{
			result = timeGetTime();
			dword_180FAEE10 = result;
			global_state_dword_1810EC5A4 = 3;
		}
		else
		{
			switch (result)
			{
			case 1:
				if (qword_183459988)
				{
					result = timeGetTime();
					dword_180FAEE10 = result;
					global_state_dword_1810EC5A4 = 5;
				}
				else
				{
					result = timeGetTime();
					dword_180FAEE10 = result;
					global_state_dword_1810EC5A4 = 4;
				}
				break;
			case 3:
				result = timeGetTime();
				dword_180FAEE10 = result;
				global_state_dword_1810EC5A4 = 6;
				break;
			case 2:
				result = timeGetTime();
				dword_180FAEE10 = result;
				global_state_dword_1810EC5A4 = 7;
				break;
			}
		}
	}
	return result;
#pragma warning( pop ) 
}


typedef __int64 (*sub_180012D60_func)();
sub_180012D60_func sub_180012D60 = nullptr;
__int64 sub_180012D60_hook()
{
	char *const pBaseAddress = reinterpret_cast<char *>(HaloReach);
	GameEngineHostCallback *&pGameEngineHostCallback = *reinterpret_cast<GameEngineHostCallback * *>(pBaseAddress + (0x1810EC5C0 - 0x180000000));

	pGameEngineHostCallback = &gameEngineHostCallback;

	auto result = sub_180012D60();

	pGameEngineHostCallback = nullptr;

	return result;
}

typedef __int64 (*sub_180013CD0_func)();
sub_180013CD0_func sub_180013CD0 = nullptr;
__int64 sub_180013CD0_hook()
{
	char *const pBaseAddress = reinterpret_cast<char *>(HaloReach);
	GameEngineHostCallback *&pGameEngineHostCallback = *reinterpret_cast<GameEngineHostCallback * *>(pBaseAddress + (0x1810EC5C0 - 0x180000000));

	pGameEngineHostCallback = &gameEngineHostCallback;

	auto result = sub_180013CD0();

	pGameEngineHostCallback = nullptr;

	return result;
}


typedef __int64(__fastcall *sub_180013BF0_func)(__int64 a1);
sub_180013BF0_func sub_180013BF0 = nullptr;
__int64 __fastcall sub_180013BF0_hook(__int64 a1)
{
	char *const pBaseAddress = reinterpret_cast<char *>(HaloReach);
	GameEngineHostCallback *&pGameEngineHostCallback = *reinterpret_cast<GameEngineHostCallback * *>(pBaseAddress + (0x1810EC5C0 - 0x180000000));

	pGameEngineHostCallback = &gameEngineHostCallback;

	auto result = sub_180013BF0(a1);

	pGameEngineHostCallback = nullptr;

	return result;
}

typedef char *(__fastcall *simulation_watcher_get_status_func)(uint8_t *pSimulationWatcher, char *dst);
simulation_watcher_get_status_func simulation_watcher_get_status = nullptr;
char *__fastcall simulation_watcher_get_status_hook(uint8_t *pSimulationWatcher, char *dst)
{
	auto result = simulation_watcher_get_status(pSimulationWatcher, dst);
	printf("%s\n%s\n", dst, result);
	return result;
}

void load_haloreach_dll()
{
	HaloReach = LoadLibraryA("haloreach.dll");

	printf("0x%p\n", HaloReach);
	printf("0x180000000\n");
	assert(HaloReach);
}

void init_haloreach()
{
	load_haloreach_dll();
	init_detours();

	setup_game_events();
	setup_game_engine_host_callback();

#define HaloReachDLL "HaloReach.dll", 0x180000000

	create_dll_hook("USER32.dll", "RegisterClassExA",	RegisterClassExA_Hook,	RegisterClassExA_Original);
	create_dll_hook("USER32.dll", "CreateWindowExA",	CreateWindowExA_Hook,	CreateWindowExA_Original);

	create_hook<0x180012730>(HaloReachDLL, "game_get_haloreach_path",			game_get_haloreach_path_hook,							game_get_haloreach_path);			
	create_hook<0x1806C18A0>(HaloReachDLL, "game_get_haloreach_path",			rasterizer_initialize_hook,								rasterizer_initialize);				
	create_hook<0x1806C2C30>(HaloReachDLL, "create_device",						create_device_hook,										create_device);						
	create_hook<0x1806C2890>(HaloReachDLL, "create_window",						create_window_hook,										create_window);						
	create_hook<0x180012B60>(HaloReachDLL, "sub_180012B60",						sub_180012B60_Hook,										sub_180012B60);						
	create_hook<0x180013CD0>(HaloReachDLL, "sub_180013CD0",						sub_180013CD0_hook,										sub_180013CD0);						
	create_hook<0x180012D60>(HaloReachDLL, "sub_180012D60",						sub_180012D60_hook,										sub_180012D60);						
	create_hook<0x180012C30>(HaloReachDLL, "sub_180012C30",						sub_180012C30_hook,										sub_180012C30);						
	create_hook<0x180013EA0>(HaloReachDLL, "sub_180013EA0",						sub_180013EA0_hook,										sub_180013EA0);						
	create_hook<0x1804EA850>(HaloReachDLL, "main_status",						main_status_hook,										main_status);						
	create_hook<0x18078C550>(HaloReachDLL, "sub_18078C550",						sub_18078C550_hook,										sub_18078C550);						
	create_hook<0x1803C9220>(HaloReachDLL, "load_scenario_into_game_options",	load_scenario_into_game_options_hook,					load_scenario_into_game_options);	
	create_hook<0x18004AFC0>(HaloReachDLL, "s_static_string_256_print",			s_static_string_256_print_hook,							s_static_string_256_print);			
	create_hook<0x180013BF0>(HaloReachDLL, "sub_180013BF0",						sub_180013BF0_hook,										sub_180013BF0);						
	create_hook<0x180108FB0>(HaloReachDLL, "simulation_watcher_get_status",		simulation_watcher_get_status_hook, 					simulation_watcher_get_status); // untested

	populate_function_ptr<0x18034A630>(HaloReachDLL,	game_options_new);
	populate_function_ptr<0x180352340>(HaloReachDLL,	cache_files_get_file_status);


	//=========================================================
	//                  rest of function
	//=========================================================



	CreateGameEngine = (CreateGameEngineFunc *)GetProcAddress(HaloReach, "CreateGameEngine");

	__int64 result = CreateGameEngine(&pHaloReachEngine);

	if (pHaloReachEngine)
	{
		pHaloReachEngine->InitGraphics(0, 0, 0, 0);
		pHaloReachEngine->InitThread(nullptr, reinterpret_cast<long long>(buffer2));

	}

	end_detours();
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