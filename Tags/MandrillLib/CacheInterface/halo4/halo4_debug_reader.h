#pragma once

#include <numeric>

class c_halo4_cache_cluster;
class c_halo4_cache_file_reader;

class c_halo4_debug_reader : public c_debug_reader
{
public:
	c_halo4_debug_reader(c_halo4_cache_cluster& cache_cluster, c_halo4_cache_file_reader& cache_reader);
	~c_halo4_debug_reader();

	virtual BCS_RESULT string_id_to_index(string_id stringid, uint32_t& string_index) final;
	virtual BCS_RESULT string_id_to_index(uint32_t string_id_index, uint32_t string_id_namespace, uint32_t string_id_length, uint32_t& string_index) final;
	virtual BCS_RESULT string_id_to_string(string_id stringid, const char*& string) final;
	virtual BCS_RESULT string_id_to_string(uint32_t string_id_index, uint32_t string_id_namespace, uint32_t string_id_length, const char*& string) final;
	virtual BCS_RESULT get_tag_filepath(long tag_index, const char*& filepath);
	virtual BCS_RESULT get_group_name(tag group_tag, const char*& group_name);
	virtual BCS_RESULT get_group_id(tag group_tag, const char*& group_id);
private:
	c_halo4_cache_cluster& cache_cluster;
	c_halo4_cache_file_reader& cache_reader;

	char* file_table_buffer;
	//unsigned long* string_id_index_buffer;
	char* string_id_buffer;

	const unsigned long* string_id_index_buffer;
	const char* encrypted_string_id_buffer;
	const unsigned long* file_table_index_buffer;
	const char* encrypted_file_table_buffer;
	// string ids

	static constexpr unsigned long string_id_index_bits = 19;
	static constexpr unsigned long string_id_index_mask = (1u << string_id_index_bits) - 1;
	static constexpr unsigned long string_id_index_shift = 0;
	static constexpr unsigned long string_id_namespace_bits = 6;
	static constexpr unsigned long string_id_namespace_mask = (1u << string_id_namespace_bits) - 1;
	static constexpr unsigned long string_id_namespace_shift = string_id_index_bits;
	static constexpr unsigned long string_id_length_bits = 7;
	static constexpr unsigned long string_id_length_mask = (1u << string_id_length_bits) - 1;
	static constexpr unsigned long string_id_length_shift = string_id_index_bits + string_id_namespace_bits;

	//static constexpr unsigned long k_engine_set_counts[] = { 1585, 2167, 267, 141, 248, 85, 43, 2812, 528, 51, 131, 0, 52, 13, 66, 227 };
	static constexpr unsigned long k_engine_set_counts[] = { 1585, 2165, 267, 141, 248, 71, 43, 2797, 524, 51, 131, 0, 52, 13, 66, 227 };
	static constexpr unsigned long k_engine_string_id_namespace_count = _countof(k_engine_set_counts);
	static constexpr unsigned long k_engine_string_ids_total = compile_time_accumulator(k_engine_set_counts);



	//struct s_string_id_namespace
	//{
	//	unsigned long count;
	//	const char** strings;
	//};
	//const char** string_id_table_buffer;
	//s_string_id_namespace string_id_table[k_engine_string_id_namespace_count];
};
