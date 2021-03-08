#pragma once

class c_halo4_cache_cluster;
class c_halo4_cache_file_reader;

class h_tag;
class h_object;
class h_group;

struct s_halo4_tag_group_hierarchy;
struct s_halo4_cache_cluster_entry;

class c_high_level_cache_cluster_transplant
{
public:
	c_high_level_cache_cluster_transplant(c_halo4_cache_cluster& cache_cluster);
	~c_high_level_cache_cluster_transplant();

	BCS_RESULT transplant_data(h_object& high_level, const char* low_level_data, s_halo4_cache_cluster_entry& cluster_entry, c_halo4_cache_file_reader& cache_reader, const blofeld::s_tag_struct_definition& struct_definition);


protected:
	BCS_RESULT init_transplant_entries();
	BCS_RESULT init_tag_groups();
	BCS_RESULT init_tag_instances();
	BCS_RESULT transplant_instance_data();

protected: // tag group hierarchy 

	BCS_RESULT init_tag_group_hierarchy();
	h_group* init_tag_group_hierarchy_impl(s_halo4_tag_group_hierarchy& tag_group_hierarchy);

public:
	BCS_RESULT get_tag_by_index(const s_halo4_cache_cluster_entry& cache_cluster_entry, unsigned long tag_index, h_tag*& tag);
	BCS_RESULT get_tag_by_group_and_filename(h_group& group, const char* filename, h_tag*& tag);
	BCS_RESULT get_tag_group(tag group_tag, h_group*& group);

	using t_transplant_instances = std::vector<h_tag*>;
	using t_transplant_instances_keyval = std::pair<s_halo4_cache_cluster_entry*, t_transplant_instances>;

	BCS_RESULT get_cluster_transplant_instances(const s_halo4_cache_cluster_entry* cache_cluster_entry, const t_transplant_instances*& transplant_instances);

	std::vector<t_transplant_instances_keyval> instance_transplant_entries;
	std::vector<h_tag*> instances;
	std::vector<h_group*> groups;
	std::vector<s_halo4_cache_cluster_entry*> transplant_entries;
	c_halo4_cache_cluster& cache_cluster;
};
