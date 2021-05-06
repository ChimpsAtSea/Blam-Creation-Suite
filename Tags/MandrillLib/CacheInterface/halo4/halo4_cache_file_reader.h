#pragma once

class c_halo4_cache_cluster;

class c_halo4_cache_file_reader : public c_cache_file_reader
{
public:
	c_halo4_cache_file_reader(const wchar_t* filepath, s_engine_platform_build engine_platform_build);
	~c_halo4_cache_file_reader();

	virtual BCS_RESULT get_build_info(s_cache_file_build_info& build_info) const;
	virtual BCS_RESULT get_debug_info(s_cache_file_debug_info& debug_info) const;
	BCS_RESULT get_section_buffer(gen3::e_cache_file_section section_index, s_cache_file_buffer_info& buffer_info) const;
	virtual BCS_RESULT get_buffer(e_cache_file_buffer_index buffer_index, s_cache_file_buffer_info& buffer_info) const;
	virtual BCS_RESULT get_buffers(s_cache_file_buffers_info& buffers_info) const;
	virtual BCS_RESULT associate_cache_cluster(c_cache_cluster& cache_cluster);
	virtual BCS_RESULT associate_cache_cluster(c_halo4_cache_cluster& cache_cluster);

	virtual BCS_RESULT virtual_address_to_relative_offset(int64_t virtual_address, int32_t& relative_offset) const;
	virtual BCS_RESULT page_offset_to_virtual_address(unsigned long page_offset, int64_t& virtual_address) const;

	c_fixed_wide_path filepath;
	s_engine_platform_build engine_platform_build;
	t_memory_mapped_file* file;
	s_memory_mapped_file_info file_info;
	c_halo4_cache_cluster* cache_cluster;

	halo4::xbox360::s_cache_file_header cache_file_header; // #TODO: move this into a wrapper?


	static constexpr char k_file_name_encryption_key[] = "LetsAllPlayNice!";
	static constexpr char k_string_id_encryption_key[] = "ILikeSafeStrings";
	static constexpr char k_localization_encryption_key[] = "BungieHaloReach!";
	static constexpr char k_network_encryption_key[] = "SneakerNetReigns";
};
