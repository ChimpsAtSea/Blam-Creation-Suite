#include "highlevelcachefileserialization-private-pch.h"

c_halo1_tag_instance::c_halo1_tag_instance(
	c_halo1_cache_cluster& _cache_cluster,
	c_halo1_tag_reader& _tag_reader,
	c_halo1_tag_group& _tag_group,
	uint32_t _cache_file_tag_index,
	const char* _instance_name,
	const void* _instance_data) :
	cache_cluster(_cache_cluster),
	tag_reader(_tag_reader),
	tag_group(_tag_group),
	cache_file_tag_index(_cache_file_tag_index),
	instance_name(_instance_name),
	instance_data(_instance_data)
{
	ASSERT(instance_data != nullptr);
}

c_halo1_tag_instance::~c_halo1_tag_instance()
{
}

BCS_RESULT c_halo1_tag_instance::get_tag_data(const void*& out_tag_data_root, const void*& out_tag_data_start, const void*& out_tag_data_end) const
{
	out_tag_data_root = nullptr;
	out_tag_data_start = instance_data;
	out_tag_data_end = nullptr;

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

BCS_RESULT c_halo1_tag_instance::get_cache_file_tag_index(uint32_t& out_cache_file_tag_index) const
{
	out_cache_file_tag_index = cache_file_tag_index;
	return BCS_S_OK;
}

BCS_RESULT c_halo1_tag_instance::get_tag_file_reader(c_tag_reader*& out_tag_reader) const
{
	out_tag_reader = &tag_reader;
	return BCS_S_OK;
}
