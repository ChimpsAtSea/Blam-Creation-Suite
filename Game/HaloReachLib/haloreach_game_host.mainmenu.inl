
#pragma region MCC Parse Hooks
uintptr_t mcc_map_id_parse_to_reach_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x18004CD50);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1930_0_0, 0x18003E3E0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x18003E390);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2028_0_0, 0x18003E390);

	if (engine_type == _engine_type_haloreach)
	{
		using namespace ketchup;
		c_pattern_scanner ps = c_pattern_scanner(GetCurrentProcess(), static_cast<HMODULE>(get_engine_memory_address(engine_type)));			// 1.1270.0.0
		ps.add_instruction(new _or("x", 0x83, 0xCA, 0xFF));																		//.text:000000018004BF10 83 CA FF                    or      edx, 0FFFFFFFFh
		ps.add_instruction(new _add("x", 0x81, 0xC1, 0x4E, 0xFF, 0xF, 0xFF));													//.text:000000018004BF13 81 C1 4E FF+                add     ecx, 0FFFFFF4Eh ; switch 42 cases
		ps.add_instruction(new _cmp("x", 0x83, 0xF9, 0x29));																		//.text:000000018004BF19 83 F9 29                    cmp     ecx, 29h
		ps.add_instruction(new _ja("x", 0x0F, 0x87, 0x64, 0x01, 0x00, 0x00));													//.text:000000018004BF1C 0F 87 64 01+                ja      def_18004BF37   ; jumptable 00007FFC6804BF37 default case
		ps.add_instruction(new _movsxd("x", 0x48, 0x63, 0xC1));																	//.text:000000018004BF22 48 63 C1                    movsxd  rax, ecx
		ps.add_instruction(new _lea("x", 0x4C, 0x8D, 0x05, 0xD4, 0x40, 0xFB, 0xFF));												//.text:000000018004BF25 4C 8D 05 D4+                lea     r8, __ImageBase
		ps.add_instruction(new _mov("x", 0x41, 0x8B, 0x8C, 0x80, 0x8C, 0xC0, 0x04, 0x00));										//.text:000000018004BF2C 41 8B 8C 80+                mov     ecx, [r8+rax*4+4C08Ch]
		ps.add_instruction(new _add("x", 0x49, 0x03, 0xC8));																		//.text:000000018004BF34 49 03 C8                    add     rcx, r8
		ps.add_instruction(new _jmp("x", 0xFF, 0xE1));																			//.text:000000018004BF37 FF E1                       jmp     rcx             ; switch jump
																																//.text:000000018004BF39             ; ---------------------------------------------------------------------------
																																//.text:000000018004BF39
																																//.text:000000018004BF39             loc_18004BF39:                          ; CODE XREF: convert_map_id_from_mcc+27↑j
																																//.text:000000018004BF39                                                     ; DATA XREF: .text:jpt_18004BF37↓o
		ps.add_instruction(new _mov("x", 0xFBA, 0x8D, 0x13, 0x00, 0x00));														//.text:000000018004BF39 BA 8D 13 00+                mov     edx, 138Dh      ; jumptable 00007FFC6804BF37 case 178
		ps.add_instruction(new _mov("x", 0xF8B, 0xC2));																			//.text:000000018004BF3E 8B C2                       mov     eax, edx
		ps.add_instruction(new _retn("x", 0xFC3));																				//.text:000000018004BF40 C3                          retn
																																//.text:000000018004BF41             ; ---------------------------------------------------------------------------
																																//.text:000000018004BF41
																																//.text:000000018004BF41             loc_18004BF41:                          ; CODE XREF: convert_map_id_from_mcc+27↑j
																																//.text:000000018004BF41                                                     ; DATA XREF: .text:jpt_18004BF37↓o
		ps.add_instruction(new _mov("x", 0xFBA, 0x92, 0x13, 0x00, 0x00));														//.text:000000018004BF41 BA 92 13 00+                mov     edx, 1392h      ; jumptable 00007FFC6804BF37 case 179
		ps.add_instruction(new _mov("x", 0xF8B, 0xC2));																			//.text:000000018004BF46 8B C2                       mov     eax, edx
		ps.add_instruction(new _retn("x", 0xFC3));																				//.text:000000018004BF48 C3                          retn

		DWORD patternOffset = ps.find_pattern(0);
		if (patternOffset)
		{
			c_console::write_line_verbose("ketchup> SUCCEED: mcc_map_id_parse_to_reach_offset @0x%x", patternOffset);
			return get_engine_base_address(engine_type) + patternOffset;
		}
		else
		{
			c_console::write_line_verbose("ketchup> FAILURE: mcc_map_id_parse_to_reach_offset");
			return ~uintptr_t();
		}
	}
	return ~uintptr_t();
}
c_function_hook_ex<mcc_map_id_parse_to_reach_offset, long __fastcall (long map_id)> mcc_map_id_parse_to_reach = { "mcc_map_id_parse_to_reach", [](long map_id)
{
	long result = mcc_map_id_parse_to_reach(map_id);
	return result == -1l ? map_id : result;
} };

uintptr_t mcc_map_id_parse_from_reach_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x18004CF80);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1930_0_0, 0x18003E6A0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x18003E650);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2028_0_0, 0x18003E650);

	if (engine_type == _engine_type_haloreach)
	{
		using namespace ketchup;
		c_pattern_scanner ps = c_pattern_scanner(GetCurrentProcess(), static_cast<HMODULE>(get_engine_memory_address(engine_type)));			// 1.1270.0.0
		ps.add_instruction(new _or("x", 0x83, 0xCA, 0xFF));																		// .text:000000018004C140 83 CA FF                    or      edx, 0FFFFFFFFh
		ps.add_instruction(new _cmp("x", 0x81, 0xF9, 0x8D, 0x13, 0x00, 0x00));													// .text:000000018004C143 81 F9 8D 13+                cmp     ecx, 138Dh
		ps.add_instruction(new _ja("x", 0x0F, 0x87, 0xEE, 0x00, 0x00, 0x00));													// .text:000000018004C149 0F 87 EE 00+                ja      loc_18004C23D
		ps.add_instruction(new _jz("x", e_jump_distance::Long, 0x0F, 0x84, 0xE0, 0x00, 0x00, 0x00));								// .text:000000018004C14F 0F 84 E0 00+                jz      loc_18004C235
		ps.add_instruction(new _cmp("x", 0x81, 0xF9, 0xB0, 0x04, 0x00, 0x00));													// .text:000000018004C155 81 F9 B0 04+                cmp     ecx, 4B0h
		ps.add_instruction(new _ja("x", 0x77, 0x71));																			// .text:000000018004C15B 77 71                       ja      short loc_18004C1CE
		ps.add_instruction(new _jz("x", e_jump_distance::Short, 0x74, 0x67));														// .text:000000018004C15D 74 67                       jz      short loc_18004C1C6
		ps.add_instruction(new _add("x", 0x81, 0xC1, 0x18, 0xFC, 0xFF, 0xFF));													// .text:000000018004C15F 81 C1 18 FC+                add     ecx, 0FFFFFC18h ; switch 151 cases
		ps.add_instruction(new _cmp("x", 0x81, 0xF9, 0x96, 0x00, 0x00, 0x00));													// .text:000000018004C165 81 F9 96 00+                cmp     ecx, 96h
		ps.add_instruction(new _ja("x", 0x0F, 0x87, 0x3D, 0x02, 0x00, 0x00));													// .text:000000018004C16B 0F 87 3D 02+                ja      def_18004C18C   ; jumptable 00007FFC6804C18C default case, cases 1001-1019,1021-1034,1036-1039,1041-1054,1056-1079,1081-1149
																																// .text:000000018004C16B 00 00                                               ; jumptable 00007FFC6804C279 default case, cases 5011-5019,5021-5029,5031-5034,5036-5044,5046-5049,5051,5053-5059,5061-5069,5071-5074,5076-5079
																																// .text:000000018004C16B                                                     ; jumptable 00007FFC6804C30F default case, cases 7021-7029,7031-7039,7041-7059,7061-7079,7081-7109,7111-7129
																																// .text:000000018004C16B                                                     ; jumptable 00007FFC6804C377 default case, cases 10011-10019,10021-10029,10031-10049,10051-10059,10061-10069,10071-10079
		ps.add_instruction(new _lea("x", 0x4C, 0x8D, 0x05, 0x88, 0x3E, 0xFB, 0xFF));												// .text:000000018004C171 4C 8D 05 88+                lea     r8, __ImageBase
		ps.add_instruction(new _movzx("x", 0x41, 0x0F, 0xB6, 0x84, 0x08, 0xD4, 0xC3, 0x04, 0x00));								// .text:000000018004C178 41 0F B6 84+                movzx   eax, byte ptr [r8+rcx+4C3D4h]
		ps.add_instruction(new _mov("x", 0x41, 0x8B, 0x8C, 0x80, 0xB4, 0xC3, 0x04, 0x00));										// .text:000000018004C181 41 8B 8C 80+                mov     ecx, [r8+rax*4+4C3B4h]
		ps.add_instruction(new _add("x", 0x49, 0x03, 0xC8));																		// .text:000000018004C189 49 03 C8                    add     rcx, r8
		ps.add_instruction(new _jmp("x", 0xFF, 0xE1));																			// .text:000000018004C18C FF E1                       jmp     rcx             ; switch jump
																																// .text:000000018004C18E             ; ---------------------------------------------------------------------------
																																// .text:000000018004C18E
																																// .text:000000018004C18E             loc_18004C18E:                          ; CODE XREF: convert_map_id_to_mcc+4C↑j
																																// .text:000000018004C18E                                                     ; DATA XREF: .text:jpt_18004C18C↓o
		ps.add_instruction(new _mov("x", 0xBA, 0xBE, 0x00, 0x00, 0x00));															// .text:000000018004C18E BA BE 00 00+                mov     edx, 0BEh ; '¾' ; jumptable 00007FFC6804C18C case 1035
		ps.add_instruction(new _mov("x", 0x8B, 0xC2));																			// .text:000000018004C193 8B C2                       mov     eax, edx
		ps.add_instruction(new _retn("x", 0xC3));																				// .text:000000018004C195 C3                          retn

		DWORD patternOffset = ps.find_pattern(0);
		if (patternOffset)
		{
			c_console::write_line_verbose("ketchup> SUCCEED: mcc_map_id_parse_from_reach_offset @0x%x", patternOffset);
			return get_engine_base_address(engine_type) + patternOffset;
		}
		else
		{
			c_console::write_line_verbose("ketchup> FAILURE: mcc_map_id_parse_from_reach_offset");
			return ~uintptr_t();
		}
	}
	return ~uintptr_t();
}
c_function_hook_ex<mcc_map_id_parse_from_reach_offset, long __fastcall (long map_id)> mcc_map_id_parse_from_reach = { "mcc_map_id_parse_from_reach", [](long map_id)
{
	long result = mcc_map_id_parse_from_reach(map_id);
	return result == -1l ? map_id : result;
} };
#pragma endregion