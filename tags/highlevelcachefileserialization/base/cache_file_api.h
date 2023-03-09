#pragma once

class c_tag_project;

class c_cache_file_reader;
class c_debug_reader;
class c_localization_reader;
class c_resource_reader;
class c_tag_reader;
class c_cache_cluster;

//struct s_cache_file_reader_plugin_callbacks_info
//{
//	void* userdata;
//};
//BCS_SHARED BCS_RESULT register_cache_file_reader_plugin_callbacks(s_cache_file_reader_plugin_callbacks_info* plugin_callbacks_info);

BCS_SHARED BCS_RESULT get_cache_file_reader_engine_and_platform(const char* filepath, s_engine_platform_build* engine_platform_build);
BCS_SHARED BCS_RESULT get_cache_file_reader_engine_and_platform(const wchar_t* filepath, s_engine_platform_build* engine_platform_build);

BCS_SHARED BCS_RESULT open_cache_file_reader(
	const char* filepath,
	s_engine_platform_build engine_platform_build,
	bool read_only,
	bool memory_mapped_file,
	c_cache_file_reader** cache_file
);

BCS_SHARED BCS_RESULT open_cache_file_reader(
	const wchar_t* filepath,
	s_engine_platform_build engine_platform_build,
	bool read_only,
	bool memory_mapped_file,
	c_cache_file_reader** cache_file
);

BCS_SHARED BCS_RESULT close_cache_file_reader(
	c_cache_file_reader* cache_reader
);

BCS_SHARED BCS_RESULT get_cache_file_reader_build_info(
	c_cache_file_reader* cache_reader,
	s_cache_file_build_info* build_info
);

struct s_cache_file_debug_info
{
	const char*** string_ids; // [set][index]
	const char** tag_names;
};

BCS_SHARED BCS_RESULT get_cache_file_reader_debug_info(
	c_cache_file_reader* cache_reader,
	s_cache_file_debug_info* debug_info
);

struct s_cache_file_buffer_info
{
	const char* begin;
	const char* end;
	uint32_t size;
	int32_t offset;
	int32_t offset_mask;
};

enum e_cache_file_buffer_index
{
	_cache_file_buffer,
	_debug_section_buffer,
	_resources_section_buffer,
	_tag_section_buffer,
	_localization_section_buffer,
	_tag_post_link_buffer,
	_tag_language_dependent_read_only_buffer,
	_tag_language_dependent_read_write_buffer,
	_tag_language_neutral_read_write_buffer,
	_tag_language_neutral_write_combined_buffer,
	_tag_language_neutral_read_only_buffer,
	_module_file_buffer_root,
	_module_file_buffer_data0,
	_module_file_buffer_data1,
	_module_file_buffer_data2,
	_module_file_buffer_data3,
	k_num_cache_file_buffers
};

BCS_SHARED BCS_RESULT get_cache_file_reader_buffer(
	c_cache_file_reader* cache_reader,
	e_cache_file_buffer_index buffer_index,
	s_cache_file_buffer_info* buffer_info
);

union s_cache_file_buffers_info
{
	s_cache_file_buffer_info buffer_infos[k_num_cache_file_buffers];
	struct
	{
		s_cache_file_buffer_info cache_file_buffer;
		s_cache_file_buffer_info debug_section_buffer;
		s_cache_file_buffer_info resources_section_buffer;
		s_cache_file_buffer_info tag_section_buffer;
		s_cache_file_buffer_info localization_section_buffer;
		s_cache_file_buffer_info tag_post_link_buffer;
		s_cache_file_buffer_info tag_language_dependent_read_only_buffer;
		s_cache_file_buffer_info tag_language_dependent_read_write_buffer;
		s_cache_file_buffer_info tag_language_neutral_read_write_buffer;
		s_cache_file_buffer_info tag_language_neutral_write_combined_buffer;
		s_cache_file_buffer_info tag_language_neutral_read_only_buffer;
	};
};

BCS_SHARED BCS_RESULT get_cache_file_reader_buffers(
	c_cache_file_reader* cache_reader,
	s_cache_file_buffers_info* buffers_info
);

BCS_SHARED BCS_RESULT create_cache_cluster(
	c_cache_file_reader** cache_readers,
	uint32_t cache_reader_count,
	s_engine_platform_build engine_platform_build,
	c_cache_cluster** cache_cluster
);

BCS_SHARED BCS_RESULT destroy_cache_cluster(
	c_cache_cluster* cache_cluster
);

BCS_SHARED BCS_RESULT create_cache_file_debug_reader(
	c_cache_cluster* cache_cluster,
	c_cache_file_reader* cache_reader,
	c_debug_reader** debug_reader
);

BCS_SHARED BCS_RESULT destroy_cache_file_debug_reader(
	c_debug_reader* debug_reader
);

BCS_SHARED BCS_RESULT create_cache_file_tag_reader(
	c_cache_cluster* cache_cluster,
	c_cache_file_reader* cache_reader,
	c_tag_reader** tag_reader
);

BCS_SHARED BCS_RESULT destroy_cache_file_tag_reader(
	c_tag_reader* tag_reader
);

BCS_SHARED BCS_RESULT create_cache_file_resource_reader(
	c_cache_cluster* cache_cluster,
	c_cache_file_reader* cache_reader,
	c_resource_reader** resource_reader
);

BCS_SHARED BCS_RESULT destroy_cache_file_resource_reader(
	c_resource_reader* resource_reader
);

BCS_SHARED BCS_RESULT create_cache_file_localization_reader(
	c_cache_cluster* cache_cluster,
	c_cache_file_reader* cache_reader,
	c_localization_reader** localization_reader
);

BCS_SHARED BCS_RESULT destroy_cache_file_localization_reader(
	c_localization_reader* localization_reader
);
