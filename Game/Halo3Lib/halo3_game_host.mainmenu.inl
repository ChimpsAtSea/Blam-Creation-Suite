
#pragma region MCC Parse Hooks
uintptr_t game_options_map_id_parse_to_halo3_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1802913C0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18028B920);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18028B9C0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18028B9C0);
	// not available for builds 1767-1955
	return ~uintptr_t();
}
c_function_hook_ex<game_options_map_id_parse_to_halo3_offset, long __fastcall(s_game_options_v2*)> game_options_map_id_parse_to_halo3 = { "game_options_map_id_parse_to_halo3", [](s_game_options_v2* options)
{
	long result = game_options_map_id_parse_to_halo3(options);
	return result == -1l ? options->map_id : result;
} };

uintptr_t mcc_map_id_parse_from_halo3_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180290FC0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18028B520);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18028B5C0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18028B5C0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x18011D980);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x18011D980);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 0x18011DE50);
	OFFSET(_engine_type_halo3, _build_mcc_1_1829_0_0, 0x180122F50);
	OFFSET(_engine_type_halo3, _build_mcc_1_1864_0_0, 0x180122F50);
	OFFSET(_engine_type_halo3, _build_mcc_1_1871_0_0, 0x180122F50);
	OFFSET(_engine_type_halo3, _build_mcc_1_1955_0_0, 0x1800E3704);
	OFFSET(_engine_type_halo3, _build_mcc_1_2028_0_0, 0x1800E5D40);
	return ~uintptr_t();
}
c_function_hook_ex<mcc_map_id_parse_from_halo3_offset, long __fastcall(long)> mcc_map_id_parse_from_halo3 = { "mcc_map_id_parse_from_halo3", [](long map_id)
{
	long result = mcc_map_id_parse_from_halo3(map_id);
	return result == -1l ? map_id : result;
} };

bool launched_as_mainmenu = false;
uintptr_t mcc_map_id_parse_to_halo3_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1802915C0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18028BB20);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18028BBC0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18028BBC0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x18011D780);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x18011D780);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 0x18011DC50);
	OFFSET(_engine_type_halo3, _build_mcc_1_1829_0_0, 0x180122D50);
	OFFSET(_engine_type_halo3, _build_mcc_1_1864_0_0, 0x180122D50);
	OFFSET(_engine_type_halo3, _build_mcc_1_1871_0_0, 0x180122D50);
	OFFSET(_engine_type_halo3, _build_mcc_1_1955_0_0, 0x1800E3554);
	OFFSET(_engine_type_halo3, _build_mcc_1_2028_0_0, 0x1800E5B90);
	return ~uintptr_t();
}
c_function_hook_ex<mcc_map_id_parse_to_halo3_offset, long __fastcall(long)> mcc_map_id_parse_to_halo3 = { "mcc_map_id_parse_to_halo3", [](long map_id)
{
	launched_as_mainmenu = map_id == _map_id_mainmenu;
	long result = mcc_map_id_parse_to_halo3(map_id);
	return result == -1l ? map_id : result;
} };

uintptr_t mcc_game_mode_parse_to_halo3_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180290BE1 + 1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18028B141 + 1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18028B1E1 + 1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18028B1E1 + 1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x18000F1E8 + 1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x18000F1E8 + 1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 0x18000F5E8 + 1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1829_0_0, 0x180014188 + 1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1864_0_0, 0x180014188 + 1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1871_0_0, 0x180014188 + 1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1955_0_0, 0x180011FE5);
	OFFSET(_engine_type_halo3, _build_mcc_1_2028_0_0, 0x1800143C5);
	return ~uintptr_t();
}
c_data_patch<mcc_game_mode_parse_to_halo3_patch_offset> mcc_game_mode_parse_to_halo3_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	packet = MAKE_DATAPATCHPACKET(data, 4);
	if (build == _build_mcc_1_1955_0_0)
	{
		nop_address(data, 4);
	}
	else
	{
		int game_mode = 2;
		copy_to_address(data, &game_mode, 4);
	}
} };
#pragma endregion

#pragma region Main Menu Patches
size_t halo3_enable_mainmenu_scenario_patch_size(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 2);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 2);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 2);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 2);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 2);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 6);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 6);
	OFFSET(_engine_type_halo3, _build_mcc_1_1829_0_0, 6);
	OFFSET(_engine_type_halo3, _build_mcc_1_1864_0_0, 6);
	OFFSET(_engine_type_halo3, _build_mcc_1_1871_0_0, 6);
	OFFSET(_engine_type_halo3, _build_mcc_1_1955_0_0, 2);
	OFFSET(_engine_type_halo3, _build_mcc_1_2028_0_0, 2);
	return ~size_t();
}
// prevents to game from exiting and switching the thread mode to single-threaded for safe engine disposal?
// this patch solves the issue of not being able to load `_scenario_type_mainmenu`
uintptr_t halo3_enable_mainmenu_scenario_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1802E5FDE);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x1802E06AE);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x1802E07C6);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x1802E07C6);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x1801752B5);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x180175345);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 0x180175815);
	OFFSET(_engine_type_halo3, _build_mcc_1_1829_0_0, 0x18017A495);
	OFFSET(_engine_type_halo3, _build_mcc_1_1864_0_0, 0x18017A495);
	OFFSET(_engine_type_halo3, _build_mcc_1_1871_0_0, 0x18017A495);
	OFFSET(_engine_type_halo3, _build_mcc_1_1955_0_0, 0x180122AEA);
	OFFSET(_engine_type_halo3, _build_mcc_1_2028_0_0, 0x180125372);
	return ~uintptr_t();
}
c_data_patch<halo3_enable_mainmenu_scenario_patch_offset> halo3_enable_mainmenu_scenario_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	size_t patch_size = halo3_enable_mainmenu_scenario_patch_size(engine_type, build);
	if (patch_size != ~size_t())
	{
		packet = MAKE_DATAPATCHPACKET(data, patch_size);
		nop_address(data, patch_size);
	}
} };

// prevents to game from exiting and switching the thread mode to single-threaded for safe engine disposal?
// this patch solves the issue of the mainmenu turning into a slideshow after (overall_timeout=120000)/(individual_state_timeout=60000) milliseconds
uintptr_t halo3_external_launch_timeout_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180012F60);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18000D2B5);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18000D2F5);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18000D2F5);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x1800ED051);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x1800ED051);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 0x1800ED451);
	OFFSET(_engine_type_halo3, _build_mcc_1_1829_0_0, 0x1800F25E1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1864_0_0, 0x1800F25E1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1871_0_0, 0x1800F25E1);
	OFFSET(_engine_type_halo3, _build_mcc_1_1955_0_0, 0x1800BE4E0);
	OFFSET(_engine_type_halo3, _build_mcc_1_2028_0_0, 0x1800C0AC4);
	return ~uintptr_t();
}
c_data_patch<halo3_external_launch_timeout_patch_offset> halo3_external_launch_timeout_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	uint8_t jump[6] { 0x90ui8, 0x90ui8, 0x90ui8, 0x90ui8, 0x90ui8, 0x90ui8 };
	packet = MAKE_DATAPATCHPACKET(data, sizeof(jump));

	// 0F 85 cw/cd 	JNE rel16/32 	Jump near if not equal (ZF=0)
	// 0F 85 cw/cd 	JNZ rel16/32 	Jump near if not zero (ZF=0)
	if (data[0] == 0x0Fi8 && data[1] == 0x85i8) // check the type of jump is JNE/JNZ
	{
		// set the type of jump to JMP
		jump[0] = 0xE9ui8;
		// set the relative offset
		*(uint32_t*)&jump[1] = (*(uint32_t*)&data[2]) + 1;

		copy_to_address(data, jump, sizeof(jump));
	}
} };

uintptr_t ui_game_mode_request_change_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1801A3C60);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18019DEC0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x1804B7070);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x1804B7070);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x18001C3D0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x18001C3D0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 0x18001C7D0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1829_0_0, 0x180021370);
	OFFSET(_engine_type_halo3, _build_mcc_1_1864_0_0, 0x180021370);
	OFFSET(_engine_type_halo3, _build_mcc_1_1871_0_0, 0x180021370);
	return ~uintptr_t();
}
c_function_hook_ex<ui_game_mode_request_change_offset, char __fastcall(int)> ui_game_mode_request_change = { "ui_game_mode_request_change", [](int ui_game_mode)
{
	static int ui_game_mode_request_change_call_count = 0;
	ui_game_mode_request_change_call_count++;
	if (launched_as_mainmenu || ui_game_mode == 1) // if mode equals matchmaking
	{
		ui_game_mode = 0; // then mode equals campaign
		if (ui_game_mode_request_change_call_count > 1)
		{
			ui_game_mode = 2; // then mode equals customs
			launched_as_mainmenu = false;
		}
	}

	return ui_game_mode_request_change(ui_game_mode);
} };

uintptr_t ui_game_mode_request_change_inlined_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1955_0_0, 0x18003A468);
	OFFSET(_engine_type_halo3, _build_mcc_1_2028_0_0, 0x18003C978);
	return ~uintptr_t();
}
c_function_hook_ex<ui_game_mode_request_change_inlined_offset, char __fastcall(void*, int)> ui_game_mode_request_change_inlined = { "ui_game_mode_request_change_inlined", [](void* a1, int ui_game_mode)
{
	static int ui_game_mode_request_change_call_count = 0;
	ui_game_mode_request_change_call_count++;
	if (launched_as_mainmenu || ui_game_mode == 1) // if mode equals matchmaking
	{
		ui_game_mode = 0; // then mode equals campaign
		if (ui_game_mode_request_change_call_count > 2)
		{
			ui_game_mode = 2; // then mode equals customs
			launched_as_mainmenu = false;
		}
	}

	return ui_game_mode_request_change_inlined(a1, ui_game_mode);
} };

uintptr_t preferences_ui_game_mode_change_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180501980);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x1804FFF90);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x180500200);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x180500200);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x1803C5180);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x1803C52B0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 0x1803C58C0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1829_0_0, 0x1803CBA30);
	OFFSET(_engine_type_halo3, _build_mcc_1_1864_0_0, 0x1803CBA30);
	OFFSET(_engine_type_halo3, _build_mcc_1_1871_0_0, 0x1803CBA30);
	OFFSET(_engine_type_halo3, _build_mcc_1_1955_0_0, 0x1802E5BFC);
	OFFSET(_engine_type_halo3, _build_mcc_1_2028_0_0, 0x1802E882C);
	return ~uintptr_t();
}
c_function_hook_ex<preferences_ui_game_mode_change_offset, void* __fastcall(void*, int)> preferences_ui_game_mode_change = { "preferences_ui_game_mode_change", [](void* a1, int ui_game_mode)
{
	if (ui_game_mode == 1) // if mode equals matchmaking
	{
		ui_game_mode = 2; // then mode equals customs
	}

	return preferences_ui_game_mode_change(a1, ui_game_mode);
} };
#pragma endregion