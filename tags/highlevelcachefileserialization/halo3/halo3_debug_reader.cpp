#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_HALO3

c_halo3_debug_reader::c_halo3_debug_reader(c_halo3_cache_cluster& cache_cluster, c_halo3_cache_file_reader& cache_reader) :
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
	s_cache_file_buffers_info buffers_info;
	BCS_FAIL_THROW(cache_reader.get_buffers(buffers_info));

	int32_t string_id_index_buffer_offset;
	BCS_FAIL_THROW(cache_reader.get_string_id_index_buffer_offset(string_id_index_buffer_offset));

	int32_t string_id_string_storage_offset;
	BCS_FAIL_THROW(cache_reader.get_string_id_string_storage_offset(string_id_string_storage_offset));

	int32_t string_id_string_storage_size;
	BCS_FAIL_THROW(cache_reader.get_string_id_string_storage_size(string_id_string_storage_size));

	int32_t file_table_indices_offset;
	BCS_FAIL_THROW(cache_reader.get_file_table_indices_offset(file_table_indices_offset));

	int32_t file_table_offset;
	BCS_FAIL_THROW(cache_reader.get_file_table_offset(file_table_offset));

	int32_t file_table_length;
	BCS_FAIL_THROW(cache_reader.get_file_table_length(file_table_length));

	int32_t string_id_index_buffer_relative_offset = string_id_index_buffer_offset - buffers_info.debug_section_buffer.offset;
	string_id_index_buffer = reinterpret_cast<const uint32_t*>(buffers_info.debug_section_buffer.begin + string_id_index_buffer_relative_offset);

	int32_t string_id_buffer_relative_offset = string_id_string_storage_offset - buffers_info.debug_section_buffer.offset;
	const char* encrypted_string_id_buffer = reinterpret_cast<const char*>(buffers_info.debug_section_buffer.begin + string_id_buffer_relative_offset);

	string_id_buffer = static_cast<char*>(tracked_aligned_malloc(string_id_string_storage_size, sizeof(__m128i)));
	if (string_id_buffer == nullptr)
	{
		throw(BCS_E_FAIL);
	}
	memcpy(string_id_buffer, encrypted_string_id_buffer, string_id_string_storage_size);
	//aes128_decrypt(encrypted_string_id_buffer, string_id_buffer, cache_file_header.string_id_string_storage_size, c_halo3_cache_file_reader::k_string_id_encryption_key);

	int32_t file_table_index_buffer_relative_offset = file_table_indices_offset - buffers_info.debug_section_buffer.offset;
	file_table_index_buffer = reinterpret_cast<const uint32_t*>(buffers_info.debug_section_buffer.begin + file_table_index_buffer_relative_offset);

	int32_t file_table_buffer_relative_offset = file_table_offset - buffers_info.debug_section_buffer.offset;
	const char* encrypted_file_table_buffer = reinterpret_cast<const char*>(buffers_info.debug_section_buffer.begin + file_table_buffer_relative_offset);

	file_table_buffer = static_cast<char*>(tracked_aligned_malloc(file_table_length, sizeof(__m128i)));
	if (file_table_buffer == nullptr)
	{
		throw(BCS_E_FAIL);
	}
	memcpy(file_table_buffer, encrypted_file_table_buffer, file_table_length);
	//aes128_decrypt(encrypted_file_table_buffer, file_table_buffer, cache_file_header.file_table_length, c_halo3_cache_file_reader::k_file_name_encryption_key);

	
}

c_halo3_debug_reader::~c_halo3_debug_reader()
{
	tracked_aligned_free(string_id_buffer);
	//tracked_aligned_free(string_id_index_buffer);
	tracked_aligned_free(file_table_buffer);
}

BCS_RESULT c_halo3_debug_reader::string_id_to_string(string_id stringid, const char*& string)
{
	uint32_t const string_id_index = (stringid >> string_id_index_shift) & string_id_index_mask;
	uint32_t const string_id_namespace = (stringid >> string_id_namespace_shift) & string_id_namespace_mask;
	uint32_t const string_id_length = (stringid >> string_id_length_shift) & string_id_length_mask;

	return string_id_to_string(string_id_index, string_id_namespace, string_id_length, string);
}

BCS_RESULT c_halo3_debug_reader::string_id_to_string(uint32_t string_id_index, uint32_t string_id_namespace, uint32_t string_id_length, const char*& string)
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


BCS_RESULT c_halo3_debug_reader::get_tag_filepath(uint32_t tag_index, const char*& filepath)
{
	BCS_RESULT rs = BCS_S_OK;

	int32_t file_count;
	if (BCS_FAILED(rs = cache_reader.get_file_count(file_count)))
	{
		return rs;
	}

	if (tag_index < 0 || tag_index > static_cast<unsigned long>(file_count))
	{
		return BCS_E_FAIL;
	}

	uint32_t file_buffer_offset = _byteswap_ulong(file_table_index_buffer[tag_index]);
	filepath = file_table_buffer + file_buffer_offset;

	return rs;
}

BCS_RESULT c_halo3_debug_reader::get_group_name(tag group_tag, const char*& group_name)
{
	return BCS_S_OK;
}

BCS_RESULT c_halo3_debug_reader::get_group_id(tag group_tag, const char*& group_id)
{
	return BCS_S_OK;
}

BCS_RESULT c_halo3_debug_reader::string_id_to_index(string_id stringid, uint32_t& string_index)
{
	uint32_t const string_id_index = (stringid & string_id_index_mask) >> string_id_index_shift;
	uint32_t const string_id_namespace = (stringid & string_id_namespace_mask) >> string_id_namespace_shift;
	uint32_t const string_id_length = (stringid & string_id_length_mask) >> string_id_length_shift;

	return string_id_to_index(string_id_index, string_id_namespace, string_id_length, string_index);
}

BCS_RESULT c_halo3_debug_reader::string_id_to_index(uint32_t string_id_index, uint32_t string_id_namespace, uint32_t string_id_length, uint32_t& string_index)
{
	int32_t string_id_index_buffer_count;
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = cache_reader.get_string_id_index_buffer_count(string_id_index_buffer_count)))
	{
		return rs;
	}

	switch (cache_cluster.engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
	{
		if (string_id_namespace > k_xbox360_engine_string_id_namespace_count)
		{
			return BCS_E_FAIL;
		}
		if (string_id_namespace == 0 && string_id_index > (string_id_index_buffer_count - (k_xbox360_engine_string_ids_total - k_xbox360_engine_set_counts[0])))
		{
			return BCS_E_FAIL;
		}
		if (string_id_namespace > 0 && string_id_index > k_xbox360_engine_set_counts[string_id_namespace])
		{
			return BCS_E_FAIL;
		}

		uint32_t offset = 0;
		if (string_id_namespace == 0 && string_id_index >= k_xbox360_engine_set_counts[0])
		{
			offset = k_xbox360_engine_string_ids_total - k_xbox360_engine_set_counts[0];
		}
		else
		{
			for (uint32_t namespace_index = 0; namespace_index < string_id_namespace; namespace_index++) // #TODO: pre calculate this table
			{
				// offset += cache_file.string_id_namespace_table[namespace_index] & 0x1FFFF; // halo reach cache table
				offset += k_xbox360_engine_set_counts[namespace_index];
			}
		}
		string_index = string_id_index + offset;
	}
	return rs;
	}
	return BCS_E_UNSUPPORTED;
}

#endif // BCS_BUILD_HIGH_LEVEL_HALO3
