
uintptr_t tag_instances_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo_reach, _build_mcc_1_824_0_0, 0x1837FD738);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_887_0_0, 0x183984DC8);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1035_0_0, 0x18358EEE8);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1186_0_0, 0x18268D7B8);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1211_0_0, 0x18268E918);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1246_0_0, 0x1826887B8);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1270_0_0, 0x1826887B8);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1305_0_0, 0x180CF8FC0);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1350_0_0, 0x182645338);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1367_0_0, 0x182645288);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1377_0_0, 0x182645288);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1384_0_0, 0x182645288);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1387_0_0, 0x182645288);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1389_0_0, 0x182645288);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1520_0_0, 0x1826475F8);
	return ~uintptr_t();
}
s_cache_file_tag_instance*& tag_instances = reference_symbol<s_cache_file_tag_instance*>("tag_instances", tag_instances_offset);

uintptr_t tag_address_table_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo_reach, _build_mcc_1_824_0_0, 0x18102F0E0);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_887_0_0, 0x1811EFD80);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1035_0_0, 0x184466280);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1186_0_0, 0x1838DD6E0);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1211_0_0, 0x1838DE840);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1246_0_0, 0x1838D86C0);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1270_0_0, 0x1838D86C0);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1305_0_0, 0x183887CA0);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1350_0_0, 0x1838CB820);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1367_0_0, 0x1838CB7E0);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1377_0_0, 0x1838CB7E0);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1384_0_0, 0x1838CB7E0);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1387_0_0, 0x1838CB7E0);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1389_0_0, 0x1838CB7E0);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1520_0_0, 0x1838CDC20);
	return ~uintptr_t();
}
uint32_t* (&tag_address_table)[] = reference_symbol<uint32_t * []>("tag_address_table", tag_address_table_offset);

uintptr_t g_cache_file_global_loaded_state_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo_reach, _build_mcc_1_824_0_0, 0x18377C720);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_887_0_0, 0x183903DB0);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1035_0_0, 0x18350DED0);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1186_0_0, 0x18260C7A0);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1211_0_0, 0x18260D900);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1246_0_0, 0x1826077A0);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1270_0_0, 0x1826077A0);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1305_0_0, 0x1825B6D90);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1350_0_0, 0x1825C4320);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1367_0_0, 0x1825C4270);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1377_0_0, 0x1825C4270);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1384_0_0, 0x1825C4270);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1387_0_0, 0x1825C4270);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1389_0_0, 0x1825C4270);
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1520_0_0, 0x1825C65E0);
	return ~uintptr_t();
}
char*& g_cache_file_global_loaded_state = reference_symbol<char*>("g_cache_file_global_loaded_state", g_cache_file_global_loaded_state_offset);

char* tag_address_get(uint32_t tag_instance_address)
{
	if (!is_valid(tag_address_table))
	{
		return nullptr;
	}
	uint32_t* pData = &tag_address_table[tag_instance_address >> 28][tag_instance_address];
	return reinterpret_cast<char*>(pData);
}

char* tag_definition_get(uint16_t index)
{
	if (!is_valid(tag_instances))
	{
		return nullptr;
	}
	uint32_t tag_instance_address = tag_instances[index].address;
	return tag_address_get(tag_instance_address);
}

template<typename T>
T& tag_definition_get(uint16_t index)
{
	return *reinterpret_cast<T*>(tag_definition_get(index));
}

template<typename T>
T& tag_block_definition_get(s_tag_block_legacy<T>& tag_block_ref, uint16_t index)
{
	T* tag_block_definition_ptr = reinterpret_cast<T*>(tag_address_get(tag_block_ref.address));

	for (size_t i = 0; i < tag_block_ref.count; i++)
	{
		if (i == index) break;
		tag_block_definition_ptr++;
	}
	return *tag_block_definition_ptr;
}

s_reach_cache_file_header* cache_file_header_get()
{
	if (!is_valid(g_cache_file_global_loaded_state))
	{
		return nullptr;
	}

	s_reach_cache_file_header& cache_file_header = *reinterpret_cast<s_reach_cache_file_header*>(&g_cache_file_global_loaded_state[0x10]);
	return &cache_file_header;
}

uintptr_t t_restricted_allocation_manager__reserve_memory_offset(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_halo_reach)
	{
		switch (build)
		{
		case _build_mcc_1_1270_0_0: return 0x180211A20;
		}
	}
	return ~uintptr_t();
}
#define t_restricted_allocation_manager__reserve_memory_offset_args void* __this, const char* szName, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8
FunctionHookEx<t_restricted_allocation_manager__reserve_memory_offset, __int64 __fastcall (t_restricted_allocation_manager__reserve_memory_offset_args)> t_restricted_allocation_manager__reserve_memory = { "t_restricted_allocation_manager__reserve_memory", [](t_restricted_allocation_manager__reserve_memory_offset_args)
{
	__int64 result = t_restricted_allocation_manager__reserve_memory(__this, szName, a3, a4, a5, a6, a7, a8);
	write_line_verbose("t_restricted_allocation_manager> Allocating memory for '%s'", szName);
	return result;
} };
