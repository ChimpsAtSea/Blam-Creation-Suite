#pragma once

class IOpusGameEngineHost : public IGameEngineHost
{
public:
	IOpusGameEngineHost(GameRuntime& rGameRuntime);
	~IOpusGameEngineHost();

	char Member00() override;
	void FrameEnd(IDXGISwapChain* pSwapChain, _QWORD) override;
	void Member02(__int64 player_identifier, unsigned int, __int64, float, float, float, float) override;
	void EngineStateUpdate(eEngineState state) override;
	__int64 GameExited(unsigned int, char*, int) override;
	__int64 __fastcall WriteBufferToFile(LPVOID pBuffer, size_t bufferSize) override;
	void Member06(GameResultsData* pGameResultsData) override;
	void Member07(unsigned int) override;
	void Member08(const wchar_t*, const wchar_t*) override;
	void Member09(wchar_t[1024], wchar_t[1024]) override;
	IGameEvents* GetGameEvents() override;
	void UpdateGameVariant(IGameVariant* pGameVariant) override;
	void UpdateMapVariant(IMapVariant* pMapVariant) override;
	void Member13(const wchar_t*, const wchar_t*, const void*, unsigned int) override;
	char Member14(int controllerIndex, BYTE*) override;
	char Member15(int controllerIndex, BYTE*) override;
	char GetNextLevelInfo(MapID* pMapID, int* pCampaignInsertionPoint, FILETIME* pFiletime, _DWORD*) override;
	bool Member17(int) override;
	void Member18(int) override;
	__int64 __fastcall MapLoadPecentStatus(__int64, __int64, float) override;
	void Member20(__int64, __int8) override;
	__int64 __fastcall GetMachineIdentifier(_QWORD) override;
	__int64 Member22(Function22Structure* buffer, __int64) override;
	char Member23(__int64, __int64) override;
	void GetSessionInfo(s_session_info_part* pSessionInfoPart) override;
	void __fastcall MembershipUpdate(s_session_membership* pSessionMembership, uint32_t playercount) override;
	bool __fastcall Member26() override;
	bool __fastcall Member27() override;
	bool __fastcall UpdateGraphics(Function28Structure* pUnknown) override;
	__int64 __fastcall UpdatePlayerConfiguration(wchar_t playerNames[4][32], PlayerConfiguration& rPlayerConfiguration) override;
	bool __fastcall __fastcall UpdateInput(_QWORD, InputBuffer* pInputBuffer) override;
	void Member31(_QWORD, float*) override;
	void Member32() override;
	void XInputSetState(DWORD dwUserIndex, XINPUT_VIBRATION* pVibration) override;
	bool __fastcall __fastcall UpdatePlayerNames(__int64*, wchar_t pszPlayerNames[4][32], size_t dataSize) override;
	void __fastcall Member35(const wchar_t*, const wchar_t*) override;
	bool __fastcall Member36(wchar_t*, __int64) override;
	__int64 __fastcall NetworkSendTo(NetworkID networkID, char* pBuffer, uint32_t buffersize, int) override;
	__int64 __fastcall NetworkReceiveFrom(char* pBuffer, uint32_t buffersize, __int64, s_transport_address* pTransportAddress) override;
	char* __fastcall Member39(unsigned int) override;
	int __fastcall Member40(BYTE* pBuffer) override;
	bool __fastcall Member41(signed int, __int64, __int64) override;
	void __fastcall FirefightNew(__int64, float) override;
	BOOL __fastcall Member43(__int64, __int64) override;
	bool __fastcall GetPathByType(PathType pathType, LPSTR pBuffer, size_t bufferLength) override;
	bool __fastcall GetWidePathByType(PathType pathType, wchar_t* pBuffer, size_t bufferLength) override;
	unsigned __int8* __fastcall Member46(_QWORD, unsigned __int8*, _QWORD) override;
	__int64 __fastcall Member47(_QWORD, __int64) override;

protected:
	GameRuntime& m_rGameRuntime;
	IGameEvents m_gameEvents;


};

