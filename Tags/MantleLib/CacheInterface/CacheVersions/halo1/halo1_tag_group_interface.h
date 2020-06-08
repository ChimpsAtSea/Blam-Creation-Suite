#pragma once

class c_halo1_tag_group_interface :
	public c_tag_group_interface
{
public:
	c_halo1_tag_group_interface(c_halo1_cache_file& cache_file, uint16_t group_index, unsigned long group_tag);
	~c_halo1_tag_group_interface();

	virtual void add_tag_interface(c_tag_interface& tag_interface);
};

