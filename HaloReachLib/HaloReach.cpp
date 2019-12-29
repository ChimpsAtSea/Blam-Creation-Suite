#include "haloreachlib-private-pch.h"

#define COMBINE1(X,Y) X##Y
#define COMBINE(X,Y) COMBINE1(X,Y)
#define RUNONCE(...) \
static bool COMBINE(__runonceflag_, __LINE__) = false; \
if (COMBINE(__runonceflag_, __LINE__) == false) \
{ \
	__VA_ARGS__; \
	COMBINE(__runonceflag_, __LINE__) = true; \
} (void)(0)

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
BuildVersion g_currentbuildVersion = BuildVersion::NotSet;

#include <map>

void _simple_pattern_match_readonly_data_copy(
	void* pEngineAddress,
	SIZE_T& rSizeOfImage,
	void*& rpModuleData)
{
	HANDLE hProcess = GetCurrentProcess();

	{
		MODULEINFO moduleInfo = {};
		BOOL getModuleInformationResult = GetModuleInformation(
			hProcess,
			static_cast<HMODULE>(pEngineAddress),
			&moduleInfo,
			sizeof(moduleInfo)
		);
		assert(getModuleInformationResult);

		rSizeOfImage = static_cast<SIZE_T>(moduleInfo.SizeOfImage);
	}

	static std::map<void*, void*> moduleMaps;
	std::map<void*, void*>::iterator existingModuleDataCopy = moduleMaps.find(pEngineAddress);

	if (existingModuleDataCopy == moduleMaps.end())
	{
		rpModuleData = new char[rSizeOfImage];
		assert(rpModuleData);

		SIZE_T numBytes = 0;
		ReadProcessMemory(
			hProcess,
			static_cast<HMODULE>(pEngineAddress),
			rpModuleData,
			rSizeOfImage,
			&numBytes
		);
		assert(numBytes > 0);

		moduleMaps[pEngineAddress] = rpModuleData;
	}
	else
	{
		rpModuleData = existingModuleDataCopy->second;
		assert(rpModuleData);
	}
}

intptr_t simple_pattern_match(EngineVersion engineVersion, BuildVersion buildVersion, const char pInputData[], size_t inputDataLength, const char* pInputMask)
{
	void* pEngineAddress = GetEngineMemoryAddress(engineVersion);
	SIZE_T sizeOfImage = 0;
	void* pModuleData = nullptr;
	_simple_pattern_match_readonly_data_copy(pEngineAddress, sizeOfImage, pModuleData);

	if (pInputMask)
	{
		size_t inputMaskLength = strlen(pInputMask);
		assert(inputMaskLength == inputDataLength);
	}

	const char* pStartSearchAddress = reinterpret_cast<char*>(pModuleData);
	intptr_t result = 0;

	if (pInputMask)
	{
		for (uintptr_t imageOffset = 0; imageOffset < sizeOfImage; imageOffset++)
		{
			const char* pCurrentSearchPointer = pStartSearchAddress + imageOffset;

			for (size_t currentPatternIndex = 0; currentPatternIndex < inputDataLength; currentPatternIndex++)
			{
				if (pInputMask[imageOffset] == '?')
				{
					continue;
				}

				if (pCurrentSearchPointer[currentPatternIndex] != pInputData[currentPatternIndex])
				{
					goto search_fail_im;
				}
			}

			return GetBuildBaseAddress(buildVersion) + static_cast<intptr_t>(imageOffset);
		search_fail_im:
			continue;
		}
	}
	else
	{
		for (uintptr_t imageOffset = 0; imageOffset < sizeOfImage; imageOffset++)
		{
			const char* pCurrentSearchPointer = pStartSearchAddress + imageOffset;

			if (memcmp(pCurrentSearchPointer, pInputData, inputDataLength) == 0)
			{
				return GetBuildBaseAddress(buildVersion) + static_cast<intptr_t>(imageOffset);
			}

			//	for (size_t currentPatternIndex = 0; currentPatternIndex < inputDataLength; currentPatternIndex++)
			//	{
			//		if (pCurrentSearchPointer[currentPatternIndex] != pInputData[currentPatternIndex])
			//		{
			//			goto search_fail;
			//		}
			//	}

			//	return GetBuildBaseAddress(buildVersion) + imageOffset;
			//search_fail:
			//	continue;
		}
	}

	return 0;
}

intptr_t string_search(EngineVersion engineVersion, BuildVersion buildVersion, const char* pString)
{
	intptr_t imageAddress = simple_pattern_match(engineVersion, buildVersion, pString, strlen(pString) + 1, nullptr);
	return imageAddress;
}

const char* string_search_ptr(EngineVersion engineVersion, BuildVersion buildVersion, const char* pString)
{
	intptr_t imageAddress = string_search(engineVersion, buildVersion, pString);
	if (imageAddress)
	{
		const char* pStringAddress = reinterpret_cast<const char*>(GetEngineMemoryAddress(engineVersion)) + (imageAddress - GetBuildBaseAddress(buildVersion));
		return pStringAddress;
	}
	return nullptr;
}

intptr_t load_state_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_887_0_0: return 0x1810EC5A4;
	case BuildVersion::Build_1_1035_0_0: return 0x180D37AB0;
	case BuildVersion::Build_1_1186_0_0: return 0x180D4E674;
	case BuildVersion::Build_1_1211_0_0: return 0x180D4F674;
	case BuildVersion::Build_1_1246_0_0: return 0x180D494F4;
	case BuildVersion::Build_1_1270_0_0: return 0x180D494F4;
	}
	return ~intptr_t();
}
DataEx<int, load_state_offset> load_state;

intptr_t main_game_launch_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	using namespace ketchup;
	PatternScan ps = PatternScan(GetCurrentProcess(), static_cast<HMODULE>(GetEngineMemoryAddress(engineVersion)));
	ps.AddInstruction(new _push	("x",						0x40, 0x57													));	//.text:0000000180011870	push		rdi
	ps.AddInstruction(new _sub	("x",						0x48, 0x83, 0xEC, 0x30										));	//.text:0000000180011872	sub			rsp, 30h
	ps.AddInstruction(new _mov	("x",						0x48, 0xC7, 0x44, 0x24, 0x20, 0xFE, 0xFF, 0xFF, 0xFF		));	//.text:0000000180011876	mov			[rsp+38h+var_18], 0FFFFFFFFFFFFFFFEh
	ps.AddInstruction(new _mov	("x",						0x48, 0x89, 0x5C, 0x24, 0x40								));	//.text:000000018001187F	mov			[rsp+38h+arg_0], rbx
	ps.AddInstruction(new _mov	("x",						0x48, 0x89, 0x74, 0x24, 0x48								));	//.text:0000000180011884	mov			[rsp+38h+arg_8], rsi
	ps.AddInstruction(new _cmp	("x",						0x80, 0x3D, 0x3C, 0x6A, 0xBF, 0x00, 0x00					));	//.text:0000000180011889	cmp			cs:byte_180C082CC, 0
	ps.AddInstruction(new _jz	("x", JumpDistance::Short,	0x74, 0x1D													));	//.text:0000000180011890	jz			short loc_1800118AF
	ps.AddInstruction(new _call	("x",						0xE8, 0x49, 0x3A, 0x00, 0x00								));	//.text:0000000180011892	call		sub_1800152E0
	ps.AddInstruction(new _mov	("x",						0x89, 0x05, 0x3B, 0x6A, 0xBF, 0x00							));	//.text:0000000180011897	mov			cs:dword_180C082D8, eax
	ps.AddInstruction(new _call	("x",						0xE8, 0x3E, 0x3A, 0x00, 0x00								));	//.text:000000018001189D	call		sub_1800152E0
	ps.AddInstruction(new _mov	("x",						0x89, 0x05, 0x2C, 0x6A, 0xBF, 0x00, 0xC6					));	//.text:00000001800118A2	mov			cs:dword_180C082D4, eax
	ps.AddInstruction(new _mov	("x",						0x05, 0x1D, 0x6A, 0xBF, 0x00, 0x00							));	//.text:00000001800118A8	mov			cs:byte_180C082CC, 0
	ps.AddInstruction(new _mov	("x",						0xBE, 0x01, 0x00, 0x00, 0x00								));	//.text:00000001800118AF	mov			esi, 1
	ps.AddInstruction(new _mov	("x",						0x8B, 0x05, 0x3A, 0x7C, 0xD3, 0x00							));	//.text:00000001800118B4	mov			eax, cs:dword_180D494F4
	ps.AddInstruction(new _cmp	("x",						0x83, 0xF8, 0x0C											));	//.text:00000001800118BA	cmp			eax, 0Ch
	ps.AddInstruction(new _jz	("x", JumpDistance::Long,	0x0F, 0x84, 0x18, 0x01, 0x00, 0x00							));	//.text:00000001800118BD	jz			loc_1800119DB									
	ps.AddInstruction(new _call	("x",						0xE8, 0x18, 0x3A, 0x00, 0x00								));	//.text:00000001800118C3	call		sub_1800152E0
	ps.AddInstruction(new _sub	("x",						0x2B, 0x05, 0x0A, 0x6A, 0xBF, 0x00							));	//.text:00000001800118C8	sub			eax, cs:dword_180C082D8
	ps.AddInstruction(new _or	("x",						0x83, 0xCF, 0xFF											));	//.text:00000001800118CE	or			edi, 0FFFFFFFFh
	ps.AddInstruction(new _cmp	("x",						0x3D, 0x90, 0x5F, 0x01, 0x00								));	//.text:00000001800118D1	cmp			eax, 15F90h
	ps.AddInstruction(new _jbe	("x", JumpDistance::Short,	0x76, 0x6F													));	//.text:00000001800118D6	jbe			short loc_180011947
	ps.AddInstruction(new _cmp	("x",						0x83, 0x3D, 0x11, 0x7C, 0xD3, 0x00, 0x00					));	//.text:00000001800118D8	cmp			cs:dword_180D494F0, 0
	ps.AddInstruction(new _jnz	("x", JumpDistance::Short,	0x75, 0x18													));	//.text:00000001800118DF	jnz			short loc_1800118F9
	ps.AddInstruction(new _mov	("x",						0xC7, 0x05, 0x05, 0x7C, 0xD3, 0x00, 0x04, 0x00, 0x00, 0x00	));	//.text:00000001800118E1	mov			cs:dword_180D494F0, 4
	ps.AddInstruction(new _lea	("x",						0x48, 0x8D, 0x05, 0xFE, 0x98, 0xA3, 0x00					));	//.text:00000001800118EB	lea			rax, aExternalLaunch ; "external_launch_overall_timeout"
	ps.AddInstruction(new _mov	("x",						0x48, 0x89, 0x05, 0xEF, 0x7B, 0xD3, 0x00					));	//.text:00000001800118F2	mov			cs:qword_180D494E8, rax

	DWORD patternOffset = ps.FindPattern(0);
	if (patternOffset)
	{
		WriteLineVerbose("ketchup> SUCCEED: main_game_launch_offset @0x%x", patternOffset);
		return GetBuildBaseAddress(buildVersion) + patternOffset;
	}
	else
	{
		WriteLineVerbose("ketchup> FAILURE: main_game_launch_offset");
	}

	switch (buildVersion)
	{
	case BuildVersion::Build_1_887_0_0: return 0x180013EA0;
	case BuildVersion::Build_1_1035_0_0: return 0x1800113F0;
	case BuildVersion::Build_1_1186_0_0: return 0x180011860;
	case BuildVersion::Build_1_1211_0_0: return 0x180011870;
	case BuildVersion::Build_1_1246_0_0: return 0x180011870;
	case BuildVersion::Build_1_1270_0_0: return 0x180011870;
	}
	return ~intptr_t();
}
FunctionHookEx<main_game_launch_offset, char __fastcall (__int64 a1, __int64 a2)> main_game_launch = { "main_game_launch", [](__int64 a1, __int64 a2)
{
	const char* load_state_names[] =
	{
		"initial",
		"create_local_squad",
		"select_game_mode",
		"saved_film",
		"campaign",
		"previous_game_state",
		"multiplayer",
		"survival",
		"wait_for_party",
		"join_remote_squad",
		"unused",
		"start_game",
		"finished"
	};

	static int previous_load_state = k_load_state_invalid;

	if ((int)load_state != previous_load_state)
	{
		previous_load_state = load_state;
		printf("load_state changed to: %s\n", load_state_names[(int)load_state]);
	}

	auto result = main_game_launch(a1, a2);

	if ((int)load_state != previous_load_state)
	{
		previous_load_state = load_state;
		printf("load_state changed to: %s\n", load_state_names[(int)load_state]);
	}

	return result;
} };

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

char(&aSystemUpdate)[] = reference_symbol<char[]>("aSystemUpdate", BuildVersion::Build_1_1035_0_0, 0x180A0EE08);

void init_halo_reach_with_mcc(EngineVersion engineVersion, BuildVersion buildVersion, bool isMCC)
{
	g_currentbuildVersion = buildVersion;
	CustomWindow::SetWindowTitle("Halo Reach");
	ReadConfig();
	//DebugUI::RegisterCallback(halo_reach_debug_callback);

	init_detours();

	DataReferenceBase::InitTree(EngineVersion::HaloReach, buildVersion);
	FunctionHookBase::InitTree(EngineVersion::HaloReach, buildVersion);
	GlobalReference::InitTree(EngineVersion::HaloReach, buildVersion);
	end_detours();

	//GameLauncher::RegisterTerminationValue(g_termination_value);
}

void init_halo_reach(EngineVersion engineVersion, BuildVersion buildVersion)
{
	init_halo_reach_with_mcc(engineVersion, buildVersion, false);
}

void deinit_halo_reach(EngineVersion engineVersion, BuildVersion buildVersion)
{
	//DebugUI::UnregisterCallback(halo_reach_debug_callback);

	init_detours();

	FunctionHookBase::DeinitTree(EngineVersion::HaloReach, buildVersion);
	DataReferenceBase::DeinitTree(EngineVersion::HaloReach, buildVersion);
	GlobalReference::DeinitTree(EngineVersion::HaloReach, buildVersion);
	end_detours();
}
