#pragma once

class c_halo3_cache_cluster;
class c_halo3_cache_file_reader;
class c_halo3_tag_group;
class c_halo3_tag_instance;

class c_high_level_cache_cluster_transplant;

class c_halo3_tag_reader : public c_tag_reader
{
public:
	friend c_halo3_cache_cluster;
	friend c_halo3_cache_file_reader;
	friend c_high_level_cache_cluster_transplant;
	c_halo3_tag_reader(c_halo3_cache_cluster& cache_cluster, c_halo3_cache_file_reader& cache_reader);
	~c_halo3_tag_reader();

	BCS_RESULT page_offset_to_pointer(long page_offset, const void*& data);
	BCS_RESULT get_tag_groups(c_halo3_tag_group**& tag_groups, unsigned long& tag_group_count);
	virtual BCS_RESULT get_tag_groups(c_tag_group**& tag_groups, unsigned long& tag_group_count) override;
	BCS_RESULT get_tag_instances(c_halo3_tag_instance**& tag_instances, unsigned long& tag_instance_count);
	virtual BCS_RESULT get_tag_instances(c_tag_instance**& tag_instances, unsigned long& tag_instance_count) override;
	virtual BCS_RESULT get_tag_instance_by_cache_file_tag_index(unsigned long cache_file_tag_index, c_tag_instance*& tag_instance) override;

private:
	struct s_halo3_tag_group_info
	{
		::halo3::s_cache_file_tag_group group;
		const char* group_name;
		const blofeld::s_tag_group* blofeld_tag_group;
		c_halo3_tag_group* tag_group;
	};

	struct s_halo3_tag_instance_info
	{
		::halo3::s_cache_file_tag_instance instance;
		unsigned long absolute_index;
		unsigned long identifier;
		const char* instance_name;
		const void* instance_data;
		s_halo3_tag_group_info* group_info;
		c_halo3_tag_instance* tag_instance;
	};

	struct s_halo3_tag_global_instance_info
	{
		::halo3::s_cache_file_tag_global_instance global_instance;
		s_halo3_tag_instance_info* instance_info;
	};

	c_halo3_cache_cluster& cache_cluster;
	c_halo3_cache_file_reader& cache_reader;

	union
	{
		::halo3::pc::s_cache_file_tags_header pc_tags_header;
		::halo3::xbox360::s_cache_file_tags_header xbox360_tags_header;
	};

	using t_tag_groups = std::vector<c_halo3_tag_group*>;
	using t_tag_instances = std::vector<c_halo3_tag_instance*>;
	using t_tag_instances_by_index = std::map<unsigned long, c_halo3_tag_instance*>;

	t_tag_groups tag_groups;
	t_tag_instances tag_instances;
	t_tag_instances_by_index tag_instances_by_index;

	using t_tag_group_infos = std::vector<s_halo3_tag_group_info>;
	using t_tag_instance_infos = std::vector<s_halo3_tag_instance_info>;
	using t_tag_global_instance_infos = std::vector<s_halo3_tag_global_instance_info>;
	using t_tag_interop_infos = std::vector<::halo3::s_cache_file_tag_interop>;
	using t_tag_instance_infos_by_index = std::map<unsigned long, s_halo3_tag_global_instance_info*>;

	t_tag_group_infos tag_group_infos;
	t_tag_instance_infos tag_instance_infos;
	t_tag_global_instance_infos tag_global_instance_infos;
	t_tag_interop_infos tag_interop_infos;

	e_halo3_interop_type* _interop_type_index_to_halo3_interop_type;
	c_halo3_interop_container** interop_containers;
	c_halo3_cache_file_reader** _shared_file_index_to_cache_file_reader;
	unsigned long _shared_file_count;

	h_resource** high_level_resources;
	unsigned long num_high_level_resources;

	BCS_RESULT read_tags_header();
	BCS_RESULT read_tag_groups();
	BCS_RESULT read_tag_instances();
	BCS_RESULT read_tag_global_instances();
	BCS_RESULT read_tag_interops();
	BCS_RESULT init_tag_groups();
	BCS_RESULT init_tag_instances();

	BCS_RESULT get_tag_group_by_group_tag(tag group_tag, c_halo3_tag_group*& tag_group) const;
	BCS_RESULT get_tag_group_by_blofeld_tag_group(const blofeld::s_tag_group& blofeld_tag_group, c_halo3_tag_group*& tag_group) const;
	BCS_RESULT get_tag_group_info_by_group_tag(tag group_tag, s_halo3_tag_group_info*& tag_group_info);
	BCS_RESULT get_tag_group_info_by_blofeld_tag_group(const blofeld::s_tag_group& blofeld_tag_group, s_halo3_tag_group_info*& tag_group_info);

	BCS_RESULT init_interop_table();
	BCS_RESULT init_interops();
	BCS_RESULT interop_type_index_to_halo3_interop_type(long type_index, e_halo3_interop_type& interop_type);

	BCS_RESULT init_resource_table();
	BCS_RESULT init_resources();

	BCS_RESULT init_shared_files_table();
	BCS_RESULT shared_file_index_to_cache_file_reader(long shared_file_index, c_halo3_cache_file_reader*& cache_file_reader);

	BCS_RESULT get_interop_container_by_type_and_descriptor(e_halo3_interop_type interop_type, unsigned long descriptor, c_halo3_interop_container*& interop_container);

	BCS_RESULT get_compression_codec_by_index(long codec_index, e_halo3_compression_codec& compression_codec);

	BCS_RESULT get_global_instance_info(tag group_tag, const s_halo3_tag_global_instance_info*& global_instance_info);
	BCS_RESULT get_instance_info_by_tag_index(unsigned long tag_index, const s_halo3_tag_instance_info*& instance_info);
	BCS_RESULT get_tag_instance_info_by_tag_index(unsigned long tag_index, c_halo3_tag_instance*& instance_info);

protected:
	BCS_RESULT get_tag_groups_section(::halo3::s_section& tag_groups);
	BCS_RESULT get_tag_instances_section(::halo3::s_section& tag_instances);
	BCS_RESULT get_global_tag_instances_section(::halo3::s_section& global_tag_instances);
	BCS_RESULT get_tag_interop_table_section(::halo3::s_section& tag_interop_table);
};
