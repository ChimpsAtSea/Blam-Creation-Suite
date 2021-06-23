#include "mandrilllib-private-pch.h"

c_tag_project::c_tag_project(c_high_level_cache_cluster_transplant& transplant) :
	engine_platform_build(transplant.engine_platform_build),
	groups(transplant.groups),
	tags()
{
	for (s_tag_transplant_instance& transplant_instance : transplant.instances)
	{
		tags.push_back(transplant_instance.high_level);
	}
}

c_tag_project::~c_tag_project()
{
	for (h_tag* tag : tags)
	{
		delete tag;
	}
}

h_group* c_tag_project::get_group_by_group_tag(tag group_tag) const
{
	for (h_group* group : groups)
	{
		if (group->tag_group.group_tag == group_tag)
		{
			return group;
		}
	}
	return nullptr;
}
