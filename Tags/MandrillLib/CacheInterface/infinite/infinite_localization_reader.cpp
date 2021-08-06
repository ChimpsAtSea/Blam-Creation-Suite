#include "mandrilllib-private-pch.h"

c_infinite_localization_reader::c_infinite_localization_reader(c_infinite_cache_cluster& cache_cluster, c_infinite_module_file_reader& cache_reader) :
	cache_cluster(cache_cluster),
	cache_reader(cache_reader)
{

}

c_infinite_localization_reader::~c_infinite_localization_reader()
{

}
