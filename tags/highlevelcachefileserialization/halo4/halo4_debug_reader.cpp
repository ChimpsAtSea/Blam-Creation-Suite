#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_HALO4

c_halo4_debug_reader::c_halo4_debug_reader(c_halo4_cache_cluster& cache_cluster, c_halo4_cache_file_reader& cache_reader) :
	cache_cluster(cache_cluster),
	cache_reader(cache_reader),
	string_id_buffer(),
	//string_id_index_buffer(),
	file_table_buffer(),
	string_id_index_buffer(),
	encrypted_string_id_buffer(),
	encrypted_file_table_buffer(),
	file_table_index_buffer()
{
	BCS_RESULT rs;

	s_cache_file_buffers_info buffers_info;
	if (BCS_FAILED(rs = cache_reader.get_buffers(buffers_info)))
	{
		throw(rs);
	}

	halo4::xbox360::s_cache_file_header& cache_file_header = cache_reader.cache_file_header;

	int32_t string_id_index_buffer_relative_offset = cache_file_header.string_id_index_buffer_offset - buffers_info.debug_section_buffer.offset;
	string_id_index_buffer = reinterpret_cast<const unsigned long*>(buffers_info.debug_section_buffer.begin + string_id_index_buffer_relative_offset);

	//string_id_index_buffer = static_cast<unsigned long*>(_aligned_malloc(cache_file_header.string_id_string_storage_size, sizeof(unsigned long)));
	//if (string_id_index_buffer == nullptr)
	//{
	//	throw(BCS_E_FAIL);
	//}
	//memcpy(string_id_index_buffer, string_id_index_buffer, cache_file_header.string_id_index_buffer_count * sizeof(unsigned long));
	//for (int32_t string_id_index = 0; string_id_index < cache_file_header.string_id_index_buffer_count; string_id_index++)
	//{
	//	string_id_index_buffer[string_id_index] = _byteswap_ulong(string_id_index_buffer[string_id_index]);
	//}

	int32_t string_id_buffer_relative_offset = cache_file_header.string_id_string_storage_offset - buffers_info.debug_section_buffer.offset;
	const char* encrypted_string_id_buffer = reinterpret_cast<const char*>(buffers_info.debug_section_buffer.begin + string_id_buffer_relative_offset);

	string_id_buffer = static_cast<char*>(tracked_aligned_malloc(halo4_cache_interface_tracked_memory, cache_file_header.string_id_string_storage_size, sizeof(__m128i)));
	if (string_id_buffer == nullptr)
	{
		throw(BCS_E_FAIL);
	}
	memcpy(string_id_buffer, encrypted_string_id_buffer, cache_file_header.string_id_string_storage_size);
	halo4_aes128_decrypt(encrypted_string_id_buffer, string_id_buffer, cache_file_header.string_id_string_storage_size, c_halo4_cache_file_reader::k_string_id_encryption_key);


	int32_t file_table_index_buffer_relative_offset = cache_file_header.file_table_indices_offset - buffers_info.debug_section_buffer.offset;
	file_table_index_buffer = reinterpret_cast<const unsigned long*>(buffers_info.debug_section_buffer.begin + file_table_index_buffer_relative_offset);

	int32_t file_table_buffer_relative_offset = cache_file_header.file_table_offset - buffers_info.debug_section_buffer.offset;
	const char* encrypted_file_table_buffer = reinterpret_cast<const char*>(buffers_info.debug_section_buffer.begin + file_table_buffer_relative_offset);

	file_table_buffer = static_cast<char*>(tracked_aligned_malloc(halo4_cache_interface_tracked_memory, cache_file_header.file_table_length, sizeof(__m128i)));
	if (file_table_buffer == nullptr)
	{
		throw(BCS_E_FAIL);
	}
	memcpy(file_table_buffer, encrypted_file_table_buffer, cache_file_header.file_table_length);
	halo4_aes128_decrypt(encrypted_file_table_buffer, file_table_buffer, cache_file_header.file_table_length, c_halo4_cache_file_reader::k_file_name_encryption_key);

	//DEBUG_ASSERT(cache_file_header.string_id_index_buffer_count >= k_engine_string_ids_total);
	//string_id_table_buffer = new() const char* [cache_file_header.string_id_index_buffer_count];

	//uint32_t const cache_file_string_id_count = cache_file_header.string_id_index_buffer_count - k_engine_string_ids_total;

	//uint32_t string_index = 0;
	//uint32_t string_buffer_index = 0;
	//{ // process engine string ids
	//	for (uint32_t set_index = 0; set_index < k_engine_string_id_namespace_count; set_index++)
	//	{
	//		uint32_t set_count = k_engine_set_counts[set_index];
	//		uint32_t set_total_strings = set_count;

	//		string_id_table->count = set_total_strings;
	//		string_id_table->strings = string_id_table_buffer + string_buffer_index;

	//		for (uint32_t set_string_index = 0; set_string_index < set_count; set_string_index++)
	//		{
	//			//int32_t string_id_buffer_offset = string_id_index_buffer[string_index];
	//			int32_t string_id_buffer_offset = _byteswap_ulong(string_id_index_buffer[string_index]);
	//			const char* string_id = string_id_buffer_unencrypted + string_id_buffer_offset;

	//			string_id_table_buffer[string_buffer_index++] = string_id;

	//			
	//			string_index++;
	//		}
	//		if (set_index == 0)
	//		{
	//			set_total_strings += cache_file_string_id_count;
	//			string_buffer_index += cache_file_string_id_count;
	//		}
	//		
	//	}
	//}
	//{ // process cache string ids
	//	string_buffer_index = k_engine_set_counts[0];
	//	DEBUG_ASSERT(string_index == k_engine_string_ids_total); // sanity check
	//	for (; string_index < cache_file_header.string_id_index_buffer_count; string_index++)
	//	{
	//		//int32_t string_id_buffer_offset = string_id_index_buffer[string_index];
	//		int32_t string_id_buffer_offset = _byteswap_ulong(string_id_index_buffer[string_index]);
	//		const char* string_id = string_id_buffer_unencrypted + string_id_buffer_offset;

	//		string_id_table_buffer[string_buffer_index++] = string_id;

	//		
	//	}
	//}

	
}

c_halo4_debug_reader::~c_halo4_debug_reader()
{
	tracked_aligned_free(string_id_buffer);
	//tracked_aligned_free(string_id_index_buffer);
	tracked_aligned_free(file_table_buffer);
}

BCS_RESULT c_halo4_debug_reader::string_id_to_string(string_id stringid, const char*& string)
{
	uint32_t const string_id_index = (stringid >> string_id_index_shift) & string_id_index_mask;
	uint32_t const string_id_namespace = (stringid >> string_id_namespace_shift) & string_id_namespace_mask;
	uint32_t const string_id_length = (stringid >> string_id_length_shift) & string_id_length_mask;

	return string_id_to_string(string_id_index, string_id_namespace, string_id_length, string);
}

BCS_RESULT c_halo4_debug_reader::string_id_to_string(uint32_t string_id_index, uint32_t string_id_namespace, uint32_t string_id_length, const char*& string)
{
	BCS_RESULT rs = BCS_S_OK;

	uint32_t string_index;
	if (BCS_FAILED(rs = string_id_to_index(string_id_index, string_id_namespace, string_id_length, string_index)))
	{
		return rs;
	}

	int32_t string_id_buffer_offset = _byteswap_ulong(string_id_index_buffer[string_index]);
	string = string_id_buffer + string_id_buffer_offset;

	return rs;
}


BCS_RESULT c_halo4_debug_reader::get_tag_filepath(uint32_t tag_index, const char*& filepath)
{
	halo4::xbox360::s_cache_file_header& cache_file_header = cache_reader.cache_file_header;

	if (tag_index < 0 || tag_index > static_cast<unsigned long>(cache_file_header.file_count))
	{
		return BCS_E_FAIL;
	}

	uint32_t file_buffer_offset = _byteswap_ulong(file_table_index_buffer[tag_index]);
	filepath = file_table_buffer + file_buffer_offset;

	return BCS_S_OK;
}

BCS_RESULT c_halo4_debug_reader::get_group_name(tag group_tag, const char*& group_name)
{
	return BCS_S_OK;
}

BCS_RESULT c_halo4_debug_reader::get_group_id(tag group_tag, const char*& group_id)
{
	return BCS_S_OK;
}

BCS_RESULT c_halo4_debug_reader::string_id_to_index(string_id stringid, uint32_t& string_index)
{
	uint32_t const string_id_index = (stringid & string_id_index_mask) >> string_id_index_shift;
	uint32_t const string_id_namespace = (stringid & string_id_namespace_mask) >> string_id_namespace_shift;
	uint32_t const string_id_length = (stringid & string_id_length_mask) >> string_id_length_shift;

	return string_id_to_index(string_id_index, string_id_namespace, string_id_length, string_index);
}

BCS_RESULT c_halo4_debug_reader::string_id_to_index(uint32_t string_id_index, uint32_t string_id_namespace, uint32_t string_id_length, uint32_t& string_index)
{
	halo4::xbox360::s_cache_file_header& cache_file_header = cache_reader.cache_file_header;

	if (string_id_namespace > k_engine_string_id_namespace_count)
	{
		return BCS_E_FAIL;
	}
	if (string_id_namespace == 0 && string_id_index > (cache_file_header.string_id_index_buffer_count - (k_engine_string_ids_total - k_engine_set_counts[0])))
	{
		return BCS_E_FAIL;
	}
	if (string_id_namespace > 0 && string_id_index > k_engine_set_counts[string_id_namespace])
	{
		return BCS_E_FAIL;
	}

	uint32_t offset = 0;
	if (string_id_namespace == 0 && string_id_index >= k_engine_set_counts[0])
	{
		offset = k_engine_string_ids_total - k_engine_set_counts[0];
	}
	else
	{
		for (uint32_t namespace_index = 0; namespace_index < string_id_namespace; namespace_index++) // #TODO: pre calculate this table
		{
			// offset += cache_file.string_id_namespace_table[namespace_index] & 0x1FFFF; // halo reach cache table
			offset += k_engine_set_counts[namespace_index];
		}
	}
	string_index = string_id_index + offset;

	return BCS_S_OK;
}

#endif // BCS_BUILD_HIGH_LEVEL_HALO4
