
// Custom Stuff
WORD g_frameLimit = 60;
int g_controlsLayout = 0;
int g_useController = 0;
bool g_pancamEnabled = false;
bool g_keyboardPrintKeyState = false;

void _simple_pattern_match_readonly_data_copy(
	void* pEngineAddress,
	SIZE_T& rSizeOfImage,
	void*& rpModuleData)
{
	HANDLE hProcess = GetCurrentProcess();

	{
		MODULEINFO moduleInfo = {};
		BOOL getModuleInformationResult = GetModuleInformation(
			hProcess,
			static_cast<HMODULE>(pEngineAddress),
			&moduleInfo,
			sizeof(moduleInfo)
		);
		ASSERT(getModuleInformationResult == TRUE);

		rSizeOfImage = static_cast<SIZE_T>(moduleInfo.SizeOfImage);
	}

	static std::map<void*, void*> moduleMaps;
	std::map<void*, void*>::iterator existingModuleDataCopy = moduleMaps.find(pEngineAddress);

	if (existingModuleDataCopy == moduleMaps.end())
	{
		rpModuleData = new char[rSizeOfImage];
		ASSERT(rpModuleData != nullptr);

		SIZE_T numBytes = 0;
		ReadProcessMemory(
			hProcess,
			static_cast<HMODULE>(pEngineAddress),
			rpModuleData,
			rSizeOfImage,
			&numBytes
		);
		ASSERT(numBytes > 0);

		moduleMaps[pEngineAddress] = rpModuleData;
	}
	else
	{
		rpModuleData = existingModuleDataCopy->second;
		ASSERT(rpModuleData);
	}
}

uintptr_t simple_pattern_match(e_engine_type engine_type, e_build build, const char pInputData[], size_t inputDataLength, const char* pInputMask)
{
	void* pEngineAddress = get_engine_memory_address(engine_type);
	SIZE_T sizeOfImage = 0;
	void* pModuleData = nullptr;
	_simple_pattern_match_readonly_data_copy(pEngineAddress, sizeOfImage, pModuleData);

	if (pInputMask)
	{
		size_t inputMaskLength = strlen(pInputMask);
		ASSERT(inputMaskLength == inputDataLength);
	}

	const char* pStartSearchAddress = reinterpret_cast<char*>(pModuleData);
	uintptr_t result = 0;

	if (pInputMask)
	{
		for (uintptr_t imageOffset = 0; imageOffset < sizeOfImage; imageOffset++)
		{
			const char* pCurrentSearchPointer = pStartSearchAddress + imageOffset;

			for (size_t currentPatternIndex = 0; currentPatternIndex < inputDataLength; currentPatternIndex++)
			{
				if (pInputMask[imageOffset] == '?')
				{
					continue;
				}

				if (pCurrentSearchPointer[currentPatternIndex] != pInputData[currentPatternIndex])
				{
					goto search_fail_im;
				}
			}

			return get_engine_base_address(engine_type) + static_cast<intptr_t>(imageOffset);
		search_fail_im:
			continue;
		}
	}
	else
	{
		for (uintptr_t imageOffset = 0; imageOffset < sizeOfImage; imageOffset++)
		{
			const char* pCurrentSearchPointer = pStartSearchAddress + imageOffset;

			if (memcmp(pCurrentSearchPointer, pInputData, inputDataLength) == 0)
			{
				return get_engine_base_address(engine_type) + static_cast<intptr_t>(imageOffset);
			}

			//	for (size_t currentPatternIndex = 0; currentPatternIndex < inputDataLength; currentPatternIndex++)
			//	{
			//		if (pCurrentSearchPointer[currentPatternIndex] != pInputData[currentPatternIndex])
			//		{
			//			goto search_fail;
			//		}
			//	}

			//	return GetBuildBaseAddress(build) + imageOffset;
			//search_fail:
			//	continue;
		}
	}

	return 0;
}

uintptr_t string_search(e_engine_type engine_type, e_build build, const char* pString)
{
	uintptr_t imageAddress = simple_pattern_match(engine_type, build, pString, strlen(pString) + 1, nullptr);
	return imageAddress;
}

const char* string_search_ptr(e_engine_type engine_type, e_build build, const char* pString)
{
	uintptr_t imageAddress = string_search(engine_type, build, pString);
	if (imageAddress)
	{
		const char* pStringAddress = reinterpret_cast<const char*>(get_engine_memory_address(engine_type)) + (imageAddress - get_engine_base_address(engine_type));
		return pStringAddress;
	}
	return nullptr;
}

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
FunctionHookEx<haloreach_main_game_launch_offset, char __fastcall (__int64 a1, __int64 a2)> haloreach_main_game_launch = { "haloreach_main_game_launch", [](__int64 a1, __int64 a2)
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
		static int external_launch_individual_state_prev = k_load_state_invalid;
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


uintptr_t mcc_map_id_parse_to_reach_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x18004CD50);
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
FunctionHookEx<mcc_map_id_parse_to_reach_offset, int __fastcall (int a1)> mcc_map_id_parse_to_reach = { "mcc_map_id_parse_to_reach", [](int a1)
{
	int result = mcc_map_id_parse_to_reach(a1);
	if (result == -1)
	{
		return a1; // return the raw map id on conversion failure
	}
	else
	{
		return result;
	}
} };

uintptr_t mcc_map_id_parse_from_reach_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x18004CF80);
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
FunctionHookEx<mcc_map_id_parse_from_reach_offset, int __fastcall (int a1)> mcc_map_id_parse_from_reach = { "mcc_map_id_parse_from_reach", [](int a1)
{
	int result = mcc_map_id_parse_from_reach(a1);
	if (result == -1)
	{
		return a1; // return the raw map id on conversion failure
	}
	else
	{
		return result;
	}
} };


void ReadConfig()
{
	g_frameLimit = __max(30, c_settings_legacy::read_integer(_settings_section_legacy_game, "FrameLimit", c_render::s_deviceMode.dmDisplayFrequency));
	g_controlsLayout = c_settings_legacy::read_integer(_settings_section_legacy_player, "ControlsLayout", 0);
	g_pancamEnabled = c_settings_legacy::read_boolean(_settings_section_legacy_debug, "PancamEnabled", false);
	g_keyboardPrintKeyState = c_settings_legacy::read_boolean(_settings_section_legacy_debug, "PrintKeyState", 0);
	g_useController = c_settings_legacy::read_integer(_settings_section_legacy_player, "UseController", 0);
	//ReadInputBindings();
}

void haloreach_debug_callback()
{
	ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(1876, 1024), ImGuiCond_FirstUseEver);

	// Main body of the Demo window starts here.
	static bool isReachDebugWindowOpen = true;
	if (!ImGui::Begin("Halo Reach Debug", &isReachDebugWindowOpen, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	//ImGui::Columns(5, "g_pNetworkSessions", false);
	//ImGui::Separator();
	//ImGui::Selectable("Session Name");
	//ImGui::NextColumn();
	//ImGui::Selectable("Address");
	//ImGui::NextColumn();
	//ImGui::Selectable("State");
	//ImGui::NextColumn();
	//ImGui::Selectable("PeerCount");
	//ImGui::NextColumn();
	//ImGui::Selectable("PlayerCount");
	//ImGui::NextColumn();
	//for (int i = 0; i < 4; i++)
	//{
	//	auto& prNetworkSession = g_pNetworkSessions[i];
	//	auto pNetworkSessionName = ppNetworkSessionNames[i];
	//	const char* local_state_str = network_session_state_to_string(prNetworkSession->m_local_state);

	//	ImGui::Text(pNetworkSessionName);
	//	ImGui::NextColumn();
	//	ImGui::Text("0x%p", &prNetworkSession);
	//	ImGui::NextColumn();
	//	ImGui::Text(local_state_str);
	//	ImGui::NextColumn();
	//	ImGui::Text("%i", prNetworkSession->m_session_membership.m_peer_count);
	//	ImGui::NextColumn();
	//	ImGui::Text("%i", prNetworkSession->m_session_membership.m_player_count);
	//	ImGui::NextColumn();
	//}
	//ImGui::Columns(1);
	//for (int i = 0; i < 4; i++)
	//{
	//	ImGui::PushID(i);
	//	auto& prNetworkSession = g_pNetworkSessions[i];
	//	auto pNetworkSessionName = ppNetworkSessionNames[i];

	//	bool header = ImGui::CollapsingHeader(pNetworkSessionName);

	//	// quick view
	//	{
	//		auto& rNetworkSession = g_pNetworkSessions[i];
	//		auto pNetworkSessionName = ppNetworkSessionNames[i];
	//		ImGui::Columns(8, pNetworkSessionName, false);
	//		ImGui::Separator();
	//		ImGui::Selectable("peer_index");
	//		ImGui::NextColumn();
	//		ImGui::Selectable("player_identifier");
	//		ImGui::NextColumn();
	//		ImGui::Text("desired_configuration_version");
	//		ImGui::NextColumn();
	//		ImGui::Selectable("player_name");
	//		ImGui::NextColumn();
	//		ImGui::Selectable("service_tag");
	//		ImGui::NextColumn();
	//		ImGui::Selectable("machine_id");
	//		ImGui::NextColumn();
	//		ImGui::Selectable("network_session_peer_state");
	//		ImGui::NextColumn();
	//		ImGui::Selectable("join_nonce");
	//		ImGui::NextColumn();

	//		auto& rSessionMembership = rNetworkSession->m_session_membership;
	//		auto& rPeers = rSessionMembership.m_peers;
	//		auto& rPlayers = rSessionMembership.m_players;

	//		for (int i = 0; i < __min(rSessionMembership.m_player_count, _countof(rPlayers)); i++)
	//		{
	//			ImGui::Text("%i", rPlayers[i].peer_index);
	//			ImGui::NextColumn();
	//			ImGui::Text("%llu", rPlayers[i].player_identifier);
	//			ImGui::NextColumn();
	//			ImGui::Text("%i", rPlayers[i].desired_configuration_version);
	//			ImGui::NextColumn();
	//			ImGui::Text("%S", rPlayers[i].player_name);
	//			ImGui::NextColumn();
	//			ImGui::Text("%S", rPlayers[i].service_tag);
	//			ImGui::NextColumn();
	//			ImGui::Text("0x%llX", rPeers[rPlayers[i].peer_index].machine_identifier);
	//			ImGui::NextColumn();
	//			if (rPeers[rPlayers[i].peer_index].network_session_peer_state < 8)
	//			{
	//				ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.2f, 0.2f, 1.0f));
	//			}
	//			ImGui::Text("%u", rPeers[rPlayers[i].peer_index].network_session_peer_state);
	//			if (rPeers[rPlayers[i].peer_index].network_session_peer_state < 8)
	//			{
	//				ImGui::PopStyleColor();
	//			}
	//			ImGui::NextColumn();
	//			ImGui::Text("%llx", rPeers[rPlayers[i].peer_index].join_nonce);
	//			ImGui::NextColumn();

	//		}

	//		ImGui::Columns(1);
	//		ImGui::Separator();
	//	}

	//	if (header)
	//	{
	//		ImGui::Dummy(ImVec2(10.0f, 0.0f));
	//		ImGui::SameLine();
	//		ImGui::BeginGroup();
	//		{
	//			ImGui::Text("m_message_gateway: %p", prNetworkSession->m_message_gateway);
	//			ImGui::Text("m_observer: %p", prNetworkSession->m_observer);
	//			ImGui::Text("m_session_manager: %p", prNetworkSession->m_session_manager);
	//			ImGui::Text("ppSession: %p", prNetworkSession->ppSession);
	//			ImGui::Text("m_session_index: %i", prNetworkSession->m_session_index);
	//			ImGui::Text("m_session_type: %i", prNetworkSession->m_session_type);
	//			ImGui::Text("m_session_class: %i", prNetworkSession->m_session_class);
	//			ImGui::Text("unknown2C: %i", prNetworkSession->unknown2C);

	//			if (ImGui::CollapsingHeader("m_session_membership"))
	//			{
	//				ImGui::Dummy(ImVec2(10.0f, 0.0f));
	//				ImGui::SameLine();
	//				ImGui::BeginGroup();
	//				{
	//					auto& rSessionMembership = prNetworkSession->m_session_membership;

	//					ImGui::Text("m_session: %p", rSessionMembership.m_session);
	//					ImGui::Text("m_baseline_update_number: %i", rSessionMembership.m_baseline_update_number);
	//					ImGui::Text("m_leader_peer_index: %i", rSessionMembership.m_leader_peer_index);
	//					ImGui::Text("m_host_peer_index: %i", rSessionMembership.m_host_peer_index);
	//					ImGui::Text("unknown14: %i", rSessionMembership.unknown14);
	//					ImGui::Text("m_private_slot_count: %i", rSessionMembership.m_private_slot_count);
	//					ImGui::Text("m_public_slot_count: %i", rSessionMembership.m_public_slot_count);
	//					ImGui::Text("m_friends_only: %lli", rSessionMembership.m_friends_only);
	//					ImGui::Text("m_peer_count: %i", rSessionMembership.m_peer_count);
	//					ImGui::Text("m_valid_peer_mask: %i", rSessionMembership.m_valid_peer_mask);

	//					if (ImGui::CollapsingHeader("m_peers"))
	//					{
	//						ImGui::Dummy(ImVec2(10.0f, 0.0f));
	//						ImGui::SameLine();
	//						ImGui::BeginGroup();
	//						{
	//							auto& rPeers = rSessionMembership.m_peers;
	//							for (int i = 0; i < __min(rSessionMembership.m_peer_count, _countof(rPeers)); i++)
	//							{
	//								ImGui::Text("machine_identifier: 0x%llX", rPeers[i].machine_identifier);
	//								ImGui::Text("dword8: %u", rPeers[i].network_session_peer_state);
	//								ImGui::Text("join_nonce: %u", rPeers[i].join_nonce);
	//								ImGui::Dummy(ImVec2(0.0f, 5.0f));
	//							}
	//						}
	//						ImGui::EndGroup();
	//					}

	//					ImGui::Text("m_player_count: %i", rSessionMembership.m_player_count);
	//					ImGui::Text("m_valid_player_mask: %i", rSessionMembership.m_valid_player_mask);

	//					if (ImGui::CollapsingHeader("m_players"))
	//					{
	//						ImGui::Dummy(ImVec2(10.0f, 0.0f));
	//						ImGui::SameLine();
	//						ImGui::BeginGroup();
	//						{
	//							auto& rPlayers = rSessionMembership.m_players;
	//							for (int i = 0; i < __min(rSessionMembership.m_player_count, _countof(rPlayers)); i++)
	//							{
	//								ImGui::Text("desired_configuration_version: %i", rPlayers[i].desired_configuration_version);
	//								ImGui::Text("player_identifier: %llu", rPlayers[i].player_identifier);
	//								ImGui::Text("peer_index: %i", rPlayers[i].peer_index);
	//								ImGui::Text("player_name: %S", rPlayers[i].player_name);
	//								ImGui::Text("service_tag: %S", rPlayers[i].service_tag);
	//								ImGui::Text("player_name2: %S", rPlayers[i].player_name2);
	//								ImGui::Dummy(ImVec2(0.0f, 5.0f));
	//							}
	//						}
	//						ImGui::EndGroup();
	//					}

	//					ImGui::Text("m_player_sequence_number: %i", rSessionMembership.m_player_sequence_number);
	//					ImGui::Text("unknown291C: %i", rSessionMembership.unknown291C);
	//					ImGui::Text("m_incremental_updates: %i", rSessionMembership.m_incremental_updates);
	//					ImGui::Text("unknown5240: %i", rSessionMembership.unknown5240);
	//					ImGui::Text("m_local_peer_index: %i", rSessionMembership.m_local_peer_index);
	//					ImGui::Text("m_player_configuration_version: %u", rSessionMembership.m_player_configuration_version);
	//				}
	//				ImGui::EndGroup();
	//			}
	//			if (ImGui::CollapsingHeader("m_session_parameters"))
	//			{
	//				ImGui::Dummy(ImVec2(10.0f, 0.0f));
	//				ImGui::SameLine();
	//				ImGui::BeginGroup();
	//				{
	//					auto& rSessionParameters = prNetworkSession->m_session_parameters;

	//					ImGui::Text("session_size.max_players: %p", rSessionParameters.session_size.max_players);
	//					ImGui::Text("session: %p", rSessionParameters.session);
	//					ImGui::Text("observer: %p", rSessionParameters.observer);
	//					ImGui::Text("flags: 0x%08x", rSessionParameters.flags);
	//					ImGui::Text("initial_parameters_update_mask: 0x%08x", rSessionParameters.initial_parameters_update_mask);
	//				}
	//				ImGui::EndGroup();
	//			}

	//			ImGui::Text("m_local_state: %i", prNetworkSession->m_local_state);
	//			ImGui::Text("m_managed_session_index: %i", prNetworkSession->m_managed_session_index);
	//			ImGui::Text("pSession: %p", prNetworkSession->pSession);
	//		}
	//		ImGui::EndGroup();
	//	}
	//	ImGui::PopID();
	//}

	ImGui::End();
}

char(&aSystemUpdate)[] = reference_symbol<char[]>("aSystemUpdate", _engine_type_haloreach, _build_mcc_1_1035_0_0, 0x180A0EE08);

void init_haloreach_with_mcc(e_engine_type engine_type, e_build build, bool isMCC)
{
	ReadConfig();
	//DebugUI::RegisterCallback(haloreach_debug_callback);

	if (hs_function_table != nullptr)
	{
		if (c_settings_legacy::read_boolean(_settings_section_legacy_debug, "ReplacePrintScriptEvaluate", true))
		{
			hs_script_op* hs_print_function = hs_function_get(0x28);
			hs_script_op* hs_chud_post_message_function = hs_function_get(build >= _build_mcc_1_1186_0_0 ? 0x509 : 0x508);

			if (c_settings_legacy::read_boolean(_settings_section_legacy_debug, "PrintToHud", false))
			{
				hs_print_function->replace_evaluate(hs_chud_post_message_function->evaluate);
			}
			else
			{
				hs_print_function->replace_evaluate(hs_print_evaluate);
			}
		}
	}

	//LegacyGameLauncher::RegisterTerminationValue(g_termination_value);
}

void init_haloreach(e_engine_type engine_type, e_build build)
{
	init_haloreach_with_mcc(engine_type, build, false);
}

void deinit_haloreach(e_engine_type engine_type, e_build build)
{
	//DebugUI::UnregisterCallback(haloreach_debug_callback);


}
