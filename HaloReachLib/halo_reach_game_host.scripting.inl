
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
static constexpr size_t s_script_node_datum_size = sizeof(s_script_node_datum);


using s_script_node_data_array = c_data_array<s_script_node_datum, 61440>;


// BuildVersion::Build_1_1350_0_0, 0x180D2A048
// BuildVersion::Build_1_1367_0_0, 0x180D2A048
s_script_node_data_array*& g_script_node_data_array = reference_symbol<s_script_node_data_array*>("g_script_node_data_array", _engine_type_halo_reach, _build_mcc_1_1350_0_0, 0x180D2A048);






