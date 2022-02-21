#pragma once

class c_cache_cluster;
class c_cache_file_reader;
class c_tag_instance;

class c_infinite_ucs_reader;

class h_tag;
class h_object;
class h_group;

struct s_tag_transplant_instance
{
	c_tag_instance* low_level;
	h_tag* high_level;
};

class c_high_level_cache_cluster_transplant
{
public:
	BCS_DEBUG_API c_high_level_cache_cluster_transplant(c_cache_cluster& cache_cluster);
	BCS_DEBUG_API ~c_high_level_cache_cluster_transplant();

	BCS_RESULT transplant_cache_file_data(h_object& high_level, const char* low_level_data, c_cache_file_reader& cache_file_reader, const blofeld::s_tag_struct_definition& struct_definition);
	BCS_RESULT transplant_module_file_data(
		c_tag_instance& tag_instance,
		h_tag& high_level, 
		c_infinite_ucs_reader* ucs_reader,
		const char* low_level_data,
		c_cache_file_reader& cache_file_reader, 
		const blofeld::s_tag_struct_definition& struct_definition);


protected:
	BCS_RESULT init_transplant_entries();
	BCS_RESULT init_tag_groups();
	BCS_RESULT init_tag_instances();
	BCS_RESULT transplant_instance_data();

public:
	BCS_RESULT get_global_tag_by_low_level_tag_instance(c_tag_instance& tag_instance, h_tag*& tag);
	BCS_RESULT get_tag_by_low_level_tag_instance(c_cache_file_reader& cache_file_reader, c_tag_instance& tag_instance, h_tag*& tag);
	BCS_RESULT get_tag_by_group_and_filename(h_group& group, const char* filename, h_tag*& tag);
	BCS_RESULT get_tag_group(tag group_tag, h_group*& group);
	
	using t_transplant_instances = std::vector<s_tag_transplant_instance>;
	using t_transplant_instances_keyval = std::pair<c_cache_file_reader*, t_transplant_instances>;

	BCS_RESULT get_cluster_transplant_instances(c_cache_file_reader& cache_file_reader, const t_transplant_instances*& transplant_instances);

	using t_instance_transplant_entries = std::vector<t_transplant_instances_keyval>;
	using t_instances = t_transplant_instances;
	using t_groups = std::vector<h_group*>;
	using t_transplant_entries = std::vector<c_cache_file_reader*>;

	t_instance_transplant_entries instance_transplant_entries;
	t_instances instances;
	t_groups groups;
	t_transplant_entries transplant_entries;
	c_cache_cluster& cache_cluster;
	s_engine_platform_build engine_platform_build;
};
