#pragma once

class c_high_level_cache_cluster_transplant;
class c_monolithic_partition_view;

class h_tag;

struct s_monolithic_tag_project_read_tags_callback_data;

class c_chunk;
class c_tag_file_index_chunk;
class c_tag_file_blocks_chunk;
class c_tag_heap_chunk;
class c_partitioned_heap_entry_list_chunk;
class c_partition_list_chunk;
class c_cache_heap_chunk;
class c_partitioned_heap_entry_list_chunk;
class c_partition_list_chunk;

class c_monolithic_tag_project :
	public c_tag_project
{
public:
	BCS_SHARED c_monolithic_tag_project(
		const wchar_t* directory, 
		s_engine_platform_build engine_platform_build,
		c_status_interface* status_interface);
	BCS_SHARED ~c_monolithic_tag_project();

	virtual BCS_RESULT get_group_by_group_tag(tag group_tag, h_group*& group) const override;
	virtual BCS_RESULT get_group_by_file_extension(const char* file_extension, h_group*& group) const;
	virtual BCS_RESULT get_tag_instances(h_tag* const*& tag_instances, uint32_t& tag_instance_count) const override;
	virtual BCS_RESULT get_tag_groups(h_group* const*& groups, uint32_t& group_count) const override;

	BCS_RESULT parse_tag_blob(const void* tag_file_data, uint64_t tag_file_data_size);
	BCS_RESULT read_tags();

protected:
	BCS_RESULT init_monolithic_tag_file_views_result;
	static void init_monolithic_tag_file_views_impl(void* userdata, uint32_t index);
	BCS_RESULT init_monolithic_tag_file_views();
	BCS_RESULT init_monolithic_cache_file_views();
	BCS_RESULT deinit_monolithic_tag_file_views();
	BCS_RESULT deinit_monolithic_cache_file_views();
	static void destroy_tags(h_tag*const* tags, size_t index);

	BCS_RESULT get_tag_partition_view(
		uint32_t tag_heap_entry_index,
		c_monolithic_partition_view*& tag_partition_view) const;
	BCS_RESULT get_cache_partition_view(
		uint32_t cache_heap_entry_index,
		c_monolithic_partition_view*& cache_partition_view) const;

	BCS_RESULT read_tag(uint32_t index, h_tag*& out_tag, h_group*& out_tag_group) const;
	static void read_tags_callback(s_monolithic_tag_project_read_tags_callback_data* userdata, int32_t index);

	wchar_t root_directory[0x10000];
	wchar_t tag_cache_directory[0x10000];
	wchar_t blob_index_file_path[0x10000];
	std::vector<h_group*> groups;
	std::vector<h_tag*> tags;

	uint32_t num_tag_partitions;
	c_monolithic_partition_view** tag_partition_views;
	uint32_t num_cache_partitions;
	//t_memory_mapped_file** cache_memory_mapped_files;
	//s_memory_mapped_file_info* cache_memory_mapped_file_infos;
	c_monolithic_partition_view** cache_partition_views;

	c_chunk* root_chunk;

	c_tag_file_index_chunk* tag_file_index_chunk;
	c_tag_file_blocks_chunk* tag_file_blocks_chunk;

	c_tag_heap_chunk* tag_heap_chunk;
	c_partitioned_heap_entry_list_chunk* tag_heap_list_chunk;
	c_partition_list_chunk* tag_partition_list_chunk;

	c_cache_heap_chunk* cache_heap_chunk;
	c_partitioned_heap_entry_list_chunk* cache_heap_list_chunk;
	c_partition_list_chunk* cache_partition_list_chunk;
};
