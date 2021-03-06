#include "mandrilllib-private-pch.h"

__m128i __vectorcall aes_128_key_expansion(__m128i key, __m128i keygened)
{
	keygened = _mm_shuffle_epi32(keygened, _MM_SHUFFLE(3, 3, 3, 3));
	key = _mm_xor_si128(key, _mm_slli_si128(key, 4));
	key = _mm_xor_si128(key, _mm_slli_si128(key, 4));
	key = _mm_xor_si128(key, _mm_slli_si128(key, 4));
	return _mm_xor_si128(key, keygened);
}

void __vectorcall aes128_generate_key_schedule(const __m128i* key, __m128i* key_schedule)
{
#define _aes_128_key_expansion(k, rcon) aes_128_key_expansion(k, _mm_aeskeygenassist_si128(k, rcon))

	key_schedule[0] = _mm_loadu_si128(key);
	key_schedule[1] = _aes_128_key_expansion(key_schedule[0], 0x01);
	key_schedule[2] = _aes_128_key_expansion(key_schedule[1], 0x02);
	key_schedule[3] = _aes_128_key_expansion(key_schedule[2], 0x04);
	key_schedule[4] = _aes_128_key_expansion(key_schedule[3], 0x08);
	key_schedule[5] = _aes_128_key_expansion(key_schedule[4], 0x10);
	key_schedule[6] = _aes_128_key_expansion(key_schedule[5], 0x20);
	key_schedule[7] = _aes_128_key_expansion(key_schedule[6], 0x40);
	key_schedule[8] = _aes_128_key_expansion(key_schedule[7], 0x80);
	key_schedule[9] = _aes_128_key_expansion(key_schedule[8], 0x1B);
	key_schedule[10] = _aes_128_key_expansion(key_schedule[9], 0x36);

#undef AES_128_key_exp
}

void __vectorcall aes128_load_key(const __m128i* enc_key, __m128i* enc_key_schedule, __m128i* dec_key_schedule) {
	aes128_generate_key_schedule(enc_key, enc_key_schedule);

	dec_key_schedule[0] = enc_key_schedule[10];
	dec_key_schedule[1] = _mm_aesimc_si128(enc_key_schedule[9]);
	dec_key_schedule[2] = _mm_aesimc_si128(enc_key_schedule[8]);
	dec_key_schedule[3] = _mm_aesimc_si128(enc_key_schedule[7]);
	dec_key_schedule[4] = _mm_aesimc_si128(enc_key_schedule[6]);
	dec_key_schedule[5] = _mm_aesimc_si128(enc_key_schedule[5]);
	dec_key_schedule[6] = _mm_aesimc_si128(enc_key_schedule[4]);
	dec_key_schedule[7] = _mm_aesimc_si128(enc_key_schedule[3]);
	dec_key_schedule[8] = _mm_aesimc_si128(enc_key_schedule[2]);
	dec_key_schedule[9] = _mm_aesimc_si128(enc_key_schedule[1]);
	dec_key_schedule[10] = enc_key_schedule[0];
}

void __vectorcall aes128_decrypt(const void* input, void* output, size_t bytes, const __m128i* key_schedule, const __m128i* iv)
{
#define AES128_DECRYPT() \
	result = _mm_xor_si128(result, key_schedule[0]); \
	result = _mm_aesdec_si128(result, key_schedule[1]); \
	result = _mm_aesdec_si128(result, key_schedule[2]); \
	result = _mm_aesdec_si128(result, key_schedule[3]); \
	result = _mm_aesdec_si128(result, key_schedule[4]); \
	result = _mm_aesdec_si128(result, key_schedule[5]); \
	result = _mm_aesdec_si128(result, key_schedule[6]); \
	result = _mm_aesdec_si128(result, key_schedule[7]); \
	result = _mm_aesdec_si128(result, key_schedule[8]); \
	result = _mm_aesdec_si128(result, key_schedule[9]); \
	result = _mm_aesdeclast_si128(result, key_schedule[10]); \
	result = _mm_xor_si128(result, previous_encrypted_value); \
	previous_encrypted_value = encrypted_value;

	__m128i previous_encrypted_value = {};
	if (iv != nullptr)
	{
		previous_encrypted_value = _mm_loadu_si128(iv);
	}

	constexpr uintptr_t unaligned_mask = (sizeof(__m128i) - 1);

	const __m128i* const input_vector_begin = static_cast<const __m128i*>(input);
	const __m128i* const input_vector_end = input_vector_begin + (bytes + unaligned_mask) / sizeof(__m128i);

	const __m128i* input_vector = input_vector_begin;
	__m128i* output_vector = static_cast<__m128i*>(output);

	if ((reinterpret_cast<uintptr_t>(input) | reinterpret_cast<uintptr_t>(output)) & unaligned_mask) // check if memory is aligned
	{
		// memory is not aligned

		while (input_vector < input_vector_end)
		{
			__m128i encrypted_value = _mm_loadu_si128(input_vector++);
			__m128i result = encrypted_value;
			AES128_DECRYPT();
			_mm_storeu_si128(output_vector++, result);
		}
	}
	else
	{
		// memory is aligned

		while (input_vector < input_vector_end)
		{
			__m128i encrypted_value = _mm_load_si128(input_vector++);
			__m128i result = encrypted_value;
			AES128_DECRYPT();
			//_mm_store_si128(output_vector++, result);
			_mm_stream_si128(output_vector++, result); // nontemporal memory store
		}

		_mm_sfence(); // wait for stores to complete
	}
#undef AES128_DECRYPT
}

void halo4_aes128_decrypt(const void* input, void* output, size_t bytes, const char* key_string)
{
	__m128i key = _mm_xor_si128(_mm_loadu_epi8(key_string), _mm_set1_epi8(0xA5i8));
	__m128i iv = _mm_xor_si128(key, _mm_set1_epi8(0x3Ci8));

	__m128i enc_key[11];
	__m128i dec_key[11];
	aes128_load_key(&key, enc_key, dec_key);

	aes128_decrypt(input, output, bytes, dec_key, &iv);
}

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

	halo4::xbox360::s_cache_file_header cache_file_header = *reinterpret_cast<halo4::xbox360::s_cache_file_header*>(cache_reader.file_info.file_view_begin); // #TODO: move this into a wrapper?
	byteswap(cache_file_header);

	long string_id_index_buffer_relative_offset = cache_file_header.string_id_index_buffer_offset - buffers_info.debug_section_buffer.offset;
	string_id_index_buffer = reinterpret_cast<const unsigned long*>(buffers_info.debug_section_buffer.begin + string_id_index_buffer_relative_offset);

	//string_id_index_buffer = static_cast<unsigned long*>(_aligned_malloc(cache_file_header.string_id_string_storage_size, sizeof(unsigned long)));
	//if (string_id_index_buffer == nullptr)
	//{
	//	throw(BCS_E_FAIL);
	//}
	//memcpy(string_id_index_buffer, string_id_index_buffer, cache_file_header.string_id_index_buffer_count * sizeof(unsigned long));
	//for (long string_id_index = 0; string_id_index < cache_file_header.string_id_index_buffer_count; string_id_index++)
	//{
	//	string_id_index_buffer[string_id_index] = _byteswap_ulong(string_id_index_buffer[string_id_index]);
	//}

	long string_id_buffer_relative_offset = cache_file_header.string_id_string_storage_offset - buffers_info.debug_section_buffer.offset;
	const char* encrypted_string_id_buffer = reinterpret_cast<const char*>(buffers_info.debug_section_buffer.begin + string_id_buffer_relative_offset);

	string_id_buffer = static_cast<char*>(_aligned_malloc(cache_file_header.string_id_string_storage_size, sizeof(__m128i)));
	if (string_id_buffer == nullptr)
	{
		throw(BCS_E_FAIL);
	}
	memcpy(string_id_buffer, encrypted_string_id_buffer, cache_file_header.string_id_string_storage_size);
	halo4_aes128_decrypt(encrypted_string_id_buffer, string_id_buffer, cache_file_header.string_id_string_storage_size, c_halo4_cache_file_reader::k_string_id_encryption_key);


	long file_table_index_buffer_relative_offset = cache_file_header.file_table_indices_offset - buffers_info.debug_section_buffer.offset;
	file_table_index_buffer = reinterpret_cast<const unsigned long*>(buffers_info.debug_section_buffer.begin + file_table_index_buffer_relative_offset);

	long file_table_buffer_relative_offset = cache_file_header.file_table_offset - buffers_info.debug_section_buffer.offset;
	const char* encrypted_file_table_buffer = reinterpret_cast<const char*>(buffers_info.debug_section_buffer.begin + file_table_buffer_relative_offset);

	file_table_buffer = static_cast<char*>(_aligned_malloc(cache_file_header.file_table_length, sizeof(__m128i)));
	if (file_table_buffer == nullptr)
	{
		throw(BCS_E_FAIL);
	}
	memcpy(file_table_buffer, encrypted_file_table_buffer, cache_file_header.file_table_length);
	halo4_aes128_decrypt(encrypted_file_table_buffer, file_table_buffer, cache_file_header.file_table_length, c_halo4_cache_file_reader::k_file_name_encryption_key);

	//DEBUG_ASSERT(cache_file_header.string_id_index_buffer_count >= k_engine_string_ids_total);
	//string_id_table_buffer = new const char* [cache_file_header.string_id_index_buffer_count];

	//unsigned long const cache_file_string_id_count = cache_file_header.string_id_index_buffer_count - k_engine_string_ids_total;

	//unsigned long string_index = 0;
	//unsigned long string_buffer_index = 0;
	//{ // process engine string ids
	//	for (unsigned long set_index = 0; set_index < k_engine_string_id_namespace_count; set_index++)
	//	{
	//		unsigned long set_count = k_engine_set_counts[set_index];
	//		unsigned long set_total_strings = set_count;

	//		string_id_table->count = set_total_strings;
	//		string_id_table->strings = string_id_table_buffer + string_buffer_index;

	//		for (unsigned long set_string_index = 0; set_string_index < set_count; set_string_index++)
	//		{
	//			//long string_id_buffer_offset = string_id_index_buffer[string_index];
	//			long string_id_buffer_offset = _byteswap_ulong(string_id_index_buffer[string_index]);
	//			const char* string_id = string_id_buffer_unencrypted + string_id_buffer_offset;

	//			string_id_table_buffer[string_buffer_index++] = string_id;

	//			debug_point;
	//			string_index++;
	//		}
	//		if (set_index == 0)
	//		{
	//			set_total_strings += cache_file_string_id_count;
	//			string_buffer_index += cache_file_string_id_count;
	//		}
	//		debug_point;
	//	}
	//}
	//{ // process cache string ids
	//	string_buffer_index = k_engine_set_counts[0];
	//	DEBUG_ASSERT(string_index == k_engine_string_ids_total); // sanity check
	//	for (; string_index < cache_file_header.string_id_index_buffer_count; string_index++)
	//	{
	//		//long string_id_buffer_offset = string_id_index_buffer[string_index];
	//		long string_id_buffer_offset = _byteswap_ulong(string_id_index_buffer[string_index]);
	//		const char* string_id = string_id_buffer_unencrypted + string_id_buffer_offset;

	//		string_id_table_buffer[string_buffer_index++] = string_id;

	//		debug_point;
	//	}
	//}

	debug_point;
}

c_halo4_debug_reader::~c_halo4_debug_reader()
{
	_aligned_free(string_id_buffer);
	//_aligned_free(string_id_index_buffer);
	_aligned_free(file_table_buffer);
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

	long string_id_buffer_offset = _byteswap_ulong(string_id_index_buffer[string_index]);
	string = string_id_buffer + string_id_buffer_offset;

	return rs;
}


BCS_RESULT c_halo4_debug_reader::get_tag_filepath(long tag_index, const char*& filepath)
{
	halo4::xbox360::s_cache_file_header cache_file_header = *reinterpret_cast<halo4::xbox360::s_cache_file_header*>(cache_reader.file_info.file_view_begin); // #TODO: move this into a wrapper?
	byteswap(cache_file_header);

	if (tag_index < 0 || tag_index > cache_file_header.file_count)
	{
		return BCS_E_FAIL;
	}

	unsigned long file_buffer_offset = _byteswap_ulong(file_table_index_buffer[tag_index]);
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
	halo4::xbox360::s_cache_file_header cache_file_header = *reinterpret_cast<halo4::xbox360::s_cache_file_header*>(cache_reader.file_info.file_view_begin); // #TODO: move this into a wrapper?
	byteswap(cache_file_header);

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

	unsigned long offset = 0;
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
