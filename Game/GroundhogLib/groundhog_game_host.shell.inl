
#pragma region Shell Debug
uintptr_t groundhog_external_launch_individual_state_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_groundhog, _build_mcc_1_1477_0_0, 0x18130E224);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1499_0_0, 0x18130E2A4);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1520_0_0, 0x18130E2A4);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1570_0_0, 0x18130E324);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1619_0_0, 0x18130E324);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1698_0_0, 0x181311524);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1716_0_0, 0x181311524);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1829_0_0, 0x18128BBF4);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1864_0_0, 0x18128BBF4);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1871_0_0, 0x18128BBF4);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1955_0_0, 0x180F02CFC);
	OFFSET(_engine_type_groundhog, _build_mcc_1_2028_0_0, 0x180F02CFC);
	return ~uintptr_t();
}
long& groundhog_external_launch_individual_state = reference_symbol<long>("groundhog_external_launch_individual_state", groundhog_external_launch_individual_state_offset);

uintptr_t groundhog_main_game_launch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_groundhog, _build_mcc_1_1477_0_0, 0x1800265D0);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1499_0_0, 0x1800265D0);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1520_0_0, 0x1800265D0);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1570_0_0, 0x1800265D0);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1619_0_0, 0x1800265D0);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1698_0_0, 0x1800265D0);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1716_0_0, 0x1800265D0);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1829_0_0, 0x180027810);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1864_0_0, 0x180027810);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1871_0_0, 0x180027810);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1955_0_0, 0x18003E8F0);
	OFFSET(_engine_type_groundhog, _build_mcc_1_2028_0_0, 0x18003E8F0);
	return ~uintptr_t();
}
c_function_hook_ex<groundhog_main_game_launch_offset, char __fastcall (__int64 a1, __int64 a2)> groundhog_main_game_launch = { "groundhog_main_game_launch", [](__int64 a1, __int64 a2)
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

	ASSERT(is_valid(groundhog_main_game_launch));
	if (is_valid(groundhog_external_launch_individual_state))
	{
		static long external_launch_individual_state_prev = -1l;
		if (groundhog_external_launch_individual_state != external_launch_individual_state_prev)
		{
			external_launch_individual_state_prev = groundhog_external_launch_individual_state;
			printf("groundhog_external_launch_individual_state changed to: %s\n", external_launch_individual_state_names[groundhog_external_launch_individual_state]);
		}

		char result = groundhog_main_game_launch(a1, a2);

		if (groundhog_external_launch_individual_state != external_launch_individual_state_prev)
		{
			external_launch_individual_state_prev = groundhog_external_launch_individual_state;
			printf("groundhog_external_launch_individual_state changed to: %s\n", external_launch_individual_state_names[groundhog_external_launch_individual_state]);
		}

		return result;
	}
	else
	{
		char result = groundhog_main_game_launch(a1, a2);
		return result;
	}

} };
#pragma endregion