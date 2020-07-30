
uintptr_t halo3_tag_instances_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180CC9970);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x180CD8080);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x180CB3700);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x180CB3700);
	return ~uintptr_t();
}
gen3::s_cache_file_tag_instance*& halo3_tag_instances = reference_symbol<gen3::s_cache_file_tag_instance*>("halo3_tag_instances", halo3_tag_instances_offset);

// Props to Camden for the name
uintptr_t k_virtual_to_physical_base_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180D15118);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x180D23838);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x180CFEEB8);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x180CFEEB8);
	return ~uintptr_t();
}
const long long& k_virtual_to_physical_base = reference_symbol<const long long>("k_virtual_to_physical_base", k_virtual_to_physical_base_offset);

uintptr_t k_physical_base_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1808842E8);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x180892418);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18087B418);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18087B418);
	return ~uintptr_t();
}
const long long& k_physical_base = reference_symbol<const long long>("k_physical_base", k_physical_base_offset);

uintptr_t halo3_cache_file_header_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180CC9998);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x180CD80A8);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x180CB3728);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x180CB3728);
	return ~uintptr_t();
}
halo3::s_cache_file_header& halo3_cache_file_header = reference_symbol<halo3::s_cache_file_header>("halo3_cache_file_header", halo3_cache_file_header_offset);

uintptr_t halo3_cache_file_tags_header_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180CCC998);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x180CDB0A8);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x180CB6728);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x180CB6728);
	return ~uintptr_t();
}
halo3::s_cache_file_tags_header*& halo3_cache_file_tags_header = reference_symbol<halo3::s_cache_file_tags_header*>("halo3_cache_file_tags_header", halo3_cache_file_tags_header_offset);

// Props to Camden for this address in build 1.1698.0.0
uintptr_t null_tag_definition_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x18072FF00);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x18073CE50);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18073B960);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18073B960);
	return ~uintptr_t();
}
char& null_tag_definition = reference_symbol<char>("null_tag_definition", null_tag_definition_offset);

uintptr_t file_table_mapping_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180CC9978);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x180CD8088);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x180CB3708);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x180CB3708);
	return ~uintptr_t();
}
void*& file_table_mapping = reference_symbol<void*>("file_table_mapping", file_table_mapping_offset);

halo3::s_cache_file_header* halo3_cache_file_header_get()
{
	if (!is_valid(halo3_cache_file_header))
	{
		return nullptr;
	}

	halo3::s_cache_file_header& cache_file_header = halo3_cache_file_header;
	return &cache_file_header;
}

halo3::s_cache_file_tags_header* halo3_cache_file_tags_header_get()
{
	if (!is_valid(halo3_cache_file_tags_header) || !halo3_cache_file_tags_header)
	{
		return nullptr;
	}

	halo3::s_cache_file_tags_header* cache_file_tags_header = halo3_cache_file_tags_header;
	return cache_file_tags_header;
}

const char* halo3_tag_name_get(unsigned long tag_index)
{
	unsigned long file_count = halo3_cache_file_header_get()->file_count;
	if (!is_valid(file_table_mapping) || !file_table_mapping || (tag_index < 0 && tag_index > file_count))
	{
		return nullptr;
	}

	const char* file_path = (const char*)file_table_mapping + *((long*)file_table_mapping + tag_index) + 0x14000;
	return file_path;
}

unsigned long halo3_tag_index_by_name_get(const char* tag_name)
{
	unsigned long tag_index = 0;
	unsigned long file_count = halo3_cache_file_header_get()->file_count;
	for (; tag_index < file_count; tag_index++)
	{
		const char* file_path = halo3_tag_name_get(tag_index);
		if (strcmp(file_path, tag_name) == 0)
		{
			break;
		}
	}

	return tag_index;
}

char* halo3_tag_address_get(uint32_t tag_instance_address)
{
	if (!is_valid(k_virtual_to_physical_base) || !tag_instance_address)
	{
		return nullptr;
	}

	// Props to Camden for this snippet
	char* data = tag_instance_address == -1 ? &null_tag_definition : reinterpret_cast<char*>(k_virtual_to_physical_base + ((unsigned long long)tag_instance_address * 4));
	return data;
}

char* halo3_tag_definition_get(uint32_t index)
{
	if (!is_valid(halo3_tag_instances) || !halo3_tag_instances)
	{
		return nullptr;
	}

	gen3::s_cache_file_tag_instance& tag_instance = halo3_tag_instances[index];
	return halo3_tag_address_get(tag_instance.address);
}

template<typename T>
T& halo3_tag_definition_get(uint32_t index)
{
	return *reinterpret_cast<T*>(halo3_tag_definition_get(index));
}

char* halo3_tag_definition_get(unsigned long group_tag, const char* tag_name)
{
	if (!is_valid(halo3_tag_instances) || !halo3_tag_instances || !is_valid(halo3_cache_file_tags_header) || !halo3_cache_file_tags_header)
	{
		return nullptr;
	}

	unsigned long tag_index = halo3_tag_index_by_name_get(tag_name);
	gen3::s_cache_file_tag_instance& tag_instance = halo3_tag_instances[tag_index];

	unsigned long(&group_tags)[3] = reinterpret_cast<gen3::s_cache_file_tag_group*>(halo3_cache_file_tags_header->tag_groups.address)[tag_instance.group_index].group_tags;
	if (group_tags[0] != group_tag)
	{
		return nullptr;
	}

	return halo3_tag_address_get(tag_instance.address);
}

template<typename T>
T& halo3_tag_definition_get(unsigned long group, const char* tag_name)
{
	return *reinterpret_cast<T*>(halo3_tag_definition_get(group, tag_name));
}