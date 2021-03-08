#pragma once

class h_group;

class c_halo4_tag_group : public c_tag_group
{
public:
	c_halo4_tag_group(c_halo4_cache_cluster& cache_cluster, tag group_tag, const char* group_name, c_halo4_tag_group* parent);
	~c_halo4_tag_group();

	BCS_RESULT get_blofeld_tag_group(const blofeld::s_tag_group*& blofeld_tag_group) const;

	tag group_tag;
	c_fixed_string<128> group_name;
	c_cache_cluster& cache_cluster;
	c_halo4_tag_group* parent;
	const blofeld::s_tag_group* blofeld_tag_group;
};

