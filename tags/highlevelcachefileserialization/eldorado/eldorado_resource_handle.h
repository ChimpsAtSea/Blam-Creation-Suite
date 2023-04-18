#pragma once

namespace blofeld::eldorado::pc32
{
	class h_cache_file_resource_location_struct;
	class h_cache_file_resource_data_block;
}

class c_eldorado_cache_file_reader;

class c_eldorado_resource_handle :
	public h_resource, public c_transplant_context
{
public:
	BCS_SHARED c_eldorado_resource_handle(
		c_transplant_context& context,
		c_eldorado_cache_file_reader& cache_file_reader, 
		c_eldorado_tag_instance& tag_instance,
		char const* resource_data_position,
		blofeld::s_tag_resource_definition const& resource_definition);
	~c_eldorado_resource_handle();

	virtual BCS_RESULT add_reference(s_resource_details& resource_details, bool create_prototype) override;
	virtual BCS_RESULT remove_reference() override;
	virtual const char* get_debug_type_string() override;

	virtual BCS_RESULT get_transplant_data(void const*& data_start, void const** data_end, void const** data_root) override;
	virtual BCS_RESULT resolve_address(dword const* address_pointer, void const*& address_data_start) override;

	blofeld::eldorado::pc32::h_cache_file_resource_location_struct& resource_location;
	blofeld::eldorado::pc32::h_cache_file_resource_data_block& resource_data;
	const wchar_t* resource_binary_filepath;
	unsigned int absolute_file_offset;
	void* decompressed_buffer;
	uint32_t decompressed_buffer_size;
	int32_t reference_count;
	std::vector<s_resource_chunk_details> chunk_details;
	t_memory_mapped_file* memory_mapped_file;
	s_memory_mapped_file_info memory_mapped_file_info;
	h_prototype* prototype;
	blofeld::s_tag_resource_definition const& resource_definition;
};
