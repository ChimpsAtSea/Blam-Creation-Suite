#pragma once
class IGameEvents
{
public:

	static IGameEvents g_gameEvents;
	static bool g_logGameEventMessages;





	/* 0   */	virtual void AchievementEarned();
	/* 1   */	virtual void AshesToAshes();
	/* 2   */	virtual void Assist();
	/* 3   */	virtual void AudioLogClaimed();
	/* 4   */	virtual void Base();
	/* 5   */	virtual void Betrayal();
	/* 6   */	virtual void BIFactControllerSettings(unsigned __int64*, GUID*, _QWORD, __int64, _DWORD, int, int);
	/* 7   */	virtual void BIFactDeepLink();
	/* 8   */	virtual void BIFactDeepLinkRecieve(_QWORD*, GUID*, _QWORD*, __int64*);
	/* 9   */	virtual void BIFactDeepLinkSend(_QWORD*, GUID*, _QWORD*, __int64*);
	/* 10  */	virtual void BIFactDualWield();
	/* 11  */	virtual void BIFactGameSession();
	/* 12  */	virtual void BIFactLoadout();
	/* 13  */	virtual void BIFactMatchmaking();
	/* 14  */	virtual void BIFactMatchmakingDetails();
	/* 15  */	virtual void BIFactMedia();
	/* 16  */	virtual void BirdOfPrey();
	/* 17  */	virtual void BitsAndPiecesDestroyed();
	/* 18  */	virtual void BroadcastingAssist();
	/* 19  */	virtual void BroadcastingDeath();
	/* 20  */	virtual void BroadcastingHeartbeat();
	/* 21  */	virtual void BroadcastingKill();
	/* 22  */	virtual void BroadcastingMatchEnd();
	/* 23  */	virtual void BroadcastingMatchRoundEnd(); // these are probably named wrong as these are alphabetical
	/* 24  */	virtual void BroadcastingMatchRoundStart(); // these are probably named wrong as these are alphabetical
	/* 25  */	virtual void BroadcastingMatchStart();
	/* 26  */	virtual void BroadcastingMedal();
	/* 27  */	virtual void BroadcastingPlayerJoined();
	/* 28  */	virtual void BroadcastingPlayerLeft();
	/* 29  */	virtual void BroadcastingPlayerSpawn();
	/* 30  */	virtual void BroadcastingPlayerSwitchedTeams();
	/* 31  */	virtual void BroadcastingScore();
	/* 32  */	virtual void BroadcastingStart(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _QWORD);
	/* 33  */	virtual void CampaignDifficulty();
	/* 34  */	virtual void ChallengeCompleted();
	/* 35  */	virtual void ClassicModeSwitched();
	/* 36  */	virtual void CleverGirl();
	/* 37  */	virtual void ClueClaimed();
	/* 38  */	virtual void CoopMissionCompleted();
	/* 39  */	virtual void CoopSpartanOpsMissionCompleted();
	/* 40  */	virtual void CompletionCount();
	/* 41  */	virtual void Customization();
	/* 42  */	virtual void DashboardContext();
	/* 43  */	virtual void Death();
	/* 44  */	virtual void DollFound();
	/* 45  */	virtual void EliteWin();
	/* 46  */	virtual void Emblem();
	/* 47  */	virtual void EnemyDefeated();
	/* 48  */	virtual void FriendsBestedOnHeroLeaderboard();
	/* 49  */	virtual void GameProgress();
	/* 50  */	virtual void GameVarSaved();
	/* 51  */	virtual void GrenadeStick();
	/* 52  */	virtual void HelloNurse();
	/* 53  */	virtual void InGamePresence();
	/* 54  */	virtual void ISeeYou();
	/* 55  */	virtual void Joinability();
	/* 56  */	virtual void Lobby();
	/* 57  */	virtual void MainMenuPresence();
	/* 58  */	virtual void MapVarSaved();
	/* 59  */	virtual void MatchmakingHopper();
	/* 60  */	virtual void MediaUsage();
	/* 61  */	virtual void MeldOfferPresented();
	/* 62  */	virtual void MeldOfferResponded();
	/* 63  */	virtual void MeldPageAction();
	/* 64  */	virtual void MeldPageView();
	/* 65  */	virtual void MissionCompleted();
	/* 66  */	virtual void MortardomWraithsKilled();
	/* 67  */	virtual void MultiplayerGameEngine();
	/* 68  */	virtual void MultiplayerMap();
	/* 69  */	virtual void MultiplayerRoundEnd();
	/* 70  */	virtual void MultiplayerRoundStart();
	/* 71  */	virtual void NappersCaught();
	/* 72  */	virtual void NewsStoryRead();
	/* 73  */	virtual void ObjectiveEnd();
	/* 74  */	virtual void ObjectiveStart();
	/* 75  */	virtual void PageAction();
	/* 76  */	virtual void PageView();
	/* 77  */	virtual void PhantomHunter();
	/* 78  */	virtual void PigsCanFly();
	/* 79  */	virtual void PlayerCheckedInToday();
	/* 80  */	virtual void PlayerDefeated();
	/* 81  */	virtual void PlayerGameResults();
	/* 82  */	virtual void PlayerGameResultsDamageStat();
	/* 83  */	virtual void PlayerGameResultsGriefingStat();
	/* 84  */	virtual void PlayerGameResultsGriefingStats();
	/* 85  */	virtual void PlayerGameResultsInterestStats();
	/* 86  */	virtual void PlayerGameResultsMedal();
	/* 87  */	virtual void PlayerSessionEnd();
	/* 88  */	virtual void PlayerSessionPause();
	/* 89  */	virtual void PlayerSessionResume();
	/* 90  */	virtual void PlayerSessionStart();
	/* 91  */	virtual void PlayerSpawned();
	/* 92  */	virtual void PlaylistCompleted();
	/* 93  */	virtual void PlaylistProgress();
	/* 94  */	virtual void RankedStatsDNFInfo();
	/* 95  */	virtual void RankedStatsOverride();
	/* 96  */	virtual void RankedStatsPenalty();
	/* 97  */	virtual void RankedStatsUpdate();
	/* 98  */	virtual void RankedUpSpartanIv();
	/* 99  */	virtual void RealtimeFlagCaptured();
	/* 100 */	virtual void RealtimeMedal();
	/* 101 */	virtual void RealtimePilotedVehicle();
	/* 102 */	virtual void RivalID();
	/* 103 */	virtual void SectionEnd();
	/* 104 */	virtual void SectionStart();
	/* 105 */	virtual void SectionStats();
	/* 106 */	virtual void SessionSizeUpdate();
	/* 107 */	virtual void SizeIsEverything();
	/* 108 */	virtual void SkeetShooter();
	/* 109 */	virtual void SkullClaimed();
	/* 110 */	virtual void SoloMissionCompleted();
	/* 111 */	virtual void SoloSpartanOpsMissionCompleted();
	/* 112 */	virtual void SpartanOpsMissionCompleted();
	/* 113 */	virtual void Supercombine();
	/* 114 */	virtual void SurvivalSpace();
	/* 115 */	virtual void TerminalFound();
	/* 116 */	virtual void TerminalId();
	/* 117 */	virtual void TicketsEarned();
	/* 118 */	virtual void TitleCompleted();
	/* 119 */	virtual void TitleLaunched();
	/* 120 */	virtual void ValhallaSign();
	/* 121 */	virtual void ViewOffer();
	/* 122 */	virtual void VIPStatusEarned();
	/* 123 */	virtual void WhatAboutTanksDestroyed();
	/* 124 */	virtual void WonWarGame();
	/* 125 */	virtual void ZanzibarSign();
	/* 126 */	virtual void FirefightGameResults();
	/* 127 */	virtual void EnemyDefeated_0(); // probably zombie defeated as these are in alphabetical order
	/* 128 */	virtual void Member128();
	/* 129 */	virtual void Member129();
	/* 130 */	virtual void Member130();
	/* 131 */	virtual void Member131();
	/* 132 */	virtual void Member132();
	/* 133 */	virtual void Member133();
	/* 134 */	virtual __int64 Member134(_QWORD);
	/* 135 */	virtual void Member135();
	/* 136 */	virtual GUID* __fastcall GetGuid(GUID* pGuid);
	/* 137 */	virtual void Member137();
	/* 138 */	virtual void Member138();
	/* 139 */	virtual void Member139();

	struct __declspec(align(8)) UnknownType
	{
		QWORD qword0;
		QWORD* qword1;
		QWORD* qword2;
		DWORD dword0;
		DWORD dword1;
		QWORD qword4;
		QWORD* qword5;
		QWORD* qword6;
		DWORD dword2;
		DWORD dword3;
		DWORD dword4;
		DWORD dword5;
	};

	_WORD word0;
	_WORD word1;
	GUID guid;
	__unaligned __declspec(align(1)) _QWORD qword0;
	__unaligned __declspec(align(1)) _QWORD qword1;
	__unaligned __declspec(align(1)) _QWORD qword2;
	__unaligned __declspec(align(1)) _QWORD qword3;
	__unaligned __declspec(align(1)) _QWORD qword4;
	__unaligned __declspec(align(1)) _QWORD qword5;
	__unaligned __declspec(align(1)) _QWORD qword6;
	__unaligned __declspec(align(1)) _QWORD qword7;
	_DWORD dword0;
	_DWORD dword1;
	_DWORD dword2;
	_RTL_CRITICAL_SECTION rtlCriticalSection;
	_QWORD qword8;
	UnknownType unknownStruct;
	_QWORD qword9;
	_QWORD qwordA;
	_QWORD qwordB;


};

