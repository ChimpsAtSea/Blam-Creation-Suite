#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_HALO4

c_halo4_tag_instance::c_halo4_tag_instance(
	c_cache_cluster& cache_cluster,
	c_halo4_tag_group& tag_group,
	uint32_t cache_file_tag_index,
	const char* instance_name,
	const void* instance_data) :
	cache_cluster(cache_cluster),
	tag_group(_tag_group),
	cache_file_tag_index(cache_file_tag_index),
	instance_name(instance_name),
	instance_data(instance_data)
{
}

c_halo4_tag_instance::~c_halo4_tag_instance()
{
}

BCS_RESULT c_halo4_tag_instance::get_tag_data(const void*& out_tag_instance_data) const
{
	out_tag_instance_data = instance_data;
	return BCS_S_OK;
}

BCS_RESULT c_halo4_tag_instance::get_instance_name(const char*& out_tag_instance_name) const
{
	out_tag_instance_name = instance_name;
	return BCS_S_OK;
}

BCS_RESULT c_halo4_tag_instance::get_tag_group(c_halo4_tag_group*& out_tag_group) const
{
	out_tag_group = &tag_group;
	return BCS_S_OK;
}

BCS_RESULT c_halo4_tag_instance::get_tag_group(c_tag_group*& out_tag_group) const
{
	out_tag_group = &tag_group;
	return BCS_S_OK;
}

BCS_RESULT c_halo4_tag_instance::get_cache_file_tag_index(uint32_t& out_cache_file_tag_index) const
{
	out_cache_file_tag_index = cache_file_tag_index;
	return BCS_S_OK;
}

#endif // BCS_BUILD_HIGH_LEVEL_HALO4
