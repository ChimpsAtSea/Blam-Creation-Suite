#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3

c_halo3_localization_reader::c_halo3_localization_reader(c_halo3_cache_cluster& cache_cluster, c_halo3_cache_file_reader& cache_reader) :
	cache_cluster(cache_cluster),
	cache_reader(cache_reader)
{

}

c_halo3_localization_reader::~c_halo3_localization_reader()
{

}

#endif // BCS_BUILD_HIGH_LEVEL_HALO_3
