#include "mandrilllib-private-pch.h"

class c_stopwatch
{
public:
	c_stopwatch() :
		time_point_start(),
		time_point_stop(),
		_duration()
	{

	}

	void start()
	{
		time_point_start = std::chrono::high_resolution_clock::now();
	}

	void stop()
	{
		time_point_stop = std::chrono::high_resolution_clock::now();
		_duration = time_point_stop - time_point_start;
	}

	float get_seconds()
	{
		double nanoseconds = static_cast<double>(_duration.count());
		double seconds = nanoseconds / static_cast<double>(std::chrono::nanoseconds::period::den);
		return static_cast<float>(seconds);
	}

	float get_miliseconds()
	{
		double nanoseconds = static_cast<double>(_duration.count());
		double miliseconds = nanoseconds / static_cast<double>(std::chrono::nanoseconds::period::den / std::chrono::milliseconds::period::den);
		return static_cast<float>(miliseconds);
	}

private:
	std::chrono::high_resolution_clock::time_point time_point_start;
	std::chrono::high_resolution_clock::time_point time_point_stop;
	std::chrono::high_resolution_clock::duration _duration;
};

c_cache_cluster::c_cache_cluster(const wchar_t* filepaths[], uint32_t num_files)
{
	tbb::task_group g;
	
	c_console::write_line_verbose("Creating cache cluster with %u files", num_files);
	c_stopwatch stopwatch;
	stopwatch.start();
	cache_files.resize(num_files);
	for (uint32_t i = 0; i < num_files; i++)
	{
		c_cache_file* cache_file = c_cache_file::create_cache_file(filepaths[i], this);
		cache_files[i] = cache_file;

		//g.run(
		//	[filepaths, i, this]
		//	{ 
		//		cache_files[i] = c_cache_file::create_cache_file(filepaths[i], this); 
		//		ASSERT(cache_files[i]);
		//	}
		//);
	}
	g.wait();



	for (uint32_t i = 0; i < num_files; i++)
	{
		c_cache_file* cache_file = cache_files[i];
		if (c_gen3_cache_file* gen3_cache_file = dynamic_cast<c_gen3_cache_file*>(cache_file))
		{
			gen3_cache_file->init_resources();
			gen3_cache_file->validate();
		}
	}
	g.wait();
	for (uint32_t i = 0; i < num_files; i++)
	{
		g.run(
			[i, this]
			{ 
				cache_files[i]->set_cache_cluster(this); 
			}
		);
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
