#include "highlevelcachefileserialization-private-pch.h"

using namespace blofeld::eldorado::pc32;

c_eldorado_resource_handle::c_eldorado_resource_handle() :
	resource_location(*new h_cache_file_resource_location_struct(this)),
	resource_data(*new h_cache_file_resource_data_block(this)),
	resource_binary_filepath(nullptr), // #TODO: How to populate?
	reference_count(0),
	memory_mapped_file(),
	memory_mapped_file_info()
{

}

c_eldorado_resource_handle::~c_eldorado_resource_handle()
{
	delete& resource_location;
	delete& resource_data;
	ASSERT(reference_count == 0);
	untracked_free(resource_binary_filepath);
}

BCS_RESULT c_eldorado_resource_handle::add_reference(const void*& buffer, uint32_t& buffer_size)
{
	BCS_RESULT rs = BCS_S_OK;

	int32_t reference_index = reference_count;

	if (reference_index == 0)
	{
		if (BCS_FAILED(rs = create_memory_mapped_file(resource_binary_filepath, true, memory_mapped_file)))
		{
			return rs;
		}

		if (BCS_FAILED(rs = get_memory_mapped_file_info(memory_mapped_file, memory_mapped_file_info)))
		{
			destroy_memory_mapped_file(memory_mapped_file);
			return rs;
		}
	}
	reference_count++;
	ASSERT(reference_count > 0);

	unsigned int offset = 0;
	throw; // #TODO: How to use resource_location.shared_file_location_index?

	const char* resource_data_start = memory_mapped_file_info.file_view_begin + offset;
	const char* resource_data_end = resource_data_start + resource_location.file_size;

	buffer = resource_data_start;
	buffer_size = static_cast<unsigned long>(resource_data_end - resource_data_start);

	return rs;
}

BCS_RESULT c_eldorado_resource_handle::remove_reference()
{
	BCS_RESULT rs = BCS_S_OK;
	int32_t reference_index = reference_count--;
	ASSERT(reference_count >= 0);

	if (reference_index == 0)
	{
		if (BCS_FAILED(rs = destroy_memory_mapped_file(memory_mapped_file)))
		{
			return rs;
		}
	}

	return rs;
}

const char* c_eldorado_resource_handle::get_debug_type_string()
{
	return "c_eldorado_resource_handle";
}
