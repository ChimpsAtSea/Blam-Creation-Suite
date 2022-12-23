#pragma once

class c_eldorado_cache_cluster;
class c_eldorado_cache_file_reader;

class c_eldorado_localization_reader : public c_localization_reader
{
public:
	c_eldorado_localization_reader(c_eldorado_cache_cluster& cache_cluster, c_eldorado_cache_file_reader& cache_reader);
	~c_eldorado_localization_reader();

private:
	c_eldorado_cache_cluster& cache_cluster;
	c_eldorado_cache_file_reader& cache_reader;
};
