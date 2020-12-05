#pragma once

class c_tag_interface;
class c_high_level_tag;
class c_high_level_type;

class c_high_level_cache_file_transplant
{
public:
	c_high_level_cache_file_transplant(c_cache_cluster& cache_cluster, c_cache_file& cache_file);
	~c_high_level_cache_file_transplant();

	void transplant_data(c_high_level_type& high_level, const char* low_level_data, const blofeld::s_tag_struct_definition& struct_definition);
	c_high_level_tag* get_high_level_tag_by_tag_interface(c_tag_interface* tag_interface);
	c_high_level_tag* tag_interface_to_high_level(c_tag_interface& tag_interface);

	struct s_tag_pair
	{
		c_tag_interface& tag_interface;
		c_high_level_tag& high_level_tag;
	};

	std::vector<s_tag_pair> tags_and_interface;

protected:	
	c_cache_cluster& cache_cluster;
	c_cache_file& cache_file;
};
