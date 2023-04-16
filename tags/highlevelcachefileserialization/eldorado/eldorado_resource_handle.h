#pragma once

namespace blofeld::eldorado::pc32
{
	class h_cache_file_resource_location_struct;
	class h_cache_file_resource_data_block;
}

class c_eldorado_cache_file_reader;

class c_eldorado_resource_handle :
	public h_resource
{
public:
	BCS_SHARED c_eldorado_resource_handle(
		c_eldorado_cache_file_reader& cache_file_reader, 
		c_tag_instance& tag_instance, 
		char const* resource_data_position);
	~c_eldorado_resource_handle();

	virtual BCS_RESULT add_reference(const void*& buffer, uint32_t& buffer_size) override;
	virtual BCS_RESULT remove_reference() override;
	virtual const char* get_debug_type_string() override;

	blofeld::eldorado::pc32::h_cache_file_resource_location_struct& resource_location;
	blofeld::eldorado::pc32::h_cache_file_resource_data_block& resource_data;
	const wchar_t* resource_binary_filepath;
	unsigned int absolute_file_offset;
	void* decompressed_buffer;
	int32_t reference_count;
	t_memory_mapped_file* memory_mapped_file;
	s_memory_mapped_file_info memory_mapped_file_info;
};
