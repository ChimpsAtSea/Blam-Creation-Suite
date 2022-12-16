#include "highlevelcachefileserialization-private-pch.h"

BCS_RESULT decompress_buffer_oodle(
	const void* compressed_buffer,
	uint32_t compressed_buffer_size,
	void* uncompressed_buffer,
	uint32_t uncompressed_buffer_size)
{
	BCS_RESULT result = BCS_E_FAIL;
	void* hack_tastic_buffer = tracked_malloca(uncompressed_buffer_size + 4096);
	auto decompress_result = Kraken_Decompress(static_cast<const byte*>(compressed_buffer), compressed_buffer_size, static_cast<byte*>(hack_tastic_buffer), uncompressed_buffer_size);
	if (decompress_result == uncompressed_buffer_size)
	{
		memcpy(uncompressed_buffer, hack_tastic_buffer, uncompressed_buffer_size);
		result = BCS_S_OK;
	}
	tracked_freea(hack_tastic_buffer);
	return result;

}

c_infinite_file_entry_block_map::c_infinite_file_entry_block_map(
	int32_t file_entry_index,
	c_infinite_module_file_reader& cache_reader,
	const char* string_buffer,
	const infinite::s_module_block_entry* block_entries,
	const void* file_entry_pointer,
	s_engine_platform_build engine_platform_build
) :
	file_entry_index(file_entry_index),
	tag_index(),
	file_entry(file_entry_pointer, engine_platform_build.build),
	filepath(string_buffer + file_entry.name_offset),
	resource_file_entry_block_maps(),
	cache_reader(cache_reader),
	block_entries(block_entries),
	mapped_data(nullptr)
{

}

c_infinite_file_entry_block_map::~c_infinite_file_entry_block_map()
{
	// unmap must be called before destructor
	ASSERT(mapped_data == nullptr);
}

BCS_RESULT c_infinite_file_entry_block_map::map(void*& data)
{
	if (mapped_data != nullptr)
	{
		return BCS_E_DATA_ALREADY_MAPPED;
	}
	BCS_RESULT rs = unpack_blocks(mapped_data);
	if (BCS_SUCCEEDED(rs))
	{
		data = mapped_data;
	}
	else
	{
		mapped_data = nullptr;
		data = nullptr;
	}
	return rs;
}

bool c_infinite_file_entry_block_map::is_valid()
{
	return file_entry.block_count > 0;
}

BCS_RESULT c_infinite_file_entry_block_map::unmap(void* data)
{
	if (data != mapped_data || data == nullptr)
	{
		return BCS_E_FAIL;
	}
	delete[] mapped_data;
	mapped_data = nullptr;
	return BCS_S_OK;
}

BCS_RESULT c_infinite_file_entry_block_map::unpack_blocks(char*& data)
{
	BCS_RESULT rs = BCS_S_OK;

	s_cache_file_buffer_info data_module_buffer;
	if (BCS_FAILED(rs = cache_reader.get_buffer(static_cast<e_cache_file_buffer_index>(_module_file_buffer_data0 + file_entry.packed_data_offset.data_file_index), data_module_buffer)))
	{
		return rs;
	}

	if (file_entry.packed_data_offset.data_file_index > 1)
	{
		return BCS_S_OK;
	}

	if (file_entry.group_tag != blofeld::INVALID_TAG)
	{
		uint32_t expected_total_data_size = 0;
		expected_total_data_size += file_entry.header_data_size;
		expected_total_data_size += file_entry.tag_data_size;
		expected_total_data_size += file_entry.resource_data_size;
		expected_total_data_size += file_entry.unknown_data_size;
		ASSERT(expected_total_data_size == file_entry.uncompressed_size);
	}

	const char* read_data_buffer = data_module_buffer.begin;
	ASSERT(read_data_buffer != nullptr);
	char* write_data_buffer = new() char[file_entry.uncompressed_size];
	memset(write_data_buffer, 0xAC, file_entry.uncompressed_size);
	if (file_entry.block_count > 0)
	{

		uint32_t total_bytes_written = 0;
		for (int32_t block_index = 0; block_index < file_entry.block_count; block_index++)
		{
			const infinite::s_module_block_entry& block_entry = block_entries[file_entry.first_block_index + block_index];

			char* write_data_position = write_data_buffer + block_entry.write_offset;
			uint64_t data_offset = file_entry.packed_data_offset.data_offset + block_entry.read_offset;
			if (BCS_FAILED(rs = cache_reader.data_offset_fixup(data_offset, file_entry.packed_data_offset.data_file_index, data_offset)))
			{
				return rs;
			}
			const char* read_data_position = read_data_buffer + data_offset;
			//ASSERT(BCS_SUCCEEDED(rs = offset_to_data))

			if (block_entry.uncompressed_size > block_entry.compressed_size)
			{
				ASSERT(read_data_position != nullptr);
				BCS_RESULT decompress_result = decompress_buffer_oodle(read_data_position, block_entry.compressed_size, write_data_position, block_entry.uncompressed_size);
				ASSERT(BCS_SUCCEEDED(decompress_result));
				
			}
			else
			{
				ASSERT(block_entry.uncompressed_size <= block_entry.compressed_size);
				memcpy(write_data_position, read_data_position, block_entry.uncompressed_size);
				
			}

			total_bytes_written += block_entry.uncompressed_size;

			
		}
		ASSERT(total_bytes_written == file_entry.uncompressed_size);
	}
	//else
	//{
	//	rs = BCS_E_FAIL;
	//}
	else
	{
		char* write_data_position = write_data_buffer;
		uint64_t data_offset = file_entry.packed_data_offset.data_offset;
		if (BCS_FAILED(rs = cache_reader.data_offset_fixup(data_offset, file_entry.packed_data_offset.data_file_index, data_offset)))
		{
			return rs;
		}
		const char* read_data_position = read_data_buffer + data_offset;

		if (file_entry.uncompressed_size > file_entry.compressed_size)
		{
			BCS_RESULT decompress_result = decompress_buffer_oodle(read_data_position, file_entry.compressed_size, write_data_position, file_entry.uncompressed_size);
			if (BCS_FAILED(decompress_result))
			{
				delete[] write_data_buffer;
				return BCS_E_FAIL;
			}
			//ASSERT(BCS_SUCCEEDED(decompress_result));
			
		}
		else
		{
			memcpy(write_data_buffer, read_data_buffer, file_entry.uncompressed_size);
		}
	}

	data = write_data_buffer;

	return rs;
}
