#include "mandrilllib-private-pch.h"

c_halo1_tag_instance::c_halo1_tag_instance(
	c_cache_cluster& cache_cluster,
	c_halo1_tag_group& tag_group,
	unsigned long cache_file_tag_index,
	const char* instance_name,
	const void* instance_data) :
	cache_cluster(cache_cluster),
	tag_group(tag_group),
	cache_file_tag_index(cache_file_tag_index),
	instance_name(instance_name),
	instance_data(instance_data)
{
	ASSERT(instance_data != nullptr);
}

c_halo1_tag_instance::~c_halo1_tag_instance()
{
}

BCS_RESULT c_halo1_tag_instance::get_tag_data(const void*& out_tag_instance_data) const
{
	out_tag_instance_data = instance_data;
	return BCS_S_OK;
}

BCS_RESULT c_halo1_tag_instance::get_instance_name(const char*& out_tag_instance_name) const
{
	out_tag_instance_name = instance_name;
	return BCS_S_OK;
}

BCS_RESULT c_halo1_tag_instance::get_tag_group(c_halo1_tag_group*& out_tag_group) const
{
	out_tag_group = &tag_group;
	return BCS_S_OK;
}

BCS_RESULT c_halo1_tag_instance::get_tag_group(c_tag_group*& out_tag_group) const
{
	out_tag_group = &tag_group;
	return BCS_S_OK;
}

BCS_RESULT c_halo1_tag_instance::get_cache_file_tag_index(unsigned long& out_cache_file_tag_index) const
{
	out_cache_file_tag_index = cache_file_tag_index;
	return BCS_S_OK;
}
