#pragma once

class c_infinite_cache_cluster;
class c_infinite_module_file_reader;
class c_infinite_tag_group;
class c_infinite_tag_instance;
class c_high_level_cache_cluster_transplant;

#define INF_DONT_PROCESS_TAG_DATA 1

class c_infinite_tag_reader : public c_tag_reader
{
public:
	friend c_infinite_cache_cluster;
	friend c_infinite_module_file_reader;
	friend c_high_level_cache_cluster_transplant;
	c_infinite_tag_reader(c_infinite_cache_cluster& cache_cluster, c_infinite_module_file_reader& cache_reader);
	~c_infinite_tag_reader();

	BCS_RESULT page_offset_to_pointer(long page_offset, const void*& data);
	BCS_RESULT get_tag_groups(c_infinite_tag_group**& tag_groups, unsigned long& tag_group_count);
	virtual BCS_RESULT get_tag_groups(c_tag_group**& tag_groups, unsigned long& tag_group_count) override;
	BCS_RESULT get_tag_instances(c_infinite_tag_instance**& tag_instances, unsigned long& tag_instance_count);
	virtual BCS_RESULT get_tag_instances(c_tag_instance**& tag_instances, unsigned long& tag_instance_count) override;
	virtual BCS_RESULT get_tag_instance_by_cache_file_tag_index(unsigned long cache_file_tag_index, c_tag_instance*& tag_instance) override;
	virtual BCS_RESULT get_tag_instance_by_global_tag_id(unsigned long global_tag_id, c_tag_instance*& tag_instance);
	virtual BCS_RESULT get_tag_instance_by_global_tag_id_and_group_tag(long global_tag_id, tag group_tag, c_tag_instance*& tag_instance);

private:
	struct s_infinite_tag_instance_info
	{
		const infinite::s_module_file_entry* file_entry;
		const char* file_name;
		const char* instance_name;
		const void* instance_data;
		const void* instance_block_data[16];
		const blofeld::s_tag_group* blofeld_tag_group;
		c_infinite_tag_group* tag_group;
	};

	c_infinite_cache_cluster& cache_cluster;
	c_infinite_module_file_reader& cache_reader;

	using t_tag_groups = std::vector<c_infinite_tag_group*>;
	using t_tag_instances = std::vector<c_infinite_tag_instance*>;
	using t_tag_instances_by_filename = std::map<std::string, c_infinite_tag_instance*>;

	t_tag_groups tag_groups;
	t_tag_instances tag_instances;
	t_tag_instances_by_filename tag_instances_by_filename;

	using t_tag_instance_infos = std::vector<s_infinite_tag_instance_info>;

	t_tag_instance_infos tag_instance_infos;

	BCS_RESULT data_offset_fixup(unsigned long offset, unsigned long index, unsigned long& fixed_offset);
	BCS_RESULT read_tag_instances();
	BCS_RESULT init_tag_groups();
	BCS_RESULT init_tag_instances();

	BCS_RESULT get_tag_group_by_group_tag(tag group_tag, c_infinite_tag_group*& tag_group) const;
	BCS_RESULT get_tag_group_by_blofeld_tag_group(const blofeld::s_tag_group& blofeld_tag_group, c_infinite_tag_group*& tag_group) const;

	BCS_RESULT get_instance_info_by_tag_filename(const char* filename, const s_infinite_tag_instance_info*& instance_info);
};
