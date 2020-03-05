
uintptr_t tag_instances_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1305_0_0, 0x180CF8FC0);
	return ~uintptr_t();
}
s_cache_file_tag_instance*& tag_instances = reference_symbol<s_cache_file_tag_instance*>("tag_instances", tag_instances_offset);

uintptr_t tag_address_table_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1305_0_0, 0x183887CA0);
	return ~uintptr_t();
}
uint32_t* (&tag_address_table)[] = reference_symbol<uint32_t * []>("tag_address_table", tag_address_table_offset);

uintptr_t g_cache_file_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo_reach, _build_mcc_1_1305_0_0, 0x1825B6D90);
	return ~uintptr_t();
}
char* & g_cache_file = reference_symbol<char*>("g_cache_file", g_cache_file_offset);

char* tag_address_get(uint32_t tagInstanceAddress)
{
	if (&tag_address_table == nullptr) return nullptr;
	uint32_t* pData = &tag_address_table[tagInstanceAddress >> 28][tagInstanceAddress];
	return reinterpret_cast<char*>(pData);
}

char* tag_definition_get(uint16_t index)
{
	if (&tag_instances == nullptr) return nullptr;
	uint32_t tagInstanceAddress = tag_instances[index].address;
	return tag_address_get(tagInstanceAddress);
}

template<typename T>
T& tag_definition_get(uint16_t index)
{
	return *reinterpret_cast<T*>(tag_definition_get(index));
}

template<typename T>
T& tag_block_definition_get(s_tag_block_definition<T>& rTagBlock, uint16_t index)
{
	T* pTagBlockDefinition = reinterpret_cast<T*>(tag_address_get(rTagBlock.address));

	for (size_t i = 0; i < rTagBlock.count; i++)
	{
		if (i == index) break;
		pTagBlockDefinition++;
	}
	return *pTagBlockDefinition;
}

s_cache_file_header* cache_file_header_get()
{
	if (&g_cache_file == nullptr) return nullptr;

	s_cache_file_header& cache_file_header = *reinterpret_cast<s_cache_file_header*>(&g_cache_file[0x10]);
	return &cache_file_header;
}

