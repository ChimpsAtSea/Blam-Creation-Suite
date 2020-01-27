
s_cache_file_tag_instance*& tag_instances = reference_symbol<s_cache_file_tag_instance*>("tag_instances", BuildVersion::Build_1_1270_0_0, 0x1826887B8);


struct s_table { uint32_t* table[]; };
intptr_t tag_address_table_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1270_0_0: return 0x1838D86C0;
	}
	return ~intptr_t();
}
DataEx<s_table, tag_address_table_offset> g_tag_address_table;

uint32_t* tag_address_get(uint32_t tagInstanceAddress)
{
	s_table& tag_address_table = g_tag_address_table;

	uint32_t* pData = &tag_address_table.table[tagInstanceAddress >> 28][tagInstanceAddress];

	return pData;
}

template<typename T>
T& tag_definition_get(uint16_t index)
{
	uint32_t tagInstanceAddress = tag_instances[index].address;
	return *reinterpret_cast<T*>(tag_address_get(tagInstanceAddress));
}


void* tag_definition_get(uint16_t index)
{
	uint32_t tagInstanceAddress = tag_instances[index].address;
	return reinterpret_cast<void*>(tag_address_get(tagInstanceAddress));
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

intptr_t cache_file_header_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1270_0_0: return 0x1826077A0;
	}
	return ~intptr_t();
}
DataEx<char*, cache_file_header_offset> g_cache_file;

s_cache_file_header* cache_file_header_get()
{
	s_cache_file_header& cache_file_header = *reinterpret_cast<s_cache_file_header*>(&g_cache_file[0x10]);
	return &cache_file_header;
}

