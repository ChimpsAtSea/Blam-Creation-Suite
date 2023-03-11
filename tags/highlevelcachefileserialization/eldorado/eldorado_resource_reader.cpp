#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO

c_eldorado_resource_reader::c_eldorado_resource_reader(c_eldorado_cache_cluster& cache_cluster, c_eldorado_cache_file_reader& cache_reader) :
	cache_cluster(cache_cluster),
	cache_reader(cache_reader)
{
	
}

c_eldorado_resource_reader::~c_eldorado_resource_reader()
{

}

#endif // BCS_BUILD_HIGH_LEVEL_ELDORADO
