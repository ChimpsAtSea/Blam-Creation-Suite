#include "mandrilllib-private-pch.h"

c_gen3_resource_page::c_gen3_resource_page(c_gen3_cache_file& cache_file, const void* raw_data, uint32_t raw_size, uint32_t memory_size, bool is_compressed) :
	cache_file(cache_file),
	data(new char[memory_size]),
	data_size(memory_size)
{
	DEBUG_ASSERT(raw_data != nullptr);

	if (!is_compressed) // #TODO: properly detect if compression is applied
	{
		memcpy(data, raw_data, memory_size);
	}
	else
	{
		z_stream stream{};
		stream.avail_out = memory_size;
		stream.next_out = reinterpret_cast<Bytef*>(data);
		stream.avail_in = raw_size;
		stream.next_in = reinterpret_cast<const Bytef*>(raw_data);
		int inflate_init_result = inflateInit2(&stream, -15);
		//ASSERT(inflate_init_result >= Z_OK);
		int inflate_result = inflate(&stream, Z_SYNC_FLUSH);
		//ASSERT(inflate_result >= Z_OK);
		int inflate_end_result = inflateEnd(&stream);
		//ASSERT(inflate_end_result >= Z_OK);
	}
}

c_gen3_resource_page::~c_gen3_resource_page()
{
	delete[] data;
}