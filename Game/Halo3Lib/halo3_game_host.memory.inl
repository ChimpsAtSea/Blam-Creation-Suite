
uintptr_t halo3_tag_instances_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180CC9970);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x180CD8080);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x180CB3700);
	return ~uintptr_t();
}
gen3::s_cache_file_tag_instance*& halo3_tag_instances = reference_symbol<gen3::s_cache_file_tag_instance*>("halo3_tag_instances", halo3_tag_instances_offset);

uintptr_t halo3_tag_address_table_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180D15118);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x180D23838);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x180CFEEB8);
	return ~uintptr_t();
}
uint32_t* (&halo3_tag_address_table)[] = reference_symbol<uint32_t*[]>("halo3_tag_address_table", halo3_tag_address_table_offset);

uintptr_t halo3_cache_file_header_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180CC9998);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x180CD80A8);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x180CB3728);
	return ~uintptr_t();
}
halo3::s_cache_file_header& halo3_cache_file_header = reference_symbol<halo3::s_cache_file_header>("halo3_cache_file_header", halo3_cache_file_header_offset);

/*
// #TODO: figure out `tag_address_get`
char* halo3_tag_address_get(uint32_t tag_instance_address)
{
	if (!is_valid(halo3_tag_address_table))
	{
		return nullptr;
	}
	uint32_t* data = &halo3_tag_address_table[tag_instance_address][tag_instance_address];
	return reinterpret_cast<char*>(data);
}

char* halo3_tag_definition_get(uint32_t index)
{
	if (!is_valid(halo3_tag_instances))
	{
		return nullptr;
	}
	uint32_t tag_instance_address = halo3_tag_instances[index].address;
	return halo3_tag_address_get(tag_instance_address);
}

template<typename T>
T& halo3_tag_definition_get(uint32_t index)
{
	return *reinterpret_cast<T*>(halo3_tag_definition_get(index));
}

template<typename T>
T& halo3_tag_block_definition_get(c_typed_tag_block<T>& tag_block_ref, uint16_t index)
{
	T* tag_block_definition_ptr = reinterpret_cast<T*>(halo3_tag_address_get(tag_block_ref.address));

	for (size_t i = 0; i < tag_block_ref.count; i++)
	{
		if (i == index) break;
		tag_block_definition_ptr++;
	}
	return *tag_block_definition_ptr;
}

// #NOTE: `cache_file_header_get` should be correct as we're grabbing it directly from memory
halo3::s_cache_file_header* halo3_cache_file_header_get()
{
	if (!is_valid(halo3_cache_file_header))
	{
		return nullptr;
	}

	halo3::s_cache_file_header& cache_file_header = halo3_cache_file_header;
	return &cache_file_header;
}
*/