#include "gameframework-private-pch.h"

IGameEvents IGameEvents::g_gameEvents = IGameEvents();
bool IGameEvents::g_logGameEventMessages = false;

void IGameEvents::EventWriteAchievementEarned(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 AchievementID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i)", UserID, PlayerSessionIDStr, HaloTitleID, AchievementID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteAshesToAshes(LPWSTR UserID, GUID PlayerSessionID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteAssist(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, LPWSTR HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteAudioLogClaimed(LPWSTR UserID, GUID PlayerSessionID, INT32 AudioLogID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %i)", UserID, PlayerSessionIDStr, AudioLogID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBase(LPWSTR UserID, GUID PlayerSessionID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBetrayal(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, LPWSTR HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBIFactControllerSettings(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR HaloTitleID, INT32 GameCategoryID, INT32 ControllerConfigurationID, bool LookInverted)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %s, \"%S\", %i, %i, %s)", UserID, PlayerSessionIDStr, IsGuest ? "true" : "false", HaloTitleID, GameCategoryID, ControllerConfigurationID, LookInverted ? "true" : "false");

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBIFactDeepLink(LPWSTR UserID, GUID PlayerSessionID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBIFactDeepLinkRecieve(LPWSTR UserID, GUID PlayerSessionID, LPWSTR DeepLinkCorrelationID, LPWSTR DeepLinkURL)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", \"%S\")", UserID, PlayerSessionIDStr, DeepLinkCorrelationID, DeepLinkURL);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBIFactDeepLinkSend(LPWSTR UserID, GUID PlayerSessionID, LPWSTR DeepLinkCorrelationID, LPWSTR DeepLinkURL)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", \"%S\")", UserID, PlayerSessionIDStr, DeepLinkCorrelationID, DeepLinkURL);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBIFactDualWield(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR HaloTitleID, INT32 GameCategoryID, INT32 LeftWeaponID, INT32 RightWeaponID, FILETIME DualWieldTimeStamp)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		SYSTEMTIME DualWieldTimeStampUTC;
		::FileTimeToSystemTime(&DualWieldTimeStamp, &DualWieldTimeStampUTC);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %s, \"%S\", %i, %i, %i, %02i:%02d:%02i)", UserID, PlayerSessionIDStr, IsGuest ? "true" : "false", HaloTitleID, GameCategoryID, LeftWeaponID, RightWeaponID, DualWieldTimeStampUTC.wHour, DualWieldTimeStampUTC.wMinute, DualWieldTimeStampUTC.wSecond);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBIFactGameSession(LPWSTR UserID, GUID PlayerSessionID, FILETIME SessionStartTimeStamp, FILETIME SessionEndTimeStamp, LPWSTR HaloTitleID, FILETIME SubTitleStartTimeStamp, FILETIME SubTitleEndTimeStamp, INT32 GameCategoryID, LPWSTR LocaleID, INT32 MapID, INT32 ArmorID, UINT64 SkullsUsed, LPWSTR HopperID, INT32 PlayerCount, bool Matchmade, INT32 MatchmakingRank, double MatchmakingRating, INT32 MatchmakingXP, bool Won, UINT64 Score, UINT64 TeamScore, INT32 Standing, bool FirstPlace, INT32 Kills, INT32 Deaths, INT32 Assists, INT32 Betrayals, INT32 Suicides)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBIFactLoadout(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR HaloTitleID, INT32 GameCategoryID, INT32 PrimaryWeaponID, INT32 SecondaryWeaponID, INT32 GrenadeID, INT32 ShieldID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %s, \"%S\", %i, %i, %i, %i, %i)", UserID, PlayerSessionIDStr, IsGuest ? "true" : "false", HaloTitleID, GameCategoryID, PrimaryWeaponID, SecondaryWeaponID, GrenadeID, ShieldID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBIFactMatchmaking(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR LobbyID, FILETIME LobbyEntryTimeStamp, bool JoinedMatch, FILETIME JoinMatchTimeStamp, INT32 MatchmakingRank, double MatchmakingRating, INT32 MatchmakingXP, INT32 PartySize, GUID PartyID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);
		OLECHAR *PartyIDStr;
		stringFromCLSIDResult = StringFromCLSID(PartyID, &PartyIDStr);

		SYSTEMTIME LobbyEntryTimeStampUTC;
		::FileTimeToSystemTime(&LobbyEntryTimeStamp, &LobbyEntryTimeStampUTC);
		SYSTEMTIME JoinMatchTimeStampUTC;
		::FileTimeToSystemTime(&JoinMatchTimeStamp, &JoinMatchTimeStampUTC);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %s, \"%S\", %02i:%02d:%02i, %s, %02i:%02d:%02i, %i, %lf, %i, %i, %S)", UserID, PlayerSessionIDStr, IsGuest ? "true" : "false", LobbyID, LobbyEntryTimeStampUTC.wHour, LobbyEntryTimeStampUTC.wMinute, LobbyEntryTimeStampUTC.wSecond, JoinedMatch ? "true" : "false", JoinMatchTimeStampUTC.wHour, JoinMatchTimeStampUTC.wMinute, JoinMatchTimeStampUTC.wSecond, MatchmakingRank, MatchmakingRating, MatchmakingXP, PartySize, PartyIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
		::CoTaskMemFree(PartyIDStr);
	}
}

void IGameEvents::EventWriteBIFactMatchmakingDetails(LPWSTR UserID, GUID PlayerSessionID, INT32 NumPlayersInParty, bool GSRFired, bool BecameActiveInSession, bool ConnectedToPeerGameHost, bool GameStarted, FILETIME LobbyEntryTimeStamp, FILETIME LobbyExitTimeStamp, INT32 ExitReason, LPWSTR GameUniqiueID, bool IsArbiter, bool IsThunderheadGame, INT32 NumPlayers, INT32 NumPreserveSessionTicketsCreated)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBIFactMedia(LPWSTR UserID, GUID PlayerSessionID, bool IsGuest, LPWSTR HaloTitleID, FILETIME MediaStartTimeStamp, bool WasSkipped, FILETIME MediaSkipTimeStamp, LPWSTR MediaID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		SYSTEMTIME MediaStartTimeStampUTC;
		::FileTimeToSystemTime(&MediaStartTimeStamp, &MediaStartTimeStampUTC);
		SYSTEMTIME MediaSkipTimeStampUTC;
		::FileTimeToSystemTime(&MediaSkipTimeStamp, &MediaSkipTimeStampUTC);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %s, \"%S\", %02i:%02d:%02i, %s, %02i:%02d:%02i, \"%S\")", UserID, PlayerSessionIDStr, IsGuest ? "true" : "false", HaloTitleID, MediaStartTimeStampUTC.wHour, MediaStartTimeStampUTC.wMinute, MediaStartTimeStampUTC.wSecond, WasSkipped ? "true" : "false", MediaSkipTimeStampUTC.wHour, MediaSkipTimeStampUTC.wMinute, MediaSkipTimeStampUTC.wSecond, MediaID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBirdOfPrey(LPWSTR UserID, GUID PlayerSessionID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBitsAndPiecesDestroyed(LPWSTR UserID, GUID PlayerSessionID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBroadcastingAssist(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 CurrentAssists)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		SYSTEMTIME TimeStampUTC;
		::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %02i:%02d:%02i, %i)", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, CurrentAssists);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBroadcastingDeath(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, LPWSTR VictimXuid, UINT32 VictimTeamID, LPWSTR KillerXuid, UINT32 KillerTeamID, LPWSTR AssistantXuids, UINT32 DamageReportingModifier, INT32 StockID, INT32 AttachmentIDs, INT32 DamageTypeID, INT32 CurrentDeaths)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBroadcastingHeartbeat(LPWSTR UserID, GUID PlayerSessionID, INT64 Heartbeat)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %lli)", UserID, PlayerSessionIDStr, Heartbeat);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBroadcastingKill(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, LPWSTR VictimXuid, UINT32 VictimTeamID, LPWSTR KillerXuid, UINT32 KillerTeamID, LPWSTR AssistantXuids, UINT32 DamageReportingModifier, INT32 StockID, INT32 AttachmentIDs, INT32 DamageTypeID, INT32 CurrentKills)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBroadcastingMatchEnd(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		SYSTEMTIME TimeStampUTC;
		::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %02i:%02d:%02i)", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBroadcastingMatchRoundEnd(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		SYSTEMTIME TimeStampUTC;
		::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %02i:%02d:%02i)", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBroadcastingMatchRoundStart(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 RoundNumber)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		SYSTEMTIME TimeStampUTC;
		::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %02i:%02d:%02i, %i)", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, RoundNumber);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBroadcastingMatchStart(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 MapVariantID, INT32 GameVariantID, LPWSTR PlaylistID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		SYSTEMTIME TimeStampUTC;
		::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %02i:%02d:%02i, %i, %i, \"%S\")", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, MapVariantID, GameVariantID, PlaylistID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBroadcastingMedal(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 MedalID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		SYSTEMTIME TimeStampUTC;
		::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %02i:%02d:%02i, %i)", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, MedalID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBroadcastingPlayerJoined(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 TeamID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		SYSTEMTIME TimeStampUTC;
		::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %02i:%02d:%02i, %i)", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, TeamID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBroadcastingPlayerLeft(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		SYSTEMTIME TimeStampUTC;
		::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %02i:%02d:%02i)", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}
void IGameEvents::EventWriteBroadcastingPlayerSpawn(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		SYSTEMTIME TimeStampUTC;
		::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %02i:%02d:%02i)", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBroadcastingPlayerSwitchedTeams(LPWSTR UserID, GUID PlayerSessionID, FILETIME TimeStamp, INT32 TeamID, LPWSTR WebColor)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		SYSTEMTIME TimeStampUTC;
		::FileTimeToSystemTime(&TimeStamp, &TimeStampUTC);

		// spams console
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %02d:%02d:%02d, %i, \"%S\")", UserID, PlayerSessionIDStr, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, TeamID, WebColor);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBroadcastingScore(LPWSTR UserID, GUID PlayerSessionID, INT32 ControllerIndex, FILETIME Timestamp, INT32 CurrentRoundScore, INT32 CurrentTotalScore, INT32 CurrentRoundTeamScore, INT32 CurrentTotalTeamScore)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		SYSTEMTIME TimeStampUTC;
		::FileTimeToSystemTime(&Timestamp, &TimeStampUTC);

		// spams console
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %i, %02i:%02d:%02i, %i, %i, %i, %i)", UserID, PlayerSessionIDStr, ControllerIndex, TimeStampUTC.wHour, TimeStampUTC.wMinute, TimeStampUTC.wSecond, CurrentRoundScore, CurrentTotalScore, CurrentRoundTeamScore, CurrentTotalTeamScore);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteBroadcastingStart(LPWSTR UserID, GUID PlayerSessionID, UINT32 GameType, UINT32 Map, UINT32 TopPlayerRank, LPWSTR PlayerIDs, GUID MatchID, bool PlayerIsCaster, INT64 MatchStartTime)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);
		OLECHAR *MatchIDStr;
		stringFromCLSIDResult = StringFromCLSID(MatchID, &MatchIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %u, %u, %u, \"%S\", %S, %s, %lli)", UserID, PlayerSessionIDStr, GameType, Map, TopPlayerRank, PlayerIDs, MatchIDStr, PlayerIsCaster ? "true" : "false", MatchStartTime);

		::CoTaskMemFree(PlayerSessionIDStr);
		::CoTaskMemFree(MatchIDStr);
	}
}

void IGameEvents::EventWriteCampaignDifficulty(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR CampaignDifficulty)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", \"%S\")", UserID, PlayerSessionIDStr, HaloTitleID, CampaignDifficulty);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteChallengeCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 ChallengeID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i)", UserID, PlayerSessionIDStr, HaloTitleID, ChallengeID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteClassicModeSwitched(LPWSTR UserID, GUID PlayerSessionID, INT32 MapID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %i)", UserID, PlayerSessionIDStr, MapID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteCleverGirl(LPWSTR UserID, GUID PlayerSessionID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteClueClaimed(LPWSTR UserID, GUID PlayerSessionID, INT32 ClueID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %i)", UserID, PlayerSessionIDStr, ClueID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteCoopMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MissionID, INT32 MapID, INT32 MissionScore, bool IronSkullUsed, bool BlackEyeSkullUsed, bool ToughLuckSkullUsed, bool CatchSkullUsed, bool CloudSkullUsed, bool FamineSkullUsed, bool ThunderstormSkullUsed, bool TiltSkullUsed, bool MythicSkullUsed, bool BlindSkullUsed, INT32 DifficultyID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteCoopSpartanOpsMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 DifficultyID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i, %i)", UserID, PlayerSessionIDStr, HaloTitleID, MapID, DifficultyID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteCompletionCount(LPWSTR UserID, GUID PlayerSessionID, INT32 Count)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %i)", UserID, PlayerSessionIDStr, Count);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteCustomization(LPWSTR UserID, GUID PlayerSessionID, INT32 Texture0, INT32 Texture1, INT32 Color0, INT32 Color1, INT32 Color2, LPWSTR ServiceID, LPWSTR ClanID, INT32 AvatarID, INT32 NameplateID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %i, %i, %i, %i, %i, \"%S\", \"%S\", %i, %i)", UserID, PlayerSessionIDStr, Texture0, Texture1, Color0, Color1, Color2, ServiceID, ClanID, AvatarID, NameplateID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteDashboardContext(LPWSTR UserID, GUID PlayerSessionID, LPWSTR DashboardContext)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\")", UserID, PlayerSessionIDStr, DashboardContext);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteDeath(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, LPWSTR HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade, bool HeadShot)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteDollFound(LPWSTR UserID, GUID PlayerSessionID, INT32 DollID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %i)", UserID, PlayerSessionIDStr, DollID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteEliteWin(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, bool MatchMade)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %s)", UserID, PlayerSessionIDStr, HaloTitleID, MatchMade ? "true" : "false");

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteEmblem(LPWSTR UserID, GUID PlayerSessionID, INT32 Texture0, INT32 Texture1, INT32 Color0, INT32 Color1, INT32 Color2)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %i, %i, %i, %i, %i)", UserID, PlayerSessionIDStr, Texture0, Texture1, Color0, Color1, Color2);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteEnemyDefeated(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, LPWSTR HaloTitleID, INT32 MapID, INT32 EnemyClassID, INT32 GameCategoryID, bool MatchMade, bool HeadShot)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteFriendsBestedOnHeroLeaderboard(LPWSTR UserID, GUID PlayerSessionID, INT32 LeaderboardID, INT32 LeaderboardRows)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %i, %i)", UserID, PlayerSessionIDStr, LeaderboardID, LeaderboardRows);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteGameProgress(LPWSTR UserID, GUID PlayerSessionID, float CompletionPercent)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %f)", UserID, PlayerSessionIDStr, CompletionPercent);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteGameVarSaved(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 BaseGameCategory, LPWSTR GameVarName)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i, \"%S\")", UserID, PlayerSessionIDStr, HaloTitleID, BaseGameCategory, GameVarName);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteGrenadeStick(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, INT32 EnemyClassID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteHelloNurse(LPWSTR UserID, GUID PlayerSessionID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteInGamePresence(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitle, INT32 CampaignDifficulty, INT32 MultiplayerMap)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i, %i)", UserID, PlayerSessionIDStr, HaloTitle, CampaignDifficulty, MultiplayerMap);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteISeeYou(LPWSTR UserID, GUID PlayerSessionID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteJoinability(LPWSTR UserID, GUID PlayerSessionID, bool InGame)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %s)", UserID, PlayerSessionIDStr, InGame ? "true" : "false");

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteLobby(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR Lobby)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", \"%S\")", UserID, PlayerSessionIDStr, HaloTitleID, Lobby);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteMainMenuPresence(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MainMenuPresence)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\")", UserID, PlayerSessionIDStr, MainMenuPresence);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteMapVarSaved(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 BaseMapID, LPWSTR MapVarName)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i, \"%S\")", UserID, PlayerSessionIDStr, HaloTitleID, BaseMapID, MapVarName);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteMatchmakingHopper(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR MatchmakingHopper)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", \"%S\")", UserID, PlayerSessionIDStr, HaloTitleID, MatchmakingHopper);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteMediaUsage(LPWSTR AppSessionID, LPWSTR AppSessionStartDateTime, UINT32 UserIDType, LPWSTR UserID, LPWSTR SubscriptionTierType, LPWSTR SubscriptionTier, LPWSTR MediaType, LPWSTR ProviderID, LPWSTR ProviderMediaID, LPWSTR ProviderMediaInstanceID, GUID BingID, UINT64 MediaLengthMs, UINT32 MediaControlAction, float PlaybackSpeed, UINT64 MediaPositionMs, UINT64 PlaybackDurationMs, LPWSTR AcquisitionType, LPWSTR AcquisitionContext, LPWSTR AcquisitionContextType, LPWSTR AcquisitionContextID, INT32 PlaybackIsStream, INT32 PlaybackIsTethered, LPWSTR MarketplaceLocation, LPWSTR ContentLocale, float TimeZoneOffset, UINT32 ScreenState)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *BingIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(BingID, &BingIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, BingIDStr);

		::CoTaskMemFree(BingIDStr);
	}
}

void IGameEvents::EventWriteMeldOfferPresented(LPWSTR UserID, GUID PlayerSessionID, GUID OfferGuid, GUID ProductGuid, LPWSTR Page, INT32 SourceTileIndex)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);
		OLECHAR *OfferGuidStr;
		stringFromCLSIDResult = StringFromCLSID(OfferGuid, &OfferGuidStr);
		OLECHAR *ProductGuidStr;
		stringFromCLSIDResult = StringFromCLSID(ProductGuid, &ProductGuidStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %S, %S, \"%S\", %i)", UserID, PlayerSessionIDStr, OfferGuidStr, ProductGuidStr, Page, SourceTileIndex);

		::CoTaskMemFree(PlayerSessionIDStr);
		::CoTaskMemFree(OfferGuidStr);
		::CoTaskMemFree(ProductGuidStr);
	}
}

void IGameEvents::EventWriteMeldOfferResponded(LPWSTR UserID, GUID PlayerSessionID, GUID OfferGuid, GUID ProductGuid, INT32 UpsellOutcome)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);
		OLECHAR *OfferGuidStr;
		stringFromCLSIDResult = StringFromCLSID(OfferGuid, &OfferGuidStr);
		OLECHAR *ProductGuidStr;
		stringFromCLSIDResult = StringFromCLSID(ProductGuid, &ProductGuidStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %S, %S, %i)", UserID, PlayerSessionIDStr, OfferGuidStr, ProductGuidStr, UpsellOutcome);

		::CoTaskMemFree(PlayerSessionIDStr);
		::CoTaskMemFree(OfferGuidStr);
		::CoTaskMemFree(ProductGuidStr);
	}
}

void IGameEvents::EventWriteMeldPageAction(LPWSTR UserID, GUID PlayerSessionID, INT32 ActionTypeID, INT32 ActionInputMethodID, LPWSTR Page, LPWSTR TemplateID, LPWSTR DestinationPage, LPWSTR Content, INT32 SourceTileIndex, INT32 SourceTileX, INT32 SourceTileY, INT32 SourceTileWidth, INT32 SourceTileHeight)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteMeldPageView(LPWSTR UserID, GUID PlayerSessionID, LPWSTR Page, LPWSTR RefererPage, INT32 PageTypeID, LPWSTR PageTags, LPWSTR TemplateID, LPWSTR Content, LPWSTR FilterContext, INT32 FilterDirection)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", \"%S\", %i, \"%S\", \"%S\", \"%S\", \"%S\", %i)", UserID, PlayerSessionIDStr, Page, RefererPage, PageTypeID, PageTags, TemplateID, Content, FilterContext, FilterDirection);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 GameCategoryID, bool Coop, UINT64 TimePlayedMS, UINT64 DatePlayedUTC, INT32 DifficultyID, UINT64 MissionScore64, UINT64 SkullUsedFlags, INT32 NumPlayers, LPWSTR PlayerSectionStats, INT32 Kills, float Multiplier, INT32 Penalties, float SkullMultiplier, INT32 TotalSoloMissionsComplete, INT32 TotalCoopMissionsComplete)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteMortardomWraithsKilled(LPWSTR UserID, GUID PlayerSessionID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteMultiplayerGameEngine(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR MultiplayerGameEngine)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", \"%S\")", UserID, PlayerSessionIDStr, HaloTitleID, MultiplayerGameEngine);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteMultiplayerMap(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR MultiplayerMap)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", \"%S\")", UserID, PlayerSessionIDStr, HaloTitleID, MultiplayerMap);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteMultiplayerRoundEnd(LPWSTR UserID, GUID RoundID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 MatchTypeID, INT32 DifficultyLevelID, float TimeInSeconds, INT32 ExitStatusID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *RoundIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(RoundID, &RoundIDStr);
		OLECHAR *PlayerSessionIDStr;
		stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %i, %S, \"%S\", %i, %i, %i, %f, %i)", UserID, RoundIDStr, SectionID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, MatchTypeID, DifficultyLevelID, TimeInSeconds, ExitStatusID);

		::CoTaskMemFree(RoundIDStr);
		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteMultiplayerRoundStart(LPWSTR UserID, GUID RoundID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 MatchTypeID, INT32 DifficultyLevelID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *RoundIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(RoundID, &RoundIDStr);
		OLECHAR *PlayerSessionIDStr;
		stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %i, %S, \"%S\", %i, %i, %i)", UserID, RoundIDStr, SectionID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, MatchTypeID, DifficultyLevelID);

		::CoTaskMemFree(RoundIDStr);
		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteNappersCaught(LPWSTR UserID, GUID PlayerSessionID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteNewsStoryRead(LPWSTR UserID, GUID PlayerSessionID, LPWSTR StoryID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\")", UserID, PlayerSessionIDStr, StoryID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteObjectiveEnd(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ObjectiveID, INT32 ExitStatusID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %i, %S, \"%S\", %i, %i, %i, %i)", UserID, SectionID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID, ObjectiveID, ExitStatusID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteObjectiveStart(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ObjectiveID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %i, %S, \"%S\", %i, %i, %i)", UserID, SectionID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID, ObjectiveID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWritePageAction(LPWSTR UserID, GUID PlayerSessionID, INT32 ActionTypeID, INT32 ActionInputMethodID, LPWSTR Page, LPWSTR TemplateID, LPWSTR DestinationPage, LPWSTR Content)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %i, %i, \"%S\", \"%S\", \"%S\", \"%S\")", UserID, PlayerSessionIDStr, ActionTypeID, ActionInputMethodID, Page, TemplateID, DestinationPage, Content);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWritePageView(LPWSTR UserID, GUID PlayerSessionID, LPWSTR Page, LPWSTR RefererPage, INT32 PageTypeID, LPWSTR PageTags, LPWSTR TemplateID, LPWSTR Content)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", \"%S\", %i, \"%S\", \"%S\", \"%S\")", UserID, PlayerSessionIDStr, Page, RefererPage, PageTypeID, PageTags, TemplateID, Content);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWritePhantomHunter(LPWSTR UserID, GUID PlayerSessionID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWritePigsCanFly(LPWSTR UserID, GUID PlayerSessionID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWritePlayerCheckedInToday(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\")", UserID, PlayerSessionIDStr, HaloTitleID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWritePlayerDefeated(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 EnemyWeaponID, float LocationX, float LocationY, float LocationZ)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWritePlayerGameResults(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 GameIndexByCategory, INT32 GameIndexByTitle, INT32 GameIndexByTitleCategory, INT32 MapID, INT32 GameCategoryID, bool MatchMade, bool Won, UINT64 TimePlayedMS, UINT64 DatePlayedUTC, UINT64 Score64, INT32 Standing, bool FirstPlace, INT32 MedalCount, INT32 Kills, INT32 Deaths, INT32 Assists, INT32 HeadShots, INT32 MostKillsInARow, LPWSTR CustomStat1ID, INT32 CustomStat1, LPWSTR CustomStat2ID, INT32 CustomStat2, LPWSTR CustomStat3ID, INT32 CustomStat3, LPWSTR CustomStat4ID, INT32 CustomStat4, GUID MatchID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWritePlayerGameResultsDamageStat(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, INT32 DamageReportingType, INT32 DamageStatisticType, INT32 DamageCount, INT32 GameCategoryID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i, %i, %s, %i, %i, %i, %i)", UserID, PlayerSessionIDStr, HaloTitleID, GameIndex, MapID, MatchMade ? "true" : "false", DamageReportingType, DamageStatisticType, DamageCount, GameCategoryID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWritePlayerGameResultsGriefingStat(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, float Betrayals, float ShieldDamage, float BodyDamage, float BetrayalPenalty, float ShieldDamagePenalty, float BodyDamagePenalty)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWritePlayerGameResultsGriefingStats(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, float Betrayals, float ShieldDamage, float BodyDamage, float BetrayalPenalty, float ShieldDamagePenalty, float BodyDamagePenalty)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWritePlayerGameResultsInterestStats(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameCategoryID, INT32 GameIndex, INT32 MapID, bool MatchMade, INT32 OrdnanceDrops, INT32 OrdnanceStrikes, UINT64 TimeMSDriven, INT32 UnitsDriven, UINT64 TimeMSPiloted, INT32 UnitsPiloted, UINT64 TimeMSPassenger, INT32 UnitsMovedPassenger, UINT64 TimeMSOnFoot, INT32 UnitsMovedOnFoot, INT32 DriverAssists, INT32 ArmorAbilityUseJetpack, INT32 ArmorAbilityUseHologram, INT32 ArmorAbilityUseReflectiveShield, INT32 ArmorAbilityUseActiveCamo, INT32 ArmorAbilityUseThrusterPack, INT32 ArmorAbilityUseAutoTurret, INT32 ArmorAbilityUseXRay)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWritePlayerGameResultsMedal(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 GameIndex, INT32 MapID, bool MatchMade, INT32 MedalType, INT32 MedalCount)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i, %i, %s, %i, %i)", UserID, PlayerSessionIDStr, HaloTitleID, GameIndex, MapID, MatchMade ? "true" : "false", MedalType, MedalCount);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWritePlayerSessionEnd(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ExitStatusID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i, %i, %i)", UserID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID, ExitStatusID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWritePlayerSessionPause(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\")", UserID, PlayerSessionIDStr, MultiplayerCorrelationID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWritePlayerSessionResume(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i, %i)", UserID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWritePlayerSessionStart(LPWSTR UserID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i, %i)", UserID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWritePlayerSpawned(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, float LocationX, float LocationY, float LocationZ)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);
		OLECHAR *RoundIDStr;
		stringFromCLSIDResult = StringFromCLSID(RoundID, &RoundIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %i, %S, \"%S\", %i, %i, %S, %i, %f, %f, %f)", UserID, SectionID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID, RoundIDStr, PlayerRoleID, LocationX, LocationY, LocationZ);

		::CoTaskMemFree(PlayerSessionIDStr);
		::CoTaskMemFree(RoundIDStr);
	}
}

void IGameEvents::EventWritePlaylistCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, UINT32 PlaylistID, UINT64 Score64, UINT64 TimeMS, INT32 Penalties, LPWSTR MissionStats, bool IsCoop)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %u, %llu, %llu, %i, \"%S\", %s)", UserID, PlayerSessionIDStr, HaloTitleID, PlaylistID, Score64, TimeMS, Penalties, MissionStats, IsCoop ? "true" : "false");

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWritePlaylistProgress(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 PlaylistID, INT32 NumMapsCompleted, UINT64 Score64, bool IsCoop, INT32 NumPlayers, bool ShouldPostTime, UINT64 TotalPlayListTimeMS)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i, %i, %llu, %s, %i, %s, %llu)", UserID, PlayerSessionIDStr, HaloTitleID, PlaylistID, NumMapsCompleted, Score64, IsCoop ? "true" : "false", NumPlayers, ShouldPostTime ? "true" : "false", TotalPlayListTimeMS);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteRankedStatsDNFInfo(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HopperName, double FinishesOverStarts, INT32 FinishesMinusStarts, INT32 FinishesPlusPenaltiesMinusStarts, double FinishesPlusPenaltiesOverStarts)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %lf, %i, %i, %lf)", UserID, PlayerSessionIDStr, HopperName, FinishesOverStarts, FinishesMinusStarts, FinishesPlusPenaltiesMinusStarts, FinishesPlusPenaltiesOverStarts);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteRankedStatsOverride(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HopperName, double Rating, double Variance, INT32 Halo2Level, INT32 Halo2XP, bool IsRanked)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %lf, %lf, %i, %i, %s)", UserID, PlayerSessionIDStr, HopperName, Rating, Variance, Halo2Level, Halo2XP, IsRanked ? "true" : "false");

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteRankedStatsPenalty(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HopperName, INT32 NumPenaltiesApplied)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i)", UserID, PlayerSessionIDStr, HopperName, NumPenaltiesApplied);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteRankedStatsUpdate(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HopperName, double Rating, double Variance, INT32 Halo2Level, INT32 Halo2XP, bool IsRanked, bool PenaltyApplied)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %lf, %lf, %i, %i, %s, %s)", UserID, PlayerSessionIDStr, HopperName, Rating, Variance, Halo2Level, Halo2XP, IsRanked ? "true" : "false", PenaltyApplied ? "true" : "false");

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteRankedUpSpartanIv(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 SpartanIvRank, INT32 SpecialisationType)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i, %i)", UserID, PlayerSessionIDStr, HaloTitleID, SpartanIvRank, SpecialisationType);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteRealtimeFlagCaptured(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, bool MatchMade)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i, %s)", UserID, PlayerSessionIDStr, HaloTitleID, MapID, MatchMade ? "true" : "false");

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteRealtimeMedal(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 GameCategoryID, INT32 GameMode, bool MatchMade, INT32 MedalType, INT32 MedalCount)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i, %i, %i, %s, %i, %i)", UserID, PlayerSessionIDStr, HaloTitleID, MapID, GameCategoryID, GameMode, MatchMade ? "true" : "false", MedalType, MedalCount);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteRealtimePilotedVehicle(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, bool MatchMade, INT32 VehicleID, UINT64 TimeMS, INT32 Distance)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i, %s, %i, %lli, %i)", UserID, PlayerSessionIDStr, HaloTitleID, MapID, MatchMade ? "true" : "false", VehicleID, TimeMS, Distance);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteRivalID(LPWSTR UserID, GUID PlayerSessionID, INT64 RivalID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %lli)", UserID, PlayerSessionIDStr, RivalID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteSectionEnd(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 ExitStatusID, INT32 MissionID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i, %i, %i, %i)", UserID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID, ExitStatusID, MissionID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteSectionStart(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, INT32 MissionID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %i, %S, \"%S\", %i, %i, %i)", UserID, SectionID, PlayerSessionIDStr, MultiplayerCorrelationID, GameplayModeID, DifficultyLevelID, MissionID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteSectionStats(LPWSTR UserID, GUID PlayerSessionID, INT32 MissionID, INT32 SectionID, INT32 SectionOrdinal, float ScoreWithoutTimeBonus, float ScoreWithTimeBonus, float TimeInSeconds)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %i, %i, %i, %f, %f, %f)", UserID, PlayerSessionIDStr, MissionID, SectionID, SectionOrdinal, ScoreWithoutTimeBonus, ScoreWithTimeBonus, TimeInSeconds);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteSessionSizeUpdate(LPWSTR UserID, GUID PlayerSessionID, INT32 SessionSize, INT32 SessionSizeMax)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %i, %i)", UserID, PlayerSessionIDStr, SessionSize, SessionSizeMax);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteSizeIsEverything(LPWSTR UserID, GUID PlayerSessionID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteSkeetShooter(LPWSTR UserID, GUID PlayerSessionID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteSkullClaimed(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 SkullID, INT32 DifficultyID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i, %i)", UserID, PlayerSessionIDStr, HaloTitleID, SkullID, DifficultyID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteSoloMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 DifficultyID, INT32 MissionScore, bool IronSkullUsed, bool BlackEyeSkullUsed, bool ToughLuckSkullUsed, bool CatchSkullUsed, bool CloudSkullUsed, bool FamineSkullUsed, bool ThunderstormSkullUsed, bool TiltSkullUsed, bool MythicSkullUsed, bool BlindSkullUsed)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteSoloSpartanOpsMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 DifficultyID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i, %i)", UserID, PlayerSessionIDStr, HaloTitleID, MapID, DifficultyID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteSpartanOpsMissionCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 MapID, INT32 MissionID, INT32 DifficultyID, bool IsCoop)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i, %i, %i, %s)", UserID, PlayerSessionIDStr, HaloTitleID, MapID, MissionID, DifficultyID, IsCoop ? "true" : "false");

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteSupercombine(LPWSTR UserID, INT32 SectionID, GUID PlayerSessionID, LPWSTR MultiplayerCorrelationID, INT32 GameplayModeID, INT32 DifficultyLevelID, GUID RoundID, INT32 PlayerRoleID, INT32 PlayerWeaponID, INT32 EnemyRoleID, INT32 KillTypeID, float LocationX, float LocationY, float LocationZ, INT32 EnemyWeaponID, INT32 EnemyClassID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		// TODO: finish
		//c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteSurvivalSpace(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, LPWSTR SurvivalSpace)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", \"%S\")", UserID, PlayerSessionIDStr, HaloTitleID, SurvivalSpace);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteTerminalFound(LPWSTR UserID, GUID PlayerSessionID, INT32 TerminalID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %i)", UserID, PlayerSessionIDStr, TerminalID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteTerminalID(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, INT32 SkullID, INT32 DifficultyID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %i, %i)", UserID, PlayerSessionIDStr, HaloTitleID, SkullID, DifficultyID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteTicketsEarned(LPWSTR UserID, GUID PlayerSessionID, INT32 TicketCount)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %i)", UserID, PlayerSessionIDStr, TicketCount);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteTitleCompleted(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\")", UserID, PlayerSessionIDStr, HaloTitleID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteTitleLaunched(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\")", UserID, PlayerSessionIDStr, HaloTitleID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteValhallaSign(LPWSTR UserID, GUID PlayerSessionID, INT32 SignID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %i)", UserID, PlayerSessionIDStr, SignID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteViewOffer(LPWSTR UserID, GUID PlayerSessionID, GUID OfferGuid, GUID ProductGuid)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);
		OLECHAR *OfferGuidStr;
		stringFromCLSIDResult = StringFromCLSID(OfferGuid, &OfferGuidStr);
		OLECHAR *ProductGuidStr;
		stringFromCLSIDResult = StringFromCLSID(ProductGuid, &ProductGuidStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %S, %S)", UserID, PlayerSessionIDStr, OfferGuidStr, ProductGuidStr);

		::CoTaskMemFree(PlayerSessionIDStr);
		::CoTaskMemFree(OfferGuidStr);
		::CoTaskMemFree(ProductGuidStr);
	}
}

void IGameEvents::EventWriteVIPStatusEarned(LPWSTR UserID, GUID PlayerSessionID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteWhatAboutTanksDestroyed(LPWSTR UserID, GUID PlayerSessionID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S)", UserID, PlayerSessionIDStr);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteWonWarGame(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\")", UserID, PlayerSessionIDStr, HaloTitleID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteZanzibarSign(LPWSTR UserID, GUID PlayerSessionID, INT32 SignID)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, %i)", UserID, PlayerSessionIDStr, SignID);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteFirefightGameResults(LPWSTR UserID, GUID PlayerSessionID, LPWSTR HaloTitleID, bool MatchMade, UINT64 TimePlayedMS, UINT32 Kills, UINT32 MostKillsInARow, UINT32 SetsCompleted, UINT32 WavesCompleted, UINT32 GeneratorsDestroyed)
{
	if (g_logGameEventMessages)
	{
		OLECHAR *PlayerSessionIDStr;
		HRESULT stringFromCLSIDResult = StringFromCLSID(PlayerSessionID, &PlayerSessionIDStr);

		c_console::write_line_verbose(__FUNCTION__"(\"%S\", %S, \"%S\", %s, %llu, %u, %u, %u, %u, %u)", UserID, PlayerSessionIDStr, HaloTitleID, MatchMade ? "true" : "false", TimePlayedMS, Kills, MostKillsInARow, SetsCompleted, WavesCompleted, GeneratorsDestroyed);

		::CoTaskMemFree(PlayerSessionIDStr);
	}
}

void IGameEvents::EventWriteEnemyDefeated_0()
{
	if (g_logGameEventMessages)
	{
		c_console::write_line_verbose(__FUNCTION__);
	}
}

void IGameEvents::Member128()
{
	if (g_logGameEventMessages)
	{
		c_console::write_line_verbose(__FUNCTION__);
	}
}

void IGameEvents::Member129()
{
	if (g_logGameEventMessages)
	{
		c_console::write_line_verbose(__FUNCTION__);
	}
}

void IGameEvents::Member130()
{
	if (g_logGameEventMessages)
	{
		c_console::write_line_verbose(__FUNCTION__);
	}
}

void IGameEvents::Member131()
{
	if (g_logGameEventMessages)
	{
		c_console::write_line_verbose(__FUNCTION__);
	}
}

void IGameEvents::Member132()
{
	if (g_logGameEventMessages)
	{
		// spams console
		//c_console::write_line_verbose(__FUNCTION__);
	}
}

void IGameEvents::Member133()
{
	if (g_logGameEventMessages)
	{
		// spams console
		//c_console::write_line_verbose(__FUNCTION__);
	}
}

INT64 IGameEvents::Member134(INT64)
{
	if (g_logGameEventMessages)
	{
		c_console::write_line_verbose(__FUNCTION__);
	}
	return INT64(0);
}

INT64 IGameEvents::Member135()
{
	if (g_logGameEventMessages)
	{
		// spams console
		//c_console::write_line_verbose(__FUNCTION__);
	}
	return 0;
}

LPGUID IGameEvents::GetSessionID()
{
	if (g_logGameEventMessages)
	{
		c_console::write_line_verbose(__FUNCTION__);
	}
	return &playerSessionId;
}

void IGameEvents::Member137()
{
	if (g_logGameEventMessages)
	{
		c_console::write_line_verbose(__FUNCTION__);
	}
}

void IGameEvents::CheckpointSaved()
{
	if (g_logGameEventMessages)
	{
		c_console::write_line_verbose(__FUNCTION__);
	}
}

void IGameEvents::Member139()
{
	if (g_logGameEventMessages)
	{
		c_console::write_line_verbose(__FUNCTION__);
	}
}

