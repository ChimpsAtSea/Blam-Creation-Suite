#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_HALO_4

c_halo4_resource_reader::c_halo4_resource_reader(c_halo4_cache_cluster& cache_cluster, c_halo4_cache_file_reader& cache_reader) :
	cache_cluster(cache_cluster),
	cache_reader(cache_reader)
{
	
}

c_halo4_resource_reader::~c_halo4_resource_reader()
{

}

#endif // BCS_BUILD_HIGH_LEVEL_HALO_4
