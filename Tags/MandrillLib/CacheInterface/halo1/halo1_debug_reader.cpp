#include "mandrilllib-private-pch.h"

c_halo1_debug_reader::c_halo1_debug_reader(c_halo1_cache_cluster& cache_cluster, c_halo1_cache_file_reader& cache_reader) :
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

	//halo1::xbox360::s_cache_file_header& cache_file_header = cache_reader.cache_file_header;

	//long string_id_index_buffer_relative_offset = cache_file_header.string_id_index_buffer_offset - buffers_info.debug_section_buffer.offset;
	//string_id_index_buffer = reinterpret_cast<const unsigned long*>(buffers_info.debug_section_buffer.begin + string_id_index_buffer_relative_offset);

	////string_id_index_buffer = static_cast<unsigned long*>(_aligned_malloc(cache_file_header.string_id_string_storage_size, sizeof(unsigned long)));
	////if (string_id_index_buffer == nullptr)
	////{
	////	throw(BCS_E_FAIL);
	////}
	////memcpy(string_id_index_buffer, string_id_index_buffer, cache_file_header.string_id_index_buffer_count * sizeof(unsigned long));
	////for (long string_id_index = 0; string_id_index < cache_file_header.string_id_index_buffer_count; string_id_index++)
	////{
	////	string_id_index_buffer[string_id_index] = _byteswap_ulong(string_id_index_buffer[string_id_index]);
	////}

	//long string_id_buffer_relative_offset = cache_file_header.string_id_string_storage_offset - buffers_info.debug_section_buffer.offset;
	//const char* encrypted_string_id_buffer = reinterpret_cast<const char*>(buffers_info.debug_section_buffer.begin + string_id_buffer_relative_offset);

	//string_id_buffer = static_cast<char*>(_aligned_malloc(cache_file_header.string_id_string_storage_size, sizeof(__m128i)));
	//if (string_id_buffer == nullptr)
	//{
	//	throw(BCS_E_FAIL);
	//}
	//memcpy(string_id_buffer, encrypted_string_id_buffer, cache_file_header.string_id_string_storage_size);
	//halo1_aes128_decrypt(encrypted_string_id_buffer, string_id_buffer, cache_file_header.string_id_string_storage_size, c_halo1_cache_file_reader::k_string_id_encryption_key);


	//long file_table_index_buffer_relative_offset = cache_file_header.file_table_indices_offset - buffers_info.debug_section_buffer.offset;
	//file_table_index_buffer = reinterpret_cast<const unsigned long*>(buffers_info.debug_section_buffer.begin + file_table_index_buffer_relative_offset);

	//long file_table_buffer_relative_offset = cache_file_header.file_table_offset - buffers_info.debug_section_buffer.offset;
	//const char* encrypted_file_table_buffer = reinterpret_cast<const char*>(buffers_info.debug_section_buffer.begin + file_table_buffer_relative_offset);

	//file_table_buffer = static_cast<char*>(_aligned_malloc(cache_file_header.file_table_length, sizeof(__m128i)));
	//if (file_table_buffer == nullptr)
	//{
	//	throw(BCS_E_FAIL);
	//}
	//memcpy(file_table_buffer, encrypted_file_table_buffer, cache_file_header.file_table_length);
	//halo1_aes128_decrypt(encrypted_file_table_buffer, file_table_buffer, cache_file_header.file_table_length, c_halo1_cache_file_reader::k_file_name_encryption_key);

	////DEBUG_ASSERT(cache_file_header.string_id_index_buffer_count >= k_engine_string_ids_total);
	////string_id_table_buffer = new() const char* [cache_file_header.string_id_index_buffer_count];

	////unsigned long const cache_file_string_id_count = cache_file_header.string_id_index_buffer_count - k_engine_string_ids_total;

	////unsigned long string_index = 0;
	////unsigned long string_buffer_index = 0;
	////{ // process engine string ids
	////	for (unsigned long set_index = 0; set_index < k_engine_string_id_namespace_count; set_index++)
	////	{
	////		unsigned long set_count = k_engine_set_counts[set_index];
	////		unsigned long set_total_strings = set_count;

	////		string_id_table->count = set_total_strings;
	////		string_id_table->strings = string_id_table_buffer + string_buffer_index;

	////		for (unsigned long set_string_index = 0; set_string_index < set_count; set_string_index++)
	////		{
	////			//long string_id_buffer_offset = string_id_index_buffer[string_index];
	////			long string_id_buffer_offset = _byteswap_ulong(string_id_index_buffer[string_index]);
	////			const char* string_id = string_id_buffer_unencrypted + string_id_buffer_offset;

	////			string_id_table_buffer[string_buffer_index++] = string_id;

	////			debug_point;
	////			string_index++;
	////		}
	////		if (set_index == 0)
	////		{
	////			set_total_strings += cache_file_string_id_count;
	////			string_buffer_index += cache_file_string_id_count;
	////		}
	////		debug_point;
	////	}
	////}
	////{ // process cache string ids
	////	string_buffer_index = k_engine_set_counts[0];
	////	DEBUG_ASSERT(string_index == k_engine_string_ids_total); // sanity check
	////	for (; string_index < cache_file_header.string_id_index_buffer_count; string_index++)
	////	{
	////		//long string_id_buffer_offset = string_id_index_buffer[string_index];
	////		long string_id_buffer_offset = _byteswap_ulong(string_id_index_buffer[string_index]);
	////		const char* string_id = string_id_buffer_unencrypted + string_id_buffer_offset;

	////		string_id_table_buffer[string_buffer_index++] = string_id;

	////		debug_point;
	////	}
	////}

	//debug_point;
}

c_halo1_debug_reader::~c_halo1_debug_reader()
{
	tracked_aligned_free(string_id_buffer);
	//tracked_aligned_free(string_id_index_buffer);
	tracked_aligned_free(file_table_buffer);
}

BCS_RESULT c_halo1_debug_reader::string_id_to_string(string_id stringid, const char*& string)
{
	unsigned long const string_id_index = (stringid >> string_id_index_shift) & string_id_index_mask;
	unsigned long const string_id_namespace = (stringid >> string_id_namespace_shift) & string_id_namespace_mask;
	unsigned long const string_id_length = (stringid >> string_id_length_shift) & string_id_length_mask;

	return string_id_to_string(string_id_index, string_id_namespace, string_id_length, string);
}

BCS_RESULT c_halo1_debug_reader::string_id_to_string(unsigned long string_id_index, unsigned long string_id_namespace, unsigned long string_id_length, const char*& string)
{
	BCS_RESULT rs = BCS_S_OK;

	unsigned long string_index;
	if (BCS_FAILED(rs = string_id_to_index(string_id_index, string_id_namespace, string_id_length, string_index)))
	{
		return rs;
	}

	long string_id_buffer_offset = _byteswap_ulong(string_id_index_buffer[string_index]);
	string = string_id_buffer + string_id_buffer_offset;

	return rs;
}


BCS_RESULT c_halo1_debug_reader::get_tag_filepath(unsigned long tag_index, const char*& filepath)
{
	BCS_RESULT rs = BCS_S_OK;

	s_cache_file_buffer_info buffer_info;
	if (BCS_FAILED(rs = cache_reader.get_buffer(_tag_section_buffer, buffer_info)))
	{
		return rs;
	}

	halo1::s_cache_file_tags_header tags_header = *reinterpret_cast<const halo1::s_cache_file_tags_header*>(buffer_info.begin);

	int32_t tag_instances_relative_offset;
	if (BCS_FAILED(rs = cache_reader.virtual_address_to_relative_offset(tags_header.tag_instances_address, tag_instances_relative_offset)))
	{
		return rs;
	}

	const halo1::s_cache_file_tag_instance* tag_instances_read_pointer = reinterpret_cast<const halo1::s_cache_file_tag_instance*>(buffer_info.begin + tag_instances_relative_offset);

	const halo1::s_cache_file_tag_instance& tag_instance = tag_instances_read_pointer[tag_index];


	int32_t name_relative_offset;
	if (BCS_FAILED(rs = cache_reader.virtual_address_to_relative_offset(tag_instance.name_address, name_relative_offset)))
	{
		return rs;
	}

	filepath = buffer_info.begin + name_relative_offset;

	return rs;
}

BCS_RESULT c_halo1_debug_reader::get_group_name(tag group_tag, const char*& group_name)
{
	return BCS_S_OK;
}

BCS_RESULT c_halo1_debug_reader::get_group_id(tag group_tag, const char*& group_id)
{
	return BCS_S_OK;
}

BCS_RESULT c_halo1_debug_reader::string_id_to_index(string_id stringid, unsigned long& string_index)
{
	unsigned long const string_id_index = (stringid & string_id_index_mask) >> string_id_index_shift;
	unsigned long const string_id_namespace = (stringid & string_id_namespace_mask) >> string_id_namespace_shift;
	unsigned long const string_id_length = (stringid & string_id_length_mask) >> string_id_length_shift;

	return string_id_to_index(string_id_index, string_id_namespace, string_id_length, string_index);
}

BCS_RESULT c_halo1_debug_reader::string_id_to_index(unsigned long string_id_index, unsigned long string_id_namespace, unsigned long string_id_length, unsigned long& string_index)
{
	return BCS_E_NOT_IMPLEMENTED;
}
