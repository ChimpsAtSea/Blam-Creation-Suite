#pragma once
class c_groundhog_cache_file :
	public c_cache_file
{
	friend c_cache_file;
protected:
	c_groundhog_cache_file(const std::wstring& map_filepath);
	virtual ~c_groundhog_cache_file();

public:
	virtual bool save_map() final;
	virtual bool is_loading() const final;
	virtual uint64_t get_base_virtual_address() const final;
	virtual uint64_t convert_page_offset(uint32_t page_offset) const final;
	virtual uint32_t get_tag_count() const final;
	virtual uint32_t get_tag_group_count() const final;
	virtual uint32_t get_string_id_count() const final;
	virtual c_tag_interface* get_tag_interface(uint16_t tag_index) const final;
	virtual c_tag_group_interface* get_tag_group_interface(uint16_t group_index) const final;
	virtual c_tag_group_interface* get_tag_group_interface_by_group_id(unsigned long tag_group) const final;
	virtual c_tag_group_interface* const* get_tag_group_interfaces() const final;
	virtual char* get_tag_data(s_tag_data& tag_data) const final;
	virtual char* get_tag_block_data(s_tag_block& tag_block) const final;
	virtual const char* get_string_id_by_index(uint32_t index) const final;
	virtual const char* get_string_id(string_id const id, const char* const error_value = nullptr) const final;
	virtual const char* get_tag_path(uint16_t tag_index) const final;
	virtual unsigned long get_group_tag_by_tag_index(uint32_t tag_index) const final;
	virtual void get_raw_tag_memory_region(uint32_t tag_index, size_t& out_size, char*& tag_data) const final;

	virtual const s_section_cache* get_section(uint32_t section_index) const final;
	const s_section_cache& get_section(e_haloreach_cache_file_section_index cache_file_section) const;
	inline const s_section_cache& get_debug_section() const { return get_section(_haloreach_cache_file_section_index_debug); };
	inline const s_section_cache& get_tags_section() const { return get_section(_haloreach_cache_file_section_index_tags); };
	inline const s_section_cache& get_resources_section() const { return get_section(_haloreach_cache_file_section_index_resource); };
	inline const s_section_cache& get_localization_section() const { return get_section(_haloreach_cache_file_section_index_localization); };

	inline s_cache_file_tag_instance* get_internal_tag_instance(uint16_t tag_index) const
	{
		return static_cast<s_cache_file_tag_instance*>(get_internal_tag_instance_impl(tag_index));
	}
	inline s_cache_file_tag_group* get_internal_tag_group(uint32_t group_index) const
	{
		return static_cast<s_cache_file_tag_group*>(get_internal_tag_group_impl(group_index));
	}

protected:
	virtual void* get_internal_tag_instance_impl(uint16_t tag_index) const final;
	virtual void* get_internal_tag_group_impl(uint32_t group_index) const final;
};

