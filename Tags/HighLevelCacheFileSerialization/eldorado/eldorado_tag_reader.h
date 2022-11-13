#pragma once

class c_eldorado_cache_cluster;
class c_eldorado_cache_file_reader;
class c_eldorado_tag_group;
class c_eldorado_tag_instance;

class c_high_level_cache_cluster_transplant;

class c_eldorado_tag_reader : public c_tag_reader
{
public:
	friend c_eldorado_cache_cluster;
	friend c_eldorado_cache_file_reader;
	friend c_high_level_cache_cluster_transplant;
	c_eldorado_tag_reader(c_eldorado_cache_cluster& cache_cluster, c_eldorado_cache_file_reader& cache_reader);
	~c_eldorado_tag_reader();

	BCS_RESULT page_offset_to_pointer(int32_t page_offset, const void*& data);

	virtual BCS_RESULT get_tag_groups(c_tag_group**& tag_groups, uint32_t& tag_group_count) override;
	BCS_RESULT get_tag_groups(c_eldorado_tag_group**& tag_groups, uint32_t& tag_group_count);
	virtual BCS_RESULT get_tag_instances(c_tag_instance**& tag_instances, uint32_t& tag_instance_count) override;
	BCS_RESULT get_tag_instances(c_eldorado_tag_instance**& tag_instances, uint32_t& tag_instance_count);
	virtual BCS_RESULT get_tag_instance_by_cache_file_tag_index(uint32_t cache_file_tag_index, c_tag_instance*& tag_instance) override;

	BCS_RESULT create_group(blofeld::s_tag_group const& tag_group, c_eldorado_tag_group*& eldorado_tag_group);
	BCS_RESULT get_tag_group_by_group_tag(tag group_tag, c_eldorado_tag_group*& tag_group) const;
	BCS_RESULT get_tag_group_by_blofeld_tag_group(blofeld::s_tag_group const& blofeld_tag_group, c_eldorado_tag_group*& tag_group) const;

private:
	BCS_RESULT read_header();
	BCS_RESULT read_groups();
	BCS_RESULT read_instances();

	c_eldorado_cache_cluster& cache_cluster;
	c_eldorado_cache_file_reader& cache_reader;
	blofeld::eldorado::s_cache_file_tags_header cache_file_tags_header;
	unsigned int* tag_cache_offsets;

	using t_tag_groups = std::vector<c_eldorado_tag_group*>;
	using t_tag_instances = std::vector<c_eldorado_tag_instance*>;
	using t_tag_instances_by_index = std::unordered_map<uint32_t, c_eldorado_tag_instance*>;

	t_tag_groups tag_groups;
	t_tag_instances tag_instances;
	t_tag_instances_by_index tag_instances_by_index;
};
