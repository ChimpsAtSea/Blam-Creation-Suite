
#pragma region Shell Debug
uintptr_t haloreach_external_launch_individual_state_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_824_0_0, 0x180F2BAA4);
	OFFSET(_engine_type_haloreach, _build_mcc_1_887_0_0, 0x1810EC5A4);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1035_0_0, 0x180D37AB0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1186_0_0, 0x180D4E674);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1211_0_0, 0x180D4F674);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1246_0_0, 0x180D494F4);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1270_0_0, 0x180D494F4);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1305_0_0, 0x180CF8AF4);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1350_0_0, 0x180D05EF4);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x180D05EF4);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1377_0_0, 0x180D05EF4);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1384_0_0, 0x180D05EF4);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1387_0_0, 0x180D05EF4);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x180D05EF4);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1520_0_0, 0x180D08274);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1570_0_0, 0x180D08274);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1619_0_0, 0x180D08274);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1698_0_0, 0x180D0A1F4);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1716_0_0, 0x180D0A1F4);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1829_0_0, 0x180DA1C74);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1864_0_0, 0x180DA1C74);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1871_0_0, 0x180DA1C74);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1930_0_0, 0x180B22274);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x180B22274);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2028_0_0, 0x180B22274);
	return ~uintptr_t();
}
long& haloreach_external_launch_individual_state = reference_symbol<long>("haloreach_external_launch_individual_state", haloreach_external_launch_individual_state_offset);

uintptr_t haloreach_main_game_launch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_824_0_0, 0x180011110);
	OFFSET(_engine_type_haloreach, _build_mcc_1_887_0_0, 0x180013EA0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1035_0_0, 0x1800113F0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1186_0_0, 0x180011860);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1211_0_0, 0x180011870);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1246_0_0, 0x180011870);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1270_0_0, 0x180011870);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1305_0_0, 0x180011870);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1350_0_0, 0x180012580);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x180012520);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1377_0_0, 0x180012520);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1384_0_0, 0x180012520);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1387_0_0, 0x180012520);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x180012520);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1520_0_0, 0x180012550);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1570_0_0, 0x180012550);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1619_0_0, 0x180012550);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1698_0_0, 0x1800124C0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1716_0_0, 0x1800124C0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1829_0_0, 0x180014F30);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1864_0_0, 0x180014F30);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1871_0_0, 0x180014F30);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1930_0_0, 0x180011058);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x180011058);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2028_0_0, 0x180011058);

	if (engine_type == _engine_type_haloreach)
	{
		using namespace ketchup;
		c_pattern_scanner ps = c_pattern_scanner(GetCurrentProcess(), static_cast<HMODULE>(get_engine_memory_address(engine_type))); // 1.1270.0.0
		ps.add_instruction(new _push("x", 0x40, 0x57));																	//.text:0000000180011870	push		rdi
		ps.add_instruction(new _sub("x", 0x48, 0x83, 0xEC, 0x30));														//.text:0000000180011872	sub			rsp, 30h
		ps.add_instruction(new _mov("x", 0x48, 0xC7, 0x44, 0x24, 0x20, 0xFE, 0xFF, 0xFF, 0xFF));							//.text:0000000180011876	mov			[rsp+38h+var_18], 0FFFFFFFFFFFFFFFEh
		ps.add_instruction(new _mov("x", 0x48, 0x89, 0x5C, 0x24, 0x40));													//.text:000000018001187F	mov			[rsp+38h+arg_0], rbx
		ps.add_instruction(new _mov("x", 0x48, 0x89, 0x74, 0x24, 0x48));													//.text:0000000180011884	mov			[rsp+38h+arg_8], rsi
		ps.add_instruction(new _cmp("x", 0x80, 0x3D, 0x3C, 0x6A, 0xBF, 0x00, 0x00));										//.text:0000000180011889	cmp			cs:byte_180C082CC, 0
		ps.add_instruction(new _jz("x", e_jump_distance::Short, 0x74, 0x1D));												//.text:0000000180011890	jz			short loc_1800118AF
		ps.add_instruction(new _call("x", 0xE8, 0x49, 0x3A, 0x00, 0x00));												//.text:0000000180011892	call		sub_1800152E0
		ps.add_instruction(new _mov("x", 0x89, 0x05, 0x3B, 0x6A, 0xBF, 0x00));											//.text:0000000180011897	mov			cs:dword_180C082D8, eax
		ps.add_instruction(new _call("x", 0xE8, 0x3E, 0x3A, 0x00, 0x00));												//.text:000000018001189D	call		sub_1800152E0
		ps.add_instruction(new _mov("x", 0x89, 0x05, 0x2C, 0x6A, 0xBF, 0x00, 0xC6));										//.text:00000001800118A2	mov			cs:dword_180C082D4, eax
		ps.add_instruction(new _mov("x", 0x05, 0x1D, 0x6A, 0xBF, 0x00, 0x00));											//.text:00000001800118A8	mov			cs:byte_180C082CC, 0
		ps.add_instruction(new _mov("x", 0xBE, 0x01, 0x00, 0x00, 0x00));													//.text:00000001800118AF	mov			esi, 1
		ps.add_instruction(new _mov("x", 0x8B, 0x05, 0x3A, 0x7C, 0xD3, 0x00));											//.text:00000001800118B4	mov			eax, cs:dword_180D494F4
		ps.add_instruction(new _cmp("x", 0x83, 0xF8, 0x0C));																//.text:00000001800118BA	cmp			eax, 0Ch
		ps.add_instruction(new _jz("x", e_jump_distance::Long, 0x0F, 0x84, 0x18, 0x01, 0x00, 0x00));						//.text:00000001800118BD	jz			loc_1800119DB									
		ps.add_instruction(new _call("x", 0xE8, 0x18, 0x3A, 0x00, 0x00));												//.text:00000001800118C3	call		sub_1800152E0
		ps.add_instruction(new _sub("x", 0x2B, 0x05, 0x0A, 0x6A, 0xBF, 0x00));											//.text:00000001800118C8	sub			eax, cs:dword_180C082D8
		ps.add_instruction(new _or("x", 0x83, 0xCF, 0xFF));																//.text:00000001800118CE	or			edi, 0FFFFFFFFh
		ps.add_instruction(new _cmp("x", 0x3D, 0x90, 0x5F, 0x01, 0x00));													//.text:00000001800118D1	cmp			eax, 15F90h
		ps.add_instruction(new _jbe("x", e_jump_distance::Short, 0x76, 0x6F));												//.text:00000001800118D6	jbe			short loc_180011947
		ps.add_instruction(new _cmp("x", 0x83, 0x3D, 0x11, 0x7C, 0xD3, 0x00, 0x00));										//.text:00000001800118D8	cmp			cs:dword_180D494F0, 0
		ps.add_instruction(new _jnz("x", e_jump_distance::Short, 0x75, 0x18));												//.text:00000001800118DF	jnz			short loc_1800118F9
		ps.add_instruction(new _mov("x", 0xC7, 0x05, 0x05, 0x7C, 0xD3, 0x00, 0x04, 0x00, 0x00, 0x00));					//.text:00000001800118E1	mov			cs:dword_180D494F0, 4
		ps.add_instruction(new _lea("x", 0x48, 0x8D, 0x05, 0xFE, 0x98, 0xA3, 0x00));										//.text:00000001800118EB	lea			rax, aExternalLaunch ; "external_launch_overall_timeout"
		ps.add_instruction(new _mov("x", 0x48, 0x89, 0x05, 0xEF, 0x7B, 0xD3, 0x00));										//.text:00000001800118F2	mov			cs:qword_180D494E8, rax

		DWORD patternOffset = ps.find_pattern(0);
		if (patternOffset)
		{
			c_console::write_line_verbose("ketchup> SUCCEED: haloreach_main_game_launch_offset @0x%x", patternOffset);
			return get_engine_base_address(engine_type) + patternOffset;
		}
		else
		{
			c_console::write_line_verbose("ketchup> FAILURE: haloreach_main_game_launch_offset");
		}
	}
	return ~uintptr_t();
}
c_function_hook_ex<haloreach_main_game_launch_offset, char __fastcall (__int64 a1, __int64 a2)> haloreach_main_game_launch = { "haloreach_main_game_launch", [](__int64 a1, __int64 a2)
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
		"",
		"start_game",
		"finished"
	};

	ASSERT(is_valid(haloreach_main_game_launch));
	if (is_valid(haloreach_external_launch_individual_state))
	{
		static long external_launch_individual_state_prev = -1l;
		if (haloreach_external_launch_individual_state != external_launch_individual_state_prev)
		{
			external_launch_individual_state_prev = haloreach_external_launch_individual_state;
			printf("haloreach_external_launch_individual_state changed to: %s\n", external_launch_individual_state_names[haloreach_external_launch_individual_state]);
		}

		char result = haloreach_main_game_launch(a1, a2);

		if (haloreach_external_launch_individual_state != external_launch_individual_state_prev)
		{
			external_launch_individual_state_prev = haloreach_external_launch_individual_state;
			printf("haloreach_external_launch_individual_state changed to: %s\n", external_launch_individual_state_names[haloreach_external_launch_individual_state]);
		}

		return result;
	}
	else
	{
		char result = haloreach_main_game_launch(a1, a2);
		return result;
	}

} };
#pragma endregion