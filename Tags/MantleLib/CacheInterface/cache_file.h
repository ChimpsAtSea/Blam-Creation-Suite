#pragma once

class VirtualMemoryContainer;

using SectionCache = std::pair<char*, size_t>;

class c_cache_file
{
public:
	friend class c_tag_interface;
	friend class c_tag_group_interface_legacy;

	c_cache_file(const std::wstring& map_filepath);
	~c_cache_file();

	void save_map();

	bool is_loading() const { return is_map_loading; }
	// uint64_t GetVirtualAddressSpace(bool ignore_loading_check = false) const { return (!ignore_loading_check && IsLoading()) ? 0 : m_pHeader->virtual_base_address; }
	uint64_t get_base_virtual_address(bool ignore_loading_check = false) const { return cache_file_header ? cache_file_header->virtual_base_address : 0; }
	uint64_t convert_page_offset(uint32_t page_offset, bool ignore_loading_check = false) const
	{
		if (ignore_loading_check) DEBUG_ASSERT(cache_file_header);
		
		if (cache_file_header)
		{
			if (cache_file_header->unknown_bits & _unknown_bits_use_absolute_addressing) // #TODO: Actually detect version
			{
				return (static_cast<uint64_t>(page_offset) * 4ull) - (get_base_virtual_address(ignore_loading_check) - 0x10000000ull);
			}
			else
			{
				return (static_cast<uint64_t>(page_offset) * 4ull) - (get_base_virtual_address(ignore_loading_check) - 0x50000000ull);
			}
		}
		else return 0;

		//if (!ignore_loading_check && IsLoading()) return 0;
		//else return (static_cast<uint64_t>(page_offset) * 4ull) - (GetVirtualAddressSpace(ignore_loading_check) - 0x50000000ull);
	}
	inline SectionCache& get_section(e_cache_file_section cache_file_section) { return section_cache[underlying_cast(cache_file_section)]; };
	inline SectionCache& get_debug_section() { return get_section(e_cache_file_section::_cache_file_section_debug); };
	inline SectionCache& get_tags_section() { return get_section(e_cache_file_section::_cache_file_section_tags); };
	inline SectionCache& get_resources_section() { return get_section(e_cache_file_section::_cache_file_section_resource); };
	inline SectionCache& get_localization_section() { return get_section(e_cache_file_section::_cache_file_section_localization); };
	inline size_t get_tag_count() const { return is_loading() ? 0 : tag_interfaces.size(); }
	inline c_tag_interface* get_tag_interface(uint16_t index, bool ignore_loading_check = false) const { return ((!ignore_loading_check && is_loading()) || index == 0xFFFFui16) ? nullptr : tag_interfaces[index]; }
	inline const std::vector<c_tag_interface*>& get_tag_interfaces(bool ignore_loading_check = false) const
	{
		if (!ignore_loading_check && is_loading())
		{
			static std::vector<c_tag_interface*> s_empty_vector;
			return s_empty_vector;
		}
		return tag_interfaces;
	}
	inline const std::vector<c_tag_interface*>& get_tag_interfaces_sorted_by_name_with_group_id(bool ignore_loading_check = false) const
	{
		if (!ignore_loading_check && is_loading())
		{
			static std::vector<c_tag_interface*> s_empty_vector;
			return s_empty_vector;
		}
		return tag_interfaces_sorted_by_name_with_group_id;
	}
	inline const std::vector<c_tag_interface*>& get_tag_interfaces_sorted_by_path_with_group_id(bool ignore_loading_check = false) const
	{
		if (!ignore_loading_check && is_loading())
		{
			static std::vector<c_tag_interface*> s_empty_vector;
			return s_empty_vector;
		}
		return tag_interfaces_sorted_by_path_with_group_id;
	}

	inline const std::vector<c_tag_group_interface_legacy*> get_group_interfaces(bool ignore_loading_check = false) const
	{
		if (!ignore_loading_check && is_loading())
		{
			static std::vector<c_tag_group_interface_legacy*> s_empty_vector;
			return s_empty_vector;
		}
		return m_groupInterfaces;
	}
	inline c_tag_group_interface_legacy* get_group_interface_by_group_id(unsigned long tag_group)
	{
		if (tag_group != blofeld::INVALID_TAG)
		{
			for (c_tag_group_interface_legacy* group_interface : get_group_interfaces())
			{
				if (group_interface->tag_group == tag_group)
				{
					return group_interface;
				}
			}
		}
		return nullptr;
	}

	template<typename T>
	inline T* get_tag_block_data(c_typed_tag_block<T>& tag_block)
	{
		return reinterpret_cast<T*>(get_tag_block_data_impl(tag_block));
	}

	inline char* get_tag_data(s_tag_data& tag_data)
	{
		return get_tag_data_impl(tag_data);
	}

	inline const wchar_t* GetFilePath() const { return map_filepath.c_str(); }
	inline const wchar_t* GetFileName() const { return map_path.c_str(); }
	inline const char* GetFilePathChar() const { return map_filepath_utf8.c_str(); }
	inline const char* GetFileNameChar() const { return map_path_utf8.c_str(); }

	inline const char* get_string_id_by_raw_index(uint32_t index)
	{
		const char* string_id_str = string_id_buffer + string_id_indices[index];
		return string_id_str;
	}

	inline const char* string_id_to_cstr(string_id const id, const char* const error_value = nullptr)
	{
		uint32_t index = string_id_guesstimator->string_id_to_index(id);

		if (index < cache_file_header->string_id_count)
		{
			const char* string = string_id_buffer + string_id_indices[index];
			return string;
		}
		return error_value;
	}

//private:

	inline char* get_tag_block_data_impl(s_tag_block& tag_block)
	{
		const SectionCache& section_info = get_section(e_cache_file_section::_cache_file_section_tags);
		char* tags_section_data = section_info.first;

		uint64_t data_offset = convert_page_offset(tag_block.address, true);
		char* data_reference_data_pointer = tags_section_data + data_offset;

		return data_reference_data_pointer;
	}

	inline char* get_tag_data_impl(s_tag_data& tag_data)
	{
		const SectionCache& section_info = get_section(e_cache_file_section::_cache_file_section_tags);
		char* tags_section_data = section_info.first;

		uint64_t data_offset = convert_page_offset(tag_data.address, true);
		char* data_reference_data_pointer = tags_section_data + data_offset;

		return data_reference_data_pointer;
	}

	void load_map(const std::wstring& map_filepath);

	/* initialize each group instance */
	void init_group_instances();
	/* initialize each tag instance */
	void init_tag_instances();
	void init_sorted_instance_lists();
	volatile bool is_map_loading;
	std::wstring map_filepath;
	std::wstring map_path;
	std::string map_filepath_utf8;
	std::string map_path_utf8;
	VirtualMemoryContainer& virtual_memory_container;

	e_engine_type engine_type;

	// raw data
	long* tag_name_indices;
	char* tag_name_buffer;
	long *string_id_indices;
	char *string_id_buffer;
	s_reach_cache_file_header* cache_file_header;
	s_cache_file_tags_header* cache_file_tags_headers;
	s_cache_file_tag_instance* cache_file_tag_instances;
	s_cache_file_tag_group* cache_file_tag_groups;

	c_cache_file_string_id_guesstimator* string_id_guesstimator;

	// interface types
	SectionCache section_cache[underlying_cast(e_cache_file_section::k_number_of_cache_file_sections)];
	std::vector<c_tag_interface*> tag_interfaces;
	std::vector<c_tag_interface*> tag_interfaces_sorted_by_name_with_group_id;
	std::vector<c_tag_interface*> tag_interfaces_sorted_by_path_with_group_id;
	std::vector<c_tag_group_interface_legacy*> m_groupInterfaces;
};

