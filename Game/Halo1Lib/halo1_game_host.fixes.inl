
uintptr_t sub_1806F4000_offset(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_halo1 && false)
	{
		using namespace ketchup;
		c_pattern_scanner ps = c_pattern_scanner(GetCurrentProcess(), static_cast<HMODULE>(get_engine_memory_address(engine_type))); // 1.1350.0.0

		// .text:00000001806F4000 sub_1806F4000   proc near               ; CODE XREF: sub_180704270+72↓p
		// .text:00000001806F4000                                         ; sub_180704BF0+65↓p ...
		// .text:00000001806F4000
		// .text:00000001806F4000 arg_0           = qword ptr  8
		// .text:00000001806F4000 arg_8           = qword ptr  10h
		// .text:00000001806F4000
		// .text:00000001806F4000                 mov     [rsp+arg_0], rbx
		// .text:00000001806F4005                 mov     [rsp+arg_8], rsi
		// .text:00000001806F400A                 push    rdi
		// .text:00000001806F400B                 sub     rsp, 20h
		// .text:00000001806F400F                 call    sub_1807B3CA0
		// .text:00000001806F4014                 call    sub_1800664C0
		// .text:00000001806F4019                 mov     rax, cs:qword_18218CD50
		// .text:00000001806F4020                 mov     cs:byte_18115AFEF, 0
		// .text:00000001806F4027                 mov     ecx, [rax+10h]
		// .text:00000001806F402A                 mov     rax, cs:qword_18115B590
		// .text:00000001806F4031                 mov     cs:dword_18115BB80, ecx
		// .text:00000001806F4037                 test    rax, rax
		// .text:00000001806F403A                 jz      short loc_1806F403F
		// .text:00000001806F403C                 mov     byte ptr [rax], 0
		// ......

		ps.add_instruction(new _mov("x", 0x48, 0x89, 0x5C, 0x24, 0x08));
		ps.add_instruction(new _mov("x", 0x48, 0x89, 0x74, 0x24, 0x10));
		ps.add_instruction(new _push("x", 0x57));
		ps.add_instruction(new _sub("x", 0x48, 0x83, 0xEC, 0x20));
		ps.add_instruction(new _call("x", 0xE8, 0x8C, 0xFC, 0x0B, 0x00));
		ps.add_instruction(new _call("x", 0xE8, 0xA7, 0x24, 0x97, 0xFF));
		ps.add_instruction(new _mov("x", 0x48, 0x8B, 0x05, 0x30, 0x8D, 0xA9, 0x01));
		ps.add_instruction(new _mov("x", 0xC6, 0x05, 0xC8, 0x6F, 0xA6, 0x00, 0x00));
		ps.add_instruction(new _mov("x", 0x8B, 0x48, 0x10));
		ps.add_instruction(new _mov("x", 0x48, 0x8B, 0x05, 0x5F, 0x75, 0xA6, 0x00));
		ps.add_instruction(new _mov("x", 0x89, 0x0D, 0x49, 0x7B, 0xA6, 0x00));
		ps.add_instruction(new _test("x", 0x48, 0x85, 0xC0));
		ps.add_instruction(new _jz("x", e_jump_distance::Short, 0x74, 0x03));
		ps.add_instruction(new _mov("x", 0xC6, 0x00, 0x00));

		DWORD pattern_offset = ps.find_pattern(0);
		if (pattern_offset)
		{
			c_console::write_line_verbose("ketchup> SUCCEED: sub_1800935B0 @0x%x", pattern_offset);
			return get_engine_base_address(engine_type) + pattern_offset;
		}
		else
		{
			c_console::write_line_verbose("ketchup> FAILURE: sub_1800935B0");
		}
	}

	
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x1806F4000);
	OFFSET(_engine_type_halo1, _build_mcc_1_1570_0_0, 0x1806F42B0);
	return ~uintptr_t();
}
FunctionHookEx<sub_1806F4000_offset, void()> sub_1806F4000 = { "sub_1806F4000", []() {

	sub_1806F4000();
	debug_point;

} };

uintptr_t sub_1800935B0_offset(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_halo1 && false)
	{
		using namespace ketchup;
		c_pattern_scanner ps = c_pattern_scanner(GetCurrentProcess(), static_cast<HMODULE>(get_engine_memory_address(engine_type))); // 1.1350.0.0

		// .text:00000001800935B0                 mov     [rsp+arg_0], rbx
		// .text:00000001800935B5                 mov     [rsp+arg_8], rbp
		// .text:00000001800935BA                 mov     [rsp+arg_10], rsi
		// .text:00000001800935BF                 push    rdi
		// .text:00000001800935C0                 sub     rsp, 20h
		// .text:00000001800935C4                 mov     bl, 1
		// .text:00000001800935C6                 lea     rdi, unk_1820B9900
		// .text:00000001800935CD                 mov     esi, 4
		// .text:00000001800935D2                 xor     ebp, ebp
		// .text:00000001800935D4
		// .text:00000001800935D4 loc_1800935D4:                          ; CODE XREF: sub_1800935B0+3F↓j
		// .text:00000001800935D4                 mov     rdx, rdi
		// .text:00000001800935D7                 call    sub_1800934C0
		// .text:00000001800935DC                 test    al, al
		// .text:00000001800935DE                 movzx   ebx, bl
		// .text:00000001800935E1                 cmovnz  ebx, ebp
		// .text:00000001800935E4                 add     rdi, 89Ch
		// .text:00000001800935EB                 sub     rsi, 1
		// .text:00000001800935EF                 jnz     short loc_1800935D4
		// .text:00000001800935F1                 mov     rbp, [rsp+28h+arg_8]
		// .text:00000001800935F6                 movzx   eax, bl
		// .text:00000001800935F9                 mov     rbx, [rsp+28h+arg_0]
		// .text:00000001800935FE                 mov     rsi, [rsp+28h+arg_10]
		// .text:0000000180093603                 add     rsp, 20h
		// .text:0000000180093607                 pop     rdi
		// .text:0000000180093608                 retn

		ps.add_instruction(new _mov("x", 0x48, 0x89, 0x5C, 0x24, 0x08));
		ps.add_instruction(new _mov("x", 0x48, 0x89, 0x6C, 0x24, 0x10));
		ps.add_instruction(new _mov("x", 0x48, 0x89, 0x74, 0x24, 0x18));
		ps.add_instruction(new _push("x", 0x57));
		ps.add_instruction(new _sub("x", 0x48, 0x83, 0xEC, 0x20));
		ps.add_instruction(new _mov("x", 0xB3, 0x01));
		ps.add_instruction(new _lea("x", 0x48, 0x8D, 0x3D, 0x33, 0x63, 0x02, 0x02));
		ps.add_instruction(new _mov("x", 0xBE, 0x04, 0x00, 0x00, 0x00));
		ps.add_instruction(new _xor("x", 0x33, 0xED));

		DWORD pattern_offset = ps.find_pattern(0);
		if (pattern_offset)
		{
			c_console::write_line_verbose("ketchup> SUCCEED: sub_1800935B0 @0x%x", pattern_offset);
			return get_engine_base_address(engine_type) + pattern_offset;
		}
		else
		{
			c_console::write_line_verbose("ketchup> FAILURE: sub_1800935B0");
		}
	}

	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x1800935B0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1570_0_0, 0x1800935F0);
	return ~uintptr_t();
}
FunctionHookEx<sub_1800935B0_offset, __int64 __fastcall (__int64 a1)> sub_1800935B0 = { "sub_1800935B0", [](__int64 a1) {

	uint32_t sub_1806F4000_reference_count = sub_1806F4000.reference_counter;

	if (sub_1806F4000_reference_count > 0)
	{
		return __int64(0);
	}
	else
	{
		__int64 result = sub_1800935B0(a1);
		return result;
	}

} };
