#include "gameframework-private-pch.h"

#define IGameEngineHostCreateBarrierDefinition(index) void IGameEngineHost::Function##index() { FATAL_ERROR(L"IGameEngineHost barrier was triggered! index:" STRINGIFY(index)); }

/* barrier functions to prevent new versions of games calling our functions */
IGameEngineHostCreateBarrierDefinition(50);
IGameEngineHostCreateBarrierDefinition(51);
IGameEngineHostCreateBarrierDefinition(52);
IGameEngineHostCreateBarrierDefinition(53);
IGameEngineHostCreateBarrierDefinition(54);
IGameEngineHostCreateBarrierDefinition(55);
IGameEngineHostCreateBarrierDefinition(56);
IGameEngineHostCreateBarrierDefinition(57);

#undef IGameEngineHostCreateBarrierDefinition

void IGameEngineHostEmptyFunction()
{
	RUNONCE({
		c_console::set_text_color(_console_color_error);
		c_console::write_line_verbose("IGameEngineHostEmptyFunction was hit!");
		c_console::set_text_color(_console_color_info);
		});
}

IGameEngineHost::IGameEngineHost(e_engine_type engine_type, e_build build, IGameEvents* game_events) :
	game_engine_host_configured(false),
	engine_type(engine_type),
	build(build),
	game_events_ptr(game_events),
	__vtbl_dynamic(__vtbl_dynamic_data)
{
	memset(__vtbl_dynamic_data, 0xFF, sizeof(__vtbl_dynamic_data));
	for (size_t i = 0; i < kTableSize; i++)
	{
		__vtbl_dynamic_data[i] = IGameEngineHostEmptyFunction;
	}

	GetDynamicGameEngineHost();
}

IGameEngineHost* IGameEngineHost::GetDynamicGameEngineHost()
{
	if (!game_engine_host_configured)
	{
		ConfigureGameEngineHost();
		game_engine_host_configured = true;
	}
	return reinterpret_cast<IGameEngineHost*>(&__vtbl_dynamic);
}

#define CHECK_ADDRESS_SHIFTED() bool address_is_shifted = __vtbl_known_address0 == known_address1; ASSERT(address_is_shifted)
#define shifted_this reinterpret_cast<IGameEngineHost*>(reinterpret_cast<char*>(this) - sizeof(uintptr_t))

char IGameEngineHost::frame_begin() { CHECK_ADDRESS_SHIFTED(); return shifted_this->frame_begin(); }
void IGameEngineHost::frame_end(IDXGISwapChain* swap_chain, _QWORD a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->frame_end(swap_chain, a2); }
void IGameEngineHost::function02(__int64 player_identifier, unsigned int a2, __int64 a3, float a4, float a5, float a6, float a7) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function02(player_identifier, a2, a3, a4, a5, a6, a7); }
void IGameEngineHost::engine_state_update_handler(e_engine_state state) { CHECK_ADDRESS_SHIFTED(); return shifted_this->engine_state_update_handler(state); }
__int64 IGameEngineHost::game_shutdown_handler(unsigned int a1, char* a2, int a3) { CHECK_ADDRESS_SHIFTED(); return shifted_this->game_shutdown_handler(a1, a2, a3); }
__int64 __fastcall IGameEngineHost::game_save_handler(LPVOID buffer, size_t buffer_size) { CHECK_ADDRESS_SHIFTED(); return shifted_this->game_save_handler(buffer, buffer_size); }
void IGameEngineHost::game_results_submission_handler(s_game_results* game_results_data) { CHECK_ADDRESS_SHIFTED(); return shifted_this->game_results_submission_handler(game_results_data); }
void IGameEngineHost::game_pause_handler(unsigned int a1) { CHECK_ADDRESS_SHIFTED(); return shifted_this->game_pause_handler(a1); }
void IGameEngineHost::function08(const wchar_t* a1, const wchar_t* a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function08(a1, a2); }
void IGameEngineHost::Function09(wchar_t a1[1024], wchar_t a2[1024]) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function09(a1, a2); }
IGameEvents* IGameEngineHost::game_events_get() { CHECK_ADDRESS_SHIFTED(); return shifted_this->game_events_get(); }
void IGameEngineHost::game_variant_save_handler(IGameVariant* game_variant) { CHECK_ADDRESS_SHIFTED(); return shifted_this->game_variant_save_handler(game_variant); }
void IGameEngineHost::map_variant_save_handler(IMapVariant* map_variant) { CHECK_ADDRESS_SHIFTED(); return shifted_this->map_variant_save_handler(map_variant); }
void IGameEngineHost::function13(const wchar_t* a1, const wchar_t* a2, const void* a3, unsigned int a4) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function13(a1, a2, a3, a4); }
char IGameEngineHost::controller_inverted_look_update_handler(int controller_index, bool inverted) { CHECK_ADDRESS_SHIFTED(); return shifted_this->controller_inverted_look_update_handler(controller_index, inverted); }
char IGameEngineHost::game_specific_bindings_get(int controller_index, char(*buffer)[256]) { CHECK_ADDRESS_SHIFTED(); return shifted_this->game_specific_bindings_get(controller_index, buffer); }
char IGameEngineHost::next_mission_info_get(e_map_id* map_id, int* campaign_insertion_point, FILETIME* file_time, _DWORD* a4) { CHECK_ADDRESS_SHIFTED(); return shifted_this->next_mission_info_get(map_id, campaign_insertion_point, file_time, a4); }
bool IGameEngineHost::function17(int a1) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function17(a1); }
void IGameEngineHost::function18(int a1) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function18(a1); }
__int64 __fastcall IGameEngineHost::engine_load_status_handler(__int64 a1, __int64 a2, float a3) { CHECK_ADDRESS_SHIFTED(); return shifted_this->engine_load_status_handler(a1, a2, a3); }
void IGameEngineHost::function20(__int64 a1, __int8 a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function20(a1, a2); }
__int64 __fastcall IGameEngineHost::local_machine_identifier_get(_QWORD a1) { CHECK_ADDRESS_SHIFTED(); return shifted_this->local_machine_identifier_get(a1); }
__int64 IGameEngineHost::function22(s_function22_data* buffer, __int64 a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function22(buffer, a2); }
char IGameEngineHost::function23(__int64 a1, __int64 a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function23(a1, a2); }
void IGameEngineHost::session_info_get(s_session_info_part* session_info_part) { CHECK_ADDRESS_SHIFTED(); return shifted_this->session_info_get(session_info_part); }
void __fastcall IGameEngineHost::session_membership_update_handler(s_session_membership* session_membership, uint32_t player_count) { CHECK_ADDRESS_SHIFTED(); return shifted_this->session_membership_update_handler(session_membership, player_count); }
bool __fastcall IGameEngineHost::function26() { CHECK_ADDRESS_SHIFTED(); return shifted_this->function26(); }
bool __fastcall IGameEngineHost::function27() { CHECK_ADDRESS_SHIFTED(); return shifted_this->function27(); }
bool __fastcall IGameEngineHost::graphical_settings_update_handler(s_graphical_settings* update_graphics_data) { CHECK_ADDRESS_SHIFTED(); return shifted_this->graphical_settings_update_handler(update_graphics_data); }
c_player_configuration* __fastcall IGameEngineHost::player_configuration_get(__int64 value) { CHECK_ADDRESS_SHIFTED(); return shifted_this->player_configuration_get(value); }
__int64 __fastcall IGameEngineHost::player_configuration_update_handler(wchar_t player_names[4][16], c_player_configuration* player_configuration) { CHECK_ADDRESS_SHIFTED(); return shifted_this->player_configuration_update_handler(player_names, player_configuration); }
bool __fastcall IGameEngineHost::input_update_handler(_QWORD a1, InputBuffer* input_buffer) { CHECK_ADDRESS_SHIFTED(); return shifted_this->input_update_handler(a1, input_buffer); }
void IGameEngineHost::function32(_QWORD a1, float* a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function32(a1, a2); }
void IGameEngineHost::function33() { CHECK_ADDRESS_SHIFTED(); return shifted_this->function33(); }
void IGameEngineHost::xinput_set_state_handler(DWORD user_index, XINPUT_VIBRATION* xinput_vibration) { CHECK_ADDRESS_SHIFTED(); return shifted_this->xinput_set_state_handler(user_index, xinput_vibration); }
bool __fastcall IGameEngineHost::player_name_update_handler(__int64* a1, wchar_t player_names[4][16], size_t data_size) { CHECK_ADDRESS_SHIFTED(); return shifted_this->player_name_update_handler(a1, player_names, data_size); }
void __fastcall IGameEngineHost::function36(const wchar_t* a1, const wchar_t* a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function36(a1, a2); }
bool __fastcall IGameEngineHost::function37(wchar_t* a1, __int64 a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function37(a1, a2); }
__int64 __fastcall IGameEngineHost::network_sendto_handler(NetworkID network_id, char* buffer, uint32_t buffer_size, int a4) { CHECK_ADDRESS_SHIFTED(); return shifted_this->network_sendto_handler(network_id, buffer, buffer_size, a4); }
__int64 __fastcall IGameEngineHost::network_recvfrom_handler(char* buffer, uint32_t buffer_size, __int64 a3, s_transport_address* pTransportAddress) { CHECK_ADDRESS_SHIFTED(); return shifted_this->network_recvfrom_handler(buffer, buffer_size, a3, pTransportAddress); }
char* __fastcall IGameEngineHost::function40(unsigned int a1) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function40(a1); }
int __fastcall IGameEngineHost::function41(BYTE* buffer) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function41(buffer); }
bool __fastcall IGameEngineHost::function42(signed int a1, __int64 a2, __int64 a3) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function42(a1, a2, a3); }
void __fastcall IGameEngineHost::firefight_new_handler(__int64 a1, float a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->firefight_new_handler(a1, a2); }
BOOL __fastcall IGameEngineHost::function44(__int64 a1, __int64 a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function44(a1, a2); }
bool __fastcall IGameEngineHost::path_by_type_get(PathType path_type, LPSTR buffer, size_t buffer_length) { CHECK_ADDRESS_SHIFTED(); return shifted_this->path_by_type_get(path_type, buffer, buffer_length); }
bool __fastcall IGameEngineHost::wide_path_by_type_get(PathType path_type, LPWSTR buffer, size_t buffer_length) { CHECK_ADDRESS_SHIFTED(); return shifted_this->wide_path_by_type_get(path_type, buffer, buffer_length); }
unsigned __int8* __fastcall IGameEngineHost::function47(_QWORD a1, unsigned __int8* a2, _QWORD a3) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function47(a1, a2, a3); }
__int64 __fastcall IGameEngineHost::function48(_QWORD a1, __int64 a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function48(a1, a2); }
char* __fastcall IGameEngineHost::function49(char* str) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function49(str); }
__int64 __fastcall IGameEngineHost::function58() { CHECK_ADDRESS_SHIFTED(); return shifted_this->function58(); }
__int64 __fastcall IGameEngineHost::function59(__int64 a1, unsigned int a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function59(a1, a2); }
__int64 __fastcall IGameEngineHost::function60(__int64 a1) { CHECK_ADDRESS_SHIFTED(); return shifted_this->function60(a1); }
void __fastcall IGameEngineHost::function61(__int64 a1) { CHECK_ADDRESS_SHIFTED(); shifted_this->function61(a1); }

void IGameEngineHost::ConfigureGameEngineHost()
{
	void** custom_game_engine_host_vtable = *reinterpret_cast<void***>(this);

	size_t current_function_index = 0;
#define enqueue_function(min_build, max_build, function) \
	__pragma(warning(suppress: 6287)) if((min_build == _build_not_set || build >= min_build) && (max_build == _build_not_set || build <= max_build)) \
	__vtbl_dynamic_data[current_function_index++] = custom_game_engine_host_vtable[function];

	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_frame_begin);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_frame_end);
	enqueue_function(_build_mcc_1_1367_0_0, _build_not_set, __game_engine_virtual_function_function44);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function2);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_engine_state_update_handler);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_game_shutdown_handler);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_game_save_handler);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_game_results_submission_handler);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_game_pause_handler);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function8);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function9);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_game_events_get);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_game_variant_save_handler);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_map_variant_save_handler);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function13);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function14);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function15);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_next_mission_info_get);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function17);
	enqueue_function(_build_mcc_1_1367_0_0, _build_not_set, __game_engine_virtual_function_function26);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function18);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_engine_load_status_handler); // after this
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function20);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_local_machine_identifier_get);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function22);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function23);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_session_info_get);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_session_membership_update_handler);															//virtual void Member25(Member25Struct * a1, uint32_t a2);
	enqueue_function(_build_not_set, _build_mcc_1_1350_0_0, __game_engine_virtual_function_function26); // relocated after 1350									//virtual void Member26();
	enqueue_function(_build_mcc_1_1035_0_0, _build_not_set, __game_engine_virtual_function_function27);																//virtual void Member27();
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_graphical_settings_update_handler);															//virtual bool Member28(__int64 a2);
	enqueue_function(_build_mcc_1_1350_0_0, _build_not_set, __game_engine_virtual_function_player_configuration_get);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_player_configuration_update_handler);												//virtual bool Member29(__int64 a2, __int64 a3);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_input_update_handler); // before this, missing after this							//virtual unsigned __int8 __fastcall Member30(_QWORD, InputBuffer * input_buffer);
	enqueue_function(_build_mcc_1_1246_0_0, _build_not_set, __game_engine_virtual_function_function32);
	enqueue_function(_build_mcc_1_1186_0_0, _build_not_set, __game_engine_virtual_function_function33);
	enqueue_function(_build_mcc_1_1186_0_0, _build_not_set, __game_engine_virtual_function_xinput_set_state_handler);
	enqueue_function(_build_not_set, _build_mcc_1_1350_0_0, __game_engine_virtual_function_player_name_update_handler); // relocated after 1350
	enqueue_function(_build_not_set, _build_mcc_1_1350_0_0, __game_engine_virtual_function_function36); // relocated after 1350
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function37);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_network_sendto_handler);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_network_recvfrom_handler);
	enqueue_function(_build_not_set, _build_mcc_1_1350_0_0, __game_engine_virtual_function_function40); // removed after 1350
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function41);
	enqueue_function(_build_not_set, _build_mcc_1_1350_0_0, __game_engine_virtual_function_function42); // removed after 1350
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_firefight_new_handler);
	enqueue_function(_build_not_set, _build_mcc_1_1350_0_0, __game_engine_virtual_function_function44); // relocated after 1350
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_path_by_type_get);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_wide_path_by_type_get);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function47);
	enqueue_function(_build_mcc_1_1186_0_0, _build_not_set, __game_engine_virtual_function_function48);
	enqueue_function(_build_mcc_1_1377_0_0, _build_not_set, __game_engine_virtual_function_function49);
	enqueue_function(_build_mcc_1_1367_0_0, _build_not_set, __game_engine_virtual_function_player_name_update_handler); // relocated after 1350
	enqueue_function(_build_mcc_1_1367_0_0, _build_not_set, __game_engine_virtual_function_function36); // relocated after 1350
	enqueue_function(_build_mcc_1_1629_0_0, _build_not_set, __game_engine_virtual_function_function50);
	enqueue_function(_build_mcc_1_1629_0_0, _build_not_set, __game_engine_virtual_function_function51);
	enqueue_function(_build_mcc_1_1658_0_0, _build_not_set, __game_engine_virtual_function_function52);
	enqueue_function(_build_mcc_1_1658_0_0, _build_not_set, __game_engine_virtual_function_function53);

#undef enqueue_function


	if (build == _build_mcc_1_887_0_0)
	{
		DEBUG_ASSERT(__vtbl_dynamic_data[19] == custom_game_engine_host_vtable[__game_engine_virtual_function_engine_load_status_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[25] == custom_game_engine_host_vtable[__game_engine_virtual_function_session_membership_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[28] == custom_game_engine_host_vtable[__game_engine_virtual_function_player_configuration_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[29] == custom_game_engine_host_vtable[__game_engine_virtual_function_input_update_handler]);
	}
	else if (build == _build_mcc_1_1305_0_0)
	{
		DEBUG_ASSERT(__vtbl_dynamic_data[0] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_begin]);
		DEBUG_ASSERT(__vtbl_dynamic_data[1] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_end]);
		DEBUG_ASSERT(__vtbl_dynamic_data[2] == custom_game_engine_host_vtable[__game_engine_virtual_function_function2]);
		DEBUG_ASSERT(__vtbl_dynamic_data[3] == custom_game_engine_host_vtable[__game_engine_virtual_function_engine_state_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[4] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_shutdown_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[5] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_save_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[6] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_results_submission_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[7] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_pause_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[8] == custom_game_engine_host_vtable[__game_engine_virtual_function_function8]);
		DEBUG_ASSERT(__vtbl_dynamic_data[9] == custom_game_engine_host_vtable[__game_engine_virtual_function_function9]);
		DEBUG_ASSERT(__vtbl_dynamic_data[10] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_events_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[11] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_variant_save_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[12] == custom_game_engine_host_vtable[__game_engine_virtual_function_map_variant_save_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[13] == custom_game_engine_host_vtable[__game_engine_virtual_function_function13]);
		DEBUG_ASSERT(__vtbl_dynamic_data[14] == custom_game_engine_host_vtable[__game_engine_virtual_function_function14]);
		DEBUG_ASSERT(__vtbl_dynamic_data[15] == custom_game_engine_host_vtable[__game_engine_virtual_function_function15]);
		DEBUG_ASSERT(__vtbl_dynamic_data[16] == custom_game_engine_host_vtable[__game_engine_virtual_function_next_mission_info_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[17] == custom_game_engine_host_vtable[__game_engine_virtual_function_function17]);
		DEBUG_ASSERT(__vtbl_dynamic_data[18] == custom_game_engine_host_vtable[__game_engine_virtual_function_function18]);
		DEBUG_ASSERT(__vtbl_dynamic_data[19] == custom_game_engine_host_vtable[__game_engine_virtual_function_engine_load_status_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[20] == custom_game_engine_host_vtable[__game_engine_virtual_function_function20]);
		DEBUG_ASSERT(__vtbl_dynamic_data[21] == custom_game_engine_host_vtable[__game_engine_virtual_function_local_machine_identifier_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[22] == custom_game_engine_host_vtable[__game_engine_virtual_function_function22]);
		DEBUG_ASSERT(__vtbl_dynamic_data[23] == custom_game_engine_host_vtable[__game_engine_virtual_function_function23]);
		DEBUG_ASSERT(__vtbl_dynamic_data[24] == custom_game_engine_host_vtable[__game_engine_virtual_function_session_info_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[25] == custom_game_engine_host_vtable[__game_engine_virtual_function_session_membership_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[26] == custom_game_engine_host_vtable[__game_engine_virtual_function_function26]);
		DEBUG_ASSERT(__vtbl_dynamic_data[27] == custom_game_engine_host_vtable[__game_engine_virtual_function_function27]);
		DEBUG_ASSERT(__vtbl_dynamic_data[28] == custom_game_engine_host_vtable[__game_engine_virtual_function_graphical_settings_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[29] == custom_game_engine_host_vtable[__game_engine_virtual_function_player_configuration_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[30] == custom_game_engine_host_vtable[__game_engine_virtual_function_input_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[31] == custom_game_engine_host_vtable[__game_engine_virtual_function_function32]);
		DEBUG_ASSERT(__vtbl_dynamic_data[32] == custom_game_engine_host_vtable[__game_engine_virtual_function_function33]);
		DEBUG_ASSERT(__vtbl_dynamic_data[33] == custom_game_engine_host_vtable[__game_engine_virtual_function_xinput_set_state_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[34] == custom_game_engine_host_vtable[__game_engine_virtual_function_player_name_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[35] == custom_game_engine_host_vtable[__game_engine_virtual_function_function36]);
		DEBUG_ASSERT(__vtbl_dynamic_data[36] == custom_game_engine_host_vtable[__game_engine_virtual_function_function37]);
		DEBUG_ASSERT(__vtbl_dynamic_data[37] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_sendto_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[38] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_recvfrom_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[39] == custom_game_engine_host_vtable[__game_engine_virtual_function_function40]);
		DEBUG_ASSERT(__vtbl_dynamic_data[40] == custom_game_engine_host_vtable[__game_engine_virtual_function_function41]);
		DEBUG_ASSERT(__vtbl_dynamic_data[41] == custom_game_engine_host_vtable[__game_engine_virtual_function_function42]);
		DEBUG_ASSERT(__vtbl_dynamic_data[42] == custom_game_engine_host_vtable[__game_engine_virtual_function_firefight_new_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[43] == custom_game_engine_host_vtable[__game_engine_virtual_function_function44]);
		DEBUG_ASSERT(__vtbl_dynamic_data[44] == custom_game_engine_host_vtable[__game_engine_virtual_function_path_by_type_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[45] == custom_game_engine_host_vtable[__game_engine_virtual_function_wide_path_by_type_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[46] == custom_game_engine_host_vtable[__game_engine_virtual_function_function47]);
		DEBUG_ASSERT(__vtbl_dynamic_data[47] == custom_game_engine_host_vtable[__game_engine_virtual_function_function48]);
	}
	else if (build == _build_mcc_1_1350_0_0)
	{
		DEBUG_ASSERT(__vtbl_dynamic_data[0] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_begin]);
		DEBUG_ASSERT(__vtbl_dynamic_data[1] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_end]);
		DEBUG_ASSERT(__vtbl_dynamic_data[2] == custom_game_engine_host_vtable[__game_engine_virtual_function_function2]);
		DEBUG_ASSERT(__vtbl_dynamic_data[3] == custom_game_engine_host_vtable[__game_engine_virtual_function_engine_state_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[4] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_shutdown_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[5] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_save_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[6] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_results_submission_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[7] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_pause_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[8] == custom_game_engine_host_vtable[__game_engine_virtual_function_function8]);
		DEBUG_ASSERT(__vtbl_dynamic_data[9] == custom_game_engine_host_vtable[__game_engine_virtual_function_function9]);
		DEBUG_ASSERT(__vtbl_dynamic_data[10] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_events_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[11] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_variant_save_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[12] == custom_game_engine_host_vtable[__game_engine_virtual_function_map_variant_save_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[13] == custom_game_engine_host_vtable[__game_engine_virtual_function_function13]);
		DEBUG_ASSERT(__vtbl_dynamic_data[14] == custom_game_engine_host_vtable[__game_engine_virtual_function_function14]);
		DEBUG_ASSERT(__vtbl_dynamic_data[15] == custom_game_engine_host_vtable[__game_engine_virtual_function_function15]);
		DEBUG_ASSERT(__vtbl_dynamic_data[16] == custom_game_engine_host_vtable[__game_engine_virtual_function_next_mission_info_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[17] == custom_game_engine_host_vtable[__game_engine_virtual_function_function17]);
		DEBUG_ASSERT(__vtbl_dynamic_data[18] == custom_game_engine_host_vtable[__game_engine_virtual_function_function18]);
		DEBUG_ASSERT(__vtbl_dynamic_data[19] == custom_game_engine_host_vtable[__game_engine_virtual_function_engine_load_status_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[20] == custom_game_engine_host_vtable[__game_engine_virtual_function_function20]);
		DEBUG_ASSERT(__vtbl_dynamic_data[21] == custom_game_engine_host_vtable[__game_engine_virtual_function_local_machine_identifier_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[22] == custom_game_engine_host_vtable[__game_engine_virtual_function_function22]);
		DEBUG_ASSERT(__vtbl_dynamic_data[23] == custom_game_engine_host_vtable[__game_engine_virtual_function_function23]);
		DEBUG_ASSERT(__vtbl_dynamic_data[24] == custom_game_engine_host_vtable[__game_engine_virtual_function_session_info_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[25] == custom_game_engine_host_vtable[__game_engine_virtual_function_session_membership_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[26] == custom_game_engine_host_vtable[__game_engine_virtual_function_function26]);
		DEBUG_ASSERT(__vtbl_dynamic_data[27] == custom_game_engine_host_vtable[__game_engine_virtual_function_function27]);
		DEBUG_ASSERT(__vtbl_dynamic_data[28] == custom_game_engine_host_vtable[__game_engine_virtual_function_graphical_settings_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[29] == custom_game_engine_host_vtable[__game_engine_virtual_function_player_configuration_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[30] == custom_game_engine_host_vtable[__game_engine_virtual_function_player_configuration_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[31] == custom_game_engine_host_vtable[__game_engine_virtual_function_input_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[32] == custom_game_engine_host_vtable[__game_engine_virtual_function_function32]);
		DEBUG_ASSERT(__vtbl_dynamic_data[33] == custom_game_engine_host_vtable[__game_engine_virtual_function_function33]);
		DEBUG_ASSERT(__vtbl_dynamic_data[34] == custom_game_engine_host_vtable[__game_engine_virtual_function_xinput_set_state_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[35] == custom_game_engine_host_vtable[__game_engine_virtual_function_player_name_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[36] == custom_game_engine_host_vtable[__game_engine_virtual_function_function36]);
		DEBUG_ASSERT(__vtbl_dynamic_data[37] == custom_game_engine_host_vtable[__game_engine_virtual_function_function37]);
		DEBUG_ASSERT(__vtbl_dynamic_data[38] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_sendto_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[39] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_recvfrom_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[40] == custom_game_engine_host_vtable[__game_engine_virtual_function_function40]);
		DEBUG_ASSERT(__vtbl_dynamic_data[41] == custom_game_engine_host_vtable[__game_engine_virtual_function_function41]);
		DEBUG_ASSERT(__vtbl_dynamic_data[42] == custom_game_engine_host_vtable[__game_engine_virtual_function_function42]);
		DEBUG_ASSERT(__vtbl_dynamic_data[43] == custom_game_engine_host_vtable[__game_engine_virtual_function_firefight_new_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[44] == custom_game_engine_host_vtable[__game_engine_virtual_function_function44]);
		DEBUG_ASSERT(__vtbl_dynamic_data[45] == custom_game_engine_host_vtable[__game_engine_virtual_function_path_by_type_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[46] == custom_game_engine_host_vtable[__game_engine_virtual_function_wide_path_by_type_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[47] == custom_game_engine_host_vtable[__game_engine_virtual_function_function47]);
		DEBUG_ASSERT(__vtbl_dynamic_data[48] == custom_game_engine_host_vtable[__game_engine_virtual_function_function48]);
	}
	else if (build == _build_mcc_1_1367_0_0)
	{
		DEBUG_ASSERT(__vtbl_dynamic_data[0] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_begin]);
		DEBUG_ASSERT(__vtbl_dynamic_data[1] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_end]);
		DEBUG_ASSERT(__vtbl_dynamic_data[2] == custom_game_engine_host_vtable[__game_engine_virtual_function_function44]);
		DEBUG_ASSERT(__vtbl_dynamic_data[3] == custom_game_engine_host_vtable[__game_engine_virtual_function_function2]);
		DEBUG_ASSERT(__vtbl_dynamic_data[4] == custom_game_engine_host_vtable[__game_engine_virtual_function_engine_state_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[5] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_shutdown_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[6] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_save_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[7] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_results_submission_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[8] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_pause_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[9] == custom_game_engine_host_vtable[__game_engine_virtual_function_function8]);
		DEBUG_ASSERT(__vtbl_dynamic_data[10] == custom_game_engine_host_vtable[__game_engine_virtual_function_function9]);
		DEBUG_ASSERT(__vtbl_dynamic_data[11] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_events_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[12] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_variant_save_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[13] == custom_game_engine_host_vtable[__game_engine_virtual_function_map_variant_save_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[14] == custom_game_engine_host_vtable[__game_engine_virtual_function_function13]);
		DEBUG_ASSERT(__vtbl_dynamic_data[15] == custom_game_engine_host_vtable[__game_engine_virtual_function_function14]);
		DEBUG_ASSERT(__vtbl_dynamic_data[16] == custom_game_engine_host_vtable[__game_engine_virtual_function_function15]);
		DEBUG_ASSERT(__vtbl_dynamic_data[17] == custom_game_engine_host_vtable[__game_engine_virtual_function_next_mission_info_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[18] == custom_game_engine_host_vtable[__game_engine_virtual_function_function17]);
		DEBUG_ASSERT(__vtbl_dynamic_data[19] == custom_game_engine_host_vtable[__game_engine_virtual_function_function26]);
		DEBUG_ASSERT(__vtbl_dynamic_data[20] == custom_game_engine_host_vtable[__game_engine_virtual_function_function18]);
		DEBUG_ASSERT(__vtbl_dynamic_data[21] == custom_game_engine_host_vtable[__game_engine_virtual_function_engine_load_status_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[22] == custom_game_engine_host_vtable[__game_engine_virtual_function_function20]);
		DEBUG_ASSERT(__vtbl_dynamic_data[23] == custom_game_engine_host_vtable[__game_engine_virtual_function_local_machine_identifier_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[24] == custom_game_engine_host_vtable[__game_engine_virtual_function_function22]);
		DEBUG_ASSERT(__vtbl_dynamic_data[25] == custom_game_engine_host_vtable[__game_engine_virtual_function_function23]);
		DEBUG_ASSERT(__vtbl_dynamic_data[26] == custom_game_engine_host_vtable[__game_engine_virtual_function_session_info_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[27] == custom_game_engine_host_vtable[__game_engine_virtual_function_session_membership_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[28] == custom_game_engine_host_vtable[__game_engine_virtual_function_function27]);
		DEBUG_ASSERT(__vtbl_dynamic_data[29] == custom_game_engine_host_vtable[__game_engine_virtual_function_graphical_settings_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[30] == custom_game_engine_host_vtable[__game_engine_virtual_function_player_configuration_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[31] == custom_game_engine_host_vtable[__game_engine_virtual_function_player_configuration_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[32] == custom_game_engine_host_vtable[__game_engine_virtual_function_input_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[33] == custom_game_engine_host_vtable[__game_engine_virtual_function_function32]);
		DEBUG_ASSERT(__vtbl_dynamic_data[34] == custom_game_engine_host_vtable[__game_engine_virtual_function_function33]);
		DEBUG_ASSERT(__vtbl_dynamic_data[35] == custom_game_engine_host_vtable[__game_engine_virtual_function_xinput_set_state_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[36] == custom_game_engine_host_vtable[__game_engine_virtual_function_function37]);
		DEBUG_ASSERT(__vtbl_dynamic_data[37] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_sendto_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[38] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_recvfrom_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[39] == custom_game_engine_host_vtable[__game_engine_virtual_function_function41]);
		DEBUG_ASSERT(__vtbl_dynamic_data[40] == custom_game_engine_host_vtable[__game_engine_virtual_function_firefight_new_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[41] == custom_game_engine_host_vtable[__game_engine_virtual_function_path_by_type_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[42] == custom_game_engine_host_vtable[__game_engine_virtual_function_wide_path_by_type_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[43] == custom_game_engine_host_vtable[__game_engine_virtual_function_function47]);
		DEBUG_ASSERT(__vtbl_dynamic_data[44] == custom_game_engine_host_vtable[__game_engine_virtual_function_function48]);
		DEBUG_ASSERT(__vtbl_dynamic_data[45] == custom_game_engine_host_vtable[__game_engine_virtual_function_player_name_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[46] == custom_game_engine_host_vtable[__game_engine_virtual_function_function36]);
	}
	else if (build == _build_mcc_1_1377_0_0)
	{
		DEBUG_ASSERT(__vtbl_dynamic_data[0] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_begin]);
		DEBUG_ASSERT(__vtbl_dynamic_data[1] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_end]);
		DEBUG_ASSERT(__vtbl_dynamic_data[2] == custom_game_engine_host_vtable[__game_engine_virtual_function_function44]);
		DEBUG_ASSERT(__vtbl_dynamic_data[3] == custom_game_engine_host_vtable[__game_engine_virtual_function_function2]);
		DEBUG_ASSERT(__vtbl_dynamic_data[4] == custom_game_engine_host_vtable[__game_engine_virtual_function_engine_state_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[5] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_shutdown_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[6] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_save_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[7] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_results_submission_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[8] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_pause_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[9] == custom_game_engine_host_vtable[__game_engine_virtual_function_function8]);
		DEBUG_ASSERT(__vtbl_dynamic_data[10] == custom_game_engine_host_vtable[__game_engine_virtual_function_function9]);
		DEBUG_ASSERT(__vtbl_dynamic_data[11] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_events_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[12] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_variant_save_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[13] == custom_game_engine_host_vtable[__game_engine_virtual_function_map_variant_save_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[14] == custom_game_engine_host_vtable[__game_engine_virtual_function_function13]);
		DEBUG_ASSERT(__vtbl_dynamic_data[15] == custom_game_engine_host_vtable[__game_engine_virtual_function_function14]);
		DEBUG_ASSERT(__vtbl_dynamic_data[16] == custom_game_engine_host_vtable[__game_engine_virtual_function_function15]);
		DEBUG_ASSERT(__vtbl_dynamic_data[17] == custom_game_engine_host_vtable[__game_engine_virtual_function_next_mission_info_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[18] == custom_game_engine_host_vtable[__game_engine_virtual_function_function17]);
		DEBUG_ASSERT(__vtbl_dynamic_data[19] == custom_game_engine_host_vtable[__game_engine_virtual_function_function26]);
		DEBUG_ASSERT(__vtbl_dynamic_data[20] == custom_game_engine_host_vtable[__game_engine_virtual_function_function18]);
		DEBUG_ASSERT(__vtbl_dynamic_data[21] == custom_game_engine_host_vtable[__game_engine_virtual_function_engine_load_status_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[22] == custom_game_engine_host_vtable[__game_engine_virtual_function_function20]);
		DEBUG_ASSERT(__vtbl_dynamic_data[23] == custom_game_engine_host_vtable[__game_engine_virtual_function_local_machine_identifier_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[24] == custom_game_engine_host_vtable[__game_engine_virtual_function_function22]);
		DEBUG_ASSERT(__vtbl_dynamic_data[25] == custom_game_engine_host_vtable[__game_engine_virtual_function_function23]);
		DEBUG_ASSERT(__vtbl_dynamic_data[26] == custom_game_engine_host_vtable[__game_engine_virtual_function_session_info_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[27] == custom_game_engine_host_vtable[__game_engine_virtual_function_session_membership_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[28] == custom_game_engine_host_vtable[__game_engine_virtual_function_function27]);
		DEBUG_ASSERT(__vtbl_dynamic_data[29] == custom_game_engine_host_vtable[__game_engine_virtual_function_graphical_settings_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[30] == custom_game_engine_host_vtable[__game_engine_virtual_function_player_configuration_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[31] == custom_game_engine_host_vtable[__game_engine_virtual_function_player_configuration_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[32] == custom_game_engine_host_vtable[__game_engine_virtual_function_input_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[33] == custom_game_engine_host_vtable[__game_engine_virtual_function_function32]);
		DEBUG_ASSERT(__vtbl_dynamic_data[34] == custom_game_engine_host_vtable[__game_engine_virtual_function_function33]);
		DEBUG_ASSERT(__vtbl_dynamic_data[35] == custom_game_engine_host_vtable[__game_engine_virtual_function_xinput_set_state_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[36] == custom_game_engine_host_vtable[__game_engine_virtual_function_function37]);
		DEBUG_ASSERT(__vtbl_dynamic_data[37] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_sendto_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[38] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_recvfrom_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[39] == custom_game_engine_host_vtable[__game_engine_virtual_function_function41]);
		DEBUG_ASSERT(__vtbl_dynamic_data[40] == custom_game_engine_host_vtable[__game_engine_virtual_function_firefight_new_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[41] == custom_game_engine_host_vtable[__game_engine_virtual_function_path_by_type_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[42] == custom_game_engine_host_vtable[__game_engine_virtual_function_wide_path_by_type_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[43] == custom_game_engine_host_vtable[__game_engine_virtual_function_function47]);
		DEBUG_ASSERT(__vtbl_dynamic_data[44] == custom_game_engine_host_vtable[__game_engine_virtual_function_function48]);
		DEBUG_ASSERT(__vtbl_dynamic_data[45] == custom_game_engine_host_vtable[__game_engine_virtual_function_function49]);
		DEBUG_ASSERT(__vtbl_dynamic_data[46] == custom_game_engine_host_vtable[__game_engine_virtual_function_player_name_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[47] == custom_game_engine_host_vtable[__game_engine_virtual_function_function36]);
	}
	else if (build == _build_mcc_1_1629_0_0)
	{
		DEBUG_ASSERT(__vtbl_dynamic_data[0] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_begin]);
		DEBUG_ASSERT(__vtbl_dynamic_data[1] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_end]);
		DEBUG_ASSERT(__vtbl_dynamic_data[2] == custom_game_engine_host_vtable[__game_engine_virtual_function_function44]);
		DEBUG_ASSERT(__vtbl_dynamic_data[3] == custom_game_engine_host_vtable[__game_engine_virtual_function_function2]);
		DEBUG_ASSERT(__vtbl_dynamic_data[4] == custom_game_engine_host_vtable[__game_engine_virtual_function_engine_state_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[5] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_shutdown_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[6] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_save_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[7] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_results_submission_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[8] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_pause_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[9] == custom_game_engine_host_vtable[__game_engine_virtual_function_function8]);
		DEBUG_ASSERT(__vtbl_dynamic_data[10] == custom_game_engine_host_vtable[__game_engine_virtual_function_function9]);
		DEBUG_ASSERT(__vtbl_dynamic_data[11] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_events_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[12] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_variant_save_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[13] == custom_game_engine_host_vtable[__game_engine_virtual_function_map_variant_save_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[14] == custom_game_engine_host_vtable[__game_engine_virtual_function_function13]);
		DEBUG_ASSERT(__vtbl_dynamic_data[15] == custom_game_engine_host_vtable[__game_engine_virtual_function_function14]);
		DEBUG_ASSERT(__vtbl_dynamic_data[16] == custom_game_engine_host_vtable[__game_engine_virtual_function_function15]);
		DEBUG_ASSERT(__vtbl_dynamic_data[17] == custom_game_engine_host_vtable[__game_engine_virtual_function_next_mission_info_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[18] == custom_game_engine_host_vtable[__game_engine_virtual_function_function17]);
		DEBUG_ASSERT(__vtbl_dynamic_data[19] == custom_game_engine_host_vtable[__game_engine_virtual_function_function26]);
		DEBUG_ASSERT(__vtbl_dynamic_data[20] == custom_game_engine_host_vtable[__game_engine_virtual_function_function18]);
		DEBUG_ASSERT(__vtbl_dynamic_data[21] == custom_game_engine_host_vtable[__game_engine_virtual_function_engine_load_status_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[22] == custom_game_engine_host_vtable[__game_engine_virtual_function_function20]);
		DEBUG_ASSERT(__vtbl_dynamic_data[23] == custom_game_engine_host_vtable[__game_engine_virtual_function_local_machine_identifier_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[24] == custom_game_engine_host_vtable[__game_engine_virtual_function_function22]);
		DEBUG_ASSERT(__vtbl_dynamic_data[25] == custom_game_engine_host_vtable[__game_engine_virtual_function_function23]);
		DEBUG_ASSERT(__vtbl_dynamic_data[26] == custom_game_engine_host_vtable[__game_engine_virtual_function_session_info_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[27] == custom_game_engine_host_vtable[__game_engine_virtual_function_session_membership_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[28] == custom_game_engine_host_vtable[__game_engine_virtual_function_function27]);
		DEBUG_ASSERT(__vtbl_dynamic_data[29] == custom_game_engine_host_vtable[__game_engine_virtual_function_graphical_settings_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[30] == custom_game_engine_host_vtable[__game_engine_virtual_function_player_configuration_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[31] == custom_game_engine_host_vtable[__game_engine_virtual_function_player_configuration_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[32] == custom_game_engine_host_vtable[__game_engine_virtual_function_input_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[33] == custom_game_engine_host_vtable[__game_engine_virtual_function_function32]);
		DEBUG_ASSERT(__vtbl_dynamic_data[34] == custom_game_engine_host_vtable[__game_engine_virtual_function_function33]);
		DEBUG_ASSERT(__vtbl_dynamic_data[35] == custom_game_engine_host_vtable[__game_engine_virtual_function_xinput_set_state_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[36] == custom_game_engine_host_vtable[__game_engine_virtual_function_function37]);
		DEBUG_ASSERT(__vtbl_dynamic_data[37] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_sendto_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[38] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_recvfrom_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[39] == custom_game_engine_host_vtable[__game_engine_virtual_function_function41]);
		DEBUG_ASSERT(__vtbl_dynamic_data[40] == custom_game_engine_host_vtable[__game_engine_virtual_function_firefight_new_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[41] == custom_game_engine_host_vtable[__game_engine_virtual_function_path_by_type_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[42] == custom_game_engine_host_vtable[__game_engine_virtual_function_wide_path_by_type_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[43] == custom_game_engine_host_vtable[__game_engine_virtual_function_function47]);
		DEBUG_ASSERT(__vtbl_dynamic_data[44] == custom_game_engine_host_vtable[__game_engine_virtual_function_function48]);
		DEBUG_ASSERT(__vtbl_dynamic_data[45] == custom_game_engine_host_vtable[__game_engine_virtual_function_function49]);
		DEBUG_ASSERT(__vtbl_dynamic_data[46] == custom_game_engine_host_vtable[__game_engine_virtual_function_player_name_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[47] == custom_game_engine_host_vtable[__game_engine_virtual_function_function36]);
		DEBUG_ASSERT(__vtbl_dynamic_data[48] == custom_game_engine_host_vtable[__game_engine_virtual_function_function50]);
		DEBUG_ASSERT(__vtbl_dynamic_data[49] == custom_game_engine_host_vtable[__game_engine_virtual_function_function51]);
	}
	else if (build == _build_mcc_1_1658_0_0)
	{
		DEBUG_ASSERT(__vtbl_dynamic_data[0] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_begin]);
		DEBUG_ASSERT(__vtbl_dynamic_data[1] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_end]);
		DEBUG_ASSERT(__vtbl_dynamic_data[2] == custom_game_engine_host_vtable[__game_engine_virtual_function_function44]);
		DEBUG_ASSERT(__vtbl_dynamic_data[3] == custom_game_engine_host_vtable[__game_engine_virtual_function_function2]);
		DEBUG_ASSERT(__vtbl_dynamic_data[4] == custom_game_engine_host_vtable[__game_engine_virtual_function_engine_state_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[5] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_shutdown_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[6] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_save_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[7] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_results_submission_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[8] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_pause_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[9] == custom_game_engine_host_vtable[__game_engine_virtual_function_function8]);
		DEBUG_ASSERT(__vtbl_dynamic_data[10] == custom_game_engine_host_vtable[__game_engine_virtual_function_function9]);
		DEBUG_ASSERT(__vtbl_dynamic_data[11] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_events_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[12] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_variant_save_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[13] == custom_game_engine_host_vtable[__game_engine_virtual_function_map_variant_save_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[14] == custom_game_engine_host_vtable[__game_engine_virtual_function_function13]);
		DEBUG_ASSERT(__vtbl_dynamic_data[15] == custom_game_engine_host_vtable[__game_engine_virtual_function_function14]);
		DEBUG_ASSERT(__vtbl_dynamic_data[16] == custom_game_engine_host_vtable[__game_engine_virtual_function_function15]);
		DEBUG_ASSERT(__vtbl_dynamic_data[17] == custom_game_engine_host_vtable[__game_engine_virtual_function_next_mission_info_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[18] == custom_game_engine_host_vtable[__game_engine_virtual_function_function17]);
		DEBUG_ASSERT(__vtbl_dynamic_data[19] == custom_game_engine_host_vtable[__game_engine_virtual_function_function26]);
		DEBUG_ASSERT(__vtbl_dynamic_data[20] == custom_game_engine_host_vtable[__game_engine_virtual_function_function18]);
		DEBUG_ASSERT(__vtbl_dynamic_data[21] == custom_game_engine_host_vtable[__game_engine_virtual_function_engine_load_status_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[22] == custom_game_engine_host_vtable[__game_engine_virtual_function_function20]);
		DEBUG_ASSERT(__vtbl_dynamic_data[23] == custom_game_engine_host_vtable[__game_engine_virtual_function_local_machine_identifier_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[24] == custom_game_engine_host_vtable[__game_engine_virtual_function_function22]);
		DEBUG_ASSERT(__vtbl_dynamic_data[25] == custom_game_engine_host_vtable[__game_engine_virtual_function_function23]);
		DEBUG_ASSERT(__vtbl_dynamic_data[26] == custom_game_engine_host_vtable[__game_engine_virtual_function_session_info_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[27] == custom_game_engine_host_vtable[__game_engine_virtual_function_session_membership_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[28] == custom_game_engine_host_vtable[__game_engine_virtual_function_function27]);
		DEBUG_ASSERT(__vtbl_dynamic_data[29] == custom_game_engine_host_vtable[__game_engine_virtual_function_graphical_settings_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[30] == custom_game_engine_host_vtable[__game_engine_virtual_function_player_configuration_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[31] == custom_game_engine_host_vtable[__game_engine_virtual_function_player_configuration_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[32] == custom_game_engine_host_vtable[__game_engine_virtual_function_input_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[33] == custom_game_engine_host_vtable[__game_engine_virtual_function_function32]);
		DEBUG_ASSERT(__vtbl_dynamic_data[34] == custom_game_engine_host_vtable[__game_engine_virtual_function_function33]);
		DEBUG_ASSERT(__vtbl_dynamic_data[35] == custom_game_engine_host_vtable[__game_engine_virtual_function_xinput_set_state_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[36] == custom_game_engine_host_vtable[__game_engine_virtual_function_function37]);
		DEBUG_ASSERT(__vtbl_dynamic_data[37] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_sendto_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[38] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_recvfrom_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[39] == custom_game_engine_host_vtable[__game_engine_virtual_function_function41]);
		DEBUG_ASSERT(__vtbl_dynamic_data[40] == custom_game_engine_host_vtable[__game_engine_virtual_function_firefight_new_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[41] == custom_game_engine_host_vtable[__game_engine_virtual_function_path_by_type_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[42] == custom_game_engine_host_vtable[__game_engine_virtual_function_wide_path_by_type_get]);
		DEBUG_ASSERT(__vtbl_dynamic_data[43] == custom_game_engine_host_vtable[__game_engine_virtual_function_function47]);
		DEBUG_ASSERT(__vtbl_dynamic_data[44] == custom_game_engine_host_vtable[__game_engine_virtual_function_function48]);
		DEBUG_ASSERT(__vtbl_dynamic_data[45] == custom_game_engine_host_vtable[__game_engine_virtual_function_function49]);
		DEBUG_ASSERT(__vtbl_dynamic_data[46] == custom_game_engine_host_vtable[__game_engine_virtual_function_player_name_update_handler]);
		DEBUG_ASSERT(__vtbl_dynamic_data[47] == custom_game_engine_host_vtable[__game_engine_virtual_function_function36]);
		DEBUG_ASSERT(__vtbl_dynamic_data[48] == custom_game_engine_host_vtable[__game_engine_virtual_function_function50]);
		DEBUG_ASSERT(__vtbl_dynamic_data[49] == custom_game_engine_host_vtable[__game_engine_virtual_function_function51]);
		DEBUG_ASSERT(__vtbl_dynamic_data[50] == custom_game_engine_host_vtable[__game_engine_virtual_function_function52]);
		DEBUG_ASSERT(__vtbl_dynamic_data[51] == custom_game_engine_host_vtable[__game_engine_virtual_function_function53]);
	}

	switch (build)
	{
	case _build_mcc_1_824_0_0: DEBUG_ASSERT(current_function_index == 43); break;
	case _build_mcc_1_887_0_0: DEBUG_ASSERT(current_function_index == 43); break;
	case _build_mcc_1_1035_0_0: DEBUG_ASSERT(current_function_index == 44); break;
	case _build_mcc_1_1186_0_0: DEBUG_ASSERT(current_function_index == 47); break;
	case _build_mcc_1_1211_0_0: DEBUG_ASSERT(current_function_index == 47); break;
	case _build_mcc_1_1246_0_0: DEBUG_ASSERT(current_function_index == 48); break;
	case _build_mcc_1_1270_0_0: DEBUG_ASSERT(current_function_index == 48); break;
	case _build_mcc_1_1305_0_0: DEBUG_ASSERT(current_function_index == 48); break;
	case _build_mcc_1_1350_0_0: DEBUG_ASSERT(current_function_index == 49); break;
	case _build_mcc_1_1367_0_0: DEBUG_ASSERT(current_function_index == 47); break;
	case _build_mcc_1_1377_0_0: DEBUG_ASSERT(current_function_index == 48); break;
	case _build_mcc_1_1384_0_0: DEBUG_ASSERT(current_function_index == 48); break;
	case _build_mcc_1_1387_0_0: DEBUG_ASSERT(current_function_index == 48); break;
	case _build_mcc_1_1389_0_0: DEBUG_ASSERT(current_function_index == 48); break;
	case _build_mcc_1_1477_0_0: DEBUG_ASSERT(current_function_index == 48); break;
	case _build_mcc_1_1499_0_0: DEBUG_ASSERT(current_function_index == 48); break;
	case _build_mcc_1_1520_0_0: DEBUG_ASSERT(current_function_index == 48); break;
	case _build_mcc_1_1570_0_0: DEBUG_ASSERT(current_function_index == 48); break;
	case _build_mcc_1_1619_0_0: DEBUG_ASSERT(current_function_index == 48); break;
	case _build_mcc_1_1629_0_0: DEBUG_ASSERT(current_function_index == 50); break;
	case _build_mcc_1_1658_0_0: DEBUG_ASSERT(current_function_index == 52); break;
	}
}

bool IGameEngineHost::PlayerConfigurationFromBuild(e_build build, c_player_configuration **player_configuration)
{
	ASSERT(build != e_build::_build_not_set);
	ASSERT(player_configuration != nullptr);

	switch (build)
	{
	case _build_mcc_1_824_0_0:
	case _build_mcc_1_887_0_0:
		*player_configuration = new c_player_configuration(e_player_configuration_version::_player_configuration_version_1);
		break;
	case _build_mcc_1_1035_0_0:
		*player_configuration = new c_player_configuration(e_player_configuration_version::_player_configuration_version_2);
		break;
	case _build_mcc_1_1186_0_0:
	case _build_mcc_1_1211_0_0:
	case _build_mcc_1_1246_0_0:
	case _build_mcc_1_1270_0_0:
	case _build_mcc_1_1305_0_0:
		*player_configuration = new c_player_configuration(e_player_configuration_version::_player_configuration_version_3);
		break;
	case _build_mcc_1_1350_0_0:
		*player_configuration = new c_player_configuration(e_player_configuration_version::_player_configuration_version_4);
		break;
	case _build_mcc_1_1367_0_0:
	case _build_mcc_1_1377_0_0:
	case _build_mcc_1_1384_0_0:
	case _build_mcc_1_1387_0_0:
	case _build_mcc_1_1389_0_0:
		*player_configuration = new c_player_configuration(e_player_configuration_version::_player_configuration_version_5);
		break;
	case _build_mcc_1_1477_0_0:
	case _build_mcc_1_1499_0_0:
	case _build_mcc_1_1520_0_0:
	case _build_mcc_1_1619_0_0:
		*player_configuration = new c_player_configuration(e_player_configuration_version::_player_configuration_version_6);
		break;
	case _build_mcc_1_1629_0_0:
	case _build_mcc_1_1658_0_0:
		*player_configuration = new c_player_configuration(e_player_configuration_version::_player_configuration_version_7);
		break;
	default:
		*player_configuration = new c_player_configuration(e_player_configuration_version::_player_configuration_version_7);
		break;
	}

	if (!is_valid(*player_configuration))
	{
		return false;
	}

	return true;
}

void IGameEngineHost::ConfigurePlayerConfiguration(c_player_configuration& player_configuration)
{
	player_configuration.subtitle_setting = 1;
	player_configuration.crosshair_location = 1;
	player_configuration.fov_setting = 90;

	player_configuration.look_controls_inverted = false;
	player_configuration.vibration_disabled = false;
	player_configuration.impulse_triggers_disabled = false;
	player_configuration.arcraft_controls_inverted = false;
	player_configuration.auto_center_enabled = false;
	player_configuration.crouch_lock_enabled = false;
	player_configuration.clench_protection_enabled = false;
	player_configuration.use_female_voice = true;
	player_configuration.hold_to_zoom = true;
	//player_configuration.player_model_primary_color_index = ;
	//player_configuration.player_model_secondary_color_index = ;
	//player_configuration.player_model_tertiary_color_index = ;
	player_configuration.use_elite_model = false;
	//player_configuration.player_model_permutation = ;

	if (player_configuration.player_configuration_version >= e_player_configuration_version::_player_configuration_version_2)
	{
		player_configuration.vehicle_fov_setting = 100;
		player_configuration.mouse_look_controls_inverted = false;
		player_configuration.mouse_arcraft_controls_inverted = false;
		player_configuration.mk_crouch_lock_enabled = false;

		if (engine_type == _engine_type_haloreach)
		{
			player_configuration.helmet_index = underlying_cast(e_customization_item_v1::HR_Helmet_EOD_Base);
			player_configuration.left_shoulder_index = underlying_cast(e_customization_item_v1::HR_LeftShoulder_Gungnir);
			player_configuration.right_shoulder_index = underlying_cast(e_customization_item_v1::HR_RightShoulder_EVA);
			player_configuration.chest_index = underlying_cast(e_customization_item_v1::HR_Chest_UABaseSecurityW);
			player_configuration.wrist_index = underlying_cast(e_customization_item_v1::HR_Wrist_Default);
			player_configuration.utility_index = underlying_cast(e_customization_item_v1::HR_Utility_Default);
			player_configuration.knee_guards_index = underlying_cast(e_customization_item_v1::HR_KneeGuards_FJPARA);
			player_configuration.visor_color_index = underlying_cast(e_customization_item_v1::HR_VisorColor_Blue);
			player_configuration.spartan_armor_effect_index = underlying_cast(e_customization_item_v1::HR_ArmorEffect_BlueFlames);
			player_configuration.spartan_body_index = underlying_cast(e_customization_item_v1::HR_Spartan_Female);
			player_configuration.elite_armor_index = underlying_cast(e_customization_item_v1::HR_Elite_FieldMarshall);
			player_configuration.elite_armor_effect_index = underlying_cast(e_customization_item_v1::HR_ArmorEffect_Pestilence);
			player_configuration.voice_index = underlying_cast(e_customization_item_v1::HR_FirefightVoice_JohnS117);
			player_configuration.player_model_primary_color = underlying_cast(e_customization_item_v1::HR_Color_Brick);
			player_configuration.player_model_secondary_color = underlying_cast(e_customization_item_v1::HR_Color_Cyan);
			player_configuration.player_model_tertiary_color = underlying_cast(e_customization_item_v1::HR_Color_Cyan);
		}
		else if (engine_type == _engine_type_halo1)
		{
			player_configuration.helmet_index = underlying_cast(e_customization_item_v1::k_customization_item_none);
			player_configuration.left_shoulder_index = underlying_cast(e_customization_item_v1::k_customization_item_none);
			player_configuration.right_shoulder_index = underlying_cast(e_customization_item_v1::k_customization_item_none);
			player_configuration.chest_index = underlying_cast(e_customization_item_v1::k_customization_item_none);
			player_configuration.wrist_index = underlying_cast(e_customization_item_v1::k_customization_item_none);
			player_configuration.utility_index = underlying_cast(e_customization_item_v1::k_customization_item_none);
			player_configuration.knee_guards_index = underlying_cast(e_customization_item_v1::k_customization_item_none);
			player_configuration.visor_color_index = underlying_cast(e_customization_item_v1::k_customization_item_none);
			player_configuration.spartan_armor_effect_index = underlying_cast(e_customization_item_v1::k_customization_item_none);
			player_configuration.spartan_body_index = underlying_cast(e_customization_item_v1::k_customization_item_none);
			player_configuration.elite_armor_index = underlying_cast(e_customization_item_v1::k_customization_item_none);
			player_configuration.elite_armor_effect_index = underlying_cast(e_customization_item_v1::k_customization_item_none);
			player_configuration.voice_index = underlying_cast(e_customization_item_v1::k_customization_item_none);
			player_configuration.player_model_primary_color = underlying_cast(e_customization_item_v1::H1_Color_1);
			player_configuration.player_model_secondary_color = underlying_cast(e_customization_item_v1::H1_Color_1);
			player_configuration.player_model_tertiary_color = underlying_cast(e_customization_item_v1::H1_Color_1);
		}
		else if (engine_type == _engine_type_groundhog)
		{
			player_configuration.helmet_index = underlying_cast(e_customization_item_v1::H2A_ARMOR0_MARKVI);
			player_configuration.left_shoulder_index = underlying_cast(e_customization_item_v1::H2A_ARMOR0_MARKVI);
			player_configuration.right_shoulder_index = underlying_cast(e_customization_item_v1::H2A_ARMOR0_MARKVI);
			player_configuration.chest_index = underlying_cast(e_customization_item_v1::H2A_ARMOR0_MARKVI);
			player_configuration.wrist_index = underlying_cast(e_customization_item_v1::H2A_ARMOR0_MARKVI);
			player_configuration.utility_index = underlying_cast(e_customization_item_v1::H2A_ARMOR0_MARKVI);
			player_configuration.knee_guards_index = underlying_cast(e_customization_item_v1::H2A_ARMOR0_MARKVI);
			player_configuration.visor_color_index = underlying_cast(e_customization_item_v1::H2A_ARMOR0_MARKVI);
			player_configuration.spartan_armor_effect_index = underlying_cast(e_customization_item_v1::H2A_ARMOR0_MARKVI);
			player_configuration.spartan_body_index = underlying_cast(e_customization_item_v1::HR_Spartan_Female);
			player_configuration.elite_armor_index = underlying_cast(e_customization_item_v1::H2A_ARMOR_ELITE1);
			player_configuration.elite_armor_effect_index = underlying_cast(e_customization_item_v1::k_customization_item_none);
			player_configuration.voice_index = underlying_cast(e_customization_item_v1::k_customization_item_none);
			player_configuration.player_model_primary_color = underlying_cast(e_customization_item_v1::H2A_Color_1);
			player_configuration.player_model_secondary_color = underlying_cast(e_customization_item_v1::H2A_Color_1);
			player_configuration.player_model_tertiary_color = underlying_cast(e_customization_item_v1::H2A_Color_1);
		}
	}

	if (is_valid(player_configuration.users_skins_enabled) && player_configuration.users_skins_enabled && player_configuration.player_configuration_version >= e_player_configuration_version::_player_configuration_version_7)
	{
		for (int i = 0; i < 15; i++)
		{
			player_configuration.customization_item_skins[i] = { 0, 0 };
		}
	}


	c_settings::read_wstring(_settings_section_player, "service_tag", player_configuration.service_tag, 4, L"117");
	player_configuration.online_medal_flasher = false;
	//player_configuration.vertical_look_sensitivity = ;
	//player_configuration.horizontal_look_sensitivity = ;
	//player_configuration.look_acceleration = ;
	//player_configuration.look_axial_dead_zone = ;
	//player_configuration.look_radial_dead_zone = ;
	//player_configuration.zoom_look_sensitivity_multiplier = ;
	//player_configuration.vehicle_look_sensitivity_multiplier = ;
	//player_configuration.button_preset = ;
	//player_configuration.stick_preset = ;
	//player_configuration.lefty_toggle = ;
	//player_configuration.flying_camera_turn_sensitivity = ;
	//player_configuration.flying_camera_panning = ;
	//player_configuration.flying_camera_speed = ;
	//player_configuration.flying_camera_thrust = ;
	//player_configuration.theater_turn_sensitivity = ;
	//player_configuration.theater_panning = ;
	//player_configuration.theater_speed = ;
	//player_configuration.theater_thrust = ;
	//player_configuration.swap_triggers_and_bumpers = ;
	//player_configuration.use_modern_aim_control = ;
	player_configuration.use_double_press_jump_to_jetpack = true;
	//player_configuration.enemy_player_name_color = ;
	//player_configuration.game_engine_timer = ;
	//player_configuration.Loadouts[5];
	//player_configuration.game_specific[256];
	//player_configuration.mouse_sensitivity = ;
	//player_configuration.mouse_smoothing = ;
	//player_configuration.mouse_acceleration = ;
	//player_configuration.mouse_acceleration_min_rate = ;
	//player_configuration.mouse_acceleration_max_accel = ;
	//player_configuration.mouse_acceleration_scale = ;
	//player_configuration.mouse_acceleration_exp = ;
	//player_configuration.keyboard_mouse_button_preset = ;

	long game_action_count = e_game_action::k_number_of_game_actions;

	switch (player_configuration.player_configuration_version)
	{
	case _player_configuration_version_1:
	case _player_configuration_version_2:
		game_action_count = k_number_of_game_actions_v1;
		break;
	case _player_configuration_version_3:
		game_action_count = k_number_of_game_actions_v2;
		break;
	case _player_configuration_version_4:
		game_action_count = k_number_of_game_actions_v3;
		break;
	case _player_configuration_version_5:
		game_action_count = k_number_of_game_actions_v4;
		break;
	case _player_configuration_version_6:
		game_action_count = k_number_of_game_actions_v5;
		break;
	case _player_configuration_version_7:
		game_action_count = k_number_of_game_actions_v6;
		break;
	}

	for (long mapping_index = 0; mapping_index < game_action_count; mapping_index++)
	{
		player_configuration.game_keyboard_mouse_mappings[mapping_index].abstract_button = mapping_index;
	}

	if (game_action_count >= k_number_of_game_actions_v1)
	{
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_jump].virtual_key_codes[0] = VK_SPACE;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_switch_grenade].virtual_key_codes[0] = 'G';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_context_primary].virtual_key_codes[0] = 'E';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_reload].virtual_key_codes[0] = 'R';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_switch_weapon].virtual_key_codes[0] = 'C';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_melee].virtual_key_codes[0] = 'V';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_flashlight].virtual_key_codes[0] = '4';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_throw_grenade].virtual_key_codes[0] = 'F';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_fire].virtual_key_codes[0] = VK_LBUTTON;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_crouch].virtual_key_codes[0] = VK_LCONTROL;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_zoom].virtual_key_codes[0] = VK_RBUTTON;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_zoom_in].virtual_key_codes[0] = 'Z';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_zoom_out].virtual_key_codes[0] = 'X';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_exchange_weapon].virtual_key_codes[0] = 'E';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_trick].virtual_key_codes[0] = VK_SPACE;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_brake].virtual_key_codes[0] = VK_LSHIFT;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_ebrake].virtual_key_codes[0] = VK_SPACE;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_sprint].virtual_key_codes[0] = VK_LSHIFT;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_banshee_bomb].virtual_key_codes[0] = 'F';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_forward].virtual_key_codes[0] = 'W';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_backward].virtual_key_codes[0] = 'S';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_left].virtual_key_codes[0] = 'A';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_right].virtual_key_codes[0] = 'D';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_lean_left].virtual_key_codes[0] = '8';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_lean_right].virtual_key_codes[0] = '9';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_start].virtual_key_codes[0] = '7';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_back].virtual_key_codes[0] = VK_TAB;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_show_scores].virtual_key_codes[0] = VK_TAB;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_accept].virtual_key_codes[0] = '5';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_cancel].virtual_key_codes[0] = '6';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_primary_vehicle_trick].virtual_key_codes[0] = VK_LCONTROL;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_secondary_vehicle_trick].virtual_key_codes[0] = VK_SPACE;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_magnify_zoom].virtual_key_codes[0] = 'Z';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v1_equipment].virtual_key_codes[0] = VK_LSHIFT;
	}
	if (game_action_count >= k_number_of_game_actions_v2)
	{
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v2_fire_secondary].virtual_key_codes[0] = VK_LSHIFT;
	}
	if (game_action_count >= k_number_of_game_actions_v3)
	{
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_lift_editor].virtual_key_codes[0] = 'R';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_drop_editor].virtual_key_codes[0] = 'F';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_grab_object_editor].virtual_key_codes[0] = VK_LBUTTON;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_boost_editor].virtual_key_codes[0] = VK_LSHIFT;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_crouch_editor].virtual_key_codes[0] = VK_LCONTROL;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_delete_object_editor].virtual_key_codes[0] = VK_DELETE;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_create_object_editor].virtual_key_codes[0] = VK_SPACE;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_open_tool_menu_editor].virtual_key_codes[0] = 'X';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_switch_player_mode_editor].virtual_key_codes[0] = VK_UP;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_scope_zoom_editor].virtual_key_codes[0] = VK_RBUTTON;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_player_lock_for_manipulation_editor].virtual_key_codes[0] = VK_LMENU;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_show_hide_pannel_theater].virtual_key_codes[0] = 'X';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_show_hide_interface_theater].virtual_key_codes[0] = 'Z';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_toggle_first_third_person_view_theater].virtual_key_codes[0] = 'C';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_camera_focus_theater].virtual_key_codes[0] = VK_RBUTTON;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_fast_forward_theater].virtual_key_codes[0] = VK_RIGHT;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_fast_rewind_theater].virtual_key_codes[0] = VK_LEFT;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_stop_continue_playback_theater].virtual_key_codes[0] = VK_RETURN;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_playback_speed_up_theater].virtual_key_codes[0] = VK_LMENU;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v3_enter_free_camera_mode_theater].virtual_key_codes[0] = VK_SPACE;
	}
	if (game_action_count >= k_number_of_game_actions_v4)
	{
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v4_movement_speed_up_theater].virtual_key_codes[0] = VK_LSHIFT;
	}
	if (game_action_count >= k_number_of_game_actions_v5)
	{
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v5_panning_camera_theater].virtual_key_codes[0] = VK_OEM_RESET;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v5_camera_move_up_theater].virtual_key_codes[0] = 'Q';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v5_camera_move_down_theater].virtual_key_codes[0] = 'E';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v5_dual_wield].virtual_key_codes[0] = 'Q';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v5_zoom_camera_theater].virtual_key_codes[0] = VK_OEM_RESET;
	}
	if (game_action_count >= k_number_of_game_actions_v6)
	{
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v6_toggle_rotation_axes_editor].virtual_key_codes[0] = 'O';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v6_show_hide_pannel_theater].virtual_key_codes[0] = 'X';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v6_show_hide_interface_theater].virtual_key_codes[0] = 'Z';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v6_toggle_first_third_person_view_theater].virtual_key_codes[0] = 'C';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v6_camera_focus_theater].virtual_key_codes[0] = VK_RBUTTON;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v6_fast_forward_theater].virtual_key_codes[0] = VK_RIGHT;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v6_fast_rewind_theater].virtual_key_codes[0] = VK_LEFT;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v6_stop_continue_playback_theater].virtual_key_codes[0] = VK_RETURN;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v6_playback_speed_up_theater].virtual_key_codes[0] = VK_LMENU;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v6_enter_free_camera_mode_theater].virtual_key_codes[0] = VK_SPACE;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v6_movement_speed_up_theater].virtual_key_codes[0] = VK_LSHIFT;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v6_panning_camera_theater].virtual_key_codes[0] = VK_OEM_RESET;
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v6_camera_move_up_theater].virtual_key_codes[0] = 'Q';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v6_camera_move_down_theater].virtual_key_codes[0] = 'E';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v6_dual_wield].virtual_key_codes[0] = 'Q';
		player_configuration.game_keyboard_mouse_mappings[e_game_action::_game_action_v6_zoom_camera_theater].virtual_key_codes[0] = VK_OEM_RESET;
	}

	player_configuration.master_volume = 60;
	player_configuration.music_volume = 20;
	player_configuration.sfx_volume = 80;
	//player_configuration.brightness = ;

	if (player_configuration.player_configuration_version >= e_player_configuration_version::_player_configuration_version_4)
	{
		for (int i = 0; i < 5; i++)
		{
			player_configuration.weapon_display_offsets[i] = { 5.f, 5.f };
		}
	}
}
