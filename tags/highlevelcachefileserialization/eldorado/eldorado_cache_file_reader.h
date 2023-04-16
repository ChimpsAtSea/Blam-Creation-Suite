#pragma once

class c_eldorado_cache_cluster;

enum e_eldorado_file_index
{
	_eldorado_file_type_resources,
	_eldorado_file_type_textures_resources,
	_eldorado_file_type_textures_b_resources,
	_eldorado_file_type_audio_resources,
	_eldorado_file_type_video_resources,
	k_num_eldorado_resource_files,
	_eldorado_file_type_string_ids = k_num_eldorado_resource_files,
	_eldorado_file_type_tags_list,
	_eldorado_file_type_tags_cache,
	k_eldorado_num_files
};

class c_eldorado_cache_file_reader : public c_cache_file_reader
{
public:
	c_eldorado_cache_file_reader(c_eldorado_cache_file_reader const&) = delete;
	BCS_SHARED c_eldorado_cache_file_reader(const wchar_t* filepath, s_engine_platform_build engine_platform_build);
	BCS_SHARED ~c_eldorado_cache_file_reader();

	BCS_SHARED virtual BCS_RESULT associate_cache_cluster(c_cache_cluster& cache_cluster) override final;
	BCS_SHARED virtual BCS_RESULT get_blofeld_tag_groups(blofeld::t_tag_group_collection& tag_groups) const override final;
	BCS_SHARED virtual BCS_RESULT virtual_address_to_relative_offset(int64_t virtual_address, int32_t& relative_offset) const override final;
	BCS_SHARED virtual BCS_RESULT page_offset_to_virtual_address(uint32_t page_offset, int64_t& virtual_address) const override final;

	BCS_SHARED BCS_RESULT get_section_buffer(gen3::e_cache_file_section section_index, s_cache_file_buffer_info& buffer_info) const;
	BCS_SHARED BCS_RESULT associate_cache_cluster(c_eldorado_cache_cluster& cache_cluster);

	virtual BCS_RESULT get_resource_absolute_file_offset(e_eldorado_file_index resource_file_index, unsigned int file_index, unsigned int& absolute_file_offset) const;

	const wchar_t* directory;
	s_engine_platform_build engine_platform_build;

	static constexpr const char* eldorado_relative_file_paths[k_eldorado_num_files] =
	{
		"maps\\resources.dat",
		"maps\\textures.dat",
		"maps\\textures_b.dat",
		"maps\\audio.dat",
		"maps\\video.dat",
		"maps\\string_ids.dat",
		"maps\\tags_list.csv",
		"maps\\tags.dat",
	};

	t_memory_mapped_file* memory_mapped_files[k_eldorado_num_files];
	s_memory_mapped_file_info memory_mapped_file_infos[k_eldorado_num_files];

	c_eldorado_cache_cluster* cache_cluster;
	blofeld::t_tag_group_collection tag_groups;

	template<typename t_element>
	void byteswap_inplace(t_element& value)
	{
		if (get_platform_is_big_endian(engine_platform_build))
		{
			::byteswap_inplace(value);
		}
	}
};
