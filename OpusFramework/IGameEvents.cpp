#include "opusframework-private-pch.h"

IGameEvents IGameEvents::g_gameEvents = IGameEvents();
bool IGameEvents::g_logGameEventMessages = false;

void IGameEvents::AchievementEarned() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: AchievementEarned"); } }
void IGameEvents::AshesToAshes() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: AshesToAshes"); } }
void IGameEvents::Assist() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: Assist"); } }
void IGameEvents::AudioLogClaimed() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: AudioLogClaimed"); } }
void IGameEvents::Base() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: Base"); } }
void IGameEvents::Betrayal() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: Betrayal"); } }
void IGameEvents::BIFactControllerSettings(unsigned __int64*, GUID*, _QWORD, __int64, _DWORD, int, int) { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactControllerSettings"); } }
void IGameEvents::BIFactDeepLink() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactDeepLink"); } }
void IGameEvents::BIFactDeepLinkRecieve(_QWORD*, GUID*, _QWORD*, __int64*) { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactDeepLinkRecieve"); } }
void IGameEvents::BIFactDeepLinkSend(_QWORD*, GUID*, _QWORD*, __int64*) { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactDeepLinkSend"); } }
void IGameEvents::BIFactDualWield() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactDualWield"); } }
void IGameEvents::BIFactGameSession() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactGameSession"); } }
void IGameEvents::BIFactLoadout() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactLoadout"); } }
void IGameEvents::BIFactMatchmaking() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactMatchmaking"); } }
void IGameEvents::BIFactMatchmakingDetails() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactMatchmakingDetails"); } }
void IGameEvents::BIFactMedia() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactMedia"); } }
void IGameEvents::BirdOfPrey() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BirdOfPrey"); } }
void IGameEvents::BitsAndPiecesDestroyed() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BitsAndPiecesDestroyed"); } }
void IGameEvents::BroadcastingAssist() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingAssist"); } }
void IGameEvents::BroadcastingDeath() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingDeath"); } }
void IGameEvents::BroadcastingHeartbeat() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingHeartbeat"); } }
void IGameEvents::BroadcastingKill() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingKill"); } }
void IGameEvents::BroadcastingMatchEnd() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingMatchEnd"); } }
void IGameEvents::MultiplayerRoundEnd_0() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MultiplayerRoundEnd_0"); } }
void IGameEvents::MultiplayerRoundStart_0() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MultiplayerRoundStart_0"); } }
void IGameEvents::BroadcastingMatchStart() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingMatchStart"); } }
void IGameEvents::BroadcastingMedal() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingMedal"); } }
void IGameEvents::BroadcastingPlayerJoined() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingPlayerJoined"); } }
void IGameEvents::BroadcastingPlayerLeft() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingPlayerLeft"); } }
void IGameEvents::BroadcastingPlayerSpawn() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingPlayerSpawn"); } }
void IGameEvents::BroadcastingPlayerSwitchedTeams() { if (g_logGameEventMessages) { /*WriteLineVerbose("GameEvent: BroadcastingPlayerSwitchedTeams"); // spams console*/ } }
void IGameEvents::BroadcastingScore() { if (g_logGameEventMessages) { /*WriteLineVerbose("GameEvent: BroadcastingScore"); // spams console*/ } }
void IGameEvents::BroadcastingStart(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _QWORD) { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingStart"); } }
void IGameEvents::CampaignDifficulty() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: CampaignDifficulty"); } }
void IGameEvents::ChallengeCompleted() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: ChallengeCompleted"); } }
void IGameEvents::ClassicModeSwitched() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: ClassicModeSwitched"); } }
void IGameEvents::CleverGirl() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: CleverGirl"); } }
void IGameEvents::ClueClaimed() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: ClueClaimed"); } }
void IGameEvents::CoopMissionCompleted() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: CoopMissionCompleted"); } }
void IGameEvents::CoopSpartanOpsMissionCompleted() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: CoopSpartanOpsMissionCompleted"); } }
void IGameEvents::CompletionCount() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: CompletionCount"); } }
void IGameEvents::Customization() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: Customization"); } }
void IGameEvents::DashboardContext() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: DashboardContext"); } }
void IGameEvents::Death() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: Death"); } }
void IGameEvents::DollFound() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: DollFound"); } }
void IGameEvents::EliteWin() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: EliteWin"); } }
void IGameEvents::Emblem() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: Emblem"); } }
void IGameEvents::EnemyDefeated() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: EnemyDefeated"); } }
void IGameEvents::FriendsBestedOnHeroLeaderboard() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: FriendsBestedOnHeroLeaderboard"); } }
void IGameEvents::GameProgress() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: GameProgress"); } }
void IGameEvents::GameVarSaved() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: GameVarSaved"); } }
void IGameEvents::GrenadeStick() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: GrenadeStick"); } }
void IGameEvents::HelloNurse() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: HelloNurse"); } }
void IGameEvents::InGamePresence() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: InGamePresence"); } }
void IGameEvents::ISeeYou() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: ISeeYou"); } }
void IGameEvents::Joinability() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: Joinability"); } }
void IGameEvents::Lobby() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: Lobby"); } }
void IGameEvents::MainMenuPresence() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MainMenuPresence"); } }
void IGameEvents::MapVarSaved() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MapVarSaved"); } }
void IGameEvents::MatchmakingHopper() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MatchmakingHopper"); } }
void IGameEvents::MediaUsage() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MediaUsage"); } }
void IGameEvents::MeldOfferPresented() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MeldOfferPresented"); } }
void IGameEvents::MeldOfferResponded() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MeldOfferResponded"); } }
void IGameEvents::MeldPageAction() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MeldPageAction"); } }
void IGameEvents::MeldPageView() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MeldPageView"); } }
void IGameEvents::MissionCompleted() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MissionCompleted"); } }
void IGameEvents::MortardomWraithsKilled() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MortardomWraithsKilled"); } }
void IGameEvents::MultiplayerGameEngine() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MultiplayerGameEngine"); } }
void IGameEvents::MultiplayerMap() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MultiplayerMap"); } }
void IGameEvents::MultiplayerRoundEnd() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MultiplayerRoundEnd"); } }
void IGameEvents::MultiplayerRoundStart() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MultiplayerRoundStart"); } }
void IGameEvents::NappersCaught() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: NappersCaught"); } }
void IGameEvents::NewsStoryRead() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: NewsStoryRead"); } }
void IGameEvents::ObjectiveEnd() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: ObjectiveEnd"); } }
void IGameEvents::ObjectiveStart() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: ObjectiveStart"); } }
void IGameEvents::PageAction() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PageAction"); } }
void IGameEvents::PageView() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PageView"); } }
void IGameEvents::PhantomHunter() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PhantomHunter"); } }
void IGameEvents::PigsCanFly() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PigsCanFly"); } }
void IGameEvents::PlayerCheckedInToday() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerCheckedInToday"); } }
void IGameEvents::PlayerDefeated() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerDefeated"); } }
void IGameEvents::PlayerGameResults() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerGameResults"); } }
void IGameEvents::PlayerGameResultsDamageStat() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerGameResultsDamageStat"); } }
void IGameEvents::PlayerGameResultsGriefingStat() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerGameResultsGriefingStat"); } }
void IGameEvents::PlayerGameResultsGriefingStats() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerGameResultsGriefingStats"); } }
void IGameEvents::PlayerGameResultsInterestStats() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerGameResultsInterestStats"); } }
void IGameEvents::PlayerGameResultsMedal() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerGameResultsMedal"); } }
void IGameEvents::PlayerSessionEnd() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerSessionEnd"); } }
void IGameEvents::PlayerSessionPause() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerSessionPause"); } }
void IGameEvents::PlayerSessionResume() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerSessionResume"); } }
void IGameEvents::PlayerSessionStart() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerSessionStart"); } }
void IGameEvents::PlayerSpawned() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerSpawned"); } }
void IGameEvents::PlaylistCompleted() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlaylistCompleted"); } }
void IGameEvents::PlaylistProgress() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlaylistProgress"); } }
void IGameEvents::RankedStatsDNFInfo() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: RankedStatsDNFInfo"); } }
void IGameEvents::RankedStatsOverride() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: RankedStatsOverride"); } }
void IGameEvents::RankedStatsPenalty() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: RankedStatsPenalty"); } }
void IGameEvents::RankedStatsUpdate() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: RankedStatsUpdate"); } }
void IGameEvents::RankedUpSpartanIv() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: RankedUpSpartanIv"); } }
void IGameEvents::RealtimeFlagCaptured() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: RealtimeFlagCaptured"); } }
void IGameEvents::RealtimeMedal() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: RealtimeMedal"); } }
void IGameEvents::RealtimePilotedVehicle() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: RealtimePilotedVehicle"); } }
void IGameEvents::RivalID() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: RivalID"); } }
void IGameEvents::SectionEnd() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SectionEnd"); } }
void IGameEvents::SectionStart() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SectionStart"); } }
void IGameEvents::SectionStats() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SectionStats"); } }
void IGameEvents::SessionSizeUpdate() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SessionSizeUpdate"); } }
void IGameEvents::SizeIsEverything() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SizeIsEverything"); } }
void IGameEvents::SkeetShooter() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SkeetShooter"); } }
void IGameEvents::SkullClaimed() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SkullClaimed"); } }
void IGameEvents::SoloMissionCompleted() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SoloMissionCompleted"); } }
void IGameEvents::SoloSpartanOpsMissionCompleted() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SoloSpartanOpsMissionCompleted"); } }
void IGameEvents::SpartanOpsMissionCompleted() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SpartanOpsMissionCompleted"); } }
void IGameEvents::Supercombine() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: Supercombine"); } }
void IGameEvents::SurvivalSpace() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SurvivalSpace"); } }
void IGameEvents::TerminalFound() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: TerminalFound"); } }
void IGameEvents::TerminalId() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: TerminalId"); } }
void IGameEvents::TicketsEarned() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: TicketsEarned"); } }
void IGameEvents::TitleCompleted() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: TitleCompleted"); } }
void IGameEvents::TitleLaunched() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: TitleLaunched"); } }
void IGameEvents::ValhallaSign() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: ValhallaSign"); } }
void IGameEvents::ViewOffer() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: ViewOffer"); } }
void IGameEvents::VIPStatusEarned() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: VIPStatusEarned"); } }
void IGameEvents::WhatAboutTanksDestroyed() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: WhatAboutTanksDestroyed"); } }
void IGameEvents::WonWarGame() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: WonWarGame"); } }
void IGameEvents::ZanzibarSign() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: ZanzibarSign"); } }
void IGameEvents::FirefightGameResults() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: FirefightGameResults"); } }
void IGameEvents::EnemyDefeated_0() { if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: EnemyDefeated_0"); } }
void IGameEvents::Member128() { if (g_logGameEventMessages) { WriteLineVerbose("IGameEvents::Member128"); } }
void IGameEvents::Member129() { if (g_logGameEventMessages) { WriteLineVerbose("IGameEvents::Member129"); } }
void IGameEvents::Member130() { if (g_logGameEventMessages) { WriteLineVerbose("IGameEvents::Member130"); } }
void IGameEvents::Member131() { if (g_logGameEventMessages) { WriteLineVerbose("IGameEvents::Member131"); } }
void IGameEvents::Member132() { if (g_logGameEventMessages) { /*WriteLineVerbose("IGameEvents::Member132"); // spams console*/ } }
void IGameEvents::Member133() { if (g_logGameEventMessages) { /*WriteLineVerbose("IGameEvents::Member133"); // spams console*/ } }
__int64 IGameEvents::Member134(_QWORD)
{
	if (g_logGameEventMessages) 
	{
		WriteLineVerbose("IGameEvents::Member134");
	}
	return __int64(0);
}

void IGameEvents::Member135() { if (g_logGameEventMessages) { WriteLineVerbose("IGameEvents::Member135"); } }

GUID* __fastcall IGameEvents::GetGuid(GUID* pGuid)
{
	//if (pGuid)
	//{
	//	*pGuid = guid;
	//}
	return &guid;
}

void IGameEvents::Member137() { if (g_logGameEventMessages) { WriteLineVerbose("IGameEvents::Member137"); } }
void IGameEvents::Member138() { if (g_logGameEventMessages) { WriteLineVerbose("IGameEvents::Member138"); } }
void IGameEvents::Member139() { if (g_logGameEventMessages) { WriteLineVerbose("IGameEvents::Member139"); } }

