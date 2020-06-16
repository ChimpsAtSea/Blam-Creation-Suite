enum e_load_state
{
	_load_state_initial,
	_load_state_create_local_squad,
	_load_state_select_game_mode,
	_load_state_saved_film,
	_load_state_campaign,
	_load_state_save_game,
	_load_state_multiplayer,
	_load_state_survival,
	_load_state_wait_for_party,
	_load_state_join_remote_squad,
	_load_state_unused,
	_load_state_start_game,
	_load_state_terminate,

	k_number_of_load_states,
	k_load_state_invalid = -1,
};

UINT64 file_get_image_base_address(LPCWSTR filename)
{
	UINT64 result = 0ull;
	HANDLE file = CreateFile(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if (file != INVALID_HANDLE_VALUE)
	{
		HANDLE file_mapping = CreateFileMapping(file, NULL, PAGE_READONLY, 0, 0, NULL);
		if (file_mapping != 0)
		{
			LPVOID file_base_address = MapViewOfFile(file_mapping, FILE_MAP_READ, 0, 0, 0);
			if (file_base_address != 0)
			{
				PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)file_base_address;
				if (dos_header->e_magic == IMAGE_DOS_SIGNATURE)
				{
					PIMAGE_NT_HEADERS nt_header = (PIMAGE_NT_HEADERS)((UINT64)dos_header + (UINT64)dos_header->e_lfanew);
					result = nt_header->OptionalHeader.ImageBase;
				}
				UnmapViewOfFile(file_base_address);
			}
			CloseHandle(file_mapping);
		}
		CloseHandle(file);
	}
	return result;
};

void write_stack_back_trace(LPCWSTR calling_function, DWORD depth = 1, DWORD size = 1024)
{
	depth++;
	c_console::write_line_verbose("TRACE(%ls)\n{", calling_function);

	LPVOID* traces = new LPVOID[size];
	for (int trace_index = 0; trace_index < CaptureStackBackTrace(depth, size, traces, NULL); trace_index++)
	{
		HANDLE current_process = GetCurrentProcess();
		HMODULE modules[1024]; DWORD needed;
		if (EnumProcessModules(current_process, modules, sizeof(modules), &needed))
		{
			for (UINT32 module_index = 0; module_index < (needed / sizeof(HMODULE)); module_index++)
			{
				MODULEINFO module_information;
				if (GetModuleInformation(current_process, modules[module_index], &module_information, sizeof(module_information)))
				{
					UINT64 module_top_address = (UINT64)module_information.lpBaseOfDll + (UINT64)module_information.SizeOfImage;
					if (traces[trace_index] >= module_information.lpBaseOfDll && (UINT64)traces[trace_index] < module_top_address)
					{
						UINT64 module_offset = 0;
						if (module_offset = (UINT64)traces[trace_index] - (UINT64)module_information.lpBaseOfDll)
						{
							wchar_t szModName[MAX_PATH];
							if (GetModuleFileNameEx(current_process, modules[module_index], szModName, sizeof(szModName) / sizeof(wchar_t)))
							{
								std::wstring module_name = std::wstring(szModName).substr(std::wstring(szModName).find_last_of(L"/\\") + 1);
								UINT64 module_base_address = file_get_image_base_address(szModName) + module_offset;
								c_console::write_line_verbose("\t%16ls+0x%08IIX, 0x%016IIX", module_name.c_str(), module_offset, module_base_address);
							}
						}
					}
				}
			}
		}
	}

	c_console::write_line_verbose("}");
};

uintptr_t enable_mainmenu_scenario_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1802E5FDE);
	return ~uintptr_t();
}
c_data_patch<enable_mainmenu_scenario_patch_offset> enable_mainmenu_scenario_patch = {
	[](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
	{
		packet = MAKE_DATAPATCHPACKET(data, 2);
		nop_address(data, 2);
	}
};

uintptr_t engine_shutdown_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1802659D0);
	return ~uintptr_t();
}
FunctionHookEx<engine_shutdown_offset, void()> engine_shutdown = { "engine_shutdown", []()
{
		//write_stack_back_trace(__FUNCTIONW__, 2);
		//engine_shutdown();
	} };

uintptr_t sub_180290BD0_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180290BD0);
	return ~uintptr_t();
}
FunctionHookEx<sub_180290BD0_offset, int __fastcall(c_game_context_v3* a1)> sub_180290BD0 = { "sub_180290BD0", [](c_game_context_v3* a1)
{
		//long result = sub_180290BD0(a1);

		switch (a1->game_mode)
		{
		case 0: return 0;
		case 1: return 1;
		case 2: return 2;
		default: return 2;
		}


		//result = nullptr;
		//return result;
	} };

uintptr_t shell_get_external_host_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180014120);
	return ~uintptr_t();
}
FunctionHookEx<shell_get_external_host_offset, IGameEngineHost* __fastcall(void)> shell_get_external_host = { "shell_get_external_host", []()
{
	IGameEngineHost* result = shell_get_external_host();
	//result = nullptr;
	return result;
} };

uintptr_t transport_endpoint_bind_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x18022C0D0);
	return ~uintptr_t();
}
FunctionHookEx<transport_endpoint_bind_offset, bool __fastcall(__int64 a1, __int64 a2)> transport_endpoint_bind = { "transport_endpoint_bind", [](__int64 a1, __int64 a2)
{
	bool result = transport_endpoint_bind(a1, a2);
	return result;
} };

uintptr_t transport_endpoint_bind_shell_host_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x18022C11E);
	return ~uintptr_t();
}
c_data_patch<transport_endpoint_bind_shell_host_patch_offset> transport_endpoint_bind_shell_host_patch = {
	[](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
	{
		packet = MAKE_DATAPATCHPACKET(data, 2);
		nop_address(data, 2);
	}
};

uintptr_t settings_menu_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1804C176B);
	return ~uintptr_t();
}
c_data_patch<settings_menu_patch_offset> settings_menu_patch = {
	[](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
	{
		packet = MAKE_DATAPATCHPACKET(data, 3);
		nop_address(data, 3);
	}
};

uintptr_t settings_menu_patch2_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1804C183A);
	return ~uintptr_t();
}
c_data_patch<settings_menu_patch2_offset> settings_menu_patch2 = {
	[](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
	{
		packet = MAKE_DATAPATCHPACKET(data, 6);
		nop_address(data, 6);
	}
};

// prevents to game from exiting and switching the thread mode to single-threaded for safe engine disposal?
// this patch solves to issue of the mainmenu turning into a slideshow after (overall_timeout=120000)/(individual_state_timeout=60000) milliseconds
uintptr_t external_launch_timeout_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180012F60);
	return ~uintptr_t();
}
c_data_patch<external_launch_timeout_patch_offset> external_launch_timeout_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
		// change `jnz     loc_180013096` to `jmp     loc_180013096`
		UINT8 jmp[6] = { 0xE9, 0x31, 0x01, 0x00, 0x00, 0x90 };
		packet = MAKE_DATAPATCHPACKET(jmp, sizeof(jmp));
		copy_to_address(data, jmp, sizeof(jmp));

		/// the offending code, some form of silent exception handler? or perhaps and if
		//	unsigned int game_exit_reason = g_game_exit_reason;
		//	if (!g_game_exit_reason)
		//		game_exit_reason = 3;
		//	g_game_exit_reason = game_exit_reason;
		//	if (game_engine_host)
		//	{
		//		unsigned int debug_source_file_print_result = debug_source_file_print("e:\jenkins\workspace\mcch3codebuild-ring1\mcc\ring1\h3\source\shell\shell_durango_dll.cpp", 1413);
		//		game_set_shutdown_started();
		//		game_set_thread_mode(debug_source_file_print_result); // is this called `game_set_thread_mode` or am I making a bad assumption based on what I can see within the function?
		//	}
} };

uintptr_t sendto_with_error_code_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x18022C820);
	return ~uintptr_t();
}
FunctionHookEx<sendto_with_error_code_offset, int __fastcall(SOCKET* a1, const char* a2, __int16 a3, __int64 a4)> sendto_with_error_code = { "sendto_with_error_code", [](SOCKET* a1, const char* a2, __int16 a3, __int64 a4)
{
	*(_WORD*)(a4 + 18) = 4;
	int result = sendto_with_error_code(a1, a2, a3, a4);
	return result;
} };

uintptr_t mcc_map_id_parse_to_halo3_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1802913C0);
	return ~uintptr_t();
}
FunctionHookEx<mcc_map_id_parse_to_halo3_offset, long __fastcall(c_game_context_v3* game_context)> mcc_map_id_parse_to_halo3 = { "mcc_map_id_parse_to_halo3", [](c_game_context_v3* game_context)
{
	long result = mcc_map_id_parse_to_halo3(game_context);
	return result == -1 ? game_context->map_id : result;
} };

uintptr_t mcc_map_id_parse_from_halo3_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1802915C0);
	return ~uintptr_t();
}
FunctionHookEx<mcc_map_id_parse_from_halo3_offset, long __fastcall(long map_id)> mcc_map_id_parse_from_halo3 = { "mcc_map_id_parse_from_halo3", [](long map_id)
{
	long result = mcc_map_id_parse_from_halo3(map_id);
	return result == -1 ? map_id : result;
} };

uintptr_t halo3_external_launch_individual_state_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x18B7CB010);
	return ~uintptr_t();
}
long& halo3_external_launch_individual_state = reference_symbol<long>("halo3_external_launch_individual_state", halo3_external_launch_individual_state_offset);

uintptr_t halo3_main_game_launch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1800138E0);
	return ~uintptr_t();
}
FunctionHookEx<halo3_main_game_launch_offset, char __fastcall (__int64 a1, __int64 a2)> halo3_main_game_launch = { "halo3_main_game_launch", [](__int64 a1, __int64 a2)
{
	static const char* external_launch_individual_state_names[] =
	{
		"initial",
		"create_local_squad",
		"select_game_mode",
		"saved_film",
		"campaign",
		"save_game",
		"multiplayer",
		"survival",
		"wait_for_party",
		"join_remote_squad",
		"start_game",
		"finished"
	};

	ASSERT(is_valid(halo3_main_game_launch));
	if (is_valid(halo3_external_launch_individual_state))
	{
		static int external_launch_individual_state_prev = k_load_state_invalid;
		if (halo3_external_launch_individual_state != external_launch_individual_state_prev)
		{
			external_launch_individual_state_prev = halo3_external_launch_individual_state;
			printf("halo3_main_game_launch changed to: %s\n", external_launch_individual_state_names[halo3_external_launch_individual_state]);
		}

		char result = halo3_main_game_launch(a1, a2);

		if (halo3_external_launch_individual_state != external_launch_individual_state_prev)
		{
			external_launch_individual_state_prev = halo3_external_launch_individual_state;
			printf("halo3_external_launch_individual_state changed to: %s\n", external_launch_individual_state_names[halo3_external_launch_individual_state]);
		}

		return result;
	}
	else
	{
		char result = halo3_main_game_launch(a1, a2);
		return result;
	}
} };

