#pragma once

struct s_section_cache
{
	long mask;
	long offset;
	long size;
	char* masked_data;
	char* data;
};

class c_gen3_cache_file_validator;
class c_string_id_guesstimator;
class c_string_id_namespace_list;
class c_resource_entry;

class c_gen3_cache_file :
	public c_cache_file
{
	friend c_cache_file;
	friend c_string_id_interface;
	friend c_string_id_guesstimator;
	friend c_string_id_namespace_list;
protected:
	gen3::s_cache_file_header* read_cache_file();
	void init_gen3_cache_file();
	c_gen3_cache_file(const std::wstring& map_filepath, e_engine_type engine_type, e_platform_type platform_type);
	virtual ~c_gen3_cache_file();

public:
	virtual bool is_loading() const final;
	virtual uint32_t get_tag_count() const final;
	virtual uint32_t get_tag_group_count() const final;
	virtual uint32_t get_string_id_count() const = 0;
	virtual char* get_data_with_page_offset(uint32_t page_offset) const;
	virtual bool is_valid_data_address(void* data) const;
	virtual char* get_tag_data(s_tag_data& tag_data) const final;
	virtual char* get_tag_block_data(const s_tag_block& tag_block) const final;
	virtual char* get_tag_interop_data(const s_tag_interop& tag_interop) const final;
	virtual const char* get_string_id_by_index(uint32_t index) const final;
	virtual const char* get_string_id(string_id const id, const char* const error_value = nullptr) const final;
	virtual const char* get_tag_path(uint32_t tag_index) const final;
	virtual unsigned long get_group_tag_by_tag_index(uint32_t tag_index) const final;
	virtual void get_raw_tag_memory_region(uint32_t tag_index, size_t& out_size, char*& tag_data) const;
	virtual void validate();

	virtual const s_section_cache& get_section(uint32_t section_index) const final;
	inline const s_section_cache& get_debug_section() const { return get_section(gen3::_cache_file_section_index_debug); };
	inline const s_section_cache& get_tags_section() const { return get_section(gen3::_cache_file_section_index_tags); };
	inline const s_section_cache& get_resources_section() const { return get_section(gen3::_cache_file_section_index_resource); };
	inline const s_section_cache& get_localization_section() const { return get_section(gen3::_cache_file_section_index_localization); };
	inline char* get_tags_buffer() const { return tags_buffer; }
	inline c_gen3_cache_file_validator& get_cache_file_validator() const { return *validator; }

	inline gen3::s_cache_file_tag_instance& get_internal_tag_instance(uint32_t tag_index) const 
	{ 
		gen3::s_cache_file_tag_instance* tag_instance = reinterpret_cast<gen3::s_cache_file_tag_instance*>(get_internal_tag_instance_impl(tag_index));
		DEBUG_ASSERT(tag_instance != nullptr);
		return *tag_instance;
	};
	inline gen3::s_cache_file_tag_group* get_internal_tag_group(uint32_t group_index) const
	{
		gen3::s_cache_file_tag_group* tag_group = reinterpret_cast<gen3::s_cache_file_tag_group*>(get_internal_tag_group_impl(group_index));
		return tag_group;
	};

	template<typename t_cache_file_header>
	inline void init_section_cache(t_cache_file_header& cache_file_header)
	{
		char* map_data = get_map_data();

		for (underlying(gen3::e_cache_file_section_index) cache_file_section_index = 0; cache_file_section_index < underlying_cast(gen3::k_number_of_cache_file_sections); cache_file_section_index++)
		{
			gen3::e_cache_file_section_index cache_file_section = static_cast<gen3::e_cache_file_section_index>(cache_file_section_index);

			long mask = cache_file_header.section_table.offset_masks[cache_file_section_index];
			long offset = cache_file_header.section_table.sections[cache_file_section_index].offset;
			long size = cache_file_header.section_table.sections[cache_file_section_index].size;

			char* masked_data = reinterpret_cast<char*>(map_data + mask);
			char* data = masked_data + offset;

			section_cache[cache_file_section_index].mask = mask;
			section_cache[cache_file_section_index].offset = offset;
			section_cache[cache_file_section_index].size = size;
			section_cache[cache_file_section_index].masked_data = masked_data;
			section_cache[cache_file_section_index].data = data;
		}
	}

	gen3::s_cache_file_tag_interop* gen3_cache_file_tag_interops;
	long tag_interop_count;
	c_resource_entry** resource_entries;
	uint32_t resource_entries_count;

	c_resource_entry* get_resource_entry(uint32_t index) const;

	template<typename T>
	T* get_resource_entry(uint32_t index) const
	{
		return dynamic_cast<T*>(get_resource_entry(index));
	}

protected:
	virtual void* get_internal_tag_instance_impl(uint32_t tag_index) const final;
	virtual void* get_internal_tag_group_impl(uint32_t group_index) const final;

	blamlib::s_cache_file_header& cache_file_header;
	gen3::s_cache_file_tag_group* gen3_cache_file_tag_groups;
	gen3::s_cache_file_tag_instance* gen3_cache_file_tag_instances;
	char* string_ids_buffer;
	long* string_id_indices;
	long* string_id_namespace_indices;
	long string_id_namespace_count;
	char* filenames_buffer;
	long* filename_indices;
	char* tags_buffer;
	s_section_cache section_cache[underlying_cast(gen3::k_number_of_cache_file_sections)];
	c_string_id_interface* string_id_interface;
	c_gen3_cache_file_validator* validator;
};

