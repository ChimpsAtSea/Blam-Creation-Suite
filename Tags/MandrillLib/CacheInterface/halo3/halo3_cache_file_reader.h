#pragma once

class c_halo3_cache_cluster;

class c_halo3_cache_file_reader : public c_cache_file_reader
{
public:
	c_halo3_cache_file_reader(const wchar_t* filepath, s_engine_platform_build engine_platform_build);
	~c_halo3_cache_file_reader();

	virtual BCS_RESULT get_build_info(s_cache_file_build_info& build_info) const;
	virtual BCS_RESULT get_debug_info(s_cache_file_debug_info& debug_info) const;
	BCS_RESULT get_section_buffer(gen3::e_cache_file_section section_index, s_cache_file_buffer_info& buffer_info) const;
	virtual BCS_RESULT get_buffer(e_cache_file_buffer_index buffer_index, s_cache_file_buffer_info& buffer_info) const;
	virtual BCS_RESULT get_buffers(s_cache_file_buffers_info& buffers_info) const;
	virtual BCS_RESULT associate_cache_cluster(c_cache_cluster& cache_cluster);
	virtual BCS_RESULT associate_cache_cluster(c_halo3_cache_cluster& cache_cluster);

	virtual BCS_RESULT virtual_address_to_relative_offset(int64_t virtual_address, int32_t& relative_offset) const;
	virtual BCS_RESULT page_offset_to_virtual_address(uint32_t page_offset, int64_t& virtual_address) const;

	virtual BCS_RESULT get_blofeld_tag_groups(blofeld::t_tag_group_collection& tag_groups) const;

	c_fixed_wide_path filepath;
	s_engine_platform_build engine_platform_build;
	t_memory_mapped_file* file;
	s_memory_mapped_file_info file_info;
	c_halo3_cache_cluster* cache_cluster;

	BCS_RESULT get_tags_header_relative_offset(int32_t& tags_header_relative_offset) const;
	BCS_RESULT get_file_count(int32_t& file_count) const;
	BCS_RESULT get_string_id_index_buffer_count(int32_t& string_id_index_buffer_count) const;
	BCS_RESULT get_string_id_index_buffer_offset(int32_t& string_id_index_buffer_offset) const;
	BCS_RESULT get_string_id_string_storage_offset(int32_t& string_id_string_storage_offset) const;
	BCS_RESULT get_string_id_string_storage_size(int32_t& string_id_string_storage_size) const;
	BCS_RESULT get_file_table_indices_offset(int32_t& file_table_indices_offset) const;
	BCS_RESULT get_file_table_offset(int32_t& file_table_offset) const;
	BCS_RESULT get_file_table_length(int32_t& file_table_length) const;

	template<typename t_element>
	void byteswap_inplace(t_element& value)
	{
		if (get_platform_is_big_endian(engine_platform_build))
		{
			::byteswap_inplace(value);
		}
	}

private:
	union
	{
		s_cache_file_header cache_file_header;
		::halo3::pc::s_cache_file_header pc_cache_file_header;
		::halo3::xbox360::s_cache_file_header xbox360_cache_file_header;
	};
};
