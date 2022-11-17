#include "mandrilllib-private-pch.h"
//
//c_cache_file_tag_project::c_cache_file_tag_project(
//	c_high_level_cache_cluster_transplant& transplant,
//	c_status_interface* status_interface) :
//	c_tag_project(transplant.engine_platform_build, status_interface),
//	groups(transplant.groups),
//	tags()
//{
//	for (s_tag_transplant_instance& transplant_instance : transplant.instances)
//	{
//		tags.push_back(transplant_instance.high_level);
//	}
//}
//
//c_cache_file_tag_project::~c_cache_file_tag_project()
//{
//	for (h_tag_instance* tag : tags)
//	{
//		delete tag;
//	}
//}
//
//BCS_RESULT c_cache_file_tag_project::get_group_by_group_tag(tag group_tag, h_tag_group*& group) const
//{
//	for (h_tag_group* current_group : groups)
//	{
//		if (current_group->tag_group.group_tag == group_tag)
//		{
//			group = current_group;
//			return BCS_S_OK;
//		}
//	}
//	return BCS_E_NOT_FOUND;
//}
//
//BCS_RESULT c_cache_file_tag_project::get_tag_instances(h_tag_instance* const*& tag_instances, uint32_t& tag_instance_count) const
//{
//	tag_instances = tags.data();
//	tag_instance_count = static_cast<unsigned long>(tags.size());
//
//	return BCS_S_OK;
//}
//
//BCS_RESULT c_cache_file_tag_project::get_tag_groups(h_tag_group* const*& out_groups, uint32_t& out_group_count) const
//{
//	out_groups = groups.data();
//	out_group_count = static_cast<unsigned long>(groups.size());
//
//	return BCS_S_OK;
//}
