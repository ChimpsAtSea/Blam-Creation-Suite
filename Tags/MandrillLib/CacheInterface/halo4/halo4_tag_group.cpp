#include "mandrilllib-private-pch.h"

c_halo4_tag_group::c_halo4_tag_group(c_halo4_cache_cluster& cache_cluster, tag group_tag, const char* group_name, c_halo4_tag_group* parent) :
	group_tag(group_tag),
	group_name(group_name),
	cache_cluster(cache_cluster),
	parent(parent),
	blofeld_tag_group(blofeld::get_group_tag_by_group_tag(cache_cluster.engine_platform_build.engine_type, group_tag))
{

}

c_halo4_tag_group::~c_halo4_tag_group()
{

}

BCS_RESULT c_halo4_tag_group::get_blofeld_tag_group(const blofeld::s_tag_group*& out_blofeld_tag_group) const
{
	if (blofeld_tag_group == nullptr)
	{
		return BCS_E_NOT_IMPLEMENTED;
	}

	out_blofeld_tag_group = blofeld_tag_group;

	return BCS_S_OK;
}

