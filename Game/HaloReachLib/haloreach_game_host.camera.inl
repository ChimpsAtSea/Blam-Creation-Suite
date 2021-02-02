
uintptr_t haloreach_player_mapping_get_local_player_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_824_0_0, 0x1805C10B0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_887_0_0, 0x180366030);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1035_0_0, 0x180190190);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1186_0_0, 0x180072F20);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1211_0_0, 0x180073460);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1246_0_0, 0x18006FDF0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1270_0_0, 0x18006FDF0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1305_0_0, 0x18006FE30);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1350_0_0, 0x1800711A0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x180071180);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1377_0_0, 0x180071180);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1384_0_0, 0x180071180);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1387_0_0, 0x180071180);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x180071180);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1520_0_0, 0x1800712E0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1570_0_0, 0x1800712E0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1619_0_0, 0x1800712E0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1698_0_0, 0x180071C90);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1716_0_0, 0x180071C90);
	// not available for builds 1767-1871
	OFFSET(_engine_type_haloreach, _build_mcc_1_1930_0_0, 0x180059A74);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x180059A24);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2028_0_0, 0x180059A24);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2094_0_0, 0x180059A24);

	if (engine_type == _engine_type_haloreach && false)
	{
		using namespace ketchup;
		c_pattern_scanner ps = c_pattern_scanner(GetCurrentProcess(), static_cast<HMODULE>(get_engine_memory_address(engine_type))); // 1.1350.0.0

		// .text:000000018006FE30                               sub_18006FE30   proc near               ; CODE XREF: sub_1800335E0+52↑p
		// .text:000000018006FE30                                                                       ; sub_1800335E0+133↑p ...
		// .text:000000018006FE30 8B 0D 62 7B C4 00                             mov     ecx, cs:TlsIndex
		// .text:000000018006FE36 45 33 C9                                      xor     r9d, r9d
		// .text:000000018006FE39 65 48 8B 04 25 58 00 00 00                    mov     rax, gs:58h
		// .text:000000018006FE42 41 8B D1                                      mov     edx, r9d
		// .text:000000018006FE45 41 BA 68 01 00 00                             mov     r10d, 168h
		// .text:000000018006FE4B 48 8B 04 C8                                   mov     rax, [rax+rcx*8]
		// .text:000000018006FE4F 4D 8B 14 02                                   mov     r10, [r10+rax]
		// .text:000000018006FE53
		// .text:000000018006FE53                               loc_18006FE53:                          ; CODE XREF: sub_18006FE30+50↓j
		// .text:000000018006FE53 41 83 BC 92 B8 00 00 00 FF                    cmp     dword ptr [r10+rdx*4+0B8h], 0FFFFFFFFh
		// .text:000000018006FE5C 75 27                                         jnz     short loc_18006FE85
		// .text:000000018006FE5E 41 83 C8 FF                                   or      r8d, 0FFFFFFFFh
		// .text:000000018006FE62 48 83 C9 FF                                   or      rcx, 0FFFFFFFFFFFFFFFFh
		// .text:000000018006FE66 41 FF C1                                      inc     r9d
		// .text:000000018006FE69 41 83 F9 03                                   cmp     r9d, 3
		// .text:000000018006FE6D 77 07                                         ja      short loc_18006FE76
		// .text:000000018006FE6F 45 8B C1                                      mov     r8d, r9d
		// .text:000000018006FE72 48 8D 4A 01                                   lea     rcx, [rdx+1]
		// .text:000000018006FE76
		// .text:000000018006FE76                               loc_18006FE76:                          ; CODE XREF: sub_18006FE30+3D↑j
		// .text:000000018006FE76 45 8B C8                                      mov     r9d, r8d
		// .text:000000018006FE79 48 8B D1                                      mov     rdx, rcx
		// .text:000000018006FE7C 48 83 F9 FF                                   cmp     rcx, 0FFFFFFFFFFFFFFFFh
		// .text:000000018006FE80 75 D1                                         jnz     short loc_18006FE53
		// .text:000000018006FE82 0B C1                                         or      eax, ecx
		// .text:000000018006FE84 C3                                            retn
		// .text:000000018006FE85                               ; ---------------------------------------------------------------------------
		// .text:000000018006FE85
		// .text:000000018006FE85                               loc_18006FE85:                          ; CODE XREF: sub_18006FE30+2C↑j
		// .text:000000018006FE85 41 8B C1                                      mov     eax, r9d
		// .text:000000018006FE88 C3                                            retn
		// .text:000000018006FE88                               sub_18006FE30   endp

		ps.add_instruction(new _mov("x", 0x8B, 0x0D, 0x62, 0x7B, 0xC4, 0x00));
		ps.add_instruction(new _xor("x", 0x45, 0x33, 0xC9));
		ps.add_instruction(new _mov("x", 0x65, 0x48, 0x8B, 0x04, 0x25, 0x58, 0x00, 0x00, 0x00));
		ps.add_instruction(new _mov("x", 0x41, 0x8B, 0xD1));
		ps.add_instruction(new _mov("x", 0x41, 0xBA, 0x68, 0x01, 0x00, 0x00));
		ps.add_instruction(new _mov("x", 0x48, 0x8B, 0x04, 0xC8));
		ps.add_instruction(new _mov("x", 0x4D, 0x8B, 0x14, 0x02));


		ps.add_instruction(new _cmp("x", 0x41, 0x83, 0xBC, 0x92, 0xB8, 0x00, 0x00, 0x00, 0xFF));
		ps.add_instruction(new _jnz("x", e_jump_distance::Short, 0x75, 0x27));
		ps.add_instruction(new _or("x", 0x41, 0x83, 0xC8, 0xFF));
		ps.add_instruction(new _or("x", 0x48, 0x83, 0xC9, 0xFF));
		ps.add_instruction(new _inc("x", 0x41, 0xFF, 0xC1));
		ps.add_instruction(new _cmp("x", 0x41, 0x83, 0xF9, 0x03));
		ps.add_instruction(new _ja("x", 0x77, 0x07));
		ps.add_instruction(new _mov("x", 0x45, 0x8B, 0xC1));
		ps.add_instruction(new _lea("x", 0x48, 0x8D, 0x4A, 0x01));


		ps.add_instruction(new _mov("x", 0x45, 0x8B, 0xC8));
		ps.add_instruction(new _mov("x", 0x48, 0x8B, 0xD1));
		ps.add_instruction(new _cmp("x", 0x48, 0x83, 0xF9, 0xFF));
		ps.add_instruction(new _jnz("x", e_jump_distance::Short, 0x75, 0xD1));
		ps.add_instruction(new _or("x", 0x0B, 0xC1));
		ps.add_instruction(new _retn("x", 0xC3));

		DWORD patternOffset = ps.find_pattern(0);
		if (patternOffset)
		{
			c_console::write_line_verbose("ketchup> SUCCEED: haloreach_player_mapping_get_local_player_offset @0x%x", patternOffset);
			return get_engine_base_address(engine_type) + patternOffset;
		}
		else
		{
			c_console::write_line_verbose("ketchup> FAILURE: haloreach_player_mapping_get_local_player_offset");
		}
	}
	return ~uintptr_t();
}
c_function_hook_ex<haloreach_player_mapping_get_local_player_offset, int __stdcall ()> haloreach_player_mapping_get_local_player;

uintptr_t haloreach_observer_try_and_get_camera_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_824_0_0, 0x180624D10);
	OFFSET(_engine_type_haloreach, _build_mcc_1_887_0_0, 0x1804DA0C0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1035_0_0, 0x18029B840);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1186_0_0, 0x1800E6110);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1211_0_0, 0x1800E66A0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1246_0_0, 0x1800E2FA0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1270_0_0, 0x1800E2FA0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1305_0_0, 0x1800E3050);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1350_0_0, 0x1800E4580);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x1800E4560);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1377_0_0, 0x1800E4560);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1384_0_0, 0x1800E4560);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1387_0_0, 0x1800E4560);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x1800E4560);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1520_0_0, 0x1800E46C0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1570_0_0, 0x1800E46C0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1619_0_0, 0x1800E46C0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1698_0_0, 0x1800E5FA0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1716_0_0, 0x1800E5FA0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1829_0_0, 0x1800EBB30);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1864_0_0, 0x1800EBB30);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1871_0_0, 0x1800EBB30);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1930_0_0, 0x1800B29E4);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x1800B2994);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2028_0_0, 0x1800B2994);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2094_0_0, 0x1800B2994);

	if (engine_type == _engine_type_haloreach && false)
	{
		using namespace ketchup;
		c_pattern_scanner ps = c_pattern_scanner(GetCurrentProcess(), static_cast<HMODULE>(get_engine_memory_address(engine_type))); // 1.1350.0.0

		// .text:00000001800E3050                               sub_1800E3050   proc near               ; CODE XREF: sub_1800DC8D0+1D4↑p
		// .text:00000001800E3050                                                                       ; sub_18016A970+D8↓p ...
		// .text:00000001800E3050 45 33 C0                                      xor     r8d, r8d
		// .text:00000001800E3053 83 F9 03                                      cmp     ecx, 3
		// .text:00000001800E3056 77 5A                                         ja      short loc_1800E30B2
		// .text:00000001800E3058 8B 15 3A 49 BD 00                             mov     edx, cs:TlsIndex
		// .text:00000001800E305E 65 48 8B 04 25 58 00 00 00                    mov     rax, gs:58h
		// .text:00000001800E3067 4C 8B 0C D0                                   mov     r9, [rax+rdx*8]
		// .text:00000001800E306B B8 68 01 00 00                                mov     eax, 168h
		// .text:00000001800E3070 48 63 D1                                      movsxd  rdx, ecx
		// .text:00000001800E3073 4A 8B 04 08                                   mov     rax, [rax+r9]
		// .text:00000001800E3077 83 BC 90 B8 00 00 00 FF                       cmp     dword ptr [rax+rdx*4+0B8h], 0FFFFFFFFh
		// .text:00000001800E307F 0F 95 C0                                      setnz   al
		// .text:00000001800E3082 84 C0                                         test    al, al
		// .text:00000001800E3084 74 2C                                         jz      short loc_1800E30B2
		// .text:00000001800E3086 44 39 05 E7 B8 79 03                          cmp     cs:dword_18387E974, r8d
		// .text:00000001800E308D 74 23                                         jz      short loc_1800E30B2
		// .text:00000001800E308F 48 69 C2 10 04 00 00                          imul    rax, rdx, 410h
		// .text:00000001800E3096 B9 80 06 00 00                                mov     ecx, 680h
		// .text:00000001800E309B 48 05 54 01 00 00                             add     rax, 154h
		// .text:00000001800E30A1 4A 8B 0C 09                                   mov     rcx, [rcx+r9]
		// .text:00000001800E30A5 48 03 C1                                      add     rax, rcx
		// .text:00000001800E30A8 74 08                                         jz      short loc_1800E30B2
		// .text:00000001800E30AA 80 78 0C FF                                   cmp     byte ptr [rax+0Ch], 0FFh
		// .text:00000001800E30AE 4C 0F 45 C0                                   cmovnz  r8, rax
		// .text:00000001800E30B2
		// .text:00000001800E30B2                               loc_1800E30B2:                          ; CODE XREF: sub_1800E3050+6↑j
		// .text:00000001800E30B2                                                                       ; sub_1800E3050+34↑j ...
		// .text:00000001800E30B2 49 8B C0                                      mov     rax, r8
		// .text:00000001800E30B5 C3                                            retn
		// .text:00000001800E30B5                               sub_1800E3050   endp

		ps.add_instruction(new _xor("x", 0x45, 0x33, 0xC0));
		ps.add_instruction(new _cmp("x", 0x83, 0xF9, 0x03));
		ps.add_instruction(new _ja("x", 0x77, 0x5A));
		ps.add_instruction(new _mov("x", 0x8B, 0x15, 0x3A, 0x49, 0xBD, 0x00));
		ps.add_instruction(new _mov("x", 0x65, 0x48, 0x8B, 0x04, 0x25, 0x58, 0x00, 0x00, 0x00));
		ps.add_instruction(new _mov("x", 0x4C, 0x8B, 0x0C, 0xD0));
		ps.add_instruction(new _mov("x", 0xB8, 0x68, 0x01, 0x00, 0x00));
		ps.add_instruction(new _movsxd("x", 0x48, 0x63, 0xD1));
		ps.add_instruction(new _mov("x", 0x4A, 0x8B, 0x04, 0x08));
		ps.add_instruction(new _cmp("x", 0x83, 0xBC, 0x90, 0xB8, 0x00, 0x00, 0x00, 0xFF));
		ps.add_instruction(new _setnz("x", 0x0F, 0x95, 0xC0));
		ps.add_instruction(new _test("x", 0x84, 0xC0));
		ps.add_instruction(new _jz("x", e_jump_distance::Short, 0x74, 0x2C));
		ps.add_instruction(new _cmp("x", 0x44, 0x39, 0x05, 0xE7, 0xB8, 0x79, 0x03));
		ps.add_instruction(new _jz("x", e_jump_distance::Short, 0x74, 0x23));
		ps.add_instruction(new _imul("x", 0x48, 0x69, 0xC2, 0x10, 0x04, 0x00, 0x00));
		ps.add_instruction(new _mov("x", 0xB9, 0x80, 0x06, 0x00, 0x00));
		ps.add_instruction(new _add("x", 0x48, 0x05, 0x54, 0x01, 0x00, 0x00));
		ps.add_instruction(new _mov("x", 0x4A, 0x8B, 0x0C, 0x09));
		ps.add_instruction(new _add("x", 0x48, 0x03, 0xC1));
		ps.add_instruction(new _jz("x", e_jump_distance::Short, 0x74, 0x08));
		ps.add_instruction(new _cmp("x", 0x80, 0x78, 0x0C, 0xFF));
		ps.add_instruction(new _cmovnz("x", 0x4C, 0x0F, 0x45, 0xC0));
		ps.add_instruction(new _mov("x", 0x49, 0x8B, 0xC0));
		ps.add_instruction(new _retn("x", 0xC3));

		DWORD patternOffset = ps.find_pattern(0);
		if (patternOffset)
		{
			c_console::write_line_verbose("ketchup> SUCCEED: haloreach_observer_try_and_get_camera_offset @0x%x", patternOffset);
			return get_engine_base_address(engine_type) + patternOffset;
		}
		else
		{
			c_console::write_line_verbose("ketchup> FAILURE: haloreach_observer_try_and_get_camera_offset");
		}
	}
	return ~uintptr_t();
}
c_function_hook_ex<haloreach_observer_try_and_get_camera_offset, s_observer_camera * __fastcall (signed int a1)> haloreach_observer_try_and_get_camera;

std::vector<uintptr_t> haloreach_enable_debug_hud_coordinates_offsets(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1305_0_0, 0x1800DCA8A, 0x1800DCA97);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x1800DDF7A, 0x1800DDF87);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1377_0_0, 0x1800DDF7A, 0x1800DDF87);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1384_0_0, 0x1800DDF7A, 0x1800DDF87);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1387_0_0, 0x1800DDF7A, 0x1800DDF87);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x1800DDF7A, 0x1800DDF87);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1520_0_0, 0x1800DE0DA, 0x1800DE0E7);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1570_0_0, 0x1800DE0DA, 0x1800DE0E7);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1619_0_0, 0x1800DE0DA, 0x1800DE0E7);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1698_0_0, 0x1800DF9EA, 0x1800DF9F7);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1716_0_0, 0x1800DF9EA, 0x1800DF9F7);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1829_0_0, 0x1800E516B, 0x1800E5178);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1864_0_0, 0x1800E516B, 0x1800E5178);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1871_0_0, 0x1800E516B, 0x1800E5178);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1930_0_0, 0x1800AED58, 0x1800AED65);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x1800AED08, 0x1800AED15);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2028_0_0, 0x1800AED08, 0x1800AED15);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2094_0_0, 0x1800AED08, 0x1800AED15);
	return {};
}
// Enable debug hud coordinates
c_multi_data_patch<haloreach_enable_debug_hud_coordinates_offsets> haloreach_enable_debug_hud_coordinates = {
	[](e_engine_type engine_type, e_build build, char *data[], DataPatchPackets &packets)
	{
		packets.push_back(MAKE_DATAPATCHPACKET(data[0], 6));
		nop_address(data[0], 6);

		packets.push_back(MAKE_DATAPATCHPACKET(data[1], 6));
		nop_address(data[1], 6);
	}
};