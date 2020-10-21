
#pragma region Shell Debug
uintptr_t halo4_external_launch_state_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo4, _build_mcc_1_1896_0_0, 0x180F1FA7C);
	return ~uintptr_t();
}
long& halo4_external_launch_state = reference_symbol<long>("halo4_external_launch_state", halo4_external_launch_state_offset);

uintptr_t halo4_main_game_launch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo4, _build_mcc_1_1896_0_0, 0x18003EBA4);
	return ~uintptr_t();
}
c_function_hook_ex<halo4_main_game_launch_offset, char __fastcall(__int64 a1, __int64 a2, __int64 a3)> halo4_main_game_launch = { "halo4_main_game_launch", [](__int64 a1, __int64 a2, __int64 a3)
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
		"spartan_ops",
		"wait_for_party",
		"join_remote_squad",
		"start_game",
		"finished"
	};

	ASSERT(is_valid(halo4_main_game_launch));
	if (is_valid(halo4_external_launch_state))
	{
		static long halo4_external_launch_state_prev = -1l;
		if (halo4_external_launch_state != halo4_external_launch_state_prev)
		{
			halo4_external_launch_state_prev = halo4_external_launch_state;
			printf("halo4_main_game_launch changed to: %s\n", external_launch_state_names[halo4_external_launch_state]);
		}

		char result = halo4_main_game_launch(a1, a2, a3);

		if (halo4_external_launch_state != halo4_external_launch_state_prev)
		{
			halo4_external_launch_state_prev = halo4_external_launch_state;
			printf("halo4_external_launch_state changed to: %s\n", external_launch_state_names[halo4_external_launch_state]);
		}

		return result;
	}
	else
	{
		char result = halo4_main_game_launch(a1, a2, a3);
		return result;
	}
} };
#pragma endregion