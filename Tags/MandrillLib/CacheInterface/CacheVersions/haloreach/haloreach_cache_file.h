#pragma once

class c_cache_cluster;

class c_haloreach_cache_file :
	public c_gen3_cache_file
{
	friend c_cache_file;
protected:
	c_haloreach_cache_file(const std::wstring& map_filepath, c_cache_cluster* cluster = nullptr);
	virtual ~c_haloreach_cache_file();

public:
	static constexpr uint32_t page_address_offset_relative = 0x50000000ull;
	static constexpr uint32_t page_address_offset_absolute = 0x10000000ull;
	virtual bool save_map() final;
	virtual uint64_t get_base_virtual_address() const final;
	virtual uint64_t convert_page_offset(uint32_t page_offset) const final;
	virtual void get_raw_tag_memory_region(uint32_t tag_index, size_t& out_size, char*& tag_data) const final;
	virtual uint32_t get_string_id_count() const final;
	virtual void set_cache_cluster(c_cache_cluster* cluster) final;
	virtual char* get_data_with_page_offset(uint32_t page_offset) const;
	virtual void init_resources();
	virtual void validate();

	c_cache_cluster* cluster;
	c_haloreach_page_file_manager* page_file_manager;

	c_cache_file* get_shared_cache_file_by_file_index(uint32_t file_index);
protected:

	gen3::e_cache_file_flags get_cache_file_flags() const;
	template<typename T> void init(T& cache_file_header);
	haloreach::s_cache_file_header* haloreach_cache_file_header;
	haloreach::s_cache_file_header_v13* haloreach_cache_file_header_v13;
	haloreach::s_cache_file_tags_header* haloreach_cache_file_tags_header;
};
