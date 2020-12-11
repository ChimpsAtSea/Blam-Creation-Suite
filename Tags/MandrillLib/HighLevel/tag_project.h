#pragma once

class h_tag;

class c_tag_project
{
public:
	c_tag_project(c_cache_cluster& cache_cluster, c_cache_file& cache_file);
	~c_tag_project();

	h_group* get_group_by_group_tag(tag group_tag) const;

	e_engine_type engine_type;
	e_platform_type platform_type;
	e_build build;

	std::vector<h_group*> groups;
	std::vector<h_tag*> tags;
};

