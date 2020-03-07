#pragma once

class VirtualMemoryContainer;

using SectionCache = std::pair<char*, size_t>;

class c_cache_file
{
public:
	friend class c_tag_interface;
	friend class c_tag_group_interface;

	c_cache_file(const std::wstring& mapFilePath);
	~c_cache_file();

	void save_map();

	bool is_loading() const { return m_isMapLoading; }
	// uint64_t GetVirtualAddressSpace(bool ignoreLoadingCheck = false) const { return (!ignoreLoadingCheck && IsLoading()) ? 0 : m_pHeader->virtual_base_address; }
	uint64_t get_base_virtual_address(bool ignoreLoadingCheck = false) const { return cache_file_header ? cache_file_header->virtual_base_address : 0; }
	uint64_t convert_page_offset(uint32_t pageOffset, bool ignoreLoadingCheck = false) const
	{
		if (ignoreLoadingCheck) DEBUG_ASSERT(cache_file_header);
		
		if (cache_file_header)
		{
			return (static_cast<uint64_t>(pageOffset) * 4ull) - (get_base_virtual_address(ignoreLoadingCheck) - 0x50000000ull);
		}
		else return 0;

		//if (!ignoreLoadingCheck && IsLoading()) return 0;
		//else return (static_cast<uint64_t>(pageOffset) * 4ull) - (GetVirtualAddressSpace(ignoreLoadingCheck) - 0x50000000ull);
	}
	inline SectionCache& get_section(e_cache_file_section cache_file_section) { return m_pSectionCache[underlying_cast(cache_file_section)]; };
	inline SectionCache& get_debug_section() { return get_section(e_cache_file_section::_cache_file_section_debug); };
	inline SectionCache& get_tags_section() { return get_section(e_cache_file_section::_cache_file_section_tags); };
	inline SectionCache& get_resources_section() { return get_section(e_cache_file_section::_cache_file_section_resource); };
	inline SectionCache& get_localization_section() { return get_section(e_cache_file_section::_cache_file_section_localization); };
	inline size_t get_tag_count() const { return is_loading() ? 0 : tag_interfaces.size(); }
	inline c_tag_interface* get_tag_interface(uint16_t index, bool ignoreLoadingCheck = false) const { return ((!ignoreLoadingCheck && is_loading()) || index == 0xFFFFui16) ? nullptr : tag_interfaces[index]; }
	inline const std::vector<c_tag_interface*>& get_tag_interfaces(bool ignoreLoadingCheck = false) const
	{
		if (!ignoreLoadingCheck && is_loading())
		{
			static std::vector<c_tag_interface*> sEmptyVector;
			return sEmptyVector;
		}
		return tag_interfaces;
	}
	inline const std::vector<c_tag_interface*>& get_tag_interfaces_sorted_by_name_with_group_id(bool ignoreLoadingCheck = false) const
	{
		if (!ignoreLoadingCheck && is_loading())
		{
			static std::vector<c_tag_interface*> sEmptyVector;
			return sEmptyVector;
		}
		return tag_interfaces_sorted_by_name_with_group_id;
	}
	inline const std::vector<c_tag_interface*>& get_tag_interfaces_sorted_by_path_with_group_id(bool ignoreLoadingCheck = false) const
	{
		if (!ignoreLoadingCheck && is_loading())
		{
			static std::vector<c_tag_interface*> sEmptyVector;
			return sEmptyVector;
		}
		return tag_interfaces_sorted_by_path_with_group_id;
	}

	inline const std::vector<c_tag_group_interface*> get_group_interfaces(bool ignoreLoadingCheck = false) const
	{
		if (!ignoreLoadingCheck && is_loading())
		{
			static std::vector<c_tag_group_interface*> sEmptyVector;
			return sEmptyVector;
		}
		return m_groupInterfaces;
	}
	inline c_tag_group_interface* get_group_interface_by_group_id(e_tag_group groupName)
	{
		if (groupName != _tag_group_invalid)
		{
			for (c_tag_group_interface* pGroupInterface : get_group_interfaces())
			{
				if (pGroupInterface->group_magic == underlying_cast(groupName))
				{
					return pGroupInterface;
				}
			}
		}
		return nullptr;
	}
	
	template<typename R, typename T>
	inline R* GetTagBlockData(s_tag_block_definition<T>& rTagBlock)
	{
		return reinterpret_cast<R*>(getTagBlockDataInternal(*reinterpret_cast<s_tag_block_definition<>*>(&rTagBlock)));
	}

	template<typename T>
	inline T* GetTagBlockData(s_tag_block_definition<T>& rTagBlock)
	{
		return reinterpret_cast<T*>(getTagBlockDataInternal(*reinterpret_cast<s_tag_block_definition<>*>(&rTagBlock)));
	}

	inline char* GetDataReferenceData(DataReference& data_reference)
	{
		return getDataReferenceDataInternal(data_reference);
	}

	inline const wchar_t* GetFilePath() const { return m_mapFilePath.c_str(); }
	inline const wchar_t* GetFileName() const { return m_mapFileName.c_str(); }
	inline const char* GetFilePathChar() const { return m_mapFilePathChar.c_str(); }
	inline const char* GetFileNameChar() const { return m_mapFileNameChar.c_str(); }

	inline const char* string_id_to_cstr(const string_id& string_id)
	{
		return string_id_to_cstr(string_id.stringid);
	}

	inline const char* string_id_to_cstr(uint32_t id)
	{
		uint32_t const k_string_id_set_string_counts[17] = { 1225, 1637, 217, 106, 217, 38, 5, 1727, 368, 20, 98, 24, 0, 13, 41, 97, 115 };

		uint32_t set = (id >> _countof(k_string_id_set_string_counts)) & 0xFF;
		uint32_t index = id & ((1 << _countof(k_string_id_set_string_counts)) - 1);

		uint32_t set_base_index = 0;

		if (set == 0 && index >= k_string_id_set_string_counts[set])
		{
			for (int i = 0; i < _countof(k_string_id_set_string_counts); i++)
				set_base_index += k_string_id_set_string_counts[i];

			index -= k_string_id_set_string_counts[set];
		}
		else
		{
			for (uint32_t i = 0; i < set; i++)
				set_base_index += k_string_id_set_string_counts[i];
		}

		return m_pStringIDBuffer + m_pStringIDIndices[set_base_index + index];
	}

//private:

	inline char* getTagBlockDataInternal(s_tag_block_definition<>& tag_block)
	{
		const SectionCache& section_info = get_section(e_cache_file_section::_cache_file_section_tags);
		char* tags_section_data = section_info.first;

		uint64_t data_offset = convert_page_offset(tag_block.address, true);
		char* data_reference_data_pointer = tags_section_data + data_offset;

		return data_reference_data_pointer;
	}

	inline char* getDataReferenceDataInternal(DataReference& data_reference)
	{
		const SectionCache& section_info = get_section(e_cache_file_section::_cache_file_section_tags);
		char* tags_section_data = section_info.first;

		uint64_t data_offset = convert_page_offset(data_reference.address, true);
		char* data_reference_data_pointer = tags_section_data + data_offset;

		return data_reference_data_pointer;
	}

	void loadMap(const std::wstring& mapFilePath);

	/* initialize each group instance */
	void initGroupInstances();
	/* initialize each tag instance */
	void initTagInstances();
	void initSortedInstanceLists();
	volatile bool m_isMapLoading;
	std::wstring m_mapFilePath;
	std::wstring m_mapFileName;
	std::string m_mapFilePathChar;
	std::string m_mapFileNameChar;
	VirtualMemoryContainer& m_rVirtualMemoryContainer;

	// raw data
	long* m_pTagNameIndices;
	char* m_pTagNameBuffer;
	long *m_pStringIDIndices;
	char *m_pStringIDBuffer;
	s_cache_file_header* cache_file_header;
	s_cache_file_tags_header* cache_file_tags_headers;
	s_cache_file_tag_instance* cache_file_tag_instances;
	s_cache_file_tag_group* cache_file_tag_groups;

	// interface types
	SectionCache m_pSectionCache[underlying_cast(e_cache_file_section::k_number_of_cache_file_sections)];
	std::vector<c_tag_interface*> tag_interfaces;
	std::vector<c_tag_interface*> tag_interfaces_sorted_by_name_with_group_id;
	std::vector<c_tag_interface*> tag_interfaces_sorted_by_path_with_group_id;
	std::vector<c_tag_group_interface*> m_groupInterfaces;
};

