#include "mandrilllib-private-pch.h"

c_infinite_tag_instance::c_infinite_tag_instance(
	c_cache_cluster& cache_cluster,
	c_infinite_tag_group& tag_group,
	const char* instance_name,
	const void* instance_data,
	const void** instance_block_data,
	const infinite::s_module_file_entry* file_entry) :
	cache_cluster(cache_cluster),
	tag_group(tag_group),
	instance_name(instance_name),
	instance_data(instance_data),
	instance_block_data(instance_block_data),
	file_entry(file_entry)
{
	ASSERT(instance_data != nullptr);
	ucs_reader = new c_infinite_ucs_reader(instance_block_data);
}

c_infinite_tag_instance::~c_infinite_tag_instance()
{
}

BCS_RESULT c_infinite_tag_instance::get_data(const void*& out_tag_instance_data) const
{
	out_tag_instance_data = instance_data;
	return BCS_S_OK;
}

BCS_RESULT c_infinite_tag_instance::get_instance_name(const char*& out_tag_instance_name) const
{
	out_tag_instance_name = instance_name;
	return BCS_S_OK;
}

BCS_RESULT c_infinite_tag_instance::get_tag_group(c_infinite_tag_group*& out_tag_group) const
{
	out_tag_group = &tag_group;
	return BCS_S_OK;
}

BCS_RESULT c_infinite_tag_instance::get_tag_group(c_tag_group*& out_tag_group) const
{
	out_tag_group = &tag_group;
	return BCS_S_OK;
}

BCS_RESULT c_infinite_tag_instance::get_cache_file_tag_index(unsigned long& out_cache_file_tag_index) const
{
	return BCS_E_UNSUPPORTED;
}
