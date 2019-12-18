

// Assembly hacks





void patch_out_gameenginehostcallback_mov_rsi(BuildVersion buildVersion, intptr_t offset)
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
		0x48i8, 0x31i8, 0xf6i8,	// xor rsi, rsi
		0x90i8,					// nop
		0x90i8,					// nop
		0x90i8,					// nop
		0x90i8,					// nop
	};

	memcpy_virtual(pMovAttack, bytes, 7);
}


intptr_t sub_1800AE4E0_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1035_0_0: return 0x1800AE4E0;
	}
	return ~intptr_t();
}
FunctionHookEx<sub_1800AE4E0_offset, int __fastcall (__int64 a1, char* a2)> sub_1800AE4E0 = { "sub_1800AE4E0", [](__int64 a1, char* a2)
{
	// this forces the game to treat network addresses as IPV4 and use the existing halo reach sockets
	{
		auto v2 = a2;
		auto& v18 = *(_QWORD*)(v2 + 24);
		SWORD& v18sword = SWORD1(v18);
		v18sword = 4;
	}

	auto result = sub_1800AE4E0(a1, a2);
	return result;
} };

void log_socket_info(const struct sockaddr* from, int bytes, const char* pPrefix, uint32_t packetID)
{
	if (strstr(GetCommandLineA(), "-shownetworktraffic"))
	{
		if (!from)
		{
			return;
		}

		switch (from->sa_family)
		{
		case AF_INET:
		{
			sockaddr_in& sockaddr = *(sockaddr_in*)from;
			char* pIPv4 = inet_ntoa(sockaddr.sin_addr);
			u_short port = htons(sockaddr.sin_port);
			WriteVerbose("%s IPv4 %s:%i", pPrefix, pIPv4, port);
			if (bytes > 0)
			{
				if (bytes < 10)
				{
					WriteVerbose(" [0%i bytes]", bytes);
				}
				else
				{
					WriteVerbose(" [%i bytes]", bytes);
				}
			}
			if (packetID <= UINT16_MAX)
			{
				WriteVerbose(" id:%04x", packetID);
				WriteVerbose(" id:%u", packetID);
				WriteVerbose(" id_nbo:%04x", uint32_t(ntohs(packetID)));
			}
			WriteLineVerbose("");
		}
		break;
		case AF_INET6:
		{
			sockaddr_in6& sockaddr6 = *(sockaddr_in6*)from;
			char IPv6[INET6_ADDRSTRLEN] = {};
			inet_ntop(AF_INET6, &sockaddr6.sin6_addr, IPv6, INET6_ADDRSTRLEN);
			WriteVerbose("IPv6 [%s]:%i", IPv6, sockaddr6.sin6_port);
			if (bytes > 0)
			{
				WriteVerbose(" [%i bytes]", bytes);
			}
			WriteLineVerbose("");
		}
		break;
		}
	}
}


typedef int (WSAAPI bindFunc)(
	_In_ SOCKET s,
	_In_reads_bytes_(namelen) const struct sockaddr FAR* name,
	_In_ int namelen
	);
static bindFunc* bindPointer;
int WSAAPI bindHook(
	_In_ SOCKET s,
	_In_reads_bytes_(namelen) const struct sockaddr FAR* name,
	_In_ int namelen
)
{
	sockaddr_in& in = *(sockaddr_in*)name;
	__int64 x = __ROR2__(in.sin_port, 8);
	{
		log_socket_info(name, 0, "bind", -1);
	}
	return bindPointer(s, name, namelen);
}




typedef int(__stdcall recvfrom_Func)(
	_In_ SOCKET s,
	_Out_writes_bytes_to_(len, return) __out_data_source(NETWORK) char FAR* buf,
	_In_ int len,
	_In_ int flags,
	_Out_writes_bytes_to_opt_(*fromlen, *fromlen) struct sockaddr FAR* from,
	_Inout_opt_ int FAR* fromlen
	);
static recvfrom_Func* recvfromPointer;
int __stdcall recvfromHook(
	_In_ SOCKET s,
	_Out_writes_bytes_to_(len, return) __out_data_source(NETWORK) char FAR* buf,
	_In_ int len,
	_In_ int flags,
	_Out_writes_bytes_to_opt_(*fromlen, *fromlen) struct sockaddr FAR* from,
	_Inout_opt_ int FAR* fromlen
)
{
	auto result = recvfromPointer(s, buf, len, flags, from, fromlen);

	// for writing an output dump of network traffic
	//if (result > 0)
	//{
	//	FILE* pFile = nullptr;
	//	if (IGameEngineHost::g_isHost)
	//	{
	//		pFile = fopen("host_recieve.bin", "a");
	//	}
	//	else
	//	{
	//		pFile = fopen("client_recieve.bin", "a");
	//	}

	//	fwrite(buf, 1, result, pFile);
	//	fclose(pFile);
	//}

	uint32_t id = -1;
	if (result > 2)
	{
		id = *(unsigned __int16*)(buf);
	}
	//if (result > 0)
	//{
	//	{
	//		sockaddr* pSocketAddressBuffer = (sockaddr*)alloca(32 * 1024);
	//		int length = 32 * 1024;
	//		memset(pSocketAddressBuffer, 0, length);
	//		getsockname(s, pSocketAddressBuffer, &length);
	//		log_socket_info(pSocketAddressBuffer);
	//	}

	//	{
	//		sockaddr* pSocketAddressBuffer = (sockaddr*)alloca(32 * 1024);
	//		int length = 32 * 1024;
	//		memset(pSocketAddressBuffer, 0, length);
	//		getpeername(s, pSocketAddressBuffer, &length);
	//		log_socket_info(pSocketAddressBuffer);
	//	}
	//}

	if (result == -1)
	{
		wchar_t* errorMessage = NULL;
		FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, WSAGetLastError(),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPWSTR)& errorMessage, 0, NULL);

		LocalFree(errorMessage);

		return result;
	}

	log_socket_info(from, result, "recv", id);

	return result;
}

typedef
int
(WSAAPI sendtoFunc)(
	_In_ SOCKET s,
	_In_reads_bytes_(len) const char FAR* buf,
	_In_ int len,
	_In_ int flags,
	_In_reads_bytes_(tolen) const struct sockaddr FAR* to,
	_In_ int tolen
	);
sendtoFunc* sendtoPointer = nullptr;

int
sendtoHook(
	_In_ SOCKET s,
	_In_reads_bytes_(len) const char FAR* buf,
	_In_ int len,
	_In_ int flags,
	_In_reads_bytes_(tolen) const struct sockaddr FAR* to,
	_In_ int tolen
)
{
	uint32_t id = -1;
	if (len > 2)
	{
		id = *(unsigned __int16*)(buf);
	}

	auto result = sendtoPointer(s, buf, len, flags, to, tolen);

	log_socket_info(to, result, "send", id);
	return result;
}

Pointer<BuildVersion::Build_1_1035_0_0, void*, 0x1830DC4E0> g_pNetworkSquadSession;
//Data<BuildVersion::Build_1_1035_0_0, c_network_session[4], 0x18324F378> g_networkSessions;
Data<BuildVersion::Build_1_1035_0_0, c_network_session* [4], 0x1830DC4E0> g_pNetworkSessions;

const char* network_session_state_to_string(e_network_session_state network_session_state)
{
	switch (network_session_state)
	{
	case _network_session_state_uninitialized:			return "_network_session_state_uninitialized";
	case _network_session_state_none:					return "_network_session_state_none";
	case _network_session_state_peer_creating:			return "_network_session_state_peer_creating";
	case _network_session_state_peer_joining:			return "_network_session_state_peer_joining";
	case _network_session_state_peer_join_abort:		return "_network_session_state_peer_join_abort";
	case _network_session_state_peer_peer_established:	return "_network_session_state_peer_peer_established";
	case _network_session_state_peer_leaving:			return "_network_session_state_peer_leaving";
	case _network_session_state_host_established:		return "_network_session_state_host_established";
	case _network_session_state_host_disband:			return "_network_session_state_host_disband";
	case _network_session_state_host_handoff:			return "_network_session_state_host_handoff";
	case _network_session_state_host_reestablish:		return "_network_session_state_host_reestablish";
	case _network_session_state_election:				return "_network_session_state_election";
	case _network_session_state_host_disconnected:		return "_network_session_state_host_disconnected";
	default:
		return "<unknown>";
		break;
	}
}

intptr_t sub_18006DAE0_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1035_0_0: return 0x18006DAE0;
	}
	return ~intptr_t();
}
FunctionHookEx<sub_18006DAE0_offset, int __fastcall (c_network_session* a1, BOOL a2)> sub_18006DAE0 = { "sub_18006DAE0", [](c_network_session* a1, BOOL a2)
{
	auto result = sub_18006DAE0(a1, a2);
	return result;
} };


const char* ppNetworkSessionNames[] = { "Squad Session", "Posse Session", "Group Session", "Target Session" };

intptr_t c_network_session_abort_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1035_0_0: return 0x18006CB40;
	}
	return ~intptr_t();
}
FunctionHookEx<c_network_session_abort_offset, __int64 __fastcall (c_network_session* a1)> c_network_session_abort = { "sub_18006CB40", [](c_network_session* _this)
{
	WriteLineVerbose("c_network_session_abort [%s]", ppNetworkSessionNames[_this->m_session_index]);
	auto result = c_network_session_abort(_this);
	return result;
} };

intptr_t c_network_session_handle_peer_joining_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1035_0_0: return 0x18006DC10;
	}
	return ~intptr_t();
}
FunctionHookEx<c_network_session_handle_peer_joining_offset, void __fastcall (c_network_session* _this)> c_network_session_handle_peer_joining = { "c_network_session::handle_peer_joining", [](c_network_session* _this)
{
	//WriteLineVerbose("c_network_session_handle_peer_joining_offset [%s]", ppNetworkSessionNames[_this->m_session_index]);
	//_this->m_session_membership.m_baseline_update_number = 14;
	c_network_session_handle_peer_joining(_this);
} };

intptr_t sub_180029B70_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1035_0_0: return 0x180029B70;
	}
	return ~intptr_t();
}
FunctionHookEx<sub_180029B70_offset, void __fastcall (c_network_session* _this, __int64 a2, BOOL a3)> sub_180029B70 = { "sub_180029B70::handle_peer_joining", [](c_network_session* _this, __int64 a2, BOOL a3)
{
	//WriteLineVerbose("sub_180029B70 called");
	return sub_180029B70(_this, a2, a3);
} };

intptr_t sub_180019F00_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1035_0_0: return 0x180019F00;
	}
	return ~intptr_t();
}
FunctionHookEx<sub_180019F00_offset, BYTE* __fastcall (c_network_session_membership* a1)> sub_180019F00 = { "sub_180029B70", [](c_network_session_membership* a1)
{
	WriteLineVerbose("sub_180019F00 called");
	return sub_180019F00(a1);
} };

intptr_t sub_18002E040_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1035_0_0: return 0x18002E040;
	}
	return ~intptr_t();
}
FunctionHookEx<sub_18002E040_offset, __int64 __fastcall (c_network_session_membership* a1, BOOL a2)> sub_18002E040 = { "sub_18002E040", [](c_network_session_membership* a1, BOOL a2)
{
	WriteLineVerbose("sub_18002E040 called");
	return sub_18002E040(a1, a2);
} };



intptr_t c_network_session_process_pending_joins_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1035_0_0: return 0x180028D00;
	}
	return ~intptr_t();
}
FunctionHookEx<c_network_session_process_pending_joins_offset, unsigned __int64 __fastcall (c_network_session*)> c_network_session_process_pending_joins = { "c_network_session::process_pending_joins", [](c_network_session* _this)
{
	auto network_session_membership = &_this->m_session_membership;
	auto v36 = 1;
	auto v29 = network_session_membership->m_valid_peer_mask;

	auto v37 = &network_session_membership->m_peers[0].join_nonce;
	auto v84 = &network_session_membership->m_peers[0].join_nonce;
	while (!(v36 & v29))
	{
		v37 += 0x2C;
		v36 *= 2;
		v84 = v37;
		if (!v29)
			break;
	}
	auto& v38 = *((_DWORD*)v37 - 78);

  if (v38 == 4)
  {
	  //v38 = 0;
  }
	return c_network_session_process_pending_joins(_this);
} };

intptr_t c_network_session_add_pending_join_to_session_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1035_0_0: return 0x180029650;
	}
	return ~intptr_t();
}
FunctionHookEx<c_network_session_add_pending_join_to_session_offset, __int64 __fastcall (c_network_session*, unsigned __int64)> c_network_session_add_pending_join_to_session = { "c_network_session::add_pending_join_to_session", [](c_network_session* _this, unsigned __int64 join_nonce)
{
	WriteLineNoSpamVerbose("c_network_session::add_pending_join_to_session [ join_nonce:0x%llx ]", join_nonce);
	return c_network_session_add_pending_join_to_session(_this, join_nonce);
} };

intptr_t c_network_message_handler_handle_channel_message_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1035_0_0: return 0x1800D1C70;
	}
	return ~intptr_t();
}
FunctionHookEx<c_network_message_handler_handle_channel_message_offset, void __fastcall(__int64 a1, __int64 a2, __int64 a3, int a4, __int64 rsi, int a5)> c_network_message_handler_handle_channel_message = { "c_network_message_handler::handle_channel_message",
[](__int64 a1, __int64 a2, __int64 a3, int a4, __int64 rsi, int a5)
{
	WriteLineNoSpamVerbose("c_network_message_handler::handle_channel_message [ %i ]", a4);
	c_network_message_handler_handle_channel_message(
		 a1,
		 a2,
		 a3,
		 a4,
		 rsi,
		 a5
	);
} };

intptr_t c_network_channel_receive_packet_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1035_0_0: return 0x1800A55C0;
	}
	return ~intptr_t();
}
FunctionHookEx<c_network_channel_receive_packet_offset, __int64 __fastcall (__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)> c_network_channel_receive_packet = { "c_network_channel::receive_packet",
[](__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
	WriteLineVerbose("c_network_channel::receive_packet [  ]");
	return c_network_channel_receive_packet(a1, a2, a3, a4);
} };

intptr_t c_network_link_process_packet_internal_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1035_0_0: return 0x1800AE850;
	}
	return ~intptr_t();
}
FunctionHookEx<c_network_link_process_packet_internal_offset, __int64 __fastcall (struct c_network_link* a1, _DWORD* a2)> c_network_link_process_packet_internal =
{ "c_network_link::process_packet_internal", [](struct c_network_link* a1, _DWORD* a2)
{
	//WriteLineVerbose("c_network_link::process_packet_internal [  ]");
	return c_network_link_process_packet_internal(a1, a2);
} };

intptr_t c_network_channel_allocate_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1035_0_0: return 0x1800A4A90;
	}
	return ~intptr_t();
}
FunctionHookEx<c_network_channel_allocate_offset, signed __int64 __fastcall (__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64)> c_network_channel_allocate =
{ "c_network_channel::allocate", [](__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9)
{
	WriteLineVerbose("c_network_channel::allocate [ 0x%llx 0x%llx 0x%llx 0x%llx 0x%llx 0x%llx 0x%llx 0x%llx 0x%llx ]", a1,  a2,  a3,  a4,  a5,  a6,  a7,  a8,  a9);
	return c_network_channel_allocate(a1,  a2,  a3,  a4,  a5,  a6,  a7,  a8,  a9);
} };


intptr_t c_network_channel_manager_recreate_channels_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1035_0_0: return 0x18003BD20;
	}
	return ~intptr_t();
}

Data<BuildVersion::Build_1_1035_0_0, char[1024], 0x18311BA86> unk_18311BA86;

FunctionHookEx<c_network_channel_manager_recreate_channels_offset, void __fastcall (__int64 a1)> c_network_channel_manager_recreate_channels =
{ "c_network_channel_manager::recreate_channels", [](__int64 a1)
{
	WriteLineVerbose("c_network_channel_manager::recreate_channels [ 0x%llx ]", a1);
	c_network_channel_manager_recreate_channels(a1);
} };


intptr_t sub_18003A740_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1035_0_0: return 0x18003A740;
	}
	return ~intptr_t();
}

struct c_network_channel_manager
{

};
Pointer<BuildVersion::Build_1_1035_0_0, c_network_channel_manager*, 0x18311A750> g_network_channel_manager;

FunctionHookEx<sub_18003A740_offset, char __fastcall (__int64, __int64, __int64, __int64, __int64, __int64)> sub_18003A740 =
{ "sub_18003A740", [](__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
	WriteLineVerbose("sub_18003A740 [ 0x%llx 0x%llx 0x%llx 0x%llx 0x%llx 0x%llx ]", a1,  a2,  a3,  a4,  a5,  a6);
	auto result = sub_18003A740(a1, a2, a3, a4, a5, a6);
	return result;
} };


intptr_t c_network_message_gateway__send_message_directed_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1035_0_0: return 0x180078660;
	}
	return ~intptr_t();
}
const char *network_message_type_to_string(e_network_message_type network_message_type)
{
	switch (network_message_type)
	{
	case _network_message_type_ping: return"ping";
	case _network_message_type_pong: return"pong";
	case _network_message_type_broadcast_search: return"broadcast_search";
	case _network_message_type_broadcast_reply: return"broadcast_reply";
	case _network_message_type_connect_request: return"connect_request";
	case _network_message_type_connect_refuse: return"connect_refuse";
	case _network_message_type_connect_establish: return"connect_establish";
	case _network_message_type_connect_closed: return"connect_closed";
	case _network_message_type_join_request: return"join_request";
	case _network_message_type_peer_connect: return"peer_connect";
	case _network_message_type_join_abort: return"join_abort";
	case _network_message_type_join_refuse: return"join_refuse";
	case _network_message_type_leave_session: return"leave_session";
	case _network_message_type_leave_acknowledge: return"leave_acknowledge";
	case _network_message_type_session_disband: return"session_disband";
	case _network_message_type_session_boot: return"session_boot";
	case _network_message_type_host_handoff: return"host_handoff";
	case _network_message_type_peer_handoff: return"peer_handoff";
	case _network_message_type_host_transition: return"host_transition";
	case _network_message_type_host_reestablish: return"host_reestablish";
	case _network_message_type_host_decline: return"host_decline";
	case _network_message_type_peer_reestablish: return"peer_reestablish";
	case _network_message_type_peer_establish: return"peer_establish";
	case _network_message_type_election: return"election";
	case _network_message_type_election_refuse: return"election_refuse";
	case _network_message_type_time_synchronize: return"time_synchronize";
	case _network_message_type_membership_update: return"membership_update";
	case _network_message_type_peer_properties: return"peer_properties";
	case _network_message_type_delegate_leadership: return"delegate_leadership";
	case _network_message_type_boot_machine: return"boot_machine";
	case _network_message_type_player_add: return"player_add";
	case _network_message_type_player_refuse: return"player_refuse";
	case _network_message_type_player_remove: return"player_remove";
	case _network_message_type_player_properties: return"player_properties";
	case _network_message_type_parameters_update: return"parameters_update";
	case _network_message_type_parameters_request: return"parameters_request";
	case _network_message_type_security: return"security";
	case _network_message_type_view_establishment: return"view_establishment";
	case _network_message_type_player_acknowledge: return"player_acknowledge";
	case _network_message_type_synchronous_update: return"synchronous_update";
	case _network_message_type_synchronous_playback_control: return"synchronous_playback_control";
	case _network_message_type_synchronous_actions: return"synchronous_actions";
	case _network_message_type_synchronous_acknowledge: return"synchronous_acknowledge";
	case _network_message_type_synchronous_join_catchup: return"synchronous_join_catchup";
	case _network_message_type_game_results: return"game_results";
	case _network_message_type_end_game: return"end_game";
	case _network_message_type_test: return"test";
	case _network_message_type_test_force_host_machine_name: return"test_force_host_machine_name";
	case _network_message_type_update_queue_element: return "update_queue_element";
	case _network_message_type_update_queue_element1: return "update_queue_element1";
	default:
		return "<unknown>";
	}
}

FunctionHookEx<c_network_message_gateway__send_message_directed_offset, char __fastcall (struct c_network_message_gateway *thisptr, _WORD *a2, e_network_message_type network_message_type, unsigned int a4, __int64 a5)> c_network_message_gateway__send_message_directed =
{ "c_network_message_gateway::send_message_directed", [](struct c_network_message_gateway *thisptr, _WORD *a2, e_network_message_type network_message_type, unsigned int a4, __int64 a5)
{
	WriteLineVerbose("c_network_message_gateway::send_message_directed [%s]", network_message_type_to_string(network_message_type));
	return c_network_message_gateway__send_message_directed(thisptr, a2, network_message_type, a4, a5);
} };