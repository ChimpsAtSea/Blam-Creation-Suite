
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
s_script_node_data_array*& g_script_node_data_array = reference_symbol<s_script_node_data_array*>("g_script_node_data_array", _engine_type_halo_reach, _build_mcc_1_1350_0_0, 0x180D2A048);

std::vector<uintptr_t> spawn_ai_with_scripts_and_effects_offsets(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_halo_reach)
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
	if (engine_type == _engine_type_halo_reach)
	{
		switch (build)
		{
		case _build_mcc_1_1305_0_0: return 0x1805D66B7;
		case _build_mcc_1_1367_0_0:
		case _build_mcc_1_1377_0_0:
		case _build_mcc_1_1384_0_0:
		case _build_mcc_1_1387_0_0:
		case _build_mcc_1_1389_0_0: return 0x1805E18D7;
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

std::vector<uintptr_t> enable_debug_hud_coordinates_offsets(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_halo_reach)
	{
		switch (build)
		{
		case _build_mcc_1_1305_0_0: return { 0x1800DCA8A, 0x1800DCA97 };
		case _build_mcc_1_1367_0_0:
		case _build_mcc_1_1377_0_0:
		case _build_mcc_1_1384_0_0:
		case _build_mcc_1_1387_0_0:
		case _build_mcc_1_1389_0_0: return { 0x1800DDF7A, 0x1800DDF87 };
		}
	}
	return {};
}
// Enable debug hud coordinates
c_multi_data_patch<enable_debug_hud_coordinates_offsets> enable_debug_hud_coordinates = {
	[](e_engine_type engine_type, e_build build, char* data[], DataPatchPackets& packets)
	{
		packets.push_back(MAKE_DATAPATCHPACKET(data[0], 6));
		nop_address(data[0], 6);

		packets.push_back(MAKE_DATAPATCHPACKET(data[1], 6));
		nop_address(data[1], 6);
	}
};



