#include "opusframework-private-pch.h"

IGameEvents IGameEvents::g_gameEvents = IGameEvents();
bool IGameEvents::g_logGameEventMessages = false;

void IGameEvents::AchievementEarned(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 AchievementId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: AchievementEarned"); }
}

void IGameEvents::AshesToAshes(wchar_t* UserId, GUID PlayerSessionId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: AshesToAshes"); }
}

void IGameEvents::Assist(wchar_t* UserId, int32 SectionId, GUID PlayerSessionId, wchar_t* MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 KillTypeId, float LocationX, float LocationY, float LocationZ, int32 EnemyWeaponId, wchar_t* HaloTitleId, int32 MapId, int32 EnemyClassId, int32 GameCategoryId, bool MatchMade)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: Assist"); }
}

void IGameEvents::AudioLogClaimed(wchar_t* UserId, GUID PlayerSessionId, int32 AudioLogId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: AudioLogClaimed"); }
}

void IGameEvents::Base(wchar_t* UserId, GUID PlayerSessionId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: Base"); }
}

void IGameEvents::Betrayal(wchar_t* UserId, int32 SectionId, GUID PlayerSessionId, wchar_t* MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 KillTypeId, float LocationX, float LocationY, float LocationZ, int32 EnemyWeaponId, wchar_t* HaloTitleId, int32 MapId, int32 EnemyClassId, int32 GameCategoryId, bool MatchMade)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: Betrayal"); }
}

void IGameEvents::BIFactControllerSettings(wchar_t* UserId, GUID PlayerSessionId, bool IsGuest, wchar_t* HaloTitleID, int32 GameCategoryID, int32 ControllerConfigurationID, bool LookInverted)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactControllerSettings"); }
}

void IGameEvents::BIFactDeepLink(wchar_t* UserId, GUID PlayerSessionId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactDeepLink"); }
}

void IGameEvents::BIFactDeepLinkRecieve(wchar_t* UserId, GUID PlayerSessionId, wchar_t* DeepLinkCorrelationID, wchar_t* DeepLinkURL)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactDeepLinkRecieve"); }
}

void IGameEvents::BIFactDeepLinkSend(wchar_t* UserId, GUID PlayerSessionId, wchar_t* DeepLinkCorrelationID, wchar_t* DeepLinkURL)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactDeepLinkSend"); }
}

void IGameEvents::BIFactDualWield(wchar_t* UserId, GUID PlayerSessionId, bool IsGuest, wchar_t* HaloTitleID, int32 GameCategoryID, int32 LeftWeaponID, int32 RightWeaponID, uint64 DualWieldTimeStamp)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactDualWield"); }
}

void IGameEvents::BIFactGameSession(wchar_t* UserId, GUID PlayerSessionId, uint64 SessionStartTimeStamp, uint64 SessionEndTimeStamp, wchar_t* HaloTitleID, uint64 SubTitleStartTimeStamp, uint64 SubTitleEndTimeStamp, int32 GameCategoryID, wchar_t* LocaleID, int32 MapID, int32 ArmorID, uint64 SkullsUsed, wchar_t* HopperID, int32 PlayerCount, bool Matchmade, int32 MatchmakingRank, double MatchmakingRating, int32 MatchmakingXP, bool Won, uint64 Score, uint64 TeamScore, int32 Standing, bool FirstPlace, int32 Kills, int32 Deaths, int32 Assists, int32 Betrayals, int32 Suicides)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactGameSession"); }
}

void IGameEvents::BIFactLoadout(wchar_t* UserId, GUID PlayerSessionId, bool IsGuest, wchar_t* HaloTitleID, int32 GameCategoryID, int32 PrimaryWeaponID, int32 SecondaryWeaponID, int32 GrenadeID, int32 ShieldID)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactLoadout"); }
}

void IGameEvents::BIFactMatchmaking(wchar_t* UserId, GUID PlayerSessionId, bool IsGuest, wchar_t* LobbyID, uint64 LobbyEntryTimeStamp, bool JoinedMatch, uint64 JoinMatchTimeStamp, int32 MatchmakingRank, double MatchmakingRating, int32 MatchmakingXP, int32 PartySize, GUID PartyID)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactMatchmaking"); }
}

void IGameEvents::BIFactMatchmakingDetails(wchar_t* UserId, GUID PlayerSessionId, int32 NumPlayersInParty, bool GSRFired, bool BecameActiveInSession, bool ConnectedToPeerGameHost, bool GameStarted, uint64 LobbyEntryTimeStamp, uint64 LobbyExitTimeStamp, int32 ExitReason, wchar_t* GameUniqiueID, bool IsArbiter, bool IsThunderheadGame, int32 NumPlayers, int32 NumPreserveSessionTicketsCreated)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactMatchmakingDetails"); }
}

void IGameEvents::BIFactMedia(wchar_t* UserId, GUID PlayerSessionId, bool IsGuest, wchar_t* HaloTitleID, uint64 MediaStartTimeStamp, bool WasSkipped, uint64 MediaSkipTimeStamp, wchar_t* MediaID)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BIFactMedia"); }
}

void IGameEvents::BirdOfPrey(wchar_t* UserId, GUID PlayerSessionId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BirdOfPrey"); }
}

void IGameEvents::BitsAndPiecesDestroyed(wchar_t* UserId, GUID PlayerSessionId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BitsAndPiecesDestroyed"); }
}

void IGameEvents::BroadcastingAssist(wchar_t* UserId, GUID PlayerSessionId, int64 TimeStamp, int32 CurrentAssists)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingAssist"); }
}

void IGameEvents::BroadcastingDeath(wchar_t* UserId, GUID PlayerSessionId, int64 TimeStamp, wchar_t* VictimXuid, uint32 VictimTeamId, wchar_t* KillerXuid, uint32 KillerTeamId, wchar_t* AssistantXuids, uint32 DamageReportingModifier, int32 StockId, int32 AttachmentIds, int32 DamageTypeId, int32 CurrentDeaths)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingDeath"); }
}

void IGameEvents::BroadcastingHeartbeat(wchar_t* UserId, GUID PlayerSessionId, int64 Heartbeat)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingHeartbeat"); }
}

void IGameEvents::BroadcastingKill(wchar_t* UserId, GUID PlayerSessionId, int64 TimeStamp, wchar_t* VictimXuid, uint32 VictimTeamId, wchar_t* KillerXuid, uint32 KillerTeamId, wchar_t* AssistantXuids, uint32 DamageReportingModifier, int32 StockId, int32 AttachmentIds, int32 DamageTypeId, int32 CurrentKills)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingKill"); }
}

void IGameEvents::BroadcastingMatchEnd(wchar_t* UserId, GUID PlayerSessionId, int64 TimeStamp)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingMatchEnd"); }
}

void IGameEvents::BroadcastingMatchRoundEnd(wchar_t* UserId, GUID PlayerSessionId, int64 TimeStamp)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingMatchRoundEnd"); }
}

void IGameEvents::BroadcastingMatchRoundStart(wchar_t* UserId, GUID PlayerSessionId, int64 TimeStamp, int32 RoundNumber)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingMatchRoundStart"); }
}

void IGameEvents::BroadcastingMatchStart(wchar_t* UserId, GUID PlayerSessionId, int64 TimeStamp, int32 MapVariantID, int32 GameVariantID, wchar_t* PlaylistID)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingMatchStart"); }
}

void IGameEvents::BroadcastingMedal(wchar_t* UserId, GUID PlayerSessionId, int64 TimeStamp, int32 MedalId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingMedal"); }
}

void IGameEvents::BroadcastingPlayerJoined(wchar_t* UserId, GUID PlayerSessionId, int64 TimeStamp, int32 TeamId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingPlayerJoined"); }
}

void IGameEvents::BroadcastingPlayerLeft(wchar_t* UserId, GUID PlayerSessionId, int64 TimeStamp)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingPlayerLeft"); }
}

void IGameEvents::BroadcastingPlayerSpawn(wchar_t* UserId, GUID PlayerSessionId, int64 TimeStamp)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingPlayerSpawn"); }
}

void IGameEvents::BroadcastingPlayerSwitchedTeams(wchar_t* UserId, GUID PlayerSessionId, int64 TimeStamp, int32 TeamId, wchar_t* WebColor)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingPlayerSwitchedTeams"); }
}

void IGameEvents::BroadcastingScore(wchar_t* UserId, GUID PlayerSessionId, int32 ControllerIndex, int64 Timestamp, int32 CurrentRoundScore, int32 CurrentTotalScore, int32 CurrentRoundTeamScore, int32 CurrentTotalTeamScore)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingScore"); }
}

void IGameEvents::BroadcastingStart(wchar_t* UserId, GUID PlayerSessionId, uint32 GameType, uint32 Map, uint32 TopPlayerRank, wchar_t* PlayerIDs, GUID MatchID, bool PlayerIsCaster, int64 MatchStartTime)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: BroadcastingStart"); }
}

void IGameEvents::CampaignDifficulty(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, wchar_t* CampaignDifficulty)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: CampaignDifficulty"); }
}

void IGameEvents::ChallengeCompleted(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 ChallengeId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: ChallengeCompleted"); }
}

void IGameEvents::ClassicModeSwitched(wchar_t* UserId, GUID PlayerSessionId, int32 MapId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: ClassicModeSwitched"); }
}

void IGameEvents::CleverGirl(wchar_t* UserId, GUID PlayerSessionId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: CleverGirl"); }
}

void IGameEvents::ClueClaimed(wchar_t* UserId, GUID PlayerSessionId, int32 ClueId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: ClueClaimed"); }
}

void IGameEvents::CoopMissionCompleted(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 MissionId, int32 MapId, int32 MissionScore, bool IronSkullUsed, bool BlackEyeSkullUsed, bool ToughLuckSkullUsed, bool CatchSkullUsed, bool CloudSkullUsed, bool FamineSkullUsed, bool ThunderstormSkullUsed, bool TiltSkullUsed, bool MythicSkullUsed, bool BlindSkullUsed, int32 DifficultyId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: CoopMissionCompleted"); }
}

void IGameEvents::CoopSpartanOpsMissionCompleted(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 MapId, int32 DifficultyId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: CoopSpartanOpsMissionCompleted"); }
}

void IGameEvents::CompletionCount(wchar_t* UserId, GUID PlayerSessionId, int32 Count)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: CompletionCount"); }
}

void IGameEvents::Customization(wchar_t* UserId, GUID PlayerSessionId, int32 Texture0, int32 Texture1, int32 Color0, int32 Color1, int32 Color2, wchar_t* ServiceId, wchar_t* ClanId, int32 AvatarId, int32 NameplateId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: Customization"); }
}

void IGameEvents::DashboardContext(wchar_t* UserId, GUID PlayerSessionId, wchar_t* DashboardContext)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: DashboardContext"); }
}

void IGameEvents::Death(wchar_t* UserId, int32 SectionId, GUID PlayerSessionId, wchar_t* MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 KillTypeId, float LocationX, float LocationY, float LocationZ, int32 EnemyWeaponId, wchar_t* HaloTitleId, int32 MapId, int32 EnemyClassId, int32 GameCategoryId, bool MatchMade, bool HeadShot)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: Death"); }
}

void IGameEvents::DollFound(wchar_t* UserId, GUID PlayerSessionId, int32 DollId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: DollFound"); }
}

void IGameEvents::EliteWin(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, bool MatchMade)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: EliteWin"); }
}

void IGameEvents::Emblem(wchar_t* UserId, GUID PlayerSessionId, int32 Texture0, int32 Texture1, int32 Color0, int32 Color1, int32 Color2)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: Emblem"); }
}

void IGameEvents::EnemyDefeated(wchar_t* UserId, int32 SectionId, GUID PlayerSessionId, wchar_t* MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 KillTypeId, float LocationX, float LocationY, float LocationZ, int32 EnemyWeaponId, wchar_t* HaloTitleId, int32 MapId, int32 EnemyClassId, int32 GameCategoryId, bool MatchMade, bool HeadShot)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: EnemyDefeated"); }
}

void IGameEvents::FriendsBestedOnHeroLeaderboard(wchar_t* UserId, GUID PlayerSessionId, int32 LeaderboardId, int32 LeaderboardRows)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: FriendsBestedOnHeroLeaderboard"); }
}

void IGameEvents::GameProgress(wchar_t* UserId, GUID PlayerSessionId, float CompletionPercent)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: GameProgress"); }
}

void IGameEvents::GameVarSaved(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 BaseGameCategory, wchar_t* GameVarName)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: GameVarSaved"); }
}

void IGameEvents::GrenadeStick(wchar_t* UserId, int32 SectionId, GUID PlayerSessionId, wchar_t* MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 KillTypeId, float LocationX, float LocationY, float LocationZ, int32 EnemyWeaponId, int32 EnemyClassId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: GrenadeStick"); }
}

void IGameEvents::HelloNurse(wchar_t* UserId, GUID PlayerSessionId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: HelloNurse"); }
}

void IGameEvents::InGamePresence(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitle, int32 CampaignDifficulty, int32 MultiplayerMap)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: InGamePresence"); }
}

void IGameEvents::ISeeYou(wchar_t* UserId, GUID PlayerSessionId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: ISeeYou"); }
}

void IGameEvents::Joinability(wchar_t* UserId, GUID PlayerSessionId, bool InGame)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: Joinability"); }
}

void IGameEvents::Lobby(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, wchar_t* Lobby)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: Lobby"); }
}

void IGameEvents::MainMenuPresence(wchar_t* UserId, GUID PlayerSessionId, wchar_t* MainMenuPresence)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MainMenuPresence"); }
}

void IGameEvents::MapVarSaved(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 BaseMapId, wchar_t* MapVarName)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MapVarSaved"); }
}

void IGameEvents::MatchmakingHopper(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, wchar_t* MatchmakingHopper)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MatchmakingHopper"); }
}

void IGameEvents::MediaUsage(wchar_t* AppSessionId, wchar_t* AppSessionStartDateTime, uint32 UserIdType, wchar_t* UserId, wchar_t* SubscriptionTierType, wchar_t* SubscriptionTier, wchar_t* MediaType, wchar_t* ProviderId, wchar_t* ProviderMediaId, wchar_t* ProviderMediaInstanceId, GUID BingId, uint64 MediaLengthMs, uint32 MediaControlAction, float PlaybackSpeed, uint64 MediaPositionMs, uint64 PlaybackDurationMs, wchar_t* AcquisitionType, wchar_t* AcquisitionContext, wchar_t* AcquisitionContextType, wchar_t* AcquisitionContextId, int32 PlaybackIsStream, int32 PlaybackIsTethered, wchar_t* MarketplaceLocation, wchar_t* ContentLocale, float TimeZoneOffset, uint32 ScreenState)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MediaUsage"); }
}

void IGameEvents::MeldOfferPresented(wchar_t* UserId, GUID PlayerSessionId, GUID OfferGuid, GUID ProductGuid, wchar_t* Page, int32 SourceTileIndex)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MeldOfferPresented"); }
}

void IGameEvents::MeldOfferResponded(wchar_t* UserId, GUID PlayerSessionId, GUID OfferGuid, GUID ProductGuid, int32 UpsellOutcome)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MeldOfferResponded"); }
}

void IGameEvents::MeldPageAction(wchar_t* UserId, GUID PlayerSessionId, int32 ActionTypeId, int32 ActionInputMethodId, wchar_t* Page, wchar_t* TemplateId, wchar_t* DestinationPage, wchar_t* Content, int32 SourceTileIndex, int32 SourceTileX, int32 SourceTileY, int32 SourceTileWidth, int32 SourceTileHeight)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MeldPageAction"); }
}

void IGameEvents::MeldPageView(wchar_t* UserId, GUID PlayerSessionId, wchar_t* Page, wchar_t* RefererPage, int32 PageTypeId, wchar_t* PageTags, wchar_t* TemplateId, wchar_t* Content, wchar_t* FilterContext, int32 FilterDirection)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MeldPageView"); }
}

void IGameEvents::MissionCompleted(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 MapId, int32 GameCategoryId, bool Coop, uint64 TimePlayedMS, uint64 DatePlayedUTC, int32 DifficultyId, uint64 MissionScore64, uint64 SkullUsedFlags, int32 NumPlayers, wchar_t* PlayerSectionStats, int32 Kills, float Multiplier, int32 Penalties, float SkullMultiplier, int32 TotalSoloMissionsComplete, int32 TotalCoopMissionsComplete)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MissionCompleted"); }
}

void IGameEvents::MortardomWraithsKilled(wchar_t* UserId, GUID PlayerSessionId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MortardomWraithsKilled"); }
}

void IGameEvents::MultiplayerGameEngine(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, wchar_t* MultiplayerGameEngine)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MultiplayerGameEngine"); }
}

void IGameEvents::MultiplayerMap(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, wchar_t* MultiplayerMap)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MultiplayerMap"); }
}

void IGameEvents::MultiplayerRoundEnd(wchar_t* UserId, GUID RoundId, int32 SectionId, GUID PlayerSessionId, wchar_t* MultiplayerCorrelationId, int32 GameplayModeId, int32 MatchTypeId, int32 DifficultyLevelId, float TimeInSeconds, int32 ExitStatusId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MultiplayerRoundEnd"); }
}

void IGameEvents::MultiplayerRoundStart(wchar_t* UserId, GUID RoundId, int32 SectionId, GUID PlayerSessionId, wchar_t* MultiplayerCorrelationId, int32 GameplayModeId, int32 MatchTypeId, int32 DifficultyLevelId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: MultiplayerRoundStart"); }
}

void IGameEvents::NappersCaught(wchar_t* UserId, GUID PlayerSessionId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: NappersCaught"); }
}

void IGameEvents::NewsStoryRead(wchar_t* UserId, GUID PlayerSessionId, wchar_t* StoryId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: NewsStoryRead"); }
}

void IGameEvents::ObjectiveEnd(wchar_t* UserId, int32 SectionId, GUID PlayerSessionId, wchar_t* MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, int32 ObjectiveId, int32 ExitStatusId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: ObjectiveEnd"); }
}

void IGameEvents::ObjectiveStart(wchar_t* UserId, int32 SectionId, GUID PlayerSessionId, wchar_t* MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, int32 ObjectiveId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: ObjectiveStart"); }
}

void IGameEvents::PageAction(wchar_t* UserId, GUID PlayerSessionId, int32 ActionTypeId, int32 ActionInputMethodId, wchar_t* Page, wchar_t* TemplateId, wchar_t* DestinationPage, wchar_t* Content)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PageAction"); }
}

void IGameEvents::PageView(wchar_t* UserId, GUID PlayerSessionId, wchar_t* Page, wchar_t* RefererPage, int32 PageTypeId, wchar_t* PageTags, wchar_t* TemplateId, wchar_t* Content)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PageView"); }
}

void IGameEvents::PhantomHunter(wchar_t* UserId, GUID PlayerSessionId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PhantomHunter"); }
}

void IGameEvents::PigsCanFly(wchar_t* UserId, GUID PlayerSessionId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PigsCanFly"); }
}

void IGameEvents::PlayerCheckedInToday(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerCheckedInToday"); }
}

void IGameEvents::PlayerDefeated(wchar_t* UserId, int32 SectionId, GUID PlayerSessionId, wchar_t* MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 EnemyWeaponId, float LocationX, float LocationY, float LocationZ)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerDefeated"); }
}

void IGameEvents::PlayerGameResults(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 GameIndex, int32 GameIndexByCategory, int32 GameIndexByTitle, int32 GameIndexByTitleCategory, int32 MapId, int32 GameCategoryId, bool MatchMade, bool Won, uint64 TimePlayedMS, uint64 DatePlayedUTC, uint64 Score64, int32 Standing, bool FirstPlace, int32 MedalCount, int32 Kills, int32 Deaths, int32 Assists, int32 HeadShots, int32 MostKillsInARow, wchar_t* CustomStat1ID, int32 CustomStat1, wchar_t* CustomStat2ID, int32 CustomStat2, wchar_t* CustomStat3ID, int32 CustomStat3, wchar_t* CustomStat4ID, int32 CustomStat4, GUID MatchId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerGameResults"); }
}

void IGameEvents::PlayerGameResultsDamageStat(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 GameIndex, int32 MapId, bool MatchMade, int32 DamageReportingType, int32 DamageStatisticType, int32 DamageCount, int32 GameCategoryId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerGameResultsDamageStat"); }
}

void IGameEvents::PlayerGameResultsGriefingStat(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 GameIndex, int32 MapId, bool MatchMade, float Betrayals, float ShieldDamage, float BodyDamage, float BetrayalPenalty, float ShieldDamagePenalty, float BodyDamagePenalty)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerGameResultsGriefingStat"); }
}

void IGameEvents::PlayerGameResultsGriefingStats(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 GameIndex, int32 MapId, bool MatchMade, float Betrayals, float ShieldDamage, float BodyDamage, float BetrayalPenalty, float ShieldDamagePenalty, float BodyDamagePenalty)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerGameResultsGriefingStats"); }
}

void IGameEvents::PlayerGameResultsInterestStats(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 GameCategoryId, int32 GameIndex, int32 MapId, bool MatchMade, int32 OrdnanceDrops, int32 OrdnanceStrikes, uint64 TimeMSDriven, int32 UnitsDriven, uint64 TimeMSPiloted, int32 UnitsPiloted, uint64 TimeMSPassenger, int32 UnitsMovedPassenger, uint64 TimeMSOnFoot, int32 UnitsMovedOnFoot, int32 DriverAssists, int32 ArmorAbilityUseJetpack, int32 ArmorAbilityUseHologram, int32 ArmorAbilityUseReflectiveShield, int32 ArmorAbilityUseActiveCamo, int32 ArmorAbilityUseThrusterPack, int32 ArmorAbilityUseAutoTurret, int32 ArmorAbilityUseXRay)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerGameResultsInterestStats"); }
}

void IGameEvents::PlayerGameResultsMedal(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 GameIndex, int32 MapId, bool MatchMade, int32 MedalType, int32 MedalCount)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerGameResultsMedal"); }
}

void IGameEvents::PlayerSessionEnd(wchar_t* UserId, GUID PlayerSessionId, wchar_t* MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, int32 ExitStatusId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerSessionEnd"); }
}

void IGameEvents::PlayerSessionPause(wchar_t* UserId, GUID PlayerSessionId, wchar_t* MultiplayerCorrelationId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerSessionPause"); }
}

void IGameEvents::PlayerSessionResume(wchar_t* UserId, GUID PlayerSessionId, wchar_t* MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerSessionResume"); }
}

void IGameEvents::PlayerSessionStart(wchar_t* UserId, GUID PlayerSessionId, wchar_t* MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerSessionStart"); }
}

void IGameEvents::PlayerSpawned(wchar_t* UserId, int32 SectionId, GUID PlayerSessionId, wchar_t* MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, float LocationX, float LocationY, float LocationZ)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlayerSpawned"); }
}

void IGameEvents::PlaylistCompleted(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, uint32 PlaylistId, uint64 Score64, uint64 TimeMS, int32 Penalties, wchar_t* MissionStats, bool IsCoop)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlaylistCompleted"); }
}

void IGameEvents::PlaylistProgress(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 PlaylistId, int32 NumMapsCompleted, uint64 Score64, bool IsCoop, int32 NumPlayers, bool ShouldPostTime, uint64 TotalPlayListTimeMS)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: PlaylistProgress"); }
}

void IGameEvents::RankedStatsDNFInfo(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HopperName, double FinishesOverStarts, int32 FinishesMinusStarts, int32 FinishesPlusPenaltiesMinusStarts, double FinishesPlusPenaltiesOverStarts)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: RankedStatsDNFInfo"); }
}

void IGameEvents::RankedStatsOverride(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HopperName, double Rating, double Variance, int32 Halo2Level, int32 Halo2XP, bool IsRanked)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: RankedStatsOverride"); }
}

void IGameEvents::RankedStatsPenalty(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HopperName, int32 NumPenaltiesApplied)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: RankedStatsPenalty"); }
}

void IGameEvents::RankedStatsUpdate(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HopperName, double Rating, double Variance, int32 Halo2Level, int32 Halo2XP, bool IsRanked, bool PenaltyApplied)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: RankedStatsUpdate"); }
}

void IGameEvents::RankedUpSpartanIv(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 SpartanIvRank, int32 SpecialisationType)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: RankedUpSpartanIv"); }
}

void IGameEvents::RealtimeFlagCaptured(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 MapId, bool MatchMade)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: RealtimeFlagCaptured"); }
}

void IGameEvents::RealtimeMedal(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 MapId, int32 GameCategoryId, int32 GameMode, bool MatchMade, int32 MedalType, int32 MedalCount)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: RealtimeMedal"); }
}

void IGameEvents::RealtimePilotedVehicle(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 MapId, bool MatchMade, int32 VehicleId, uint64 TimeMS, int32 Distance)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: RealtimePilotedVehicle"); }
}

void IGameEvents::RivalID(wchar_t* UserId, GUID PlayerSessionId, int64 RivalID)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: RivalID"); }
}

void IGameEvents::SectionEnd(wchar_t* UserId, int32 SectionId, GUID PlayerSessionId, wchar_t* MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, int32 ExitStatusId, int32 MissionId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SectionEnd"); }
}

void IGameEvents::SectionStart(wchar_t* UserId, int32 SectionId, GUID PlayerSessionId, wchar_t* MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, int32 MissionId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SectionStart"); }
}

void IGameEvents::SectionStats(wchar_t* UserId, GUID PlayerSessionId, int32 MissionId, int32 SectionId, int32 SectionOrdinal, float ScoreWithoutTimeBonus, float ScoreWithTimeBonus, float TimeInSeconds)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SectionStats"); }
}

void IGameEvents::SessionSizeUpdate(wchar_t* UserId, GUID PlayerSessionId, int32 SessionSize, int32 SessionSizeMax)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SessionSizeUpdate"); }
}

void IGameEvents::SizeIsEverything(wchar_t* UserId, GUID PlayerSessionId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SizeIsEverything"); }
}

void IGameEvents::SkeetShooter(wchar_t* UserId, GUID PlayerSessionId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SkeetShooter"); }
}

void IGameEvents::SkullClaimed(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 SkullId, int32 DifficultyId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SkullClaimed"); }
}

void IGameEvents::SoloMissionCompleted(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 MapId, int32 DifficultyId, int32 MissionScore, bool IronSkullUsed, bool BlackEyeSkullUsed, bool ToughLuckSkullUsed, bool CatchSkullUsed, bool CloudSkullUsed, bool FamineSkullUsed, bool ThunderstormSkullUsed, bool TiltSkullUsed, bool MythicSkullUsed, bool BlindSkullUsed)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SoloMissionCompleted"); }
}

void IGameEvents::SoloSpartanOpsMissionCompleted(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 MapId, int32 DifficultyId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SoloSpartanOpsMissionCompleted"); }
}

void IGameEvents::SpartanOpsMissionCompleted(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 MapId, int32 MissionId, int32 DifficultyId, bool IsCoop)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SpartanOpsMissionCompleted"); }
}

void IGameEvents::Supercombine(wchar_t* UserId, int32 SectionId, GUID PlayerSessionId, wchar_t* MultiplayerCorrelationId, int32 GameplayModeId, int32 DifficultyLevelId, GUID RoundId, int32 PlayerRoleId, int32 PlayerWeaponId, int32 EnemyRoleId, int32 KillTypeId, float LocationX, float LocationY, float LocationZ, int32 EnemyWeaponId, int32 EnemyClassId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: Supercombine"); }
}

void IGameEvents::SurvivalSpace(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, wchar_t* SurvivalSpace)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: SurvivalSpace"); }
}

void IGameEvents::TerminalFound(wchar_t* UserId, GUID PlayerSessionId, int32 TerminalId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: TerminalFound"); }
}

void IGameEvents::TerminalId(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, int32 SkullId, int32 DifficultyId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: TerminalId"); }
}

void IGameEvents::TicketsEarned(wchar_t* UserId, GUID PlayerSessionId, int32 TicketCount)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: TicketsEarned"); }
}

void IGameEvents::TitleCompleted(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: TitleCompleted"); }
}

void IGameEvents::TitleLaunched(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: TitleLaunched"); }
}

void IGameEvents::ValhallaSign(wchar_t* UserId, GUID PlayerSessionId, int32 SignId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: ValhallaSign"); }
}

void IGameEvents::ViewOffer(wchar_t* UserId, GUID PlayerSessionId, GUID OfferGuid, GUID ProductGuid)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: ViewOffer"); }
}

void IGameEvents::VIPStatusEarned(wchar_t* UserId, GUID PlayerSessionId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: VIPStatusEarned"); }
}

void IGameEvents::WhatAboutTanksDestroyed(wchar_t* UserId, GUID PlayerSessionId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: WhatAboutTanksDestroyed"); }
}

void IGameEvents::WonWarGame(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: WonWarGame"); }
}

void IGameEvents::ZanzibarSign(wchar_t* UserId, GUID PlayerSessionId, int32 SignId)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: ZanzibarSign"); }
}

void IGameEvents::FirefightGameResults(wchar_t* UserId, GUID PlayerSessionId, wchar_t* HaloTitleId, bool MatchMade, uint64 TimePlayedMS, uint32 Kills, uint32 MostKillsInARow, uint32 SetsCompleted, uint32 WavesCompleted, uint32 GeneratorsDestroyed)
{
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: FirefightGameResults"); }
}

void IGameEvents::EnemyDefeated_0()
{ 
	if (g_logGameEventMessages) { WriteLineVerbose("GameEvent: EnemyDefeated_0"); }
}
void IGameEvents::Member128() 
{ 
	if (g_logGameEventMessages) { WriteLineVerbose("IGameEvents::Member128"); }
}
void IGameEvents::Member129() 
{ 
	if (g_logGameEventMessages) { WriteLineVerbose("IGameEvents::Member129"); }
}
void IGameEvents::Member130() 
{ 
	if (g_logGameEventMessages) { WriteLineVerbose("IGameEvents::Member130"); }
}
void IGameEvents::Member131() 
{ 
	if (g_logGameEventMessages) { WriteLineVerbose("IGameEvents::Member131"); }
}
void IGameEvents::Member132() 
{ 
	if (g_logGameEventMessages) { /*WriteLineVerbose("IGameEvents::Member132"); // spams console*/ }
}
void IGameEvents::Member133() 
{ 
	if (g_logGameEventMessages) { /*WriteLineVerbose("IGameEvents::Member133"); // spams console*/ }
}
__int64 IGameEvents::Member134(_QWORD)
{
	if (g_logGameEventMessages) 
	{
		WriteLineVerbose("IGameEvents::Member134");
	}
	return __int64(0);
}

void IGameEvents::Member135() 
{ 
	if (g_logGameEventMessages) { WriteLineVerbose("IGameEvents::Member135"); } 
}

GUID* __fastcall IGameEvents::GetPlayerSessionId(GUID* pGuid)
{
	//if (pGuid)
	//{
	//	*pGuid = guid;
	//}
	return &playerSessionId;
}

void IGameEvents::Member137() 
{ 
	if (g_logGameEventMessages) { WriteLineVerbose("IGameEvents::Member137"); }
}
void IGameEvents::CheckpointSaved() 
{ 
	if (g_logGameEventMessages) { WriteLineVerbose("IGameEvents::CheckpointSaved"); }
}
void IGameEvents::Member139() 
{ 
	if (g_logGameEventMessages) { WriteLineVerbose("IGameEvents::Member139"); }
}

