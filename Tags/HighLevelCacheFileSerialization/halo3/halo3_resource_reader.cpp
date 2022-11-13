#include "highlevelcachefileserialization-private-pch.h"

c_halo3_resource_reader::c_halo3_resource_reader(c_halo3_cache_cluster& cache_cluster, c_halo3_cache_file_reader& cache_reader) :
	cache_cluster(cache_cluster),
	cache_reader(cache_reader)
{
	
}

c_halo3_resource_reader::~c_halo3_resource_reader()
{

}
