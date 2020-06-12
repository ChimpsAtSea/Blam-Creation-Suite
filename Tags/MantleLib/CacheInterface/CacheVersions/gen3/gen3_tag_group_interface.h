#pragma once

class c_gen3_tag_group_interface :
	public c_tag_group_interface
{
public:
	c_gen3_tag_group_interface(c_cache_file& cache_file, uint16_t group_index);
	~c_gen3_tag_group_interface();

	virtual void add_tag_interface(c_tag_interface& tag_interface);

	gen3::s_cache_file_tag_group& cache_file_tag_group;
};

