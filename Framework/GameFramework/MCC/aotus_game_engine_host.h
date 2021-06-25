#pragma once

class c_aotus_game_engine_host : public IGameEngineHost
{
public:
	c_aotus_game_engine_host(s_engine_platform_build engine_platform_build, c_game_runtime& rGameRuntime);
	virtual ~c_aotus_game_engine_host();

	// MCC Functions

	virtual char frame_begin() override;
	virtual void frame_end(IDXGISwapChain* swap_chain, _QWORD) override;
	virtual void function02(__int64 player_identifier, unsigned int, __int64, float, float, float, float) override;
	virtual void engine_state_update_handler(e_engine_state state) override;
	virtual __int64 game_shutdown_handler(unsigned int, char*, int) override;
	virtual __int64 __fastcall game_save_handler(LPVOID buffer, size_t buffer_size) override;
	virtual void game_results_submission_handler(s_game_results* game_results_data) override;
	virtual void game_pause_handler(unsigned int) override;
	virtual void function08(const wchar_t*, const wchar_t*) override;
	virtual void Function09(wchar_t[1024], wchar_t[1024]) override;
	virtual IGameEvents* game_events_get() override;
	virtual void game_variant_save_handler(IGameVariant* game_variant) override;
	virtual void map_variant_save_handler(IMapVariant* map_variant) override;
	virtual void function13(const wchar_t*, const wchar_t*, const void*, unsigned int) override;
	virtual char controller_inverted_look_update_handler(int controller_index, bool inverted) override;
	virtual char game_specific_bindings_get(int controller_index, char(*buffer)[256]) override;
	virtual char next_mission_info_get(e_map_id* map_id, int* campaign_insertion_point, FILETIME* file_time, _DWORD*) override;
	virtual bool function17(int) override;
	virtual void function18(int) override;
	virtual __int64 __fastcall engine_load_status_handler(__int64, __int64, float) override;
	virtual void function20(__int64, __int8) override;
	virtual __int64 __fastcall local_machine_identifier_get(_QWORD) override;
	virtual __int64 function22(s_function22_data* buffer, __int64) override;
	virtual char function23(__int64, __int64) override;
	virtual void session_info_get(s_session_info_part* session_info_part) override;
	virtual void __fastcall session_membership_update_handler(s_session_membership* session_membership, uint32_t player_count) override;
	virtual bool __fastcall function26() override;
	virtual bool __fastcall function27() override;
	virtual bool __fastcall game_data_update_handler(char* game_data) override;
	virtual c_player_configuration* __fastcall player_configuration_get(__int64 value) override;
	virtual __int64 __fastcall player_configuration_update_handler(wchar_t player_names[4][16], c_player_configuration* player_configuration) override;
	virtual bool __fastcall input_update_handler(_QWORD, InputBuffer* input_buffer) override;
	virtual void function32(_QWORD, float*) override;
	virtual void function33() override;
	virtual void xinput_set_state_handler(DWORD user_index, XINPUT_VIBRATION* xinput_vibration) override;
	virtual bool __fastcall player_name_update_handler(__int64*, wchar_t player_names[4][16], size_t data_size) override;
	virtual void __fastcall function36(const wchar_t*, const wchar_t*) override;
	virtual bool __fastcall function37(wchar_t*, __int64) override;
	virtual __int64 __fastcall network_sendto_handler(NetworkID network_id, char* buffer, uint32_t buffer_size, int) override;
	virtual __int64 __fastcall network_recvfrom_handler(char* buffer, uint32_t buffer_size, __int64, s_transport_address* pTransportAddress) override;
	virtual char* __fastcall function40(unsigned int) override;
	virtual int __fastcall telnet_console_print(const char* buffer) override;
	virtual bool __fastcall function42(signed int, __int64, __int64) override;
	virtual void __fastcall firefight_new_handler(__int64, float) override;
	virtual BOOL __fastcall function44(__int64, __int64) override;
	virtual bool __fastcall path_by_type_get(PathType path_type, LPSTR buffer, size_t buffer_length) override;
	virtual bool __fastcall wide_path_by_type_get(PathType path_type, wchar_t* buffer, size_t buffer_length) override;
	virtual unsigned __int8* __fastcall function47(_QWORD, unsigned __int8*, _QWORD) override;
	virtual __int64 __fastcall function48(_QWORD, __int64) override;
	virtual char* __fastcall function49(char* str) override;
	virtual __int64  __fastcall function58(); /* added in 1629 */
	virtual __int64 __fastcall function59(__int64 a1, unsigned int a2); /* added in 1629 */
	virtual __int64 __fastcall function60(__int64 a1); /* added in 1658 */
	virtual void __fastcall function61(__int64 a1); /* added in 1658 */
	virtual float __fastcall function62(); /* added in 1896 */
	virtual __int64 __fastcall function63(float a1); /* added in 1896 */
	virtual __int64 __fastcall function64(__int64, unsigned int, int, __int64, float*); /* added in 1896 */

	// Aotus Functionality
	virtual void render_ui() const = 0;
	virtual IGameEngine* get_game_engine() const = 0;

protected:
	IGameEngine* game_engine;
	c_window* window;
	c_mouse_input& mouse_input;
	c_game_runtime& game_runtime;
	IGameEvents game_events;
	c_high_precision_timer frame_timer;
	double total_frame_cpu_time;
};

