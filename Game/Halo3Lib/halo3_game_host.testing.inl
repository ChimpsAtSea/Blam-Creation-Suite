
#pragma region network tests

uintptr_t transport_endpoint_bind_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x18022C0D0);
	return ~uintptr_t();
}
c_function_hook_ex<transport_endpoint_bind_offset, bool __fastcall(__int64 a1, __int64 a2)> transport_endpoint_bind = { "transport_endpoint_bind", [](__int64 a1, __int64 a2)
{
	bool result = transport_endpoint_bind(a1, a2);
	return result;
} };

uintptr_t transport_endpoint_bind_shell_host_patch_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x18022C11E);
	return ~uintptr_t();
}
c_data_patch<transport_endpoint_bind_shell_host_patch_offset> transport_endpoint_bind_shell_host_patch = {
	[](s_engine_platform_build engine_platform_build, char* data, DataPatchPacket& packet)
	{
		packet = MAKE_DATAPATCHPACKET(data, 2);
		nop_address(data, 2);
	}
};

uintptr_t sendto_with_error_code_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x18022C820);
	return ~uintptr_t();
}
c_function_hook_ex<sendto_with_error_code_offset, int __fastcall(SOCKET* a1, const char* a2, __int16 a3, __int64 a4)> sendto_with_error_code = { "sendto_with_error_code", [](SOCKET* a1, const char* a2, __int16 a3, __int64 a4)
{
	*(_WORD*)(a4 + 18) = 4;
	int result = sendto_with_error_code(a1, a2, a3, a4);
	return result;
} };

#pragma endregion

#pragma region network_message_type tests

struct c_halo3_network_message_type
{
	bool initialized;
	char __pad1[7];
	const char* name;
	__int32 __unknown10;
	int min_len;
	int max_len;
	char __pad1C[4];
	void(__fastcall* encode_callback)(class c_bit_stream* stream, int len, const void* packet);
	bool(__fastcall* decode_callback)(class c_bit_stream* stream, int len, void* packet);
	void* __unknown30; // unknkown callback
	void* __unknown38; // unknkown callback
};
static_assert_64(sizeof(c_halo3_network_message_type) == 0x40);

enum class e_halo3_network_message_type : long
{
	_ping,
	_pong,
	_broadcast_search,
	_broadcast_reply,
	_connect_request,
	_connect_refuse,
	_connect_establish,
	_connect_closed,
	_join_request,
	_peer_connect,
	_join_abort,
	_join_refuse,
	_leave_session,
	_leave_acknowledge,
	_session_disband,
	_session_boot,
	_host_handoff,
	_peer_handoff,
	_host_transition,
	_host_reestablish,
	_host_decline,
	_peer_reestablish,
	_peer_establish,
	_election,
	_election_refuse,
	_time_synchronize,
	_membership_update,
	_peer_properties,
	_delegate_leadership,
	_boot_machine,
	_player_add,
	_player_refuse,
	_player_remove,
	_player_properties,
	_parameters_update,
	_parameters_request,
	_view_establishment,
	_player_acknowledge,
	_synchronous_update,
	_synchronous_playback_control,
	_synchronous_actions,
	_synchronous_acknowledge,
	_synchronous_gamestate,
	_game_results,
	_synchronous_client_ready,
	_test,

	k_count,

	// custom `network_message_types` start here
	k_custom_start = -1,
	//_custom_test,

	k_custom_count
};

const long k_halo3_network_message_type_collection_size = 0xB80;
const long k_number_of_halo3_network_message_types = underlying_cast(e_halo3_network_message_type::k_count); // 46
const long k_number_of_custom_halo3_network_message_types = underlying_cast(e_halo3_network_message_type::k_custom_count); // 0

c_halo3_network_message_type custom_network_message_type_collection[k_number_of_halo3_network_message_types + k_number_of_custom_halo3_network_message_types];

uintptr_t network_message_type_collection_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x180A651F0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x180A651F0);
	return ~uintptr_t();
}
c_halo3_network_message_type(&network_message_type_collection)[k_number_of_halo3_network_message_types]
= reference_symbol<c_halo3_network_message_type[k_number_of_halo3_network_message_types]>("network_message_type_collection", network_message_type_collection_offset);

uintptr_t simulation_view_initialize_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x1801F4E50);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x1801F4E50);
	return ~uintptr_t();
}
c_function_hook_ex<simulation_view_initialize_offset, char __fastcall(void**, void**, void**, void**, void**, void**, void**, void**)> simulation_view_initialize
= { "simulation_view_initialize", [](void** link, void** collection, void** a3, void** a4, void** a5, void** a6, void** a7, void** a8)
{
	char result = simulation_view_initialize(link, collection, a3, a4, a5, a6, a7, a8);

	if (k_number_of_custom_halo3_network_message_types > 0)
	{
		*collection = &custom_network_message_type_collection;
	}

	return result;
} };

uintptr_t network_message_types_initialize_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x1801FBD70);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x1801FBD70);
	return ~uintptr_t();
}
c_function_hook_ex<network_message_types_initialize_offset, void* __fastcall(void*)> network_message_types_initialize = { "network_message_types_initialize", [](void* collection)
{
	void* result = network_message_types_initialize(collection);

	const long custom_network_message_type_collection_size = sizeof(c_halo3_network_message_type) * (k_number_of_halo3_network_message_types + k_number_of_custom_halo3_network_message_types);
	if (custom_network_message_type_collection_size > k_halo3_network_message_type_collection_size)
	{
		result = memset(collection, 0, custom_network_message_type_collection_size);
	}

	return result;
} };

void network_message_types_test_command()
{
	const char* enum_name = "network_message_type";
	const char* enum_type = "long";

	c_console::write_line_verbose("enum e_%s : %s", enum_name, enum_type);
	c_console::write_line("{");
	for (long i = 0; i < k_number_of_halo3_network_message_types; i++)
	{
		std::string name = network_message_type_collection[i].name;
		std::replace(name.begin(), name.end(), '-', '_');
		c_console::write_line_verbose("\t_%s_%s,", enum_name, name.c_str());
	}
	c_console::write_line_verbose("\tk_number_of_%ss", enum_name);
	c_console::write_line("}");

	return;
}

#pragma endregion