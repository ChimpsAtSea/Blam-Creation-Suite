#pragma once

class c_eldorado_tag_reader;
class c_eldorado_tag_group;

class c_eldorado_tag_instance : public c_tag_instance
{
public:
	friend class c_eldorado_tag_reader;

	c_eldorado_tag_instance(
		c_eldorado_cache_cluster& cache_cluster,
		c_eldorado_tag_reader& tag_reader,
		c_eldorado_tag_group& tag_group,
		uint32_t cache_file_tag_index,
		const char* instance_name,
		const blofeld::eldorado::s_cache_file_tag_instance& tag_header,
		const void* tag_data_start,
		const void* tag_data_end
	);
	~c_eldorado_tag_instance();


	virtual BCS_RESULT get_tag_data(const void*& tag_data_root, const void*& tag_data_start, const void*& tag_data_end) const override;
	virtual BCS_RESULT get_instance_name(const char*& tag_instance_name) const override;
	BCS_RESULT get_tag_group(c_eldorado_tag_group*& tag_group) const;
	virtual BCS_RESULT get_tag_group(c_tag_group*& tag_group) const override;
	virtual BCS_RESULT get_cache_file_tag_index(uint32_t& cache_file_tag_index) const override;
	virtual BCS_RESULT get_tag_file_reader(c_tag_reader*& tag_reader) const override;

private:
	c_cache_cluster& cache_cluster;
	c_eldorado_tag_reader& tag_reader;
	c_eldorado_tag_group& tag_group;
	blofeld::eldorado::s_cache_file_tag_instance tag_header;
	uint32_t const cache_file_tag_index;
	const char* const instance_name;
	const void* const tag_data_start;
	const void* const tag_data_end;
};

