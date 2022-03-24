#pragma once

#include <numeric>

class c_halo3_cache_cluster;
class c_halo3_cache_file_reader;

class c_halo3_debug_reader : public c_debug_reader
{
public:
	c_halo3_debug_reader(c_halo3_cache_cluster& cache_cluster, c_halo3_cache_file_reader& cache_reader);
	~c_halo3_debug_reader();

	virtual BCS_RESULT string_id_to_index(string_id stringid, unsigned long& string_index) final;
	virtual BCS_RESULT string_id_to_index(unsigned long string_id_index, unsigned long string_id_namespace, unsigned long string_id_length, unsigned long& string_index) final;
	virtual BCS_RESULT string_id_to_string(string_id stringid, const char*& string) final;
	virtual BCS_RESULT string_id_to_string(unsigned long string_id_index, unsigned long string_id_namespace, unsigned long string_id_length, const char*& string) final;
	virtual BCS_RESULT get_tag_filepath(unsigned long tag_index, const char*& filepath);
	virtual BCS_RESULT get_group_name(tag group_tag, const char*& group_name);
	virtual BCS_RESULT get_group_id(tag group_tag, const char*& group_id);
private:
	c_halo3_cache_cluster& cache_cluster;
	c_halo3_cache_file_reader& cache_reader;

	char* file_table_buffer;
	//unsigned long* string_id_index_buffer;
	char* string_id_buffer;

	const unsigned long* string_id_index_buffer;
	const char* encrypted_string_id_buffer;
	const unsigned long* file_table_index_buffer;
	const char* encrypted_file_table_buffer;
	// string ids

	static constexpr unsigned long string_id_index_bits = 16;
	static constexpr unsigned long string_id_index_mask = (1u << string_id_index_bits) - 1;
	static constexpr unsigned long string_id_index_shift = 0;
	static constexpr unsigned long string_id_namespace_bits = 8;
	static constexpr unsigned long string_id_namespace_mask = (1u << string_id_namespace_bits) - 1;
	static constexpr unsigned long string_id_namespace_shift = string_id_index_bits;
	static constexpr unsigned long string_id_length_bits = 8;
	static constexpr unsigned long string_id_length_mask = (1u << string_id_length_bits) - 1;
	static constexpr unsigned long string_id_length_shift = string_id_index_bits + string_id_namespace_bits;

	//static constexpr unsigned long k_xbox360_engine_set_counts[] = { 1208, 825, 56, 34, 16, 52, 45 };
	//static constexpr unsigned long k_xbox360_engine_string_id_namespace_count = _countof(k_xbox360_engine_set_counts);
	//static constexpr unsigned long k_xbox360_engine_string_ids_total = compile_time_accumulator(k_xbox360_engine_set_counts);

	static constexpr unsigned long k_xbox360_engine_set_counts[] = { 1207, 1478, 146, 84, 76, 16, 49, 20, 13 };
	static constexpr unsigned long k_xbox360_engine_string_id_namespace_count = _countof(k_xbox360_engine_set_counts);
	static constexpr unsigned long k_xbox360_engine_string_ids_total = compile_time_accumulator(k_xbox360_engine_set_counts);



	//struct s_string_id_namespace
	//{
	//	unsigned long count;
	//	const char** strings;
	//};
	//const char** string_id_table_buffer;
	//s_string_id_namespace string_id_table[k_engine_string_id_namespace_count];
};
