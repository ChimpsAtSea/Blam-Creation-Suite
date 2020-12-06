#pragma once

class h_tag;

class c_tag_project
{
public:
	c_tag_project(c_cache_cluster& cache_cluster, c_cache_file& cache_file);
	~c_tag_project();

	std::vector<h_group*> groups;
	std::vector<h_tag*> tags;
};

