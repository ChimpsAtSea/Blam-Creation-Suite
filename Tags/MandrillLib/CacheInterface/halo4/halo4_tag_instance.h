#pragma once

class c_halo4_tag_reader;
class c_halo4_tag_group;

class c_halo4_tag_instance : public c_tag_instance
{
public:
	friend class c_halo4_tag_reader;

	c_halo4_tag_instance(
		c_cache_cluster& cache_cluster,
		c_halo4_tag_group& tag_group,
		unsigned long cache_file_tag_index,
		const char* instance_name,
		const void* instance_data
	);
	~c_halo4_tag_instance();


	virtual BCS_RESULT get_data(const void*& tag_instance_data) const override;
	virtual BCS_RESULT get_instance_name(const char*& tag_instance_name) const override;
	BCS_RESULT get_tag_group(c_halo4_tag_group*& tag_group) const;
	virtual BCS_RESULT get_tag_group(c_tag_group*& tag_group) const override;
	virtual BCS_RESULT get_cache_file_tag_index(unsigned long& cache_file_tag_index) const override;

private:
	c_cache_cluster& cache_cluster;
	c_halo4_tag_group& tag_group;
	unsigned long const cache_file_tag_index;
	const char* const instance_name;
	const void* const instance_data;
};

