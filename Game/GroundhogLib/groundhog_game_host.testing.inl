
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
	_load_state_start_game,
	_load_state_terminate,

	k_number_of_load_states,
	k_load_state_invalid = -1,
};


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
		static int external_launch_individual_state_prev = k_load_state_invalid;
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