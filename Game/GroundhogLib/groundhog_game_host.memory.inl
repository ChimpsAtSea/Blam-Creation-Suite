
uintptr_t groundhog_tag_instances_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_groundhog, _build_mcc_1_1477_0_0, 0x1816042F8);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1499_0_0, 0x181604378);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1520_0_0, 0x181604378);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1570_0_0, 0x1816043F8);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1619_0_0, 0x1816043F8);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1698_0_0, 0x181607618);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1716_0_0, 0x181607618);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1829_0_0, 0x1815819C8);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1864_0_0, 0x1815819C8);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1871_0_0, 0x1815819C8);
	return ~uintptr_t();
}
gen3::s_cache_file_tag_instance*& groundhog_tag_instances = reference_symbol<gen3::s_cache_file_tag_instance*>("groundhog_tag_instances", groundhog_tag_instances_offset);

uintptr_t groundhog_tag_address_table_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_groundhog, _build_mcc_1_1477_0_0, 0x18375F900);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1499_0_0, 0x18375F980);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1520_0_0, 0x18375F980);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1570_0_0, 0x18375FA00);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1619_0_0, 0x18375FA00);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1698_0_0, 0x183763660);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1716_0_0, 0x183763660);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1829_0_0, 0x1835B8780);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1864_0_0, 0x1835B8780);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1871_0_0, 0x1835B8780);
	return ~uintptr_t();
}
uint32_t* (&groundhog_tag_address_table)[] = reference_symbol<uint32_t* []>("groundhog_tag_address_table", groundhog_tag_address_table_offset);

uintptr_t groundhog_cache_file_global_loaded_state_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_groundhog, _build_mcc_1_1477_0_0, 0x181583200);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1499_0_0, 0x181583280);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1520_0_0, 0x181583280);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1570_0_0, 0x181583300);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1619_0_0, 0x181583300);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1698_0_0, 0x181586520);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1716_0_0, 0x181586520);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1829_0_0, 0x1815008D0);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1864_0_0, 0x1815008D0);
	OFFSET(_engine_type_groundhog, _build_mcc_1_1871_0_0, 0x1815008D0);
	return ~uintptr_t();
}
char*& groundhog_cache_file_global_loaded_state = reference_symbol<char*>("groundhog_cache_file_global_loaded_state", groundhog_cache_file_global_loaded_state_offset);

char* groundhog_tag_address_get(uint32_t tag_instance_address)
{
	if (!is_valid(groundhog_tag_address_table))
	{
		return nullptr;
	}
	uint32_t* data = &groundhog_tag_address_table[tag_instance_address >> 28][tag_instance_address];
	return reinterpret_cast<char*>(data);
}

char* groundhog_tag_definition_get(uint32_t tag_index)
{
	if (!is_valid(groundhog_tag_instances))
	{
		return nullptr;
	}
	uint32_t tag_instance_address = groundhog_tag_instances[tag_index].address;
	return groundhog_tag_address_get(tag_instance_address);
}

template<typename T>
T& groundhog_tag_definition_get(uint32_t tag_index)
{
	return *reinterpret_cast<T*>(groundhog_tag_definition_get(tag_index));
}

template<typename T>
T& groundhog_tag_block_definition_get(c_typed_tag_block<T>& tag_block_ref, uint32_t tag_index)
{
	T* tag_block_definition_ptr = reinterpret_cast<T*>(groundhog_tag_address_get(tag_block_ref.address));

	for (uint32_t i = 0; i < tag_block_ref.count; i++)
	{
		if (i == tag_index) break;
		tag_block_definition_ptr++;
	}
	return *tag_block_definition_ptr;
}

groundhog::s_groundhog_cache_file_header* groundhog_cache_file_header_get()
{
	if (!is_valid(groundhog_cache_file_global_loaded_state))
	{
		return nullptr;
	}

	groundhog::s_groundhog_cache_file_header& cache_file_header = *reinterpret_cast<groundhog::s_groundhog_cache_file_header*>(&groundhog_cache_file_global_loaded_state[0x10]);
	return &cache_file_header;
}