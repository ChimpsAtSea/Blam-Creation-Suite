#pragma once

class c_opus_game_engine_host : public IGameEngineHost
{
public:
	c_opus_game_engine_host(e_engine_type engine_type, e_build build, c_game_runtime& rGameRuntime);
	virtual ~c_opus_game_engine_host();

	// MCC Functions

	virtual char FrameStart() override;
	virtual void FrameEnd(IDXGISwapChain* swap_chain, _QWORD) override;
	virtual void Function02(__int64 player_identifier, unsigned int, __int64, float, float, float, float) override;
	virtual void EngineStateUpdate(eEngineState state) override;
	virtual __int64 GameExited(unsigned int, char*, int) override;
	virtual __int64 __fastcall SaveGameState(LPVOID buffer, size_t buffer_size) override;
	virtual void SubmitGameResults(GameResultsData* game_results_data) override;
	virtual void Function07(unsigned int) override;
	virtual void Function08(const wchar_t*, const wchar_t*) override;
	virtual void Function09(wchar_t[1024], wchar_t[1024]) override;
	virtual IGameEvents* GetGameEvents() override;
	virtual void SaveGameVariant(IGameVariant* game_variant) override;
	virtual void SaveMapVariant(IMapVariant* map_variant) override;
	virtual void Function13(const wchar_t*, const wchar_t*, const void*, unsigned int) override;
	virtual char InvertLookControls(int controller_index, bool inverted) override;
	virtual char GetGameSpecificBindings(int controller_index, char(*buffer)[256]) override;
	virtual char GetNextLevelInfo(e_map_id* pMapID, int* campaign_insertion_point, FILETIME* file_time, _DWORD*) override;
	virtual bool Function17(int) override;
	virtual void Function18(int) override;
	virtual __int64 __fastcall MapLoadPecentStatus(__int64, __int64, float) override;
	virtual void Function20(__int64, __int8) override;
	virtual __int64 __fastcall GetMachineIdentifier(_QWORD) override;
	virtual __int64 Function22(Function22Structure* buffer, __int64) override;
	virtual char Function23(__int64, __int64) override;
	virtual void GetSessionInfo(s_session_info_part* session_info_part) override;
	virtual void __fastcall MembershipUpdate(s_session_membership* session_membership, uint32_t player_count) override;
	virtual bool __fastcall Function26() override;
	virtual bool __fastcall Function27() override;
	virtual bool __fastcall UpdateGraphics(UpdateGraphicsData* update_graphics_data) override;
	virtual PlayerConfiguration* __fastcall GetPlayerConfiguration(__int64 value) override;
	virtual __int64 __fastcall UpdatePlayerConfiguration(wchar_t player_names[4][16], PlayerConfiguration* player_configuration) override;
	virtual bool __fastcall __fastcall UpdateInput(_QWORD, InputBuffer* input_buffer) override;
	virtual void Function32(_QWORD, float*) override;
	virtual void Function33() override;
	virtual void XInputSetState(DWORD user_index, XINPUT_VIBRATION* xinput_vibration) override;
	virtual bool __fastcall __fastcall UpdatePlayerNames(__int64*, wchar_t player_names[4][16], size_t data_size) override;
	virtual void __fastcall Function36(const wchar_t*, const wchar_t*) override;
	virtual bool __fastcall Function37(wchar_t*, __int64) override;
	virtual __int64 __fastcall NetworkSendTo(NetworkID network_id, char* buffer, uint32_t buffer_size, int) override;
	virtual __int64 __fastcall NetworkReceiveFrom(char* buffer, uint32_t buffer_size, __int64, s_transport_address* pTransportAddress) override;
	virtual char* __fastcall Function40(unsigned int) override;
	virtual int __fastcall Function41(BYTE* buffer) override;
	virtual bool __fastcall Function42(signed int, __int64, __int64) override;
	virtual void __fastcall FirefightNew(__int64, float) override;
	virtual BOOL __fastcall Function44(__int64, __int64) override;
	virtual bool __fastcall get_pathByType(PathType path_type, LPSTR buffer, size_t buffer_length) override;
	virtual bool __fastcall GetWidePathByType(PathType path_type, wchar_t* buffer, size_t buffer_length) override;
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

