#pragma once

class c_infinite_cache_cluster;

class c_infinite_module_file_reader : public c_cache_file_reader
{
public:
	static constexpr unsigned long k_max_module_files = 4;

	c_infinite_module_file_reader(const wchar_t* filepath, s_engine_platform_build engine_platform_build);
	~c_infinite_module_file_reader();

	BCS_RESULT get_module_file_entry_structure_size(unsigned long& structure_size) const;
	BCS_RESULT get_string_buffer_fixup_offset_hack(unsigned long& string_buffer_fixup_offset_hack) const;
	virtual BCS_RESULT get_build_info(s_cache_file_build_info& build_info) const;
	virtual BCS_RESULT get_debug_info(s_cache_file_debug_info& debug_info) const;
	BCS_RESULT get_section_buffer(gen3::e_cache_file_section section_index, s_cache_file_buffer_info& buffer_info) const;
	virtual BCS_RESULT get_buffer(e_cache_file_buffer_index buffer_index, s_cache_file_buffer_info& buffer_info) const;
	virtual BCS_RESULT get_buffers(s_cache_file_buffers_info& buffers_info) const;
	virtual BCS_RESULT associate_cache_cluster(c_cache_cluster& cache_cluster);
	virtual BCS_RESULT associate_cache_cluster(c_infinite_cache_cluster& cache_cluster);

	virtual BCS_RESULT virtual_address_to_relative_offset(int64_t virtual_address, int32_t& relative_offset) const;
	virtual BCS_RESULT page_offset_to_virtual_address(unsigned long page_offset, int64_t& virtual_address) const;

	virtual BCS_RESULT get_blofeld_tag_groups(const blofeld::s_tag_group**& tag_groups) const;

	unsigned long get_field_size(blofeld::e_field field);
	unsigned long get_field_size(const blofeld::s_tag_field& field);
	unsigned long calculate_struct_size(const blofeld::s_tag_struct_definition& struct_definition);

	BCS_RESULT data_offset_fixup(unsigned long long data_offset, unsigned long index, unsigned long long& fixed_offset);
		
	c_fixed_wide_path filepath;
	s_engine_platform_build engine_platform_build;
	t_memory_mapped_file* files[k_max_module_files];
	s_memory_mapped_file_info file_infos[k_max_module_files];
	c_infinite_cache_cluster* cache_cluster;

	infinite::s_module_file_header* module_file_header;
};
