#include "haloreachlib-private-pch.h"

// Custom Engine Stuff
s_thread_local_storage ThreadLocalStorage;

// Custom Stuff


s_game_bindings g_GameBindings;
bool g_customBinds = false;
e_peer_property g_lastGameLoadStatus;
const char* g_lastGameLoadStatusStr;
const char* g_haloReachPathOverride = "";
bool g_gameManuallyKilled = false;
bool g_isHooked = false;
WORD g_frameLimit = 60;
int g_fieldOfView = 78;
int g_controlsLayout = 0;
int g_useController = 0;
bool g_pancamEnabled = false;
bool g_keyboardPrintKeyState = false;
HaloGameID g_currentGameID = HaloGameID::NotSet;

void patch_out_gameenginehostcallback_mov_rcx(HaloGameID id, intptr_t offset)
{
	char* pBeginning = (char*)GetLoadedHaloModule(id);

	char* pMovAttack = pBeginning + (offset - 0x180000000);
	// 48 8B 0D A3 9B C8 00
	// mov    rcx,QWORD PTR [rip+0xc89ba3]
	// change to
	// 48 31 c9
	// xor rcx, rcx
	// nop
	// nop
	// nop
	// nop

	char bytes[] =
	{
		0x48i8, 0x31i8, 0xc9i8,	// xor rcx, rcx
		0x90i8,					// nop
		0x90i8,					// nop
		0x90i8,					// nop
		0x90i8,					// nop
	};

	memcpy_virtual(pMovAttack, bytes, 7);
}

//
//// Halo Reach Variables
//
//Pointer<HaloGameID::HaloReach_2019_Aug_20, IDirectInputDevice8*, 0x1839EC128> qword_1839EC128;
//
//
//intptr_t TlsIndex_offset(HaloGameID gameID)
//{
//	switch (gameID)
//	{
//	case HaloGameID::HaloReach_2019_Jun_24: return 0x1810A3098;
//	case HaloGameID::HaloReach_2019_Aug_20: return 0x180CF6998;
//	}
//	return ~intptr_t();
//}
//DataEx<uint32_t, TlsIndex_offset> TlsIndex;
//
//intptr_t g_termination_value_offset(HaloGameID gameID)
//{
//	switch (gameID)
//	{
//	case HaloGameID::HaloReach_2019_Jun_24: return 0x183984DE4;
//	case HaloGameID::HaloReach_2019_Aug_20: return 0x18358EF04;
//	}
//	return ~intptr_t();
//}
//char& g_termination_value = reference_symbol<char>("g_termination_value", g_termination_value_offset);
//
//intptr_t g_controller_interfaces_offset(HaloGameID gameID)
//{
//	switch (gameID)
//	{
//	case HaloGameID::HaloReach_2019_Jun_24: return 0x183D43560;
//	case HaloGameID::HaloReach_2019_Aug_20: return 0x183945FC0;
//	}
//	return ~intptr_t();
//}
//c_controller_interface(&g_controller_interfaces)[4] = reference_symbol<c_controller_interface[4]>("g_controller_interfaces", g_controller_interfaces_offset);
//
//intptr_t g_game_options_offset(HaloGameID gameID)
//{
//	switch (gameID)
//	{
//	case HaloGameID::HaloReach_2019_Jun_24: return 0x183B0FB70;
//	case HaloGameID::HaloReach_2019_Aug_20: return 0x183719E50;
//	}
//	return ~intptr_t();
//}
//s_game_options& g_game_options = reference_symbol<s_game_options>("g_game_options", g_game_options_offset);
//
//// HaloReach_2019_Jun_24_Data<float, 0x183DF5830> dword_183DF5830; g_gamepad_globals->unknown350
//HaloReach_2019_Jun_24_Data<_QWORD, 0x183461018> qword_183461018; // no equivalent
//
//intptr_t g_gamepad_globals_offset(HaloGameID gameID)
//{
//	switch (gameID)
//	{
//	case HaloGameID::HaloReach_2019_Jun_24: return 0x183DF54E0;
//	case HaloGameID::HaloReach_2019_Aug_20: return 0x1839EBDE0;
//	}
//	return ~intptr_t();
//}
//DataEx<s_gamepad_globals, g_gamepad_globals_offset> g_gamepad_globals;
//
//intptr_t g_input_abstraction_offset(HaloGameID gameID)
//{
//	switch (gameID)
//	{
//	case HaloGameID::HaloReach_2019_Jun_24: return 0x183B2E510;
//	case HaloGameID::HaloReach_2019_Aug_20: return 0x1837387F0;
//	}
//	return ~intptr_t();
//}
//DataEx<s_input_abstraction, g_input_abstraction_offset> g_input_abstraction;
//
//HaloReach_2019_Jun_24_Data<char*, 0x183461000> g_shell_command_line; // no equivalent
//
//// Halo Reach Functions
//
//intptr_t restricted_region_unlock_primary_offset(HaloGameID gameID)
//{
//	switch (gameID)
//	{
//	case HaloGameID::HaloReach_2019_Jun_24: return 0x1803FB790;
//	case HaloGameID::HaloReach_2019_Aug_20: return 0x1802041F0;
//	}
//	return ~intptr_t();
//}
//FunctionHookEx<restricted_region_unlock_primary_offset, __int64(int a1)> restricted_region_unlock_primary;

// core functionality required for the game to run
#include "haloreach.core.inl"

// input functionality
//#include "haloreach.input.inl"

// rendering functionality
//#include "haloreach.render.inl"

//// log and text manipulation functionality
//#include "haloreach.log.inl"
//
//// game functionality
//#include "haloreach.game.inl"

// network functionality
//#include "haloreach.network.inl"

#define COMBINE1(X,Y) X##Y
#define COMBINE(X,Y) COMBINE1(X,Y)
#define RUNONCE(...) \
static bool COMBINE(__runonceflag_, __LINE__) = false; \
if (COMBINE(__runonceflag_, __LINE__) == false) \
{ \
	__VA_ARGS__; \
	COMBINE(__runonceflag_, __LINE__) = true; \
} (void)(0)

// this function runs to start the UI when the game engine host callback is null.
FunctionHookVarArgs<HaloGameID::HaloReach_2019_Aug_20, 0x180495220, char(unsigned int a1, __int64 a2, __int64 a3, IGameEngineHost* a4, __int64 a5, __int64 a6, ...)> sub_180495220 = { "sub_180495220", [](unsigned int a1, __int64 a2, __int64 a3, IGameEngineHost* a4, __int64 a5, __int64 a6, ...)
{
	char result = sub_180495220(a1, a2, a3, a4, a5, a6);
	WriteLineVerbose("sub_180495220: %i", (int)result);
	return result;
} };


//char sub_180495220()

void set_service_tag(int index)
{
	//static wchar_t tag[5] = L"";
	//if (GetPrivateProfileStringW(L"Player", L"ServiceTag", L"UNSC", tag, 5, L".\\Settings.ini") != 2)
	//{
	//	if (wcsncmp(g_controller_interfaces[index].Profile.ServiceTag, tag, 5) == 0)
	//	{
	//		WriteLineVerbose("player[%d].Tag already set", index);
	//		return;
	//	}
	//	wcsncpy(g_controller_interfaces[index].Profile.ServiceTag, tag, 5);
	//	WriteLineVerbose("player[%d].Tag: set %ls", index, tag);
	//}
}

void ReadConfig()
{
	g_frameLimit = __max(30, Settings::ReadIntegerValue(SettingsSection::Game, "FrameLimit", GameRender::s_deviceMode.dmDisplayFrequency));
	g_fieldOfView = Settings::ReadIntegerValue(SettingsSection::Camera, "FieldOfView", 78);
	g_controlsLayout = Settings::ReadIntegerValue(SettingsSection::Player, "ControlsLayout", 0);
	g_pancamEnabled = Settings::ReadBoolValue(SettingsSection::Debug, "PancamEnabled", false);
	g_keyboardPrintKeyState = Settings::ReadBoolValue(SettingsSection::Debug, "PrintKeyState", 0);
	g_useController = Settings::ReadIntegerValue(SettingsSection::Player, "UseController", 0);
	//ReadInputBindings();
}

void halo_reach_debug_callback()
{
	ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(1876, 1024), ImGuiCond_FirstUseEver);

	// Main body of the Demo window starts here.
	static bool isReachDebugWindowOpen = true;
	if (!ImGui::Begin("Halo Reach Debug", &isReachDebugWindowOpen, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	//ImGui::Columns(5, "g_pNetworkSessions", false);
	//ImGui::Separator();
	//ImGui::Selectable("Session Name");
	//ImGui::NextColumn();
	//ImGui::Selectable("Address");
	//ImGui::NextColumn();
	//ImGui::Selectable("State");
	//ImGui::NextColumn();
	//ImGui::Selectable("PeerCount");
	//ImGui::NextColumn();
	//ImGui::Selectable("PlayerCount");
	//ImGui::NextColumn();
	//for (int i = 0; i < 4; i++)
	//{
	//	auto& prNetworkSession = g_pNetworkSessions[i];
	//	auto pNetworkSessionName = ppNetworkSessionNames[i];
	//	const char* local_state_str = network_session_state_to_string(prNetworkSession->m_local_state);

	//	ImGui::Text(pNetworkSessionName);
	//	ImGui::NextColumn();
	//	ImGui::Text("0x%p", &prNetworkSession);
	//	ImGui::NextColumn();
	//	ImGui::Text(local_state_str);
	//	ImGui::NextColumn();
	//	ImGui::Text("%i", prNetworkSession->m_session_membership.m_peer_count);
	//	ImGui::NextColumn();
	//	ImGui::Text("%i", prNetworkSession->m_session_membership.m_player_count);
	//	ImGui::NextColumn();
	//}
	//ImGui::Columns(1);
	//for (int i = 0; i < 4; i++)
	//{
	//	ImGui::PushID(i);
	//	auto& prNetworkSession = g_pNetworkSessions[i];
	//	auto pNetworkSessionName = ppNetworkSessionNames[i];

	//	bool header = ImGui::CollapsingHeader(pNetworkSessionName);

	//	// quick view
	//	{
	//		auto& rNetworkSession = g_pNetworkSessions[i];
	//		auto pNetworkSessionName = ppNetworkSessionNames[i];
	//		ImGui::Columns(8, pNetworkSessionName, false);
	//		ImGui::Separator();
	//		ImGui::Selectable("peer_index");
	//		ImGui::NextColumn();
	//		ImGui::Selectable("player_identifier");
	//		ImGui::NextColumn();
	//		ImGui::Text("desired_configuration_version");
	//		ImGui::NextColumn();
	//		ImGui::Selectable("player_name");
	//		ImGui::NextColumn();
	//		ImGui::Selectable("service_tag");
	//		ImGui::NextColumn();
	//		ImGui::Selectable("machine_id");
	//		ImGui::NextColumn();
	//		ImGui::Selectable("network_session_peer_state");
	//		ImGui::NextColumn();
	//		ImGui::Selectable("join_nonce");
	//		ImGui::NextColumn();

	//		auto& rSessionMembership = rNetworkSession->m_session_membership;
	//		auto& rPeers = rSessionMembership.m_peers;
	//		auto& rPlayers = rSessionMembership.m_players;

	//		for (int i = 0; i < __min(rSessionMembership.m_player_count, _countof(rPlayers)); i++)
	//		{
	//			ImGui::Text("%i", rPlayers[i].peer_index);
	//			ImGui::NextColumn();
	//			ImGui::Text("%llu", rPlayers[i].player_identifier);
	//			ImGui::NextColumn();
	//			ImGui::Text("%i", rPlayers[i].desired_configuration_version);
	//			ImGui::NextColumn();
	//			ImGui::Text("%S", rPlayers[i].player_name);
	//			ImGui::NextColumn();
	//			ImGui::Text("%S", rPlayers[i].service_tag);
	//			ImGui::NextColumn();
	//			ImGui::Text("0x%llX", rPeers[rPlayers[i].peer_index].machine_identifier);
	//			ImGui::NextColumn();
	//			if (rPeers[rPlayers[i].peer_index].network_session_peer_state < 8)
	//			{
	//				ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.2f, 0.2f, 1.0f));
	//			}
	//			ImGui::Text("%u", rPeers[rPlayers[i].peer_index].network_session_peer_state);
	//			if (rPeers[rPlayers[i].peer_index].network_session_peer_state < 8)
	//			{
	//				ImGui::PopStyleColor();
	//			}
	//			ImGui::NextColumn();
	//			ImGui::Text("%llx", rPeers[rPlayers[i].peer_index].join_nonce);
	//			ImGui::NextColumn();

	//		}

	//		ImGui::Columns(1);
	//		ImGui::Separator();
	//	}

	//	if (header)
	//	{
	//		ImGui::Dummy(ImVec2(10.0f, 0.0f));
	//		ImGui::SameLine();
	//		ImGui::BeginGroup();
	//		{
	//			ImGui::Text("m_message_gateway: %p", prNetworkSession->m_message_gateway);
	//			ImGui::Text("m_observer: %p", prNetworkSession->m_observer);
	//			ImGui::Text("m_session_manager: %p", prNetworkSession->m_session_manager);
	//			ImGui::Text("ppSession: %p", prNetworkSession->ppSession);
	//			ImGui::Text("m_session_index: %i", prNetworkSession->m_session_index);
	//			ImGui::Text("m_session_type: %i", prNetworkSession->m_session_type);
	//			ImGui::Text("m_session_class: %i", prNetworkSession->m_session_class);
	//			ImGui::Text("unknown2C: %i", prNetworkSession->unknown2C);

	//			if (ImGui::CollapsingHeader("m_session_membership"))
	//			{
	//				ImGui::Dummy(ImVec2(10.0f, 0.0f));
	//				ImGui::SameLine();
	//				ImGui::BeginGroup();
	//				{
	//					auto& rSessionMembership = prNetworkSession->m_session_membership;

	//					ImGui::Text("m_session: %p", rSessionMembership.m_session);
	//					ImGui::Text("m_baseline_update_number: %i", rSessionMembership.m_baseline_update_number);
	//					ImGui::Text("m_leader_peer_index: %i", rSessionMembership.m_leader_peer_index);
	//					ImGui::Text("m_host_peer_index: %i", rSessionMembership.m_host_peer_index);
	//					ImGui::Text("unknown14: %i", rSessionMembership.unknown14);
	//					ImGui::Text("m_private_slot_count: %i", rSessionMembership.m_private_slot_count);
	//					ImGui::Text("m_public_slot_count: %i", rSessionMembership.m_public_slot_count);
	//					ImGui::Text("m_friends_only: %lli", rSessionMembership.m_friends_only);
	//					ImGui::Text("m_peer_count: %i", rSessionMembership.m_peer_count);
	//					ImGui::Text("m_valid_peer_mask: %i", rSessionMembership.m_valid_peer_mask);

	//					if (ImGui::CollapsingHeader("m_peers"))
	//					{
	//						ImGui::Dummy(ImVec2(10.0f, 0.0f));
	//						ImGui::SameLine();
	//						ImGui::BeginGroup();
	//						{
	//							auto& rPeers = rSessionMembership.m_peers;
	//							for (int i = 0; i < __min(rSessionMembership.m_peer_count, _countof(rPeers)); i++)
	//							{
	//								ImGui::Text("machine_identifier: 0x%llX", rPeers[i].machine_identifier);
	//								ImGui::Text("dword8: %u", rPeers[i].network_session_peer_state);
	//								ImGui::Text("join_nonce: %u", rPeers[i].join_nonce);
	//								ImGui::Dummy(ImVec2(0.0f, 5.0f));
	//							}
	//						}
	//						ImGui::EndGroup();
	//					}

	//					ImGui::Text("m_player_count: %i", rSessionMembership.m_player_count);
	//					ImGui::Text("m_valid_player_mask: %i", rSessionMembership.m_valid_player_mask);

	//					if (ImGui::CollapsingHeader("m_players"))
	//					{
	//						ImGui::Dummy(ImVec2(10.0f, 0.0f));
	//						ImGui::SameLine();
	//						ImGui::BeginGroup();
	//						{
	//							auto& rPlayers = rSessionMembership.m_players;
	//							for (int i = 0; i < __min(rSessionMembership.m_player_count, _countof(rPlayers)); i++)
	//							{
	//								ImGui::Text("desired_configuration_version: %i", rPlayers[i].desired_configuration_version);
	//								ImGui::Text("player_identifier: %llu", rPlayers[i].player_identifier);
	//								ImGui::Text("peer_index: %i", rPlayers[i].peer_index);
	//								ImGui::Text("player_name: %S", rPlayers[i].player_name);
	//								ImGui::Text("service_tag: %S", rPlayers[i].service_tag);
	//								ImGui::Text("player_name2: %S", rPlayers[i].player_name2);
	//								ImGui::Dummy(ImVec2(0.0f, 5.0f));
	//							}
	//						}
	//						ImGui::EndGroup();
	//					}

	//					ImGui::Text("m_player_sequence_number: %i", rSessionMembership.m_player_sequence_number);
	//					ImGui::Text("unknown291C: %i", rSessionMembership.unknown291C);
	//					ImGui::Text("m_incremental_updates: %i", rSessionMembership.m_incremental_updates);
	//					ImGui::Text("unknown5240: %i", rSessionMembership.unknown5240);
	//					ImGui::Text("m_local_peer_index: %i", rSessionMembership.m_local_peer_index);
	//					ImGui::Text("m_player_configuration_version: %u", rSessionMembership.m_player_configuration_version);
	//				}
	//				ImGui::EndGroup();
	//			}
	//			if (ImGui::CollapsingHeader("m_session_parameters"))
	//			{
	//				ImGui::Dummy(ImVec2(10.0f, 0.0f));
	//				ImGui::SameLine();
	//				ImGui::BeginGroup();
	//				{
	//					auto& rSessionParameters = prNetworkSession->m_session_parameters;

	//					ImGui::Text("session_size.max_players: %p", rSessionParameters.session_size.max_players);
	//					ImGui::Text("session: %p", rSessionParameters.session);
	//					ImGui::Text("observer: %p", rSessionParameters.observer);
	//					ImGui::Text("flags: 0x%08x", rSessionParameters.flags);
	//					ImGui::Text("initial_parameters_update_mask: 0x%08x", rSessionParameters.initial_parameters_update_mask);
	//				}
	//				ImGui::EndGroup();
	//			}

	//			ImGui::Text("m_local_state: %i", prNetworkSession->m_local_state);
	//			ImGui::Text("m_managed_session_index: %i", prNetworkSession->m_managed_session_index);
	//			ImGui::Text("pSession: %p", prNetworkSession->pSession);
	//		}
	//		ImGui::EndGroup();
	//	}
	//	ImGui::PopID();
	//}

	ImGui::End();
}

char(&aSystemUpdate)[] = reference_symbol<char[]>("aSystemUpdate", HaloGameID::HaloReach_2019_Aug_20, 0x180A0EE08);

void dump_binary(const char* pFileName, void* pData, size_t size)
{
	FILE* pFile = fopen(pFileName, "wb");
	if (pFile)
	{
		fwrite(pData, 1, size, pFile);
		fclose(pFile);
		WriteLineVerbose("Successfully dumped %s", pFileName);
	}
	else
	{
		WriteLineVerbose("Failed to dump %s", pFileName);
	}
}

intptr_t game_start_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Oct_30: return 0x180011C60;
	}
	return ~intptr_t();
}

#pragma optimize("", off)
FunctionHookEx<game_start_offset, char(__fastcall)(IGameEngineHaloReach * __this, class IGameEngineHost* pGameEngineHost, GameContext * pGameContext)> game_start = [](IGameEngineHaloReach* __this, class IGameEngineHost* pGameEngineHost, GameContext* pGameContext)
{
	dump_binary("gamecontext.bin", pGameContext, sizeof(GameContext));
	auto result = game_start(__this, pGameEngineHost, pGameContext);
	return result;
};
#pragma optimize("", on)

void init_halo_reach_with_mcc(HaloGameID gameID, bool isMCC)
{
	game_start.SetIsActive(isMCC || GameLauncher::HasCommandLineArg("-dump:gamecontext.bin"));

	g_currentGameID = gameID;
	CustomWindow::SetWindowTitle("Halo Reach");
	ReadConfig();
	//DebugUI::RegisterCallback(halo_reach_debug_callback);

	init_detours();

	//if (gameID == HaloGameID::HaloReach_2019_Jun_24)
	//{
	//	g_shell_command_line = GetCommandLineA();
	//}

	
	//nop_address(HaloGameID::HaloReach_2019_Oct_30, 0x18002DA56, 7);
	//patch_out_gameenginehostcallback_mov_rcx(HaloGameID::HaloReach_2019_Oct_30, 0x18002DA81);

	//unsigned char jnz = 0x75;
	//copy_to_address(HaloGameID::HaloReach_2019_Oct_30, 0x18002DA5D, &jnz, 1);

	//bool isNetworkingPatchActive = true;
	//if (isNetworkingPatchActive)
	//{
	//	patch_out_gameenginehostcallback_mov_rcx(HaloGameID::HaloReach_2019_Aug_20, 0x1800AE684);
	//	patch_out_gameenginehostcallback_mov_rcx(HaloGameID::HaloReach_2019_Aug_20, 0x180100D54);
	//	patch_out_gameenginehostcallback_mov_rcx(HaloGameID::HaloReach_2019_Aug_20, 0x1800ADEFE);
	//	//patch_out_gameenginehostcallback_mov_rsi(HaloGameID::HaloReach_2019_Aug_20, 0x18002350D); // patch for sub_1800234F0 to bypass member25
	//	nop_address(HaloGameID::HaloReach_2019_Aug_20, 0x1800ADB4F, 6);
	//	int32_t host_wait_for_party_timeout = 45000000;
	//	copy_to_address(HaloGameID::HaloReach_2019_Aug_20, 0x180011090, &host_wait_for_party_timeout, sizeof(host_wait_for_party_timeout));
	//	copy_to_address(HaloGameID::HaloReach_2019_Aug_20, 0x180011431, &host_wait_for_party_timeout, sizeof(host_wait_for_party_timeout));
	//	copy_to_address(HaloGameID::HaloReach_2019_Aug_20, 0x180011458, &host_wait_for_party_timeout, sizeof(host_wait_for_party_timeout));

	//	// this patches out the gameenginehostcallback to get the game to use its original pause menu
	//	bool enableOriginalMenu = false;
	//	sub_180495220.SetIsActive(enableOriginalMenu);
	//	if(enableOriginalMenu)
	//	{
	//		// patch	mov r9, cs:g_pGameEngineHost
	//		// to		xor r9, r9
	//		nop_address(HaloGameID::HaloReach_2019_Aug_20, 0x180495158, 7);
	//		char xor_r9_r9[] = { 0x4di8, 0x31i8, 0xc9i8 };
	//		copy_to_address(HaloGameID::HaloReach_2019_Aug_20, 0x180495158, xor_r9_r9, sizeof(xor_r9_r9));
	//	}

	//	//if (!IGameEngineHost::g_isHost)
	//	//{
	//	//	char jne = 0x75i8;
	//	//	copy_to_address(HaloGameID::HaloReach_2019_Aug_20, 0x1800AE91D, &jne, sizeof(jne));
	//	//}


	//}

	//RUNONCE(create_dll_hook("WS2_32.dll", "recvfrom", recvfromHook, recvfromPointer));
	//RUNONCE(create_dll_hook("WS2_32.dll", "bind", bindHook, bindPointer));
	//RUNONCE(create_dll_hook("WS2_32.dll", "sendto", sendtoHook, sendtoPointer));
	//sub_1800AE4E0.SetIsActive(isNetworkingPatchActive);

	DataReferenceBase::InitTree(gameID);
	FunctionHookBase::InitTree(gameID);
	GlobalReference::InitTree(gameID);
	end_detours();

	//GameLauncher::RegisterTerminationValue(g_termination_value);
}

void init_halo_reach(HaloGameID gameID)
{
	init_halo_reach_with_mcc(gameID, false);
}

void deinit_halo_reach(HaloGameID gameID)
{
	//DebugUI::UnregisterCallback(halo_reach_debug_callback);

	init_detours();

	FunctionHookBase::DeinitTree(gameID);
	DataReferenceBase::DeinitTree(gameID);
	GlobalReference::DeinitTree(gameID);
	end_detours();
}
