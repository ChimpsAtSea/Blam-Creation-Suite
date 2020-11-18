
// Custom Stuff
bool g_keyboardPrintKeyState = false;

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
		ASSERT(getModuleInformationResult == TRUE);

		rSizeOfImage = static_cast<SIZE_T>(moduleInfo.SizeOfImage);
	}

	static std::map<void*, void*> moduleMaps;
	std::map<void*, void*>::iterator existingModuleDataCopy = moduleMaps.find(pEngineAddress);

	if (existingModuleDataCopy == moduleMaps.end())
	{
		rpModuleData = new char[rSizeOfImage];
		ASSERT(rpModuleData != nullptr);

		SIZE_T numBytes = 0;
		ReadProcessMemory(
			hProcess,
			static_cast<HMODULE>(pEngineAddress),
			rpModuleData,
			rSizeOfImage,
			&numBytes
		);
		ASSERT(numBytes > 0);

		moduleMaps[pEngineAddress] = rpModuleData;
	}
	else
	{
		rpModuleData = existingModuleDataCopy->second;
		ASSERT(rpModuleData);
	}
}

uintptr_t simple_pattern_match(e_engine_type engine_type, e_build build, const char pInputData[], size_t inputDataLength, const char* pInputMask)
{
	void* pEngineAddress = get_engine_memory_address(engine_type);
	SIZE_T sizeOfImage = 0;
	void* pModuleData = nullptr;
	_simple_pattern_match_readonly_data_copy(pEngineAddress, sizeOfImage, pModuleData);

	if (pInputMask)
	{
		size_t inputMaskLength = strlen(pInputMask);
		ASSERT(inputMaskLength == inputDataLength);
	}

	const char* pStartSearchAddress = reinterpret_cast<char*>(pModuleData);
	uintptr_t result = 0;

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

			return get_engine_base_address(engine_type) + static_cast<intptr_t>(imageOffset);
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
				return get_engine_base_address(engine_type) + static_cast<intptr_t>(imageOffset);
			}

			//	for (size_t currentPatternIndex = 0; currentPatternIndex < inputDataLength; currentPatternIndex++)
			//	{
			//		if (pCurrentSearchPointer[currentPatternIndex] != pInputData[currentPatternIndex])
			//		{
			//			goto search_fail;
			//		}
			//	}

			//	return GetBuildBaseAddress(build) + imageOffset;
			//search_fail:
			//	continue;
		}
	}

	return 0;
}

uintptr_t string_search(e_engine_type engine_type, e_build build, const char* string)
{
	uintptr_t imageAddress = simple_pattern_match(engine_type, build, string, strlen(string) + 1, nullptr);
	return imageAddress;
}

const char* string_search_ptr(e_engine_type engine_type, e_build build, const char* string)
{
	uintptr_t imageAddress = string_search(engine_type, build, string);
	if (imageAddress)
	{
		const char* string_address = reinterpret_cast<const char*>(get_engine_memory_address(engine_type)) + (imageAddress - get_engine_base_address(engine_type));
		return string_address;
	}
	return nullptr;
}


void haloreach_debug_callback()
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
	//	auto& network_session = g_pNetworkSessions[i];
	//	auto pNetworkSessionName = ppNetworkSessionNames[i];
	//	const char* local_state_str = network_session_state_to_string(network_session->local_state);

	//	ImGui::Text(pNetworkSessionName);
	//	ImGui::NextColumn();
	//	ImGui::Text("0x%p", &network_session);
	//	ImGui::NextColumn();
	//	ImGui::Text(local_state_str);
	//	ImGui::NextColumn();
	//	ImGui::Text("%i", network_session->session_membership.peer_count);
	//	ImGui::NextColumn();
	//	ImGui::Text("%i", network_session->session_membership.player_count);
	//	ImGui::NextColumn();
	//}
	//ImGui::Columns(1);
	//for (int i = 0; i < 4; i++)
	//{
	//	ImGui::PushID(i);
	//	auto& network_session = g_pNetworkSessions[i];
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

	//		auto& session_membership = rNetworkSession->session_membership;
	//		auto& rPeers = session_membership.peers;
	//		auto& rPlayers = session_membership.players;

	//		for (int i = 0; i < __min(session_membership.player_count, _countof(rPlayers)); i++)
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
	//			ImGui::Text("message_gateway: %p", network_session->message_gateway);
	//			ImGui::Text("observer: %p", network_session->observer);
	//			ImGui::Text("session_manager: %p", network_session->session_manager);
	//			ImGui::Text("ppSession: %p", network_session->ppSession);
	//			ImGui::Text("session_index: %i", network_session->session_index);
	//			ImGui::Text("session_type: %i", network_session->session_type);
	//			ImGui::Text("session_class: %i", network_session->session_class);
	//			ImGui::Text("unknown2C: %i", network_session->unknown2C);

	//			if (ImGui::CollapsingHeader("session_membership"))
	//			{
	//				ImGui::Dummy(ImVec2(10.0f, 0.0f));
	//				ImGui::SameLine();
	//				ImGui::BeginGroup();
	//				{
	//					auto& session_membership = network_session->session_membership;

	//					ImGui::Text("session: %p", session_membership.session);
	//					ImGui::Text("baseline_update_number: %i", session_membership.baseline_update_number);
	//					ImGui::Text("leader_peer_index: %i", session_membership.leader_peer_index);
	//					ImGui::Text("host_peer_index: %i", session_membership.host_peer_index);
	//					ImGui::Text("unknown14: %i", session_membership.unknown14);
	//					ImGui::Text("private_slot_count: %i", session_membership.private_slot_count);
	//					ImGui::Text("public_slot_count: %i", session_membership.public_slot_count);
	//					ImGui::Text("friends_only: %lli", session_membership.friends_only);
	//					ImGui::Text("peer_count: %i", session_membership.peer_count);
	//					ImGui::Text("valid_peer_mask: %i", session_membership.valid_peer_mask);

	//					if (ImGui::CollapsingHeader("peers"))
	//					{
	//						ImGui::Dummy(ImVec2(10.0f, 0.0f));
	//						ImGui::SameLine();
	//						ImGui::BeginGroup();
	//						{
	//							auto& rPeers = session_membership.peers;
	//							for (int i = 0; i < __min(session_membership.peer_count, _countof(rPeers)); i++)
	//							{
	//								ImGui::Text("machine_identifier: 0x%llX", rPeers[i].machine_identifier);
	//								ImGui::Text("dword8: %u", rPeers[i].network_session_peer_state);
	//								ImGui::Text("join_nonce: %u", rPeers[i].join_nonce);
	//								ImGui::Dummy(ImVec2(0.0f, 5.0f));
	//							}
	//						}
	//						ImGui::EndGroup();
	//					}

	//					ImGui::Text("player_count: %i", session_membership.player_count);
	//					ImGui::Text("valid_player_mask: %i", session_membership.valid_player_mask);

	//					if (ImGui::CollapsingHeader("players"))
	//					{
	//						ImGui::Dummy(ImVec2(10.0f, 0.0f));
	//						ImGui::SameLine();
	//						ImGui::BeginGroup();
	//						{
	//							auto& rPlayers = session_membership.players;
	//							for (int i = 0; i < __min(session_membership.player_count, _countof(rPlayers)); i++)
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

	//					ImGui::Text("player_sequence_number: %i", session_membership.player_sequence_number);
	//					ImGui::Text("unknown291C: %i", session_membership.unknown291C);
	//					ImGui::Text("incremental_updates: %i", session_membership.incremental_updates);
	//					ImGui::Text("unknown5240: %i", session_membership.unknown5240);
	//					ImGui::Text("local_peer_index: %i", session_membership.local_peer_index);
	//					ImGui::Text("player_configuration_version: %u", session_membership.player_configuration_version);
	//				}
	//				ImGui::EndGroup();
	//			}
	//			if (ImGui::CollapsingHeader("session_parameters"))
	//			{
	//				ImGui::Dummy(ImVec2(10.0f, 0.0f));
	//				ImGui::SameLine();
	//				ImGui::BeginGroup();
	//				{
	//					auto& rSessionParameters = network_session->session_parameters;

	//					ImGui::Text("session_size.max_players: %p", rSessionParameters.session_size.max_players);
	//					ImGui::Text("session: %p", rSessionParameters.session);
	//					ImGui::Text("observer: %p", rSessionParameters.observer);
	//					ImGui::Text("flags: 0x%08x", rSessionParameters.flags);
	//					ImGui::Text("initial_parameters_update_mask: 0x%08x", rSessionParameters.initial_parameters_update_mask);
	//				}
	//				ImGui::EndGroup();
	//			}

	//			ImGui::Text("local_state: %i", network_session->local_state);
	//			ImGui::Text("managed_session_index: %i", network_session->managed_session_index);
	//			ImGui::Text("pSession: %p", network_session->pSession);
	//		}
	//		ImGui::EndGroup();
	//	}
	//	ImGui::PopID();
	//}

	ImGui::End();
}

char(&aSystemUpdate)[] = reference_symbol<char[]>("aSystemUpdate", _engine_type_haloreach, _build_mcc_1_1035_0_0, 0x180A0EE08);

void init_haloreach_with_mcc(e_engine_type engine_type, e_build build, bool isMCC)
{
	g_keyboardPrintKeyState = c_settings::read_boolean(_settings_section_debug, "PrintKeyState", 0);
	//ReadInputBindings();

	//DebugUI::RegisterCallback(haloreach_debug_callback);

	//LegacyGameLauncher::RegisterTerminationValue(g_termination_value);
}

void init_haloreach(e_engine_type engine_type, e_build build)
{
	init_haloreach_with_mcc(engine_type, build, false);
}

void deinit_haloreach(e_engine_type engine_type, e_build build)
{
	//DebugUI::UnregisterCallback(haloreach_debug_callback);


}
