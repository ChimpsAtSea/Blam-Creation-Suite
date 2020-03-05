#pragma once

class c_opus_game_engine_host : public IGameEngineHost
{
public:
	c_opus_game_engine_host(e_engine_type engine_type, e_build build, c_game_runtime& rGameRuntime);
	virtual ~c_opus_game_engine_host();

	// MCC Functions

	char FrameStart() override;
	void FrameEnd(IDXGISwapChain* pSwapChain, _QWORD) override;
	void Function02(__int64 player_identifier, unsigned int, __int64, float, float, float, float) override;
	void EngineStateUpdate(eEngineState state) override;
	__int64 GameExited(unsigned int, char*, int) override;
	__int64 __fastcall WriteBufferToFile(LPVOID pBuffer, size_t bufferSize) override;
	void Function06(GameResultsData* pGameResultsData) override;
	void Function07(unsigned int) override;
	void Function08(const wchar_t*, const wchar_t*) override;
	void Function09(wchar_t[1024], wchar_t[1024]) override;
	IGameEvents* GetGameEvents() override;
	void UpdateGameVariant(IGameVariant* pGameVariant) override;
	void UpdateMapVariant(IMapVariant* pMapVariant) override;
	void Function13(const wchar_t*, const wchar_t*, const void*, unsigned int) override;
	char Function14(int controllerIndex, BYTE*) override;
	char Function15(int controllerIndex, BYTE*) override;
	char GetNextLevelInfo(e_map_id* pMapID, int* pCampaignInsertionPoint, FILETIME* pFiletime, _DWORD*) override;
	bool Function17(int) override;
	void Function18(int) override;
	__int64 __fastcall MapLoadPecentStatus(__int64, __int64, float) override;
	void Function20(__int64, __int8) override;
	__int64 __fastcall GetMachineIdentifier(_QWORD) override;
	__int64 Function22(Function22Structure* buffer, __int64) override;
	char Function23(__int64, __int64) override;
	void GetSessionInfo(s_session_info_part* pSessionInfoPart) override;
	void __fastcall MembershipUpdate(s_session_membership* pSessionMembership, uint32_t playercount) override;
	bool __fastcall Function26() override;
	bool __fastcall Function27() override;
	bool __fastcall UpdateGraphics(UpdateGraphicsData* pUnknown) override;
	__int64 __fastcall Member29(__int64 value) override;
	__int64 __fastcall UpdatePlayerConfiguration(wchar_t playerNames[4][32], PlayerConfiguration& rPlayerConfiguration) override;
	bool __fastcall __fastcall UpdateInput(_QWORD, InputBuffer* pInputBuffer) override;
	void Function32(_QWORD, float*) override;
	void Function33() override;
	void XInputSetState(DWORD dwUserIndex, XINPUT_VIBRATION* pVibration) override;
	bool __fastcall __fastcall UpdatePlayerNames(__int64*, wchar_t pszPlayerNames[4][32], size_t dataSize) override;
	void __fastcall Function36(const wchar_t*, const wchar_t*) override;
	bool __fastcall Function37(wchar_t*, __int64) override;
	__int64 __fastcall NetworkSendTo(NetworkID networkID, char* pBuffer, uint32_t buffersize, int) override;
	__int64 __fastcall NetworkReceiveFrom(char* pBuffer, uint32_t buffersize, __int64, s_transport_address* pTransportAddress) override;
	char* __fastcall Function40(unsigned int) override;
	int __fastcall Function41(BYTE* pBuffer) override;
	bool __fastcall Function42(signed int, __int64, __int64) override;
	void __fastcall FirefightNew(__int64, float) override;
	BOOL __fastcall Function44(__int64, __int64) override;
	bool __fastcall get_pathByType(PathType pathType, LPSTR pBuffer, size_t bufferLength) override;
	bool __fastcall GetWidePathByType(PathType pathType, wchar_t* pBuffer, size_t bufferLength) override;
	unsigned __int8* __fastcall Function47(_QWORD, unsigned __int8*, _QWORD) override;
	__int64 __fastcall Function48(_QWORD, __int64) override;

	// Opus Functionality
	virtual void render_ui() const = 0;
	virtual IGameEngine* get_game_engine() const = 0;


protected:
	c_game_runtime& game_runtime;
	IGameEvents game_events;
};

