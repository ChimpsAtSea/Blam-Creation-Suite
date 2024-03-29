#include "mandrilllib-private-pch.h"

c_cache_file_tag_project::c_cache_file_tag_project(
	c_cache_cluster& cache_cluster,
	s_cache_cluster_transplant_context& cache_cluster_transplant_context,
	c_status_interface* status_interface) :
	c_tag_project(
		bcs_result_wrapper_throw<s_engine_platform_build, c_cache_cluster, s_engine_platform_build&>(cache_cluster, &c_cache_cluster::get_engine_platform_build),
		status_interface),
	groups(),
	tags()
{
	h_tag_group** tag_groups;
	unsigned int num_tag_groups;
	BCS_RESULT get_high_level_tag_groups_result;
	if (BCS_FAILED(get_high_level_tag_groups_result = high_level_transplant_context_get_high_level_tag_groups(
		cache_cluster_transplant_context,
		tag_groups,
		num_tag_groups)))
	{
		throw get_high_level_tag_groups_result;
	}

	h_tag_instance** tag_instances;
	unsigned int num_tag_instances;
	BCS_RESULT get_high_level_tag_instances_result;
	if (BCS_FAILED(get_high_level_tag_instances_result = high_level_transplant_context_get_high_level_tag_instances(
		cache_cluster_transplant_context,
		tag_instances,
		num_tag_instances)))
	{
		throw get_high_level_tag_instances_result;
	}

	groups.insert(groups.begin(), tag_groups, tag_groups + num_tag_groups);
	tags.insert(tags.begin(), tag_instances, tag_instances + num_tag_instances);
}

c_cache_file_tag_project::~c_cache_file_tag_project()
{
	for (h_tag_instance* tag : tags)
	{
		delete tag;
	}
}

BCS_RESULT c_cache_file_tag_project::get_group_by_group_tag(tag group_tag, h_tag_group*& group) const
{
	for (h_tag_group* current_group : groups)
	{
		if (current_group->blofeld_tag_group.group_tag == group_tag)
		{
			group = current_group;
			return BCS_S_OK;
		}
	}
	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_cache_file_tag_project::get_tag_instances(h_tag_instance* const*& tag_instances, uint32_t& tag_instance_count) const
{
	tag_instances = tags.data();
	tag_instance_count = static_cast<unsigned long>(tags.size());

	return BCS_S_OK;
}

BCS_RESULT c_cache_file_tag_project::get_tag_groups(h_tag_group* const*& out_groups, uint32_t& out_group_count) const
{
	out_groups = groups.data();
	out_group_count = static_cast<unsigned long>(groups.size());

	return BCS_S_OK;
}
