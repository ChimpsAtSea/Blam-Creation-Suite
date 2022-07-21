#pragma once

class c_infinite_cache_cluster;
class c_infinite_module_file_reader;
class c_infinite_tag_group;
class c_infinite_tag_instance;
class c_high_level_cache_cluster_transplant;

#define INF_DONT_PROCESS_TAG_DATA 1

class c_infinite_file_entry_block_map;

class c_infinite_tag_reader : public c_tag_reader
{
public:
	friend c_infinite_cache_cluster;
	friend c_infinite_module_file_reader;
	friend c_high_level_cache_cluster_transplant;
	c_infinite_tag_reader(c_infinite_cache_cluster& cache_cluster, c_infinite_module_file_reader& cache_reader);
	~c_infinite_tag_reader();

	BCS_RESULT page_offset_to_pointer(int32_t page_offset, const void*& data);
	BCS_RESULT get_tag_groups(c_infinite_tag_group**& tag_groups, uint32_t& tag_group_count);
	virtual BCS_RESULT get_tag_groups(c_tag_group**& tag_groups, uint32_t& tag_group_count) override;
	BCS_RESULT get_tag_instances(c_infinite_tag_instance**& tag_instances, uint32_t& tag_instance_count);
	virtual BCS_RESULT get_tag_instances(c_tag_instance**& tag_instances, uint32_t& tag_instance_count) override;
	virtual BCS_RESULT get_tag_instance_by_cache_file_tag_index(uint32_t cache_file_tag_index, c_tag_instance*& tag_instance) override;
	virtual BCS_RESULT get_tag_instance_by_global_tag_id(uint32_t global_tag_id, c_tag_instance*& tag_instance);
	virtual BCS_RESULT get_tag_instance_by_global_tag_id_and_group_tag(int32_t global_tag_id, tag group_tag, c_tag_instance*& tag_instance);

private:
	struct s_infinite_tag_instance_info
	{
		c_infinite_file_entry_block_map* file_entry_block_map;
		const char* filepath;
		const blofeld::s_tag_group* blofeld_tag_group;
	};

	c_infinite_cache_cluster& cache_cluster;
	c_infinite_module_file_reader& cache_reader;

	using t_tag_groups = std::vector<c_infinite_tag_group*>;
	using t_tag_instances = std::vector<c_infinite_tag_instance*>;
	using t_tag_instances_by_filename = std::unordered_map<std::string, c_infinite_tag_instance*>;

	t_tag_groups tag_groups;
	t_tag_instances tag_instances;
	t_tag_instances_by_filename tag_instances_by_filepath;

	c_infinite_file_entry_block_map** file_entry_block_maps;
	uint32_t num_file_entry_block_maps;

	s_infinite_tag_instance_info* tag_instance_infos;
	uint32_t num_tag_instance_infos;



	BCS_RESULT offset_to_data(uint64_t offset, const char*& data);
	BCS_RESULT read_tag_instances();
	BCS_RESULT init_tag_groups();
	BCS_RESULT init_tag_instances();

	BCS_RESULT get_tag_group_by_group_tag(tag group_tag, c_infinite_tag_group*& tag_group) const;
	BCS_RESULT get_tag_group_by_blofeld_tag_group(const blofeld::s_tag_group& blofeld_tag_group, c_infinite_tag_group*& tag_group) const;

	BCS_RESULT get_instance_info_by_tag_filepath(const char* filepath, const s_infinite_tag_instance_info*& instance_info);
};
