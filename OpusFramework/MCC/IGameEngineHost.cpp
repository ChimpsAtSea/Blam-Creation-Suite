#include "opusframework-private-pch.h"

#define IGameEngineHostCreateBarrierDefinition(index) void IGameEngineHost::Function##index() { FATAL_ERROR(L"IGameEngineHost barrier was triggered! index:" STRINGIFY(index)); }

/* barrier functions to prevent new versions of games calling our functions */
IGameEngineHostCreateBarrierDefinition(49);
IGameEngineHostCreateBarrierDefinition(50);
IGameEngineHostCreateBarrierDefinition(51);
IGameEngineHostCreateBarrierDefinition(52);
IGameEngineHostCreateBarrierDefinition(53);
IGameEngineHostCreateBarrierDefinition(54);
IGameEngineHostCreateBarrierDefinition(55);
IGameEngineHostCreateBarrierDefinition(56);

#undef IGameEngineHostCreateBarrierDefinition

void IGameEngineHostEmptyFunction()
{
	RUNONCE({
		c_console::set_text_color(_console_color_error);
		write_line_verbose("IGameEngineHostEmptyFunction was hit!");
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

char IGameEngineHost::FrameStart()																															{ CHECK_ADDRESS_SHIFTED(); return shifted_this->FrameStart(); }
void IGameEngineHost::FrameEnd(IDXGISwapChain* pSwapChain, _QWORD a2)																						{ CHECK_ADDRESS_SHIFTED(); return shifted_this->FrameEnd(pSwapChain, a2); }
void IGameEngineHost::Function02(__int64 player_identifier, unsigned int a2, __int64 a3, float a4, float a5, float a6, float a7)							{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function02(player_identifier,  a2,  a3,  a4,  a5,  a6,  a7); }
void IGameEngineHost::EngineStateUpdate(eEngineState state)																									{ CHECK_ADDRESS_SHIFTED(); return shifted_this->EngineStateUpdate(state); }
__int64 IGameEngineHost::GameExited(unsigned int a1, char* a2, int a3)																						{ CHECK_ADDRESS_SHIFTED(); return shifted_this->GameExited(a1, a2, a3); }
__int64 __fastcall IGameEngineHost::WriteBufferToFile(LPVOID pBuffer, size_t bufferSize)																	{ CHECK_ADDRESS_SHIFTED(); return shifted_this->WriteBufferToFile(pBuffer, bufferSize); }
void IGameEngineHost::Function06(GameResultsData* pGameResultsData)																							{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function06(pGameResultsData); }
void IGameEngineHost::Function07(unsigned int a1)																											{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function07(a1); }
void IGameEngineHost::Function08(const wchar_t* a1, const wchar_t* a2)																						{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function08(a1, a2); }
void IGameEngineHost::Function09(wchar_t a1[1024], wchar_t a2[1024])																						{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function09(a1, a2); }
IGameEvents* IGameEngineHost::GetGameEvents()																												{ CHECK_ADDRESS_SHIFTED(); return shifted_this->GetGameEvents(); }
void IGameEngineHost::UpdateGameVariant(IGameVariant* pGameVariant)																							{ CHECK_ADDRESS_SHIFTED(); return shifted_this->UpdateGameVariant(pGameVariant); }
void IGameEngineHost::UpdateMapVariant(IMapVariant* pMapVariant)																							{ CHECK_ADDRESS_SHIFTED(); return shifted_this->UpdateMapVariant(pMapVariant); }
void IGameEngineHost::Function13(const wchar_t* a1, const wchar_t* a2, const void* a3, unsigned int a4)														{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function13(a1, a2, a3, a4); }
char IGameEngineHost::Function14(int controllerIndex, BYTE* a2)																								{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function14(controllerIndex, a2); }
char IGameEngineHost::Function15(int controllerIndex, BYTE* a2)																								{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function15(controllerIndex, a2); }
char IGameEngineHost::GetNextLevelInfo(e_map_id* pMapID, int* pCampaignInsertionPoint, FILETIME* pFiletime, _DWORD* a4)										{ CHECK_ADDRESS_SHIFTED(); return shifted_this->GetNextLevelInfo(pMapID, pCampaignInsertionPoint, pFiletime, a4); }
bool IGameEngineHost::Function17(int a1)																													{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function17(a1); }
void IGameEngineHost::Function18(int a1)																													{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function18(a1); }
__int64 __fastcall IGameEngineHost::MapLoadPecentStatus(__int64 a1, __int64 a2, float a3)																	{ CHECK_ADDRESS_SHIFTED(); return shifted_this->MapLoadPecentStatus(a1, a2, a3); }
void IGameEngineHost::Function20(__int64 a1, __int8 a2)																										{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function20(a1, a2); }
__int64 __fastcall IGameEngineHost::GetMachineIdentifier(_QWORD a1)																							{ CHECK_ADDRESS_SHIFTED(); return shifted_this->GetMachineIdentifier(a1); }
__int64 IGameEngineHost::Function22(Function22Structure* buffer, __int64 a2)																				{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function22(buffer, a2); }
char IGameEngineHost::Function23(__int64 a1, __int64 a2)																									{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function23(a1, a2); }
void IGameEngineHost::GetSessionInfo(s_session_info_part* pSessionInfoPart)																					{ CHECK_ADDRESS_SHIFTED(); return shifted_this->GetSessionInfo(pSessionInfoPart); }
void __fastcall IGameEngineHost::MembershipUpdate(s_session_membership* pSessionMembership, uint32_t playercount)											{ CHECK_ADDRESS_SHIFTED(); return shifted_this->MembershipUpdate(pSessionMembership, playercount); }
bool __fastcall IGameEngineHost::Function26()																												{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function26(); }
bool __fastcall IGameEngineHost::Function27()																												{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function27(); }
bool __fastcall IGameEngineHost::UpdateGraphics(UpdateGraphicsData* pUnknown)																				{ CHECK_ADDRESS_SHIFTED(); return shifted_this->UpdateGraphics(pUnknown); }
__int64 __fastcall IGameEngineHost::Member29(__int64 value)																									{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Member29(value); }
__int64 __fastcall IGameEngineHost::UpdatePlayerConfiguration(wchar_t playerNames[4][32], PlayerConfiguration& rPlayerConfiguration)						{ CHECK_ADDRESS_SHIFTED(); return shifted_this->UpdatePlayerConfiguration(playerNames, rPlayerConfiguration); }
bool __fastcall __fastcall IGameEngineHost::UpdateInput(_QWORD a1, InputBuffer* pInputBuffer)																{ CHECK_ADDRESS_SHIFTED(); return shifted_this->UpdateInput(a1, pInputBuffer); }
void IGameEngineHost::Function32(_QWORD a1, float* a2)																										{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function32(a1, a2); }
void IGameEngineHost::Function33()																															{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function33(); }
void IGameEngineHost::XInputSetState(DWORD dwUserIndex, XINPUT_VIBRATION* pVibration)																		{ CHECK_ADDRESS_SHIFTED(); return shifted_this->XInputSetState(dwUserIndex, pVibration); }
bool __fastcall __fastcall IGameEngineHost::UpdatePlayerNames(__int64* a1, wchar_t pszPlayerNames[4][32], size_t dataSize)									{ CHECK_ADDRESS_SHIFTED(); return shifted_this->UpdatePlayerNames(a1, pszPlayerNames, dataSize); }
void __fastcall IGameEngineHost::Function36(const wchar_t* a1, const wchar_t* a2)																			{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function36(a1, a2); }
bool __fastcall IGameEngineHost::Function37(wchar_t* a1, __int64 a2)																						{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function37(a1, a2); }
__int64 __fastcall IGameEngineHost::NetworkSendTo(NetworkID networkID, char* pBuffer, uint32_t buffersize, int a4)											{ CHECK_ADDRESS_SHIFTED(); return shifted_this->NetworkSendTo(networkID, pBuffer, buffersize, a4); }
__int64 __fastcall IGameEngineHost::NetworkReceiveFrom(char* pBuffer, uint32_t buffersize, __int64 a3, s_transport_address* pTransportAddress)				{ CHECK_ADDRESS_SHIFTED(); return shifted_this->NetworkReceiveFrom(pBuffer, buffersize, a3, pTransportAddress); }
char* __fastcall IGameEngineHost::Function40(unsigned int a1)																								{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function40(a1); }
int __fastcall IGameEngineHost::Function41(BYTE* pBuffer)																									{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function41(pBuffer); }
bool __fastcall IGameEngineHost::Function42(signed int a1, __int64 a2, __int64 a3)																			{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function42(a1, a2, a3); }
void __fastcall IGameEngineHost::FirefightNew(__int64 a1, float a2)																							{ CHECK_ADDRESS_SHIFTED(); return shifted_this->FirefightNew(a1, a2); }
BOOL __fastcall IGameEngineHost::Function44(__int64 a1, __int64 a2)																							{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function44(a1, a2); }
bool __fastcall IGameEngineHost::GetPathByType(PathType pathType, LPSTR pBuffer, size_t bufferLength)														{ CHECK_ADDRESS_SHIFTED(); return shifted_this->GetPathByType(pathType, pBuffer, bufferLength); }
bool __fastcall IGameEngineHost::GetWidePathByType(PathType pathType, LPWSTR pBuffer, size_t bufferLength) 													{ CHECK_ADDRESS_SHIFTED(); return shifted_this->GetWidePathByType(pathType, pBuffer, bufferLength); }
unsigned __int8* __fastcall IGameEngineHost::Function47(_QWORD a1, unsigned __int8* a2, _QWORD a3)															{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function47(a1, a2, a3); }
__int64 __fastcall IGameEngineHost::Function48(_QWORD a1, __int64 a2)																						{ CHECK_ADDRESS_SHIFTED(); return shifted_this->Function48(a1, a2); }

void IGameEngineHost::ConfigureGameEngineHost()
{
	void** custom_game_engine_host_vtable = *reinterpret_cast<void***>(this);

	__vtbl_dynamic_data[0] = custom_game_engine_host_vtable[__game_engine_virtual_function_frame_start];
	__vtbl_dynamic_data[1] = custom_game_engine_host_vtable[__game_engine_virtual_function_frame_end];
	__vtbl_dynamic_data[2] = custom_game_engine_host_vtable[__game_engine_virtual_function_function2];
	__vtbl_dynamic_data[3] = custom_game_engine_host_vtable[__game_engine_virtual_function_engine_state_update];
	__vtbl_dynamic_data[4] = custom_game_engine_host_vtable[__game_engine_virtual_function_game_exited];
	__vtbl_dynamic_data[5] = custom_game_engine_host_vtable[__game_engine_virtual_function_write_buffer_to_file];
	__vtbl_dynamic_data[6] = custom_game_engine_host_vtable[__game_engine_virtual_function_function6];
	__vtbl_dynamic_data[7] = custom_game_engine_host_vtable[__game_engine_virtual_function_function7];
	__vtbl_dynamic_data[8] = custom_game_engine_host_vtable[__game_engine_virtual_function_function8];
	__vtbl_dynamic_data[9] = custom_game_engine_host_vtable[__game_engine_virtual_function_function9];
	__vtbl_dynamic_data[10] = custom_game_engine_host_vtable[__game_engine_virtual_function_get_game_events];
	__vtbl_dynamic_data[11] = custom_game_engine_host_vtable[__game_engine_virtual_function_update_game_variant];
	__vtbl_dynamic_data[12] = custom_game_engine_host_vtable[__game_engine_virtual_function_update_map_variant];
	__vtbl_dynamic_data[13] = custom_game_engine_host_vtable[__game_engine_virtual_function_function13];
	__vtbl_dynamic_data[14] = custom_game_engine_host_vtable[__game_engine_virtual_function_function14];
	__vtbl_dynamic_data[15] = custom_game_engine_host_vtable[__game_engine_virtual_function_function15];
	__vtbl_dynamic_data[16] = custom_game_engine_host_vtable[__game_engine_virtual_function_get_next_level_info];
	__vtbl_dynamic_data[17] = custom_game_engine_host_vtable[__game_engine_virtual_function_function17];
	__vtbl_dynamic_data[18] = custom_game_engine_host_vtable[__game_engine_virtual_function_function18];
	__vtbl_dynamic_data[19] = custom_game_engine_host_vtable[__game_engine_virtual_function_map_load_percent_status];
	__vtbl_dynamic_data[20] = custom_game_engine_host_vtable[__game_engine_virtual_function_function20];
	__vtbl_dynamic_data[21] = custom_game_engine_host_vtable[__game_engine_virtual_function_get_machine_identifier];
	__vtbl_dynamic_data[22] = custom_game_engine_host_vtable[__game_engine_virtual_function_function22];
	__vtbl_dynamic_data[23] = custom_game_engine_host_vtable[__game_engine_virtual_function_function23];
	__vtbl_dynamic_data[24] = custom_game_engine_host_vtable[__game_engine_virtual_function_get_session_info];
	__vtbl_dynamic_data[25] = custom_game_engine_host_vtable[__game_engine_virtual_function_membership_update];
	__vtbl_dynamic_data[26] = custom_game_engine_host_vtable[__game_engine_virtual_function_function26];
	__vtbl_dynamic_data[27] = custom_game_engine_host_vtable[__game_engine_virtual_function_function27];
	__vtbl_dynamic_data[28] = custom_game_engine_host_vtable[__game_engine_virtual_function_update_graphics];
	__vtbl_dynamic_data[29] = custom_game_engine_host_vtable[__game_engine_virtual_function_function29];
	__vtbl_dynamic_data[30] = custom_game_engine_host_vtable[__game_engine_virtual_function_update_player_configuration];
	__vtbl_dynamic_data[31] = custom_game_engine_host_vtable[__game_engine_virtual_function_update_input];
	__vtbl_dynamic_data[32] = custom_game_engine_host_vtable[__game_engine_virtual_function_function32];
	__vtbl_dynamic_data[33] = custom_game_engine_host_vtable[__game_engine_virtual_function_function33];
	__vtbl_dynamic_data[34] = custom_game_engine_host_vtable[__game_engine_virtual_function_xinput_set_state];
	__vtbl_dynamic_data[35] = custom_game_engine_host_vtable[__game_engine_virtual_function_update_player_names];
	__vtbl_dynamic_data[36] = custom_game_engine_host_vtable[__game_engine_virtual_function_function36];
	__vtbl_dynamic_data[37] = custom_game_engine_host_vtable[__game_engine_virtual_function_function37];
	__vtbl_dynamic_data[38] = custom_game_engine_host_vtable[__game_engine_virtual_function_network_send_to];
	__vtbl_dynamic_data[39] = custom_game_engine_host_vtable[__game_engine_virtual_function_network_recieve_from];
	__vtbl_dynamic_data[40] = custom_game_engine_host_vtable[__game_engine_virtual_function_function40];
	__vtbl_dynamic_data[41] = custom_game_engine_host_vtable[__game_engine_virtual_function_function41];
	__vtbl_dynamic_data[42] = custom_game_engine_host_vtable[__game_engine_virtual_function_function42];
	__vtbl_dynamic_data[43] = custom_game_engine_host_vtable[__game_engine_virtual_function_firefight_new];
	__vtbl_dynamic_data[44] = custom_game_engine_host_vtable[__game_engine_virtual_function_function44];
	__vtbl_dynamic_data[45] = custom_game_engine_host_vtable[__game_engine_virtual_function_get_path_by_type];
	__vtbl_dynamic_data[46] = custom_game_engine_host_vtable[__game_engine_virtual_function_get_path_by_type_wide];
	__vtbl_dynamic_data[47] = custom_game_engine_host_vtable[__game_engine_virtual_function_function47];
	__vtbl_dynamic_data[48] = custom_game_engine_host_vtable[__game_engine_virtual_function_function48];
}
