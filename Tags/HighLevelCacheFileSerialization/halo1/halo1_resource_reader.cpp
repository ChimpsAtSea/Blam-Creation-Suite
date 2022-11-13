#include "highlevelcachefileserialization-private-pch.h"

c_halo1_resource_reader::c_halo1_resource_reader(c_halo1_cache_cluster& cache_cluster, c_halo1_cache_file_reader& cache_reader) :
	cache_cluster(cache_cluster),
	cache_reader(cache_reader)
{
	
}

c_halo1_resource_reader::~c_halo1_resource_reader()
{

}
