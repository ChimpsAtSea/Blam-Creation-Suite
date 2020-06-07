#pragma once

class c_virtual_memory_container;

struct s_section_cache
{
	char* data;
	size_t size;
};

class c_cache_file
{
public:

	friend class c_tag_interface;
	friend class c_tag_group_interface;

	static e_engine_type get_cache_file_engine_type(const wchar_t* filepath);
	static c_cache_file* create_cache_file(const std::wstring& map_filepath);

protected:
	c_cache_file(const std::wstring& map_filepath);
public:
	virtual ~c_cache_file();

	virtual bool save_map() = 0;
	virtual bool is_loading() const = 0;
	virtual uint64_t get_base_virtual_address() const = 0;
	virtual uint64_t convert_page_offset(uint32_t page_offset) const = 0;
	virtual const s_section_cache* get_section(uint32_t section_index) const = 0;
	virtual uint32_t get_tag_count() const = 0;
	virtual uint32_t get_tag_group_count() const = 0;
	virtual uint32_t get_string_id_count() const = 0;
	virtual c_tag_interface* get_tag_interface(uint16_t tag_index) const = 0;
	virtual c_tag_interface* const* get_tag_interfaces() const = 0;
	virtual c_tag_interface* const* get_tag_interfaces_sorted_by_name_with_group_id() const = 0;
	virtual c_tag_interface* const* get_tag_interfaces_sorted_by_path_with_group_id() const = 0;
	virtual c_tag_group_interface* get_tag_group_interface(uint16_t group_index) const = 0;
	virtual c_tag_group_interface* get_group_interface_by_group_id(unsigned long tag_group) const = 0;
	virtual c_tag_group_interface* const* get_tag_group_interfaces() const = 0;
	virtual char* get_tag_data(s_tag_data& tag_data) const = 0;
	virtual char* get_tag_block_data(s_tag_block& tag_block) const = 0;
	virtual const char* get_string_id_by_index(uint32_t index) const = 0;
	virtual const char* get_string_id(string_id const id, const char* const error_value = nullptr) const = 0;
	virtual void* get_internal_tag_instance_impl(uint16_t tag_index) const = 0;
	virtual void* get_internal_tag_group_impl(uint32_t group_index) const = 0;
	virtual unsigned long get_tag_group_by_tag_index(uint32_t tag_index) const = 0;
	virtual const char* get_tag_path(uint16_t tag_index) const = 0;

	template<typename T>
	inline T* get_tag_block_data(c_typed_tag_block<T>& tag_block)
	{
		void* data = get_tag_block_data(*reinterpret_cast<s_tag_block*>(&tag_block));
		T* typed_data = reinterpret_cast<T*>(data);
		return typed_data;
	}

	inline const wchar_t* get_map_filepath() const { return map_filepath.c_str(); }
	inline const char* get_map_filepath_utf8() const { return map_filepath_utf8.c_str(); }

	inline const wchar_t* get_map_path() const { return map_path.c_str(); }
	inline const char* get_map_path_utf8() const { return map_path_utf8.c_str(); }

protected:
	void cache_file_post_load();

	c_virtual_memory_container& virtual_memory_container;
	e_engine_type engine_type;

	// interface types
	std::vector<c_tag_interface*> tag_interfaces;
	std::vector<c_tag_interface*> tag_interfaces_sorted_by_name_with_group_id;
	std::vector<c_tag_interface*> tag_interfaces_sorted_by_path_with_group_id;
	std::vector<c_tag_group_interface*> tag_group_interfaces;

private:
	/* initialize each group instance */
	void init_group_instances();
	/* initialize each tag instance */
	void init_tag_instances();
	void init_sorted_instance_lists();

	std::wstring map_filepath;
	std::wstring map_path;
	std::string map_filepath_utf8;
	std::string map_path_utf8;
};

