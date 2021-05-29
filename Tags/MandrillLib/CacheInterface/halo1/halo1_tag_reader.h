#pragma once

class c_halo1_cache_cluster;
class c_halo1_cache_file_reader;
class c_high_level_cache_cluster_transplant;

struct s_halo1_tag_instance_info
{
	halo1::s_cache_file_tag_instance instance;
	long index;
	const char* instance_name;
	const void* instance_data;
	const blofeld::s_tag_group* tag_group;
};

class c_halo1_tag_reader : public c_tag_reader
{
public:
	friend c_halo1_cache_cluster;
	friend c_halo1_cache_file_reader;
	friend c_high_level_cache_cluster_transplant;
	c_halo1_tag_reader(c_halo1_cache_cluster& cache_cluster, c_halo1_cache_file_reader& cache_reader);
	~c_halo1_tag_reader();

	BCS_RESULT get_instance_info(unsigned long tag_index, const s_halo1_tag_instance_info*& instance_info);
	BCS_RESULT page_offset_to_pointer(long page_offset, const void*& data);

	c_halo1_cache_cluster& cache_cluster;
	c_halo1_cache_file_reader& cache_reader;

	unsigned long group_count;
	const blofeld::s_tag_group** groups;
	unsigned long instance_count;
	s_halo1_tag_instance_info* instances;

private:
};
