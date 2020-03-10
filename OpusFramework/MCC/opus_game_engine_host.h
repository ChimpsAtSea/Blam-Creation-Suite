#pragma once

class c_opus_game_engine_host : public IGameEngineHost
{
public:
	c_opus_game_engine_host(e_engine_type engine_type, e_build build, c_game_runtime& rGameRuntime);
	virtual ~c_opus_game_engine_host();

	// MCC Functions

	virtual char FrameStart() override;
	virtual void FrameEnd(IDXGISwapChain* pSwapChain, _QWORD) override;
	virtual void Function02(__int64 player_identifier, unsigned int, __int64, float, float, float, float) override;
	virtual void EngineStateUpdate(eEngineState state) override;
	virtual __int64 GameExited(unsigned int, char*, int) override;
	virtual __int64 __fastcall WriteBufferToFile(LPVOID pBuffer, size_t bufferSize) override;
	virtual void Function06(GameResultsData* pGameResultsData) override;
	virtual void Function07(unsigned int) override;
	virtual void Function08(const wchar_t*, const wchar_t*) override;
	virtual void Function09(wchar_t[1024], wchar_t[1024]) override;
	virtual IGameEvents* GetGameEvents() override;
	virtual void UpdateGameVariant(IGameVariant* pGameVariant) override;
	virtual void UpdateMapVariant(IMapVariant* pMapVariant) override;
	virtual void Function13(const wchar_t*, const wchar_t*, const void*, unsigned int) override;
	virtual char Function14(int controllerIndex, BYTE*) override;
	virtual char Function15(int controllerIndex, BYTE*) override;
	virtual char GetNextLevelInfo(e_map_id* pMapID, int* pCampaignInsertionPoint, FILETIME* pFiletime, _DWORD*) override;
	virtual bool Function17(int) override;
	virtual void Function18(int) override;
	virtual __int64 __fastcall MapLoadPecentStatus(__int64, __int64, float) override;
	virtual void Function20(__int64, __int8) override;
	virtual __int64 __fastcall GetMachineIdentifier(_QWORD) override;
	virtual __int64 Function22(Function22Structure* buffer, __int64) override;
	virtual char Function23(__int64, __int64) override;
	virtual void GetSessionInfo(s_session_info_part* pSessionInfoPart) override;
	virtual void __fastcall MembershipUpdate(s_session_membership* pSessionMembership, uint32_t playercount) override;
	virtual bool __fastcall Function26() override;
	virtual bool __fastcall Function27() override;
	virtual bool __fastcall UpdateGraphics(UpdateGraphicsData* pUnknown) override;
	virtual __int64 __fastcall Member29(__int64 value) override;
	virtual __int64 __fastcall UpdatePlayerConfiguration(wchar_t playerNames[4][32], PlayerConfiguration& rPlayerConfiguration) override;
	virtual bool __fastcall __fastcall UpdateInput(_QWORD, InputBuffer* pInputBuffer) override;
	virtual void Function32(_QWORD, float*) override;
	virtual void Function33() override;
	virtual void XInputSetState(DWORD dwUserIndex, XINPUT_VIBRATION* pVibration) override;
	virtual bool __fastcall __fastcall UpdatePlayerNames(__int64*, wchar_t pszPlayerNames[4][32], size_t dataSize) override;
	virtual void __fastcall Function36(const wchar_t*, const wchar_t*) override;
	virtual bool __fastcall Function37(wchar_t*, __int64) override;
	virtual __int64 __fastcall NetworkSendTo(NetworkID networkID, char* pBuffer, uint32_t buffersize, int) override;
	virtual __int64 __fastcall NetworkReceiveFrom(char* pBuffer, uint32_t buffersize, __int64, s_transport_address* pTransportAddress) override;
	virtual char* __fastcall Function40(unsigned int) override;
	virtual int __fastcall Function41(BYTE* pBuffer) override;
	virtual bool __fastcall Function42(signed int, __int64, __int64) override;
	virtual void __fastcall FirefightNew(__int64, float) override;
	virtual BOOL __fastcall Function44(__int64, __int64) override;
	virtual bool __fastcall get_pathByType(PathType pathType, LPSTR pBuffer, size_t bufferLength) override;
	virtual bool __fastcall GetWidePathByType(PathType pathType, wchar_t* pBuffer, size_t bufferLength) override;
	virtual unsigned __int8* __fastcall Function47(_QWORD, unsigned __int8*, _QWORD) override;
	virtual __int64 __fastcall Function48(_QWORD, __int64) override;
	virtual char* __fastcall Function49(char* str) override;

	// Opus Functionality
	virtual void render_ui() const = 0;
	virtual IGameEngine* get_game_engine() const = 0;


protected:
	c_game_runtime& game_runtime;
	IGameEvents game_events;
	c_high_precision_timer frame_timer;
	double total_frame_cpu_time;
	IGameEngine* game_engine;
};

