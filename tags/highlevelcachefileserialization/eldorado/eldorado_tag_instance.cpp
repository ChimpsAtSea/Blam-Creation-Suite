#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO

c_eldorado_tag_instance::c_eldorado_tag_instance(
	c_eldorado_cache_cluster& _cache_cluster,
	c_eldorado_tag_reader& _tag_reader,
	c_eldorado_tag_group& _tag_group,
	uint32_t _cache_file_tag_index,
	const char* _instance_name,
	const blofeld::eldorado::s_cache_file_tag_instance& _tag_header,
	const void* _tag_data_start,
	const void* _tag_data_end) :
	cache_cluster(_cache_cluster),
	tag_reader(_tag_reader),
	tag_group(_tag_group),
	cache_file_tag_index(_cache_file_tag_index),
	instance_name(_instance_name ? _strdup(_instance_name) : nullptr),
	tag_header(_tag_header),
	tag_data_start(_tag_data_start),
	tag_data_end(_tag_data_end)
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

BCS_RESULT c_eldorado_tag_instance::get_tag_file_reader(c_tag_reader*& out_tag_reader) const
{
	out_tag_reader = &tag_reader;
	return BCS_S_OK;
}

#endif // BCS_BUILD_HIGH_LEVEL_ELDORADO
