#pragma once

class c_infinite_tag_reader;
class c_infinite_tag_group;
class c_infinite_ucs_reader;

class c_infinite_tag_instance : public c_tag_instance
{
public:
	friend class c_infinite_tag_reader;

	c_infinite_tag_instance(
		c_cache_cluster& cache_cluster,
		c_infinite_tag_group& tag_group,
		const char* instance_name,
		const void* instance_data,
		const void** instance_block_data,
		const infinite::s_module_file_entry* file_entry
	);
	~c_infinite_tag_instance();

	c_infinite_ucs_reader* ucs_reader;
	const infinite::s_module_file_entry* file_entry;

	virtual BCS_RESULT get_data(const void*& tag_instance_data) const override;
	virtual BCS_RESULT get_instance_name(const char*& tag_instance_name) const override;
	BCS_RESULT get_tag_group(c_infinite_tag_group*& tag_group) const;
	virtual BCS_RESULT get_tag_group(c_tag_group*& tag_group) const override;
	virtual BCS_RESULT get_cache_file_tag_index(unsigned long& cache_file_tag_index) const override;

private:
	c_cache_cluster& cache_cluster;
	c_infinite_tag_group& tag_group;
	const char* const instance_name;
	const void* const instance_data;
	const void** const instance_block_data;
};

