#include "highlevelcachefileserialization-private-pch.h"

c_eldorado_tag_instance::c_eldorado_tag_instance(
	c_cache_cluster& cache_cluster,
	c_eldorado_tag_group& tag_group,
	uint32_t cache_file_tag_index,
	const char* _instance_name,
	const blofeld::eldorado::s_cache_file_tag_instance& _tag_header,
	const void* _tag_data_start,
	const void* _tag_data_end) :
	cache_cluster(cache_cluster),
	tag_group(tag_group),
	cache_file_tag_index(cache_file_tag_index),
	instance_name(_instance_name ? strdup(_instance_name) : nullptr),
	tag_header(_tag_header),
	tag_data_start(_tag_data_start),
	tag_data_end(_tag_data_start)
{

}

c_eldorado_tag_instance::~c_eldorado_tag_instance()
{
	untracked_free(instance_name);
}

BCS_RESULT c_eldorado_tag_instance::get_tag_data(const void*& out_tag_data_root, const void*& out_tag_data_start, const void*& out_tag_data_end) const
{
	out_tag_data_root = static_cast<const char*>(tag_data_start) + tag_header.offset;
	out_tag_data_start = tag_data_start;
	out_tag_data_end = tag_data_end;
	return BCS_S_OK;
}

BCS_RESULT c_eldorado_tag_instance::get_instance_name(const char*& out_tag_instance_name) const
{
	out_tag_instance_name = instance_name;
	return BCS_S_OK;
}

BCS_RESULT c_eldorado_tag_instance::get_tag_group(c_eldorado_tag_group*& out_tag_group) const
{
	out_tag_group = &tag_group;
	return BCS_S_OK;
}

BCS_RESULT c_eldorado_tag_instance::get_tag_group(c_tag_group*& out_tag_group) const
{
	out_tag_group = &tag_group;
	return BCS_S_OK;
}

BCS_RESULT c_eldorado_tag_instance::get_cache_file_tag_index(uint32_t& out_cache_file_tag_index) const
{
	out_cache_file_tag_index = cache_file_tag_index;
	return BCS_S_OK;
}
