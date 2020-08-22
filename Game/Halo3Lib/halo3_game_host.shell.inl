
#pragma region Shell Debug
uintptr_t shell_get_external_host_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180014120);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18000E3C0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18000E480);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18000E480);
	//OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x18000F5B0); this build inlined `shell_get_external_host` so this offset is only used in one place
	//OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x18000F5B0); this build inlined `shell_get_external_host` so this offset is only used in one place
	return ~uintptr_t();
}
FunctionHookEx<shell_get_external_host_offset, void* __fastcall(void)> shell_get_external_host = { "shell_get_external_host", []()
{
	debug_point;
	void* result = shell_get_external_host();
	//result = nullptr;
	return result;
} };
uintptr_t halo3_external_launch_state_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x18B7CB010);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18B7DF74C);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18B7BAE4C);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18B7BAE4C);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x180B6098C);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x180B6098C);
	return ~uintptr_t();
}
long& halo3_external_launch_state = reference_symbol<long>("halo3_external_launch_state", halo3_external_launch_state_offset);

uintptr_t halo3_main_game_launch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1800138E0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18000DC20);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18000DCA0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18000DCA0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x18000EF10);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x18000EF10);
	return ~uintptr_t();
}
FunctionHookEx<halo3_main_game_launch_offset, char __fastcall(__int64 a1, __int64 a2)> halo3_main_game_launch = { "halo3_main_game_launch", [](__int64 a1, __int64 a2)
{
	static const char* external_launch_state_names[] =
	{
		"initial",
		"create_local_squad",
		"select_game_mode",
		"saved_film",
		"campaign",
		"save_game",
		"multiplayer",
		"",
		"wait_for_party",
		"join_remote_squad",
		"start_game",
		"finished"
	};

	ASSERT(is_valid(halo3_main_game_launch));
	if (is_valid(halo3_external_launch_state))
	{
		static long halo3_external_launch_state_prev = -1l;
		if (halo3_external_launch_state != halo3_external_launch_state_prev)
		{
			halo3_external_launch_state_prev = halo3_external_launch_state;
			printf("halo3_main_game_launch changed to: %s\n", external_launch_state_names[halo3_external_launch_state]);
		}

		char result = halo3_main_game_launch(a1, a2);

		if (halo3_external_launch_state != halo3_external_launch_state_prev)
		{
			halo3_external_launch_state_prev = halo3_external_launch_state;
			printf("halo3_external_launch_state changed to: %s\n", external_launch_state_names[halo3_external_launch_state]);
		}

		return result;
	}
	else
	{
		char result = halo3_main_game_launch(a1, a2);
		return result;
	}
} };
#pragma endregion