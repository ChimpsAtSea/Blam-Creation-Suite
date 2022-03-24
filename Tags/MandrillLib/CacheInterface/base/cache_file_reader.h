#pragma once

class c_cache_cluster;

struct s_cache_file_build_info;
struct s_cache_file_debug_info;
struct s_cache_file_buffer_info;
union s_cache_file_buffers_info;

class c_cache_file_reader
{
public:
	c_cache_file_reader();
	virtual ~c_cache_file_reader();

	virtual BCS_RESULT get_build_info(s_cache_file_build_info& build_info) const = 0;
	virtual BCS_RESULT get_debug_info(s_cache_file_debug_info& debug_info) const = 0;
	virtual BCS_RESULT get_buffer(e_cache_file_buffer_index buffer_index, s_cache_file_buffer_info& buffer_info) const = 0;
	virtual BCS_RESULT get_buffers(s_cache_file_buffers_info& buffers_info) const = 0;
	virtual BCS_RESULT associate_cache_cluster(c_cache_cluster& cache_cluster) = 0;
	virtual BCS_RESULT get_blofeld_tag_groups(const blofeld::s_tag_group**& tag_groups) const = 0;
	virtual BCS_RESULT virtual_address_to_relative_offset(long long virtual_address, long& relative_offset) const = 0;
	virtual BCS_RESULT page_offset_to_virtual_address(unsigned long page_offset, long long& virtual_address) const = 0;
};
