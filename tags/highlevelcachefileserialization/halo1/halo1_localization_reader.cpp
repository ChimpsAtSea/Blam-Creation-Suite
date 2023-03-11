#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_HALO_1

c_halo1_localization_reader::c_halo1_localization_reader(c_halo1_cache_cluster& cache_cluster, c_halo1_cache_file_reader& cache_reader) :
	cache_cluster(cache_cluster),
	cache_reader(cache_reader)
{

}

c_halo1_localization_reader::~c_halo1_localization_reader()
{

}

#endif // BCS_BUILD_HIGH_LEVEL_HALO_1
