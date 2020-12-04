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
		if (c_gen3_cache_file* gen3_cache_file = dynamic_cast<c_gen3_cache_file*>(cache_file))
		{
			gen3_cache_file->validate();
		}

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

uint32_t c_cache_cluster::encode_page_address(uint32_t file_index, uint64_t offset)
{
	DEBUG_ASSERT((offset % 4) == 0); // expect 4 byte alignment for the offset
	DEBUG_ASSERT(file_index < 4); // can only support 4 files with current address schema

	uint32_t custom_bits = 0x80000000;
	custom_bits |= (file_index << 28u) & 0x60000000;
	custom_bits |= static_cast<uint32_t>(offset / 4ull) & 0x1FFFFFFF;

	return custom_bits;
}

bool c_cache_cluster::decode_page_address(uint32_t page_address, uint32_t& file_index, uint64_t& offset)
{
	if (page_address & 0x80000000)
	{
		uint32_t custom_bits = page_address & 0x7FFFFFFF;
		file_index = (custom_bits & 0x60000000) >> 28u; // bit 30-31
		offset = static_cast<uint64_t>(custom_bits & 0x1FFFFFFF) * 4ull; // bit 0-28 (represents 2GB of address space)

		return true;
	}
	return false;
}

bool c_cache_cluster::is_valid_data_address(void* data) const
{
	for (c_cache_file* cache_file : cache_files)
	{
		if (c_gen3_cache_file* gen3_cache_file = dynamic_cast<c_gen3_cache_file*>(cache_file))
		{
			if (gen3_cache_file->is_valid_data_address(data))
			{
				return true;
			}
		}
	}
	return false;
}
