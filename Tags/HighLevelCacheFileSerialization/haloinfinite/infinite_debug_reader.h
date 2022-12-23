#pragma once

#include <numeric>

class c_infinite_cache_cluster;
class c_infinite_module_file_reader;

class c_infinite_debug_reader : public c_debug_reader
{
public:
	c_infinite_debug_reader(c_infinite_cache_cluster& cache_cluster, c_infinite_module_file_reader& cache_reader);
	~c_infinite_debug_reader();

	virtual BCS_RESULT string_id_to_index(string_id stringid, uint32_t& string_index) final;
	virtual BCS_RESULT string_id_to_index(uint32_t string_id_index, uint32_t string_id_namespace, uint32_t string_id_length, uint32_t& string_index) final;
	virtual BCS_RESULT string_id_to_string(string_id stringid, const char*& string) final;
	virtual BCS_RESULT string_id_to_string(uint32_t string_id_index, uint32_t string_id_namespace, uint32_t string_id_length, const char*& string) final;
	virtual BCS_RESULT get_tag_filepath(uint32_t tag_index, const char*& filepath);
	virtual BCS_RESULT get_group_name(tag group_tag, const char*& group_name);
	virtual BCS_RESULT get_group_id(tag group_tag, const char*& group_id);
private:
	c_infinite_cache_cluster& cache_cluster;
	c_infinite_module_file_reader& cache_reader;
};
