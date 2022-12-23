#pragma once

class c_halo1_cache_cluster;
class c_halo1_cache_file_reader;
class c_halo1_tag_group;
class c_halo1_tag_instance;
class c_high_level_cache_cluster_transplant;

class c_halo1_tag_reader : public c_tag_reader
{
public:
	friend c_halo1_cache_cluster;
	friend c_halo1_cache_file_reader;
	friend c_high_level_cache_cluster_transplant;
	c_halo1_tag_reader(c_halo1_cache_cluster& cache_cluster, c_halo1_cache_file_reader& cache_reader);
	~c_halo1_tag_reader();

	BCS_RESULT page_offset_to_pointer(int32_t page_offset, const void*& data);
	BCS_RESULT get_tag_groups(c_halo1_tag_group**& tag_groups, uint32_t& tag_group_count);
	virtual BCS_RESULT get_tag_groups(c_tag_group**& tag_groups, uint32_t& tag_group_count) override;
	BCS_RESULT get_tag_instances(c_halo1_tag_instance**& tag_instances, uint32_t& tag_instance_count);
	virtual BCS_RESULT get_tag_instances(c_tag_instance**& tag_instances, uint32_t& tag_instance_count) override;
	virtual BCS_RESULT get_tag_instance_by_cache_file_tag_index(uint32_t cache_file_tag_index, c_tag_instance*& tag_instance) override;

private:
	struct s_halo1_tag_instance_info
	{
		halo1::s_cache_file_tag_instance instance;
		int32_t index;
		const char* instance_name;
		const void* instance_data;
		blofeld::s_tag_group const* blofeld_tag_group;
		c_halo1_tag_group* tag_group;
	};

	c_halo1_cache_cluster& cache_cluster;
	c_halo1_cache_file_reader& cache_reader;

	using t_tag_groups = std::vector<c_halo1_tag_group*>;
	using t_tag_instances = std::vector<c_halo1_tag_instance*>;
	using t_tag_instances_by_index = std::unordered_map<uint32_t, c_halo1_tag_instance*>;

	t_tag_groups tag_groups;
	t_tag_instances tag_instances;
	t_tag_instances_by_index tag_instances_by_index;

	using t_tag_instance_infos = std::vector<s_halo1_tag_instance_info>;

	t_tag_instance_infos tag_instance_infos;

	BCS_RESULT read_tag_instances();
	BCS_RESULT init_tag_groups();
	BCS_RESULT init_tag_instances();

	BCS_RESULT get_tag_group_by_group_tag(tag group_tag, c_halo1_tag_group*& tag_group) const;
	BCS_RESULT get_tag_group_by_blofeld_tag_group(blofeld::s_tag_group const& blofeld_tag_group, c_halo1_tag_group*& tag_group) const;

	BCS_RESULT get_instance_info_by_tag_index(uint32_t tag_index, const s_halo1_tag_instance_info*& instance_info);
};
