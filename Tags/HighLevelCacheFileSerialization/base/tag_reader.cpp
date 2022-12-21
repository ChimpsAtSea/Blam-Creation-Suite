#include "highlevelcachefileserialization-private-pch.h"

c_tag_reader::c_tag_reader(c_cache_cluster& _cache_cluster, c_cache_file_reader& _cache_file_reader) :
	cache_cluster(_cache_cluster),
	cache_file_reader(_cache_file_reader)
{

}

c_tag_reader::~c_tag_reader()
{

}

BCS_RESULT c_tag_reader::get_cache_cluster(c_cache_cluster*& out_cache_cluster) const
{
	out_cache_cluster = &cache_cluster;
	return BCS_S_OK;
}

BCS_RESULT c_tag_reader::get_cache_file_reader(c_cache_file_reader*& out_cache_file_reader) const
{
	out_cache_file_reader = &cache_file_reader;
	return BCS_S_OK;
}