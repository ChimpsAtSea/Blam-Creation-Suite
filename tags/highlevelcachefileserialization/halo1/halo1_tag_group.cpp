#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_HALO1

c_halo1_tag_group::c_halo1_tag_group(c_halo1_cache_cluster& cache_cluster, blofeld::s_tag_group const& blofeld_tag_group, c_halo1_tag_group* parent) :
	cache_cluster(cache_cluster),
	parent(parent),
	blofeld_tag_group(blofeld_tag_group)
{

}

c_halo1_tag_group::~c_halo1_tag_group()
{

}

BCS_RESULT c_halo1_tag_group::get_blofeld_tag_group(blofeld::s_tag_group const*& out_blofeld_tag_group) const
{
	out_blofeld_tag_group = &blofeld_tag_group;
	return BCS_S_OK;
}

BCS_RESULT c_halo1_tag_group::get_group_tag(tag& out_group_tag) const
{
	out_group_tag = blofeld_tag_group.group_tag;
	return BCS_S_OK;
}

BCS_RESULT c_halo1_tag_group::get_group_name(const char*& out_group_name) const
{
	out_group_name = blofeld_tag_group.name;
	return BCS_S_OK;
}

BCS_RESULT c_halo1_tag_group::get_group_short_name(const char*& out_group_short_name) const
{
	out_group_short_name = blofeld_tag_group.group_tag_short_string;
	return BCS_S_OK;
}

#endif // BCS_BUILD_HIGH_LEVEL_HALO1