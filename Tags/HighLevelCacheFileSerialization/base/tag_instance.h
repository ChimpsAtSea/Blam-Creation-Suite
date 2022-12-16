#pragma once

class c_tag_group;

class c_tag_instance
{
public:

	virtual BCS_RESULT map_data();
	virtual BCS_RESULT unmap_data();
	virtual BCS_RESULT get_tag_data(const void*& tag_data_root, const void*& tag_data_start, const void*& tag_data_end) const = 0;
	virtual BCS_RESULT get_instance_name(const char*& tag_instance_name) const = 0;
	virtual BCS_RESULT get_tag_group(c_tag_group*& tag_group) const = 0;
	virtual BCS_RESULT get_cache_file_tag_index(uint32_t& cache_file_tag_index) const = 0;
	virtual BCS_RESULT get_tag_file_reader(c_tag_reader*& tag_reader) const = 0;
};
