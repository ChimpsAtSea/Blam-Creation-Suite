#pragma once

class c_high_level_cache_cluster_transplant;
class h_tag;

class c_tag_project
{
public:
	c_tag_project(c_high_level_cache_cluster_transplant& transplant);
	~c_tag_project();

	h_group* get_group_by_group_tag(tag group_tag) const;

	s_engine_platform_build engine_platform_build;

	std::vector<h_group*> groups;
	std::vector<h_tag*> tags;
};

