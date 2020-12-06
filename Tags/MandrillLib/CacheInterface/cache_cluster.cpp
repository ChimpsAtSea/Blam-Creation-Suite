#include "mandrilllib-private-pch.h"

c_cache_cluster::c_cache_cluster(const wchar_t* filepaths[], uint32_t num_files)
{
	tbb::task_group g;
	
	c_console::write_line_verbose("Creating cache cluster with %u files", num_files);
	c_stopwatch stopwatch;
	stopwatch.start();
	cache_files.resize(num_files);
	for (uint32_t i = 0; i < num_files; i++)
	{
		g.run([filepaths, i, this]
			{
				cache_files[i] = c_cache_file::create_cache_file(filepaths[i], this);
				ASSERT(cache_files[i]);
			});
	}
	g.wait();
	for (uint32_t i = 0; i < num_files; i++)
	{
		g.run([filepaths, i, this]
			{
				c_cache_file* cache_file = cache_files[i];
				if (c_gen3_cache_file* gen3_cache_file = dynamic_cast<c_gen3_cache_file*>(cache_file))
				{
					gen3_cache_file->init_resources();
					gen3_cache_file->validate();
				}
			});
	}
	g.wait();
	for (uint32_t i = 0; i < num_files; i++)
	{
		g.run([i, this]
			{ 
				cache_files[i]->set_cache_cluster(this); 
			});
	}
	g.wait();
	stopwatch.stop();
	c_console::write_line_verbose("Finished creating cache cluster in %.2fms", stopwatch.get_miliseconds());
}

c_cache_cluster::c_cache_cluster(const wchar_t* directory)
{
	
}

c_cache_cluster::~c_cache_cluster()
{
	for (c_cache_file* cache_file : cache_files)
	{
		delete cache_file;
	}
}

c_cache_file* c_cache_cluster::get_cache_file_by_dvd_path(const char* dvd_path)
{
	for (c_cache_file* cache_file : cache_files)
	{
		const char* map_filepath = cache_file->get_map_filepath_utf8();
		if (strstr(map_filepath, dvd_path) != nullptr)
		{
			return cache_file;
		}
	}
	return nullptr;
}
