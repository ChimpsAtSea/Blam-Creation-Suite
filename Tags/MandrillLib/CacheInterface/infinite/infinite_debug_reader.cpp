#include "mandrilllib-private-pch.h"

c_infinite_debug_reader::c_infinite_debug_reader(c_infinite_cache_cluster& cache_cluster, c_infinite_module_file_reader& cache_reader) :
	cache_cluster(cache_cluster),
	cache_reader(cache_reader)
{
	BCS_RESULT rs;

	s_cache_file_buffers_info buffers_info;
	if (BCS_FAILED(rs = cache_reader.get_buffers(buffers_info)))
	{
		throw(rs);
	}
}

c_infinite_debug_reader::~c_infinite_debug_reader()
{
}

BCS_RESULT c_infinite_debug_reader::string_id_to_string(string_id stringid, const char*& string)
{
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_infinite_debug_reader::string_id_to_string(uint32_t string_id_index, uint32_t string_id_namespace, uint32_t string_id_length, const char*& string)
{
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_infinite_debug_reader::get_tag_filepath(unsigned long tag_index, const char*& filepath)
{
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_infinite_debug_reader::get_group_name(tag group_tag, const char*& group_name)
{
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_infinite_debug_reader::get_group_id(tag group_tag, const char*& group_id)
{
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_infinite_debug_reader::string_id_to_index(string_id stringid, uint32_t& string_index)
{
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_infinite_debug_reader::string_id_to_index(uint32_t string_id_index, uint32_t string_id_namespace, uint32_t string_id_length, uint32_t& string_index)
{
	return BCS_E_UNSUPPORTED;
}
