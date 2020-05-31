
template<typename t_type>
class c_data_array_base
{
public:
	char m_Name[32];
	size_t m_Size;
	unsigned int m_Signature;
	int m_MaximumCount;

private:
	char __unknown30[8];

public:
	class c_allocation_interface* m_pAllocation;
	int m_NextIndex;
	int m_FirstUnallocated;
	int m_ActualCount;
	unsigned __int16 m_NextIdentifier;
	unsigned __int16 m_IsolatedNextIdentifier;
	t_type* m_pData;
	unsigned int* m_InUseBitVector;
	int m_OffsetToData;
	int m_OffsetToBitVector;

private:
	char __unknown68[8];
};

template<typename t_type, size_t k_count>
class c_data_array : public c_data_array_base<t_type>
{
private:
	t_type m_Data[k_count];
};

struct s_script_node_datum
{
	char data[24];
};
constexpr size_t s_script_node_datum_size = sizeof(s_script_node_datum);


using s_script_node_data_array = c_data_array<s_script_node_datum, 61440>;


// BuildVersion::Build_1_1350_0_0, 0x180D2A048
// BuildVersion::Build_1_1367_0_0, 0x180D2A048
s_script_node_data_array*& g_script_node_data_array = reference_symbol<s_script_node_data_array*>("g_script_node_data_array", _engine_type_haloreach, _build_mcc_1_1350_0_0, 0x180D2A048);

std::vector<uintptr_t> spawn_ai_with_scripts_and_effects_offsets(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_haloreach)
	{
		switch (build)
		{
		case _build_mcc_1_1270_0_0: return { 0x18076F581, 0x180730287 };
		case _build_mcc_1_1305_0_0: return { 0x18076E341, 0x18072F047 };
		case _build_mcc_1_1367_0_0:
		case _build_mcc_1_1377_0_0:
		case _build_mcc_1_1384_0_0:
		case _build_mcc_1_1387_0_0:
		case _build_mcc_1_1389_0_0: return { 0x180779781, 0x18073A467 };
		case _build_mcc_1_1520_0_0:
		case _build_mcc_1_1570_0_0: return { 0x18077A971, 0x18073B657 };
		}
	}
	return {};
}
// Allows spawning AI via scripts or effects, props to Zeddikins
c_multi_data_patch<spawn_ai_with_scripts_and_effects_offsets> spawn_ai_with_scripts_and_effects = { 
	[](e_engine_type engine_type, e_build build, char* data[], DataPatchPackets& packets)
	{
		UINT8 jmp[1] = { 0xEB };

		packets.push_back(MAKE_DATAPATCHPACKET(data[0], sizeof(jmp)));
		copy_to_address(data[0], jmp, sizeof(jmp));

		packets.push_back(MAKE_DATAPATCHPACKET(data[1], 6));
		nop_address(data[1], 6);
	} 
};

uintptr_t allow_night_vision_in_multiplayer_offset(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_haloreach)
	{
		switch (build)
		{
		case _build_mcc_1_1305_0_0: return 0x1805D66B7;
		case _build_mcc_1_1367_0_0:
		case _build_mcc_1_1377_0_0:
		case _build_mcc_1_1384_0_0:
		case _build_mcc_1_1387_0_0:
		case _build_mcc_1_1389_0_0: return 0x1805E18D7;
		case _build_mcc_1_1520_0_0:
		case _build_mcc_1_1570_0_0: return 0x1805E2AC7;
		}
	}
	return ~uintptr_t();
}
// Allow the use of night vision in multiplayer, props to Zeddikins
c_data_patch<allow_night_vision_in_multiplayer_offset> allow_night_vision_in_multiplayer = { 
	[](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
	{
		packet = MAKE_DATAPATCHPACKET(data, 6);
		nop_address(data, 6);
	} 
};

#pragma pack(push, 4)
struct hs_script_op
{
	short return_type;
	short flags;
	__int32 __unused4;
	void(__fastcall *evaluate)(short opcode, unsigned short expression_index, char execute);
	const char *parameter_info;
	short parameter_count;
	short parameter_types;

	void replace_evaluate(LPVOID new_evaluate)
	{
		//printf("0x%08llX\n", *(UINT64 *)&evaluate);
		memcpy_virtual(&evaluate, &new_evaluate, sizeof(void *));
		//printf("0x%08llX\n", *(UINT64 *)&evaluate);
	}
	void print_parameter_info()
	{
		printf("%s\n", parameter_info);
	}
};
#pragma pack(pop)

uintptr_t hs_function_table_offset(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_haloreach)
	{
		switch (build)
		{
		case _build_mcc_1_824_0_0: return 0x180C33620;
		case _build_mcc_1_887_0_0: return 0x180D89480;
		case _build_mcc_1_1035_0_0: return 0x180AB2910;
		case _build_mcc_1_1186_0_0: return 0x180ABF520;
		case _build_mcc_1_1211_0_0: return 0x180ABF4B0;
		case _build_mcc_1_1246_0_0: return 0x180ABC220;
		case _build_mcc_1_1270_0_0: return 0x180ABC230;
		case _build_mcc_1_1305_0_0: return 0x180AA76C0;
		case _build_mcc_1_1350_0_0: return 0x180AB2810;
		case _build_mcc_1_1367_0_0:
		case _build_mcc_1_1377_0_0:
		case _build_mcc_1_1384_0_0:
		case _build_mcc_1_1387_0_0:
		case _build_mcc_1_1389_0_0: return 0x180AB2820;
		case _build_mcc_1_1520_0_0:
		case _build_mcc_1_1570_0_0: return 0x180AB4850;
		}
	}
	return ~uintptr_t();
}
hs_script_op *(&hs_function_table)[] = reference_symbol<hs_script_op *[]>("hs_function_table", hs_function_table_offset);

uintptr_t hs_evaluate_arguments_offset(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_haloreach)
	{
		switch (build)
		{
		case _build_mcc_1_824_0_0: return 0x1807351D0;
		case _build_mcc_1_887_0_0: return 0x1803EC060;
		case _build_mcc_1_1035_0_0: return 0x1801F9290;
		case _build_mcc_1_1186_0_0: return 0x1801F6420;
		case _build_mcc_1_1211_0_0: return 0x1801F6B60;
		case _build_mcc_1_1246_0_0: return 0x1801EF600;
		case _build_mcc_1_1270_0_0: return 0x1801EF690;
		case _build_mcc_1_1305_0_0: return 0x1801EF7A0;
		case _build_mcc_1_1350_0_0: return 0x1801F1620;
		case _build_mcc_1_1367_0_0:
		case _build_mcc_1_1377_0_0:
		case _build_mcc_1_1384_0_0:
		case _build_mcc_1_1387_0_0:
		case _build_mcc_1_1389_0_0: return 0x1801F1610;
		case _build_mcc_1_1520_0_0:
		case _build_mcc_1_1570_0_0: return 0x1801F17D0;
		}
	}
	return ~uintptr_t();
}

template<typename t_parameter>
FunctionHookEx<hs_evaluate_arguments_offset, t_parameter __fastcall (unsigned short expression_index, short parameters_count, short *parameters, char execute)> hs_evaluate_arguments;

uintptr_t hs_return_offset(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_haloreach)
	{
		switch (build)
		{
		case _build_mcc_1_824_0_0: return 0x180734900;
		case _build_mcc_1_887_0_0: return 0x1803EB790;
		case _build_mcc_1_1035_0_0: return 0x1801F8A00;
		case _build_mcc_1_1186_0_0: return 0x1801F5B90;
		case _build_mcc_1_1211_0_0: return 0x1801F62D0;
		case _build_mcc_1_1246_0_0: return 0x1801EED70;
		case _build_mcc_1_1270_0_0: return 0x1801EEE00;
		case _build_mcc_1_1305_0_0: return 0x1801EEF10;
		case _build_mcc_1_1350_0_0: return 0x1801F0D90;
		case _build_mcc_1_1367_0_0:
		case _build_mcc_1_1377_0_0:
		case _build_mcc_1_1384_0_0:
		case _build_mcc_1_1387_0_0:
		case _build_mcc_1_1389_0_0: return 0x1801F0D80;
		case _build_mcc_1_1520_0_0:
		case _build_mcc_1_1570_0_0: return 0x1801F0F40;
		}
	}
	return ~uintptr_t();
}
FunctionHookEx<hs_return_offset, __int64 __fastcall (unsigned short expression_index, unsigned int handle)> hs_return;

hs_script_op *hs_function_get(short opcode)
{
	REFERENCE_ASSERT(hs_function_table);
	return hs_function_table[opcode];
}

template<typename t_parameter>
t_parameter &hs_macro_function_evaluate(short opcode, unsigned short expression_index, char execute)
{
	hs_script_op *hs_function = hs_function_get(opcode);
	return *hs_evaluate_arguments<t_parameter *>(expression_index, hs_function->parameter_count, &hs_function->parameter_types, execute);
}

uintptr_t hs_inspect_str_offset(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_haloreach)
	{
		switch (build)
		{
		case _build_mcc_1_824_0_0: return 0x180732290;
		case _build_mcc_1_887_0_0: return 0x1803E9120;
		case _build_mcc_1_1035_0_0: return 0x1801F6B00;
		case _build_mcc_1_1186_0_0: return 0x1801F3D10;
		case _build_mcc_1_1211_0_0: return 0x1801F4450;
		case _build_mcc_1_1246_0_0: return 0x1801ECEF0;
		case _build_mcc_1_1270_0_0: return 0x1801ECF80;
		case _build_mcc_1_1305_0_0: return 0x1801ED090;
		case _build_mcc_1_1350_0_0: return 0x1801EEF10;
		case _build_mcc_1_1367_0_0:
		case _build_mcc_1_1377_0_0:
		case _build_mcc_1_1384_0_0:
		case _build_mcc_1_1387_0_0:
		case _build_mcc_1_1389_0_0: return 0x1801EEF00;
		case _build_mcc_1_1520_0_0:
		case _build_mcc_1_1570_0_0: return 0x1801EF0C0;
		}
	}
	return ~uintptr_t();
}
FunctionHookEx<hs_inspect_str_offset, char *__fastcall (__int64 unused, int id, char *dst, int len)> hs_inspect_str;

void __fastcall hs_print_evaluate(short opcode, unsigned short expression_index, char execute)
{
	int &out_parameter = hs_macro_function_evaluate<int>(opcode, expression_index, execute);
	if (&out_parameter)
	{
		char buf[1024] = {};
		hs_inspect_str(0, out_parameter, buf, 1024);
		printf("%s\n", buf);

		hs_return(expression_index, 0);
	}
}
