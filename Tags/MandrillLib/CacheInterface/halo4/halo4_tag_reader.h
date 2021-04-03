#pragma once

class c_halo4_cache_cluster;
class c_halo4_cache_file_reader;
class c_high_level_cache_cluster_transplant;

struct s_halo4_tag_group_info
{
	halo4::xbox360::s_cache_file_tag_group group;
	const char* group_name;
};

struct s_halo4_tag_instance_info
{
	halo4::xbox360::s_cache_file_tag_instance instance;
	long index;
	const char* instance_name;
	const void* instance_data;
	s_halo4_tag_group_info* group_info;
};

struct s_halo4_tag_global_instance_info
{
	halo4::xbox360::s_cache_file_tag_global_instance global_instance;
	s_halo4_tag_instance_info* instance_info;
};

class c_halo4_tag_reader : public c_tag_reader
{
public:
	friend c_halo4_cache_cluster;
	friend c_halo4_cache_file_reader;
	friend c_high_level_cache_cluster_transplant;
	c_halo4_tag_reader(c_halo4_cache_cluster& cache_cluster, c_halo4_cache_file_reader& cache_reader);
	~c_halo4_tag_reader();

	BCS_RESULT get_global_instance_info(tag group_tag, const s_halo4_tag_global_instance_info*& global_instance_info);
	BCS_RESULT get_instance_info(unsigned long tag_index, const s_halo4_tag_instance_info*& instance_info);
	BCS_RESULT page_offset_to_pointer(long page_offset, const void*& data);

	c_halo4_cache_cluster& cache_cluster;
	c_halo4_cache_file_reader& cache_reader;

	unsigned long group_count;
	s_halo4_tag_group_info* groups;
	unsigned long instance_count;
	s_halo4_tag_instance_info* instances;
	unsigned long global_instance_count;
	s_halo4_tag_global_instance_info* global_instances;
	unsigned long interop_count;
	halo4::xbox360::s_cache_file_tag_interop* interops;

private:
	BCS_RESULT init_interop_table();
	BCS_RESULT init_interops();
	BCS_RESULT interop_type_index_to_halo4_interop_type(long type_index, e_halo4_interop_type& interop_type);

	BCS_RESULT init_resource_table();
	BCS_RESULT init_resources();
	BCS_RESULT export_resources();
	BCS_RESULT resource_type_index_to_halo4_resource_type(long type_index, e_halo4_resource_type& resource_type);

	BCS_RESULT init_shared_files_table();
	BCS_RESULT shared_file_index_to_cache_file_reader(long shared_file_index, c_halo4_cache_file_reader*& cache_file_reader);

	BCS_RESULT get_interop_container_by_type_and_descriptor(e_halo4_interop_type interop_type, unsigned long descriptor, c_halo4_interop_container*& interop_container);

	BCS_RESULT get_compression_codec_by_index(long codec_index, e_compression_codec& compression_codec);

	e_halo4_resource_type* _resource_type_index_to_halo4_resource_type;
	e_halo4_interop_type* _interop_type_index_to_halo4_interop_type;
	c_halo4_interop_container** interop_containers;
	c_halo4_cache_file_reader** _shared_file_index_to_cache_file_reader;
	unsigned long _shared_file_count;
};
