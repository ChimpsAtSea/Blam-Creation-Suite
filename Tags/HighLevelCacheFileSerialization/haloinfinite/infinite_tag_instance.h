#pragma once

class c_infinite_tag_reader;
class c_infinite_tag_group;
class c_infinite_ucs_reader;
class c_infinite_high_level_moule_file_transplant;

class c_infinite_tag_instance : 
	public c_tag_instance
{
public:
	friend class c_infinite_high_level_moule_file_transplant;
	friend class c_infinite_tag_reader;

	c_infinite_tag_instance(
		c_cache_cluster& cache_cluster,
		c_infinite_tag_group& tag_group,
		const char* instance_name,
		c_infinite_file_entry_block_map& file_entry_block_map
	);
	~c_infinite_tag_instance();

	

	virtual BCS_RESULT get_global_tag_id(int32_t& global_tag_id) const;
	virtual BCS_RESULT map_data() override;
	virtual BCS_RESULT unmap_data() override;
	virtual BCS_RESULT get_ucs_reader(c_infinite_ucs_reader*& ucs_reader) const;
	virtual BCS_RESULT get_header_data(const void*& header_data, uint32_t& header_data_size) const;
	virtual BCS_RESULT get_tag_data(const void*& tag_data_root, const void*& tag_data_start, const void*& tag_data_end) const override;
	virtual BCS_RESULT get_resource_data(const void*& resource_data, uint32_t& resource_data_size) const;
	virtual BCS_RESULT get_unknown_data(const void*& unknown_data, uint32_t& unknown_data_size) const;
	virtual BCS_RESULT get_instance_name(const char*& tag_instance_name) const override;
	BCS_RESULT get_tag_group(c_infinite_tag_group*& tag_group) const;
	virtual BCS_RESULT get_tag_group(c_tag_group*& tag_group) const override;
	virtual BCS_RESULT get_cache_file_tag_index(uint32_t& cache_file_tag_index) const override;

private:
	c_cache_cluster& cache_cluster;
	c_infinite_tag_group& tag_group;
	const char* const instance_name;
	c_infinite_file_entry_block_map& file_entry_block_map;
	c_infinite_ucs_reader* ucs_reader;
	void* mapped_data;
	const char* header_data;
	const char* tag_data;
	const char* resource_data;
	const char* unknown_data;
};

