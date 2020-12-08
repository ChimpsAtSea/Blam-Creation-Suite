#pragma once

class c_tag_interface;
class c_tag_group_interface;
class h_tag;
class h_object;
class h_group;

class c_high_level_cache_file_transplant
{
public:
	c_high_level_cache_file_transplant(c_cache_cluster& cache_cluster, c_cache_file& cache_file);
	~c_high_level_cache_file_transplant();

	void transplant_data(h_object& high_level, const char* low_level_data, const blofeld::s_tag_struct_definition& struct_definition);
	h_tag* get_high_level_tag_by_tag_interface(c_tag_interface* tag_interface);
	h_tag* tag_interface_to_high_level(c_tag_interface& tag_interface);
	h_group& get_or_create_group(/*c_tag_group_interface& group_interface*/ const blofeld::s_tag_group& tag_group);

	struct s_group_pair
	{
		const blofeld::s_tag_group& tag_group;
		//c_tag_group_interface& group_interface;
		h_group& high_level_group;
	};
	std::vector<s_group_pair> groups_and_interface;

	struct s_tag_pair
	{
		c_tag_interface& tag_interface;
		h_tag& high_level_tag;
	};
	std::vector<s_tag_pair> tags_and_interface;

protected:	
	c_cache_cluster& cache_cluster;
	c_cache_file& cache_file;
};
