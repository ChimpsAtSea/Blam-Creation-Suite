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

char IGameEngineHost::FrameStart() { CHECK_ADDRESS_SHIFTED(); return shifted_this->FrameStart(); }
void IGameEngineHost::FrameEnd(IDXGISwapChain* swap_chain, _QWORD a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->FrameEnd(swap_chain, a2); }
void IGameEngineHost::Function02(__int64 player_identifier, unsigned int a2, __int64 a3, float a4, float a5, float a6, float a7) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function02(player_identifier, a2, a3, a4, a5, a6, a7); }
void IGameEngineHost::EngineStateUpdate(eEngineState state) { CHECK_ADDRESS_SHIFTED(); return shifted_this->EngineStateUpdate(state); }
__int64 IGameEngineHost::GameExited(unsigned int a1, char* a2, int a3) { CHECK_ADDRESS_SHIFTED(); return shifted_this->GameExited(a1, a2, a3); }
__int64 __fastcall IGameEngineHost::SaveGameState(LPVOID buffer, size_t buffer_size) { CHECK_ADDRESS_SHIFTED(); return shifted_this->SaveGameState(buffer, buffer_size); }
void IGameEngineHost::SubmitGameResults(GameResultsData* game_results_data) { CHECK_ADDRESS_SHIFTED(); return shifted_this->SubmitGameResults(game_results_data); }
void IGameEngineHost::Function07(unsigned int a1) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function07(a1); }
void IGameEngineHost::Function08(const wchar_t* a1, const wchar_t* a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function08(a1, a2); }
void IGameEngineHost::Function09(wchar_t a1[1024], wchar_t a2[1024]) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function09(a1, a2); }
IGameEvents* IGameEngineHost::GetGameEvents() { CHECK_ADDRESS_SHIFTED(); return shifted_this->GetGameEvents(); }
void IGameEngineHost::SaveGameVariant(IGameVariant* game_variant) { CHECK_ADDRESS_SHIFTED(); return shifted_this->SaveGameVariant(game_variant); }
void IGameEngineHost::SaveMapVariant(IMapVariant* map_variant) { CHECK_ADDRESS_SHIFTED(); return shifted_this->SaveMapVariant(map_variant); }
void IGameEngineHost::Function13(const wchar_t* a1, const wchar_t* a2, const void* a3, unsigned int a4) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function13(a1, a2, a3, a4); }
char IGameEngineHost::InvertLookControls(int controller_index, bool inverted) { CHECK_ADDRESS_SHIFTED(); return shifted_this->InvertLookControls(controller_index, inverted); }
char IGameEngineHost::GetGameSpecificBindings(int controller_index, char(*buffer)[256]) { CHECK_ADDRESS_SHIFTED(); return shifted_this->GetGameSpecificBindings(controller_index, buffer); }
char IGameEngineHost::GetNextLevelInfo(e_map_id* pMapID, int* campaign_insertion_point, FILETIME* file_time, _DWORD* a4) { CHECK_ADDRESS_SHIFTED(); return shifted_this->GetNextLevelInfo(pMapID, campaign_insertion_point, file_time, a4); }
bool IGameEngineHost::Function17(int a1) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function17(a1); }
void IGameEngineHost::Function18(int a1) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function18(a1); }
__int64 __fastcall IGameEngineHost::MapLoadPecentStatus(__int64 a1, __int64 a2, float a3) { CHECK_ADDRESS_SHIFTED(); return shifted_this->MapLoadPecentStatus(a1, a2, a3); }
void IGameEngineHost::Function20(__int64 a1, __int8 a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function20(a1, a2); }
__int64 __fastcall IGameEngineHost::GetMachineIdentifier(_QWORD a1) { CHECK_ADDRESS_SHIFTED(); return shifted_this->GetMachineIdentifier(a1); }
__int64 IGameEngineHost::Function22(Function22Structure* buffer, __int64 a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function22(buffer, a2); }
char IGameEngineHost::Function23(__int64 a1, __int64 a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function23(a1, a2); }
void IGameEngineHost::GetSessionInfo(s_session_info_part* session_info_part) { CHECK_ADDRESS_SHIFTED(); return shifted_this->GetSessionInfo(session_info_part); }
void __fastcall IGameEngineHost::MembershipUpdate(s_session_membership* session_membership, uint32_t player_count) { CHECK_ADDRESS_SHIFTED(); return shifted_this->MembershipUpdate(session_membership, player_count); }
bool __fastcall IGameEngineHost::Function26() { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function26(); }
bool __fastcall IGameEngineHost::Function27() { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function27(); }
bool __fastcall IGameEngineHost::UpdateGraphics(UpdateGraphicsData* update_graphics_data) { CHECK_ADDRESS_SHIFTED(); return shifted_this->UpdateGraphics(update_graphics_data); }
c_player_configuration* __fastcall IGameEngineHost::GetPlayerConfiguration(__int64 value) { CHECK_ADDRESS_SHIFTED(); return shifted_this->GetPlayerConfiguration(value); }
__int64 __fastcall IGameEngineHost::UpdatePlayerConfiguration(wchar_t player_names[4][16], c_player_configuration* player_configuration) { CHECK_ADDRESS_SHIFTED(); return shifted_this->UpdatePlayerConfiguration(player_names, player_configuration); }
bool __fastcall IGameEngineHost::UpdateInput(_QWORD a1, InputBuffer* input_buffer) { CHECK_ADDRESS_SHIFTED(); return shifted_this->UpdateInput(a1, input_buffer); }
void IGameEngineHost::Function32(_QWORD a1, float* a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function32(a1, a2); }
void IGameEngineHost::Function33() { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function33(); }
void IGameEngineHost::XInputSetState(DWORD user_index, XINPUT_VIBRATION* xinput_vibration) { CHECK_ADDRESS_SHIFTED(); return shifted_this->XInputSetState(user_index, xinput_vibration); }
bool __fastcall IGameEngineHost::UpdatePlayerNames(__int64* a1, wchar_t player_names[4][16], size_t data_size) { CHECK_ADDRESS_SHIFTED(); return shifted_this->UpdatePlayerNames(a1, player_names, data_size); }
void __fastcall IGameEngineHost::Function36(const wchar_t* a1, const wchar_t* a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function36(a1, a2); }
bool __fastcall IGameEngineHost::Function37(wchar_t* a1, __int64 a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function37(a1, a2); }
__int64 __fastcall IGameEngineHost::NetworkSendTo(NetworkID network_id, char* buffer, uint32_t buffer_size, int a4) { CHECK_ADDRESS_SHIFTED(); return shifted_this->NetworkSendTo(network_id, buffer, buffer_size, a4); }
__int64 __fastcall IGameEngineHost::NetworkReceiveFrom(char* buffer, uint32_t buffer_size, __int64 a3, s_transport_address* pTransportAddress) { CHECK_ADDRESS_SHIFTED(); return shifted_this->NetworkReceiveFrom(buffer, buffer_size, a3, pTransportAddress); }
char* __fastcall IGameEngineHost::Function40(unsigned int a1) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function40(a1); }
int __fastcall IGameEngineHost::Function41(BYTE* buffer) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function41(buffer); }
bool __fastcall IGameEngineHost::Function42(signed int a1, __int64 a2, __int64 a3) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function42(a1, a2, a3); }
void __fastcall IGameEngineHost::FirefightNew(__int64 a1, float a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->FirefightNew(a1, a2); }
BOOL __fastcall IGameEngineHost::Function44(__int64 a1, __int64 a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function44(a1, a2); }
bool __fastcall IGameEngineHost::get_pathByType(PathType path_type, LPSTR buffer, size_t buffer_length) { CHECK_ADDRESS_SHIFTED(); return shifted_this->get_pathByType(path_type, buffer, buffer_length); }
bool __fastcall IGameEngineHost::GetWidePathByType(PathType path_type, LPWSTR buffer, size_t buffer_length) { CHECK_ADDRESS_SHIFTED(); return shifted_this->GetWidePathByType(path_type, buffer, buffer_length); }
unsigned __int8* __fastcall IGameEngineHost::Function47(_QWORD a1, unsigned __int8* a2, _QWORD a3) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function47(a1, a2, a3); }
__int64 __fastcall IGameEngineHost::Function48(_QWORD a1, __int64 a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function48(a1, a2); }
char* __fastcall IGameEngineHost::Function49(char* str) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function49(str); }
__int64 __fastcall IGameEngineHost::Function58() { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function58(); }
__int64 __fastcall IGameEngineHost::Function59(__int64 a1, unsigned int a2) { CHECK_ADDRESS_SHIFTED(); return shifted_this->Function59(a1, a2); }

void IGameEngineHost::ConfigureGameEngineHost()
{
	void** custom_game_engine_host_vtable = *reinterpret_cast<void***>(this);

	size_t current_function_index = 0;
#define enqueue_function(min_build, max_build, function) \
	__pragma(warning(suppress: 6287)) if((min_build == _build_not_set || build >= min_build) && (max_build == _build_not_set || build <= max_build)) \
	__vtbl_dynamic_data[current_function_index++] = custom_game_engine_host_vtable[function];

	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_frame_start);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_frame_end);
	enqueue_function(_build_mcc_1_1367_0_0, _build_not_set, __game_engine_virtual_function_function44);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function2);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_engine_state_update);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_game_exited);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_save_game_state);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_submit_game_results);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function7);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function8);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function9);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_get_game_events);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_save_game_variant);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_save_map_variant);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function13);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function14);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function15);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_get_next_level_info);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function17);
	enqueue_function(_build_mcc_1_1367_0_0, _build_not_set, __game_engine_virtual_function_function26);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function18);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_map_load_percent_status); // after this
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function20);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_get_machine_identifier);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function22);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function23);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_get_session_info);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_membership_update);															//virtual void Member25(Member25Struct * a1, uint32_t a2);
	enqueue_function(_build_not_set, _build_mcc_1_1350_0_0, __game_engine_virtual_function_function26); // relocated after 1350									//virtual void Member26();
	enqueue_function(_build_mcc_1_1035_0_0, _build_not_set, __game_engine_virtual_function_function27);																//virtual void Member27();
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_update_graphics);															//virtual bool Member28(__int64 a2);
	enqueue_function(_build_mcc_1_1350_0_0, _build_not_set, __game_engine_virtual_function_get_player_configuration);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_update_player_configuration);												//virtual bool Member29(__int64 a2, __int64 a3);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_update_input); // before this, missing after this							//virtual unsigned __int8 __fastcall Member30(_QWORD, InputBuffer * input_buffer);
	enqueue_function(_build_mcc_1_1246_0_0, _build_not_set, __game_engine_virtual_function_function32);
	enqueue_function(_build_mcc_1_1186_0_0, _build_not_set, __game_engine_virtual_function_function33);
	enqueue_function(_build_mcc_1_1186_0_0, _build_not_set, __game_engine_virtual_function_xinput_set_state);
	enqueue_function(_build_not_set, _build_mcc_1_1350_0_0, __game_engine_virtual_function_update_player_names); // relocated after 1350
	enqueue_function(_build_not_set, _build_mcc_1_1350_0_0, __game_engine_virtual_function_function36); // relocated after 1350
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function37);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_network_send_to);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_network_recieve_from);
	enqueue_function(_build_not_set, _build_mcc_1_1350_0_0, __game_engine_virtual_function_function40); // removed after 1350
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function41);
	enqueue_function(_build_not_set, _build_mcc_1_1350_0_0, __game_engine_virtual_function_function42); // removed after 1350
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_firefight_new);
	enqueue_function(_build_not_set, _build_mcc_1_1350_0_0, __game_engine_virtual_function_function44); // relocated after 1350
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_get_path_by_type);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_get_path_by_type_wide);
	enqueue_function(_build_not_set, _build_not_set, __game_engine_virtual_function_function47);
	enqueue_function(_build_mcc_1_1186_0_0, _build_not_set, __game_engine_virtual_function_function48);
	enqueue_function(_build_mcc_1_1377_0_0, _build_not_set, __game_engine_virtual_function_function49);
	enqueue_function(_build_mcc_1_1367_0_0, _build_not_set, __game_engine_virtual_function_update_player_names); // relocated after 1350
	enqueue_function(_build_mcc_1_1367_0_0, _build_not_set, __game_engine_virtual_function_function36); // relocated after 1350
	enqueue_function(_build_mcc_1_1629_0_0, _build_not_set, __game_engine_virtual_function_function50);
	enqueue_function(_build_mcc_1_1629_0_0, _build_not_set, __game_engine_virtual_function_function51);

#undef enqueue_function


	if (build == _build_mcc_1_887_0_0)
	{
		DEBUG_ASSERT(__vtbl_dynamic_data[19] == custom_game_engine_host_vtable[__game_engine_virtual_function_map_load_percent_status]);
		DEBUG_ASSERT(__vtbl_dynamic_data[25] == custom_game_engine_host_vtable[__game_engine_virtual_function_membership_update]);
		DEBUG_ASSERT(__vtbl_dynamic_data[28] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_player_configuration]);
		DEBUG_ASSERT(__vtbl_dynamic_data[29] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_input]);
	}
	else if (build == _build_mcc_1_1305_0_0)
	{
		DEBUG_ASSERT(__vtbl_dynamic_data[0] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_start]);
		DEBUG_ASSERT(__vtbl_dynamic_data[1] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_end]);
		DEBUG_ASSERT(__vtbl_dynamic_data[2] == custom_game_engine_host_vtable[__game_engine_virtual_function_function2]);
		DEBUG_ASSERT(__vtbl_dynamic_data[3] == custom_game_engine_host_vtable[__game_engine_virtual_function_engine_state_update]);
		DEBUG_ASSERT(__vtbl_dynamic_data[4] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_exited]);
		DEBUG_ASSERT(__vtbl_dynamic_data[5] == custom_game_engine_host_vtable[__game_engine_virtual_function_save_game_state]);
		DEBUG_ASSERT(__vtbl_dynamic_data[6] == custom_game_engine_host_vtable[__game_engine_virtual_function_submit_game_results]);
		DEBUG_ASSERT(__vtbl_dynamic_data[7] == custom_game_engine_host_vtable[__game_engine_virtual_function_function7]);
		DEBUG_ASSERT(__vtbl_dynamic_data[8] == custom_game_engine_host_vtable[__game_engine_virtual_function_function8]);
		DEBUG_ASSERT(__vtbl_dynamic_data[9] == custom_game_engine_host_vtable[__game_engine_virtual_function_function9]);
		DEBUG_ASSERT(__vtbl_dynamic_data[10] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_game_events]);
		DEBUG_ASSERT(__vtbl_dynamic_data[11] == custom_game_engine_host_vtable[__game_engine_virtual_function_save_game_variant]);
		DEBUG_ASSERT(__vtbl_dynamic_data[12] == custom_game_engine_host_vtable[__game_engine_virtual_function_save_map_variant]);
		DEBUG_ASSERT(__vtbl_dynamic_data[13] == custom_game_engine_host_vtable[__game_engine_virtual_function_function13]);
		DEBUG_ASSERT(__vtbl_dynamic_data[14] == custom_game_engine_host_vtable[__game_engine_virtual_function_function14]);
		DEBUG_ASSERT(__vtbl_dynamic_data[15] == custom_game_engine_host_vtable[__game_engine_virtual_function_function15]);
		DEBUG_ASSERT(__vtbl_dynamic_data[16] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_next_level_info]);
		DEBUG_ASSERT(__vtbl_dynamic_data[17] == custom_game_engine_host_vtable[__game_engine_virtual_function_function17]);
		DEBUG_ASSERT(__vtbl_dynamic_data[18] == custom_game_engine_host_vtable[__game_engine_virtual_function_function18]);
		DEBUG_ASSERT(__vtbl_dynamic_data[19] == custom_game_engine_host_vtable[__game_engine_virtual_function_map_load_percent_status]);
		DEBUG_ASSERT(__vtbl_dynamic_data[20] == custom_game_engine_host_vtable[__game_engine_virtual_function_function20]);
		DEBUG_ASSERT(__vtbl_dynamic_data[21] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_machine_identifier]);
		DEBUG_ASSERT(__vtbl_dynamic_data[22] == custom_game_engine_host_vtable[__game_engine_virtual_function_function22]);
		DEBUG_ASSERT(__vtbl_dynamic_data[23] == custom_game_engine_host_vtable[__game_engine_virtual_function_function23]);
		DEBUG_ASSERT(__vtbl_dynamic_data[24] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_session_info]);
		DEBUG_ASSERT(__vtbl_dynamic_data[25] == custom_game_engine_host_vtable[__game_engine_virtual_function_membership_update]);
		DEBUG_ASSERT(__vtbl_dynamic_data[26] == custom_game_engine_host_vtable[__game_engine_virtual_function_function26]);
		DEBUG_ASSERT(__vtbl_dynamic_data[27] == custom_game_engine_host_vtable[__game_engine_virtual_function_function27]);
		DEBUG_ASSERT(__vtbl_dynamic_data[28] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_graphics]);
		DEBUG_ASSERT(__vtbl_dynamic_data[29] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_player_configuration]);
		DEBUG_ASSERT(__vtbl_dynamic_data[30] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_input]);
		DEBUG_ASSERT(__vtbl_dynamic_data[31] == custom_game_engine_host_vtable[__game_engine_virtual_function_function32]);
		DEBUG_ASSERT(__vtbl_dynamic_data[32] == custom_game_engine_host_vtable[__game_engine_virtual_function_function33]);
		DEBUG_ASSERT(__vtbl_dynamic_data[33] == custom_game_engine_host_vtable[__game_engine_virtual_function_xinput_set_state]);
		DEBUG_ASSERT(__vtbl_dynamic_data[34] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_player_names]);
		DEBUG_ASSERT(__vtbl_dynamic_data[35] == custom_game_engine_host_vtable[__game_engine_virtual_function_function36]);
		DEBUG_ASSERT(__vtbl_dynamic_data[36] == custom_game_engine_host_vtable[__game_engine_virtual_function_function37]);
		DEBUG_ASSERT(__vtbl_dynamic_data[37] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_send_to]);
		DEBUG_ASSERT(__vtbl_dynamic_data[38] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_recieve_from]);
		DEBUG_ASSERT(__vtbl_dynamic_data[39] == custom_game_engine_host_vtable[__game_engine_virtual_function_function40]);
		DEBUG_ASSERT(__vtbl_dynamic_data[40] == custom_game_engine_host_vtable[__game_engine_virtual_function_function41]);
		DEBUG_ASSERT(__vtbl_dynamic_data[41] == custom_game_engine_host_vtable[__game_engine_virtual_function_function42]);
		DEBUG_ASSERT(__vtbl_dynamic_data[42] == custom_game_engine_host_vtable[__game_engine_virtual_function_firefight_new]);
		DEBUG_ASSERT(__vtbl_dynamic_data[43] == custom_game_engine_host_vtable[__game_engine_virtual_function_function44]);
		DEBUG_ASSERT(__vtbl_dynamic_data[44] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_path_by_type]);
		DEBUG_ASSERT(__vtbl_dynamic_data[45] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_path_by_type_wide]);
		DEBUG_ASSERT(__vtbl_dynamic_data[46] == custom_game_engine_host_vtable[__game_engine_virtual_function_function47]);
		DEBUG_ASSERT(__vtbl_dynamic_data[47] == custom_game_engine_host_vtable[__game_engine_virtual_function_function48]);
	}
	else if (build == _build_mcc_1_1350_0_0)
	{
		DEBUG_ASSERT(__vtbl_dynamic_data[0] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_start]);
		DEBUG_ASSERT(__vtbl_dynamic_data[1] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_end]);
		DEBUG_ASSERT(__vtbl_dynamic_data[2] == custom_game_engine_host_vtable[__game_engine_virtual_function_function2]);
		DEBUG_ASSERT(__vtbl_dynamic_data[3] == custom_game_engine_host_vtable[__game_engine_virtual_function_engine_state_update]);
		DEBUG_ASSERT(__vtbl_dynamic_data[4] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_exited]);
		DEBUG_ASSERT(__vtbl_dynamic_data[5] == custom_game_engine_host_vtable[__game_engine_virtual_function_save_game_state]);
		DEBUG_ASSERT(__vtbl_dynamic_data[6] == custom_game_engine_host_vtable[__game_engine_virtual_function_submit_game_results]);
		DEBUG_ASSERT(__vtbl_dynamic_data[7] == custom_game_engine_host_vtable[__game_engine_virtual_function_function7]);
		DEBUG_ASSERT(__vtbl_dynamic_data[8] == custom_game_engine_host_vtable[__game_engine_virtual_function_function8]);
		DEBUG_ASSERT(__vtbl_dynamic_data[9] == custom_game_engine_host_vtable[__game_engine_virtual_function_function9]);
		DEBUG_ASSERT(__vtbl_dynamic_data[10] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_game_events]);
		DEBUG_ASSERT(__vtbl_dynamic_data[11] == custom_game_engine_host_vtable[__game_engine_virtual_function_save_game_variant]);
		DEBUG_ASSERT(__vtbl_dynamic_data[12] == custom_game_engine_host_vtable[__game_engine_virtual_function_save_map_variant]);
		DEBUG_ASSERT(__vtbl_dynamic_data[13] == custom_game_engine_host_vtable[__game_engine_virtual_function_function13]);
		DEBUG_ASSERT(__vtbl_dynamic_data[14] == custom_game_engine_host_vtable[__game_engine_virtual_function_function14]);
		DEBUG_ASSERT(__vtbl_dynamic_data[15] == custom_game_engine_host_vtable[__game_engine_virtual_function_function15]);
		DEBUG_ASSERT(__vtbl_dynamic_data[16] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_next_level_info]);
		DEBUG_ASSERT(__vtbl_dynamic_data[17] == custom_game_engine_host_vtable[__game_engine_virtual_function_function17]);
		DEBUG_ASSERT(__vtbl_dynamic_data[18] == custom_game_engine_host_vtable[__game_engine_virtual_function_function18]);
		DEBUG_ASSERT(__vtbl_dynamic_data[19] == custom_game_engine_host_vtable[__game_engine_virtual_function_map_load_percent_status]);
		DEBUG_ASSERT(__vtbl_dynamic_data[20] == custom_game_engine_host_vtable[__game_engine_virtual_function_function20]);
		DEBUG_ASSERT(__vtbl_dynamic_data[21] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_machine_identifier]);
		DEBUG_ASSERT(__vtbl_dynamic_data[22] == custom_game_engine_host_vtable[__game_engine_virtual_function_function22]);
		DEBUG_ASSERT(__vtbl_dynamic_data[23] == custom_game_engine_host_vtable[__game_engine_virtual_function_function23]);
		DEBUG_ASSERT(__vtbl_dynamic_data[24] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_session_info]);
		DEBUG_ASSERT(__vtbl_dynamic_data[25] == custom_game_engine_host_vtable[__game_engine_virtual_function_membership_update]);
		DEBUG_ASSERT(__vtbl_dynamic_data[26] == custom_game_engine_host_vtable[__game_engine_virtual_function_function26]);
		DEBUG_ASSERT(__vtbl_dynamic_data[27] == custom_game_engine_host_vtable[__game_engine_virtual_function_function27]);
		DEBUG_ASSERT(__vtbl_dynamic_data[28] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_graphics]);
		DEBUG_ASSERT(__vtbl_dynamic_data[29] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_player_configuration]);
		DEBUG_ASSERT(__vtbl_dynamic_data[30] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_player_configuration]);
		DEBUG_ASSERT(__vtbl_dynamic_data[31] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_input]);
		DEBUG_ASSERT(__vtbl_dynamic_data[32] == custom_game_engine_host_vtable[__game_engine_virtual_function_function32]);
		DEBUG_ASSERT(__vtbl_dynamic_data[33] == custom_game_engine_host_vtable[__game_engine_virtual_function_function33]);
		DEBUG_ASSERT(__vtbl_dynamic_data[34] == custom_game_engine_host_vtable[__game_engine_virtual_function_xinput_set_state]);
		DEBUG_ASSERT(__vtbl_dynamic_data[35] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_player_names]);
		DEBUG_ASSERT(__vtbl_dynamic_data[36] == custom_game_engine_host_vtable[__game_engine_virtual_function_function36]);
		DEBUG_ASSERT(__vtbl_dynamic_data[37] == custom_game_engine_host_vtable[__game_engine_virtual_function_function37]);
		DEBUG_ASSERT(__vtbl_dynamic_data[38] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_send_to]);
		DEBUG_ASSERT(__vtbl_dynamic_data[39] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_recieve_from]);
		DEBUG_ASSERT(__vtbl_dynamic_data[40] == custom_game_engine_host_vtable[__game_engine_virtual_function_function40]);
		DEBUG_ASSERT(__vtbl_dynamic_data[41] == custom_game_engine_host_vtable[__game_engine_virtual_function_function41]);
		DEBUG_ASSERT(__vtbl_dynamic_data[42] == custom_game_engine_host_vtable[__game_engine_virtual_function_function42]);
		DEBUG_ASSERT(__vtbl_dynamic_data[43] == custom_game_engine_host_vtable[__game_engine_virtual_function_firefight_new]);
		DEBUG_ASSERT(__vtbl_dynamic_data[44] == custom_game_engine_host_vtable[__game_engine_virtual_function_function44]);
		DEBUG_ASSERT(__vtbl_dynamic_data[45] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_path_by_type]);
		DEBUG_ASSERT(__vtbl_dynamic_data[46] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_path_by_type_wide]);
		DEBUG_ASSERT(__vtbl_dynamic_data[47] == custom_game_engine_host_vtable[__game_engine_virtual_function_function47]);
		DEBUG_ASSERT(__vtbl_dynamic_data[48] == custom_game_engine_host_vtable[__game_engine_virtual_function_function48]);
	}
	else if (build == _build_mcc_1_1367_0_0)
	{
		DEBUG_ASSERT(__vtbl_dynamic_data[0] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_start]);
		DEBUG_ASSERT(__vtbl_dynamic_data[1] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_end]);
		DEBUG_ASSERT(__vtbl_dynamic_data[2] == custom_game_engine_host_vtable[__game_engine_virtual_function_function44]);
		DEBUG_ASSERT(__vtbl_dynamic_data[3] == custom_game_engine_host_vtable[__game_engine_virtual_function_function2]);
		DEBUG_ASSERT(__vtbl_dynamic_data[4] == custom_game_engine_host_vtable[__game_engine_virtual_function_engine_state_update]);
		DEBUG_ASSERT(__vtbl_dynamic_data[5] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_exited]);
		DEBUG_ASSERT(__vtbl_dynamic_data[6] == custom_game_engine_host_vtable[__game_engine_virtual_function_save_game_state]);
		DEBUG_ASSERT(__vtbl_dynamic_data[7] == custom_game_engine_host_vtable[__game_engine_virtual_function_submit_game_results]);
		DEBUG_ASSERT(__vtbl_dynamic_data[8] == custom_game_engine_host_vtable[__game_engine_virtual_function_function7]);
		DEBUG_ASSERT(__vtbl_dynamic_data[9] == custom_game_engine_host_vtable[__game_engine_virtual_function_function8]);
		DEBUG_ASSERT(__vtbl_dynamic_data[10] == custom_game_engine_host_vtable[__game_engine_virtual_function_function9]);
		DEBUG_ASSERT(__vtbl_dynamic_data[11] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_game_events]);
		DEBUG_ASSERT(__vtbl_dynamic_data[12] == custom_game_engine_host_vtable[__game_engine_virtual_function_save_game_variant]);
		DEBUG_ASSERT(__vtbl_dynamic_data[13] == custom_game_engine_host_vtable[__game_engine_virtual_function_save_map_variant]);
		DEBUG_ASSERT(__vtbl_dynamic_data[14] == custom_game_engine_host_vtable[__game_engine_virtual_function_function13]);
		DEBUG_ASSERT(__vtbl_dynamic_data[15] == custom_game_engine_host_vtable[__game_engine_virtual_function_function14]);
		DEBUG_ASSERT(__vtbl_dynamic_data[16] == custom_game_engine_host_vtable[__game_engine_virtual_function_function15]);
		DEBUG_ASSERT(__vtbl_dynamic_data[17] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_next_level_info]);
		DEBUG_ASSERT(__vtbl_dynamic_data[18] == custom_game_engine_host_vtable[__game_engine_virtual_function_function17]);
		DEBUG_ASSERT(__vtbl_dynamic_data[19] == custom_game_engine_host_vtable[__game_engine_virtual_function_function26]);
		DEBUG_ASSERT(__vtbl_dynamic_data[20] == custom_game_engine_host_vtable[__game_engine_virtual_function_function18]);
		DEBUG_ASSERT(__vtbl_dynamic_data[21] == custom_game_engine_host_vtable[__game_engine_virtual_function_map_load_percent_status]);
		DEBUG_ASSERT(__vtbl_dynamic_data[22] == custom_game_engine_host_vtable[__game_engine_virtual_function_function20]);
		DEBUG_ASSERT(__vtbl_dynamic_data[23] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_machine_identifier]);
		DEBUG_ASSERT(__vtbl_dynamic_data[24] == custom_game_engine_host_vtable[__game_engine_virtual_function_function22]);
		DEBUG_ASSERT(__vtbl_dynamic_data[25] == custom_game_engine_host_vtable[__game_engine_virtual_function_function23]);
		DEBUG_ASSERT(__vtbl_dynamic_data[26] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_session_info]);
		DEBUG_ASSERT(__vtbl_dynamic_data[27] == custom_game_engine_host_vtable[__game_engine_virtual_function_membership_update]);
		DEBUG_ASSERT(__vtbl_dynamic_data[28] == custom_game_engine_host_vtable[__game_engine_virtual_function_function27]);
		DEBUG_ASSERT(__vtbl_dynamic_data[29] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_graphics]);
		DEBUG_ASSERT(__vtbl_dynamic_data[30] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_player_configuration]);
		DEBUG_ASSERT(__vtbl_dynamic_data[31] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_player_configuration]);
		DEBUG_ASSERT(__vtbl_dynamic_data[32] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_input]);
		DEBUG_ASSERT(__vtbl_dynamic_data[33] == custom_game_engine_host_vtable[__game_engine_virtual_function_function32]);
		DEBUG_ASSERT(__vtbl_dynamic_data[34] == custom_game_engine_host_vtable[__game_engine_virtual_function_function33]);
		DEBUG_ASSERT(__vtbl_dynamic_data[35] == custom_game_engine_host_vtable[__game_engine_virtual_function_xinput_set_state]);
		DEBUG_ASSERT(__vtbl_dynamic_data[36] == custom_game_engine_host_vtable[__game_engine_virtual_function_function37]);
		DEBUG_ASSERT(__vtbl_dynamic_data[37] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_send_to]);
		DEBUG_ASSERT(__vtbl_dynamic_data[38] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_recieve_from]);
		DEBUG_ASSERT(__vtbl_dynamic_data[39] == custom_game_engine_host_vtable[__game_engine_virtual_function_function41]);
		DEBUG_ASSERT(__vtbl_dynamic_data[40] == custom_game_engine_host_vtable[__game_engine_virtual_function_firefight_new]);
		DEBUG_ASSERT(__vtbl_dynamic_data[41] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_path_by_type]);
		DEBUG_ASSERT(__vtbl_dynamic_data[42] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_path_by_type_wide]);
		DEBUG_ASSERT(__vtbl_dynamic_data[43] == custom_game_engine_host_vtable[__game_engine_virtual_function_function47]);
		DEBUG_ASSERT(__vtbl_dynamic_data[44] == custom_game_engine_host_vtable[__game_engine_virtual_function_function48]);
		DEBUG_ASSERT(__vtbl_dynamic_data[45] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_player_names]);
		DEBUG_ASSERT(__vtbl_dynamic_data[46] == custom_game_engine_host_vtable[__game_engine_virtual_function_function36]);
	}
	else if (build == _build_mcc_1_1377_0_0)
	{
		DEBUG_ASSERT(__vtbl_dynamic_data[0] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_start]);
		DEBUG_ASSERT(__vtbl_dynamic_data[1] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_end]);
		DEBUG_ASSERT(__vtbl_dynamic_data[2] == custom_game_engine_host_vtable[__game_engine_virtual_function_function44]);
		DEBUG_ASSERT(__vtbl_dynamic_data[3] == custom_game_engine_host_vtable[__game_engine_virtual_function_function2]);
		DEBUG_ASSERT(__vtbl_dynamic_data[4] == custom_game_engine_host_vtable[__game_engine_virtual_function_engine_state_update]);
		DEBUG_ASSERT(__vtbl_dynamic_data[5] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_exited]);
		DEBUG_ASSERT(__vtbl_dynamic_data[6] == custom_game_engine_host_vtable[__game_engine_virtual_function_save_game_state]);
		DEBUG_ASSERT(__vtbl_dynamic_data[7] == custom_game_engine_host_vtable[__game_engine_virtual_function_submit_game_results]);
		DEBUG_ASSERT(__vtbl_dynamic_data[8] == custom_game_engine_host_vtable[__game_engine_virtual_function_function7]);
		DEBUG_ASSERT(__vtbl_dynamic_data[9] == custom_game_engine_host_vtable[__game_engine_virtual_function_function8]);
		DEBUG_ASSERT(__vtbl_dynamic_data[10] == custom_game_engine_host_vtable[__game_engine_virtual_function_function9]);
		DEBUG_ASSERT(__vtbl_dynamic_data[11] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_game_events]);
		DEBUG_ASSERT(__vtbl_dynamic_data[12] == custom_game_engine_host_vtable[__game_engine_virtual_function_save_game_variant]);
		DEBUG_ASSERT(__vtbl_dynamic_data[13] == custom_game_engine_host_vtable[__game_engine_virtual_function_save_map_variant]);
		DEBUG_ASSERT(__vtbl_dynamic_data[14] == custom_game_engine_host_vtable[__game_engine_virtual_function_function13]);
		DEBUG_ASSERT(__vtbl_dynamic_data[15] == custom_game_engine_host_vtable[__game_engine_virtual_function_function14]);
		DEBUG_ASSERT(__vtbl_dynamic_data[16] == custom_game_engine_host_vtable[__game_engine_virtual_function_function15]);
		DEBUG_ASSERT(__vtbl_dynamic_data[17] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_next_level_info]);
		DEBUG_ASSERT(__vtbl_dynamic_data[18] == custom_game_engine_host_vtable[__game_engine_virtual_function_function17]);
		DEBUG_ASSERT(__vtbl_dynamic_data[19] == custom_game_engine_host_vtable[__game_engine_virtual_function_function26]);
		DEBUG_ASSERT(__vtbl_dynamic_data[20] == custom_game_engine_host_vtable[__game_engine_virtual_function_function18]);
		DEBUG_ASSERT(__vtbl_dynamic_data[21] == custom_game_engine_host_vtable[__game_engine_virtual_function_map_load_percent_status]);
		DEBUG_ASSERT(__vtbl_dynamic_data[22] == custom_game_engine_host_vtable[__game_engine_virtual_function_function20]);
		DEBUG_ASSERT(__vtbl_dynamic_data[23] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_machine_identifier]);
		DEBUG_ASSERT(__vtbl_dynamic_data[24] == custom_game_engine_host_vtable[__game_engine_virtual_function_function22]);
		DEBUG_ASSERT(__vtbl_dynamic_data[25] == custom_game_engine_host_vtable[__game_engine_virtual_function_function23]);
		DEBUG_ASSERT(__vtbl_dynamic_data[26] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_session_info]);
		DEBUG_ASSERT(__vtbl_dynamic_data[27] == custom_game_engine_host_vtable[__game_engine_virtual_function_membership_update]);
		DEBUG_ASSERT(__vtbl_dynamic_data[28] == custom_game_engine_host_vtable[__game_engine_virtual_function_function27]);
		DEBUG_ASSERT(__vtbl_dynamic_data[29] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_graphics]);
		DEBUG_ASSERT(__vtbl_dynamic_data[30] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_player_configuration]);
		DEBUG_ASSERT(__vtbl_dynamic_data[31] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_player_configuration]);
		DEBUG_ASSERT(__vtbl_dynamic_data[32] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_input]);
		DEBUG_ASSERT(__vtbl_dynamic_data[33] == custom_game_engine_host_vtable[__game_engine_virtual_function_function32]);
		DEBUG_ASSERT(__vtbl_dynamic_data[34] == custom_game_engine_host_vtable[__game_engine_virtual_function_function33]);
		DEBUG_ASSERT(__vtbl_dynamic_data[35] == custom_game_engine_host_vtable[__game_engine_virtual_function_xinput_set_state]);
		DEBUG_ASSERT(__vtbl_dynamic_data[36] == custom_game_engine_host_vtable[__game_engine_virtual_function_function37]);
		DEBUG_ASSERT(__vtbl_dynamic_data[37] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_send_to]);
		DEBUG_ASSERT(__vtbl_dynamic_data[38] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_recieve_from]);
		DEBUG_ASSERT(__vtbl_dynamic_data[39] == custom_game_engine_host_vtable[__game_engine_virtual_function_function41]);
		DEBUG_ASSERT(__vtbl_dynamic_data[40] == custom_game_engine_host_vtable[__game_engine_virtual_function_firefight_new]);
		DEBUG_ASSERT(__vtbl_dynamic_data[41] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_path_by_type]);
		DEBUG_ASSERT(__vtbl_dynamic_data[42] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_path_by_type_wide]);
		DEBUG_ASSERT(__vtbl_dynamic_data[43] == custom_game_engine_host_vtable[__game_engine_virtual_function_function47]);
		DEBUG_ASSERT(__vtbl_dynamic_data[44] == custom_game_engine_host_vtable[__game_engine_virtual_function_function48]);
		DEBUG_ASSERT(__vtbl_dynamic_data[45] == custom_game_engine_host_vtable[__game_engine_virtual_function_function49]);
		DEBUG_ASSERT(__vtbl_dynamic_data[46] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_player_names]);
		DEBUG_ASSERT(__vtbl_dynamic_data[47] == custom_game_engine_host_vtable[__game_engine_virtual_function_function36]);
	}
	else if (build == _build_mcc_1_1629_0_0)
	{
		DEBUG_ASSERT(__vtbl_dynamic_data[0] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_start]);
		DEBUG_ASSERT(__vtbl_dynamic_data[1] == custom_game_engine_host_vtable[__game_engine_virtual_function_frame_end]);
		DEBUG_ASSERT(__vtbl_dynamic_data[2] == custom_game_engine_host_vtable[__game_engine_virtual_function_function44]);
		DEBUG_ASSERT(__vtbl_dynamic_data[3] == custom_game_engine_host_vtable[__game_engine_virtual_function_function2]);
		DEBUG_ASSERT(__vtbl_dynamic_data[4] == custom_game_engine_host_vtable[__game_engine_virtual_function_engine_state_update]);
		DEBUG_ASSERT(__vtbl_dynamic_data[5] == custom_game_engine_host_vtable[__game_engine_virtual_function_game_exited]);
		DEBUG_ASSERT(__vtbl_dynamic_data[6] == custom_game_engine_host_vtable[__game_engine_virtual_function_save_game_state]);
		DEBUG_ASSERT(__vtbl_dynamic_data[7] == custom_game_engine_host_vtable[__game_engine_virtual_function_submit_game_results]);
		DEBUG_ASSERT(__vtbl_dynamic_data[8] == custom_game_engine_host_vtable[__game_engine_virtual_function_function7]);
		DEBUG_ASSERT(__vtbl_dynamic_data[9] == custom_game_engine_host_vtable[__game_engine_virtual_function_function8]);
		DEBUG_ASSERT(__vtbl_dynamic_data[10] == custom_game_engine_host_vtable[__game_engine_virtual_function_function9]);
		DEBUG_ASSERT(__vtbl_dynamic_data[11] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_game_events]);
		DEBUG_ASSERT(__vtbl_dynamic_data[12] == custom_game_engine_host_vtable[__game_engine_virtual_function_save_game_variant]);
		DEBUG_ASSERT(__vtbl_dynamic_data[13] == custom_game_engine_host_vtable[__game_engine_virtual_function_save_map_variant]);
		DEBUG_ASSERT(__vtbl_dynamic_data[14] == custom_game_engine_host_vtable[__game_engine_virtual_function_function13]);
		DEBUG_ASSERT(__vtbl_dynamic_data[15] == custom_game_engine_host_vtable[__game_engine_virtual_function_function14]);
		DEBUG_ASSERT(__vtbl_dynamic_data[16] == custom_game_engine_host_vtable[__game_engine_virtual_function_function15]);
		DEBUG_ASSERT(__vtbl_dynamic_data[17] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_next_level_info]);
		DEBUG_ASSERT(__vtbl_dynamic_data[18] == custom_game_engine_host_vtable[__game_engine_virtual_function_function17]);
		DEBUG_ASSERT(__vtbl_dynamic_data[19] == custom_game_engine_host_vtable[__game_engine_virtual_function_function26]);
		DEBUG_ASSERT(__vtbl_dynamic_data[20] == custom_game_engine_host_vtable[__game_engine_virtual_function_function18]);
		DEBUG_ASSERT(__vtbl_dynamic_data[21] == custom_game_engine_host_vtable[__game_engine_virtual_function_map_load_percent_status]);
		DEBUG_ASSERT(__vtbl_dynamic_data[22] == custom_game_engine_host_vtable[__game_engine_virtual_function_function20]);
		DEBUG_ASSERT(__vtbl_dynamic_data[23] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_machine_identifier]);
		DEBUG_ASSERT(__vtbl_dynamic_data[24] == custom_game_engine_host_vtable[__game_engine_virtual_function_function22]);
		DEBUG_ASSERT(__vtbl_dynamic_data[25] == custom_game_engine_host_vtable[__game_engine_virtual_function_function23]);
		DEBUG_ASSERT(__vtbl_dynamic_data[26] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_session_info]);
		DEBUG_ASSERT(__vtbl_dynamic_data[27] == custom_game_engine_host_vtable[__game_engine_virtual_function_membership_update]);
		DEBUG_ASSERT(__vtbl_dynamic_data[28] == custom_game_engine_host_vtable[__game_engine_virtual_function_function27]);
		DEBUG_ASSERT(__vtbl_dynamic_data[29] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_graphics]);
		DEBUG_ASSERT(__vtbl_dynamic_data[30] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_player_configuration]);
		DEBUG_ASSERT(__vtbl_dynamic_data[31] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_player_configuration]);
		DEBUG_ASSERT(__vtbl_dynamic_data[32] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_input]);
		DEBUG_ASSERT(__vtbl_dynamic_data[33] == custom_game_engine_host_vtable[__game_engine_virtual_function_function32]);
		DEBUG_ASSERT(__vtbl_dynamic_data[34] == custom_game_engine_host_vtable[__game_engine_virtual_function_function33]);
		DEBUG_ASSERT(__vtbl_dynamic_data[35] == custom_game_engine_host_vtable[__game_engine_virtual_function_xinput_set_state]);
		DEBUG_ASSERT(__vtbl_dynamic_data[36] == custom_game_engine_host_vtable[__game_engine_virtual_function_function37]);
		DEBUG_ASSERT(__vtbl_dynamic_data[37] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_send_to]);
		DEBUG_ASSERT(__vtbl_dynamic_data[38] == custom_game_engine_host_vtable[__game_engine_virtual_function_network_recieve_from]);
		DEBUG_ASSERT(__vtbl_dynamic_data[39] == custom_game_engine_host_vtable[__game_engine_virtual_function_function41]);
		DEBUG_ASSERT(__vtbl_dynamic_data[40] == custom_game_engine_host_vtable[__game_engine_virtual_function_firefight_new]);
		DEBUG_ASSERT(__vtbl_dynamic_data[41] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_path_by_type]);
		DEBUG_ASSERT(__vtbl_dynamic_data[42] == custom_game_engine_host_vtable[__game_engine_virtual_function_get_path_by_type_wide]);
		DEBUG_ASSERT(__vtbl_dynamic_data[43] == custom_game_engine_host_vtable[__game_engine_virtual_function_function47]);
		DEBUG_ASSERT(__vtbl_dynamic_data[44] == custom_game_engine_host_vtable[__game_engine_virtual_function_function48]);
		DEBUG_ASSERT(__vtbl_dynamic_data[45] == custom_game_engine_host_vtable[__game_engine_virtual_function_function49]);
		DEBUG_ASSERT(__vtbl_dynamic_data[46] == custom_game_engine_host_vtable[__game_engine_virtual_function_update_player_names]);
		DEBUG_ASSERT(__vtbl_dynamic_data[47] == custom_game_engine_host_vtable[__game_engine_virtual_function_function36]);
		DEBUG_ASSERT(__vtbl_dynamic_data[48] == custom_game_engine_host_vtable[__game_engine_virtual_function_function50]);
		DEBUG_ASSERT(__vtbl_dynamic_data[49] == custom_game_engine_host_vtable[__game_engine_virtual_function_function51]);
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
	case _build_mcc_1_1387_0_0: DEBUG_ASSERT(current_function_index == 48); break;
	case _build_mcc_1_1389_0_0: DEBUG_ASSERT(current_function_index == 48); break;
	case _build_mcc_1_1477_0_0: DEBUG_ASSERT(current_function_index == 48); break;
	case _build_mcc_1_1499_0_0: DEBUG_ASSERT(current_function_index == 48); break;
	case _build_mcc_1_1520_0_0: DEBUG_ASSERT(current_function_index == 48); break;
	case _build_mcc_1_1629_0_0: DEBUG_ASSERT(current_function_index == 50); break;
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
		*player_configuration = new c_player_configuration(e_player_configuration_version::_player_configuration_version_6);
		break;
	case _build_mcc_1_1629_0_0:
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


	c_settings_legacy::read_wstring(_settings_section_legacy_player, "service_tag", player_configuration.service_tag, 4, L"117");
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
