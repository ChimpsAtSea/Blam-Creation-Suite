#define __HALO1_GAME_HOST_CONTROLS_RESEARCH_INL

uintptr_t get_local_player_input_blob_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x180767C10);
	return ~uintptr_t();
}
c_function_hook_ex<get_local_player_input_blob_offset, char __fastcall(__int64 a1, __int64 a2, __int64 a3)> get_local_player_input_blob 
	= { "get_local_player_input_blob", [](__int64 a1, __int64 a2, __int64 a3)
{
	auto result = get_local_player_input_blob(a1, a2, a3);
	return result;
} };

uintptr_t sub_18006ECD0_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18006ECD0);
	return ~uintptr_t();
}
c_function_hook_ex<sub_18006ECD0_offset, signed int()> sub_18006ECD0 = { "sub_18006ECD0", []()
{
	update_console();
	return sub_18006ECD0();
} };

extern BYTE keyboardState[256];

uintptr_t input_update_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18070E120);
	return ~uintptr_t();
}
c_function_hook_ex<input_update_offset, void()> input_update = { "input_update", []()
{
	input_update();

	//for (int i = 0; i < 256; i++)
	//{
	//	if (keyboardState[i] & 0b10000000)
	//	{
	//		g_keyboard_state[i] = 0xFF;
	//	}
	//	else
	//	{
	//		g_keyboard_state[i] = 0;
	//	}
	//}

} };


static bool disable_input_state = false;
static thread_local bool disable_input = false;

uintptr_t g_GameInputSource_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18218CDF4);
	return ~uintptr_t();
}
int& g_GameInputSource = reference_symbol<int>("g_GameInputSource", g_GameInputSource_offset);

uintptr_t input_abstraction_update_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18071F200);
	return ~uintptr_t();
}
c_function_hook_ex<input_abstraction_update_offset, __int64 __fastcall (__int64 a1)> input_abstraction_update = { "input_abstraction_update", [](__int64 a1)
{
	disable_input = disable_input_state;

	return input_abstraction_update(a1);

	disable_input = false;

	//static bool enable = true;
	//if (GetAsyncKeyState(VK_F6) >> 15)
	//{
	//	enable = !enable;
	//}

	//if (enable)
	//{
	//	return input_abstraction_update(a1);
	//}

	//return (__int64)0;

} };

uintptr_t input_key_is_down_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18070E8B0);
	return ~uintptr_t();
}
c_function_hook_ex<input_key_is_down_offset, char __fastcall (__int16 a1)> input_key_is_down = { "input_key_is_down", [](__int16 a1)
{
	char result = (disable_input) ? char(0) : input_key_is_down(a1);
	return result;
} };

bool sub_18071E950_override = 0;
int32_t sub_18071E950_override_value = 0;
int16_t sub_18071E950_state = 0;

uintptr_t sub_18071E950_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18071E950);
	return ~uintptr_t();
}
c_function_hook_ex<sub_18071E950_offset, __int64 __fastcall (unsigned __int16 a1, QWORD* a2)> sub_18071E950 = { "sub_18071E950", [](unsigned __int16 a1, QWORD* a2)
{
	__int64 result = sub_18071E950(a1, a2);

	int16_t& value = *reinterpret_cast<int16_t*>(a2);

	sub_18071E950_state = value;

	if (sub_18071E950_override)
	{
		value = sub_18071E950_override_value;
	}

	return result;
} };


//uintptr_t input_abstraction_update_patch_offset(s_engine_platform_build engine_platform_build)
//{
//	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18071F200);
//	return ~uintptr_t();
//}
//DataPatch<input_abstraction_update_patch_offset> input_abstraction_update_patch = { [](s_engine_platform_build engine_platform_build, char* data, DataPatchPacket& packet)
//{
//	char* return_address = data;
//	packet = MAKE_DATAPATCHPACKET(return_address,  0x18072083F - 0x18071F200);
//
//	//nop_address(engine_platform_build, 0x18071F5DF, 0x1807207F6 - 0x18071F5DF);
//
//	uint8_t data2[] = { 0xC3ui8 };
//	memcpy_virtual(data + (0x18071F5B1 - 0x18071F200), data2, 1);
//	//memcpy_virtual(data + (0x18071F200 - 0x18071F200), data2, 1);
//
//
//	//data[0] = 0xC3; // RETN
//} };



#define sign(value) (value < 0 ? -1 : 1)
#define clamp(value, min_value, max_value) ((value) > (max_value) ? (max_value) : ((value) < (min_value) ? (min_value) : (value)))
#define CONTROLLER_JOYSTICK_THRESHOLD 0.15f

uintptr_t mcc_input_update_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_mcc, _build_mcc_1_1389_0_0, 0x1418BFE5C);
	return ~uintptr_t();
}
c_function_hook_ex<mcc_input_update_offset, unsigned __int8 __fastcall (void* a1, _QWORD a2, IGameEngineHost::InputBuffer* input_buffer)> mcc_input_update
	= { "mcc_input_update", [](void* a1, _QWORD a2, IGameEngineHost::InputBuffer* input_buffer)
{
	auto result = mcc_input_update(a1, a2, input_buffer);
	return result;
} };


bool sub_18071E690_override = 0;
int32_t sub_18071E690_override_value = 0;
int16_t sub_18071E690_state = 0;


uintptr_t sub_18071E690_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18071E690);
	return ~uintptr_t();
}
c_function_hook_ex<sub_18071E690_offset, __int64 __fastcall (unsigned int a1, __int16 a2)> sub_18071E690 = { "sub_18071E690", [](unsigned int a1, __int16 a2)
{
	sub_18071E690_state = a1;
	if (sub_18071E690_override)
	{
		a1 = sub_18071E690_override_value;
	}

	//console_write_line("sub_18071E690 %u %u", a1, static_cast<uint32_t>(a2));
	auto result = sub_18071E690(a1, a2);
	return __int64(1);
	return result;
} };

//uintptr_t halo1_update_engine_state_offset(s_engine_platform_build engine_platform_build)
//{
//	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x180076490);
//	return ~uintptr_t();
//}
//c_function_hook_ex<halo1_update_engine_state_offset, __int64 __fastcall (IGameEngine* _this, e_engine_state status, _QWORD* extraArgument)> halo1_update_engine_state 
//	= { "halo1_update_engine_state", [](IGameEngine* _this, e_engine_state status, _QWORD* extraArgument) {
//
//	//auto result = halo1_update_engine_state(_this, status, extraArgument);
//	//return result;
//	return __int64(0);
//
//} };

//__int64 __fastcall update_engine_state(IGameEngine* _this, e_engine_state status, _QWORD* extraArgument);

uintptr_t dword_18115BB84_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18115BB84);
	return ~uintptr_t();
}
DWORD& dword_18115BB84 = reference_symbol<DWORD>("dword_18115BB84", dword_18115BB84_offset);

uintptr_t byte_1811684DA_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x1811684DA);
	return ~uintptr_t();
}
uint8_t(&byte_1811684DA)[128] = reference_symbol<uint8_t[128]>("byte_1811684DA", byte_1811684DA_offset); // SOURCE

uintptr_t word_18115BBB6_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18115BBB6);
	return ~uintptr_t();
}
uint8_t(&word_18115BBB6)[128] = reference_symbol<uint8_t[128]>("word_18115BBB6", word_18115BBB6_offset); // DESTINATION


uintptr_t sub_18072FCF0_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18072FCF0);
	return ~uintptr_t();
}
c_function_hook_ex<sub_18072FCF0_offset, void* (__int16 a1)> sub_18072FCF0 = { "sub_18072FCF0", [](__int16 a1)
{
	uint32_t sub_18006ECD0_reference_counter = sub_18006ECD0.reference_counter;

	if (sub_18006ECD0_reference_counter > 0)
	{
		void* result = sub_18072FCF0(a1);
		return result;
	}
	else
	{
		void* result = sub_18072FCF0(a1);
		return result;
	}
} };

uintptr_t g_player_configuration_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x1820b9900);
	return ~uintptr_t();
}
c_player_configuration& g_player_configuration = reference_symbol<c_player_configuration>("g_player_configuration", g_player_configuration_offset);
uintptr_t sub_180093240_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x180093240);
	return ~uintptr_t();
}
c_function_hook_ex<sub_180093240_offset, void __fastcall (c_player_configuration* player_configuration)> sub_180093240 = { "sub_180093240", [](c_player_configuration* player_configuration)
{
	sub_180093240(player_configuration);
	//printf("");
	return;
} };


uintptr_t sub_1807A6200_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x1807A6200);
	return ~uintptr_t();
}
c_function_hook_ex<sub_1807A6200_offset, __int64 __fastcall (__int16* a1, __int16 a2, __int64 a3)> sub_1807A6200 = { "sub_1807A6200", [](__int16* a1, __int16 a2, __int64 a3)
{
	__int64 result = sub_1807A6200(a1, a2, a3);
	return result;
} };

uintptr_t sub_180721840_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x180721840);
	return ~uintptr_t();
}
c_function_hook_ex<sub_180721840_offset, __int64 __fastcall (char* control_type, char* virtual_key_code_name, __int64 a3)> sub_180721840 
	= { "sub_180721840", [](char* control_type, char* virtual_key_code_name, __int64 a3)
{
	__int64 result = sub_180721840(control_type, virtual_key_code_name, a3);
	console_write_line("sub_180721840> '%s' '%s' [%lli]", control_type, virtual_key_code_name, result);
	return result;
} };
